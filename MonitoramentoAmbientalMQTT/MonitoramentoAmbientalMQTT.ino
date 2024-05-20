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

    float H = dht.readHumidity(); 
    float T = dht.readTemperature();

    // Check if any reads failed and if exit
    if (isnan(H) || isnan(T)){
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
 
    // Combine Humidity and Temperature into single string
    String dhtData = String(H) + "," + String(T);
    Serial.println(dhtData);

    if (Serial.available() > 0) {  // Verifica se há dados disponíveis para ler na serial
      char command = Serial.read(); // Lê um caractere da serial

      if (command == '0') {
        digitalWrite(RELAY_PIN, HIGH); // Desliga o relé
      } else if (command == '1') {
        digitalWrite(RELAY_PIN, LOW);  // Liga o relé
      }
  }
}