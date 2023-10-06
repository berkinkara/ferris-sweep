#include QMK_KEYBOARD_H

#include "tap_dance.h"

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
static td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

static td_tap_t tap_states[] = {
    [AMPERSAND_PIPE] = {.is_press_action = true, .state = TD_NONE},
    [ASTERISK_CIRCLE] = {.is_press_action = true, .state = TD_NONE},
    [BRACES] = {.is_press_action = true, .state = TD_NONE},
    [EQUAL_PLUS] = {.is_press_action = true, .state = TD_NONE},
    [GRAVE_TILDE] = {.is_press_action = true, .state = TD_NONE},
    [LESSTHAN_GREATERTHAN] = {.is_press_action = true, .state = TD_NONE},
    [PARANTHESIS] = {.is_press_action = true, .state = TD_NONE},
    [Q_ESCAPE] = {.is_press_action = true, .state = TD_NONE},
    [QUESTION_EXCLAMATION] = {.is_press_action = true, .state = TD_NONE},
    [QUOTE_DOUBLEQUOTE] = {.is_press_action = true, .state = TD_NONE},
    [SEMICOLON_COLON] = {.is_press_action = true, .state = TD_NONE},
    [SLASH_BACKSLASH] = {.is_press_action = true, .state = TD_NONE},
    [UNDERSCORE_MINUS] = {.is_press_action = true, .state = TD_NONE},
    [Z_CAPSLOCK] = {.is_press_action = true, .state = TD_NONE},
};


static void ampersand_pipe_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[AMPERSAND_PIPE].state = cur_dance(state);
    switch (tap_states[AMPERSAND_PIPE].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void ampersand_pipe_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[AMPERSAND_PIPE].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[AMPERSAND_PIPE].state = TD_NONE;
}

static void asterisk_circle_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[ASTERISK_CIRCLE].state = cur_dance(state);
    switch (tap_states[ASTERISK_CIRCLE].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void asterisk_circle_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[ASTERISK_CIRCLE].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[ASTERISK_CIRCLE].state = TD_NONE;
}

static void braces_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[BRACES].state = cur_dance(state);
    switch (tap_states[BRACES].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void braces_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[BRACES].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[BRACES].state = TD_NONE;
}

static void curly_braces_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[CURLY_BRACES].state = cur_dance(state);
    switch (tap_states[CURLY_BRACES].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void curly_braces_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[CURLY_BRACES].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[CURLY_BRACES].state = TD_NONE;
}

static void equal_plus_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[EQUAL_PLUS].state = cur_dance(state);
    switch (tap_states[EQUAL_PLUS].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void equal_plus_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[EQUAL_PLUS].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[EQUAL_PLUS].state = TD_NONE;
}

static void grave_plus_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[GRAVE_TILDE].state = cur_dance(state);
    switch (tap_states[GRAVE_TILDE].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void grave_plus_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[GRAVE_TILDE].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[GRAVE_TILDE].state = TD_NONE;
}

static void lessthan_greaterthan_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[LESSTHAN_GREATERTHAN].state = cur_dance(state);
    switch (tap_states[LESSTHAN_GREATERTHAN].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void lessthan_greaterthan_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[LESSTHAN_GREATERTHAN].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[LESSTHAN_GREATERTHAN].state = TD_NONE;
}

static void paranthesis_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[PARANTHESIS].state = cur_dance(state);
    switch (tap_states[PARANTHESIS].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void paranthesis_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[PARANTHESIS].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[PARANTHESIS].state = TD_NONE;
}

static void q_escape_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[Q_ESCAPE].state = cur_dance(state);
    switch (tap_states[Q_ESCAPE].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void q_escape_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[Q_ESCAPE].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[Q_ESCAPE].state = TD_NONE;
}

static void question_exclamation_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[QUESTION_EXCLAMATION].state = cur_dance(state);
    switch (tap_states[QUESTION_EXCLAMATION].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void question_exclamation_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[QUESTION_EXCLAMATION].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[QUESTION_EXCLAMATION].state = TD_NONE;
}

static void quote_doublequote_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[QUOTE_DOUBLEQUOTE].state = cur_dance(state);
    switch (tap_states[QUOTE_DOUBLEQUOTE].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void quote_doublequote_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[QUOTE_DOUBLEQUOTE].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[QUOTE_DOUBLEQUOTE].state = TD_NONE;
}

static void semicolon_colon_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[SEMICOLON_COLON].state = cur_dance(state);
    switch (tap_states[SEMICOLON_COLON].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void semicolon_colon_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[SEMICOLON_COLON].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[SEMICOLON_COLON].state = TD_NONE;
}

static void slash_backslash_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[SLASH_BACKSLASH].state = cur_dance(state);
    switch (tap_states[SLASH_BACKSLASH].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void slash_backslash_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[SLASH_BACKSLASH].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[SLASH_BACKSLASH].state = TD_NONE;
}

static void underscore_minus_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[UNDERSCORE_MINUS].state = cur_dance(state);
    switch (tap_states[UNDERSCORE_MINUS].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void underscore_minus_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[UNDERSCORE_MINUS].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[UNDERSCORE_MINUS].state = TD_NONE;
}

static void z_capslock_finished(tap_dance_state_t *state, void *user_data) {
    tap_states[Z_CAPSLOCK].state = cur_dance(state);
    switch (tap_states[Z_CAPSLOCK].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

static void z_capslock_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_states[Z_CAPSLOCK].state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    tap_states[Z_CAPSLOCK].state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [AMPERSAND_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ampersand_pipe_finished, ampersand_pipe_reset),
    [ASTERISK_CIRCLE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, asterisk_circle_finished, asterisk_circle_reset),
    [BRACES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, braces_finished, braces_reset),
    [CURLY_BRACES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, curly_braces_finished, curly_braces_reset),
    [EQUAL_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, equal_plus_finished, equal_plus_reset),
    [GRAVE_TILDE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, grave_plus_finished, grave_plus_reset),
    [LESSTHAN_GREATERTHAN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lessthan_greaterthan_finished, lessthan_greaterthan_reset),
    [PARANTHESIS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, paranthesis_finished, paranthesis_reset),
    [Q_ESCAPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_escape_finished, q_escape_reset),
    [QUESTION_EXCLAMATION] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, question_exclamation_finished, question_exclamation_reset),
    [QUOTE_DOUBLEQUOTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, quote_doublequote_finished, quote_doublequote_reset),
    [SEMICOLON_COLON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, semicolon_colon_finished, semicolon_colon_reset),
    [SLASH_BACKSLASH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slash_backslash_finished, slash_backslash_reset),
    [UNDERSCORE_MINUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, underscore_minus_finished, underscore_minus_reset),
    [Z_CAPSLOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, z_capslock_finished, z_capslock_reset),
};
