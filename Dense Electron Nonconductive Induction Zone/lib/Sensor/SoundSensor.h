
#ifndef SoundSensor_h
#define SoundSensor_h

#include "Arduino.h"
#include "SoundSensor.h"

class SoundSensor
{
public:
  SoundSensor(int inputPin);
  void initializeSensor();
  void read();
  void reset();
  unsigned int getMinMaxDiff();
  bool isUserCmdReceived();

private:
  int inputPin;
  unsigned int minMaxDiff;
  unsigned int minSample;
  unsigned int maxSample;
  unsigned int thresholdLimit = 100;
};

#endif
