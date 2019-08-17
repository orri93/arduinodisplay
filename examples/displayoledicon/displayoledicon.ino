#include <arduinodisplay.h>
#include "fds-logo.h"

void setup() {
  fds::display::u8g2.begin();
  fds::display::logo(fds_logo_width, fds_logo_height, fds_logo_bits);
}

void loop() {
}