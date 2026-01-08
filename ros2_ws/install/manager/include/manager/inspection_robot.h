// #ifndef ROBOT_MANAGER__INSPECTION_ROBOT_H_
// #define ROBOT_MANAGER__INSPECTION_ROBOT_H_

// // #include "geometry_msgs/msg/pose.hpp"

// #include "manager/base_robot.h"

// #include <vector>
// #include <iostream>

// // POLYMORPHIC PLAN
// // class InspectionRobot : public BaseRobot {
// // public:
// //   InspectionRobot() { robot_type_ = "inspection"; }

// //   // --- Core lifecycle ---
// //   void startRobot() override;
// //   void stopRobot() override;

// //   // --- Specialised behaviour ---
// //   void explore();

// // protected:
// //   void enablePeripherals() override;

// // };

// // #endif


// // SHIT PLAN
// //-------------------------------//
// //        Inspection Robot       //
// //-------------------------------//
// class InspectionRobot : public BaseRobot {
// public:
//   InspectionRobot();
//   void startRobot() override;
//   void stopRobot() override;
//   void update() override;

// protected:
//   void enablePeripherals() override;
// };

// // class InspectionRobot : public BaseRobot {
// // public:
// //     explicit InspectionRobot(CommandFn dispatch,
// //                            std::vector<geometry_msgs::msg::Pose> inspection_points)
// //     : BaseRobot(std::move(dispatch)), points_(std::move(inspection_points)) {}

// //     ~InspectionRobot() override;  // Saves defect log to JSON on destruction

// //     void assignMission() override;  // Main inspection behavior


// // private:
// //     // // Helper to simulate defect detection logic (to be implemented)
// //     // bool damageFound(const sensor_msgs::msg::Image &frame) const;

// //     // // Helper to simulate getting the current robot pose (to be implemented)
// //     // geometry_msgs::msg::Pose currentPose() const;

// //     // std::vector<TaskRecord> defects_;  // Recorded defects
// //     // int next_id_ = 0;                  // Incremental defect ID
// //     // size_t current_index_ = 0;         // Index of current inspection point
// //     std::vector<geometry_msgs::msg::Pose> points_;
// //     size_t idx_ = 0;
// //     bool pending_goal_ = false;
// // };

// #endif  // ROBOT_MANAGER__INSPECTION_ROBOT_H_
