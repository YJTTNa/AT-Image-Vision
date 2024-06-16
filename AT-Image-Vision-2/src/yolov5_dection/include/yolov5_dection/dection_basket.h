///
///***by yami
///***6.8 2024
/// find basket

#ifndef __MY_DECTION__
#define __MY_DECTION__

#include "ros/ros.h"
#include "yolov5_ros_msgs/BoundingBox.h"
#include "yolov5_ros_msgs/BoundingBoxes.h"
#include "yolov5_ros_msgs/arr_rank.h"
#include "yolov5_ros_msgs/arr.h"
#include "unordered_map"
#include "unordered_set"
#include "algorithm"

// 容器来存数据图片 的数据
// 上位版发送请求
namespace Image_vision {
    class My_dection {

        using BoundingBox = yolov5_ros_msgs::BoundingBox;
        using BoundingBoxes = yolov5_ros_msgs::BoundingBoxes;
        using arr_rank = yolov5_ros_msgs::arr_rank;
        using arr = yolov5_ros_msgs::arr;
        public:
            explicit My_dection(ros::NodeHandle nh) {
                ROS_INFO("My_dection create");
                message_sub = nh.subscribe("BoundingBoxes" , 10 , &My_dection::message_callback, this);
            }
            ~My_dection() {
                ROS_INFO("My_dection ");
            }
            
           // void init_ROS_Sub(ros::NodeHandle sh);

            void message_callback(const BoundingBoxes& msg);

            static bool Bas_Compare(const BoundingBox & a , const BoundingBox &b) { return a.xmin < b.xmin; }

            static bool Ball_Compare(const BoundingBox & a , const BoundingBox &b) { return a.ymin > b.ymin; }

            void spin() { ros::spin(); }
        private:
            int Mode = 1;
            ros::Subscriber message_sub;
    };
} // namespace Image_vision

#endif // MY_DECTION