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

    struct Actions
    {
        const String startup = "startup";
        const String light = "light";
        const String cut = "cut";
        const String move_to_left = "mtl";
        const String move_to_right = "mtr";
        const String centered = "centered";
    };

    int trigger_x;
    int trigger_y;

public:
    Function(String action, byte pin[], int x, int y);
    Function(String action, int x, int y);
    Function(String action, byte pin[]);
    Function(String action);
    Function();

    ~Function();

    bool operator==(Function &obj);

    static LCD *lcd;

    static void Create_function(String action, byte pin[], int x, int y);
    static void Create_function(String action, int x, int y);
    static void Create_function(String action, byte pin[]);

    static Actions action;

    static Vector<Function *> functions;

    void Execute();

    String get_action();
};