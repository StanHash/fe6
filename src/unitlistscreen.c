#include "unitlistscreen.h"

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "icon.h"
#include "sprite.h"
#include "event.h"
#include "msg.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "battle.h"
#include "bmio.h"
#include "chapter.h"
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

// TODO: clean up
// TODO: fix nonmatches

struct UnitListScreenSpritesProc;

struct UnitListScreenProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 unk_29;
    /* 2A */ u8 unk_2A;
    /* 2B */ u8 unk_2B;
    /* 2C */ u8 unk_2C;
    /* 2D */ u8 unk_2D;
    /* 2E */ u8 unk_2E;
    /* 2F */ u8 page;
    /* 30 */ u8 unk_30;
    /* 31 */ u8 unk_31;
    /* 32 */ u8 sort_key;
    /* 33 */ u8 target_sort_order; // idk which is which actually
    /* 34 */ u8 sort_order;
    /* 35 */ u8 unk_35;
    /* 36 */ u8 page_target;
    /* 37 */ u8 unk_37;
    /* 38 */ u8 unk_38;
    /* 39 */ u8 mode;
    /* 3A */ u8 unk_3A;
    /* 3B */ u8 unk_3B;
    /* 3C */ u8 unk_3C;
    /* 3D */ STRUCT_PAD(0x3D, 0x3E);
    /* 3E */ u16 unk_3E;
    /* 40 */ u16 unk_40;
    /* 42 */ STRUCT_PAD(0x42, 0x44);
    /* 44 */ struct UnitListScreenSpritesProc * sprites_proc;
    /* 48 */ ProcPtr unk_48;
};

void func_fe6_08076448(struct UnitListScreenProc * proc, fu8 unit_num, u16 * tm, fu8 page, bool put_name);

struct UnitListScreenSpritesProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct UnitListScreenProc * main_proc;
    /* 30 */ u8 unk_30;
    /* 34 */ ProcPtr unk_34;
    /* 38 */ u16 unk_38;
    /* 3A */ u8 unk_3A;
    /* 3B */ u8 unk_3B;
    /* 3C */ u8 unk_3C;
};

void func_fe6_08074EF0(struct UnitListScreenProc * proc);

struct SortedUnitEnt
{
    /* 00 */ struct Unit * unit;
    /* 04 */ i16 battle_attack;
    /* 06 */ i16 battle_hit;
    /* 08 */ i16 battle_avoid;
    /* 0A */ u8 support_talk_count;
};

extern struct SortedUnitEnt gSortedUnitsBuf[];
extern struct SortedUnitEnt * gSortedUnits[];

extern struct Text gUnk_0200D6AC;
extern struct Unit gUnk_0200D6B4[];
extern u8 gUnk_0200CD38;
extern u32 gUnk_0200E6B4[]; // equipped item icons
extern int gUnk_0200E7D8; // unit id

extern u8 CONST_DATA gUnk_08678722[];

extern u16 const * CONST_DATA gUnk_08678744[3];

struct UnitListScreenField
{
    /* 00 */ u8 sort_key;
    /* 01 */ STRUCT_PAD(0x01, 0x04);
    /* 04 */ char const * label_string;
    /* 08 */ u8 x_column;
    /* 09 */ STRUCT_PAD(0x09, 0x0C);
    /* 0C */ u32 msg_help;
};

extern struct UnitListScreenField UnitListPageFields[][9];

extern u16 CONST_DATA Sprite_08678750[]; // sprite
extern u16 const * CONST_DATA gUnk_08678818[]; // sprites
extern u16 CONST_DATA Sprite_08678758[]; // sprite
extern u16 CONST_DATA Sprite_08678760[]; // sprite

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
extern struct Text gUnk_0200D5F4[][3];
extern struct Text gUnk_0200D69C;
extern struct Text gUnk_0200D6A4;
extern struct Text gUnk_0200D6AC;

extern struct ProcScr CONST_DATA ProcScr_UnitListScreenSprites[];

enum
{
    BGPAL_UNITLIST_10 = 10, // ..13
    BGPAL_UNITLIST_15 = 15,
};

enum
{
    OBCHR_UNITLIST_240 = 0x240,
    OBCHR_UNITLIST_390 = 0x390,
};

enum
{
    OBPAL_UNITLIST_1 = 1, // ..4
    OBPAL_UNITLIST_9 = 9,
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
        UnitRearrangeAdd(gSortedUnits[i]->unit);
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

    PutSpriteExt(0x0D, x, y, gUnk_08678744[0], OAM2_PAL(5));

    for (i = 0; i < width - 1; i++)
    {
        PutSpriteExt(0x0D, x + i * 16 + 8, y, gUnk_08678744[1], OAM2_PAL(5));
    }

    PutSpriteExt(0x0D, x + i * 16 + 8, y, gUnk_08678744[2], OAM2_PAL(5));
}

void func_fe6_080742D0(fu8 sort_key)
{
    int i, j;

    TmFillRect(gBg2Tm + 0x34, 4, 1, 0);

    ClearText(&gUnk_0200D6AC);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (UnitListPageFields[i][j].sort_key == sort_key)
            {
                if (i == 5 && j != 0)
                {
                    PutIcon(gBg2Tm + 0x34, ICON_ITEM_KIND_BASE + j - 1, 0xA0 << 7);
                }
                else
                {
                    Text_SetCursor(&gUnk_0200D6AC, 0);
                    Text_SetColor(&gUnk_0200D6AC, TEXT_COLOR_SYSTEM_WHITE);
                    Text_DrawString(&gUnk_0200D6AC, UnitListPageFields[i][j].label_string);
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
        if (GetUnitEquippedWeapon(gSortedUnits[offset + i]->unit) != 0)
        {
            icons_to_display[i] = GetItemIcon(GetUnitEquippedWeapon(gSortedUnits[offset + i]->unit));
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

void func_fe6_08074558(struct UnitListScreenProc * proc, fi8 arg_1)
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
            if (UNIT_PID(gSortedUnits[i]->unit) == unit_id)
                goto found_unit;

            continue;
        }
        else
        {
            if (gSortedUnits[i]->unit->id == unit_id)
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

void func_fe6_08074778(struct UnitListScreenProc * proc)
{
    EndAllMus();
    Proc_End(proc->sprites_proc);
    Proc_End(proc->unk_48);
    EndGreenText();

    SetWinEnable(0, 0, 0);

    if (proc->mode == UNITLIST_MODE_PREPMENU)
    {
        SetStatScreenExcludedUnitFlags(UNIT_FLAG_DEAD);
    }
    else
    {
        SetStatScreenExcludedUnitFlags(UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED);
    }

    StartStatScreen(gSortedUnits[proc->unk_30]->unit, proc);

    gPlaySt.last_sort_key = (proc->sort_order << 7) + proc->sort_key;

    proc->unk_29 = 4;
}

void func_fe6_08074804(struct UnitListScreenProc * proc)
{
    func_fe6_08074EF0(proc);
    SetDispEnable(0, 0, 0, 0, 0);
}

void func_fe6_08074830(struct UnitListScreenProc * proc)
{
    SetDispEnable(1, 1, 1, 1, 1);
}

void UnitListScreenSprites_Init(struct UnitListScreenSpritesProc * proc)
{
    proc->main_proc = proc->proc_parent;
    proc->unk_3B = 0;
    proc->unk_3C = 0;
    proc->unk_38 = proc->main_proc->unk_40;
    proc->unk_3A = 0;
    proc->unk_30 = 0;
    proc->unk_34 = func_fe6_0808230C(proc);

    func_fe6_08082320(proc->unk_34, 0xE0, 0x40, 10, proc->main_proc->unk_40, gUnk_0200CD38, 6);

    ForceSyncUnitSpriteSheet();
}

void UnitListScreenSprites_Main(struct UnitListScreenSpritesProc * proc)
{
    fu8 r5;
    fi8 sl;
    fu8 i;

    u8 sp_0C[4] = { 0, 1, 2, 1 };

    if (proc->main_proc->sort_order == 0)
    {
        PutSpriteExt(0x0B, 0xB8, sp_0C[(proc->unk_3B / 8) % 4] + 7, Sprite_08678750, OAM2_PAL(9));
    }
    else
    {
        PutSpriteExt(0x0B, 0xB8 + 0x2000, sp_0C[(proc->unk_3B / 8) % 4] + 7, Sprite_08678750, OAM2_PAL(9));
    }

    PutSpriteExt(0x0D, 0x20, 0x08, gUnk_08678818[proc->main_proc->page], OAM2_PAL(9));
    PutSpriteExt(0x0D, 0xA0, 0, Sprite_08678758, OAM2_PAL(9));

    func_fe6_08082320(proc->unk_34, 0xE0, 0x40, 0x0A, proc->main_proc->unk_40, gUnk_0200CD38, 6);

    if (proc->main_proc->unk_29 > 2)
    {
        PutUiHand(
            UnitListPageFields[proc->main_proc->page][proc->main_proc->unk_2D].x_column,
            40 + proc->main_proc->unk_2C * 16);
    }
    else
    {
        PutSpriteExt(0x0D, 4, 0x40 + proc->main_proc->unk_2C * 16, Sprite_08678760, OAM2_PAL(9));
    }

    if (proc->unk_38 != proc->main_proc->unk_40 || (proc->main_proc->unk_40 % 0x10) != 0)
    {
        gPal[0x19E] = gUnk_02016874.unk_10;
        EnablePalSync();

        proc->unk_3C = 0x20;
        proc->unk_38 = proc->main_proc->unk_40;

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
        PutUnitSprite(4, 8, 56 + i * 16 + sl, gSortedUnits[i + r5]->unit);
    }

    if (proc->unk_3A != 0 && i + r5 < gUnk_0200CD38)
    {
        PutUnitSprite(4, 8, 56 + i * 16 + sl, gSortedUnits[i + r5]->unit);
    }

    if (proc->main_proc->page < proc->main_proc->unk_2E && proc->main_proc->mode != UNITLIST_MODE_SOLOANIM)
    {
        func_fe6_080744A0(1, proc->unk_30, 1);
    }
    else
    {
        func_fe6_080744A0(1, proc->unk_30, 0);
    }

    if (proc->main_proc->page > 1 && proc->main_proc->mode != UNITLIST_MODE_SOLOANIM)
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

void UnitListScreenSprites_Dummy(struct UnitListScreenSpritesProc * proc)
{
}

void func_fe6_08074BA4(struct UnitListScreenProc * proc)
{
    int support_count;
    fu8 i, support_now_count;

    FOR_UNITS_FACTION(gPlaySt.faction, unit,
    {
        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        if (proc->mode != UNITLIST_MODE_PREPMENU && (unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
            continue;

        if ((unit->flags & UNIT_FLAG_NOT_DEPLOYED) == 0)
            proc->unk_3B++;

        gSortedUnitsBuf[gUnk_0200CD38].unit = unit;

        BattleGenerateDisplayStats(unit, -1);

        gSortedUnitsBuf[gUnk_0200CD38].battle_attack = ((gBattleUnitA.battle_attack + 1) & 0xFF) - 1;
        gSortedUnitsBuf[gUnk_0200CD38].battle_hit = ((gBattleUnitA.battle_hit + 1) & 0xFF) - 1;
        gSortedUnitsBuf[gUnk_0200CD38].battle_avoid = ((gBattleUnitA.battle_avoid + 1) & 0xFF) - 1;

        support_count = GetUnitSupportCount(unit);
        support_now_count = 0;

        for (i = 0; i < support_count; i++)
        {
            if (CanUnitSupportNow(unit, i))
                support_now_count++;
        }

        if (support_now_count > 3)
            proc->unk_2E = 6 + (support_now_count - 1) / 3;

        gSortedUnitsBuf[gUnk_0200CD38].support_talk_count = support_now_count;
        gSortedUnits[gUnk_0200CD38] = &gSortedUnitsBuf[gUnk_0200CD38];

        gUnk_0200CD38++;

        UseUnitSprite(GetUnitMapSprite(unit));
    })
}

void func_fe6_08074D54(struct UnitListScreenProc * proc)
{
    // this function is identical to func_fe6_08074BA4
    // except it uses FACTION_BLUE instead of gPlaySt.faction

    int support_count;
    fu8 i, support_now_count;

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        if (proc->mode != UNITLIST_MODE_PREPMENU && (unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
            continue;

        if ((unit->flags & UNIT_FLAG_NOT_DEPLOYED) == 0)
            proc->unk_3B++;

        gSortedUnitsBuf[gUnk_0200CD38].unit = unit;

        BattleGenerateDisplayStats(unit, -1);

        gSortedUnitsBuf[gUnk_0200CD38].battle_attack = ((gBattleUnitA.battle_attack + 1) & 0xFF) - 1;
        gSortedUnitsBuf[gUnk_0200CD38].battle_hit = ((gBattleUnitA.battle_hit + 1) & 0xFF) - 1;
        gSortedUnitsBuf[gUnk_0200CD38].battle_avoid = ((gBattleUnitA.battle_avoid + 1) & 0xFF) - 1;

        support_count = GetUnitSupportCount(unit);
        support_now_count = 0;

        for (i = 0; i < support_count; i++)
        {
            if (CanUnitSupportNow(unit, i))
                support_now_count++;
        }

        if (support_now_count > 3)
            proc->unk_2E = 6 + (support_now_count - 1) / 3;

        gSortedUnitsBuf[gUnk_0200CD38].support_talk_count = support_now_count;
        gSortedUnits[gUnk_0200CD38] = &gSortedUnitsBuf[gUnk_0200CD38];

        gUnk_0200CD38++;

        UseUnitSprite(GetUnitMapSprite(unit));
    })
}

void func_fe6_08074EF0(struct UnitListScreenProc * proc)
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

    if (proc->mode != UNITLIST_MODE_PREPMENU || proc->unk_2A == 1)
    {
        thing = gPlaySt.last_sort_key;

        if (thing != 0)
        {
            proc->target_sort_order = (thing >> 7) & 1;
            proc->sort_order = proc->target_sort_order;
            proc->sort_key = thing & 0x7F;
        }

        if (proc->unk_29 != 4 && proc->page != 0)
        {
            thing = gPlaySt.last_unit_list_page;

            if (thing != 0)
            {
                if (thing > 6)
                    proc->page = 6;
                else
                    proc->page = thing;

                proc->page_target = proc->page;
            }
        }

        SortUnitList(proc->sort_key, proc->sort_order);
    }

    Decompress(gUnk_083198CC, OBJ_VRAM0 + OBCHR_UNITLIST_390 * CHR_SIZE);
    ApplyPalettes(gUnk_08319E88, 0x10 + OBPAL_UNITLIST_1, 3);

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    TmFill(gBg2Tm, 0);

    InitIcons();
    ApplyIconPalettes(4);
    UnpackUiWindowFrameGraphics();
    Decompress(gUnk_083215B8, OBJ_VRAM0 + OBCHR_UNITLIST_240 * CHR_SIZE);
    ApplyPalette(gUnk_08321EE4, 0x10 + OBPAL_UNITLIST_9);

    func_fe6_08082CBC();
    TmApplyTsa(gBg1Tm, gUnk_083210A0, TILEREF(0, BGPAL_WINDOWFRAME));

    for (i = 0; i < 7 ; i++)
    {
        InitText(&gUnk_0200D5BC[i], 5);
        InitTextDb(&gUnk_0200D5F4[i][0], 7);
        InitText(&gUnk_0200D5F4[i][1], 7);
        InitText(&gUnk_0200D5F4[i][2], 5);
    }

    InitText(&gUnk_0200D69C, 4);
    InitText(&gUnk_0200D6A4, 20);
    InitText(&gUnk_0200D6AC, 4);

    func_fe6_080742D0(proc->sort_key);

    if (proc->unk_29 == 4)
    {
        func_fe6_08074558(proc, 0);
        proc->unk_29 = 0;
    }
    else
    {
        if (proc->mode == UNITLIST_MODE_PREPMENU)
            func_fe6_08074558(proc, 1);
    }

    proc->unk_3E = 0;
    proc->unk_2B = 0;

    ClearText(&gUnk_0200D69C);
    Text_SetCursor(&gUnk_0200D69C, 0);
    Text_SetColor(&gUnk_0200D69C, 0);
    Text_DrawString(&gUnk_0200D69C, JTEXT("名　前"));
    PutText(&gUnk_0200D69C, gBg2Tm + TM_OFFSET(3, 5));

    for (i = 0; i < 20; i++)
    {
        gUnk_0200E6B4[i] = UINT8_MAX;
    }

    for (i = proc->unk_40 / 16; i < proc->unk_40 / 16 + 6 && i < gUnk_0200CD38; i++)
    {
        func_fe6_08076448(proc, i, gBg0Tm, proc->page, TRUE);
    }

    func_fe6_080763D8(proc->unk_2E, proc->page, TRUE);

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

    proc->sprites_proc = SpawnProc(ProcScr_UnitListScreenSprites, proc);

    if (proc->mode == UNITLIST_MODE_PREPMENU && proc->unk_3C == 0)
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

void func_fe6_08075338(struct UnitListScreenProc * proc)
{
    proc->unk_29 = 0;
    proc->unk_31 = 1;
    proc->unk_2C = 0;
    proc->unk_2D = 0;
    proc->unk_30 = 0;

    if (proc->mode == UNITLIST_MODE_SOLOANIM)
        proc->page = UNITLIST_PAGE_SOLOANIM;
    else
        proc->page = UNITLIST_PAGE_1;

    proc->page_target = proc->page;
    proc->unk_40 = 0;
    proc->sort_key = 1;
    proc->unk_2A = 0;
    proc->target_sort_order = 1;
    proc->sort_order = 0;
    proc->unk_35 = 0;

    func_fe6_08074EF0(proc);
}

void func_fe6_080753A0(struct UnitListScreenProc * proc)
{
    fu8 idx = proc->unk_30;

    if ((gSortedUnits[idx]->unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
    {
        if (proc->unk_3C == 0 || func_fe6_08082B74(gSortedUnits[idx]->unit))
        {
            if (proc->unk_3A > proc->unk_3B)
            {
                gSortedUnits[idx]->unit->flags &= ~(UNIT_FLAG_TURN_ENDED | UNIT_FLAG_NOT_DEPLOYED);
                func_fe6_080791B4(UNIT_PID(gSortedUnits[idx]->unit));
                proc->unk_3B++;
                PlaySe(SONG_6A);
                func_fe6_08076448(proc, idx, gBg0Tm, proc->page, TRUE);
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
        if (proc->unk_3C != 0 || !func_fe6_08079404(gSortedUnits[idx]->unit))
        {
            gSortedUnits[idx]->unit->flags |= UNIT_FLAG_TURN_ENDED | UNIT_FLAG_NOT_DEPLOYED;
            func_fe6_080791DC(UNIT_PID(gSortedUnits[idx]->unit));
            PlaySe(SONG_6B);
            proc->unk_3B--;
            func_fe6_08076448(proc, idx, gBg0Tm, proc->page, TRUE);
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

void func_fe6_08075570(struct UnitListScreenProc * proc)
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
                switch (proc->mode)
                {
                    case UNITLIST_MODE_PREPMENU:
                        func_fe6_080753A0(proc);
                        break;

                    case UNITLIST_MODE_SOLOANIM:
                        func_fe6_080754F4(gSortedUnits[proc->unk_30]->unit, 1);
                        func_fe6_08076448(proc, proc->unk_30, gBg0Tm, proc->page, FALSE);
                        break;

                    case UNITLIST_MODE_FIELD:
                        SetStatScreenLastUnitId(gSortedUnits[proc->unk_30]->unit->id);
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
                if (proc->mode == UNITLIST_MODE_SOLOANIM)
                {
                    if ((gKeySt->pressed & KEY_DPAD_LEFT) == 0)
                        break;

                    func_fe6_080754F4(gSortedUnits[proc->unk_30]->unit, -1);
                    func_fe6_08076448(proc, proc->unk_30, gBg0Tm, proc->page, 0);

                    break;
                }

                if (proc->page < 2)
                    break;

                proc->page_target--;
                Proc_Goto(proc, 2);
                proc->unk_2D = 0;
                PlaySe(SONG_6F);

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_RIGHT) != 0)
            {
                if (proc->mode == UNITLIST_MODE_SOLOANIM)
                {
                    if ((gKeySt->pressed & KEY_DPAD_RIGHT) == 0)
                        break;

                    func_fe6_080754F4(gSortedUnits[proc->unk_30]->unit, +1);
                    func_fe6_08076448(proc, proc->unk_30, gBg0Tm, proc->page, 0);

                    break;
                }

                if (proc->page < proc->unk_2E)
                {
                    proc->page_target++;
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

                        func_fe6_08076448(proc, proc->unk_40 / 16 - 1, gBg0Tm, proc->page, 1);
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
                        func_fe6_08076448(proc, 6 + proc->unk_40 / 16, gBg0Tm, proc->page, 1);
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
                var_08 = proc->sort_key;

                proc->unk_2A = 1;
                PlaySe(SONG_6A);
                proc->sort_key = UnitListPageFields[proc->page][proc->unk_2D].sort_key;
                proc->target_sort_order = (proc->target_sort_order + 1) & 1;

                if (SortUnitList(proc->sort_key, proc->target_sort_order))
                {
                    for (i = 0; i < 6 && i < gUnk_0200CD38; i++)
                    {
                        func_fe6_08076448(proc, i, gBg0Tm, proc->page, 1);
                    }

                    func_fe6_080743C8(proc->unk_40);
                    EnableBgSync(1);
                }

                proc->sort_order = proc->target_sort_order;
                proc->unk_35 = proc->unk_2D;
                
                if (proc->sort_key != var_08)
                    func_fe6_080742D0(proc->sort_key);

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_DOWN) != 0 && proc->unk_2B == 0)
            {
                PlaySe(SONG_66);
                proc->target_sort_order = 1;
                proc->unk_29 = 0;
                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_LEFT) != 0)
            {
                proc->target_sort_order = 1;

                if (proc->unk_2D == 0)
                {
                    if (proc->page < 2)
                        break;

                    if (proc->mode == UNITLIST_MODE_SOLOANIM)
                        break;

                    PlaySe(SONG_6F);
                    proc->page_target--;

                    for (i = 8; i > 0 && UnitListPageFields[proc->page_target][i].x_column == 0; i--)
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
                proc->target_sort_order = 1;

                if (proc->unk_2D == 8 || UnitListPageFields[proc->page][proc->unk_2D + 1].x_column == 0)
                {
                    if (proc->page < proc->unk_2E)
                    {
                        if (proc->mode == UNITLIST_MODE_SOLOANIM)
                            break;
    
                        proc->unk_2D = 0;
                        PlaySe(SONG_6F);
    
                        proc->page_target++;
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
                    UnitListPageFields[proc->page][proc->unk_2D].x_column, 0x28,
                    UnitListPageFields[proc->page][proc->unk_2D].msg_help);
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
            UnitListPageFields[proc->page_target][proc->unk_2D].x_column, 0x28,
            UnitListPageFields[proc->page_target][proc->unk_2D].msg_help);
    }
}

void func_fe6_08075D34(struct UnitListScreenProc * proc)
{
    if (proc->mode == UNITLIST_MODE_PREPMENU)
    {
        gUnk_0200E7D8 = UNIT_PID(gSortedUnits[proc->unk_30]->unit);
        func_fe6_080741EC();
    }

    gPlaySt.last_sort_key = (proc->sort_order << 7) + proc->sort_key;

    if (proc->page != UNITLIST_PAGE_SOLOANIM)
        gPlaySt.last_unit_list_page = proc->page;

    Proc_End(proc->sprites_proc);

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

void func_fe6_08075DF8(struct UnitListScreenProc * proc)
{
    int i;

    TmFillRect(gUnk_0200CD3A, 31, 31, 0);

    for (i = proc->unk_40 / 16; i < proc->unk_40 / 16 + 6 && i < gUnk_0200CD38; i++)
    {
        func_fe6_08076448(proc, i, gUnk_0200CD3A, proc->page, 0);
    }

    TmFillRect(gUnk_0200D53A, 31, 1, 0);

    func_fe6_08076314(gUnk_0200D53A, proc->page);

    proc->unk_3E = 0;
    proc->unk_37 = proc->page;
    proc->unk_38 = 0;
}

#if NONMATCHING

void func_fe6_08075E94(struct UnitListScreenProc * proc)
{
    int r4, i;

    proc->unk_38 += gUnk_0867871C[proc->unk_3E];

    if (proc->unk_38 > 20)
        proc->unk_38 = 20;

    proc->unk_3E++;

    for (i = 0; i < 20; i++)
    { 
        fu8 r1;

        if (proc->page_target > proc->page)
        {
            // permuter found that idk though
            proc->sort_key = proc->sort_key;

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

    proc->page = proc->page_target;

    TmFillRect(gBg2Tm+0x150/2, 0x16, 1, 0);
    TmFillRect(gBg0Tm+0x10/2, 0x16, 0x1F, 0);

    for (r4 = 0; r4 < 20; r4++)
        gUnk_0200E6B4[r4] = UINT8_MAX;

    ClearIcons();
    func_fe6_080742D0(proc->sort_key);

    for (r4 = proc->unk_40 / 16; r4 < proc->unk_40 / 16 + 6 && r4 < gUnk_0200CD38; r4++)
    {
        func_fe6_08076448(proc, r4, gUnk_0200CD3A, proc->page, 0);
    }

    func_fe6_08076314(gUnk_0200D53A, proc->page);
    func_fe6_080763D8(proc->unk_2E, proc->page, 0);

    proc->unk_38 = 0;
    proc->unk_3E = 0;

    Proc_Break(proc);
}

#else

NAKEDFUNC
void func_fe6_08075E94(struct UnitListScreenProc * proc)
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

#if NONMATCHING

void func_fe6_08076060(struct UnitListScreenProc * proc)
{
    int r5, r4;
    fu8 r1;

    proc->unk_38 += gUnk_08678722[proc->unk_3E];

    if (proc->unk_38 > 20)
        proc->unk_38 = 20;

    proc->unk_3E++;

    if (proc->page_target > proc->unk_37)
    {
        for (r5 = 0; r5 < proc->unk_38; r5++)
        {    
            for (r4 = proc->unk_40 / 8; r4 < 12 + proc->unk_40 / 8; r4++)
            {
                gBg0Tm[r5 + 0x1C + (r4 & 0x1F) * 0x20 - proc->unk_38] = *(r5 + 8 + (r4 & 0x1F) * 0x20 + gUnk_0200CD3A);
            }

            for (r4 = 0; r4 < 2; r4++)
            {
                gBg2Tm[r5 + 0x1C - proc->unk_38 + r4 * 0x20 + 0xA0] = *(gUnk_0200D53A + r5 + 8 + r4 * 0x20);
            }
        }
    }
    else
    {
        for (r5 = 0; r5 < proc->unk_38; r5++)
        {    
            for (r4 = proc->unk_40 / 8; r4 < 12 + proc->unk_40 / 8; r4++)
            {
                gBg0Tm[(((r4 & 0x1F) << 5) + 8) + r5] = *((r5 + 0x1C - proc->unk_38) + (r4 & 0x1F) * 0x20 + gUnk_0200CD3A);
            }

            for (r4 = 0; r4 < 2; r4++)
            {
                gBg2Tm[0xA8 + TM_OFFSET(r5, r4)] = *(gUnk_0200D53A + (r5 + 0x1C - proc->unk_38) + r4 * 0x20);
            }
        }
    }

    EnableBgSync(BG0_SYNC_BIT | BG2_SYNC_BIT);

    if (proc->unk_38 >= 20)
        Proc_Break(proc);
}

#else // NONMATCHING

NAKEDFUNC
void func_fe6_08076060(struct UnitListScreenProc * proc)
{
    // https://decomp.me/scratch/j9zM3

    asm(".syntax unified\n\
        push {r4, r5, r6, r7, lr}\n\
        mov r7, sl\n\
        mov r6, sb\n\
        mov r5, r8\n\
        push {r5, r6, r7}\n\
        sub sp, #0x18\n\
        str r0, [sp]\n\
        adds r2, r0, #0\n\
        adds r2, #0x38\n\
        ldr r0, .L08076150 @ =gUnk_08678722\n\
        ldr r1, [sp]\n\
        ldrh r1, [r1, #0x3e]\n\
        adds r0, r1, r0\n\
        ldrb r3, [r2]\n\
        ldrb r0, [r0]\n\
        adds r0, r3, r0\n\
        strb r0, [r2]\n\
        lsls r0, r0, #0x18\n\
        lsrs r0, r0, #0x18\n\
        cmp r0, #0x14\n\
        bls .L0807608E\n\
        movs r0, #0x14\n\
        strb r0, [r2]\n\
    .L0807608E:\n\
        ldr r5, [sp]\n\
        ldrh r0, [r5, #0x3e]\n\
        adds r0, #1\n\
        strh r0, [r5, #0x3e]\n\
        adds r0, r5, #0\n\
        adds r0, #0x36\n\
        adds r1, r5, #0\n\
        adds r1, #0x37\n\
        ldrb r0, [r0]\n\
        ldrb r1, [r1]\n\
        cmp r0, r1\n\
        bls .L08076164\n\
        movs r5, #0\n\
        str r2, [sp, #8]\n\
        ldrb r6, [r2]\n\
        cmp r5, r6\n\
        blt .L080760B2\n\
        b .L08076202\n\
    .L080760B2:\n\
        ldr r7, [sp]\n\
        adds r7, #0x40\n\
        str r7, [sp, #4]\n\
        str r2, [sp, #0x10]\n\
    .L080760BA:\n\
        ldr r0, [sp, #4]\n\
        ldrh r0, [r0]\n\
        lsrs r4, r0, #3\n\
        adds r0, r4, #0\n\
        adds r0, #0xc\n\
        adds r6, r5, #0\n\
        adds r6, #0x1c\n\
        movs r1, #8\n\
        adds r1, r1, r5\n\
        mov ip, r1\n\
        adds r5, #1\n\
        mov sb, r5\n\
        cmp r4, r0\n\
        bge .L08076116\n\
        str r6, [sp, #0xc]\n\
        ldr r2, .L08076154 @ =gUnk_0200CD3A\n\
        mov sl, r2\n\
        lsls r1, r1, #1\n\
        str r1, [sp, #0x14]\n\
        movs r3, #0x1f\n\
        mov r8, r3\n\
    .L080760E4:\n\
        adds r3, r4, #0\n\
        mov r5, r8\n\
        ands r3, r5\n\
        lsls r1, r3, #5\n\
        ldr r2, [sp, #0xc]\n\
        ldr r7, [sp, #0x10]\n\
        ldrb r7, [r7]\n\
        subs r0, r2, r7\n\
        adds r1, r1, r0\n\
        lsls r1, r1, #1\n\
        ldr r0, .L08076158 @ =gBg0Tm\n\
        adds r1, r1, r0\n\
        lsls r0, r3, #6\n\
        ldr r2, [sp, #0x14]\n\
        adds r0, r2, r0\n\
        add r0, sl\n\
        ldrh r0, [r0]\n\
        strh r0, [r1]\n\
        adds r4, #1\n\
        ldr r3, [sp, #4]\n\
        ldrh r3, [r3]\n\
        lsrs r0, r3, #3\n\
        adds r0, #0xc\n\
        cmp r4, r0\n\
        blt .L080760E4\n\
    .L08076116:\n\
        ldr r5, .L0807615C @ =gBg2Tm\n\
        mov r8, r5\n\
        adds r5, r6, #0\n\
        mov r6, ip\n\
        lsls r0, r6, #1\n\
        ldr r7, .L08076160 @ =gUnk_0200D53A\n\
        adds r2, r0, r7\n\
        movs r3, #0xa0\n\
        movs r4, #1\n\
    .L08076128:\n\
        ldr r1, [sp, #0x10]\n\
        ldrb r1, [r1]\n\
        subs r0, r5, r1\n\
        adds r0, r3, r0\n\
        lsls r0, r0, #1\n\
        add r0, r8\n\
        ldrh r1, [r2]\n\
        strh r1, [r0]\n\
        adds r2, #0x40\n\
        adds r3, #0x20\n\
        subs r4, #1\n\
        cmp r4, #0\n\
        bge .L08076128\n\
        mov r5, sb\n\
        ldr r2, [sp, #0x10]\n\
        ldrb r2, [r2]\n\
        cmp r5, r2\n\
        blt .L080760BA\n\
        b .L08076202\n\
        .align 2, 0\n\
    .L08076150: .4byte gUnk_08678722\n\
    .L08076154: .4byte gUnk_0200CD3A\n\
    .L08076158: .4byte gBg0Tm\n\
    .L0807615C: .4byte gBg2Tm\n\
    .L08076160: .4byte gUnk_0200D53A\n\
    .L08076164:\n\
        movs r5, #0\n\
        str r2, [sp, #8]\n\
        ldrb r3, [r2]\n\
        cmp r5, r3\n\
        bge .L08076202\n\
        ldr r6, [sp]\n\
        adds r6, #0x40\n\
        mov sl, r6\n\
        str r2, [sp, #0x10]\n\
    .L08076176:\n\
        mov r7, sl\n\
        ldrh r7, [r7]\n\
        lsrs r4, r7, #3\n\
        adds r0, r4, #0\n\
        adds r0, #0xc\n\
        adds r6, r5, #0\n\
        adds r6, #0x1c\n\
        adds r1, r5, #1\n\
        mov sb, r1\n\
        cmp r4, r0\n\
        bge .L080761CC\n\
        mov ip, r6\n\
        movs r2, #0x1f\n\
        mov r8, r2\n\
    .L08076192:\n\
        adds r3, r4, #0\n\
        mov r7, r8\n\
        ands r3, r7\n\
        lsls r2, r3, #5\n\
        adds r2, #8\n\
        adds r2, r2, r5\n\
        lsls r2, r2, #1\n\
        ldr r0, .L08076228 @ =gBg0Tm\n\
        adds r2, r2, r0\n\
        str r2, [sp, #0x14]\n\
        mov r2, ip\n\
        ldr r1, [sp, #0x10]\n\
        ldrb r1, [r1]\n\
        subs r0, r2, r1\n\
        lsls r0, r0, #1\n\
        lsls r1, r3, #6\n\
        adds r0, r0, r1\n\
        ldr r2, .L0807622C @ =gUnk_0200CD3A\n\
        adds r0, r0, r2\n\
        ldrh r0, [r0]\n\
        ldr r3, [sp, #0x14]\n\
        strh r0, [r3]\n\
        adds r4, #1\n\
        mov r7, sl\n\
        ldrh r7, [r7]\n\
        lsrs r0, r7, #3\n\
        adds r0, #0xc\n\
        cmp r4, r0\n\
        blt .L08076192\n\
    .L080761CC:\n\
        movs r4, #0\n\
        ldr r0, .L08076230 @ =gUnk_0200D53A\n\
        mov ip, r0\n\
        adds r3, r6, #0\n\
        adds r0, r5, #0\n\
        adds r0, #0xa8\n\
        lsls r0, r0, #1\n\
        ldr r1, .L08076234 @ =gBg2Tm\n\
        adds r2, r0, r1\n\
    .L080761DE:\n\
        ldr r5, [sp, #0x10]\n\
        ldrb r5, [r5]\n\
        subs r0, r3, r5\n\
        lsls r0, r0, #1\n\
        lsls r1, r4, #6\n\
        adds r0, r0, r1\n\
        add r0, ip\n\
        ldrh r0, [r0]\n\
        strh r0, [r2]\n\
        adds r2, #0x40\n\
        adds r4, #1\n\
        cmp r4, #1\n\
        ble .L080761DE\n\
        mov r5, sb\n\
        ldr r6, [sp, #0x10]\n\
        ldrb r6, [r6]\n\
        cmp r5, r6\n\
        blt .L08076176\n\
    .L08076202:\n\
        movs r0, #5\n\
        bl EnableBgSync\n\
        ldr r7, [sp, #8]\n\
        ldrb r7, [r7]\n\
        cmp r7, #0x13\n\
        bls .L08076216\n\
        ldr r0, [sp]\n\
        bl Proc_Break\n\
    .L08076216:\n\
        add sp, #0x18\n\
        pop {r3, r4, r5}\n\
        mov r8, r3\n\
        mov sb, r4\n\
        mov sl, r5\n\
        pop {r4, r5, r6, r7}\n\
        pop {r0}\n\
        bx r0\n\
        .align 2, 0\n\
    .L08076228: .4byte gBg0Tm\n\
    .L0807622C: .4byte gUnk_0200CD3A\n\
    .L08076230: .4byte gUnk_0200D53A\n\
    .L08076234: .4byte gBg2Tm\n\
        .syntax divided");
}

#endif // NONMATCHING

struct ProcScr CONST_DATA ProcScr_UnitListScreen[] =
{
    PROC_19,
    PROC_CALL(LockGame),

    PROC_CALL(StartFastFadeToBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(LockBmDisplay),

    PROC_CALL(func_fe6_08075338),

    PROC_CALL(StartFastFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

PROC_LABEL(1),
    PROC_REPEAT(func_fe6_08075570),

    PROC_CALL(StartFastFadeToBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(func_fe6_08075D34),

    PROC_CALL(UnlockBmDisplay),
    PROC_CALL(InitBmDisplay),
    PROC_CALL(EndAllMus),
    PROC_CALL(StartFastFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(UnlockGame),
    PROC_GOTO(4),

PROC_LABEL(2),
    PROC_CALL(func_fe6_08075DF8),
    PROC_REPEAT(func_fe6_08075E94),
    PROC_REPEAT(func_fe6_08076060),
    PROC_GOTO(1),

PROC_LABEL(3),
    PROC_CALL(func_fe6_08074778),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08074804),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08074830),
    PROC_GOTO(1),

PROC_LABEL(4),
    PROC_END,
};

void StartUnitListScreen(void)
{
    struct UnitListScreenProc * proc;

    proc = SpawnProc(ProcScr_UnitListScreen, PROC_TREE_3);
    proc->mode = UNITLIST_MODE_FIELD;
}

struct ProcScr CONST_DATA gUnk_08678594[] =
{
    PROC_19,
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08075338),
    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),
PROC_LABEL(1),
    PROC_REPEAT(func_fe6_08075570),
    PROC_CALL(StartMidFadeToBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(func_fe6_08075D34),
    PROC_GOTO(4),
PROC_LABEL(2),
    PROC_CALL(func_fe6_08075DF8),
    PROC_REPEAT(func_fe6_08075E94),
    PROC_REPEAT(func_fe6_08076060),
    PROC_GOTO(1),
PROC_LABEL(3),
    PROC_CALL(func_fe6_08074778),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08074804),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08074830),
    PROC_GOTO(1),
PROC_LABEL(4),
    PROC_END,
};

void func_fe6_08076250(ProcPtr parent)
{
    struct UnitListScreenProc * proc;

    if (parent == NULL)
    {
        proc = SpawnProc(gUnk_08678594, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(gUnk_08678594, parent);
    }

    proc->mode = UNITLIST_MODE_PREPMENU;

    if (func_fe6_08036984() == 1)
    {
        proc->unk_3C = 1;
        proc->unk_3A = 5;
    }
    else
    {
        proc->unk_3C = 0;
        proc->unk_3A = GetPlayerMaxDeployCount();
    }

    proc->unk_3B = 0;
}

struct ProcScr CONST_DATA gUnk_0867865C[] =
{
    PROC_SLEEP(0),
    PROC_CALL(func_fe6_08075338),
    PROC_CALL(StartFastFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),
PROC_LABEL(1),
    PROC_REPEAT(func_fe6_08075570),
    PROC_CALL(StartFastFadeToBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(func_fe6_08075D34),
    PROC_GOTO(4),
PROC_LABEL(3),
    PROC_CALL(func_fe6_08074778),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08074804),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08074830),
    PROC_GOTO(1),
PROC_LABEL(4),
    PROC_END,
};

void func_fe6_080762B4(ProcPtr parent)
{
    struct UnitListScreenProc * proc;

    if (parent == NULL)
    {
        proc = SpawnProc(gUnk_0867865C, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(gUnk_0867865C, parent);
    }

    proc->mode = UNITLIST_MODE_SOLOANIM;
}

void func_fe6_080762E4(ProcPtr parent)
{
    struct UnitListScreenProc * proc;

    if (parent == NULL)
    {
        proc = SpawnProc(gUnk_08678594, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(gUnk_08678594, parent);
    }

    proc->mode = UNITLIST_MODE_4;
}

void func_fe6_08076314(u16 * tm, fu8 page)
{
    fu8 i;

    TmFillRect(tm + 9, 0x13, 1, 0);

    ClearText(&gUnk_0200D6A4);

    if (page == UNITLIST_PAGE_WEXP)
    {
        for (i = 0; i < 8; i++)
        {
            PutIcon(tm + 9 + 2 * i, ICON_ITEM_KIND_BASE + i, TILEREF(0, BGPAL_ICONS + 1));
        }
    }
    else
    {
        for (i = 1; i < 9 && UnitListPageFields[page][i].x_column != 0; i++)
        {
            Text_SetCursor(&gUnk_0200D6A4, UnitListPageFields[page][i].x_column - 0x40);
            Text_SetColor(&gUnk_0200D6A4, TEXT_COLOR_SYSTEM_WHITE);
            Text_DrawString(&gUnk_0200D6A4, UnitListPageFields[page][i].label_string);
        }
        
        PutText(&gUnk_0200D6A4, tm + 8);
    }

    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_080763D8(fu8 max_pages, fu8 page, bool arg_2)
{
    if (page != 0)
    {
        PutNumber(gBg2Tm + (0x74 / 2), TEXT_COLOR_SYSTEM_BLUE, page);
        PutSpecialChar(gBg2Tm + (0x74 / 2) + 1, TEXT_COLOR_SYSTEM_WHITE, TEXT_SPECIAL_SLASH);
        PutNumber(gBg2Tm + (0x74 / 2) + 2, TEXT_COLOR_SYSTEM_BLUE, max_pages);
    }
    else
    {
        TmFillRect(gBg1Tm + (0x32 / 2), 6, 3, 0);
        EnableBgSync(BG1_SYNC_BIT);
    }

    if (arg_2)
    {
        func_fe6_08076314(gBg2Tm + (0x140 / 2), page);
    }

    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_08076448(struct UnitListScreenProc * proc, fu8 unit_num, u16 * tm, fu8 page, bool put_name)
{
    fu8 inactive;
    fu8 i;
    fu8 num;
    int icon;

    // this is something permuter found, it matches but ugh
    int dummy_zero = 0;

    int row = unit_num % 7;
    int y = (unit_num * 2) & 0x1F;

    if ((gSortedUnits[unit_num]->unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
        inactive = TRUE;
    else
        inactive = FALSE;

    if (put_name != 0)
    {
        ClearText(&gUnk_0200D5BC[row]);
        Text_SetCursor(&gUnk_0200D5BC[row], 0);

        if (proc->unk_3C == 0 && proc->mode == UNITLIST_MODE_PREPMENU && func_fe6_08079404(gSortedUnits[unit_num]->unit))
        {
            Text_SetColor(&gUnk_0200D5BC[row], TEXT_COLOR_SYSTEM_GREEN);
        }
        else
        {
            Text_SetColor(&gUnk_0200D5BC[row], inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE);
        }

        Text_DrawString(&gUnk_0200D5BC[row], DecodeMsg(gSortedUnits[unit_num]->unit->pinfo->msg_name));
        PutText(&gUnk_0200D5BC[row], tm + y * 0x20 + 3);
    }

    ClearText(&gUnk_0200D5F4[row][0]);
    ClearText(&gUnk_0200D5F4[row][1]);

    TmFillRect(tm + y * 0x20 + 8, 0x18, 1, 0);

    switch (page)
    {
        case UNITLIST_PAGE_SOLOANIM:
            PutDrawText(&gUnk_0200D5F4[row][0], tm + y * 0x20 + 8, 0, 0, 0, DecodeMsg(gSortedUnits[unit_num]->unit->jinfo->msg_name));
            Text_SetColor(&gUnk_0200D5F4[row][1], inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE);

            if (GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit) == 0)
            {
                PutDrawText(&gUnk_0200D5F4[row][1], tm + y * 0x20 + 17, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, JTEXT("ーーーー"));
            }
            else
            {
                PutDrawText(&gUnk_0200D5F4[row][1], tm + y * 0x20 + 17, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, GetItemName(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit)));
                PutIcon(tm + y * 0x20 + 15, GetItemIcon(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit)), TILEREF(0, BGPAL_ICONS));
                func_fe6_08074384(GetItemIcon(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit)));
            }

            ClearText(&gUnk_0200D5F4[row][2]);

            if (gSortedUnits[unit_num]->unit->pinfo->id == PID_MERLINUS)
            {
                PutDrawText(&gUnk_0200D5F4[row][2], tm + y * 0x20 + 24, 1, 4, 0, JTEXT("オフ"));
            }
            else
            {
                switch (gSortedUnits[unit_num]->unit->flags & UNIT_FLAG_SOLOANIM)
                {
                    case UNIT_FLAG_SOLOANIM_1:
                        PutDrawText(&gUnk_0200D5F4[row][2], tm + y * 0x20 + 24, 4, 8, 0, JTEXT("１"));
                        break;

                    case UNIT_FLAG_SOLOANIM_2:
                        PutDrawText(&gUnk_0200D5F4[row][2], tm + y * 0x20 + 24, 4, 8, 0, JTEXT("２"));
                        break;

                    case 0:
                        PutDrawText(&gUnk_0200D5F4[row][2], tm + y * 0x20 + 24, 1, 4, 0, JTEXT("オフ"));
                        break;
                }
            }

            break;

        case UNITLIST_PAGE_1:
            // jinfo
            PutDrawText(&gUnk_0200D5F4[row][0], tm + y * 0x20 + 8, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, DecodeMsg(gSortedUnits[unit_num]->unit->jinfo->msg_name));

            // level
            PutNumberOrBlank(tm + y * 0x20 + 17, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE, gSortedUnits[unit_num]->unit->level);

            // exp
            PutNumberOrBlank(tm + y * 0x20 + 20, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE, gSortedUnits[unit_num]->unit->exp);

            // hp
            PutNumberOrBlank(tm + y * 0x20 + 23, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE, GetUnitCurrentHp(gSortedUnits[unit_num]->unit));
            PutSpecialChar(tm + y * 0x20 + 24, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0x16);
            PutNumberOrBlank(tm + y * 0x20 + 26, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE, GetUnitMaxHp(gSortedUnits[unit_num]->unit));

            break;

        case UNITLIST_PAGE_2:
            PutNumberOrBlank(tm + y * 0x20 + 9, UNIT_POW_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->pow ? 4 : 2, GetUnitPower(gSortedUnits[unit_num]->unit));
            PutNumberOrBlank(tm + y * 0x20 + 12, UNIT_SKL_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->skl ? 4 : 2, GetUnitSkill(gSortedUnits[unit_num]->unit));
            PutNumberOrBlank(tm + y * 0x20 + 15, UNIT_SPD_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->spd ? 4 : 2, GetUnitSpeed(gSortedUnits[unit_num]->unit));
            PutNumberOrBlank(tm + y * 0x20 + 18, UNIT_LCK_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->lck ? 4 : 2, GetUnitLuck(gSortedUnits[unit_num]->unit));
            PutNumberOrBlank(tm + y * 0x20 + 21, UNIT_DEF_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->def ? 4 : 2, GetUnitDefense(gSortedUnits[unit_num]->unit));
            PutNumberOrBlank(tm + y * 0x20 + 24, UNIT_RES_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->res ? 4 : 2, GetUnitResistance(gSortedUnits[unit_num]->unit));

            icon = GetUnitAffinityIcon(gSortedUnits[unit_num]->unit);

            if (icon == -1)
                PutSpecialChar(tm + y * 0x20 + 26, 2, TEXT_SPECIAL_DASH);
            else
                PutIcon(tm + y * 0x20 + 26, icon, TILEREF(0, BGPAL_ICONS + 1));

            break;

        case UNITLIST_PAGE_3:
            if (GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit) == 0)
            {
                PutDrawText(&gUnk_0200D5F4[row][0], tm + y * 0x20 + 10, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, JTEXT("ーーーー"));
            }
            else
            {
                char const * name = GetItemName(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit));

                PutDrawText(&gUnk_0200D5F4[row][0], tm + y * 0x20 + 10,
                    inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, dummy_zero, name);

                PutIcon(tm + y * 0x20 + 8, GetItemIcon(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit)), TILEREF(0, BGPAL_ICONS));
                func_fe6_08074384(GetItemIcon(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit)));
            }

            PutNumberOrBlank(tm + y * 0x20 + 18, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                gSortedUnits[unit_num]->battle_attack);

            PutNumberOrBlank(tm + y * 0x20 + 22, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                gSortedUnits[unit_num]->battle_hit);

            PutNumberOrBlank(tm + y * 0x20 + 26, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                gSortedUnits[unit_num]->battle_avoid);
            
            break;

        case UNITLIST_PAGE_4:
            if ((gSortedUnits[unit_num]->unit->flags & UNIT_FLAG_RESCUING) != 0)
            {
                PutDrawText(&gUnk_0200D5F4[row][1], tm + y * 0x20 + 18,
                    inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0,
                    GetUnitRescueName(gSortedUnits[unit_num]->unit));
            }
            else
            {
                PutDrawText(&gUnk_0200D5F4[row][1], tm + y * 0x20 + 18,
                    inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0,
                    JTEXT("ーーー"));
            }

            PutNumberOrBlank(tm + y * 0x20 + 10, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                UNIT_MOV(gSortedUnits[unit_num]->unit));

            PutNumberOrBlank(tm + y * 0x20 + 13, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                UNIT_CON(gSortedUnits[unit_num]->unit));

            PutNumberOrBlank(tm + y * 0x20 + 16, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                GetUnitAid(gSortedUnits[unit_num]->unit));

            PutDrawText(&gUnk_0200D5F4[row][0], tm + y * 0x20 + 23,
                inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0,
                GetUnitStatusName(gSortedUnits[unit_num]->unit));

            break;

        case UNITLIST_PAGE_WEXP:
        {
            for (i = 0; i < 8; i++)
            {
                int special_chars[] =
                {
                    [WPN_LEVEL_0] = TEXT_SPECIAL_DASH,
                    [WPN_LEVEL_E] = TEXT_SPECIAL_E,
                    [WPN_LEVEL_D] = TEXT_SPECIAL_D,
                    [WPN_LEVEL_C] = TEXT_SPECIAL_C,
                    [WPN_LEVEL_B] = TEXT_SPECIAL_B,
                    [WPN_LEVEL_A] = TEXT_SPECIAL_A,
                    [WPN_LEVEL_S] = TEXT_SPECIAL_S,
                };

                num = GetWeaponLevelFromExp(gSortedUnits[unit_num]->unit->wexp[i]);

                PutSpecialChar(tm + y * 0x20 + 10 + 2 * i,
                    num == WPN_LEVEL_S ? TEXT_COLOR_SYSTEM_GREEN : 2, special_chars[num]);
            }

            break;
        }

        default:
        {
            fu8 support_start;
            fu8 support_passed;
            int support_count;

            support_start = (page - UNITLIST_PAGE_SUPPORT) * 3;
            support_passed = 0;
            num = 0;
            support_count = GetUnitSupportCount(gSortedUnits[unit_num]->unit);

            ClearText(&gUnk_0200D5F4[row][2]);

            for (i = 0; i < support_count; i++)
            {
                if (CanUnitSupportNow(gSortedUnits[unit_num]->unit, i))
                {
                    if (support_passed >= support_start)
                    {
                        struct Unit * other = GetUnitSupportUnit(gSortedUnits[unit_num]->unit, i);
    
                        if ((other->flags & UNIT_FLAG_NOT_DEPLOYED) == 0)
                        {
                            char const * name = DecodeMsg(
                                GetPInfo(GetUnitSupportPid(gSortedUnits[unit_num]->unit, i))->msg_name);

                            PutDrawText(&gUnk_0200D5F4[row][num], tm + y * 0x20 + 9 + num * 6,
                                inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, name);
                        }
                        else
                        {
                            char const * name = DecodeMsg(
                                GetPInfo(GetUnitSupportPid(gSortedUnits[unit_num]->unit, i))->msg_name);

                            PutDrawText(&gUnk_0200D5F4[row][num], tm + y * 0x20 + 9 + num * 6,
                                TEXT_COLOR_SYSTEM_GRAY, 0, 0, name);
                        }
    
                        num++;
    
                        if (num == 3)
                            break;
                    }
                    else
                    {
                        support_passed++;
                    }
                }
            }

            for (; num < 3; num++)
            {
                PutDrawText(&gUnk_0200D5F4[row][num], tm + y * 0x20 + 9 + num * 6 ,
                    inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, JTEXT("ーーー"));
            }

            break;
        }
    }

    EnableBgSync(BG0_SYNC_BIT);
}

int func_fe6_08076D30(struct Unit * unit)
{
    return (unit->flags & UNIT_FLAG_SOLOANIM);
}

bool SortUnitList(fu8 key, fu8 order)
{
    u8 cache[0x40];

    order = order & 1;

    #define PREPARE_VARS \
        bool changed = FALSE; \
        fu8 i, j, tmp_cache; \
        void * tmp_addr;

    #define BUILD_CACHE(key) \
    { \
        for (i = 0; i < gUnk_0200CD38; i++) \
        { \
            cache[i] = key(i); \
        } \
    }

    #define RETURN_IF_CHANGED if (changed) return TRUE;

    #define SWAP(i, j) \
    { \
        tmp_addr = gSortedUnits[(i)]; \
        gSortedUnits[(i)] = gSortedUnits[(j)]; \
        gSortedUnits[(j)] = tmp_addr; \
    }

    #define SWAP_CACHE(i, j) \
    { \
        tmp_cache = cache[(i)]; \
        cache[(i)] = cache[(j)]; \
        cache[(j)] = tmp_cache; \
        SWAP(i, j) \
    }

    #define SORT_CORE(cond, swap) \
    { \
        /* this is a bubble sort, I think */ \
        for (i = 0; i < gUnk_0200CD38 - 1; i++) \
        { \
            for (j = 0; j < gUnk_0200CD38 - 1 - i; j++) \
            { \
                if (cond) \
                { \
                    /* swap */ \
                    swap(j, j + 1) \
                    changed = TRUE; \
                } \
            } \
        } \
    }

    #define SORT_CORE_KEY(key, arrow, swap) \
    { \
        /* this is a bubble sort, I think */ \
        for (i = 0; i < gUnk_0200CD38 - 1; i++) \
        { \
            for (j = 0; j < gUnk_0200CD38 - 1 - i; j++) \
            { \
                if (key(j + 1) arrow key(j)) \
                { \
                    /* swap */ \
                    swap(j, j + 1) \
                    changed = TRUE; \
                } \
            } \
        } \
    }

    #define SORT_REAL(cond_asc, cond_dsc) \
        if (order == 0) \
        { \
            PREPARE_VARS \
            SORT_CORE(cond_asc, SWAP) \
            RETURN_IF_CHANGED \
        } \
        else \
        { \
            PREPARE_VARS \
            SORT_CORE(cond_dsc, SWAP) \
            RETURN_IF_CHANGED \
        }

    #define SORT(cond) SORT_REAL(cond, !(cond))

    #define SORT_BY_KEY(key) \
        if (order == 0) \
        { \
            PREPARE_VARS \
            SORT_CORE_KEY(key, >, SWAP) \
            RETURN_IF_CHANGED \
        } \
        else \
        { \
            PREPARE_VARS \
            SORT_CORE_KEY(key, <, SWAP) \
            RETURN_IF_CHANGED \
        }

    #define SORT_MAIN(sort_a, sort_b) \
        if (order == 0) \
        { \
            PREPARE_VARS \
            sort_a \
            RETURN_IF_CHANGED \
        } \
        else \
        { \
            PREPARE_VARS \
            sort_b \
            RETURN_IF_CHANGED \
        } \
        break;

    #define SORT_BY_FUNC(func) \
        SORT_REAL(func(gSortedUnits[j + 1]->unit) > func(gSortedUnits[j]->unit), \
            func(gSortedUnits[j + 1]->unit) < func(gSortedUnits[j]->unit))

    #define SORT_BY_UNIT_FIELD(field) \
        SORT_REAL((gSortedUnits[j + 1]->unit->field) > (gSortedUnits[j]->unit->field), \
            (gSortedUnits[j + 1]->unit->field) < (gSortedUnits[j]->unit->field))

    switch (key)
    {
        case UNITLIST_SORTKEY_1:
            #define KEY_A(i) (gSortedUnits[(i)]->unit->pinfo->unk_0A)
            #define KEY_B(i) (gSortedUnits[(i)]->unit->flags & UNIT_FLAG_TURN_ENDED)

            SORT_MAIN(
                SORT_CORE_KEY(KEY_A, <, SWAP) SORT_CORE_KEY(KEY_B, <, SWAP),
                SORT_CORE_KEY(KEY_A, >, SWAP) SORT_CORE_KEY(KEY_B, >, SWAP))

            #undef KEY_B
            #undef KEY_A

        case UNITLIST_SORTKEY_3:
            #define KEY(i) (gSortedUnits[(i)]->unit->level)
            SORT_MAIN(SORT_CORE_KEY(KEY, >, SWAP), SORT_CORE_KEY(KEY, <, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_2:
            #define KEY(i) (gSortedUnits[(i)]->unit->jinfo->unk_0A)
            SORT_MAIN(SORT_CORE_KEY(KEY, <, SWAP), SORT_CORE_KEY(KEY, >, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_4:
            SORT_BY_UNIT_FIELD(exp)
            break;

        case UNITLIST_SORTKEY_5:
            SORT_BY_FUNC(GetUnitCurrentHp)
            break;

        case UNITLIST_SORTKEY_6:
            SORT_BY_FUNC(GetUnitMaxHp)
            break;

        case UNITLIST_SORTKEY_7:
            SORT_BY_FUNC(GetUnitPower)
            break;

        case UNITLIST_SORTKEY_8:
            SORT_BY_FUNC(GetUnitSkill)
            break;

        case UNITLIST_SORTKEY_9:
            SORT_BY_FUNC(GetUnitSpeed)
            break;

        case UNITLIST_SORTKEY_10:
            SORT_BY_FUNC(GetUnitLuck)
            break;

        case UNITLIST_SORTKEY_11:
            SORT_BY_FUNC(GetUnitDefense)
            break;

        case UNITLIST_SORTKEY_12:
            SORT_BY_FUNC(GetUnitResistance)
            break;

        case UNITLIST_SORTKEY_19:
            SORT_BY_FUNC(UNIT_CON)
            break;

        case UNITLIST_SORTKEY_20:
            SORT_BY_FUNC(GetUnitAid)
            break;

        case UNITLIST_SORTKEY_13:
            #define KEY(i) (GetUnitAffinityIcon(gSortedUnits[(i)]->unit))
            SORT_MAIN(SORT_CORE_KEY(KEY, <, SWAP), SORT_CORE_KEY(KEY, >, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_14:
            SORT_MAIN(
            {
                for (i = 0; i < gUnk_0200CD38; i++)
                {
                    cache[i] = GetItemIid(GetUnitEquippedWeapon(gSortedUnits[i]->unit));
                }

                for (i = 0; i < gUnk_0200CD38 - 1; i++)
                {
                    for (j = 0; j < gUnk_0200CD38 - 1 - i; j++)
                    {
                        if (cache[j + 1] > cache[j])
                        {
                            SWAP_CACHE(j, j + 1)
                            changed = TRUE;
                        }
                        else if (cache[j + 1] == cache[j] && GetUnitEquippedWeapon(gSortedUnits[j + 1]->unit) > GetUnitEquippedWeapon(gSortedUnits[j]->unit))
                        {
                            SWAP_CACHE(j, j + 1)
                            changed = TRUE;
                        }
                    }
                }
            },
            {
                for (i = 0; i < gUnk_0200CD38; i++)
                {
                    cache[i] = GetItemIid(GetUnitEquippedWeapon(gSortedUnits[i]->unit));
                }

                for (i = 0; i < gUnk_0200CD38 - 1; i++)
                {
                    for (j = 0; j < gUnk_0200CD38 - 1 - i; j++)
                    {
                        if (cache[j + 1] < cache[j])
                        {
                            SWAP_CACHE(j, j + 1)
                            changed = TRUE;
                        }
                        else if (cache[j + 1] == cache[j] && GetUnitEquippedWeapon(gSortedUnits[j + 1]->unit) < GetUnitEquippedWeapon(gSortedUnits[j]->unit))
                        {
                            SWAP_CACHE(j, j + 1)
                            changed = TRUE;
                        }
                    }
                }
            })

        case UNITLIST_SORTKEY_15:
            #define KEY(i) (gSortedUnits[(i)]->battle_attack)
            SORT_MAIN(SORT_CORE_KEY(KEY, >, SWAP), SORT_CORE_KEY(KEY, <, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_16:
            #define KEY(i) (gSortedUnits[(i)]->battle_hit)
            SORT_MAIN(SORT_CORE_KEY(KEY, >, SWAP), SORT_CORE_KEY(KEY, <, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_17:
            #define KEY(i) (gSortedUnits[(i)]->battle_avoid)
            SORT_MAIN(SORT_CORE_KEY(KEY, >, SWAP), SORT_CORE_KEY(KEY, <, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_18:
            SORT_BY_FUNC(UNIT_MOV)
            break;

        case UNITLIST_SORTKEY_21:
            SORT_BY_UNIT_FIELD(status)
            break;

        case UNITLIST_SORTKEY_22:
            SORT_MAIN(
            {
                for (i = 0; i < gUnk_0200CD38; i++)
                {
                    if ((gSortedUnits[i]->unit->flags & 0x10) != 0)
                        cache[i] = 1;
                    else
                        cache[i] = 0;
                }

                SORT_CORE(cache[j + 1] > cache[j], SWAP_CACHE)
            },
            {
                for (i = 0; i < gUnk_0200CD38; i++)
                {
                    if ((gSortedUnits[i]->unit->flags & 0x10) != 0)
                        cache[i] = 1;
                    else
                        cache[i] = 0;
                }

                SORT_CORE(cache[j + 1] < cache[j], SWAP_CACHE)
            })

        case UNITLIST_SORTKEY_23:
            SORT_BY_UNIT_FIELD(wexp[0])
            break;

        case UNITLIST_SORTKEY_24:
            SORT_BY_UNIT_FIELD(wexp[1])
            break;

        case UNITLIST_SORTKEY_25:
            SORT_BY_UNIT_FIELD(wexp[2])
            break;

        case UNITLIST_SORTKEY_26:
            SORT_BY_UNIT_FIELD(wexp[3])
            break;

        case UNITLIST_SORTKEY_27:
            SORT_BY_UNIT_FIELD(wexp[4])
            break;

        case UNITLIST_SORTKEY_28:
            SORT_BY_UNIT_FIELD(wexp[5])
            break;

        case UNITLIST_SORTKEY_29:
            SORT_BY_UNIT_FIELD(wexp[6])
            break;

        case UNITLIST_SORTKEY_30:
            SORT_BY_UNIT_FIELD(wexp[7])
            break;

        case UNITLIST_SORTKEY_31:
            #define KEY(i) (gSortedUnits[(i)]->support_talk_count)
            SORT_MAIN(SORT_CORE_KEY(KEY, >, SWAP), SORT_CORE_KEY(KEY, <, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_32:
            SORT_BY_FUNC(func_fe6_08076D30)
            break;
    }

    return FALSE;
}

// TODO: move data above funcs

struct ProcScr CONST_DATA ProcScr_UnitListScreenSprites[] =
{
    PROC_19,
    PROC_CALL(UnitListScreenSprites_Init),
    PROC_REPEAT(UnitListScreenSprites_Main),
    PROC_CALL(UnitListScreenSprites_Dummy),
    PROC_END,
};

u8 CONST_DATA gUnk_0867871C[] =
{
    0x5,
    0x4,
    0x4,
    0x3,
    0x3,
    0x2,
};

u8 CONST_DATA gUnk_08678722[] =
{
    0x5,
    0x4,
    0x3,
    0x2,
    0x2,
    0x2,
    0x1,
    0x1,
    0x1,
    0x0,
};

u16 CONST_DATA Sprite_0867872C[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x25C),
};

u16 CONST_DATA Sprite_08678734[] =
{
    1,
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x25D),
};

u16 CONST_DATA Sprite_0867873C[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x25F),
};

u16 const * CONST_DATA gUnk_08678744[] =
{
    Sprite_0867872C,
    Sprite_08678734,
    Sprite_0867873C,
};

u16 CONST_DATA Sprite_08678750[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x240),
};

u16 CONST_DATA Sprite_08678758[] =
{
    1,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8, OAM2_CHR(0x262) + OAM2_LAYER(2),
};

u16 CONST_DATA Sprite_08678760[] =
{
    7,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8, OAM2_CHR(0x242) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(32), OAM2_CHR(0x243) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(64), OAM2_CHR(0x243) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(96), OAM2_CHR(0x243) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(128), OAM2_CHR(0x243) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(160), OAM2_CHR(0x243) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(192), OAM2_CHR(0x244) + OAM2_LAYER(2),
};

u16 CONST_DATA Sprite_0867878C[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x280),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x284),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x288),
};

u16 CONST_DATA Sprite_086787A0[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x28C),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x290),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x294),
};

u16 CONST_DATA Sprite_086787B4[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x2C0),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x2C4),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x2C8),
};

u16 CONST_DATA Sprite_086787C8[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x2CC),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x2D0),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x2D4),
};

u16 CONST_DATA Sprite_086787DC[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x300),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x304),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x308),
};

u16 CONST_DATA Sprite_086787F0[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x24C),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x250),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x254),
};

u16 CONST_DATA Sprite_08678804[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x30D),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x311),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(64), OAM2_CHR(0x315),
};

u16 const * CONST_DATA gUnk_08678818[] =
{
    [UNITLIST_PAGE_SOLOANIM] = Sprite_08678804,
    [UNITLIST_PAGE_1] = Sprite_0867878C,
    [UNITLIST_PAGE_2] = Sprite_086787A0,
    [UNITLIST_PAGE_3] = Sprite_086787B4,
    [UNITLIST_PAGE_4] = Sprite_086787C8,
    [UNITLIST_PAGE_WEXP] = Sprite_086787DC,
    [UNITLIST_PAGE_SUPPORT + 0] = Sprite_086787F0,
    [UNITLIST_PAGE_SUPPORT + 1] = Sprite_086787F0,
    [UNITLIST_PAGE_SUPPORT + 2] = Sprite_086787F0,
    [UNITLIST_PAGE_SUPPORT + 3] = Sprite_086787F0,
};

struct UnitListScreenField UnitListPageFields[][9] =
{
    [UNITLIST_PAGE_SOLOANIM] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_2,
            .label_string = JTEXT("クラス"),
            .x_column = 0x48,
            .msg_help = MSG_592,
        },
        {
            .sort_key = UNITLIST_SORTKEY_14,
            .label_string = JTEXT("装備"),
            .x_column = 0x88,
            .msg_help = MSG_669,
        },
        {
            .sort_key = UNITLIST_SORTKEY_32,
            .label_string = JTEXT("アニメ"),
            .x_column = 0xC0,
            .msg_help = MSG_66C,
        },
    },
    [UNITLIST_PAGE_1] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_2,
            .label_string = JTEXT("クラス"),
            .x_column = 0x48,
            .msg_help = MSG_592,
        },
        {
            .sort_key = UNITLIST_SORTKEY_3,
            .label_string = JTEXT("ＬＶ"),
            .x_column = 0x80,
            .msg_help = MSG_593,
        },
        {
            .sort_key = UNITLIST_SORTKEY_4,
            .label_string = JTEXT("ＥＸ"),
            .x_column = 0x98,
            .msg_help = MSG_594,
        },
        {
            .sort_key = UNITLIST_SORTKEY_5,
            .label_string = JTEXT("ＨＰ"),
            .x_column = 0xB0,
            .msg_help = MSG_595,
        },
        {
            .sort_key = UNITLIST_SORTKEY_6,
            .label_string = JTEXT("ＭＨＰ"),
            .x_column = 0xC4,
            .msg_help = MSG_667,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_2] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_7,
            .label_string = JTEXT("力／魔"),
            .x_column = 0x40,
            .msg_help = MSG_668,
        },
        {
            .sort_key = UNITLIST_SORTKEY_8,
            .label_string = JTEXT("技"),
            .x_column = 0x60,
            .msg_help = MSG_59E,
        },
        {
            .sort_key = UNITLIST_SORTKEY_9,
            .label_string = JTEXT("速さ"),
            .x_column = 0x70,
            .msg_help = MSG_59F,
        },
        {
            .sort_key = UNITLIST_SORTKEY_10,
            .label_string = JTEXT("幸運"),
            .x_column = 0x88,
            .msg_help = MSG_5A6,
        },
        {
            .sort_key = UNITLIST_SORTKEY_11,
            .label_string = JTEXT("守備"),
            .x_column = 0xA0,
            .msg_help = MSG_5A0,
        },
        {
            .sort_key = UNITLIST_SORTKEY_12,
            .label_string = JTEXT("魔防"),
            .x_column = 0xB8,
            .msg_help = MSG_5A1,
        },
        {
            .sort_key = UNITLIST_SORTKEY_13,
            .label_string = JTEXT("属性"),
            .x_column = 0xCE,
            .msg_help = MSG_5A7,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_3] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_14,
            .label_string = JTEXT("装備"),
            .x_column = 0x50,
            .msg_help = MSG_669,
        },
        {
            .sort_key = UNITLIST_SORTKEY_15,
            .label_string = JTEXT("攻撃"),
            .x_column = 0x88,
            .msg_help = MSG_597,
        },
        {
            .sort_key = UNITLIST_SORTKEY_16,
            .label_string = JTEXT("命中"),
            .x_column = 0xA8,
            .msg_help = MSG_598,
        },
        {
            .sort_key = UNITLIST_SORTKEY_17,
            .label_string = JTEXT("回避"),
            .x_column = 0xC8,
            .msg_help = MSG_59B,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_4] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_18,
            .label_string = JTEXT("移動"),
            .x_column = 0x48,
            .msg_help = MSG_5A4,
        },
        {
            .sort_key = UNITLIST_SORTKEY_19,
            .label_string = JTEXT("体格"),
            .x_column = 0x60,
            .msg_help = MSG_5A2,
        },
        {
            .sort_key = UNITLIST_SORTKEY_20,
            .label_string = JTEXT("救出"),
            .x_column = 0x78,
            .msg_help = MSG_5A3,
        },
        {
            .sort_key = UNITLIST_SORTKEY_22,
            .label_string = JTEXT("同行"),
            .x_column = 0x94,
            .msg_help = MSG_5A5,
        },
        {
            .sort_key = UNITLIST_SORTKEY_21,
            .label_string = JTEXT("状態"),
            .x_column = 0xBC,
            .msg_help = MSG_66A,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_WEXP] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_23,
            .label_string = "",
            .x_column = 0x4C,
            .msg_help = MSG_62D,
        },
        {
            .sort_key = UNITLIST_SORTKEY_24,
            .label_string = "",
            .x_column = 0x5C,
            .msg_help = MSG_62E,
        },
        {
            .sort_key = UNITLIST_SORTKEY_25,
            .label_string = "",
            .x_column = 0x6C,
            .msg_help = MSG_62F,
        },
        {
            .sort_key = UNITLIST_SORTKEY_26,
            .label_string = "",
            .x_column = 0x7C,
            .msg_help = MSG_630,
        },
        {
            .sort_key = UNITLIST_SORTKEY_27,
            .label_string = "",
            .x_column = 0x8C,
            .msg_help = MSG_631,
        },
        {
            .sort_key = UNITLIST_SORTKEY_28,
            .label_string = "",
            .x_column = 0x9C,
            .msg_help = MSG_632,
        },
        {
            .sort_key = UNITLIST_SORTKEY_29,
            .label_string = "",
            .x_column = 0xAC,
            .msg_help = MSG_633,
        },
        {
            .sort_key = UNITLIST_SORTKEY_30,
            .label_string = "",
            .x_column = 0xBC,
            .msg_help = MSG_634,
        },
    },
    [UNITLIST_PAGE_SUPPORT + 0] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_31,
            .label_string = JTEXT("相手"),
            .x_column = 0x48,
            .msg_help = MSG_636,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_SUPPORT + 1] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_31,
            .label_string = JTEXT("相手"),
            .x_column = 0x48,
            .msg_help = MSG_636,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_SUPPORT + 2] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_31,
            .label_string = JTEXT("相手"),
            .x_column = 0x48,
            .msg_help = MSG_636,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_SUPPORT + 3] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_31,
            .label_string = JTEXT("相手"),
            .x_column = 0x48,
            .msg_help = MSG_636,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
};
