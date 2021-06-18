#include "../../include/Elements/button.hpp"

Button::Button(String name, byte pin) : Element(name)
{
    this->last_debonuce_time = 0;
    this->debonuce_delay = 35;
    this->last_reading = LOW;
    this->pin = pin;
    
    this->Initialize();
    this->updateState();
}

Button::~Button() {}

void Button::updateState()
{
    byte new_reading = digitalRead(this->pin);

    if (new_reading != last_reading)
        last_debonuce_time = millis();

    if (millis() - last_debonuce_time > debonuce_delay)
        state = new_reading;
    
    last_reading = new_reading;
}

byte Button::getState()
{
    this->updateState();
    return this->state;
}

bool Button::isPressed() { return (getState() == HIGH); }