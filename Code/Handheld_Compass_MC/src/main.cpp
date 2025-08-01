/*--------------------------------------------------------------------
Name:   Brandon Ramos
Date:   7/26/2025
File:   Minecraft Compass main file

Doc:  
--------------------------------------------------------------------*/
#include <Arduino.h>
#include "LED.h"
#include "Magnetometer.h"

void setup() { 
  setupLED();
  setupMagnetometer();
}

void loop() { 
  //get compass heading and use the LEDs to display north
  float heading = getMagnetometerData(false);
  compassHead(heading);

  //refresh every 0.2ms
  delay(200);
}