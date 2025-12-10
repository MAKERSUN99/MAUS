#include <Arduino.h>
#include <DigiMouse.h>
#include <Adafruit_NeoPixel.h>
#include <TaskScheduler.h>

#define PIN 1        // Pin controlling the WS2812B LED
#define NUMPIXELS 1  // Number of WS2812B LEDs
#define LED 0        // Pin for the traditional LED

// boot
uint8_t boot = 0;
// Latching Mouse movements
uint8_t state = 0;
// Variable to manage the position of rainbow colors
int rainbowIndex = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
Scheduler runner;

uint32_t Wheel(byte WheelPos);
void ledStart();
void showRainbow();
void mouseMove();

// Create a task for the rainbow
Task rainbowTask(400, TASK_FOREVER, &showRainbow);

// Create a task for the mouse
Task mouseTask(20000, TASK_FOREVER, &mouseMove);

void setup() {
  pinMode(LED, OUTPUT);
  DigiMouse.begin();
  pixels.begin();               // Initialize the WS2812B LED
  runner.init();                // Initialize the task runner
  runner.addTask(rainbowTask);  // Add the rainbow task
  runner.addTask(mouseTask);    // Add the mouse task
  rainbowTask.enable();         // Enable the rainbow task
  mouseTask.enable();           // Enable the mouse task
}

void loop() {
  ledStart();
  runner.execute();  // Execute the scheduled tasks
}

uint32_t wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;  // Invert the position
  if (WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);  // Red to Green
  } else if (WheelPos < 170) {
    WheelPos -= 85;                                            // Adjust position
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);  // Green to Blue
  } else {
    WheelPos -= 170;                                           // Adjust position
    return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);  // Blue to Red
  }
}

void ledStart() {
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
}

void showRainbow() {
  pixels.setPixelColor(0, wheel(rainbowIndex));  // Set the color of the LED
  pixels.setBrightness(255);                     // Set brightness to maximum
  pixels.show();                                 // Update the LED
  rainbowIndex = (rainbowIndex + 1) % 256;       // Increment the color index
}

void mouseMove() {
  analogWrite(LED, 2);
  state = state ^ 1;
  if (state == 1) {
    DigiMouse.moveY(1);
    analogWrite(LED, 10);
    DigiMouse.delay(250);
    analogWrite(LED, 2);
  } else {
    DigiMouse.moveY(-1);
    analogWrite(LED, 10);
    DigiMouse.delay(250);
    analogWrite(LED, 2);
  }
}