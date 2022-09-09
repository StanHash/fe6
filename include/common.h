#pragma once

#if defined(MODERN) && MODERN
#  ifdef NONMATCHING
#    undef NONMATCHING
#  endif // NONMATCHING
#  ifdef BUGFIX
#    undef BUGFIX
#  endif // BUGFIX
#  define NONMATCHING 1
#  define BUGFIX 1
#endif // MODERN

#include "gba/gba.h"

#include "attributes.h"
#include "types.h"

#include "unk-types.h"
#include "unk-funcs.h"
#include "unk-objects.h"

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#define ABS(val) ((val) >= 0 ? (val) : -(val))

#define RECT_DISTANCE(xa, ya, xb, yb) (ABS((xa) - (xb)) + ABS((ya) - (yb)))

// For translate-able strings.
#define TEXT(str) (str)
