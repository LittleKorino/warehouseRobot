#include "WebServerHandler.h"

const char WebServerHandler::MAIN_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <title>ESP32 Car Control</title>
    <style>
      button { width:100px; height:50px; font-size:18px; margin:10px; }
    </style>
  </head>
  <body style="text-align:center; font-family:Arial;">
    <h2>ESP32 WiFi Car</h2>
    <button onmousedown="fetch('/forward')" onmouseup="fetch('/stop')">Forward</button><br>
    <button onmousedown="fetch('/left')" onmouseup="fetch('/stop')">Left</button>
    <button onmousedown="fetch('/stop')">Stop</button>
    <button onmousedown="fetch('/right')" onmouseup="fetch('/stop')">Right</button><br>
    <button onmousedown="fetch('/backward')" onmouseup="fetch('/brake')">Backward</button>
  </body>
</html>
)rawliteral";

WebServerHandler::WebServerHandler(const char* ssid_, const char* password_,
                                   Motor* mA, Motor* mB, Rotor* rot)
  : server(80), ssid(ssid_), password(password_),
    motorA(mA), motorB(mB), rotor(rot) {}

void WebServerHandler::begin() {
  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started");
  Serial.print("SSID: "); Serial.println(ssid);
  Serial.print("IP Address: "); Serial.println(WiFi.softAPIP());

  server.on("/", [this]() {
    server.send(200, "text/html", MAIN_page);
  });

  server.on("/forward", [this]() {
    motorA->forward(255); motorB->forward(255);
    server.send(200, "text/plain", "Forward");
  });
  server.on("/backward", [this]() {
    motorA->backward(255); motorB->backward(255);
    server.send(200, "text/plain", "Backward");
  });
  server.on("/left", [this]() {
    motorA->forward(255); motorB->backward(255);
    server.send(200, "text/plain", "Left");
  });
  server.on("/right", [this]() {
    motorA->backward(255); motorB->forward(255);
    server.send(200, "text/plain", "Right");
  });
  server.on("/stop", [this]() {
    motorA->stop(); motorB->stop();
    server.send(200, "text/plain", "Stopped");
  });
  server.on("/brake", [this]() {
    motorA->brake(); motorB->brake();
    server.send(200, "text/plain", "Brake");
  });

  server.begin();
  Serial.println("HTTP server started");
}

void WebServerHandler::handleClient() {
  server.handleClient();
}
