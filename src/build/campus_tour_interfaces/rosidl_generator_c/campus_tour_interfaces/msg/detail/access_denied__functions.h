// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from campus_tour_interfaces:msg/AccessDenied.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__FUNCTIONS_H_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "campus_tour_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "campus_tour_interfaces/msg/detail/access_denied__struct.h"

/// Initialize msg/AccessDenied message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * campus_tour_interfaces__msg__AccessDenied
 * )) before or use
 * campus_tour_interfaces__msg__AccessDenied__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__AccessDenied__init(campus_tour_interfaces__msg__AccessDenied * msg);

/// Finalize msg/AccessDenied message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__AccessDenied__fini(campus_tour_interfaces__msg__AccessDenied * msg);

/// Create msg/AccessDenied message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * campus_tour_interfaces__msg__AccessDenied__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
campus_tour_interfaces__msg__AccessDenied *
campus_tour_interfaces__msg__AccessDenied__create();

/// Destroy msg/AccessDenied message.
/**
 * It calls
 * campus_tour_interfaces__msg__AccessDenied__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__AccessDenied__destroy(campus_tour_interfaces__msg__AccessDenied * msg);

/// Check for msg/AccessDenied message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__AccessDenied__are_equal(const campus_tour_interfaces__msg__AccessDenied * lhs, const campus_tour_interfaces__msg__AccessDenied * rhs);

/// Copy a msg/AccessDenied message.
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
campus_tour_interfaces__msg__AccessDenied__copy(
  const campus_tour_interfaces__msg__AccessDenied * input,
  campus_tour_interfaces__msg__AccessDenied * output);

/// Initialize array of msg/AccessDenied messages.
/**
 * It allocates the memory for the number of elements and calls
 * campus_tour_interfaces__msg__AccessDenied__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__AccessDenied__Sequence__init(campus_tour_interfaces__msg__AccessDenied__Sequence * array, size_t size);

/// Finalize array of msg/AccessDenied messages.
/**
 * It calls
 * campus_tour_interfaces__msg__AccessDenied__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__AccessDenied__Sequence__fini(campus_tour_interfaces__msg__AccessDenied__Sequence * array);

/// Create array of msg/AccessDenied messages.
/**
 * It allocates the memory for the array and calls
 * campus_tour_interfaces__msg__AccessDenied__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
campus_tour_interfaces__msg__AccessDenied__Sequence *
campus_tour_interfaces__msg__AccessDenied__Sequence__create(size_t size);

/// Destroy array of msg/AccessDenied messages.
/**
 * It calls
 * campus_tour_interfaces__msg__AccessDenied__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__AccessDenied__Sequence__destroy(campus_tour_interfaces__msg__AccessDenied__Sequence * array);

/// Check for msg/AccessDenied message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__AccessDenied__Sequence__are_equal(const campus_tour_interfaces__msg__AccessDenied__Sequence * lhs, const campus_tour_interfaces__msg__AccessDenied__Sequence * rhs);

/// Copy an array of msg/AccessDenied messages.
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
campus_tour_interfaces__msg__AccessDenied__Sequence__copy(
  const campus_tour_interfaces__msg__AccessDenied__Sequence * input,
  campus_tour_interfaces__msg__AccessDenied__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__FUNCTIONS_H_
