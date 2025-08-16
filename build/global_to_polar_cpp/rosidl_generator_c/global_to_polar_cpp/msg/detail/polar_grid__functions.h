// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from global_to_polar_cpp:msg/PolarGrid.idl
// generated code does not contain a copyright notice

#ifndef GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__FUNCTIONS_H_
#define GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "global_to_polar_cpp/msg/rosidl_generator_c__visibility_control.h"

#include "global_to_polar_cpp/msg/detail/polar_grid__struct.h"

/// Initialize msg/PolarGrid message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * global_to_polar_cpp__msg__PolarGrid
 * )) before or use
 * global_to_polar_cpp__msg__PolarGrid__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
bool
global_to_polar_cpp__msg__PolarGrid__init(global_to_polar_cpp__msg__PolarGrid * msg);

/// Finalize msg/PolarGrid message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
void
global_to_polar_cpp__msg__PolarGrid__fini(global_to_polar_cpp__msg__PolarGrid * msg);

/// Create msg/PolarGrid message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * global_to_polar_cpp__msg__PolarGrid__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
global_to_polar_cpp__msg__PolarGrid *
global_to_polar_cpp__msg__PolarGrid__create();

/// Destroy msg/PolarGrid message.
/**
 * It calls
 * global_to_polar_cpp__msg__PolarGrid__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
void
global_to_polar_cpp__msg__PolarGrid__destroy(global_to_polar_cpp__msg__PolarGrid * msg);

/// Check for msg/PolarGrid message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
bool
global_to_polar_cpp__msg__PolarGrid__are_equal(const global_to_polar_cpp__msg__PolarGrid * lhs, const global_to_polar_cpp__msg__PolarGrid * rhs);

/// Copy a msg/PolarGrid message.
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
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
bool
global_to_polar_cpp__msg__PolarGrid__copy(
  const global_to_polar_cpp__msg__PolarGrid * input,
  global_to_polar_cpp__msg__PolarGrid * output);

/// Initialize array of msg/PolarGrid messages.
/**
 * It allocates the memory for the number of elements and calls
 * global_to_polar_cpp__msg__PolarGrid__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
bool
global_to_polar_cpp__msg__PolarGrid__Sequence__init(global_to_polar_cpp__msg__PolarGrid__Sequence * array, size_t size);

/// Finalize array of msg/PolarGrid messages.
/**
 * It calls
 * global_to_polar_cpp__msg__PolarGrid__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
void
global_to_polar_cpp__msg__PolarGrid__Sequence__fini(global_to_polar_cpp__msg__PolarGrid__Sequence * array);

/// Create array of msg/PolarGrid messages.
/**
 * It allocates the memory for the array and calls
 * global_to_polar_cpp__msg__PolarGrid__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
global_to_polar_cpp__msg__PolarGrid__Sequence *
global_to_polar_cpp__msg__PolarGrid__Sequence__create(size_t size);

/// Destroy array of msg/PolarGrid messages.
/**
 * It calls
 * global_to_polar_cpp__msg__PolarGrid__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
void
global_to_polar_cpp__msg__PolarGrid__Sequence__destroy(global_to_polar_cpp__msg__PolarGrid__Sequence * array);

/// Check for msg/PolarGrid message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
bool
global_to_polar_cpp__msg__PolarGrid__Sequence__are_equal(const global_to_polar_cpp__msg__PolarGrid__Sequence * lhs, const global_to_polar_cpp__msg__PolarGrid__Sequence * rhs);

/// Copy an array of msg/PolarGrid messages.
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
ROSIDL_GENERATOR_C_PUBLIC_global_to_polar_cpp
bool
global_to_polar_cpp__msg__PolarGrid__Sequence__copy(
  const global_to_polar_cpp__msg__PolarGrid__Sequence * input,
  global_to_polar_cpp__msg__PolarGrid__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__FUNCTIONS_H_
