// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

#define MOUSEKEY_INTERVAL 16  // Interval between scroll events (ms)
#define MOUSEKEY_DELAY 0      // Delay before scrolling starts
#define MOUSEKEY_TIME_TO_MAX 40  // Time to reach maximum scrolling speed
#define MOUSEKEY_WHEEL_INTERVAL 50  // Interval between wheel events
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100  // Time to reach maximum wheel speed

#define RGBLIGHT_DEFAULT_HUE 180  // Tone
#define RGBLIGHT_DEFAULT_SAT 255  // Saturation
#define RGBLIGHT_DEFAULT_VAL 120  // Brightness

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP 10
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 17
#endif
