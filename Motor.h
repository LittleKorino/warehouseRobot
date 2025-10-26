#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
private:
  int in1, in2, pwm;

public:
  Motor(int pin_in1, int pin_in2, int pin_pwm);
  void forward(int speed);
  void backward(int speed);
  void stop();
  void brake();
};

#endif
