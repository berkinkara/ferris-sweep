#include QMK_KEYBOARD_H

enum layer_names {
    BASE,
    SYMBOL,
    FUNCTION,
    NAVIGATION,
    MEDIA,
};

#define LSFT_F LSFT_T(KC_F)
#define LCTL_D LCTL_T(KC_D)
#define LALT_S LALT_T(KC_S)
#define LGUI_A LGUI_T(KC_A)

#define RSFT_J RSFT_T(KC_J)
#define RCTL_K RCTL_T(KC_K)
#define RALT_L RALT_T(KC_L)
#define RGUI_SCLN RGUI_T(KC_SCLN)

#define SYM_BSPC LT(SYMBOL, KC_BSPC)
#define FNC_ENT LT(FUNCTION, KC_ENT)
#define NAV_SPC LT(NAVIGATION, KC_SPC)
#define MED_TAB LT(MEDIA, KC_TAB)

#define LSFT_LPRN LSFT_T(KC_LPRN)
#define LCTL_LBRC LCTL_T(KC_LBRC)
#define LALT_LCBR LALT_T(KC_LCBR)
#define LGUI_LGRV LGUI_T(KC_GRV)

#define RSFT_UNDS RSFT_T(KC_UNDS)
#define RCTL_DQUO RCTL_T(KC_DQUO)
#define RALT_QUOT RALT_T(KC_QUOT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_2(
        KC_Q      , KC_W      , KC_E      , KC_R      , KC_T      ,        KC_Y      , KC_U      , KC_I      , KC_O      , KC_P      ,
        LGUI_A    , LALT_S    , LCTL_D    , LSFT_F    , KC_G      ,        KC_H      , RSFT_J    , RCTL_K    , RALT_L    , RGUI_SCLN ,
        KC_Z      , KC_X      , KC_C      , KC_V      , KC_B      ,        KC_N      , KC_M      , KC_COMM   , KC_DOT    , KC_SLSH   ,
                                            MED_TAB   , NAV_SPC   ,        SYM_BSPC  , FNC_ENT
    ),
    [SYMBOL] = LAYOUT_split_3x5_2(
        KC_1      , KC_2      , KC_3      , KC_4      , KC_5      ,        KC_6      , KC_7      , KC_8      , KC_9      , KC_0      ,
        LGUI_LGRV , LALT_LCBR , LCTL_LBRC , LSFT_LPRN , KC_PLUS   ,        KC_ASTR   , RSFT_UNDS , RCTL_DQUO , RALT_QUOT , RGUI_SCLN ,
        KC_BSLS   , KC_RCBR   , KC_RBRC   , KC_RPRN   , KC_MINS   ,        KC_SLSH   , KC_EQL    , KC_LT     , KC_GT     , KC_QUES   ,
                                            XXXXXXX   , KC_ESC    ,        XXXXXXX   , XXXXXXX
    ),
    [FUNCTION] = LAYOUT_split_3x5_2(
        KC_F1     , KC_F2     , KC_F3     , KC_F4     , KC_F5     ,        KC_F6     , KC_F7     , KC_F8     , KC_F9     , KC_F10    ,
        XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,        XXXXXXX   , KC_F11    , KC_F12    , XXXXXXX   , XXXXXXX   ,
        XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,        XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,
                                            XXXXXXX   , XXXXXXX   ,        XXXXXXX   , XXXXXXX
    ),
    [NAVIGATION] = LAYOUT_split_3x5_2(
        KC_ESC    , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,        KC_COPY   , KC_UNDO   , KC_INS    , XXXXXXX   , KC_DEL    ,
        KC_LGUI   , KC_LALT   , KC_LCTL   , KC_LSFT   , XXXXXXX   ,        KC_LEFT   , KC_DOWN   , KC_UP     , KC_RGHT   , XXXXXXX   ,
        KC_CAPS   , KC_CUT    , KC_COPY   , KC_PSTE   , QK_BOOT   ,        KC_HOME   , KC_PGDN   , KC_PGUP   , KC_END    , XXXXXXX   ,
                                            XXXXXXX   , XXXXXXX   ,        XXXXXXX   , XXXXXXX
    ),
    [MEDIA] = LAYOUT_split_3x5_2(
        XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,        XXXXXXX   , XXXXXXX   , KC_MRWD   , KC_MFFD   , XXXXXXX   ,
        XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,        KC_MPLY   , KC_VOLD   , KC_VOLU   , KC_MUTE   , XXXXXXX   ,
        XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,        XXXXXXX   , KC_BRID   , KC_BRIU   , XXXXXXX   , XXXXXXX   ,
                                            XXXXXXX   , XXXXXXX   ,        XXXXXXX   , XXXXXXX
    ),
};
