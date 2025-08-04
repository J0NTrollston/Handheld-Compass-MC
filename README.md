# Working MC Compass (Working on README)
This was a fun side project that allowed me to learn more about 3D printing and how I could create functional designs. The idea to create this project came to me when learning how to create your own multi-colored prints. 
Although this is more of a creative than practical design, I decided to create a tutorial for others to follow and build their own. 

Thoughout this tutorial, I will explain my thought process and give details on how certain things came to be. When I am finished with this tutorial, most of the inforamtion will not be required for building your own. 
I believe that in the end, you will only need the 3d print file, PCB files and other circuits and just skip my explanation if you want to.

## Table of Contents (TBA)

## Getting Started
Starting this project, the first thing that I needed to figure out was how I was going to control the LEDs. I had no experience with using addressable LEDs and started looking at a couple of options. I saw some LED strips with 4 contacts and others with 3. The LED strips with only 3 contacts had Power, Ground and the address signal. 
This was all that I needed and decided to get a roll to use. I did see other LED strips which had the LEDs a little close together, but they were either more expensive or were the 4 contact variant. Some considerations when choosign the LED strip were the LED spacing, support for the LED using pre-existing libraries and how to mount.
The spacing of the LEDs was not too big of an issue for the prototype but would have to be folded closer together to reduce the size of the compass' overall width. This will be shown later when preparing the LEDs for installation. 
Later when I get a working design, I would like to create a custom PCB instead of using an LED matrix due to the limited sizes they come in. 
While searching for addressable LEDs, I did see some libraries I could use and shortly found one that would work for me. Lastly, the issue with mounting the LED strip was to get them in the right place in the compass. This will be explained in detail later.


![LED Strip](/Images/LED_Strip.jpg)


Although I had initially considered buying an LED matrix, I went with the LED strip for a couple of reasons. 




- Resources
 Image of blank compasss: https://minecraft.fandom.com/wiki/Compass?file=Compass_%28texture%29_JE1_BE1.png
 GIF of compass needle: https://minecraft.fandom.com/wiki/Compass?file=Compass_Proctex_Needle_Points.gif
 

Tools that I used: 
 Fusion 360 for the compass design
 Inkscape for taking a picture of the compass and converting it to a sketch in Fusion 360
 Altium Designer for the PCB design
 Bambu Lab P1S printer with AMS

Tools that you will need to make this yourself: 
 3D Printer
 