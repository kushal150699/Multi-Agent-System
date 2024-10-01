// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from campus_tour_interfaces:msg/AccessDenied.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__STRUCT_H_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'visitor_id'
// Member 'reason'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AccessDenied in the package campus_tour_interfaces.
typedef struct campus_tour_interfaces__msg__AccessDenied
{
  rosidl_runtime_c__String visitor_id;
  rosidl_runtime_c__String reason;
} campus_tour_interfaces__msg__AccessDenied;

// Struct for a sequence of campus_tour_interfaces__msg__AccessDenied.
typedef struct campus_tour_interfaces__msg__AccessDenied__Sequence
{
  campus_tour_interfaces__msg__AccessDenied * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} campus_tour_interfaces__msg__AccessDenied__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__STRUCT_H_
