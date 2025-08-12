'''
L = 49cm 
R = 6.25cm
v_left  = v - (L / 2.0) * omega
v_right = v + (L / 2.0) * omega
'''

# IN TERMINAL RUN:
# ros2 run joy joy_node
# ros2 topic echo /joy


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
        # set defaults
        left_velocity = 0 
        right_velocity = 0
        try:
            vertical_val = msg.axes[1]  # range: [-1.0, 1.0]
            horizontal_val = msg.axes[0]
            # self.get_logger().info(f"Joy msg: {msg.axes[1]}")
            # self.get_logger().info(f"Joy msg type: {type(msg.axes[1])}")

            if horizontal_val >= 0 and vertical_val > 0: # turn forward-left 
                right_velocity = 800
                left_velocity = (1 - horizontal_val) * 800

            elif horizontal_val <= 0 and vertical_val > 0: # turn forward-right
                left_velocity = 800
                right_velocity = (1 - (horizontal_val * -1)) * 800

            elif horizontal_val > 0 and vertical_val == 0: # rotate left
                right_velocity = 700
                left_velocity = -700

            elif horizontal_val < 0 and vertical_val == 0: # rotate right
                right_velocity = -700
                left_velocity = 700

            elif horizontal_val >= 0 and vertical_val < 0: # turn backward-left
                right_velocity = -800
                left_velocity = (1 - horizontal_val) * -800
            
            elif horizontal_val <= 0 and vertical_val < 0: # turn backward-right
                left_velocity = -800
                right_velocity = (1 - (-1 * horizontal_val)) * -800

            left_velocity = int(left_velocity)
            right_velocity = int(right_velocity)
            cmd = f'LEFTM:{left_velocity}\nRIGHTM:{right_velocity}\n'

            self.sock.sendall(cmd.encode('utf-8'))
            time.sleep(0.01)  # give the receiver time to process
            self.get_logger().info(f'Sent command: {cmd.strip()}')
        except Exception as e:
            self.get_logger().error(f"Error in joy callback: {e}")
            exit(1)

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