from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

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

    # nav2 = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource(
    #         os.path.join(
    #             get_package_share_directory('nav2_bringup'),
    #             'launch',
    #             'bringup_launch.py'
    #         )
    #     ),
    #     launch_arguments={
    #         'use_sim_time': 'false',
    #         'params_file': '/home/icr247/external-idec-ez-wheel/src/ezw/params/nav2_params.yaml'
    #     }.items()
    # )


    return LaunchDescription([
        
        realsense_launch,

        # Depth to LaserScan conversion
        Node(
            package='depthimage_to_laserscan',
            executable='depthimage_to_laserscan_node',
            name='depth_to_scan',
            output='screen',
            parameters=[{
                'scan_height': 10,
                'output_frame_id': 'camera_link',
                'range_min': 0.2,
                'range_max': 4.0
            }],
            remappings=[
                ('/depth', '/camera/camera/depth/image_rect_raw'),
                ('/depth_camera_info', '/camera/camera/depth/camera_info'),
                ('/scan', '/scan')
            ],
            
        ),

         # Fake odometry TF: odom -> base_link
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments=['0', '0', '0', '0', '0', '0', 'odom', 'base_link'],
            output='screen'
        ),

        # Fake TF: base_link -> camera_link
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments=['0', '0', '0', '0', '0', '0', 'base_link', 'camera_link'],
            output='screen'
        ),

        # SLAM Toolbox mapping
        Node(
            package='slam_toolbox',
            executable='sync_slam_toolbox_node',
            name='slam_toolbox',
            output='screen',
            parameters=[{
                # 'mode': 'mapping',
                # 'map_file_name': 'my_map',
                'resolution': 0.05,
                # 'scan_topic': '/scan',
                'use_sim_time': False,
                'transform_publish_period': 0.02,
                'map_update_interval': 5.0,
                'publish_tf': True,
                'map_frame': 'map',
                'odom_frame': 'odom',
                'base_frame': 'base_link' 
            }],
            remappings=[
                ('scan', '/scan')
            ],
            #ros_arguments=['--log-level', 'debug']
        ),

        # Lifecycle manager for SLAM Toolbox
        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_slam',
            output='screen',
            parameters=[{
                'use_sim_time': False,
                'autostart': True,
                'node_names': ['slam_toolbox']
            }]
        )


        # Launch Navigation stack
        # nav2 

        # set up joystick control
        # Node(
        #     package= 'ezw',
        #     executable='diff_drive',
        #     output='screen',
        # ),

        # Node(
        #     package='joy',
        #     executable='joy_node',
        #     output='screen',
        # ),
    ])
