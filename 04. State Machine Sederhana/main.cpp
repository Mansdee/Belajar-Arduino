#include <Arduino.h>

const int redPin  = 13;
const int yellowPin = 12;
const int greenPin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  //STATE 1: MERAH
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  delay(3000); // merah nyala 3 detik

  //STATE 2: KUNING
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(1500); // kuning nyala 1,5 detik

  //STATE 3: HIJAU
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(2000); // hijau nyala 2 detik

  // Setelah itu, kembali ke STATE 1 (loop)
}