// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from swd_ros2_controllers:msg/SafetyFunctions.idl
// generated code does not contain a copyright notice
#include "swd_ros2_controllers/msg/detail/safety_functions__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "swd_ros2_controllers/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "swd_ros2_controllers/msg/detail/safety_functions__struct.h"
#include "swd_ros2_controllers/msg/detail/safety_functions__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_swd_ros2_controllers
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_swd_ros2_controllers
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_swd_ros2_controllers
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_swd_ros2_controllers
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_swd_ros2_controllers
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_swd_ros2_controllers
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_swd_ros2_controllers
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_swd_ros2_controllers
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _SafetyFunctions__ros_msg_type = swd_ros2_controllers__msg__SafetyFunctions;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
bool cdr_serialize_swd_ros2_controllers__msg__SafetyFunctions(
  const swd_ros2_controllers__msg__SafetyFunctions * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: safe_torque_off
  {
    cdr << (ros_message->safe_torque_off ? true : false);
  }

  // Field name: safe_brake_control
  {
    cdr << (ros_message->safe_brake_control ? true : false);
  }

  // Field name: safety_limited_speed_1
  {
    cdr << (ros_message->safety_limited_speed_1 ? true : false);
  }

  // Field name: safety_limited_speed_2
  {
    cdr << (ros_message->safety_limited_speed_2 ? true : false);
  }

  // Field name: safe_direction_indication_forward
  {
    cdr << (ros_message->safe_direction_indication_forward ? true : false);
  }

  // Field name: safe_direction_indication_backward
  {
    cdr << (ros_message->safe_direction_indication_backward ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
bool cdr_deserialize_swd_ros2_controllers__msg__SafetyFunctions(
  eprosima::fastcdr::Cdr & cdr,
  swd_ros2_controllers__msg__SafetyFunctions * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: safe_torque_off
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->safe_torque_off = tmp ? true : false;
  }

  // Field name: safe_brake_control
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->safe_brake_control = tmp ? true : false;
  }

  // Field name: safety_limited_speed_1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->safety_limited_speed_1 = tmp ? true : false;
  }

  // Field name: safety_limited_speed_2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->safety_limited_speed_2 = tmp ? true : false;
  }

  // Field name: safe_direction_indication_forward
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->safe_direction_indication_forward = tmp ? true : false;
  }

  // Field name: safe_direction_indication_backward
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->safe_direction_indication_backward = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
size_t get_serialized_size_swd_ros2_controllers__msg__SafetyFunctions(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SafetyFunctions__ros_msg_type * ros_message = static_cast<const _SafetyFunctions__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: safe_torque_off
  {
    size_t item_size = sizeof(ros_message->safe_torque_off);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: safe_brake_control
  {
    size_t item_size = sizeof(ros_message->safe_brake_control);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: safety_limited_speed_1
  {
    size_t item_size = sizeof(ros_message->safety_limited_speed_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: safety_limited_speed_2
  {
    size_t item_size = sizeof(ros_message->safety_limited_speed_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: safe_direction_indication_forward
  {
    size_t item_size = sizeof(ros_message->safe_direction_indication_forward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: safe_direction_indication_backward
  {
    size_t item_size = sizeof(ros_message->safe_direction_indication_backward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
size_t max_serialized_size_swd_ros2_controllers__msg__SafetyFunctions(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: safe_torque_off
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: safe_brake_control
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: safety_limited_speed_1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: safety_limited_speed_2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: safe_direction_indication_forward
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: safe_direction_indication_backward
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = swd_ros2_controllers__msg__SafetyFunctions;
    is_plain =
      (
      offsetof(DataType, safe_direction_indication_backward) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
bool cdr_serialize_key_swd_ros2_controllers__msg__SafetyFunctions(
  const swd_ros2_controllers__msg__SafetyFunctions * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: safe_torque_off
  {
    cdr << (ros_message->safe_torque_off ? true : false);
  }

  // Field name: safe_brake_control
  {
    cdr << (ros_message->safe_brake_control ? true : false);
  }

  // Field name: safety_limited_speed_1
  {
    cdr << (ros_message->safety_limited_speed_1 ? true : false);
  }

  // Field name: safety_limited_speed_2
  {
    cdr << (ros_message->safety_limited_speed_2 ? true : false);
  }

  // Field name: safe_direction_indication_forward
  {
    cdr << (ros_message->safe_direction_indication_forward ? true : false);
  }

  // Field name: safe_direction_indication_backward
  {
    cdr << (ros_message->safe_direction_indication_backward ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
size_t get_serialized_size_key_swd_ros2_controllers__msg__SafetyFunctions(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SafetyFunctions__ros_msg_type * ros_message = static_cast<const _SafetyFunctions__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: safe_torque_off
  {
    size_t item_size = sizeof(ros_message->safe_torque_off);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: safe_brake_control
  {
    size_t item_size = sizeof(ros_message->safe_brake_control);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: safety_limited_speed_1
  {
    size_t item_size = sizeof(ros_message->safety_limited_speed_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: safety_limited_speed_2
  {
    size_t item_size = sizeof(ros_message->safety_limited_speed_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: safe_direction_indication_forward
  {
    size_t item_size = sizeof(ros_message->safe_direction_indication_forward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: safe_direction_indication_backward
  {
    size_t item_size = sizeof(ros_message->safe_direction_indication_backward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swd_ros2_controllers
size_t max_serialized_size_key_swd_ros2_controllers__msg__SafetyFunctions(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: safe_torque_off
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: safe_brake_control
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: safety_limited_speed_1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: safety_limited_speed_2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: safe_direction_indication_forward
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: safe_direction_indication_backward
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = swd_ros2_controllers__msg__SafetyFunctions;
    is_plain =
      (
      offsetof(DataType, safe_direction_indication_backward) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _SafetyFunctions__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const swd_ros2_controllers__msg__SafetyFunctions * ros_message = static_cast<const swd_ros2_controllers__msg__SafetyFunctions *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_swd_ros2_controllers__msg__SafetyFunctions(ros_message, cdr);
}

static bool _SafetyFunctions__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  swd_ros2_controllers__msg__SafetyFunctions * ros_message = static_cast<swd_ros2_controllers__msg__SafetyFunctions *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_swd_ros2_controllers__msg__SafetyFunctions(cdr, ros_message);
}

static uint32_t _SafetyFunctions__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_swd_ros2_controllers__msg__SafetyFunctions(
      untyped_ros_message, 0));
}

static size_t _SafetyFunctions__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_swd_ros2_controllers__msg__SafetyFunctions(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SafetyFunctions = {
  "swd_ros2_controllers::msg",
  "SafetyFunctions",
  _SafetyFunctions__cdr_serialize,
  _SafetyFunctions__cdr_deserialize,
  _SafetyFunctions__get_serialized_size,
  _SafetyFunctions__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SafetyFunctions__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SafetyFunctions,
  get_message_typesupport_handle_function,
  &swd_ros2_controllers__msg__SafetyFunctions__get_type_hash,
  &swd_ros2_controllers__msg__SafetyFunctions__get_type_description,
  &swd_ros2_controllers__msg__SafetyFunctions__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, swd_ros2_controllers, msg, SafetyFunctions)() {
  return &_SafetyFunctions__type_support;
}

#if defined(__cplusplus)
}
#endif
