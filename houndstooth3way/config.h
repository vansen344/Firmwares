#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xFA9D
#define DEVICE_VER      0x0001
#define MANUFACTURER    Worldspawn00
#define PRODUCT         Houndstooth3Way
#define DESCRIPTION     6, 12, or 18 column split ortho keyboard

/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

/* key matrix pins */
#define MATRIX_ROW_PINS { C6, F7, D7, B1, B4, B2, B5, B6, D2, D3, E6, B3 }
#define MATRIX_COL_PINS { D1, F4, D0, F5, D4, F6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

//#ifdef BACKLIGHT_PIN
//#define BACKLIGHT_LEVELS 0
//#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN F1
//#ifdef RGB_DI_PIN
//#define RGBLIGHT_ANIMATIONS
//#define RGBLED_NUM 0
//#define RGBLIGHT_HUE_STEP 8
//#define RGBLIGHT_SAT_STEP 8
//#define RGBLIGHT_VAL_STEP 8
//#endif

