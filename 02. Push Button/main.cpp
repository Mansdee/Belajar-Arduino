#include <Arduino.h>

const int buttonPin = 4;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  // INPUT_PULLUP artinya: kalau button belum ditekan, nilainya otomatis HIGH.
  // Pas ditekan, nilainya jadi LOW. Ini teknik umum biar nggak perlu
  // resistor tambahan di rangkaian (disebut "pull-up resistor").
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    // LOW artinya button LAGI DITEKAN (karena kita pakai INPUT_PULLUP), nyalakan LED
    digitalWrite(ledPin, HIGH);
  } else {
    // HIGH artinya button TIDAK DITEKAN, matikan LED
    digitalWrite(ledPin, LOW);
  }
}