#include "unitsprite.h"

#include "armfunc.h"
#include "bm.h"
#include "faction.h"
#include "hardware.h"
#include "map.h"
#include "move.h"
#include "mu.h"
#include "oam.h"
#include "sprite.h"
#include "trap.h"
#include "unit.h"
#include "util.h"

#include "constants/terrains.h"
#include "constants/unitsprites.h"
#include "constants/videoalloc_global.h"

enum
{
    UNITSPRITE_FRAME_A = 0,
    UNITSPRITE_FRAME_B = 32,
    UNITSPRITE_FRAME_C = 36,
    UNITSPRITE_FRAME_D = 68,
    UNITSPRITE_FRAME_END = 72,
};

static int ApplyUnitSpriteImage16x16(int slot, u32 id);
static int ApplyUnitSpriteImage16x32(int slot, u32 id);
static int ApplyUnitSpriteImage32x32(int slot, u32 id);

u8 EWRAM_DATA gUnitSpriteSlots[UNITSPRITE_MAX] = { 0 };

u8 EWRAM_DATA gUnitSpriteBuf[3][UNITSPRITE_SHEET_SIZE] = { 0 };

int EWRAM_DATA gUnitSpriteSmallAllocCount = 0;
int EWRAM_DATA gUnitSpriteLargeAllocCount = 0;

struct UnitSprite EWRAM_DATA gUnitSprites[UNITSPRITE_SIMULATANEOUS_MAX] = { 0 };
struct UnitSprite * EWRAM_DATA gNextFreeUnitSprite = NULL;

int EWRAM_DATA gUnitSpriteSyncRequest = 0;

int EWRAM_DATA gUnitSpriteHoverClock = 0;

u8 * CONST_DATA UnitSpriteUnpackBuf = gBuf;

u16 CONST_DATA UnitSpriteSlotToChrTable[] = {
    0 * CHR_LINE + 0x00,  2 * CHR_LINE + 0x00,  0 * CHR_LINE + 0x02,  2 * CHR_LINE + 0x02,  0 * CHR_LINE + 0x04,
    2 * CHR_LINE + 0x04,  0 * CHR_LINE + 0x06,  2 * CHR_LINE + 0x06,  0 * CHR_LINE + 0x08,  2 * CHR_LINE + 0x08,
    0 * CHR_LINE + 0x0A,  2 * CHR_LINE + 0x0A,  0 * CHR_LINE + 0x0C,  2 * CHR_LINE + 0x0C,  0 * CHR_LINE + 0x0E,
    2 * CHR_LINE + 0x0E,  0 * CHR_LINE + 0x10,  2 * CHR_LINE + 0x10,  0 * CHR_LINE + 0x12,  2 * CHR_LINE + 0x12,
    0 * CHR_LINE + 0x14,  2 * CHR_LINE + 0x14,  0 * CHR_LINE + 0x16,  2 * CHR_LINE + 0x16,  0 * CHR_LINE + 0x18,
    2 * CHR_LINE + 0x18,  0 * CHR_LINE + 0x1A,  2 * CHR_LINE + 0x1A,  0 * CHR_LINE + 0x1C,  2 * CHR_LINE + 0x1C,
    0 * CHR_LINE + 0x1E,  2 * CHR_LINE + 0x1E,  4 * CHR_LINE + 0x00,  6 * CHR_LINE + 0x00,  4 * CHR_LINE + 0x02,
    6 * CHR_LINE + 0x02,  4 * CHR_LINE + 0x04,  6 * CHR_LINE + 0x04,  4 * CHR_LINE + 0x06,  6 * CHR_LINE + 0x06,
    4 * CHR_LINE + 0x08,  6 * CHR_LINE + 0x08,  4 * CHR_LINE + 0x0A,  6 * CHR_LINE + 0x0A,  4 * CHR_LINE + 0x0C,
    6 * CHR_LINE + 0x0C,  4 * CHR_LINE + 0x0E,  6 * CHR_LINE + 0x0E,  4 * CHR_LINE + 0x10,  6 * CHR_LINE + 0x10,
    4 * CHR_LINE + 0x12,  6 * CHR_LINE + 0x12,  4 * CHR_LINE + 0x14,  6 * CHR_LINE + 0x14,  4 * CHR_LINE + 0x16,
    6 * CHR_LINE + 0x16,  4 * CHR_LINE + 0x18,  6 * CHR_LINE + 0x18,  4 * CHR_LINE + 0x1A,  6 * CHR_LINE + 0x1A,
    4 * CHR_LINE + 0x1C,  6 * CHR_LINE + 0x1C,  4 * CHR_LINE + 0x1E,  6 * CHR_LINE + 0x1E,  8 * CHR_LINE + 0x00,
    10 * CHR_LINE + 0x00, 8 * CHR_LINE + 0x02,  10 * CHR_LINE + 0x02, 8 * CHR_LINE + 0x04,  10 * CHR_LINE + 0x04,
    8 * CHR_LINE + 0x06,  10 * CHR_LINE + 0x06, 8 * CHR_LINE + 0x08,  10 * CHR_LINE + 0x08, 8 * CHR_LINE + 0x0A,
    10 * CHR_LINE + 0x0A, 8 * CHR_LINE + 0x0C,  10 * CHR_LINE + 0x0C, 8 * CHR_LINE + 0x0E,  10 * CHR_LINE + 0x0E,
    8 * CHR_LINE + 0x10,  10 * CHR_LINE + 0x10, 8 * CHR_LINE + 0x12,  10 * CHR_LINE + 0x12, 8 * CHR_LINE + 0x14,
    10 * CHR_LINE + 0x14, 8 * CHR_LINE + 0x16,  10 * CHR_LINE + 0x16, 8 * CHR_LINE + 0x18,  10 * CHR_LINE + 0x18,
    8 * CHR_LINE + 0x1A,  10 * CHR_LINE + 0x1A, 8 * CHR_LINE + 0x1C,  10 * CHR_LINE + 0x1C, 8 * CHR_LINE + 0x1E,
    10 * CHR_LINE + 0x1E,
};

// clang-format off

u16 CONST_DATA Sprite_SleepIconA[] =
{
    1, OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x64) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_SleepIconB[] =
{
    1, OAM0_SHAPE_16x16 + OAM0_Y(-1), OAM1_SIZE_16x16, OAM2_CHR(0x64) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_SleepIconC[] =
{
    1, OAM0_SHAPE_16x16 + OAM0_Y(-2), OAM1_SIZE_16x16 + OAM1_X(-1), OAM2_CHR(0x64) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_SleepIconD[] =
{
    1, OAM0_SHAPE_16x16 + OAM0_Y(-3), OAM1_SIZE_16x16 + OAM1_X(-1), OAM2_CHR(0x4A) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_SleepIconE[] =
{
    1, OAM0_SHAPE_16x16 + OAM0_Y(-4), OAM1_SIZE_16x16 + OAM1_X(-2), OAM2_CHR(0x4A) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_SleepIconF[] =
{
    1, OAM0_SHAPE_16x16 + OAM0_Y(-5), OAM1_SIZE_16x16 + OAM1_X(-2), OAM2_CHR(0x4A) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_SleepIconG[] =
{
    1, OAM0_SHAPE_16x16 + OAM0_Y(-6), OAM1_SIZE_16x16 + OAM1_X(-3), OAM2_CHR(0x4A) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 const * CONST_DATA SleepIconSprites[] =
{
    Sprite_SleepIconA,
    Sprite_SleepIconB,
    Sprite_SleepIconC,
    Sprite_SleepIconD,
    Sprite_SleepIconE,
    Sprite_SleepIconF,
    Sprite_SleepIconG,
};

u16 CONST_DATA Sprite_BerserkIconA[] =
{
    1, OAM0_SHAPE_16x8, OAM1_SIZE_16x8, OAM2_CHR(0x42) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_BerserkIconB[] =
{
    1, OAM0_SHAPE_16x8 + OAM0_Y(+1), OAM1_SIZE_16x8 + OAM1_X(+1), OAM2_CHR(0x62) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_BerserkIconC[] =
{
    1, OAM0_SHAPE_16x8 + OAM0_Y(+1), OAM1_SIZE_16x8, OAM2_CHR(0x44) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_BerserkIconD[] =
{
    1, OAM0_SHAPE_16x8, OAM1_SIZE_16x8 + OAM1_X(+1), OAM2_CHR(0x42) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_BerserkIconE[] =
{
    1, OAM0_SHAPE_16x8, OAM1_SIZE_16x8 + OAM1_X(+2), OAM2_CHR(0x62) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_BerserkIconF[] =
{
    1, OAM0_SHAPE_16x8 + OAM0_Y(+1), OAM1_SIZE_16x8, OAM2_CHR(0x44) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_BerserkIconG[] =
{
    1, OAM0_SHAPE_16x8, OAM1_SIZE_16x8 + OAM1_X(-1), OAM2_CHR(0x42) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_BerserkIconH[] =
{
    1, OAM0_SHAPE_16x8 + OAM0_Y(+1), OAM1_SIZE_16x8 + OAM1_X(+1), OAM2_CHR(0x62) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_BerserkIconI[] =
{
    1, OAM0_SHAPE_16x8 + OAM0_Y(+1), OAM1_SIZE_16x8 + OAM1_X(+2), OAM2_CHR(0x44) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 const * CONST_DATA BerserkIconSprites[] =
{
    Sprite_BerserkIconA,
    Sprite_BerserkIconB,
    Sprite_BerserkIconC,
    Sprite_BerserkIconD,
    Sprite_BerserkIconE,
    Sprite_BerserkIconF,
    Sprite_BerserkIconG,
    Sprite_BerserkIconH,
    Sprite_BerserkIconI,
};

u16 CONST_DATA Sprite_None[] = { 0 };

u16 CONST_DATA Sprite_SilenceIconA[] =
{
    1, OAM0_SHAPE_16x8, OAM1_SIZE_16x8, OAM2_CHR(0x66) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_SilenceIconB[] =
{
    1, OAM0_SHAPE_16x8 + OAM0_Y(-1), OAM1_SIZE_16x8, OAM2_CHR(0x46) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_SilenceIconC[] =
{
    1, OAM0_SHAPE_16x16 + OAM0_Y(-2), OAM1_SIZE_16x16, OAM2_CHR(0x48) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 const * CONST_DATA SilenceIconSprites[] =
{
    Sprite_SilenceIconA,
    Sprite_SilenceIconB,
    Sprite_SilenceIconC,
    Sprite_SilenceIconC,
    Sprite_SilenceIconC,
    Sprite_SilenceIconC,
    Sprite_SilenceIconC,
    Sprite_SilenceIconC,
    Sprite_SilenceIconC,
    Sprite_SilenceIconC,
    Sprite_SilenceIconC,
    Sprite_SilenceIconB,
    Sprite_SilenceIconA,
    Sprite_None,
    Sprite_None,
    Sprite_None,
    Sprite_None,
    Sprite_None,
};

u16 CONST_DATA Sprite_PoisonIconA[] =
{
    2,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(2), OAM2_CHR(0x40) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
    OAM0_SHAPE_8x16 + OAM0_Y(3), OAM1_SIZE_8x16 + OAM1_X(10), OAM2_CHR(0x41) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_PoisonIconB[] =
{
    2,
    OAM0_SHAPE_8x16 + OAM0_Y(-1), OAM1_SIZE_8x16 + OAM1_X(2) + OAM1_HFLIP, OAM2_CHR(0x40) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
    OAM0_SHAPE_8x16 + OAM0_Y(2), OAM1_SIZE_8x16 + OAM1_X(8) + OAM1_HFLIP, OAM2_CHR(0x41) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_PoisonIconC[] =
{
    2,
    OAM0_SHAPE_8x16 + OAM0_Y(-2), OAM1_SIZE_8x16 + OAM1_X(2), OAM2_CHR(0x40) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
    OAM0_SHAPE_8x16 + OAM0_Y(1), OAM1_SIZE_8x16 + OAM1_X(10), OAM2_CHR(0x41) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_PoisonIconD[] =
{
    2,
    OAM0_SHAPE_8x16 + OAM0_Y(-3), OAM1_SIZE_8x16 + OAM1_X(2) + OAM1_HFLIP, OAM2_CHR(0x40) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(8) + OAM1_HFLIP, OAM2_CHR(0x41) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_PoisonIconE[] =
{
    1, OAM0_SHAPE_8x16 + OAM0_Y(-4), OAM1_SIZE_8x16 + OAM1_X(4), OAM2_CHR(0x40) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_PoisonIconF[] =
{
    1, OAM0_SHAPE_8x16 + OAM0_Y(-5), OAM1_SIZE_8x16 + OAM1_X(4), OAM2_CHR(0x41) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_PoisonIconG[] =
{
    1, OAM0_SHAPE_8x16 + OAM0_Y(-6), OAM1_SIZE_8x16 + OAM1_X(4), OAM2_CHR(0x40) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_PoisonIconH[] =
{
    1, OAM0_SHAPE_8x16 + OAM0_Y(-7), OAM1_SIZE_8x16 + OAM1_X(4) + OAM1_HFLIP, OAM2_CHR(0x41) + OAM2_LAYER(2) + OAM2_PAL(OBPAL_1),
};

u16 const * CONST_DATA PoisonIconSprites[] =
{
    Sprite_PoisonIconA,
    Sprite_PoisonIconB,
    Sprite_PoisonIconC,
    Sprite_PoisonIconD,
    Sprite_PoisonIconE,
    Sprite_PoisonIconF,
    Sprite_PoisonIconG,
    Sprite_PoisonIconH,
    Sprite_PoisonIconH,
    Sprite_None,
    Sprite_None,
    Sprite_None,
};

u16 CONST_DATA Sprite_16x16_Blend[] =
{
    1, OAM0_SHAPE_16x16 + OAM0_BLEND, OAM1_SIZE_16x16, 0,
};

u16 CONST_DATA Sprite_16x32_Blend[] =
{
    1, OAM0_SHAPE_16x32 + OAM0_BLEND, OAM1_SIZE_16x32, 0,
};

u16 CONST_DATA Sprite_32x32_Blend[] =
{
    1, OAM0_SHAPE_32x32 + OAM0_BLEND, OAM1_SIZE_32x32, 0,
};

u16 CONST_DATA Sprite_16x16_Window[] =
{
    1, OAM0_SHAPE_16x16 + OAM0_WINDOW, OAM1_SIZE_16x16, 0,
};

u16 CONST_DATA Sprite_16x32_Window[] =
{
    1, OAM0_SHAPE_16x32 + OAM0_WINDOW, OAM1_SIZE_16x32, 0,
};

u16 CONST_DATA Sprite_32x32_Window[] =
{
    1, OAM0_SHAPE_32x32 + OAM0_WINDOW, OAM1_SIZE_32x32, 0,
};

// clang-format on

void func_fe6_08021B88(void)
{
    gUnitSpriteSyncRequest++;
}

void ApplyUnitSpritePalettes(void)
{
    ApplyPalettes(Pal_UnitSprites, 0x10 + OBPAL_MAPSPRITES, 4);

    if ((gBmSt.flags & BM_FLAG_LINKARENA) != 0)
        ApplyPalette(Pal_UnitSpritesPurple, 0x10 + OBPAL_UNITSPRITE_PURPLE);
}

void ResetUnitSprites(void)
{
    int i;

    for (i = UNITSPRITE_MAX - 1; i >= 0; --i)
        gUnitSpriteSlots[i] = 0xFF;

    gUnitSpriteLargeAllocCount = 0;
    gUnitSpriteSmallAllocCount = 0x40 - 1;
}

void ResetUnitSpritesB(void)
{
    int i;

    for (i = UNITSPRITE_MAX - 1; i >= 0; --i)
        gUnitSpriteSlots[i] = 0xFF;

    gUnitSpriteLargeAllocCount = 0;
    gUnitSpriteSmallAllocCount = 0x60 - 1;
}

int UseUnitSprite(u32 id)
{
    if (gUnitSpriteSlots[id] == 0xFF)
    {
        Decompress(GetUnitSpriteInfo(id).img, UnitSpriteUnpackBuf);

        switch (GetUnitSpriteInfo(id).size)
        {
            case UNITSPRITE_16x16:
                gUnitSpriteSlots[id] = ApplyUnitSpriteImage16x16(gUnitSpriteSmallAllocCount, id) / 2;
                gUnitSpriteSmallAllocCount -= 1;

                break;

            case UNITSPRITE_16x32:
                gUnitSpriteSlots[id] = ApplyUnitSpriteImage16x32(gUnitSpriteLargeAllocCount, id) / 2;
                gUnitSpriteLargeAllocCount += 2;

                break;

            case UNITSPRITE_32x32:
                if ((gUnitSpriteLargeAllocCount & 0x1E) == 0x1E)
                    gUnitSpriteLargeAllocCount += 2; // avoid case where current alloc is at edge of line

                gUnitSpriteSlots[id] = ApplyUnitSpriteImage32x32(gUnitSpriteLargeAllocCount, id) / 2;
                gUnitSpriteLargeAllocCount += 4;

                break;
        }

        gUnitSpriteSyncRequest++;
    }

    return OBCHR_MAPSPRITES + gUnitSpriteSlots[id] * 2;
}

static int ApplyUnitSpriteImage16x16(int slot, u32 id)
{
    int out_off, i;

    out_off = UnitSpriteSlotToChrTable[slot] * CHR_SIZE;
    id = ((id >> UNITSPRITE_ID_BITS) ^ 1) & 1;

    for (i = 0; i < 3; ++i)
    {
        int img_off = (i * id) * 4 * CHR_SIZE;

        CpuFastCopy(
            UnitSpriteUnpackBuf + 0 * CHR_SIZE + img_off, gUnitSpriteBuf[i] + 0 * CHR_SIZE * CHR_LINE + out_off,
            2 * CHR_SIZE);
        CpuFastCopy(
            UnitSpriteUnpackBuf + 2 * CHR_SIZE + img_off, gUnitSpriteBuf[i] + 1 * CHR_SIZE * CHR_LINE + out_off,
            2 * CHR_SIZE);
    }

    return UnitSpriteSlotToChrTable[slot];
}

static int ApplyUnitSpriteImage16x32(int slot, u32 id)
{
    int out_off, i;

    out_off = UnitSpriteSlotToChrTable[slot] * CHR_SIZE;
    id = ((id >> UNITSPRITE_ID_BITS) ^ 1) & 1;

    for (i = 0; i < 3; ++i)
    {
        int img_off = (i * id) * 8 * CHR_SIZE;

        CpuFastCopy(
            UnitSpriteUnpackBuf + 0 * CHR_SIZE + img_off, gUnitSpriteBuf[i] + 0 * CHR_SIZE * CHR_LINE + out_off,
            2 * CHR_SIZE);
        CpuFastCopy(
            UnitSpriteUnpackBuf + 2 * CHR_SIZE + img_off, gUnitSpriteBuf[i] + 1 * CHR_SIZE * CHR_LINE + out_off,
            2 * CHR_SIZE);
        CpuFastCopy(
            UnitSpriteUnpackBuf + 4 * CHR_SIZE + img_off, gUnitSpriteBuf[i] + 2 * CHR_SIZE * CHR_LINE + out_off,
            2 * CHR_SIZE);
        CpuFastCopy(
            UnitSpriteUnpackBuf + 6 * CHR_SIZE + img_off, gUnitSpriteBuf[i] + 3 * CHR_SIZE * CHR_LINE + out_off,
            2 * CHR_SIZE);
    }

    return UnitSpriteSlotToChrTable[slot];
}

static int ApplyUnitSpriteImage32x32(int slot, u32 id)
{
    int out_off, i;

    out_off = UnitSpriteSlotToChrTable[slot] * CHR_SIZE;
    id = ((id >> UNITSPRITE_ID_BITS) ^ 1) & 1;

    for (i = 0; i < 3; ++i)
    {
        int img_off = (i * id) * 16 * CHR_SIZE;

        CpuFastCopy(
            UnitSpriteUnpackBuf + 0 * CHR_SIZE + img_off, gUnitSpriteBuf[i] + 0 * CHR_SIZE * CHR_LINE + out_off,
            4 * CHR_SIZE);
        CpuFastCopy(
            UnitSpriteUnpackBuf + 4 * CHR_SIZE + img_off, gUnitSpriteBuf[i] + 1 * CHR_SIZE * CHR_LINE + out_off,
            4 * CHR_SIZE);
        CpuFastCopy(
            UnitSpriteUnpackBuf + 8 * CHR_SIZE + img_off, gUnitSpriteBuf[i] + 2 * CHR_SIZE * CHR_LINE + out_off,
            4 * CHR_SIZE);
        CpuFastCopy(
            UnitSpriteUnpackBuf + 12 * CHR_SIZE + img_off, gUnitSpriteBuf[i] + 3 * CHR_SIZE * CHR_LINE + out_off,
            4 * CHR_SIZE);
    }

    return UnitSpriteSlotToChrTable[slot];
}

void SyncUnitSpriteSheet(void)
{
    int frame = GetGameTime() % UNITSPRITE_FRAME_END;

    if (frame == UNITSPRITE_FRAME_A)
        CpuFastCopy(gUnitSpriteBuf[0], OBJ_VRAM0 + CHR_SIZE * OBCHR_MAPSPRITES, sizeof(gUnitSpriteBuf[0]));

    if (frame == UNITSPRITE_FRAME_B)
        CpuFastCopy(gUnitSpriteBuf[1], OBJ_VRAM0 + CHR_SIZE * OBCHR_MAPSPRITES, sizeof(gUnitSpriteBuf[1]));

    if (frame == UNITSPRITE_FRAME_C)
        CpuFastCopy(gUnitSpriteBuf[2], OBJ_VRAM0 + CHR_SIZE * OBCHR_MAPSPRITES, sizeof(gUnitSpriteBuf[2]));

    if (frame == UNITSPRITE_FRAME_D)
        CpuFastCopy(gUnitSpriteBuf[1], OBJ_VRAM0 + CHR_SIZE * OBCHR_MAPSPRITES, sizeof(gUnitSpriteBuf[1]));
}

void ForceSyncUnitSpriteSheet(void)
{
    int frame;

    gUnitSpriteSyncRequest = 0;

    frame = GetGameTime() % UNITSPRITE_FRAME_END;

    if (frame >= UNITSPRITE_FRAME_D)
    {
        RegisterDataMove(gUnitSpriteBuf[1], OBJ_VRAM0 + CHR_SIZE * OBCHR_MAPSPRITES, sizeof(gUnitSpriteBuf[1]));
        return;
    }

    if (frame >= UNITSPRITE_FRAME_C)
    {
        RegisterDataMove(gUnitSpriteBuf[2], OBJ_VRAM0 + CHR_SIZE * OBCHR_MAPSPRITES, sizeof(gUnitSpriteBuf[2]));
        return;
    }

    if (frame >= UNITSPRITE_FRAME_B)
    {
        RegisterDataMove(gUnitSpriteBuf[1], OBJ_VRAM0 + CHR_SIZE * OBCHR_MAPSPRITES, sizeof(gUnitSpriteBuf[1]));
        return;
    }

    if (frame >= UNITSPRITE_FRAME_A)
    {
        RegisterDataMove(gUnitSpriteBuf[0], OBJ_VRAM0 + CHR_SIZE * OBCHR_MAPSPRITES, sizeof(gUnitSpriteBuf[0]));
        return;
    }
}

int GetUnitDisplayedSpritePalette(struct Unit * unit)
{
    if ((unit->flags & UNIT_FLAG_TURN_ENDED) != 0)
        return OBPAL_UNITSPRITE_GRAY;

    return GetUnitSpritePalette(unit);
}

int GetUnitSpritePalette(struct Unit * unit)
{
    switch (UNIT_FACTION(unit))
    {
        case FACTION_BLUE:
            return OBPAL_UNITSPRITE_BLUE;

        case FACTION_RED:
            return OBPAL_UNITSPRITE_RED;

        case FACTION_GREEN:
            return OBPAL_UNITSPRITE_GREEN;

        case FACTION_PURPLE:
            return OBPAL_UNITSPRITE_PURPLE;
    }
}

void RefreshUnitSprites(void)
{
    struct UnitSprite * map_sprite;

    struct Trap * trap;
    int i;

    gNextFreeUnitSprite = &gUnitSprites[0];

    gNextFreeUnitSprite->next = NULL;
    gNextFreeUnitSprite->y = 0x400;

    gNextFreeUnitSprite = &gUnitSprites[1];

    for (i = 1; i < FACTION_PURPLE + 6; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        unit->map_sprite = NULL;

        if ((unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_CONCEALED)) != 0)
            continue;

        if (gMapUnit[unit->y][unit->x] == 0)
            continue;

        map_sprite = AddUnitSprite(unit->y * 16);

        map_sprite->y = unit->y * 16;
        map_sprite->x = unit->x * 16;

        map_sprite->oam2 = UseUnitSprite(GetUnitMapSprite(unit)) + OAM2_PAL(GetUnitDisplayedSpritePalette(unit));

        map_sprite->config = GetUnitSpriteInfo(GetUnitMapSprite(unit)).size;

        // map fade units are put on the same hardware layer as the map tiles
        if ((unit->flags & UNIT_FLAG_MAPFADE) != 0)
            map_sprite->config += 3;

        unit->map_sprite = map_sprite;
    }

    for (trap = GetTrap(0); trap->kind != TRAP_NONE; ++trap)
    {
        u16 oam2;

        switch (trap->kind)
        {
            case TRAP_BALLISTA:
                oam2 = UseUnitSprite(UNITSPRITE_BALLISTA) - 0x4000;
                break;

            case TRAP_LONGBALLISTA:
                oam2 = UseUnitSprite(UNITSPRITE_LONGBALLISTA) - 0x4000;
                break;

            case TRAP_KILLERBALLISTA:
                oam2 = UseUnitSprite(UNITSPRITE_KILLERBALLISTA) - 0x4000;
                break;

            default:
                continue;
        }

        map_sprite = AddUnitSprite(trap->y * 16);

        map_sprite->y = trap->y * 16;
        map_sprite->x = trap->x * 16;

        map_sprite->oam2 = oam2;

        map_sprite->config = GetUnitSpriteInfo(UNITSPRITE_BALLISTA).size;
    }

    if (gUnitSpriteSyncRequest != 0)
        ForceSyncUnitSpriteSheet();
}

struct UnitSprite * AddUnitSprite(int y)
{
    struct UnitSprite * it = gUnitSprites;

    while (TRUE)
    {
        if (it->next == NULL || it->next->y < y)
        {
            gNextFreeUnitSprite->next = it->next;
            gNextFreeUnitSprite = (it->next = gNextFreeUnitSprite) + 1;

            return it->next;
        }

        it = it->next;
    }
}

void PutUnitSpritesOam(void)
{
    struct UnitSprite * it = gUnitSprites->next;

    PutUnitSpriteIconsOam();

    for (; it != NULL; it = it->next)
    {
        int x = it->x - gBmSt.camera.x;
        int y = it->y - gBmSt.camera.y;

        if (x < -16 || x > DISPLAY_WIDTH)
            continue;

        if (y < -32 || y > DISPLAY_HEIGHT)
            continue;

        switch (it->config)
        {
            case UNITSPRITE_16x16:
                PutOamHi(OAM1_X(0x200 + x), OAM0_Y(0x100 + y), Sprite_16x16, it->oam2 + OAM2_LAYER(2));
                break;

            case UNITSPRITE_16x32:
                PutOamHi(OAM1_X(0x200 + x), OAM0_Y(0x100 + y - 0x10), Sprite_16x32, it->oam2 + OAM2_LAYER(2));
                break;

            case UNITSPRITE_32x32:
                PutOamHi(OAM1_X(0x200 + x - 8), OAM0_Y(0x100 + y - 0x10), Sprite_32x32, it->oam2 + OAM2_LAYER(2));
                break;

                // map fade units are put on the same hardware layer as the map tiles

            case UNITSPRITE_16x16 + 3:
                PutOamHi(OAM1_X(0x200 + x), OAM0_Y(0x100 + y), Sprite_16x16, it->oam2 + OAM2_LAYER(3));
                break;

            case UNITSPRITE_16x32 + 3:
                PutOamHi(OAM1_X(0x200 + x), OAM0_Y(0x100 + y - 0x10), Sprite_16x32, it->oam2 + OAM2_LAYER(3));
                break;

            case UNITSPRITE_32x32 + 3:
                PutOamHi(OAM1_X(0x200 + x - 8), OAM0_Y(0x100 + y - 0x10), Sprite_32x32, it->oam2 + OAM2_LAYER(3));
                break;
        }
    }
}

void PutUnitSpriteIconsOam(void)
{
    SHOULD_BE_STATIC u16 SHOULD_BE_CONST rescue_pal_table[] = {
        OBPAL_UNITSPRITE_BLUE,
        OBPAL_UNITSPRITE_GREEN,
        OBPAL_UNITSPRITE_RED,
    };

    int i, x, y;

    bool display_rescue_icon = GetGameTime() % 32 < 20 ? TRUE : FALSE;

    int poison_icon_frame = GetGameTime() / 8 % ARRAY_COUNT(PoisonIconSprites);
    int sleep_icon_frame = GetGameTime() / 16 % ARRAY_COUNT(SleepIconSprites);
    int berserk_icon_frame = GetGameTime() / 8 % ARRAY_COUNT(BerserkIconSprites);
    int silence_icon_frame = GetGameTime() / 4 % ARRAY_COUNT(SilenceIconSprites);

    for (i = 1; i < FACTION_PURPLE; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if ((unit->flags & UNIT_FLAG_HIDDEN) != 0)
            continue;

        if (GetUnitSpriteHiddenFlag(unit) != 0)
            continue;

        // Display status icon

        switch (unit->status)
        {
            case UNIT_STATUS_POISON:
                x = unit->x * 16 - gBmSt.camera.x;
                y = unit->y * 16 - gBmSt.camera.y;

                if (x < -16 || x > DISPLAY_WIDTH)
                    break;

                if (y < -16 || y > DISPLAY_HEIGHT)
                    break;

                PutOamHi(OAM1_X(0x200 + x - 2), OAM0_Y(0x100 + y - 4), PoisonIconSprites[poison_icon_frame], 0);

                break;

            case UNIT_STATUS_SILENCED:
                x = unit->x * 16 - gBmSt.camera.x;
                y = unit->y * 16 - gBmSt.camera.y;

                if (x < -16 || x > DISPLAY_WIDTH)
                    break;

                if (y < -16 || y > DISPLAY_HEIGHT)
                    break;

                PutOamHi(OAM1_X(0x200 + x - 2), OAM0_Y(0x100 + y - 4), SilenceIconSprites[silence_icon_frame], 0);

                break;

            case UNIT_STATUS_SLEEP:
                x = unit->x * 16 - gBmSt.camera.x;
                y = unit->y * 16 - gBmSt.camera.y;

                if (x < -16 || x > DISPLAY_WIDTH)
                    break;

                if (y < -16 || y > DISPLAY_HEIGHT)
                    break;

                PutOamHi(OAM1_X(0x200 + x + 2), OAM0_Y(0x100 + y), SleepIconSprites[sleep_icon_frame], 0);

                break;

            case UNIT_STATUS_BERSERK:
                x = unit->x * 16 - gBmSt.camera.x;
                y = unit->y * 16 - gBmSt.camera.y;

                if (x < -16 || x > DISPLAY_WIDTH)
                    break;

                if (y < -16 || y > DISPLAY_HEIGHT)
                    break;

                PutOamHi(OAM1_X(0x200 + x + 1), OAM0_Y(0x100 + y - 5), BerserkIconSprites[berserk_icon_frame], 0);

                break;
        }

        // Display rescue icon

        if ((unit->flags & UNIT_FLAG_RESCUING) != 0 && display_rescue_icon)
        {
            x = unit->x * 16 - gBmSt.camera.x;
            y = unit->y * 16 - gBmSt.camera.y;

            if (x < -16 || x > DISPLAY_WIDTH)
                continue;

            if (y < -16 || y > DISPLAY_HEIGHT)
                continue;

            PutOamHi(
                OAM1_X(0x200 + x + 9), OAM0_Y(0x100 + y + 7), Sprite_8x8,
                OAM2_CHR(3) + OAM2_LAYER(2) + OAM2_PAL(rescue_pal_table[unit->rescue >> 6]));
        }
    }
}

void func_fe6_08022618(void)
{
    gBmSt.cursor_previous.x = -1;
}

void ResetUnitSpritHover(void)
{
    gUnitSpriteHoverClock = 0;
}

void UnitSpriteHoverUpdate(void)
{
    struct Unit * unit = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

    if (unit != NULL)
    {
        if (!(unit->flags & UNIT_FLAG_TURN_ENDED) && UNIT_FACTION(unit) == FACTION_BLUE &&
            unit->status != UNIT_STATUS_BERSERK && unit->status != UNIT_STATUS_SLEEP)
        {
            if ((UNIT_ATTRIBUTES(unit) & UNIT_ATTR_BALLISTA) != 0)
            {
                switch (gMapTerrain[gBmSt.cursor.y][gBmSt.cursor.x])
                {

                    case TERRAIN_BALLISTA:
                    case TERRAIN_LONGBALLISTA:
                    case TERRAIN_KILLERBALLISTA:
                        goto not_hover;
                }
            }

            gUnitSpriteHoverClock++;

            if (gUnitSpriteHoverClock == 5)
            {
                StartMu(unit);
                HideUnitSprite(unit);

                return;
            }
        }
    }

not_hover:
    if (gBmSt.cursor_previous.x != gBmSt.cursor.x || gBmSt.cursor_previous.y != gBmSt.cursor.y)
    {
        gUnitSpriteHoverClock = 0;

        unit = GetUnit(gMapUnit[gBmSt.cursor_previous.y][gBmSt.cursor_previous.x]);

        if (unit)
        {
            EndAllMus();
            ShowUnitSprite(unit);
        }
    }
}

bool IsUnitSpriteHoverEnabledAt(int x, int y)
{
    struct Unit * unit = GetUnit(gMapUnit[y][x]);

    if (!unit)
        return FALSE;

    if ((unit->flags & UNIT_FLAG_TURN_ENDED) != 0)
        return FALSE;

    if (UNIT_FACTION(unit) != FACTION_BLUE)
        return FALSE;

    if (unit->status != UNIT_STATUS_BERSERK && unit->status != UNIT_STATUS_SLEEP)
        return TRUE;

    return FALSE;
}

void PutUnitSprite(int layer, int x, int y, struct Unit * unit)
{
    u32 id = GetUnitMapSprite(unit);
    int chr = UseUnitSprite(id);

    if (x < -16 || x > DISPLAY_WIDTH)
        return;

    if (y < -32 || y > DISPLAY_HEIGHT)
        return;

    switch (GetUnitSpriteInfo(id).size)
    {
        case UNITSPRITE_16x16:
            PutSprite(layer, x, y, Sprite_16x16, OAM2_PAL(GetUnitDisplayedSpritePalette(unit)) + OAM2_LAYER(2) + chr);
            break;

        case UNITSPRITE_16x32:
            PutSprite(
                layer, x, y - 16, Sprite_16x32, OAM2_PAL(GetUnitDisplayedSpritePalette(unit)) + OAM2_LAYER(2) + chr);
            break;

        case UNITSPRITE_32x32:
            PutSprite(
                layer, x - 8, y - 16, Sprite_32x32,
                OAM2_PAL(GetUnitDisplayedSpritePalette(unit)) + OAM2_LAYER(2) + chr);
            break;
    }
}

void PutUnitSpriteExt(int layer, int x, int y, int oam2, struct Unit * unit)
{
    u32 id = GetUnitMapSprite(unit);
    int chr = UseUnitSprite(id);

    if (x < -16 || x > DISPLAY_WIDTH)
        return;

    if (y < -32 || y > DISPLAY_HEIGHT)
        return;

    switch (GetUnitSpriteInfo(id).size)
    {

        case UNITSPRITE_16x16:
            PutSprite(layer, x, y, Sprite_16x16, OAM2_PAL(GetUnitSpritePalette(unit)) + oam2 + chr);
            break;

        case UNITSPRITE_16x32:
            PutSprite(layer, x, y - 16, Sprite_16x32, OAM2_PAL(GetUnitSpritePalette(unit)) + oam2 + chr);
            break;

        case UNITSPRITE_32x32:
            PutSprite(layer, x - 8, y - 16, Sprite_32x32, OAM2_PAL(GetUnitSpritePalette(unit)) + oam2 + chr);
            break;
    }
}

void PutBlendWindowUnitSprite(int layer, int x, int y, int oam2, struct Unit * unit)
{
    u32 id = GetUnitMapSprite(unit);
    int chr = UseUnitSprite(id);

    if (x < -16 || x > DISPLAY_WIDTH)
        return;

    if (y < -32 || y > DISPLAY_HEIGHT)
        return;

    switch (GetUnitSpriteInfo(id).size)
    {

        case UNITSPRITE_16x16:
            PutSprite(layer, x, y, Sprite_16x16_Blend, chr + oam2);
            PutSprite(layer, x, y, Sprite_16x16_Window, chr + oam2);
            break;

        case UNITSPRITE_16x32:
            PutSprite(layer, x, y - 16, Sprite_16x32_Blend, chr + oam2);
            PutSprite(layer, x, y - 16, Sprite_16x32_Window, chr + oam2);
            break;

        case UNITSPRITE_32x32:
            PutSprite(layer, x - 8, y - 16, Sprite_32x32_Blend, chr + oam2);
            PutSprite(layer, x - 8, y - 16, Sprite_32x32_Window, chr + oam2);
            break;
    }
}

void func_fe6_08022A2C(void)
{
    gUnitSprites[0].next = NULL;
}

void HideUnitSprite(struct Unit * unit)
{
    // BUG: this was probably meant to check for unit->map_sprite instead
    if (unit == NULL)
        RefreshUnitSprites();

    if (unit->map_sprite == NULL)
        return;

    unit->map_sprite->config |= 0x80;
}

void ShowUnitSprite(struct Unit * unit)
{
    if (unit->map_sprite == NULL)
        return;

    unit->map_sprite->config &= ~0x80;
}

u8 GetUnitSpriteHiddenFlag(struct Unit * unit)
{
    if (unit->map_sprite == NULL)
        return 0x80;

    return unit->map_sprite->config & 0x80;
}
