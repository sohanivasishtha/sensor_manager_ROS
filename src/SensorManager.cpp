#include "SensorManager.h"
#include <UltraSonicSensor.h>
#include <LidarSensor.h>
#include <TemperatureSensor.h>
#include <rclcpp/rclcpp.hpp>
#include <vector>


using namespace std;

SensorManager::SensorManager(){};
SensorManager::~SensorManager(){
    for (Sensor* s: sensors){
        delete s;

    }
}

void SensorManager::addSensor(int id, string type){
    if (type == "ultra"){
        sensors.push_back(new UltraSonicSensor(id, type));
    }
    else if (type == "lidar"){
        sensors.push_back(new LidarSensor(id,type));
    }
    else if (type == "temp"){
        sensors.push_back(new TemperatureSensor(id, type));
    }
    else{
        cout << "Unknown Sensor Type " << endl;
        return;
    }
}

void SensorManager::addReadingToSensor(int id, int no_of_reading){
    for (int i = 0; i < no_of_reading; i++){
        float value;
        cout << "enter value :";
        cin >> value;
        bool found = false;
        for (Sensor* s : sensors){
            if (s->getId() == id){
                s->addReading(value);
                found = true;
                break;
        }
    }
if (!found) cout << " Invalid ID\n" << endl;
}}

void SensorManager::removeSensor(int id){
    for (auto it = sensors.begin() ; it != sensors.end(); ++it){
        if((*it)->getId() == id){
            delete *it;
            sensors.erase(it);
            cout << "Sensor Removed" << endl;
            return;
        }}
        cout << "Sensor not found" << endl ;}

void SensorManager::readAllSensors(){
    
    for (Sensor* s : sensors){
        s->readValue();
        //s->printInfo();
        s->printReadings();
    }
}

void SensorManager::exportToCSV(string filename){
    ofstream file(filename);
    
    if(!file.is_open()){
        cout << "Can't open the file" << endl;
        return;
    }
    file << "id, type, readings \n";
    for (Sensor* s : sensors){
        for (float r: s->getReadings()){
            file << s->getId() << "," << s->getName() <<"," << r << "\n";

        }
    }
    file.close();
    cout <<" file generated" << endl;
}



std::optional<sensor_manager_ros::msg::LidarSummary> SensorManager::processLaserScan(const sensor_msgs::msg::LaserScan::SharedPtr msg){
    LidarSensor lidar;

    std::vector<float> ranges = msg->ranges;
    double timestamps = rclcpp::Time(msg->header.stamp).seconds();

    return lidar.addSummaryFromScan(ranges,timestamps);

    //cout << "Processing scan. Range count = " << msg->ranges.size() << endl;

    
}




