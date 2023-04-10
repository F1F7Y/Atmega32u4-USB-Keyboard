/*----------------------------------------\
| File: layout.h                          |
|                                         |
| Stores the layout\layouts stored in an  |
| array.                                  |
\----------------------------------------*/
 
#ifndef LAYOUT_H
#define LAYOUT_H

#include "keycodes.h"
#include "matrix.h"

//------------------------------------------------
// Uncomment a layout you wish to use
// Only one can be uncommented
//------------------------------------------------
#define DVORAK
//#define QWERTY


//------------------------------------------------
// Layout: QWERTY
// Standart layout on most keyboards
//------------------------------------------------
#ifdef QWERTY
const uint8_t layout[LAYERS][ROWS][COLS] =
{
	{
		{KEY_ESCAPE, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_LEFTBRACE, KEY_RIGHTBRACE, KEY_GRAVE, KEY_BACKSPACE},
		{KEY_TAB, KEY_APOSTROPHE, KEY_COMMA, KEY_DOT, KEY_P, KEY_Y, KEY_F, KEY_G, KEY_C, KEY_R, KEY_L, KEY_SLASH, KEY_EQUAL, KEY_BACKSLASH, KEY_DELETE},
		{KEY_CAPSLOCK, KEY_A, KEY_O, KEY_E, KEY_U, KEY_I, KEY_D, KEY_H, KEY_T, KEY_N, KEY_S, KEY_MINUS, 0x00, KEY_ENTER, KEY_INSERT},
		{0x00, KEY_SEMICOLON, KEY_Q, KEY_J, KEY_K, KEY_X, KEY_B, KEY_M, KEY_W, KEY_V, KEY_Z, 0x00, 0x00, KEY_UP, KEY_PRINTSCREEN},
		{0x00, 0x00, 0x00, 0x00, 0x00, KEY_SPACE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, KEY_LEFT, KEY_DOWN, KEY_RIGHT}
		},{
		{0x00, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, KEY_STOP, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, KEY_MUTE, 0x00, 0x00, 0x00, 0x00, 0x00, KEY_VOLUMEUP, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, KEY_VOLUMEDOWN, 0x00}
	}
	
};
#endif // QWERTY

//------------------------------------------------
// Layout: DVORAK
// Optimizes finger travel time between strokes
//------------------------------------------------
#ifdef DVORAK
const uint8_t layout[LAYERS][ROWS][COLS] =
{
	{
		{KEY_ESCAPE, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_LEFTBRACE, KEY_RIGHTBRACE, KEY_GRAVE, KEY_BACKSPACE},
		{KEY_TAB, KEY_APOSTROPHE, KEY_COMMA, KEY_DOT, KEY_P, KEY_Y, KEY_F, KEY_G, KEY_C, KEY_R, KEY_L, KEY_SLASH, KEY_EQUAL, KEY_BACKSLASH, KEY_DELETE},
		{KEY_CAPSLOCK, KEY_A, KEY_O, KEY_E, KEY_U, KEY_I, KEY_D, KEY_H, KEY_T, KEY_N, KEY_S, KEY_MINUS, 0x00, KEY_ENTER, KEY_INSERT},
		{0x00, KEY_SEMICOLON, KEY_Q, KEY_J, KEY_K, KEY_X, KEY_B, KEY_M, KEY_W, KEY_V, KEY_Z, 0x00, 0x00, KEY_UP, KEY_PRINTSCREEN},
		{0x00, 0x00, 0x00, 0x00, 0x00, KEY_SPACE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, KEY_LEFT, KEY_DOWN, KEY_RIGHT}
	},{
		{0x00, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, KEY_STOP, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, KEY_MUTE, 0x00, 0x00, 0x00, 0x00, 0x00, KEY_VOLUMEUP, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, KEY_VOLUMEDOWN, 0x00}
	}
	
};
#endif // DVORAK

#endif // LAYOUT_H