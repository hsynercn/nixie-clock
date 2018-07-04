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
        digitalWrite(this->_pins[3], LOW);
    }
}

void NixieDigit::printDecNum(int number)
{
    int num = number % 10;

    if (num >= 5)
        digitalWrite(this->_pins[_pinCount - 1], HIGH);
    else
        digitalWrite(this->_pins[_pinCount - 1], LOW);

    num = num % 5;
    num++;

    digitalWrite(this->_pins[0], (num % 2) ? HIGH : LOW);
    num = num / 2;
    digitalWrite(this->_pins[1], (num % 2) ? HIGH : LOW);
    num = num / 2;
    digitalWrite(this->_pins[2], (num % 2) ? HIGH : LOW);
}