void setup() {
  pinMode(10, INPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  if(digitalRead(10)==LOW){
    digitalWrite(9, LOW);
  }else{
    digitalWrite(9, HIGH);
  }
}
