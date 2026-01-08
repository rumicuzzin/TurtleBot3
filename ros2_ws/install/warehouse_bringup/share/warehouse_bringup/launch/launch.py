from launch import LaunchDescription
from launch_ros.actions import Node, LifecycleNode
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # ManagerLifecycleNode – lifecycle-managed
    manager_lifecycle_node = LifecycleNode(
        package='manager',
        executable='manager_lifecycle_node',
        name='manager_lifecycle_node',   # match code
        namespace='',                       # REQUIRED in Jazzy
        output='screen',
        emulate_tty=True,
        parameters=[
            'manager_params.yaml',   # or dict if preferred
        ],
    )

    # Battery node – normal ROS2 node
    battery_node = Node(
        package='battery',
        executable='battery_node',
        name='battery_node',
        namespace='',
        output='screen',
        emulate_tty=True,
    )

    # Battery node – normal ROS2 node
    user_interface = Node(
        package='user_interface',
        executable='user_interface',
        name='user_interface',
        namespace='',
        output='screen',
        emulate_tty=True,
    )

    # Logger node – normal ROS2 node
    logger_node = Node(
        package='logger_pkg',
        executable='logger_node',
        name='logger_node',
        namespace='',
        output='screen',
        emulate_tty=True,
    )

    # navigation_launch = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource(
    #         os.path.join(
    #             get_package_share_directory('navigation'),
    #             'launch',
    #             'navigation_launch.py')
    #     )
    # )

    return LaunchDescription([
        manager_lifecycle_node,
        battery_node,
        logger_node,
        user_interface,
        # navigation_launch
    ])
