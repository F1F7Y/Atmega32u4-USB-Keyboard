/*----------------------------------------\
| File: keycodes.h                        |
|                                         |
| Taken from:                             |
|    HID Usage Tables                     |
|    Version 1.12                         |
| Section 10:                             |
|    Keyboard/Keypad Page (0x07)          |
|                                         |
| For more information check the document |
| mentioned above                         |
\----------------------------------------*/

// KEY DEFINITION   // USAGE ID (Hex) // USAGE NAME                         / PC-AT /  MAC  / UNIX  /
#define KEY_RESERVED            0x00  // Reserved (no event indicated)      /   Y   /   Y   /   Y   /
#define KEY_ERR_ROLLOVER        0x01  // Keyboard ErrorRollOver             /   Y   /   Y   /   Y   /
#define KEY_ERR_POSTFAIL        0x02  // Keyboard PostFail                  /   Y   /   Y   /   Y   /
#define KEY_ERR_UNDEFINED       0x03  // Keyboard ErrorUndefined            /   Y   /   Y   /   Y   /
#define KEY_A                   0x04  // Keyboard a and A                   /   Y   /   Y   /   Y   /
#define KEY_B                   0x05  // Keyboard b and B                   /   Y   /   Y   /   Y   /
#define KEY_C                   0x06  // Keyboard c and C                   /   Y   /   Y   /   Y   /
#define KEY_D                   0x07  // Keyboard d and D                   /   Y   /   Y   /   Y   /
#define KEY_E                   0x08  // Keyboard e and E                   /   Y   /   Y   /   Y   /
#define KEY_F                   0x09  // Keyboard f and F                   /   Y   /   Y   /   Y   /
#define KEY_G                   0x0A  // Keyboard g and G                   /   Y   /   Y   /   Y   /
#define KEY_H                   0x0B  // Keyboard h and H                   /   Y   /   Y   /   Y   /
#define KEY_I                   0x0C  // Keyboard i and I                   /   Y   /   Y   /   Y   /
#define KEY_J                   0x0D  // Keyboard g and J                   /   Y   /   Y   /   Y   /
#define KEY_K                   0x0E  // Keyboard k and K                   /   Y   /   Y   /   Y   /
#define KEY_L                   0x0F  // Keyboard l and L                   /   Y   /   Y   /   Y   /
#define KEY_M                   0x10  // Keyboard m and M                   /   Y   /   Y   /   Y   /
#define KEY_N                   0x11  // Keyboard n and N                   /   Y   /   Y   /   Y   /
#define KEY_O                   0x12  // Keyboard o and O                   /   Y   /   Y   /   Y   /
#define KEY_P                   0x13  // Keyboard p and P                   /   Y   /   Y   /   Y   /
#define KEY_Q                   0x14  // Keyboard q and Q                   /   Y   /   Y   /   Y   /
#define KEY_R                   0x15  // Keyboard r and R                   /   Y   /   Y   /   Y   /
#define KEY_S                   0x16  // Keyboard s and S                   /   Y   /   Y   /   Y   /
#define KEY_T                   0x17  // Keyboard t and T                   /   Y   /   Y   /   Y   /
#define KEY_U                   0x18  // Keyboard u and U                   /   Y   /   Y   /   Y   /
#define KEY_V                   0x19  // Keyboard v and V                   /   Y   /   Y   /   Y   /
#define KEY_W                   0x1A  // Keyboard w and W                   /   Y   /   Y   /   Y   /
#define KEY_X                   0x1B  // Keyboard x and X                   /   Y   /   Y   /   Y   /
#define KEY_Y                   0x1C  // Keyboard y and Y                   /   Y   /   Y   /   Y   /
#define KEY_Z                   0x1D  // Keyboard z and Z                   /   Y   /   Y   /   Y   /
#define KEY_1                   0x1E  // Keyboard 1                         /   Y   /   Y   /   Y   /
#define KEY_2                   0x1F  // Keyboard 2                         /   Y   /   Y   /   Y   /
#define KEY_3                   0x20  // Keyboard 3                         /   Y   /   Y   /   Y   /
#define KEY_4                   0x21  // Keyboard 4                         /   Y   /   Y   /   Y   /
#define KEY_5                   0x22  // Keyboard 5                         /   Y   /   Y   /   Y   /
#define KEY_6                   0x23  // Keyboard 6                         /   Y   /   Y   /   Y   /
#define KEY_7                   0x24  // Keyboard 7                         /   Y   /   Y   /   Y   /
#define KEY_8                   0x25  // Keyboard 8                         /   Y   /   Y   /   Y   /
#define KEY_9                   0x26  // Keyboard 9                         /   Y   /   Y   /   Y   /
#define KEY_0                   0x27  // Keyboard 0                         /   Y   /   Y   /   Y   /
#define KEY_ENTER               0x28  // Keyboard Return (Enter)            /   Y   /   Y   /   Y   /
#define KEY_ESCAPE              0x29  // Keyboard ESCAPE                    /   Y   /   Y   /   Y   /
#define KEY_BACKSPACE           0x2A  // Keyboard DELETE (Backspace)        /   Y   /   Y   /   Y   /
#define KEY_TAB                 0x2B  // Keyboard Tab                       /   Y   /   Y   /   Y   /
#define KEY_SPACE               0x2C  // Keyboard Spacebar                  /   Y   /   Y   /   Y   /
#define KEY_MINUS               0x2D  // Keyboard - and (undecscore)        /   Y   /   Y   /   Y   /
#define KEY_EQUAL               0x2E  // Keyboard = and +                   /   Y   /   Y   /   Y   /
#define KEY_LEFTBRACE           0x2F  // Keyboard [ and {                   /   Y   /   Y   /   Y   /
#define KEY_RIGHTBRACE          0x30  // Keyboard ] and }                   /   Y   /   Y   /   Y   /
#define KEY_BACKSLASH           0x31  // Keyboard \ and |                   /   Y   /   Y   /   Y   /
#define KEY_HASHTILDE           0x32  // Keyboard Non-US # and ~            /   Y   /   Y   /   Y   /
#define KEY_SEMICOLON           0x33  // Keyboard ; and :                   /   Y   /   Y   /   Y   /
#define KEY_APOSTROPHE          0x34  // Keyboard ' and "                   /   Y   /   Y   /   Y   /
#define KEY_GRAVE               0x35  // Keyboard Grave Accent and Tilde    /   Y   /   Y   /   Y   /
#define KEY_COMMA               0x36  // Keyboard , and <                   /   Y   /   Y   /   Y   /
#define KEY_DOT                 0x37  // Keyboard . and >                   /   Y   /   Y   /   Y   /
#define KEY_SLASH               0x38  // Keyboard / and ?                   /   Y   /   Y   /   Y   /
#define KEY_CAPSLOCK            0x39  // Keyboard Caps Lock                 /   Y   /   Y   /   Y   /
#define KEY_F1                  0x3A  // Keyboard F1                        /   Y   /   Y   /   Y   /
#define KEY_F2                  0x3B  // Keyboard F2                        /   Y   /   Y   /   Y   /
#define KEY_F3                  0x3C  // Keyboard F3                        /   Y   /   Y   /   Y   /
#define KEY_F4                  0x3D  // Keyboard F4                        /   Y   /   Y   /   Y   /
#define KEY_F5                  0x3E  // Keyboard F5                        /   Y   /   Y   /   Y   /
#define KEY_F6                  0x3F  // Keyboard F6                        /   Y   /   Y   /   Y   /
#define KEY_F7                  0x40  // Keyboard F7                        /   Y   /   Y   /   Y   /
#define KEY_F8                  0x41  // Keyboard F8                        /   Y   /   Y   /   Y   /
#define KEY_F9                  0x42  // Keyboard F9                        /   Y   /   Y   /   Y   /
#define KEY_F10                 0x43  // Keyboard F10                       /   Y   /   Y   /   Y   /
#define KEY_F11                 0x44  // Keyboard F11                       /   Y   /   Y   /   Y   /
#define KEY_F12                 0x45  // Keyboard F12                       /   Y   /   Y   /   Y   /
#define KEY_PRINTSCREEN         0x46  // Keyboard PrintScreen               /   Y   /   Y   /   Y   /
#define KEY_SCROLLLOCK          0x47  // Keyboard Scroll Lock               /   Y   /   Y   /   Y   /
#define KEY_PAUSE               0x48  // Keyboard Pause                     /   Y   /   Y   /   Y   /
#define KEY_INSERT              0x49  // Keyboard Insert                    /   Y   /   Y   /   Y   /
#define KEY_HOME                0x4A  // Keyboard Home                      /   Y   /   Y   /   Y   /
#define KEY_PAGEUP              0x4B  // Keyboard PageUp                    /   Y   /   Y   /   Y   /
#define KEY_DELETE              0x4C  // Keyboard Delete Forward            /   Y   /   Y   /   Y   /
#define KEY_END                 0x4D  // Keyboard End                       /   Y   /   Y   /   Y   /
#define KEY_PAGEDOWN            0x4E  // Keyboard PageDown                  /   Y   /   Y   /   Y   /
#define KEY_RIGHT               0x4F  // Keyboard RightArrow                /   Y   /   Y   /   Y   /
#define KEY_LEFT                0x50  // Keyboard LeftArrow                 /   Y   /   Y   /   Y   /
#define KEY_DOWN                0x51  // Keyboard DownArrow                 /   Y   /   Y   /   Y   /
#define KEY_UP                  0x52  // Keyboard UpArrow                   /   Y   /   Y   /   Y   /
#define KEY_NUMLOCK             0x53  // Keypad Num Lock and Clear          /   Y   /   Y   /   Y   /
#define KEYPAD_SLASH            0x54  // Keypad /                           /   Y   /   Y   /   Y   /
#define KEYPAD_STAR             0x55  // Keypad *                           /   Y   /   Y   /   Y   /
#define KEYPAD_MINUS            0x56  // Keypad -                           /   Y   /   Y   /   Y   /
#define KEYPAD_PLUS             0x57  // Keypad +                           /   Y   /   Y   /   Y   /
#define KEYPAD_ENTER            0x58  // Keypad ENTER                       /   Y   /   Y   /   Y   /
#define KEYPAD_1                0x59  // Keypad 1 and End                   /   Y   /   Y   /   Y   /
#define KEYPAD_2                0x5A  // Keypad 2 and Down Arrow            /   Y   /   Y   /   Y   /
#define KEYPAD_3                0x5B  // Keypad 3 and PageDn                /   Y   /   Y   /   Y   /
#define KEYPAD_4                0x5C  // Keypad 4 and Left Arrow            /   Y   /   Y   /   Y   /
#define KEYPAD_5                0x5D  // Keypad 5                           /   Y   /   Y   /   Y   /
#define KEYPAD_6                0x5E  // Keypad 6 and Right Arrow           /   Y   /   Y   /   Y   /
#define KEYPAD_7                0x5F  // Keypad 7 and Home                  /   Y   /   Y   /   Y   /
#define KEYPAD_8                0x60  // Keypad 8 and Up Arrow              /   Y   /   Y   /   Y   /
#define KEYPAD_9                0x61  // Keypad 9 and PageUp                /   Y   /   Y   /   Y   /
#define KEYPAD_0                0x62  // Keypad 0 and Insert                /   Y   /   Y   /   Y   /
#define KEYPAD_DOT              0x63  // Keypad . and Delete                /   Y   /   Y   /   Y   /
#define KEY_SLASHBAR            0x64  // Keyboard Non-US \ and |            /   Y   /   Y   /   Y   /
#define KEY_APPLICATION         0x65  // Keyboard Application               /   Y   /       /   Y   /
#define KEY_POWER               0x66  // Keyboard Power                     /       /   Y   /   Y   /
#define KEYPAD_EQUAL            0x67  // Keypad =                           /       /   Y   /       /
#define KEY_F13                 0x68  // Keyboard F13                       /       /   Y   /       /
#define KEY_F14                 0x69  // Keyboard F14                       /       /   Y   /       /
#define KEY_F15                 0x6A  // Keyboard F15                       /       /   Y   /       /
#define KEY_F16                 0x6B  // Keyboard F16                       /       /       /       /
#define KEY_F17                 0x6C  // Keyboard F17                       /       /       /       /
#define KEY_F18                 0x6D  // Keyboard F18                       /       /       /       /
#define KEY_F19                 0x6E  // Keyboard F19                       /       /       /       /
#define KEY_F20                 0x6F  // Keyboard F20                       /       /       /       /
#define KEY_F21                 0x70  // Keyboard F21                       /       /       /       /
#define KEY_F22                 0x71  // Keyboard F22                       /       /       /       /
#define KEY_F23                 0x72  // Keyboard F23                       /       /       /       /
#define KEY_F24                 0x73  // Keyboard F24                       /       /       /       /
#define KEY_EXECUTE             0x74  // Keyboard Execute                   /       /       /   Y   /
#define KEY_HELP                0x75  // Keyboard Help                      /       /       /   Y   /
#define KEY_MENU                0x76  // Keyboard Menu                      /       /       /   Y   /
#define KEY_SELECT              0x77  // Keyboard Select                    /       /       /   Y   /
#define KEY_STOP                0x78  // Keyboard Stop                      /       /       /   Y   /
#define KEY_AGAIN               0x79  // Keyboard Again                     /       /       /   Y   /
#define KEY_UNDO                0x7A  // Keyboard Undo                      /       /       /   Y   /
#define KEY_CUT                 0x7B  // Keyboard Cut                       /       /       /   Y   /
#define KEY_COPY                0x7C  // Keyboard Copy                      /       /       /   Y   /
#define KEY_PASTE               0x7D  // Keyboard Paste                     /       /       /   Y   /
#define KEY_FIND                0x7E  // Keyboard Find                      /       /       /   Y   /
#define KEY_MUTE                0x7F  // Keyboard Mute                      /       /       /   Y   /
#define KEY_VOLUMEUP            0x80  // Keyboard Volume Up                 /       /       /   Y   /
#define KEY_VOLUMEDOWN          0x81  // Keyboard Volume Down               /       /       /   Y   /
#define KEY_LOCKING_CAPSLOCK    0x82  // Keyboard Locking Caps Lock         /       /       /   Y   /
#define KEY_LOCKING_NUMLOCK     0x83  // Keyboard Locking Num Lock          /       /       /   Y   /
#define KEY_LOCKING_SCROLLLOCK  0x84  // Keyboard Locking Scroll Lock       /       /       /   Y   /
#define KEYPAD_COMMA            0x85  // Keyboard Comma                     /       /       /       /
#define KEYPAD_EQUALSIGN        0x86  // Keyboard Equal Sign                /       /       /       /
#define KEY_INTERNATIONAL1      0x87  // Keyboard International1            /       /       /       /
#define KEY_INTERNATIONAL2      0x88  // Keyboard International2            /       /       /       /
#define KEY_INTERNATIONAL3      0x89  // Keyboard International3            /       /       /       /
#define KEY_INTERNATIONAL4      0x8A  // Keyboard International4            /       /       /       /
#define KEY_INTERNATIONAL5      0x8B  // Keyboard International5            /       /       /       /
#define KEY_INTERNATIONAL6      0x8C  // Keyboard International6            /       /       /       /
#define KEY_INTERNATIONAL7      0x8D  // Keyboard International7            /       /       /       /
#define KEY_INTERNATIONAL8      0x8E  // Keyboard International8            /       /       /       /
#define KEY_INTERNATIONAL9      0x8F  // Keyboard International9            /       /       /       /
#define KEY_LANG1               0x90  // Keyboard LANG1                     /       /       /       /
#define KEY_LANG2               0x91  // Keyboard LANG2                     /       /       /       /
#define KEY_LANG3               0x92  // Keyboard LANG3                     /       /       /       /
#define KEY_LANG4               0x93  // Keyboard LANG4                     /       /       /       /
#define KEY_LANG5               0x94  // Keyboard LANG5                     /       /       /       /
#define KEY_LANG6               0x95  // Keyboard LANG6                     /       /       /       /
#define KEY_LANG7               0x96  // Keyboard LANG7                     /       /       /       /
#define KEY_LANG8               0x97  // Keyboard LANG8                     /       /       /       /
#define KEY_LANG9               0x98  // Keyboard LANG9                     /       /       /       /
#define KEY_ALTERNATEERASE      0x99  // Keyboard Alternate Erase           /       /       /       /
#define KEY_SYSREQ              0x9A  // Keyboard SysReq/Attention          /       /       /       /
#define KEY_CANCEL              0x9B  // Keyboard Cancel                    /       /       /       /
#define KEY_CLEAR               0x9C  // Keyboard Clear                     /       /       /       /
#define KEY_PRIOR               0x9D  // Keyboard Prior                     /       /       /       /
#define KEY_RETURN_2            0x9E  // Keyboard Return                    /       /       /       /
#define KEY_SEPARATOR           0x9F  // Keyboard Separator                 /       /       /       /
#define KEY_OUT                 0xA0  // Keyboard Out                       /       /       /       /
#define KEY_OPER                0xA1  // Keyboard Oper                      /       /       /       /
#define KEY_CLEARAGAIN          0xA2  // Keyboard Clear/Again               /       /       /       /
#define KEY_CRSEL               0xA3  // Keyboard CrSel/Props               /       /       /       /
#define KEY_EXSEL               0xA4  // Keyboard ExSel                     /       /       /       /
// Reserved              0xA5 - 0xAF
#define KEYPAD_00               0xB0  // Keypad 00                          /       /       /       /
#define KEYPAD_000              0xB1  // Keypad 000                         /       /       /       /
#define KEY_THOUSANDS_SEPARATOR 0xB2  // Thousands Separator                /       /       /       /
#define KEY_DECIMAL_SEPARATOR   0xB3  // Decimal Separator                  /       /       /       /
#define KEY_CURRENCY_UNIT       0xB4  // Currency Unit                      /       /       /       /
#define KEY_CURRENCY_SUBUNIT    0xB5  // Currency Sub-unit                  /       /       /       /
#define KEYPAD_LEFTBRACE        0xB6  // Keypad (                           /       /       /       /
#define KEYPAD_RIGHTBRACE       0xB7  // Keypad )                           /       /       /       /
#define KEYPAD_LEFTBCURLYBRACE  0xB8  // Keypad {                           /       /       /       /
#define KEYPAD_RIGHTCURLYBRACE  0xB9  // Keypad }                           /       /       /       /
#define KEYPAD_TAB              0xBA  // Keypad Tab                         /       /       /       /
#define KEYPAD_BACKSPACE        0xBB  // Keypad Backspace                   /       /       /       /
#define KEYPAD_A                0xBC  // Keypad A                           /       /       /       /
#define KEYPAD_B                0xBD  // Keypad B                           /       /       /       /
#define KEYPAD_C                0xBE  // Keypad C                           /       /       /       /
#define KEYPAD_D                0xBF  // Keypad D                           /       /       /       /
#define KEYPAD_E                0xC0  // Keypad E                           /       /       /       /
#define KEYPAD_F                0xC1  // Keypad F                           /       /       /       /
#define KEYPAD_XOR              0xC2  // Keypad XOR                         /       /       /       /
#define KEYPAD_CARET            0xC3  // Keypad ^                           /       /       /       /
#define KEYPAD_PERCENTAGE       0xC4  // Keypad %                           /       /       /       /
#define KEYPAD_LESSTHAN         0xC5  // Keypad <                           /       /       /       /
#define KEYPAD_GREATERTHAN      0xC6  // Keypad >                           /       /       /       /
#define KEYPAD_BITWISEAND       0xC7  // Keypad &                           /       /       /       /
#define KEYPAD_LOGICALAND       0xC8  // Keypad &&                          /       /       /       /
#define KEYPAD_BITWISEOR        0xC9  // Keypad |                           /       /       /       /
#define KEYPAD_LOGICALOR        0xCA  // Keypad ||                          /       /       /       /
#define KEYPAD_COLON            0xCB  // Keypad :                           /       /       /       /
#define KEYPAD_HASH             0xCC  // Keypad #                           /       /       /       /
#define KEYPAD_SPACE            0xCD  // Keypad Space                       /       /       /       /
#define KEYPAD_ATSIGN           0xCE  // Keypad @                           /       /       /       /
#define KEYPAD_EXCLAMATIONMARK  0xCF  // Keypad !                           /       /       /       /
#define KEYPAD_MEMORY_STORE     0xD0  // Keypad Memory Store                /       /       /       /
#define KEYPAD_MEMORY_RECALL    0xD1  // Keypad Memory Recall               /       /       /       /
#define KEYPAD_MEMORY_CLEAR     0xD2  // Keypad Memory Clear                /       /       /       /
#define KEYPAD_MEMORY_ADD       0xD3  // Keypad Memory Add                  /       /       /       /
#define KEYPAD_MEMORY_SUBTRACT  0xD4  // Keypad Memory Subtract             /       /       /       /
#define KEYPAD_MEMORY_MULTIPLY  0xD5  // Keypad Memory Multiply             /       /       /       /
#define KEYPAD_MEMORY_DIVIDE    0xD6  // Keypad Memory Divide               /       /       /       /
#define KEYPAD_PLUSMINUS        0xD7  // Keypad +/-                         /       /       /       /
#define KEYPAD_CLEAR            0xD8  // Keypad Clear                       /       /       /       /
#define KEYPAD_CLEARENTRY       0xD9  // Keypad Clear Entry                 /       /       /       /
#define KEYPAD_BINARY           0xDA  // Keypad Binary                      /       /       /       /
#define KEYPAD_OCTAL            0xDB  // Keypad Octal                       /       /       /       /
#define KEYPAD_DECIMAL          0xDC  // Keypad Decimal                     /       /       /       /
#define KEYPAD_HEXADECIMAL      0xDD  // Keypad Hexadecimal                 /       /       /       /
// Reserved              0xDE - 0xDF
#define KEY_LEFTCONTROL         0xE0  // Keyboard LeftControl               /   Y   /   Y   /   Y   /
#define KEY_LEFTSHIFT           0xE1  // Keyboard LeftShift                 /   Y   /   Y   /   Y   /
#define KEY_LEFTALT             0xE2  // Keyboard LeftAlt                   /   Y   /   Y   /   Y   /
#define KEY_LEGTGUI             0xE3  // Keyboard Left GUI                  /   Y   /   Y   /   Y   /
#define KEY_RIGHTCONTROL        0xE4  // Keyboard RightControl              /   Y   /   Y   /   Y   /
#define KEY_RIGHTSHIFT          0xE5  // Keyboard RightShift                /   Y   /   Y   /   Y   /
#define KEY_RIGHTALT            0xE6  // Keyboard RightAlt                  /   Y   /   Y   /   Y   /
#define KEY_RIGHTGUI            0xE7  // Keyboard Right GUI                 /   Y   /   Y   /   Y   /
// Reserved            0xE8 - 0xFFFF
