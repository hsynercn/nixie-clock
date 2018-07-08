#include <Arduino.h>
#include "NixieDigit.h"
#include "NixieGroup.h"

NixieDigit digit1(23, 25, 27, 29);
NixieDigit digit2(31, 33, 35, 37);
NixieDigit digit3(39, 41, 43, 45);
NixieDigit digit4(47, 49, 51, 53);
NixieDigit digit5(46, 48, 50, 52);
NixieDigit digit6(38, 40, 42, 44);
NixieGroup nixieGroup(&digit1, &digit2, &digit3, &digit4, &digit5, &digit6, 100);

const int inputPin = A0;
const int inputWindow = 100;
unsigned int inputSample;

void setup()
{
    Serial.begin(9600);
    digit1.initializePins();
    digit2.initializePins();
    digit3.initializePins();
    digit4.initializePins();
    digit5.initializePins();
    digit6.initializePins();

    pinMode(inputPin, INPUT);

}

void loop()
{
    unsigned long startMillis = millis();
    unsigned long currentMillis = startMillis;
    unsigned long lastRandMillis = startMillis;
    int period = 1000;
    int randPeirod = 60000;
    int sec, min,hour;
    int totalSec = 0;

    unsigned int inputMax = 0;
    unsigned int inputMin = 1024;

    int repeat = 0;
    bool soundOnFlag = true;
    
    while(1)
    {
        if(soundOnFlag)
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
            

        if((currentMillis - startMillis) >= period)
        {
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
            repeat = 0;

            startMillis = currentMillis;
            totalSec = startMillis/1000;
            sec = totalSec%60;
            min =(totalSec/60)%60;
            hour = totalSec/3600;
            nixieGroup.setTime(sec, min, hour);
            if((currentMillis - lastRandMillis) >= randPeirod && soundOnFlag)
            {
                nixieGroup.randPrintGroup();
                lastRandMillis = currentMillis;
            }
        }

        

        
    }    
}