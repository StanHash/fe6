
#pragma once

#include "gba/gba.h"

#include "types.h"
#include "unk-funcs.h"
#include "unk-objects.h"

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#define ABS(val) ((val) >= 0 ? (val) : -(val))

#define RECT_DISTANCE(xa, ya, xb, yb) (ABS((xa) - (xb)) + ABS((ya) - (yb)))
