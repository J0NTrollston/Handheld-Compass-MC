/*--------------------------------------------------------------------
Name:   Brandon Ramos
Date:   7/26/2025
File:   LED functions

Doc:  Below is the LED array where 21 is the center 

->       [38] [39] [40] [41] [42] [43] [44] [45] [46]
    [37] [36] [35] [34] [33] [32] [31] [30] [29] [28] [27]  <-
->  [16] [17] [18] [19] [20] [21] [22] [23] [24] [25] [26]
    [15] [14] [13] [12] [11] [10] [09] [08] [07] [06]       <-
->            [00] [01] [02] [03] [04] [05]
--------------------------------------------------------------------*/
#include <FastLED.h>
#include "LED.h"

// How many leds in your strip?
#define NUM_LEDS 47

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN. 
#define DATA_PIN 7
#define COLOR_ORDER  GRB //Is GRB but can also be RGB

// Define the array of leds
CRGB leds[NUM_LEDS];

/******************************************************** 
* Setup to describe the model, pin and color for the led array
********************************************************/
void setupLED(){
    FastLED.addLeds<WS2812, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);  // GRB ordering is typical
}

/******************************************************** 
* Test all LEDs one at a time 
* Test the Compass Head pointing up
********************************************************/
void testLED(){
  // Turn the LED on, then pause
  for(int i = 0; i<NUM_LEDS; i++){
    // Test LED
    leds[i] = CRGB::Green;
    // Turn the previous LED off. If i starts over then turn the last LED off.
    if(i == 0 ){
      leds[NUM_LEDS-1] = CRGB::Black;
    }else{
      leds[i-1] = CRGB::Black;
    }
  }
}

/******************************************************** 
* Turn off LEDs before displaying next direction
********************************************************/
static void turnOffAllLEDS(){
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Black;
  }
}

/******************************************************** 
* Given a heading from 0-360 degrees, display the LED array to show north
********************************************************/
void compassHead(float heading){

  if((360-heading) > 349.0 or (360-heading) <= 191.0){
    /*
     Reason for taking the difference in 360 degrees and the heading is to 
     account for how I measured the compass heading. I measured the angle of 
     the compass head to where it was pointing in reference to the top of the 
     compass being 0,360 degrees. Because of this, when you actually use it 
     you will need to offset by taking (360-heading) to display magnetic north.     
  */
    heading = 360 - heading;

    // If pointing North
    //  xxxxRxxxx    
    // xxxxxRxxxxx   
    // xxxxGRGxxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    if(heading > 349.0 or heading <= 11.6){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[42] = CRGB::Red;

        leds[32] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;

        leds[10] = CRGB::Gray;
        
        FastLED.show();
    }

    // Step 1
    //  xxxxRRxxx    
    // xxxxxRxxxxx   
    // xxxxGRGxxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 11.6 and heading <= 18.9){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[42] = CRGB::Red;
        leds[43] = CRGB::Red;

        leds[32] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;

        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step 2
    //  xxxxxRxxx    
    // xxxxxRxxxxx   
    // xxxxGRGxxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 18.9 and heading <= 19.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[43] = CRGB::Red;

        leds[32] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;

        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step 3
    //  xxxxxRxxx    
    // xxxxxRRxxxx   
    // xxxxGRGxxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 19.1 and heading <= 20.6){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[43] = CRGB::Red;

        leds[32] = CRGB::Red;
        leds[31] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;

        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step 4
    //  xxxxxRxxx    
    // xxxxxRRxxxx   
    // xxxxGRGxxxx   
    // xxxxGGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 20.6 and heading <= 33.4){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[43] = CRGB::Red;

        leds[32] = CRGB::Red;
        leds[31] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Gray;
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step 5
    //  xxxxxRRxx    
    // xxxxxRRxxxx   
    // xxxxGRGxxxx   
    // xxxxGGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 33.4 and heading <= 45){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[43] = CRGB::Red;
        leds[44] = CRGB::Red;

        leds[32] = CRGB::Red;
        leds[31] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Gray;
        leds[10] = CRGB::Gray;

        FastLED.show();
    }
    
    // Step 6
    //  xxxxxxRxx    
    // xxxxxxRxxxx   
    // xxxxGRGxxxx   
    // xxxxGxxxxxX   
    //  XxxxxxxXX 
    else if(heading > 45 and heading <= 45.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[44] = CRGB::Red;

        leds[31] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Gray;

        FastLED.show();
    }

    // Step 7
    //  xxxxxxRxx    
    // xxxxxxRRxxx   
    // xxxxGRGxxxx   
    // XxxxGxxxxxx   
    //  XXxxxxxxX 
    else if(heading > 45.2 and heading <= 51.5){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[44] = CRGB::Red;

        leds[31] = CRGB::Red;
        leds[30] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Gray;

        FastLED.show();
    }

    // Step 8
    //  xxxxxxRRx    
    // xxxxxxRRxxx   
    // xxxxGRGxxxx   
    // XxxxGxxxxxx   
    //  XXxxxxxxX 
    else if(heading > 51.5 and heading <= 54.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[44] = CRGB::Red;
        leds[45] = CRGB::Red;

        leds[31] = CRGB::Red;
        leds[30] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Gray;

        FastLED.show();
    }

    // Step 9
    //  xxxxxxRRx    
    // xxxxxxRRxxx   
    // xxxxGRRxxxx   
    // xxxxGxxxxxX   
    //  XxxxxxxXX 
    else if(heading > 54.8 and heading <= 57.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[44] = CRGB::Red;
        leds[45] = CRGB::Red;

        leds[31] = CRGB::Red;
        leds[30] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        
        leds[11] = CRGB::Gray;

        FastLED.show();
    }

    // Step 10
    //  xxxxxxRRx    
    // xxxxxxRRxxx   
    // xxxxGRRxxxx   
    // xxxGGxxxxxX   
    //  XxxxxxxXX 
    else if(heading > 57.2 and heading <= 59.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[44] = CRGB::Red;
        leds[45] = CRGB::Red;

        leds[31] = CRGB::Red;
        leds[30] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        
        leds[12] = CRGB::Gray;
        leds[11] = CRGB::Gray;

        FastLED.show();
    }
    
    // Step 11
    //  xxxxxxxRx    
    // xxxxxxRRRxx   
    // xxxxGRRxxxx   
    // xxxGGxxxxxX   
    //  XxxxxxxXX 
    else if(heading > 59.2 and heading <= 65.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[45] = CRGB::Red;

        leds[31] = CRGB::Red;
        leds[30] = CRGB::Red;
        leds[29] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        
        leds[12] = CRGB::Gray;
        leds[11] = CRGB::Gray;

        FastLED.show();
    }

    // Step 12
    //  xxxxxxxRR    
    // xxxxxxRRRxx   
    // xxxxGRRxxxx   
    // xxxGGxxxxxX   
    //  XxxxxxxXX 
    else if(heading > 65.1 and heading <= 66.7){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[45] = CRGB::Red;
        leds[46] = CRGB::Red;

        leds[31] = CRGB::Red;
        leds[30] = CRGB::Red;
        leds[29] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        
        leds[12] = CRGB::Gray;
        leds[11] = CRGB::Gray;

        FastLED.show();
    }

    // Step 13
    //  xxxxxxxxR    
    // xxxxxxRRRxx   
    // xxxxGRRxxxx   
    // xxxGGxxxxxX   
    //  XxxxxxxXX 
    else if(heading > 66.7 and heading <= 66.9){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[46] = CRGB::Red;

        leds[31] = CRGB::Red;
        leds[30] = CRGB::Red;
        leds[29] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        
        leds[12] = CRGB::Gray;
        leds[11] = CRGB::Gray;

        FastLED.show();
    }

    // Step 14
    //  xxxxxxxxx    
    // xxxxxxRRRRx   
    // xxxxGRRxxxx   
    // xxxGGxxxxxX   
    //  XxxxxxxXX 
    else if(heading > 66.9 and heading <= 71.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[31] = CRGB::Red;
        leds[30] = CRGB::Red;
        leds[29] = CRGB::Red;
        leds[28] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        
        leds[12] = CRGB::Gray;
        leds[11] = CRGB::Gray;

        FastLED.show();
    }

    // Step 15
    //  xxxxxxxxx    
    // xxxxGxxRRRx   
    // xxxGGRRRxxx   
    // xxxGxxGxxxX   
    //  XxxxxxxXX 
    else if(heading > 71.8 and heading <= 76.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[33] = CRGB::Gray;
        leds[30] = CRGB::Red;
        leds[29] = CRGB::Red;
        leds[28] = CRGB::Red;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        
        leds[12] = CRGB::Gray;
        leds[9] = CRGB::Gray;

        FastLED.show();
    }

    // Step 16
    //  xxxxxxxxx    
    // xxxxxGxRRRx   
    // xxxGGRRRxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 76.1 and heading <= 78.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[30] = CRGB::Red;
        leds[29] = CRGB::Red;
        leds[28] = CRGB::Red;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step 17
    //  xxxxxxxxx    
    // xxxxxGxxRRx   
    // xxxGGRRRRxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 78.8 and heading <= 79.0){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[29] = CRGB::Red;
        leds[28] = CRGB::Red;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        leds[24] = CRGB::Red;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step 18
    //  xxxxxxxxx    
    // xxxxxGxxRRR   
    // xxxGGRRRRxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 79.0 and heading <= 81.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[29] = CRGB::Red;
        leds[28] = CRGB::Red;
        leds[27] = CRGB::Red;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        leds[24] = CRGB::Red;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step 19
    //  xxxxxxxxx    
    // xxxxxGxxxRR   
    // xxxGGRRRRxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 81.8 and heading <= 82.0){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[28] = CRGB::Red;
        leds[27] = CRGB::Red;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        leds[24] = CRGB::Red;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step 20
    //  xxxxxxxxx    
    // xxxxxGxxxRR   
    // xxxGGRRRRRx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 82.0 and heading <= 83.6){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[28] = CRGB::Red;
        leds[27] = CRGB::Red;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        leds[24] = CRGB::Red;
        leds[25] = CRGB::Red;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step 21
    //  xxxxxxxxx    
    // xxxxxGxxxxR   
    // xxxGGRRRRRx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 83.6 and heading <= 83.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[27] = CRGB::Red;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        leds[24] = CRGB::Red;
        leds[25] = CRGB::Red;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step 22 (East)
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxGGRRRRRR   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 83.8 and heading <= 96.3){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        leds[24] = CRGB::Red;
        leds[25] = CRGB::Red;
        leds[26] = CRGB::Red;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Not used
    // Step 23
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxGGRRRRRx   
    // xxxxxGxxxxr   
    //  XxxxxxxXX 

    // Step 24
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxGGRRRRRx   
    // xxxxxGxxxRr   
    //  XxxxxxxXX 
    else if(heading > 96.3 and heading <= 98.0){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        leds[24] = CRGB::Red;
        leds[25] = CRGB::Red;
        
        leds[10] = CRGB::Gray;
        leds[7] = CRGB::Red;

        FastLED.show();
    }

    // Step 25
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxGGRRRRxx   
    // xxxxxGxxxRr   
    //  XxxxxxxXX 
    else if(heading > 98.0 and heading <= 98.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        leds[24] = CRGB::Red;
        
        leds[10] = CRGB::Gray;
        leds[7] = CRGB::Red;

        FastLED.show();
    }

    // Step 26
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxGGRRRRxx   
    // xxxxxGxxRRr   
    //  XxxxxxxXX 
    else if(heading > 98.2 and heading <= 101.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        leds[24] = CRGB::Red;
        
        leds[10] = CRGB::Gray;
        leds[7] = CRGB::Red;
        leds[6] = CRGB::Red;

        FastLED.show();
    }

    // Not used
    // Step 27
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxGGRRRRxx   
    // xxxxxGxxRRx   
    //  XxxxxxxXX 

    // Step 28
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxGGRRRxxx   
    // xxxxxGxxRRx   
    //  XxxxxxxXX 
    else if(heading > 101.2 and heading <= 101.4){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        
        leds[10] = CRGB::Gray;
        leds[7] = CRGB::Red;
        leds[6] = CRGB::Red;

        FastLED.show();
    }

    // Step 29
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxGGRRRxxx   
    // xxxxxGxRRRx   
    //  XxxxxxxXX 
    else if(heading > 101.4 and heading <= 104.0){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        
        leds[10] = CRGB::Gray;
        leds[8] = CRGB::Red;
        leds[7] = CRGB::Red;
        leds[6] = CRGB::Red;

        FastLED.show();
    }

    // Step 30
    //  xxxxxxxxx    
    // xxxGxxGxxxx   
    // xxxGGRRRxxx   
    // xxxxGxxRRRx   
    //  XxxxxxxXX 
    else if(heading > 104.0 and heading <= 108.3){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[34] = CRGB::Gray;
        leds[31] = CRGB::Gray;

        leds[19] = CRGB::Gray;
        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        leds[23] = CRGB::Red;
        
        leds[11] = CRGB::Gray;
        leds[8] = CRGB::Red;
        leds[7] = CRGB::Red;
        leds[6] = CRGB::Red;

        FastLED.show();
    }

    // Step 31
    //  xxxxxxxxx    
    // xxxGGxxxxxx   
    // xxxxGRRxxxx   
    // xxxxxxRRRRx   
    //  XxxxxxxXX 
    else if(heading > 108.3 and heading <= 113.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[34] = CRGB::Gray;
        leds[33] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        
        leds[9] = CRGB::Red;
        leds[8] = CRGB::Red;
        leds[7] = CRGB::Red;
        leds[6] = CRGB::Red;

        FastLED.show();
    }

    // Not used
    // Step 32
    //  xxxxxxxxx    
    // xxxGGxxxxxx   
    // xxxxGRRxxxx   
    // xxxxxxRRRRX   
    //  XxxxxxxXr 
    
    // Step 33
    //  xxxxxxxxx    
    // xxxGGxxxxxx   
    // xxxxGRRxxxx   
    // xxxxxxRRRxX   
    //  XxxxxxxXr 
    else if(heading > 113.1 and heading <= 120.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[34] = CRGB::Gray;
        leds[33] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        
        leds[9] = CRGB::Red;
        leds[8] = CRGB::Red;
        leds[7] = CRGB::Red;

        FastLED.show();
    }
    
    // Not used
    // Step 34
    //  xxxxxxxxx    
    // xxxGGxxxxxx   
    // xxxxGRRxxxx   
    // xxxxxxRRRxX   
    //  Xxxxxxxrr 

    // Not used
    // Step 35
    //  xxxxxxxxx    
    // xxxGGxxxxxx   
    // xxxxGRRxxxx   
    // xxxxxxRRRxX   
    //  XxxxxxxrX 

    // Step 36
    //  xxxxxxxxx    
    // xxxGGxxxxxx   
    // xxxxGRRxxxx   
    // xxxxxxRRxxX   
    //  XxxxxxRrX 
    else if(heading > 120.8 and heading <= 122.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[34] = CRGB::Gray;
        leds[33] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        
        leds[9] = CRGB::Red;
        leds[8] = CRGB::Red;

        leds[5] = CRGB::Red;

        FastLED.show();
    }

    // Step 37
    //  xxxxxxxxx    
    // xxxxGxxxxxx   
    // xxxxGRRxxxx   
    // xxxxxxRRxxX   
    //  XxxxxxRrX 
    else if(heading > 122.2 and heading <= 123.4){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[33] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Red;
        
        leds[9] = CRGB::Red;
        leds[8] = CRGB::Red;

        leds[5] = CRGB::Red;

        FastLED.show();
    }
    
    // Step 38
    //  xxxxxxxxx    
    // xxxxGxxxxxx   
    // xxxxGRGxxxx   
    // xxxxxxRRxxX   
    //  XxxxxxRrX 
    else if(heading > 123.4 and heading <= 134.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[33] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[9] = CRGB::Red;
        leds[8] = CRGB::Red;

        leds[5] = CRGB::Red;

        FastLED.show();
    }

    // Not used
    // Step 39
    //  xxxxxxxxx    
    // xxxxGxxxxxx   
    // xxxxGRGxxxx   
    // xxxxxxRRxxX   
    //  XxxxxxRXX 

    // Step 40
    //  xxxxxxxxx    
    // xxxxGxxxxxx   
    // xxxxGRGxxxx   
    // xxxxxxRxxxX   
    //  XxxxxxRXX 
    else if(heading > 134.8 and heading <= 135.0){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[33] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[9] = CRGB::Red;
    
        leds[5] = CRGB::Red;

        FastLED.show();
    }

    // Step 41
    //  xxxxxxxxx    
    // xxxxGGxxxxx   
    // xxxxGRGxxxx   
    // xxxxxRRxxxX   
    //  XxxxxRRXX 
    else if(heading > 135.0 and heading <= 145.7){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[33] = CRGB::Gray;
        leds[32] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[10] = CRGB::Red;
        leds[9] = CRGB::Red;
    
        leds[4] = CRGB::Red;
        leds[5] = CRGB::Red;

        FastLED.show();
    }

    // Step 42
    //  xxxxxxxxx    
    // xxxxGGxxxxx   
    // xxxxGRGxxxx   
    // xxxxxRRxxxX   
    //  XxxxxRxXX 
    else if(heading > 145.7 and heading <= 155.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[33] = CRGB::Gray;
        leds[32] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[10] = CRGB::Red;
        leds[9] = CRGB::Red;
    
        leds[4] = CRGB::Red;

        FastLED.show();
    }

    // Step 43
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxxGRGxxxx   
    // xxxxxRRxxxX   
    //  XxxxxRxXX 
    else if(heading > 155.1 and heading <= 160.9){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[10] = CRGB::Red;
        leds[9] = CRGB::Red;
    
        leds[4] = CRGB::Red;

        FastLED.show();
    }

    // Step 44
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxxGRGxxxx   
    // xxxxxRxxxxX   
    //  XxxxxRxXX 
    else if(heading > 160.9 and heading <= 161.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[10] = CRGB::Red;
    
        leds[4] = CRGB::Red;

        FastLED.show();
    }

    // Step 45
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxxGRGxxxx   
    // xxxxxRxxxxX   
    //  XxxxRRxXX 
    else if(heading > 161.1 and heading <= 168.4){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[10] = CRGB::Red;
    
        leds[3] = CRGB::Red;
        leds[4] = CRGB::Red;

        FastLED.show();
    }

    // Step 46 (South)
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxxGRGxxxx   
    // xxxxxRxxxxX   
    //  XxxxRxxXX 
        else if(heading > 168.4 and heading <= 191.0){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[10] = CRGB::Red;
    
        leds[3] = CRGB::Red;

        FastLED.show();
    }else {
        turnOffAllLEDS();
    }
  }else{ // heading is (191.0 to 349.0]

    // Step -1
    //  xxxRRxxxx    
    // xxxxxRxxxxx   
    // xxxxGRGxxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    if(heading > 11.6 and heading <= 18.9){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[42] = CRGB::Red;
        leds[41] = CRGB::Red;

        leds[32] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;

        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step -2
    //  xxxRxxxxx    
    // xxxxxRxxxxx   
    // xxxxGRGxxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 18.9 and heading <= 19.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[41] = CRGB::Red;

        leds[32] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;

        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step -3
    //  xxxRxxxxx    
    // xxxxRRxxxxx   
    // xxxxGRGxxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 19.1 and heading <= 20.6){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[41] = CRGB::Red;

        leds[32] = CRGB::Red;
        leds[33] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;

        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step -4
    //  xxxRxxxxx    
    // xxxxRRxxxxx   
    // xxxxGRGxxxx   
    // xxxxxGGxxxX   
    //  XxxxxxxXX 
    else if(heading > 20.6 and heading <= 33.4){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[41] = CRGB::Red;

        leds[32] = CRGB::Red;
        leds[33] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[9] = CRGB::Gray;
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step -5
    //  xxRRxxxxx    
    // xxxxRRxxxxx   
    // xxxxGRGxxxx   
    // xxxxxGGxxxX   
    //  XxxxxxxXX 
    else if(heading > 33.4 and heading <= 45){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[40] = CRGB::Red;
        leds[41] = CRGB::Red;

        leds[32] = CRGB::Red;
        leds[33] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[9] = CRGB::Gray;
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step -6
    //  xxRxxxxxx    
    // xxxxRxxxxxx   
    // xxxxGRGxxxx   
    // xxxxxxGxxxX   
    //  XxxxxxxXX 
    else if(heading > 45 and heading <= 45.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[40] = CRGB::Red;

        leds[33] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[9] = CRGB::Gray;

        FastLED.show();
    }

    // Step -7
    //  xxRxxxxxx    
    // xxxRRxxxxxx   
    // xxxxGRGxxxx   
    // XxxxxxGxxxx   
    //  XXxxxxxxX 
    else if(heading > 45.2 and heading <= 51.5){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[40] = CRGB::Red;

        leds[34] = CRGB::Red;
        leds[33] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[9] = CRGB::Gray;

        FastLED.show();
    }

    // Step -8
    //  xRRxxxxxx    
    // xxxRRxxxxxx   
    // xxxxGRGxxxx   
    // XxxxxxGxxxx   
    //  XXxxxxxxX 
    else if(heading > 51.5 and heading <= 54.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[39] = CRGB::Red;
        leds[40] = CRGB::Red;

        leds[34] = CRGB::Red;
        leds[33] = CRGB::Red;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[9] = CRGB::Gray;

        FastLED.show();
    }

    // Step -9
    //  xRRxxxxxx    
    // xxxRRxxxxxx   
    // xxxxRRGxxxx   
    // xxxxxxGxxxX   
    //  XxxxxxxXX 
    else if(heading > 54.8 and heading <= 57.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[39] = CRGB::Red;
        leds[40] = CRGB::Red;

        leds[34] = CRGB::Red;
        leds[33] = CRGB::Red;

        leds[22] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[20] = CRGB::Red;
        
        leds[9] = CRGB::Gray;

        FastLED.show();
    }

    // Step -10
    //  xRRxxxxxx    
    // xxxRRxxxxxx   
    // xxxxRRGxxxx   
    // xxxxxxGGxxX   
    //  XxxxxxxXX 
    else if(heading > 57.2 and heading <= 59.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[39] = CRGB::Red;
        leds[40] = CRGB::Red;

        leds[34] = CRGB::Red;
        leds[33] = CRGB::Red;

        leds[22] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[20] = CRGB::Red;
        
        leds[9] = CRGB::Gray;
        leds[8] = CRGB::Gray;

        FastLED.show();
    }

    // Step -11
    //  xRxxxxxxx    
    // xxRRRxxxxxx   
    // xxxxRRGxxxx   
    // xxxxxxGGxxX   
    //  XxxxxxxXX 
    else if(heading > 59.2 and heading <= 65.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[39] = CRGB::Red;

        leds[33] = CRGB::Red;
        leds[34] = CRGB::Red;
        leds[35] = CRGB::Red;

        leds[22] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[20] = CRGB::Red;
        
        leds[9] = CRGB::Gray;
        leds[8] = CRGB::Gray;

        FastLED.show();
    }

    // Step -12
    //  RRxxxxxxx    
    // xxRRRxxxxxx   
    // xxxxRRGxxxx   
    // xxxxxxGGxxX   
    //  XxxxxxxXX 
    else if(heading > 65.1 and heading <= 66.7){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[39] = CRGB::Red;
        leds[38] = CRGB::Red;

        leds[33] = CRGB::Red;
        leds[34] = CRGB::Red;
        leds[35] = CRGB::Red;

        leds[22] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[20] = CRGB::Red;
        
        leds[9] = CRGB::Gray;
        leds[8] = CRGB::Gray;

        FastLED.show();
    }

    // Step -13
    //  Rxxxxxxxx    
    // xxRRRxxxxxx   
    // xxxxRRGxxxx   
    // xxxxxxGGxxX   
    //  XxxxxxxXX 
    else if(heading > 66.7 and heading <= 66.9){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[38] = CRGB::Red;

        leds[33] = CRGB::Red;
        leds[34] = CRGB::Red;
        leds[35] = CRGB::Red;

        leds[22] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[20] = CRGB::Red;
        
        leds[9] = CRGB::Gray;
        leds[8] = CRGB::Gray;

        FastLED.show();
    }

    // Step -14
    //  xxxxxxxxx    
    // xRRRRxxxxxx   
    // xxxxRRGxxxx   
    // xxxxxxGGxxX   
    //  XxxxxxxXX 
    else if(heading > 66.9 and heading <= 71.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[36] = CRGB::Red;
        leds[33] = CRGB::Red;
        leds[34] = CRGB::Red;
        leds[35] = CRGB::Red;

        leds[22] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[20] = CRGB::Red;
        
        leds[9] = CRGB::Gray;
        leds[8] = CRGB::Gray;

        FastLED.show();
    }

    // Step -15
    //  xxxxxxxxx    
    // xRRRxxGxxxx   
    // xxxRRRGGxxx   
    // xxxxGxxGxxX   
    //  XxxxxxxXX 
    else if(heading > 71.8 and heading <= 76.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[31] = CRGB::Gray;
        leds[36] = CRGB::Red;
        leds[35] = CRGB::Red;
        leds[34] = CRGB::Red;

        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[8] = CRGB::Gray;
        leds[11] = CRGB::Gray;

        FastLED.show();
    }

    // Step -16
    //  xxxxxxxxx    
    // xRRRxGxxxxx   
    // xxxRRRGGxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 76.1 and heading <= 78.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[34] = CRGB::Red;
        leds[35] = CRGB::Red;
        leds[36] = CRGB::Red;

        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step -17
    //  xxxxxxxxx    
    // xRRxxGxxxxx   
    // xxRRRRGGxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 78.8 and heading <= 79.0){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[35] = CRGB::Red;
        leds[36] = CRGB::Red;

        leds[18] = CRGB::Red;
        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step -18
    //  xxxxxxxxx    
    // xRRxxGxxxxx   
    // xxRRRRGGxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 79.0 and heading <= 81.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[35] = CRGB::Red;
        leds[36] = CRGB::Red;
        leds[37] = CRGB::Red;

        leds[18] = CRGB::Red;
        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step -19
    //  xxxxxxxxx    
    // RRxxxGxxxxx   
    // xxRRRRGGxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 81.8 and heading <= 82.0){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[36] = CRGB::Red;
        leds[37] = CRGB::Red;

        leds[18] = CRGB::Red;
        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step -20
    //  xxxxxxxxx    
    // RRxxxGxxxxx   
    // xRRRRRGGxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 82.0 and heading <= 83.6){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[36] = CRGB::Red;
        leds[37] = CRGB::Red;

        leds[17] = CRGB::Red;
        leds[18] = CRGB::Red;
        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step -21
    //  xxxxxxxxx    
    // RxxxxGxxxxx   
    // xRRRRRGGxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 83.6 and heading <= 83.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[37] = CRGB::Red;

        leds[17] = CRGB::Red;
        leds[18] = CRGB::Red;
        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step -22 (West)
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // RRRRRRGGxxx   
    // xxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 83.8 and heading <= 96.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[16] = CRGB::Red;
        leds[17] = CRGB::Red;
        leds[18] = CRGB::Red;
        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;

        FastLED.show();
    }

    // Step 23
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xRRRRRGGxxx   
    // RxxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 96.2 and heading <= 96.4){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[17] = CRGB::Red;
        leds[18] = CRGB::Red;
        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;
        leds[15] = CRGB::Red;

        FastLED.show();
    }

    // Step -24
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xRRRRRGGxxx   
    // RRxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 96.4 and heading <= 98.0){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[17] = CRGB::Red;
        leds[18] = CRGB::Red;
        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;
        leds[15] = CRGB::Red;
        leds[14] = CRGB::Red;

        FastLED.show();
    }

    // Step -25
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxRRRRGGxxx   
    // RRxxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 98.0 and heading <= 98.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[18] = CRGB::Red;
        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;
        leds[15] = CRGB::Red;
        leds[14] = CRGB::Red;

        FastLED.show();
    }

    // Step -26
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxRRRRGGxxx   
    // RRRxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 98.2 and heading <= 99.7){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[18] = CRGB::Red;
        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;
        leds[15] = CRGB::Red;
        leds[14] = CRGB::Red;
        leds[13] = CRGB::Red;

        FastLED.show();
    }

    // Step -27
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxRRRRGGxxx   
    // xRRxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 99.7 and heading <= 99.9){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[18] = CRGB::Red;
        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;
        leds[14] = CRGB::Red;
        leds[13] = CRGB::Red;

        FastLED.show();
    }

    // Step -28
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxRRRGGxxx   
    // xRRxxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 99.9 and heading <= 101.4){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;
        leds[14] = CRGB::Red;
        leds[13] = CRGB::Red;

        FastLED.show();
    }

    // Step -29
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxxRRGGxxx   
    // xRRRxGxxxxX   
    //  XxxxxxxXX 
    else if(heading > 101.4 and heading <= 104.0){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[10] = CRGB::Gray;
        leds[14] = CRGB::Red;
        leds[13] = CRGB::Red;
        leds[12] = CRGB::Red;

        FastLED.show();
    }

    // Step -30
    //  xxxxxxxxx    
    // xxxxGxxGxxx   
    // xxxRRRGGxxx   
    // xRRRxxGxxxR   
    //  XxxxxxxXX 
    else if(heading > 104.0 and heading <= 108.3){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[33] = CRGB::Gray;
        leds[30] = CRGB::Gray;

        leds[19] = CRGB::Red;
        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        leds[23] = CRGB::Gray;
        
        leds[9] = CRGB::Gray;
        leds[12] = CRGB::Red;
        leds[13] = CRGB::Red;
        leds[14] = CRGB::Red;

        FastLED.show();
    }

    // Step -31
    //  xxxxxxxxx    
    // xxxxxxGGxxx   
    // xxxxRRGxxxx   
    // xRRRRxxxxxX   
    //  XxxxxxxXX 
    else if(heading > 108.3 and heading <= 113.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[31] = CRGB::Gray;
        leds[30] = CRGB::Gray;

        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Red;
        leds[12] = CRGB::Red;
        leds[13] = CRGB::Red;
        leds[14] = CRGB::Red;

        FastLED.show();
    }

    // Not used
    // Step -32
    //  xxxxxxxxx    
    // xxxxxxGGxxx   
    // xxxxRRGxxxx   
    // xRRRRxxxxxX   
    //  rxxxxxxXX 

    // Step -33
    //  xxxxxxxxx    
    // xxxxxxGGxxx   
    // xxxxRRGxxxx   
    // xxRRRxxxxxX   
    //  rxxxxxxXX 
    else if(heading > 113.1 and heading <= 120.8){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[31] = CRGB::Gray;
        leds[30] = CRGB::Gray;

        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Red;
        leds[12] = CRGB::Red;
        leds[13] = CRGB::Red;

        FastLED.show();
    }

    // Not used
    // Step 34
    //  xxxxxxxxx    
    // xxxGGxxxxxx   
    // xxxxGRRxxxx   
    // xxxxxxRRRxX   
    //  Xxxxxxxrr 

    // Not used
    // Step 35
    //  xxxxxxxxx    
    // xxxGGxxxxxx   
    // xxxxGRRxxxx   
    // xxxxxxRRRxX   
    //  XxxxxxxrX 

    // Step -36
    //  xxxxxxxxx    
    // xxxxxxGGxxx   
    // xxxxRRGxxxx   
    // xxxRRxxxxxX   
    //  XRRxxxxXX 
    else if(heading > 120.8 and heading <= 122.2){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[31] = CRGB::Gray;
        leds[30] = CRGB::Gray;

        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Red;
        leds[12] = CRGB::Red;
        
        leds[0] = CRGB::Red;
        leds[1] = CRGB::Red;

        FastLED.show();
    }

    // Step -37
    //  xxxxxxxxx    
    // xxxxxxGxxxx   
    // xxxxRRGxxxx   
    // xxxRRxxxxxX   
    //  XRRxxxxXX 
    else if(heading > 122.2 and heading <= 123.4){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[31] = CRGB::Gray;

        leds[20] = CRGB::Red;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Red;
        leds[12] = CRGB::Red;
        
        leds[0] = CRGB::Red;
        leds[1] = CRGB::Red;

        FastLED.show();
    }
    
    // Step -38
    //  xxxxxxxxx    
    // xxxxxxGxxxx   
    // xxxxGRGxxxx   
    // xxxRRxxxxxX   
    //  XRRxxxxXX 
    else if(heading > 123.4 and heading <= 129.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[31] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Red;
        leds[12] = CRGB::Red;
        
        leds[0] = CRGB::Red;
        leds[1] = CRGB::Red;

        FastLED.show();
    }

    // Step -39
    //  xxxxxxxxx    
    // xxxxxxGxxxx   
    // xxxxGRGxxxx   
    // xxxRRxxxxxX   
    //  XxRxxxxXX 
    else if(heading > 129.1 and heading <= 129.3){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[31] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Red;
        leds[12] = CRGB::Red;
        
        leds[1] = CRGB::Red;

        FastLED.show();
    }

    // Step -40
    //  xxxxxxxxx    
    // xxxxxxGxxxx   
    // xxxxGRGxxxx   
    // xxxxRxxxxxX   
    //  XxRxxxxXX 
    else if(heading > 129.3 and heading <= 135.0){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[31] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[11] = CRGB::Red;
        
        leds[1] = CRGB::Red;

        FastLED.show();
    }

    // Step -41
    //  xxxxxxxxx    
    // xxxxxGGxxxx   
    // xxxxGRGxxxx   
    // xxxxRRxxxxX   
    //  XxRxxxxXX 
    else if(heading > 135.0 and heading <= 145.7){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[31] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[10] = CRGB::Red;
        leds[11] = CRGB::Red;
        
        leds[1] = CRGB::Red;


        FastLED.show();
    }

    // Step -42
    //  xxxxxxxxx    
    // xxxxxGGxxxx   
    // xxxxGRGxxxx   
    // xxxxRRxxxxX   
    //  XxxRxxxXX 
    else if(heading > 145.7 and heading <= 155.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;
        leds[31] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[10] = CRGB::Red;
        leds[11] = CRGB::Red;
        
        leds[2] = CRGB::Red;

        FastLED.show();
    }

    // Step -43
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxxGRGxxxx   
    // xxxxRRxxxxX   
    //  XxxRxxxXX 
    else if(heading > 155.1 and heading <= 160.9){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[10] = CRGB::Red;
        leds[11] = CRGB::Red;
        
        leds[2] = CRGB::Red;

        FastLED.show();
    }

    // Step -44
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxxGRGxxxx   
    // xxxxxRxxxxX   
    //  XxxRxxxXX 
    else if(heading > 160.9 and heading <= 161.1){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[10] = CRGB::Red;
        
        leds[2] = CRGB::Red;

        FastLED.show();
    }

    // Step -45
    //  xxxxxxxxx    
    // xxxxxGxxxxx   
    // xxxxGRGxxxx   
    // xxxxxRxxxxX   
    //  XxxRRxxXX 
    else if(heading > 161.1 and heading <= 168.4){

        //Turn off all LEDs
        turnOffAllLEDS();

        leds[32] = CRGB::Gray;

        leds[20] = CRGB::Gray;
        leds[21] = CRGB::Red;
        leds[22] = CRGB::Gray;
        
        leds[10] = CRGB::Red;
        
        leds[2] = CRGB::Red;
        leds[3] = CRGB::Red;

        FastLED.show();
    }else {
        turnOffAllLEDS();
    }
  }
}