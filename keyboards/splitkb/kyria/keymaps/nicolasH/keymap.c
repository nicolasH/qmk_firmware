/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _CMK = 0,
    _NUM,
    _NAV,
    _FUN,
    _SYM
    // ,_ADJUST
};




// Left-hand home row mods
#define MC_A LCTL_T(KC_A)
#define MA_R LALT_T(KC_R)
#define MS_S LSFT_T(KC_S)
#define MG_T LGUI_T(KC_T)


// Right-hand home row mods
#define MG_N RGUI_T(KC_N)
#define MS_E RSFT_T(KC_E)
#define MA_I LALT_T(KC_I)
#define MC_O RCTL_T(KC_O)

#define LT_NUM_SPC LT(_NUM,KC_SPC)
#define LT_FUN_TAB LT(_FUN,KC_TAB)

#define LT_SYM_ENT LT(_SYM,KC_ENT)
#define LT_NAV_BSP LT(_NAV,KC_BSPC)


#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    ~   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   ;  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Tab|   A  |   R  |  S   |   T  |   G  |                              |   M  |   N  |   E  |   I  |  O   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    `   |   Z  |   X  |   C  |   V  |   B  | ---- | ---- |  | ---- | ---- |   K  |   H  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  "   |   '  | Esc  | Space| Tab  |  | Del  | Bksp    | Ret  l      |      |
 *                        |      |      |      | Num  | Fn   |  | Sym  | Nav  |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

  [_CMK] = LAYOUT(
      KC_TILDE,       KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                                                          KC_J,     KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_PIPE,
      LCTL_T(KC_TAB), MC_A,   MA_R,   MS_S,   MG_T,   KC_G,                                                          KC_M,     MG_N,    MS_E,    MA_I,    MC_O,     KC_BSLASH,
      KC_GRV,         KC_Z,   KC_X,   KC_C,   KC_D,   KC_V, _______, _______,                      _______, _______, KC_K,     KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_EQUAL,
                                KC_DQT, KC_QUOT,  KC_ESC,   LT_NUM_SPC,  LT_FUN_TAB,                        LT_SYM_ENT,  LT_NAV_BSP, KC_DEL,     KC_MINS, KC_UNDS
						       ),



      [_SYM] = LAYOUT(
		_______,_______, _______, _______, _______, _______,                                    KC_EXLM, KC_AT ,  KC_LCBR, KC_RCBR, KC_AMPR,_______,
		_______,RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_ASTR,_______,
		_______,_______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______,_______,  _______,_______, KC_PERC, KC_CIRC, KC_LT,   KC_GT,   KC_DQUO,_______,
		                      _______,_______,_______,_______,_______,              _______,_______,_______, KC_LBRC, KC_RBRC
		  ),
  [_NAV] = LAYOUT(
		_______,_______,_______,_______,_______,_______,                                   _______,_______,KC_PGUP,_______ ,_______, KC_INSERT,
		_______,_______,_______,_______,_______,_______,                                   KC_HOME,KC_LEFT,KC_UP  ,KC_DOWN, KC_RIGHT,KC_END ,
		_______,_______,_______,_______,_______,_______,_______,_______,  _______,_______, _______, _______,_______,KC_PGDN,_______,_______,
		                        _______,_______,_______,_______,_______,  _______,_______,_______,_______,_______
		  ),
  [_NUM] = LAYOUT(
		  _______,KC_PLUS , KC_7,    KC_8,    KC_9,  KC_ASTR,                                   _______,_______,_______,_______,_______,_______,
		  _______,KC_MINS , KC_4,    KC_5,    KC_6,  KC_SLASH,                                  _______,_______,_______,_______,_______,_______,
		  _______,KC_EQUAL, KC_1,    KC_2,    KC_3,  KC_ENTER,_______,_______,  _______,_______,_______,_______,_______,_______,_______,_______,
                                     KC_0,   KC_DOT,  _______,        _______,_______,  _______,_______,_______,_______,_______
		  ),
  [_FUN] = LAYOUT(
		  _______,_______, KC_F7,    KC_F8,   KC_F9, KC_F10,                                    _______,_______,_______,_______,_______,_______,
		  _______,_______, KC_F4,    KC_F5,   KC_F6, KC_F11,                                    _______,_______,_______,_______,_______,_______,
		  _______,KC_EJCT, KC_F1,    KC_F2,   KC_F3, KC_F12,_______,_______,    _______,_______,_______,_______,_______,_______,_______,_______,
	                                    _______,_______,_______,_______,_______,    _______,_______,_______,_______,_______
		  )

      
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); */
/* } */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_status_keymap(void) {
  // QMK Logo and version information
  //render_qmk_logo();



  //                 __________|__________
  //  oled_write_P(PSTR("Keyboard: Kyria rev1.3\n"), false);
  oled_write_P(PSTR("Keymap revision:  1.3\n"), false);
  oled_write_P(PSTR("\n"), false);
  // Host Keyboard Layer Status
  //oled_write_P(PSTR("Layer: "), false);

  switch (get_highest_layer(layer_state)) {
  case _CMK:
    //                   __________|__________
    if (is_keyboard_master()){
      oled_write_P(PSTR("  ~  Q W F P B     \n"), false);
      oled_write_P(PSTR(" TAB A R S T G     \n"), false);
      oled_write_P(PSTR("  `  Z X C D V     \n"), false);
      oled_write_P(PSTR("     \" ' ESC SPC TAB\n"), false);
    }else{
      oled_write_P(PSTR("         J L U Y ; |\n"), false);
      oled_write_P(PSTR("         M N E I O \\\n"), false);
      oled_write_P(PSTR("         K H , . / =\n"), false);
      oled_write_P(PSTR(" ENT BSP DEL - _   \n"), false);      
    }
       break;
  case _SYM:
    //                   __________|__________
    if (is_keyboard_master()){
      /* _______,_______,_______,_______,_______,_______,         */
      /* _______,RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, */
      /* _______,_______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,*/
      //                 __________|__________
      oled_write_P(PSTR("-  --SAT|HUE|INT|MOD\n"),false);
      oled_write_P(PSTR("- RGB ^   ^   ^   ^ \n"), false);
      oled_write_P(PSTR("- RGB v   v   v   v \n"), false);
      oled_write_P(PSTR("           - - - - -\n"), false);
    }
    else { //            __________|__________
      oled_write_P(PSTR("       ! @ [ ] &  --\n"),false);
      oled_write_P(PSTR("       # $ ( ) *  --\n"),false);
      oled_write_P(PSTR("       % ^ < > \"  --\n"),false);
      oled_write_P(PSTR(" -- -- --  { } \n"),false);
    }


    break;
  case _NAV:
    if (is_keyboard_master()){
      //                 __________|__________
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR("\n"), false);
    }else{
      //                 __________|__________
      oled_write_P(PSTR("    - - PGUP - - Ins\n"), false);
      oled_write_P(PSTR("   |< <  ^  v  > >|\n"), false);
      oled_write_P(PSTR("    -  - - PGDWN - -\n"), false);
      oled_write_P(PSTR("- - - - - \n"), false);
    }
    break;
  case _NUM:
    if (is_keyboard_master()){
      //                 __________|__________
      oled_write_P(PSTR(" --  + 7 8 9 *     \n"), false);
      oled_write_P(PSTR(" --  - 4 5 6 /     \n"), false);
      oled_write_P(PSTR(" --  = 1 2 3 RET   \n"), false);
      oled_write_P(PSTR("        0 . -- -- --\n"), false);	  
    }else{
      //                 __________|__________
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR("\n"), false);
    }
    break;
  case _FUN:
    if (is_keyboard_master()){    
      //                 __________|__________
      oled_write_P(PSTR("-- -- F7 F8 F9 F10 \n"), false);
      oled_write_P(PSTR("-- -- F4 F5 F6 F11 \n"), false);
      oled_write_P(PSTR("-- -- F1 F2 F3 F12 \n"), false);
      oled_write_P(PSTR("      -- -- -- -- --\n"), false);	  

    } else{
      //                 __________|__________
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR("\n"), false);
    }
    break;
  default:
    //                 __________|__________
    oled_write_P(PSTR(" ---- Undefined ---- \n"), false);    
  }
  //oled_write_P(PSTR("123456789012345678901234567890\n"), false);
  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}


void oled_task_user(void) {
  render_status_keymap();
}
#endif
