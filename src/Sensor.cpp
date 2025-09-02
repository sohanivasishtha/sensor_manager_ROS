#include "Sensor.h"

using namespace std;

Sensor::Sensor() {};
Sensor::Sensor(int val_id, string val_name){
    id = val_id;
    name = val_name;
}

Sensor::~Sensor(){}

void Sensor::readValue(){
    cout << " Generic Sensor Value" << endl;
}

bool Sensor::validateReading(float /*value*/){
    return true; 
}

void Sensor::addReading(float value){        
        if (validateReading(value)){
            readings.push_back(value);
    }
    else{
        cout << "WARNING: not a valid value" << endl;
    }
}

void Sensor::printReadings(){
    cout << "Readings : { ";
    for (float s : readings){
        cout << s << ", " ;
    }
    cout <<"}" << endl;
}

void Sensor::printInfo(){
    cout <<"Sensor ID :" << id << endl << "Sensor Name :" << name << endl;
}

int Sensor::getId(){
    return id;
}

string Sensor::getName(){
    return name;
}

vector<float> Sensor::getReadings(){
    return readings;
}











