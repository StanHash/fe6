#pragma once

#include "helpbox.h"
#include "battlepreview.h"
#include "statscreen.h"
#include "constants/msg.h"

struct HelpBoxInfo CONST_DATA HelpInfo_08677798 =
{
    .adjacent_down = &HelpInfo_086777B4,
    .adjacent_right = &HelpInfo_08677878,
    .x = 40,
    .y = 80,
    .populate = HelpBoxPopulateStatScreenPInfo,
};

struct HelpBoxInfo CONST_DATA HelpInfo_086777B4 =
{
    .adjacent_up = &HelpInfo_08677798,
    .adjacent_down = &HelpInfo_086777D0,
    .adjacent_right = &HelpInfo_086778B0,
    .x = 6,
    .y = 104,
    .msg = MSG_592,
    .populate = HelpBoxPopulateStatScreenJInfo,
};

struct HelpBoxInfo CONST_DATA HelpInfo_086777D0 =
{
    .adjacent_up = &HelpInfo_086777B4,
    .adjacent_down = &HelpInfo_08677808,
    .adjacent_right = &HelpInfo_086777EC,
    .x = 6,
    .y = 120,
    .msg = MSG_593,
};

struct HelpBoxInfo CONST_DATA HelpInfo_086777EC =
{
    .adjacent_up = &HelpInfo_086777B4,
    .adjacent_down = &HelpInfo_08677808,
    .adjacent_left = &HelpInfo_086777D0,
    .adjacent_right = &HelpInfo_086778B0,
    .x = 38,
    .y = 120,
    .msg = MSG_594,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677808 =
{
    .adjacent_up = &HelpInfo_086777D0,
    .adjacent_right = &HelpInfo_086778B0,
    .x = 6,
    .y = 136,
    .msg = MSG_595,
};

struct HelpBoxInfo CONST_DATA HelpInfo_StatScreenPersonalInfo_Pow =
{
    .adjacent_down = &HelpInfo_08677840,
    .adjacent_left = &HelpInfo_08677798,
    .adjacent_right = &HelpInfo_086778CC,
    .x = 102,
    .y = 24,
    .msg = MSG_59C,
    .populate = HelpBoxPopulateStatScreenPower,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677840 =
{
    .adjacent_up = &HelpInfo_StatScreenPersonalInfo_Pow,
    .adjacent_down = &HelpInfo_0867785C,
    .adjacent_left = &HelpInfo_08677798,
    .adjacent_right = &HelpInfo_086778E8,
    .x = 105,
    .y = 40,
    .msg = MSG_59E,
};

struct HelpBoxInfo CONST_DATA HelpInfo_0867785C =
{
    .adjacent_up = &HelpInfo_08677840,
    .adjacent_down = &HelpInfo_08677878,
    .adjacent_left = &HelpInfo_08677798,
    .adjacent_right = &HelpInfo_08677904,
    .x = 102,
    .y = 56,
    .msg = MSG_59F,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677878 =
{
    .adjacent_up = &HelpInfo_0867785C,
    .adjacent_down = &HelpInfo_08677894,
    .adjacent_left = &HelpInfo_08677798,
    .adjacent_right = &HelpInfo_08677920,
    .x = 102,
    .y = 72,
    .msg = MSG_5A6,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677894 =
{
    .adjacent_up = &HelpInfo_08677878,
    .adjacent_down = &HelpInfo_086778B0,
    .adjacent_left = &HelpInfo_08677798,
    .adjacent_right = &HelpInfo_0867793C,
    .x = 102,
    .y = 88,
    .msg = MSG_5A0,
};

struct HelpBoxInfo CONST_DATA HelpInfo_086778B0 =
{
    .adjacent_up = &HelpInfo_08677894,
    .adjacent_left = &HelpInfo_086777B4,
    .adjacent_right = &HelpInfo_08677958,
    .x = 102,
    .y = 104,
    .msg = MSG_5A1,
};

struct HelpBoxInfo CONST_DATA HelpInfo_086778CC =
{
    .adjacent_down = &HelpInfo_086778E8,
    .adjacent_left = &HelpInfo_StatScreenPersonalInfo_Pow,
    .x = 166,
    .y = 24,
    .msg = MSG_5A4,
};

struct HelpBoxInfo CONST_DATA HelpInfo_086778E8 =
{
    .adjacent_up = &HelpInfo_086778CC,
    .adjacent_down = &HelpInfo_08677904,
    .adjacent_left = &HelpInfo_08677840,
    .x = 166,
    .y = 40,
    .msg = MSG_5A2,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677904 =
{
    .adjacent_up = &HelpInfo_086778E8,
    .adjacent_down = &HelpInfo_08677920,
    .adjacent_left = &HelpInfo_0867785C,
    .x = 166,
    .y = 56,
    .msg = MSG_5A3,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677920 =
{
    .adjacent_up = &HelpInfo_08677904,
    .adjacent_down = &HelpInfo_0867793C,
    .adjacent_left = &HelpInfo_08677878,
    .x = 166,
    .y = 72,
    .msg = MSG_5A5,
};

struct HelpBoxInfo CONST_DATA HelpInfo_0867793C =
{
    .adjacent_up = &HelpInfo_08677920,
    .adjacent_down = &HelpInfo_08677958,
    .adjacent_left = &HelpInfo_08677894,
    .x = 166,
    .y = 88,
    .msg = MSG_5A7,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677958 =
{
    .adjacent_up = &HelpInfo_0867793C,
    .adjacent_left = &HelpInfo_086778B0,
    .x = 166,
    .y = 104,
    .populate = HelpBoxPopulateStatScreenStatus,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677974 =
{
    .adjacent_down = &HelpInfo_08677990,
    .adjacent_right = &HelpInfo_08677A54,
    .x = 40,
    .y = 80,
    .populate = HelpBoxPopulateStatScreenPInfo,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677990 =
{
    .adjacent_up = &HelpInfo_08677974,
    .adjacent_down = &HelpInfo_086779AC,
    .adjacent_right = &HelpInfo_08677A8C,
    .x = 6,
    .y = 104,
    .msg = MSG_592,
    .populate = HelpBoxPopulateStatScreenJInfo,
};

struct HelpBoxInfo CONST_DATA HelpInfo_086779AC =
{
    .adjacent_up = &HelpInfo_08677990,
    .adjacent_down = &HelpInfo_086779E4,
    .adjacent_right = &HelpInfo_086779C8,
    .x = 6,
    .y = 120,
    .msg = MSG_593,
};

struct HelpBoxInfo CONST_DATA HelpInfo_086779C8 =
{
    .adjacent_up = &HelpInfo_08677990,
    .adjacent_down = &HelpInfo_086779E4,
    .adjacent_left = &HelpInfo_086779AC,
    .adjacent_right = &HelpInfo_08677A8C,
    .x = 38,
    .y = 120,
    .msg = MSG_594,
};

struct HelpBoxInfo CONST_DATA HelpInfo_086779E4 =
{
    .adjacent_up = &HelpInfo_086779AC,
    .adjacent_right = &HelpInfo_08677AA8,
    .x = 6,
    .y = 136,
    .msg = MSG_595,
};

struct HelpBoxInfo CONST_DATA HelpInfo_StatScreenItems_ItemA =
{
    .adjacent_down = &HelpInfo_08677A1C,
    .adjacent_left = &HelpInfo_08677974,
    .x = 104,
    .y = 24,
    .msg = 0, // item num
    .redirect = HelpBoxRedirectStatScreenItem,
    .populate = HelpBoxPopulateStatScreenItem,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677A1C =
{
    .adjacent_up = &HelpInfo_StatScreenItems_ItemA,
    .adjacent_down = &HelpInfo_08677A38,
    .adjacent_left = &HelpInfo_08677974,
    .x = 104,
    .y = 40,
    .msg = 1, // item num
    .redirect = HelpBoxRedirectStatScreenItem,
    .populate = HelpBoxPopulateStatScreenItem,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677A38 =
{
    .adjacent_up = &HelpInfo_08677A1C,
    .adjacent_down = &HelpInfo_08677A54,
    .adjacent_left = &HelpInfo_08677974,
    .x = 104,
    .y = 56,
    .msg = 2, // item num
    .redirect = HelpBoxRedirectStatScreenItem,
    .populate = HelpBoxPopulateStatScreenItem,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677A54 =
{
    .adjacent_up = &HelpInfo_08677A38,
    .adjacent_down = &HelpInfo_08677A70,
    .adjacent_left = &HelpInfo_08677974,
    .x = 104,
    .y = 72,
    .msg = 3, // item num
    .redirect = HelpBoxRedirectStatScreenItem,
    .populate = HelpBoxPopulateStatScreenItem,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677A70 =
{
    .adjacent_up = &HelpInfo_08677A54,
    .adjacent_down = &HelpInfo_08677A8C,
    .adjacent_left = &HelpInfo_08677974,
    .adjacent_right = &HelpInfo_08677AC4,
    .x = 104,
    .y = 88,
    .msg = 4, // item num
    .redirect = HelpBoxRedirectStatScreenItem,
    .populate = HelpBoxPopulateStatScreenItem,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677A8C =
{
    .adjacent_up = &HelpInfo_08677A70,
    .adjacent_down = &HelpInfo_08677AA8,
    .adjacent_left = &HelpInfo_086779C8,
    .adjacent_right = &HelpInfo_08677AE0,
    .x = 118,
    .y = 120,
    .msg = MSG_597,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677AA8 =
{
    .adjacent_up = &HelpInfo_08677A8C,
    .adjacent_left = &HelpInfo_086779E4,
    .adjacent_right = &HelpInfo_08677AFC,
    .x = 118,
    .y = 136,
    .msg = MSG_598,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677AC4 =
{
    .adjacent_up = &HelpInfo_08677A70,
    .adjacent_down = &HelpInfo_08677AE0,
    .adjacent_left = &HelpInfo_08677A8C,
    .x = 174,
    .y = 104,
    .msg = MSG_599,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677AE0 =
{
    .adjacent_up = &HelpInfo_08677AC4,
    .adjacent_down = &HelpInfo_08677AFC,
    .adjacent_left = &HelpInfo_08677A8C,
    .x = 174,
    .y = 120,
    .msg = MSG_59A,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677AFC =
{
    .adjacent_up = &HelpInfo_08677AE0,
    .adjacent_left = &HelpInfo_08677AA8,
    .x = 174,
    .y = 136,
    .msg = MSG_59B,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677B18 =
{
    .adjacent_down = &HelpInfo_08677B34,
    .adjacent_right = &HelpInfo_08677C14,
    .x = 40,
    .y = 80,
    .populate = HelpBoxPopulateStatScreenPInfo,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677B34 =
{
    .adjacent_up = &HelpInfo_08677B18,
    .adjacent_down = &HelpInfo_08677B50,
    .adjacent_right = &HelpInfo_08677C14,
    .x = 6,
    .y = 104,
    .msg = MSG_592,
    .populate = HelpBoxPopulateStatScreenJInfo,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677B50 =
{
    .adjacent_up = &HelpInfo_08677B34,
    .adjacent_down = &HelpInfo_08677B88,
    .adjacent_right = &HelpInfo_08677B6C,
    .x = 6,
    .y = 120,
    .msg = MSG_593,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677B6C =
{
    .adjacent_up = &HelpInfo_08677B34,
    .adjacent_down = &HelpInfo_08677B88,
    .adjacent_left = &HelpInfo_08677B50,
    .adjacent_right = &HelpInfo_08677C14,
    .x = 38,
    .y = 120,
    .msg = MSG_594,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677B88 =
{
    .adjacent_up = &HelpInfo_08677B50,
    .adjacent_right = &HelpInfo_08677C14,
    .x = 6,
    .y = 136,
    .msg = MSG_595,
};

struct HelpBoxInfo CONST_DATA HelpInfo_StatScreenWeaponExp_WExpA =
{
    .adjacent_down = &HelpInfo_08677BC0,
    .adjacent_left = &HelpInfo_08677B18,
    .adjacent_right = &HelpInfo_08677BDC,
    .x = 104,
    .y = 24,
    .msg = 0, // slot num
    .populate = HelpBoxPopulateStatScreenWeaponExp,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677BC0 =
{
    .adjacent_up = &HelpInfo_StatScreenWeaponExp_WExpA,
    .adjacent_down = &HelpInfo_08677C14,
    .adjacent_left = &HelpInfo_08677B18,
    .adjacent_right = &HelpInfo_08677BF8,
    .x = 104,
    .y = 40,
    .msg = 1, // slot num
    .populate = HelpBoxPopulateStatScreenWeaponExp,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677BDC =
{
    .adjacent_down = &HelpInfo_08677BF8,
    .adjacent_left = &HelpInfo_StatScreenWeaponExp_WExpA,
    .x = 168,
    .y = 24,
    .msg = 2, // slot num
    .populate = HelpBoxPopulateStatScreenWeaponExp,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677BF8 =
{
    .adjacent_up = &HelpInfo_08677BDC,
    .adjacent_down = &HelpInfo_08677C14,
    .adjacent_left = &HelpInfo_08677BC0,
    .x = 168,
    .y = 40,
    .msg = 3, // slot num
    .populate = HelpBoxPopulateStatScreenWeaponExp,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677C14 =
{
    .adjacent_up = &HelpInfo_08677BC0,
    .adjacent_down = &HelpInfo_08677B18,
    .adjacent_left = &HelpInfo_08677B18,
    .x = 128,
    .y = 64,
    .msg = MSG_635,
    .redirect = HelpBoxRedirectStatScreenSupports,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677C30 =
{
    .adjacent_down = &HelpInfo_BpShort_Hp,
    .x = 8,
    .y = 8,
    .populate = HelpBoxPopulateBattlePreviewAdvantageA,
};

struct HelpBoxInfo CONST_DATA HelpInfo_BpShort_Hp =
{
    .adjacent_up = &HelpInfo_08677C30,
    .adjacent_down = &HelpInfo_08677C68,
    .x = 28,
    .y = 24,
    .msg = MSG_595,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677C68 =
{
    .adjacent_up = &HelpInfo_BpShort_Hp,
    .adjacent_down = &HelpInfo_08677C84,
    .x = 28,
    .y = 40,
    .msg = MSG_6AA,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677C84 =
{
    .adjacent_up = &HelpInfo_08677C68,
    .adjacent_down = &HelpInfo_08677CA0,
    .x = 28,
    .y = 56,
    .msg = MSG_598,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677CA0 =
{
    .adjacent_up = &HelpInfo_08677C84,
    .adjacent_down = &HelpInfo_08677CBC,
    .x = 28,
    .y = 72,
    .msg = MSG_59A,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677CBC =
{
    .adjacent_up = &HelpInfo_08677CA0,
    .x = 56,
    .y = 88,
    .populate = HelpBoxPopulateBattlePreviewAdvantageB,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677CD8 =
{
    .adjacent_down = &HelpInfo_BpLarge_Hp,
    .x = 8,
    .y = 8,
    .populate = HelpBoxPopulateBattlePreviewAdvantageA,
};

struct HelpBoxInfo CONST_DATA HelpInfo_BpLarge_Hp =
{
    .adjacent_up = &HelpInfo_08677CD8,
    .adjacent_down = &HelpInfo_08677D10,
    .x = 28,
    .y = 24,
    .msg = MSG_595,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677D10 =
{
    .adjacent_up = &HelpInfo_BpLarge_Hp,
    .adjacent_down = &HelpInfo_08677D2C,
    .x = 28,
    .y = 40,
    .msg = MSG_597,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677D2C =
{
    .adjacent_up = &HelpInfo_08677D10,
    .adjacent_down = &HelpInfo_08677D48,
    .x = 28,
    .y = 56,
    .msg = MSG_6AC,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677D48 =
{
    .adjacent_up = &HelpInfo_08677D2C,
    .adjacent_down = &HelpInfo_08677D64,
    .x = 28,
    .y = 72,
    .msg = MSG_598,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677D64 =
{
    .adjacent_up = &HelpInfo_08677D48,
    .adjacent_down = &HelpInfo_08677D80,
    .x = 28,
    .y = 88,
    .msg = MSG_59A,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677D80 =
{
    .adjacent_up = &HelpInfo_08677D64,
    .adjacent_down = &HelpInfo_08677D9C,
    .x = 28,
    .y = 104,
    .msg = MSG_6AB,
};

struct HelpBoxInfo CONST_DATA HelpInfo_08677D9C =
{
    .adjacent_up = &HelpInfo_08677D80,
    .x = 56,
    .y = 120,
    .populate = HelpBoxPopulateBattlePreviewAdvantageB,
};
