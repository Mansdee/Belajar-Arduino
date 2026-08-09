#include <Arduino.h>

const int ldrPin = A0; // LDR connected to analog pin A0
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  // Ini buka "jalur komunikasi" ke komputer, biar kita bisa kirim data ke Serial Monitor
}

void loop() {
  int lightValue = analogRead(ldrPin);
  // analogRead() beda sama digitalRead() — hasilnya bukan cuma HIGH/LOW,
  // tapi angka dari 0 sampai 1023 (makin gelap, nilainya biasanya makin gede,
  // tergantung arah rangkaian voltage divider kamu)

  Serial.println(lightValue);
  // Ini nampilin nilai sensor di Serial Monitor, buat kamu ngecek
  // angka berapa pas terang vs gelap

  if (lightValue > 500) {
    // Kalau gelap (angka gede), nyalain LED otomatis
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(200); // delay 200ms biar nggak terlalu cepet ngecek sensor
}