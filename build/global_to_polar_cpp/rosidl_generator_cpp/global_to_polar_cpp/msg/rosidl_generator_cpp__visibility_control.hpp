// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef GLOBAL_TO_POLAR_CPP__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define GLOBAL_TO_POLAR_CPP__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_global_to_polar_cpp __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_global_to_polar_cpp __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_global_to_polar_cpp __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_global_to_polar_cpp __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_global_to_polar_cpp
    #define ROSIDL_GENERATOR_CPP_PUBLIC_global_to_polar_cpp ROSIDL_GENERATOR_CPP_EXPORT_global_to_polar_cpp
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_global_to_polar_cpp ROSIDL_GENERATOR_CPP_IMPORT_global_to_polar_cpp
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_global_to_polar_cpp __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_global_to_polar_cpp
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_global_to_polar_cpp __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_global_to_polar_cpp
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // GLOBAL_TO_POLAR_CPP__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
