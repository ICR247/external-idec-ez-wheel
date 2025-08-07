# this program only moves robot forward and backward using the top left joystick on the controller

import rclpy
from rclpy.node import Node
import socket
from sensor_msgs.msg import Joy
import time

class TcpCanJoystickClient(Node):
    def __init__(self):
        super().__init__('tcp_can_joystick_client')
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

        # Subscribe to /joy topic
        self.joy_sub = self.create_subscription(Joy, '/joy', self.joy_callback, 10)

    def joy_callback(self, msg):
        # Example: left joystick vertical axis = axes[1]
        try:
            axis_val = msg.axes[1]  # range: [-1.0, 1.0]
            # self.get_logger().info(f"Joy msg: {msg.axes[1]}")
            # self.get_logger().info(f"Joy msg type: {type(msg.axes[1])}")
            velocity = int(axis_val * 500)  # scale to [-300, 300] or as needed
            print(velocity)
            cmd = f'SETVEL:{velocity}\n'
            self.sock.sendall(cmd.encode('utf-8'))
            time.sleep(0.1)  # give the receiver time to process
            self.get_logger().info(f'Sent command: {cmd.strip()}')
        except Exception as e:
            self.get_logger().error(f"Error in joy callback: {e}")

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
