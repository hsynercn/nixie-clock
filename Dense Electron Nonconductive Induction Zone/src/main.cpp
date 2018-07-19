#include <Arduino.h>
#include "NixieDigit.h"
#include "NixieGroup.h"

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


NixieGroup nixieGroup(&digit1, &digit2, &digit3, &digit4, &digit5, &digit6, 100);

RTC_DS3231 rtc;

const int inputPin = A0;
const int outpitPin = 13;

unsigned int inputSample;

void setup()
{
    pinMode(22, OUTPUT);
    Serial.begin(9600);
    nixieGroup.initializeDigits();

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
    int randPeirod = 900;
    int sec, min,hour;
    int totalSec = 0;

    unsigned int inputMax = 0;
    unsigned int inputMin = 1024;

    int lastRepeat = 0;
    int repeat = 0;
    bool soundOnFlag = true;
    int a = 0;
    while(1)
    {

        //if(soundOnFlag)
            nixieGroup.printGroup();

        repeat++;
        currentMillis = millis();

        inputSample = analogRead(inputPin);

        if(inputMin>inputSample)
        {
            inputMin = inputSample;
        }
        if(inputMax<inputSample)
        {
            inputMax = inputSample;
        }
            
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
            Serial.print(repeat);
            if((inputMax - inputMin)>100)
            {
                soundOnFlag = !soundOnFlag;
                Serial.print(" Diff: ");
                Serial.print(inputMax - inputMin);
                Serial.println();
            }
            Serial.println();

            inputMax = 0;
            inputMin = 1024;
            lastRepeat = repeat; 
            repeat = 0;
            
            startMillis = currentMillis;
            
            totalSec = startMillis/1000;
            //sec = now.second();
            sec++;
            //min = now.minute();
            //hour = now.hour();
            //nixieGroup.setTime(sec, min, hour);
            nixieGroup.setTime(sec, sec, sec);
            /*
            if((currentMillis - lastRandMillis) >= randPeirod && soundOnFlag)
            {
                nixieGroup.randPrintGroup();
                lastRandMillis = currentMillis;
            }*/

        }
    
    }    
}