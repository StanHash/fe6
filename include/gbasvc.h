#pragma once

#include "types.h"

struct BgAffineSetSrc
{
    /* +00 */ i32 tex_x;
    /* +04 */ i32 tex_y;
    /* +08 */ i16 scr_x;
    /* +0A */ i16 scr_y;
    /* +0C */ i16 sx;
    /* +0E */ i16 sy;
    /* +10 */ u16 alpha;
};

struct BgAffineSetDst
{
    /* +00 */ i16 pa;
    /* +02 */ i16 pb;
    /* +04 */ i16 pc;
    /* +06 */ i16 pd;
    /* +08 */ i32 dx;
    /* +0C */ i32 dy;
};

struct ObjAffineSetSrc
{
    /* +00 */ i16 x_scale;
    /* +02 */ i16 y_scale;
    /* +04 */ u16 rotation;
};

enum
{
    BIT_UNPACK_ADDEND_ZERO = 1 << 31,
};

struct BitUnpackInfo
{
    /* +00 */ u16 src_len;
    /* +02 */ u8  src_unit_bits;
    /* +03 */ u8  dst_unit_bits;
    /* +04 */ u32 data_addend;
};

enum
{
    GBA_RESET_EWRAM    = 1 << 0,
    GBA_RESET_IWRAM    = 1 << 1,
    GBA_RESET_PALETTE  = 1 << 2,
    GBA_RESET_VRAM     = 1 << 3,
    GBA_RESET_OAM      = 1 << 4,
    GBA_RESET_SIO_IO   = 1 << 5,
    GBA_RESET_SOUND_IO = 1 << 6,
    GBA_RESET_IO       = 1 << 7,
    GBA_RESET_ALL      = (1 << 8) - 1,
};

enum
{
    CPU_SET_SRC_FIXED = 0x01000000,
    CPU_SET_32BIT     = 0x04000000,
    CPU_SET_16BIT     = 0x00000000,
};

/* svc 00 */ void SoftReset(u32 reset_flags);
/* svc 01 */ void RegisterRamReset(u32 reset_flags);
// svc 02 */ void Halt(void);
// svc 03 */ void Stop(void);
// svc 04 */ void IntrWait(bool wait_next, u16 intr_flags);
/* svc 05 */ void VBlankIntrWait(void);
/* svc 06 */ i32  Div(i32 lhs, i32 rhs);
/* svc 06 */ i32  DivRem(i32 lhs, i32 rhs);
// svc 07 */ i32  DivArm(i32 rhs, i32 lhs);
/* svc 08 */ u16  Sqrt(u32 num);
// svc 09 */ u32  ArcTan(u16 tan);
/* svc 0A */ u16  ArcTan2(i16 x, i16 y);
/* svc 0B */ void CpuSet(const void * src, void * dst, u32 control);
/* svc 0C */ void CpuFastSet(const void * src, void * dst, u32 control);
// svc 0D */ u32  GetBiosChecksum(void);
/* svc 0E */ void BgAffineSet(struct BgAffineSetSrc const * src, struct BgAffineSetDst * dst, i32 count);
/* svc 0F */ void ObjAffineSet(struct ObjAffineSetSrc const * src, void * dest, i32 count, i32 offset);
// svc 10 */ void BitUnpack(void const * src, void * dst, struct BitUnpackInfo const * info);
/* svc 11 */ void LZ77UnCompWram(void const * src, void * dst);
/* svc 12 */ void LZ77UnCompVram(void const * src, void * dst);
/* svc 13 */ void HuffUnComp(void const * src, void * dst);
/* svc 14 */ void RLUnCompWram(void const * src, void * dst);
/* svc 15 */ void RLUnCompVram(void const * src, void * dst);
// svc 16 */ void Diff8bitUnFilterWram(void const * src, void * dst);
// svc 17 */ void Diff8bitUnFilterVram(void const * src, void * dst);
// svc 18 */ void Diff16bitUnFilter(void const * src, void * dst);
/* svc 19 */ void SoundBiasReset(void);
/* svc 19 */ void SoundBiasSet(void);
// ...
