/*----------------------------------------\
| File: matrix.c                          |
|                                         |
| Defines functions for scanning and      |
| handling the keyboard matrix            |
\----------------------------------------*/
#define F_CPU 16000000

#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "layout.h"
#include "keycodes.h"
#include "usb.h"
#include "matrix.h"

// Stores current PORTF state
uint8_t port;
// Stores current ROW state
uint16_t row_state;

// Keeps track of the number of pressed keys
// We can only send 6 key codes
uint8_t registered_keys = 0;

// True = A key changed state
// False = No change happened
bool changed = false;

// Matrix state stores current key states
// 0 = not pressed
// 1 = pressed
bool matrix_state[ROWS][COLS] =
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

//------------------------------------------------
// Name: matrix_init
// Purpose: Setup Input/Output pins
//------------------------------------------------
void matrix_init()
{
	// Set ROWS as output
	DDRF = 0b11110010;
	
	// Set COLS as input
	DDRB = 0b00000000; // Column 0 - 7
	DDRD = 0b00000000; // Column 8 - 14
	
	// Pull COLS high
	PORTB = 0b11111111;
	PORTD = 0b01111111;
	
}

//------------------------------------------------
// Name: matrix_scan
// Purpose: Scan the matrix for pressed keys
//------------------------------------------------
void matrix_scan()
{
	// Due to PORTF missing the 2nd and 3rd pins
	// we can't use a for loop (check schematic)
	for (uint8_t r = 0; r < ROWS; r++)
	{
		switch(r)
		{
			case 0:
				port = 0b11110000;
				break;
			case 1:
				port = 0b11100010;
				break;
			case 2:
				port = 0b11010010;
				break;
			case 3:
				port = 0b10110010;
				break;
			case 4:
				port = 0b01110010;
				break;
		}
		
		// Assign new value to PORTF
		PORTF = port;
		
		// Wait for the registers to update
		// (3ms worked fine too)
		_delay_ms(5);
		
		// Save the row values into a 16 bit variable
		// We use inverted logic, to make the rest
		// of the code readable we invert the bits
		// Before: 1 = Not pressed; 0 = Pressed
		// After: 1 = Pressed; 0 = Not pressed
		row_state = ~((PIND << 8) | PINB);
		
		// Loop through all the bits (keys)
		// in the selected column
		for (uint8_t c = 0; c < COLS; c++)
		{
			// If pressed save a 1
			if (row_state & (1 << c))
			{
				// If the last value was a 0, it has changed
				if (matrix_state[r][c] == 0) changed = true;
				// Update value
				matrix_state[r][c] = 1;
			}
			// If not pressed save a 0
			else
			{
				// If the last value was 1, it has changed
				if (matrix_state[r][c] == 1) changed = true;
				// Update value
				matrix_state[r][c] = 0;
			}
		}
	}
}

//------------------------------------------------
// Name: build_key_array
// Purpose: Build keyboard report
//------------------------------------------------
void build_key_array()
{
	// Disable interrupts
	cli();
	// Clear report variables
	// Don't want any leftovers
	clear_keys();
	
	// Check if the FN key has been pressed
	// If it has change layers
	uint8_t l = matrix_state[4][10] == 1 ? 1 : 0;
	
	// Loop through ROWS
	for (uint8_t r = 0; r < ROWS; r++)
	{
		// Loop through COLS
		for (uint8_t c = 0; c < COLS; c++)
		{
			// If key is pressed add to report
			if (matrix_state[r][c])
			{
				// Check if it is a modifier key (Shift, Ctrl, ...)
				// Modifier keys have their own byte in the report
				if (!add_mod_key(r,c))
				{
					add_key(layout[l][r][c]);
				}
			}
		}
	}
	// Enable interrupts
	sei();
}

//------------------------------------------------
// Name: add_mod_key
// Purpose: Check if a mod key has been pressed
//------------------------------------------------
bool add_mod_key(uint8_t r, uint16_t c)
{
	// Based on input variables check if key is
	// a modifier, if so add it to the kbd_mod_keys
	// variable
	switch (r)
	{
		case 3:
			switch (c)
			{
				case 0: // Left shift
					kbd_mod_keys |= 0b00000010;
					return true;
				case 12: // Right shift
					kbd_mod_keys |= 0b00100000;
					return true;
			}
			break;
		case 4:
			switch (c)
			{
				case 0: // Left ctrl
					kbd_mod_keys |= 0b00000001;
					return true;
				case 1: // Left meta
					kbd_mod_keys |= 0b00001000;
					return true;
				case 2: // Left alt
					kbd_mod_keys |= 0b00000100;
					return true;
				case 9: // Right alt
					kbd_mod_keys |= 0b01000000;
					return true;
				case 11: // Right ctrl
					kbd_mod_keys |= 0b00010000;
					return true;
			}
			break;
		default:
			return false;
	}
	return false;
}

//------------------------------------------------
// Name: add_key
// Purpose: Add key to keyboard report
//------------------------------------------------
void add_key(uint8_t key)
{
	// Disable interupts
	cli();
	// Check for overflow and undefined (0x00) keys
	if (registered_keys > 5) return;
	if (!key) return;
	
	// Add key to kbd_keys
	kbd_keys[registered_keys] = key;
	registered_keys++;
	// Enable interupts
	sei();
}

//------------------------------------------------
// Name: clear_keys
// Purpose: Clear keyboard report
//------------------------------------------------
void clear_keys()
{
	// Disable interupts
	cli();
	for (uint8_t i = 0; i < 6; i++)
	{
		kbd_keys[i] = 0;
	}
	registered_keys = 0;
	kbd_mod_keys = 0;
	// Enable interupts
	sei();
}

//------------------------------------------------
// Name: send_report
// Purpose: If a key changed state send a report
//------------------------------------------------
void send_report()
{
	if (changed)
	{
		usb_send();
		changed = false;
	}
}