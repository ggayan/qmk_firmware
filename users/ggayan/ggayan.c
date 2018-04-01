#include "ggayan.h"
#include "version.h"

// Defines actions tor my global custom keycodes. Defined in drashna.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_L_OSX:
                set_single_persistent_default_layer(L_OSX);
                return false;
                break;
            case KC_L_WIN:
                set_single_persistent_default_layer(L_WIN);
                return false;
                break;
            case KC_MAKE:
                SEND_STRING("make -j8 " QMK_KEYBOARD ":" QMK_KEYMAP ":teensy" SS_TAP(X_ENTER));
                return false;
                break;
            case VRSN:  // Prints firmware version
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
                return false;
                break;
        }
    }
    return true;
}
