#pragma once

#include <Arduino.h>
#include <string.h>
#include <Vector.h>

#include "Elements/element.hpp"
#include "Elements/led.hpp"
#include "Elements/button.hpp"
#include "Elements/lcd.hpp"

class Function
{
private:
    String function;

    Element *element;

    LCD *lcd;

    struct Actions
    {
        const String startup = "startup";
        const String light = "light";
        const String cut = "cut";
        const String move_to_left = "mtl";
        const String move_to_right = "mtr";
    };

    unsigned int trigger_x;
    unsigned int trigger_y;

public:
    Function(String action, byte pin[], unsigned int x, unsigned int y);
    Function(String action, byte pin[]);
    Function(String action);

    ~Function();

    static void Create_function(String action, byte pin[], unsigned int x, unsigned int y);
    static void Create_function(String action, byte pin[]);

    static Actions action;

    static Vector<Function *> Functions;

    void Execute();

    void Execute(uint32_t argument);
};