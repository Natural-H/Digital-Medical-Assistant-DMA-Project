#pragma once

#include <Arduino.h>

#include "sensor.hpp"

class Frecuency_sensor : public Sensor
{
private:
    /* data */
public:
    Frecuency_sensor(byte pin, byte led_pin);
    ~Frecuency_sensor();
};
