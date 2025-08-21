# This message provides information about CiA 402-4 CANopen safety drive functions.
# True if the safety drive function is enabled.

std_msgs/Header header
bool safe_torque_off                        # Safe Torque Off (STO)
bool safe_brake_control                     # Safe Brake Control (SBC)
bool safety_limited_speed_1                 # Safety Limited Speed 1 (SLS_1)
bool safety_limited_speed_2                 # Safety Limited Speed 2 (SLS_2)
bool safe_direction_indication_forward      # Safe Direction Indication (positive)
bool safe_direction_indication_backward     # Safe Direction Indication (negative)

# The main safe drive function is the STO whereby the immediately torque-off on the motor may be accompanied by an SBC command to close the brakes. 
# The SLS functions cause the drive to decelerate (if required) and monitor whether the velocity is held within the defined limits.
# The functions SDIp and SDIn enable the motor movement only in the corresponding (positive or negative) direction. 