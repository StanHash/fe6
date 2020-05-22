
#pragma once

#include "common.h"
#include "proc.h"

struct MuConfig;

struct MuProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Unit* unit;
    /* 30 */ void* ap;
    /* 34 */ struct MuConfig* config;
    /* 38 */ u8* vramImg;

    /* 3C */ u8 id;
    /* 3D */ u8 unk3D;
    /* 3E */ u8 boolCam;
    /* 3F */ u8 state;
    /* 40 */ u8 boolHidden;
    /* 41 */ u8 jidDisplayed;
    /* 42 */ s8 facing;
    /* 43 */ u8 stepSoundClock;
    /* 44 */ u8 forceMaxSpeed;
    /* 45 */ // pad
    /* 46 */ u16 oam2;
    /* 48 */ u16 moveClock;
    /* 4A */ short moveConfig;

    /* 4C */ short q4_x;
    /* 4E */ short q4_y;
    /* 50 */ short q4_xOffset;
    /* 52 */ short q4_yOffset;
};

struct MuConfig
{
    /* 00 */ u8 muId;
    /* 01 */ u8 palid;
    /* 02 */ u16 chr;
    /* 04 */ u8 currentCommand;
    /* 05 */ s8 commands[0x40];
    /* 45 */ // 3 byte padding
    /* 48 */ struct MuProc* mu;
};

struct MuProc* MU_Start(struct Unit* unit);
void sub_805F91C(struct MuProc* mu);
s8 sub_805FD40(struct MuProc* proc);
void sub_805FD78(struct MuProc* mu, u8 const* movescr);
void sub_80608EC(struct MuProc* proc);
void MU_SetDefaultFacing_Auto(void);
void MU_StartDeathFade(struct MuProc* mu);
Bool MU_CanStart(void);
void MU_EndAll(void);
Bool MU_IsAnyActive(void);
