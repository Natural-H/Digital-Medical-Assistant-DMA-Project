#include "../../include/Elements/section.hpp"

Section::Measurements Section::measuring;

Section::Section(String measure, String name_of_data[2], String data[2])
{
    this->measure = measure;
    this->name_of_data = name_of_data;
    this->data = data;

    if (this->measure == Section::measuring.temperature)
        this->sensor = new Temperature_Sensor(A0);

    else if (this->measure == Section::measuring.bpm)
        this->sensor = new Pulsemeter(A1, 10);

    else if (this->measure == Section::measuring.frecuency)
        this->sensor = new Frecuency_sensor(A2, 10);

    this->update_data();
}

Section::~Section() {}

String Section::getName() { return this->measure; }

String Section::getInfo()
{
    this->update_data();
    return (this->name_of_data[0] + ": " + this->data[0] + " " + this->name_of_data[1] + this->data[1]);
}

void Section::update_data() { this->data[0] = this->sensor->get_value(); }