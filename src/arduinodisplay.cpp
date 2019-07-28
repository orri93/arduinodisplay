#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>

#include <arduinoformat.h>

//#include "pidmodbuspromicro33.h"
#include "arduinodisplay.h"

namespace fds {
namespace display {

U8G2_SSD1306_128X32_UNIVISION_1_HW_I2C u8g2(U8G2_R0);

static bool isdisplaystarting = false;
static uint8_t todisplay = 0;
static char* formated;

static void twolines();

void logo(u8g2_uint_t w, u8g2_uint_t h, const uint8_t *bitmap) {
  // picture loop
  u8g2.firstPage();
  do {
    u8g2.drawXBMP(
      0,  /* x */
      0,  /* y */
      w,
      h,
      bitmap);
  } while( u8g2.nextPage() );
}

void lines(const uint8_t& lines) {
  todisplay = lines;
  isdisplaystarting = true;
}

void loop() {
  if(todisplay > 0) {
    if(isdisplaystarting) {
      u8g2.firstPage();
      isdisplaystarting = false;
    }

    switch(todisplay) {
    case 2:
      twolines();
      break;
    }

    if(!u8g2.nextPage()) {
      todisplay = 0;
    }
  }
}

void twolines() {
  u8g2.setFont(DISPLAY_FONT_TWO_LINES);
  formated = fds::format::get(0);
  u8g2.drawStr(0, DISPLAY_TWO_LINES_Y1, formated);
  u8g2.setFont(DISPLAY_FONT_TWO_LINES);
  formated = fds::format::get(1);
  u8g2.drawStr(0, DISPLAY_TWO_LINES_Y2, formated);
}

}
}
