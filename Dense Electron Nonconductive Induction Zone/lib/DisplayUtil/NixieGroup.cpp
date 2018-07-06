#include "NixieGroup.h"

NixieGroup::NixieGroup( NixieDigit *digit1, 
                        NixieDigit *digit2,
                        NixieDigit *digit3,
                        NixieDigit *digit4,
                        NixieDigit *digit5,
                        NixieDigit *digit6,
                        int frameMicrosecond)
{
    this->nixieDigits[0] = digit1;
    this->nixieDigits[1] = digit2;
    this->nixieDigits[2] = digit3;
    this->nixieDigits[3] = digit4;
    this->nixieDigits[4] = digit5;
    this->nixieDigits[5] = digit6;
    this->frameMicrosecond = frameMicrosecond;
}

void NixieGroup::initializePins()
{
    for(int i=0;i<this->digitCount;i++)
    {
        this->nixieDigits[0]->initializePins();
    }
}

void NixieGroup::clearAll()
{
    for(int i=0;i<this->digitCount;i++)
    {
        this->nixieDigits[i]->clear();
    }
}

void NixieGroup::setTime(int sec,int min,int hour)
{
    this->digitVals[0] = sec%10;
    this->digitVals[1] = sec/10;
    this->digitVals[2] = min%10;
    this->digitVals[3] = min/10;
    this->digitVals[4] = hour%10;
    this->digitVals[5] = hour/10;
}

void NixieGroup::printGroup()
{
    for(int i=0;i<this->digitCount;i++)
    {
        this->nixieDigits[i]->printDecNum(this->digitVals[i]);
        delayMicroseconds(this->frameMicrosecond);
        this->nixieDigits[i]->clear();
    }
}