#include "FastLED.h"

#define NUM_LEDS 80
#define DATA_PIN 11
#define CLOCK_PIN 13

// LED array
CRGB leds[NUM_LEDS];

//Flames data
CRGB fire[18];
int fireFrame = 0;
int fireWait = 0;
int lavaStart = 18;
int lavaLength = 5;

void setup() {
  // LED arrangement
  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
  
  //putting frames in the flames
  for(int i=0; i<12;i++){
    fire[i] = CRGB(14*i,5*i,0);
  }
}

void loop() {
  // refreshing the "screen"
  for(int i = 0;i< NUM_LEDS;i++){
    leds[i] = CRGB(0,0,0);
  }

  // This makes the animations cycle through the active and inactive frames
  if(fireWait >16){
    for(int j = 0;j<lavaLength;j++){
      leds[lavaStart + j] = fire[fireFrame];
    }
    fireFrame++;
    if(fireFrame >16){
      fireWait = 0;
    }
  }
  else {
    fireWait++;
    if(fireWait >16){
      fireFrame = 0;
    }
  }
  FastLED.show();
}
