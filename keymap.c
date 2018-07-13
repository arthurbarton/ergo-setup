#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  =   |           | F4   |   6  |   7  |   8  |   9  |   0  |   BS   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |   -  |           |   [  |   Y  |   U  |   I  |   O  |   P  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ESC    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | ENTER  |
 * |--------+------+------+------+------+------|   \  |           |  '   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |CTRL  |Syper |   <- |  ->  |  Alt  |                                       | T->1| PRNT |  ALT | SUPER| CTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       |  <-  |  ->  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |  Up  |        |      |
 *                                 | Space|  DEL |------|       |------| Enter  |Space |
 *                                 |      |      | PgDn |       |  Dn  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
  // left hand
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,   KC_5,   KC_EQL,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,   KC_MINS,
  KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,   KC_G,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,   KC_BSLS,
  KC_LCTL,  KC_LWIN,  KC_LEFT,  KC_RGHT,  KC_LALT,
                                                  KC_HOME,  KC_END,
                                                            KC_PGUP,
                                          KC_SPC, KC_DEL,   KC_PGDN,
  // right hand
  KC_F4,    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
  KC_LBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_RBRC,
            KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,
  KC_QUOT,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                      TO(1),    KC_PSCR,  KC_LALT,  KC_RWIN,  KC_RCTL,
  KC_LEFT,  KC_RIGHT,
  KC_UP,
  KC_DOWN,  KC_ENT, KC_SPC
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |  Up  |      |      |      |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   ESC   |  <-  |  Dn  |  ->  |      |      |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       | T->0 |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Prev | Next |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Play |      |VolUp |       |      |      |      |
 *                                 |Pause | Mute |------|       |------|      |      |
 *                                 |      |      |VolDn |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS

[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,   KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_UP,  KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,
       KC_ESC, KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRNS,KC_TRNS,
       KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         TO(0),KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_MPRV, KC_MNXT,
       KC_VOLU,
       KC_VOLD, KC_MUTE, KC_MPLY
),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
