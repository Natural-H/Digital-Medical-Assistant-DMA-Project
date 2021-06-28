#pragma once

#include <Arduino.h>

#include "element.hpp"
#include "led.hpp"

class Pulsemeter : public Element
{
private:
    byte pin;
    byte led_pin;

    Led *led;

    unsigned int ppm;
    unsigned int time_between_pulsations;

    bool is_pulse;

public:
    Pulsemeter(byte pin, byte led_pin);
    ~Pulsemeter();

    void Initialize();
};