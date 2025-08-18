# Annas notes

# running the camera with depth perception
ros2 launch realsense2_camera rs_launch.py

# running object detection
make sure global path is set to virtual environment
ros2 run ezw object_detector
ros2 run rqt_image_view rqt_image_view

# creating virtual environment
cd ~
python3 -m venv ros2-yolo-venv
source ~/ros2-yolo-venv/bin/activate
which python3


sudo apt install python3-opencv ros-<distro>-cv-bridge

pip install ultralytics
pip install 'numpy<2'

# sourcing

source /opt/ros/jazzy/setup.bash
source ~/external-idec-ez-wheel/install/setup.bash

# how to make SLAM /map topic appear
ros2 lifecycle set /slam_toolbox configure
ros2 lifecycle set /slam_toolbox activate

# how to fix dbus library issue with swd_ros2_controllers

locate libCommonAPI-DBus.so.3.1.12
sudo sh -c 'echo "/opt/ezw/usr/lib" > /etc/ld.so.conf.d/ezw.conf'
sudo ldconfig
ldconfig -p | grep libCommonAPI-DBus


# how to check can0 status
ip -det link show can0


