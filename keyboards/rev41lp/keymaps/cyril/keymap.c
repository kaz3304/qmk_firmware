/* Copyright 2021 cyril279
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NAVIG
};

enum custom_keycodes {
  CTLESC,
  SFTCAP
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define SPC_NAV LT(_NAVIG,KC_SPC)
#define SFT_CAP MT(MOD_LSFT, KC_CAPS)

#define LGUI_A LGUI_T(KC_A)
#define LALT_S LALT_T(KC_S)
#define LSFT_D LSFT_T(KC_D)
#define LCTL_F LCTL_T(KC_F)
#define RCTL_J RCTL_T(KC_J)
#define RSFT_K RSFT_T(KC_K)
#define RALT_L LALT_T(KC_L)
#define RGUI_SCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_rev41lp(
    KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,             KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC, LGUI_A,  LALT_S,  LSFT_D, LCTL_F,    KC_G,             KC_H,   RCTL_J,  RSFT_K,  RALT_L,  RGUI_SCLN, KC_QUOT,
    SFT_CAP,  KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,             KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
                                      KC_LALT,   LOWER,   SPC_NAV, RAISE, KC_LGUI
  ),

  [_LOWER] = LAYOUT_rev41lp(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,           KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                                 _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_rev41lp(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,           KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                                 _______, _______, _______, _______, _______
  ),

  [_NAVIG] = LAYOUT_rev41lp(
    KC_DEL,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_DEL,
    _______, _______, _______, _______, _______, _______,          _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
    _______, _______, _______, _______, _______, _______,          _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                        _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_rev41lp(
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,   BL_DEC,   RGB_TOG,            BL_BRTG,   BL_INC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                               _______, _______, _______,  _______,  _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t modclick_timer;
  switch (keycode) {
    case CTLESC:
      if(record->event.pressed) {
        modclick_timer = timer_read();
        register_code(KC_LCTL); // Change the key to be held here
      } else {
        unregister_code(KC_LCTL); // Change the key that was held here, too!
        if (timer_elapsed(modclick_timer) < TAPPING_TERM) {
          SEND_STRING(SS_TAP(X_ESCAPE)); // Change the character(s) to be sent on tap here
        }
      } return false; // We handled this keypress
    case SFTCAP:
      if(record->event.pressed) {
        modclick_timer = timer_read();
        register_code(KC_LSFT); // Change the key to be held here
      } else {
        unregister_code(KC_LSFT); // Change the key that was held here, too!
        if (timer_elapsed(modclick_timer) < TAPPING_TERM) {
          SEND_STRING(SS_TAP(X_CAPS)); // Change the character(s) to be sent on tap here
        }
      } return false; // We handled this keypress
  }
  return true; // We didn't handle other keypresses
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTLESC:
        case SFTCAP:
            return 75;
        case LGUI_A:
        case RGUI_SCLN:
        case LALT_S:
        case RALT_L:
//        case RSFT_K: // too long at 225
        case SPC_NAV:
            return 225;
        default:
            return TAPPING_TERM;
    }
}
