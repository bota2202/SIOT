void setup() {
  for (int i = 2; i <= 6; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 1; i <= 6; i++) {
    digitalWrite(i, HIGH);
    delay(59);
    digitalWrite(i, LOW);
    delay(50);
  }
  for (int i = 6; i >= 2; i--) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    delay(50);
  }
}
