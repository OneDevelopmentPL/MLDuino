#include <Arduino.h>
#include "model.h"

constexpr uint8_t LED_INDICATOR_PIN = 13;
constexpr uint8_t SENSOR_PINS[] = {A0, A1, A2};
constexpr uint8_t NUM_FEATURES = sizeof(SENSOR_PINS) / sizeof(SENSOR_PINS[0]);
constexpr uint32_t BAUD_RATE = 115200;
constexpr float ADC_MAX = 1023.0f;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(LED_INDICATOR_PIN, OUTPUT);
  digitalWrite(LED_INDICATOR_PIN, LOW);
  
  Serial.println("TinyML Launcher initialized.");
}

void loop() {
  float features[NUM_FEATURES];
  
  for (uint8_t i = 0; i < NUM_FEATURES; i++) {
    features[i] = analogRead(SENSOR_PINS[i]) / ADC_MAX;
  }
  
  int prediction = run_model(features);
  
  digitalWrite(LED_INDICATOR_PIN, (prediction == 1) ? HIGH : LOW);
  
  delay(50);
}
