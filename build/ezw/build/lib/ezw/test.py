import rclpy
from rclpy.node import Node
import socket

class TcpCanClient(Node):
    def __init__(self):
        super().__init__('tcp_can_client')
        self.declare_parameter('robot_ip', '10.1.69.215')  # Change to embedded robot IP
        self.declare_parameter('robot_port', 5555)           # Port the embedded server listens on
        
        self.robot_ip = self.get_parameter('robot_ip').get_parameter_value().string_value
        self.robot_port = self.get_parameter('robot_port').get_parameter_value().integer_value
        
        self.get_logger().info(f"Connecting to robot at {self.robot_ip}:{self.robot_port}")
        
        # Connect to robot TCP socket
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            self.sock.connect((self.robot_ip, self.robot_port))
            self.get_logger().info("Connected to robot TCP server")
        except Exception as e:
            self.get_logger().error(f"Failed to connect: {e}")
            exit(1)
    
    def send_command(self, cmd_str):
        try:
            self.sock.sendall(cmd_str.encode('utf-8'))
            self.get_logger().info(f"Sent command: {cmd_str.strip()}")
        except Exception as e:
            self.get_logger().error(f"Failed to send command: {e}")

def main(args=None):
    rclpy.init(args=args)
    tcp_client = TcpCanClient()

    try:
        # Example simple interactive loop sending velocity commands
        while rclpy.ok():
            vel = input('Enter velocity int value (e.g., 1), or "exit": ')
            if vel.lower() == 'exit':
                break
            try:
                v = int(vel)
                cmd = f'SETVEL:{v}\n'  # Match embedded side command format
                tcp_client.send_command(cmd)
            except ValueError:
                tcp_client.get_logger().warn("Please enter a valid float number")
    except KeyboardInterrupt:
        pass
    
    tcp_client.sock.close()
    tcp_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
