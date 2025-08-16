#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include "global_to_polar_cpp/msg/polar_grid.hpp"

class DataLoggerNode : public rclcpp::Node
{
public:
    DataLoggerNode() : Node("data_logger_node"), header_written_(false)
    {
        output_csv_file_ = this->declare_parameter<std::string>("output_csv_file", "datalog.csv");
        write_masks_ = this->declare_parameter<bool>("write_masks", false);
        normalize_ = this->declare_parameter<bool>("normalize", false);

        csv_file_.open(output_csv_file_, std::ios::out | std::ios::trunc);
        if (!csv_file_.is_open()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open output file: %s", output_csv_file_.c_str());
            rclcpp::shutdown();
            return;
        }

        laser_scan_sub_.subscribe(this, "/scan");
        polar_grid_sub_.subscribe(this, "/polar_grid");

        sync_ = std::make_shared<Synchronizer>(SyncPolicy(10), laser_scan_sub_, polar_grid_sub_);
        sync_->registerCallback(std::bind(&DataLoggerNode::syncCallback, this, std::placeholders::_1, std::placeholders::_2));

        RCLCPP_INFO(this->get_logger(), "Data Logger Node initialized. Logging to %s", output_csv_file_.c_str());
    }

    ~DataLoggerNode()
    {
        if (csv_file_.is_open()) {
            csv_file_.close();
        }
    }

private:
    using LaserScan = sensor_msgs::msg::LaserScan;
    using PolarGrid = global_to_polar_cpp::msg::PolarGrid;
    using SyncPolicy = message_filters::sync_policies::ApproximateTime<LaserScan, PolarGrid>;
    using Synchronizer = message_filters::Synchronizer<SyncPolicy>;

    void writeHeader(size_t n)
    {
        csv_file_ << "stamp";
        for (size_t i = 0; i < n; ++i) {
            csv_file_ << ",scan_" << i;
        }
        for (size_t i = 0; i < n; ++i) {
            csv_file_ << ",grid_" << i;
        }
        if (write_masks_) {
            for (size_t i = 0; i < n; ++i) {
                csv_file_ << ",scan_mask_" << i;
            }
            for (size_t i = 0; i < n; ++i) {
                csv_file_ << ",grid_mask_" << i;
            }
        }
        csv_file_ << "\n";
        csv_file_.flush();
    }

    double sanitize(double value, double range_min, double range_max, int &mask) const
    {
        if (!std::isfinite(value) || value < range_min || value > range_max) {
            mask = 0;
            return 0.0;
        }
        mask = 1;
        return normalize_ ? value / range_max : value;
    }

    void syncCallback(const LaserScan::ConstSharedPtr &scan,
                      const PolarGrid::ConstSharedPtr &grid)
    {
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
            writeHeader(range_count_);
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

        try {
            double stamp = static_cast<double>(scan->header.stamp.sec) +
                           static_cast<double>(scan->header.stamp.nanosec) * 1e-9;

            csv_file_ << std::fixed << std::setprecision(5);
            csv_file_ << stamp;

            std::vector<int> scan_mask(range_count_, 0);
            std::vector<int> grid_mask(range_count_, 0);

            for (size_t i = 0; i < range_count_; ++i) {
                double val = sanitize(scan->ranges[i], scan->range_min, scan->range_max, scan_mask[i]);
                csv_file_ << "," << val;
            }

            for (size_t i = 0; i < range_count_; ++i) {
                double g = grid->ranges[i];
                if (!std::isfinite(g) || g <= 0.0) {
                    grid_mask[i] = 0;
                    g = 0.0;
                } else {
                    grid_mask[i] = 1;
                    if (normalize_) {
                        g /= scan->range_max;
                    }
                    if (normalize_) {
                        if (g > 1.0) g = 1.0;
                    } else {
                        if (g > scan->range_max) g = scan->range_max;
                    }
                }
                csv_file_ << "," << g;
            }

            if (write_masks_) {
                for (size_t i = 0; i < range_count_; ++i) {
                    csv_file_ << "," << scan_mask[i];
                }
                for (size_t i = 0; i < range_count_; ++i) {
                    csv_file_ << "," << grid_mask[i];
                }
            }

            csv_file_ << "\n";
            csv_file_.flush();
            if (!csv_file_.good()) {
                RCLCPP_ERROR(this->get_logger(), "Failed writing to CSV file.");
            }
        } catch (const std::exception &e) {
            RCLCPP_ERROR(this->get_logger(), "Exception while writing CSV: %s", e.what());
        }
    }

    message_filters::Subscriber<LaserScan> laser_scan_sub_;
    message_filters::Subscriber<PolarGrid> polar_grid_sub_;
    std::shared_ptr<Synchronizer> sync_;

    std::ofstream csv_file_;
    std::string output_csv_file_;
    bool header_written_;
    bool write_masks_;
    bool normalize_;
    size_t range_count_ {0};
    double angle_min_ {0.0};
    double angle_max_ {0.0};
    double angle_increment_ {0.0};
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DataLoggerNode>());
    rclcpp::shutdown();
    return 0;
}

