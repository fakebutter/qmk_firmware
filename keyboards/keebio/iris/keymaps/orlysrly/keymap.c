#include QMK_KEYBOARD_H

// Layers
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _FN 4

/*
const rgblight_segment_t PROGMEM fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 2, HSV_ORANGE},
    {6, 2, HSV_ORANGE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    fn_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _FN));
    return state;
}
*/

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Aliases
#define KC_     KC_TRNS
#define KC_RST  RESET
#define KC_LWR  LOWER
#define KC_RSE  RAISE
#define KC_RGHT KC_RIGHT

#define KC_CTRL MT(MOD_LCTL, KC_ESC)
#define KC_LOCK LGUI(LALT(KC_POWER))
#define KC_SCP4 SGUI(KC_4)
#define KC_SCP5 SGUI(KC_5)
#define KC_FN   MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬─────┐
      GRV ,  1  ,  2  ,  3  ,  4  ,  5  ,                       6  ,  7  ,  8  ,  9  ,  0  , BSPC,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
      TAB ,  Q  ,  W  ,  E  ,  R  ,  T  ,                       Y  ,  U  ,  I  ,  O  ,  P  , BSLS,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
      CTRL,  A  ,  S  ,  D  ,  F  ,  G  ,                       H  ,  J  ,  K  ,  L  , SCLN, QUOT,
  //├─────┼─────┼─────┼─────┼─────┼─────┤─────┐        ┌─────├─────┼─────┼─────┼─────┼─────┼─────┤
      LSFT,  Z  ,  X  ,  C  ,  V  ,  B  , LALT,          BSPC,  N  ,  M  , COMM, DOT , SLSH, ENT ,
  //└─────┴─────┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘        └──┬──┴──┬──┴──┬──┴──┬──┴─────┴─────┴─────┘
                          LGUI ,LWR  , SPC ,                SPC , RSE ,  FN
                      // └─────┴─────┴─────┘              └─────┴─────┴─────┘
  ),

  [_LOWER] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬─────┐
          ,  F1 ,  F2 ,  F3 ,  F4 ,  F5 ,                       F6 ,  F7 ,  F8 ,  F9 , F10 ,     ,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
          , F11 , F12 ,     ,     ,     ,                       7  ,  8  ,  9  ,     ,     ,     ,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
          ,     ,     ,     ,     ,     ,                       4  ,  5  ,  6  , SLSH, ASTR,     ,
  //├─────┼─────┼─────┼─────┼─────┼─────┤─────┐        ┌─────├─────┼─────┼─────┼─────┼─────┼─────┤
          ,     ,     ,     ,     ,     , RST ,          DEL ,  1  ,  2  ,  3  , MINS, PLUS,     ,
  //└─────┴─────┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘        └──┬──┴──┬──┴──┬──┴──┬──┴─────┴─────┴─────┘
                               ,     ,     ,                    ,  0  , DOT
                      // └─────┴─────┴─────┘              └─────┴─────┴─────┘
  ),

  [_RAISE] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬─────┐
          ,     ,     ,     ,     ,     ,                          ,     ,     , MINS, EQL ,     ,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
          ,     ,     ,     ,     ,     ,                      HOME, PGDN, PGUP, END , LPRN, RPRN,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
          ,     ,     ,     ,     ,     ,                      LEFT, DOWN,  UP , RGHT, LCBR, RCBR,
  //├─────┼─────┼─────┼─────┼─────┼─────┤─────┐        ┌─────├─────┼─────┼─────┼─────┼─────┼─────┤
          ,     ,     ,     ,     ,     ,     ,              ,     ,     ,     ,     , LBRC, RBRC,
  //└─────┴─────┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘        └──┬──┴──┬──┴──┬──┴──┬──┴─────┴─────┴─────┘
                               ,     ,     ,                    ,     ,
                      // └─────┴─────┴─────┘              └─────┴─────┴─────┘
  ),

  [_FN] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬─────┐
      LOCK, SCP4, SCP5,     ,     ,     ,                          ,     ,     ,     ,     ,     ,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
          ,     ,     ,     , MPLY, VOLU,                          ,     ,     ,     ,     ,     ,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
          ,     ,     ,     , MNXT, VOLD,                          ,     ,     ,     ,     ,     ,
  //├─────┼─────┼─────┼─────┼─────┼─────┤─────┐        ┌─────├─────┼─────┼─────┼─────┼─────┼─────┤
          ,     ,     ,     ,     ,     ,     ,              ,     ,     ,     ,     ,     ,     ,
  //└─────┴─────┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘        └──┬──┴──┬──┴──┬──┴──┬──┴─────┴─────┴─────┘
                               ,     ,     ,                    ,     ,
                      // └─────┴─────┴─────┘              └─────┴─────┴─────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, RGB_TOG, RGB_MOD,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, RGB_HUD, RGB_HUI,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, RGB_SAD, RGB_SAI,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_SPD,          RGB_SPI, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

/*
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
*/
