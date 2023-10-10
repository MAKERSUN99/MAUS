//////////////////
// MAKERSUN.NET //
//    MAUS      //
//   101023     //
//////////////////
//
// changes:
// - Use FastLED
//
#include <DigiMouse.h>
#include <FastLED.h>

// LED on PB0
#define LED 0
// WS2812B on PB1
#define DATA_PIN 1
//
#define NUM_LEDS 1      
#define LED_TYPE WS2812B 
#define BRIGHTNESS 255   
#define SATURATION 255   
//
// Latching Mouse movements
uint8_t state = 0;
// boot
uint8_t boot = 0;
//
CRGB leds[NUM_LEDS];
//
void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  pinMode(LED, OUTPUT);
  DigiMouse.begin();
}

void loop() {
  if (boot == 0) {
    digitalWrite(LED, HIGH);
    DigiMouse.delay(500);
    digitalWrite(LED, LOW);
    DigiMouse.delay(200);
    digitalWrite(LED, HIGH);
    DigiMouse.delay(200);
    digitalWrite(LED, LOW);
    DigiMouse.delay(200);
    boot = 1;
  }
  ////////////////////////////
  //digitalWrite(LED, HIGH);
  analogWrite(LED, 4);
  rainbow(120);
  state = state ^ 1;
  if (state == 1) {
    DigiMouse.moveY(1);
    analogWrite(LED, 24);
    DigiMouse.delay(1000);
    analogWrite(LED, 4);
  } else {
    DigiMouse.moveY(-1);
    analogWrite(LED, 24);
    DigiMouse.delay(1000);
    analogWrite(LED, 4);
  }
}
//
void rainbow(uint8_t wait) {
  uint16_t j;
  for (int j = 0; j < 255; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(i - (j * 2), SATURATION, BRIGHTNESS); /* The higher the value 4 the less fade there is and vice versa */ 
    }
    FastLED.show();
    delay(wait); /* Change this to your hearts desire, the lower the value the faster your colors move (and vice versa) */
  }
}
