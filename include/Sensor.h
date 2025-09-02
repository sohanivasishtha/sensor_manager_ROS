#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Sensor{
    protected:
        int id;
        string name;
        vector<float> readings;
    
    public:
        Sensor();
        Sensor(int val_id, string val_name);
        virtual ~ Sensor();

        virtual void readValue();
        virtual bool validateReading(float value);

        void addReading(float value);
        void printReadings();
        
        virtual void printInfo();

        int getId();
        string getName();

        vector<float> getReadings();


};
