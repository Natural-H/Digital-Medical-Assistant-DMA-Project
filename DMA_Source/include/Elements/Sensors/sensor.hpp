#pragma once

#include "../element.hpp"

class Sensor : public Element
{
private:

public:
    Sensor();
    ~Sensor();

    virtual void update_value();
    virtual long get_value();

    virtual void Initialize();
};