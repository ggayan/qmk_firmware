#include "ggayan.h"
#include "version.h"

// Defines actions tor my global custom keycodes. Defined in ggayan.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t default_layer = eeconfig_read_default_layer();

    if (record->event.pressed) {
        switch (keycode) {
            case KC_L_TOGGLE_MAC_WIN:
                if (default_layer & (1UL << L_OSX)) {  // swap to windows
                    set_single_persistent_default_layer(L_WIN);
                } else {  // swap to mac
                    set_single_persistent_default_layer(L_OSX);
                }
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
