"""
MTRX3760 2025 Project 2: Warehouse Robot DevKit
File: defect_detection.launch.py
Author(s): Will Rumi
Launch file for defect detection node
"""
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    """
    Launch the defect detection node with configurable parameters
    Usage:
        ros2 launch defect_detector defect_detection.launch.py
        # With custom parameters:
        ros2 launch defect_detector defect_detection.launch.py camera_topic:=/turtlebot/camera/image
    """
    
    # Declare launch arguments
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',  # ADDED - default to true for simulation
        description='Use simulation time from Gazebo'
    )
    
    camera_topic_arg = DeclareLaunchArgument(
        'camera_topic',
        default_value='/camera/image_raw',
        description='Camera image topic name'
    )
    
    detection_rate_arg = DeclareLaunchArgument(
        'detection_rate',
        default_value='2.0',
        description='Detection frequency in Hz'
    )
    
    blue_threshold_arg = DeclareLaunchArgument(
        'blue_threshold',
        default_value='1000',
        description='Minimum blue pixel count to trigger detection'
    )
    
    map_frame_arg = DeclareLaunchArgument(
        'map_frame',
        default_value='odom',
        description='Global reference frame'
    )
    
    base_frame_arg = DeclareLaunchArgument(
        'base_frame',
        default_value='base_footprint',
        description='Robot base frame'
    )
    
    log_file_arg = DeclareLaunchArgument(
        'log_file_path',
        default_value='/tmp/warehouse_defects.yaml',
        description='Path to save defect log file'
    )
    
    # Create the defect detection node
    defect_detection_node = Node(
        package='defect_detector',  
        executable='defect_detection_node',
        name='defect_detection_node',
        output='screen',
        emulate_tty=True,
        parameters=[{
            'use_sim_time': LaunchConfiguration('use_sim_time'),  # ADDED
            'camera_topic': LaunchConfiguration('camera_topic'),
            'detection_rate': LaunchConfiguration('detection_rate'),
            'blue_threshold': LaunchConfiguration('blue_threshold'),
            'map_frame': LaunchConfiguration('map_frame'),
            'base_frame': LaunchConfiguration('base_frame'),
            'log_file_path': LaunchConfiguration('log_file_path'),
        }],
        # Useful for debugging
        arguments=['--ros-args', '--log-level', 'info']
    )
    
    return LaunchDescription([
        # Launch arguments
        use_sim_time_arg,  # ADDED
        camera_topic_arg,
        detection_rate_arg,
        blue_threshold_arg,
        map_frame_arg,
        base_frame_arg,
        log_file_arg,
        
        # Nodes
        defect_detection_node,
    ])