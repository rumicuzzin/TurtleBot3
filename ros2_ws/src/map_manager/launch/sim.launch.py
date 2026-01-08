from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
import os

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution

from launch_ros.actions import Node

def generate_launch_description():
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')

    slam_nav2_params = os.path.join(
        get_package_share_directory('map_manager'),
        'config',
        'nav2_params.yaml'
    )

    maps_dir = os.path.join(
        get_package_share_directory('map_manager'),
        'maps'
    )

    # --- SLAM Toolbox (ASYNC) ---
    # Using online_async_launch.py for better performance
    slam_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('slam_toolbox'),
                         'launch', 'online_async_launch.py')
        ),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'slam_params_file': slam_nav2_params
        }.items()
    )

    # --- Nav2 bringup using live SLAM map (no map_server / amcl) ---
    nav2_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('nav2_bringup'),
                         'launch', 'navigation_launch.py')
        ),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'params_file': slam_nav2_params
        }.items()
    )

    # start localization stack (map_server + amcl), but don't autostart
    # Provide a default map to overwrite later.
    default_map = os.path.join(get_package_share_directory('map_manager'),
                             'maps', 'default.yaml')

    localization_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('nav2_bringup'),
                         'launch', 'localization_launch.py')
        ),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'autostart': 'false',
            'map': default_map,
            'params_file': slam_nav2_params
        }.items()
    )

    # ▶ Map manager node
    map_manager_node = Node(
        package='map_manager',
        executable='map_manager_node',
        name='map_manager',
        output='screen',
        parameters=[{
            'slam_node': 'slam_toolbox',
            'map_server_node': 'map_server',
            'amcl_node': 'amcl',
            "map_save_dir": maps_dir,           # shared map directory
            "map_prefix": "warehouse",          # filenames to be written like warehouse_YYYYMMDD-HHMMSS
        }]
    )

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        slam_launch,
        nav2_launch,
        localization_launch,
        map_manager_node,
    ])

