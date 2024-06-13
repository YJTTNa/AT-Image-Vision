//*
//**** yami 
//*    6.7 18.40 2024
#ifndef __My_Descion__
#define __My_Descion__

#include "vector"
#include "map"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "deque"
#include "ros/ros.h"
#include "yolov5_ros_msgs/BoundingBox.h"
#include "yolov5_ros_msgs/BoundingBoxes.h"
#include "yolov5_ros_msgs/arr.h"
#include "yolov5_ros_msgs/arr_rank.h"
#include "yolov5_ros_msgs/X_Y_ARG.h"
#include "yolov5_ros_msgs/port_serial.h"
#include "std_msgs/Int32.h"
// 这里可以封装一些结构体 类的初始化 枚举类之类的
// 调用者不需要直到这个函数的方法是干什么的就可以
namespace Image_vision {
    
    using BoundingBox = yolov5_ros_msgs::BoundingBox;
    using BoundingBoxes = yolov5_ros_msgs::BoundingBoxes;
    using arr = yolov5_ros_msgs::arr;
    using arr_rank = yolov5_ros_msgs::arr_rank;
    using X_Y_ARG = yolov5_ros_msgs::X_Y_ARG;
    using Int32 = std_msgs::Int32;
    using port_serial = yolov5_ros_msgs::port_serial;
    
    class Descion_Machine;
    //* 状态的转换 
    std::unordered_set<int> My_set;
    std::unordered_map<int, int> My_map;  
    class Fixed_Deque {   
        public:
            // 初始化方法( Fixed_Deque deque( 5 ) )
            Fixed_Deque(int size) : maxSize(size) {}
            // 重写push_back() 函数  
            void push_back(int value) {  
                if (data.size() == maxSize) data.pop_front();  
                data.push_back(value);  
            }  
            // 设置接口获取当前的实时大小  
            int size() const { return data.size(); }
            // 轮询里面出现次数最多的数据
            int Find_Multifrequency() const;
        private:  
            std::deque<int> data;  
            int maxSize; 
          
    };  
    class TrackerStateMachine {
        public:
            // 默认是int类型
            enum class State{
                FALSE,
                WINNER,
                ATTACK,
                DEFEND,
                GAME
            };

            TrackerStateMachine() = default;

            [[nodiscard]] inline std::string My_string_state() const { return My_state.find(state)->second; }

            [[nodiscard]] inline State Get_State() const { return state; }

            inline void Set_Attack() { this->state = State::ATTACK; }
            inline void Set_Defend() { this->state = State::DEFEND; }
            inline void Set_Game() { this->state = State::GAME; }
            inline void Set_WINNER() { this->state = State::WINNER; }
            inline void Set_FALSE() { this->state = State::FALSE; }

            void Set_m_attack_threshold(int v) { m_attack_threshold = v; }
            void Set_m_defend_threshold(int v) { m_defend_threshold = v; }
            void Set_m_game_threshold(int v) { m_game_threshold = v; }

 
            // 状态更新函数的接口
            void update();
            // 失败状态 与 胜利状态 不需要 累计更新 建议累计次数

        private:
            // 没法动这个变量
            State state = State::DEFEND;

            int m_lost_counst = 0;
            int m_winner_counst = 0;
            int m_attack_threshold = 20;
            int m_defend_threshold = 20;
            int m_game_threshold = 20;

            std::map<State, std::string> My_state {
                { State::FALSE, "NOW_FALSE" },
                { State::WINNER, "NOW_IS_OUR_WINNER" },
                { State::ATTACK, "NOW_ATTACK" },
                { State::DEFEND, "NOW_DEFEND" },
                { State::GAME, "NOW_GAME" }
            };

    };

    //* 决策机 大类 大脑的主干 我只需要有TrackerStateMachine这样的一个类就可以
    class Descion_Machine {
        public:
            Descion_Machine() = default;
            ~Descion_Machine() {};

            void Set_Red_or_Blue(int Blue, int Red) { this->blue = Blue; this->red = Red; }

            /**
             * @brief result_our_win_or_lost
             * @param arr[][] basket_ball now_state
             * @return void
             */
            void Lost_or_Win(const arr_rank arr);
            // 初始
            // 1. DEBUG_ = 1   NODEBUG = 0
            void init_ROS_Sub(bool DEBUG_);
            // mark评分
            /**
             * @brief Give this Situation a Mark
             * @param arr_rank arr_rank
             * @return int Mark this Situation
             */
            void TD_location(const X_Y_ARG & msg);
            void Key_location(const Int32 & msg);
            int Mark(const arr_rank Mark_Arr_Rank);   
            int Basket_Attack(const arr_rank arr_and_rank);
            int Basket_Defend(const arr_rank arr_and_rank);
            /**
             * @brief how_to_change_state
             * @param pchMessage basket_ball now_state
             * @return void
             */
            // 累计上一次的数据次数
            // 判断当前框里球的数量
            // 定义变量来累加 上述决策
            void Docile_Anger(const arr_rank arr_rank_Mark);
            void message(const arr_rank & msg);

        //* 一般都是变量私有化
        private:
            // 这里用于备选框的距离使用
            typedef struct {
                int one[5] =   {1, 2, 3, 4, 5};
                int two[5] =   {2, 3, 1, 4, 5};
                int three[5] = {3, 2, 4, 1, 5};
                int four[5] =  {4, 3, 5, 2, 1};
                int five[5] =  {5, 4, 3, 2, 1};
            } My_Rank;
            TrackerStateMachine trackerStateMachine;
            // 定义接口队列
            Fixed_Deque Deq = Fixed_Deque(5);
            // 受控接口
            int blue = 0;
            int red = 0;
            // 防止误判大胜
            int Lost_Winner_Num = 0;
            // 阈值
            int Docile_Treshold = 0;
            int Anger_Treshold = 0;
            int Anger = 0;
            int Docile = 10;
            int Re_Set = -1;
            int Mode = -1;
            int Send_num = 0;
            // 上一个使用消息
            arr_rank Last_Arr_And_Rank;
            int Now_Mark;
            int Last_Mark;
            // 这里是Mark的阈值
            int Mark_Treshold = 10;
    };

// int main() {  
//     FixedSizeDeque fdq(5); // 创建一个最大容量为5的FixedSizeDeque  
//     for (int i = 0; i < 10; ++i) {  
//         fdq.push_back(i); // 尝试添加10个元素  
//         fdq.print();     // 打印当前队列的元素  
//     }  
//     return 0;  
// }
}



#endif //My_DESCION_H