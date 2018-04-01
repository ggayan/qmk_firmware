#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"


#define KC_MPP KC_MEDIA_PLAY_PAUSE // rename media play pause for better layout

enum userspace_layers {
  L_WIN = 0, // default layer for windows
  L_OSX, // default layer for mac
  L_SYMB, // symbols and media layer
  L_HOTS, // hots layer
};

enum userspace_custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN, // type version
  KC_MAKE, // type make
  KC_L_WIN, // set windows as default layer in EEPROM
  KC_L_OSX, // set mac as a default layer in EEPROM
  NEW_SAFE_RANGE
};

#endif
