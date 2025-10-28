#include "DHT.h"

#define DHTPIN 2       // Pino do DHT
#define DHTTYPE DHT11  // ou DHT22, se for o modelo 22
DHT dht(DHTPIN, DHTTYPE);

// Pinos dos LEDs
#define LED_VERDE 6
#define LED_AMARELO 7
#define LED_VERMELHO 8

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  // Desliga todos os LEDs
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Se leitura falhar, envia "Erro" para o Flask
  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Erro");
    delay(2000);
    return;
  }

  // Lógica dos LEDs físicos
  if (temperatura < 70) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
  } 
  else if (temperatura >= 70 && temperatura < 90) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
  } 
  else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
  }

  // Envia dados para o Flask
  Serial.print(temperatura);
  Serial.print(",");
  Serial.println(umidade);

  delay(2000);
}