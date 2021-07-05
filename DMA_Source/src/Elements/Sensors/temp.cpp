#include "../../../include/Elements/Sensors/temp.hpp"

Temperature_Sensor::Temperature_Sensor(byte pin)
{
    this->pin = pin;
    this->Initialize();
}

Temperature_Sensor::~Temperature_Sensor() {}

void Temperature_Sensor::Initialize()
{
    pinMode(this->pin, INPUT);
    this->update_value();
}

void Temperature_Sensor::update_value()
{
    this->actual_value = analogRead(this->pin);
}

long Temperature_Sensor::get_value()
{
    update_value();
    return this->actual_value;
}