## 1D-D-Crawler
**Made by:** Adriaan van Oostveen

---
###Description:
This is an instructable on how I made a one dimensional dungeon crawler and how to make one yourself.
In this insctructable we will go over how to connect buttons to the arduino and how to code them, how to work with an adressable RGB LED strip using the FastLED library, and more.

---
###Software:  

* Arduino - 1.8.1
  https://www.arduino.cc/en/Main/Software
  
###Hardware:

* An Arduino
* 2 Buttons or an arcade stick
* A button
* An adressable RGB LED strip
* A power supply for the LED strip (they use 5V like the Arduino but need more Ampere than the Arduino can deliver reliably)
* Pin jumper cables
* A breadborad
  
#####Recommended links

1. Reference:
  Nice to have open in case you want to look up how to write something quickly.
  https://www.arduino.cc/en/Reference/HomePage

2. Arduino/Circuit simulators:
  You can use one of these progams to simulate builds, which is nice if you don't have your parts at hand. I would recommend working with real stuff as much as possible though.
  * https://circuits.io/
  * http://fritzing.org/download/

###Tutorials:

You can find all the code used here in the "Code Examples" folder above as .ino files

#####Stick & Button
https://circuits.io/circuits/3837213-controller-circuit-test

This is a simple circuit where the three buttons (the two buttons on the left symbolise an arcade stick) control three LEDs. This is to test if all the connections work.
#####Moving a light
https://circuits.io/circuits/3843497-moving-a-light

It's important that you turn all the leds off again before you show the new frame else all the leds will be on after a few movements.
#####FastLED & adressable RGB LED strip
Get the FastLED library. You can download this from https://github.com/FastLED/FastLED/releases or in the Ardiono program by going to Sketch > Include Library > Manage Libraries...
From there you type "FastLED" into the search bar at the top right, and then press "install".

Then you want to go to File > Examples > FastLED (should be at/near the bottom) > Blink. 
This Example makes the first LED in the strip blink red at an 500ms interval.

At the top you define the ammount of LEDs you have in your strip, and what the data and clock pin are.
It makes an array with the length of the defined ammount of LEDs on your strip, where each array point is an RGB value.

In the Setup there's a list of commented lines. These are the chipsets that FastLED supports. You take the line that contains the chipset of your LED strip.
#####Animating with arrays
You can animate lights by using an array to store frames, and using an integer to store the frame counter. Each array entry is an RGB value.

#####Final Code
This is the code I have so far.
https://circuits.io/circuits/3844412-final-code-setup

The yellow and orange cable symbolise the two cables that are from the LED strip.
