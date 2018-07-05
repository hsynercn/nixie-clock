#include <Arduino.h>
#include "NixieDigit.h"

NixieDigit digit1(23, 25, 27, 29);
NixieDigit digit2(31, 33, 35, 37);
NixieDigit digit3(39, 41, 43, 45);
NixieDigit digit4(47, 49, 51, 53);
NixieDigit digit5(46, 48, 50, 52);
NixieDigit digit6(38, 40, 42, 44);

void setup()
{
    Serial.begin(9600);
    digit1.initializePins();
    digit2.initializePins();
    digit3.initializePins();
    digit4.initializePins();
    digit5.initializePins();
    digit6.initializePins();
}

void loop()
{
    unsigned long startMillis = millis();
    unsigned long currentMillis;
    int time = 2700;
    int period = 1000;
    Serial.print("LOOP");
    int i = 0;
    while(1)
    {
        digit1.printDecNum(i);
        delayMicroseconds(time);
        digit1.clear();
        
        digit2.printDecNum(i);
        delayMicroseconds(time);
        digit2.clear();
        
        digit3.printDecNum(i);
        delayMicroseconds(time);
        digit3.clear();

        digit4.printDecNum(i);
        delayMicroseconds(time);
        digit4.clear();

        digit5.printDecNum(i);
        delayMicroseconds(time);
        digit5.clear();

        digit6.printDecNum(i);
        delayMicroseconds(time);
        digit6.clear();

        currentMillis = millis();
        if(currentMillis - startMillis >= period)
        {
            startMillis = currentMillis;
            i++;
            i %= 10;
        }
        
    }
}