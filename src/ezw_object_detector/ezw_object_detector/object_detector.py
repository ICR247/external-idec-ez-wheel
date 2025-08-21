#!/home/icr247/ros2-yolo-venv/bin/python3

''' RUN:
export PYTHONPATH=/home/icr247/ros2-yolo-venv/lib/python3.12/site-packages:$PYTHONPATH
export PATH=/home/icr247/ros2-yolo-venv/bin:$PATH
ros2 launch realsense2_camera rs_launch.py
'''

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
from sensor_msgs.msg import Image
from std_msgs.msg import String
from cv_bridge import CvBridge
import cv2
import threading
import time
import json
from queue import Queue, Empty

# ultralytics YOLO
from ultralytics import YOLO
import numpy as np

class ObjectDetector(Node):
    def __init__(self):
        super().__init__('object_detector')

        # --- parameters (can be set via ros2 param or directly here) ---
        self.declare_parameter("color_topic", "/camera/camera/color/image_raw")
        self.declare_parameter("depth_topic", "/camera/camera/depth/image_rect_raw")
        self.declare_parameter("annotated_topic", "/detections/image_annotated")
        self.declare_parameter("json_topic", "/detections/json")
        self.declare_parameter("model_path", "yolov8n.pt")
        self.declare_parameter("imgsz", 640)
        self.declare_parameter("conf_thres", 0.25)
        self.declare_parameter("depth_scale", 0.001)  # default: depth unit -> meters (e.g. 1mm units)

        self.color_topic = self.get_parameter("color_topic").get_parameter_value().string_value
        self.depth_topic = self.get_parameter("depth_topic").get_parameter_value().string_value
        self.annotated_topic = self.get_parameter("annotated_topic").get_parameter_value().string_value
        self.json_topic = self.get_parameter("json_topic").get_parameter_value().string_value
        self.model_path = self.get_parameter("model_path").get_parameter_value().string_value
        self.imgsz = self.get_parameter("imgsz").get_parameter_value().integer_value
        self.conf_thres = self.get_parameter("conf_thres").get_parameter_value().double_value
        self.depth_scale = self.get_parameter("depth_scale").get_parameter_value().double_value

        qos = QoSProfile(history=QoSHistoryPolicy.KEEP_LAST, depth=5, reliability=QoSReliabilityPolicy.BEST_EFFORT)

        self.bridge = CvBridge()
        self.latest_depth = None
        self.frame_queue = Queue(maxsize=2)  # hold a small buffer to decouple callbacks from inference

        # Subscribers
        self.create_subscription(Image, self.color_topic, self.color_cb, qos)
        self.create_subscription(Image, self.depth_topic, self.depth_cb, qos)

        # Publishers
        self.annotated_pub = self.create_publisher(Image, self.annotated_topic, qos)
        self.json_pub = self.create_publisher(String, self.json_topic, qos)

        # Load model
        self.get_logger().info(f"Loading model: {self.model_path} (imgsz={self.imgsz}, conf={self.conf_thres})")
        self.model = YOLO(self.model_path)
        # configure confidence threshold
        try:
            self.model.conf = float(self.conf_thres)
        except Exception:
            pass

        # Start worker thread
        self.worker_running = True
        self.worker_thread = threading.Thread(target=self.inference_worker, daemon=True)
        self.worker_thread.start()

        self.get_logger().info("ObjectDetector node ready.")

    def color_cb(self, msg: Image):
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f"cv_bridge color convert failed: {e}")
            return

        # enqueue latest color frame and timestamp
        try:
            self.frame_queue.put_nowait((frame, msg.header.stamp))
        except Exception:
            # queue full -> drop oldest and insert new
            try:
                _ = self.frame_queue.get_nowait()
                self.frame_queue.put_nowait((frame, msg.header.stamp))
            except Exception:
                pass

    def depth_cb(self, msg: Image):
        # store latest depth frame (raw). We'll convert when reading.
        try:
            # keep as NumPy array in original encoding; use passthrough -> handle types later
            depth = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            self.latest_depth = depth
        except Exception as e:
            self.get_logger().warn(f"cv_bridge depth convert failed: {e}")
            self.latest_depth = None

    def inference_worker(self):
        while self.worker_running and rclpy.ok():
            try:
                frame, stamp = self.frame_queue.get(timeout=0.1)
            except Empty:
                time.sleep(0.01)
                continue

            try:
                # Run YOLO inference on the BGR frame (ultralytics expects numpy array)
                results = self.model(frame, imgsz=self.imgsz, conf=self.conf_thres, verbose=False)  # list-like results
                r = results[0]

                # draw annotated image (ultralytics offers .plot())
                try:
                    annotated = r.plot()  # returns RGB or BGR depending on version; usually RGB
                    # ensure BGR for cv2 if it's RGB
                    if annotated.shape[2] == 3:
                        # assume annotated is RGB -> convert to BGR
                        annotated_bgr = cv2.cvtColor(annotated, cv2.COLOR_RGB2BGR)
                    else:
                        annotated_bgr = annotated
                except Exception:
                    # safe fallback: copy original frame
                    annotated_bgr = frame.copy()

                # collect detection metadata
                detections = []
                boxes = getattr(r, "boxes", None)
                if boxes is not None and len(boxes) > 0:
                    # boxes.xyxy, boxes.conf, boxes.cls
                    try:
                        xyxy = boxes.xyxy.cpu().numpy()  # N x 4
                        confs = boxes.conf.cpu().numpy()
                        cls_ids = boxes.cls.cpu().numpy().astype(int)
                    except Exception:
                        # fallback if API differs
                        data = boxes.data.cpu().numpy()  # Nx6 [x1,y1,x2,y2,conf,class]
                        xyxy = data[:, :4]
                        confs = data[:, 4]
                        cls_ids = data[:, 5].astype(int)

                    # try to get class names (if model.names exists)
                    names = getattr(self.model, "names", None)
                    for i, (x1, y1, x2, y2) in enumerate(xyxy):
                        conf = float(confs[i])
                        cls = int(cls_ids[i])
                        label = str(names[cls]) if names is not None and cls < len(names) else str(cls)
                        bbox = [int(x1), int(y1), int(x2 - x1), int(y2 - y1)]  # x,y,w,h

                        # estimate center depth using latest_depth (if available)
                        center_x = int((x1 + x2) / 2.0)
                        center_y = int((y1 + y2) / 2.0)
                        depth_m = None
                        if self.latest_depth is not None:
                            try:
                                # latest_depth might be uint16 (mm) or float32 (meters)
                                val = float(self.latest_depth[center_y, center_x])
                                if val == 0 or np.isnan(val) or np.isinf(val):
                                    depth_m = None
                                else:
                                    # Heuristic: if depth values look large (>100), assume mm - apply scale param
                                    if val > 1000:
                                        depth_m = float(val) * float(self.depth_scale)
                                    else:
                                        depth_m = float(val) if self.depth_scale == 1.0 else float(val) * float(self.depth_scale)
                            except Exception:
                                depth_m = None

                        detections.append({
                            "class_id": cls,
                            "label": label,
                            "confidence": float(conf),
                            "bbox_xywh": bbox,
                            "center_pixel": [center_x, center_y],
                            "center_depth_m": depth_m
                        })

                # publish annotated image
                try:
                    img_msg = self.bridge.cv2_to_imgmsg(annotated_bgr, encoding='bgr8')
                    img_msg.header.stamp = stamp
                    img_msg.header.frame_id = "camera_color_frame"
                    self.annotated_pub.publish(img_msg)
                except Exception as e:
                    self.get_logger().warn(f"Failed to publish annotated image: {e}")

                # publish JSON detection summary
                summary = {
                    "header": {"stamp": {"sec": stamp.sec, "nanosec": stamp.nanosec} if stamp is not None else None},
                    "detections": detections,
                    "frame_w": int(frame.shape[1]),
                    "frame_h": int(frame.shape[0])
                }
                msg = String()
                msg.data = json.dumps(summary, default=str)
                self.json_pub.publish(msg)

            except Exception as e:
                self.get_logger().error(f"Inference worker error: {e}")

        self.get_logger().info("Inference worker exiting.")

    def destroy_node(self):
        self.worker_running = False
        if self.worker_thread.is_alive():
            self.worker_thread.join(timeout=1.0)
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = ObjectDetector()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
