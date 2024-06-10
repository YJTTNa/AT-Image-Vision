//*
//**** yami 
//*    6.7 18.40 2024

//// 建立在红色方来处理 我方为红色
//// 后通过改换颜色的参数 以实现换方


//// 可以发三要备选******


#include "yolov5_drive/descion.h"

namespace Image_vision {
    void TrackerStateMachine::update() {
        
    }
    void Descion_Machine::init_ROS_Sub() {
        setlocale(LC_ALL , " " );
        ros::NodeHandle ph;
        ros::Subscriber Arr_Rank_sub = ph.subscribe("My_arr_rank", 1, &Descion_Machine::message, this);
    }

    int Descion_Machine::Mark(const arr_rank Mark_Arr_Rank) {
        int Mark = 0;
        for (int i = 0; i <= 4; ++i) {
            if (Mark_Arr_Rank.arrs[i].arr[0] == 0) Mark = Mark;
            else if (Mark_Arr_Rank.arrs[i].arr[0] == 1) Mark = Mark_Arr_Rank.arrs[i].arr[1]==red?Mark+2:Mark-2; 
            else if (Mark_Arr_Rank.arrs[i].arr[0] == 2) {
                Mark = Mark_Arr_Rank.arrs[i].arr[1]==red?Mark+3:Mark-2;
                // 有且仅有对面非常慢 第一个球是对面 我们放第二个
                Mark = Mark_Arr_Rank.arrs[i].arr[2]==red?Mark+4:Mark+6;
            }
            else if (Mark_Arr_Rank.arrs[i].arr[0] == 3) {
                // 关键
                //*A: 优势类 --
                // 1. 红蓝红
                // 8. 红红红
                // 6. 蓝红红
                //*B: 劣势类 --
                // 4. 红蓝蓝 (有机会)
                // 3. 蓝蓝红
                // 5. 蓝红蓝 (对面慢但是运气好)
                // 7. 蓝蓝蓝 
                //*C: 中类   --
                // 2. 红红蓝
            }
        }

        // 用完Last_Mark 记得更新
    }
    //* Defend
    int Descion_Machine::Basket_Defend(const int arr[5][4], const int rank[]) {
        for (int i = 0; i <= 4; ++i) {
            if (arr[i][0] == 2 && arr[i][2] == blue) return i + 1;
        }
        // 这里是空框的情况
        for (int i = 0; i <= 4; ++i) {
            if (arr[rank[i] - 1][0] == 0) return rank[i];
        }
        // 这里是两个球的情况
        for (int i = 0; i <= 4; ++i) {
            if (arr[rank[i] - 1][0] == 2) return rank[i];
        }
        // 这里补充的情况
        for (int i = 0; i <= 4; ++i) {
            if (arr[rank[i] - 1][0] == 1 && arr[rank[i] - 1][1] == red) return rank[i];
        }
        return 0;
    }

    //* Attack 进攻方为主(追求大胜) 速度 放到一定的球数
    int Descion_Machine::Basket_Attack(const int arr[5][4], const int rank[]) {
        for (int i = 0; i <= 4; ++i) {
            if (arr[i][0] == 2 && arr[i][2] == blue) return i + 1;
        }
        for (int i = 0; i <= 4; ++i) {
            if (arr[rank[i] - 1][0] == 2 && arr[rank[i] - 1][2] == red) return rank[i];
        }
        for (int i = 0; i <= 4; ++i) {
            if (arr[rank[i] - 1][0] == 1 && arr[rank[i] - 1][1] == red) return rank[i];
        }
        //* 这里还需要增加
        return 0;
    }
    // 累计怒火值 或 贤者值 判断使用那个来进行决策
    void Descion_Machine::Docile_Anger() {
        // 调用评分函数
        // 更新当前状态
        // 并打印
        if (TrackerStateMachine::State::WINNER == trackerStateMachine.Get_State() || \
            TrackerStateMachine::State::FALSE == trackerStateMachine.Get_State()) {
                
        }
    }
    void Descion_Machine::message(const arr_rank & msg) {
        // 先存储先前的排序
        Last_Arr_And_Rank.arrs = msg.arrs;
        Last_Arr_And_Rank.rank = msg.rank;

    }
    // 可以在函数里面调用函数 是调用过程更加简单
    void Descion_Machine::Lost_or_Win(const int arr[5][4]) {
        int Lost = 0;
        int Win = 0;
        int Redd = 0;
        int Bluee = 0;
        for (int i = 0; i <= 4; ++i) {
            if (arr[i][0] == 3) {
                for (int j = 1; j <= 3; ++j) {
                    if (arr[i][j] == red) 
                        Redd++;
                    else 
                        Bluee++;
                }
                if (Bluee > Redd)
                    Lost++;
                else 
                    Win++;
                Redd = 0;
                Bluee = 0;
            }
        }
        if (Win == 3) {
            if (Lost_Winner_Num >= 5) {
                ROS_INFO("%s", trackerStateMachine.My_string_state().c_str());
                trackerStateMachine.Set_WINNER();
                ROS_INFO("%s", trackerStateMachine.My_string_state().c_str());
            }
            Lost_Winner_Num++;
        }
        else if (Lost == 3) {
            if (Lost_Winner_Num >= 5) {
                ROS_INFO("%s", trackerStateMachine.My_string_state().c_str());
                trackerStateMachine.Set_FALSE();
                ROS_INFO("%s", trackerStateMachine.My_string_state().c_str());
            }
            Lost_Winner_Num++;
        }
        else {
            // 调用别的函数
            if (Lost_Winner_Num > 0) Lost_Winner_Num = 0;
            this->Docile_Anger();
        }
    }
} // namespace 
