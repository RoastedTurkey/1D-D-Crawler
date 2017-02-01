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

This is a simple circuit where the three buttons (the two buttons on the left symbolise an arcade stick) control three LEDs. This is to test if all the connections work, and to show how you can make them control something.

The variables of the sensors (buttons, in this case lines 19, 20, and 21) are within the void loop because they need to be adjusted to the values that the sensor reads every time this loop is run. They are at the top because usually your code is based on what these values read.
#####Moving a light
https://circuits.io/circuits/3843497-moving-a-light

In this example the movement is inverted because as you can see the numbers of the pins is counting upwards from right to left. You can do this with a LED strip as well, but in the next step we'll talk about how to control that.

It's important that you turn all the leds off again before you show the new frame else all the leds will be on after a few movements.
You can see this if you comment (add "//" at the start of each line) the for loop that turns the lights off, which is on lines 46, 47, and 48.
#####FastLED & adressable RGB LED strip
Get the FastLED library. You can download this from https://github.com/FastLED/FastLED/releases or in the Ardiono program by going to Sketch > Include Library > Manage Libraries...
From there you type "FastLED" into the search bar at the top right, and then press "install".

Then you want to go to File > Examples > FastLED (should be at/near the bottom) > Blink. 
This Example makes the first LED in the strip blink red at an 500ms interval.

At the top you define the ammount of LEDs you have in your strip, and what the data and clock pin are (some strips don't have a clock pin).
It makes an array with the length of the defined ammount of LEDs on your strip (in my case for the final code, i had 80 LEDs), where each array point is an RGB value.

In the Setup there's a list of commented lines. These are the chipsets that FastLED supports. You take the line that contains the chipset of your LED strip.

In the Loop there's some code to turn the first LED in the strip on and then off. The values of the LEDs is stored in the "leds" array, and they're only pushed to the strip when you call for the function "FastLED.show();". In this example the creator of the library uses just a text code for a colour, but you can also use an rgb code by using "CRGB(255,0,0)" instead of "CRGB::Red". Black or all zeroes means that the light is off.

If you want to recreate the last step on the LED strip you need to push an RGB value to the LED's coresponding position withing the array, based on the player's coordinate.
#####Animating with arrays
You can animate lights by using an array to store frames, and using an integer to store the frame counter. Each array entry is an RGB value.

In my example, I created these "flames" to create an obstacle for the player, hence the variable names. The variables from lines 11 through 15 (these are refered to later) are outside of any loops, so they don't get changed (Do this as well for stuff like a "game over" boolean, if it's in the void loop it will be constantly changerd to the defined value and you cannot game over).

In the setup the fire array is filled with different RBG values, in this case becoming brighter with each array entry. In the void loop it starts with emptying the "leds" array, and then it checks wether or not it needs to count active frames (labled fireFrame) or inactive frames (labled "fireWait").

If it's in its active frames it will take the RGB values of its current frame out of the coresponding point in the "fire" animation array, and then push those RGB values to the coordinates of the fire (atarting at "lavaStart" with a length of "lavaLength") on the "leds" array. Then at the end it adds 1 to the the active frame counter. 

If the frame coutner is at the end, defined in the "if" statement (at line 39), it will start counting inactive frames instead. And once those inactive frames are at their cap, defined at line 45, it will reset the active frame counter.

It also checks whether or not the inactive frames are at its defined end at the start, at line 34. I had to do thise because if I checked for frame counters differently they either wouldn't reset and get it would get stuck or I would have to write some seperate lines to check wether or not the counters had to be reset or not.
#####Final Code
This is the code I have so far.
https://circuits.io/circuits/3844412-final-code-setup

The yellow and orange cable symbolise the two cables that are from the LED strip.
