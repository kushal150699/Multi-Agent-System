// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from campus_tour_interfaces:msg/VisitorArrival.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__BUILDER_HPP_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "campus_tour_interfaces/msg/detail/visitor_arrival__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace campus_tour_interfaces
{

namespace msg
{

namespace builder
{

class Init_VisitorArrival_visitor_position
{
public:
  explicit Init_VisitorArrival_visitor_position(::campus_tour_interfaces::msg::VisitorArrival & msg)
  : msg_(msg)
  {}
  ::campus_tour_interfaces::msg::VisitorArrival visitor_position(::campus_tour_interfaces::msg::VisitorArrival::_visitor_position_type arg)
  {
    msg_.visitor_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::campus_tour_interfaces::msg::VisitorArrival msg_;
};

class Init_VisitorArrival_ci_id
{
public:
  explicit Init_VisitorArrival_ci_id(::campus_tour_interfaces::msg::VisitorArrival & msg)
  : msg_(msg)
  {}
  Init_VisitorArrival_visitor_position ci_id(::campus_tour_interfaces::msg::VisitorArrival::_ci_id_type arg)
  {
    msg_.ci_id = std::move(arg);
    return Init_VisitorArrival_visitor_position(msg_);
  }

private:
  ::campus_tour_interfaces::msg::VisitorArrival msg_;
};

class Init_VisitorArrival_visitor_id
{
public:
  explicit Init_VisitorArrival_visitor_id(::campus_tour_interfaces::msg::VisitorArrival & msg)
  : msg_(msg)
  {}
  Init_VisitorArrival_ci_id visitor_id(::campus_tour_interfaces::msg::VisitorArrival::_visitor_id_type arg)
  {
    msg_.visitor_id = std::move(arg);
    return Init_VisitorArrival_ci_id(msg_);
  }

private:
  ::campus_tour_interfaces::msg::VisitorArrival msg_;
};

class Init_VisitorArrival_host_id
{
public:
  explicit Init_VisitorArrival_host_id(::campus_tour_interfaces::msg::VisitorArrival & msg)
  : msg_(msg)
  {}
  Init_VisitorArrival_visitor_id host_id(::campus_tour_interfaces::msg::VisitorArrival::_host_id_type arg)
  {
    msg_.host_id = std::move(arg);
    return Init_VisitorArrival_visitor_id(msg_);
  }

private:
  ::campus_tour_interfaces::msg::VisitorArrival msg_;
};

class Init_VisitorArrival_building_id
{
public:
  Init_VisitorArrival_building_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisitorArrival_host_id building_id(::campus_tour_interfaces::msg::VisitorArrival::_building_id_type arg)
  {
    msg_.building_id = std::move(arg);
    return Init_VisitorArrival_host_id(msg_);
  }

private:
  ::campus_tour_interfaces::msg::VisitorArrival msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::campus_tour_interfaces::msg::VisitorArrival>()
{
  return campus_tour_interfaces::msg::builder::Init_VisitorArrival_building_id();
}

}  // namespace campus_tour_interfaces

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__BUILDER_HPP_
