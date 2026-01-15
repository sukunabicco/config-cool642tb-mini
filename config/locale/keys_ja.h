/*
 * Japanese (JIS) Keyboard Layout Keys
 * For use with Windows set to Japanese keyboard layout
 */

#pragma once

#include <dt-bindings/zmk/keys.h>

/* Symbols - JIS layout mapping */

// Row 1: Numbers with Shift
#define JP_EXLM LS(N1)    // !
#define JP_DQUO LS(N2)    // "
#define JP_HASH LS(N3)    // #
#define JP_DLR  LS(N4)    // $
#define JP_PERC LS(N5)    // %
#define JP_AMPR LS(N6)    // &
#define JP_QUOT LS(N7)    // '
#define JP_LPRN LS(N8)    // (
#define JP_RPRN LS(N9)    // )

// Special characters
#define JP_EQL  LS(MINUS) // =
#define JP_TILD LS(EQUAL) // ~
#define JP_PIPE LS(INT3)  // |
#define JP_GRV  LS(LBKT)  // `
#define JP_AT   LBKT      // @
#define JP_LBKT RBKT      // [
#define JP_RBKT NUHS      // ] (Non-US Hash position)
#define JP_LBRC LS(RBKT)  // {
#define JP_RBRC LS(NUHS)  // }
#define JP_CARET EQUAL    // ^
#define JP_YEN  INT3      // yen sign
#define JP_BSLS INT1      // backslash (ro key)
#define JP_UNDS LS(INT1)  // _

// Punctuation
#define JP_SCLN SEMI      // ;
#define JP_COLN APOS      // :
#define JP_PLUS LS(SEMI)  // +
#define JP_ASTR LS(APOS)  // *
#define JP_MINS MINUS     // -

// Other symbols
#define JP_COMM COMMA     // ,
#define JP_DOT  DOT       // .
#define JP_SLSH SLASH     // /
#define JP_QUES LS(SLASH) // ?
#define JP_LT   LS(COMMA) // <
#define JP_GT   LS(DOT)   // >

// Aliases for compatibility
#define JP_ZKHK INT5      // Zenkaku/Hankaku (grave position on JIS)
#define JP_MHEN INT5      // Muhenkan
#define JP_HENK INT4      // Henkan
#define JP_KANA INT2      // Katakana/Hiragana
