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
#include "deferred_exec.h"

enum my_keycodes {
    KC_LANG1_ENT
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_GRV  ,
    KC_TAB   , KC_QUOTE     , KC_COMMA     , KC_DOT     , KC_P     , KC_Y     ,                                  KC_Z     , KC_G     , KC_C     , KC_R     , KC_L     , KC_PPLS  ,
    KC_TAB   , KC_A   , KC_O     , KC_E     , KC_U     , KC_I     ,                                  KC_D     , KC_H     , KC_T     , KC_N     , KC_S  , LT(2, KC_MINS)  ,
    KC_LSFT    ,KC_SCLN     , KC_Q     , KC_J     , KC_K     , KC_X     , KC_LCBR  ,              KC_SLSH, KC_B     , KC_M     , KC_W  , KC_V   , KC_F  , MO(3)  ,
    KC_LCTL  , KC_LALT  , KC_LALT  , KC_LANG2,KC_LGUI,LT(2,KC_SPC),KC_ENT,    KC_BSPC,KC_LANG1,_______,_______, _______ , KC_RALT  , KC_BSLS
  ),

//   [1] = LAYOUT_universal(
//     G(KC_ESC), G(KC_1)  , KC_LBRC  , G(KC_3)  , G(KC_4)  , G(KC_5)  ,                                  KC_EQL   , G(KC_6)  ,G(KC_QUOT), G(KC_8)  , G(KC_9)  ,G(KC_INT1),
//     G(KC_DEL), G(KC_Q)  , G(KC_W)  , G(KC_E)  , G(KC_R)  , G(KC_T)  ,                                  G(KC_Y)  , G(KC_U)  , G(KC_I)  , G(KC_O)  , G(KC_P)  ,G(KC_INT3),
//     G(KC_TAB), G(KC_A)  , G(KC_S)  , G(KC_D)  , KC_F  , G(KC_G)  ,                                  G(KC_H)  , G(KC_J)  , G(KC_K)  , G(KC_L)  , KC_QUOT  , G(KC_2)  ,
//     _______  , G(KC_Z)  , G(KC_X)  , G(KC_C)  , G(KC_V)  , G(KC_B)  ,G(KC_RBRC),           KC_NUHS, G(KC_N)  , G(KC_M)  ,G(KC_COMM), G(KC_DOT),G(KC_SLSH),G(KC_RSFT),
//     _______  ,G(KC_LCTL),G(KC_LALT),G(KC_LGUI), _______  , _______  , _______  ,            _______  , _______  , _______  ,G(KC_RGUI), _______  , G(KC_RALT), _______
//   ),

  [1] = LAYOUT_universal(
    _______   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , _______  ,
    _______   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , _______  ,
    _______   , KC_E     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , _______  ,
    _______    , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_BSPC  ,              KC_SLSH, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , _______  ,
    _______  , _______  , _______  , _______,_______,_______,_______,    _______,_______,_______,_______, _______ , _______  , _______
  ),
  [2] = LAYOUT_universal(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  _______  , KC_BTN3  , _______  , KC_BTN2  , _______  , KC_F12   ,
    _______  , _______  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                  KC_BTN4  , KC_BTN1  , KC_UP    , KC_BTN5  , _______  , _______  ,
    _______  , _______  , KC_1    , KC_2     , KC_3     ,S(KC_MINS), S(KC_8)  ,            S(KC_9)  , _______  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
    _______  , _______  , KC_0    , KC_DOT   , _______  , _______  , _______  ,             KC_DEL  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , _______  , _______  , _______ , _______  , _______  ,
    RGB_RMOD , KC_KB_VOLUME_DOWN,KC_KB_VOLUME_UP,KC_KB_MUTE, _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______ , _______  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EEP_RST  ,            _______  , _______  , _______  , _______  , _______   , _______  , _______  ,
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

// deferred_token mouse_layer_token = INVALID_DEFERRED_TOKEN;


// uint32_t mouse_layer_cb(uint32_t trigger_time, void *cb_arg) {
//     layer_off(2);
//     mouse_layer_token = INVALID_DEFERRED_TOKEN;
//     return 0;
// }

// report_mouse_t pointing_device_task_user(report_mouse_t report) {
//     if (report.x != 0 && report.y != 0) {
//         layer_on(2);
// 	if (mouse_layer_token == INVALID_DEFERRED_TOKEN) {
//             mouse_layer_token = defer_exec(1000, mouse_layer_cb, NULL);
// 	} else {
//             extend_deferred_exec(mouse_layer_token, 1000);
//         }
//     }
//     return report;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static uint16_t mem_keycode;
    // uint16_t prev_keycode = mem_keycode;
    // bool is_tapped = ((!record->event.pressed) && (keycode == prev_keycode));
    // mem_keycode = keycode;
    switch (keycode) {
        case KC_LGUI:
        if(record->event.pressed) {
            register_code(KC_LGUI);
            layer_on(1);
        } else {
            layer_off(1);
            unregister_code(KC_LGUI);
        }
        return false;
        case KC_LANG1:
        if(record->event.pressed) {
            register_code(KC_LANG1);
            unregister_code(KC_LANG1);
        } else {
            register_code(KC_LANG2);
            unregister_code(KC_LANG2);
        }
        return false;
        // case KC_LANG1_ENT:
        //     if(record->event.pressed) {
        //         register_code(KC_LANG1);
        //         unregister_code(KC_LANG1);
        //     }
        //     else {
        //         register_code(KC_LANG2);
        //         unregister_code(KC_LANG2);
        //         if(is_tapped) {
        //             tap_code(KC_ENT);
        //         }
        //     }
        //     return false;
    }
    return true;
}

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case CTL_T(KC_ENTER):
//             return TAPPING_TERM + 300; // 390ミリ秒(極端な例)
//         case LGUI_T(KC_ENTER):
//             return 39; // 高橋名人以上の素早さが必要(これも極端な例)
//         default:
//             return TAPPING_TERM; // 90ミリ秒
//     }
// }
