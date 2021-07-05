#include "../../include/Elements/section.hpp"

Section::Measurements Section::measuring;

Section::Section(String measure)
{
    this->measure = measure;

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
    // this->update_data();
    return (this->data + " " + this->status[1]);
}

void Section::update_data() { this->data = this->sensor->get_value(); }