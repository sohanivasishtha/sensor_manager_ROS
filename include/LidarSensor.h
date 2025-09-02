#pragma once
#include <iostream>
#include "Sensor.h"
#include "sensor_manager_ros/msg/lidar_summary.hpp"
#include <optional>

struct LidarSummary{
    float max_distance;
    float min_distance;
    float std_dev;
    float entropy;
    double timestamp;
};



class LidarSensor: public Sensor{
    public:
        LidarSensor();
        LidarSensor(int val_id, string val_name);
        virtual ~LidarSensor();
        virtual void readValue() override;
        virtual bool validateReading(float value) override;
        virtual std::optional<sensor_manager_ros::msg::LidarSummary> addSummaryFromScan(const std::vector<float>& ranges, double timestamps);
        
    
    private:
        std::vector <LidarSummary> summaries;

};
