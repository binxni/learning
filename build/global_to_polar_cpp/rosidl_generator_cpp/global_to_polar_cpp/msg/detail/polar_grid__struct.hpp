// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from global_to_polar_cpp:msg/PolarGrid.idl
// generated code does not contain a copyright notice

#ifndef GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__STRUCT_HPP_
#define GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__global_to_polar_cpp__msg__PolarGrid __attribute__((deprecated))
#else
# define DEPRECATED__global_to_polar_cpp__msg__PolarGrid __declspec(deprecated)
#endif

namespace global_to_polar_cpp
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PolarGrid_
{
  using Type = PolarGrid_<ContainerAllocator>;

  explicit PolarGrid_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit PolarGrid_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _ranges_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _ranges_type ranges;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__ranges(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->ranges = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator> *;
  using ConstRawPtr =
    const global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__global_to_polar_cpp__msg__PolarGrid
    std::shared_ptr<global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__global_to_polar_cpp__msg__PolarGrid
    std::shared_ptr<global_to_polar_cpp::msg::PolarGrid_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PolarGrid_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->ranges != other.ranges) {
      return false;
    }
    return true;
  }
  bool operator!=(const PolarGrid_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PolarGrid_

// alias to use template instance with default allocator
using PolarGrid =
  global_to_polar_cpp::msg::PolarGrid_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace global_to_polar_cpp

#endif  // GLOBAL_TO_POLAR_CPP__MSG__DETAIL__POLAR_GRID__STRUCT_HPP_
