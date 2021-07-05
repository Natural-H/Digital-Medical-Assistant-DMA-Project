#include "../../../include/Elements/Sensors/pulsemeter.hpp"

Pulsemeter::Pulsemeter(byte pin, byte led_pin) : Sensor()
{
    this->Initialize();
}

Pulsemeter::~Pulsemeter() {}

void Pulsemeter::Initialize()
{
    this->led = new Led(this->led_pin);
}