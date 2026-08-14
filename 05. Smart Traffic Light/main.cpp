#include <Arduino.h>

const int redPin  = 13;
const int yellowPin = 12;
const int greenPin = 11;
const int buttonPin = 2;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

// Fungsi baru: "nunggu pintar" uang sambil ngecek button
// durationMs = berapa lama mau nunggu (dalam milidetik)
void smartDelay(int durationMs) {
  int steps = durationMs / 100; // pecah jadu puteran-puteran kecil 100ms

  for (int i = 0; i < steps; i++) {
    int buttonState = digitalRead(buttonPin);

    if (buttonState == LOW) {
      break;
    }

    delay(100); // nunggu sedikit doang, bukan nunggu lama sekaligus
  }
}

void loop() {
  //STATE 1: MERAH
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  delay(3000);

  //STATE 2: KUNING
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(1500);

  //STATE 3: HIJAU
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(2000);
}