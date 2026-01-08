#!/usr/bin/env python3
#
# Gazebo (Ignition) + custom maze world + TurtleBot3 + bridges + perception + drive
#
# Usage:
#   export TURTLEBOT3_MODEL=burger
#   ros2 launch turtlebot_maze_solver bringup_maze_launch.py
#
# Optional:
#   HEADLESS=true ros2 launch turtlebot_maze_solver bringup_maze_launch.py
#

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (
    AppendEnvironmentVariable,
    DeclareLaunchArgument,
    IncludeLaunchDescription,
    OpaqueFunction,  # <— added
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # Package locations
    tb3_gazebo_share = get_package_share_directory("turtlebot3_gazebo")
    ros_gz_sim_share = get_package_share_directory("ros_gz_sim")
    this_pkg_share   = get_package_share_directory("warehouse_bringup")

    # --- Arguments ---
    use_sim_time = LaunchConfiguration("use_sim_time", default="true")
    # changed defaults to "auto" so we can derive from world
    x_pose = LaunchConfiguration("x_pose", default="auto")   # <— changed
    y_pose = LaunchConfiguration("y_pose", default="auto")   # <— changed
    z_pose = LaunchConfiguration("z_pose", default="0.06")  # lift above ground
    world_file = LaunchConfiguration(
        "world",
        default=os.path.join(this_pkg_share, "worlds", "maze_2.world"),
    )
    # params file (defaults to params/default.yaml inside this package)
    params_file = LaunchConfiguration(
        "params_file",
        default=os.path.join(this_pkg_share, "params", "default.yaml"),
    )

    declare_use_sim_time = DeclareLaunchArgument("use_sim_time", default_value=use_sim_time)
    declare_x_pose = DeclareLaunchArgument("x_pose", default_value=x_pose)
    declare_y_pose = DeclareLaunchArgument("y_pose", default_value=y_pose)
    declare_z_pose = DeclareLaunchArgument("z_pose", default_value=z_pose)
    declare_world = DeclareLaunchArgument("world", default_value=world_file)
    declare_params_file = DeclareLaunchArgument("params_file", default_value=params_file)

    # --- Gazebo server (loads world) ---
    gzserver = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(ros_gz_sim_share, "launch", "gz_sim.launch.py")),
        launch_arguments={
            "gz_args": ["-r -s -v2 ", world_file],
            "on_exit_shutdown": "true",
        }.items(),
    )

    # --- Gazebo client (GUI), optional via HEADLESS env ---
    gzclient = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(ros_gz_sim_share, "launch", "gz_sim.launch.py")),
        launch_arguments={
            "gz_args": "-g -v2 ",
            "on_exit_shutdown": "true",
        }.items(),
    )

    # --- Robot state publisher (URDF to TF) ---
    robot_state_pub = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(tb3_gazebo_share, "launch", "robot_state_publisher.launch.py")
        ),
        launch_arguments={"use_sim_time": use_sim_time}.items(),
    )

    # --- Spawn TurtleBot3 SDF ---
    tb3_model = os.environ.get("TURTLEBOT3_MODEL", "burger_cam")
    model_folder = f"turtlebot3_{tb3_model}"
    sdf_path = os.path.join(tb3_gazebo_share, "models", model_folder, "model.sdf")

    # Replace the original spawn_tb3 Node with a tiny resolver that only affects spawn
    def spawn_with_world_pose(context):
        world_val = world_file.perform(context)
        x_cfg = x_pose.perform(context)
        y_cfg = y_pose.perform(context)
        z_cfg = z_pose.perform(context)

        pose_map = {
            "maze_2.world": (-0.87, -0.87),
            "maze_3.world": (-1.4, 0),
            "maze_4.world": (1,-4),
        }

        def _num(s, default):
            try:
                return float(s)
            except Exception:
                return default

        # Only auto-pick if user left "auto"
        if x_cfg == "auto" or y_cfg == "auto":
            x_val, y_val = pose_map.get(os.path.basename(world_val), (0.0, 0.0))
        else:
            x_val, y_val = _num(x_cfg, 0.0), _num(y_cfg, 0.0)

        return [
            Node(
                package="ros_gz_sim",
                executable="create",
                arguments=[
                    "-name", "turtlebot3",
                    "-file", sdf_path,
                    "-x", str(x_val),
                    "-y", str(y_val),
                    "-z", z_cfg,
                ],
                output="screen",
            )
        ]

    # --- Bridges ---
    bridge_params = os.path.join(tb3_gazebo_share, "params", f"{model_folder}_bridge.yaml")

    parameter_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=["--ros-args", "-p", f"config_file:={bridge_params}"],
        output="screen",
        parameters=[{"use_sim_time": use_sim_time}],
    )

    image_bridge = Node(
        package="ros_gz_image",
        executable="image_bridge",
        arguments=["/camera/image_raw"],
        output="screen",
        parameters=[{"use_sim_time": use_sim_time}],
    )

    # --- Drive node (Action server) ---
    drive_node = Node(
        package="warehouse_bringup",
        executable="drive_node",
        output="screen",
        arguments=[
            "--ros-args",
            "--log-level", "drive_node:=info"
        ],
        parameters=[
            params_file,                      # <-- YAML for node params
            {"use_sim_time": use_sim_time},   # launch override
        ]
    )

    # --- Resource paths for Gazebo ---
    set_tb3_models = AppendEnvironmentVariable(
        "GZ_SIM_RESOURCE_PATH", os.path.join(tb3_gazebo_share, "models")
    )
    set_this_worlds = AppendEnvironmentVariable(
        "GZ_SIM_RESOURCE_PATH", os.path.join(this_pkg_share, "worlds")
    )

    # --- LaunchDescription ---
    ld = LaunchDescription()

    # Declare args
    ld.add_action(declare_use_sim_time)
    ld.add_action(declare_x_pose)
    ld.add_action(declare_y_pose)
    ld.add_action(declare_z_pose)
    ld.add_action(declare_world)
    ld.add_action(declare_params_file)

    # Env paths
    ld.add_action(set_tb3_models)
    ld.add_action(set_this_worlds)

    # Start processes
    ld.add_action(gzserver)
    if os.environ.get("HEADLESS", "false").lower() not in ["true", "1"]:
        ld.add_action(gzclient)

    ld.add_action(robot_state_pub)

    # Only this line changes how the robot is spawned:
    ld.add_action(OpaqueFunction(function=spawn_with_world_pose))  # <— replaces original spawn_tb3

    ld.add_action(parameter_bridge)
    if image_bridge:
        ld.add_action(image_bridge)

    # Start our nodes
    # ld.add_action(drive_node)

    return ld
