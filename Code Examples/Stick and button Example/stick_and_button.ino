void setup() {
  //turns the serial monitor on to directly read out values
  Serial.begin(9600);
  //the 3 LED pins
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  //Stick up
  pinMode(2, INPUT_PULLUP);
  //Stick down
  pinMode(4, INPUT_PULLUP);
  //Button
  pinMode(7, INPUT_PULLUP);
}

void loop() {
  //Makes a variable of the stick and button pins 
  int stickUp = digitalRead(2);
  int stickDown = digitalRead(4);
  int buttonDown = digitalRead(7);

  //Prints the values on the monitor
  Serial.print(stickUp);
  Serial.print(stickDown);
  Serial.println(buttonDown);

  //Example on how to make the button and stick control something, in this case 3 LEDs
  if (stickUp == 1) {
    digitalWrite(11, LOW);
  } else {
    digitalWrite(11, HIGH);
  }
  if (stickDown == 1) {
    digitalWrite(10, LOW);
  } else {
    digitalWrite(10, HIGH);
  }
  if (buttonDown == 1) {
    digitalWrite(9, LOW);
  } else {
    digitalWrite(9, HIGH);
  }
}
