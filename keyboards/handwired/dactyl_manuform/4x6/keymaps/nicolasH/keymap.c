#include QMK_KEYBOARD_H


#define _BASE 0

#define _SYM 1
#define _NAV 2
#define _NUM 3
#define _FUN 4

//#define _LOWER 5
//#define _RAISE 6

// Fillers to make layering more clear

#define ____ KC_TRNS

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
#define KC_MB3 KC_MS_BTN3




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



//#define RAISE MO(_RAISE)
//#define LOWER MO(_LOWER)

/*
#define FUN MO(_FUN)
#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define NUM MO(_NUM)
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (colemak-DHm)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | ESC  |   q  |   w  |   f  |   p  |   b  |                             |   j  |   l  |   u  |   y  |   ;  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | TAB  |   a  |   r  |   s  |   t  |   g  |                             |   m  |   n  |   e  |   i  |   o  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |   z  |   x  |   c  |   d  |   v  |                             |   k  |   h  |   ,  |   .  |   /  |      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |  `   |   '  |                                                         |   -  |  \    |
 *               +-------------+-------------+                             +-------------+-------------+
 *                             |      |      |                             |      |      |
 *                             +-------------+                             +-------------+
 *                                           +-------------+ +-------------+
 *                                           |      |      | |      |      |
 *                                           |------+------| |------+------|
 *                                           |      |      | |      |      |
 *                                           +-------------+ +-------------+
 */

/*[_SYM] = LAYOUT(
		_______,_______,_______,_______,_______,_______,    KC_EXLM,KC_AT  ,KC_LCBR,KC_RCBR,KC_AMPR,_______,
		_______,_______,_______,_______,_______,_______,    KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_ASTR,_______,
		_______,_______,_______,_______,_______,_______,    KC_PERC,KC_CIRC,KC_LT  ,KC_GT,  KC_DQUO,-------,
		                _______,_______,                                    KC_LBRC, KC_RBRC,
		                                _______,_______,    _______,_______,
		                                _______,_______,    _______,_______,
				                _______,_______,    _______,_______
						),
*/
  [_BASE] = LAYOUT(\
		   KC_ESC,          KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,          KC_J,           KC_L,           KC_U,         KC_Y,       KC_SCLN,   KC_DEL, /* KC_MINS */ \
		   LCTL_T(KC_TAB),  LCTL_T(KC_A),   LALT_T(KC_R),   LSFT_T(KC_S),   LGUI_T(KC_T),   KC_G,          KC_M,   RGUI_T(KC_N),   RSFT_T(KC_E),   LALT_T(KC_I),  RCTL_T(KC_O), KC_ENT,  /* KC_QUOT,*/ \
		   KC_LSFT,         KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,          KC_K,           KC_H,        KC_COMM,       KC_DOT,       KC_SLSH,   KC_RSFT, /* KC_BSLASH,*/ \
                                                    KC_GRV,         KC_QUOTE,                                                                KC_MINUS,         KC_BSLASH,                    \
		   /*		                                        LT(_NAV,KC_SPC), LT(_SYM,KC_TAB),          LT(_FUN,KC_BSPC), LT(_NUM,KC_ENT), \*/
		                                                        LT(_NUM,KC_SPC), LT(_FUN,KC_TAB),          LT(_SYM,KC_ENT), LT(_NAV,KC_BSPC), \
                                                                                KC_LGUI,         KC_LALT,          KC_RCTRL       , KC_BTN3,           \
                                                                                 KC_DQT,         KC_UNDS,          KC_WH_U        , KC_WH_D\
)

  [_SYM] = LAYOUT(
		_______,_______,_______,_______,_______,_______,    KC_EXLM,KC_AT  ,KC_LCBR,KC_RCBR,KC_AMPR,_______,
		_______,_______,_______,_______,_______,_______,    KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_ASTR,_______,
		_______,_______,_______,_______,_______,_______,    KC_PERC,KC_CIRC,KC_LT  ,KC_GT,  KC_DQUO,_______,
		                _______,_______,                                    KC_LBRC, KC_RBRC,
		                                _______,_______,    _______,_______,
		                                _______,_______,    _______,_______,
				                _______,_______,    _______,_______
						),
[_NAV] = LAYOUT(
		_______,_______,_______,_______,_______,_______,    _______,_______,KC_PGUP,_______ ,_______ ,KC_INSERT,
		_______,_______,_______,_______,_______,_______,    KC_HOME,KC_LEFT,KC_UP  ,KC_DOWN ,KC_RIGHT,KC_END ,
		_______,_______,_______,_______,_______,_______,    _______,_______,_______,KC_PGDN, _______ ,_______,
		                _______,_______,                                    _______,_______,
		                                _______,_______,    _______,_______,
		                                _______,_______,    _______,_______,
				                _______,_______,    _______,_______
		),
[_NUM] = LAYOUT(
		_______,KC_PLUS ,KC_7    ,KC_8    ,KC_9  ,KC_ASTR,  _______,_______,_______,_______,_______,_______,
		_______,KC_MINS ,KC_4    ,KC_5    ,KC_6  ,KC_SLASH, _______,_______,_______,_______,_______,_______,
		_______,KC_EQUAL,KC_1    ,KC_2    ,KC_3  ,KC_ENTER, _______,_______,_______,_______,_______,_______,
		                 KC_0    ,KC_DOT  ,                                   _______,_______,
		                                _______,_______,      _______,_______,
		                                _______,_______,      _______,_______,
				                _______,_______,      _______,_______
		),

[_FUN] = LAYOUT(
		_______,_______,KC_F7    ,KC_F8    ,KC_F9  ,KC_F10,   _______,_______,_______,_______,_______,_______,
		_______,_______,KC_F4    ,KC_F5    ,KC_F6  ,KC_F11,   _______,_______,_______,_______,_______,_______,
		_______,KC_EJCT,KC_F1    ,KC_F2    ,KC_F3  ,KC_F12,   _______,_______,_______,_______,_______,_______,
		                _______,_______,                                      _______,_______,
		                                _______,_______,      _______,_______,
		                                _______,_______,      _______,_______,
				                _______,_______,      _______,_______
		)


/*
[_LOWER] = LAYOUT(
    _______,_______,_______,_______,_______,KC_LBRC,            KC_RBRC, KC_P7, KC_P8,  KC_P9,  RESET,  KC_PLUS,   \
    _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,            KC_RPRN, KC_P4, KC_P5,  KC_P6,  KC_MINS,KC_PIPE,   \
    _______,_______,_______,_______,_______,_______,            _______, KC_P1, KC_P2,  KC_P3,  KC_EQL, KC_UNDS,   \
                                            _______,KC_PSCR,    _______, KC_P0,                                    \
                                            _______,_______,    _______,_______,                                   \
                                            _______,_______,    _______,_______,                                   \
                                            _______,_______,    _______,_______                                    \
					    ),*/

};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
