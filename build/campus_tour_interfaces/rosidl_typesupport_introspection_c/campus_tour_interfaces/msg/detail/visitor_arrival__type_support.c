// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from campus_tour_interfaces:msg/VisitorArrival.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "campus_tour_interfaces/msg/detail/visitor_arrival__rosidl_typesupport_introspection_c.h"
#include "campus_tour_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "campus_tour_interfaces/msg/detail/visitor_arrival__functions.h"
#include "campus_tour_interfaces/msg/detail/visitor_arrival__struct.h"


// Include directives for member types
// Member `building_id`
// Member `host_id`
// Member `visitor_id`
// Member `ci_id`
// Member `visitor_position`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  campus_tour_interfaces__msg__VisitorArrival__init(message_memory);
}

void campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_fini_function(void * message_memory)
{
  campus_tour_interfaces__msg__VisitorArrival__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_message_member_array[5] = {
  {
    "building_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces__msg__VisitorArrival, building_id),  // bytes offset in struct
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
    offsetof(campus_tour_interfaces__msg__VisitorArrival, host_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "visitor_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces__msg__VisitorArrival, visitor_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ci_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces__msg__VisitorArrival, ci_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "visitor_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces__msg__VisitorArrival, visitor_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_message_members = {
  "campus_tour_interfaces__msg",  // message namespace
  "VisitorArrival",  // message name
  5,  // number of fields
  sizeof(campus_tour_interfaces__msg__VisitorArrival),
  campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_message_member_array,  // message members
  campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_init_function,  // function to initialize message memory (memory has to be allocated)
  campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_message_type_support_handle = {
  0,
  &campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_campus_tour_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, campus_tour_interfaces, msg, VisitorArrival)() {
  if (!campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_message_type_support_handle.typesupport_identifier) {
    campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &campus_tour_interfaces__msg__VisitorArrival__rosidl_typesupport_introspection_c__VisitorArrival_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
