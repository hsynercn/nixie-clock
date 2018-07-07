#include <Arduino.h>
#include "NixieDigit.h"
#include "NixieGroup.h"

NixieDigit digit1(23, 25, 27, 29);
NixieDigit digit2(31, 33, 35, 37);
NixieDigit digit3(39, 41, 43, 45);
NixieDigit digit4(47, 49, 51, 53);
NixieDigit digit5(46, 48, 50, 52);
NixieDigit digit6(38, 40, 42, 44);
NixieGroup nixieGroup(&digit1, &digit2, &digit3, &digit4, &digit5, &digit6, 2700);

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
    unsigned long currentMillis = startMillis;
    unsigned long lastRandMillis = startMillis;
    int period = 1000;
    int randPeirod = 20000;
    int sec, min,hour;
    int totalSec = 0;
    while(1)
    {
        
        nixieGroup.printGroup();

        currentMillis = millis();
        if((currentMillis - startMillis) >= period)
        {
            startMillis = currentMillis;
            totalSec = startMillis/1000;
            sec = totalSec%60;
            min =(totalSec/60)%60;
            hour = totalSec/3600;
            nixieGroup.setTime(sec, min, hour);
        }
        if((currentMillis - lastRandMillis) >= randPeirod)
        {
            nixieGroup.randPrintGroup();
            lastRandMillis = currentMillis;
        }
        
    }
}