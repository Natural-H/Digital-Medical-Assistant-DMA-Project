#pragma once

#include <Arduino.h>
#include <string.h>
#include <Vector.h>

#include "Elements/element.hpp"
#include "Elements/led.hpp"
#include "Elements/button.hpp"

class Function
{
private:
    String id;

    Element *element;

    struct Actions
    {
        const String startup = "startup";
        const String light = "light";
        const String cut = "cut";
    };

    Function(String action, byte pin[], unsigned int x, unsigned int y);
    
    ~Function();

public:
    static void Create_function(String action, byte pin[], unsigned int x, unsigned int y);

    static Actions action;

    static Vector<Function *> Functions;

    void Execute();

    void Execute(uint32_t argument);
};