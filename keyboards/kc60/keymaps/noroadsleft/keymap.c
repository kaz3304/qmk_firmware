/* Copyright 2018-2021 James Young (@noroadsleft)
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

#include "noroadsleft.h"


// LAYER DEFINITIONS
enum layer_names {
    // BASE LAYERS
    _DV,
    _QW,
    _CM,
    // QUAKE 2 OVERLAY
    _Q2,
    // FUNCTION LAYER
    _FN,
    // OTHER LAYERS
    _NP,
    _MA,
    _SY,
};


// KEYCODE DEFINITIONS
#define FN_CAPS LT(_FN, KC_CAPS)  // Function Layer when held, Caps Lock when tapped
#define CTL_GRV MT(MOD_LCTL, KC_GRV)  // Left Control when held, Grave accent when tapped


// KEYMAPS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // BASE LAYERS

    [_DV] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS,
        FN_CAPS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          KC_ENT,
        KC_LSFT,          KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,             KC_RSFT,
        CTL_GRV, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_MA), MO(_FN), KC_RCTL
    ),

    [_QW] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        CTL_GRV, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_MA), MO(_FN), KC_RCTL
    ),

    [_CM] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
        FN_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        CTL_GRV, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_MA), MO(_FN), KC_RCTL
    ),

    // QUAKE 2 OVERLAYS

    [_Q2] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_GRV,  _______, _______,                            _______,                            _______, _______, _______, _______
    ),

    // FUNCTION LAYER

    [_FN] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_CALC, KC_APP,  _______, _______, _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_PSCR, KC_SLCK, KC_PAUS,
        _______, M_SALL,  _______, _______, _______, _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,          KC_PENT,
        _______,          M_UNDO,  M_CUT,   M_COPY,  M_PASTE, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, TG(_SY),          _______,
        _______, _______, _______,                            TG(_NP),                            _______, _______, _______, _______
    ),

    // OTHER LAYERS

    [_NP] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______,
        _______, _______, _______, _______, KC_E,    KC_F,    _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_PSLS, KC_PEQL, _______,
        _______, _______, _______, _______, KC_C,    KC_D,    _______, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PMNS,          KC_PENT,
        _______,          _______, _______, _______, KC_A,    KC_B,    _______, KC_P0,   _______, KC_PDOT, _______,          _______,
        _______, _______, _______,                            TG(_NP),                            _______, _______, _______, _______
    ),

    [_MA] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DM_REC1, DM_REC2, _______,
        _______, _______, _______, G_PUSH,  _______, _______, _______, _______, _______, _______, _______, DM_PLY1, DM_PLY2, DM_RSTP,
        _______, _______, _______, G_FTCH,  _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, G_BRCH,  _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),

    [_SY] = LAYOUT_60_ansi(
        TG(_SY), TO(_QW), TO(_DV), TO(_CM), TG(_Q2), XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, DEBUG,   XXXXXXX, VRSN,    XXXXXXX,
        XXXXXXX, XXXXXXX, M_MDSWP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, BL_DEC,  BL_TOGG, BL_INC,  BL_BRTG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, _______, XXXXXXX
    ),

};
