//MAX3010x library
#include <MAX30105.h>
#include <heartRate.h>

#include <Wire.h>

//  RF24 Libraries
#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>
#include <LiquidCrystal.h>

struct data
{
    int x;
    int y;
};

struct Section
{
    const String temp = "Temperatura";
    const String pulse = "Pulso Cardiaco";
    const String frecuency = "Frecuencia";
    const String time = "Time running:";
};

byte rates[4];
byte rate_iterator;
unsigned int beat_average;
unsigned long last_beat;

data get_data;
Section section;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
RF24 radio(10, 9);
MAX30105 sensor;

String name_of_section;
byte last_section_showed;

const byte led = 7;
const byte buzzer = 6;

void setup()
{
    const byte address[6] = "00001";

    // Initializing values to avoid "Using uninitialized memory" exception
    last_section_showed = 0;

    get_data.x = 0;
    get_data.y = 0;

    rate_iterator = 0;
    beat_average = 0;
    last_beat = 0;

    // radio.begin();
    // radio.openReadingPipe(0, address);
    // radio.setPALevel(RF24_PA_MIN);
    // radio.setDataRate(RF24_250KBPS);
    // radio.startListening();

    sensor.begin();
    sensor.setup();
    sensor.setPulseAmplitudeRed(0x0A);

    lcd.begin(16, 2);
    lcd.clear();
}

void loop()
{
    // if (radio.available())
    // {
    //     radio.read(&get_data, sizeof(data));
    // }

    if (get_data.x < /* X Value Coord */ 500 && get_data.x > /* another value */ 250 || foo() == 1)
    {
        name_of_section = section.temp;

        show_section(1);
    }
    else if (get_data.x > 0 && get_data.x < 115 || foo() == 2)
    {
        name_of_section = section.pulse;

        show_section(2);
    }
    else if (get_data.x > -200 && get_data.x < -1 || foo() == 3)
    {
        name_of_section = section.frecuency;

        show_section(3);
    }
    else if (foo() == 4)
    {
        name_of_section = section.time;

        show_section(4);
    }
}

void show_section(uint16_t section)
{
    lcd.setCursor(0, 0);

    if (section != last_section_showed)
        lcd.clear();

    lcd.print(name_of_section);
    lcd.setCursor(0, 1);

    switch (section)
    {
    case 1:
        lcd.print("Section 1");
        break;

    case 2:
        Show_BPM_Section();
        break;

    case 3:
        lcd.print("Section 3");
        break;

    case 4:
        Show_Time_Section();
        break;

    default:
        lcd.print("Null section");
        break;
    }

    last_section_showed = section;
}

void Show_Time_Section() { lcd.print((String)(millis() / 1000) + " seconds."); }

void Show_BPM_Section()
{
    long ir_value = sensor.getIR();

    if (ir_value > 7000)
    {
        lcd.print(beat_average);

        if (checkForBeat(ir_value) == true)
        {
            lcd.print(beat_average);

            tone(buzzer, 1000);
            delay(100);
            noTone(buzzer);

            long delta_time = millis() - last_beat;
            last_beat = millis();

            calculate_average(delta_time);
        }
    }
    else
    {
        lcd.print("- Pon tu dedo -");
    }
}

double beats_per_minute(long delta_time) { return 60 / delta_time / 1000.0; }

void calculate_average(long delta_time)
{
    if (beats_per_minute(delta_time) > 20 && beats_per_minute(delta_time) < 255)
    {
        rates[rate_iterator++] = (byte)beats_per_minute(delta_time);
        rate_iterator %= 4;

        beat_average = 0; //  Reset Average

        for (auto &&rate : rates)
            beat_average += rate;

        beat_average / 4;
    }
}

int foo()
{
    if (millis() > 0 && millis() < 5000)
        return 1;
    else if (millis() > 5000 && millis() < 7000)
        return 2;
    else if (millis() > 7000 && millis() < 12000)
        return 3;
    else
        return 4;
}