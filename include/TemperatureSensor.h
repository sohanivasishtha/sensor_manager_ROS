#pragma once
#include <iostream>
#include <vector>
#include "Sensor.h"

class TemperatureSensor : public Sensor{
    public:
        TemperatureSensor();
        TemperatureSensor(int val_id, string val_name);
        virtual ~TemperatureSensor();

        virtual void readValue() override;
        virtual bool validateReading(float value) override;
};








