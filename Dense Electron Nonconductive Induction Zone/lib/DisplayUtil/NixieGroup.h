/*
  NixieGroup.h - Library for 6 nixie digit display
  control.
*/
#ifndef NixieGroup_h
#define NixieGroup_h

#include "Arduino.h"
#include "NixieDigit.h"
#include "SoundSensor.h"

class NixieGroup
{
public:
  NixieGroup(NixieDigit *digit1,
             NixieDigit *digit2,
             NixieDigit *digit3,
             NixieDigit *digit4,
             NixieDigit *digit5,
             NixieDigit *digit6,
             int frameMicrosecond);
  void initializeDigits();
  void clearAll();
  void setTime(int sec,int min,int hour);
  unsigned int printGroup(int inputPin);
  void randPrintGroup();
  void setSoundSensor(SoundSensor *soundSensor);

private:
  NixieDigit *nixieDigits[6];
  int digitCount = 6;
  int digitVals[6];
  int frameMicrosecond = 2700000000;
  int antiPoisonSec = 10;
  int antiPoisonIntervalMilisec = 200;
  SoundSensor *soundSensor;
};

#endif
