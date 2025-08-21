import canopen
import time

def send_velocity_via_sdo(motor1_id, motor2_id, eds_path, can_interface='can0'):
    network = canopen.Network()
    network.connect(channel=can_interface, bustype='socketcan')
    
    motor1 = canopen.RemoteNode(motor1_id, eds_path)
    network.add_node(motor1)

    # motor2 = canopen.RemoteNode(motor2_id, eds_path)
    # network.add_node(motor2)
    
    try:
        # Enable the drive first
        # node.sdo[0x6040].raw = 0x000F  # Control word: operation enabled
        # time.sleep(0.1)
        

        # turn on and off 
        for _ in range(5):

            # Set target velocity
            motor1.sdo[0x6042].raw = int(500)  # Target velocity
            # motor2.sdo[0x6042].raw = int(500)  # Target velocity
        
            print(f"motor on to node {motor1_id:#02x} and {motor2_id:#02x}")

            time.sleep(3)

            motor1.sdo[0x6042].raw = int(0)  # Target velocity
            # motor2.sdo[0x6042].raw = int(0)  # Target velocity

            print(f"motor off to node {motor1_id:#02x} and {motor2_id:#02x}")

            time.sleep(3)

        
    except Exception as e:
        print(f"Error: {e}")
    finally:
        network.disconnect()

# Run the function
send_velocity_via_sdo(motor1_id=0x04, motor2_id=0x05, eds_path='/opt/ezw/usr/etc/ezw-canopen-dico/swd_core.eds')