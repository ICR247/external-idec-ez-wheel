# TCP Joystick Control for Differential Drive Robot

This ROS 2 Python node allows you to control a differential-drive robot over a TCP socket using a USB joystick (e.g., Xbox controller). The joystick inputs are converted into left and right motor velocity commands using a simple kinematic model, and sent to the robot over a TCP connection.


---

## 📦 Package Name

```
ezw
```

---

## 🧰 Requirements

- ROS 2 (Tested on Jazzy)
- Python 3
- A joystick (e.g., Xbox controller) recognized by `joy_node`
- Running TCP server on the embedded robot side
- Proper motor command handling on robot: expects messages like  

```
LEFTM:<velocity>\n
RIGHTM:<velocity>\n
```


---

## ⚙️ Parameters

You can override these using launch files or command-line args:

| Parameter     | Type   | Default         | Description                    |
|---------------|--------|-----------------|--------------------------------|
| `robot_ip`    | String | `10.1.69.215`   | IP address of robot            |
| `robot_port`  | Int    | `5555`          | TCP port the robot listens on  |

---

## 🚀 How to Run

### 1. Start the ROS 2 joystick node

```bash
ros2 run joy joy_node
```
This will publish messages to /joy.

### 2. Run the TCP joystick control node

Make sure you're in your workspace and have sourced the setup script:

```bash
ros2 run ezw tcp_can_diff_client
```

---

## 🎮 Control Scheme

| Joystick Input        | Behavior         |
| --------------------- | ---------------- |
| Left stick up/down    | Linear velocity  |
| Left stick left/right | Angular velocity |


The code uses the left stick to calculate forward/backward motion and turning by mapping axis values to wheel speeds.

---

## 🤖 Differential Drive Model

Based on the following equations:
```
v_left  = v - (L / 2.0) * omega
v_right = v + (L / 2.0) * omega
```
Where:

    L = 0.49 m (distance between wheels)

    R = 0.0625 m (wheel radius)

    v is forward velocity (from joystick Y)

    omega is rotational velocity (from joystick X)

Currently, the joystick inputs are linearly mapped to motor speeds up to ±500 or ±300 depending on context. For more accurate physical control, this model can be directly integrated.


## 🧠 Debugging

    Make sure the embedded device is correctly parsing the TCP commands.

    The joystick axes may differ depending on the controller — you can run ros2 topic echo /joy to inspect them.

    Adjust scaling factors (500, 300) to match your robot's safe speed limits.

📜 License

MIT (or your preferred license — update in package.xml)
👤 Authors

Anna Wilkowski
Email: annmarywil@gmail.com
GitHub: annwilkowski

Jung Shim
Email: 0325jms12@gmail.com
GitHub: jmshim2


---

Let me know if you want to include a launch file, diagram, or actual joystick-to-velocity math implementation (`v` and `omega` conversion).

