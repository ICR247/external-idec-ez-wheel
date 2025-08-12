import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ezw',  # change to your package name
            executable='object_detector', # or entry_point if using setup.py
            output='screen',
            parameters=[{
                "color_topic": "camera/camera/color/image_raw",
                "depth_topic": "camera/camera/depth/image_rect_raw",
                "model_path": "yolov8n.pt",
                "imgsz": 640,
                "conf_thres": 0.25,
                "depth_scale": 0.001,
            }],
        )
    ])
