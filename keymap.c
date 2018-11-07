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

  [0] = KEYMAP(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_EQUAL,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_MINUS,LT(1,KC_ESCAPE),KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_BSLASH,KC_LCTL,KC_LGUI,KC_LEFT,KC_RIGHT,KC_LALT,ALGR_T(KC_MEDIA_PLAY_PAUSE),KC_LGUI,KC_HOME,KC_SPACE,KC_DELETE,KC_END,KC_PSCREEN,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPACE,KC_LBRACKET,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_RBRACKET,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_ENTER,KC_QUOTE,KC_N,KC_M,KC_COMMA,KC_DOT,LT(2,KC_SLASH),SFT_T(KC_ESCAPE),KC_DELETE,KC_UP,KC_DOWN,MO(2),MO(1),ALT_T(KC_INSERT),CTL_T(KC_ESCAPE),KC_PGUP,KC_PGDOWN,KC_ENTER,KC_SPACE),

  [1] = KEYMAP(RESET,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_AUDIO_MUTE,KC_TRANSPARENT,KC_TRANSPARENT,KC_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_UP,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LSHIFT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_DOWN,KC_LCTL,KC_LGUI,KC_TRANSPARENT,KC_TRANSPARENT,KC_LALT,RGB_MOD,KC_TRANSPARENT,KC_TRANSPARENT,RGB_VAD,RGB_VAI,RGB_FF0000,KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,RGB_800080,KC_UP,KC_7,KC_8,KC_9,KC_ASTR,KC_F12,KC_DOWN,KC_4,KC_5,KC_6,KC_PLUS,KC_F14,RGB_FFA500,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_F15,KC_TRANSPARENT,KC_DOT,KC_0,KC_EQUAL,KC_TRANSPARENT,RGB_TOG,RGB_SLD,KC_TRANSPARENT,RGB_008000,RGB_HUD,RGB_HUI),

  [2] = KEYMAP(KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN3,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_ESCAPE,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LCTL,KC_LGUI,KC_TRANSPARENT,KC_TRANSPARENT,KC_LALT,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,KC_PAUSE,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_WWW_BACK,KC_WWW_FORWARD),

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
