void setup() {
  Serial.begin(9600);

  // Left
  pinMode(A0, INPUT_PULLUP);
  // Right
  pinMode(12, INPUT_PULLUP);
  // LEDs
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
  int pos = 11;
  int speed = 1;

void loop() {
  int left = digitalRead(A0);
  int right = digitalRead(12);
  
  Serial.print(left);
  Serial.print(right);
  Serial.print(", ");
  Serial.println(pos);
  
  //makes the buttons move the character
  if (left == 0) {
    pos = pos + speed;
    if (pos > 11) {
      pos = 11;
    }
  }else if (right == 0) {
    pos = pos - speed;
    if (pos < 2) {
      pos = 2;
    }
  }
  
  // refreshing the "screen"
  for(int i = 2; i<12; i++){
    digitalWrite(i, LOW);
  }
  // then showing the player's position
  digitalWrite(pos, HIGH);
}

