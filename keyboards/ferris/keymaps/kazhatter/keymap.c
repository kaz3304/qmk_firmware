// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _Base,
  _Num,
  _Nav,
  _Super
};

enum ferris_tap_dances {
  TD_Q_ESC,
  TD_QU_ENT
};

/*#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_SPM2 LT(2, KC_SPC)
#define KC_LSM1 LT(1, KC_LSFT)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGU CTL_T(KC_LGUI)*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_Base] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,               KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,               KC_H, KC_J, KC_K, KC_L, KC_QUOT,
    KC_Z, KC_X, KC_C, LT(_Num, KC_V), KC_B,    KC_N, LT(_Nav, KC_M), KC_COMM, KC_DOT, KC_SLSH,
                            KC_LCTL, KC_LSFT,   KC_SPC, LALT_T(KC_MINS)
  ),

  [_Num] = LAYOUT(
    _______, KC_LPRN, KC_RPRN, KC_AMPR, KC_ASTR,            KC_P7, KC_P8, KC_P9, KC_PSLS, KC_BSPC,
    _______, KC_CIRC, KC_PERC, KC_DLR, KC_EXLM,            KC_P4, KC_P5, KC_P6, KC_MINS, KC_PENT,
    KC_NLCK, KC_HASH, KC_AT, _______, KC_EXLM,            KC_P1, KC_P2, KC_P3, KC_PPLS, KC_EQL,
                                    _______, _______,   KC_P0, KC_PDOT
  ),

  [_Nav] = LAYOUT(
    _______, KC_UP, _______, _______, _______,            _______, KC_PGUP, _______, KC_LBRC, KC_RBRC,
    KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,            KC_HOME, KC_PGDN, KC_END, _______, KC_BSLS,
    _______, _______, _______, MO(_Super), _______,            _______, _______, _______, _______, KC_GRV,
                                    _______, _______,   _______, KC_LALT
  ),

  [_Super] = LAYOUT(
    _______, _______, _______, _______, RESET,            KC_F9, KC_F10, KC_F11, KC_F12, _______,
    _______, _______, _______, _______, _______,            KC_F5, KC_F6, KC_F7, KC_F8, _______,
    _______, _______, _______, _______, _______,            KC_F1, KC_F2, KC_F3, KC_F4, _______,
                                    _______, _______,   _______, _______
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_QU_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_ENT)
};

enum combos {
    QA_TAB,
    ZX_GUI,
    PQ_COLN
};

const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM GUI_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM colon_combo[] = {KC_DOT, KC_QUOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [QA_TAB]  = COMBO(tab_combo, KC_TAB),
    [ZX_GUI]  = COMBO(GUI_combo, KC_LGUI),
    [PQ_COLN] = COMBO(colon_combo, KC_SCLN)
};
