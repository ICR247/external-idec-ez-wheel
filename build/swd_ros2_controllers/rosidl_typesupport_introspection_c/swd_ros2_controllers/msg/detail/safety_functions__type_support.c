// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from swd_ros2_controllers:msg/SafetyFunctions.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "swd_ros2_controllers/msg/detail/safety_functions__rosidl_typesupport_introspection_c.h"
#include "swd_ros2_controllers/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "swd_ros2_controllers/msg/detail/safety_functions__functions.h"
#include "swd_ros2_controllers/msg/detail/safety_functions__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swd_ros2_controllers__msg__SafetyFunctions__init(message_memory);
}

void swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_fini_function(void * message_memory)
{
  swd_ros2_controllers__msg__SafetyFunctions__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_message_member_array[7] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swd_ros2_controllers__msg__SafetyFunctions, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "safe_torque_off",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swd_ros2_controllers__msg__SafetyFunctions, safe_torque_off),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "safe_brake_control",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swd_ros2_controllers__msg__SafetyFunctions, safe_brake_control),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "safety_limited_speed_1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swd_ros2_controllers__msg__SafetyFunctions, safety_limited_speed_1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "safety_limited_speed_2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swd_ros2_controllers__msg__SafetyFunctions, safety_limited_speed_2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "safe_direction_indication_forward",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swd_ros2_controllers__msg__SafetyFunctions, safe_direction_indication_forward),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "safe_direction_indication_backward",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swd_ros2_controllers__msg__SafetyFunctions, safe_direction_indication_backward),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_message_members = {
  "swd_ros2_controllers__msg",  // message namespace
  "SafetyFunctions",  // message name
  7,  // number of fields
  sizeof(swd_ros2_controllers__msg__SafetyFunctions),
  false,  // has_any_key_member_
  swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_message_member_array,  // message members
  swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_init_function,  // function to initialize message memory (memory has to be allocated)
  swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_message_type_support_handle = {
  0,
  &swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_message_members,
  get_message_typesupport_handle_function,
  &swd_ros2_controllers__msg__SafetyFunctions__get_type_hash,
  &swd_ros2_controllers__msg__SafetyFunctions__get_type_description,
  &swd_ros2_controllers__msg__SafetyFunctions__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swd_ros2_controllers
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swd_ros2_controllers, msg, SafetyFunctions)() {
  swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_message_type_support_handle.typesupport_identifier) {
    swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swd_ros2_controllers__msg__SafetyFunctions__rosidl_typesupport_introspection_c__SafetyFunctions_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
