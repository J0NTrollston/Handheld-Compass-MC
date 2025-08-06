# Working MC Compass (Workin on README)
If you are looking to build this design here is the documentation and all necessary informtion for [Building Your Own]() (link not yet created).

## Table of Contents (TBA)
1. [Objectives or Purpose](#objectives-or-purpose)
2. [Preliminary Design](#preliminary-design)
3. [CAD](#cad)
4. [Hardware](#hardware)
5. [Software](#software)
6. [Debugging](#debugging)
7. [Testing methodology or results](#testing-methodology-or-results)
8. [Conclusions](#conclusions)
9. [Documentation](#documentation)


### Objectives or Purpose 
This design take the compass from the game Minecraft and places it into your hands. By creating the shell of the compass to picking the internal components, I provide documentation on how to build it yourself. 
Most of this document will go over the process in designing the compass and is not the document for building your own. Please see the top of this document for the link on how to build your own. 
This compass has the full functionality shown in the game as well as a rechargible lipo battery through USB-C and a swith to power off when not in use. At this time, there is an LED to show when the battery is fully charged, however I have not implemented a way to show this outside the enclosure. 
Other compoents include a microcontroller to display a compass needle using an LED array, magnetometer and boost converter.

### Preliminary Design
Starting this project, the first thing that I needed to figure out was how I was going to control the LEDs. I had no experience with using addressable LEDs and started looking at a couple of options. I saw some LED strips with 4 contacts and others with 3. The LED strips with only 3 contacts had Power, Ground and the address signal. 
This was all that I needed and decided to get a roll to use. I did see other LED strips which had the LEDs a little close together, but they were either more expensive or were the 4 contact variant. Some considerations when choosign the LED strip were the LED spacing, support for the LED using pre-existing libraries and how to mount.
The spacing of the LEDs was not too big of an issue for the prototype but would have to be folded closer together to reduce the size of the compass' overall width. This will be shown later when preparing the LEDs for installation. 
Later when I get a working design, I would like to create a custom PCB instead of using an LED matrix due to the limited sizes they come in. 
While searching for addressable LEDs, I did see some libraries I could use and shortly found one that would work for me. Lastly, the issue with mounting the LED strip was to get them in the right place in the compass. This will be explained in detail later.

![LED Strip](/Images/LED_Strip_Amazon.jpg)

Now that I had decided on an LED strip for the prototype, I now needed to find out the size of the compass. Shown below is a blank MC compass which is 14 pixels wide and 12 pixels tall. 
When measuring out the center spacing between each LED on the strip, this came out to 16.5mm which would give me a total width of 16.5mm x 14 pixels = 231mm (9 inches) across. This would obviously not fit in one hand and would be too big. Instead, I would fold the strip to being the LEDs closer together. 

![Blank Minecraft Compass](/Images/Minecraft_Compass_Blank.jpg)

By folding the space between each LED, I could decrease the center spacing between each LED and thus each pixel could be smaller. I decided to use a spacing of 10mm which means each pixel would be 10mm squares giving a total width of 10mm x 14 pixels = 140mm (5.5 inches) across. 
This was still quite large but would be small enough for the prototype. I had the LEDs and a decent size for the compass in mind, now I had to determine how the display was going to work with 3D printing filament.

![LED Strip Folded Close Together](/Images/LED_Strip_Folded_Together.jpg)

Another component that I had added was the Magnetometer which would use Earth's magnetic field to display north on the compass. This was quite simple and only needed I2C communication. It came with mounting holes for later versions of my design but would be glued on for now. 


### CAD
#### 3D Printing
There are some translucent filaments out there that can be used to see the light from the LED through the compass. For my design, I used PLA Matte and printed a very thin layer so the light could pass through. I did this because I did not wanted to only use PLA Matte and 4 primary colors.
The P1S Bambu Printer allows for small layer heights, playing with these layer heights for the firstt few layers allowed for more or less light to pass through. I played with layer heights between 0.1mm to 1.0mm by increasing steps of 0.1mm each iteration. 
I found that 0.4mm was a good thickness as to let enough light to pass through but not too think to become fragile when handled. As the only place where the design needed to be 0.4mm in thickness was where the LEDs displayed the compass needle, the rest of the area around could be increased in thickness. 

Couple of considerations before we go into the compass design. There are 51 pixels in the compass that change colors for the moving needle but I only use 47 because 4 of those pixels are the black border and not the lighter gray color meaning that 0.4mm is too thick for the LEDs to shine through.
The other note is that many libraries for controlling the LEDs intend for the LED matrix to be a rectangle, since I am only using the required amount of LEDs I will not have a rectangular matrix which will be shown later. This is not an issue however since I treat my LEDs like an array and display my own display.

##### Inkscape
Special note on multicolor filament is that Inkscape is helpful when converting pictures to stl format. I found this really helpful video from [Dark Side Designs](https://www.youtube.com/watch?v=wVLm3hICILs) in which they explain how to use an image when creating an stl file. This is helpful when needing to print in different colors.
Following the video, I was able to create the face of the compass which would let me set each section to a different color by making them their own Components in Fusion 360. The sections can be seen in the image below.

![Inkscape to STL Compass](/Images/Inkscape_to_Fusion360.jpg)

With the face of the compass now made, we need to make the mount for the LEDs as well as a way to properly diffuse the light throught the front of the compass. Given a spacing of 10mm as well as thick walls between each LED provides clear display with the LEDs being 5mm away from the thin compass face. 
Below are 2 images showing the front and back of the compass with the top removed. This shows the LED mount where each LED is placed in the square hole. For the LED strip to be fixed in place, I had to use E6000 Adhesive which took a painful amount of time to place. 
Also by bending the LED strip, I did have some connection issues where at some places the metal creased and caused connection issues. Later I will use mounting holes with the LED Array PCB to solve this issue.

![Compass Top Removed](/Images/Compass_Body_Top_Removed.jpg)
![Compass Top Removed (Back)](/Images/Compass_Body_Top_Removed_Back.jpg)

### Hardware
### Software
#### Add readme to Code folder?
Once the mount for the LEDs have been created, I started to work on the code to verify the library is compatible for the LEDs I received. Given the WS2812 LED I used <FastLED.h> which I had used to display each direction I wanted. 
When reviewing the [LED Code](https://github.com/J0NTrollston/Handheld-Compass-MC/blob/main/Code/Handheld_Compass_MC/src/LED.cpp) written, please note that most of the code is to simply display which direction the compass needle was pointint to. It is very simple but includes many direction choices. 

For the [Magnetometer Code](https://github.com/J0NTrollston/Handheld-Compass-MC/blob/main/Code/Handheld_Compass_MC/src/Magnetometer.cpp), I had used the <Adafruit_MMC56x3.h> library which did most of the work for me. Using the raw data from the component, I could calculate the heading and return it to my LED function. 

#### Calibration
Note that when using a component like a Magnetometer, you will need to calibrate it. These are referred top as "Soft Iron" and "Hard Iron" calibrations. For my compass, I opted to only do a 2 axis calibration by keeping the compass level with the X and Y axis. 

#### Add calibration screenshots?

### Debugging

### Testing methodology or results

### Conclusion

### Documentation
#### Sources
- Image of blank compasss: https://minecraft.fandom.com/wiki/Compass?file=Compass_%28texture%29_JE1_BE1.png
- GIF of compass needle: https://minecraft.fandom.com/wiki/Compass?file=Compass_Proctex_Needle_Points.gif
- Image to STL YouTube: https://www.youtube.com/watch?v=wVLm3hICILs
 
#### Tools used
- Fusion 360
- Inkscape
- Altium Designer
- Bambu Lab P1S with AMS
- VSCode
 
#### Overall BOM:
 - [LED Strip from Amazon](https://a.co/d/37Ocjif) $13.99
 - [PLA Matte for White, Charcoal, Nardo Gray and Ash Gray](https://us.store.bambulab.com/products/pla-matte) $59.96 (Assuming you have to buy new rolls)
 - [Magnetometer](https://www.digikey.com/short/5crqvzjf) $5.95