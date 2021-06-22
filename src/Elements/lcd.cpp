#include "../../include/Elements/lcd.hpp"

LCD::LCD(byte pin[]) : Element()
{
    this->pin = pin;

    this->lcd = new LiquidCrystal(12, 11, pin[0], pin[1], pin[2], pin[3]);
}

LCD::~LCD() {}

void LCD::Initialize() { lcd->begin(16, 2); }

void LCD::print(String text) { this->lcd->print(text); }