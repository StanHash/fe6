
#include "common.h"

#include "bm.h"

enum { MAX_GOLD = 999999 };

int GetGold(void)
{
	return gPlaySt.gold;
}

void SetGold(int amount)
{
	gPlaySt.gold = amount;

	if (gPlaySt.gold > MAX_GOLD)
		gPlaySt.gold = MAX_GOLD;
}

void AddGold(int amount)
{
	gPlaySt.gold += amount;

	if (gPlaySt.gold > MAX_GOLD)
		gPlaySt.gold = MAX_GOLD;
}
