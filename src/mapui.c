#include "common.h"

#include "hardware.h"
#include "armfunc.h"
#include "ramfunc.h"
#include "proc.h"
#include "unit.h"
#include "map.h"
#include "faction.h"

struct UnkProc_080722FC
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x48);
    /* 48 */ i8 unk_48;
    /* 49 */ STRUCT_PAD(0x49, 0x4D);
    /* 4D */ i8 unk_4D;
    /* 4E */ STRUCT_PAD(0x4E, 0x50);
    /* 50 */ i32 unk_50;
};

extern u16 const gUnk_0831906C[];
extern u16 const gUnk_0831908C[];
extern u16 const gUnk_083190AC[];

extern i8 CONST_DATA gUnk_08678164[];
extern i8 CONST_DATA gUnk_08678168[];
extern i8 CONST_DATA gUnk_0867816B[];
extern i8 CONST_DATA gUnk_0867816E[];

void func_fe6_080728A4(struct UnkProc_080722FC * proc, struct Unit * unit);

void func_fe6_08072218(u16 * out, fi16 r1, int r2)
{
    if (r1 > 5)
        r1 = 5;

    *out = r1 + r2;
}

void func_fe6_08072230(u16 * out, fi16 r1, int r2)
{
    int i;

    int r4 = r1 >> 3;
    int r0 = r1 & 7;

    for (i = 0; i < 4; i++)
    {
        if (i < r4)
            *out = r2 + 14;
        else if (i == r4)
            *out = r2 + 6 + r0;
        else
            *out = r2 + 6;

        out++;
    }
}

void func_fe6_0807226C(u16 * out, fi16 r1, int r2)
{
    if (r1 > 4)
        r1 = 5;

    if (r1 < 0)
        r1 = 0;

    *out = 15 + r2 + r1;
}

void func_fe6_08072298(u16 * out, struct Unit * unit, int r2)
{
    fi16 hp_ratio;

    hp_ratio = 42 * GetUnitCurrentHp(unit);
    hp_ratio = Div(hp_ratio, GetUnitMaxHp(unit));

    func_fe6_08072218(out + 0, hp_ratio, r2);
    func_fe6_08072230(out + 1, hp_ratio - 5, r2);
    func_fe6_0807226C(out + 5, hp_ratio - 37, r2);
}

void func_fe6_080722FC(struct UnkProc_080722FC * proc)
{
    int width;

    proc->unk_4D = 1;

    CpuFastFill(0, gBg0Tm, 6 * 0x20 * sizeof(u16));
    CpuFastFill(0, gBg1Tm, 6 * 0x20 * sizeof(u16));

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    width = gUnk_08678164[proc->unk_50];

    if (proc->unk_48 < 0)
    {
        TmCopyRect_t(gUnk_Tm_02003238 + TM_OFFSET(12 - width, 0), gBg0Tm + TM_OFFSET(0, 0), width, 6);
        TmCopyRect_t(gUnk_Tm_02003738 + TM_OFFSET(12 - width, 0), gBg1Tm + TM_OFFSET(0, 0), width, 6);
    }
    else
    {
        TmCopyRect_t(gUnk_Tm_02003238 + TM_OFFSET(0, 0), gBg0Tm + TM_OFFSET(30 - width, 0), width, 6);
        TmCopyRect_t(gUnk_Tm_02003738 + TM_OFFSET(0, 0), gBg1Tm + TM_OFFSET(30 - width, 0), width, 6);
    }

    proc->unk_50++;

    if (proc->unk_50 == 4)
    {
        proc->unk_4D = 0;
        proc->unk_50 = 0;

        Proc_Break(proc);

        func_fe6_080728A4(proc, GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]));
    }
}

void func_fe6_08072408(struct UnkProc_080722FC * proc)
{
    int width;

    proc->unk_4D = 1;

    // clear first 6 tm lines
    CpuFastFill(0, gBg0Tm, 6 * 0x20 * sizeof(u16));
    CpuFastFill(0, gBg1Tm, 6 * 0x20 * sizeof(u16));

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    width = gUnk_08678168[proc->unk_50];

    if (proc->unk_48 < 0)
    {
        TmCopyRect_t(gUnk_Tm_02003238 + TM_OFFSET(12 - width, 0), gBg0Tm, width, 6);
        TmCopyRect_t(gUnk_Tm_02003738 + TM_OFFSET(12 - width, 0), gBg1Tm, width, 6);
    }
    else
    {
        TmCopyRect_t(gUnk_Tm_02003238, gBg0Tm + TM_OFFSET(30 - width, 0), width, 6);
        TmCopyRect_t(gUnk_Tm_02003738, gBg1Tm + TM_OFFSET(30 - width, 0), width, 6);
    }

    proc->unk_50++;

    if (proc->unk_50 == 3)
    {
        proc->unk_50 = 0;

        Proc_Break(proc);
    }
}

void func_fe6_080724E0(struct UnkProc_080722FC * proc)
{
    int width;

    proc->unk_4D = 1;

    TmFillRect_t(gBg0Tm + TM_OFFSET(0, 13), 6, 7, 0);
    TmFillRect_t(gBg1Tm + TM_OFFSET(0, 13), 6, 7, 0);
    TmFillRect_t(gBg0Tm + TM_OFFSET(24, 13), 6, 7, 0);
    TmFillRect_t(gBg1Tm + TM_OFFSET(24, 13), 6, 7, 0);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    width = gUnk_0867816B[proc->unk_50];

    if (proc->unk_48 < 0)
    {
        TmCopyRect_t(gUnk_Tm_02003238 + TM_OFFSET(6 - width, 10), gBg0Tm + TM_OFFSET(0, 13), width, 7);
        TmCopyRect_t(gUnk_Tm_02003738 + TM_OFFSET(6 - width, 10), gBg1Tm + TM_OFFSET(0, 13), width, 7);
    }
    else
    {
        TmCopyRect_t(gUnk_Tm_02003238 + TM_OFFSET(0, 10), gBg0Tm + TM_OFFSET(30 - width, 13), width, 7);
        TmCopyRect_t(gUnk_Tm_02003738 + TM_OFFSET(0, 10), gBg1Tm + TM_OFFSET(30 - width, 13), width, 7);
    }

    proc->unk_50++;

    if (proc->unk_50 == 3)
    {
        proc->unk_50 = 0;
        proc->unk_4D = 0;

        Proc_Break(proc);
    }
}

void func_fe6_080725E0(struct UnkProc_080722FC * proc)
{
    int width;

    proc->unk_4D = 1;

    // clear last 7 tm lines
    CpuFastFill(0, gBg0Tm + TM_OFFSET(0, 13), 7 * 0x20 * sizeof(u16));
    CpuFastFill(0, gBg1Tm + TM_OFFSET(0, 13), 7 * 0x20 * sizeof(u16));

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    width = gUnk_0867816E[proc->unk_50];

    if (proc->unk_48 < 0)
    {
        TmCopyRect_t(gUnk_Tm_02003238 + TM_OFFSET(6 - width, 10), gBg0Tm + TM_OFFSET(0, 13), width, 7);
        TmCopyRect_t(gUnk_Tm_02003738 + TM_OFFSET(6 - width, 10), gBg1Tm + TM_OFFSET(0, 13), width, 7);
    }
    else
    {
        TmCopyRect_t(gUnk_Tm_02003238 + TM_OFFSET(0, 10), gBg0Tm + TM_OFFSET(30 - width, 13), width, 7);
        TmCopyRect_t(gUnk_Tm_02003738 + TM_OFFSET(0, 10), gBg1Tm + TM_OFFSET(30 - width, 13), width, 7);
    }

    proc->unk_50++;

    if (proc->unk_50 == 3)
    {
        proc->unk_50 = 0;
        proc->unk_4D = 0;

        Proc_Break(proc);
    }
}

void func_fe6_080726CC(struct UnkProc_080722FC * proc)
{
    int x;

    if (proc->unk_48 < 0)
        x = 0;
    else
        x = 18;

    TmCopyRect_t(gUnk_Tm_02003238 + TM_OFFSET(0, 0), gBg0Tm + TM_OFFSET(x, 0), 12, 6);
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void func_fe6_08072700(struct UnkProc_080722FC * proc)
{
    int x;

    if (proc->unk_48 < 0)
        x = 0;
    else
        x = 24;

    TmCopyRect_t(gUnk_Tm_02003238 + TM_OFFSET(0, 10), gBg0Tm + TM_OFFSET(x, 13), 6, 7);
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void func_fe6_08072734(int faction, int pal_id)
{
    u16 const * pal = NULL;

    switch (faction)
    {
        case FACTION_BLUE:
            pal = gUnk_0831906C;
            break;

        case FACTION_RED:
            pal = gUnk_0831908C;
            break;

        case FACTION_GREEN:
            pal = gUnk_083190AC;
            break;

        default:
            func_fe6_08018CDC();
            break;

    }

    ApplyPalette(pal, pal_id);
}

int func_fe6_0807277C(void)
{
    int x = gBmSt.cursor.x * 16 - gBmSt.camera.x;

    if (x < 0x70)
        return +1;

    if (x > 0x70)
        return -1;

    return 0;
}
