#include "common.h"

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "icon.h"
#include "sprite.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "battle.h"
#include "support.h"
#include "faction.h"
#include "unitsprite.h"
#include "unitrearrange.h"
#include "ui.h"
#include "mu.h"
#include "statscreen.h"
#include "helpbox.h"

#include "constants/icons.h"
#include "constants/msg.h"
#include "constants/songs.h"
#include "constants/pids.h"

#include "constants/videoalloc_global.h"

struct UnitListScreenProcA
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 unk_29;
    /* 2A */ u8 unk_2A;
    /* 2B */ u8 unk_2B;
    /* 2C */ u8 unk_2C;
    /* 2D */ u8 unk_2D;
    /* 2E */ u8 unk_2E;
    /* 2F */ u8 unk_2F;
    /* 30 */ u8 unk_30;
    /* 31 */ u8 unk_31;
    /* 32 */ u8 unk_32;
    /* 33 */ u8 unk_33;
    /* 34 */ u8 unk_34;
    /* 35 */ u8 unk_35;
    /* 36 */ u8 unk_36;
    /* 37 */ u8 unk_37;
    /* 38 */ u8 unk_38;
    /* 39 */ u8 unk_39;
    /* 3A */ u8 unk_3A;
    /* 3B */ u8 unk_3B;
    /* 3C */ u8 unk_3C;
    /* 3D */ STRUCT_PAD(0x3D, 0x3E);
    /* 3E */ u16 unk_3E;
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

struct Unk_0200C938
{
    /* 00 */ struct Unit * unit;
    /* 04 */ i16 battle_attack;
    /* 06 */ i16 battle_hit;
    /* 08 */ i16 battle_avoid;
    /* 0A */ u8 support_talk_count;
};

extern struct Unk_0200C938 gUnk_0200C938[];

extern struct Unk_0200C938 * gUnk_0200CC38[];
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
    /* 09 */ STRUCT_PAD(0x09, 0x0C);
    /* 0C */ u32 msg_0C;
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

extern u8 const gUnk_083198CC[]; // img
extern u16 const gUnk_08319E88[]; // pal
extern u8 const gUnk_083215B8[]; // img
extern u16 const gUnk_08321EE4[]; // pal
extern u8 const gUnk_083210A0[]; // tsa
extern u16 const gUnk_08320EEC[]; // tm
extern u8 const gUnk_0831B0A8[]; // img
extern u16 const gUnk_08320D98[]; // pal

extern struct Text gUnk_0200D5BC[];
extern struct Text gUnk_0200D5F4[]; // this could be an array of struct of 3 texts also
extern struct Text gUnk_0200D69C;
extern struct Text gUnk_0200D6A4;
extern struct Text gUnk_0200D6AC;

extern char const gUnk_0832714C[];

extern struct ProcScr CONST_DATA gUnk_086786F4[];

enum
{
    BGPAL_UNITLIST_10 = 10, // ..13
    BGPAL_UNITLIST_15 = 15,
};

enum
{
    OBJCHR_UNITLIST_240 = 0x240,
    OBJCHR_UNITLIST_390 = 0x390,
};

enum
{
    OBJPAL_UNITLIST_1 = 1, // ..4
    OBJPAL_UNITLIST_9 = 9,
};

extern u16 gUnk_0200CD3A[]; // tm
extern u16 gUnk_0200D53A[]; // tm

extern u8 CONST_DATA gUnk_0867871C[];

void func_fe6_080741EC(void)
{
    int i;

    UnitRearrangeInit(gUnk_0200D6B4);

    for (i = 0; i < gUnk_0200CD38; i++)
    {
        UnitRearrangeAdd(gUnk_0200CC38[i]->unit);
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
        if (GetUnitEquippedWeapon(gUnk_0200CC38[offset + i]->unit) != 0)
        {
            icons_to_display[i] = GetItemIcon(GetUnitEquippedWeapon(gUnk_0200CC38[offset + i]->unit));
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
            if (UNIT_PID(gUnk_0200CC38[i]->unit) == unit_id)
                goto found_unit;

            continue;
        }
        else
        {
            if (gUnk_0200CC38[i]->unit->id == unit_id)
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

    StartStatScreen(gUnk_0200CC38[proc->unk_30]->unit, proc);

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
        PutUnitSprite(4, 8, 56 + i * 16 + sl, gUnk_0200CC38[i + r5]->unit);
    }

    if (proc->unk_3A != 0 && i + r5 < gUnk_0200CD38)
    {
        PutUnitSprite(4, 8, 56 + i * 16 + sl, gUnk_0200CC38[i + r5]->unit);
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

void func_fe6_08074BA4(struct UnitListScreenProcA * proc)
{
    int support_count;
    fu8 i, support_now_count;

    FOR_UNITS_FACTION(gPlaySt.faction, unit,
    {
        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        if (proc->unk_39 != 1 && (unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
            continue;

        if ((unit->flags & UNIT_FLAG_NOT_DEPLOYED) == 0)
            proc->unk_3B++;

        gUnk_0200C938[gUnk_0200CD38].unit = unit;

        BattleGenerateDisplayStats(unit, -1);

        gUnk_0200C938[gUnk_0200CD38].battle_attack = ((gBattleUnitA.battle_attack + 1) & 0xFF) - 1;
        gUnk_0200C938[gUnk_0200CD38].battle_hit = ((gBattleUnitA.battle_hit + 1) & 0xFF) - 1;
        gUnk_0200C938[gUnk_0200CD38].battle_avoid = ((gBattleUnitA.battle_avoid + 1) & 0xFF) - 1;

        support_count = GetUnitSupportCount(unit);
        support_now_count = 0;

        for (i = 0; i < support_count; i++)
        {
            if (CanUnitSupportNow(unit, i))
                support_now_count++;
        }

        if (support_now_count > 3)
            proc->unk_2E = 6 + (support_now_count - 1) / 3;

        gUnk_0200C938[gUnk_0200CD38].support_talk_count = support_now_count;
        gUnk_0200CC38[gUnk_0200CD38] = &gUnk_0200C938[gUnk_0200CD38];

        gUnk_0200CD38++;

        UseUnitSprite(GetUnitMapSprite(unit));
    })
}

void func_fe6_08074D54(struct UnitListScreenProcA * proc)
{
    // this function is identical to func_fe6_08074BA4
    // except it uses FACTION_BLUE instead of gPlaySt.faction

    int support_count;
    fu8 i, support_now_count;

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        if (proc->unk_39 != 1 && (unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
            continue;

        if ((unit->flags & UNIT_FLAG_NOT_DEPLOYED) == 0)
            proc->unk_3B++;

        gUnk_0200C938[gUnk_0200CD38].unit = unit;

        BattleGenerateDisplayStats(unit, -1);

        gUnk_0200C938[gUnk_0200CD38].battle_attack = ((gBattleUnitA.battle_attack + 1) & 0xFF) - 1;
        gUnk_0200C938[gUnk_0200CD38].battle_hit = ((gBattleUnitA.battle_hit + 1) & 0xFF) - 1;
        gUnk_0200C938[gUnk_0200CD38].battle_avoid = ((gBattleUnitA.battle_avoid + 1) & 0xFF) - 1;

        support_count = GetUnitSupportCount(unit);
        support_now_count = 0;

        for (i = 0; i < support_count; i++)
        {
            if (CanUnitSupportNow(unit, i))
                support_now_count++;
        }

        if (support_now_count > 3)
            proc->unk_2E = 6 + (support_now_count - 1) / 3;

        gUnk_0200C938[gUnk_0200CD38].support_talk_count = support_now_count;
        gUnk_0200CC38[gUnk_0200CD38] = &gUnk_0200C938[gUnk_0200CD38];

        gUnk_0200CD38++;

        UseUnitSprite(GetUnitMapSprite(unit));
    })
}

void func_fe6_08074EF0(struct UnitListScreenProcA * proc)
{
    fu8 i, thing;

    SetDispEnable(1, 1, 1, 1, 1);
    SetOnVMatch(NULL);
    InitBgs(NULL);
    ResetText();
    ResetTextFont();
    ClearIcons();
    ApplyUnitSpritePalettes();
    ApplySystemObjectsGraphics();

    StartGreenText(proc);

    gUnk_0200CD38 = 0;
    proc->unk_3B = 0;
    proc->unk_2E = 6;

    func_fe6_08074D54(proc);

    if (proc->unk_39 != 1 || proc->unk_2A == 1)
    {
        thing = gPlaySt.last_sort_id;

        if (thing != 0)
        {
            proc->unk_33 = (thing >> 7) & 1;
            proc->unk_34 = proc->unk_33;
            proc->unk_32 = thing & 0x7F;
        }

        if (proc->unk_29 != 4 && proc->unk_2F != 0)
        {
            thing = gPlaySt.unk_19_4;

            if (thing != 0)
            {
                if (thing > 6)
                    proc->unk_2F = 6;
                else
                    proc->unk_2F = thing;

                proc->unk_36 = proc->unk_2F;
            }
        }

        func_fe6_08076D3C(proc->unk_32, proc->unk_34);
    }

    Decompress(gUnk_083198CC, OBJ_VRAM0 + OBJCHR_UNITLIST_390 * CHR_SIZE);
    ApplyPalettes(gUnk_08319E88, 0x10 + OBJPAL_UNITLIST_1, 3);

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    TmFill(gBg2Tm, 0);

    InitIcons();
    ApplyIconPalettes(4);
    UnpackUiWindowFrameGraphics();
    Decompress(gUnk_083215B8, OBJ_VRAM0 + OBJCHR_UNITLIST_240 * CHR_SIZE);
    ApplyPalette(gUnk_08321EE4, 0x10 + OBJPAL_UNITLIST_9);

    func_fe6_08082CBC();
    TmApplyTsa(gBg1Tm, gUnk_083210A0, TILEREF(0, BGPAL_WINDOWFRAME));

    for (i = 0; i < 7 ; i++)
    {
        InitText(gUnk_0200D5BC + i, 5);
        InitTextDb(gUnk_0200D5F4 + i * 3, 7);
        InitText(gUnk_0200D5F4 + i * 3 + 1, 7);
        InitText(gUnk_0200D5F4 + i * 3 + 2, 5);
    }

    InitText(&gUnk_0200D69C, 4);
    InitText(&gUnk_0200D6A4, 20);
    InitText(&gUnk_0200D6AC, 4);

    func_fe6_080742D0(proc->unk_32);

    if (proc->unk_29 == 4)
    {
        func_fe6_08074558(proc, 0);
        proc->unk_29 = 0;
    }
    else
    {
        if (proc->unk_39 == 1)
            func_fe6_08074558(proc, 1);
    }

    proc->unk_3E = 0;
    proc->unk_2B = 0;

    ClearText(&gUnk_0200D69C);
    Text_SetCursor(&gUnk_0200D69C, 0);
    Text_SetColor(&gUnk_0200D69C, 0);
    Text_DrawString(&gUnk_0200D69C, gUnk_0832714C);
    PutText(&gUnk_0200D69C, gBg2Tm + TM_OFFSET(3, 5));

    for (i = 0; i < 20; i++)
    {
        gUnk_0200E6B4[i] = UINT8_MAX;
    }

    for (i = proc->unk_40 / 16; i < proc->unk_40 / 16 + 6 && i < gUnk_0200CD38; i++)
    {
        func_fe6_08076448(proc, i, gBg0Tm, proc->unk_2F, 1);
    }

    func_fe6_080763D8(proc->unk_2E, proc->unk_2F, 1);

    SetWinEnable(1, 0, 0);
    SetWin0Box(0x10, 0x38, 0xe0, 0x98);
    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(0, 1, 1, 1, 1);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    SetBgOffset(3, 0, 0);
    SetBgOffset(2, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(0, 0, (proc->unk_40 - 0x38) & 0xFF);

    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 2;
    gDispIo.bg2_ct.priority = 1;
    gDispIo.bg3_ct.priority = 3;

    Decompress(gUnk_08320EEC, gBg1Tm + TM_OFFSET(0, 20));
    ApplyPalette(gUnk_08319E88, BGPAL_UNITLIST_15);

    proc->unk_44 = SpawnProc(gUnk_086786F4, proc);

    if (proc->unk_39 == 1 && proc->unk_3C == 0)
    {
        Decompress(gUnk_0831B0A8, (void *) VRAM + GetBgChrOffset(3));
        ApplyPalettes(gUnk_08320D98, BGPAL_UNITLIST_10, 4);
        proc->unk_48 = func_fe6_08082560(proc);
    }
    else
    {
        proc->unk_48 = StartMuralBackground(NULL, NULL, BGPAL_UNITLIST_10);
    }

    func_fe6_08070E70(NULL, -1);
}

void func_fe6_08075338(struct UnitListScreenProcA * proc)
{
    proc->unk_29 = 0;
    proc->unk_31 = 1;
    proc->unk_2C = 0;
    proc->unk_2D = 0;
    proc->unk_30 = 0;

    if (proc->unk_39 == 3)
        proc->unk_2F = 0;
    else
        proc->unk_2F = 1;

    proc->unk_36 = proc->unk_2F;
    proc->unk_40 = 0;
    proc->unk_32 = 1;
    proc->unk_2A = 0;
    proc->unk_33 = 1;
    proc->unk_34 = 0;
    proc->unk_35 = 0;

    func_fe6_08074EF0(proc);
}

void func_fe6_080753A0(struct UnitListScreenProcA * proc)
{
    fu8 idx = proc->unk_30;

    if ((gUnk_0200CC38[idx]->unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
    {
        if (proc->unk_3C == 0 || func_fe6_08082B74(gUnk_0200CC38[idx]->unit))
        {
            if (proc->unk_3A > proc->unk_3B)
            {
                gUnk_0200CC38[idx]->unit->flags &= ~(UNIT_FLAG_TURN_ENDED | UNIT_FLAG_NOT_DEPLOYED);
                func_fe6_080791B4(UNIT_PID(gUnk_0200CC38[idx]->unit));
                proc->unk_3B++;
                PlaySe(SONG_6A);
                func_fe6_08076448(proc, idx, gBg0Tm, proc->unk_2F, 1);
            }
            else
            {
                PlaySe(SONG_6C);
            }
        }
        else
        {
            func_fe6_08082B00(0, proc->unk_2C * 16 + 0x38, MSG_6C1, proc);
        }

        return;
    }
    else
    {
        if (proc->unk_3C != 0 || !func_fe6_08079404(gUnk_0200CC38[idx]->unit))
        {
            gUnk_0200CC38[idx]->unit->flags |= UNIT_FLAG_TURN_ENDED | UNIT_FLAG_NOT_DEPLOYED;
            func_fe6_080791DC(UNIT_PID(gUnk_0200CC38[idx]->unit));
            PlaySe(SONG_6B);
            proc->unk_3B--;
            func_fe6_08076448(proc, idx, gBg0Tm, proc->unk_2F, 1);
        }
        else
        {
            PlaySe(SONG_6C);
        }
    }
}

void func_fe6_080754F4(struct Unit * unit, int step)
{
    int anim_param;

    if (UNIT_PID(unit) == PID_MERLINUS)
    {
        PlaySe(SONG_6C);
        return;
    }

    anim_param = unit->flags & UNIT_FLAG_SOLOANIM;

    anim_param = anim_param >> 14;
    anim_param = ((anim_param + step + 3)) % 3;
    anim_param = anim_param << 14;

    unit->flags = anim_param | (unit->flags & ~UNIT_FLAG_SOLOANIM);

    if ((anim_param & UNIT_FLAG_SOLOANIM) != 0)
    {
        PlaySe(SONG_6A);
    }
    else
    {
        PlaySe(SONG_6B);
    }
}

void func_fe6_08075570(struct UnitListScreenProcA * proc)
{
    fu8 var_04 = proc->unk_2D;

    int i;
    fu8 var_08;

    switch (proc->unk_29)
    {
        case 0:
            if ((gKeySt->held & KEY_BUTTON_L) != 0)
            {
                proc->unk_31 = 2;
            }
            else
            {
                proc->unk_31 = 1;
            }

            if ((gKeySt->pressed & KEY_BUTTON_R) != 0)
            {
                Proc_Goto(proc, 3);
                return;
            }

            if ((gKeySt->pressed & KEY_BUTTON_A) != 0)
            {
                switch (proc->unk_39)
                {
                    case 1:
                        func_fe6_080753A0(proc);
                        break;

                    case 3:
                        func_fe6_080754F4(gUnk_0200CC38[proc->unk_30]->unit, 1);
                        func_fe6_08076448(proc, proc->unk_30, gBg0Tm, proc->unk_2F, 0);
                        break;

                    case 0:
                        SetStatScreenLastUnitId(gUnk_0200CC38[proc->unk_30]->unit->id);
                        PlaySe(SONG_6A);
                        Proc_Break(proc);
                        break;

                    default:
                        break;
                }

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_LEFT) != 0)
            {
                if (proc->unk_39 == 3)
                {
                    if ((gKeySt->pressed & KEY_DPAD_LEFT) == 0)
                        break;

                    func_fe6_080754F4(gUnk_0200CC38[proc->unk_30]->unit, -1);
                    func_fe6_08076448(proc, proc->unk_30, gBg0Tm, proc->unk_2F, 0);

                    break;
                }

                if (proc->unk_2F < 2)
                    break;

                proc->unk_36--;
                Proc_Goto(proc, 2);
                proc->unk_2D = 0;
                PlaySe(SONG_6F);

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_RIGHT) != 0)
            {
                if (proc->unk_39 == 3)
                {
                    if ((gKeySt->pressed & KEY_DPAD_RIGHT) == 0)
                        break;

                    func_fe6_080754F4(gUnk_0200CC38[proc->unk_30]->unit, +1);
                    func_fe6_08076448(proc, proc->unk_30, gBg0Tm, proc->unk_2F, 0);

                    break;
                }

                if (proc->unk_2F < proc->unk_2E)
                {
                    proc->unk_36++;
                    proc->unk_2D = 0;
                    PlaySe(SONG_6F);
                    Proc_Goto(proc, 2);
                }

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_UP) != 0 || ((gKeySt->held & KEY_BUTTON_L) != 0 && (gKeySt->pressed2 & KEY_DPAD_UP) != 0))
            {
                if (proc->unk_30 == 0)
                {
                    if ((gKeySt->pressed & KEY_DPAD_UP) == 0)
                        break;

                    PlaySe(SONG_66);
                    proc->unk_29 = 3;
                    break;
                }

                proc->unk_30--;
                PlaySe(SONG_66);

                if (proc->unk_2C < 2)
                {
                    if (proc->unk_40 / 16 != 0)
                    {
                        if (proc->unk_2C == 0)
                        {
                            proc->unk_30++;
                            proc->unk_2C = 1;
                        }

                        func_fe6_08076448(proc, proc->unk_40 / 16 - 1, gBg0Tm, proc->unk_2F, 1);
                        proc->unk_29 = 2;
                        proc->unk_40 = -(proc->unk_31 * 4) + proc->unk_40;
                        SetBgOffset(0, 0, (proc->unk_40 - 0x38) & 0xFF);

                        if (proc->unk_2C == 0)
                        {
                            proc->unk_2C++;
                        }

                        break;
                    }
                }

                proc->unk_2C--;

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_DOWN) != 0 || ((gKeySt->held & KEY_BUTTON_L) != 0 && (gKeySt->pressed2 & KEY_DPAD_DOWN) != 0))
            {
                if (proc->unk_30 < gUnk_0200CD38 - 1)
                {
                    proc->unk_30++;
                    PlaySe(SONG_66);
    
                    if (proc->unk_2C == 4 && proc->unk_30 != gUnk_0200CD38 - 1)
                    {
                        func_fe6_08076448(proc, 6 + proc->unk_40 / 16, gBg0Tm, proc->unk_2F, 1);
                        proc->unk_29 = 1;
                        proc->unk_40 = proc->unk_40 + proc->unk_31 * 4;
                        SetBgOffset(0, 0, (proc->unk_40 - 0x38) & 0xFF);
                        break;
                    }
    
                    proc->unk_2C++;
                }
                break;
            }

            break;

        case 1:
            proc->unk_40 += 4 * proc->unk_31;
            SetBgOffset(0, 0, (proc->unk_40 - 0x38) & 0xFF);

            if ((proc->unk_40 % 0x10) == 0)
            {
                proc->unk_29 = 0;
                func_fe6_080743C8(proc->unk_40);
            }

            break;

        case 2:
            proc->unk_40 += -(4 * proc->unk_31);
            SetBgOffset(0, 0, (proc->unk_40 - 0x38) & 0xFF);

            if ((proc->unk_40 % 0x10) == 0)
            {
                proc->unk_29 = 0;
                func_fe6_080743C8(proc->unk_40);
            }

            break;

        case 3:
            if (proc->unk_2B != 0 && (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R)) != 0)
            {
                CloseHelpBox();
                proc->unk_2B = 0;
                return;
            }

            if ((gKeySt->pressed & KEY_BUTTON_A) != 0 && proc->unk_2B == 0)
            {
                var_08 = proc->unk_32;

                proc->unk_2A = 1;
                PlaySe(SONG_6A);
                proc->unk_32 = gUnk_08678840[proc->unk_2F].unk_00[proc->unk_2D].unk_00;
                proc->unk_33 = (proc->unk_33 + 1) & 1;

                if (func_fe6_08076D3C(proc->unk_32, proc->unk_33))
                {
                    for (i = 0; i < 6 && i < gUnk_0200CD38; i++)
                    {
                        func_fe6_08076448(proc, i, gBg0Tm, proc->unk_2F, 1);
                    }

                    func_fe6_080743C8(proc->unk_40);
                    EnableBgSync(1);
                }

                proc->unk_34 = proc->unk_33;
                proc->unk_35 = proc->unk_2D;
                
                if (proc->unk_32 != var_08)
                    func_fe6_080742D0(proc->unk_32);

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_DOWN) != 0 && proc->unk_2B == 0)
            {
                PlaySe(SONG_66);
                proc->unk_33 = 1;
                proc->unk_29 = 0;
                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_LEFT) != 0)
            {
                proc->unk_33 = 1;

                if (proc->unk_2D == 0)
                {
                    if (proc->unk_2F < 2)
                        break;

                    if (proc->unk_39 == 3)
                        break;

                    PlaySe(SONG_6F);
                    proc->unk_36--;

                    for (i = 8; i > 0 && gUnk_08678840[proc->unk_36].unk_00[i].unk_08 == 0; i--)
                    {
                    }

                    proc->unk_2D = i;
                    Proc_Goto(proc, 2);
                    break;
                }

                proc->unk_2D--;
                PlaySe(SONG_67);
                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_RIGHT) != 0)
            {
                proc->unk_33 = 1;

                if (proc->unk_2D == 8 || gUnk_08678840[proc->unk_2F].unk_00[proc->unk_2D + 1].unk_08 == 0)
                {
                    if (proc->unk_2F < proc->unk_2E)
                    {
                        if (proc->unk_39 == 3)
                            break;
    
                        proc->unk_2D = 0;
                        PlaySe(SONG_6F);
    
                        proc->unk_36++;
                        Proc_Goto(proc, 2);
                    }
                    break;
                }
                else
                {
                    proc->unk_2D = proc->unk_2D + 1;
                    PlaySe(SONG_67);
                }

                break;
            }

            if ((gKeySt->pressed & KEY_BUTTON_R) != 0 && proc->unk_2B == 0)
            {
                proc->unk_2B = 1;

                StartHelpBox(
                    gUnk_08678840[proc->unk_2F].unk_00[proc->unk_2D].unk_08, 0x28,
                    gUnk_08678840[proc->unk_2F].unk_00[proc->unk_2D].msg_0C);
            }

            break;
    }

    if ((gKeySt->pressed & KEY_BUTTON_B) != 0 && proc->unk_2B == 0)
    {
        PlaySe(SONG_6B);
        SetStatScreenLastUnitId(0);
        Proc_Break(proc);
    }

    if (proc->unk_2B != 0 && var_04 != proc->unk_2D)
    {
        StartHelpBox(
            gUnk_08678840[proc->unk_36].unk_00[proc->unk_2D].unk_08, 0x28,
            gUnk_08678840[proc->unk_36].unk_00[proc->unk_2D].msg_0C);
    }
}

void func_fe6_08075D34(struct UnitListScreenProcA * proc)
{
    if (proc->unk_39 == 1)
    {
        gUnk_0200E7D8 = UNIT_PID(gUnk_0200CC38[proc->unk_30]->unit);
        func_fe6_080741EC();
    }

    gPlaySt.last_sort_id = (proc->unk_34 << 7) + proc->unk_32;

    if (proc->unk_2F != 0)
        gPlaySt.unk_19_4 = proc->unk_2F;

    Proc_End(proc->unk_44);

    if (proc->unk_48 != NULL)
        Proc_End(proc->unk_48);

    EndGreenText();

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    TmFill(gBg2Tm, 0);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    SetWinEnable(0, 0, 0);

    ResetTextFont();
    ClearIcons();
}

void func_fe6_08075DF8(struct UnitListScreenProcA * proc)
{
    int i;

    TmFillRect(gUnk_0200CD3A, 31, 31, 0);

    for (i = proc->unk_40 / 16; i < proc->unk_40 / 16 + 6 && i < gUnk_0200CD38; i++)
    {
        func_fe6_08076448(proc, i, gUnk_0200CD3A, proc->unk_2F, 0);
    }

    TmFillRect(gUnk_0200D53A, 31, 1, 0);

    func_fe6_08076314(gUnk_0200D53A, proc->unk_2F);

    proc->unk_3E = 0;
    proc->unk_37 = proc->unk_2F;
    proc->unk_38 = 0;
}

#if NONMATCHING

void func_fe6_08075E94(struct UnitListScreenProcA * proc)
{
    int r4, i;

    proc->unk_38 += gUnk_0867871C[proc->unk_3E];

    if (proc->unk_38 > 20)
        proc->unk_38 = 20;

    proc->unk_3E++;

    for (i = 0; i < 20; i++)
    { 
        fu8 r1;

        if (proc->unk_36 > proc->unk_2F)
        {
            // permuter found that idk though
            proc->unk_32 = proc->unk_32;

            if (proc->unk_38 + i > 20)
                r1 = 0;
            else
                r1 = i + proc->unk_38 + 8;
        }
        else
        {
            if (i < proc->unk_38)
                r1 = 0;
            else
                r1 = i - proc->unk_38 + 8;
        }

        for (r4 = proc->unk_40 / 8; r4 < 12 + proc->unk_40 / 8; r4++)
        {
            int off = 8 + (r4 & 0x1F) * 0x20;
            gBg0Tm[off + i] = *(gUnk_0200CD3A + r1 + (r4 & 0x1F) * 0x20);
        }

        for (r4 = 0; r4 < 2; r4++)
        {
            int off = 0xA8 + r4 * 0x20;
            gBg2Tm[i + off] = *(gUnk_0200D53A + r1 + r4 * 0x20);
        }
    }

    EnableBgSync(BG0_SYNC_BIT | BG2_SYNC_BIT);

    if (proc->unk_38 < 20)
        return;

    proc->unk_2F = proc->unk_36;

    TmFillRect(gBg2Tm+0x150/2, 0x16, 1, 0);
    TmFillRect(gBg0Tm+0x10/2, 0x16, 0x1F, 0);

    for (r4 = 0; r4 < 20; r4++)
        gUnk_0200E6B4[r4] = UINT8_MAX;

    ClearIcons();
    func_fe6_080742D0(proc->unk_32);

    for (r4 = proc->unk_40 / 16; r4 < proc->unk_40 / 16 + 6 && r4 < gUnk_0200CD38; r4++)
    {
        func_fe6_08076448(proc, r4, gUnk_0200CD3A, proc->unk_2F, 0);
    }

    func_fe6_08076314(gUnk_0200D53A, proc->unk_2F);
    func_fe6_080763D8(proc->unk_2E, proc->unk_2F, 0);

    proc->unk_38 = 0;
    proc->unk_3E = 0;

    Proc_Break(proc);
}

#else

NAKEDFUNC
void func_fe6_08075E94(struct UnitListScreenProcA * proc)
{
    // https://decomp.me/scratch/sjiAE

    asm(".syntax unified\n\
        push {r4, r5, r6, r7, lr}\n\
        mov r7, sl\n\
        mov r6, sb\n\
        mov r5, r8\n\
        push {r5, r6, r7}\n\
        sub sp, #0x18\n\
        adds r7, r0, #0\n\
        adds r1, r7, #0\n\
        adds r1, #0x38\n\
        ldr r0, .L08075EF8 @ =gUnk_0867871C\n\
        ldrh r2, [r7, #0x3e]\n\
        adds r0, r2, r0\n\
        ldrb r2, [r1]\n\
        ldrb r0, [r0]\n\
        adds r0, r2, r0\n\
        strb r0, [r1]\n\
        lsls r0, r0, #0x18\n\
        lsrs r0, r0, #0x18\n\
        cmp r0, #0x14\n\
        bls .L08075EC0\n\
        movs r0, #0x14\n\
        strb r0, [r1]\n\
    .L08075EC0:\n\
        ldrh r0, [r7, #0x3e]\n\
        adds r0, #1\n\
        strh r0, [r7, #0x3e]\n\
        movs r3, #0\n\
        str r1, [sp, #0x10]\n\
        adds r0, r7, #0\n\
        adds r0, #0x36\n\
        str r0, [sp, #0xc]\n\
        adds r1, r7, #0\n\
        adds r1, #0x2f\n\
        str r1, [sp, #8]\n\
        adds r2, r7, #0\n\
        adds r2, #0x40\n\
        str r2, [sp, #0x14]\n\
        ldr r0, [sp, #0x10]\n\
        str r0, [sp, #4]\n\
    .L08075EE0:\n\
        ldr r1, [sp, #0xc]\n\
        ldrb r2, [r1]\n\
        ldr r1, [sp, #8]\n\
        ldrb r1, [r1]\n\
        cmp r2, r1\n\
        bls .L08075EFC\n\
        ldr r2, [sp, #4]\n\
        ldrb r2, [r2]\n\
        adds r0, r2, r3\n\
        cmp r0, #0x14\n\
        bgt .L08075F04\n\
        b .L08075F0A\n\
        .align 2, 0\n\
    .L08075EF8: .4byte gUnk_0867871C\n\
    .L08075EFC:\n\
        ldr r1, [sp, #4]\n\
        ldrb r0, [r1]\n\
        cmp r3, r0\n\
        bge .L08075F08\n\
    .L08075F04:\n\
        movs r1, #0\n\
        b .L08075F10\n\
    .L08075F08:\n\
        subs r0, r3, r0\n\
    .L08075F0A:\n\
        adds r0, #8\n\
        lsls r0, r0, #0x18\n\
        lsrs r1, r0, #0x18\n\
    .L08075F10:\n\
        ldr r6, [sp, #0x14]\n\
        ldrh r2, [r6]\n\
        lsrs r4, r2, #3\n\
        adds r0, r4, #0\n\
        adds r0, #0xc\n\
        lsls r5, r1, #1\n\
        adds r1, r3, #1\n\
        mov sl, r1\n\
        cmp r4, r0\n\
        bge .L08075F58\n\
        movs r2, #0x1f\n\
        mov sb, r2\n\
        ldr r0, .L08075FD8 @ =gBg0Tm\n\
        mov r8, r0\n\
        ldr r1, .L08075FDC @ =gUnk_0200CD3A\n\
        mov ip, r1\n\
        adds r2, r5, #0\n\
    .L08075F32:\n\
        adds r0, r4, #0\n\
        mov r1, sb\n\
        ands r0, r1\n\
        lsls r1, r0, #5\n\
        adds r1, #8\n\
        adds r1, r1, r3\n\
        lsls r1, r1, #1\n\
        add r1, r8\n\
        lsls r0, r0, #6\n\
        adds r0, r2, r0\n\
        add r0, ip\n\
        ldrh r0, [r0]\n\
        strh r0, [r1]\n\
        adds r4, #1\n\
        ldrh r1, [r6]\n\
        lsrs r0, r1, #3\n\
        adds r0, #0xc\n\
        cmp r4, r0\n\
        blt .L08075F32\n\
    .L08075F58:\n\
        ldr r0, .L08075FE0 @ =gBg2Tm\n\
        ldr r1, .L08075FE4 @ =gUnk_0200D53A\n\
        adds r2, r5, r1\n\
        adds r1, r3, #0\n\
        adds r1, #0xa8\n\
        movs r4, #1\n\
        lsls r1, r1, #1\n\
        adds r1, r1, r0\n\
    .L08075F68:\n\
        ldrh r0, [r2]\n\
        strh r0, [r1]\n\
        adds r2, #0x40\n\
        adds r1, #0x40\n\
        subs r4, #1\n\
        cmp r4, #0\n\
        bge .L08075F68\n\
        mov r3, sl\n\
        cmp r3, #0x13\n\
        ble .L08075EE0\n\
        movs r0, #5\n\
        bl EnableBgSync\n\
        ldr r2, [sp, #0x10]\n\
        ldrb r2, [r2]\n\
        cmp r2, #0x13\n\
        bls .L08076042\n\
        ldr r1, [sp, #0xc]\n\
        ldrb r0, [r1]\n\
        ldr r2, [sp, #8]\n\
        strb r0, [r2]\n\
        ldr r0, .L08075FE8 @ =gBg2Tm+0x150\n\
        movs r1, #0x16\n\
        movs r2, #1\n\
        movs r3, #0\n\
        bl TmFillRect_thm\n\
        ldr r0, .L08075FEC @ =gBg0Tm+0x10\n\
        movs r1, #0x16\n\
        movs r2, #0x1f\n\
        movs r3, #0\n\
        bl TmFillRect_thm\n\
        adds r4, r7, #0\n\
        adds r4, #0x32\n\
        adds r5, r7, #0\n\
        adds r5, #0x2e\n\
        ldr r1, .L08075FF0 @ =gUnk_0200E6B4\n\
        movs r2, #0xff\n\
        adds r0, r1, #0\n\
        adds r0, #0x4c\n\
    .L08075FBA:\n\
        str r2, [r0]\n\
        subs r0, #4\n\
        cmp r0, r1\n\
        bge .L08075FBA\n\
        bl ClearIcons\n\
        ldrb r0, [r4]\n\
        bl func_fe6_080742D0\n\
        ldr r0, [sp, #0x14]\n\
        ldrh r0, [r0]\n\
        lsrs r4, r0, #4\n\
        adds r0, r4, #6\n\
        b .L08076012\n\
        .align 2, 0\n\
    .L08075FD8: .4byte gBg0Tm\n\
    .L08075FDC: .4byte gUnk_0200CD3A\n\
    .L08075FE0: .4byte gBg2Tm\n\
    .L08075FE4: .4byte gUnk_0200D53A\n\
    .L08075FE8: .4byte gBg2Tm+0x150\n\
    .L08075FEC: .4byte gBg0Tm+0x10\n\
    .L08075FF0: .4byte gUnk_0200E6B4\n\
    .L08075FF4:\n\
        lsls r1, r4, #0x18\n\
        lsrs r1, r1, #0x18\n\
        ldr r2, [sp, #8]\n\
        ldrb r3, [r2]\n\
        movs r0, #0\n\
        str r0, [sp]\n\
        adds r0, r7, #0\n\
        ldr r2, .L08076054 @ =gUnk_0200CD3A\n\
        bl func_fe6_08076448\n\
        adds r4, #1\n\
        ldr r1, [sp, #0x14]\n\
        ldrh r1, [r1]\n\
        lsrs r0, r1, #4\n\
        adds r0, #6\n\
    .L08076012:\n\
        cmp r4, r0\n\
        bge .L0807601E\n\
        ldr r0, .L08076058 @ =gUnk_0200CD38\n\
        ldrb r0, [r0]\n\
        cmp r4, r0\n\
        blt .L08075FF4\n\
    .L0807601E:\n\
        ldr r0, .L0807605C @ =gUnk_0200D53A\n\
        ldr r2, [sp, #8]\n\
        ldrb r1, [r2]\n\
        bl func_fe6_08076314\n\
        ldrb r0, [r5]\n\
        ldr r2, [sp, #8]\n\
        ldrb r1, [r2]\n\
        movs r2, #0\n\
        bl func_fe6_080763D8\n\
        movs r0, #0\n\
        ldr r1, [sp, #0x10]\n\
        strb r0, [r1]\n\
        strh r0, [r7, #0x3e]\n\
        adds r0, r7, #0\n\
        bl Proc_Break\n\
    .L08076042:\n\
        add sp, #0x18\n\
        pop {r3, r4, r5}\n\
        mov r8, r3\n\
        mov sb, r4\n\
        mov sl, r5\n\
        pop {r4, r5, r6, r7}\n\
        pop {r0}\n\
        bx r0\n\
        .align 2, 0\n\
    .L08076054: .4byte gUnk_0200CD3A\n\
    .L08076058: .4byte gUnk_0200CD38\n\
    .L0807605C: .4byte gUnk_0200D53A\n\
        .syntax divided\n");
}

#endif // NONMATCHING
