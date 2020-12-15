
#pragma once

#include "common.h"

#include "ai.h"

struct AiAttackStruct
{
    /* 00 */ u8 unk_00;
    /* 01 */ u8 unk_01;
    /* 02 */ u8 unk_02;
    /* 03 */ u8 unk_03;
    /* 04 */ u8 unk_04;
    /* 05 */ u8 unk_05;
    /* 06 */ u8 unk_06;
    /* 07 */ u8 unk_07;
    /* 08 */ u8 unk_08[9];
};

struct AiEscapePt
{
    /* 00 */ u8 x, y;
    /* 02 */ u8 facing;
};

struct AiHealThreshold
{
    u8 exitThreshold;
    u8 enterThreshold;
};

extern u8 CONST_DATA gUnk_085C864C[];
extern u8 CONST_DATA gUnk_085C864F[];
extern struct AiScr CONST_DATA AiScr_FallbackA[];
extern struct AiScr CONST_DATA AiScr_FallbackB[];
extern u8 const* CONST_DATA gUnk_085C8674[];
extern struct AiAttackStruct const gUnk_0810D728[];
extern struct AiEscapePt const* CONST_DATA gUnk_085C86B8[];
extern struct AiEscapePt const* CONST_DATA gUnk_085C876C[];
extern struct AiHealThreshold CONST_DATA gUnk_085C8820[];
extern u16 CONST_DATA gUnk_085C8834[];
extern u32 const AiItemConfigTable[];
extern struct AiScr const* const* CONST_DATA gAiScriptLutB[];
extern struct AiScr const* const* CONST_DATA gAiScriptLutA[];
