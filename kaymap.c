#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base
    [0] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LCTL, MO(1), KC_LALT, MO(2), KC_SPC, KC_MUTE, KC_GRV, KC_0, KC_9, KC_8, KC_7, KC_6, KC_BSPC, KC_P, KC_O, KC_I, KC_U, KC_Y, KC_QUOT, KC_SCLN, KC_L, KC_K, KC_J, KC_H, KC_BSLS, KC_SLSH, KC_DOT, KC_COMM, KC_M, KC_N, KC_RGUI, KC_RALT, KC_RCTL, MO(3), KC_ENT, KC_NO
    ),
    // Layer 1
    [1] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_D, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, BL_ON, KC_LALT, KC_LCTL, KC_TRNS, KC_ENT, KC_MUTE, KC_GRV, KC_0, KC_9, KC_8, KC_7, KC_6, KC_BSPC, KC_SCLN, KC_Y, KC_U, KC_L, KC_J, KC_QUOT, KC_O, KC_I, KC_E, KC_N, KC_H, KC_RSFT, KC_SLSH, KC_DOT, KC_COMM, KC_M, KC_K, KC_RGUI, KC_RALT, KC_RCTL, KC_TRNS, KC_BSPC, KC_NO
    ),
    // Layer 2
    [2] = LAYOUT(
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_TRNS, KC_EQL, KC_MINS, S(KC_EQL), S(KC_LBRC), S(KC_RBRC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_F10, KC_F9, KC_F8, KC_F7, KC_F6, KC_F12, KC_RBRC, KC_LBRC, KC_8, KC_7, KC_6, KC_PEQL, KC_MINS, S(KC_MINS), S(KC_8), S(KC_7), S(KC_6), S(KC_BSLS), KC_BSLS, S(KC_SCLN), KC_SCLN, KC_RBRC, KC_LBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS
    ),
    // Layer 3
    [3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_UP, KC_APP, KC_NO, KC_NO, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_CAPS, KC_TRNS, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_PSCR, KC_TRNS, KC_UP, KC_TRNS, KC_PGUP, KC_BSPC, KC_DEL, KC_RGHT, KC_DOWN, KC_LEFT, KC_PGDN, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // First encoder
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { // Second encoder
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENC_A:
            if (record->event.pressed) {
                tap_code(KC_MUTE);
            }
            return false;
    }
    return true;
}
