#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <nav_msgs/msg/path.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

#include "global_to_polar_cpp/msg/polar_grid.hpp"

class DataLoggerNode : public rclcpp::Node
{
public:
    DataLoggerNode() : Node("data_logger_node"), tf_buffer_(this->get_clock()), tf_listener_(tf_buffer_)
    {
        output_csv_file_ = this->declare_parameter<std::string>("output_csv_file", "datalog.csv");
        normalize_       = this->declare_parameter<bool>("normalize", false);
        horizon_sec_     = this->declare_parameter<double>("horizon_sec", 1.6);
        dt_              = this->declare_parameter<double>("dt", 0.1);
        forward_only_    = this->declare_parameter<bool>("forward_only", false);
        downsample_step_ = this->declare_parameter<int>("downsample_step", 1);

        label_steps_ = static_cast<size_t>(std::round(horizon_sec_ / dt_));

        csv_file_.open(output_csv_file_, std::ios::out | std::ios::trunc);
        if (!csv_file_.is_open()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open output file: %s", output_csv_file_.c_str());
            rclcpp::shutdown();
            return;
        }

        laser_scan_sub_.subscribe(this, "scan");
        polar_grid_sub_.subscribe(this, "polar_grid");
        path_sub_.subscribe(this, "planned_path_with_velocity");

        sync_ = std::make_shared<Synchronizer>(SyncPolicy(10), laser_scan_sub_, polar_grid_sub_, path_sub_);
        sync_->registerCallback(std::bind(&DataLoggerNode::syncCallback, this,
                                          std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

        RCLCPP_INFO(this->get_logger(), "Data Logger Node initialized. Logging to %s", output_csv_file_.c_str());
    }

    ~DataLoggerNode()
    {
        if (csv_file_.is_open()) {
            csv_file_.close();
        }
    }

private:
    using LaserScan  = sensor_msgs::msg::LaserScan;
    using PolarGrid  = global_to_polar_cpp::msg::PolarGrid;
    using Path       = nav_msgs::msg::Path;
    using SyncPolicy = message_filters::sync_policies::ApproximateTime<LaserScan, PolarGrid, Path>;
    using Synchronizer = message_filters::Synchronizer<SyncPolicy>;

    void writeHeader()
    {
        csv_file_ << "stamp";
        for (size_t i = 0; i < range_count_; ++i) {
            csv_file_ << ",scan_" << i;
        }
        for (size_t i = 0; i < range_count_; ++i) {
            csv_file_ << ",grid_" << i;
        }
        for (size_t i = 0; i < label_steps_; ++i) {
            csv_file_ << ",label_x_" << i;
        }
        for (size_t i = 0; i < label_steps_; ++i) {
            csv_file_ << ",label_y_" << i;
        }
        csv_file_ << "\n";
        csv_file_.flush();
    }

    double sanitize(double value, double range_min, double range_max) const
    {
        if (!std::isfinite(value) || value < range_min) {
            return 0.0;
        }
        if (value > range_max) {
            return range_max;
        }
        return normalize_ ? value / range_max : value;
    }

    void syncCallback(const LaserScan::ConstSharedPtr &scan,
                      const PolarGrid::ConstSharedPtr &grid,
                      const Path::ConstSharedPtr &path)
    {
        if (downsample_step_ > 1 && (sample_count_++ % downsample_step_) != 0) {
            return;
        }

        if (scan->ranges.size() != grid->ranges.size()) {
            RCLCPP_WARN(this->get_logger(),
                        "Range size mismatch: scan %zu vs grid %zu. Sample skipped.",
                        scan->ranges.size(), grid->ranges.size());
            return;
        }

        if (!header_written_) {
            range_count_ = scan->ranges.size();
            angle_min_ = scan->angle_min;
            angle_max_ = scan->angle_max;
            angle_increment_ = scan->angle_increment;
            writeHeader();
            header_written_ = true;
        } else {
            if (std::fabs(scan->angle_min - angle_min_) > 1e-6 ||
                std::fabs(scan->angle_max - angle_max_) > 1e-6 ||
                std::fabs(scan->angle_increment - angle_increment_) > 1e-9 ||
                scan->ranges.size() != range_count_) {
                RCLCPP_WARN(this->get_logger(),
                            "LaserScan angle metadata changed. Sample skipped.");
                return;
            }
        }

        std::vector<double> times;
        std::vector<double> xs;
        std::vector<double> ys;
        try {
            if (path->poses.empty()) {
                RCLCPP_WARN(this->get_logger(), "Path empty. Sample skipped.");
                return;
            }
            auto tf = tf_buffer_.lookupTransform("base_link", path->header.frame_id,
                                                  scan->header.stamp, rclcpp::Duration::from_seconds(0.1));
            rclcpp::Time start_time = path->header.stamp;
            for (const auto &ps : path->poses) {
                geometry_msgs::msg::PointStamped in, out;
                in.header = ps.header;
                in.point  = ps.pose.position;
                tf2::doTransform(in, out, tf);
                double x = out.point.x;
                double y = out.point.y;
                double t = (rclcpp::Time(ps.header.stamp) - start_time).seconds();
                if (forward_only_ && x <= 0.0) {
                    continue;
                }
                xs.push_back(x);
                ys.push_back(y);
                times.push_back(t);
            }
        } catch (const tf2::TransformException &ex) {
            RCLCPP_WARN(this->get_logger(), "TF lookup failed: %s", ex.what());
            return;
        }

        if (times.empty()) {
            RCLCPP_WARN(this->get_logger(), "No valid path points after filtering. Sample skipped.");
            return;
        }

        std::vector<double> label_x(label_steps_, 0.0);
        std::vector<double> label_y(label_steps_, 0.0);
        double last_x = xs.front();
        double last_y = ys.front();
        size_t idx = 0;
        for (size_t i = 0; i < label_steps_; ++i) {
            double target = dt_ * static_cast<double>(i);
            while (idx + 1 < times.size() && times[idx + 1] < target) {
                idx++;
            }
            double x = last_x;
            double y = last_y;
            if (idx + 1 < times.size() && times[idx] <= target) {
                double t0 = times[idx];
                double t1 = times[idx + 1];
                double ratio = (target - t0) / (t1 - t0);
                x = xs[idx] + ratio * (xs[idx + 1] - xs[idx]);
                y = ys[idx] + ratio * (ys[idx + 1] - ys[idx]);
            } else if (idx < times.size()) {
                x = xs[idx];
                y = ys[idx];
            }
            last_x = x;
            last_y = y;
            label_x[i] = x;
            label_y[i] = y;
        }

        double stamp = static_cast<double>(scan->header.stamp.sec) +
                       static_cast<double>(scan->header.stamp.nanosec) * 1e-9;

        csv_file_ << std::fixed << std::setprecision(5) << stamp;

        for (size_t i = 0; i < range_count_; ++i) {
            csv_file_ << "," << sanitize(scan->ranges[i], scan->range_min, scan->range_max);
        }
        for (size_t i = 0; i < range_count_; ++i) {
            csv_file_ << "," << sanitize(grid->ranges[i], 0.0, scan->range_max);
        }
        for (size_t i = 0; i < label_steps_; ++i) {
            csv_file_ << "," << label_x[i];
        }
        for (size_t i = 0; i < label_steps_; ++i) {
            csv_file_ << "," << label_y[i];
        }
        csv_file_ << "\n";
        csv_file_.flush();
        if (!csv_file_.good()) {
            RCLCPP_ERROR(this->get_logger(), "Failed writing to CSV file.");
        }
    }

    // Subscribers and synchronizer
    message_filters::Subscriber<LaserScan> laser_scan_sub_;
    message_filters::Subscriber<PolarGrid> polar_grid_sub_;
    message_filters::Subscriber<Path> path_sub_;
    std::shared_ptr<Synchronizer> sync_;

    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;

    std::ofstream csv_file_;
    std::string output_csv_file_;
    bool header_written_ {false};
    bool normalize_ {false};
    bool forward_only_ {false};
    int downsample_step_ {1};
    size_t sample_count_ {0};

    size_t range_count_ {0};
    double angle_min_ {0.0};
    double angle_max_ {0.0};
    double angle_increment_ {0.0};

    double horizon_sec_ {1.6};
    double dt_ {0.1};
    size_t label_steps_ {16};
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DataLoggerNode>());
    rclcpp::shutdown();
    return 0;
}
