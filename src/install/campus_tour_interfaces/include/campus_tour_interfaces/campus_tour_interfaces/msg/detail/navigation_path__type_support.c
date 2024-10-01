// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from campus_tour_interfaces:msg/NavigationPath.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "campus_tour_interfaces/msg/detail/navigation_path__rosidl_typesupport_introspection_c.h"
#include "campus_tour_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "campus_tour_interfaces/msg/detail/navigation_path__functions.h"
#include "campus_tour_interfaces/msg/detail/navigation_path__struct.h"


// Include directives for member types
// Member `visitor_id`
// Member `host_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `path`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  campus_tour_interfaces__msg__NavigationPath__init(message_memory);
}

void campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_fini_function(void * message_memory)
{
  campus_tour_interfaces__msg__NavigationPath__fini(message_memory);
}

size_t campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__size_function__NavigationPath__path(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__get_const_function__NavigationPath__path(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__get_function__NavigationPath__path(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__fetch_function__NavigationPath__path(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__get_const_function__NavigationPath__path(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__assign_function__NavigationPath__path(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__get_function__NavigationPath__path(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__resize_function__NavigationPath__path(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_message_member_array[3] = {
  {
    "visitor_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces__msg__NavigationPath, visitor_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "host_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces__msg__NavigationPath, host_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces__msg__NavigationPath, path),  // bytes offset in struct
    NULL,  // default value
    campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__size_function__NavigationPath__path,  // size() function pointer
    campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__get_const_function__NavigationPath__path,  // get_const(index) function pointer
    campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__get_function__NavigationPath__path,  // get(index) function pointer
    campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__fetch_function__NavigationPath__path,  // fetch(index, &value) function pointer
    campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__assign_function__NavigationPath__path,  // assign(index, value) function pointer
    campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__resize_function__NavigationPath__path  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_message_members = {
  "campus_tour_interfaces__msg",  // message namespace
  "NavigationPath",  // message name
  3,  // number of fields
  sizeof(campus_tour_interfaces__msg__NavigationPath),
  campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_message_member_array,  // message members
  campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_init_function,  // function to initialize message memory (memory has to be allocated)
  campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_message_type_support_handle = {
  0,
  &campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_campus_tour_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, campus_tour_interfaces, msg, NavigationPath)() {
  if (!campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_message_type_support_handle.typesupport_identifier) {
    campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &campus_tour_interfaces__msg__NavigationPath__rosidl_typesupport_introspection_c__NavigationPath_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
