#include <iostream>
#include "Sensor.h"
#include "UltraSonicSensor.h"
#include "LidarSensor.h"
#include "TemperatureSensor.h"
#include <vector>
#include "SensorManager.h"

int main(){

    int no_of_sensors;
    int input_id;
    string input_name;
    vector <float> input_readings;
    

    cout << "Enter the number of sensors to add: ";
    cin >> no_of_sensors; 
    SensorManager manager;

    for (int i = 0; i < no_of_sensors; i++){
        cout << "Enter Sensor ID: ";
        cin >> input_id;
        cout << "Enter Sensor Type (ultra, lidar, temp): ";
        cin >> input_name;
        manager.addSensor(input_id, input_name);
        
        cout << "Enter number of readings for the" << input_name << " sensor:";
        int no_of_reading;
        cin >> no_of_reading;
        
        manager.addReadingToSensor(input_id,no_of_reading);    
    }

    //Summarize the Sensor readings
    manager.readAllSensors();  
    manager.exportToCSV("data.csv");
    return 0;
}