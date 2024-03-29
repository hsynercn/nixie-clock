#include <Arduino.h>
#include "NixieDigit.h"
#include "NixieGroup.h"
#include "SoundSensor.h"

#include <Wire.h>
#include "RTClib.h"

/*NixieDigit digit1(23, 25, 27, 29);
NixieDigit digit2(31, 33, 35, 37);
NixieDigit digit3(39, 41, 43, 45);
NixieDigit digit4(47, 49, 51, 53);
NixieDigit digit5(46, 48, 50, 52);
NixieDigit digit6(38, 40, 42, 44);*/

NixieDigit digit1(23, 25, 27, 29);
NixieDigit digit2(31, 33, 35, 37);
NixieDigit digit3(39, 41, 43, 45);
NixieDigit digit4(47, 49, 51, 53);
NixieDigit digit5(52, 50, 48, 46);
NixieDigit digit6(44, 42, 40, 38);


NixieGroup nixieGroup(&digit1, &digit2, &digit3, &digit4, &digit5, &digit6, 1000);

SoundSensor soundSensor(A0);

RTC_DS3231 rtc;

const int inputPin = A0;
const int outpitPin = 13;

unsigned int inputDiff;

void setup()
{
    pinMode(22, OUTPUT);
    Serial.begin(9600);
    nixieGroup.initializeDigits();
    soundSensor.initializeSensor();

    nixieGroup.setSoundSensor(&soundSensor);

    pinMode(outpitPin, OUTPUT);
    pinMode(inputPin, INPUT);

    if (! rtc.begin()) 
    {
        Serial.println("Couldn't find RTC");
        while (1);
    }

    //Setup of time if RTC lost power or time is not set
    if (rtc.lostPower()) 
    {
        //Sets the code compilation time to RTC DS3231
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

}

void loop()
{
    unsigned long startMillis = millis();
    unsigned long currentMillis = startMillis;
    unsigned long lastRandMillis = startMillis;
    int period = 1000;
    int randPeirod = 60;
    int sec, min,hour;
    int totalSec = 0;

    int lastRepeat = 0;
    int repeat = 0;
    bool soundOnFlag = true;
    soundSensor.reset();
    while(1)
    {
        
        if(soundOnFlag)
        {
            nixieGroup.printGroup(inputPin);
        }
        else
        {
            soundSensor.read();
        }
        
        repeat++;
        currentMillis = millis();
            
        analogWrite(outpitPin, (255-((float)(currentMillis - startMillis)/(float)period)*255));                                          

        if((currentMillis - startMillis) >= period)
        {
            DateTime now = rtc.now();
            Serial.print("TEST");
            Serial.print(now.year(), DEC);
            Serial.print('/');
            Serial.print(now.month(), DEC);
            Serial.print('/');
            Serial.print(now.day(), DEC);
            Serial.print(now.hour(), DEC);
            Serial.print(':');
            Serial.print(now.minute(), DEC);
            Serial.print(':');
            Serial.print(now.second(), DEC);
            Serial.println();

            Serial.print("CPS:");
            Serial.println(repeat);
            
            Serial.println();
            Serial.print(" Diff: ");
            Serial.print(inputDiff);
            Serial.println();
            Serial.println("Sound flag:");
            Serial.println(soundOnFlag);

            if(soundSensor.isUserCmdReceived() == true)
            {
                Serial.println("COMMAND RECEIVED");
                soundOnFlag = !soundOnFlag;
                soundSensor.reset();
            }

            lastRepeat = repeat; 
            repeat = 0;
            
            startMillis = currentMillis;
            totalSec = startMillis/1000;

            if(soundOnFlag == true)
            {
                sec = now.second();
                min = now.minute();
                hour = now.hour();
                nixieGroup.setTime(sec, min, hour);
            }
            else
            {
                nixieGroup.clearAll();
            }
            
            if(abs(currentMillis - lastRandMillis)/1000 >= randPeirod && soundOnFlag)
            {
                nixieGroup.randPrintGroup();
                lastRandMillis = currentMillis;
            }

        }
    
    }    
}
