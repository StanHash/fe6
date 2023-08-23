#include "common.h"

#include "armfunc.h"
#include "hardware.h"
#include "icon.h"
#include "text.h"
#include "face.h"
#include "event.h"
#include "msg.h"
#include "item.h"
#include "unit.h"
#include "faction.h"
#include "unitrearrange.h"
#include "ui.h"

#include "constants/pids.h"
#include "constants/chapters.h"
#include "constants/msg.h"

#include "constants/videoalloc_global.h"

// TODO: MOOOOVE
#define BGPAL_PREPMENU_2 2
#define BGCHR_PREPMENU_230 0x230

struct PrepMenuProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ u8 unk_2A;
    /* 2B */ STRUCT_PAD(0x2B, 0x2C);
    /* 2C */ u8 unk_2C;
    /* 2D */ u8 unk_2D; // size of gUnk_0200E6D4?
    /* 2E */ u8 unk_2E;
    /* 2F */ u8 unk_2F;
    /* 30 */ u8 unk_30; // id within gUnk_0200E6D4
    /* 31 */ STRUCT_PAD(0x31, 0x33);
    /* 33 */ u8 unk_33[2];
    /* 35 */ u8 unk_35;
    /* 36 */ u8 unk_36;
    /* 37 */ STRUCT_PAD(0x37, 0x44);
    /* 44 */ u16 unk_44;
    /* 46 */ STRUCT_PAD(0x46, 0x5C);
    /* 5C */ u32 unk_5C;
};

struct UnkProc_08678DE0
{
    /* 00 */ PROC_HEADER_EXT(struct PrepMenuProc);
    /* 29 */ STRUCT_PAD(0x29, 0x30);
    /* 30 */ u16 unk_30;
};

struct UnkProc_08678E00
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x48);
    /* 48 */ struct Unit * unit;
};

struct UnkProc_08678E18
{
    /* 00 */ PROC_HEADER_EXT(struct PrepMenuProc);
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ struct Unit * unit;
    /* 30 */ struct PrepMenuProc * main_proc;
    /* 34 */ u8 unk_34;
    /* 35 */ u8 unk_35;
};

void func_fe6_0807A67C(struct PrepMenuProc * proc);
fu8 func_fe6_0807CD24(fu8 arg_0);
void func_fe6_0807CEF0(fu8 arg_0, fu8 arg_1);
void func_fe6_0807CD5C(struct Text * text, fu8 arg_1, u16 * tm, fu8 arg_3);

extern u8 gUnk_0203D494[5];

extern struct Unit * gUnk_0200E6D4[];
extern struct Text gUnk_0200E7DC;
extern struct Text gUnk_0200E864[];
extern struct Text gUnk_0200E89C;
extern u16 gUnk_0200E8A4[];
extern struct Unit gUnk_0200F0A4[];
extern struct Text gUnk_0200E7E4[];

extern u16 const gUnk_08320FCE[]; // tiles

#if 0
struct ProcScr CONST_DATA gUnk_08678E38[] =
{
    PROC_19,
    PROC_CALL(LockGame),
    PROC_CALL(StartMidFadeToBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(LockBmDisplay),
    PROC_CALL(func_fe6_0807ACFC),
    PROC_SLEEP(0),
    PROC_CALL(func_fe6_0807AD6C),
    PROC_CALL(func_fe6_0807B888),
    PROC_SLEEP(0),
PROC_LABEL(1),
    PROC_REPEAT(func_fe6_0807AD78),
    PROC_GOTO(5),
PROC_LABEL(7),
    PROC_REPEAT(func_fe6_0807B178),
PROC_LABEL(8),
    PROC_REPEAT(func_fe6_0807B200),
PROC_LABEL(3),
    PROC_REPEAT(func_fe6_0807B28C),
PROC_LABEL(4),
    PROC_REPEAT(func_fe6_0807B3D8),
    PROC_GOTO(1),
PROC_LABEL(15),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_0807B69C),
    PROC_GOTO(1),
PROC_LABEL(9),
    PROC_CALL(func_fe6_0807B49C),
    PROC_REPEAT(func_fe6_0807B4C0),
    PROC_GOTO(1),
PROC_LABEL(10),
    PROC_CALL(func_fe6_0807B49C),
    PROC_REPEAT(func_fe6_0807B5A0),
    PROC_GOTO(1),
PROC_LABEL(13),
    PROC_CALL(func_fe6_0807B89C),
    PROC_SLEEP(0),
    PROC_GOTO(3),
PROC_LABEL(12),
    PROC_CALL(func_fe6_0807B888),
    PROC_SLEEP(0),
    PROC_GOTO(1),
PROC_LABEL(14),
    PROC_CALL(func_fe6_0807B0DC),
    PROC_GOTO(6),
PROC_LABEL(5),
    PROC_CALL(func_fe6_0807B0DC),
    PROC_SLEEP(60),
PROC_LABEL(6),
    PROC_CALL(func_fe6_0807B89C),
    PROC_SLEEP(1),
PROC_LABEL(11),
    PROC_CALL(func_fe6_0807B0E4),
    PROC_SLEEP(0),
    PROC_CALL(EndAllMus),
    PROC_CALL(UnlockBmDisplay),
    PROC_CALL(UnlockGame),
    PROC_END,
};
// end at 08679008
#endif

void func_fe6_080791A0(void)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(gUnk_0203D494); i++)
        gUnk_0203D494[i] = 0;
}

void func_fe6_080791B4(fu8 pid)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(gUnk_0203D494); i++)
    {
        if (gUnk_0203D494[i] == 0)
        {
            gUnk_0203D494[i] = pid;
            return;
        }
    }
}

void func_fe6_080791DC(fu8 pid)
{
    int i, j;

    for (i = 0; i < (int)ARRAY_COUNT(gUnk_0203D494); i++)
    {
        if (gUnk_0203D494[i] == pid)
        {
            for (j = i; j < (int)ARRAY_COUNT(gUnk_0203D494) - 1; j++)
                gUnk_0203D494[j] = gUnk_0203D494[j + 1];

            gUnk_0203D494[4] = 0;
            return;
        }
    }
}

void func_fe6_0807921C(void)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if ((unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
        {
            // oof
            unit->flags |= UNIT_FLAG_DEAD;
        }
    })
}

void func_fe6_08079250(struct UnkProc_08678DE0 * proc)
{
    proc->unk_30 = 0;

    SetWinEnable(1, 1, 0);
    SetWin0Layers(0, 0, 0, 1, 0);
    SetWin1Layers(0, 0, 0, 1, 0);
    SetWOutLayers(1, 1, 1, 1, 1);
}

void func_fe6_080792C8(struct UnkProc_08678DE0 * proc)
{
    proc->unk_30 += 8;

    if (proc->unk_30 >= 0x40)
        proc->unk_30 = 0x40;

    SetWin0Box(0x68, 0x20, DISPLAY_WIDTH, 0x20 + proc->unk_30);
    SetWin1Box(0x68, DISPLAY_HEIGHT - proc->unk_30, DISPLAY_WIDTH, DISPLAY_HEIGHT);

    if (proc->unk_30 == 0x40)
    {
        Proc_Break(proc);

        proc->unk_30 = 0;

        if (proc->proc_parent->unk_2A == 0)
            proc->proc_parent->unk_2A = 1;
        else
            proc->proc_parent->unk_2A = 0;

        func_fe6_0807A67C(proc->proc_parent);

        SetWinEnable(1, 0, 0);
        SetWin0Box(0x68, 0x20, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    }
}

void func_fe6_08079388(struct UnkProc_08678DE0 * proc)
{
    proc->unk_30 += 8;

    if (proc->unk_30 >= 0x40)
        proc->unk_30 = 0x40;

    SetWin0Box(0x68, 0x20 + proc->unk_30, DISPLAY_WIDTH, DISPLAY_HEIGHT - proc->unk_30);

    if (proc->unk_30 == 0x40)
    {
        Proc_Break(proc);
        SetWinEnable(0, 0, 0);
    }
}

struct ProcScr CONST_DATA ProcScr_Unk_08678DE0[] =
{
    PROC_CALL(func_fe6_08079250),
    PROC_REPEAT(func_fe6_080792C8),
    PROC_REPEAT(func_fe6_08079388),
    PROC_END,
};

void func_fe6_080793F0(struct PrepMenuProc * parent)
{
    SpawnProc(ProcScr_Unk_08678DE0, parent);
}

bool func_fe6_08079404(struct Unit * unit)
{
    if (UNIT_PID(unit) == PID_ROY)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_24 && UNIT_PID(unit) == PID_FAE)
        return TRUE;

    return FALSE;
}

void func_fe6_08079424(struct PrepMenuProc * proc)
{
    func_fe6_0807CC34(func_fe6_0807C5B8, 0, MSG_6AE, 0, MSG_659, 0);
    func_fe6_0807CC34(func_fe6_0807C7B8, 0, MSG_6AF, 0, MSG_65A, 1);

    if (func_fe6_0808D0F8() != 0xFF && (proc->unk_2C & 1) == 0 && (gPlaySt.flags & PLAY_FLAG_COMPLETE) == 0)
    {
        func_fe6_0807CC34(func_fe6_0807CB08, 0, MSG_6B7, 0, MSG_6A3, 10);
    }

    func_fe6_0807CC34(func_fe6_0807C884, 1, MSG_6B3, proc->unk_2D == 1 ? 1 : 0, MSG_65F, 5);

    if ((proc->unk_2C & 1) == 0)
    {
        if ((gPlaySt.flags & PLAY_FLAG_COMPLETE) == 0)
        {
            func_fe6_0807CC34(func_fe6_0807CB78, 0, MSG_6B1, 0, MSG_65C, 3);
        }

        func_fe6_0807CC34(func_fe6_0807CBB0, 0, MSG_6B2, 0, MSG_65D, 4);
        func_fe6_0807CC34(func_fe6_0807C97C, 1, MSG_6B4, 0, MSG_660, 6);
    }

    func_fe6_0807CC34(func_fe6_0807C9F4, 1, MSG_6B5, 0, MSG_661, 7);
    func_fe6_0807CC34(func_fe6_0807CA48, 1, MSG_6B6, 0, MSG_662, 8);

    if ((proc->unk_2C & 1) == 0)
    {
        if ((gPlaySt.flags & (PLAY_FLAG_COMPLETE | PLAY_FLAG_HARD)) == 0)
        {
            func_fe6_0807CC34(func_fe6_0807CA9C, 1, MSG_6B9, 0, MSG_663, 9);
        }
    }

    if ((proc->unk_2C & 1) != 0)
    {
        func_fe6_0807CC34(func_fe6_0807CBDC, 0, MSG_6B0, 0, MSG_6F1, 12);
    }
    else
    {
        func_fe6_0807CC34(func_fe6_0807CBDC, 0, MSG_6BA, 0, MSG_65E, 12);
    }
}

void func_fe6_08079624(struct Unit * unit, u16 * tm)
{
    int text_offset;

    PutNumberOrBlank(tm + TM_OFFSET(8, 1), TEXT_COLOR_SYSTEM_BLUE, unit->level);
    PutNumberOrBlank(tm + TM_OFFSET(11, 1), TEXT_COLOR_SYSTEM_BLUE, unit->exp);
    PutNumberOrBlank(tm + TM_OFFSET(11, 3), TEXT_COLOR_SYSTEM_BLUE, GetUnitCurrentHp(unit));
    PutNumberOrBlank(tm + TM_OFFSET(8, 3), TEXT_COLOR_SYSTEM_BLUE, GetUnitMaxHp(unit));

    text_offset = (0x38 - GetStringTextLen(DecodeMsg(unit->pinfo->msg_name))) >> 1;

    ClearText(&gUnk_0200E89C);

    PutDrawText(&gUnk_0200E89C, tm + TM_OFFSET(3, 5), TEXT_COLOR_SYSTEM_WHITE,
        text_offset, 0, DecodeMsg(unit->pinfo->msg_name));
}

void func_fe6_080796B0(struct Unit * unit)
{
    u16 const * tiles = gUnk_08320FCE;
    int ix, iy;

    TmFillRect(gUnk_0200E8A4, 29, 29, 0);

    for (iy = 0; iy < 8; iy++)
    {
        for (ix = 0; ix < 13; ix++)
        {
            gUnk_0200E8A4[TM_OFFSET(ix, iy + 10)] = tiles[ix + (7 - iy) * 13] + TILEREF(0, 1);
        }
    }

    ClearText(&gUnk_0200E89C);

    PutSpecialChar(gUnk_0200E8A4 + TM_OFFSET(9, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_SLASH);
    PutSpecialChar(gUnk_0200E8A4 + TM_OFFSET(5, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_A);
    PutSpecialChar(gUnk_0200E8A4 + TM_OFFSET(6, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_B);
    PutSpecialChar(gUnk_0200E8A4 + TM_OFFSET(5, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_LV_A);
    PutSpecialChar(gUnk_0200E8A4 + TM_OFFSET(6, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_LV_B);
    PutSpecialChar(gUnk_0200E8A4 + TM_OFFSET(9, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_EXP_E);

    func_fe6_08079624(unit, gUnk_0200E8A4);

    PutFaceChibi(GetUnitFid(unit), gUnk_0200E8A4 + TM_OFFSET(1, 1),
        BGCHR_PREPMENU_230, BGPAL_PREPMENU_2, FALSE);
}

void func_fe6_0807979C(struct UnkProc_08678E00 * proc)
{
    struct Unit * unit = proc->unit;

    TmFillRect(gBg0Tm + TM_OFFSET(7, 1), 1, 3, 0);
    TmFillRect(gBg0Tm + TM_OFFSET(10, 1), 1, 3, 0);
    func_fe6_08079624(unit, gBg0Tm);

    EnableBgSync(BG0_SYNC_BIT);

    Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_Unk_08678E00[] =
{
    PROC_SLEEP(0),
    PROC_REPEAT(func_fe6_0807979C),
    PROC_END,
};

void func_fe6_080797DC(struct PrepMenuProc * parent)
{
    struct UnkProc_08678E00 * proc;

    proc = SpawnProc(ProcScr_Unk_08678E00, parent);
    proc->unit = gUnk_0200E6D4[parent->unk_30];
}

void func_fe6_08079804(struct PrepMenuProc * proc)
{
    u16 const * tiles = gUnk_08320FCE;
    int ix, iy;

    PutSpecialChar(gBg0Tm + TM_OFFSET(9, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_SLASH);
    PutSpecialChar(gBg0Tm + TM_OFFSET(5, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_A);
    PutSpecialChar(gBg0Tm + TM_OFFSET(6, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_B);
    PutSpecialChar(gBg0Tm + TM_OFFSET(5, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_LV_A);
    PutSpecialChar(gBg0Tm + TM_OFFSET(6, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_LV_B);
    PutSpecialChar(gBg0Tm + TM_OFFSET(9, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_EXP_E);

    for (iy = 0; iy < 8; iy++)
    {
        for (ix = 0; ix < 13; ix++)
        {
            (gBg1Tm + TM_OFFSET(0, iy))[ix] = tiles[13 * (7 - iy) + ix] + TILEREF(0, 1);
        }
    }

    PutFaceChibi(GetUnitFid(gUnk_0200E6D4[proc->unk_30]), gBg0Tm + TM_OFFSET(1, 1),
        BGCHR_PREPMENU_230, BGPAL_PREPMENU_2, FALSE);

    func_fe6_080797DC(proc);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void func_fe6_080798EC(struct PrepMenuProc * proc)
{
    PutFaceChibi(GetUnitFid(gUnk_0200E6D4[proc->unk_30]), gBg0Tm + TM_OFFSET(1, 1),
        BGCHR_PREPMENU_230, BGPAL_PREPMENU_2, FALSE);

    func_fe6_080797DC(proc);
}

void func_fe6_08079928(struct PrepMenuProc * proc, int unit_id_or_pid, bool by_pid)
{
    fu8 i;

    for (i = 0; i < proc->unk_2D; i++)
    {
        if ((by_pid && UNIT_PID(gUnk_0200E6D4[i]) == unit_id_or_pid) || (!by_pid && gUnk_0200E6D4[i]->id == unit_id_or_pid))
        {
            proc->unk_30 = i;

            if (i / 2 == 0)
            {
                proc->unk_36 = 0;
                proc->unk_44 = 0;
            }
            else if (i / 2 == (proc->unk_2D - 1) / 2)
            {
                if (proc->unk_2D < 15)
                {
                    proc->unk_36 = i / 2;
                    proc->unk_44 = 0;
                }
                else
                {
                    proc->unk_36 = 6;
                    proc->unk_44 = ((proc->unk_2D - 0xd) / 2) * 16;
                }
            }
            else if (i / 2 > proc->unk_44 / 16 && i / 2 < proc->unk_44 / 16 + 6)
            {
                proc->unk_36 = i / 2 - proc->unk_44 / 16;
            }
            else if (proc->unk_44 / 16 > i / 2 - 1)
            {
                proc->unk_36 = 1;
                proc->unk_44 = (i / 2 - 1) * 16;
            }
            else if (proc->unk_44 / 16 < i / 2 - 5)
            {
                proc->unk_36 = 5;
                proc->unk_44 = (i / 2 - 5) * 16;
            }

            break;
        }
    }

    SetBgOffset(2, 0, proc->unk_44 - 0x28);
}

void func_fe6_08079A28(void)
{
    UnitRearrangeInit(gUnk_0200F0A4);

    FOR_UNITS(FACTION_BLUE + 1, FACTION_BLUE + 0x40, unit,
    {
        if ((unit->flags & (UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED)) == 0)
            UnitRearrangeAdd(unit);
    })

    FOR_UNITS(FACTION_BLUE + 1, FACTION_BLUE + 0x40, unit,
    {
        if ((unit->flags & (UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED)) != 0)
            UnitRearrangeAdd(unit);
    })

    UnitRearrangeApply();
}

void func_fe6_08079A94(struct PrepMenuProc * proc)
{
    fu8 r7 = func_fe6_0807CD24(proc->unk_35);

    if (proc->unk_35 == 0)
    {
        if (proc->unk_2F == 0)
        {
            func_fe6_0807CEF0(12, 1);
        }
        else
        {
            func_fe6_0807CEF0(12, 0);
        }

        TmFillRect(gBg0Tm, 12, 19, 0);
        TmFillRect(gBg1Tm, 12, 19, 0);

        PutUiWindowFrame(0, 4, 12, 2 + r7 * 2, UI_WINDOW_REGULAR);
        func_fe6_0807CD5C(gUnk_0200E864, 0, gBg0Tm + TM_OFFSET(2, 5), r7);
        PutUiEntryHover(1, 5 + proc->unk_33[proc->unk_35] * 2, 10);
    }
    else
    {
        if (GetUnitItemCount(gUnk_0200E6D4[proc->unk_30]) > 0)
        {
            func_fe6_0807CEF0(6, 0);
        }
        else
        {
            func_fe6_0807CEF0(6, 1);
        }

        TmFillRect(gBg0Tm + TM_OFFSET(0, 8), 12, 11, 0);
        TmFillRect(gBg1Tm + TM_OFFSET(0, 8), 12, 11, 0);

        PutUiWindowFrame(0, 8, 13, 2 + r7 * 2, UI_WINDOW_REGULAR);
        func_fe6_0807CD5C(gUnk_0200E864, proc->unk_35, gBg0Tm + TM_OFFSET(2, 9), r7);
        PutUiEntryHover(1, 9 + proc->unk_33[proc->unk_35] * 2, 10);
    }

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void func_fe6_08079BC8(struct UnkProc_08678E18 * proc)
{
    proc->main_proc = proc->proc_parent;
    proc->unit = gUnk_0200E6D4[proc->main_proc->unk_30];

    TmFillRect(gBg0Tm + TM_OFFSET(0, 8), 12, 11, 0);
    PutUiWindowFrame(0, 8, 13, 12, UI_WINDOW_REGULAR);
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    proc->unk_34 = 0;
    proc->unk_35 = GetUnitItemCount(proc->unit);

    ClearIcons();

    if (proc->unk_35 == 0)
    {
        proc->main_proc->unk_5C = 0;
        Proc_End(proc);
    }
}

void func_fe6_08079C38(struct UnkProc_08678E18 * proc)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        ClearText(&gUnk_0200E864[proc->unk_34]);

        PutIcon(gBg0Tm + TM_OFFSET(1, 9 + proc->unk_34 * 2),
            GetItemIcon(proc->unit->items[proc->unk_34]), TILEREF(0, BGPAL_ICONS));

        Text_SetColor(&gUnk_0200E864[proc->unk_34],
            IsItemDisplayUseable(proc->unit, proc->unit->items[proc->unk_34])
                ? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY);
        Text_SetCursor(&gUnk_0200E864[proc->unk_34], 0);
        Text_DrawString(&gUnk_0200E864[proc->unk_34], GetItemName(proc->unit->items[proc->unk_34]));
        PutText(&gUnk_0200E864[proc->unk_34], gBg0Tm + TM_OFFSET(3, 9 + proc->unk_34 * 2));

        PutNumberOrBlank(gBg0Tm + TM_OFFSET(11, 9 + proc->unk_34 * 2),
            IsItemDisplayUseable(proc->unit, proc->unit->items[proc->unk_34])
                ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY,
            GetItemUses(proc->unit->items[proc->unk_34]));

        proc->unk_34++;

        if (proc->unk_34 >= proc->unk_35)
        {
            proc->main_proc->unk_5C = 0;
            Proc_Break(proc);
            break;
        }
    }
}

struct ProcScr CONST_DATA ProcScr_Unk_08678E18[] =
{
    PROC_SLEEP(0),
    PROC_CALL(func_fe6_08079BC8),
    PROC_REPEAT(func_fe6_08079C38),
    PROC_END,
};

struct UnkProc_08678E18 * func_fe6_08079D70(struct PrepMenuProc * parent)
{
    return SpawnProc(ProcScr_Unk_08678E18, parent);
}

void func_fe6_08079D84(struct PrepMenuProc * proc)
{
    struct Unit * unit = gUnk_0200E6D4[proc->unk_30];
    int i, count;

    TmFillRect(gBg0Tm + TM_OFFSET(0, 8), 12, 11, 0);
    PutUiWindowFrame(0, 8, 13, 12, UI_WINDOW_REGULAR);

    count = GetUnitItemCount(gUnk_0200E6D4[proc->unk_30]);

    ClearIcons();

    for (i = 0; i < count; i++)
    {
        ClearText(&gUnk_0200E864[i]);

        PutIcon(gBg0Tm + TM_OFFSET(1, 9 + i * 2),
            GetItemIcon(unit->items[i]), TILEREF(0, BGPAL_ICONS));

        Text_SetColor(&gUnk_0200E864[i],
            IsItemDisplayUseable(unit, unit->items[i])
                ? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY);
        Text_SetCursor(&gUnk_0200E864[i], 0);
        Text_DrawString(&gUnk_0200E864[i], GetItemName(unit->items[i]));
        PutText(&gUnk_0200E864[i], gBg0Tm + TM_OFFSET(3, 9 + i * 2));

        PutNumberOrBlank(gBg0Tm + TM_OFFSET(11, 9 + i * 2),
            IsItemDisplayUseable(unit, unit->items[i])
                ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY,
            GetItemUses(unit->items[i]));
    }

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void func_fe6_08079EA0(struct PrepMenuProc * proc)
{
    ClearText(&gUnk_0200E7DC);

    Text_SetCursor(&gUnk_0200E7DC, 0);
    Text_SetColor(&gUnk_0200E7DC, TEXT_COLOR_SYSTEM_WHITE);
    Text_DrawString(&gUnk_0200E7DC, JTEXT("残り"));

    Text_SetCursor(&gUnk_0200E7DC, 0x18);
    Text_SetColor(&gUnk_0200E7DC, TEXT_COLOR_SYSTEM_BLUE);
    Text_DrawNumberOrBlank(&gUnk_0200E7DC, proc->unk_2E - proc->unk_2F);

    Text_SetColor(&gUnk_0200E7DC, TEXT_COLOR_SYSTEM_WHITE);

    Text_SetCursor(&gUnk_0200E7DC, 0x20);
    Text_DrawString(&gUnk_0200E7DC, JTEXT("人"));

    Text_SetCursor(&gUnk_0200E7DC, 0x28);
    Text_DrawString(&gUnk_0200E7DC, JTEXT("／"));

    Text_SetCursor(&gUnk_0200E7DC, 0x38);
    Text_SetColor(&gUnk_0200E7DC, TEXT_COLOR_SYSTEM_BLUE);
    Text_DrawNumberOrBlank(&gUnk_0200E7DC, proc->unk_2E);

    PutText(&gUnk_0200E7DC, gBg0Tm + TM_OFFSET(21, 1));

    EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_08079F50(struct PrepMenuProc * proc, fu8 row)
{
    fu8 i;

    fu8 first_ent = row * 2;
    int text_base = first_ent % 0x10;

    TmFillRect(gBg2Tm + TM_OFFSET(0, first_ent % 0x20), 15, 1, 0);

    for (i = 0; i < 2 && first_ent + i < proc->unk_2D; i++)
    {
        ClearText(&gUnk_0200E7E4[text_base + i]);
        Text_SetCursor(&gUnk_0200E7E4[text_base + i], 0);

        if ((proc->unk_2C & 1) == 0 && func_fe6_08079404(gUnk_0200E6D4[first_ent + i]))
        {
            // force deployed color
            Text_SetColor(&gUnk_0200E7E4[text_base + i], TEXT_COLOR_SYSTEM_GREEN);
        }
        else if ((gUnk_0200E6D4[first_ent + i]->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
        {
            // not selected color
            Text_SetColor(&gUnk_0200E7E4[text_base + i], TEXT_COLOR_SYSTEM_GRAY);
        }
        else
        {
            // selected color
            Text_SetColor(&gUnk_0200E7E4[text_base + i], TEXT_COLOR_SYSTEM_WHITE);
        }

        Text_DrawString(&gUnk_0200E7E4[text_base + i], DecodeMsg(gUnk_0200E6D4[first_ent + i]->pinfo->msg_name));

        PutText(&gUnk_0200E7E4[text_base + i], gBg2Tm + TM_OFFSET(i * 8, first_ent % 0x20));
    }

    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_0807A07C(void)
{
    struct Unit * order[0x40];
    int i, j;

    fu8 deploy_max = GetPlayerMaxDeployCount();
    fu8 deploy_count = 0;
    fu8 order_count = 0;

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        order[order_count] = unit;
        order_count++;
    })

    for (i = 0; i < order_count; i++)
    {
        if ((order[i]->flags & UNIT_FLAG_DEAD) == 0 && func_fe6_08079404(order[i]))
        {
            for (j = i - 1; i > 0; i--, j--)
            {
                if (!func_fe6_08079404(order[i - 1]))
                {
                    struct Unit * tmp = order[i];
                    order[i] = order[i - 1];
                    order[i - 1] = tmp;
                }
                else
                {
                    break;
                }
            }
        }
    }

    UnitRearrangeInit(gUnk_0200F0A4);

    for (i = 0; i < order_count; i++)
        UnitRearrangeAdd(order[i]);

    UnitRearrangeApply();

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        if (deploy_max > deploy_count)
        {
            unit->flags &= ~UNIT_FLAG_NOT_DEPLOYED;
            deploy_count++;
        }
        else
        {
            unit->flags |= UNIT_FLAG_NOT_DEPLOYED;
        }
    })
}
