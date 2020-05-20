
#pragma once

#include "common.h"

#include "text.h"
#include "unit.h"

enum
{
    ITEM_KIND_SWORD,
    ITEM_KIND_LANCE,
    ITEM_KIND_AXE,
    ITEM_KIND_BOW,
    ITEM_KIND_STAFF,
    ITEM_KIND_ANIMA,
    ITEM_KIND_LIGHT,
    ITEM_KIND_ELDER,

    ITEM_KIND_UNK8,
    ITEM_KIND_UNK9,
    ITEM_KIND_DRAGON,

    ITEM_KIND_INVALID = 0xFF,
};

enum
{
    // Item attribute flags

    ITEM_ATTR_WEAPON = (1 << 0),
    ITEM_ATTR_MAGIC = (1 << 1),
    ITEM_ATTR_STAFF = (1 << 2),
    ITEM_ATTR_UNBREAKABLE = (1 << 3),

    ITEM_ATTR_UNREPAIRABLE = (1 << 9),
    ITEM_ATTR_LOCK_DRAGON = (1 << 10),
    ITEM_ATTR_LOCK_1 = (1 << 11),
    ITEM_ATTR_LOCK_2 = (1 << 12),
    ITEM_ATTR_LOCK_3 = (1 << 13),

    ITEM_ATTR_DELPHI_SHIELD = (1 << 14),

    // Helpers
    ITEM_ATTR_REQUIRES_EXP = ITEM_ATTR_WEAPON + ITEM_ATTR_STAFF,
    ITEM_ATTR_LOCK_ANY = ITEM_ATTR_LOCK_1 + ITEM_ATTR_LOCK_2 + ITEM_ATTR_LOCK_3 + ITEM_ATTR_LOCK_DRAGON,
};

enum
{
    // Weapon level ids

    WPN_LEVEL_0 = 0,
    WPN_LEVEL_E = 1,
    WPN_LEVEL_D = 2,
    WPN_LEVEL_C = 3,
    WPN_LEVEL_B = 4,
    WPN_LEVEL_A = 5,
    WPN_LEVEL_S = 6,
};

enum
{
    // Weapon exp needed to have a given weapon level

    WPN_EXP_0 = 0,
    WPN_EXP_E = 1,
    WPN_EXP_D = 51,
    WPN_EXP_C = 101,
    WPN_EXP_B = 151,
    WPN_EXP_A = 201,
    WPN_EXP_S = 251,
};

enum
{
    // Unit ranges are a (sometimes) weirdly hardcoded.
    // A bitset value is used to represent the combined ranges of a unit's usable items
    // That's what those "reaches" bits are for.

    REACH_NONE   = 0,

    REACH_RANGE1 = (1 << 0),
    REACH_RANGE2 = (1 << 1),
    REACH_RANGE3 = (1 << 2),
    REACH_TO10   = (1 << 3),
    REACH_TO15   = (1 << 4),
    REACH_TOMAG  = (1 << 5),
};

struct ItemBonuses
{
    /* 00 */ s8 hp;
    /* 01 */ s8 pow;
    /* 02 */ s8 skl;
    /* 03 */ s8 spd;
    /* 04 */ s8 def;
    /* 05 */ s8 res;
    /* 06 */ s8 lck;
    /* 07 */ s8 mov;
    /* 08 */ s8 con;
};

struct ItemInfo
{
    /* 00 */ u16 msgName;
    /* 02 */ u16 msgDesc;
    /* 04 */ u16 msgDescUse;
    /* 06 */ u8 id;
    /* 07 */ u8 kind;
    /* 08 */ u16 attributes;
    /* 0A */ // pad
    /* 0C */ struct ItemBonuses const* bonuses;
    /* 10 */ u8 const* effectiveness;
    /* 14 */ u8 uses;
    /* 15 */ u8 might;
    /* 16 */ u8 hit;
    /* 17 */ u8 weight;
    /* 18 */ u8 crit;
    /* 19 */ u8 encodedRange;
    /* 1A */ u16 costPerUse;
    /* 1C */ u8 requiredExp;
    /* 1D */ u8 icon;
    /* 1E */ u8 itemEffect;
    /* 1F */ u8 weaponEffect;
};

int GetItemIid(int item);
char const* GetItemName(int item);
int GetItemDescMsg(int item);
int GetItemUseDescMsg(int item);
int GetItemKind(int item);
int GetItemAttributes(int item);
int GetItemUses(int item);
int GetItemMaxUses(int item);
int GetItemMight(int item);
int GetItemHit(int item);
int GetItemWeight(int item);
int GetItemCrit(int item);
int GetItemValue(int item);
int GetItemMinRange(int item);
int GetItemMaxRange(int item);
int GetItemEncodedRange(int item);
int GetItemRequiredExp(int item);
u8 const* GetItemEffectiveness(int item);
struct ItemBonuses const* GetItemBonuses(int item);
int GetItemIcon(int item);
int GetItemWeaponEffect(int item);
int GetItemEffect(int item);
int GetItemCostPerUse(int item);
int GetItemMaxValue(int item);
int GetItemHpBonus(int item);
int GetItemPowBonus(int item);
int GetItemSklBonus(int item);
int GetItemSpdBonus(int item);
int GetItemDefBonus(int item);
int GetItemResBonus(int item);
int GetItemLckBonus(int item);
int CreateItem(int item);
Bool CanUnitUseWeapon(struct Unit* unit, int item);
Bool CanUnitUseStaff(struct Unit* unit, int item);
void sub_8016694(struct Text* text, int item, Bool isUseable, u16* tm);
void sub_8016720(struct Text* text, int item, Bool isUseable, u16* tm);
void sub_80167E4(struct Text* text, int item, u16* tm);
void sub_8016860(struct Text* text, int item, Bool isUseable, u16* tm);
u16 GetItemAfterUse(int item);
u16 GetUnitEquippedWeapon(struct Unit* unit);
int GetUnitEquippedWeaponSlot(struct Unit* unit);
Bool CanItemReachDistance(int item, int distance);
void UnitEquipItemSlot(struct Unit* unit, int itemSlot);
Bool IsItemEffectiveAgainst(u16 item, struct Unit* unit);
char const* GetItemRangeString(int item);
int GetWeaponLevelFromExp(int wexp);
char const* GetWeaponLevelStringFromExp(int wexp);
int GetWeaponLevelSpecialCharFromExp(int wexp);
char const* GetItemKindString(int kind);
Bool IsItemDisplayUseable(struct Unit* unit, int item);
Bool Unused_08016C50(struct Unit* unit, int item);
int GetUnitItemHealAmount(struct Unit* unit, int item);
int FindUnitItemSlot(struct Unit* unit, int iid);
Bool IsItemStealable(int item);
Bool IsItemRepairable(int item);
int GetItemReach(int item);
int GetUnitWeaponReach(struct Unit* unit, int itemSlot);
int GetUnitItemUseReach(struct Unit* unit, int itemSlot);
int GetUnitStaffReach(struct Unit* unit);
int GetTotalConvoyItemsValue(void);
int GetTotalUnitItemsValue(void);
int sub_8017104(void);
