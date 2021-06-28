#include "../../include/Elements/pulsemeter.hpp"

Pulsemeter::Pulsemeter(byte pin, byte led_pin) : Element()
{
    this->Initialize();
}

Pulsemeter::~Pulsemeter() {}

void Pulsemeter::Initialize()
{
    this->led = new Led(this->led_pin);
}