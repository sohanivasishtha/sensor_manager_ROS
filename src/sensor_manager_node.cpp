    #include "SensorManager.h"
    #include <rclcpp/rclcpp.hpp>
    #include <sensor_msgs/msg/laser_scan.hpp>
    #include <LidarSensor.h>


    class SensorManagerNode : public rclcpp::Node{
        public:
            SensorManagerNode() : Node("sensor_manage_node"){
                RCLCPP_INFO(this->get_logger(),"SensorManagerNode started.");

            laser_sub = this->create_subscription<sensor_msgs::msg::LaserScan>("/scan",10,
            std::bind(&SensorManagerNode::callback, this, std::placeholders::_1));

            laser_summary_pub = this->create_publisher<sensor_manager_ros::msg::LidarSummary>("lidar_summary", 10);

            }
            

            void callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
                auto summary = manager.processLaserScan(msg);
                if (laser_summary_pub){
                    laser_summary_pub->publish(summary.value());
                }
                        
            }

        private:
            SensorManager manager;
            rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_sub;
            rclcpp::Publisher<sensor_manager_ros::msg::LidarSummary>::SharedPtr laser_summary_pub;
    };

    int main(int argc, char **argv){
        rclcpp::init(argc, argv);
        auto node= std::make_shared<SensorManagerNode>();
        rclcpp::spin(node); 
        rclcpp::shutdown();
        return 0;
    }

