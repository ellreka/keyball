/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

enum keymap_layer {
    _SHIFT = 4,
    _JAPANESE = 5,
};

enum my_keycodes {
    KC_LANG1_ENT,
    KC_CANCEL_ENT
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // DVORAK Layer(Mac)
  [0] = LAYOUT_universal(
    KC_CANCEL_ENT   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_GRV  ,
    KC_TAB   , KC_QUOTE     , KC_COMMA     , KC_DOT     , KC_P     , KC_Y     ,                                  KC_Z     , KC_G     , KC_C     , KC_R     , KC_L     , KC_PLUS  ,
    KC_TAB    , KC_A   , KC_O     , KC_E     , KC_U     , KC_I     ,                                  KC_D     , KC_H     , KC_T     , KC_N     , KC_S  , LT(2, KC_MINUS)  ,
    LM(4, MOD_LSFT)    ,KC_SCLN     , KC_Q     , KC_J     , KC_K     , KC_X     , KC_LBRC  ,              KC_RBRC, KC_B     , KC_M     , KC_W  , KC_V   , KC_F  , LT(3, KC_SLSH)  ,
    KC_LCTL  , KC_LALT  , KC_LANG2  , KC_ESC,KC_LGUI, KC_SPC, KC_ENT,                        KC_BSPC,KC_LANG1_ENT,_______,_______, _______ , KC_RALT  , KC_BSLS
  ),
  // Windows Layer
  [6] = LAYOUT_universal(
    _______   , _______     , _______     , _______     , _______     , _______     ,                                  _______     , _______     , _______     , _______     , _______     , _______  ,
    _______   , _______     , _______     , _______     , _______     , _______     ,                                  _______     , _______     , _______     , _______     , _______     , _______  ,
    _______   , _______     , _______     , _______     , _______     , _______     ,                                  _______     , _______     , _______     , _______     , _______  , _______  ,
    _______    , _______     , _______     , _______     , _______     , _______     , _______  ,              _______, _______     , _______     , _______  , _______   , _______  , _______  ,
    KC_LGUI  , _______  , _______  , _______,KC_LCTL,_______,_______,                                          _______,_______,_______,_______, _______ , _______  , _______
  ),
  // Japanese Layer
  [5] = LAYOUT_universal(
    KC_CANCEL_ENT   , _______     , _______     , _______     , _______     , _______     ,                                  _______     , _______     , _______     , _______     , _______     , _______  ,
    _______   , _______     , _______     , _______     , _______     , _______     ,                                  _______     , _______     , _______     , _______     , _______     , _______  ,
    _______   , _______     , _______     , _______     , _______     , _______     ,                                  _______     , _______     , _______     , _______     , _______  , _______  ,
    _______    , _______     , _______     , _______     , _______     , _______     , _______  ,              _______, _______     , _______     , _______  , _______   , _______  , _______  ,
    _______  , _______  , _______  , _______,_______,_______,KC_BSPC,                                          _______,_______,_______,_______, _______ , _______  , _______
  ),
  // Shift Layer
  [4] = LAYOUT_universal(
    _______   , _______     , _______     , _______     , _______     , _______     ,                                  _______     , _______     , _______     , _______     , _______     , _______  ,
    _______   , _______     , _______     , _______     , _______     , _______     ,                                  _______     , _______     , _______     , _______     , _______     , KC_UNDS  ,
    _______   , _______     , _______     , _______     , _______     , _______     ,                                  _______     , _______     , _______     , _______     , _______  , KC_PEQL  ,
    _______    , _______     , _______     , _______     , _______     , _______     , _______  ,              _______, _______     , _______     , _______  , _______   , _______  , _______  ,
    _______  , _______  , _______  , _______,_______,_______,_______,    _______,_______,_______,_______, _______ , _______  , _______
  ),
  // QWERTY(Cmd, Alt, Ctrl) Layer
  [1] = LAYOUT_universal(
    _______   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , _______  ,
    _______   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I    , KC_O     , KC_P     , _______  ,
    _______   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , _______  ,
    _______    , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , _______  ,              _______, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , _______  ,
    _______  , _______  , _______  , _______,_______,_______,_______,    _______,_______,_______,_______, _______ , _______  , _______
  ),
  // Mouse Layer
  [2] = LAYOUT_universal(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , KC_Q  , KC_W     , KC_E     , KC_R     , _______  ,                                  KC_BTN5  , _______  , KC_BTN3  , KC_BTN2  , _______  , KC_F12   ,
    _______  , KC_A  , KC_S     , KC_D     , KC_F     ,KC_T,                                  KC_BTN4  , KC_BTN1  , KC_BTN8  , KC_BTN7  , _______ , _______  ,
    _______  , KC_Z  , KC_X    , KC_C     , KC_V     ,KC_G, KC_RBRC  ,            S(KC_9)  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , KC_0    , KC_DOT   , _______  , _______  , _______  ,              _______ , _______  , _______  , _______  , _______  , _______  , _______
  ),

  // Mouse Scroll Layer
  [3] = LAYOUT_universal(
    _______  , DF(1)  , TG(6)      , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______ , _______  ,
    _______  , _______  , _______  , _______  , G(KC_PMNS)  , G(KC_PPLS) ,                                  _______  , _______  , _______  , _______ , _______  , _______  ,
    _______ , KC_KB_VOLUME_DOWN,KC_KB_VOLUME_UP,KC_KB_MUTE, _______  , _______  ,                       _______  , _______  , KC_UP  , _______ , _______ , _______  ,
    _______  , _______  , _______ , _______ , _______  , _______  , EEP_RST  ,            _______  , _______  , KC_LEFT  , KC_DOWN  , KC_RGHT   , _______  , _______  ,
    RESET    , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif

// bool macos_check(void) {
//     wait_ms(1600);
//     bool mac_mode = true;
//     tap_code(KC_NLCK);
//     wait_ms(100);
//     if (host_keyboard_leds() & (1 << USB_LED_NUM_LOCK))
//     {
//     mac_mode = false;
//     }
//     tap_code(KC_NLCK);
//     wait_ms(100);
//     if (host_keyboard_leds() & (1 << USB_LED_NUM_LOCK))
//     {
//     mac_mode = false;
//     }
//     return mac_mode;
// }

// uint16_t prev_keycode = 0x00;

static bool is_cancel_enter = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // bool is_tapped = ((!record->event.pressed) && (keycode == prev_keycode));
    // prev_keycode = keycode;
    switch (keycode) {
        // case KC_LALT:
        // case KC_LCTL:
        case KC_LGUI:
            if(record->event.pressed) {
                layer_on(1);
                tap_code(KC_LANG2);
            } else {
                layer_off(1);
                tap_code(KC_LANG2);
            }
            return true;
        // case KC_LCTL:
        // if(macos_check) {
        //     if(record->event.pressed) {
        //         register_code(keycode);
        //         layer_on(1);
        //     } else {
        //         unregister_code(keycode);
        //         layer_off(1);
        //     }
        // } else {
        //     if(record->event.pressed) {
        //         register_code(KC_LGUI);
        //     } else {
        //         unregister_code(KC_LGUI);
        //     }
        // }
        // return false;
        // case KC_LGUI:
        // if(macos_check) {
        //     if(record->event.pressed) {
        //         register_code(keycode);
        //         layer_on(1);
        //     } else {
        //         unregister_code(keycode);
        //         layer_off(1);
        //     }
        // } else {
        //     if(record->event.pressed) {
        //         register_code(KC_LCTL);
        //     } else {
        //         unregister_code(KC_LCTL);
        //     }
        // }
        // return false;
        // TapしたときはEnterを、Holdしたときは日本語入力に切り替える
        case KC_LANG1_ENT:
            if(record->event.pressed) {
                layer_on(5);
                tap_code(KC_LANG1);
            } else {
                layer_off(5);
                if(!is_cancel_enter){
                    tap_code(KC_ENT);
                }
                tap_code(KC_LANG2);
                is_cancel_enter = false;
            }
            return false;
        case KC_CANCEL_ENT:
            is_cancel_enter = true;
            // if(record->event.pressed) {
            //     is_cancel_enter = true;
            // } else {
            //     is_cancel_enter = false;
            // }
            return false;
        // case KC_ESC:
        //     if(record->event.pressed) {
        //         register_code(KC_LANG2);
        //     } else {
        //         unregister_code(KC_LANG2);
        //     }
        //     return true;
    }
    return true;
}
