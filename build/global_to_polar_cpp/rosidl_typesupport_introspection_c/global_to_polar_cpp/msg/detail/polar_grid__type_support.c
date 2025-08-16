// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from global_to_polar_cpp:msg/PolarGrid.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "global_to_polar_cpp/msg/detail/polar_grid__rosidl_typesupport_introspection_c.h"
#include "global_to_polar_cpp/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "global_to_polar_cpp/msg/detail/polar_grid__functions.h"
#include "global_to_polar_cpp/msg/detail/polar_grid__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `ranges`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  global_to_polar_cpp__msg__PolarGrid__init(message_memory);
}

void global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_fini_function(void * message_memory)
{
  global_to_polar_cpp__msg__PolarGrid__fini(message_memory);
}

size_t global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__size_function__PolarGrid__ranges(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__get_const_function__PolarGrid__ranges(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__get_function__PolarGrid__ranges(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__fetch_function__PolarGrid__ranges(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__get_const_function__PolarGrid__ranges(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__assign_function__PolarGrid__ranges(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__get_function__PolarGrid__ranges(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__resize_function__PolarGrid__ranges(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(global_to_polar_cpp__msg__PolarGrid, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ranges",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(global_to_polar_cpp__msg__PolarGrid, ranges),  // bytes offset in struct
    NULL,  // default value
    global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__size_function__PolarGrid__ranges,  // size() function pointer
    global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__get_const_function__PolarGrid__ranges,  // get_const(index) function pointer
    global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__get_function__PolarGrid__ranges,  // get(index) function pointer
    global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__fetch_function__PolarGrid__ranges,  // fetch(index, &value) function pointer
    global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__assign_function__PolarGrid__ranges,  // assign(index, value) function pointer
    global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__resize_function__PolarGrid__ranges  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_message_members = {
  "global_to_polar_cpp__msg",  // message namespace
  "PolarGrid",  // message name
  2,  // number of fields
  sizeof(global_to_polar_cpp__msg__PolarGrid),
  global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_message_member_array,  // message members
  global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_init_function,  // function to initialize message memory (memory has to be allocated)
  global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_message_type_support_handle = {
  0,
  &global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_global_to_polar_cpp
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, global_to_polar_cpp, msg, PolarGrid)() {
  global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_message_type_support_handle.typesupport_identifier) {
    global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &global_to_polar_cpp__msg__PolarGrid__rosidl_typesupport_introspection_c__PolarGrid_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
