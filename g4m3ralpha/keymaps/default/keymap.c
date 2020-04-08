#include QMK_KEYBOARD_H

#define HOME 0
#define FN 1
#define FNCHAR 2
#define FKEYS 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[HOME] = LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5,
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
		MT(MOD_LCTL, KC_Z), MT(MOD_LALT, KC_X), LT(1, KC_C), LT(2, KC_V), MT(MOD_LSFT, KC_SPC), MT(MOD_RGUI,KC_B), MT(MOD_RALT, KC_N), MT(MOD_RCTL, KC_M)),

	[FN] = LAYOUT(
		KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_ESC, KC__MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,
		KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC,
		KC_LCTL, KC_LALT, KC_TRNS, MO(3), MT(MOD_LSFT, KC_SPC), KC_RGUI, KC_RALT, KC_RCTL),

	[FNCHAR] = LAYOUT(
		RGB_TOG, RGB_VAD, RGB_VAI, RGB_MOD, RGB_SPD,
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_GRV,KC_NO,KC_MINS,KC_EQL,KC_BSLS,KC_LBRC,KC_RBRC,KC_SCLN,KC_QUOT,KC_BSPC,
		KC_LCTL, KC_LALT, MO(3), KC_TRNS, MT(MOD_LSFT, KC_SPC), KC_COMM, KC_DOT, KC_SLSH),

	[FKEYS] = LAYOUT(
		RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_SPI,
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		KC_F11,KC_F12,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_DEL,
		KC_LCTL, KC_LALT, KC_TRNS, KC_TRNS, MT(MOD_LSFT, KC_SPC), KC_RGUI, KC_RALT, KC_RCTL),
};

void matrix_init_user(void) {
  setPinOutput(D3);
  writePinLow(D3);
  setPinOutput(D2);
  writePinLow(D2);
  setPinOutput(D0);
  writePinLow(D0);
}

void matrix_scan_user(void) {

}


uint32_t layer_state_set_user(uint32_t state)
{
    if (state & (1<<1)) {
    writePinHigh(D3);
	 writePinLow(D2);
    } else if (state & (1<<2)) {
        writePinLow(D3);
        writePinHigh(D2);
    } else if (state & (1<<3)) {
        writePinHigh(D3);
        writePinHigh(D2);
    } else {
        writePinLow(D3);
        writePinLow(D2);
    }
    return state;
}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinHigh(D0);
    } else {
        writePinLow(D0);
    }
}
