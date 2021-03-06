#pragma once

#include <Arduino.h>
#include "element.hpp"

class Button : public Element
{
private:
    byte pin;
    byte state;
    byte last_reading;

    unsigned long last_debonuce_time;
    unsigned long debonuce_delay;

public:
    Button(byte pin);
    ~Button();

    void Initialize();
    void update_state();

    byte get_state();
    bool isPressed();
};
