/*----------------------------------------\
| File: main.c                            |
|                                         |
| Created: 12.03.2021 09:57:35            |
|          DD/MM/YYYY HH/MM/SS            |
| Author: Filip Bartoš                    |
\----------------------------------------*/


/* https://github.com/kmani314/ATMega32u4-HID-Keyboard
 * https://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega32u4&LOW=FF&HIGH=99&EXTENDED=FF&LOCKBIT=FF
 *
 * https://www.usb.org/document-library/usb-20-specification
 * https://www.usb.org/document-library/device-class-definition-hid-111
*/

#define F_CPU 16000000


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "matrix.h"
#include "keycodes.h"
#include "usb.h"


int main(void)
{
	// Setup I/O pins
	matrix_init();
	
	// Initilaze USB
	usb_init();
	
	// Wait for USB
	while(!usb_configured());
	
	// Give me some time
	_delay_ms(1000);
	
	// Loop
	for (;;)
	{
		// Scan keyboard matrix
		matrix_scan();
		// Build keyboard report
		build_key_array();
		// Send report if a key has been pressed/released
		send_report();
	}
	
}
