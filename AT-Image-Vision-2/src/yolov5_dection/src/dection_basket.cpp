///
///***by yami
///***6.8 2024
/// find basket

#include "yolov5_dection/dection_basket.h"

namespace Image_vision {
    void My_dection::init_ROS_Sub(bool DEBUG_) {
        if (DEBUG_) {
            setlocale(LC_ALL , " " );
            //* 这个init 应该放在主函数里
            //ros::init(argc , argv , "message");
            ros::NodeHandle sh;
            ros::Subscriber message_sub = sh.subscribe("/yolov5/BoundingBoxes" , 10 , &My_dection::message_callback, this);
            ros::Subscriber test_location = sh.subscribe("Key_mode", 1, &My_dection::Key_location, this);
        } else {
            setlocale(LC_ALL , " " );
            ros::NodeHandle sh;
            ros::Subscriber message_sub = sh.subscribe("/yolov5/BoundingBoxes" , 10 , &My_dection::message_callback, this);
            ros::Subscriber location = sh.subscribe("X_Y_ARG", 1, &My_dection::TD_location, this);
        }
    }
    void My_dection::TD_location(const X_Y_ARG & msg) {
            if (msg.x == 1) {
                Red = 1;
                Blue = 2;
                ROS_INFO("My are red!!");
            }
            else if (msg.x == 2) {
                Red = 2;
                Blue = 1;
                ROS_INFO("My are blue!!");
            }
            else {
                ROS_INFO("Have a problen");
            }
            if (msg.mode == 1) {
                if (Re_Set == 1) {
                    Send_num = 0;
                    My_map.clear();
                    My_set.clear();
                }
                ROS_INFO("1 puls ");
                Re_Set = 0;
                Mode = msg.mode;
            }
            if (msg.mode == 2) {
                if (Re_Set == 0) {
                    int Temp{};
                    for (int num : My_set) {
                        if (My_map[num] >= Temp) {
                            Temp = My_map[num];
                            Send_num = num;
                        }
                    }
                    Re_Set = 1;
                }
                ROS_INFO("2 puls");
                if (Send_num / 10 != 0) {
                    ROS_INFO("%d", Send_num);
                    Mode = msg.mode;
                    Bask_ID.id = Send_num / 10;
                    message_pub.publish(Bask_ID);
                }
                else {
                    ROS_INFO("%d", Send_num);
                    Mode = msg.mode;
                    Bask_ID.id = Send_num / 10;
                    Bask_ID.distance = 30;
                    message_pub.publish(Bask_ID);
                }
            }
    }
    void My_dection::Key_location(const Int32 & msg) {
        if (msg.data == 1) {
            if (Re_Set == 1) {
                Send_num = 0;
                My_map.clear();
                My_set.clear();
            }
            Re_Set = 0;
            Mode = msg.data;
            ROS_INFO("1");
        }
        if (msg.data == 2) {
            if (Re_Set == 0) {
                int Temp{};
                for (int num : My_set) {
                    if (My_map[num] >= Temp) {
                        Temp = My_map[num];
                        Send_num = num;
                    }
                }
                Re_Set = 1;
            }
            if (Send_num / 10 != 0) {
                ROS_INFO("2");
                ROS_INFO("%d", Send_num);
                Mode = msg.data;
                Bask_ID.id = Send_num / 10;
                message_pub.publish(Bask_ID);
            }
            else {
                ROS_INFO("2");
                ROS_INFO("%d", Send_num);
                Mode = msg.data;
                Bask_ID.id = Send_num / 10;
                Bask_ID.distance = 30;
                message_pub.publish(Bask_ID);
            }

        }
    }
    void My_dection::message_callback(const BoundingBoxes & msg) {

        int Temp_basket = 0;
        std::vector< BoundingBox > ball;
        std::vector< BoundingBox > basket;
        int Sum_ball{};
        int Ha_num{};
        int Temp[3]{};
        arr_rank pub_arr_rank;

        if (!msg.bounding_boxes.empty()) {
            int16_t num_thing = msg.bounding_boxes[msg.bounding_boxes.size() - 1].num; 
            for (int i = 0; i < num_thing; ++i)
                if (msg.bounding_boxes[i].Class == "basket") Temp_basket++;
                
            if (Temp_basket == 5 && Mode == 1) {
                for (int i = 0; i < num_thing; ++i) 
                    if (msg.bounding_boxes[i].Class == "basket") basket.push_back(msg.bounding_boxes[i]);
                std::sort(basket.begin(), basket.end(), My_dection::Bas_Compare);

                std::array<int, 5> sorted = {0, 1, 2, 3, 4};
                std::sort(sorted.begin(), sorted.end(), [&](int a, int b) {
                    return abs((basket[a].xmin + basket[a].xmax) / 2 - 320 ) < abs((basket[b].xmin + basket[b].xmax) / 2 - 320);});

                for (int q = 0; q < 5; ++q) 
                    pub_arr_rank.rank[q] = sorted[q] + 1;

                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < num_thing; ++j) {
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
                        else pub_arr_rank.arrs[i].arr[m + 1] = 1;
                    }
                    Sum_ball = 0;
                    ball.clear();
                }
                static ros::NodeHandle nh;
                static ros::Publisher pub_Arr_Rank = nh.advertise< port_serial >("My_arr_rank", 5);
                static arr_rank pub_arr_rank;
                // 每处理好一张都会发出去
                pub_Arr_Rank.publish(pub_arr_rank);
            }
        basket.clear();
        }
    }
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