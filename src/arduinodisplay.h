#ifndef _FDS_ARDUINO_LIBRARY_DISPLAY_H_
#define _FDS_ARDUINO_LIBRARY_DISPLAY_H_

#include <U8g2lib.h>

#ifndef DISPLAY_FONT_TWO_LINES
#define DISPLAY_FONT_TWO_LINES u8g2_font_profont22_mf
#endif
#ifndef DISPLAY_TWO_LINES_Y1
#define DISPLAY_TWO_LINES_Y1   14
#endif
#ifndef DISPLAY_TWO_LINES_Y2
#define DISPLAY_TWO_LINES_Y2   32
#endif

namespace fds {
namespace display {

extern U8G2_SSD1306_128X32_UNIVISION_1_HW_I2C u8g2;

void logo(u8g2_uint_t w, u8g2_uint_t h, const uint8_t *bitmap);

void lines(const uint8_t& lines);

void loop();

}
}

#endif /* _FDS_ARDUINO_LIBRARY_DISPLAY_H_ */
