#pragma once

#include <Arduino.h>
#include <Vector.h>
#include <string.h>

class Element
{
protected:
    String name;
    byte pin;

public:
    Element(String name, byte pin);
    ~Element();

    virtual void Action();

    String getName();
};