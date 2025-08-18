// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from swd_ros2_controllers:msg/SafetyFunctions.idl
// generated code does not contain a copyright notice
#include "swd_ros2_controllers/msg/detail/safety_functions__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
swd_ros2_controllers__msg__SafetyFunctions__init(swd_ros2_controllers__msg__SafetyFunctions * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    swd_ros2_controllers__msg__SafetyFunctions__fini(msg);
    return false;
  }
  // safe_torque_off
  // safe_brake_control
  // safety_limited_speed_1
  // safety_limited_speed_2
  // safe_direction_indication_forward
  // safe_direction_indication_backward
  return true;
}

void
swd_ros2_controllers__msg__SafetyFunctions__fini(swd_ros2_controllers__msg__SafetyFunctions * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // safe_torque_off
  // safe_brake_control
  // safety_limited_speed_1
  // safety_limited_speed_2
  // safe_direction_indication_forward
  // safe_direction_indication_backward
}

bool
swd_ros2_controllers__msg__SafetyFunctions__are_equal(const swd_ros2_controllers__msg__SafetyFunctions * lhs, const swd_ros2_controllers__msg__SafetyFunctions * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // safe_torque_off
  if (lhs->safe_torque_off != rhs->safe_torque_off) {
    return false;
  }
  // safe_brake_control
  if (lhs->safe_brake_control != rhs->safe_brake_control) {
    return false;
  }
  // safety_limited_speed_1
  if (lhs->safety_limited_speed_1 != rhs->safety_limited_speed_1) {
    return false;
  }
  // safety_limited_speed_2
  if (lhs->safety_limited_speed_2 != rhs->safety_limited_speed_2) {
    return false;
  }
  // safe_direction_indication_forward
  if (lhs->safe_direction_indication_forward != rhs->safe_direction_indication_forward) {
    return false;
  }
  // safe_direction_indication_backward
  if (lhs->safe_direction_indication_backward != rhs->safe_direction_indication_backward) {
    return false;
  }
  return true;
}

bool
swd_ros2_controllers__msg__SafetyFunctions__copy(
  const swd_ros2_controllers__msg__SafetyFunctions * input,
  swd_ros2_controllers__msg__SafetyFunctions * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // safe_torque_off
  output->safe_torque_off = input->safe_torque_off;
  // safe_brake_control
  output->safe_brake_control = input->safe_brake_control;
  // safety_limited_speed_1
  output->safety_limited_speed_1 = input->safety_limited_speed_1;
  // safety_limited_speed_2
  output->safety_limited_speed_2 = input->safety_limited_speed_2;
  // safe_direction_indication_forward
  output->safe_direction_indication_forward = input->safe_direction_indication_forward;
  // safe_direction_indication_backward
  output->safe_direction_indication_backward = input->safe_direction_indication_backward;
  return true;
}

swd_ros2_controllers__msg__SafetyFunctions *
swd_ros2_controllers__msg__SafetyFunctions__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swd_ros2_controllers__msg__SafetyFunctions * msg = (swd_ros2_controllers__msg__SafetyFunctions *)allocator.allocate(sizeof(swd_ros2_controllers__msg__SafetyFunctions), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(swd_ros2_controllers__msg__SafetyFunctions));
  bool success = swd_ros2_controllers__msg__SafetyFunctions__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
swd_ros2_controllers__msg__SafetyFunctions__destroy(swd_ros2_controllers__msg__SafetyFunctions * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    swd_ros2_controllers__msg__SafetyFunctions__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
swd_ros2_controllers__msg__SafetyFunctions__Sequence__init(swd_ros2_controllers__msg__SafetyFunctions__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swd_ros2_controllers__msg__SafetyFunctions * data = NULL;

  if (size) {
    data = (swd_ros2_controllers__msg__SafetyFunctions *)allocator.zero_allocate(size, sizeof(swd_ros2_controllers__msg__SafetyFunctions), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = swd_ros2_controllers__msg__SafetyFunctions__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        swd_ros2_controllers__msg__SafetyFunctions__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
swd_ros2_controllers__msg__SafetyFunctions__Sequence__fini(swd_ros2_controllers__msg__SafetyFunctions__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      swd_ros2_controllers__msg__SafetyFunctions__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

swd_ros2_controllers__msg__SafetyFunctions__Sequence *
swd_ros2_controllers__msg__SafetyFunctions__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swd_ros2_controllers__msg__SafetyFunctions__Sequence * array = (swd_ros2_controllers__msg__SafetyFunctions__Sequence *)allocator.allocate(sizeof(swd_ros2_controllers__msg__SafetyFunctions__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = swd_ros2_controllers__msg__SafetyFunctions__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
swd_ros2_controllers__msg__SafetyFunctions__Sequence__destroy(swd_ros2_controllers__msg__SafetyFunctions__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    swd_ros2_controllers__msg__SafetyFunctions__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
swd_ros2_controllers__msg__SafetyFunctions__Sequence__are_equal(const swd_ros2_controllers__msg__SafetyFunctions__Sequence * lhs, const swd_ros2_controllers__msg__SafetyFunctions__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!swd_ros2_controllers__msg__SafetyFunctions__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
swd_ros2_controllers__msg__SafetyFunctions__Sequence__copy(
  const swd_ros2_controllers__msg__SafetyFunctions__Sequence * input,
  swd_ros2_controllers__msg__SafetyFunctions__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(swd_ros2_controllers__msg__SafetyFunctions);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    swd_ros2_controllers__msg__SafetyFunctions * data =
      (swd_ros2_controllers__msg__SafetyFunctions *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!swd_ros2_controllers__msg__SafetyFunctions__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          swd_ros2_controllers__msg__SafetyFunctions__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!swd_ros2_controllers__msg__SafetyFunctions__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
