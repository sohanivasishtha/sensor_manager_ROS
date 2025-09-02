#include "UltraSonicSensor.h"

UltraSonicSensor::UltraSonicSensor(){};
UltraSonicSensor::UltraSonicSensor(int val_id, string val_name){
    id = val_id;
    name = val_name;
}
UltraSonicSensor::~UltraSonicSensor(){};

void UltraSonicSensor::readValue(){
    cout << " The readinng is from " << name << " sensor having id: " << id << endl;
}

bool UltraSonicSensor::validateReading(float value){
    if (value >0 && value < 400){
                cout << "Valid reading from "<< name << "sensor" << endl;
                return true;
            }
            cout <<" Invalid reading from " << name << "sensor" << endl;
            return false;
}
