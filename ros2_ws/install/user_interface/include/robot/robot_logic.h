#ifndef ROBOT_LOGIC_H
#define ROBOT_LOGIC_H

#include <string>

class RobotLogic{
    public:
        RobotLogic();
        void updateBatteryLevel(int level);
        void updateUserMode(const std::string &requested_mode);
        void controllerFinished();
        std::string getCurrentMode() const;
        void step();

        void setCurrentMode(const std::string &mode);

    private:
        int battery_level_;
        std::string current_mode_;
        std::string pending_mode_;
        bool controller_busy_;

        void evaluateState();
};

#endif //ROBOT_LOGIC_H