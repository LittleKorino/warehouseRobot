#ifndef WEBSERVER_HANDLER_H
#define WEBSERVER_HANDLER_H

#include <WiFi.h>
#include <WebServer.h>
#include "Motor.h"
#include "Rotor.h"

class WebServerHandler {
private:
  WebServer server;
  const char* ssid;
  const char* password;
  Motor* motorA;
  Motor* motorB;
  Rotor* rotor;

  static const char MAIN_page[];

public:
  WebServerHandler(const char* ssid, const char* password,
                   Motor* motorA, Motor* motorB, Rotor* rotor);
  void begin();
  void handleClient();
};

#endif
