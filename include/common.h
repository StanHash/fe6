#pragma once

#if defined(MODERN) && MODERN
#  ifndef MODERN
#    define MODERN
#  endif
#  ifdef NONMATCHING
#    undef NONMATCHING
#  endif // NONMATCHING
#  ifdef BUGFIX
#    undef BUGFIX
#  endif // BUGFIX
#  define NONMATCHING 1
#  define BUGFIX 1
#endif // MODERN

#include <stdint.h>
#include <stddef.h>

#include "gba/gba.h"

#include "attributes.h"
#include "types.h"

#include "unknown_types.h"
#include "unknown_funcs.h"
#include "unknown_objects.h"

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#define ABS(val) ((val) >= 0 ? (val) : -(val))

#define RECT_DISTANCE(xa, ya, xb, yb) (ABS((xa) - (xb)) + ABS((ya) - (yb)))

// For translate-able strings.
#define JTEXT(orig) (orig)
#define TEXT(orig, english) (orig)

#if defined(MODERN) && MODERN
#  define STATIC_ASSERT(expr) _Static_assert(expr)
#else
#  define STATIC_ASSERT(expr)
#endif
