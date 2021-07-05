#include "../../include/Listener/listener.hpp"

Listener *Listener::instance;

Listener::Listener()
{
    this->RF24_pins = new byte[2] {10, 9};
    this->radio = new RF24(RF24_pins[0], RF24_pins[1]);

    this->Initialize();
}

Listener *Listener::getInstance()
{
    if (instance == nullptr)
        instance = new Listener();
    
    return instance;
}

void Listener::Initialize()
{
    const byte address[6] = "00001";

    this->radio->begin();
    this->radio->openReadingPipe(0, address);
    this->radio->setPALevel(RF24_PA_MIN);
    this->radio->setDataRate(RF24_250KBPS);
    this->radio->startListening();
}

bool Listener::RF24_is_available() { return this->radio->available(); }

void Listener::RF24_take_values() { this->radio->read(&this->get_data, sizeof(data)); }