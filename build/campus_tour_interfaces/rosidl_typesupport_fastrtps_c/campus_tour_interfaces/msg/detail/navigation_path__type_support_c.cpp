// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from campus_tour_interfaces:msg/NavigationPath.idl
// generated code does not contain a copyright notice
#include "campus_tour_interfaces/msg/detail/navigation_path__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "campus_tour_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "campus_tour_interfaces/msg/detail/navigation_path__struct.h"
#include "campus_tour_interfaces/msg/detail/navigation_path__functions.h"
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

#include "rosidl_runtime_c/string.h"  // host_id, path, visitor_id
#include "rosidl_runtime_c/string_functions.h"  // host_id, path, visitor_id

// forward declare type support functions


using _NavigationPath__ros_msg_type = campus_tour_interfaces__msg__NavigationPath;

static bool _NavigationPath__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _NavigationPath__ros_msg_type * ros_message = static_cast<const _NavigationPath__ros_msg_type *>(untyped_ros_message);
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

  // Field name: path
  {
    size_t size = ros_message->path.size;
    auto array_ptr = ros_message->path.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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
  }

  return true;
}

static bool _NavigationPath__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _NavigationPath__ros_msg_type * ros_message = static_cast<_NavigationPath__ros_msg_type *>(untyped_ros_message);
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

  // Field name: path
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->path.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->path);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->path, size)) {
      fprintf(stderr, "failed to create array for field 'path'");
      return false;
    }
    auto array_ptr = ros_message->path.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'path'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_campus_tour_interfaces
size_t get_serialized_size_campus_tour_interfaces__msg__NavigationPath(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavigationPath__ros_msg_type * ros_message = static_cast<const _NavigationPath__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name visitor_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->visitor_id.size + 1);
  // field.name host_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->host_id.size + 1);
  // field.name path
  {
    size_t array_size = ros_message->path.size;
    auto array_ptr = ros_message->path.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _NavigationPath__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_campus_tour_interfaces__msg__NavigationPath(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_campus_tour_interfaces
size_t max_serialized_size_campus_tour_interfaces__msg__NavigationPath(
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
  // member: path
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

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
    using DataType = campus_tour_interfaces__msg__NavigationPath;
    is_plain =
      (
      offsetof(DataType, path) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _NavigationPath__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_campus_tour_interfaces__msg__NavigationPath(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_NavigationPath = {
  "campus_tour_interfaces::msg",
  "NavigationPath",
  _NavigationPath__cdr_serialize,
  _NavigationPath__cdr_deserialize,
  _NavigationPath__get_serialized_size,
  _NavigationPath__max_serialized_size
};

static rosidl_message_type_support_t _NavigationPath__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NavigationPath,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, campus_tour_interfaces, msg, NavigationPath)() {
  return &_NavigationPath__type_support;
}

#if defined(__cplusplus)
}
#endif
