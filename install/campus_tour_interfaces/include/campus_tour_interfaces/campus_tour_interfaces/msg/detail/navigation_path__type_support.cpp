// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from campus_tour_interfaces:msg/NavigationPath.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "campus_tour_interfaces/msg/detail/navigation_path__struct.hpp"
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

void NavigationPath_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) campus_tour_interfaces::msg::NavigationPath(_init);
}

void NavigationPath_fini_function(void * message_memory)
{
  auto typed_message = static_cast<campus_tour_interfaces::msg::NavigationPath *>(message_memory);
  typed_message->~NavigationPath();
}

size_t size_function__NavigationPath__path(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__NavigationPath__path(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__NavigationPath__path(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__NavigationPath__path(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__NavigationPath__path(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__NavigationPath__path(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__NavigationPath__path(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__NavigationPath__path(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember NavigationPath_message_member_array[3] = {
  {
    "visitor_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces::msg::NavigationPath, visitor_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "host_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces::msg::NavigationPath, host_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "path",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(campus_tour_interfaces::msg::NavigationPath, path),  // bytes offset in struct
    nullptr,  // default value
    size_function__NavigationPath__path,  // size() function pointer
    get_const_function__NavigationPath__path,  // get_const(index) function pointer
    get_function__NavigationPath__path,  // get(index) function pointer
    fetch_function__NavigationPath__path,  // fetch(index, &value) function pointer
    assign_function__NavigationPath__path,  // assign(index, value) function pointer
    resize_function__NavigationPath__path  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers NavigationPath_message_members = {
  "campus_tour_interfaces::msg",  // message namespace
  "NavigationPath",  // message name
  3,  // number of fields
  sizeof(campus_tour_interfaces::msg::NavigationPath),
  NavigationPath_message_member_array,  // message members
  NavigationPath_init_function,  // function to initialize message memory (memory has to be allocated)
  NavigationPath_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t NavigationPath_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &NavigationPath_message_members,
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
get_message_type_support_handle<campus_tour_interfaces::msg::NavigationPath>()
{
  return &::campus_tour_interfaces::msg::rosidl_typesupport_introspection_cpp::NavigationPath_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, campus_tour_interfaces, msg, NavigationPath)() {
  return &::campus_tour_interfaces::msg::rosidl_typesupport_introspection_cpp::NavigationPath_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
