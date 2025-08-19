const int ledPins[] = {2, 3, 4, 5, 6}; 
const int potPin = A0;                

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int potValue = analogRead(potPin); 
  int level = map(potValue, 0, 1023, 0, 6); 
  for (int i = 0; i < 5; i++) {
    if (i < level) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  delay(50); 
}
