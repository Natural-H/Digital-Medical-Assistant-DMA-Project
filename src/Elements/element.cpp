#include "../../include/Elements/element.hpp"

Element::Element(String name, byte pin)
{
    this->name = name;
    this->pin = pin;
}

Element::~Element()
{
}

void Element::Action() {}

String Element::getName() { return this->name; }