#include <Arduino.h>
#include <Servo.h> // Library bawaan Arduino, ngurusin detail teknis PWM buat kita

Servo myServo; // Bikin "objek" servo, namanya myServo (bebas mau dinamain apa)

int pos = 0; // posisi servo, 0-180 derajat

void setup() {
  myServo.attach(9); // pin 9 buat servo khusus tanda (~) PWM
  Serial.begin(9600); // buat komunikasi serial, biar bisa ngeprint ke Serial Monitor
}

void loop() {
  // Gerak servo dari 0 ke 180 derajat
  for (pos = 0; pos <= 180; pos++) {
    myServo.write(pos); // set posisi servo
    Serial.println(pos); // print posisi ke Serial Monitor
    delay(15); // delay biar gerakannya halus
  }

  // Gerak balik servo dari 180 ke 0 derajat
  for (pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    Serial.println(pos);
    delay(15);
  }
}