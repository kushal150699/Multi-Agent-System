// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from campus_tour_interfaces:msg/VisitorArrival.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__STRUCT_H_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'building_id'
// Member 'host_id'
// Member 'visitor_id'
// Member 'ci_id'
// Member 'visitor_position'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/VisitorArrival in the package campus_tour_interfaces.
typedef struct campus_tour_interfaces__msg__VisitorArrival
{
  rosidl_runtime_c__String building_id;
  rosidl_runtime_c__String host_id;
  rosidl_runtime_c__String visitor_id;
  rosidl_runtime_c__String ci_id;
  rosidl_runtime_c__String visitor_position;
} campus_tour_interfaces__msg__VisitorArrival;

// Struct for a sequence of campus_tour_interfaces__msg__VisitorArrival.
typedef struct campus_tour_interfaces__msg__VisitorArrival__Sequence
{
  campus_tour_interfaces__msg__VisitorArrival * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} campus_tour_interfaces__msg__VisitorArrival__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__STRUCT_H_
