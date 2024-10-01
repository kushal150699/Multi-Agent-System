// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from campus_tour_interfaces:msg/OutOfService.idl
// generated code does not contain a copyright notice
#include "campus_tour_interfaces/msg/detail/out_of_service__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "campus_tour_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "campus_tour_interfaces/msg/detail/out_of_service__struct.h"
#include "campus_tour_interfaces/msg/detail/out_of_service__functions.h"
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

#include "rosidl_runtime_c/string.h"  // bi_id
#include "rosidl_runtime_c/string_functions.h"  // bi_id

// forward declare type support functions


using _OutOfService__ros_msg_type = campus_tour_interfaces__msg__OutOfService;

static bool _OutOfService__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _OutOfService__ros_msg_type * ros_message = static_cast<const _OutOfService__ros_msg_type *>(untyped_ros_message);
  // Field name: bi_id
  {
    const rosidl_runtime_c__String * str = &ros_message->bi_id;
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

  // Field name: duration
  {
    cdr << ros_message->duration;
  }

  return true;
}

static bool _OutOfService__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _OutOfService__ros_msg_type * ros_message = static_cast<_OutOfService__ros_msg_type *>(untyped_ros_message);
  // Field name: bi_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bi_id.data) {
      rosidl_runtime_c__String__init(&ros_message->bi_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bi_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bi_id'\n");
      return false;
    }
  }

  // Field name: duration
  {
    cdr >> ros_message->duration;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_campus_tour_interfaces
size_t get_serialized_size_campus_tour_interfaces__msg__OutOfService(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _OutOfService__ros_msg_type * ros_message = static_cast<const _OutOfService__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name bi_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bi_id.size + 1);
  // field.name duration
  {
    size_t item_size = sizeof(ros_message->duration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _OutOfService__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_campus_tour_interfaces__msg__OutOfService(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_campus_tour_interfaces
size_t max_serialized_size_campus_tour_interfaces__msg__OutOfService(
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

  // member: bi_id
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
  // member: duration
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = campus_tour_interfaces__msg__OutOfService;
    is_plain =
      (
      offsetof(DataType, duration) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _OutOfService__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_campus_tour_interfaces__msg__OutOfService(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_OutOfService = {
  "campus_tour_interfaces::msg",
  "OutOfService",
  _OutOfService__cdr_serialize,
  _OutOfService__cdr_deserialize,
  _OutOfService__get_serialized_size,
  _OutOfService__max_serialized_size
};

static rosidl_message_type_support_t _OutOfService__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_OutOfService,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, campus_tour_interfaces, msg, OutOfService)() {
  return &_OutOfService__type_support;
}

#if defined(__cplusplus)
}
#endif
