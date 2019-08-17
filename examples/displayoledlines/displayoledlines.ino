#include <Arduino.h>

#include <arduinodisplay.h>

#include <arduinotick.h>

#define INTERVAL 5000
#define IDS "AB"

Tick timer(INTERVAL);

uint8_t lines = 1;

unsigned long tick;

void setup() {
  fds::display::u8g2.begin();
  fds::format::setup();
  fds::format::ids(IDS, sizeof(IDS));
}

void loop() {
  tick = millis();
  if (timer.is(tick)) {
    switch (lines) {
    case 1:
      lines = 2;
      break;
    default:
      lines = 1;
      break;
    }
    fds::
  }
  fds::display::loop();
}