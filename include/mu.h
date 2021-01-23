
#pragma once

#include "common.h"
#include "proc.h"
#include "anim.h"

enum
{
    MU_STATE_NOSTATE,
    MU_STATE_NONACTIVE,
    MU_STATE_MOVEMENT,
    MU_STATE_WAITING,
    MU_STATE_UNK4,
    MU_STATE_BUMPING,
    MU_STATE_DISPLAY_UI,
    MU_STATE_DEATHFADE,
};

struct MuConfig;

struct MuProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Unit* unit;
    /* 30 */ struct Anim* anim;
    /* 34 */ struct MuConfig* config;

    /* 38 */ u8 boolCam;
    /* 39 */ u8 state;
    /* 3A */ u8 boolHidden;
    /* 3B */ u8 jid;
    /* 3C */ s8 facing;
    /* 3D */ u8 stepSoundClock;
    /* 3E */ u8 unk_3E;
    /* 3F */ // pad
    /* 40 */ u16 moveClock;
    /* 42 */ u16 unk_42;
    /* 44 */ short q4_x, q4_y;
    /* 48 */ short q4_xOffset, q4_yOffset;

    /* ?? */ u8* vramImg;

    /* ?? */ u8 id;
    /* ?? */ u8 unk3D;
    /* ?? */ u8 forceMaxSpeed;
    /* ?? */ u16 oam2;
    /* ?? */ short moveConfig;
};

struct MuConfig
{
    /* 00 */ u8 id;
    /* 01 */ u8 pal;
    /* 02 */ u16 chr;
    /* 04 */ u8 pc;
    /* 05 */ s8 movescr[0x40];
    /* 45 */ // 3 byte padding
    /* 48 */ struct MuProc* mu;
};

struct MuProc* MU_Start(struct Unit* unit);
struct MuProc* MU_StartExt(u16 x, u16 y, u16 jid, int pal);
void sub_805F91C(struct MuProc* mu);
s8 sub_805FD40(struct MuProc* proc);
void sub_805FD78(struct MuProc* mu, u8 const* movescr);
void sub_80608EC(struct MuProc* proc);
void MU_SetDefaultFacing_Auto(void);
void MU_StartDeathFade(struct MuProc* mu);
Bool MU_CanStart(void);
void MU_EndAll(void);
Bool MU_IsAnyActive(void);
