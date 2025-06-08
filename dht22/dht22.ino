#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

unsigned long previousSensorRead = 0;
unsigned long previousDisplay = 0;

float lastHumidity = NAN;
float lastTemperature = NAN;

const unsigned long sensorInterval = 2000;  // interval baca sensor (ms)
const unsigned long displayInterval = 500;  // interval update tampilan (ms)

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  unsigned long currentMillis = millis();

  // Baca sensor tiap 2 detik
  if (currentMillis - previousSensorRead >= sensorInterval) {
    previousSensorRead = currentMillis;

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (!isnan(humidity) && !isnan(temperature)) {
      lastHumidity = humidity;
      lastTemperature = temperature;
    }
  }

  // Update tampilan tiap 500 ms dengan data terakhir
  if (currentMillis - previousDisplay >= displayInterval) {
    previousDisplay = currentMillis;

    if (isnan(lastHumidity) || isnan(lastTemperature)) {
      Serial.println("Data sensor belum valid.");
    } else {
      Serial.print("Kelembaban: ");
      Serial.print(lastHumidity);
      Serial.print(" %\t");
      Serial.print("Suhu: ");
      Serial.print(lastTemperature);
      Serial.println(" °C");
    }
  }
}
