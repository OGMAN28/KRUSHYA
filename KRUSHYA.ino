#include "DHT.h"

#define DHTPIN 2  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
#include <SoftwareSerial.h>
SoftwareSerial bt(4, 5);
int moisture = 0;

void setup()
{
  pinMode(A0, OUTPUT);//power
  pinMode(A1, INPUT);//signal
  Serial.begin(9600);
  bt.begin(9600);
  dht.begin();
}

void loop()
{
   int h = dht.readHumidity();
    int t = dht.readTemperature();
    Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
   bt.print(t); 
 bt.print(";");
 bt.print(h);  
 bt.println(";");
  digitalWrite(A0, HIGH);
  delay(10); 
  moisture = analogRead(A1);
  digitalWrite(A0, LOW);
  Serial.println(moisture);
  bt.print (moisture);
  delay(2000); 
}
