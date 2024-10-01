// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from campus_tour_interfaces:msg/VisitorArrival.idl
// generated code does not contain a copyright notice
#include "campus_tour_interfaces/msg/detail/visitor_arrival__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "campus_tour_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "campus_tour_interfaces/msg/detail/visitor_arrival__struct.h"
#include "campus_tour_interfaces/msg/detail/visitor_arrival__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // building_id, ci_id, host_id, visitor_id, visitor_position
#include "rosidl_runtime_c/string_functions.h"  // building_id, ci_id, host_id, visitor_id, visitor_position

// forward declare type support functions


using _VisitorArrival__ros_msg_type = campus_tour_interfaces__msg__VisitorArrival;

static bool _VisitorArrival__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VisitorArrival__ros_msg_type * ros_message = static_cast<const _VisitorArrival__ros_msg_type *>(untyped_ros_message);
  // Field name: building_id
  {
    const rosidl_runtime_c__String * str = &ros_message->building_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: host_id
  {
    const rosidl_runtime_c__String * str = &ros_message->host_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: visitor_id
  {
    const rosidl_runtime_c__String * str = &ros_message->visitor_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: ci_id
  {
    const rosidl_runtime_c__String * str = &ros_message->ci_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: visitor_position
  {
    const rosidl_runtime_c__String * str = &ros_message->visitor_position;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _VisitorArrival__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VisitorArrival__ros_msg_type * ros_message = static_cast<_VisitorArrival__ros_msg_type *>(untyped_ros_message);
  // Field name: building_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->building_id.data) {
      rosidl_runtime_c__String__init(&ros_message->building_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->building_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'building_id'\n");
      return false;
    }
  }

  // Field name: host_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->host_id.data) {
      rosidl_runtime_c__String__init(&ros_message->host_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->host_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'host_id'\n");
      return false;
    }
  }

  // Field name: visitor_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->visitor_id.data) {
      rosidl_runtime_c__String__init(&ros_message->visitor_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->visitor_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'visitor_id'\n");
      return false;
    }
  }

  // Field name: ci_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->ci_id.data) {
      rosidl_runtime_c__String__init(&ros_message->ci_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->ci_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'ci_id'\n");
      return false;
    }
  }

  // Field name: visitor_position
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->visitor_position.data) {
      rosidl_runtime_c__String__init(&ros_message->visitor_position);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->visitor_position,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'visitor_position'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_campus_tour_interfaces
size_t get_serialized_size_campus_tour_interfaces__msg__VisitorArrival(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VisitorArrival__ros_msg_type * ros_message = static_cast<const _VisitorArrival__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name building_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->building_id.size + 1);
  // field.name host_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->host_id.size + 1);
  // field.name visitor_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->visitor_id.size + 1);
  // field.name ci_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->ci_id.size + 1);
  // field.name visitor_position
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->visitor_position.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _VisitorArrival__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_campus_tour_interfaces__msg__VisitorArrival(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_campus_tour_interfaces
size_t max_serialized_size_campus_tour_interfaces__msg__VisitorArrival(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: building_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: host_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: visitor_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: ci_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: visitor_position
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = campus_tour_interfaces__msg__VisitorArrival;
    is_plain =
      (
      offsetof(DataType, visitor_position) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _VisitorArrival__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_campus_tour_interfaces__msg__VisitorArrival(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_VisitorArrival = {
  "campus_tour_interfaces::msg",
  "VisitorArrival",
  _VisitorArrival__cdr_serialize,
  _VisitorArrival__cdr_deserialize,
  _VisitorArrival__get_serialized_size,
  _VisitorArrival__max_serialized_size
};

static rosidl_message_type_support_t _VisitorArrival__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VisitorArrival,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, campus_tour_interfaces, msg, VisitorArrival)() {
  return &_VisitorArrival__type_support;
}

#if defined(__cplusplus)
}
#endif
