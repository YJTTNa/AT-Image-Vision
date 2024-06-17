///
///***by yami
///***6.8 2024
/// find basket

#include "yolov5_dection/dection_basket.h"

namespace Image_vision {
    // 这里初始化节点  是通过这样来实现的  ros::init(argc , argv , "message");
    // void My_dection::init_ROS_Sub(ros::NodeHandle sh) {
    //         //setlocale(LC_ALL , " " ); ///yolov5/BoundingBoxes
    //         message_sub = sh.subscribe("/yolov5/BoundingBoxes" , 10 , &My_dection::message_callback, this);
    //         ROS_INFO("aaaaaaa");
    // }

    void My_dection::message_callback(const BoundingBoxes& msg) {

        int Temp_basket {};
        int Sum_ball {};
        std::vector< BoundingBox > ball;
        std::vector< BoundingBox > basket;
        
        arr_rank pub_arr_rank;
        arr pub_arr;
        if (!msg.bounding_boxes.empty()) {
            int16_t num_thing = msg.bounding_boxes[msg.bounding_boxes.size() - 1].num; 
            for (int i = 0; i < num_thing; ++i)
                if (msg.bounding_boxes[i].Class == "basket") Temp_basket++;
                // 这里需要考虑与那个节点的交互性问题
            if (Temp_basket == 5 && Mode == 1) {
                for (int i = 0; i < num_thing; ++i) 
                    if (msg.bounding_boxes[i].Class == "basket") basket.push_back(msg.bounding_boxes[i]);
                std::sort(basket.begin(), basket.end(), My_dection::Bas_Compare);
                std::array<int, 5> sorted = {0, 1, 2, 3, 4};
                std::sort(sorted.begin(), sorted.end(), [&](int a, int b) {
                    return abs((basket[a].xmin + basket[a].xmax) / 2 - 320 ) < abs((basket[b].xmin + basket[b].xmax) / 2 - 320);});

                for (int q = 0; q < 5; ++q) pub_arr_rank.rank.emplace_back(sorted[q] + 1);
                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < num_thing; ++j) {
                        // 这里来调整符合框里的球的数量
                        if (msg.bounding_boxes[j].Class != "basket" && 
                            (msg.bounding_boxes[j].xmin + msg.bounding_boxes[j].xmax) / 2 > basket[i].xmin - 5 &&
                            (msg.bounding_boxes[j].xmin + msg.bounding_boxes[j].xmax) / 2 < basket[i].xmax + 5 && 
                            (msg.bounding_boxes[j].ymin + msg.bounding_boxes[j].ymax) / 2 > basket[i].ymin - 30 &&
                            (msg.bounding_boxes[j].ymin + msg.bounding_boxes[j].ymax) / 2 < basket[i].ymax + 5) {
                                ball.push_back(msg.bounding_boxes[j]);
                                Sum_ball++;
                        }
                    }
                    std::sort(ball.begin(), ball.end(), My_dection::Ball_Compare);
                    pub_arr.arr.push_back(Sum_ball);
                    for (int m = 1; m <= Sum_ball; ++m) {
                        if (ball[m - 1].Class == "red") pub_arr.arr.push_back(1);
                        else if (ball[m - 1].Class == "blue") pub_arr.arr.push_back(2); //pub_arr_rank.arrs[i].arr[m + 1] = 2; 
                    }
                    if (Sum_ball < 3)
                        for (int i = Sum_ball; i <= 3; ++i) pub_arr.arr.push_back(0); 
                    pub_arr_rank.arrs.push_back(pub_arr);
                    pub_arr.arr.clear();
                    Sum_ball = 0;
                    ball.clear();
                }
                
                static ros::NodeHandle nh;
                static ros::Publisher pub_Arr_Rank = nh.advertise< arr_rank >("My_arr_rank", 10);
                // 每处理好一张都会发出去
                // for (int i = 0; i < 4; ++i) ROS_INFO("%d", pub_arr_rank.arrs[4].arr[i]);
                // ROS_INFO("7877");
                pub_Arr_Rank.publish(pub_arr_rank);
            }
        basket.clear();
        }
    }
}

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "dection_basket");
    ROS_INFO("Initializing dection_basket node");
    ros::NodeHandle nh;
    Image_vision::My_dection my_dection(nh);
    ros::spin(); 
    ROS_INFO("Exiting dection_basket node");
    return 0;
}
/*
#include <ros/ros.h>  
#include "your_package/BoundingBoxes.h"  
#include <vector>  
  
class MyDetectionNode {  
public:  
    MyDetectionNode() {  
        // 初始化节点句柄  
        ros::NodeHandle nh("~");  
  
        // 创建一个订阅者，订阅/yolov5/BoundingBoxes话题  
        // 使用10作为队列大小，并绑定到本类的message_callback回调函数  
        message_sub = nh.subscribe("/yolov5/BoundingBoxes", 10, &MyDetectionNode::message_callback, this);  
  
        // 其他初始化代码...  
    }  
  
    // 回调函数来处理接收到的BoundingBoxes消息  
    void message_callback(const your_package::BoundingBoxesConstPtr& msg) {  
        // 在这里处理接收到的消息  
        // 例如，遍历边界框并执行一些操作  
        for (int i = 0; i < msg->bounding_boxes.size(); ++i) {  
            // 假设bounding_boxes是一个包含边界框信息的数组  
            // 这里只是简单地打印边界框的中心坐标  
            double x_center = (msg->bounding_boxes[i].xmin + msg->bounding_boxes[i].xmax) / 2.0;  
            double y_center = (msg->bounding_boxes[i].ymin + msg->bounding_boxes[i].ymax) / 2.0;  
            ROS_INFO("Detected bounding box center at (%f, %f)", x_center, y_center);  
  
            // ... 其他处理逻辑  
        }  
    }  
  
    // ROS节点句柄和订阅者  
    ros::NodeHandle nh_;  
    ros::Subscriber message_sub;  
  
    // 可以在这里添加其他成员变量和函数  
};  
  
int main(int argc, char **argv) {  
    // 初始化ROS节点  
    ros::init(argc, argv, "my_detection_node");  
  
    // 创建MyDetectionNode对象  
    MyDetectionNode my_detection_node;  
  
    // 进入ROS事件循环  
    ros::spin();  
  
    return 0;  
}
*/
    // Ha_num = into_box(arr, rank);
    // for (int e = 1; e < 4; ++e) {
    //     if (arr[Ha_num - 1][e] == 0) {
    //         arr[Ha_num - 1][0]++;
    //         arr[Ha_num - 1][e] = Blue;    
    //         break;
    //     }
    // }

    // Ha_num *= 10;
    // switch (Ha_num) {
    //     case 10 :
    //         Ha_num = Ha_num + into_box(arr, rank1);
    //         break;
    //     case 20 :
    //         Ha_num = Ha_num + into_box(arr, rank2);
    //         break;
    //     case 30 :
    //         Ha_num = Ha_num + into_box(arr, rank3);
    //         break;
    //     case 40 :
    //         Ha_num = Ha_num + into_box(arr, rank4);
    //         break;
    //     case 50 :
    //         Ha_num = Ha_num + into_box(arr, rank5);
    //         break;
    //     default:
    //     // 博弈期间
    //         break;
    // }
    // if (My_set.find(Ha_num) == My_set.end()) {
    //     My_set.insert(Ha_num);
    //     My_map.emplace(Ha_num, 1);
    // }
    // else if (My_set.find(Ha_num) != My_set.end()) {
    //     My_map[Ha_num]++;
    // }