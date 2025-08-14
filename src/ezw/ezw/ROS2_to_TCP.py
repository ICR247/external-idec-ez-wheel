import socket
import math
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

'''
If you want to use SLAM + Nav2, you'll need something in between Nav2's cmd_vel output and your 
TCP string format — basically a ROS 2 velocity bridge node that:

1. Subscribes to geometry_msgs/Twist (what Nav2 publishes for motion).
2. Converts (linear.x, angular.z) into left/right motor commands using your wheelbase geometry.
3. Formats them as "LEFTM: X" and "RIGHTM: Y" strings.
4. Sends them over TCP to your CAN computer.

That way Nav2 thinks it's talking to a normal differential drive base, and you don't have to rewrite Nav2 at all.

A minimal ROS 2 “cmd_vel → TCP string” bridge could look like:
'''

class CmdVelToTCP(Node):
    def __init__(self):
        super().__init__('cmdvel_to_tcp')
        self.create_subscription(Twist, '/cmd_vel', self.cmd_vel_callback, 10)

        # TCP connection params
        self.tcp_ip = '192.168.0.50'   # your CAN PC IP
        self.tcp_port = 12345
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.connect((self.tcp_ip, self.tcp_port))

        # Robot geometry (meters)
        self.L = 0.49    # wheel separation
        self.R = 0.0625  # wheel radius

    def cmd_vel_callback(self, msg):
        v = msg.linear.x
        omega = msg.angular.z

        # differential drive kinematics
        v_left  = v - (self.L / 2.0) * omega
        v_right = v + (self.L / 2.0) * omega

        # Convert m/s to your motor units (example: ticks/sec)
        left_cmd  = int(v_left / (2 * math.pi * self.R) * 1000)  # scale factor placeholder
        right_cmd = int(v_right / (2 * math.pi * self.R) * 1000)

        # Format and send
        cmd_str = f"LEFTM: {left_cmd}\nRIGHTM: {right_cmd}\n"
        try:
            self.sock.sendall(cmd_str.encode())
        except Exception as e:
            self.get_logger().error(f"TCP send failed: {e}")

def main():
    rclpy.init()
    node = CmdVelToTCP()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
