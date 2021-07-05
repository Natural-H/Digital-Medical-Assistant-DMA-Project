#include "../../include/Elements/led.hpp"

Led::Led(byte pin) : Element()
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