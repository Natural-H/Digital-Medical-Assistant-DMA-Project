#pragma once

#include <Arduino.h>
#include <Vector.h>
#include <string.h>

class Element
{
protected:
    String name;

    Element(String name);
    ~Element();

public:
    virtual void Action();

    String getName();
};