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
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x6B7A // kz
#define PRODUCT_ID 0x4040 // @@
#define DEVICE_VER 0x0001
#define MANUFACTURER kazKeebz
#define PRODUCT KAZATAT

#define MATRIX_ROWS 4
#define MATRIX_COLS 10

#define MATRIX_ROW_PINS { F4, F5, F6, F7 }
#define MATRIX_COL_PINS { D3, D2, D1, D0, D4, C6, D7, E6, B4, B5 }
#define RGB_DI_PIN B1

#ifdef RGBLIGHT_ENABLE
#    define RGBLED_NUM 6
#    define RGBLIGHT_HUE_STEP 6
#    define RGBLIGHT_SAT_STEP 6
#    define RGBLIGHT_VAL_STEP 6
#    define RGBLIGHT_LIMIT_VAL 200
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_ANIMATIONS
#endif

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5
