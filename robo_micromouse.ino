// Definição dos pinos conectados à ponte H L298N
#define  IN1  23
#define  IN2  22
#define  IN3  18
#define  IN4  19

// Definição dos pinos do sensor ultrassônico
#define TRIGGER_PIN 2
#define ECHO_PIN 3

// Definição da variável que irá armazenar a distância medida pelo sensor
float distancia;

void setup() { 
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Movimentação para frente
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Mede a duração do pulso de eco no pino de echo
  long duracao = pulseIn(ECHO_PIN, HIGH);

  // Converte a duração do pulso em distância em centímetros
  distancia = 0.034 * duracao / 2;

  if(distancia > 25){
    // Andando para frente
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  else{
    // Parado por meio segundo
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(500);
    
    // Virando para a esquerda por 100ms
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(100);
  }
}