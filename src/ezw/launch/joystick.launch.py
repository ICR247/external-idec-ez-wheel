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

    return LaunchDescription([

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

        # Teleop node to convert joystick -> Twist (/cmd_vel)
        Node(
            package='teleop_twist_joy',
            executable='teleop_node',
            name='teleop_twist_joy',
            output='screen',
            parameters=[{
                'axis_linear.x': 1,        # left stick vertical
                'scale_linear.x': 1.0,
                'axis_angular.yaw': 0,     # left stick horizontal
                'scale_angular.yaw': 2.0,
                'enable_button': 0         # optional: press button 0 to enable
            }]

        ),

        diff_drive,

    ])
