import can
import canopen
import time


def read_statusword_from_eds(node_id, eds_path, can_interface='can0'):
    # Set up CANopen network
    network = canopen.Network()
    network.connect(channel=can_interface, bustype='socketcan')

    # Add node using EDS file
    node = canopen.RemoteNode(node_id, eds_path)
    network.add_node(node)

    try:
        print(f"Sending NMT Start to node {node_id:#02x}")
        node.nmt.state = 'OPERATIONAL'
        time.sleep(0.1)

        # Read the statusword from object dictionary (0x6041:00)
        statusword = node.sdo[0x2101].raw
        print(f"Statusword: 0x{statusword:04X}")
        return statusword

    except canopen.SdoAbortedError as e:
        print(f"SDO Aborted: {e}")
        return None
    except Exception as e:
        print(f"Error communicating with node {node_id:#02x}: {e}")
        return None
    finally:
        network.disconnect()


if __name__ == '__main__':
    node_id = 0x05
    eds_path = '/opt/ezw/usr/etc/ezw-canopen-dico/swd_core.eds'  # Replace with path to your EDS file
    read_statusword_from_eds(node_id, eds_path)