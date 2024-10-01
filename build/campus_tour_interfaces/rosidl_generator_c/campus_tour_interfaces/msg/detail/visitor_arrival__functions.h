// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from campus_tour_interfaces:msg/VisitorArrival.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__FUNCTIONS_H_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "campus_tour_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "campus_tour_interfaces/msg/detail/visitor_arrival__struct.h"

/// Initialize msg/VisitorArrival message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * campus_tour_interfaces__msg__VisitorArrival
 * )) before or use
 * campus_tour_interfaces__msg__VisitorArrival__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__VisitorArrival__init(campus_tour_interfaces__msg__VisitorArrival * msg);

/// Finalize msg/VisitorArrival message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__VisitorArrival__fini(campus_tour_interfaces__msg__VisitorArrival * msg);

/// Create msg/VisitorArrival message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * campus_tour_interfaces__msg__VisitorArrival__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
campus_tour_interfaces__msg__VisitorArrival *
campus_tour_interfaces__msg__VisitorArrival__create();

/// Destroy msg/VisitorArrival message.
/**
 * It calls
 * campus_tour_interfaces__msg__VisitorArrival__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__VisitorArrival__destroy(campus_tour_interfaces__msg__VisitorArrival * msg);

/// Check for msg/VisitorArrival message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__VisitorArrival__are_equal(const campus_tour_interfaces__msg__VisitorArrival * lhs, const campus_tour_interfaces__msg__VisitorArrival * rhs);

/// Copy a msg/VisitorArrival message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__VisitorArrival__copy(
  const campus_tour_interfaces__msg__VisitorArrival * input,
  campus_tour_interfaces__msg__VisitorArrival * output);

/// Initialize array of msg/VisitorArrival messages.
/**
 * It allocates the memory for the number of elements and calls
 * campus_tour_interfaces__msg__VisitorArrival__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__VisitorArrival__Sequence__init(campus_tour_interfaces__msg__VisitorArrival__Sequence * array, size_t size);

/// Finalize array of msg/VisitorArrival messages.
/**
 * It calls
 * campus_tour_interfaces__msg__VisitorArrival__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__VisitorArrival__Sequence__fini(campus_tour_interfaces__msg__VisitorArrival__Sequence * array);

/// Create array of msg/VisitorArrival messages.
/**
 * It allocates the memory for the array and calls
 * campus_tour_interfaces__msg__VisitorArrival__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
campus_tour_interfaces__msg__VisitorArrival__Sequence *
campus_tour_interfaces__msg__VisitorArrival__Sequence__create(size_t size);

/// Destroy array of msg/VisitorArrival messages.
/**
 * It calls
 * campus_tour_interfaces__msg__VisitorArrival__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__VisitorArrival__Sequence__destroy(campus_tour_interfaces__msg__VisitorArrival__Sequence * array);

/// Check for msg/VisitorArrival message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__VisitorArrival__Sequence__are_equal(const campus_tour_interfaces__msg__VisitorArrival__Sequence * lhs, const campus_tour_interfaces__msg__VisitorArrival__Sequence * rhs);

/// Copy an array of msg/VisitorArrival messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__VisitorArrival__Sequence__copy(
  const campus_tour_interfaces__msg__VisitorArrival__Sequence * input,
  campus_tour_interfaces__msg__VisitorArrival__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__FUNCTIONS_H_
