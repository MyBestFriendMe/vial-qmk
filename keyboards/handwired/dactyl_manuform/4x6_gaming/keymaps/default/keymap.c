// Copyright 2023 Adam Tombleson (@rekarnar)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R  ,
        KC_V   , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F  ,
        KC_M   , KC_B   , KC_Z   , KC_2   , KC_C   , KC_1  ,
        TG(1)  , KC_K   , KC_LGUI, KC_G   , KC_MUTE,
                                    KC_LCTL, KC_SPC, KC_3
    ),

    [1] = LAYOUT(
        _______,_______,_______, KC_UP  ,_______ ,_______,
        _______,_______,KC_LEFT, KC_DOWN,KC_RGHT ,_______,
        _______,_______,RGB_TOG, UG_NEXT,_______ ,_______,
        _______,_______,_______,_______ ,_______,
                                KC_BTN1 , KC_LCTL, TO(0)
    ),

    [2] = LAYOUT(
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,
                                _______,_______, TO(0)
    ),

    [3] = LAYOUT(
        _______,_______,_______,_______,_______,_______,
        KC_CAPS,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,
                                _______,_______,_______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [1] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU)},
    [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT)},
};
#endif
