int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int brilho = 0; brilho <= 255; brilho++) {
    analogWrite(ledPin, brilho); 
    delay(10); 
  }
  for (int brilho = 255; brilho >= 0; brilho--) {
    analogWrite(ledPin, brilho);
    delay(10);
  }
}
