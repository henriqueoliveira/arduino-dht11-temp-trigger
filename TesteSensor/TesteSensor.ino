#include <DHT.h>

#define DHTPIN 2          // Pino conectado ao DHT11
#define DHTTYPE DHT11     // Tipo do sensor DHT
DHT dht(DHTPIN, DHTTYPE);

unsigned long sensorTimes[4]; // Array para armazenar tempos

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  for (int i = 0; i < 4; i++) {
    unsigned long startTime = millis();
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    unsigned long endTime = millis();
    
    Serial.print("Medição ");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.print(endTime - startTime);
    Serial.println("ms ");
    delay(2000); // Delay entre leituras para estabilidade
  }
  
  // Aguardar um tempo antes de reiniciar o teste
  delay(10000);
}
