#include "../include/function.hpp"

Vector<Function *> Function::Functions;
Function::Actions Function::action;

Function::Function(String action, byte pin[], unsigned int x, unsigned int y)
{
    this->function = action;
    this->trigger_x = x;
    this->trigger_y = y;

    // It's not possible use Strings with Switch Statements
    if (action == Function::action.startup)
    {
        this->element = new Led(10);
        this->lcd = new LCD(pin);
    }

    else if (action == Function::action.light)
        this->element = new Led(pin[0]);
}

Function::Function(String action, byte pin[])
{
    this->function = action;

    // It's not possible use Strings with Switch Statements
    if (action == Function::action.startup)
    {
        this->element = new Led(10);
        this->lcd = new LCD(pin);
    }

    else if (action == Function::action.light)
        this->element = new Led(pin[0]);
}

Function::Function(String action) { this->function = action; }

Function::Function() {}

Function::~Function() {}

bool Function::operator==(Function &obj) { return (this->get_action() == obj.get_action()); }

void Function::Create_function(String action, byte pin[], unsigned int x, unsigned int y)
{
    Functions.push_back(new Function(action, pin, x, y));
}

void Function::Create_function(String action, byte pin[])
{
    Functions.push_back(new Function(action, pin));
}

void Function::Execute()
{
    if (this->function == action.startup)
        this->lcd->Action();

    if (this->function == action.move_to_left)
        this->lcd->Action(1);

    if (this->function == action.move_to_right)
        this->lcd->Action(2);
}

String Function::get_action() { return this->function; }