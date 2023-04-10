/*----------------------------------------\
| File: usb.c                             |
|                                         |
| Defines functions and interrupts for    |
| handling USB                            |
\----------------------------------------*/

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include "usb.h"


// Pressed keys
volatile uint8_t kbd_keys[6] = {0, 0, 0, 0, 0, 0};
// Pressed modifier keys (shift, ctrl, ...)
volatile uint8_t kbd_mod_keys = 0b00000000;

// How often we send unchanged reports
static uint16_t kbd_idle_config = 125;

// How many SOFE interrupts have occured
static uint8_t kbd_idle_count = 0;
// What ever this is
static uint8_t this_interrupt = 0;

//-------------------------------------------------
// Device descriptor
// Universal Serial Bus Specification Revision 2.0 - Table 9-8
//
// Describes general information about a USB device
//-------------------------------------------------
static const uint8_t device_descriptor[] PROGMEM =
{
	18,	// bLength - Size of this descriptor
	1,	// bDescriptorType - Type of this descriptor (1 is DEVICE)
	0x00, 0x02,	//bcdUSB - The release of the USB specification with which this device is compliant
	0,	// bDeviceClass - Check documentation
	0,	// bDeviceSubClass - Sub class of bDeviceClass
	0,	// bDeviceProtocol - Sub class of bDeviceClass
	32,	// bMaxPacketSize0 - Maximum packet size for endpoint zero
	LSB(VENDOR_ID), MSB(VENDOR_ID),		// idVendor - Vendor ID assigned by USB-IF
	LSB(PRODUCT_ID), MSB(PRODUCT_ID),	// idProduct - Product ID assigned by the manufacturer
	0x00, 0x01,	// bcdDevice - Device release number
	0,	// iManufacturer - Index describing manufacturer
	0,	// iProduct - Index describing product
	0,	// iSerialNumber - Index describing device's serial number
	1	// bNumConfigurations - Number of possible configurations
};

//-------------------------------------------------
// HID descriptor
// Device Class Definition for Human Interface Devices Version 1.11 - Appendix E, table E.6
//
// Describes subordinate descriptors
//-------------------------------------------------
static const uint8_t kbd_HID_descriptor[] PROGMEM =
{
	0x05, 0x01,	// Usage Page (Generic Desktop)
	0x09, 0x06,	// Usage (Keyboard)
	0xA1, 0x01,	// Collection (Application)
	0x05, 0x07,	// Usage Page (Key Codes)
	0x19, 0xE0,	// Usage Minimum (224)
	0x29, 0xE7,	// Usage Maximum (231)
	0x15, 0x00,	// Logical Minimum (0)
	0x25, 0x01, // Logical Maximum (1)
	0x75, 0x01,	// Report size (1)
	0x95, 0x08, // Report Count (8)
	0x81, 0x02,	// Input (Data, Variable, Absolute)
	0x95, 0x01,	// Report Count (1)
	0x75, 0x08,	// Report Size (8)
	0x81, 0x01,	// Input (Constant)
	0x95, 0x05,	// Report Count (5)
	0x75, 0x01,	// Report Size (1)
	0x05, 0x08,	// Usage Page (Page# for LEDs)
	0x19, 0x01,	// Usage Minimum (1)
	0x29, 0x05,	// Usage maximum (5)
	0x91, 0x02,	// Output (Data, Variable, Absolute)
	0x95, 0x01, // Report Count (1)
	0x75, 0x03,	// Report Size (3)
	0x91, 0x01,	// Output (Constant)
	0x95, 0x06,	// Report Count (1)
	0x75, 0x08,	// Report Size (8)
	0x15, 0x00,	// Logical Minimum (0)
	0x25, 0x65,	// Logical Maximum (101)
	0x05, 0x07,	// Usage Page (Key Codes)
	0x19, 0x00,	// Usage Minimum (0)
	0x29, 0x65,	// Usage Maximum (101)
	0x81, 0x00,	// Input (Data, Array)
	0xC0		// End Collection
};

//-------------------------------------------------
// Configuration descriptor
//
// Describes the device configuration
//-------------------------------------------------
static const uint8_t configuration_descriptor[] PROGMEM =
{
	// Device Class Definition for Human Interface Devices Version 1.11 - Appendix E, table E.2
	9,	// bLength
	2,	// bDescriptorType
	LSB(CONFIG_SIZE), MSB(CONFIG_SIZE),	// wTotalLength
	1,	// bNumInterfaces
	1,	// bConfigurationValue
	0,	// iConfiguration
	0xC0,	// bmAttributes
	50,	// MaxPower
	// Device Class Definition for Human Interface Devices Version 1.11 - Appendix E, table E.3
	9,	// blength
	4,	// bDescriptorType
	0,	// bInterFaceNumber
	0,	// bAlternateSetting
	1,	// bNumEndpoints
	0x03,	// bInterfaceClass
	0x01,	// bInterfaceSubClass
	0x01,	// bInterfaceProtocol
	0,	// iInterface
	// Device Class Definition for Human Interface Devices Version 1.11 - Appendix E, table E.4
	9,	// bLength
	0x21,	// bDescriptorType
	0x11, 0x01,	// bcdHID
	0,	// bCountryCode
	1,	// bNumDescriptors
	0x22,	// bDescriptorType
	sizeof(kbd_HID_descriptor), 0,	// wDescriptorLength
	// Device Class Definition for Human Interface Devices Version 1.11 - Appendix E, table E.5
	7,	// bLength
	0x05,	// bDescriptorType
	KEYBOARD_ENDPOINT | 0x80,	// bEndpointAddress
	0x03,	// bmAttributes
	8, 0,	// wMaxPacketSize
	0x01	// bInterval
};

//-------------------------------------------------
// Name: usb_init
// Purpose: Initilaze USB
//-------------------------------------------------
uint8_t usb_init()
{
	// Global Interrupt Disable
	cli();
	// Enable USB Pads Regulator
	UHWCON |= (1 << UVREGE);
	// Configure to use 16mHz oscillator and enable PLL
	PLLCSR |= (1 << PINDIV)  | (1 << PLLE);
	// Wait for PLL Lock to be achieved
	while (!(PLLCSR & (1 << PLOCK)));
	// Enable USB Controller and USB power pads
	USBCON |= (1 << USBE) | (1 << OTGPADE);
	// Unfreeze the clock
	USBCON &= ~(1 << FRZCLK);
	// Full speed mode, connect device
	UDCON = 0;
	// Connect
	USBCON &= ~(1 << VBUSTE);
	// Enable End Of Reset Interrupt and Starn Of Frame Interrupt
	UDIEN |= (1 << EORSTE) | (1 << SOFE);
	
	usb_status = 0;
	// Global Interrupt Enable
	sei();
	return 0;
}

//-------------------------------------------------
// Name: usb_send
// Purpose: Send pressed keys
//-------------------------------------------------
uint8_t usb_send()
{
	// Why are you even trying
	if (!usb_status) return -1;
	// Global Interrupt Disable
	cli();
	// Set endpoint
	UENUM = KEYBOARD_ENDPOINT;
	// Wait for banks to be ready
	while (!(UEINTX & (1 << RWAL)));
	// Device Class Definition for Human Interface Devices Version 1.11 - page 60
	// Send modifier keys
	UEDATX = kbd_mod_keys;
	// Reserved
	UEDATX = 0;
	// Send keys
	for (int i = 0; i < 6; i++)
	{
		UEDATX = kbd_keys[i];
	}
	// 
	UEINTX = 0b00111010;
	// Reset idle count
	kbd_idle_count = 0;
	// Global Interrupt Enable
	sei();
	// Return
	return 0;
}

//-------------------------------------------------
// Name: usb_configured
// Purpose: Return usb_status
//-------------------------------------------------
uint8_t usb_configured()
{
	return usb_status;
}

//-------------------------------------------------
// USB General interrupt request
//-------------------------------------------------
ISR(USB_GEN_vect)
{
	// Save UDINT
	uint8_t udint = UDINT;
	// Clear UDINT
	UDINT = 0;
	
	// End of Reset Interrupt
	if (udint & (1 << EORSTI))
	{
		// Configure Control Endpoint
		UENUM = 0;             // Select Endpoint 0, the default control endpoint
		UECONX = (1 << EPEN);  // Enable the Endpoint
		UECFG0X = 0;      // Control Endpoint, OUT direction for control endpoint
		UECFG1X |= 0x22;  // 32 byte endpoint, 1 bank, allocate the memory
		usb_status = 0;

		if (!(UESTA0X & (1 << CFGOK)))
		{  // Check if endpoint configuration was successful
			return;
		}

		UERST = 1;  // Reset Endpoint
		UERST = 0;

		UEIENX = (1 << RXSTPE);  // Re-enable the RXSPTE (Receive Setup Packet) Interrupt
		return;
	}
	
	// Start Of Frame
	if ((udint & (1 << SOFI)) && usb_status)
	{
		this_interrupt++;
		
		if (kbd_idle_config && (this_interrupt & 3) == 0)
		{  // Scaling by four, trying to save memory
			UENUM = KEYBOARD_ENDPOINT;
			if (UEINTX & (1 << RWAL))
			{  // Check if banks are writable
				kbd_idle_count++;
				if (kbd_idle_count == kbd_idle_config)
				{  // Have we reached the idle threshold?
					kbd_idle_count = 0;
					
					UEDATX = kbd_mod_keys;
					
					UEDATX = 0;
					
					for (int i = 0; i < 6; i++)
					{
						UEDATX = kbd_keys[i];
					}
					
					UEINTX = 0b00111010;
				}
			}
		}
	}
}

//-------------------------------------------------
// USB Endpoint interrupt communication request
//-------------------------------------------------
ISR(USB_COM_vect)
{
	UENUM = 0;
	
	if (UEINTX & (1 << RXSTPI)) {
		uint8_t bmRequestType = UEDATX;  // UEDATX is FIFO; see table in README
		uint8_t bRequest = UEDATX;
		
		uint16_t wValue = UEDATX;
		wValue |= UEDATX << 8;
		
		uint16_t wIndex = UEDATX;
		wIndex |= UEDATX << 8;
		
		uint16_t wLength = UEDATX;
		wLength |= UEDATX << 8;

		

		UEINTX &= ~((1 << RXSTPI) | (1 << RXOUTI) | (1 << TXINI));  // Handshake the Interrupts, do this after recording
		// the packet because it also clears the endpoint banks
		if (bRequest == GET_DESCRIPTOR)
		{
			// The Host is requesting a descriptor to enumerate the device
			uint8_t* descriptor;
			uint8_t descriptor_length;

			if (wValue == 0x0100)
			{  // Is the host requesting a device descriptor?
				descriptor = device_descriptor;
				descriptor_length = pgm_read_byte(descriptor);
			}
			else if (wValue == 0x0200)
			{  // Is it asking for a configuration descriptor?
				descriptor = configuration_descriptor;
				descriptor_length =
				CONFIG_SIZE;  // Configuration descriptor is comprised of many
				// different descriptors; the length is more than
				// bLength
			}
			else if (wValue == 0x2100)
			{  // Is it asking for a HID Report Descriptor?
				descriptor = configuration_descriptor + HID_OFFSET;
				descriptor_length = pgm_read_byte(descriptor);
			}
			else if (wValue == 0x2200)
			{
				descriptor = kbd_HID_descriptor;
				descriptor_length = sizeof(kbd_HID_descriptor);
			}
			else
			{
				PORTC = 0xFF;
				UECONX |= (1 << STALLRQ) | (1 << EPEN);  // Enable the endpoint and stall, the
				// descriptor does not exist
				return;
			}

			uint8_t request_length = wLength > 255 ? 255 : wLength;  // Our endpoint is only so big; the USB Spec
			// says to truncate the response if the size
			// exceeds the size of the endpoint

			descriptor_length = request_length > descriptor_length ? descriptor_length : request_length;  // Truncate to descriptor length at most

			while (descriptor_length > 0)
			{
				while (!(UEINTX & (1 << TXINI)));  // Wait for banks to be ready for data transmission
				
				if (UEINTX & (1 << RXOUTI)) return;  // If there is another packet, exit to handle it

				uint8_t packet = descriptor_length > 32 ? 32 : descriptor_length;  // Make sure that the packet we are
				// getting is not too big to fit in the
				// endpoint

				for (int i = 0; i < packet; i++)
				{
					UEDATX = pgm_read_byte(descriptor + i);  // Send the descriptor over UEDATX, use pgmspace functions
					// because the descriptors are stored in flash
				}

				descriptor_length -= packet;
				descriptor += packet;
				UEINTX &= ~(1 << TXINI);
			}
			return;
		}

		if (bRequest == SET_CONFIGURATION && bmRequestType == 0)
		{  // Refer to USB Spec 9.4.7 - This is the configuration request
			// to place the device into address mode
			usb_status = wValue;
			UEINTX &= ~(1 << TXINI);
			UENUM = KEYBOARD_ENDPOINT;
			UECONX = 1;
			UECFG0X = 0b11000001;  // EPTYPE Interrupt IN
			UECFG1X = 0b00000110;  // Dual Bank Endpoint, 8 Bytes, allocate memory
			UERST = 0x1E;          // Reset all of the endpoints
			UERST = 0;
			return;
		}

		if (bRequest == SET_ADDRESS)
		{
			UEINTX &= ~(1 << TXINI);
			while (!(UEINTX & (1 << TXINI)))
			;  // Wait until the banks are ready to be filled

			UDADDR = wValue | (1 << ADDEN);  // Set the device address
			return;
		}

		if (bRequest == GET_CONFIGURATION && bmRequestType == 0x80)
		{  // GET_CONFIGURATION is the host trying to get
			// the current config status of the device
			while (!(UEINTX & (1 << TXINI)))
			;  // Wait until the banks are ready to be filled
			UEDATX = usb_status;
			UEINTX &= ~(1 << TXINI);
			return;
		}

		if (bRequest == GET_STATUS)
		{
			while (!(UEINTX & (1 << TXINI)));
			
			UEDATX = 0;
			UEDATX = 0;
			UEINTX &= ~(1 << TXINI);
			
			return;
		}

		if (wIndex == 0)
		{  // Is this a request to the keyboard interface for HID
			// class-specific requests?
			if (bmRequestType == 0xA1)
			{  // GET Requests - Refer to the table in HID Specification 7.2
				// - This byte specifies the data direction of the packet.
				// Unnecessary since bRequest is unique, but it makes the
				// code clearer
				if (bRequest == GET_REPORT)
				{  // Get the current HID report
					while (!(UEINTX & (1 << TXINI)));  // Wait for the banks to be ready for transmission
					
					UEDATX = kbd_mod_keys;

					for (int i = 0; i < 6; i++)
					{
						UEDATX = kbd_keys
						[i];  // According to the spec, this method of getting the
						// report is not used for device polling, although we
						// still have to implement the response
					}
					
					UEINTX &= ~(1 << TXINI);
					
					return;
				}
				
				if (bRequest == GET_IDLE)
				{
					while (!(UEINTX & (1 << TXINI)));

					UEDATX = kbd_idle_config;

					UEINTX &= ~(1 << TXINI);
					return;
				}
				
				if (bRequest == GET_PROTOCOL)
				{
					while (!(UEINTX & (1 << TXINI)))
					;

					UEDATX = kbd_protocol;

					UEINTX &= ~(1 << TXINI);
					return;
				}
			}

			if (bmRequestType == 0x21) {  // SET Requests - Host-to-device data direction
				if (bRequest == SET_REPORT)
				{
					while (!(UEINTX & (1 << RXOUTI)));  // This is the opposite of the TXINI one, we are waiting until
					// the banks are ready for reading instead of for writing
					kbd_leds = UEDATX;

					UEINTX &= ~(1 << TXINI);  // Send ACK and clear TX bit
					UEINTX &= ~(1 << RXOUTI);
					return;
				}
				
				if (bRequest == SET_IDLE)
				{
					kbd_idle_config = wValue;  //
					kbd_idle_count = 0;

					UEINTX &= ~(1 << TXINI);  // Send ACK and clear TX bit
					return;
				}
				
				if (bRequest == SET_PROTOCOL)
				{  // This request is only mandatory for boot devices,
					// and this is a boot device
					kbd_protocol = wValue >> 8;  // Nobody cares what happens to this, arbitrary cast
					// from 16 bit to 8 bit doesn't matter

					UEINTX &= ~(1 << TXINI);  // Send ACK and clear TX bit
					return;
				}
			}
		}
	}
	
	UECONX |= (1 << STALLRQ) | (1 << EPEN);  // The host made an invalid request or there was an
	// error with one of the request parameters
}
