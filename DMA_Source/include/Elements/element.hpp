#pragma once

#include <Arduino.h>
#include <Vector.h>
#include <string.h>

class Element
{
protected:
    Element();
    ~Element();

public:
    virtual void Action();

    virtual void Action(uint32_t argument);
};