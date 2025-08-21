#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
from geometry_msgs.msg import Twist
from std_msgs.msg import String
import json

class FollowBallNode(Node):
    def __init__(self):
        super().__init__('follow_ball')

        # Publisher to cmd_vel
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # QoS for BEST_EFFORT camera detection messages
        qos = QoSProfile(
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=5,
            reliability=QoSReliabilityPolicy.BEST_EFFORT
        )

        # Subscribe to detection messages
        self.camera_sub = self.create_subscription(
            String,
            '/detections/json',
            self.camera_callback,
            qos
        )

    def camera_callback(self, msg):
        try:
            data = json.loads(msg.data)
            target_center_x = None
            target_distance = None

            # Find first ball/frisbee/orange
            for detection in data.get("detections", []):
                if detection["label"] in ["sports ball", "orange", "frisbee"]:
                    target_center_x = detection["center_pixel"][0]
                    target_distance = detection.get("center_depth_m", None)
                    break

            twist = Twist()
            # if target was detected
            if target_center_x is not None:
                # Compute error relative to image center (assume 1280x720)
                error_x = target_center_x - 640

                # In control systems, a gain is a constant that determines how strongly your system reacts to an error.
                # Simple proportional controller
                K_ang = 0.01   # angular velocity gain
                K_lin = 0.5     # forward velocity gain

                # left/right rotation (yaw)
                twist.angular.z = -K_ang * error_x  # negative to turn toward object

                if target_distance is not None:
                    # Drive forward proportional to distance, stop if too close
                    distance_error = target_distance - 0.5  # stop at 0.5 m
                    twist.linear.x = max(0.0, min(1.0, K_lin * distance_error))
                else:
                    twist.linear.x = 0.2  # small forward speed if no distance info

            else:
                twist.linear.x = 0.0
                twist.angular.z = 0.0

            self.cmd_pub.publish(twist)

        except Exception as e:
            self.get_logger().error(f"Error in camera callback: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = FollowBallNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
