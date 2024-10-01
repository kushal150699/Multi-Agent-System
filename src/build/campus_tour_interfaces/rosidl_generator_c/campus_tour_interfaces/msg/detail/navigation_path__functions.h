// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from campus_tour_interfaces:msg/NavigationPath.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__FUNCTIONS_H_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "campus_tour_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "campus_tour_interfaces/msg/detail/navigation_path__struct.h"

/// Initialize msg/NavigationPath message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * campus_tour_interfaces__msg__NavigationPath
 * )) before or use
 * campus_tour_interfaces__msg__NavigationPath__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__NavigationPath__init(campus_tour_interfaces__msg__NavigationPath * msg);

/// Finalize msg/NavigationPath message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__NavigationPath__fini(campus_tour_interfaces__msg__NavigationPath * msg);

/// Create msg/NavigationPath message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * campus_tour_interfaces__msg__NavigationPath__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
campus_tour_interfaces__msg__NavigationPath *
campus_tour_interfaces__msg__NavigationPath__create();

/// Destroy msg/NavigationPath message.
/**
 * It calls
 * campus_tour_interfaces__msg__NavigationPath__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__NavigationPath__destroy(campus_tour_interfaces__msg__NavigationPath * msg);

/// Check for msg/NavigationPath message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__NavigationPath__are_equal(const campus_tour_interfaces__msg__NavigationPath * lhs, const campus_tour_interfaces__msg__NavigationPath * rhs);

/// Copy a msg/NavigationPath message.
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
campus_tour_interfaces__msg__NavigationPath__copy(
  const campus_tour_interfaces__msg__NavigationPath * input,
  campus_tour_interfaces__msg__NavigationPath * output);

/// Initialize array of msg/NavigationPath messages.
/**
 * It allocates the memory for the number of elements and calls
 * campus_tour_interfaces__msg__NavigationPath__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__NavigationPath__Sequence__init(campus_tour_interfaces__msg__NavigationPath__Sequence * array, size_t size);

/// Finalize array of msg/NavigationPath messages.
/**
 * It calls
 * campus_tour_interfaces__msg__NavigationPath__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__NavigationPath__Sequence__fini(campus_tour_interfaces__msg__NavigationPath__Sequence * array);

/// Create array of msg/NavigationPath messages.
/**
 * It allocates the memory for the array and calls
 * campus_tour_interfaces__msg__NavigationPath__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
campus_tour_interfaces__msg__NavigationPath__Sequence *
campus_tour_interfaces__msg__NavigationPath__Sequence__create(size_t size);

/// Destroy array of msg/NavigationPath messages.
/**
 * It calls
 * campus_tour_interfaces__msg__NavigationPath__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
void
campus_tour_interfaces__msg__NavigationPath__Sequence__destroy(campus_tour_interfaces__msg__NavigationPath__Sequence * array);

/// Check for msg/NavigationPath message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_campus_tour_interfaces
bool
campus_tour_interfaces__msg__NavigationPath__Sequence__are_equal(const campus_tour_interfaces__msg__NavigationPath__Sequence * lhs, const campus_tour_interfaces__msg__NavigationPath__Sequence * rhs);

/// Copy an array of msg/NavigationPath messages.
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
campus_tour_interfaces__msg__NavigationPath__Sequence__copy(
  const campus_tour_interfaces__msg__NavigationPath__Sequence * input,
  campus_tour_interfaces__msg__NavigationPath__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__FUNCTIONS_H_
