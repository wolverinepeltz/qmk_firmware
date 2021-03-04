/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _COLEMAK,
  _SYM,
  _NAV
};

// Enums defined for all tap dance examples:
enum {
	//GUI_E,
	SCLN_COLN
};

//#define CTL_PSCR LCTL_T(LCTL(KC_P))
#define CTL_PSCR KC_LCTL
#define OSM_CS OSM(MOD_LCTL|MOD_LSFT)
#define T_SYM TT(_SYM)
#define S_SYM MO(_SYM)
#define NAV_BSP LT(_NAV,KC_BSPC)
#define SFT_ENT LSFT(KC_ENT) 
#define RCTL_BR C_S_T(KC_RBRACKET)
#define LCTL_BR LCTL_T(KC_LBRACKET)
#define LCT_PRN KC_LCPO
#define RCT_PRN KC_RCPC

#define PREV_WD RCTL(KC_LEFT)
#define NEXT_WD RCTL(KC_RIGHT)
#define PREV_PAR RCTL(KC_UP)
#define NEXT_PAR RCTL(KC_DOWN)


#define WIN_CLS LALT(KC_F4)

#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)

#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_RALT)

#define NAV_DEL  LT(_NAV,KC_DEL)
#define NAV_ESC  LT(_NAV,KC_ESC)
#define NAV_QUOT LT(_NAV,KC_QUOT)
#define NAV_TAB LT(_NAV,KC_TAB)

#define SFT_SPC SFT_T(KC_SPC)
#define SFT_BSP SFT_T(KC_BSPC)
#define SYM_BSP  LT(_SYM,KC_BSPC)
#define SYM_DEL  LT(_SYM,KC_DEL)
#define SYM_ENT LT(_SYM,KC_ENTER)

#define GUI_MINS LGUI_T(KC_MINS)
#define ALT_EQL RALT_T(KC_EQL)

#define CTL_LPRN LCTL_T(KC_LPRN)
#define CTL_RPRN MT(MOD_RCTL | MOD_RSFT, KC_RPRN)

#define CTL_SFT KC_RCTL(KC_RSFT)
#define KC_SLSH2 KC_SLSH
#define KC_DOT2 KC_DOT
#define TD_SCLN_COLN TD(SCLN_COLN)
//#define TD_GUI_E TD(GUI_E)
//#define WIN_E LGUI_T(LGUI(KC_E))
#define GUI_DEL LGUI_T(KC_DEL)
#define OS_SYM OSL(_SYM)
#define DEFQWE DF(_QWERTY)
#define DEFCMK DF(_COLEMAK)


// do i switch the CTRL and ALT keys?? I should also look at where I have the Mod shift to NAV, or maybe move CTRL to the other side??

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     NAV_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, NAV_QUOT,
  //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     OS_CTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM_CS,
  //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         GUI_DEL, OS_SYM,   KC_SFTENT,  SFT_SPC,  SYM_BSP, KC_RALT
                                      //|--------------------------|  |--------------------------|


  ),
  
  [_COLEMAK] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      NAV_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, NAV_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OS_CTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, OSM_CS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          GUI_DEL,   OS_SYM, KC_SFTENT,    SFT_SPC,   SYM_BSP, KC_RALT 
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_TRNS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_UNDS,                         KC_HASH,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_TILD, KC_LPRN,   KC_RPRN, KC_0,  KC_EXLM,                      KC_DLR, KC_1, KC_MINS, KC_EQL, KC_COLN, KC_CIRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	 KC_LCBR, KC_RCBR,  KC_LBRC, KC_LBRC, KC_AT, KC_AMPR,                      KC_PERC, KC_ASTR, KC_PLUS,   KC_DOT2,   KC_SLSH2, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
										 KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //|--------------------------|  |--------------------------|
  ),

   // [_SYM] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
   //  KC_CIRC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 //    KC_ESC, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN,  KC_TILD,                      KC_DLR, KC_MINS, KC_EQL, KC_UNDS, KC_COLN, KC_HASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//	 KC_TRNS, KC_LCBR,  KC_RCBR, KC_LBRC, KC_RBRC, KC_AMPR,                      KC_PERC, KC_PLUS, KC_ASTR,   KC_DOT2,   KC_SLSH2, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
///										 KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //|--------------------------|  |--------------------------|
  //),
  
  [_NAV] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     DEFQWE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_PGUP, PREV_WD, KC_UP,   NEXT_WD, KC_HOME, KC_NO, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     DEFCMK, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  WIN_CLS, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	 KC_LCTL, UNDO,    CUT,     COPY,    PASTE,   KC_CAPS,                      KC_INS,  PREV_PAR,KC_NO,   NEXT_PAR,KC_DEL,  OSM_CS, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //|--------------------------|  |--------------------------|
									  
  )
};

//const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//	[_QWERTY] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_GESC, KC_DEL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, CTL_PSCR, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM_CS, KC_LGUI, T_SYM, KC_SFTENT, KC_SPC, NAV_BSPC, KC_RALT),
//	[_SYM] = LAYOUT_split_3x6_3(KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, KC_LCTL, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_LT, KC_GT, KC_BSLS, KC_UNDS, KC_TRNS, S_SYM, SFT_ENT, KC_TRNS, KC_BSPC, KC_TRNS),
//	[_NAV] = LAYOUT_split_3x6_3(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_PGUP, PREV_WD, KC_UP, NEXT_WD, KC_HOME, RESET, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, WIN_CLS, KC_TRNS, UNDO, CUT, COPY, PASTE, KC_CAPS, KC_INS, PREV_PARA, KC_NO, NEXT_PARA, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
//};

// Tap dance functions
void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_COLN);
    } else {
        register_code(KC_SCLN);
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_COLN);
    } else {
        unregister_code(KC_SCLN);
    }
}

// All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
	//[GUI_E] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LGUI(KC_E)),
    [SCLN_COLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
            return true;
        default:
            return false;
    }
}
#endif // OLED_DRIVER_ENABLE
