#pragma once

#include "prelude.h"

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
    ITEM_KIND_ITEM,
    ITEM_KIND_DRAGON,
    ITEM_KIND_DRAGONSTONE,

    ITEM_KIND_INVALID = 0xFF,
};

enum
{
    // Item attribute flags

    ITEM_ATTR_WEAPON = (1 << 0),
    ITEM_ATTR_MAGIC = (1 << 1),
    ITEM_ATTR_STAFF = (1 << 2),
    ITEM_ATTR_UNBREAKABLE = (1 << 3),
    ITEM_ATTR_IMPORTANT = (1 << 4),
    ITEM_ATTR_BRAVE = (1 << 5),
    ITEM_ATTR_LIGHTBRAND = (1 << 6),
    ITEM_ATTR_UNCOUNTERABLE = (1 << 7),
    ITEM_ATTR_REVERTS_TRIANGLE = (1 << 8),
    ITEM_ATTR_UNREPAIRABLE = (1 << 9),
    ITEM_ATTR_LOCK_DRAGON = (1 << 10),
    ITEM_ATTR_LOCK_ROY = (1 << 11),
    ITEM_ATTR_LOCK_MYRM = (1 << 12),
    ITEM_ATTR_LOCK_ZEPHIEL = (1 << 13),
    ITEM_ATTR_DELPHI_SHIELD = (1 << 14),

    // Helpers
    ITEM_ATTR_REQUIRES_EXP = ITEM_ATTR_WEAPON + ITEM_ATTR_STAFF,
    ITEM_ATTR_LOCK_ANY = ITEM_ATTR_LOCK_ROY + ITEM_ATTR_LOCK_MYRM + ITEM_ATTR_LOCK_ZEPHIEL + ITEM_ATTR_LOCK_DRAGON,
};

enum
{
    ITEM_EFFECT_01 = 0x01,
    ITEM_EFFECT_02 = 0x02,
    ITEM_EFFECT_03 = 0x03,
    ITEM_EFFECT_04 = 0x04,
    ITEM_EFFECT_05 = 0x05,
    ITEM_EFFECT_06 = 0x06,
    ITEM_EFFECT_07 = 0x07,
    ITEM_EFFECT_08 = 0x08,
    ITEM_EFFECT_09 = 0x09,
    ITEM_EFFECT_0A = 0x0A,
    ITEM_EFFECT_0B = 0x0B,
    ITEM_EFFECT_0C = 0x0C,
    ITEM_EFFECT_0D = 0x0D,
    ITEM_EFFECT_0E = 0x0E,
    ITEM_EFFECT_0F = 0x0F,
    ITEM_EFFECT_10 = 0x10,
    ITEM_EFFECT_11 = 0x11,
    ITEM_EFFECT_12 = 0x12,
    ITEM_EFFECT_13 = 0x13,
    ITEM_EFFECT_14 = 0x14,
    ITEM_EFFECT_15 = 0x15,
    ITEM_EFFECT_16 = 0x16,
    ITEM_EFFECT_17 = 0x17,
    ITEM_EFFECT_18 = 0x18,
    ITEM_EFFECT_19 = 0x19,
    ITEM_EFFECT_1A = 0x1A,
    ITEM_EFFECT_1B = 0x1B,
    ITEM_EFFECT_1C = 0x1C,
    ITEM_EFFECT_1D = 0x1D,
    ITEM_EFFECT_1E = 0x1E,
    ITEM_EFFECT_1F = 0x1F,
    ITEM_EFFECT_20 = 0x20,
    ITEM_EFFECT_21 = 0x21,
    ITEM_EFFECT_22 = 0x22,
    ITEM_EFFECT_23 = 0x23,
    ITEM_EFFECT_24 = 0x24,
    ITEM_EFFECT_25 = 0x25,
    ITEM_EFFECT_26 = 0x26,
    ITEM_EFFECT_27 = 0x27,
    ITEM_EFFECT_28 = 0x28,
    ITEM_EFFECT_29 = 0x29,
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

    WEXP_0 = 0,
    WEXP_E = 1,
    WEXP_D = 51,
    WEXP_C = 101,
    WEXP_B = 151,
    WEXP_A = 201,
    WEXP_S = 251,
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

enum
{
    WEAPON_EFFECT_POISON = 1,
    WEAPON_EFFECT_NOSFERATU = 2,
    WEAPON_EFFECT_ECLIPSE = 3,
    WEAPON_EFFECT_DEVIL = 4,
};

struct ItemBonuses
{
    /* 00 */ i8 hp;
    /* 01 */ i8 pow;
    /* 02 */ i8 skl;
    /* 03 */ i8 spd;
    /* 04 */ i8 def;
    /* 05 */ i8 res;
    /* 06 */ i8 lck;
    /* 07 */ i8 mov;
    /* 08 */ i8 con;
};

struct IInfo
{
    /* 00 */ u16 msg_name;
    /* 02 */ u16 msg_desc;
    /* 04 */ u16 msg_desc_use;
    /* 06 */ u8 id;
    /* 07 */ u8 kind;
    /* 08 */ u16 attributes;
    /* 0A */ // pad
    /* 0C */ struct ItemBonuses const * bonuses;
    /* 10 */ u8 const * effectiveness;
    /* 14 */ u8 uses;
    /* 15 */ u8 might;
    /* 16 */ u8 hit;
    /* 17 */ u8 weight;
    /* 18 */ u8 crit;
    /* 19 */ u8 encoded_range;
    /* 1A */ u16 cost_per_use;
    /* 1C */ u8 required_wexp;
    /* 1D */ u8 icon;
    /* 1E */ u8 item_effect;
    /* 1F */ u8 weapon_effect;
};

int GetItemIid(int item);
char const * GetItemName(int item);
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
u8 const * GetItemEffectiveness(int item);
struct ItemBonuses const * GetItemBonuses(int item);
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
bool CanUnitUseWeapon(struct Unit * unit, int item);
bool CanUnitUseStaff(struct Unit * unit, int item);
void func_fe6_08016694(struct Text * text, int item, bool is_usable, u16 * tm);
void func_fe6_08016720(struct Text * text, int item, bool is_usable, u16 * tm);
void func_fe6_080167E4(struct Text * text, int item, u16 * tm);
void func_fe6_08016860(struct Text * text, int item, bool is_usable, u16 * tm);
u16 GetItemAfterUse(int item);
u16 GetUnitEquippedWeapon(struct Unit * unit);
int GetUnitEquippedWeaponSlot(struct Unit * unit);
bool CanItemReachDistance(int item, int distance);
void UnitEquipItemSlot(struct Unit * unit, int item_slot);
bool IsItemEffectiveAgainst(u16 item, struct Unit * unit);
char const * GetItemRangeString(int item);
int GetWeaponLevelFromExp(int wexp);
char const * GetWeaponLevelStringFromExp(int wexp);
int GetWeaponLevelSpecialCharFromExp(int wexp);
char const * GetItemKindString(int kind);
bool IsItemDisplayUseable(struct Unit * unit, int item);
bool Unused_08016C50(struct Unit * unit, int item);
int GetUnitItemHealAmount(struct Unit * unit, int item);
int FindUnitItemSlot(struct Unit * unit, int iid);
bool IsItemStealable(int item);
bool IsItemRepairable(int item);
int GetItemReach(int item);
int GetUnitWeaponReach(struct Unit * unit, int item_slot);
int GetUnitItemUseReach(struct Unit * unit, int item_slot);
int GetUnitStaffReach(struct Unit * unit);
int GetTotalConvoyItemsValue(void);
int GetTotalUnitItemsValue(void);
int func_fe6_08017104(void);

enum { ITEM_USES_SHIFT = 8 };

#define ITEM_IID(item) ((item) & ((1 << ITEM_USES_SHIFT) - 1))
#define ITEM_USES(item) ((item) >> ITEM_USES_SHIFT)

// dummy macro for when the game confuses the two
#define ITEM_FROM_IID(iid) (iid)

// pretending to be reasonable
#define ITEM_KIND_DARK ITEM_KIND_ELDER
