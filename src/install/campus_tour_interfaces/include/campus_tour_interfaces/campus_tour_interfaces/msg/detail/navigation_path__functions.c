// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from campus_tour_interfaces:msg/NavigationPath.idl
// generated code does not contain a copyright notice
#include "campus_tour_interfaces/msg/detail/navigation_path__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `visitor_id`
// Member `host_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `path`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
campus_tour_interfaces__msg__NavigationPath__init(campus_tour_interfaces__msg__NavigationPath * msg)
{
  if (!msg) {
    return false;
  }
  // visitor_id
  if (!rosidl_runtime_c__String__init(&msg->visitor_id)) {
    campus_tour_interfaces__msg__NavigationPath__fini(msg);
    return false;
  }
  // host_id
  if (!rosidl_runtime_c__String__init(&msg->host_id)) {
    campus_tour_interfaces__msg__NavigationPath__fini(msg);
    return false;
  }
  // path
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->path, 0)) {
    campus_tour_interfaces__msg__NavigationPath__fini(msg);
    return false;
  }
  return true;
}

void
campus_tour_interfaces__msg__NavigationPath__fini(campus_tour_interfaces__msg__NavigationPath * msg)
{
  if (!msg) {
    return;
  }
  // visitor_id
  rosidl_runtime_c__String__fini(&msg->visitor_id);
  // host_id
  rosidl_runtime_c__String__fini(&msg->host_id);
  // path
  rosidl_runtime_c__int32__Sequence__fini(&msg->path);
}

bool
campus_tour_interfaces__msg__NavigationPath__are_equal(const campus_tour_interfaces__msg__NavigationPath * lhs, const campus_tour_interfaces__msg__NavigationPath * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // visitor_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->visitor_id), &(rhs->visitor_id)))
  {
    return false;
  }
  // host_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->host_id), &(rhs->host_id)))
  {
    return false;
  }
  // path
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->path), &(rhs->path)))
  {
    return false;
  }
  return true;
}

bool
campus_tour_interfaces__msg__NavigationPath__copy(
  const campus_tour_interfaces__msg__NavigationPath * input,
  campus_tour_interfaces__msg__NavigationPath * output)
{
  if (!input || !output) {
    return false;
  }
  // visitor_id
  if (!rosidl_runtime_c__String__copy(
      &(input->visitor_id), &(output->visitor_id)))
  {
    return false;
  }
  // host_id
  if (!rosidl_runtime_c__String__copy(
      &(input->host_id), &(output->host_id)))
  {
    return false;
  }
  // path
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->path), &(output->path)))
  {
    return false;
  }
  return true;
}

campus_tour_interfaces__msg__NavigationPath *
campus_tour_interfaces__msg__NavigationPath__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  campus_tour_interfaces__msg__NavigationPath * msg = (campus_tour_interfaces__msg__NavigationPath *)allocator.allocate(sizeof(campus_tour_interfaces__msg__NavigationPath), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(campus_tour_interfaces__msg__NavigationPath));
  bool success = campus_tour_interfaces__msg__NavigationPath__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
campus_tour_interfaces__msg__NavigationPath__destroy(campus_tour_interfaces__msg__NavigationPath * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    campus_tour_interfaces__msg__NavigationPath__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
campus_tour_interfaces__msg__NavigationPath__Sequence__init(campus_tour_interfaces__msg__NavigationPath__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  campus_tour_interfaces__msg__NavigationPath * data = NULL;

  if (size) {
    data = (campus_tour_interfaces__msg__NavigationPath *)allocator.zero_allocate(size, sizeof(campus_tour_interfaces__msg__NavigationPath), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = campus_tour_interfaces__msg__NavigationPath__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        campus_tour_interfaces__msg__NavigationPath__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
campus_tour_interfaces__msg__NavigationPath__Sequence__fini(campus_tour_interfaces__msg__NavigationPath__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      campus_tour_interfaces__msg__NavigationPath__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

campus_tour_interfaces__msg__NavigationPath__Sequence *
campus_tour_interfaces__msg__NavigationPath__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  campus_tour_interfaces__msg__NavigationPath__Sequence * array = (campus_tour_interfaces__msg__NavigationPath__Sequence *)allocator.allocate(sizeof(campus_tour_interfaces__msg__NavigationPath__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = campus_tour_interfaces__msg__NavigationPath__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
campus_tour_interfaces__msg__NavigationPath__Sequence__destroy(campus_tour_interfaces__msg__NavigationPath__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    campus_tour_interfaces__msg__NavigationPath__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
campus_tour_interfaces__msg__NavigationPath__Sequence__are_equal(const campus_tour_interfaces__msg__NavigationPath__Sequence * lhs, const campus_tour_interfaces__msg__NavigationPath__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!campus_tour_interfaces__msg__NavigationPath__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
campus_tour_interfaces__msg__NavigationPath__Sequence__copy(
  const campus_tour_interfaces__msg__NavigationPath__Sequence * input,
  campus_tour_interfaces__msg__NavigationPath__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(campus_tour_interfaces__msg__NavigationPath);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    campus_tour_interfaces__msg__NavigationPath * data =
      (campus_tour_interfaces__msg__NavigationPath *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!campus_tour_interfaces__msg__NavigationPath__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          campus_tour_interfaces__msg__NavigationPath__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!campus_tour_interfaces__msg__NavigationPath__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
