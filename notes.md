# Annas notes

# running the camera with depth perception
ros2 run realsense2_camera realsense2_camera_node \
    --ros-args \
    -p pointcloud.enable:=true

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

