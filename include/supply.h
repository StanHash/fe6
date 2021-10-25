#pragma once

#include "common.h"

enum { SUPPLY_ITEM_COUNT = 100 };

u16* GetSupplyItems(void);
void ClearSupplyItems(void);
void SquashSupplyItems(void);
int CountSupplyItems(void);
int AddSupplyItem(int item);
void RemoveSupplyItem(int slot);
int FindSupplyItem(int item);
