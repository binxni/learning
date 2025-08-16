// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from global_to_polar_cpp:msg/PolarGrid.idl
// generated code does not contain a copyright notice

#ifndef GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__BUILDER_HPP_
#define GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "global_to_polar_cpp/msg/detail/polar_grid__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace global_to_polar_cpp
{

namespace msg
{

namespace builder
{

class Init_PolarGrid_ranges
{
public:
  explicit Init_PolarGrid_ranges(::global_to_polar_cpp::msg::PolarGrid & msg)
  : msg_(msg)
  {}
  ::global_to_polar_cpp::msg::PolarGrid ranges(::global_to_polar_cpp::msg::PolarGrid::_ranges_type arg)
  {
    msg_.ranges = std::move(arg);
    return std::move(msg_);
  }

private:
  ::global_to_polar_cpp::msg::PolarGrid msg_;
};

class Init_PolarGrid_header
{
public:
  Init_PolarGrid_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PolarGrid_ranges header(::global_to_polar_cpp::msg::PolarGrid::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PolarGrid_ranges(msg_);
  }

private:
  ::global_to_polar_cpp::msg::PolarGrid msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::global_to_polar_cpp::msg::PolarGrid>()
{
  return global_to_polar_cpp::msg::builder::Init_PolarGrid_header();
}

}  // namespace global_to_polar_cpp

#endif  // GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__BUILDER_HPP_
