/* Copyright 2017 Wunder
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MAGIC = SAFE_RANGE,
  SMART_RESET,
};

enum layers_keymap {
  _QWERTY = 0,
  _FUNCTION,
  _MAGIC,
  _SHIFTMAGIC,
};

#define H(x) UC(0x##x)
#define FNKEY MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | BACKSP | HOME   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \      | END    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CTRL   | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | ENTER  | ENTER  | PGUP   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | ???    | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | RSHIFT | UP     | PGDN   |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | ???    | LALT   | LWIN   | SPACE  | SPACE  | SPACE  | SPACE  | SPACE  | ALTGR  | FN     | ???    | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x15(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,  \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,  KC_PGUP, \
  KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
  KC_LCTL, _______, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC,  MAGIC,   FNKEY,   _______, KC_LEFT, KC_DOWN, KC_RGHT),


/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG |        | RGB RMD| RGB MD | P0     |        | P.     | PENT   | FN     |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_FUNCTION] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
    KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______,
    KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
    _______, _______, RGB_TOG, _______, RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, FNKEY,   _______, _______, _______, _______
  )
};

// Layer bitfields.
#define MAGIC_LAYER (1UL << _MAGIC)
#define SHIFTMAGIC_LAYER (1UL << _SHIFTMAGIC)
// The layers we don't touch.
#define LAYER_MASK ~(MAGIC_LAYER|SHIFTMAGIC_LAYER)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Activate the appropriate magic layer:
  //   User is holding AltGr+Shift => _SHIFTMAGIC
  //   User is holding AltGr       => _MAGIC
  //   Not holding AltGr           => None
  // We do this the efficient way, by grabbing the non-magic bits from the current layer bitmap,
  // setting the appropriate magic or shiftmagic bit, and doing an absolute layer set. (Layer
  // sets are nontrivial, so we don't want to do extras!)

  // We track shift and AltGr state on our own, because this function is called before get_mods is
  // updated!
  static bool shifted = false;
  static bool magic = false;

  if (keycode == KC_LSHIFT || keycode == KC_RSHIFT) {
    shifted = record->event.pressed;
  } else if (keycode == MAGIC) {
    magic = record->event.pressed;
  } else if (keycode == SMART_RESET) {
    // Safe reset: Only actually let this keycode through if shift is held as well. Since there's no
    // right-shift in the function layer, this means that reset is Fn+LShift+Esc, something you're
    // not likely to hit by accident. (Especially since AltGr+Esc is backtick!)
    if (record->event.pressed && shifted) {
      reset_keyboard();
      return false;
    } else if (record->event.pressed) {
      register_code(KC_GRV);
    } else {
      unregister_code(KC_GRV);
    }
  }

  // Update the layer.
  uint32_t new_layer_state = layer_state & LAYER_MASK;
  if (magic) {
    new_layer_state |= (shifted ? SHIFTMAGIC_LAYER : MAGIC_LAYER);
  }
  if (layer_state != new_layer_state) {
    layer_state_set(new_layer_state);
  }

  return true;
}

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {


}
