#include "../../include/Elements/element.hpp"

Element::Element(String name)
{
    this->name = name;
}

Element::~Element()
{
}

void Element::Action() {}

String Element::getName() { return this->name; }