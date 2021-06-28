#pragma once

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "element.hpp"

class LCD : public Element
{
private:
    byte *pin;
    LiquidCrystal *lcd;

public:
    LCD(byte pin[]);
    ~LCD();

    void Initialize();
    void print(String text);
};