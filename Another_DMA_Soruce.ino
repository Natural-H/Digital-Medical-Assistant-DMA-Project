//MAX3010x libraries
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
    int z;
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
float beats_per_minute;
unsigned int beat_average;
unsigned long last_beat;

const byte lm35_pin = A0;
const byte lm35dz_pin = A1;

const unsigned int reference_temp = 36;

data get_data;
Section section;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
RF24 radio(10, 9);
MAX30105 sensor;

String name_of_section;
byte last_section_showed;

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
    sensor.setup();                    //Configure sensor with default settings
    sensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
    sensor.setPulseAmplitudeGreen(0);  //Turn off Green LED

    lcd.begin(16, 2);
    lcd.clear();
}

void loop()
{
    // if (radio.available())
    // {
    //     radio.read(&get_data, sizeof(data));
    // }

    //  This will change due the type of aceleremeter

    if (get_data.x < /* X Value Coord */ 500 && get_data.x > /* another value */ 250)
    {
        name_of_section = section.temp;

        show_section(1);
    }
    else if (get_data.x > 0 && get_data.x < 115)
    {
        name_of_section = section.pulse;

        show_section(2);
    }
    else if (get_data.x > -200 && get_data.x < -1)
    {
        name_of_section = section.frecuency;

        show_section(3);
    }
    else
    {
        // name_of_section = section.temp;
        //  show_section(1);
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
        Show_Temperature_Section();
        break;

    case 2:
        Show_BPM_Section();
        break;

    case 3:
        Show_Frequency_Section();
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

    if (ir_value > 50000)
    {
        clearLine(1);
        lcd.print("BPM: " + (String)beats_per_minute); //  Using explicit casting to String

        if (checkForBeat(ir_value) == true)
        {
            long delta = millis() - last_beat;
            last_beat = millis();

            tone(buzzer, 1000, 100);

            beats_per_minute = 60 / (delta / 1000.0);

            if (beats_per_minute < 255 && beats_per_minute > 20)
            {
                rates[rate_iterator++] = (byte)beats_per_minute; //Store this reading in the array
                rate_iterator %= 4;

                //Take average of readings
                beat_average = 0;

                for (byte x = 0; x < 4; x++)
                    beat_average += rates[x];

                beat_average /= 4;
            }
        }
    }
    else
    {
        lcd.print("- Pon tu dedo -");
    }
}

void clearLine(uint16_t line)
{
    lcd.setCursor(0, line);
    lcd.print("                ");
}

void Show_Temperature_Section() { lcd.print((String)get_temperature(lm35_pin) + " C"); }

float get_temperature(byte pin) { return ((analogRead(pin) * 5000.0) / 1023.0) / 10.0; }

bool old_state;
bool is_first_time = true;
int breath_count = 0;
unsigned int breaths_per_minute;
unsigned long time_measuring = 15000;
unsigned long last_reading = 0;

void Show_Frequency_Section()
{
    if (is_first_time)
        lcd.print("Midiendo...");
    
    measure_frequency();

    if (millis() - last_reading < time_measuring)
    {
        last_reading = millis();
        is_first_time = false;
    }   else
    {
        breaths_per_minute = breath_count * 4;
        breath_count = 0;
        clearLine(1);
        lcd.print("Test: " + (String)breaths_per_minute);
    }
    
}

void measure_frequency()
{
    bool is_breathing;

    if (get_temperature(lm35dz_pin) > reference_temp)
        is_breathing = true;
    else
        is_breathing = false;

    if (old_state != is_breathing && is_breathing)
        breath_count++;

    old_state = is_breathing;
}