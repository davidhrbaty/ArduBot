// ---------------------------------------------------------------------------
// TimerFreeTone Library - v1.1 - 04/30/2014
//
// AUTHOR/LICENSE:
// Created by Tim Eckel - teckel@leethost.com
// Copyright 2014 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
//
// LINKS:
// Project home: https://code.google.com/p/arduino-timer-free-tone/
// Blog: http://forum.arduino.cc/index.php?topic=235774.0
//
// DISCLAIMER:
// This software is furnished "as is", without technical support, and with no 
// warranty, express or implied, as to its usefulness for any purpose.
//
// PURPOSE:
// Doesn't use timers which frees up conflicts with other libraries. Compatible
// with all ATmega, ATtiny and ARM-based microcontrollers. Over 1,500 bytes
// smaller binary sketch size than the standard tone library. Exclusive use of
// port registers for AVR-based microcontrollers for fastest and smallest code.
// Close to a plug-in replacement for the standard Tone library.
//
// SYNTAX:
//   TimerFreeTone( pin, frequency, duration [, overhead ] ) - Play a note on pin at frequency in Hz for duration in milliseconds.
//     Parameters:
//       * pin        - Pin speaker is wired to (other wire to ground, be sure to add an inline 100 ohm resistor).
//       * frequency  - Play the specified frequency (should work fairly well in the 100 to 15000 Hz range).
//       * duration   - Set the duration to play in milliseconds. Range: 0 to 65535 (65.5 seconds).
//
// HISTORY:
// 04/25/2014 v1.0 - Initial release.
//
// 04/30/2014 v1.1 - Automatically sets mode of pin to OUTPUT as does the
// standard Tone library. Sets pinOutput variable to volatile to work with
// certain microcontrollers. Removed overhead parameter and calculation, fairly
// accurate anyway at audible frequencies. Even smaller binary sketch size.
//
// ---------------------------------------------------------------------------

#ifndef TimerFreeTone_h
  #define TimerFreeTone_h

  #if ARDUINO < 100
    #include <WProgram.h>
    #include <pins_arduino.h>
  #else
    #include <Arduino.h>
  #endif

  void TimerFreeTone(uint8_t pin, unsigned long frequency, unsigned int duration);
#endif