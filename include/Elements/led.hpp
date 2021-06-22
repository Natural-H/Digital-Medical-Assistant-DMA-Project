#pragma once

#include <Arduino.h>

#include "element.hpp"

class Led : public Element
{
private:
    byte pin;

public:
    Led(byte pin);
    ~Led();

    void Initialize();
    void on();
    void off();
};