#include "../include/function.hpp"

Vector<Function *> Function::Functions;
Function::Actions Function::action;

Function::Function(String element, byte pin[], unsigned int x, unsigned int y)
{
    // It's not possible use Strings with Switch Statements
    if (element == action.startup)
        this->element = new Led(pin[0]);

    else if (element == action.light)
        this->element = new Led(pin[0]);
}

Function::~Function()
{
}

void Function::Create_function(String action, byte pin[], unsigned int x, unsigned int y)
{
    Functions.push_back(new Function(action, pin, x, y));
}