// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from campus_tour_interfaces:msg/OutOfService.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__OUT_OF_SERVICE__STRUCT_H_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__OUT_OF_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'bi_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/OutOfService in the package campus_tour_interfaces.
typedef struct campus_tour_interfaces__msg__OutOfService
{
  rosidl_runtime_c__String bi_id;
  int32_t duration;
} campus_tour_interfaces__msg__OutOfService;

// Struct for a sequence of campus_tour_interfaces__msg__OutOfService.
typedef struct campus_tour_interfaces__msg__OutOfService__Sequence
{
  campus_tour_interfaces__msg__OutOfService * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} campus_tour_interfaces__msg__OutOfService__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__OUT_OF_SERVICE__STRUCT_H_
