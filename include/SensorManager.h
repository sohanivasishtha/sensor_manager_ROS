#include <iostream>
#include <string>
#include "Sensor.h"
#include <vector>
#include <fstream>
#include <sensor_msgs/msg/laser_scan.hpp>

class SensorManager{
    protected:
        std::vector<Sensor*> sensors;
    public:
        SensorManager();
        virtual ~SensorManager();
        void addSensor(int id, std::string name);
        void addReadingToSensor(int id, int value);
        void removeSensor(int id);
        void readAllSensors();
        void exportToCSV(std::string filename);
        void printSummary();
        void processLaserScan(const sensor_msgs::msg::LaserScan::SharedPtr msg);
        
};



