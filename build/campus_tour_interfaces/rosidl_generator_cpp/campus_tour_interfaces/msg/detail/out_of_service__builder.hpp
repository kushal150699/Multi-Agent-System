// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from campus_tour_interfaces:msg/OutOfService.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__OUT_OF_SERVICE__BUILDER_HPP_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__OUT_OF_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "campus_tour_interfaces/msg/detail/out_of_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace campus_tour_interfaces
{

namespace msg
{

namespace builder
{

class Init_OutOfService_duration
{
public:
  explicit Init_OutOfService_duration(::campus_tour_interfaces::msg::OutOfService & msg)
  : msg_(msg)
  {}
  ::campus_tour_interfaces::msg::OutOfService duration(::campus_tour_interfaces::msg::OutOfService::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::campus_tour_interfaces::msg::OutOfService msg_;
};

class Init_OutOfService_bi_id
{
public:
  Init_OutOfService_bi_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OutOfService_duration bi_id(::campus_tour_interfaces::msg::OutOfService::_bi_id_type arg)
  {
    msg_.bi_id = std::move(arg);
    return Init_OutOfService_duration(msg_);
  }

private:
  ::campus_tour_interfaces::msg::OutOfService msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::campus_tour_interfaces::msg::OutOfService>()
{
  return campus_tour_interfaces::msg::builder::Init_OutOfService_bi_id();
}

}  // namespace campus_tour_interfaces

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__OUT_OF_SERVICE__BUILDER_HPP_
