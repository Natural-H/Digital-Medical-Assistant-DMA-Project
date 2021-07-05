#include "../../include/Elements/lcd.hpp"

Vector<Section> LCD::sections;

LCD::LCD(byte pin[]) : Element()
{
    this->actual_position = 1;

    this->sections[0] = Section(Section::measuring.bpm);
    this->sections[1] = Section(Section::measuring.temperature);
    this->sections[2] = Section(Section::measuring.frecuency);

    this->pin = pin;

    this->lcd = new LiquidCrystal(12, 11, pin[0], pin[1], pin[2], pin[3]);
}

LCD::~LCD() {}

void LCD::Initialize() { lcd->begin(16, 2); }

void LCD::Action()
{
    this->show_section(1);
    this->apply_position();
}

void LCD::Action(uint32_t argument)
{
    switch (argument)
    {
    case 1:
        if (this->actual_position > 0)
            actual_position--;
        break;
    case 2:
        if (this->actual_position < 2)
            actual_position++;
        break;
    
    default:
        this->actual_position = 1;
        break;
    }

    this->apply_position();
}

void LCD::apply_position()
{
    switch (this->actual_position)
    {
    case 1:
        this->show_section(0);
        break;
    case 2:
        this->show_section(1);
        break;
    case 3:
        this->show_section(2);
        break;
    
    default:
        this->lcd->print("Unknow section...");
        break;
    }
}

void LCD::show_section(uint32_t section)
{
    this->lcd->clear();
    this->lcd->println(sections[section].getName());
    this->lcd->println(sections[section].getInfo());
}

void LCD::update_section() { this->show_section(this->actual_position); }

void LCD::update_sensors()
{
    for (auto &&section : /*Function::functions[0]->lcd->sections*/ LCD::sections)
        section.sensor->update_value();
}