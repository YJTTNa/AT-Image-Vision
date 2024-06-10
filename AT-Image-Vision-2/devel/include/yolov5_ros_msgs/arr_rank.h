// Generated by gencpp from file yolov5_ros_msgs/arr_rank.msg
// DO NOT EDIT!


#ifndef YOLOV5_ROS_MSGS_MESSAGE_ARR_RANK_H
#define YOLOV5_ROS_MSGS_MESSAGE_ARR_RANK_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <yolov5_ros_msgs/arr.h>

namespace yolov5_ros_msgs
{
template <class ContainerAllocator>
struct arr_rank_
{
  typedef arr_rank_<ContainerAllocator> Type;

  arr_rank_()
    : arrs()
    , rank()  {
    }
  arr_rank_(const ContainerAllocator& _alloc)
    : arrs(_alloc)
    , rank(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::yolov5_ros_msgs::arr_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::yolov5_ros_msgs::arr_<ContainerAllocator> >> _arrs_type;
  _arrs_type arrs;

   typedef std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> _rank_type;
  _rank_type rank;





  typedef boost::shared_ptr< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> const> ConstPtr;

}; // struct arr_rank_

typedef ::yolov5_ros_msgs::arr_rank_<std::allocator<void> > arr_rank;

typedef boost::shared_ptr< ::yolov5_ros_msgs::arr_rank > arr_rankPtr;
typedef boost::shared_ptr< ::yolov5_ros_msgs::arr_rank const> arr_rankConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::yolov5_ros_msgs::arr_rank_<ContainerAllocator1> & lhs, const ::yolov5_ros_msgs::arr_rank_<ContainerAllocator2> & rhs)
{
  return lhs.arrs == rhs.arrs &&
    lhs.rank == rhs.rank;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::yolov5_ros_msgs::arr_rank_<ContainerAllocator1> & lhs, const ::yolov5_ros_msgs::arr_rank_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace yolov5_ros_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fda0ba7f4327a4a5573e422b6bef24b9";
  }

  static const char* value(const ::yolov5_ros_msgs::arr_rank_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfda0ba7f4327a4a5ULL;
  static const uint64_t static_value2 = 0x573e422b6bef24b9ULL;
};

template<class ContainerAllocator>
struct DataType< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> >
{
  static const char* value()
  {
    return "yolov5_ros_msgs/arr_rank";
  }

  static const char* value(const ::yolov5_ros_msgs::arr_rank_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> >
{
  static const char* value()
  {
    return "arr[] arrs\n"
"int32[] rank\n"
"================================================================================\n"
"MSG: yolov5_ros_msgs/arr\n"
"int32[] arr\n"
;
  }

  static const char* value(const ::yolov5_ros_msgs::arr_rank_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.arrs);
      stream.next(m.rank);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct arr_rank_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::yolov5_ros_msgs::arr_rank_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::yolov5_ros_msgs::arr_rank_<ContainerAllocator>& v)
  {
    s << indent << "arrs[]" << std::endl;
    for (size_t i = 0; i < v.arrs.size(); ++i)
    {
      s << indent << "  arrs[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::yolov5_ros_msgs::arr_<ContainerAllocator> >::stream(s, indent + "    ", v.arrs[i]);
    }
    s << indent << "rank[]" << std::endl;
    for (size_t i = 0; i < v.rank.size(); ++i)
    {
      s << indent << "  rank[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.rank[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // YOLOV5_ROS_MSGS_MESSAGE_ARR_RANK_H
