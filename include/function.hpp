#pragma once

#include <Arduino.h>
#include <string.h>
#include <Vector.h>

class Function
{
private:
    String id;

    struct Actions
    {
        String startup = "startup";
        String light = "light";
        String cut = "cut";
    };
    
    Actions action;

public:
    Function(/* args */);
    
    ~Function();
};