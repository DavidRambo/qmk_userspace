/* Copyright 2022 Cole Smith <cole@boardsource.xyz>
 * Copyright 2022 David Rambo <davidrambo@mailfence.com>
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

#include <stdint.h>
#include QMK_KEYBOARD_H

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX UNICODE_MODE_MACOS

enum custom_layers {
    _GRALMAK,
    _RL, // Layer for roguelikes, pairs with a numpad on _NAVRL
    _GAME,
    _SYMBOL,
    _NUMROW,
    _NAVIGATION,
    _NAVRL,
    _FKEYS,
};

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    ZT,
    ZZ,
    ZB,
};

// Layer Toggles
#define SPCNUM LT(_NUMROW, KC_SPC)
#define BSPCSYM LT(_SYMBOL, KC_BSPC)
#define ESCNAV LT(_NAVIGATION, KC_ESC)
#define FKEY MO(_FKEYS)

// aliases for clarity in layering
#define SftEnt SFT_T(KC_ENT) // Shift when held, Enter when tapped
#define OS_SFT OSM(MOD_LSFT)
#define C_TAB LCTL(KC_TAB)
#define A_TAB LALT(KC_TAB)
#define CRGHT LCTL(KC_RGHT)
#define CLEFT LCTL(KC_LEFT)
#define G_GRV LGUI(KC_GRV)

// Left-hand home row mods
#define HOME_N LALT_T(KC_N)
#define HOME_R LGUI_T(KC_R)
#define HOME_T LSFT_T(KC_T)
#define HOME_S LCTL_T(KC_S)

// Right-hand home row mods
#define HOME_H RCTL_T(KC_H)
#define HOME_A RSFT_T(KC_A)
#define HOME_E LGUI_T(KC_E)
#define HOME_I LALT_T(KC_I)

// internet browser tab shortcuts and window swapping
#define CTLPGDN LCTL(KC_PGDN)
#define CTLPGUP LCTL(KC_PGUP)

// Combos
const uint16_t PROGMEM esc_combo[]  = {KC_D, KC_W, COMBO_END};
const uint16_t PROGMEM ent_combo[]  = {KC_P, KC_COMM, COMBO_END};
const uint16_t PROGMEM lpar_combo[] = {HOME_T, HOME_E, COMBO_END};
const uint16_t PROGMEM rpar_combo[] = {HOME_S, HOME_I, COMBO_END};
const uint16_t PROGMEM kc_m_combo[] = {KC_X, KC_C, COMBO_END}; // For quick "m" access in gaming layer.
const uint16_t PROGMEM kc_g_combo[] = {KC_Z, KC_X, COMBO_END}; // For quick "g" access in gaming layer.
const uint16_t PROGMEM kc_i_combo[] = {KC_C, KC_V, COMBO_END}; // For quick "i" access in gaming layer.

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(ent_combo, KC_ENT),
    COMBO(lpar_combo, KC_LPRN),
    COMBO(rpar_combo, KC_RPRN),
    COMBO(kc_m_combo, KC_M),
    COMBO(kc_g_combo, KC_G),
    COMBO(kc_i_combo, KC_I),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off

/* Gralmak Base Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `~  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | MPLY |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   B  |   L  |   D  |   W  |   Z  |                    |   J  |   F  |   F  |   U  |   '  | BSP  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |EscNAV|   N  |   R  |   T  |   S  |   G  |-------.    ,-------|   Y  |   H  |   A  |   E  |   I  |  '   |
 * |------+------+------+------+------+------|   NO  |    |   NO  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   M  |   C  |   V  |-------|    |-------|   K  |   P  |   ,  |   .  |   /  |EntSft|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Del  | LGUI | ESC/ | /BS/SYM /       \Space \  |   _  | FKEY | RALT |
 *                   |      |      | NAV  |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_GRALMAK] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MPLY,
  KC_TAB,   KC_B,   KC_L,    KC_D,    KC_W,    KC_Z,                     KC_QUOT,KC_F,   KC_O,    KC_U,    KC_J,    KC_BSPC,
  ESCNAV,   HOME_N, HOME_R,  HOME_T,  HOME_S,  KC_G,                     KC_Y,  HOME_H,  HOME_A,  HOME_E,  HOME_I,  KC_SCLN,
  KC_LSFT,  KC_Q,   KC_X,    KC_M,    KC_C,    KC_V,   KC_MUTE,   KC_NO, KC_K,  KC_P,    KC_COMM, KC_DOT,  KC_SLSH, SftEnt,
                     MEH_T(KC_DEL), KC_LALT, OS_SFT, BSPCSYM,       SPCNUM, KC_UNDS, FKEY, KC_RALT
),

 [_RL] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,  _______,  _______,  _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, TG(_NAVRL),    _______,  _______, _______, _______
),

/* Gaming Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |  T   |  Q   |  W   |  E   |  R   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB | LSFT |  S   |  A   |  D   |  F   |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | LALT | LCTL |  Z  (G) X  (M) C  (I) V   |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /  SPC  /       \      \  |      |      |      |
 *                   |   G  |   I  |  B   |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_GAME] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, TO(0),
  KC_ESC , KC_T   , KC_Q   , KC_W   , KC_E   , KC_R   ,                      _______, _______, _______, _______, _______, _______,
  KC_TAB , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   ,                      _______, _______, _______, _______, _______, _______,
  KC_LALT, KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   ,  _______,  _______,  _______, _______, _______, _______, _______, _______,
                               KC_G,    KC_I,    KC_B,  KC_SPC ,    _______,  _______, _______, _______
),

/* Symbols Layer
 * Inspired by Pascal Getreuer's symbol layer: https://getreuer.info/posts/keyboards/symbol-layer/index.html
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ;  |   &  |  {  |   }   |   %  |                    |  ../ |   "  |   <  |   >  |   |  |      |
 * |------+------+------+-----+-------+------|                    |------+------+------+------+------+------|
 * |      |   %  |   _  |  (  |   )   |      |-------.    ,-------|   \  |   =  |   -  |   +  |   !  |      |
 * |------+------+------+-----+-------+------|       |    |       |------+------+------+------+------+------|
 * |      |   ^  |   $  |  [  |   ]   |      |-------|    |-------|   `  |   :  |   ~  |   #  |   *  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \ SPC  \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_SYMBOL] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, KC_SCLN, KC_AMPR, KC_LCBR, KC_RCBR, KC_PERC,                      UPDIR  , KC_DQUO, KC_LABK, KC_RABK, KC_PIPE, _______,
  _______, KC_PERC, KC_UNDS, KC_LPRN, KC_RPRN, _______,                      KC_BSLS, KC_EQL , KC_MINS, KC_PLUS, KC_EXLM, _______,
  _______, KC_CIRC, KC_DLR , KC_LBRC, KC_RBRC, _______,  _______,  _______,  KC_GRV , KC_COLN, KC_TILD, KC_HASH, KC_ASTR, _______,
                            _______, _______, _______,  _______,    KC_SPC , _______, _______, _______
),

/* Number Row Layer
 * This brings the numbers and their shifted keycodes down toward the home row.
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   [  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   ]  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  \|  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   =  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | TAB  |      |      |      |      |-------|    |-------|      |   —  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | ____ | ____ | ____ | / ____  /       \ ____ \  |      |      | ____ |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUMROW] = LAYOUT(
  KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                    KC_F6  , KC_F7  , KC_F8  , KC_F9 ,  KC_F10 , KC_F11 ,
  _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                    KC_6   , KC_7   , KC_8   , KC_9  ,  KC_0   , _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL ,
  _______, KC_TAB , _______, ZT     , ZZ     , ZB     , _______,  _______, _______,UC(L'—'), _______, _______, _______, _______,
                            _______, _______, _______, KC_SPC ,    _______, _______, _______, _______
),

/* Navigation
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |  UP  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | LEFT | DOWN |RIGHT |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NAVIGATION] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, MS_BTN2, MS_UP  , MS_BTN1, _______,                      C_TAB  , CLEFT  ,  KC_UP , CRGHT  , KC_DEL , _______,
  _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, _______,                      CTLPGUP, KC_LEFT, KC_DOWN, KC_RGHT, CTLPGDN, _______,
  _______, KC_HOME, KC_END , MS_WHLU, MS_WHLD, KC_MPLY,  _______,  _______,  A_TAB  , KC_PGDN, KC_PGUP, _______, G_GRV  , _______,
                            _______, _______, _______,  _______,    _______,  _______, _______, _______
),

 [_NAVRL] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, KC_P0  , KC_PSLS, KC_PAST, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, KC_P7  , KC_P8  , KC_P9  , _______, _______,
  _______, _______, _______, _______, _______, _______,                      KC_PMNS, KC_P4  , KC_P2  , KC_P6  , KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______,  _______,  _______,  _______, KC_P1  , KC_P5  , KC_P3  , _______, _______,
                            _______, _______, _______,  _______,    _______,  _______, _______, _______
),

/* Function Keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | BOOT |      |      |      |      |      |                    | BOOT |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |BRGHT-| SAT- | HUE- |BRGHT+|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |RGBMOD| SAT+ | HUE+ |RGBTOG|-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |VOL UP|VOL DN| PLAY |       |----|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_FKEYS] = LAYOUT(
  QK_BOOT, _______, _______, _______, _______, _______,                      QK_BOOT, _______, _______, _______, _______, TO(1)  ,
  _______, _______, RM_VALD, RM_SATD, RM_HUEU, RM_NEXT,                      _______, _______, _______, _______, _______, TO(2)  ,
  _______, _______, RM_VALU, RM_SATU, RM_HUEU, RM_TOGG,                      _______, _______, _______, _______, _______, TO(0)  ,
  _______, _______, _______, KC_VOLD, KC_VOLU, KC_MPLY,  _______,  _______,  UC_NEXT, _______, _______, _______, _______, _______,
                            _______, _______, _______,  _______,    _______,  _______, _______, _______
)
};

/* [_SAMPLE] = LAYOUT(
 _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______,  _______,  _______,  _______, _______, _______, _______, _______, _______,
                           _______, _______, _______,  _______,    _______,  _______, _______, _______
) */

// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(MS_WHLU);
        } else {
            tap_code(MS_WHLD);
        }
    }
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UPDIR:
            if (record->event.pressed) {
                send_string("../");
            }
            return false;
        case ZT:
            if (record->event.pressed) {
                send_string("zt");
            }
            return false;
        case ZZ:
            if (record->event.pressed) {
                send_string("zz");
            }
            return false;
        case ZB:
            if (record->event.pressed) {
                send_string("zb");
            }
            return false;
    }
    return true;
}

// Decrease the flow tap term for SPC/NumRow LT since I do add in numbers very quickly.
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        switch (keycode) {
            case LT(_NUMROW, KC_SPC):
                return 50;
            default:
                return FLOW_TAP_TERM;
        }
    }
    return 0;
}
