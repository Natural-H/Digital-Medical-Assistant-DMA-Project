#include "../include/function.hpp"

Vector<Function *> Function::functions;
Function::Actions Function::action;
LCD *Function::lcd;

Function::Function(String action, byte pin[], int x, int y, int radius)
{
    this->function = action;
    this->trigger_x = x;
    this->trigger_y = y;
    this->radius = radius;

    // It's not possible use Strings with Switch Statements
    if (action == Function::action.startup)
    {
        this->element = new Led(10);
        lcd = new LCD(pin);
    }

    else if (action == Function::action.light)
        this->element = new Led(pin[0]);
}

Function::Function(String action, int x, int y, int radius)
{
    this->function = action;
    this->trigger_x = x;
    this->trigger_y = y;
    this->radius = radius;
}

Function::Function(String action, byte pin[])
{
    this->function = action;

    // It's not possible use Strings with Switch Statements
    if (action == Function::action.startup)
    {
        this->element = new Led(10);
        lcd = new LCD(pin);
    }

    else if (action == Function::action.light)
        this->element = new Led(pin[0]);
}

Function::Function(String action) { this->function = action; }

Function::Function() {}

Function::~Function() {}

bool Function::operator==(Function &obj) { return (this->get_action() == obj.get_action()); }

int Function::get_x() { return this->trigger_x; }
int Function::get_y() { return this->trigger_y; }
int Function::get_radius() { return this->radius; }

void Function::Create_function(String action, byte pin[], int x, int y, int radius)
{
    functions.push_back(new Function(action, pin, x, y, radius));
}

void Function::Create_function(String action, int x, int y, int radius)
{
    functions.push_back(new Function(action, x, y, radius));
}

void Function::Create_function(String action, byte pin[])
{
    functions.push_back(new Function(action, pin));
}

void Function::Execute()
{
    if (this->function == action.startup)
        lcd->Action();

    if (this->function == action.move_to_left)
        lcd->Action(1);

    if (this->function == action.move_to_right)
        lcd->Action(2);
}

String Function::get_action() { return this->function; }