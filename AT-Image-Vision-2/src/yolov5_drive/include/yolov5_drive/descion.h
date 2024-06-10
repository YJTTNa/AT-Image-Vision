//*
//**** yami 
//*    6.7 18.40 2024
#ifndef __My_Descion__
#define __My_Descion__

#include "vector"
#include "map"
#include "string"
#include "ros/ros.h"
#include "yolov5_ros_msgs/BoundingBox.h"
#include "yolov5_ros_msgs/BoundingBoxes.h"
#include "yolov5_ros_msgs/arr.h"
#include "yolov5_ros_msgs/arr_rank.h"
// 这里可以封装一些结构体 类的初始化 枚举类之类的
// 调用者不需要直到这个函数的方法是干什么的就可以
namespace Image_vision {
    
    using BoundingBox = yolov5_ros_msgs::BoundingBox;
    using BoundingBoxes = yolov5_ros_msgs::BoundingBoxes;
    using arr = yolov5_ros_msgs::arr;
    using arr_rank = yolov5_ros_msgs::arr_rank;

    class Descion_Machine;

    //* 状态的转换 
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
                {State::FALSE, "NOW_FALSE"},
                {State::WINNER, "NOW_IS_OUR_WINNER"},
                {State::ATTACK, "NOW_ATTACK"},
                {State::DEFEND, "NOW_DEFEND"},
                {State::GAME, "NOW_GAME"}
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
            void Lost_or_Win(const int arr[5][4]);
            // 初始
            void init_ROS_Sub();
            // mark评分
            /**
             * @brief Give this Situation a Mark
             * @param arr_rank arr_rank
             * @return int Mark this Situation
             */
            int Mark(const arr_rank Mark_Arr_Rank);        
            int Basket_Attack(const int arr[5][4], const int rank[]);
            int Basket_Defend(const int arr[5][4], const int rank[]);
            /**
             * @brief how_to_change_state
             * @param pchMessage basket_ball now_state
             * @return void
             */
            // 累计上一次的数据次数
            // 判断当前框里球的数量
            // 定义变量来累加 上述决策
            void Docile_Anger();
            void message(const arr_rank & msg);
        //* 一般都是变量私有化
        private:
            typedef struct {
                int one[5] =   {1, 2, 3, 4, 5};
                int two[5] =   {2, 3, 1, 4, 5};
                int three[5] = {3, 2, 4, 1, 5};
                int four[5] =  {4, 3, 5, 2, 1};
                int five[5] =  {5, 4, 3, 2, 1};
            } My_Rank;

            TrackerStateMachine trackerStateMachine;
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

            // 上一个使用消息
           arr_rank Last_Arr_And_Rank;
           int Last_Mark;
    };
}


#endif //My_DESCION_H