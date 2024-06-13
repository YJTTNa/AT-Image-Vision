///
///***by yami
///***6.8 2024
/// find basket

#include "yolov5_dection/dection_basket.h"

namespace Image_vision {
    // 这里初始化节点  是通过这样来实现的  ros::init(argc , argv , "message");
    void My_dection::init_ROS_Sub() {
            setlocale(LC_ALL , " " );
            ros::NodeHandle sh;
            ros::Subscriber message_sub = sh.subscribe("/yolov5/BoundingBoxes" , 10 , &My_dection::message_callback, this);
            ros::spin();
    }

    void My_dection::message_callback(const BoundingBoxes & msg) {
        
        int Temp_basket {};
        int Sum_ball {};
        std::vector< BoundingBox > ball;
        std::vector< BoundingBox > basket;
        
        arr_rank pub_arr_rank;

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

                for (int q = 0; q < 5; ++q) pub_arr_rank.rank[q] = sorted[q] + 1;

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
                    pub_arr_rank.arrs[i].arr[0] = Sum_ball;
                    for (int m = 0; m < Sum_ball; ++m) {
                        if (ball[m].Class == "red") pub_arr_rank.arrs[i].arr[m + 1] = 1;
                        else pub_arr_rank.arrs[i].arr[m + 1] = 2;
                    }
                    Sum_ball = 0;
                    ball.clear();
                }
                static ros::NodeHandle nh;
                static ros::Publisher pub_Arr_Rank = nh.advertise< arr_rank >("My_arr_rank", 2);
                // 每处理好一张都会发出去
                pub_Arr_Rank.publish(pub_arr_rank);
            }
        basket.clear();
        }
    }
}

int main(int argc, char *argv[]) {
    ros::init(argc , argv , "message");
    Image_vision::My_dection My_Eye;
    My_Eye.init_ROS_Sub();
    return 0;
}
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