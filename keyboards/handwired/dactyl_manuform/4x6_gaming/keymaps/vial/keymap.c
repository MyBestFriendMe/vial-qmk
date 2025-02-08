#include QMK_KEYBOARD_H

/*
enum layer_number {
  _QWERTY = 0,
  _LOWER = 1,
  _RAISE = 2,
  _ADJUST = 3,
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R  ,
        KC_V   , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F  ,
        KC_M   , KC_B   , KC_Z   , KC_2   , KC_C   , KC_1  ,
        TG(1)  , KC_K   , KC_LGUI, KC_G   , KC_MUTE,
                                    KC_LCTL, KC_SPC, MO(2)
    ),

    [1] = LAYOUT(
        RGB_MOD,_______,_______, KC_UP  ,_______ ,_______,
        _______,_______,KC_LEFT, KC_DOWN,KC_RGHT ,_______,
        _______,_______,RGB_TOG, UG_NEXT,_______ ,_______,
        TG(1)  ,_______,_______,_______ ,_______,
                                KC_BTN1 , KC_LCTL, MO(2)
    ),

    [2] = LAYOUT(
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,
                                _______,_______, MO(2)
    ),

    [3] = LAYOUT(
        _______,_______,_______,_______,_______,_______,
        KC_CAPS,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,
                                _______,_______,_______
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [1] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU)},
    [3] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)}
};
#endif // ENCODER MAP

/*
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),  ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif
*/


/*
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(_QWERTY, _RAISE, _LOWER, _ADJUST);
}
*/

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
const char *read_rgb_info(void);

// const char *read_mode_icon(bool swap);
const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user() {

    led_t led_state = host_keyboard_led_state();
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(rgb_state_reader(), false);
    oled_write_ln(read_layer_state(), false);
    //oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(led_state.caps_lock ? PSTR("Caps Lock On") : PSTR("Caps Lock Off"), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);

    // Host Keyboard LED Status
    //led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);

    //rgblight_get_mode(led_state_reader(), false);

    return false;
    }

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
