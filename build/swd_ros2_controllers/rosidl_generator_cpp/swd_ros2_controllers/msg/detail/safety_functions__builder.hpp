// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from swd_ros2_controllers:msg/SafetyFunctions.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swd_ros2_controllers/msg/safety_functions.hpp"


#ifndef SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__BUILDER_HPP_
#define SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "swd_ros2_controllers/msg/detail/safety_functions__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace swd_ros2_controllers
{

namespace msg
{

namespace builder
{

class Init_SafetyFunctions_safe_direction_indication_backward
{
public:
  explicit Init_SafetyFunctions_safe_direction_indication_backward(::swd_ros2_controllers::msg::SafetyFunctions & msg)
  : msg_(msg)
  {}
  ::swd_ros2_controllers::msg::SafetyFunctions safe_direction_indication_backward(::swd_ros2_controllers::msg::SafetyFunctions::_safe_direction_indication_backward_type arg)
  {
    msg_.safe_direction_indication_backward = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swd_ros2_controllers::msg::SafetyFunctions msg_;
};

class Init_SafetyFunctions_safe_direction_indication_forward
{
public:
  explicit Init_SafetyFunctions_safe_direction_indication_forward(::swd_ros2_controllers::msg::SafetyFunctions & msg)
  : msg_(msg)
  {}
  Init_SafetyFunctions_safe_direction_indication_backward safe_direction_indication_forward(::swd_ros2_controllers::msg::SafetyFunctions::_safe_direction_indication_forward_type arg)
  {
    msg_.safe_direction_indication_forward = std::move(arg);
    return Init_SafetyFunctions_safe_direction_indication_backward(msg_);
  }

private:
  ::swd_ros2_controllers::msg::SafetyFunctions msg_;
};

class Init_SafetyFunctions_safety_limited_speed_2
{
public:
  explicit Init_SafetyFunctions_safety_limited_speed_2(::swd_ros2_controllers::msg::SafetyFunctions & msg)
  : msg_(msg)
  {}
  Init_SafetyFunctions_safe_direction_indication_forward safety_limited_speed_2(::swd_ros2_controllers::msg::SafetyFunctions::_safety_limited_speed_2_type arg)
  {
    msg_.safety_limited_speed_2 = std::move(arg);
    return Init_SafetyFunctions_safe_direction_indication_forward(msg_);
  }

private:
  ::swd_ros2_controllers::msg::SafetyFunctions msg_;
};

class Init_SafetyFunctions_safety_limited_speed_1
{
public:
  explicit Init_SafetyFunctions_safety_limited_speed_1(::swd_ros2_controllers::msg::SafetyFunctions & msg)
  : msg_(msg)
  {}
  Init_SafetyFunctions_safety_limited_speed_2 safety_limited_speed_1(::swd_ros2_controllers::msg::SafetyFunctions::_safety_limited_speed_1_type arg)
  {
    msg_.safety_limited_speed_1 = std::move(arg);
    return Init_SafetyFunctions_safety_limited_speed_2(msg_);
  }

private:
  ::swd_ros2_controllers::msg::SafetyFunctions msg_;
};

class Init_SafetyFunctions_safe_brake_control
{
public:
  explicit Init_SafetyFunctions_safe_brake_control(::swd_ros2_controllers::msg::SafetyFunctions & msg)
  : msg_(msg)
  {}
  Init_SafetyFunctions_safety_limited_speed_1 safe_brake_control(::swd_ros2_controllers::msg::SafetyFunctions::_safe_brake_control_type arg)
  {
    msg_.safe_brake_control = std::move(arg);
    return Init_SafetyFunctions_safety_limited_speed_1(msg_);
  }

private:
  ::swd_ros2_controllers::msg::SafetyFunctions msg_;
};

class Init_SafetyFunctions_safe_torque_off
{
public:
  explicit Init_SafetyFunctions_safe_torque_off(::swd_ros2_controllers::msg::SafetyFunctions & msg)
  : msg_(msg)
  {}
  Init_SafetyFunctions_safe_brake_control safe_torque_off(::swd_ros2_controllers::msg::SafetyFunctions::_safe_torque_off_type arg)
  {
    msg_.safe_torque_off = std::move(arg);
    return Init_SafetyFunctions_safe_brake_control(msg_);
  }

private:
  ::swd_ros2_controllers::msg::SafetyFunctions msg_;
};

class Init_SafetyFunctions_header
{
public:
  Init_SafetyFunctions_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SafetyFunctions_safe_torque_off header(::swd_ros2_controllers::msg::SafetyFunctions::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SafetyFunctions_safe_torque_off(msg_);
  }

private:
  ::swd_ros2_controllers::msg::SafetyFunctions msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::swd_ros2_controllers::msg::SafetyFunctions>()
{
  return swd_ros2_controllers::msg::builder::Init_SafetyFunctions_header();
}

}  // namespace swd_ros2_controllers

#endif  // SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__BUILDER_HPP_
