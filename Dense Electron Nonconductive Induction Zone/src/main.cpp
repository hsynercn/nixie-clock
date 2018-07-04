#include <Arduino.h>
#include "NixieDigit.h"

NixieDigit digit1(23, 25, 27, 29);

void setup()
{
    Serial.begin(9600);
    digit1.initializePins();
}

void loop()
{
    Serial.print("LOOP");
    for(int i=0;i<10;i++)
    {
        digit1.printDecNum(i);
        delay(20);
    }
}