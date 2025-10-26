#include "Rotor.h"

Rotor::Rotor(int pwmpin) {
  pwm = pwmpin;
  pinMode(pwm, OUTPUT);
}

void Rotor::setSpeed(int speed) {
  analogWrite(pwm, map(speed, 0, 255, 128, 255));
}
