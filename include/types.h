#pragma once

#include <stdint.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;

typedef float  f32;
typedef double f64;

typedef i8  fi8;
typedef i16 fi16;
typedef u8  fu8;
typedef u16 fu16;

typedef u8  volatile vu8;
typedef u16 volatile vu16;
typedef u32 volatile vu32;
typedef u64 volatile vu64;
typedef i8  volatile vi8;
typedef i16 volatile vi16;
typedef i32 volatile vi32;
typedef i64 volatile vi64;

#if !defined(__cplusplus) && !defined(bool)

typedef i8 bool;

#endif

typedef void(*Func)(void);

struct Vec2
{
    i16 x, y;
};

struct Vec2u
{
    u16 x, y;
};

// Forward decls for common types
// TODO: move

struct BmSt;
struct PlaySt;

struct Unit;
struct UnitInfo;
struct UnitSprite;
struct SupportInfo;

struct HelpBoxInfo;
