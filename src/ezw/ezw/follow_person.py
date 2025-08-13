#!/home/icr247/ros2-yolo-venv/bin/python3

''' RUN:
export PYTHONPATH=/home/icr247/ros2-yolo-venv/lib/python3.12/site-packages:$PYTHONPATH
export PATH=/home/icr247/ros2-yolo-venv/bin:$PATH
ros2 launch realsense2_camera rs_launch.py
ros2 run ezw object_detector
ros2 run ezw follow_person
'''

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
import socket
from std_msgs.msg import String
import time
import json


class TcpCanJoystickClient(Node):
    def __init__(self):
        super().__init__('follow_person')
        self.declare_parameter('robot_ip', '10.1.69.215')
        self.declare_parameter('robot_port', 5555)

        self.robot_ip = self.get_parameter('robot_ip').get_parameter_value().string_value
        self.robot_port = self.get_parameter('robot_port').get_parameter_value().integer_value

        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            self.sock.connect((self.robot_ip, self.robot_port))
            self.get_logger().info("Connected to robot TCP server")
        except Exception as e:
            self.get_logger().error(f"Failed to connect: {e}")
            exit(1)

        # Subscribe to camera topic
        # ros2 topic info /detections/json --verbose (publisher is BEST_EFFORT)
        # BEST_EFFORT tells middleware: "Send messages as fast as possible, but don’t worry if some get lost."
        qos = QoSProfile(history=QoSHistoryPolicy.KEEP_LAST, depth=5, reliability=QoSReliabilityPolicy.BEST_EFFORT)
        self.camera_sub = self.create_subscription(String, '/detections/json', self.camera_callback, qos)

    def camera_callback(self, msg):
        # set defaults
        left_velocity = 0 
        right_velocity = 0
        center_x = None
        distance = None

        try:
            detection_data = json.loads(msg.data)

            for detection in detection_data["detections"]:
                if detection["label"] == "sports ball" or detection["label"] == "orange" or detection["label"] == "frisbee":
                    center_x = detection["center_pixel"][0]
                    distance = detection["center_depth_m"]
                    self.get_logger().info(f"Person center X: {center_x}")
                    self.get_logger().info(f"Person distance m: {distance}")


            if center_x is not None:
                # 640 is the center of the image so acceptable range is 600-680
                speed = 640 - center_x

                if speed > 40 or speed < -40:
                    right_velocity = speed
                    left_velocity = (-1 * speed)
                elif distance is not None:
                    if distance >=  0.75 and distance <= 2:
                        speed = 400 * distance
                        right_velocity = speed
                        left_velocity = speed
                    elif distance > 2:
                        right_velocity = 800
                        left_velocity = 800
                    else:
                        right_velocity = 0
                        left_velocity = 0
                else:
                    right_velocity = 0
                    left_velocity = 0

            else:
                left_velocity = 0    # don't move if nothing detected
                right_velocity = 0

            left_velocity = int(left_velocity)
            right_velocity = int(right_velocity)
            cmd = f'LEFTM:{left_velocity}\nRIGHTM:{right_velocity}\n'

            self.sock.sendall(cmd.encode('utf-8'))
            time.sleep(0.01)  # give the receiver time to process
            self.get_logger().info(f'Sent command: {cmd.strip()}')
        except (BrokenPipeError, ConnectionResetError):
            self.get_logger().warn("Lost connection to robot, reconnecting...")
            self.reconnect()
        except Exception as e:
            self.get_logger().error(f"Error in camera callback: {e}")
            # exit(1)


    def reconnect(self):
        self.sock.close()
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.connect((self.robot_ip, self.robot_port))


    def close(self):
        self.sock.close()

def main(args=None):
    rclpy.init(args=args)
    node = TcpCanJoystickClient()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
