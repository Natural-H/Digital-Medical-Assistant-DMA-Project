#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//  Singleton class
class Listener
{
private:
    Listener(/* args */);
    static Listener *instance;

    byte *RF24_pins;
    RF24 *radio;

    struct data
    {
        int x;
        int y;
    };

public:
    static Listener *getInstance();

    Listener(Listener &other) = delete;
    
    void operator=(const Listener&) = delete;

    data get_data;

    bool RF24_is_available();
    void RF24_take_values();

    void Initialize();
};