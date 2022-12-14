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

struct HelpBoxInfo
{
    /* 00 */ struct HelpBoxInfo const * adjUp;
    /* 04 */ struct HelpBoxInfo const * adjDown;
    /* 08 */ struct HelpBoxInfo const * adjLeft;
    /* 0C */ struct HelpBoxInfo const * adjRight;
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
struct HelpBoxInfo const * func_fe6_08070CA8(void);
void func_fe6_08070CB4(int flags, int pal);
void func_fe6_08070D08(int chr, int chapter);
// func_fe6_08070D48
void func_fe6_08070D78(int chr);
void func_fe6_08070DA8(u16 * tm, int pal);
// func_fe6_08070DC8
void func_fe6_08070DE8(u16 * tm, int pal);
int func_fe6_08070E0C(struct PlaySt const * play_st);
void func_fe6_08070E70(void * vram, int pal);
// func_fe6_08070EEC
void func_fe6_08070F64(int x_box, int y_box, int w_box, int h_box);
// func_fe6_08071120
// func_fe6_08071198
// func_fe6_08071218
// func_fe6_08071274
// func_fe6_08071308
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
// func_fe6_08071748
// func_fe6_08071760
// func_fe6_08071778
// func_fe6_080717B8
void func_fe6_08071830(struct HelpBoxProc * proc, int x, int y);
void func_fe6_08071838(struct HelpBoxProc * proc);
// func_fe6_08071848
// func_fe6_08071888
// func_fe6_080718A8
// func_fe6_080718E0
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
// func_fe6_08071B6C
// func_fe6_08071B80
// func_fe6_08071BC0
// func_fe6_08071C00
// func_fe6_08071C8C
// func_fe6_08071D04
// func_fe6_08071D94
// func_fe6_08071F50
// func_fe6_08071F64
// func_fe6_080720E0
// func_fe6_08072100
// func_fe6_080721B8
// func_fe6_080721D0

extern struct ProcScr CONST_DATA ProcScr_HelpBox[];

extern struct HelpBoxInfo const HelpInfo_StatScreenPersonalInfo_Pow;
extern struct HelpBoxInfo const HelpInfo_StatScreenItems_ItemA;
extern struct HelpBoxInfo const HelpInfo_StatScreenWeaponExp_WExpA;
extern struct HelpBoxInfo const HelpInfo_BpShort_Hp;
extern struct HelpBoxInfo const HelpInfo_BpLarge_Hp;
