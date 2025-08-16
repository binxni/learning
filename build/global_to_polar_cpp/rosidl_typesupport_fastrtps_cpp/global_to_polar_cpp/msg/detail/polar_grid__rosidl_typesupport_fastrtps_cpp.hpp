// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from global_to_polar_cpp:msg/PolarGrid.idl
// generated code does not contain a copyright notice

#ifndef GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "global_to_polar_cpp/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "global_to_polar_cpp/msg/detail/polar_grid__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace global_to_polar_cpp
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_global_to_polar_cpp
cdr_serialize(
  const global_to_polar_cpp::msg::PolarGrid & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_global_to_polar_cpp
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  global_to_polar_cpp::msg::PolarGrid & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_global_to_polar_cpp
get_serialized_size(
  const global_to_polar_cpp::msg::PolarGrid & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_global_to_polar_cpp
max_serialized_size_PolarGrid(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace global_to_polar_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_global_to_polar_cpp
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, global_to_polar_cpp, msg, PolarGrid)();

#ifdef __cplusplus
}
#endif

#endif  // GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
