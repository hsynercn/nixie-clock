/*
  NixieDigit.h - Library for 4 pin encoded nixie display
  control.
*/
#ifndef NixieDigit_h
#define NixieDigit_h

#include "Arduino.h"

class NixieDigit
{
  public:
    NixieDigit(int pinA, int pinB, int pinC, int pinD);
    void initializePins();
    void clear();
    void printDecNum(int number);

  private:
    int pins[4];
    int pinCount = 4;
    int base = 10;
};

#endif