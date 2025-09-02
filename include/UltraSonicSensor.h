#pragma once
#include <iostream>
#include <vector>
#include "Sensor.h"

using namespace std;

class UltraSonicSensor : public Sensor{
    public:
        UltraSonicSensor();
        UltraSonicSensor(int val_id, string val_name);
        virtual ~UltraSonicSensor();

        virtual void readValue() override;
        virtual bool validateReading(float value) override;
};

