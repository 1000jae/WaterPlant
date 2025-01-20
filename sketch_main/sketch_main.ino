// for the WiFi module
#include <ESP8266WiFi.h>

// define soil moisture sensor pin
#define sensorPin A0



void setup() {
  // start serial monitor (for testing)
  Serial.begin(9600);
  // 
  int notified = 0;
}

void loop() {
  // read the soil moisture sensor
  int value = getSensorVal();
  // if the soil moisture sensor states that the soil is not moist enough
  // send an alert to phone
  if (value < 400){
    if (notified == 0){
      notified = 1;
      // print on serial monitor
      Serial.println("Dry");
    }
    else{
      Serial.println("Dry Notified");
    }
  }
  
  else if (value >= 400 && notified == 1){
    Serial.println("Watered");
    notified = 0;
  }

  Serial.println("Moist");
}


void getSensorVal(){
  /*
    Function to read the soil moisture from the sensor and return the moisture value. 
    https://projecthub.arduino.cc/Aswinth/soil-moisture-sensor-with-arduino-91c818
  */

  // read the sensor value
  int value = analogRead(sensorPin);

  // map the value read from the sensor
  int result = map(value, 0, 1023, 255, 0);

  return result;
}
