#pragma once

#include "common.h"

#include "proc.h"

enum
{
    HELPBOX_INFO_NONE,
    HELPBOX_INFO_WEAPON,
    HELPBOX_INFO_STAFF,
};

struct HelpBoxProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct HelpBoxInfo const * info;

    /* 30 */ i16 x_box;
    /* 32 */ i16 y_box;
    /* 34 */ i16 w_box;
    /* 36 */ i16 h_box;
    /* 38 */ i16 x_box_init;
    /* 3A */ i16 y_box_init;
    /* 3C */ i16 x_box_fini;
    /* 3E */ i16 y_box_fini;
    /* 40 */ i16 w_box_init;
    /* 42 */ i16 h_box_init;
    /* 44 */ i16 w_box_fini;
    /* 46 */ i16 h_box_fini;
    /* 48 */ i16 timer;
    /* 4A */ i16 timer_end;

    /* 4C */ u16 msg;
    /* 4E */ u16 item;

    /* 50 */ u16 move_key_bit; // move ctrl proc only

    /* 52 */ u8 unk_52;

    // NOTE: there's likely more, need to decompile more files
};

struct HelpBoxPrintProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ char const * str_it;
    /* 30 */ struct Font * font;
    /* 34 */ struct Text * text[6];
    /* 4C */ STRUCT_PAD(0x4C, 0x5C);
    /* 5C */ i16 line;
    /* 5E */ i16 clock;
    /* 60 */ i16 clock_interval;
    /* 62 */ i16 chars_per_print;
};

struct HelpBoxInfo
{
    /* 00 */ struct HelpBoxInfo const * adjacent_up;
    /* 04 */ struct HelpBoxInfo const * adjacent_down;
    /* 08 */ struct HelpBoxInfo const * adjacent_left;
    /* 0C */ struct HelpBoxInfo const * adjacent_right;
    /* 10 */ u8 x, y;
    /* 12 */ u16 msg;
    /* 14 */ void (* redirect)(struct HelpBoxProc * proc);
    /* 18 */ void (* populate)(struct HelpBoxProc * proc);
};

void UpdateHelpBoxDisplay(struct HelpBoxProc * proc, int interpolate_method);
void HelpBox_OnOpen(struct HelpBoxProc * proc);
void HelpBox_OnLoop(struct HelpBoxProc * proc);
void HelpBox_OnClose(struct HelpBoxProc * proc);
void HelpBox_WaitClose(struct HelpBoxProc * proc);
void StartHelpBox(int x, int y, int msg);
void StartItemHelpBox(int x, int y, int item);
void StartHelpBoxExt(struct HelpBoxInfo const * info, int unk);
void StartHelpBox_08070804(int x, int y, int msg);
void CloseHelpBox(void);
// KillHelpBox
// HelpBoxMoveControl_OnInitBox
// HelpBoxMoveControl_OnIdle
// HelpBoxMoveControl_OnEnd
void StartMovingHelpBox(struct HelpBoxInfo const * info, ProcPtr parent);
void StartMovingHelpBoxExt(struct HelpBoxInfo const * info, ProcPtr parent, int x, int y);
void ApplyHelpBoxContentSize(struct HelpBoxProc * proc, int w_inner, int h_inner);
void ApplyHelpBoxPosition(struct HelpBoxProc * proc, int x, int y);
void SetHelpBoxInitPosition(struct HelpBoxProc * proc, int x, int y);
void ResetHelpBoxInitSize(struct HelpBoxProc * proc);
int func_fe6_08070B30(int item);
void HelpBoxPopulateAutoItem(struct HelpBoxProc * proc);
int HelpBoxTryRelocateUp(struct HelpBoxProc * proc);
int HelpBoxTryRelocateDown(struct HelpBoxProc * proc);
int HelpBoxTryRelocateLeft(struct HelpBoxProc * proc);
int HelpBoxTryRelocateRight(struct HelpBoxProc * proc);
// func_fe6_08070C4C
// StartLockingHelpBox
struct HelpBoxInfo const * GetLastHelpBoxInfo(void);
void func_fe6_08070CB4(int flags, int pal);
void func_fe6_08070D08(int chr, int chapter);
void func_fe6_08070D48(int chr);
void func_fe6_08070D78(int chr);
void func_fe6_08070DA8(u16 * tm, int pal);
void func_fe6_08070DC8(u16 * tm, int pal);
void func_fe6_08070DE8(u16 * tm, int pal);
int func_fe6_08070E0C(struct PlaySt const * play_st);
void func_fe6_08070E70(void * vram, int pal);
// func_fe6_08070EEC
void PutSpriteTalkBox(int x_box, int y_box, int w_box, int h_box);
// DrawHelpBoxWeaponLabels
// DrawHelpBoxWeaponStats
// DrawHelpBoxStaffLabels
void func_fe6_08071274(struct HelpBoxPrintProc * proc);
void func_fe6_08071308(struct HelpBoxPrintProc * proc);
// func_fe6_08071374
// func_fe6_080713DC
// func_fe6_08071410
void func_fe6_080714F8(int msg, int item);
void func_fe6_08071514(void);
// func_fe6_0807155C
// func_fe6_08071584
// func_fe6_080715B4
// func_fe6_080715DC
// func_fe6_080715FC
// func_fe6_080716C8
// func_fe6_080716F0
// func_fe6_08071714
// func_fe6_08071734
void func_fe6_08071748(struct HelpBoxInfo const * info);
// func_fe6_08071760
void func_fe6_08071778(struct HelpBoxProc * proc, int w_inner, int h_inner);
void func_fe6_080717B8(struct HelpBoxProc * proc, int x, int y);
void func_fe6_08071830(struct HelpBoxProc * proc, int x, int y);
void func_fe6_08071838(struct HelpBoxProc * proc);
int func_fe6_08071848(int item);
// func_fe6_08071888
// func_fe6_080718A8
bool func_fe6_080718E0(void);
// func_fe6_080718FC
// func_fe6_08071978
// func_fe6_080719D8
// func_fe6_080719EC
// func_fe6_08071A20
// func_fe6_08071A24
// func_fe6_08071A34
// func_fe6_08071AF8
// func_fe6_08071B20
// func_fe6_08071B44
void func_fe6_08071B6C(void);
void func_fe6_08071B80(int x, int y, int msg, ProcPtr parent);
// func_fe6_08071BC0
// func_fe6_08071C00
// func_fe6_08071C8C
void func_fe6_08071D04(int x, int y, int msg);
void func_fe6_08071D94(int x, int y, int w, int h);
// func_fe6_08071F50
// func_fe6_08071F64
// func_fe6_080720E0
// func_fe6_08072100
void func_fe6_080721B8(int msg);
void func_fe6_080721D0(void);

extern struct ProcScr CONST_DATA ProcScr_HelpBox[];
extern struct ProcScr CONST_DATA ProcScr_HelpBoxMoveControl[];

extern u8 const * CONST_DATA gUnk_08677F20[]; // array img ref

extern struct ProcScr CONST_DATA ProcScr_Unk_08677FD0[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08677FE0[];
extern struct ProcScr CONST_DATA gUnk_08677FF8[];
extern struct ProcScr CONST_DATA gUnk_08678020[];
extern struct ProcScr CONST_DATA gUnk_08678040[];
extern struct ProcScr CONST_DATA gUnk_08678070[];
extern struct ProcScr CONST_DATA gUnk_08678080[];
extern struct ProcScr CONST_DATA gUnk_086780C8[];
extern struct ProcScr CONST_DATA ProcScr_HelpBoxPrint_086780E8[];
extern struct ProcScr CONST_DATA ProcScr_HelpBoxStartPrint_08678110[];

// TODO: move to helpboxinfo
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677798;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086777B4;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086777D0;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086777EC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677808;
extern struct HelpBoxInfo CONST_DATA HelpInfo_StatScreenPersonalInfo_Pow;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677840;
extern struct HelpBoxInfo CONST_DATA HelpInfo_0867785C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677878;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677894;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086778B0;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086778CC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086778E8;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677904;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677920;
extern struct HelpBoxInfo CONST_DATA HelpInfo_0867793C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677958;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677974;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677990;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086779AC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086779C8;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086779E4;
extern struct HelpBoxInfo CONST_DATA HelpInfo_StatScreenItems_ItemA;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677A1C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677A38;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677A54;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677A70;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677A8C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677AA8;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677AC4;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677AE0;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677AFC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677B18;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677B34;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677B50;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677B6C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677B88;
extern struct HelpBoxInfo CONST_DATA HelpInfo_StatScreenWeaponExp_WExpA;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677BC0;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677BDC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677BF8;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677C14;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677C30;
extern struct HelpBoxInfo CONST_DATA HelpInfo_BpShort_Hp;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677C68;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677C84;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677CA0;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677CBC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677CD8;
extern struct HelpBoxInfo CONST_DATA HelpInfo_BpLarge_Hp;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D10;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D2C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D48;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D64;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D80;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D9C;
