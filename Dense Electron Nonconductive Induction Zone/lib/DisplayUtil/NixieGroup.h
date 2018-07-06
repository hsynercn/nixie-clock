/*
  NixieGroup.h - Library for 6 nixie digit display
  control.
*/
#ifndef NixieClockGroup_h
#define NixieClockGroup_h

#include "Arduino.h"
#include "NixieDigit.h"

class NixieGroup
{
  public:
    NixieGroup(int pinA, int pinB, int pinC, int pinD);
    void initializePins();
    void clearAll();
    void printDecGroup();

  private:
    NixieDigit _nixDigits[6];
    int _digitCount = 6;
};

#endif
