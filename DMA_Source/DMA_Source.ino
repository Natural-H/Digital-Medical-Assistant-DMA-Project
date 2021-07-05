#include <Vector.h>

#include "include/function.hpp"
#include "include/Listener/listener.hpp"
#include "include/Elements/element.hpp"

//  Necessary to create a listener
Listener *listener = listener->getInstance();

Function *last_executed_function;

void setup()
{
    byte pins_for_LCD[4]{5, 4, 3, 2};

    //  This function only will be called once
    Function startup(Function::action.startup, pins_for_LCD);
    startup.Execute();

    Function::Create_function(Function::action.move_to_left, 12312, 12321, 150);
    Function::Create_function(Function::action.move_to_right, 12312, 12321, 150);
    Function::Create_function(Function::action.centered, 0, 0, 150);

    last_executed_function = new Function();
}

void loop()
{
    if (listener->RF24_is_available())
    {
        listener->RF24_take_values();

        for (auto &&function : Function::functions)
        {
            if ((listener->get_data.x > function->get_x() - function->get_radius() && listener->get_data.x < function->get_x() + function->get_radius()) &&
                (listener->get_data.y > function->get_y() - function->get_radius() && listener->get_data.y < function->get_y() + function->get_radius()) &&
                //  Avoid multiple execution
                function != last_executed_function)
            {
                function->Execute();
                last_executed_function = function;
            }
        }
    }

    LCD::update_sensors();

    //  Showing and updating data
    last_executed_function->lcd->update_section();
}