// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from swd_ros2_controllers:msg/SafetyFunctions.idl
// generated code does not contain a copyright notice
#ifndef SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "swd_ros2_controllers/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "swd_ros2_controllers/msg/detail/safety_functions__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
bool cdr_serialize_swd_ros2_controllers__msg__SafetyFunctions(
  const swd_ros2_controllers__msg__SafetyFunctions * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
bool cdr_deserialize_swd_ros2_controllers__msg__SafetyFunctions(
  eprosima::fastcdr::Cdr &,
  swd_ros2_controllers__msg__SafetyFunctions * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
size_t get_serialized_size_swd_ros2_controllers__msg__SafetyFunctions(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
size_t max_serialized_size_swd_ros2_controllers__msg__SafetyFunctions(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
bool cdr_serialize_key_swd_ros2_controllers__msg__SafetyFunctions(
  const swd_ros2_controllers__msg__SafetyFunctions * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
size_t get_serialized_size_key_swd_ros2_controllers__msg__SafetyFunctions(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
size_t max_serialized_size_key_swd_ros2_controllers__msg__SafetyFunctions(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, swd_ros2_controllers, msg, SafetyFunctions)();

#ifdef __cplusplus
}
#endif

#endif  // SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
