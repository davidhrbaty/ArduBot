// ---------------------------------------------------------------------------
// Created by Tim Eckel - teckel@leethost.com
// Copyright 2014 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
//
// See "TimerFreeTone.h" for purpose, syntax, version history, links, and more.
// ---------------------------------------------------------------------------

#include "TimerFreeTone.h"

void TimerFreeTone(uint8_t pin, unsigned long frequency, unsigned int duration) {
  if (!frequency) { delay(duration); return; } // Frequency is false (zero), nothing to play, just delay for duration and return.
  unsigned long endtime = millis() + duration; // Calculate when the note will end.
  unsigned long notch = 500000 / frequency;    // Calculate how fast to toggle the pin.
#ifdef __AVR__
  uint8_t pinBit = digitalPinToBitMask(pin);                                           // Get the bitmask for the pin.
  volatile uint8_t *pinOutput = (uint8_t *) portOutputRegister(digitalPinToPort(pin)); // Get the port register for the pin.
  uint8_t *portMode = (uint8_t *) portModeRegister(digitalPinToPort(pin));             // Get the port mode register for the pin.
  *portMode |= pinBit;                                                                 // Set pin to output mode.
#else
  pinMode(pin, OUTPUT);                                                                // Set pin to output mode.
#endif
  while (millis() < endtime) { // Loop for the desired duration.
#ifdef __AVR__
    *pinOutput |= pinBit;      // Set pin high.
    delayMicroseconds(notch);  // Square wave duration (how long to leave pin high).
    *pinOutput &= ~pinBit;     // Set pin low.
#else
    digitalWrite(pin,HIGH);    // Set pin high.
    delayMicroseconds(notch);  // Square wave duration (how long to leave pin high).
    digitalWrite(pin,LOW);     // Set pin low.
#endif
    delayMicroseconds(notch);  // Square wave duration (how long to leave pin low).
  }
}