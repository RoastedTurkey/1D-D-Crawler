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

boolean dash = false;
boolean gameOver = false;
boolean nextLevel = false;

void setup() {
  Serial.begin(9600);

  // Stick up
  pinMode(2, INPUT_PULLUP);
  // Stick down
  pinMode(4, INPUT_PULLUP);
//  // Button
//  pinMode(7, INPUT_PULLUP);
//  // Flex resistor
//  pinMode(A0, INPUT_PULLUP);
//  // LDR
//  pinMode(A1, INPUT_PULLUP);
  // LED arrangement
  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
  //putting frames in the flames
  for(int i=0; i<12;i++){
    fire[i] = CRGB(14*i,5*i,0);
  }
}
  int pcPos = 10;
  int pcSpeed = 1;
  int deadTimer = 0;

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
  
//  Serial.print("up = ");
//  Serial.print(stickUp);
//  Serial.print(", down = ");
//  Serial.println(stickDown);
  Serial.print("pcPos = ");
  Serial.print(pcPos);
  Serial.print(", fire = ");
  Serial.print(fireFrame);
  Serial.print(", no fire= ");
  Serial.print(fireWait);
  Serial.print(", gameover = ");
  Serial.print(gameOver);
  Serial.print(", d.count = ");
  Serial.println(deadTimer);
  
  //Stick changing the player position
  if (dash == false && gameOver == false && nextLevel == false) {
    if (stickUp == 0) {
//      pcPos = pcPos + pcSpeed;
      pcPos++;
        if (pcPos > NUM_LEDS - 1) {
          pcPos = NUM_LEDS - 1;
          nextLevel = true;
      }
    }
    else if (stickDown == 0) {
//      pcPos = pcPos - pcSpeed;
      pcPos = pcPos - 1;
      if (pcPos <0)  {
        pcPos = 0;
      }
    }
  }

//  //Button + stick in a direction to dash WIP
//  if (dash == false) {
//    if (buttonDown == 1 && stickUp == 1) {
//      dash = true;
//      // some dashing code
//      dash = false;
//    }
//    else if (buttonDown == 1 && stickDown == 1) {
//      dash = true;
//      // some dashing code
//      dash = false;
//    }
//  }

  //lava floor
  if (pcPos >= lavaStart && pcPos < lavaStart + lavaLength && fireFrame > 8 && fireWait == 17) {
    gameOver = true;
  }
  
  // refreshing the "screen"
  for(int i = 0;i< NUM_LEDS;i++){
    leds[i] = CRGB(0,0,0);
  }
   
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
  
  leds[pcPos] = CRGB(0,255,0);
  
  if(gameOver == true || nextLevel == true){
    for(int k = 0; k<NUM_LEDS; k++){
      if(gameOver == true){
        leds[k] = CRGB(255,0,0);
      }
      else{
        leds[k] =  CRGB(0,255,0);
      }
    }
    deadTimer++;
    if (deadTimer >22){
      pcPos = 1;
      gameOver = false;
      nextLevel = false;
      deadTimer = 0;
      lavaStart = random(6,76);
    }
  }
  FastLED.show();
//  delay(200);
  }
