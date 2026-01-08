#ifndef MANAGER__MANAGER_LIFECYCLE_NODE_H_
#define MANAGER__MANAGER_LIFECYCLE_NODE_H_

#include <memory>
#include <string>
#include <optional>
#include <chrono>
#include <functional>

// ROS2 lifecycle + core
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "lifecycle_msgs/msg/state.hpp"

// Messages
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int32.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

// Shared interfaces (custom)
#include "shared_interfaces/msg/check_log.hpp"
#include "shared_interfaces/srv/navigation_mode.hpp"
#include "shared_interfaces/srv/charging.hpp"
#include "shared_interfaces/srv/detecting.hpp"
#include "shared_interfaces/srv/robot_type.hpp"

// Constants for navigation modes
struct NavModes {
  static constexpr const char * GOTO    = "goto";
  static constexpr const char * EXPLORE = "explore";
  static constexpr const char * STOPPED = "stopped";
};

class ManagerLifecycleNode : public rclcpp_lifecycle::LifecycleNode
{
public:
  using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

  ManagerLifecycleNode();

protected:
  // Lifecycle state transitions
  CallbackReturn on_configure(const rclcpp_lifecycle::State & state) override;
  CallbackReturn on_activate(const rclcpp_lifecycle::State & state) override;
  CallbackReturn on_deactivate(const rclcpp_lifecycle::State & state) override;
  CallbackReturn on_cleanup(const rclcpp_lifecycle::State & state) override;

private:
  // ===== Parameters & setup =====
  void setParams();
  void createCommunications();

  // ===== Core mission logic =====
  void robotTypeCallback(
    const std::shared_ptr<shared_interfaces::srv::RobotType::Request> req,
    std::shared_ptr<shared_interfaces::srv::RobotType::Response> res);

  void navRequestAsync(
    const std::string & mode,
    const geometry_msgs::msg::PoseStamped & target,
    std::function<void(bool)> done);

  bool controlCharge(const std::string & command);
  bool controlDetect(const std::string & command);

  void publishLog(const std::string & task_type,
                  int8_t current_index,
                  const geometry_msgs::msg::PoseStamped & pose,
                  bool complete);

  void batteryCallback(const std_msgs::msg::Int32::SharedPtr msg);
  bool poseProvided(const geometry_msgs::msg::PoseStamped & pose);

  void storeRequest(const std::string &robot_type, int8_t index, const geometry_msgs::msg::PoseStamped &pose);

  // ===== Internal state tracking =====
  enum class State {
    IDLE,
    RUNNING,
    CHARGING
  };

  // Lifecycle state fields
  std::string current_mode_;
  std::string nav_mode_;
  State current_state_{State::IDLE};
  std::string current_type_;
  int8_t current_index_{0};

  geometry_msgs::msg::PoseStamped initial_pose_;
  geometry_msgs::msg::PoseStamped target_pose_;

  bool charging_override_{false};
  std::atomic<bool> busy_{false};
  int battery_low_threshold_{20};
  int battery_resume_threshold_{99};
  int queue_size_{10};


  // Saved/stored mission requests
  std::shared_ptr<shared_interfaces::srv::RobotType::Request> stored_request_{nullptr};

  // ===== ROS communications =====
  // Publishers
  rclcpp_lifecycle::LifecyclePublisher<shared_interfaces::msg::CheckLog>::SharedPtr update_log_pub_;
  rclcpp_lifecycle::LifecyclePublisher<std_msgs::msg::String>::SharedPtr current_type_pub_;

  // Subscriptions
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr battery_sub_;

  // Service servers
  rclcpp::Service<shared_interfaces::srv::RobotType>::SharedPtr robot_type_srv_;

  // Service clients
  rclcpp::Client<shared_interfaces::srv::Detecting>::SharedPtr detecting_client_;
  rclcpp::Client<shared_interfaces::srv::Charging>::SharedPtr charging_client_;
  rclcpp::Client<shared_interfaces::srv::NavigationMode>::SharedPtr nav_client_;

  // Callback groups
  rclcpp::CallbackGroup::SharedPtr cg_clients_;
  rclcpp::CallbackGroup::SharedPtr cg_timers_;

  // ===== Timers & durations =====
  std::chrono::milliseconds control_timer_period_{std::chrono::milliseconds(200)};
  std::chrono::seconds nav_response_timeout_{std::chrono::seconds(60)};
  std::chrono::seconds explore_timeout_{std::chrono::seconds(120)};
  std::chrono::seconds dock_timeout_{std::chrono::seconds(60)};
  std::chrono::seconds detect_stop_timeout_{std::chrono::seconds(30)};

  rclcpp::TimerBase::SharedPtr control_timer_;
};

#endif  // MANAGER__MANAGER_LIFECYCLE_NODE_H_


// /*
//  Description:
//   Lifecycle orchestrator that owns a BaseRobot (Inspection/Delivery/Mapping/Docking).
//   - Service: /robot_instance (string) to switch robot subclass
         
//   - Services: start mapping (trigger) + get map (nav_msgs/srv/GetMap)
//   - Action: MotionTask (motion_mode:string, pose:geometry_msgs/PoseStamped when needed)
//   - Subscriptions: /defect_found (std_msgs/Bool), /angle (std_msgs/Float32)
//   - Logger: service to record events (defects, deliveries_incomplete, deliveries_complete)
//   - On any request for "docking_robot", it overrides current mode, reconfigures, and runs DockingRobot.


// TO DECIDE:
// - sticker method or hardcode coordinates?
// - feedback from proj1


// I NEED TO:
// - polymorphism!
// - put more logic into BaseRobot subclasses
// */


// #ifndef MANAGER_LIFECYCLE_NODE_H_
// #define MANAGER_LIFECYCLE_NODE_H_

// struct State {
//   static constexpr const char * EXECUTING    = "executing";
//   static constexpr const char * DOCKING = "docking";
//   static constexpr const char * CHARGING = "charging";
//   static constexpr const char * IDLE    = "idle";
// };

// struct NavModes {
//   static constexpr const char * GOTO     = "goto";
//   static constexpr const char * EXPLORE  = "explore";
//   static constexpr const char * STOPPED  = "stopped";
// };

// #include <memory>
// #include <string>
// #include <optional>
// #include <chrono>
// #include <future>

// #include "rclcpp/rclcpp.hpp"
// #include "rclcpp_lifecycle/lifecycle_node.hpp"
// #include "rclcpp_lifecycle/lifecycle_publisher.hpp"

// #include "lifecycle_msgs/msg/state.hpp"
// #include "std_msgs/msg/string.hpp"
// #include "std_msgs/msg/int32.hpp"
// #include "geometry_msgs/msg/pose_stamped.hpp"

// #include "shared_interfaces/msg/check_log.hpp"
// #include "shared_interfaces/srv/detecting.hpp"
// #include "shared_interfaces/srv/charging.hpp"
// #include "shared_interfaces/srv/navigation_mode.hpp"
// #include "shared_interfaces/srv/robot_type.hpp"

// // #include "manager/base_robot.h"
// // #include "manager/delivery_robot.h"
// // #include "manager/inspection_robot.h"

// using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;
// using nav_future_response = rclcpp::Client<shared_interfaces::srv::NavigationMode>::SharedFuture;

// class ManagerLifecycleNode : public rclcpp_lifecycle::LifecycleNode
// {
// public:
//   ManagerLifecycleNode();

//   using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

//   CallbackReturn on_configure(const rclcpp_lifecycle::State &) override;
//   CallbackReturn on_activate(const rclcpp_lifecycle::State &) override;
//   CallbackReturn on_deactivate(const rclcpp_lifecycle::State &) override;
//   CallbackReturn on_cleanup(const rclcpp_lifecycle::State &) override;

// private:
//   // comms
//   // in ManagerLifecycleNode (header)
//   rclcpp::CallbackGroup::SharedPtr cg_clients_;
//   rclcpp::CallbackGroup::SharedPtr cg_timers_;

//   rclcpp_lifecycle::LifecyclePublisher<std_msgs::msg::String>::SharedPtr current_type_pub_;
//   rclcpp_lifecycle::LifecyclePublisher<shared_interfaces::msg::CheckLog>::SharedPtr update_log_pub_;

//   rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr battery_sub_;

//   rclcpp::Client<shared_interfaces::srv::Detecting>::SharedPtr detecting_client_;
//   rclcpp::Client<shared_interfaces::srv::Charging>::SharedPtr charging_client_;
//   rclcpp::Client<shared_interfaces::srv::NavigationMode>::SharedPtr nav_client_;

//   rclcpp::Service<shared_interfaces::srv::RobotType>::SharedPtr robot_type_srv_;

//   // params / state
//   int queue_size_ = 10;
//   int battery_low_threshold_ = 20;
//   int battery_resume_threshold_ = 99;
//   int8_t current_index = 0;

//   geometry_msgs::msg::PoseStamped initial_pose_;

//   std::chrono::milliseconds control_timer_period_{std::chrono::milliseconds(200)};
//   std::chrono::seconds nav_response_timeout_{std::chrono::seconds(60)};   // generic nav response wait
//   std::chrono::seconds explore_timeout_{std::chrono::seconds(120)};       // exploration completion wait
//   std::chrono::seconds dock_timeout_{std::chrono::seconds(60)};           // docking wait
//   std::chrono::seconds detect_stop_timeout_{std::chrono::seconds(30)};    // stop_detecting wait

//   bool charging_override_ = false;
//   bool detecting_active_ = false;
//   // std::string saved_mission_mode_;
//   // geometry_msgs::msg::PoseStamped saved_target_pose_;
//   const std::shared_ptr<shared_interfaces::srv::RobotType::Request> stored_request_ = nullptr;
//   bool was_mission_active_ = false;

//   enum class State { IDLE, RUNNING, CHARGING };
//   State current_state_ = State::IDLE;

//   // robot (non-ROS polymorphic)
//   // std::unique_ptr<BaseRobot> robot_;
//   bool busy_ = false;
//   bool peripherals_enabled_ = false;
//   bool is_docking_ = false;

//   std::string current_mode_;
//   std::string robot_type_;
//   std::string nav_mode_;
//   std::optional<geometry_msgs::msg::PoseStamped> target_pose_;

//   // internal flags for nav results
//   bool nav_result_ready_ = false;
//   bool nav_succeeded_ = false;

//   // helpers / timers
//   rclcpp::TimerBase::SharedPtr control_timer_;



//   // methods
//   void setParams();
//   void createCommunications();

//   // service callbacks
// //   void requestCallback(
// //     const std::shared_ptr<manager::srv::SetMode::Request> req,
// //     std::shared_ptr<manager::srv::SetMode::Response> res);

//   void robotTypeCallback(
//     const std::shared_ptr<shared_interfaces::srv::RobotType::Request> req,
//     std::shared_ptr<shared_interfaces::srv::RobotType::Response> res);

//   // comm helpers
//   void navRequestAsync(const std::string &mode,
//                        const geometry_msgs::msg::PoseStamped &target,
//                        std::function<void(bool)> done = nullptr);

//   void onNavSuccess(const geometry_msgs::msg::PoseStamped& target_pose);

//   bool controlCharge(const std::string &command);

//   bool controlDetect(const std::string &command);

//   void publishLog(const std::string & task_type,
//                   int8_t index,
//                   const geometry_msgs::msg::PoseStamped & pose,
//                   bool complete);

//   // callbacks
//   void batteryCallback(const std_msgs::msg::Int32::SharedPtr msg);

//   // robot control
//   void switchRobot(const std::string & new_type, const std::optional<geometry_msgs::msg::PoseStamped> & pose = std::nullopt);

//   // utilities
//   bool poseProvided(const geometry_msgs::msg::PoseStamped & p);
// };


// #endif  // MANAGER_LIFECYCLE_NODE_H_



// // class ManagerLifecycleNode : public rclcpp_lifecycle::LifecycleNode {
// // public:
// //     // using MissionTask = robot_manager::action::MissionTask;
// //     // using GoalHandleMissionTask = rclcpp_action::ClientGoalHandle<MissionTask>;

// //     // explicit ManagerLifecycleNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
// //     explicit ManagerLifecycleNode();

// // protected:
// //     // Lifecycle transitions
// //     CallbackReturn on_configure(const rclcpp_lifecycle::State &) override;
// //     CallbackReturn on_activate(const rclcpp_lifecycle::State &) override;
// //     CallbackReturn on_deactivate(const rclcpp_lifecycle::State &) override;
// //     CallbackReturn on_cleanup(const rclcpp_lifecycle::State &) override;
// //     CallbackReturn on_shutdown(const rclcpp_lifecycle::State &) override;

// // private:

// //     // ======= High-level robot instance management ===========================================
// //     // Switch robot instance (inspection, delivery, mapping, docking). Safe stop + rebind + (re)start.
// //     void switchRobot(const std::string & instance);          // overrides to docking_robot immediately if requested
// //     void instantiateRobotFor(const std::string & instance);          // create subclass and bind callbacks (navigate/log/map/inspect)
// //     void startCurrentRobot();                                        // call robot_->startMode()
// //     void stopCurrentRobot();                                         // call robot_->stopMode()

// //     // ======= ROS-facing bindings for robot callbacks ========================================
// //     // These are bound into the pure-C++ robot via std::function in on_configure().
// //     void cbNavigate_sendGoal(const std::string & motion_mode,
// //                             const geometry_msgs::msg::PoseStamped & pose_opt);
// //     void cbLog_send(const std::string & category,
// //                     const std::string & id,
// //                     const std::string & text);
// //     void cbMap_request();                                    // trigger mapping
// //     void cbInspect_report(const std::string & type,
// //                             double confidence,
// //                             double angle_deg);
// //     // callback and helper
// //     void batteryCallback(const std_msgs::msg::Int32::SharedPtr msg);
// //     void resumePreviousMission();
// //     // ======= Service / Topic / Action handlers ==============================================
// //     // /robot_instance service (RobotNode -> manager): request to change instance by string
// //     void handleSetRobotInstance(const std::shared_ptr<manager::srv::SetMode::Request>  request,
// //                                 std::shared_ptr<manager::srv::SetMode::Response>       response);


// //     // ======= Members =========================================================================
// //     // Current robot + instance label
// //     std::unique_ptr<BaseRobot> robot_;
// //     std::atomic<State> current_state_ = State::IDLE;
// //     std::atomic<bool> type_active_{false};                       // true when robot is active (started) + thread-safe
// //     std::atomic<bool> peripherals_active_{false};
// //     std::atomic<bool> nav_mode_sent_{false};
// //     std::optional<std::string> pending_robot_type_;         // requested robot type during active operation (can be empty)
// //     std::optional<geometry_msgs::msg::Pose> pending_pose_;  // requested target pose during active operation (can be empty)
// //     geometry_msgs::msg::Pose initial_pose_;

// //      // battery / charging control
// //     bool charging_override_ = false;
// //     int battery_low_threshold_ = 20;
// //     int battery_resume_threshold_ = 99;

// //     // saved mission so we can resume after charging
// //     std::string saved_mission_mode_;
// //     geometry_msgs::msg::Pose saved_target_pose_;
// //     bool was_mission_active_ = false;
    
// //     // ======= ROS Interfaces ==================================================================
// //     // ---- Lifecycle Publishers ----
// //     rclcpp_lifecycle::LifecyclePublisher<shared_interfaces::msg::TaskLog>::SharedPtr task_log_pub_;
// //     rclcpp_lifecycle::LifecyclePublisher<std_msgs::msg::string>::SharedPtr current_type_pub_;

// //     // ---- Subscriptions ----
// //     rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr                  battery_sub_;  // /battery_level

// //     // ---- Services (server) ----
// //     rclcpp::Service<shared_interfaces::srv::SetMode>::SharedPtr            set_robot_type_srv_;   // /robot_mode

// //     // ---- Services (clients) ----
// //     // MapNode: start mapping then get map
// //     rclcpp::Client<shared_interfaces::srv::NavigationMode>::SharedPtr      set_nav_mode_srv_;      // /navigation_mode
// //     rclcpp::Client<shared_interfaces::srv::DefectControl>::SharedPtr       detecting_client_;

// //     // ======= Utilities =========================================================================
// //     // Send a MotionTask goal (mode-only or pose+mode)
// //     bool sendMotionGoal(const std::string & motion_mode,
// //                         const geometry_msgs::msg::PoseStamped * pose_opt = nullptr);

// //     // Synchronous logger helper (wraps logger_cli_)
// //     bool logEvent(const std::string & category,
// //                     const std::string & id,
// //                     const std::string & text);

// //     // Map request helper (Trigger start, then GetMap)
// //     bool requestMap(nav_msgs::msg::OccupancyGrid & out_map);
// // };

// // #endif  // MANAGER_LIFECYCLE_NODE_H_
