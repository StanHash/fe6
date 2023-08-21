#include "common.h"

#include "hardware.h"
#include "unit.h"
#include "faction.h"

#include "constants/pids.h"
#include "constants/chapters.h"
#include "constants/msg.h"

struct PrepMenuProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ u8 unk_2A;
    /* 2B */ STRUCT_PAD(0x2B, 0x2C);
    /* 2C */ u8 unk_2C;
    /* 2D */ u8 unk_2D;
};

struct UnkProc_08678DE0
{
    /* 00 */ PROC_HEADER_EXT(struct PrepMenuProc);
    /* 29 */ STRUCT_PAD(0x29, 0x30);
    /* 30 */ u16 unk_30;
};

void func_fe6_0807A67C(struct PrepMenuProc * proc);

extern u8 gUnk_0203D494[5];

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

    SetWin0Box(0x68, 0x20, 0xF0, 0x20 + proc->unk_30);
    SetWin1Box(0x68, 0xA0 - proc->unk_30, 0xF0, 0xA0);

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
        SetWin0Box(0x68, 0x20, 0xF0, 0xA0);
    }
}

void func_fe6_08079388(struct UnkProc_08678DE0 * proc)
{
    proc->unk_30 += 8;

    if (proc->unk_30 >= 0x40)
        proc->unk_30 = 0x40;

    SetWin0Box(0x68, 0x20 + proc->unk_30, 0xF0, 0xA0 - proc->unk_30);

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
