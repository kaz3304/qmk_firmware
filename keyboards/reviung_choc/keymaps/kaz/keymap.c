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
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung_choc(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_QUOT,  KC_ENT,
    KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SCLN,  KC_SLSH,
                                            LOWER,  KC_LSFT,   KC_SPC, 	   KC_LGUI,  RAISE
  ),
  
  [_LOWER] = LAYOUT_reviung_choc(
    _______,  _______,  KC_LPRN,  KC_RPRN,  KC_ASTR,   KC_AMPR,            KC_P7,	 KC_P8,	   KC_P9,	 KC_PMNS,  KC_PSLS,  KC_DEL,
    _______,  _______,  _______,  KC_CIRC,  KC_PERC,   KC_DLR,             KC_P4,	 KC_P5,	   KC_P6,	 KC_PPLS,  KC_PAST,  _______,
    _______,  _______,  _______,  KC_HASH,  KC_AT,     KC_EXLM,            KC_P1,	 KC_P2,	   KC_P3,	 KC_PDOT,  KC_EQL,	 _______,
                                            _______,   _______,  KC_ENT,   KC_P0,  _______
  ),
  
  [_RAISE] = LAYOUT_reviung_choc(
    _______,  _______,  KC_UP,    _______,  _______,   _______,            KC_MPRV,	 KC_MPLY,  KC_MNXT,	 KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_LEFT,	KC_DOWN,  KC_RGHT,  _______,   _______,            KC_MUTE,	 KC_PGUP,  KC_MSTP,  KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______,  _______,  _______,  _______,  _______,   _______,            KC_HOME,	 KC_PGDN,  KC_END,	 KC_MINS,  KC_TRNS,	 KC_GRV,
                                            _______,   _______,  _______,  _______,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung_choc(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BL_INC,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BL_BRTG,  BL_DEC,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BL_TOGG,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

