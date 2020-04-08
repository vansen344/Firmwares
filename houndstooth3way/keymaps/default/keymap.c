#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PSLS, KC_BSPC, 
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST, LCTL_T(KC_C), 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_P1, KC_P2, KC_P3, KC_UP, KC_TAB, LCTL_T(KC_V), 
		KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_P0, KC_PDOT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PENT),

		
		
		
		
		
	[1] = LAYOUT(
		KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_INS, KC_DEL, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

//Using the Pro micro onboard LEDs for layer state indicators (pull low to turn on)
void matrix_init_user(void) {
  setPinOutput(B0);
  writePinHigh(B0);
  setPinOutput(D5);
  writePinHigh(D5);
  
}

void matrix_scan_user(void) {

}
	
	
layer_state_t layer_state_set_user(layer_state_t state)
{
    if (layer_state_cmp(state, 1)) {
    writePinLow(B0);
	writePinHigh(D5);
    } else if (state & (1<<2)) {
        writePinHigh(B0);
        writePinLow(D5);
    } else if (state & (1<<3)) {
        writePinLow(B0);
        writePinLow(D5);
    } else {
        writePinHigh(B0);
        writePinHigh(D5);
    }
    return state;
}