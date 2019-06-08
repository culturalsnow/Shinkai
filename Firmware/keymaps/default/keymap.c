#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _LOWER 1
#define _RAISE 2

enum {
  TD_SCCL = 0,
};

#define KC_SCCL  TD(TD_SCCL)
#define KC_BSCT LCTL_T(KC_BSPC)
#define KC_ALTB LALT_T(KC_TAB)
#define KC_ALEN LALT(KC_ENT)
#define KC_CTEN LCTL(KC_ENT)
#define KC_WLNG LALT(KC_LSFT)
#define KC_LOCK LGUI(KC_L)
#define KC_ULCK LCTL(LALT(KC_DEL))
#define KC_DSTP LGUI(KC_D)
#define KC_ESLO LT(_LOWER, KC_ESC)


qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SCCL] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
             KC_ALTB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,  \
             KC_CTEN, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCCL,  KC_ENT, \
             KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ALEN, \
                                                KC_ESLO, KC_BSCT,   KC_SPC,  MO(_RAISE)
  ),

  [_LOWER] = LAYOUT(
             KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,  \
             _______, _______, KC_F2,   KC_DSTP, _______, KC_WLNG, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_ALEN,  \
             _______, KC_F8,   _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  KC_HOME, KC_END,  _______, \
                                                 _______, KC_BSCT, KC_SPC,  KC_LOCK
  ),

  [_RAISE] = LAYOUT(
             _______,  KC_1,    KC_2,    KC_3,      KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
             _______,  _______, _______, _______,   _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
             _______, _______, _______, _______,    _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, \
                                                    KC_ULCK, KC_BSCT,   KC_SPC,  _______
  ),
};
