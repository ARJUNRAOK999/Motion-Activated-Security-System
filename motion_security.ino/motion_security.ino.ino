#include <SoftwareSerial.h>

const int pirPin = 2;
const int ledPin = 8;
const int buzzerPin = 9;

SoftwareSerial BTSerial(10, 11); // RX, TX

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);       // For Serial Monitor
  BTSerial.begin(9600);     // For HC-05 Bluetooth

  Serial.println("System ready");
  BTSerial.println("Bluetooth system started");
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Motion Detected!");
  
  } else {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, LOW);
        BTSerial.println("Motion Detected!");
  }

  delay(200);
}
