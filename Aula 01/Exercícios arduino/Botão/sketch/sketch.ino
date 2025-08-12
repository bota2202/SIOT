void setup() {
  pinMode(10, INPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  if(digitalRead(10)==LOW){
    delay(200);
    digitalWrite(9, LOW);
  }else{
    delay(200);
    digitalWrite(9, HIGH);
  }
}
