from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

# ros2 launch ezw follow_person.launch.py

def generate_launch_description():
    realsense_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory('realsense2_camera'),
                'launch',
                'rs_launch.py'
            )
        )
    )

    return LaunchDescription([
        realsense_launch,
        Node(
            package='ezw',
            executable='object_detector',
            output='screen',
            # env={
            #     'PYTHONPATH': '/home/icr247/ros2-yolo-venv/lib/python3.12/site-packages:$PYTHONPATH',
            #     'PATH': '/home/icr247/ros2-yolo-venv/bin:$PATH'
            # }
        ),
        Node(
            package='ezw',
            executable='follow_person',
            output='screen',
            # env={
            #     'PYTHONPATH': '/home/icr247/ros2-yolo-venv/lib/python3.12/site-packages:$PYTHONPATH',
            #     'PATH': '/home/icr247/ros2-yolo-venv/bin:$PATH'
            # }
        ),
    ])