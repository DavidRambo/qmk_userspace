/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2024 David Rambo <@davidrambo>

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

enum custom_layers {
    _COLEMAK,
    _SYMBOL,
    _NUMROW,
    _NAVIGATION,
    _FKEYS,
};

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
};

// keycode shorthands
#define SPCNUM LT(_NUMROW, KC_SPC)
#define TABSYM LT(_NUMROW, KC_TAB)
#define BSPCSYM LT(_SYMBOL, KC_BSPC)
#define ESCNAV LT(_NAVIGATION, KC_ESC)
#define FKEY MO(_FKEYS)

// aliases for clarity in layering
#define SftEnt SFT_T(KC_ENT)  // Shift when held, Enter when tapped
#define BSCTL LCTL_T(KC_BSPC) // Ctrl when held, Backspace when tapped

// aliases for clarity in layering
#define C_TAB LCTL(KC_TAB)
#define A_TAB LALT(KC_TAB)
#define G_TAB LGUI(KC_TAB) // Mac: switch applications

#define CRGHT LCTL(KC_RGHT)
#define CLEFT LCTL(KC_LEFT)

// Left-hand home row mods
#define HOME_A LALT_T(KC_A)
#define HOME_R LGUI_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LGUI_T(KC_I)
#define HOME_O LALT_T(KC_O)

// internet browser tab shortcuts and window swapping
#define CTLPGDN LCTL(KC_PGDN)
#define CTLPGUP LCTL(KC_PGUP)

#define G_GRV LGUI(KC_GRV)
#define SftEnt SFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                           KC_J,  KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ESCNAV,   HOME_A, HOME_R,  HOME_S,  HOME_T,  KC_D,                           KC_H,  HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SftEnt,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, ESCNAV, BSPCSYM,      SPCNUM, KC_UNDS,  FKEY
                                      //`--------------------------'  `--------------------------'

  ),

    [_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, KC_SLSH, KC_LCBR, KC_RCBR, _______,                      UPDIR  , KC_DQUO, KC_LABK, KC_RABK, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PERC, KC_UNDS, KC_LPRN, KC_RPRN, KC_BSLS,                      KC_PIPE, KC_EQL , KC_MINS, KC_PLUS, KC_EXLM, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CIRC, KC_DLR , KC_LBRC, KC_RBRC, _______,                      KC_GRV , KC_COLN, KC_TILD, KC_HASH, KC_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     KC_SPC, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUMROW] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LBRC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                    KC_6   , KC_7   , KC_8   , KC_9  ,  KC_0   , KC_RBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSLS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDS, KC_EQL , KC_LBRC, KC_RBRC, _______,                    KC_GRV , KC_MINS, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, KC_SPC,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAVIGATION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, _______,                      C_TAB  , CLEFT  ,  KC_UP , CRGHT  , KC_DEL , _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_COPY, KC_MS_L, KC_MS_D, KC_MS_R, KC_PSTE,                      CTLPGUP, KC_LEFT, KC_DOWN, KC_RGHT, CTLPGDN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, KC_END , KC_WH_U, KC_WH_D, KC_MPLY,                      A_TAB  , KC_PGDN, KC_PGUP, _______, G_GRV  , _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_FKEYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5 ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9 ,  KC_F10 , KC_F11 ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_MOD, RGB_SAI, RGB_HUI, RGB_TOG, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_BOOT, RGB_VAD, RGB_SAD, RGB_HUD, RGB_VAI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_VOLD, KC_VOLU, KC_MPLY,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case UPDIR:
        if (record ->event.pressed) {
                SEND_STRING("../");
            }
        return false;

    }
    return true;
}
