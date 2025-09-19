/*
  Keyboard.h

  Modified by Earle F. Philhower, III <earlephilhower@yahoo.com>
  Main Arduino Library Copyright (c) 2015, Arduino LLC
  Original code (pre-library): Copyright (c) 2011, Peter Barrett

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

#include <Arduino.h>

//================================================================================
//================================================================================
//  Keyboard

// Modifiers
#define KEY_LEFT_CTRL     0x80
#define KEY_LEFT_SHIFT    0x81
#define KEY_LEFT_ALT      0x82
#define KEY_LEFT_GUI      0x83
#define KEY_RIGHT_CTRL    0x84
#define KEY_RIGHT_SHIFT   0x85
#define KEY_RIGHT_ALT     0x86
#define KEY_RIGHT_GUI     0x87

// Misc keys
#define KEY_UP_ARROW      0xDA
#define KEY_DOWN_ARROW    0xD9
#define KEY_LEFT_ARROW    0xD8
#define KEY_RIGHT_ARROW   0xD7
#define KEY_BACKSPACE     0xB2
#define KEY_TAB           0xB3
#define KEY_RETURN        0xB0
#define KEY_MENU          0xED // "Keyboard Application" in USB standard
#define KEY_ESC           0xB1
#define KEY_INSERT        0xD1
#define KEY_DELETE        0xD4
#define KEY_PAGE_UP       0xD3
#define KEY_PAGE_DOWN     0xD6
#define KEY_HOME          0xD2
#define KEY_END           0xD5
#define KEY_CAPS_LOCK     0xC1
#define KEY_PRINT_SCREEN  0xCE // Print Screen / SysRq
#define KEY_SCROLL_LOCK   0xCF
#define KEY_PAUSE         0xD0 // Pause / Break

// Numeric keypad
#define KEY_NUM_LOCK      0xDB
#define KEY_KP_SLASH      0xDC
#define KEY_KP_ASTERISK   0xDD
#define KEY_KP_MINUS      0xDE
#define KEY_KP_PLUS       0xDF
#define KEY_KP_ENTER      0xE0
#define KEY_KP_1          0xE1
#define KEY_KP_2          0xE2
#define KEY_KP_3          0xE3
#define KEY_KP_4          0xE4
#define KEY_KP_5          0xE5
#define KEY_KP_6          0xE6
#define KEY_KP_7          0xE7
#define KEY_KP_8          0xE8
#define KEY_KP_9          0xE9
#define KEY_KP_0          0xEA
#define KEY_KP_DOT        0xEB

// Function keys
#define KEY_F1            0xC2
#define KEY_F2            0xC3
#define KEY_F3            0xC4
#define KEY_F4            0xC5
#define KEY_F5            0xC6
#define KEY_F6            0xC7
#define KEY_F7            0xC8
#define KEY_F8            0xC9
#define KEY_F9            0xCA
#define KEY_F10           0xCB
#define KEY_F11           0xCC
#define KEY_F12           0xCD
#define KEY_F13           0xF0
#define KEY_F14           0xF1
#define KEY_F15           0xF2
#define KEY_F16           0xF3
#define KEY_F17           0xF4
#define KEY_F18           0xF5
#define KEY_F19           0xF6
#define KEY_F20           0xF7
#define KEY_F21           0xF8
#define KEY_F22           0xF9
#define KEY_F23           0xFA
#define KEY_F24           0xFB


// Cpnsumer keys, taken from TinyUSB

// Power Control
#define KEY_POWER                              0x0030
#define KEY_RESET                              0x0031
#define KEY_SLEEP                              0x0032

// Screen Brightness
#define KEY_BRIGHTNESS_INCREMENT               0x006F
#define KEY_BRIGHTNESS_DECREMENT               0x0070

// These HID usages operate only on mobile systems (battery powered) and
// require Windows 8 (build 8302 or greater).
#define KEY_WIRELESS_RADIO_CONTROLS            0x000C
#define KEY_WIRELESS_RADIO_BUTTONS             0x00C6
#define KEY_WIRELESS_RADIO_LED                 0x00C7
#define KEY_WIRELESS_RADIO_SLIDER_SWITCH       0x00C8

// Media Control
#define KEY_PLAY_PAUSE                         0x00CD
#define KEY_SCAN_NEXT                          0x00B5
#define KEY_SCAN_PREVIOUS                      0x00B6
#define KEY_STOP                               0x00B7
#define KEY_VOLUME                             0x00E0
#define KEY_MUTE                               0x00E2
#define KEY_BASS                               0x00E3
#define KEY_TREBLE                             0x00E4
#define KEY_BASS_BOOST                         0x00E5
#define KEY_VOLUME_INCREMENT                   0x00E9
#define KEY_VOLUME_DECREMENT                   0x00EA
#define KEY_BASS_INCREMENT                     0x0152
#define KEY_BASS_DECREMENT                     0x0153
#define KEY_TREBLE_INCREMENT                   0x0154
#define KEY_TREBLE_DECREMENT                   0x0155

// Application Launcher
#define KEY_AL_CONSUMER_CONTROL_CONFIGURATION  0x0183
#define KEY_AL_EMAIL_READER                    0x018A
#define KEY_AL_CALCULATOR                      0x0192
#define KEY_AL_LOCAL_BROWSER                   0x0194

// Browser/Explorer Specific
#define KEY_AC_SEARCH                          0x0221
#define KEY_AC_HOME                            0x0223
#define KEY_AC_BACK                            0x0224
#define KEY_AC_FORWARD                         0x0225
#define KEY_AC_STOP                            0x0226
#define KEY_AC_REFRESH                         0x0227
#define KEY_AC_BOOKMARKS                       0x022A

// Mouse Horizontal scroll
#define KEY_AC_PAN                             0x0238


// Supported keyboard layouts
extern const uint8_t KeyboardLayout_de_DE[];
extern const uint8_t KeyboardLayout_en_US[];
extern const uint8_t KeyboardLayout_es_ES[];
extern const uint8_t KeyboardLayout_fr_FR[];
extern const uint8_t KeyboardLayout_it_IT[];
extern const uint8_t KeyboardLayout_pt_PT[];
extern const uint8_t KeyboardLayout_sv_SE[];
extern const uint8_t KeyboardLayout_da_DK[];


// Low level key report: up to 6 keys and shift, ctrl etc at once
typedef struct
{
  uint8_t modifiers;
  uint8_t reserved;
  uint8_t keys[6];
} KeyReport;

class HID_Keyboard : public Print
{
protected:
  KeyReport _keyReport;
  const uint8_t *_asciimap;
  virtual void sendReport(KeyReport* keys) = 0;
  virtual void sendConsumerReport(uint16_t key) = 0;

public:
  HID_Keyboard(void);
  virtual void begin(const uint8_t *layout = KeyboardLayout_en_US);
  virtual void end(void);
  size_t write(uint8_t k);
  size_t write(const uint8_t *buffer, size_t size);
  size_t press(uint8_t k);
  size_t release(uint8_t k);
  void releaseAll(void);
  size_t consumerPress(uint16_t k);
  size_t consumerRelease();

  typedef void(*LedCallbackFcn)(bool numlock, bool capslock, bool scrolllock, bool compose, bool kana, void *cbData);
  void onLED(LedCallbackFcn fcn, void *cbData = nullptr);
  LedCallbackFcn _ledCB;
  void * _ledCBdata;
  bool _running;
};
