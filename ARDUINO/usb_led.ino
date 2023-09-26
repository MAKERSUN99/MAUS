//////////////////
// MAKERSUN.NET //
//   USB_LED    //
//   210923     //
//////////////////
//
/*
 * Demonstrate USB communications with computer
 * download this (https://github.com/digistump/DigisparkExamplePrograms/tree/master/Python/DigiUSB/windows)
 * and execute Monitor.exe
 *
 * Library used:
 * - Digispark https://github.com/ArminJo/DigistumpArduino
 * - FastLED https://github.com/FastLED/FastLED
 *
 * Hit 1 for red, 2 for green
 * Enjoy :)
*/
#include <DigiUSB.h>
#include <FastLED.h>
// LED on PB0
#define LED 0
// How many leds in your strip?
#define NUM_LEDS 1
// WS2812B on PB1
#define DATA_PIN 1
//
#define BRIGHTNESS 255
// Define the array of leds
CRGB leds[NUM_LEDS];
//
//
void setup() {
  DigiUSB.begin();
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(LED, OUTPUT);
}
//
void loop() {
  digitalWrite(LED, HIGH);
  DigiUSB.delay(500);
  digitalWrite(LED, LOW);
  //
  if (DigiUSB.available()) {
    char input = DigiUSB.read();
    if (input == '1') {
      leds[0] = CRGB::Red;
      FastLED.show();
    }
    if (input == '2') {
      leds[0] = CRGB::ForestGreen;
      FastLED.show();
    }
    DigiUSB.delay(10);
  }
}
