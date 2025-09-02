#pragma once
#include <iostream>
#include "Sensor.h"

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
        virtual void addSummaryFromScan(const std::vector<float>& ranges, double timestamps);
    
    private:
        std::vector <LidarSummary> summaries;

};
