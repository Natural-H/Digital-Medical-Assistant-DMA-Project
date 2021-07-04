#pragma once

#include <Arduino.h>
#include <Vector.h>
#include <LiquidCrystal.h>

#include "element.hpp"
#include "section.hpp"

class LCD : public Element
{
private:
    byte *pin;
    LiquidCrystal *lcd;

    uint16_t actual_position;

public:
    LCD(byte pin[]);
    ~LCD();

    static Vector<Section> sections;

    void Initialize();

    void Action() override;
    void Action(uint32_t argument) override;
    void show_section(uint32_t section);
    void update_section();
    void apply_position();
};