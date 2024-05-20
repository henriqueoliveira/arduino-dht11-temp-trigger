#define RELAY_PIN 4

unsigned long actuatorTimes[4];

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Inicialmente desligado
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    unsigned long startTime = millis();
    digitalWrite(RELAY_PIN, LOW); // Ativa o relé
    delay(10); // Suponha um tempo mínimo para ativação física
    digitalWrite(RELAY_PIN, HIGH); // Desativa o relé
    unsigned long endTime = millis();
    
    Serial.print("Medição ");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.print(endTime - startTime);
    Serial.println("ms ");
    delay(2000); // Delay entre ativações
  }

  Serial.println();
  
  delay(10000); // Aguardar antes de reiniciar os testes
}
