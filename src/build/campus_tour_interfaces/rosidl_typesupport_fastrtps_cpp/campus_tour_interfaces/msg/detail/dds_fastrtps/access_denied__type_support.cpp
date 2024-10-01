// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from campus_tour_interfaces:msg/AccessDenied.idl
// generated code does not contain a copyright notice
#include "campus_tour_interfaces/msg/detail/access_denied__rosidl_typesupport_fastrtps_cpp.hpp"
#include "campus_tour_interfaces/msg/detail/access_denied__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace campus_tour_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_campus_tour_interfaces
cdr_serialize(
  const campus_tour_interfaces::msg::AccessDenied & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: visitor_id
  cdr << ros_message.visitor_id;
  // Member: reason
  cdr << ros_message.reason;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_campus_tour_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  campus_tour_interfaces::msg::AccessDenied & ros_message)
{
  // Member: visitor_id
  cdr >> ros_message.visitor_id;

  // Member: reason
  cdr >> ros_message.reason;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_campus_tour_interfaces
get_serialized_size(
  const campus_tour_interfaces::msg::AccessDenied & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: visitor_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.visitor_id.size() + 1);
  // Member: reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.reason.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_campus_tour_interfaces
max_serialized_size_AccessDenied(
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


  // Member: visitor_id
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

  // Member: reason
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
    using DataType = campus_tour_interfaces::msg::AccessDenied;
    is_plain =
      (
      offsetof(DataType, reason) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _AccessDenied__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const campus_tour_interfaces::msg::AccessDenied *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _AccessDenied__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<campus_tour_interfaces::msg::AccessDenied *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _AccessDenied__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const campus_tour_interfaces::msg::AccessDenied *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _AccessDenied__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_AccessDenied(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _AccessDenied__callbacks = {
  "campus_tour_interfaces::msg",
  "AccessDenied",
  _AccessDenied__cdr_serialize,
  _AccessDenied__cdr_deserialize,
  _AccessDenied__get_serialized_size,
  _AccessDenied__max_serialized_size
};

static rosidl_message_type_support_t _AccessDenied__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_AccessDenied__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace campus_tour_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_campus_tour_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<campus_tour_interfaces::msg::AccessDenied>()
{
  return &campus_tour_interfaces::msg::typesupport_fastrtps_cpp::_AccessDenied__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, campus_tour_interfaces, msg, AccessDenied)() {
  return &campus_tour_interfaces::msg::typesupport_fastrtps_cpp::_AccessDenied__handle;
}

#ifdef __cplusplus
}
#endif
