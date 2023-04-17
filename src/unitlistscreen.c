#include "common.h"

#include "armfunc.h"
#include "oam.h"
#include "icon.h"
#include "sprite.h"
#include "item.h"
#include "unit.h"
#include "unitsprite.h"
#include "unitrearrange.h"
#include "ui.h"
#include "mu.h"
#include "statscreen.h"

#include "constants/icons.h"

struct UnitListScreenProcA
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 unk_29;
    /* 2A */ STRUCT_PAD(0x2A, 0x2C);
    /* 2C */ u8 unk_2C;
    /* 2D */ u8 unk_2D;
    /* 2E */ u8 unk_2E;
    /* 2F */ u8 unk_2F;
    /* 30 */ u8 unk_30;
    /* 31 */ STRUCT_PAD(0x31, 0x32);
    /* 32 */ u8 unk_32;
    /* 33 */ STRUCT_PAD(0x33, 0x34);
    /* 34 */ u8 unk_34;
    /* 35 */ STRUCT_PAD(0x35, 0x39);
    /* 39 */ u8 unk_39;
    /* 3A */ STRUCT_PAD(0x3A, 0x40);
    /* 40 */ u16 unk_40;
    /* 42 */ STRUCT_PAD(0x42, 0x44);
    /* 44 */ ProcPtr unk_44;
    /* 48 */ ProcPtr unk_48;
};

struct UnitListScreenProcB
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct UnitListScreenProcA * unk_2C;
    /* 30 */ u8 unk_30;
    /* 34 */ ProcPtr unk_34;
    /* 38 */ u16 unk_38;
    /* 3A */ u8 unk_3A;
    /* 3B */ u8 unk_3B;
    /* 3C */ u8 unk_3C;
};

void func_fe6_08074EF0(struct UnitListScreenProcA * proc);

extern struct Unit ** gUnk_0200CC38[];
extern struct Text gUnk_0200D6AC;
extern struct Unit gUnk_0200D6B4[];
extern u8 gUnk_0200CD38;
extern u32 gUnk_0200E6B4[]; // equipped item icons
extern int gUnk_0200E7D8; // unit id

struct Unk_08678744
{
    u16 const * sprite_00;
    u16 const * sprite_04;
    u16 const * sprite_08;
};

extern struct Unk_08678744 CONST_DATA gUnk_08678744;

struct Unk_08678840_00
{
    /* 00 */ u8 unk_00;
    /* 01 */ STRUCT_PAD(0x01, 0x04);
    /* 04 */ char const * str_04;
    /* 08 */ u8 unk_08;
    /* 09 */ STRUCT_PAD(0x09, 0x10);
};

struct Unk_08678840
{
    /* 04 */ struct Unk_08678840_00 unk_00[9];
};

extern struct Unk_08678840 gUnk_08678840[];

extern u16 CONST_DATA gUnk_08678750[]; // sprite
extern u16 const * CONST_DATA gUnk_08678818[]; // sprites
extern u16 CONST_DATA gUnk_08678758[]; // sprite
extern u16 CONST_DATA gUnk_08678760[]; // sprite

struct Unk_02016874
{
    /* 00 */ u16 unk_00[8]; // 0x10
    /* 10 */ u16 unk_10; // this is part of unk_00
};

extern struct Unk_02016874 gUnk_02016874;

void func_fe6_080741EC(void)
{
    int i;

    UnitRearrangeInit(gUnk_0200D6B4);

    for (i = 0; i < gUnk_0200CD38; i++)
    {
        UnitRearrangeAdd(*gUnk_0200CC38[i]);
    }

    for (i = 1; i < 0x40; i++)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if ((unit->flags & UNIT_FLAG_DEAD) == 0)
            continue;

        UnitRearrangeAdd(unit);
    }

    UnitRearrangeApply();
}

void func_fe6_08074254(fu8 x, fu8 y, fu8 width)
{
    int i;

    PutSpriteExt(0x0D, x, y, gUnk_08678744.sprite_00, 0xA0 << 7);

    for (i = 0; i < width - 1; i++)
    {
        PutSpriteExt(0x0D, x + i * 16 + 8, y, gUnk_08678744.sprite_04, 0xA0 << 7);
    }

    PutSpriteExt(0x0D, x + i * 16 + 8, y, gUnk_08678744.sprite_08, 0xA0 << 7);
}

void func_fe6_080742D0(fu8 arg_0)
{
    int i, j;

    TmFillRect(gBg2Tm + 0x34, 4, 1, 0);

    ClearText(&gUnk_0200D6AC);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (gUnk_08678840[i].unk_00[j].unk_00 == arg_0)
            {
                if (i == 5 && j != 0)
                {
                    PutIcon(gBg2Tm + 0x34, ICON_ITEM_KIND_BASE + j - 1, 0xA0 << 7);
                }
                else
                {
                    Text_SetCursor(&gUnk_0200D6AC, 0);
                    Text_SetColor(&gUnk_0200D6AC, TEXT_COLOR_SYSTEM_WHITE);
                    Text_DrawString(&gUnk_0200D6AC, gUnk_08678840[i].unk_00[j].str_04);
                    PutText(&gUnk_0200D6AC, gBg2Tm + 0x34);
                }

                break;
            }
        }
    }

    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_08074384(int arg_0)
{
    fu8 i;

    for (i = 0; i < 8; i++)
    {
        if (gUnk_0200E6B4[i] == arg_0)
            return;
    }

    for (i = 0; i < 8; i++)
    {
        if (gUnk_0200E6B4[i] == UINT8_MAX)
        {
            gUnk_0200E6B4[i] = arg_0;
            return;
        }
    }
}

void func_fe6_080743C8(fu16 arg_0)
{
    int icons_to_display[10];
    fu8 i, j;

    fu8 offset = arg_0 / 16;

    for (i = 0; i < 8; i++)
    {
        icons_to_display[i] = UINT8_MAX;
    }

    if (offset != 0)
        offset = offset - 1;

    for (i = 0; i < 8 && i + offset < gUnk_0200CD38; i++)
    {
        if (GetUnitEquippedWeapon(*gUnk_0200CC38[offset + i]) != 0)
        {
            icons_to_display[i] = GetItemIcon(GetUnitEquippedWeapon(*gUnk_0200CC38[offset + i]));
        }
    }

    for (i = 0; i < 8; i++)
    {
        if (gUnk_0200E6B4[i] != UINT8_MAX)
        {
            bool icon_in_use = FALSE;

            for (j = 0; j < 8; j++)
            {
                if (icons_to_display[j] == gUnk_0200E6B4[i])
                    icon_in_use = TRUE;
            }

            if (!icon_in_use)
            {
                ClearIcon(gUnk_0200E6B4[i]);
                gUnk_0200E6B4[i] = UINT8_MAX;
            }
        }
    }
}

void func_fe6_080744A0(fu8 arg_0, fu8 arg_1, fi8 arg_2)
{
    // TODO: chr & pal constants

    fu8 chr_offset = (arg_1 / 8) % 6;

    if (arg_0 == 0)
    {
        if (arg_2 != 0)
        {
            gBg2Tm[TM_OFFSET(0, 4)] = TILEREF(0x368 + chr_offset, 0xF);
            gBg2Tm[TM_OFFSET(0, 5)] = TILEREF(0x36E + chr_offset, 0xF);
        }
        else
        {
            gBg2Tm[TM_OFFSET(0, 4)] = 0;
            gBg2Tm[TM_OFFSET(0, 5)] = 0;
        }
    }
    else
    {
        if (arg_2 != 0)
        {
            gBg2Tm[TM_OFFSET(29, 4)] = TILEREF(0x368 + chr_offset, 0xF) + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(29, 5)] = TILEREF(0x36E + chr_offset, 0xF) + TILE_HFLIP;
        }
        else
        {
            gBg2Tm[TM_OFFSET(29, 4)] = 0;
            gBg2Tm[TM_OFFSET(29, 5)] = 0;
        }
    }

    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_08074558(struct UnitListScreenProcA * proc, fi8 arg_1)
{
    fu8 i;

    int unit_id;

    if (arg_1 != 0)
    {
        unit_id = gUnk_0200E7D8;
    }
    else
    {
        unit_id = GetLastStatScreenUnitId();
    }

    for (i = 0; i < gUnk_0200CD38; i++)
    {
        if (arg_1 != 0)
        {
            if (UNIT_PID(*gUnk_0200CC38[i]) == unit_id)
                goto found_unit;

            continue;
        }
        else
        {
            if ((*gUnk_0200CC38[i])->id == unit_id)
                goto found_unit;

            continue;
        }

    found_unit:
        proc->unk_30 = i;

        if (i == 0)
        {
            proc->unk_2C = 0;
            proc->unk_40 = 0;
            return;
        }

        if (i == gUnk_0200CD38 - 1)
        {
            if (gUnk_0200CD38 < 7)
            {
                proc->unk_2C = i;
                proc->unk_40 = 0;
                return;
            }
            else
            {
                proc->unk_2C = 5;
                proc->unk_40 = (gUnk_0200CD38 - 6) * 16;
                return;
            }
        }

        if (i > proc->unk_40 / 16 && i < proc->unk_40 / 16 + 5)
        {
            proc->unk_2C = i - proc->unk_40 / 16;
            return;
        }

        if (proc->unk_40 > (i - 1) * 16)
        {
            proc->unk_2C = 1;
            proc->unk_40 = (i - 1) * 16;
            return;
        }

        if (proc->unk_40 < (i - 4) * 16)
        {
            proc->unk_2C = 4;
            proc->unk_40 = (i - 4) * 16;
            return;
        }

        return;
    }
}

void func_fe6_08074668(bool use_win1)
{
    if (use_win1)
    {
        SetWinEnable(1, 1, 0);
        SetWin0Box(0, 0x38, DISPLAY_WIDTH, 0x98);
        SetWin1Box(0, 0x00, DISPLAY_WIDTH, 0x20);
        SetWin0Layers(1, 1, 1, 1, 1);
        SetWin1Layers(0, 1, 1, 1, 1);
        SetWOutLayers(0, 1, 1, 1, 0);
    }
    else
    {
        SetWinEnable(1, 0, 0);
        SetWin0Box(0, 0x38, DISPLAY_WIDTH, 0x98);
        SetWin0Layers(1, 1, 1, 1, 1);
        SetWOutLayers(0, 1, 1, 1, 1);
    }
}

void func_fe6_08074778(struct UnitListScreenProcA * proc)
{
    EndAllMus();
    Proc_End(proc->unk_44);
    Proc_End(proc->unk_48);
    EndGreenText();

    SetWinEnable(0, 0, 0);

    if (proc->unk_39 == 1)
    {
        SetStatScreenExcludedUnitFlags(UNIT_FLAG_DEAD);
    }
    else
    {
        SetStatScreenExcludedUnitFlags(UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED);
    }

    StartStatScreen(*gUnk_0200CC38[proc->unk_30], proc);

    gPlaySt.last_sort_id = (proc->unk_34 << 7) + proc->unk_32;

    proc->unk_29 = 4;
}

void func_fe6_08074804(struct UnitListScreenProcA * proc)
{
    func_fe6_08074EF0(proc);
    SetDispEnable(0, 0, 0, 0, 0);
}

void func_fe6_08074830(struct UnitListScreenProcA * proc)
{
    SetDispEnable(1, 1, 1, 1, 1);
}

void func_fe6_08074850(struct UnitListScreenProcB * proc)
{
    proc->unk_2C = proc->proc_parent;
    proc->unk_3B = 0;
    proc->unk_3C = 0;
    proc->unk_38 = proc->unk_2C->unk_40;
    proc->unk_3A = 0;
    proc->unk_30 = 0;
    proc->unk_34 = func_fe6_0808230C(proc);

    func_fe6_08082320(proc->unk_34, 0xE0, 0x40, 10, proc->unk_2C->unk_40, gUnk_0200CD38, 6);

    ForceSyncUnitSpriteSheet();
}

#include <string.h> // memcpy, TODO: remove
extern u8 const gUnk_08327148[4];

void func_fe6_080748AC(struct UnitListScreenProcB * proc)
{
    fu8 r5;
    fi8 sl;
    fu8 i;

    u8 sp_0C[4];
    memcpy(sp_0C, gUnk_08327148, sizeof(sp_0C));

    if (proc->unk_2C->unk_34 == 0)
    {
        PutSpriteExt(0x0B, 0xB8, sp_0C[(proc->unk_3B / 8) % 4] + 7, gUnk_08678750, OAM2_PAL(9));
    }
    else
    {
        PutSpriteExt(0x0B, 0xB8 + 0x2000, sp_0C[(proc->unk_3B / 8) % 4] + 7, gUnk_08678750, OAM2_PAL(9));
    }

    PutSpriteExt(0x0D, 0x20, 0x08, gUnk_08678818[proc->unk_2C->unk_2F], OAM2_PAL(9));
    PutSpriteExt(0x0D, 0xA0, 0, gUnk_08678758, OAM2_PAL(9));

    func_fe6_08082320(proc->unk_34, 0xE0, 0x40, 0x0A, proc->unk_2C->unk_40, gUnk_0200CD38, 6);

    if (proc->unk_2C->unk_29 > 2)
    {
        PutUiHand(
            gUnk_08678840[proc->unk_2C->unk_2F].unk_00[proc->unk_2C->unk_2D].unk_08,
            40 + proc->unk_2C->unk_2C * 16);
    }
    else
    {
        PutSpriteExt(0x0D, 4, 0x40 + proc->unk_2C->unk_2C * 16, gUnk_08678760, 0x9000);
    }

    if ( proc->unk_38 != proc->unk_2C->unk_40 || (proc->unk_2C->unk_40 % 0x10) != 0)
    {
        gPal[0x19E] = gUnk_02016874.unk_10;
        EnablePalSync();

        proc->unk_3C = 0x20;
        proc->unk_38 = proc->unk_2C->unk_40;

        if (proc->unk_3A == 0)
        {
            func_fe6_08074668(TRUE);
            proc->unk_3A = 1;
        }
    }
    else
    {
        gPal[0x19E] = gUnk_02016874.unk_00[(proc->unk_3C / 4) & 0x0F];
        EnablePalSync();

        if (proc->unk_3A == 1)
        {
            func_fe6_08074668(FALSE);
            proc->unk_3A = 0;
        }
    }

    SyncUnitSpriteSheet();

    r5 = proc->unk_38 / 0x10;
    sl = -(proc->unk_38 % 0x10);

    for (i = 0; i < 6 && i + r5 < gUnk_0200CD38; i++)
    {
        PutUnitSprite(4, 8, 56 + i * 16 + sl, *gUnk_0200CC38[i + r5]);
    }

    if (proc->unk_3A != 0 && i + r5 < gUnk_0200CD38)
    {
        PutUnitSprite(4, 8, 56 + i * 16 + sl, *gUnk_0200CC38[i + r5]);
    }

    if (proc->unk_2C->unk_2F < proc->unk_2C->unk_2E && proc->unk_2C->unk_39 != 3)
    {
        func_fe6_080744A0(1, proc->unk_30, 1);
    }
    else
    {
        func_fe6_080744A0(1, proc->unk_30, 0);
    }

    if (proc->unk_2C->unk_2F > 1 && proc->unk_2C->unk_39 != 3)
    {
        func_fe6_080744A0(0, proc->unk_30, 1);
    }
    else
    {
        func_fe6_080744A0(0, proc->unk_30, 0);
    }

    proc->unk_30++;

    if ((proc->unk_30 >> 3) > 5)
        proc->unk_30 = 0;

    proc->unk_3B++;
    proc->unk_3C++;
}

void func_fe6_08074BA0(void)
{
}
