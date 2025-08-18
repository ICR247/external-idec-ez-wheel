// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from swd_ros2_controllers:msg/SafetyFunctions.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swd_ros2_controllers/msg/safety_functions.hpp"


#ifndef SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__TRAITS_HPP_
#define SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "swd_ros2_controllers/msg/detail/safety_functions__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace swd_ros2_controllers
{

namespace msg
{

inline void to_flow_style_yaml(
  const SafetyFunctions & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: safe_torque_off
  {
    out << "safe_torque_off: ";
    rosidl_generator_traits::value_to_yaml(msg.safe_torque_off, out);
    out << ", ";
  }

  // member: safe_brake_control
  {
    out << "safe_brake_control: ";
    rosidl_generator_traits::value_to_yaml(msg.safe_brake_control, out);
    out << ", ";
  }

  // member: safety_limited_speed_1
  {
    out << "safety_limited_speed_1: ";
    rosidl_generator_traits::value_to_yaml(msg.safety_limited_speed_1, out);
    out << ", ";
  }

  // member: safety_limited_speed_2
  {
    out << "safety_limited_speed_2: ";
    rosidl_generator_traits::value_to_yaml(msg.safety_limited_speed_2, out);
    out << ", ";
  }

  // member: safe_direction_indication_forward
  {
    out << "safe_direction_indication_forward: ";
    rosidl_generator_traits::value_to_yaml(msg.safe_direction_indication_forward, out);
    out << ", ";
  }

  // member: safe_direction_indication_backward
  {
    out << "safe_direction_indication_backward: ";
    rosidl_generator_traits::value_to_yaml(msg.safe_direction_indication_backward, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SafetyFunctions & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: safe_torque_off
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "safe_torque_off: ";
    rosidl_generator_traits::value_to_yaml(msg.safe_torque_off, out);
    out << "\n";
  }

  // member: safe_brake_control
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "safe_brake_control: ";
    rosidl_generator_traits::value_to_yaml(msg.safe_brake_control, out);
    out << "\n";
  }

  // member: safety_limited_speed_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "safety_limited_speed_1: ";
    rosidl_generator_traits::value_to_yaml(msg.safety_limited_speed_1, out);
    out << "\n";
  }

  // member: safety_limited_speed_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "safety_limited_speed_2: ";
    rosidl_generator_traits::value_to_yaml(msg.safety_limited_speed_2, out);
    out << "\n";
  }

  // member: safe_direction_indication_forward
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "safe_direction_indication_forward: ";
    rosidl_generator_traits::value_to_yaml(msg.safe_direction_indication_forward, out);
    out << "\n";
  }

  // member: safe_direction_indication_backward
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "safe_direction_indication_backward: ";
    rosidl_generator_traits::value_to_yaml(msg.safe_direction_indication_backward, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SafetyFunctions & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace swd_ros2_controllers

namespace rosidl_generator_traits
{

[[deprecated("use swd_ros2_controllers::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swd_ros2_controllers::msg::SafetyFunctions & msg,
  std::ostream & out, size_t indentation = 0)
{
  swd_ros2_controllers::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swd_ros2_controllers::msg::to_yaml() instead")]]
inline std::string to_yaml(const swd_ros2_controllers::msg::SafetyFunctions & msg)
{
  return swd_ros2_controllers::msg::to_yaml(msg);
}

template<>
inline const char * data_type<swd_ros2_controllers::msg::SafetyFunctions>()
{
  return "swd_ros2_controllers::msg::SafetyFunctions";
}

template<>
inline const char * name<swd_ros2_controllers::msg::SafetyFunctions>()
{
  return "swd_ros2_controllers/msg/SafetyFunctions";
}

template<>
struct has_fixed_size<swd_ros2_controllers::msg::SafetyFunctions>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<swd_ros2_controllers::msg::SafetyFunctions>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<swd_ros2_controllers::msg::SafetyFunctions>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__TRAITS_HPP_
