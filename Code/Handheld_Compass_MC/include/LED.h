#ifndef LED_H
#define LED_H

/* Setup the LEDs
*/
void setupLED();

/* Test all LEDs in array one-by-one to ensure all are functional
 */
void testLED();

/* Given the compass heading, display the head appropriately with the LEDs
 * @param heading The heading given between 0 - 360 degrees
 */
void compassHead(float heading);

#endif