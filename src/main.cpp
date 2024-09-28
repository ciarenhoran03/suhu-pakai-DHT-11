#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 23    
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(115200); 
  dht.begin();
}
void loop() {
  delay(2000); 

  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 
  
  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca dari sensor DHT!");
    return;
  }

  Serial.print("Kelembapan: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Suhu: ");
  Serial.print(t);
  Serial.println(" °C");
}