/*--------------------------------------------------------------------
Name:   Brandon Ramos
Date:   7/26/2025
File:   Magnetometer functions

Doc:  oNLY
--------------------------------------------------------------------*/
#include <Adafruit_MMC56x3.h>
#include "Magnetometer.h"

//Magnetic offsets
#define OFFSET_X -62.28
#define OFFSET_y 140.35

/* Assign a unique ID to this sensor at the same time */
Adafruit_MMC5603 mmc = Adafruit_MMC5603(12345);

/******************************************************** 
* Initialize magnetometer
********************************************************/
void setupMagnetometer() {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit_MMC5603 Magnetometer Test");
  Serial.println("");

  /* Initialise the sensor */
  if (!mmc.begin(MMC56X3_DEFAULT_ADDRESS, &Wire)) {  // I2C mode
    /* There was a problem detecting the MMC5603 ... check your connections */
    Serial.println("Ooops, no MMC5603 detected ... Check your wiring!");
    while (1) delay(10);
  }

  /* Display some basic information on this sensor */
  mmc.printSensorDetails();
}

/******************************************************** 
* Read the contents from the magnetometer 
********************************************************/
float getMagnetometerData(bool debug_flag) {
  // Get a new sensor event 
  sensors_event_t event;
  mmc.getEvent(&event);

  if(debug_flag){
    // Display the results (magnetic vector values are in micro-Tesla (uT))
    // Serial.print("Uni:0.00,0.00,0.00,0.0000,0.0000,0.0000,");
    Serial.print("X: ");
    Serial.print(event.magnetic.x-OFFSET_X);
    Serial.print(" ,");
    Serial.print("Y: ");
    Serial.print(event.magnetic.y-OFFSET_y);
    Serial.print(" ,");
    Serial.print("Z: ");
    Serial.print(event.magnetic.z); //Not used 
  }
  
  //Calculate angle
  float Pi = 3.14159;
  float mag_y = event.magnetic.y-OFFSET_y;
  float mag_x = event.magnetic.x-OFFSET_X;

  // Calculate the heading given that X is the heading
  float heading = (atan2(mag_x,mag_y) * 180) / Pi;

  // Normalize to 0-360
  if (heading < 0){
    heading = 360 + heading;
  }

  if(debug_flag){
    Serial.print(" Compass Heading: ");
    Serial.println(heading);
  }

  // Delay before the next sample
  delay(10);

  return heading;
}