// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from campus_tour_interfaces:msg/AccessDenied.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "campus_tour_interfaces/msg/detail/access_denied__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace campus_tour_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void AccessDenied_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) campus_tour_interfaces::msg::AccessDenied(_init);
}

void AccessDenied_fini_function(void * message_memory)
{
  auto typed_message = static_cast<campus_tour_interfaces::msg::AccessDenied *>(message_memory);
  typed_message->~AccessDenied();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AccessDenied_message_member_array[2] = {
  {
    "visitor_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces::msg::AccessDenied, visitor_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "reason",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces::msg::AccessDenied, reason),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AccessDenied_message_members = {
  "campus_tour_interfaces::msg",  // message namespace
  "AccessDenied",  // message name
  2,  // number of fields
  sizeof(campus_tour_interfaces::msg::AccessDenied),
  AccessDenied_message_member_array,  // message members
  AccessDenied_init_function,  // function to initialize message memory (memory has to be allocated)
  AccessDenied_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AccessDenied_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AccessDenied_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace campus_tour_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<campus_tour_interfaces::msg::AccessDenied>()
{
  return &::campus_tour_interfaces::msg::rosidl_typesupport_introspection_cpp::AccessDenied_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, campus_tour_interfaces, msg, AccessDenied)() {
  return &::campus_tour_interfaces::msg::rosidl_typesupport_introspection_cpp::AccessDenied_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
