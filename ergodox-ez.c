#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
  HSV_0_255_255,
  HSV_300_255_128,
  HSV_38_255_255,
  HSV_120_255_128
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_EQUAL,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_MINUS,LT(1,KC_ESCAPE),KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_BSLASH,KC_LCTRL,KC_LGUI,KC_QUOTE,KC_SLASH,KC_LALT,ALGR_T(KC_MEDIA_PLAY_PAUSE),TG(2),KC_PGUP,KC_SPACE,KC_DELETE,KC_PGDOWN,KC_PSCREEN,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPACE,KC_LBRACKET,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_RBRACKET,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_ENTER,KC_QUOTE,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,LT(1,KC_DELETE),KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,RALT_T(KC_INSERT),RCTL_T(KC_ESCAPE),KC_HOME,KC_END,KC_ENTER,KC_SPACE),

  [1] = LAYOUT_ergodox(RESET,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_AUDIO_MUTE,KC_CAPSLOCK,KC_TRANSPARENT,KC_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_UP,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LSHIFT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_DOWN,KC_LCTRL,KC_LGUI,TG(3),KC_TRANSPARENT,KC_LALT,RGB_MOD,KC_TRANSPARENT,KC_TRANSPARENT,RGB_VAD,RGB_VAI,HSV_0_255_255,KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,HSV_300_255_128,KC_UP,KC_7,KC_8,KC_9,KC_ASTR,KC_F12,KC_DOWN,KC_4,KC_5,KC_6,KC_PLUS,KC_F14,HSV_38_255_255,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_F15,KC_TRANSPARENT,KC_DOT,KC_0,KC_EQUAL,KC_TRANSPARENT,RGB_TOG,RGB_SLD,KC_TRANSPARENT,HSV_120_255_128,RGB_HUD,RGB_HUI),

  [2] = LAYOUT_ergodox(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_TAB,KC_Q,KC_W,KC_F,KC_P,KC_G,KC_MINUS,KC_ESCAPE,KC_A,KC_R,KC_S,KC_T,KC_D,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_BSLASH,KC_LCTRL,KC_LGUI,TO(3),KC_TRANSPARENT,KC_LALT,KC_BSPACE,KC_TRANSPARENT,KC_PGUP,KC_SPACE,KC_DELETE,KC_PGDOWN,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_EQUAL,KC_BSPACE,KC_LBRACKET,KC_J,KC_L,KC_U,KC_Y,KC_SCOLON,KC_RBRACKET,KC_H,KC_N,KC_E,KC_I,KC_O,KC_ENTER,KC_QUOTE,KC_K,KC_M,KC_COMMA,KC_DOT,KC_TRANSPARENT,KC_RSHIFT,KC_DELETE,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_INSERT,KC_ESCAPE,KC_HOME,KC_END,KC_ENTER,KC_SPACE),

  [3] = LAYOUT_ergodox(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,LALT(KC_F5),KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,LALT(LCTL(KC_F12)),KC_ESCAPE,KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_TRANSPARENT,KC_LCTRL,KC_CAPSLOCK,KC_TRANSPARENT,KC_TRANSPARENT,KC_LALT,KC_TRANSPARENT,TO(0),KC_PGUP,KC_SPACE,KC_DELETE,KC_PGDOWN,LALT(KC_F9),KC_F1,KC_F2,KC_F3,KC_F4,KC_TRANSPARENT,KC_BSPACE,KC_LBRACKET,KC_TRANSPARENT,KC_U,KC_I,KC_TRANSPARENT,KC_TRANSPARENT,KC_RBRACKET,KC_H,KC_J,KC_K,KC_L,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_INSERT,KC_DELETE,KC_HOME,KC_END,KC_TRANSPARENT,KC_SPACE),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    case HSV_0_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(0,255,255);
        #endif
      }
      return false;
      break;
    case HSV_300_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(300,255,128);
        #endif
      }
      return false;
      break;
    case HSV_38_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(38,255,255);
        #endif
      }
      return false;
      break;
    case HSV_120_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(120,255,128);
        #endif
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
