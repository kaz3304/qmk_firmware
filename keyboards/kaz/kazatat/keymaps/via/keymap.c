/* Copyright 2021 kaz
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT,
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_ENT,
            KC_LCTL, MO(1), KC_LSFT, KC_SPC, MO(2), KC_SLSH
  ),

  [1] = LAYOUT(
    KC_ESC,        KC_LPRN, KC_RPRN, KC_AMPR, KC_ASTR, KC_P7, KC_P8, KC_P9, KC_DEL,  KC_BSPC,
    KC_TAB,        KC_NO,   KC_CIRC, KC_PERC, KC_AMPR, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_SCLN,
    OSM(MOD_LGUI), KC_NO,   KC_HASH, KC_AT,   KC_EXLM, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_EQL,
                            KC_TRNS, KC_TRNS, KC_LALT, KC_P0, MO(3), KC_PDOT
  ),

  [2] = LAYOUT(
    KC_NO,   KC_UP,   KC_NO,   KC_NO, KC_NO,   KC_MUTE, KC_MPLY, KC_NO,   KC_LBRC, KC_RBRC,
    KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO,   KC_MPRV, KC_PGUP, KC_MNXT, KC_NO,   KC_BSLS,
    KC_LSFT, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_HOME, KC_PGDN, KC_END,  KC_NO,   KC_GRV,
                      KC_TRNS, MO(3), KC_TRNS, KC_NO,   KC_TRNS, KC_NO
  ),

  [3] = LAYOUT(
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_VAI, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
    RGB_SAD, RGB_RMOD,KC_NO,   RGB_VAD, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
    RGB_SAI, KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,RESET,
                    KC_NO,KC_TRNS,KC_NO,KC_NO,KC_TRNS,KC_NO
     ),
};
