#include "TemperatureSensor.h"


TemperatureSensor::TemperatureSensor(){};
TemperatureSensor::TemperatureSensor(int val_id, string val_name){
    id = val_id;
    name = val_name;
}
TemperatureSensor::~TemperatureSensor(){}

void TemperatureSensor::readValue(){
    cout << " This reading is from" <<name << "sensor" << 
"with id" << id << endl;
}

bool TemperatureSensor::validateReading(float value){
    if (value > -50 && value < 150){
                cout << "Valid reading from"<<name<<" sensor" << endl;
                return true;
            }
            cout <<" Invalid reading from" << name << "sensor" << endl;
            return false;
}





