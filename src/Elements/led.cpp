#include "../../include/Elements/led.hpp"

Led::Led(String name, byte pin) : Element(name)
{
    this->pin = pin;
    this->Initialize();
}

Led::~Led() {}

void Led::Initialize()
{
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, LOW);
}