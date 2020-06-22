
#include "supply.h"

#include "hardware.h"
#include "bm.h"
#include "item.h"

static u16 EWRAM_DATA sSupplyItems[SUPPLY_ITEM_COUNT] = {};

u16* GetSupplyItems(void)
{
    return sSupplyItems;
}

void ClearSupplyItems(void)
{
    CpuFill16(0, sSupplyItems, sizeof(sSupplyItems));
}

void SquashSupplyItems(void)
{
    u16 i;

    u16* buf = (u16*) gBuf;

    u16* ot = buf;
    u16* it = GetSupplyItems();

    for (i = 0; i < SUPPLY_ITEM_COUNT; ++it, ++i)
    {
        if (*it != 0)
            *ot++ = *it;
    }

    *ot = 0;

    ClearSupplyItems();
    CpuCopy16(buf, GetSupplyItems(), sizeof(u16)*i);
}

int CountSupplyItems(void)
{
    int i, result = 0;

    for (i = 0; i < SUPPLY_ITEM_COUNT; ++i)
    {
        if (sSupplyItems[i] != 0)
            result++;
    }

    return result;
}

int AddSupplyItem(int item)
{
    int i;

    gBmSt.supplyItemOverflow = 0;

    for (i = 0; i < SUPPLY_ITEM_COUNT; ++i)
    {
        if (sSupplyItems[i] == 0)
        {
            sSupplyItems[i] = item;
            return i;
        }
    }

    gBmSt.supplyItemOverflow = item;
    return -1;
}

void RemoveSupplyItem(int slot)
{
    sSupplyItems[slot] = 0;
    SquashSupplyItems();
}

int FindSupplyItem(int item)
{
    int i;

    item = GetItemIid(item);

    for (i = 0; i < SUPPLY_ITEM_COUNT; ++i)
    {
        if (item == ITEM_IID(sSupplyItems[i]))
            return i;
    }

    return -1;
}
