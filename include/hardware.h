
#pragma once

#include "gba/gba.h"

struct KeySt
{
    /* 00 */ u8 repeatDelay;     // initial delay before generating auto-repeat presses
    /* 01 */ u8 repeatInterval;  // time between auto-repeat presses
    /* 02 */ u8 repeatTimer;     // (decreased by one each frame, reset to repeatDelay when Presses change and repeatInterval when reaches 0)
    /* 04 */ u16 held;           // keys that are currently held down
    /* 06 */ u16 repeated;       // auto-repeated keys
    /* 08 */ u16 pressed;        // keys that went down this frame
    /* 0A */ u16 previous;       // keys that were held down last frame
    /* 0C */ u16 last;
    /* 0E */ bool16 ABLRPressed; // 1 for Release (A B L R Only), 0 Otherwise
    /* 10 */ u16 pressed2;
    /* 12 */ u16 timeSinceStartSelect; // Time since last Non-Start Non-Select Button was pressed
};

extern struct KeySt* gKeySt;

void ResetKeyStatus(struct KeySt* keySt);
void UpdateKeyStatus(struct KeySt* keySt);
