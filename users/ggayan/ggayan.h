#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"
// #define LEADER_TIMEOUT 300
// #define LEADER_PER_KEY_TIMING

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
  KC_L_TOGGLE_MAC_WIN, // swap and set default layer in EEPROM
  NEW_SAFE_RANGE
};

#endif
