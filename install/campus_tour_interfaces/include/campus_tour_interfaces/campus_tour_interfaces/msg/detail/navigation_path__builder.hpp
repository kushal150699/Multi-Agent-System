// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from campus_tour_interfaces:msg/NavigationPath.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__BUILDER_HPP_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "campus_tour_interfaces/msg/detail/navigation_path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace campus_tour_interfaces
{

namespace msg
{

namespace builder
{

class Init_NavigationPath_path
{
public:
  explicit Init_NavigationPath_path(::campus_tour_interfaces::msg::NavigationPath & msg)
  : msg_(msg)
  {}
  ::campus_tour_interfaces::msg::NavigationPath path(::campus_tour_interfaces::msg::NavigationPath::_path_type arg)
  {
    msg_.path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::campus_tour_interfaces::msg::NavigationPath msg_;
};

class Init_NavigationPath_host_id
{
public:
  explicit Init_NavigationPath_host_id(::campus_tour_interfaces::msg::NavigationPath & msg)
  : msg_(msg)
  {}
  Init_NavigationPath_path host_id(::campus_tour_interfaces::msg::NavigationPath::_host_id_type arg)
  {
    msg_.host_id = std::move(arg);
    return Init_NavigationPath_path(msg_);
  }

private:
  ::campus_tour_interfaces::msg::NavigationPath msg_;
};

class Init_NavigationPath_visitor_id
{
public:
  Init_NavigationPath_visitor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationPath_host_id visitor_id(::campus_tour_interfaces::msg::NavigationPath::_visitor_id_type arg)
  {
    msg_.visitor_id = std::move(arg);
    return Init_NavigationPath_host_id(msg_);
  }

private:
  ::campus_tour_interfaces::msg::NavigationPath msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::campus_tour_interfaces::msg::NavigationPath>()
{
  return campus_tour_interfaces::msg::builder::Init_NavigationPath_visitor_id();
}

}  // namespace campus_tour_interfaces

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__BUILDER_HPP_
