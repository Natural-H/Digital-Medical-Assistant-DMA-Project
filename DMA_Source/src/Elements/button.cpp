#include "../../include/Elements/button.hpp"

Button::Button(byte pin) : Element()
{
    this->last_debonuce_time = 0;
    this->debonuce_delay = 35;
    this->last_reading = LOW;
    this->pin = pin;
    
    this->Initialize();
    this->update_state();
}

Button::~Button() {}

void Button::update_state()
{
    byte new_reading = digitalRead(this->pin);

    if (new_reading != last_reading)
        last_debonuce_time = millis();

    if (millis() - last_debonuce_time > debonuce_delay)
        state = new_reading;
    
    last_reading = new_reading;
}

byte Button::get_state()
{
    this->update_state();
    return this->state;
}

bool Button::isPressed() { return (get_state() == HIGH); }