// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from campus_tour_interfaces:msg/AccessDenied.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__BUILDER_HPP_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "campus_tour_interfaces/msg/detail/access_denied__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace campus_tour_interfaces
{

namespace msg
{

namespace builder
{

class Init_AccessDenied_reason
{
public:
  explicit Init_AccessDenied_reason(::campus_tour_interfaces::msg::AccessDenied & msg)
  : msg_(msg)
  {}
  ::campus_tour_interfaces::msg::AccessDenied reason(::campus_tour_interfaces::msg::AccessDenied::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return std::move(msg_);
  }

private:
  ::campus_tour_interfaces::msg::AccessDenied msg_;
};

class Init_AccessDenied_visitor_id
{
public:
  Init_AccessDenied_visitor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AccessDenied_reason visitor_id(::campus_tour_interfaces::msg::AccessDenied::_visitor_id_type arg)
  {
    msg_.visitor_id = std::move(arg);
    return Init_AccessDenied_reason(msg_);
  }

private:
  ::campus_tour_interfaces::msg::AccessDenied msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::campus_tour_interfaces::msg::AccessDenied>()
{
  return campus_tour_interfaces::msg::builder::Init_AccessDenied_visitor_id();
}

}  // namespace campus_tour_interfaces

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__BUILDER_HPP_
