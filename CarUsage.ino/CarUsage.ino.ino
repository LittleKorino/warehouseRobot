// =============================================
// TB6612FNG Dual Motor Control (ESP32)
// Class-based version by Master Korino
// =============================================

class Motor {
private:
  int in1, in2, pwm; // control pins

public:
  // Constructor
  Motor(int pin_in1, int pin_in2, int pin_pwm) {
    in1 = pin_in1;
    in2 = pin_in2;
    pwm = pin_pwm;
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(pwm, OUTPUT);
  }

  // Move motor forward at given speed (0–255)
  void forward(int speed) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(pwm, constrain(speed, 0, 255));
  }

  // Move motor backward at given speed (0–255)
  void backward(int speed) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(pwm, constrain(speed, 0, 255));
  }

  // Stop motor
  void stop() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(pwm, 0);
  }

  // Brake motor (quick stop)
  void brake() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    analogWrite(pwm, 0);
  }
};

class Rotor {

private:
  int pwm;
  int speed;
public:
  Rotor(int pwmpin){
    pwm = pwmpin;
    speed = 0;
    pinMode(pwm,OUTPUT);
  }

  void setSpeed(int speed){
    analogWrite(pwm,speed);
  }
};

// --- Pin configuration for TB6612FNG ---
#define AIN1 27
#define AIN2 14
#define PWMA 32
#define BIN1 25
#define BIN2 33
#define PWMB 13
#define STBY 26
#define ROT 12

// Create two motor objects
Motor motorA(AIN1, AIN2, PWMA); //Right
Motor motorB(BIN1, BIN2, PWMB); //Left
Rotor rotorA(ROT);

void setup() {
  Serial.begin(115200);
  Serial.println("TB6612FNG Motor Class Test - Master Korino");

  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);  // enable motors
}

void loop() {
  /*
  Serial.println("Forward");
  motorA.forward(128);
  motorB.forward(128);
  delay(2000);

  Serial.println("Backward");
  motorA.backward(128);
  motorB.backward(128);
  delay(2000);

  Serial.println("Left Spin");
  motorA.forward(255);
  motorB.backward(255);
  delay(2000);

  Serial.println("Right Spin");
  motorA.backward(255);
  motorB.forward(255);
  delay(2000);

  Serial.println("Stop");
  motorA.stop();
  motorB.stop();
  delay(2000);
  */
  // rotorA.setSpeed(128);
  // delay(2000);
  // rotorA.setSpeed(255);
  // delay(2000);
  // rotorA.setSpeed(128);
  // delay(2000);
  // rotorA.setSpeed(0);
  // delay(2000);

}
