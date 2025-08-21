# SWD-EZ-WHEEL ROS2 DRIVER SETUP

This project allows you to control a differential-drive robot using the SWD EZ-Wheels by using their swd_ros2_controllers.

Additionally, there is an extension that also allows you to track and follow objects with a depth perception camera. 

## Table of Contents

### On this page:
1. [Prerequisites](#prerequisites)
2. [ROS2 Wheel Driver Installation](#installation)
3. [Running the ROS2 Wheel Driver](#running-the-ros2-wheel-driver)
4. [Running the Follow Ball Program](#running-the-folloq-ball-program)
5. [Acknowledgements](#acknowledgements)

### Dedicated pages:
1. [Troubleshooting](./.docs/troubleshooting.md)


## Prerequisites
For just the differential drive:
   - Linux Ubuntu 24.04
   - CAN-to-USB converter ([recommended: RH02 USB-to-CAN Converter](https://www.amazon.com/Jhoinrch-Converter-Open-Source-Hardware-Operating/dp/B0CRB8KXWL))
For the object following program:
   - Depth Camera ([recommended: Intel RealSense D456](https://store.realsenseai.com/buy-intel-realsense-depth-camera-d456.html?srsltid=AfmBOoqkjm4JbCpeJVfGqdiTUsUTtYwASr900dfDDn8FJs0InGAz8mhW))


## ROS2 Wheel Driver Installation
1. [First install ROS2 Jazzy](https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debs.html) 

<br>

2. To properly install the swd_ros2_controllers package run these commmands. [link to original instructions](https://github.com/IDEC-ezWheel/swd_ros2_controllers)

Add ez-Wheel repository to your Apt sources configuration file. Then, download and add the GPG key. 
```bash
echo "deb http://packages.ez-wheel.com:8081/ubuntu/ $(lsb_release -cs) main" | sudo tee -a /etc/apt/sources.list
sudo bash -c "wget -qO - http://packages.ez-wheel.com:8081/archive.key | gpg --dearmor > /etc/apt/trusted.gpg.d/ez-wheel-keyring.gpg"
sudo apt-get update && sudo apt install swd-services
```

Then compile from source!
```bash
source /opt/ros/jazzy/setup.bash
mkdir -p ~/ros2_ws/src/
cd ~/ros2_ws/src/
git clone https://github.com/IDEC-ezWheel/swd_ros2_controllers.git
cd ..
colcon build
source ~/ros2_ws/install/setup.bash
```

<br>

3. Set up your IPC with the minimal SWD® Starter Kit config files 

```bash
sudo addgroup swd_sk
sudo useradd -m -s /bin/bash -g swd_sk swd_sk
sudo bash -c 'echo swd_sk:swd_sk | chpasswd'
sudo usermod -aG sudo swd_sk
```

Then log in with user swd_sk
```bash
su - swd_sk
```

Since the setup files are not supported on noble, you must modify your sources.list to point to the focal release (this still works in implementation so no worries)
```bash
echo "deb http://packages.ez-wheel.com:8081/ubuntu/ focal main" | sudo tee -a /etc/apt/sources.list
sudo bash -c "wget -qO - http://packages.ez-wheel.com:8081/archive.key | gpg --dearmor > /etc/apt/trusted.gpg.d/ez-wheel-keyring.gpg"
sudo apt-get update
sudo apt install swd-system-config-2wheels
```

4. Optionally disable/comment out the Focal repo afterward to avoid pulling unrelated packages from Focal.

5. This package will configure your system to start at boot up four new services (with user swd_sk account):

    - ezw-stack.service : initialize can0 
    - ezw-dbus-user-session : initialize D-Bus session
    - ezw-swd-left.service : start left D-Bus service
    - ezw-swd-right.service : start right D-Bus service

You must modify the ezw-stack and ezw-dbus-user-session startup order

For a system service, systemd reads override files from a drop-in directory:
```bash
sudo mkdir -p /etc/systemd/system/ezw-stack.service.d
sudo mkdir -p /etc/systemd/system/ezw-dbus-user-session.service.d
sudo nano /etc/systemd/system/ezw-stack.service.d/override.conf
```

```bash
# write this into the file
[Unit]
After=systemd-timesyncd.service
```

and similarly for the D-Bus session service:
```bash
sudo nano /etc/systemd/system/ezw-dbus-user-session.service.d/override.conf
```
```bash
# write this into the file
[Unit]
After=systemd-timesyncd.service
```

6. Then run the commissioning scripts that were installed into your system:

apply the commissioning using:

```bash
cd /opt/ezw/commissioning/
./swd_left_4_commissioning.py
./swd_right_5_commissioning.py
```

7. Restart the PC. The services may not be entirely properly configured at first so refer to the [troubleshooting]((./docs/troubleshooting.md)) section for more guidance. 

### This project is still in it's early development and testing phases so if there are any issues during installation, please create an issue and our team will look at it!



## Running the ROS2 Wheel Driver
Make sure your project is built
```bash
colcon build --symlink-install
```

This command allows the terminal to access the proper ezw libraries and runs the given swd_ros2_controllers launch file
```bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/ezw/usr/lib
ros2 launch swd_ros2_controllers swd_diff_drive_controller.launch.py
```

You should be able to run ros2 node list and see:
```bash
swd_ros2_controllers
```
or ros2 topic list and see topics such as:
```bash
/cmd_vel
/set_speed
/odom
...
```

Also, make sure you can make both wheels move using this command:
```bash
ros2 topic pub -r 10 /set_speed geometry_msgs/Point "{x: 10.0, y: 10.0, z: 0.0}"
```

If one of these doesn't work, please refer to our troubleshooting section or the issues pages on the original swd_ros2_controllers or swd_ros_controllers github. Even though swd_ros_controllers is meant for ROS1, it's still extremely insightful in how to debug the services and config files.  
[Troubleshooting]((./docs/troubleshooting.md))
[swd_ros2_controllers issues](https://github.com/IDEC-ezWheel/swd_ros2_controllers/issues)
[swd_ros_controllers issues](https://github.com/IDEC-ezWheel/swd_ros_controllers/issues)


## Running the Follow Ball Program

1. Install your camera SDK (Ex: librealsense)[https://github.com/IntelRealSense/librealsense]

For an Intel camera, install the required packages
```bash
sudo apt update
sudo apt install git cmake build-essential libusb-1.0-0-dev pkg-config libssl-dev libudev-dev libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev
```

Clone the SDK
```bash
git clone https://github.com/IntelRealSense/librealsense.git
cd librealsense
```

Setup udev rules
```bash
./scripts/setup_udev_rules.sh
```

Configure and build
```bash
mkdir build && cd build
cmake ../ -DCMAKE_BUILD_TYPE=Release -DFORCE_RSUSB_BACKEND=true
make -j$(nproc)
sudo make install
```

Verify installation by connecting camera and running
```bash
realsense-viewer
```

2. Reboot computer

3. Make virtual environment
```bash
python3 -m venv ~/yolovenv
source ~/yolovenv/bin/activate
pip install --upgrade pip
```

4. Install Ultralytics (make sure all dependencies are met)
```bash
pip install ultralytics
```
verify install
```bash
yolo --version
```

5. Add environment variable that Python checks to know where to search for modules and packages in addition to the default locations.
```bash
export PYTHONPATH=~/yolovenv/lib/python3.12/site-packages:$PYTHONPATH
```

6. Make sure the object-detector, ezw, and ros2_controler packages are built
```bash
colcon build --symlink-install
```

6. Run launch file 
```bash
export PYTHONPATH=~/yolovenv/lib/python3.12/site-packages:$PYTHONPATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/ezw/usr/lib
ros2 launch ezw follow_ball.launch.py 
```

## Acknowledgments 

<img src="https://github.com/ivanrulik.png" alt="Ivan Rulik" width="50"/>

[Ivan Rulik](https://github.com/ivanrulik)  

<img src="https://github.com/annwilkowski.png" alt="Anna Wilkowski" width="50"/>

[Anna Wilkowski](https://github.com/annwilkowski)  

<img src="https://github.com/jmshim2.png" alt="Jung Moo Shim" width="50"/>

[Jung Moo Shim](https://github.com/jmshim2)  


