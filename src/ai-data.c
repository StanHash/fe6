
#include "ai-data.h"

#include "ai-script.h"

#include "constants/items.h"
#include "constants/jids.h"
#include "constants/pids.h"
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

// unused
u16 CONST_DATA PList_AiRoy[] =
{
    PID_ROY, 0,
};

u16 CONST_DATA PList_AiClarine[] =
{
    PID_CLARINE, 0,
};

u16 CONST_DATA PList_AiLalumAndElfin[] =
{
    PID_LALUM, PID_ELFIN, 0,
};

u16 CONST_DATA PList_Ai_085C86AA[] =
{
    PID_CITIZEN_A4, PID_CITIZEN_CD, 0,
};

u8 CONST_DATA TerrainList_AiArmory[] =
{
    TERRAIN_ARMORY, 0,
};

u8 CONST_DATA TerrainList_AiSeizePoint[] =
{
    TERRAIN_GATE_0B, TERRAIN_THRONE, 0,
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

u32 const AiItemConfigTable[] =
{
    [CHAPTER_TUTORIAL] = 0x7,
    [CHAPTER_CH01]     = 0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
};

// ===============
// = ??? ??? ??? =
// ===============

struct Vec2 const gUnk_0810DADC[] =
{
    {  3,  1 },
    {  3,  5 },
    {  7,  5 },
    {  7,  1 },

    { -1, -1 },
};

struct Vec2 const gUnk_0810DAF0[] =
{
    {  9,  9 },
    { 13, 15 },
    {  3, 18 },

    { -1, -1 },
};

struct Vec2 const* CONST_DATA gUnk_085C8870[] =
{
    gUnk_0810DADC,
    gUnk_0810DAF0,
};

struct Vec2 const* const* CONST_DATA gUnk_085C8878 = gUnk_085C8870;

char CONST_DATA gUnk_085C887C[] = "CALL TEST\n";
char CONST_DATA gUnk_085C8887   = 3;

// ==============
// = AI SCRIPTS =
// ==============

struct AiScr CONST_DATA AiScr_AiB_MoveToEnemy[] =
{
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_MoveToEnemy_IgnoreClarine[] =
{
    AI_MOVE_TO_ENEMY_IGNORING(PList_AiClarine),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_MoveToEnemy_IgnoreRefreshers[] =
{
    AI_MOVE_TO_ENEMY_IGNORING(PList_AiLalumAndElfin),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_Nop[] =
{
    AI_NOP_0E,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_PillageThenPursue[] =
{
    AI_PILLAGE,
    AI_SET_AI(AI_A_00, AI_B_00),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_PillageThenStop[] =
{
    AI_PILLAGE,
    AI_SET_AI(AI_A_06, AI_B_0C),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_Escape[] =
{
    AI_ESCAPE,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_MoveTo_21_17[] =
{
    AI_MOVE_TOWARDS(21, 17),

AI_LABEL(1),
    AI_NOP,
    AI_GOTO(1),
};

// FIXME: use sub_80336CC input struct
u8 const gUnk_0810DB00[] = { -1, +1, 0, 0 };

struct AiScr CONST_DATA AiScr_Unk_085C89C8[] =
{
    AI_CALL_FUNC(sub_80337B4, NULL),
    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_GOTO_START,

AI_LABEL(1),
    AI_CALL_FUNC(sub_80336CC, gUnk_0810DB00),
};

// FIXME: use sub_80333B0 input struct
u8 const gUnk_0810DB04[] = { +32, +1, 0, 0 };

struct AiScr CONST_DATA AiScr_Unk_085C8A18[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB04),
    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_NOP_0E,
    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI_B(AI_B_00),
    AI_GOTO(1),
};

struct AiScr CONST_DATA AiScr_Unk_085C8A88[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB04),
    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_NOP_0E,
    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI_B(AI_B_01),
    AI_GOTO(1),
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8AF8[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB04),
    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_NOP_0E,
    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI_B(AI_B_00),
    AI_GOTO(1),
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8B68[] =
{
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8B88[] =
{
    AI_MOVE_RANDOM,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8BA8[] =
{
    AI_MOVE_TO_LISTED_TERRAIN(TerrainList_AiArmory),
    AI_GOTO_IFEQ(1, gAiSt.unk_86+0, 4),
    AI_GOTO_START,

AI_BAD_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8C08[] =
{
    AI_MOVE_TO_LISTED_TERRAIN(TerrainList_AiSeizePoint),
    AI_GOTO_IFEQ(1, gAiSt.unk_86+0, 4),
    AI_GOTO_START,

AI_BAD_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_Action[] =
{
    AI_ACTION(100),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_Action80[] =
{
    AI_ACTION(80),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_Action50[] =
{
    AI_ACTION(50),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_ActionInPlace[] =
{
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_ActionInPlace80[] =
{
    AI_ACTION_IN_PLACE(80),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_ActionInPlace50[] =
{
    AI_ACTION_IN_PLACE(50),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_Nop[] =
{
    AI_NOP,
    AI_GOTO_START,
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8D48[] =
{
    AI_ACTION(100),

    AI_CALL_FUNC(sub_80336B0, NULL),
    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_GOTO_START,

AI_LABEL(1),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO(1),
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8DB8[] =
{
    AI_ACTION(100),
    AI_GOTO_START,
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8DD8[] =
{
    AI_ACTION(100),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8DF8[] =
{
    AI_ACTION_IGNORING(100, PList_AiClarine),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8E18[] =
{
    AI_ACTION_IGNORING(100, PList_AiLalumAndElfin),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8E38[] =
{
    AI_ACTION_IGNORING(100, PList_Ai_085C86AA),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8E58[] =
{
    AI_ACTION_ON_PID(100, PID_LILINA),

    AI_GOTO_IFEQ(1, gAiSt.unk_86+0, 3),
    AI_GOTO_IFNE(0, gAiSt.unk_86+0, 1),

AI_LABEL(1),
    AI_ACTION(100),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8EB8[] =
{
    AI_ACTION_ON_PID(100, PID_ROY),

    AI_GOTO_IFNE(0, gAiSt.unk_86+0, 3),

    AI_ACTION(100),
    AI_GOTO_START,
};

// FIXME: use sub_80333B0 input struct
u8 const gUnk_0810DB08[] = { +8, +1, 0, 0, };

struct AiScr CONST_DATA AiScr_Unk_085C8EF8[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB08),

    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_ACTION(100),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8F68[] =
{
    AI_CALL_FUNC(sub_8033898, NULL),

    AI_GOTO_IFEQ(1, gAiSt.unk_86+1, 1),

    AI_CALL_FUNC(sub_8033AA4, NULL),
    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI(AI_A_00, AI_B_00),
    AI_GOTO_START,
};

// FIXME: use sub_8033998 input struct
struct { u8 unk_00; } const gUnk_0810DB0C[] = { 1 };

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8FD8[] =
{
    AI_CALL_FUNC(sub_8033998, gUnk_0810DB0C),

    AI_GOTO_IFEQ(1, gAiSt.unk_86+1, 1),

    AI_CALL_FUNC(sub_8033AA4, NULL),
    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI(AI_A_00, AI_B_00),
    AI_GOTO_START,
};

// FIXME: use sub_80333B0 input struct
u8 const gUnk_0810DB10[] = { 8, 1, 0, 0 };

struct AiScr CONST_DATA AiScr_Unk_085C9048[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_MOVE_TOWARDS(5, 7),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C90C8[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_MOVE_TOWARDS(17, 6),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C9148[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_MOVE_TOWARDS(19, 4),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C91C8[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_MOVE_TOWARDS(4, 2),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C9248[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_MOVE_TOWARDS(6, 2),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C92C8[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_MOVE_TOWARDS(4, 3),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C9348[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_MOVE_TOWARDS(5, 3),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C93C8[] =
{
    AI_CALL_FUNC(sub_80333B0, gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.unk_86+0, 0),

    AI_MOVE_TOWARDS(6, 3),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

// FIXME: use AiFunc_DecideTalk input struct
struct { u8 pidA, pidB; } const gUnk_0810DB14 = { PID_LANCE, PID_ALAN };

struct AiScr CONST_DATA AiScr_Unk_085C9448[] =
{
    AI_MOVE_TOWARDS_PID(PID_ALAN),
    AI_GOTO_IFNE(0, gAiSt.unk_86+0, 2),

    AI_CALL_FUNC(AiFunc_DecideTalk, &gUnk_0810DB14),
    AI_SET_AI(AI_A_00, AI_B_00),
};

// FIXME: use AiFunc_DecideTalk input struct
struct { u8 pidA, pidB; } const gUnk_0810DB18 = { PID_CLARINE, PID_ROY };

struct AiScr CONST_DATA AiScr_AiB_Clarine[] =
{
    AI_MOVE_TOWARDS_PID(PID_ROY),

    AI_GOTO_IFEQ(1, gAiSt.unk_86+0, 4),
    AI_GOTO_IFEQ(0, gAiSt.unk_86+0, 3),
    AI_GOTO_IFNE(0, gAiSt.unk_86+0, 2),

    AI_CALL_FUNC(AiFunc_DecideTalk, &gUnk_0810DB18),
    AI_SET_AI(AI_A_00, AI_B_00),
    AI_GOTO_START,

AI_LABEL(1),
    AI_NOP_0E,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_MoveToRoy[] =
{
    AI_MOVE_TOWARDS_PID(PID_ROY),

    AI_GOTO_IFEQ(1, gAiSt.unk_86+0, 4),
    AI_GOTO_IFEQ(2, gAiSt.unk_86+0, 1),

    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,

AI_LABEL(2),
    AI_MOVE_TO_ENEMY,
    AI_GOTO(2),
};

struct AiScr CONST_DATA AiScr_AiB_MoveToLilina[] =
{
    AI_MOVE_TOWARDS_PID(PID_LILINA),

    AI_GOTO_IFEQ(1, gAiSt.unk_86+0, 4),
    AI_GOTO_IFEQ(2, gAiSt.unk_86+0, 1),

    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,

AI_LABEL(2),
    AI_MOVE_TO_ENEMY,
    AI_GOTO(2),
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C9568[] =
{
    AI_CALL_FUNC(sub_8033898, NULL),
    AI_CALL_FUNC(sub_8033AA4, NULL),
    AI_GOTO_START,
};

// FIXME: use sub_8033B04 input struct
struct { u8 chance, unk_01; } const gUnk_0810DB1C = { 100, 50 };

struct AiScr CONST_DATA AiScr_Unk_085C9698[] =
{
    AI_CALL_FUNC(sub_8033B04, &gUnk_0810DB1C),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C96B8[] =
{
    AI_CALL_FUNC(sub_8033B04, &gUnk_0810DB1C),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,
};

// FIXME: use sub_8033B50 input struct
struct { u8 a, b; } const gUnk_0810DB20 = { 100, 0 };

struct AiScr CONST_DATA AiScr_Unk_085C96E8[] =
{
    AI_CALL_FUNC(sub_8033B50, &gUnk_0810DB20),
    AI_GOTO_IFEQ(1, gAiSt.unk_86+0, 5),

    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI(AI_A_06, AI_B_0C),
    AI_GOTO_START,
};

static struct AiScr const* CONST_DATA sAiScriptLutB[] =
{
    AiScr_AiB_MoveToEnemy,
    AiScr_AiB_MoveToEnemy_IgnoreClarine,
    AiScr_AiB_MoveToEnemy_IgnoreRefreshers,
    AiScr_AiB_Nop,
    AiScr_AiB_PillageThenPursue,
    AiScr_AiB_PillageThenStop,
    AiScr_Unk_085C8A18,
    AiScr_Unk_085C8A88,
    AiScr_Unk_085C89C8,
    AiScr_Unk_085C8B88,
    AiScr_Unk_085C9448,
    AiScr_AiB_Clarine,
    AiScr_AiB_Escape,
    AiScr_AiB_MoveTo_21_17,
    AiScr_AiB_MoveToRoy,
    AiScr_AiB_MoveToLilina,
    AiScr_Unk_085C9048,
    AiScr_Unk_085C90C8,
    AiScr_Unk_085C9148,
    AiScr_Unk_085C91C8,
    AiScr_Unk_085C9248,
    AiScr_Unk_085C92C8,
    AiScr_Unk_085C9348,
    AiScr_Unk_085C93C8,
    AiScr_Unk_085C8C08,
};

static struct AiScr const* CONST_DATA sAiScriptLutA[] =
{
    AiScr_AiA_Action,
    AiScr_AiA_Action80,
    AiScr_AiA_Action50,
    AiScr_AiA_ActionInPlace,
    AiScr_AiA_ActionInPlace80,
    AiScr_AiA_ActionInPlace50,
    AiScr_AiA_Nop,
    AiScr_Unk_085C8DF8,
    AiScr_Unk_085C8E18,
    AiScr_Unk_085C8E38,
    AiScr_Unk_085C8E58,
    AiScr_Unk_085C8EB8,
    AiScr_Unk_085C8EF8,
    AiScr_Unk_085C8F68,
    AiScr_Unk_085C9698,
    AiScr_Unk_085C96B8,
};

struct AiScr const* const* CONST_DATA gAiScriptLutB[] =
{
    sAiScriptLutB,
    sAiScriptLutB,
    sAiScriptLutB,
};

struct AiScr const* const* CONST_DATA gAiScriptLutA[] =
{
    sAiScriptLutA,
    sAiScriptLutA,
    sAiScriptLutA,
};
