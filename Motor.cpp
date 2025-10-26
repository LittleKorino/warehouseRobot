#include "Motor.h"

Motor::Motor(int pin_in1, int pin_in2, int pin_pwm) {
  in1 = pin_in1;
  in2 = pin_in2;
  pwm = pin_pwm;
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(pwm, OUTPUT);
}

void Motor::forward(int speed) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(pwm, constrain(speed, 0, 255));
}

void Motor::backward(int speed) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwm, constrain(speed, 0, 255));
}

void Motor::stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(pwm, 0);
}

void Motor::brake() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  analogWrite(pwm, 0);
}
