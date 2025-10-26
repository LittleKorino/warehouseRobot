#ifndef ROTOR_H
#define ROTOR_H

#include <Arduino.h>

class Rotor {
private:
  int pwm;
public:
  Rotor(int pwmpin);
  void setSpeed(int speed);
};

#endif
