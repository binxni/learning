#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>

#include "global_to_polar_cpp/msg/polar_grid.hpp"

struct Waypoint {
    double x, y;
};

class GlobalToPolarNode : public rclcpp::Node
{
public:
    GlobalToPolarNode() : Node("global_to_polar_node")
    {
        std::string path_csv_file = this->declare_parameter<std::string>("path_csv_file", "path.csv");
        lookahead_points_ = this->declare_parameter<int>("lookahead_points", 20);
        search_window_ = this->declare_parameter<int>("search_window", 10);

        if (!loadPathFromCSV(path_csv_file)) {
            RCLCPP_ERROR(this->get_logger(), "Failed to load path from CSV. Shutting down.");
            rclcpp::shutdown();
            return;
        }

        odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "pf/pose/odom", 10,
            std::bind(&GlobalToPolarNode::odomCallback, this, std::placeholders::_1));
        scan_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "scan", 10,
            std::bind(&GlobalToPolarNode::scanCallback, this, std::placeholders::_1));

        polar_grid_pub_ = this->create_publisher<global_to_polar_cpp::msg::PolarGrid>("polar_grid", 10);

        current_x_ = 0.0;
        current_y_ = 0.0;
        current_yaw_ = 0.0;
        last_closest_idx_ = 0;
        odom_received_ = false;

        RCLCPP_INFO(this->get_logger(), "Global to Polar Node initialized successfully.");
    }

private:
    bool loadPathFromCSV(const std::string &file_path)
    {
        std::ifstream file(file_path);
        if (!file.is_open()) {
            RCLCPP_ERROR(this->get_logger(), "Cannot open CSV file: %s", file_path.c_str());
            return false;
        }

        global_path_.clear();
        std::string line;
        if (!std::getline(file, line)) {
            RCLCPP_ERROR(this->get_logger(), "CSV file is empty.");
            return false;
        }

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string x_str, y_str;
            if (std::getline(ss, x_str, ',') && std::getline(ss, y_str, ',')) {
                try {
                    Waypoint wp{std::stod(x_str), std::stod(y_str)};
                    global_path_.push_back(wp);
                } catch (const std::invalid_argument &) {
                    RCLCPP_WARN(this->get_logger(), "Skipping malformed line in CSV: %s", line.c_str());
                }
            }
        }
        file.close();

        if (global_path_.empty()) {
            RCLCPP_ERROR(this->get_logger(), "No valid waypoints loaded from CSV file.");
            return false;
        }
        RCLCPP_INFO(this->get_logger(), "Loaded %zu waypoints from %s", global_path_.size(), file_path.c_str());
        return true;
    }

    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        current_x_ = msg->pose.pose.position.x;
        current_y_ = msg->pose.pose.position.y;
        tf2::Quaternion q(
            msg->pose.pose.orientation.x,
            msg->pose.pose.orientation.y,
            msg->pose.pose.orientation.z,
            msg->pose.pose.orientation.w);
        tf2::Matrix3x3 m(q);
        double roll, pitch;
        m.getRPY(roll, pitch, current_yaw_);
        odom_received_ = true;
    }

    void scanCallback(const sensor_msgs::msg::LaserScan::SharedPtr scan)
    {
        if (!odom_received_ || global_path_.empty()) {
            return;
        }
        processPathToPolarGrid(*scan);
    }

    void processPathToPolarGrid(const sensor_msgs::msg::LaserScan &scan)
    {
        const size_t path_size = global_path_.size();

        double min_dist = std::numeric_limits<double>::max();
        size_t closest_waypoint_idx = last_closest_idx_;
        for (int j = 0; j < search_window_; ++j) {
            size_t current_idx = (last_closest_idx_ + j) % path_size;
            double dx = global_path_[current_idx].x - current_x_;
            double dy = global_path_[current_idx].y - current_y_;
            double dist = std::sqrt(dx * dx + dy * dy);
            if (dist < min_dist) {
                min_dist = dist;
                closest_waypoint_idx = current_idx;
            }
        }
        last_closest_idx_ = closest_waypoint_idx;

        auto polar_grid_msg = global_to_polar_cpp::msg::PolarGrid();
        polar_grid_msg.header.frame_id = "base_link";
        polar_grid_msg.header.stamp = scan.header.stamp;
        const double angle_min = scan.angle_min;
        const double angle_increment = scan.angle_increment;
        const size_t num_ranges = scan.ranges.size();
        polar_grid_msg.ranges.assign(num_ranges, 0.0f);

        for (int j = 0; j < lookahead_points_; ++j) {
            size_t idx = (closest_waypoint_idx + j) % path_size;
            const auto &wp = global_path_[idx];
            double dx = wp.x - current_x_;
            double dy = wp.y - current_y_;
            double distance = std::sqrt(dx * dx + dy * dy);
            double global_angle = std::atan2(dy, dx);
            double relative_angle = global_angle - current_yaw_;
            while (relative_angle > M_PI) relative_angle -= 2.0 * M_PI;
            while (relative_angle < -M_PI) relative_angle += 2.0 * M_PI;
            int index = static_cast<int>(std::round((relative_angle - angle_min) / angle_increment));
            if (index >= 0 && static_cast<size_t>(index) < num_ranges) {
                if (polar_grid_msg.ranges[index] == 0.0f ||
                    distance < polar_grid_msg.ranges[index]) {
                    polar_grid_msg.ranges[index] = static_cast<float>(distance);
                }
            }
        }
        polar_grid_pub_->publish(polar_grid_msg);
    }

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_sub_;
    rclcpp::Publisher<global_to_polar_cpp::msg::PolarGrid>::SharedPtr polar_grid_pub_;

    std::vector<Waypoint> global_path_;
    double current_x_ {0.0};
    double current_y_ {0.0};
    double current_yaw_ {0.0};
    size_t last_closest_idx_ {0};
    bool odom_received_ {false};

    int lookahead_points_ {20};
    int search_window_ {10};
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GlobalToPolarNode>());
    rclcpp::shutdown();
    return 0;
}
