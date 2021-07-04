#include <Vector.h>

#include "include/function.hpp"
#include "include/Elements/element.hpp"

Function last_executed_function;

void setup()
{
    byte pins_for_LCD[4] {5, 4, 3, 2};

    //  This function only will be called once
    Function startup(Function::action.startup, pins_for_LCD, 12312 /* This is just a test */, 12321 /* This is just a test */);
    startup.Execute();

    Function::Create_function(Function::action.move_to_left, pins_for_LCD);
    Function::Create_function(Function::action.move_to_right, pins_for_LCD);
}

void loop()
{
    for (auto &&function : Function::Functions)
    {
        if (true)
        {
            function->Execute();
            last_executed_function = *function;
        }
    }
    
    update_sensors();
    last_executed_function.lcd->update_section();
}

void update_sensors()
{
    for (auto &&section : /*Function::Functions[0]->lcd->sections*/ LCD::sections)
        section.sensor->update_value();
}