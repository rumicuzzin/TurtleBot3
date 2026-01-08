
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    mode_arg = DeclareLaunchArgument(
        'mode',
        default_value='docking_robot',
        description='Initial robot mode: delivery_robot, inspection_robot, mapping_robot, or docking_robot'
    )

    robot_node = Node(
        package='robot',
        executable='robot_node',
        name='robot_node',
        output='screen',
        parameters=[{
            'mode': LaunchConfiguration('mode')
        }]
    )

    return LaunchDescription([
        mode_arg,
        robot_node
    ])
