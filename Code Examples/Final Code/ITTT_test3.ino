#include "FastLED.h"

#define NUM_LEDS 80
#define DATA_PIN 11
#define CLOCK_PIN 13

// LED array
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);

  // Stick up
  pinMode(2, INPUT);
  // Stick down
  pinMode(4, INPUT);
  // Button
  pinMode(7, INPUT);
  // Flex resistor
  pinMode(A0, INPUT);
  // LDR
  pinMode(A1, INPUT);
  // LED arrangement
  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
//  leds[0] = CRGB(255,0,0);
//  FastLED.show();
//  delay(500);
//  
//  leds[0] = CRGB(0,0,0);
//  FastLED.show();
//  delay(500);

  int stickUp = digitalRead(2);
  int stickDown = digitalRead(4);
  int buttonDown = digitalRead(7);
  int pcPos = 0;
  int pcSpeed = 1;
  boolean dash = false;
  boolean gameOver = false;
  
  //Stick changing the player position
  if (dash == false) {
    if (stickUp == 1) {
      if (pcPos > NUM_LEDS)  {
        pcPos = NUM_LEDS - 1;
      }
      else{
        pcPos = pcPos + pcSpeed;
      }
    }
    else if (stickDown == 1) {
      if (pcPos <0)  {
        pcPos = 0;
      }
      else{
        pcPos = pcPos - pcSpeed;
      }
    }
  }

  //Button + stick in a direction to dash WIP
  if (dash == false) {
    if (buttonDown == 1 && stickUp == 1) {
      dash = true;
      // some dashing code
      dash = false;
    }
    else if (buttonDown == 1 && stickDown == 1) {
      dash = true;
      // some dashing code
      dash = false;
    }
  }

  //lava floor
  int lavaStart = 18;
  int lavaLength = 5;
  if (pcPos >= lavaStart && pcPos <= lavaStart + lavaLength) {
    gameOver = true;
  }
  // refreshing the "screen"
  for(int i = 0;i< NUM_LEDS;i++){
    leds[i] = CRGB(0,0,0);
  }
  leds[pcPos] = CRGB(0,255,0);
}
