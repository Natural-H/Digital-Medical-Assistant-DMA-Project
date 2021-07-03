#pragma once

#include <Arduino.h>

#include "sensor.hpp"

class Temperature_Sensor : public Sensor
{
private:
    byte pin;
    long actual_value;

public:
    Temperature_Sensor(byte pin);
    ~Temperature_Sensor();

    void update_value() override;
    void Initialize() override;

    long get_value() override;
};