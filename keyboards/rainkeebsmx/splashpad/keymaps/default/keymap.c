#include "splashpad.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_Q, KC_W, KC_E, 
		KC_A, RGB_TOG, KC_D,
		KC_Z, KC_X, KC_C
	)
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}
