#ifndef Magnetometer_H
#define Magnetometer_H

/* Setup the Magnetometer
*/
void setupMagnetometer();

/* Get the data from the magenetometer to get a heading
* @param debug_flag Set to true to print data to console, else set to false
* @return return the heading 0-360 degrees
*/
float getMagnetometerData(bool debug_flag);

#endif