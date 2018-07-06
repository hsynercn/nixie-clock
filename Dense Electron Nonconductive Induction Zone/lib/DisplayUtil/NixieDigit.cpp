#include "NixieDigit.h"

NixieDigit::NixieDigit(int pinA, int pinB, int pinC, int pinD)
{
    this->pins[0] = pinA;
    this->pins[1] = pinB;
    this->pins[2] = pinC;
    this->pins[3] = pinD;

}

void NixieDigit::initializePins()
{
    for (int i = 0; i < this->pinCount; i++)
    {
        pinMode(this->pins[i], OUTPUT);
        digitalWrite(this->pins[3], LOW);
    }
}

void NixieDigit::clear()
{
    for (int i = 0; i < this->pinCount; i++)
    {
        digitalWrite(this->pins[i], LOW);
    }
}

void NixieDigit::printDecNum(int number)
{
    int num = number % 10;    
    digitalWrite(this->pins[this->pinCount - 1], (num / 5) ? HIGH : LOW);
    
    num %= 5;
    num++;
    
    for(int i = 0 ; i < this->pinCount - 1 ; i++)
    {
        digitalWrite(this->pins[i], (num % 2) ? HIGH : LOW);    
        num = num / 2;
    }
}
