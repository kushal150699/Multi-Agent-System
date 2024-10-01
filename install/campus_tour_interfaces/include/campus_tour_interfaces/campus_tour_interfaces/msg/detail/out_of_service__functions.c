// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from campus_tour_interfaces:msg/OutOfService.idl
// generated code does not contain a copyright notice
#include "campus_tour_interfaces/msg/detail/out_of_service__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `bi_id`
#include "rosidl_runtime_c/string_functions.h"

bool
campus_tour_interfaces__msg__OutOfService__init(campus_tour_interfaces__msg__OutOfService * msg)
{
  if (!msg) {
    return false;
  }
  // bi_id
  if (!rosidl_runtime_c__String__init(&msg->bi_id)) {
    campus_tour_interfaces__msg__OutOfService__fini(msg);
    return false;
  }
  // duration
  return true;
}

void
campus_tour_interfaces__msg__OutOfService__fini(campus_tour_interfaces__msg__OutOfService * msg)
{
  if (!msg) {
    return;
  }
  // bi_id
  rosidl_runtime_c__String__fini(&msg->bi_id);
  // duration
}

bool
campus_tour_interfaces__msg__OutOfService__are_equal(const campus_tour_interfaces__msg__OutOfService * lhs, const campus_tour_interfaces__msg__OutOfService * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // bi_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->bi_id), &(rhs->bi_id)))
  {
    return false;
  }
  // duration
  if (lhs->duration != rhs->duration) {
    return false;
  }
  return true;
}

bool
campus_tour_interfaces__msg__OutOfService__copy(
  const campus_tour_interfaces__msg__OutOfService * input,
  campus_tour_interfaces__msg__OutOfService * output)
{
  if (!input || !output) {
    return false;
  }
  // bi_id
  if (!rosidl_runtime_c__String__copy(
      &(input->bi_id), &(output->bi_id)))
  {
    return false;
  }
  // duration
  output->duration = input->duration;
  return true;
}

campus_tour_interfaces__msg__OutOfService *
campus_tour_interfaces__msg__OutOfService__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  campus_tour_interfaces__msg__OutOfService * msg = (campus_tour_interfaces__msg__OutOfService *)allocator.allocate(sizeof(campus_tour_interfaces__msg__OutOfService), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(campus_tour_interfaces__msg__OutOfService));
  bool success = campus_tour_interfaces__msg__OutOfService__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
campus_tour_interfaces__msg__OutOfService__destroy(campus_tour_interfaces__msg__OutOfService * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    campus_tour_interfaces__msg__OutOfService__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
campus_tour_interfaces__msg__OutOfService__Sequence__init(campus_tour_interfaces__msg__OutOfService__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  campus_tour_interfaces__msg__OutOfService * data = NULL;

  if (size) {
    data = (campus_tour_interfaces__msg__OutOfService *)allocator.zero_allocate(size, sizeof(campus_tour_interfaces__msg__OutOfService), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = campus_tour_interfaces__msg__OutOfService__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        campus_tour_interfaces__msg__OutOfService__fini(&data[i - 1]);
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
campus_tour_interfaces__msg__OutOfService__Sequence__fini(campus_tour_interfaces__msg__OutOfService__Sequence * array)
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
      campus_tour_interfaces__msg__OutOfService__fini(&array->data[i]);
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

campus_tour_interfaces__msg__OutOfService__Sequence *
campus_tour_interfaces__msg__OutOfService__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  campus_tour_interfaces__msg__OutOfService__Sequence * array = (campus_tour_interfaces__msg__OutOfService__Sequence *)allocator.allocate(sizeof(campus_tour_interfaces__msg__OutOfService__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = campus_tour_interfaces__msg__OutOfService__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
campus_tour_interfaces__msg__OutOfService__Sequence__destroy(campus_tour_interfaces__msg__OutOfService__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    campus_tour_interfaces__msg__OutOfService__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
campus_tour_interfaces__msg__OutOfService__Sequence__are_equal(const campus_tour_interfaces__msg__OutOfService__Sequence * lhs, const campus_tour_interfaces__msg__OutOfService__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!campus_tour_interfaces__msg__OutOfService__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
campus_tour_interfaces__msg__OutOfService__Sequence__copy(
  const campus_tour_interfaces__msg__OutOfService__Sequence * input,
  campus_tour_interfaces__msg__OutOfService__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(campus_tour_interfaces__msg__OutOfService);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    campus_tour_interfaces__msg__OutOfService * data =
      (campus_tour_interfaces__msg__OutOfService *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!campus_tour_interfaces__msg__OutOfService__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          campus_tour_interfaces__msg__OutOfService__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!campus_tour_interfaces__msg__OutOfService__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
