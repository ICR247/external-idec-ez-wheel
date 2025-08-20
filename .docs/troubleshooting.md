# Troubleshooting

If you're having problems setting up your IDED EZ-Wheel Starterkit Robot, you've come to the right page

## Table of Contents

### On this page:
1. Troubleshooting
   - [CAN not setup properly](#can-not-setup-properly)
   - [Commissioning scripts failed](#commissioning-scripts-failed)
   - [Motors are assigned to the same CAN NodeID](#motors-are-assigned-to-the-same-can-nodeid)
   - [NMT is not OK](#nmt-is-not-ok)
2. [Other Resources](#other-resources)


## CAN not setup properly

If you run:
```bash
candump can0
```
and get no output, your CAN bus is not set up correctly. 

Try: 

unplug and replug can adapter 
restart services one by one (restarting them all together could throw errors)


## Commissioning scripts failed

make sure all your setup scripts are running (RUN ONE BY ONE)
```bash
sudo systemctl restart ezw-stack.service
sudo systemctl restart ezw-dbus-user-session.service
sudo systemctl restart ezw-swd-left.service 
sudo systemctl restart ezw-swd-right.service
```

check can connection with
```bash
candump can0
```
if you're receiving data check:
```bash
candump can0 | grep 7 
```
check that you can see messages coming from 704, 705, 706, and 707

if you don't see 704 or 705, refer to [this section](#motors-are-assigned-to-the-same-can-nodeid)

if you don't see 706 or 707, your setup scripts are not launching the dbus clients correctly. I haven't encountered this issue so you're going to have to debug it yourself, but let me try to point you in the right direction. 
Check if your services are running: 
```bash
sudo systemctl status ezw-stack.service
sudo systemctl status ezw-dbus-user-session.service
sudo systemctl status ezw-swd-left.service 
sudo systemctl status ezw-swd-right.service
```

If they are, check the logs such as sce-swd-right.log in the /tmp/ folder of your computer. But don't get caught up with these messages:
```bash
Exporting following variables :
DBUS_SESSION_BUS_ADDRESS=unix:path=/tmp/dbus-CPWGxHqyAC,guid=05654f95b7c5de2e7e94698368a5ec9c
DBUS_SESSION_BUS_PID=5092
2025-8-20 15:41:16;SMCS;SMCDS;WARN;load;44;Config;Invalid type for SWCompatibilityFile;
2025-8-20 15:41:16;SMCS;COS;WARN;loadNodes;43;CANOpenNodeCollectionFactory;No Node file specified !;
2025-8-20 15:41:16;SMCS;SMCDS;ERROR;main;180;SMCService : Controller::getCoreVersion() return error code : 1;
2025-8-20 15:41:16;SMCS;CAN;WARN;ezw_can_process;541;<ezw-can> process : Reader thread stopped, restarting it;
```
I'm pretty sure they're always there even when it works so don't worry about it too much. Look for things like SDO timouts after 5 retry's, etc. 



## Motors are assigned to the same CAN NodeID

This is an easy fix. But first confirm your nodes are assigned to the same ID's. 
check:
```bash
candump can0 | grep 7 
```
if you only see one of 704 or 705 and don't see the other, this is a very telling sign. 

To make sure run these commands and view their output: 
```bash 
$ python3 /opt/ezw/usr/sbin/remote.py swd_right
DBUS Instance        : swd_left ..................................................................... [OK]
Core Version         : 0.3.0-2d28735 ................................................................ [OK]
Node ID              : 0x4 .......................................................................... [OK]
RT activated         : True ......................................................................... [OK]
CAN device           : can0 ......................................................................... [OK]
Vendor-Id            : 0x515 ........................................................................ [OK]
Product code         : 0x3 .......................................................................... [OK]
Serial number        : 25009SC001A1 ................................................................. [OK]
Revision number      : 131072 ....................................................................... [OK]
SWVersion            : 2.0.2 ........................................................................ [OK]
HWVersion            : 0.0.8 ........................................................................ [OK]
Calibrated           : True ......................................................................... [OK]
SRDO validity        : True ......................................................................... [OK]
NMT state on error   : 1 ............................................................................ [OK]
NMT State            : OPER  ........................................................................ [OK]
PDS State            : OPERATION_ENABLED  ........................................................... [OK]
NbError              : 0 ............................................................................ [OK]
LastError            : 0 : Error_reset_or_no_error .................................................. [OK]
SystemError          : EZW_PROTECT_NONE EZW_PROTECT_NONE  ........................................... [OK]
SSW CAN1             : False, False, False, False, False, False, False, False  ...................... [OK]
SSW CAN2             : False, False, False, False, False, False, False, False  ...................... [OK]
SSW CAN3             : False, False, False, False, False, False, False, False  ...................... [OK]
SSW CAN4             : False, False, False, False, False, False, False, False  ...................... [OK]
SSW CAN5             : False, False, False, False, False, False, False, False  ...................... [OK]
SSW CAN6             : False, False, False, False, False, False, False, False  ...................... [OK]
SSW CAN7             : False, False, False, False, False, False, False, False  ...................... [OK]
SSW CAN8             : False, False, False, False, False, False, False, False  ...................... [OK]
SSW SAFEOUT          : False, False, False, False, False, False, False, False  ...................... [OK]
SCW SAFEIN_1         : True, True, True, True, False, False, True, True  ............................ [OK]
Peripheral           : True, True, True, True, True, True  .......................................... [OK]
VelocityModeSW       : internal_limit_active: False ................................................. [OK]
VelocityModeCW       : enable_ramp: False, unlock_ramp: False, reference_ramp: False, halt: False ... [OK]
Polarity             : velocity_polarity: True, position_polarity: True ............................. [OK]
TargetVelocity       : 0 ............................................................................ [OK]
VelocityDemand       : 0 ............................................................................ [OK]
VelocityActualValue  : 0 ............................................................................ [OK]
PositionValue        : 1 ............................................................................ [OK]
OdometryValue        : 0 ............................................................................ [OK]
<COM> Connect NodeId = i Disconnect = d Restore param = j Change current NodeId = g
<NMT> RESET_NODE = r Start all = m
<PDS> Go to OPERATION_ENABLED = o
<VL mode> target velocity (500) = +/- positive order = 8 negative order = 2 stop = *
<Param> STO_ACK off/on = f/n
<Mode> local = w remote = z
<Diagnostic> a
<EMCY> get full EMCY list = e, clear EMCY list = c
<SW> s
<quit> 0

$ python3 /opt/ezw/usr/sbin/remote.py swd_right
SYSTEMCTL_dbus.id detected
DBUS Instance        : swd_right .................................................................... [OK]
Core Version         : 0.3.0-2d28735 ................................................................ [OK]
Node ID              : 0x0 .......................................................................... [KO]
RT activated         : False ........................................................................ [KO]
CAN device           : can0 ......................................................................... [OK]
Vendor-Id            : 0x0 .......................................................................... [KO]
Product code         : 0x0 .......................................................................... [KO]
Serial number        : XXXXXXXXXXXX ................................................................. [KO]
Revision number      : 0 ............................................................................ [KO]
SWVersion            :  ............................................................................. [KO]
HWVersion            :  ............................................................................. [KO]
Calibrated           : False ........................................................................ [KO]
SRDO validity        : False ........................................................................ [KO]
NMT state on error   : 0 ............................................................................ [KO]
NMT State            : UNKNOWN  ..................................................................... [OK]
PDS State            : NOT_READY_TO_SWITCH_ON  ...................................................... [KO]
NbError              : 0 ............................................................................ [KO]
LastError            : 0 : Error_reset_or_no_error .................................................. [OK]
SystemError          : EZW_PROTECT_NONE EZW_PROTECT_NONE  ........................................... [KO]
SSW CAN1             : False, False, False, False, False, False, False, False  ...................... [KO]
SSW CAN2             : False, False, False, False, False, False, False, False  ...................... [KO]
SSW CAN3             : False, False, False, False, False, False, False, False  ...................... [KO]
SSW CAN4             : False, False, False, False, False, False, False, False  ...................... [KO]
SSW CAN5             : False, False, False, False, False, False, False, False  ...................... [KO]
SSW CAN6             : False, False, False, False, False, False, False, False  ...................... [KO]
SSW CAN7             : False, False, False, False, False, False, False, False  ...................... [KO]
SSW CAN8             : False, False, False, False, False, False, False, False  ...................... [KO]
SSW SAFEOUT          : False, False, False, False, False, False, False, False  ...................... [KO]
SCW SAFEIN_1         : False, False, False, False, False, False, False, False  ...................... [KO]
Peripheral           : False, False, False, False, False, False  .................................... [KO]
VelocityModeSW       : internal_limit_active: False ................................................. [KO]
VelocityModeCW       : enable_ramp: False, unlock_ramp: False, reference_ramp: False, halt: False ... [KO]
Polarity             : velocity_polarity: False, position_polarity: False ........................... [KO]
TargetVelocity       : 0 ............................................................................ [KO]
VelocityDemand       : 0 ............................................................................ [KO]
VelocityActualValue  : 0 ............................................................................ [KO]
PositionValue        : 0 ............................................................................ [KO]
OdometryValue        : 0 ............................................................................ [KO]
<COM> Connect NodeId = i Disconnect = d Restore param = j Change current NodeId = g
<NMT> RESET_NODE = r Start all = m
<PDS> Go to OPERATION_ENABLED = o
<VL mode> target velocity (500) = +/- positive order = 8 negative order = 2 stop = *
<Param> STO_ACK off/on = f/n
<Mode> local = w remote = z
<Diagnostic> a
<EMCY> get full EMCY list = e, clear EMCY list = c
<SW> s
<quit> 0
```

re-run the script for the wheel that appears entirely green (OK). Watch the flashing lights on the wheels very closely and press "m", then "o", and then "a". If you see both drivers lights stabilize, this means your commands reached both wheels and enabled NMT and PDS. 

<br>

To fix this, we will disconnect the wheel that is configured to the correct NodeID. Unplug the CANopen wire of tyhe correct wheel from the SWD Safety Hub. To figure out which wire goes to which motor, look at page 15 of this [manual](https://www.ez-wheel.com/storage/upload/pdf/swd-starter-kit-v5-04042024-instruction-manual-en.pdf).  

Now that you have only the motor that you need to configure connected, run this command again, but replace "right" with the wheel that was CONFIGURED CORRECTLY. 
```bash
python3 /opt/ezw/usr/sbin/remote.py swd_right
```

Press "g" and enter the NodeID you want to cofigure the connected motor to. (right nodeid = 5, left nodeid = 4)
Rerun the python script to verify the change. 
Reconnect the other motors CANopen connector. 

Then restart the services so that the dbus clients connect to the correct NodeID:
```bash
sudo systemctl restart ezw-stack.service
sudo systemctl restart ezw-dbus-user-session.service
sudo systemctl restart ezw-swd-left.service 
sudo systemctl restart ezw-swd-right.service
```
and re-run the commissioning scripts: 
```bash
cd /opt/ezw/commissioning/
./swd_left_4_commissioning.py
./swd_right_5_commissioning.py
```

Now you should see both nodes (704 and 705) on candump and when you run 
```bash
$ python3 /opt/ezw/usr/sbin/remote.py swd_right
$ python3 /opt/ezw/usr/sbin/remote.py swd_left
```
you should see the NodeId listed for both and a lot more green!


## NMT is not OK 

You know you have this error when you try launching the ROS2 node and the latest message in the terminal is:
```bash
[swd_diff_drive_controller-1] [INFO] [1755704575.551104021] [swd_diff_drive_controller]: NMT state machine is not OK.
[swd_diff_drive_controller-1] [INFO] [1755704576.052402683] [swd_diff_drive_controller]: PDS state machine is not OK.
```

I hate this error the most, but just make sure you followed Step 5 in Installation process. It's never to late to configure the scripts correctly. If doing that and restarting the computer doesn't work, try commenting out these lines in the commissioning scripts:

```python3
update_SRDO_parameters()
commissioning.update_STO_parameters(restart_acknowledge_behavior)
commissioning.update_SLS_parameters(sls_vl_limit, sls_vl_time_monitoring)
```
and re-running commissioning.


If that doesn't work try ChatGPT and looking at the other debugging resources listed further below and Good Luck, this ones a toughie! ;) 


## Other Resources
If these aren't helpful, please refer to the issues pages on the original swd_ros2_controllers or swd_ros_controllers github. Even though swd_ros_controllers is meant for ROS1, it's still extremely insightful in how to debug the services and config files.  
[swd_ros2_controllers issues](https://github.com/IDEC-ezWheel/swd_ros2_controllers/issues)
[swd_ros_controllers issues](https://github.com/IDEC-ezWheel/swd_ros_controllers/issues)

### This project is still in it's early development and testing phases so if there are any issues during troubleshooting, please create an issue and our team will look at it!