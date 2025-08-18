// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from swd_ros2_controllers:msg/SafetyFunctions.idl
// generated code does not contain a copyright notice
#include "swd_ros2_controllers/msg/detail/safety_functions__rosidl_typesupport_fastrtps_cpp.hpp"
#include "swd_ros2_controllers/msg/detail/safety_functions__functions.h"
#include "swd_ros2_controllers/msg/detail/safety_functions__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_key_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace swd_ros2_controllers
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_swd_ros2_controllers
cdr_serialize(
  const swd_ros2_controllers::msg::SafetyFunctions & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);

  // Member: safe_torque_off
  cdr << (ros_message.safe_torque_off ? true : false);

  // Member: safe_brake_control
  cdr << (ros_message.safe_brake_control ? true : false);

  // Member: safety_limited_speed_1
  cdr << (ros_message.safety_limited_speed_1 ? true : false);

  // Member: safety_limited_speed_2
  cdr << (ros_message.safety_limited_speed_2 ? true : false);

  // Member: safe_direction_indication_forward
  cdr << (ros_message.safe_direction_indication_forward ? true : false);

  // Member: safe_direction_indication_backward
  cdr << (ros_message.safe_direction_indication_backward ? true : false);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_swd_ros2_controllers
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  swd_ros2_controllers::msg::SafetyFunctions & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: safe_torque_off
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.safe_torque_off = tmp ? true : false;
  }

  // Member: safe_brake_control
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.safe_brake_control = tmp ? true : false;
  }

  // Member: safety_limited_speed_1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.safety_limited_speed_1 = tmp ? true : false;
  }

  // Member: safety_limited_speed_2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.safety_limited_speed_2 = tmp ? true : false;
  }

  // Member: safe_direction_indication_forward
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.safe_direction_indication_forward = tmp ? true : false;
  }

  // Member: safe_direction_indication_backward
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.safe_direction_indication_backward = tmp ? true : false;
  }

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_swd_ros2_controllers
get_serialized_size(
  const swd_ros2_controllers::msg::SafetyFunctions & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header
  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);

  // Member: safe_torque_off
  {
    size_t item_size = sizeof(ros_message.safe_torque_off);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: safe_brake_control
  {
    size_t item_size = sizeof(ros_message.safe_brake_control);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: safety_limited_speed_1
  {
    size_t item_size = sizeof(ros_message.safety_limited_speed_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: safety_limited_speed_2
  {
    size_t item_size = sizeof(ros_message.safety_limited_speed_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: safe_direction_indication_forward
  {
    size_t item_size = sizeof(ros_message.safe_direction_indication_forward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: safe_direction_indication_backward
  {
    size_t item_size = sizeof(ros_message.safe_direction_indication_backward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_swd_ros2_controllers
max_serialized_size_SafetyFunctions(
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

  // Member: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: safe_torque_off
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: safe_brake_control
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: safety_limited_speed_1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: safety_limited_speed_2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: safe_direction_indication_forward
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: safe_direction_indication_backward
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
    using DataType = swd_ros2_controllers::msg::SafetyFunctions;
    is_plain =
      (
      offsetof(DataType, safe_direction_indication_backward) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_swd_ros2_controllers
cdr_serialize_key(
  const swd_ros2_controllers::msg::SafetyFunctions & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.header,
    cdr);

  // Member: safe_torque_off
  cdr << (ros_message.safe_torque_off ? true : false);

  // Member: safe_brake_control
  cdr << (ros_message.safe_brake_control ? true : false);

  // Member: safety_limited_speed_1
  cdr << (ros_message.safety_limited_speed_1 ? true : false);

  // Member: safety_limited_speed_2
  cdr << (ros_message.safety_limited_speed_2 ? true : false);

  // Member: safe_direction_indication_forward
  cdr << (ros_message.safe_direction_indication_forward ? true : false);

  // Member: safe_direction_indication_backward
  cdr << (ros_message.safe_direction_indication_backward ? true : false);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_swd_ros2_controllers
get_serialized_size_key(
  const swd_ros2_controllers::msg::SafetyFunctions & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header
  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.header, current_alignment);

  // Member: safe_torque_off
  {
    size_t item_size = sizeof(ros_message.safe_torque_off);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: safe_brake_control
  {
    size_t item_size = sizeof(ros_message.safe_brake_control);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: safety_limited_speed_1
  {
    size_t item_size = sizeof(ros_message.safety_limited_speed_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: safety_limited_speed_2
  {
    size_t item_size = sizeof(ros_message.safety_limited_speed_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: safe_direction_indication_forward
  {
    size_t item_size = sizeof(ros_message.safe_direction_indication_forward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: safe_direction_indication_backward
  {
    size_t item_size = sizeof(ros_message.safe_direction_indication_backward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_swd_ros2_controllers
max_serialized_size_key_SafetyFunctions(
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

  // Member: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: safe_torque_off
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: safe_brake_control
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: safety_limited_speed_1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: safety_limited_speed_2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: safe_direction_indication_forward
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: safe_direction_indication_backward
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
    using DataType = swd_ros2_controllers::msg::SafetyFunctions;
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
  auto typed_message =
    static_cast<const swd_ros2_controllers::msg::SafetyFunctions *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SafetyFunctions__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<swd_ros2_controllers::msg::SafetyFunctions *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SafetyFunctions__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const swd_ros2_controllers::msg::SafetyFunctions *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SafetyFunctions__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SafetyFunctions(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SafetyFunctions__callbacks = {
  "swd_ros2_controllers::msg",
  "SafetyFunctions",
  _SafetyFunctions__cdr_serialize,
  _SafetyFunctions__cdr_deserialize,
  _SafetyFunctions__get_serialized_size,
  _SafetyFunctions__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SafetyFunctions__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SafetyFunctions__callbacks,
  get_message_typesupport_handle_function,
  &swd_ros2_controllers__msg__SafetyFunctions__get_type_hash,
  &swd_ros2_controllers__msg__SafetyFunctions__get_type_description,
  &swd_ros2_controllers__msg__SafetyFunctions__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace swd_ros2_controllers

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_swd_ros2_controllers
const rosidl_message_type_support_t *
get_message_type_support_handle<swd_ros2_controllers::msg::SafetyFunctions>()
{
  return &swd_ros2_controllers::msg::typesupport_fastrtps_cpp::_SafetyFunctions__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, swd_ros2_controllers, msg, SafetyFunctions)() {
  return &swd_ros2_controllers::msg::typesupport_fastrtps_cpp::_SafetyFunctions__handle;
}

#ifdef __cplusplus
}
#endif
