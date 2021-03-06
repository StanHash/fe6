
#include "item.h"
#include "common.h"

#include "hardware.h"
#include "icon.h"
#include "text.h"
#include "msg.h"
#include "bm.h"
#include "unit.h"
#include "faction.h"
#include "gold.h"
#include "item-use.h"
#include "supply.h"

#include "constants/video-global.h"
#include "constants/items.h"
#include "constants/icons.h"

extern struct ItemInfo CONST_DATA ItemInfoTable[];

inline struct ItemInfo const* GetItemInfo(int iid)
{
    return ItemInfoTable + iid;
}

inline int GetItemIid(int item)
{
    return ITEM_IID(item);
}

inline char const* GetItemName(int item)
{
    return DecodeMsg(GetItemInfo(ITEM_IID(item))->msgName);
}

inline int GetItemDescMsg(int item)
{
    return GetItemInfo(ITEM_IID(item))->msgDesc;
}

inline int GetItemUseDescMsg(int item)
{
    return GetItemInfo(ITEM_IID(item))->msgDescUse;
}

inline int GetItemKind(int item)
{
    if (!item)
        return ITEM_KIND_INVALID;

    return GetItemInfo(ITEM_IID(item))->kind;
}

inline int GetItemAttributes(int item)
{
    return GetItemInfo(ITEM_IID(item))->attributes;
}

inline int GetItemUses(int item)
{
    if (GetItemAttributes(item) & ITEM_ATTR_UNBREAKABLE)
        return 0xFF;

    return ITEM_USES(item);
}

inline int GetItemMaxUses(int item)
{
    if (GetItemAttributes(item) & ITEM_ATTR_UNBREAKABLE)
        return 0xFF;

    return GetItemInfo(ITEM_IID(item))->uses;
}

inline int GetItemMight(int item)
{
    return GetItemInfo(ITEM_IID(item))->might;
}

inline int GetItemHit(int item)
{
    return GetItemInfo(ITEM_IID(item))->hit;
}

inline int GetItemWeight(int item)
{
    return GetItemInfo(ITEM_IID(item))->weight;
}

inline int GetItemCrit(int item)
{
    return GetItemInfo(ITEM_IID(item))->crit;
}

inline int GetItemValue(int item)
{
    return GetItemInfo(ITEM_IID(item))->costPerUse * GetItemUses(item);
}

inline int GetItemMinRange(int item)
{
    return GetItemInfo(ITEM_IID(item))->encodedRange >> 4;
}

inline int GetItemMaxRange(int item)
{
    return GetItemInfo(ITEM_IID(item))->encodedRange & 0xF;
}

inline int GetItemEncodedRange(int item)
{
    return GetItemInfo(ITEM_IID(item))->encodedRange;
}

inline int GetItemRequiredExp(int item)
{
    return GetItemInfo(ITEM_IID(item))->requiredExp;
}

inline u8 const* GetItemEffectiveness(int item)
{
    return GetItemInfo(ITEM_IID(item))->effectiveness;
}

inline struct ItemBonuses const* GetItemBonuses(int item)
{
    return GetItemInfo(ITEM_IID(item))->bonuses;
}

inline int GetItemIcon(int item)
{
    if (!item)
        return ICON_NONE;

    return GetItemInfo(ITEM_IID(item))->icon;
}

inline int GetItemWeaponEffect(int item)
{
    return GetItemInfo(ITEM_IID(item))->weaponEffect;
}

inline int GetItemEffect(int item)
{
    return GetItemInfo(ITEM_IID(item))->itemEffect;
}

inline int GetItemCostPerUse(int item)
{
    return GetItemInfo(ITEM_IID(item))->costPerUse;
}

inline int GetItemMaxValue(int item)
{
    return GetItemInfo(ITEM_IID(item))->costPerUse * GetItemMaxUses(item);
}

int GetItemHpBonus(int item)
{
    struct ItemBonuses const* bonuses;

    if (!item)
        return 0;

    if ((bonuses = GetItemBonuses(item)))
        return bonuses->hp;

    return 0;
}

int GetItemPowBonus(int item)
{
    struct ItemBonuses const* bonuses;

    if (!item)
        return 0;

    if ((bonuses = GetItemBonuses(item)))
        return bonuses->pow;

    return 0;
}

int GetItemSklBonus(int item)
{
    struct ItemBonuses const* bonuses;

    if (!item)
        return 0;

    if ((bonuses = GetItemBonuses(item)))
        return bonuses->skl;

    return 0;
}

int GetItemSpdBonus(int item)
{
    struct ItemBonuses const* bonuses;

    if (!item)
        return 0;

    if ((bonuses = GetItemBonuses(item)))
        return bonuses->spd;

    return 0;
}

int GetItemDefBonus(int item)
{
    struct ItemBonuses const* bonuses;

    if (!item)
        return 0;

    if ((bonuses = GetItemBonuses(item)))
        return bonuses->def;

    return 0;
}

int GetItemResBonus(int item)
{
    struct ItemBonuses const* bonuses;

    if (!item)
        return 0;

    if ((bonuses = GetItemBonuses(item)))
        return bonuses->res;

    return 0;
}

int GetItemLckBonus(int item)
{
    struct ItemBonuses const* bonuses;

    if (!item)
        return 0;

    if ((bonuses = GetItemBonuses(item)))
        return bonuses->lck;

    return 0;
}

int CreateItem(int item)
{
    int uses = GetItemMaxUses(item);

    if (GetItemAttributes(item) & ITEM_ATTR_UNBREAKABLE)
        uses = 0;

    return (uses << ITEM_USES_SHIFT) + GetItemIid(item);
}

bool CanUnitUseWeapon(struct Unit* unit, int item)
{
    int requiredExp, unitExp;

    if (!item)
        return FALSE;

    if (!(GetItemAttributes(item) & ITEM_ATTR_WEAPON))
        return FALSE;

    if (GetItemAttributes(item) & ITEM_ATTR_LOCK_ANY)
    {
        if ((GetItemAttributes(item) & ITEM_ATTR_LOCK_1) && !(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_LOCK_1))
            return FALSE;

        if ((GetItemAttributes(item) & ITEM_ATTR_LOCK_2) && !(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_LOCK_2))
            return FALSE;

        if (GetItemAttributes(item) & ITEM_ATTR_LOCK_DRAGON)
        {
            if (!(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_LOCK_DRAGON))
                return FALSE;

            return TRUE;
        }

        if ((GetItemAttributes(item) & ITEM_ATTR_LOCK_3) && !(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_LOCK_3))
            return FALSE;
    }

    if ((unit->status == UNIT_STATUS_SILENCED) && (GetItemAttributes(item) & ITEM_ATTR_MAGIC))
        return FALSE;

    requiredExp = GetItemRequiredExp(item);
    unitExp = (unit->weaponExp[GetItemKind(item)]);

    return (unitExp >= requiredExp) ? TRUE : FALSE;
}

bool CanUnitUseStaff(struct Unit* unit, int item)
{
    int requiredExp, unitExp;

    if (!item)
        return FALSE;

    if (!(GetItemAttributes(item) & ITEM_ATTR_STAFF))
        return FALSE;

    if (unit->status == UNIT_STATUS_SILENCED)
        return FALSE;

    if (unit->status == UNIT_STATUS_SLEEP)
        return FALSE;

    if (unit->status == UNIT_STATUS_BERSERK)
        return FALSE;

    requiredExp = GetItemRequiredExp(item);
    unitExp = (unit->weaponExp[GetItemKind(item)]);

    return (unitExp >= requiredExp) ? TRUE : FALSE;
}

void sub_8016694(struct Text* text, int item, bool isUseable, u16* tm)
{
    Text_SetParams(text, 0, (isUseable ? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY));
    Text_DrawString(text, GetItemName(item));

    PutText(text, tm + 2);

    PutNumberOrBlank(tm + 11, isUseable ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY, GetItemUses(item));

    PutIcon(tm, GetItemIcon(item), TILEREF(0, BGPAL_ICONS));
}

void sub_8016720(struct Text* text, int item, bool isUseable, u16* tm)
{
    Text_SetParams(text, 0, (isUseable ? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY));
    Text_DrawString(text, GetItemName(item));

    PutText(text, tm + 2);

    PutNumberOrBlank(tm + 10, isUseable ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY, GetItemUses(item));
    PutNumberOrBlank(tm + 13, isUseable ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY, GetItemMaxUses(item));
    PutSpecialChar(tm + 11, isUseable ? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY, TEXT_SPECIAL_SLASH);

    PutIcon(tm, GetItemIcon(item), TILEREF(0, BGPAL_ICONS));
}

void sub_80167E4(struct Text* text, int item, u16* tm)
{
    Text_SetCursor(text, 0);
    Text_DrawString(text, GetItemName(item));

    PutText(text, tm + 2);

    PutNumberOrBlank(tm + 11, Text_GetColor(text), GetItemUses(item));

    PutIcon(tm, GetItemIcon(item), TILEREF(0, BGPAL_ICONS));
}

void sub_8016860(struct Text* text, int item, bool isUseable, u16* tm)
{
    int color;

    ClearText(text);

    color = isUseable ? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY;

    Text_SetColor(text, color);
    Text_DrawString(text, GetItemName(item));

    PutSpecialChar(tm + 12, color, TEXT_SPECIAL_SLASH);

    color = isUseable ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY;

    PutNumberOrBlank(tm + 11, color, GetItemUses(item));
    PutNumberOrBlank(tm + 14, color, GetItemMaxUses(item));

    PutText(text, tm + 2);

    PutIcon(tm, GetItemIcon(item), TILEREF(0, BGPAL_ICONS));
}

u16 GetItemAfterUse(int item)
{
    if (GetItemAttributes(item) & ITEM_ATTR_UNBREAKABLE)
        return item; // unbreakable items don't get used

    item -= (1 << ITEM_USES_SHIFT); // lose one use

    if (item < (1 << ITEM_USES_SHIFT))
        return 0; // return no item if uses < 0

    return item; // return used item
}

u16 GetUnitEquippedWeapon(struct Unit* unit)
{
    int i;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        if (CanUnitUseWeapon(unit, unit->items[i]) == TRUE)
            return unit->items[i];
    }

    return 0;
}

int GetUnitEquippedWeaponSlot(struct Unit* unit)
{
    int i;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        if (CanUnitUseWeapon(unit, unit->items[i]) == TRUE)
            return i;
    }

    return -1;
}

bool CanItemReachDistance(int item, int distance)
{
    int min = GetItemMinRange(item);
    int max = GetItemMaxRange(item);

    if ((min <= distance) && (distance <= max))
        return TRUE;

    return FALSE;
}

void UnitEquipItemSlot(struct Unit* unit, int itemSlot)
{
    int item, i;

    item = unit->items[itemSlot];

    for (i = itemSlot; i != 0; --i)
        unit->items[i] = unit->items[i - 1];

    unit->items[0] = item;
}

bool IsItemEffectiveAgainst(u16 item, struct Unit* unit)
{
    int jid = unit->job->id;
    u8 const* list = GetItemEffectiveness(item);

    if (!list)
        return FALSE;

    while (*list != 0)
    {
        if (*list == jid)
            goto check_delphi_shield;

        list++;
    }

    return FALSE;

    check_delphi_shield:
    {
        int i, attributes;

        if (GetItemEffectiveness(item) != JList_BowEffectiveness)
            return TRUE;

        attributes = 0;

        for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
            attributes = attributes | GetItemAttributes(unit->items[i]);

        if (attributes & ITEM_ATTR_DELPHI_SHIELD)
            return FALSE;

        return TRUE;
    }
}

#include "data/strings/item-ranges.h"

char const* GetItemRangeString(int item)
{
    char const* strings[] =
    {
        String_ItemRange_1ToMag,
        String_ItemRange_1,
        String_ItemRange_1To2,
        String_ItemRange_1To3,
        String_ItemRange_2,
        String_ItemRange_2To3,
        String_ItemRange_3To10,
        String_ItemRange_3To15,
        String_ItemRange_All,
        String_ItemRange_None,
    };

    switch (GetItemEncodedRange(item))
    {

    case 0x10: // 1-mag
        return strings[0];

    case 0x11: // 1-1
        return strings[1];

    case 0x12: // 1-2
        return strings[2];

    case 0x13: // 1-3
        return strings[3];

    case 0x22: // 2-2
        return strings[4];

    case 0x23: // 2-3
        return strings[5];

    case 0x3A: // 3-10
        return strings[6];

    case 0x3F: // 3-15
        return strings[7];

    case 0xFF: // all
        return strings[8];

    default: // bad
        return strings[9];

    }
}

int GetWeaponLevelFromExp(int wexp)
{
    if (wexp < WPN_EXP_E)
        return WPN_LEVEL_0;

    if (wexp < WPN_EXP_D)
        return WPN_LEVEL_E;

    if (wexp < WPN_EXP_C)
        return WPN_LEVEL_D;

    if (wexp < WPN_EXP_B)
        return WPN_LEVEL_C;

    if (wexp < WPN_EXP_A)
        return WPN_LEVEL_B;

    if (wexp < WPN_EXP_S)
        return WPN_LEVEL_A;

    return WPN_LEVEL_S;
}

#include "data/strings/item-levels.h"

char const* GetWeaponLevelStringFromExp(int wexp)
{
    char const* strings[] =
    {
        [WPN_LEVEL_0] = String_ItemLevel_None,
        [WPN_LEVEL_E] = String_ItemLevel_E,
        [WPN_LEVEL_D] = String_ItemLevel_D,
        [WPN_LEVEL_C] = String_ItemLevel_C,
        [WPN_LEVEL_B] = String_ItemLevel_B,
        [WPN_LEVEL_A] = String_ItemLevel_A,
        [WPN_LEVEL_S] = String_ItemLevel_S,
    };

    return strings[GetWeaponLevelFromExp(wexp)];
}

int GetWeaponLevelSpecialCharFromExp(int wexp)
{
    u8 specials[] =
    {
        [WPN_LEVEL_0] = TEXT_SPECIAL_DASH,
        [WPN_LEVEL_E] = TEXT_SPECIAL_E,
        [WPN_LEVEL_D] = TEXT_SPECIAL_D,
        [WPN_LEVEL_C] = TEXT_SPECIAL_C,
        [WPN_LEVEL_B] = TEXT_SPECIAL_B,
        [WPN_LEVEL_A] = TEXT_SPECIAL_A,
        [WPN_LEVEL_S] = TEXT_SPECIAL_S,
    };

    return specials[GetWeaponLevelFromExp(wexp)];
}

#include "data/strings/item-kinds.h"

char const* GetItemKindString(int kind)
{
    char const* strings[] =
    {
        [ITEM_KIND_SWORD]  = String_ItemKind_Sword,
        [ITEM_KIND_LANCE]  = String_ItemKind_Lance,
        [ITEM_KIND_AXE]    = String_ItemKind_Axe,
        [ITEM_KIND_BOW]    = String_ItemKind_Bow,
        [ITEM_KIND_STAFF]  = String_ItemKind_Staff,
        [ITEM_KIND_ANIMA]  = String_ItemKind_Anima,
        [ITEM_KIND_LIGHT]  = String_ItemKind_Light,
        [ITEM_KIND_ELDER]  = String_ItemKind_Elder,
        [ITEM_KIND_UNK8]   = String_ItemKind_Unk8,
        [ITEM_KIND_UNK9]   = String_ItemKind_Unk9,
        [ITEM_KIND_DRAGON] = String_ItemKind_Dragon,
    };

    return strings[kind];
}

bool IsItemDisplayUseable(struct Unit* unit, int item)
{
    if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
        return CanUnitUseWeapon(unit, item);

    if (GetItemAttributes(item) & ITEM_ATTR_STAFF)
        return CanUnitUseStaff(unit, item);

    if (GetItemEffect(item) != 0)
    {
        if (unit->status == UNIT_STATUS_SLEEP)
            return FALSE;

        if (unit->status == UNIT_STATUS_BERSERK)
            return FALSE;

        if (!(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_STEAL) && GetItemIid(item) == IID_LOCKPICK)
            return FALSE;
    }

    return TRUE;
}

bool Unused_08016C50(struct Unit* unit, int item)
{
    if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
        return CanUnitUseWeapon(unit, item);

    return CanUnitUseItem(unit, item);
}

int GetUnitItemHealAmount(struct Unit* unit, int item)
{
    int result = 0;

    switch (GetItemIid(item))
    {

    case IID_HEALSTAFF:
    case IID_PHYSICSTAFF:
    case IID_FORTIFYSTAFF:
    case IID_VULNERARY:
        result = 10;
        break;

    case IID_TINASTAFF:
        result = 15;
        break;

    case IID_MENDSTAFF:
        result = 20;
        break;

    case IID_BINDINGBLADE:
        result = 30;
        break;

    case IID_RECOVERSTAFF:
    case IID_ELIXIR:
        result = 80;
        break;

    }

    if (GetItemAttributes(item) & ITEM_ATTR_STAFF)
    {
        result += GetUnitPower(unit);

        if (result > 80)
            result = 80;
    }

    return result;
}

int FindUnitItemSlot(struct Unit* unit, int iid)
{
    int i;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        if (GetItemIid(unit->items[i]) == iid)
            return i;
    }

    return -1;
}

bool IsItemStealable(int item)
{
    return GetItemKind(item) == ITEM_KIND_UNK9;
}

bool IsItemRepairable(int item)
{
    if (!item)
        return FALSE;

    if (!(GetItemAttributes(item) & (ITEM_ATTR_WEAPON | ITEM_ATTR_STAFF)))
        return FALSE;

    if (GetItemAttributes(item) & (ITEM_ATTR_UNBREAKABLE | ITEM_ATTR_UNREPAIRABLE | ITEM_ATTR_LOCK_DRAGON))
        return FALSE;

    if (GetItemUses(item) == GetItemMaxUses(item))
        return FALSE;

    return TRUE;
}

int GetItemReach(int item)
{
    switch (GetItemEncodedRange(item))
    {

    case 0x11:
        return REACH_RANGE1;

    case 0x12:
        return REACH_RANGE1 | REACH_RANGE2;

    case 0x13:
        return REACH_RANGE1 | REACH_RANGE2 | REACH_RANGE3;

    case 0x22:
        return REACH_RANGE2;

    case 0x23:
        return REACH_RANGE2 | REACH_RANGE3;

    case 0x33:
        return REACH_RANGE3;

    case 0x3A:
        return REACH_RANGE3 | REACH_TO10;

    case 0x3F:
        return REACH_RANGE3 | REACH_TO15;

    default:
        return REACH_NONE;

    }
}

int GetUnitWeaponReach(struct Unit* unit, int itemSlot)
{
    int i, item, result = 0;

    if (itemSlot >= 0)
        return GetItemReach(unit->items[itemSlot]);

    for (i = 0; (i < ITEMSLOT_INV_COUNT) && (item = unit->items[i]); ++i)
    {
        if (CanUnitUseWeapon(unit, item))
            result |= GetItemReach(item);
    }

    return result;
}

int GetUnitItemUseReach(struct Unit* unit, int itemSlot)
{
    int i, tmp, range = 0;

    if (itemSlot >= 0)
    {
        tmp = unit->items[itemSlot];

        if (!CanUnitUseItem(unit, tmp))
            return REACH_NONE;

        range = GetItemMaxRange(tmp);

        if (range == 0)
            range = 99;
    }
    else
    {
        for (i = 0; (i < ITEMSLOT_INV_COUNT) && (tmp = unit->items[i]); ++i)
        {
            if (CanUnitUseItem(unit, tmp))
            {
                tmp = GetItemMaxRange(tmp);

                if (tmp == 0)
                    tmp = 99;

                if (range < tmp)
                    range = tmp;
            }
        }
    }

    switch (range)
    {

    case 1:
        return REACH_RANGE1;

    case 2:
        return REACH_RANGE1 | REACH_RANGE2;

    case 99:
        return REACH_TOMAG;

    default:
        return REACH_NONE;

    }
}

int GetUnitStaffReach(struct Unit* unit)
{
    int i, tmp, range = 0;

    for (i = 0; (i < ITEMSLOT_INV_COUNT) && (tmp = unit->items[i]); ++i)
    {
        if (CanUnitUseStaff(unit, tmp))
        {
            tmp = GetItemMaxRange(tmp);

            if (tmp == 0)
                tmp = 99;

            if (range < tmp)
                range = tmp;
        }
    }

    switch (range)
    {

    case 1:
        return REACH_RANGE1;

    case 2:
        return REACH_RANGE1 | REACH_RANGE2;

    case 99:
        return REACH_TOMAG;

    default:
        return REACH_NONE;

    } 
}

int GetTotalConvoyItemsValue(void)
{
    int i, result = 0;

    u16 const* supply = GetSupplyItems();

    for (i = 0; (i < SUPPLY_ITEM_COUNT) && (*supply); ++i)
    {
        result += GetItemValue(*supply);
        supply++;
    }

    return result;
}

int GetTotalUnitItemsValue(void)
{
    int i, item, result = 0;

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        for (i = 0; (i < ITEMSLOT_INV_COUNT) && (item = unit->items[i]); ++i)
            result += GetItemValue(item);
    })

    return result;
}

int sub_8017104(void)
{
    int halved, heldValue;

    heldValue = GetTotalConvoyItemsValue();
    heldValue = heldValue + GetTotalUnitItemsValue();

    halved = heldValue / 2;

    heldValue = halved + GetGold();

    return heldValue;
}
