from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    params_global = {
        'path_csv_file': 'path.csv',
        'lookahead_points': 20,
        'search_window': 10,
    }

    params_logger = {
        'output_csv_file': 'datalog.csv',
        'normalize': False,
        'horizon_sec': 1.6,
        'dt': 0.1,
        'forward_only': False,
        'downsample_step': 1,
    }

    return LaunchDescription([
        Node(
            package='global_to_polar_cpp',
            executable='global_to_polar_node',
            name='global_to_polar_node',
            remappings=[
                ('pf/pose/odom', '/pf/pose/odom'),
                ('scan', '/scan'),
                ('polar_grid', '/polar_grid'),
            ],
            parameters=[params_global],
        ),
        Node(
            package='global_to_polar_cpp',
            executable='data_logger_node',
            name='data_logger_node',
            remappings=[
                ('scan', '/scan'),
                ('polar_grid', '/polar_grid'),
                ('planned_path_with_velocity', '/planned_path_with_velocity'),
            ],
            parameters=[params_logger],
        ),
    ])
