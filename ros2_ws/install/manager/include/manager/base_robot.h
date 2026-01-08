// /*
// Abstract base robot class
// Purely C++

// ok so you start a robot type, it sets nav mode + target pose as needed
// then every control tick you call update() to check its flags and if they have changed, you call the relevant callbacks to the ROS side

// common:
// - goToGoal
// - dock
// - startCharging
// - logUpdate

// inspection:
// - explore
// - detectDefects

// delivery:
// [nothing new]
// */

// // #ifndef ROBOT_MANAGER__BASE_ROBOT_H_
// // #define ROBOT_MANAGER__BASE_ROBOT_H_

// // #include <string>
// // #include <optional>
// // #include <iostream>
// // #include <vector>
// // #include "geometry_msgs/msg/pose.hpp"

// // struct NavModes {
// //   static constexpr const char * GOTO     = "goto";
// //   static constexpr const char * EXPLORE  = "explore";
// //   static constexpr const char * STOPPED  = "stopped";
// // };

// // class BaseRobot {
// // public:
// //   virtual ~BaseRobot() = default;

// //   // --- Common actions ---
// //   virtual void goToGoal(const geometry_msgs::msg::Pose &goal);
// //   virtual void dock(const geometry_msgs::msg::Pose &dock_pose);
// //   virtual void startCharging();
// //   virtual void logUpdate(const std::string &task_type, const geometry_msgs::msg::Pose &pose, bool complete);

// //   // --- Accessors / mutators ---
// //   void setNavMode(const std::string &nav_mode);
// //   void setTargetPose(const geometry_msgs::msg::Pose &pose);
// //   std::string getNavMode() const;
// //   geometry_msgs::msg::Pose getTargetPose() const;

// //   std::string getRobotType() const;
// //   bool isBusy() const { return busy_; }

// //   // --- Lifecycle hooks ---
// //   virtual void startRobot() = 0;
// //   virtual void stopRobot() = 0;
// //   virtual void update();  // called periodically
// //   virtual void reset();

// //   // --- Utility ---
// //   virtual bool requiresPose() const { return false; }

// // protected:
// //   bool busy_{false};
// //   // bool peripherals_enabled_{false};
// //   bool is_docking_{false};
// //   std::string robot_type_{"base"};
// //   std::string nav_mode_{NavModes::STOPPED};
// //   std::optional<geometry_msgs::msg::Pose> target_pose_;

// //   virtual void enablePeripherals() = 0;
// // };

// // #endif


// #ifndef ROBOT_MANAGER__BASE_ROBOT_H_
// #define ROBOT_MANAGER__BASE_ROBOT_H_

// #include <optional>
// #include <string>
// #include <iostream>
// #include "geometry_msgs/msg/pose.hpp"

// struct NavModes {
//   static constexpr const char * GOTO    = "goto";
//   static constexpr const char * EXPLORE = "explore";
//   static constexpr const char * STOPPED    = "stopped";
// };

// class BaseRobot {
// public:
//   virtual ~BaseRobot() = default;

//   // Set
//   virtual void setNavMode(const std::string &nav_mode);        // request nav behaviour
//   virtual void setTargetPose(const geometry_msgs::msg::Pose &target_pose); // request move
//   void dock(const geometry_msgs::msg::Pose &initial_pose);                          // request docking

//   // virtual void assignMission(const std::string &nav_mode,
//   //                          const std::optional<geometry_msgs::msg::Pose> &pose);

//   // Get
//   std::string getRobotType() const;
//   std::string getNavMode() const;
//   geometry_msgs::msg::Pose getTargetPose() const;

//   // State
//   bool isBusy() const;
//   bool peripheralsEnabled() const;
//   virtual bool requiresPose() const { return false; }

//   // Lifecycle
//   virtual void startRobot() = 0;
//   virtual void stopRobot() = 0;

//   // Called every control tick (non-ROS update)
//   virtual void update();
//   virtual void reset();

//   // dependency injection: callbacks provided by Manager
//   // using NavRequester = std::function<void(const std::string&, const geometry_msgs::msg::PoseStamped&)>;
//   // using ChargingRequester = std::function<void(const std::string&)>;
//   // using LogPublisher = std::function<void(const std::string&, const geometry_msgs::msg::PoseStamped&, bool)>;

//   // void setNavRequester(NavRequester cb) { nav_requester_ = std::move(cb); }
//   // void setChargingRequester(ChargingRequester cb) { charging_requester_ = std::move(cb); }
//   // void setLogPublisher(LogPublisher cb) { log_publisher_ = std::move(cb); }


// protected:
//   bool busy_ = false;
//   bool peripherals_enabled_ = false;
//   bool is_docking_ = false;
//   std::string robot_type_;
//   std::string nav_mode_;
//   std::optional<geometry_msgs::msg::Pose> target_pose_;

//   // Hook for subclasses to implement custom peripherals
//   virtual void enablePeripherals() = 0;
// };

// #endif