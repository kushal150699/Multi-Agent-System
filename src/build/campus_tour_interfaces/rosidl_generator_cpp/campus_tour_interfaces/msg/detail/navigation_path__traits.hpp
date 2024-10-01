// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from campus_tour_interfaces:msg/NavigationPath.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__TRAITS_HPP_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "campus_tour_interfaces/msg/detail/navigation_path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace campus_tour_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavigationPath & msg,
  std::ostream & out)
{
  out << "{";
  // member: visitor_id
  {
    out << "visitor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.visitor_id, out);
    out << ", ";
  }

  // member: host_id
  {
    out << "host_id: ";
    rosidl_generator_traits::value_to_yaml(msg.host_id, out);
    out << ", ";
  }

  // member: path
  {
    if (msg.path.size() == 0) {
      out << "path: []";
    } else {
      out << "path: [";
      size_t pending_items = msg.path.size();
      for (auto item : msg.path) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigationPath & msg,
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

  // member: host_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "host_id: ";
    rosidl_generator_traits::value_to_yaml(msg.host_id, out);
    out << "\n";
  }

  // member: path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.path.size() == 0) {
      out << "path: []\n";
    } else {
      out << "path:\n";
      for (auto item : msg.path) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigationPath & msg, bool use_flow_style = false)
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
  const campus_tour_interfaces::msg::NavigationPath & msg,
  std::ostream & out, size_t indentation = 0)
{
  campus_tour_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use campus_tour_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const campus_tour_interfaces::msg::NavigationPath & msg)
{
  return campus_tour_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<campus_tour_interfaces::msg::NavigationPath>()
{
  return "campus_tour_interfaces::msg::NavigationPath";
}

template<>
inline const char * name<campus_tour_interfaces::msg::NavigationPath>()
{
  return "campus_tour_interfaces/msg/NavigationPath";
}

template<>
struct has_fixed_size<campus_tour_interfaces::msg::NavigationPath>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<campus_tour_interfaces::msg::NavigationPath>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<campus_tour_interfaces::msg::NavigationPath>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__TRAITS_HPP_
