// Definição de pinos
const int ledVermelho = 8;
const int ledAmarelo = 9;
const int ledVerde = 10;
const int ledPedestre = 11;
const int botao = 2;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledPedestre, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  // Semáforo automático
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledPedestre, LOW);
  
  if (lerBotao()) {
    atravessarPedestre();
  } else {
    delay(5000); // verde 5s
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    delay(2000); // amarelo 2s
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    delay(5000); // vermelho 5s
  }
}

// Função para ler botão com debounce
bool lerBotao() {
  if (digitalRead(botao) == HIGH) {
    delay(50); // debounce simples
    if (digitalRead(botao) == HIGH) return true;
  }
  return false;
}

// Função que simula travessia do pedestre
void atravessarPedestre() {
  // Transito vermelho
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, HIGH);
  
  // Pedestre atravessando
  digitalWrite(ledPedestre, HIGH);
  
  delay(5000); // tempo de travessia 5s
  
  digitalWrite(ledPedestre, LOW);
  
  // Retorna ao semáforo normal
  digitalWrite(ledVermelho, LOW);
}
