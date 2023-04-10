/*----------------------------------------\
| File: matrix.h                          |
|                                         |
| Defines functions for scanning and      |
| handling the keyboard matrix            |
\----------------------------------------*/

#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

// Define keyboard dimentions and number of layers
#define LAYERS 2
#define ROWS 5
#define COLS 15


void matrix_init();
void matrix_scan();
void build_key_array();

bool add_mod_key(uint8_t r, uint16_t c);
void add_key(uint8_t key);
void clear_keys();
void send_report();

#endif // MATRIX_H