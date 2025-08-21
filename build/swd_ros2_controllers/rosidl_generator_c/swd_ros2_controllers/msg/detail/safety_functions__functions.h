// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from swd_ros2_controllers:msg/SafetyFunctions.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swd_ros2_controllers/msg/safety_functions.h"


#ifndef SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__FUNCTIONS_H_
#define SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "swd_ros2_controllers/msg/rosidl_generator_c__visibility_control.h"

#include "swd_ros2_controllers/msg/detail/safety_functions__struct.h"

/// Initialize msg/SafetyFunctions message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * swd_ros2_controllers__msg__SafetyFunctions
 * )) before or use
 * swd_ros2_controllers__msg__SafetyFunctions__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
bool
swd_ros2_controllers__msg__SafetyFunctions__init(swd_ros2_controllers__msg__SafetyFunctions * msg);

/// Finalize msg/SafetyFunctions message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
void
swd_ros2_controllers__msg__SafetyFunctions__fini(swd_ros2_controllers__msg__SafetyFunctions * msg);

/// Create msg/SafetyFunctions message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * swd_ros2_controllers__msg__SafetyFunctions__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
swd_ros2_controllers__msg__SafetyFunctions *
swd_ros2_controllers__msg__SafetyFunctions__create(void);

/// Destroy msg/SafetyFunctions message.
/**
 * It calls
 * swd_ros2_controllers__msg__SafetyFunctions__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
void
swd_ros2_controllers__msg__SafetyFunctions__destroy(swd_ros2_controllers__msg__SafetyFunctions * msg);

/// Check for msg/SafetyFunctions message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
bool
swd_ros2_controllers__msg__SafetyFunctions__are_equal(const swd_ros2_controllers__msg__SafetyFunctions * lhs, const swd_ros2_controllers__msg__SafetyFunctions * rhs);

/// Copy a msg/SafetyFunctions message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
bool
swd_ros2_controllers__msg__SafetyFunctions__copy(
  const swd_ros2_controllers__msg__SafetyFunctions * input,
  swd_ros2_controllers__msg__SafetyFunctions * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
const rosidl_type_hash_t *
swd_ros2_controllers__msg__SafetyFunctions__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
const rosidl_runtime_c__type_description__TypeDescription *
swd_ros2_controllers__msg__SafetyFunctions__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
const rosidl_runtime_c__type_description__TypeSource *
swd_ros2_controllers__msg__SafetyFunctions__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
const rosidl_runtime_c__type_description__TypeSource__Sequence *
swd_ros2_controllers__msg__SafetyFunctions__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/SafetyFunctions messages.
/**
 * It allocates the memory for the number of elements and calls
 * swd_ros2_controllers__msg__SafetyFunctions__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
bool
swd_ros2_controllers__msg__SafetyFunctions__Sequence__init(swd_ros2_controllers__msg__SafetyFunctions__Sequence * array, size_t size);

/// Finalize array of msg/SafetyFunctions messages.
/**
 * It calls
 * swd_ros2_controllers__msg__SafetyFunctions__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
void
swd_ros2_controllers__msg__SafetyFunctions__Sequence__fini(swd_ros2_controllers__msg__SafetyFunctions__Sequence * array);

/// Create array of msg/SafetyFunctions messages.
/**
 * It allocates the memory for the array and calls
 * swd_ros2_controllers__msg__SafetyFunctions__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
swd_ros2_controllers__msg__SafetyFunctions__Sequence *
swd_ros2_controllers__msg__SafetyFunctions__Sequence__create(size_t size);

/// Destroy array of msg/SafetyFunctions messages.
/**
 * It calls
 * swd_ros2_controllers__msg__SafetyFunctions__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
void
swd_ros2_controllers__msg__SafetyFunctions__Sequence__destroy(swd_ros2_controllers__msg__SafetyFunctions__Sequence * array);

/// Check for msg/SafetyFunctions message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
bool
swd_ros2_controllers__msg__SafetyFunctions__Sequence__are_equal(const swd_ros2_controllers__msg__SafetyFunctions__Sequence * lhs, const swd_ros2_controllers__msg__SafetyFunctions__Sequence * rhs);

/// Copy an array of msg/SafetyFunctions messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
bool
swd_ros2_controllers__msg__SafetyFunctions__Sequence__copy(
  const swd_ros2_controllers__msg__SafetyFunctions__Sequence * input,
  swd_ros2_controllers__msg__SafetyFunctions__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SWD_ROS2_CONTROLLERS__MSG__DETAIL__SAFETY_FUNCTIONS__FUNCTIONS_H_
