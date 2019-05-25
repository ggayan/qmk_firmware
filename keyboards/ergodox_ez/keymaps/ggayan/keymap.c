#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "ggayan.h"

#define _____ KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_WIN] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_ESCAPE,     KC_1,     KC_2,     KC_3,      KC_4,  KC_5, KC_GRAVE,
    KC_TAB,        KC_Q,     KC_W,     KC_E,      KC_R,  KC_T,   KC_TAB,
    KC_LGUI,       KC_A,     KC_S,     KC_D,      KC_F,  KC_G,
    KC_LSFT,       KC_Z,     KC_X,     KC_C,      KC_V,  KC_B,   KC_DEL,
    OSL(L_SYMB),   KC_LCTL,  KC_LALT,  KC_LEFT,   KC_RIGHT,

                                                 LCTL(KC_C), LCTL(KC_V),
                                                                KC_LALT,
                                             KC_SPACE,KC_BSPACE,KC_LCTL,

    // right hand
    KC_EQUAL,    KC_6,   KC_7,  KC_8,   KC_9,     KC_0,          KC_MINUS,
    KC_BSPACE,   KC_Y,   KC_U,  KC_I,   KC_O,     KC_P,          KC_BSLASH,
                 KC_H,   KC_J,  KC_K,   KC_L,     KC_SCOLON,     RCTL(KC_QUOTE),
    KC_ESCAPE,   KC_N,   KC_M,  KC_COMM,KC_DOT,   KC_SLASH,      KC_RSFT,
                        KC_UP,  KC_DOWN,KC_LBRC,  KC_RBRC, KC_RCTRL,

    KC_PGUP, KC_PGDN,
    TG(L_HOTS),
    KC_RALT, MO(L_SYMB), KC_ENTER
),
[L_OSX] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_ESCAPE,      KC_1,     KC_2,      KC_3,      KC_4,   KC_5,   KC_GRAVE,
    KC_TAB,         KC_Q,     KC_W,      KC_E,      KC_R,   KC_T,   KC_TAB,
    KC_HYPR,        KC_A,     KC_S,      KC_D,      KC_F,   KC_G,
    KC_LSFT,        KC_Z,     KC_X,      KC_C,      KC_V,   KC_B,   KC_DELETE,
    OSL(L_SYMB),    KC_LCTL,  KC_LALT,   KC_LEFT,   KC_RIGHT,

                                                      LGUI(KC_C),LGUI(KC_V),
                                                              LGUI(KC_LALT),
                                                 KC_SPACE,KC_BSPACE,KC_LGUI,

    // right hand
    KC_EQUAL,    KC_6,   KC_7,  KC_8,   KC_9,     KC_0,          KC_MINUS,
    KC_BSPACE,   KC_Y,   KC_U,  KC_I,   KC_O,     KC_P,          KC_BSLASH,
                 KC_H,   KC_J,  KC_K,   KC_L,     KC_SCOLON,     GUI_T(KC_QUOT),
    KC_ESCAPE,   KC_N,   KC_M,  KC_COMM,KC_DOT,   KC_SLASH,      KC_RSFT,
                        KC_UP,  KC_DOWN,KC_LBRC,  KC_RBRC, KC_RCTRL,

    KC_PGUP, KC_PGDN,
    TG(L_HOTS),
    KC_RALT, MO(L_SYMB), KC_ENTER
),
[L_SYMB] = LAYOUT_ergodox(
    // left hand
    _____,   KC_F1,     KC_F2,      KC_F3,      KC_F4,      KC_F5,      _____,
    _____,   KC_EXLM,   KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE,    _____,
    _____,   KC_HASH,   KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRV,
    _____,   KC_PERC,   KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_TILD,    _____,
    _____,   _____,     _____,      KC_MPRV,    KC_MNXT,

                                                                  _____,_____,
                                                                        _____,
                                                        KC_VOLD,KC_VOLU,_____,
    // right hand
    RESET,    KC_F6,    KC_F7,    KC_F8,    KC_F9,  KC_F10,   KC_F11,
    KC_MAKE,  KC_UP,    KC_7,     KC_8,     KC_9,   KC_ASTR,  KC_F12,
              KC_DOWN,  KC_4,     KC_5,     KC_6,   KC_PLUS,  KC_L_OSX,
    VRSN,     KC_AMPR,  KC_1,     KC_2,     KC_3,   KC_BSLS,  KC_L_WIN,
                        _____,    KC_DOT,   KC_0,   KC_EQL,   _____,

    _____, _____,
    _____,
    _____, _____, KC_MEDIA_PLAY_PAUSE
),
[L_HOTS] = LAYOUT_ergodox(
    // left hand
    KC_ESCAPE, _____,  _____,  _____,  _____,  _____,  _____,
    KC_TAB,    _____,  _____,  _____,  _____,  _____,  _____,
    KC_F2,     _____,  _____,  _____,  _____,  _____,
    KC_LSHIFT, _____,  _____,  _____,  _____,  _____,  _____,
    KC_LCTL,   KC_LCTL,  KC_LCTL,  KC_LCTL,  KC_LALT,

                     KC_NO,  KC_NO,
                             _____,
             _____,  _____,  _____,

    // right hand (skip entirely)
    _____,_____,_____,_____,_____,_____,_____,
    _____,_____,_____,_____,_____,_____,_____,
          _____,_____,_____,_____,_____,_____,
    _____,_____,_____,_____,_____,_____,_____,
                _____,_____,_____,_____,_____,

    _____,_____,
    _____,
    _____,_____,_____
)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_init();
  rgblight_enable();
  #ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
  #endif
#endif
  // set led1 for default eeprom layer if necessary
  uint8_t default_layer = eeconfig_read_default_layer();
  if (default_layer & (1UL << L_OSX)) {
    ergodox_right_led_1_on();
  }
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  uint8_t default_layer = eeconfig_read_default_layer();

  // led1 indicates whether we're on osx or win default layouts
  // led2 indicates symbols/media layer
  // led3 indicates whether we're in gaming mode or not.
  if (default_layer & (1UL << L_OSX)) {
    ergodox_right_led_1_on();
  }

  switch (layer) {
    case L_SYMB:
      ergodox_right_led_2_on();
      break;
    case L_HOTS:
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }

  return state;
};
