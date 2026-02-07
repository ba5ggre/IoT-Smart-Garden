#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define TDS_PIN 34
#define LDR_PIN 35

DHT dht(DHTPIN, DHTTYPE);

struct GardenData {
  float t;
  float h;
  int l;
  int tds;
};

void initSensors() {
  dht.begin();
  pinMode(TDS_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
}

GardenData readSensors() {
  GardenData data;
  data.t = dht.readTemperature();
  data.h = dht.readHumidity();
  data.l = analogRead(LDR_PIN);
  data.tds = analogRead(TDS_PIN); 
  return data;
}