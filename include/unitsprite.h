#pragma once

#include "common.h"

enum
{
    UNITSPRITE_ID_BITS = 7,
    UNITSPRITE_NOTANIMATED = 1 << UNITSPRITE_ID_BITS, // or that to any map sprite id to have it not animate

    UNITSPRITE_MAX = 0xD0,
};

enum
{
    UNITSPRITE_16x16,
    UNITSPRITE_16x32,
    UNITSPRITE_32x32,
};

struct UnitSprite
{
    /* 00 */ struct UnitSprite* next;
    /* 04 */ short x, y;
    /* 08 */ u16 oam2;
    /* 0A */ u8 unk_0A;
    /* 0B */ i8 config;
};

struct UnitSpriteInfo
{
    /* 00 */ u16 unk_00;
    /* 02 */ u16 size;
    /* 04 */ u8 const* img;
};

void sub_8021B88(void);
void ApplyUnitSpritePalettes(void);
void ResetUnitSprites(void);
void ResetUnitSpritesB(void);
int UseUnitSprite(unsigned id);
void SyncUnitSpriteSheet(void);
void ForceSyncUnitSpriteSheet(void);
int GetUnitDisplayedSpritePalette(struct Unit* unit);
int GetUnitSpritePalette(struct Unit* unit);
void RefreshUnitSprites(void);
void PutUnitSpritesOam(void);
void PutUnitSpriteIconsOam(void);
void sub_8022618(void);
void ResetUnitSpritHover(void);
void UnitSpriteHoverUpdate(void);
bool IsUnitSpriteHoverEnabledAt(int x, int y);
void PutUnitSprite(int layer, int x, int y, struct Unit* unit);
void PutUnitSpriteExt(int layer, int x, int y, int oam2, struct Unit* unit);
void PutBlendWindowUnitSprite(int layer, int x, int y, int oam2, struct Unit* unit);
void sub_8022A2C(void);
void HideUnitSprite(struct Unit* unit);
void ShowUnitSprite(struct Unit* unit);
u8 GetUnitSpriteHiddenFlag(struct Unit* unit);
