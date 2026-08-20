#include <Arduino.h>
#include <Servo.h> // Library bawaan Arduino, ngurusin detail teknis PWM buat kita

Servo myServo; // Bikin "objek" servo, namanya myServo (bebas mau dinamain apa)

const int pinLdr = A0;
const int pinServo = 9;

void setup() {
  Serial.begin(9600); // Biar bisa komunikasi serial sama komputer
  myServo.attach(pinServo); // Hubungin objek servo sama pin servo
  myServo.write(90); // Set posisi awal servo ke 90 derajat (tengah)
}

void loop() {
  int nilaiLdr = analogRead(pinLdr); // Baca nilai dari LDR (0-1023)

  // sementara: convert langsung nilai LDR ke sudut servo (0-180 derajat)
  int sudut = map(nilaiLdr, 0, 1023, 0, 180);
  myServo.write(sudut); // Set posisi servo sesuai nilai LDR

  Serial.print("Nilai LDR: ");
  Serial.print(nilaiLdr);
  Serial.print(" | Sudut Servo: ");
  Serial.println(sudut);

  delay(100); // Delay sebentar biar nggak kebanyakan baca
}