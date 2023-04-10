/*----------------------------------------\
| File: usb.h                             |
|                                         |
| Defines functions and interrupts for    |
| handling USB                            |
\----------------------------------------*/

#ifndef USB_H
#define USB_H

#include <stdbool.h>
#include <stdint.h>

// Report variables
extern volatile uint8_t kbd_keys[6];
extern volatile uint8_t kbd_mod_keys;

// LEDs (capslock state, numlock state, ...)
uint8_t kbd_leds;


uint8_t usb_status;
uint8_t kbd_protocol;


uint8_t usb_init();
uint8_t usb_configured();
uint8_t usb_send();

// Least significant byte / Most significant byte
#define LSB(n) (n & 255)
#define MSB(n) ((n >> 8) & 255)

// Vendor and product IDs
#define VENDOR_ID 0x16C0
#define PRODUCT_ID 0x047C


#define GET_STATUS 0x00
#define CLEAR_FEATURE 0x01
#define SET_FEATURE 0x03
#define SET_ADDRESS 0x05
#define GET_DESCRIPTOR 0x06
#define GET_CONFIGURATION 0x08
#define SET_CONFIGURATION 0x09
#define GET_INTERFACE 0x0A
#define SET_INTERFACE 0x0B


#define KEYBOARD_ENDPOINT 3  // The second endpoint is the HID endpoint

#define CONFIG_SIZE 34
#define HID_OFFSET 18

// HID Class-specific request codes - refer to HID Class Specification
// Chapter 7.2 - Remarks

#define GET_REPORT 0x01
#define GET_IDLE 0x02
#define GET_PROTOCOL 0x03
#define SET_REPORT 0x09
#define SET_IDLE 0x0A
#define SET_PROTOCOL 0x0B


#endif // USB_H