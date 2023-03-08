//////////////////
// MAKERSUN.NET //
//    MAUS      //
//   040323     //
//////////////////
//
//  
#include <DigiMouse.h>
#include <Adafruit_NeoPixel.h>
//
// LED on PB0
#define LED            0
// WS2812B on PB1
#define PIN            1
#define NUMPIXELS      1
// Latching Mouse movements
uint8_t state = 0;
// boot
uint8_t boot = 0;
//
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  pinMode(LED, OUTPUT);
  DigiMouse.begin();
  pixels.begin();
  pixels.setBrightness(255);
  pixels.show();
}
////////////////////////////////////////////
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
  rainbow(40);
  state = state ^ 1;
  if (state == 1) {
    DigiMouse.moveY(1);
    analogWrite(LED, 14);
    DigiMouse.delay(2000);
    analogWrite(LED, 4);
  } else {
    DigiMouse.moveY(-1);
    analogWrite(LED, 14);
    DigiMouse.delay(2000);
    analogWrite(LED, 4);
  }
}
////////////////////////////////////////////////
///////////////////////////////////////////////
void rainbow(uint8_t wait) {
  uint16_t j;
  for (j = 0; j < 256; j++) {
    pixels.setPixelColor(0, Wheel(j));
    pixels.show();
    DigiMouse.update();
    delay(wait);
  }
}
/////////////////////////////////////////////////
/////////////////////////////////////////////////
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
    WheelPos -= 170;
    return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}
