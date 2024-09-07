#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum layer_names {
  _QWERTY,
  _COLEMAK,
  _SYM,
  _NAV
};

enum {
	CA_CC_CV = 0,
	DOT_TD,
	D_COPY,
	F_PASTE,
	S_COPY,
	T_PASTE,
	A_UNDO,
	S_CUT,
	R_CUT,
	G_BOLD
};

enum custom_keycodes {
		NXTDSC = SAFE_RANGE
};


//#define CTL_PSCR LCTL_T(LCTL(KC_P))
/*
#define CTL_PSCR KC_LCTL
#define OSM_CS OSM(MOD_LCTL|MOD_LSFT)
#define T_SYM TT(_SYM)
#define T_NAV TT(_NAV)
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
#define ALT_ENT RALT_T(KC_ENTER)
#define CTL_DEL LCTL_T(KC_DEL)
#define CAD LCTL(LALT(KC_DEL))
*/

#define CTL_PSCR KC_LCTL
#define OSM_CS OSM(MOD_LCTL|MOD_LSFT)
#define OSM_AS OSM(MOD_LALT|MOD_LSFT)
#define T_SYM TT(_SYM)
#define S_SYM MO(_SYM)
#define NAV_BSP LT(_NAV,KC_BSPC)
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
#define BOLD LCTL(KC_B)
#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_RALT)
#define NAV_DEL  LT(_NAV,KC_DEL)
#define NAV_ESC  LT(_NAV,KC_ESC)
#define NAV_QUOT LT(_NAV,KC_QUOT)
#define NAV_TAB LT(_NAV,KC_TAB)
#define SFT_SPC SFT_T(KC_SPC)
#define SFT_BSP SFT_T(KC_BSPC)
#define SFT_ENT SFT_T(KC_ENTER)
#define SYM_BSP  LT(_SYM,KC_BSPC)
#define SYM_DEL  LT(_SYM,KC_DEL)
#define SYM_ENT LT(_SYM,KC_ENTER)
#define GUI_MINS LGUI_T(KC_MINS)
#define ALT_EQL RALT_T(KC_EQL)
#define ALT_ESC ALT_T(KC_ESC)
#define CTL_LPRN LCTL_T(KC_LPRN)
#define CTL_RPRN MT(MOD_RCTL | MOD_RSFT, KC_RPRN)
#define CTL_SFT KC_RCTL(KC_RSFT)
#define KC_SLSH2 KC_SLSH
#define KC_DOT2 KC_DOT
#define TD_SCLN_COLN TD(SCLN_COLN)
#define GUI_DEL LGUI_T(KC_DEL)
#define OS_SYM OSL(_SYM)
#define DEFQWE DF(_QWERTY)
#define DEFCMK DF(_COLEMAK)
#define ALT_ENT RALT_T(KC_ENTER)
#define CTL_DEL LCTL_T(KC_DEL)
#define CAD LCTL(LALT(KC_DEL))
#define ALTENT RALT(KC_ENT)
#define TGNUM TG(_NUM)
#define OS_NAV OSL(_NAV)
#define CTL_QT RCTL_T(KC_QUOT)
#define GUI_QT RGUI_T(KC_QUOT)
#define T_NAV TT(_NAV)

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
void sentence_end(qk_tap_dance_state_t *state, void *user_data);
void d_copy(qk_tap_dance_state_t *state, void *user_data);
void f_paste(qk_tap_dance_state_t *state, void *user_data);
void s_copy(qk_tap_dance_state_t *state, void *user_data);
void t_paste(qk_tap_dance_state_t *state, void *user_data);
void a_undo(qk_tap_dance_state_t *state, void *user_data);
void s_cut(qk_tap_dance_state_t *state, void *user_data);
void r_cut(qk_tap_dance_state_t *state, void *user_data);
void g_bold(qk_tap_dance_state_t *state, void *user_data);

#define TD_DOT TD(DOT_TD)
#define DCOPY TD(D_COPY)
#define FPASTE TD(F_PASTE)
#define SCOPY TD(S_COPY)
#define TPASTE TD(T_PASTE)
#define AUNDO TD(A_UNDO)
#define SCUT TD(S_CUT)
#define RCUT TD(R_CUT)
#define GBOLD TD(G_BOLD)
#define HELP KC_F1
#define SEARCH KC_F3
#define REFRSH KC_F5
#define SPELL KC_F7
#define SNDRCV KC_F9 
#define FULLSC KC_F11 
#define XCELABS KC_F4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


 [_QWERTY] = LAYOUT( \
      KC_DEL,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_GRV, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GESC, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTL_DEL,  KC_A,    SCUT,    DCOPY,    FPASTE,    GBOLD,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTL_QT, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      T_NAV,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_RBRC,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  OSM_CS, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        T_NAV, KC_LGUI, T_SYM, KC_SFTENT, SFT_SPC, SYM_BSP, KC_RALT, T_NAV \
						             //`--------------------------'  `--------------------------'
),

  [_COLEMAK] = LAYOUT( \
  KC_DEL,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_GESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTL_DEL,  KC_A,    RCUT,    SCOPY,    TPASTE,    GBOLD,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, CTL_QT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      T_NAV,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_LBRC,  KC_RBRC,       KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, OSM_CS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          T_NAV, KC_LGUI, T_SYM, KC_SFTENT, SFT_SPC, SYM_BSP, KC_RALT, T_NAV \
                                      //`--------------------------'  `--------------------------'
  ),


  [_SYM] = LAYOUT(
     KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, 						KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_CIRC,                   KC_PERC,  KC_EXLM,  KC_AT, KC_HASH,  KC_DLR,    KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS,   KC_7,    KC_8,    KC_9,    KC_0,    KC_6,                      KC_5,     KC_1,    KC_2,    KC_3,    KC_4,    KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	 KC_TRNS, KC_LCBR, KC_RCBR,  KC_LBRC, KC_RBRC, KC_PIPE,  KC_NO, KC_NO,      KC_BSLS, KC_MINS, KC_PLUS,   KC_EQL,   KC_UNDS, KC_SCLN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
							          KC_TRNS, KC_SLSH, KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_DOT, KC_TRNS
                                      //|--------------------------|  |--------------------------|
  ),

  
  [_NAV] = LAYOUT(
  //   KC_ASDN,   KC_ASUP,  KC_ASRP,   KC_ASON,   KC_ASOFF,   KC_ASTG, 						KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, 						KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     WIN_CLS, KC_F8,   KC_F9,   KC_WH_U,   KC_F10,  KC_F11,                       KC_PGUP, PREV_WD, KC_UP,   NEXT_WD, KC_HOME, DEFQWE, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_F6,  KC_WH_L,   KC_WH_D, KC_WH_R, KC_F7,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  DEFCMK, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	 KC_TRNS, KC_F1,   KC_F2,     KC_F3,     KC_F4, KC_F5,   KC_NO, KC_NO,       KC_INS,  PREV_PAR,KC_NO,   NEXT_PAR,OSM_AS,  CAD, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_ESC, KC_DEL, KC_CAPS,    NXTDSC, KC_TRNS, ALT_ESC, KC_TRNS
                                      //|--------------------------|  |--------------------------|
									  
  )
};


// Setting ADJUST layer RGB back to default
/*
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}
*/

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}



// When you add source files to SRC in rules.mk, you can use functions.
/*
const char *read_layer_state(void);
const char *read_logo(void);
const char *read_keylogs(void);
*/

const char *read_logo(void);
const char *read_keylog(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);

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

void oled_render_locked(void) {
	led_t led_state = host_keyboard_led_state();
	oled_write_P(PSTR("os: "), false);
    oled_write(oslock_str, false);
	oled_write_P(PSTR(" | LED: "),false);
    oled_write_P(led_state.num_lock ? PSTR("N") : PSTR("-"), false);
    oled_write_P(led_state.caps_lock ? PSTR("C") : PSTR("-"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("S") : PSTR("-"), false);
}
  
void oled_render_layer_state(void) {
	oled_write_P(PSTR("Layout: "), false);
	switch(get_highest_layer(default_layer_state)) {
		case _QWERTY:
			oled_write_P(PSTR("QWE"), false);
		break;
		case _COLEMAK:
			oled_write_P(PSTR("CMK"), false);
			break;
		default:
		break;
	}
	oled_write_P(PSTR(" | "), false);
    oled_write_P(PSTR("SYM"), layer_state_is(_SYM));
	oled_write_P(PSTR(" "), false);
	oled_write_P(PSTR("NAV"), layer_state_is(_NAV));
}


/*
char keylog_str[24] = {};


const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};
*/

/*
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
*/

void oled_render_keylog(void) {
	oled_write_ln(read_keylog(), false);
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



void oled_task_user(void) {
  if (is_keyboard_master()) {
       oled_render_layer_state();
       oled_render_keylog();
	   oled_render_locked();
  } else {
    oled_render_logo();
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
  }
    switch (keycode) {	
	case NXTDSC:
	if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_ESC));
		SEND_STRING(SS_DELAY(150));
		SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_UP))));
    } 
	break;
		
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
		case FPASTE:
		case SCOPY:
		case TPASTE:
		case SCUT:
		case RCUT:
		case AUNDO:
		case GBOLD:
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

TAP_HOLD(d_copy,KC_D, KC_C);
TAP_HOLD(s_copy,KC_S, KC_C);
TAP_HOLD(f_paste,KC_F, KC_V);
TAP_HOLD(t_paste,KC_T, KC_V);
TAP_HOLD(a_undo,KC_A, KC_Z);
TAP_HOLD(s_cut,KC_S, KC_X);
TAP_HOLD(r_cut,KC_R, KC_X);
TAP_HOLD(g_bold,KC_G, KC_B);

void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 2:
            /* Check that Shift is inactive */
            if (!(get_mods() & MOD_MASK_SHIFT)) {
                tap_code(KC_SPC);
                /* Internal code of OSM(MOD_LSFT) */
                add_oneshot_mods(MOD_BIT(KC_LSHIFT));

            } else {
                // send ">" (KC_DOT + shift → ">")
                tap_code(KC_DOT);
            }
            break;
        case 3:
            // remove the added space of the double tap case
            tap_code(KC_BSPC);
            // replace the space with a second dot
            tap_code(KC_DOT);
            // tap the third dot
            tap_code(KC_DOT);
            break;

        // send KC_DOT on every normal tap of TD_DOT
        default:
            tap_code(KC_DOT);
    }
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [DOT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, NULL, NULL),
	[D_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,d_copy, NULL),
	[F_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,f_paste, NULL),
	[S_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,s_copy, NULL),
	[T_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,t_paste, NULL),
	[A_UNDO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,a_undo, NULL),
	[S_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,s_cut, NULL),
	[R_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,r_cut, NULL),
	[G_BOLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,g_bold, NULL)
};

