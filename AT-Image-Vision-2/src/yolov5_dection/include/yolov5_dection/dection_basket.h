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
#include "Eigen/Core"
#include "Eigen/Dense"
#include "opencv2/opencv.hpp"
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

            inline void SetMode(const int mode) { Mode == mode; }
            
            void spin() { ros::spin(); }
        private:
            int Mode = 1;
            ros::Subscriber message_sub;
            // 记得运行矫正畸变的参数 文件yaml用来矫正畸变
            double Real_Size_baeket = 250.f;
            double Fx = 436.98248;
            double Fy = 403.1976;
            double Ux = 306.42987;
            double Uy = 265.51439;     
            /*
                image_width: 640
                image_height: 480
                camera_name: narrow_stereo
                camera_matrix:
                rows: 3
                cols: 3
                data: [436.98248,   0.     , 306.42987,
                        0.     , 403.1976 , 265.51439,
                        0.     ,   0.     ,   1.     ]
                distortion_model: plumb_bob
                distortion_coefficients:
                rows: 1
                cols: 5
                data: [-0.031216, 0.017851, -0.001129, 0.010687, 0.000000]
                rectification_matrix:
                rows: 3
                cols: 3
                data: [1., 0., 0.,
                        0., 1., 0.,
                        0., 0., 1.]
                projection_matrix:
                rows: 3
                cols: 4
                data: [433.51863,   0.     , 314.94963,   0.     ,
                        0.     , 404.37373, 264.76882,   0.     ,
                        0.     ,   0.     ,   1.     ,   0.     ]
            */
    };
} // namespace Image_vision

#endif // MY_DECTION