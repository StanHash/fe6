
#pragma once

#include "gba/gba.h"

// TODO: move elsewhere
#define CHR_SIZE 0x20

enum
{
    BGCHR_TEXT_DEFAULT = 0x80,

    BGCHR_DEBUGTEXT_DEFAULT = 0x2C0,

    BGCHR_ICON_BEGIN = 0x280,
    BGCHR_ICON_END   = 0x300,
};

enum
{
    BGPAL_DEBUGTEXT = 0,
    BGPAL_TEXT_DEFAULT = 0,
};

enum
{
    OBJCHR_DEBUGTEXT_DEFAULT = 0x180,
};
