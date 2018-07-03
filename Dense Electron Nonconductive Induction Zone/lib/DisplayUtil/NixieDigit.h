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
    int _pins[4];
    int _pinCount = 4;
    int _base = 10;
};

#endif