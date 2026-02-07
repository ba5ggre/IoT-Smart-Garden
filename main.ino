#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "web_pages.h"
#include "sensor_modules.h"
#include "servo_control.h"

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

AsyncWebServer server(80);
GardenData currentData;
int servoPos = 0;

String processor(const String& var){
  if(var == "TEMP") return String(currentData.t, 1);
  if(var == "HUMI") return String(currentData.h, 1);
  if(var == "LIGHT") return String(currentData.l);
  if(var == "TDS") return String(currentData.tds);
  if(var == "SERVO_POS") return String(servoPos);
  return String();
}

void setup(){
  Serial.begin(115200);
  initSensors();
  initServo();
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(1000); Serial.println("Connecting..."); }
  Serial.print("IP Address: "); Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  server.on("/servo", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("value")) {
      servoPos = request->getParam("value")->value().toInt();
      moveShield(servoPos);
    }
    request->send(200, "text/plain", "OK");
  });

  server.begin();
}

void loop(){
  currentData = readSensors();
  
  // Logic tự động dựa trên ánh sáng (Nếu không có điều khiển từ Web)
  // int autoAngle = map(currentData.l, 0, 4095, 0, 180);
  // moveShield(autoAngle);
  
  delay(2000);
}