#pragma once

#include <Arduino.h>
#include <string.h>

#include "Sensors/sensor.hpp"
#include "Sensors/pulsemeter.hpp"
#include "Sensors/temp.hpp"
#include "Sensors/frecuency_sensor.hpp"

class Section
{
private:
    String measure;
    String *name_of_data;
    String *data;

    struct Measurements
    {
        const String temperature = "Temperature.";
        const String bpm = "Beats per min.";
        const String frecuency = "Frecuency.";
    };

public:
    Section(String measure, String name_of_data[2], String data[2]);
    ~Section();

    static Measurements measuring;

    Sensor *sensor;

    String getName();
    String getInfo();

    void update_data();
};