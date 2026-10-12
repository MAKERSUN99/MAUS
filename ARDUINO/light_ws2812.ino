//
// download https://github.com/cpldcpu/light_ws2812/blob/master/light_ws2812_Arduino/light_WS2812.zip
// install from menu: Sketch -> Include Library -> Add .zip Library
//

#include <WS2812.h>        // light_ws2812 (cpldcpu)
#include <TaskScheduler.h>
#include <DigiMouse.h>

#define PIN 1              // WS2812B
#define LED 0              // LED tradizionale

WS2812 pixel(1);
cRGB color;
Scheduler runner;

uint8_t boot = 0;
uint8_t state = 0;
uint8_t rainbowIndex = 0;

void wheel(uint8_t pos) {
  pos = 255 - pos;
  if (pos < 85) {
    color.r = 255 - pos * 3; color.g = 0; color.b = pos * 3;
  } else if (pos < 170) {
    pos -= 85;
    color.r = 0; color.g = pos * 3; color.b = 255 - pos * 3;
  } else {
    pos -= 170;
    color.r = pos * 3; color.g = 255 - pos * 3; color.b = 0;
  }
}

void showRainbow() {
  wheel(rainbowIndex++);
  pixel.set_crgb_at(0, color);
  pixel.sync();
}

void ledDim();                                  // dichiarazione anticipata
Task ledDimTask(0, TASK_ONCE, &ledDim);         // one-shot: riporta il LED a 4

void ledDim() {
  analogWrite(LED, 4);
}

void mouseMove() {
  state ^= 1;
  DigiMouse.moveY(state ? 1 : -1);
  analogWrite(LED, 20);
  ledDimTask.restartDelayed(500);               // dopo 500 ms, senza bloccare
}

void ledStart() {
  if (boot == 0) {
    digitalWrite(LED, HIGH); DigiMouse.delay(500);
    digitalWrite(LED, LOW);  DigiMouse.delay(200);
    digitalWrite(LED, HIGH); DigiMouse.delay(200);
    digitalWrite(LED, LOW);  DigiMouse.delay(200);
    boot = 1;
  }
}

Task rainbowTask(200, TASK_FOREVER, &showRainbow);
Task mouseTask(15000, TASK_FOREVER, &mouseMove);

void setup() {
  pinMode(LED, OUTPUT);
  pixel.setOutput(PIN);
  DigiMouse.begin();
  runner.init();
  runner.addTask(rainbowTask);
  runner.addTask(mouseTask);
  runner.addTask(ledDimTask);
  rainbowTask.enable();
  mouseTask.enable();
}

void loop() {
  DigiMouse.update();   // necessario: ora non c'è più il delay che lo chiamava
  ledStart();
  runner.execute();
}
