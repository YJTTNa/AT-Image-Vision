//*
//**** yami 
//*    6.7 18.40 2024

//// 建立在红色方来处理 我方为红色
//// 后通过改换颜色的参数 以实现换方


//// 可以发三要备选******

// 一定要等到甩标志位可以给数
#include "yolov5_drive/descion.h"

namespace Image_vision {
    void TrackerStateMachine::update() {
        
    }
    void Descion_Machine::init_ROS_Sub(bool DEBUG_) {
        if (DEBUG_) {
            ros::NodeHandle ph;
            ros::Subscriber test_location = ph.subscribe("Key_mode", 1, &Descion_Machine::Key_location, this);
            ros::Subscriber Arr_Rank_sub = ph.subscribe("My_arr_rank", 1, &Descion_Machine::message, this);
            ros::MultiThreadedSpinner spinner(2);
            spinner.spin();
        }
        else {
            ros::NodeHandle ph;
            ros::Subscriber location = ph.subscribe("X_Y_ARG", 1, &Descion_Machine::TD_location, this);
            ros::Subscriber Arr_Rank_sub = ph.subscribe("My_arr_rank", 1, &Descion_Machine::message, this);
            ros::MultiThreadedSpinner spinner(2);
            spinner.spin();
        }
    }

    void Descion_Machine::TD_location(const X_Y_ARG & msg) {
        static ros::NodeHandle nh;
        static ros::Publisher message_pub = nh.advertise< port_serial >("basket_id", 10);
        static port_serial Bask_ID;
        // 红蓝方错位问题从这里解决
        if (msg.x == 1) {
            red = 1;
            blue = 2;
            ROS_INFO("My are red!!");
        }
        else if (msg.x == 2) {
            red = 2;
            blue = 1;
            ROS_INFO("My are blue!!");
        }
        else {
            ROS_INFO("Have a problen");
        }
        // 整体的逻辑还是 mode=1 为识别模式 mode=2 为发送模式 
        if (msg.mode == 1) {

            if (Re_Set == 1) {
                Send_num = 0;
            }
            ROS_INFO("1 puls ");
            Re_Set = 0;
            Mode = msg.mode;
        }
        if (msg.mode == 2) {
            if (Re_Set == 0) {
                Re_Set = 1;
            }
            ROS_INFO("2 puls");
            if (Deq.size() == 0) Send_num = rand() % 5;
            else Send_num = Deq.Find_Multifrequency();
            if (Send_num == 0) {
                // 这里是博弈代码
                // 进入轮询发送检测模式
                // 这里就体现了进入数据里就存的作用
                ROS_INFO("%d", Send_num);
            }
            else {
                ROS_INFO("%d", Send_num);
                Bask_ID.id = Send_num;
                message_pub.publish(Bask_ID);
            }
        }
    }
    
    void Descion_Machine::Key_location(const Int32 & msg) {
        static ros::NodeHandle nh;
        static ros::Publisher message_pub = nh.advertise< port_serial >("basket_id", 10);
        static port_serial Bask_ID;
        if (msg.data == 1) {
            if (Re_Set == 1) {
                // 这里考虑给不给零
                Send_num = 0;
            }
            Re_Set = 0;
            Mode = msg.data;
            ROS_INFO("now mode 1");
        }
        if (msg.data == 2) {
            if (Re_Set == 0) {
                Re_Set = 1;
            }
            Mode = msg.data;
            ROS_INFO("now mode 2");
            Send_num = Deq.Find_Multifrequency();
            //Send_num = Deq.Find_Multifrequency();
            if (Send_num == 0) {
                // 这里是博弈代码
                ROS_INFO("%d", Send_num);
            }
            else {
                ROS_INFO("%d", Send_num);
                Bask_ID.id = Send_num;
                message_pub.publish(Bask_ID);
            }
        }
        if (msg.data == 3) { 
            red = 1;
            blue = 2;
            ROS_INFO("%d", blue);
            ROS_INFO("My are red!!");
        }
        if (msg.data == 4) {
            red = 2;
            blue = 1;
            ROS_INFO("%d", blue);
            ROS_INFO("My are blue!!");
        }
    }
    // 考虑 瞎放的学校的处理办法

    void Descion_Machine::message(const arr_rank & msg) {
        // 存储当前的排序
        // 这个可能会用到
        // 后面
        Last_Arr_And_Rank.arrs = msg.arrs;
        Last_Arr_And_Rank.rank = msg.rank;
        if (Mode == 1) this->Lost_or_Win(msg);
    }
    // 空框是+0
    // 如果是一个球 +2 -2
    // 如果是两个球 
    // 如果是三个球的情况 
    int Descion_Machine::Mark(const arr_rank Mark_Arr_Rank) {
        int Mark = 0;
        for (int i = 0; i <= 4; ++i) {
            if (Mark_Arr_Rank.arrs[i].arr[0] == 0) Mark = Mark;
            else if (Mark_Arr_Rank.arrs[i].arr[0] == 1) Mark = Mark_Arr_Rank.arrs[i].arr[1]==red?Mark+2:Mark-2; 
            else if (Mark_Arr_Rank.arrs[i].arr[0] == 2) {
                if (Mark_Arr_Rank.arrs[i].arr[1] != Mark_Arr_Rank.arrs[i].arr[2]) Mark = Mark_Arr_Rank.arrs[i].arr[1]==red?Mark+3:Mark+4;
                else Mark = Mark_Arr_Rank.arrs[i].arr[2]==red?Mark+3:Mark-3;
            }
            else if (Mark_Arr_Rank.arrs[i].arr[0] == 3) {
                // 关键
                //*A: 优势类 --
                // 1. 红蓝红
                // 8. 红红红
                // 6. 蓝红红
                if (Mark_Arr_Rank.arrs[i].arr[3] == red) {
                    if (Mark_Arr_Rank.arrs[i].arr[1] != Mark_Arr_Rank.arrs[i].arr[2])
                        Mark = Mark_Arr_Rank.arrs[i].arr[1] == red ? Mark+5 : Mark+7;
                    Mark = Mark_Arr_Rank.arrs[i].arr[1] == red ? Mark+3 : Mark-4;
                }
                else {
                    if (Mark_Arr_Rank.arrs[i].arr[1] != Mark_Arr_Rank.arrs[i].arr[2]) 
                        Mark = Mark_Arr_Rank.arrs[i].arr[1] == red ? Mark+1 : Mark+5;
                    Mark = Mark_Arr_Rank.arrs[i].arr[1] == red ? Mark+4 : Mark-3;
                }
            }
                //*B: 劣势类 --
                // 4. 红蓝蓝 (有机会)
                // 5. 蓝红蓝 (对面慢但是运气好)
                // 7. 蓝蓝蓝
                //*C: 中类   --
                // 2. 红红蓝
                // 3. 蓝蓝红
        }
        // 这里的mark是累计了5个框的数值
        return Mark;
        // 用完Last_Mark 记得更新
    }

    void Descion_Machine::Lost_or_Win(const arr_rank arr) {
        int Lost = 0;
        int Win = 0;
        int Redd = 0;
        int Bluee = 0;
        for (int i = 0; i <= 4; ++i) {
            if (arr.arrs[i].arr[0] == 3) {
                for (int j = 1; j <= 3; ++j) {
                    if (arr.arrs[i].arr[j] == red) Redd++;
                    else Bluee++;
                }
                if (Bluee > Redd) Lost++;
                else Win++;
                Redd = 0; Bluee = 0;
            }
        }
        // 简单累计 防止误判
        // 防止少识别了以为不是大胜状态
        if (Win >= 3) {
            ROS_INFO("before state %s", trackerStateMachine.My_string_state().c_str());
            if (trackerStateMachine.Get_State() != TrackerStateMachine::State::WINNER && Lost_Winner_Num >= 3) {
                trackerStateMachine.Set_WINNER();
                Lost_Winner_Num++;
                ROS_INFO("now state %s", trackerStateMachine.My_string_state().c_str());
            }
            else Lost_Winner_Num++;
        }
        else if (Lost >= 3) {
            ROS_INFO("before state %s", trackerStateMachine.My_string_state().c_str());
            if (trackerStateMachine.Get_State() != TrackerStateMachine::State::FALSE && Lost_Winner_Num >= 3) {
                trackerStateMachine.Set_FALSE();
                Lost_Winner_Num++;
                ROS_INFO("now state %s", trackerStateMachine.My_string_state().c_str());
            }
            else Lost_Winner_Num++;
        }
        else {
            // 防止少识别以为不是大胜
            if (Lost_Winner_Num > 10) Lost_Winner_Num -= 5;
            else if (Lost_Winner_Num >= 5) {
                Lost_Winner_Num = 2;
                this->Docile_Anger(arr);
            }
            else if (Lost_Winner_Num < 5) {
                Lost_Winner_Num = 0;
                this->Docile_Anger(arr);
            }
        }
    }

    void Descion_Machine::Docile_Anger(const arr_rank arr_rank_Mark) {
        // 调用评估函数 先跑简单的流程
        int Temp_rank_Mark = Mark(arr_rank_Mark);
        // 调用评估函数之后
        if (Temp_rank_Mark > Mark_Treshold) {
            // 接上变量并入队列
            // 在要入队列之前需要先打印状态
            ROS_INFO("before state %s", trackerStateMachine.My_string_state().c_str());
            if (trackerStateMachine.Get_State() != TrackerStateMachine::State::ATTACK) {
                trackerStateMachine.Set_Attack();
                ROS_INFO("now state %s", trackerStateMachine.My_string_state().c_str());
            }
            Deq.push_back(Basket_Attack(arr_rank_Mark));
        }
        else {
            ROS_INFO("before state %s", trackerStateMachine.My_string_state().c_str());
            if (trackerStateMachine.Get_State() != TrackerStateMachine::State::DEFEND) {
                trackerStateMachine.Set_Defend();
                ROS_INFO("now state %s", trackerStateMachine.My_string_state().c_str());
            }
            Deq.push_back(Basket_Defend(arr_rank_Mark));
        }
    }
    //* Defend 防止对面大胜 
    int Descion_Machine::Basket_Defend(const arr_rank arr_and_rank) {
        for (int i = 0; i <= 4; ++i) {
            if (arr_and_rank.arrs[i].arr[0] == 2 && arr_and_rank.arrs[i].arr[2] == blue) return i + 1;
        }
        // 这里是两个球的情况
        for (int i = 0; i <= 4; ++i) {
            if (arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[0] == 2) return arr_and_rank.rank[i];
        }
        // 这里是空框的情况
        for (int i = 0; i <= 4; ++i) {
            if (arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[0] == 0) return arr_and_rank.rank[i];
        }
        // 这里补充的情况
        for (int i = 0; i <= 4; ++i) {
            if (arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[0] == 1 && arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[1] == red) return arr_and_rank.rank[i];
        }
        return 0;
    }
    //* Attack 进攻方为主(追求大胜) 速度 放到一定的球数
    int Descion_Machine::Basket_Attack(const arr_rank arr_and_rank) {
        // 2个且不相同
        for (int i = 0; i <= 4; ++i) {
            if (arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[0] == 2 && (arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[2] != arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[1])) 
                return arr_and_rank.rank[i];
        }
        // 2个优先我方
        for (int i = 0; i <= 4; ++i) {
            if (arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[0] == 2 && arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[2] == red) 
                return arr_and_rank.rank[i];
        }
        // 其次是他们的
        for (int i = 0; i <= 4; ++i) {
            if (arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[0] == 2 && arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[2] == blue) 
                return arr_and_rank.rank[i];
        }
        for (int i = 0; i <= 4; ++i) {
            if (arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[0] == 1 && arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[1] == red) return arr_and_rank.rank[i];
        }
        for (int i = 0; i <= 4; ++i) {
            if (arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[0] == 0) return arr_and_rank.rank[i];
        }
        for (int i = 0; i <= 4; ++i) {
            if (arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[0] == 1 && arr_and_rank.arrs[arr_and_rank.rank[i] - 1].arr[1] == blue) return arr_and_rank.rank[i];
        }
        // 总上说明进攻状态下不会进入博弈
        return 0;
    }

    // 这个属于新写的容器  
    int Fixed_Deque::Find_Multifrequency() const {
        int Temp {};
        int ssend_num {};
        if (data.size() != 5) {
            ssend_num = data.at(data.size() - 1);
        } else {
            for (const auto & Ha_num : data) {
                if (My_set.find(Ha_num) == My_set.end()) {
                    My_set.insert(Ha_num);
                    My_map.emplace(Ha_num, 1);
                }
                else if (My_set.find(Ha_num) != My_set.end()) {
                    My_map[Ha_num]++;
                }
            }
            // 这里可能略有问题后期需要调整
            for (const auto & num : My_set) {
                if (My_map[num] >= Temp) {
                    Temp = My_map[num];
                    ssend_num = num;
                }
            }
        }
        My_map.clear();
        My_set.clear();
        return ssend_num;
    }
} // namespace 

int main(int argc, char * argv[]) {
    ros::init(argc, argv, "descion");
    Image_vision::Descion_Machine desicion_machine;
    desicion_machine.init_ROS_Sub(1);
    return 0;
}