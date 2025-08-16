// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from global_to_polar_cpp:msg/PolarGrid.idl
// generated code does not contain a copyright notice

#ifndef GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__TRAITS_HPP_
#define GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "global_to_polar_cpp/msg/detail/polar_grid__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace global_to_polar_cpp
{

namespace msg
{

inline void to_flow_style_yaml(
  const PolarGrid & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: ranges
  {
    if (msg.ranges.size() == 0) {
      out << "ranges: []";
    } else {
      out << "ranges: [";
      size_t pending_items = msg.ranges.size();
      for (auto item : msg.ranges) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PolarGrid & msg,
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

  // member: ranges
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ranges.size() == 0) {
      out << "ranges: []\n";
    } else {
      out << "ranges:\n";
      for (auto item : msg.ranges) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PolarGrid & msg, bool use_flow_style = false)
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

}  // namespace global_to_polar_cpp

namespace rosidl_generator_traits
{

[[deprecated("use global_to_polar_cpp::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const global_to_polar_cpp::msg::PolarGrid & msg,
  std::ostream & out, size_t indentation = 0)
{
  global_to_polar_cpp::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use global_to_polar_cpp::msg::to_yaml() instead")]]
inline std::string to_yaml(const global_to_polar_cpp::msg::PolarGrid & msg)
{
  return global_to_polar_cpp::msg::to_yaml(msg);
}

template<>
inline const char * data_type<global_to_polar_cpp::msg::PolarGrid>()
{
  return "global_to_polar_cpp::msg::PolarGrid";
}

template<>
inline const char * name<global_to_polar_cpp::msg::PolarGrid>()
{
  return "global_to_polar_cpp/msg/PolarGrid";
}

template<>
struct has_fixed_size<global_to_polar_cpp::msg::PolarGrid>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<global_to_polar_cpp::msg::PolarGrid>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<global_to_polar_cpp::msg::PolarGrid>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__TRAITS_HPP_
