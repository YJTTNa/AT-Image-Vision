// Generated by gencpp from file yolov5_ros_msgs/X_Y_ARG.msg
// DO NOT EDIT!


#ifndef YOLOV5_ROS_MSGS_MESSAGE_X_Y_ARG_H
#define YOLOV5_ROS_MSGS_MESSAGE_X_Y_ARG_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace yolov5_ros_msgs
{
template <class ContainerAllocator>
struct X_Y_ARG_
{
  typedef X_Y_ARG_<ContainerAllocator> Type;

  X_Y_ARG_()
    : x(0)
    , y(0)
    , arg(0)
    , mode(0)  {
    }
  X_Y_ARG_(const ContainerAllocator& _alloc)
    : x(0)
    , y(0)
    , arg(0)
    , mode(0)  {
  (void)_alloc;
    }



   typedef int16_t _x_type;
  _x_type x;

   typedef int16_t _y_type;
  _y_type y;

   typedef int16_t _arg_type;
  _arg_type arg;

   typedef int16_t _mode_type;
  _mode_type mode;





  typedef boost::shared_ptr< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> const> ConstPtr;

}; // struct X_Y_ARG_

typedef ::yolov5_ros_msgs::X_Y_ARG_<std::allocator<void> > X_Y_ARG;

typedef boost::shared_ptr< ::yolov5_ros_msgs::X_Y_ARG > X_Y_ARGPtr;
typedef boost::shared_ptr< ::yolov5_ros_msgs::X_Y_ARG const> X_Y_ARGConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator1> & lhs, const ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.arg == rhs.arg &&
    lhs.mode == rhs.mode;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator1> & lhs, const ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace yolov5_ros_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3221f6e0c05aea0457e6a44220fa22a2";
  }

  static const char* value(const ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3221f6e0c05aea04ULL;
  static const uint64_t static_value2 = 0x57e6a44220fa22a2ULL;
};

template<class ContainerAllocator>
struct DataType< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> >
{
  static const char* value()
  {
    return "yolov5_ros_msgs/X_Y_ARG";
  }

  static const char* value(const ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16 x\n"
"int16 y\n"
"int16 arg\n"
"int16 mode\n"
;
  }

  static const char* value(const ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.arg);
      stream.next(m.mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct X_Y_ARG_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::yolov5_ros_msgs::X_Y_ARG_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<int16_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<int16_t>::stream(s, indent + "  ", v.y);
    s << indent << "arg: ";
    Printer<int16_t>::stream(s, indent + "  ", v.arg);
    s << indent << "mode: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // YOLOV5_ROS_MSGS_MESSAGE_X_Y_ARG_H
