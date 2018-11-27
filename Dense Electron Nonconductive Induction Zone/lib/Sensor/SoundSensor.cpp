#include "SoundSensor.h"

SoundSensor::SoundSensor(int inputPin)
{
    this->inputPin = inputPin;
}

void SoundSensor::initializeSensor()
{
    pinMode(this->inputPin, INPUT);
}

void SoundSensor::reset()
{
    this->minMaxDiff = 0;
    this->minSample = 1024;
    this->maxSample = 0;
}

void SoundSensor::read()
{
    int inputSample = analogRead(this->inputPin);
    if(this->minSample>inputSample)
    {
        this->minSample = inputSample;
    }
    if(this->maxSample<inputSample)
    {
        this->maxSample = inputSample;
    }
    if((maxSample-minSample) > this->minMaxDiff)
    {
        this->minMaxDiff = maxSample-minSample;
    }
}

unsigned int SoundSensor::getMinMaxDiff()
{
    return this->minMaxDiff;
}

bool SoundSensor::isUserCmdReceived()
{
    if(this->minMaxDiff >= this->thresholdLimit)
    {
        return true;
    }
    else
    {
        return false;
    }
}