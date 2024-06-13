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
        public:
            My_dection() = default;
            ~My_dection() {}

            void init_ROS_Sub();

            void message_callback(const BoundingBoxes & msg);

            static bool Bas_Compare(const BoundingBox & a , const BoundingBox &b) { return a.xmin < b.xmin; }

            static bool Ball_Compare(const BoundingBox & a , const BoundingBox &b) { return a.ymin > b.ymin; }

        private:
            //* 用于累加
            std::unordered_set<int> My_set;
            std::unordered_map<int, int> My_map;
            int Re_Set = -1;
            int Mode = -1;
            int Send_num = 0;
    };
} // namespace Image_vision

#endif // MY_DECTION