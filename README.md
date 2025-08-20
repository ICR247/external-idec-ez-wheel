# SWD-EZ-WHEEL ROS2 DRIVER SETUP

This project allows you to control a differential-drive robot using swd_ros2_controllers. 

## Table of Contents

### On this page:
1. [Prerequisites](#prerequisites)
3. [Installation](#installation)
4. [Running the Project](#running-the-project)
5. [Acknowledgements](#acknowledgements)

### Dedicated pages:
1. [Troubleshooting](./.docs/troubleshooting.md)
 <!-- . [License](#license) -->



## Prerequisites
   - Linux Ubuntu 24.04
   - CAN-to-USB converter ([recommended: RH02 USB-to-CAN Converter](https://www.amazon.com/Jhoinrch-Converter-Open-Source-Hardware-Operating/dp/B0CRB8KXWL))


## Installation
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



## Running the Project
This command allows the terminal to access the proper ezw libraries and runs the given swd_ros2_controllers launch file
```bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/ezw/usr/lib
ros2 launch swd_ros2_controllers swd_diff_drive_controller.launch.py
```

you should be able to run ros2 node list and see:
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

also, make sure you can make both wheels move using this command:
```bash
ros2 topic pub -r 10 /set_speed geometry_msgs/Point "{x: 10.0, y: 10.0, z: 0.0}"
```

If one of these doesn't work, please refer to our troubleshooting section or the issues pages on the original swd_ros2_controllers or swd_ros_controllers github. Even though swd_ros_controllers is meant for ROS1, it's still extremely insightful in how to debug the services and config files.  
[Troubleshooting]((./docs/troubleshooting.md))
[swd_ros2_controllers issues](https://github.com/IDEC-ezWheel/swd_ros2_controllers/issues)
[swd_ros_controllers issues](https://github.com/IDEC-ezWheel/swd_ros_controllers/issues)

## Acknowledgments 

<img src="https://github.com/ivanrulik.png" alt="Ivan Rulik" width="50"/>

[Ivan Rulik](https://github.com/ivanrulik)  

<img src="https://github.com/annwilkowski.png" alt="Anna Wilkowski" width="50"/>

[Anna Wilkowski](https://github.com/annwilkowski)  

<img src="https://github.com/jmshim2.png" alt="Jung Moo Shim" width="50"/>

[Jung Moo Shim](https://github.com/jmshim2)  


