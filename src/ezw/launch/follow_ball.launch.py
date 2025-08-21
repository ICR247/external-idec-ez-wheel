# joy_teleop.launch.py
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():

    diff_drive = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory('swd_ros2_controllers'),
                'launch',
                'swd_diff_drive_controller.launch.py'
            )
        )
    )

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

        # launch realsense camera and object detection
        realsense_launch,
        Node(
            package='ezw_object_detector',
            executable='ezw_object_detector',
            output='screen',
        ),

        # Joystick driver
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            output='screen',
            parameters=[{
                # 'dev': '/dev/input/js0',   # joystick device
                'deadzone': 0.1,
                'autorepeat_rate': 20.0
            }]
        ),

        Node(
            package='ezw',
            executable='follow_ball',
            name='follow_ball',
            output='screen',
            remappings=[
                ('/detections', '/detections/json'),
                ('/cmd_vel', '/cmd_vel')
            ],
        ),

        diff_drive,

    ])
