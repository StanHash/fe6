#ifndef UNITSPRITE_H
#define UNITSPRITE_H

#include "common.h"

// TODO: CHR_LINE and CHR_SIZE in appropriate headers
#include "constants/videoalloc_global.h"

#define UNITSPRITE_ID_BITS 7

// or that to any map sprite id to have it not animate
#define UNITSPRITE_NOTANIMATED (1 << UNITSPRITE_ID_BITS)

#define UNITSPRITE_MAX 0xD0
#define UNITSPRITE_SIMULATANEOUS_MAX 100

#define UNITSPRITE_SHEET_LINES 8
#define UNITSPRITE_SHEET_SIZE (UNITSPRITE_SHEET_LINES * CHR_LINE * CHR_SIZE)

enum
{
    UNITSPRITE_16x16,
    UNITSPRITE_16x32,
    UNITSPRITE_32x32,
};

struct UnitSprite
{
    /* 00 */ struct UnitSprite * next;
    /* 04 */ i16 x, y;
    /* 08 */ u16 oam2;
    /* 0A */ STRUCT_PAD(0x0A, 0x0B);
    /* 0B */ i8 config;
};

struct UnitSpriteInfo
{
    /* 00 */ u16 unk_00;
    /* 02 */ u16 size;
    /* 04 */ u8 const * img;
};

void func_fe6_08021B88(void);
void ApplyUnitSpritePalettes(void);
void ResetUnitSprites(void);
void ResetUnitSpritesB(void);
int UseUnitSprite(u32 id);
void SyncUnitSpriteSheet(void);
void ForceSyncUnitSpriteSheet(void);
int GetUnitDisplayedSpritePalette(struct Unit * unit);
int GetUnitSpritePalette(struct Unit * unit);
void RefreshUnitSprites(void);
void PutUnitSpritesOam(void);
void PutUnitSpriteIconsOam(void);
void func_fe6_08022618(void);
void ResetUnitSpritHover(void);
void UnitSpriteHoverUpdate(void);
bool IsUnitSpriteHoverEnabledAt(int x, int y);
void PutUnitSprite(int layer, int x, int y, struct Unit * unit);
void PutUnitSpriteExt(int layer, int x, int y, int oam2, struct Unit * unit);
void PutBlendWindowUnitSprite(int layer, int x, int y, int oam2, struct Unit * unit);
void func_fe6_08022A2C(void);
void HideUnitSprite(struct Unit * unit);
void ShowUnitSprite(struct Unit * unit);
u8 GetUnitSpriteHiddenFlag(struct Unit * unit);

struct UnitSprite * AddUnitSprite(int y);

extern struct UnitSpriteInfo CONST_DATA UnitSpriteTable[];

extern u8 EWRAM_DATA gUnitSpriteSlots[UNITSPRITE_MAX];

extern u8 EWRAM_DATA gUnitSpriteBuf[3][UNITSPRITE_SHEET_SIZE];

extern int EWRAM_DATA gUnitSpriteSmallAllocCount;
extern int EWRAM_DATA gUnitSpriteLargeAllocCount;

extern struct UnitSprite EWRAM_DATA gUnitSprites[UNITSPRITE_SIMULATANEOUS_MAX];
extern struct UnitSprite * EWRAM_DATA gNextFreeUnitSprite;

extern int EWRAM_DATA gUnitSpriteSyncRequest;

extern int EWRAM_DATA gUnitSpriteHoverClock;

extern u8 * CONST_DATA UnitSpriteUnpackBuf;

#define GetUnitSpriteInfo(id) (UnitSpriteTable[(id) & ((1 << UNITSPRITE_ID_BITS) - 1)])

#endif // UNITSPRITE_H
