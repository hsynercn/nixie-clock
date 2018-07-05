#include "NixieDigit.h"

NixieDigit::NixieDigit(int pinA, int pinB, int pinC, int pinD)
{
    this->_pins[0] = pinA;
    this->_pins[1] = pinB;
    this->_pins[2] = pinC;
    this->_pins[3] = pinD;

}

void NixieDigit::initializePins()
{
    for (int i = 0; i < this->_pinCount; i++)
    {
        pinMode(this->_pins[i], OUTPUT);
        digitalWrite(this->_pins[3], LOW);
    }
}

void NixieDigit::clear()
{
    for (int i = 0; i < this->_pinCount; i++)
    {
        digitalWrite(this->_pins[i], LOW);
    }
}

void NixieDigit::printDecNum(int number)
{
    int num = number % 10;    
    digitalWrite(this->_pins[this->_pinCount - 1], (num / 5) ? HIGH : LOW);
    
    num %= 5;
    num++;
    
    for(int i = 0 ; i < this->_pinCount - 1 ; i++)
    {
        digitalWrite(this->_pins[i], (num % 2) ? HIGH : LOW);    
        num = num / 2;
    }
}
