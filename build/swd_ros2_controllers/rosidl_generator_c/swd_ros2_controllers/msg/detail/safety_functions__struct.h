// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from swd_ros2_controllers:msg/SafetyFunctions.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swd_ros2_controllers/msg/safety_functions.h"


#ifndef SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__STRUCT_H_
#define SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/SafetyFunctions in the package swd_ros2_controllers.
/**
  * This message provides information about CiA 402-4 CANopen safety drive functions.
  * True if the safety drive function is enabled.
 */
typedef struct swd_ros2_controllers__msg__SafetyFunctions
{
  std_msgs__msg__Header header;
  /// Safe Torque Off (STO)
  bool safe_torque_off;
  /// Safe Brake Control (SBC)
  bool safe_brake_control;
  /// Safety Limited Speed 1 (SLS_1)
  bool safety_limited_speed_1;
  /// Safety Limited Speed 2 (SLS_2)
  bool safety_limited_speed_2;
  /// Safe Direction Indication (positive)
  bool safe_direction_indication_forward;
  /// Safe Direction Indication (negative)
  bool safe_direction_indication_backward;
} swd_ros2_controllers__msg__SafetyFunctions;

// Struct for a sequence of swd_ros2_controllers__msg__SafetyFunctions.
typedef struct swd_ros2_controllers__msg__SafetyFunctions__Sequence
{
  swd_ros2_controllers__msg__SafetyFunctions * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swd_ros2_controllers__msg__SafetyFunctions__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__STRUCT_H_
