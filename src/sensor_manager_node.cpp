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
            }

            void callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
                RCLCPP_INFO(this->get_logger(),
                "LaserScan callback triggered. angle_increment = %f",
                msg->angle_increment);                
                manager.processLaserScan(msg);      

            }

        private:
            SensorManager manager;
            rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_sub;
    };

    int main(int argc, char **argv){
        rclcpp::init(argc, argv);
        auto node= std::make_shared<SensorManagerNode>();
        
        rclcpp::spin(node); 
        rclcpp::shutdown();
        return 0;
    }

