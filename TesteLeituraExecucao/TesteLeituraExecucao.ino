// Read DHT11 sensor and send serially to PC

#include <DHT.h>         // Include Adafruit DHT11 Sensors Library

#define DHTPIN 2          // DHT11 Output Pin connection
#define DHTTYPE DHT11     // DHT Type is DHT11
#define RELAY_PIN 4       // Relay PIN

DHT dht(DHTPIN, DHTTYPE);   // Initialize DHT sensor

void setup () {
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT); // Configura o pino do relé como saída
  Serial.begin(9600);         // To see data on serial monitor
}

void loop (){

    for (int i = 0; i < 40; i++) {
      unsigned long startTime = millis();
      float humidity = dht.readHumidity();
      float temperature = dht.readTemperature();
      String dhtData = String(humidity) + "," + String(temperature);
      Serial.println(dhtData);

      while (Serial.available() <= 0)
      {}
      char command = Serial.read(); // Lê um caractere da serial

      if (command == '0') {
        digitalWrite(RELAY_PIN, HIGH); // Desliga o relé
      } else if (command == '1') {
        digitalWrite(RELAY_PIN, LOW);  // Liga o relé
      }

      unsigned long endTime = millis();
      
      Serial.print("Medição ");
      Serial.print(i+1);
      Serial.print(": ");
      Serial.print(endTime - startTime);
      Serial.println("ms ");
      delay(2000); // Delay entre leituras para estabilidade
    }
}