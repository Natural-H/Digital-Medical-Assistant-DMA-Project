#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

class Button
{
private:
    byte pin;
    byte state;
    byte last_reading;

    unsigned long last_debonuce_time;
    unsigned long debonuce_delay;

public:
    Button(byte pin)
    {
        this->last_debonuce_time = 0;
        this->debonuce_delay = 35;
        this->last_reading = LOW;
        this->pin = pin;

        this->Initialize();
        this->update_state();
    }

    ~Button() {}

    void Initialize()
    {
        pinMode(this->pin, INPUT);
        this->update_state();
    }

    void update_state()
    {
        byte new_reading = digitalRead(this->pin);

        if (new_reading != last_reading)
            last_debonuce_time = millis();

        if (millis() - last_debonuce_time > debonuce_delay)
            state = new_reading;

        last_reading = new_reading;
    }

    byte get_state()
    {
        this->update_state();
        return this->state;
    }

    bool is_pressed() { return (this->get_state() == HIGH); }
};

Button button = 5;

const byte x = A0;
const byte y = A1;
const byte z = A2;

RF24 radio(8, 10);
const byte address[6] = "00001";

struct data
{
    int x;
    int y;
    int z;
};

data read_data;

void setup()
{
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
    radio.setDataRate(RF24_250KBPS);
    radio.stopListening();
}

void loop()
{
    read_data.x = analogRead(x);
    read_data.y = analogRead(y);
    read_data.z = analogRead(z);

    if (button.is_pressed())
        radio.write(&read_data, sizeof(data));
}