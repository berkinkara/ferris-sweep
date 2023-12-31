#include QMK_KEYBOARD_H

#include "tap_dance.h"

enum layer_names {
    BASE,
    SYMBOL,
    FUNCTION,
    NAVIGATION,
    MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_2(
        /*L11*/ TD(Q_ESCAPE),
        /*L12*/ KC_W,
        /*L13*/ KC_E,
        /*L14*/ KC_R,
        /*L15*/ KC_T,
        /*R11*/ KC_Y,
        /*R12*/ KC_U,
        /*R13*/ KC_I,
        /*R14*/ KC_O,
        /*R15*/ KC_P,
        /*L21*/ LGUI_T(KC_A),
        /*L22*/ LALT_T(KC_S),
        /*L23*/ LCTL_T(KC_D),
        /*L24*/ LSFT_T(KC_F),
        /*L25*/ KC_G,
        /*R21*/ KC_H,
        /*R22*/ RSFT_T(KC_J),
        /*R23*/ RCTL_T(KC_K),
        /*R24*/ RALT_T(KC_L),
        /*R25*/ TD(SEMICOLON_COLON),
        /*L31*/ KC_Z,
        /*L32*/ KC_X,
        /*L33*/ KC_C,
        /*L34*/ KC_V,
        /*L35*/ KC_B,
        /*R31*/ KC_N,
        /*R32*/ KC_M,
        /*R33*/ KC_COMM,
        /*R34*/ KC_DOT,
        /*R35*/ KC_SLSH,
        /*L41*/ LT(MEDIA, KC_TAB),
        /*L42*/ LT(NAVIGATION, KC_SPC),
        /*L41*/ LT(SYMBOL, KC_BSPC),
        /*L42*/ LT(FUNCTION, KC_ENT)
    ),
    [SYMBOL] = LAYOUT_split_3x5_2(
        /*L11*/ KC_1,
        /*L12*/ KC_2,
        /*L13*/ KC_3,
        /*L14*/ KC_4,
        /*L15*/ KC_5,
        /*R11*/ KC_6,
        /*R12*/ KC_7,
        /*R13*/ KC_8,
        /*R14*/ KC_9,
        /*R15*/ KC_0,
        /*L21*/ TD(GRAVE_TILDE),
        /*L22*/ TD(AMPERSAND_PIPE),
        /*L23*/ TD(BRACES),
        /*L24*/ TD(PARANTHESIS),
        /*L25*/ KC_PERC,
        /*R21*/ TD(QUESTION_EXCLAMATION),
        /*R22*/ TD(QUOTE_DOUBLEQUOTE),
        /*R23*/ TD(EQUAL_PLUS),
        /*R24*/ TD(UNDERSCORE_MINUS),
        /*R25*/ TD(SEMICOLON_COLON),
        /*L31*/ XXXXXXX,
        /*L32*/ KC_HASH,
        /*L33*/ TD(CURLY_BRACES),
        /*L34*/ KC_DLR,
        /*L35*/ XXXXXXX,
        /*R31*/ KC_AT,
        /*R32*/ TD(ASTERISK_CIRCLE),
        /*R33*/ TD(LESSTHAN_GREATERTHAN),
        /*R34*/ TD(SLASH_BACKSLASH),
        /*R35*/ XXXXXXX,
        /*L41*/ XXXXXXX,
        /*L42*/ KC_SPC,
        /*L41*/ XXXXXXX,
        /*L42*/ XXXXXXX
    ),
    [FUNCTION] = LAYOUT_split_3x5_2(
        /*L11*/ KC_F1,
        /*L12*/ KC_F2,
        /*L13*/ KC_F3,
        /*L14*/ KC_F4,
        /*L15*/ KC_F5,
        /*R11*/ KC_F6,
        /*R12*/ KC_F7,
        /*R13*/ KC_F8,
        /*R14*/ KC_F9,
        /*R15*/ KC_F10,
        /*L21*/ XXXXXXX,
        /*L22*/ XXXXXXX,
        /*L23*/ XXXXXXX,
        /*L24*/ XXXXXXX,
        /*L25*/ XXXXXXX,
        /*R21*/ XXXXXXX,
        /*R22*/ KC_F11,
        /*R23*/ KC_F12,
        /*R24*/ XXXXXXX,
        /*R25*/ XXXXXXX,
        /*L31*/ XXXXXXX,
        /*L32*/ XXXXXXX,
        /*L33*/ XXXXXXX,
        /*L34*/ XXXXXXX,
        /*L35*/ XXXXXXX,
        /*R31*/ XXXXXXX,
        /*R32*/ XXXXXXX,
        /*R33*/ XXXXXXX,
        /*R34*/ XXXXXXX,
        /*R35*/ XXXXXXX,
        /*L41*/ XXXXXXX,
        /*L42*/ XXXXXXX,
        /*L41*/ XXXXXXX,
        /*L42*/ XXXXXXX
    ),
    [NAVIGATION] = LAYOUT_split_3x5_2(
        /*L11*/ KC_ESC,
        /*L12*/ XXXXXXX,
        /*L13*/ XXXXXXX,
        /*L14*/ XXXXXXX,
        /*L15*/ XXXXXXX,
        /*R11*/ KC_COPY,
        /*R12*/ KC_UNDO,
        /*R13*/ KC_INS,
        /*R14*/ XXXXXXX,
        /*R15*/ KC_DEL,
        /*L21*/ KC_LGUI,
        /*L22*/ KC_LALT,
        /*L23*/ KC_LCTL,
        /*L24*/ KC_LSFT,
        /*L25*/ XXXXXXX,
        /*R21*/ KC_LEFT,
        /*R22*/ KC_DOWN,
        /*R23*/ KC_UP,
        /*R24*/ KC_RGHT,
        /*R25*/ XXXXXXX,
        /*L31*/ KC_CAPS,
        /*L32*/ KC_CUT,
        /*L33*/ KC_COPY,
        /*L34*/ KC_PSTE,
        /*L35*/ QK_BOOT,
        /*R31*/ KC_HOME,
        /*R32*/ KC_PGDN,
        /*R33*/ KC_PGUP,
        /*R34*/ KC_END,
        /*R35*/ XXXXXXX,
        /*L41*/ XXXXXXX,
        /*L42*/ XXXXXXX,
        /*L41*/ XXXXXXX,
        /*L42*/ XXXXXXX
    ),
    [MEDIA] = LAYOUT_split_3x5_2(
        /*L11*/ XXXXXXX,
        /*L12*/ XXXXXXX,
        /*L13*/ XXXXXXX,
        /*L14*/ XXXXXXX,
        /*L15*/ XXXXXXX,
        /*R11*/ XXXXXXX,
        /*R12*/ XXXXXXX,
        /*R13*/ KC_MRWD,
        /*R14*/ KC_MFFD,
        /*R15*/ XXXXXXX,
        /*L21*/ XXXXXXX,
        /*L22*/ XXXXXXX,
        /*L23*/ XXXXXXX,
        /*L24*/ XXXXXXX,
        /*L25*/ XXXXXXX,
        /*R21*/ KC_MPLY,
        /*R22*/ KC_VOLD,
        /*R23*/ KC_VOLU,
        /*R24*/ KC_MUTE,
        /*R25*/ XXXXXXX,
        /*L31*/ XXXXXXX,
        /*L32*/ XXXXXXX,
        /*L33*/ XXXXXXX,
        /*L34*/ XXXXXXX,
        /*L35*/ XXXXXXX,
        /*R31*/ XXXXXXX,
        /*R32*/ KC_BRID,
        /*R33*/ KC_BRIU,
        /*R34*/ XXXXXXX,
        /*R35*/ XXXXXXX,
        /*L41*/ XXXXXXX,
        /*L42*/ XXXXXXX,
        /*L41*/ XXXXXXX,
        /*L42*/ XXXXXXX
    ),
};
