#pragma once

#include <stddef.h>

#define SECTION(name) __attribute__((section(name)))

#define IWRAM_DATA        SECTION("iwram_data")
#define EWRAM_DATA        SECTION("ewram_data")
#define EWRAM_OVERLAY(id) SECTION("ewram_overlay_" # id)

#define ALIGNED(n) __attribute__((aligned(n)))
#define NAKEDFUNC __attribute__((naked))

#if defined(MODERN) && MODERN
#  define CONST_DATA const
#  define SHOULD_BE_STATIC static
#  define SHOULD_BE_CONST const
#else
#  define CONST_DATA SECTION(".data")
#  define SHOULD_BE_STATIC
#  define SHOULD_BE_CONST
#endif
