
#include "ai-data.h"

#include "ai-script.h"

#include "constants/items.h"
#include "constants/jids.h"
#include "constants/chapters.h"
#include "constants/terrains.h"

u8 CONST_DATA gUnk_085C864C[] =
{
    TERRAIN_VILLAGE,
    TERRAIN_CHURCH,
    0,
};

u8 CONST_DATA gUnk_085C864F[] =
{
    TERRAIN_VILLAGE,
    TERRAIN_CHURCH,
    TERRAIN_CHEST,
    0,
};

struct AiScr CONST_DATA AiScr_FallbackA[] =
{
    AI_ACTION(100),
};

struct AiScr CONST_DATA AiScr_FallbackB[] =
{
    AI_MOVE_TO_ENEMY,
};

static u8 const gUnk_0810D6F8[] = { JID_ROY, 0 };
static u8 const gUnk_0810D6FA[] = { JID_THIEF, JID_THIEF_F, JID_BARD, JID_DANCER, 0 };
static u8 const gUnk_0810D6FF[] = { JID_PRIEST, JID_CLERIC, JID_TROUBADOUR, 0 };
static u8 const gUnk_0810D703[] = { JID_CIVILIAN, JID_CIVILIAN_F, JID_CHILD, JID_CHILD_F, 0 };
static u8 const gUnk_0810D708[] = { JID_BISHOP, JID_BISHOP_F, JID_MAGE, JID_MAGE_F, JID_SAGE, JID_SAGE_F, JID_SHAMAN, JID_SHAMAN_F, JID_DRUID, JID_DRUID_F, JID_VALKYRIE, 0 };
static u8 const gUnk_0810D714[] = { JID_PEGASUSKNIGHT, JID_FALCOKNIGHT, JID_WYVERNRIDER, JID_WYVERNRIDER_F, JID_WYVERNLORD, JID_WYVERNLORD_F, 0 };
static u8 const gUnk_0810D71B[] = { JID_ARMOR, JID_GENERAL, 0 };
static u8 const gUnk_0810D71E[] = { JID_CAVALIER, JID_CAVALIER_F, JID_PALADIN, JID_PALADIN_F, 0 };
static u8 const gUnk_0810D723[] = { JID_ARCHER, JID_ARCHER_F, JID_SNIPER, JID_SNIPER_F, 0 };

u8 const* CONST_DATA gUnk_085C8674[] =
{
    gUnk_0810D6F8,
    gUnk_0810D6FA,
    gUnk_0810D6FF,
    gUnk_0810D703,
    gUnk_0810D708,
    gUnk_0810D714,
    gUnk_0810D71B,
    gUnk_0810D71E,
    gUnk_0810D723,
    NULL,
};

struct AiAttackStruct const gUnk_0810D728[] =
{
    [0] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [1] =
    {
        .unk_00 = 1,
        .unk_01 = 2,
        .unk_02 = 2,
        .unk_03 = 2,
        .unk_04 = 0,
        .unk_05 = 0,
        .unk_06 = 0,
        .unk_07 = 0,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [2] =
    {
        .unk_00 = 1,
        .unk_01 = 2,
        .unk_02 = 2,
        .unk_03 = 2,
        .unk_04 = 2,
        .unk_05 = 2,
        .unk_06 = 1,
        .unk_07 = 2,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [3] =
    {
        .unk_00 = 2,
        .unk_01 = 2,
        .unk_02 = 2,
        .unk_03 = 2,
        .unk_04 = 0,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [4] =
    {
        .unk_00 = 1,
        .unk_01 = 0,
        .unk_02 = 0,
        .unk_03 = 0,
        .unk_04 = 2,
        .unk_05 = 0,
        .unk_06 = 0,
        .unk_07 = 0,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [5] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 0,
        .unk_06 = 0,
        .unk_07 = 0,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
            [5] = 40,
        }
    },

    [6] =
    {
        .unk_00 = 2,
        .unk_01 = 2,
        .unk_02 = 2,
        .unk_03 = 2,
        .unk_04 = 0,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 5,
            [4] = 5,
            [5] = 5,
            [6] = 40,
        }
    },

    [7] =
    {
        .unk_00 = 2,
        .unk_01 = 2,
        .unk_02 = 2,
        .unk_03 = 2,
        .unk_04 = 0,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 5,
            [4] = 5,
            [5] = 5,
            [7] = 40,
        }
    },

    [8] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 2,
        .unk_04 = 0,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 5,
            [3] = 40,
        }
    },

    [9] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 = {}
    },

    [10] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [2] = 40,
            [4] = 40,
        }
    },

    [11] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 2,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
            [8] = 40,
        }
    },

    [12] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 2,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 20,
            [1] = 20,
            [2] = 20,
            [4] = 20,
            [5] = 20,
            [6] = 20,
            [7] = 20,
            [8] = 20,
        }
    },

    [13] =
    {
        .unk_00 = 1,
        .unk_01 = 2,
        .unk_02 = 1,
        .unk_03 = 2,
        .unk_04 = 1,
        .unk_05 = 2,
        .unk_06 = 2,
        .unk_07 = 2,
        .unk_08 =
        {
            [0] = 20,
            [1] = 25,
            [3] = 20,
            [4] = 25,
            [5] = 20,
            [6] = 20,
            [7] = 20,
            [8] = 20,
        }
    },

    [14] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 0,
        .unk_03 = 0,
        .unk_04 = 0,
        .unk_05 = 2,
        .unk_06 = 0,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [15] =
    {
        .unk_00 = 1,
        .unk_01 = 1,
        .unk_02 = 0,
        .unk_03 = 0,
        .unk_04 = 0,
        .unk_05 = 1,
        .unk_06 = 0,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [16] =
    {
        .unk_00 = 2,
        .unk_01 = 2,
        .unk_02 = 2,
        .unk_03 = 2,
        .unk_04 = 0,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 5,
            [4] = 5,
        }
    },

    [17] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 0,
        .unk_06 = 0,
        .unk_07 = 0,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [18] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 0,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [19] =
    {
        .unk_00 = 2,
        .unk_01 = 2,
        .unk_02 = 2,
        .unk_03 = 2,
        .unk_04 = 0,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [20] =
    {
        .unk_00 = 1,
        .unk_01 = 0,
        .unk_02 = 0,
        .unk_03 = 0,
        .unk_04 = 2,
        .unk_05 = 0,
        .unk_06 = 0,
        .unk_07 = 0,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [21] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 0,
        .unk_06 = 0,
        .unk_07 = 0,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [22] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 2,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 5,
            [4] = 5,
            [5] = 5,
            [6] = 50,
        }
    },

    [23] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 2,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 5,
            [4] = 5,
            [5] = 5,
            [7] = 50,
        }
    },

    [24] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 2,
        .unk_04 = 0,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 5,
            [3] = 80,
        }
    },

    [25] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 = {}
    },

    [26] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 25,
            [2] = 40,
        }
    },

    [27] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 2,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
            [8] = 40,
        }
    },

    [28] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 1,
        .unk_03 = 2,
        .unk_04 = 1,
        .unk_05 = 1,
        .unk_06 = 1,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 20,
            [1] = 20,
            [2] = 20,
            [4] = 20,
            [5] = 20,
            [6] = 20,
            [7] = 20,
            [8] = 20,
        }
    },

    [29] =
    {
        .unk_00 = 1,
        .unk_01 = 2,
        .unk_02 = 1,
        .unk_03 = 1,
        .unk_04 = 1,
        .unk_05 = 2,
        .unk_06 = 1,
        .unk_07 = 2,
        .unk_08 =
        {
            [0] = 20,
            [1] = 25,
            [3] = 20,
            [4] = 25,
            [5] = 20,
            [6] = 20,
            [7] = 20,
            [8] = 20,
        }
    },

    [30] =
    {
        .unk_00 = 2,
        .unk_01 = 1,
        .unk_02 = 0,
        .unk_03 = 0,
        .unk_04 = 0,
        .unk_05 = 2,
        .unk_06 = 0,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },

    [31] =
    {
        .unk_00 = 1,
        .unk_01 = 1,
        .unk_02 = 0,
        .unk_03 = 0,
        .unk_04 = 0,
        .unk_05 = 1,
        .unk_06 = 0,
        .unk_07 = 1,
        .unk_08 =
        {
            [0] = 10,
            [1] = 15,
            [4] = 5,
        }
    },
};

u8 CONST_DATA gUnk_085C869C[] =
{
    0x01, 0x00,
    0x00, 0x00,
    0x02, 0x00,
    0x00, 0x00,
    0x2B, 0x00,
    0x34, 0x00,
    0x00, 0x00,
    0xA4, 0x00,
    0xCD, 0x00,
    0x00, 0x00,
    0x06, 0x00,
    0x0B, 0x1F,
    0x00, 0x00,
    0x00, 0x00,
};

struct AiEscapePt const AiEscapePts_1[] =
{
    { 0, 4, FACING_LEFT },
    { -1 },
};

struct AiEscapePt const AiEscapePts_2[] =
{
    { -1 },
};

struct AiEscapePt const AiEscapePts_6[] =
{
    { 14, 0, FACING_UP },
    { -1 },
};

struct AiEscapePt const AiEscapePts_8[] =
{
    { 0, 4, FACING_LEFT },
    { -1 },
};

struct AiEscapePt const AiEscapePts_26[] =
{
    { 16, 0, FACING_UP },
    { -1 },
};

struct AiEscapePt const AiEscapePts_11[] =
{
    { 23, 0, FACING_UP },
    { -1 },
};

struct AiEscapePt const AiEscapePts_27[] =
{
    { 28, 0, FACING_UP },
    { -1 },
};

struct AiEscapePt const AiEscapePts_12[] =
{
    { 12, 31, FACING_DOWN },
    { -1 },
};

struct AiEscapePt const AiEscapePts_13[] =
{
    { 45, 6, FACING_RIGHT },
    { -1 },
};

struct AiEscapePt const AiEscapePts_15[] =
{
    { 27, 23, FACING_RIGHT },
    { -1 },
};

struct AiEscapePt const AiEscapePts_16[] =
{
    { 6, 22, 5 },
    { -1 },
};

struct AiEscapePt const AiEscapePts_20[] =
{
    { 13, 0, FACING_UP },
    { -1 },
};

struct AiEscapePt const AiEscapePts_22[] =
{
    { 1, 31, FACING_DOWN },
    { -1 },
};

struct AiEscapePt const AiEscapePts_31[] =
{
    { 15, 25, FACING_DOWN },
    { -1 },
};

struct AiEscapePt const AiEscapePts_33[] =
{
    { 2, 26, FACING_DOWN },
    { -1 },
};

struct AiEscapePt const AiEscapePts_None[] =
{
    { -1 },
};

struct AiEscapePt const* CONST_DATA gUnk_085C86B8[CHAPTER_COUNT] =
{
    AiEscapePts_None,
    AiEscapePts_1,
    AiEscapePts_2,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_6,
    AiEscapePts_None,
    AiEscapePts_8,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_12,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_16,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_20,
    AiEscapePts_None,
    AiEscapePts_22,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_31,
    AiEscapePts_None,
    AiEscapePts_33,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
};

struct AiEscapePt const* CONST_DATA gUnk_085C876C[CHAPTER_COUNT] =
{
    AiEscapePts_None,
    AiEscapePts_1,
    AiEscapePts_2,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_6,
    AiEscapePts_None,
    AiEscapePts_8,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_11,
    AiEscapePts_12,
    AiEscapePts_13,
    AiEscapePts_None,
    AiEscapePts_15,
    AiEscapePts_16,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_20,
    AiEscapePts_None,
    AiEscapePts_22,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_26,
    AiEscapePts_27,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_31,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
};

struct AiHealThreshold CONST_DATA gUnk_085C8820[] =
{
    { 100,  50 },
    {  80,  30 },
    {  50,  10 },
    { 100,  80 },
    {   0,   0 },
};

u16 CONST_DATA gUnk_085C8834[] =
{
    IID_FIRESTONE,
    IID_DIVINESTONE,
    IID_DEMONSTONE,
    IID_HEROCREST,
    IID_KNIGHTCREST,
    IID_ORIONBOLT,
    IID_ELYSIANWHIP,
    IID_GUIDINGRING,
    IID_SKILLBOOSTER,
    IID_LUCKBOOSTER,
    IID_HPBOOSTER,
    IID_DEFBOOSTER,
    IID_POWBOOSTER,
    IID_SPEEDBOOSTER,
    IID_RESBOOSTER,
    IID_MOVBOOSTER,
    IID_CONBOOSTER,
    IID_MEMBERCARD,
    IID_SILVERCARD,
    IID_ELIXIR,
    IID_CHESTKEY,
    IID_DOORKEY,
    IID_BRIDGEKEY,
    IID_LOCKPICK,
    IID_VULNERARY,
    IID_PUREWATER,
    IID_TORCH,
    IID_ANTITOXIN,
    -1,
};
