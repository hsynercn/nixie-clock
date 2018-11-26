#include "NixieDigit.h"

NixieDigit::NixieDigit(int pinA, int pinB, int pinC, int pinD)
{
    this->pins[3] = pinA;
    this->pins[2] = pinB;
    this->pins[1] = pinC;
    this->pins[0] = pinD;

}

void NixieDigit::initializePins()
{
    Serial.println("OUTPUT");
    for (int i = 0; i < this->pinCount; i++)
    {
        Serial.println(this->pins[i]);
        pinMode(this->pins[i], OUTPUT);
        digitalWrite(this->pins[i], LOW);
    }
}

void NixieDigit::clear()
{
    digitalWrite(this->pins[3], HIGH);
    digitalWrite(this->pins[2], HIGH);
    digitalWrite(this->pins[1], HIGH);
    digitalWrite(this->pins[0], HIGH);
}

void NixieDigit::printDecNum(int number)
{
    
    int num = number % 10;    
    if(num == 0)
    {
        digitalWrite(this->pins[3], LOW);
        digitalWrite(this->pins[2], LOW);
        digitalWrite(this->pins[1], LOW);
        digitalWrite(this->pins[0], LOW);
        return;
    }
    if(num == 1)
    {
        digitalWrite(this->pins[3], LOW);
        digitalWrite(this->pins[2], LOW);
        digitalWrite(this->pins[1], LOW);
        digitalWrite(this->pins[0], HIGH);
        return;
    }
    if(num == 2)
    {
        digitalWrite(this->pins[3], LOW);
        digitalWrite(this->pins[2], LOW);
        digitalWrite(this->pins[1], HIGH);
        digitalWrite(this->pins[0], LOW);
        return;
    }
    if(num == 3)
    {
        digitalWrite(this->pins[3], LOW);
        digitalWrite(this->pins[2], LOW);
        digitalWrite(this->pins[1], HIGH);
        digitalWrite(this->pins[0], HIGH);
        return;
    }
    if(num == 4)
    {
        digitalWrite(this->pins[3], LOW);
        digitalWrite(this->pins[2], HIGH);
        digitalWrite(this->pins[1], LOW);
        digitalWrite(this->pins[0], LOW);
        return;
    }
    if(num == 5)
    {
        digitalWrite(this->pins[3], HIGH);
        digitalWrite(this->pins[2], LOW);
        digitalWrite(this->pins[1], LOW);
        digitalWrite(this->pins[0], LOW);
        return;
    }
    if(num == 6)
    {
        digitalWrite(this->pins[3], HIGH);
        digitalWrite(this->pins[2], LOW);
        digitalWrite(this->pins[1], LOW);
        digitalWrite(this->pins[0], HIGH);
        return;
    }
    if(num == 7)
    {
        digitalWrite(this->pins[3], HIGH);
        digitalWrite(this->pins[2], LOW);
        digitalWrite(this->pins[1], HIGH);
        digitalWrite(this->pins[0], LOW);
        return;
    }
    if(num == 8)
    {
        digitalWrite(this->pins[3], HIGH);
        digitalWrite(this->pins[2], LOW);
        digitalWrite(this->pins[1], HIGH);
        digitalWrite(this->pins[0], HIGH);
        return;
    }
    if(num == 9)
    {
        digitalWrite(this->pins[3], HIGH);
        digitalWrite(this->pins[2], HIGH);
        digitalWrite(this->pins[1], LOW);
        digitalWrite(this->pins[0], LOW);
        return;
    }
}
