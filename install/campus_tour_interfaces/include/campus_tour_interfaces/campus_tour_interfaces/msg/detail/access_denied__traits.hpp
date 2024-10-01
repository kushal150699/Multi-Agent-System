// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from campus_tour_interfaces:msg/AccessDenied.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__TRAITS_HPP_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "campus_tour_interfaces/msg/detail/access_denied__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace campus_tour_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AccessDenied & msg,
  std::ostream & out)
{
  out << "{";
  // member: visitor_id
  {
    out << "visitor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.visitor_id, out);
    out << ", ";
  }

  // member: reason
  {
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AccessDenied & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: visitor_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "visitor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.visitor_id, out);
    out << "\n";
  }

  // member: reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AccessDenied & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace campus_tour_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use campus_tour_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const campus_tour_interfaces::msg::AccessDenied & msg,
  std::ostream & out, size_t indentation = 0)
{
  campus_tour_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use campus_tour_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const campus_tour_interfaces::msg::AccessDenied & msg)
{
  return campus_tour_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<campus_tour_interfaces::msg::AccessDenied>()
{
  return "campus_tour_interfaces::msg::AccessDenied";
}

template<>
inline const char * name<campus_tour_interfaces::msg::AccessDenied>()
{
  return "campus_tour_interfaces/msg/AccessDenied";
}

template<>
struct has_fixed_size<campus_tour_interfaces::msg::AccessDenied>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<campus_tour_interfaces::msg::AccessDenied>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<campus_tour_interfaces::msg::AccessDenied>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__TRAITS_HPP_
