#ifndef UNITLISTSCREEN_H
#define UNITLISTSCREEN_H

#include "common.h"

enum
{
    UNITLIST_PAGE_SOLOANIM = 0,
    UNITLIST_PAGE_1 = 1,
    UNITLIST_PAGE_2 = 2,
    UNITLIST_PAGE_3 = 3,
    UNITLIST_PAGE_4 = 4,
    UNITLIST_PAGE_WEXP = 5,
    UNITLIST_PAGE_SUPPORT = 6,
};

enum
{
    UNITLIST_MODE_FIELD = 0,
    UNITLIST_MODE_PREPMENU = 1,
    // no 2?
    UNITLIST_MODE_SOLOANIM = 3,
    UNITLIST_MODE_4 = 4,
};

enum
{
    UNITLIST_SORTKEY_0,
    UNITLIST_SORTKEY_1,
    UNITLIST_SORTKEY_2,
    UNITLIST_SORTKEY_3,
    UNITLIST_SORTKEY_4,
    UNITLIST_SORTKEY_5,
    UNITLIST_SORTKEY_6,
    UNITLIST_SORTKEY_7,
    UNITLIST_SORTKEY_8,
    UNITLIST_SORTKEY_9,
    UNITLIST_SORTKEY_10,
    UNITLIST_SORTKEY_11,
    UNITLIST_SORTKEY_12,
    UNITLIST_SORTKEY_13,
    UNITLIST_SORTKEY_14,
    UNITLIST_SORTKEY_15,
    UNITLIST_SORTKEY_16,
    UNITLIST_SORTKEY_17,
    UNITLIST_SORTKEY_18,
    UNITLIST_SORTKEY_19,
    UNITLIST_SORTKEY_20,
    UNITLIST_SORTKEY_21,
    UNITLIST_SORTKEY_22,
    UNITLIST_SORTKEY_23,
    UNITLIST_SORTKEY_24,
    UNITLIST_SORTKEY_25,
    UNITLIST_SORTKEY_26,
    UNITLIST_SORTKEY_27,
    UNITLIST_SORTKEY_28,
    UNITLIST_SORTKEY_29,
    UNITLIST_SORTKEY_30,
    UNITLIST_SORTKEY_31,
    UNITLIST_SORTKEY_32,
};

// TODO
struct UnitListScreenProc;

// func_fe6_080741EC
// func_fe6_08074254
// func_fe6_080742D0
// func_fe6_08074384
// func_fe6_080743C8
// func_fe6_080744A0
// func_fe6_08074558
// func_fe6_08074668
// func_fe6_08074778
// func_fe6_08074804
// func_fe6_08074830
// UnitListScreenSprites_Init
// UnitListScreenSprites_Main
// UnitListScreenSprites_Dummy
// func_fe6_08074BA4
// func_fe6_08074D54
// func_fe6_08074EF0
// func_fe6_08075338
// func_fe6_080753A0
// func_fe6_080754F4
// func_fe6_08075570
// func_fe6_08075D34
// func_fe6_08075DF8
// func_fe6_08075E94
// func_fe6_08076060
void StartUnitListScreen(void);
// func_fe6_08076250
// func_fe6_080762B4
// func_fe6_080762E4
void func_fe6_08076314(u16 * tm, fu8 arg_1);
void func_fe6_080763D8(fu8 arg_0, fu8 arg_1, bool arg_2);
// void func_fe6_08076448(ProcPtr proc, fu8 arg_1, u16 * tm, int arg_3, int arg_4);
// func_fe6_08076D30
bool SortUnitList(fu8 arg_0, fu8 arg_1);

extern int gUnk_0200E7D8; // unit id

#endif // UNITLISTSCREEN_H
