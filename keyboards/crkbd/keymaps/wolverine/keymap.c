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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _COLEMAK,
  _QWERTY,
  _MTGAP,
  _SYM,
  _NAV
};

enum {
	S_CUT = 0,
	R_CUT,
	N_CUT,
	D_COPY,
	S_COPY,
	E_COPY,
	F_PASTE,
	F_FIND,
	T_PASTE,
	A_PASTE,
	G_BOLD,
	QT_BOLD
};

enum custom_keycodes {
		COLEMAK = SAFE_RANGE,
		QWERTY,
		MTGAP
};

#define OSL_NAV OSL(_NAV)
#define PREV_WD RCTL(KC_LEFT)
#define NEXT_WD RCTL(KC_RIGHT)
#define PREV_PAR RCTL(KC_UP)
#define NEXT_PAR RCTL(KC_DOWN)

#define NAV_BSP LT(_NAV,s)
#define SYM_BSP LT(_SYM,KC_BSPC)


#define NAV_Z LT(_NAV,KC_Z)
#define NAV_SLSH LTf(_NAV,KC_SLSH)

#define SFT_SPC SFT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENTER)

#define ALT_TAB ALT_T(KC_TAB)
#define ALT_PSCR ALT_T(KC_PSCR)
#define LCA_TAB LCA_T(KC_TAB)	

#define GUI_PSCR GUI_T(KC_PSCR)

#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_TAB LCTL_T(KC_TAB)
#define CTL_BSP RCTL(KC_BSPC)
#define CTL_F LCTL_T(KC_F)

#define SYM_DEL  LT(_SYM,KC_DEL)
#define CAD LCTL(LALT(KC_DEL))
#define OSM_CS OSM(MOD_LCTL|MOD_LSFT)
#define OSM_CTRL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)

#define SCUT TD(S_CUT)
#define DCOPY TD(D_COPY)
#define FPASTE TD(F_PASTE)
#define FFIND TD(F_FIND)

#define RCUT TD(R_CUT)
#define SCOPY TD(S_COPY)
#define TPASTE TD(T_PASTE)

#define NCUT TD(N_CUT)
#define ECOPY TD(E_COPY)
#define APASTE TD(A_PASTE)

#define GBOLD TD(G_BOLD)
#define QTBOLD TD(QT_BOLD)

#define EDITCELL KC_F2
#define TGL_ABSREF KC_F4
#define REFRESH KC_F5
#define SPELL KC_F7
#define EXT_MODE KC_F8
#define RECALC_XLS KC_F9
#define FULL_SCRN KC_F11
#define FILE_E LCTL(LSFT(KC_1))

#define TAP_HOLD(_func_, _tap_, _hold_) \
void _func_(qk_tap_dance_state_t *state, void *user_data) { \
  td_state = cur_dance(state);  \
  switch (td_state) {  \
    case SINGLE_TAP:  \
      tap_code16(_tap_);  \
      break;  \
    case SINGLE_HOLD:  \
	  tap_code16(C(_hold_));  \
      break;  \
    case DOUBLE_SINGLE_TAP:  \
		tap_code16(_tap_);  \
		tap_code16(_tap_);  \
		break;  \
  }  \
}
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// function to track the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

// `finished` function for each tapdance keycode
// `finished` function for each tapdance keycode
void d_copy(qk_tap_dance_state_t *state, void *user_data);
void s_copy(qk_tap_dance_state_t *state, void *user_data);
void e_copy(qk_tap_dance_state_t *state, void *user_data);
void f_paste(qk_tap_dance_state_t *state, void *user_data);
void f_find(qk_tap_dance_state_t *state, void *user_data);
void t_paste(qk_tap_dance_state_t *state, void *user_data);
void a_paste(qk_tap_dance_state_t *state, void *user_data);
void a_undo(qk_tap_dance_state_t *state, void *user_data);
void s_cut(qk_tap_dance_state_t *state, void *user_data);
void r_cut(qk_tap_dance_state_t *state, void *user_data);
void n_cut(qk_tap_dance_state_t *state, void *user_data);
void g_bold(qk_tap_dance_state_t *state, void *user_data);
void qt_bold(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
  [_COLEMAK] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GESC,    KC_Q,    KC_W,    FFIND,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, GUI_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCA_TAB,    KC_A,    RCUT,    SCOPY,    TPASTE,    GBOLD,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, CTL_BSP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OSL_NAV,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                   KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, OSM_CS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          OSM_CTRL,   SYM_DEL, KC_SFTENT,    SFT_SPC,   SYM_BSP, KC_LALT 
                                      //`--------------------------'  `--------------------------'
  ),
  [_QWERTY] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_GESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    GUI_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LCA_TAB,  KC_A,    SCUT,    DCOPY,    FPASTE,    GBOLD,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTL_BSP,
  //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     OSL_NAV, KC_Z,    KC_X,    KC_C,    KC_V, KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM_CS,
  //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         OSM_CTRL, SYM_DEL,   KC_SFTENT,  SFT_SPC,  SYM_BSP, KC_LALT
                                      //|--------------------------|  |--------------------------|
  ),
  
    [_MTGAP] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_GESC,  KC_Y,    KC_P,    KC_O,    KC_U,    KC_J,                         KC_K,    KC_D,    KC_L,    KC_C,    KC_W,    GUI_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LCA_TAB,  KC_I,    NCUT,    ECOPY,    APASTE, QTBOLD,                      KC_M,    KC_H,    KC_T,    KC_S,    KC_R, CTL_BSP,
  //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     OSL_NAV, KC_Q,    KC_Z,    KC_COMM,    KC_DOT, KC_SLSH,                              KC_B,    KC_F,    KC_G,    KC_V,    KC_X, OSM_CS,
  //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         OSM_CTRL, SYM_DEL,   KC_SFTENT,  SFT_SPC,  SYM_BSP, KC_LALT
                                      //|--------------------------|  |--------------------------|
  ),


  
    [_SYM] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_GRV, KC_EXLM, KC_AT, KC_LPRN, KC_RPRN, KC_BSLS,                       KC_UNDS,  KC_ASTR, KC_DLR,  KC_PERC, KC_HASH,   KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TILD,   KC_7,    KC_8,    KC_9,    KC_0,    KC_6,                        KC_5,     KC_1,    KC_2,    KC_3,    KC_4,   KC_CIRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	 KC_LCBR, KC_LBRC, KC_RBRC,  KC_COLN, KC_SCLN, KC_AMPR,                     KC_PLUS, KC_MINS, KC_EQL, KC_DOT,  KC_SLSH, KC_RCBR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
										 KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //|--------------------------|  |--------------------------|
  ),
  
  
  [_NAV] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_TRNS,   FULL_SCRN,   EXT_MODE,   KC_WH_U, RECALC_XLS, TGL_ABSREF,          KC_PGUP, PREV_WD, KC_UP,   NEXT_WD, KC_HOME, KC_TRNS, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS,   REFRESH,  KC_WH_L,   KC_WH_D, KC_WH_R, KC_VOLU,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	 KC_TRNS,   SPELL,    KC_MPRV,  KC_MPLY,KC_MNXT, KC_VOLD,                      KC_ESC, PREV_PAR, OSM_ALT, NEXT_PAR,KC_TRNS,  FILE_E, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          QWERTY, COLEMAK, MTGAP,       KC_CAPS, KC_TRNS, CAD
                                      //|--------------------------|  |--------------------------|
									  
  )
};






#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

char oslock_str[5] = "----" ;

void oneshot_locked_mods_changed_user(uint8_t mods) {
  char ms = '-';
  char mc = '-';
  char ma = '-';
  char mg = '-';
  
  if (mods & MOD_MASK_SHIFT) {
    ms = 's';
  }
  if (mods & MOD_MASK_CTRL) {
    mc = 'c';
  }
  if (mods & MOD_MASK_ALT) {
    ma = 'a';
  }
  if (mods & MOD_MASK_GUI) {
    mg = 'g';
  }
    snprintf(oslock_str, sizeof(oslock_str), "%c%c%c%c", ms,mc,ma,mg);
  
}

/*
void oled_render_locked(void) {
	led_t led_state = host_keyboard_led_state();
	oled_write_P(PSTR("os: "), false);
    oled_write(oslock_str, false);
	oled_write_P(PSTR(" | LED: "),false);
    oled_write_P(led_state.num_lock ? PSTR("N") : PSTR("-"), false);
    oled_write_P(led_state.caps_lock ? PSTR("C") : PSTR("-"), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("S") : PSTR("-"), false);
}
*/
  
void oled_render_layer_state(void) {
    
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
			oled_write_P(PSTR("Qwerty"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak"), false);
            break;
		case _MTGAP:
            oled_write_P(PSTR("MTGAP"), false);
            break;
    }
	
	 switch (get_highest_layer(layer_state)) {
        case _QWERTY: 
		case _COLEMAK:
		case _MTGAP:		
            oled_write_ln_P(PSTR(" / Base"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR(" / Navigation"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR(" / Symbol"), false);
            break;
        default:
            oled_write_ln_P(PSTR(" / Unknown"), false);
    }
}

void oled_render_mod_status(led_t led_state, uint8_t modifiers) {
	oled_write_P(PSTR("CAPS"), led_state.caps_lock);
    oled_write_P(PSTR(" | "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR(" "), false);
    oled_write_ln_P(PSTR("W"), (modifiers & MOD_MASK_GUI));
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
	
	static const char PROGMEM my_logo[] = {
    // Paste the code from the previous step below this line!
0xff, 0xff, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x1f, 0x3f, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 
0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 
0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xf8, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0x03, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x03, 0x03, 
0x03, 0x81, 0x83, 0x8f, 0x8f, 0x8e, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x03, 0x03, 0x03, 0x01, 0xff, 
0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0x83, 0x83, 0x81, 
0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x01, 0x03, 0xff, 0xff, 0xff, 0x01, 0x00, 
0x00, 0x01, 0xff, 0xff, 0xff, 0xc3, 0xc3, 0xc3, 0x03, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0x1f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x08, 
0xf0, 0xe0, 0x80, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0x08, 0x0e, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0f, 0x0f, 0x1f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0xff, 0xc0, 0x80, 
0x80, 0x81, 0xc1, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x80, 0x80, 0x80, 0xff, 
0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0x81, 0x81, 0x81, 
0xff, 0xff, 0x7e, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xc0, 0x80, 0x80, 0xc0, 0xf0, 0xf0, 
0xf0, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xff, 0x7f, 0x3f, 0x00, 0x00, 
0x00, 0x80, 0xff, 0xff, 0xff, 0xc1, 0x80, 0x80, 0xc0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x7f, 0x7f, 0x70, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 
0x60, 0x60, 0x60, 0x60, 0x60, 0x70, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
	
	oled_write_raw_P(my_logo, sizeof(my_logo));
	
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
		oled_render_mod_status(host_keyboard_led_state(),get_mods() | get_oneshot_mods());
		oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  
  switch (keycode) {	
      case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY); 
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK); 
            }
            return false;  
		case MTGAP:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MTGAP); 
            }
            return false; 
  }
  return true;
}



bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_SPC:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DCOPY:
		case SCOPY:
		case ECOPY:
		case FPASTE:
		case FFIND:
		case TPASTE:
		case APASTE:
		case SCUT:
		case RCUT:
		case NCUT:
		case GBOLD:
		case QTBOLD:
		case SYM_DEL:
			return TAPPING_TERM - 50;
		default:
            return TAPPING_TERM;
    }
}

// track the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
        return SINGLE_TAP; 
    } else {
       return SINGLE_HOLD; 
    }
  }
  if (state->count == 2) {
      return DOUBLE_SINGLE_TAP; 
  }
  else {
      return 3; // any number higher than the maximum state value you return above
  } 
}

// handle the possible states for each tapdance keycode you define:

TAP_HOLD(s_cut,KC_S, KC_X);
TAP_HOLD(r_cut,KC_R, KC_X);
TAP_HOLD(n_cut,KC_N, KC_X);
TAP_HOLD(d_copy,KC_D, KC_C);
TAP_HOLD(s_copy,KC_S, KC_C);
TAP_HOLD(e_copy,KC_E, KC_C);
TAP_HOLD(f_paste,KC_F, KC_V);
TAP_HOLD(f_find,KC_F, KC_F);
TAP_HOLD(t_paste,KC_T, KC_V);
TAP_HOLD(a_paste,KC_A, KC_V);
TAP_HOLD(g_bold,KC_G, KC_B);
TAP_HOLD(qt_bold,KC_QUOT, KC_B);


qk_tap_dance_action_t tap_dance_actions[] = {
	[S_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,s_cut, NULL),
	[R_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,r_cut, NULL),
	[N_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,n_cut, NULL),
	[D_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,d_copy, NULL),
	[S_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,s_copy, NULL),
	[E_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,e_copy, NULL),
	
	[F_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,f_paste, NULL),
	[F_FIND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,f_find, NULL),
	[T_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,t_paste, NULL),
	[A_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,a_paste, NULL),
	[G_BOLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,g_bold, NULL),
	[QT_BOLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,qt_bold, NULL)
};
