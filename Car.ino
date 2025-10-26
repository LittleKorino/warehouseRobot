#include "Motor.h"
#include "Rotor.h"
#include "WebServerHandler.h"

// Pin configuration
#define AIN1 27
#define AIN2 14
#define PWMA 32
#define BIN1 25
#define BIN2 33
#define PWMB 13
#define STBY 26
#define ROT 12

// Wi-Fi credentials
const char* ssid = "ESP32-Car";
const char* password = "12345678";

// Motor and Rotor objects
Motor motorA(AIN1, AIN2, PWMA);
Motor motorB(BIN1, BIN2, PWMB);
Rotor rotorA(ROT);

// Web server handler
WebServerHandler webServer(ssid, password, &motorA, &motorB, &rotorA);

void setup() {
  Serial.begin(115200);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
  webServer.begin();
}

void loop() {
  webServer.handleClient();
}
