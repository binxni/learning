// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from global_to_polar_cpp:msg/PolarGrid.idl
// generated code does not contain a copyright notice

#ifndef GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__STRUCT_H_
#define GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__STRUCT_H_

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
// Member 'ranges'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PolarGrid in the package global_to_polar_cpp.
/**
  * PolarGrid.msg
  * 극좌표계 그리드 상의 거리 값 배열
 */
typedef struct global_to_polar_cpp__msg__PolarGrid
{
  /// 메시지가 생성된 시간과 좌표계를 포함하는 헤더
  std_msgs__msg__Header header;
  /// 거리(range) 값들을 담는 배열.
  /// global_to_polar_node는 여기에 1081개의 float 값을 채웁니다.
  rosidl_runtime_c__float__Sequence ranges;
} global_to_polar_cpp__msg__PolarGrid;

// Struct for a sequence of global_to_polar_cpp__msg__PolarGrid.
typedef struct global_to_polar_cpp__msg__PolarGrid__Sequence
{
  global_to_polar_cpp__msg__PolarGrid * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} global_to_polar_cpp__msg__PolarGrid__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__STRUCT_H_
