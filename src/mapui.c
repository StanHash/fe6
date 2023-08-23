#include "mapui.h"

#include "hardware.h"
#include "oam.h"
#include "armfunc.h"
#include "proc.h"
#include "icon.h"
#include "sprite.h"
#include "face.h"
#include "debugtext.h" // GenNumberStr, gNumberStr
#include "msg.h"
#include "util.h"
#include "unit.h"
#include "map.h"
#include "trap.h"
#include "bmfx.h"
#include "faction.h"
#include "ui.h"
#include "gamedata.h"

#include "constants/terrains.h"
#include "constants/videoalloc_global.h"

i8 CONST_DATA gUnitBurstMapUiTextXTable[] =
{
    +1, +1, +1,
    +1, +1, +1,
};

i8 CONST_DATA gUnitBurstMapUiTextYTable[] =
{
    +1, +1, +1,
    +1, +1, +1,
};

i8 CONST_DATA unused_08678134[] =
{
    +1, +1, +1,
    +1, +1, +1,

    +3, +3, +3,
    +3, +3, +3,
};

i8 CONST_DATA gUnitBurstMapUiXOffsetTable[] =
{
    0, -1, -6,
    0, -1, -6,
};

i8 CONST_DATA gUnitBurstMapUiYOffsetTable[] =
{
    -6, -6, -6,
    +3, +3, +3,
};

u8 const * CONST_DATA gUnitBurstMapUiFrameTsaTable[] =
{
    Tsa_UnitBurstMapUi_Frame0,
    Tsa_UnitBurstMapUi_Frame1,
    Tsa_UnitBurstMapUi_Frame2,
    Tsa_UnitBurstMapUi_Frame3,
    Tsa_UnitBurstMapUi_Frame4,
    Tsa_UnitBurstMapUi_Frame5,
};

i8 CONST_DATA gUnitMapUiShowOffsetTable[] =
{
    5, 9, 11, 12,
};

i8 CONST_DATA gUnitMapUiHideOffsetTable[] =
{
    11, 7, 0,
};

i8 CONST_DATA gTerrainMapUiShowOffsetTable[] =
{
    4, 5, 6,
};

i8 CONST_DATA gTerrainMapUiHideOffsetTable[] =
{
    5, 4, 0,
};

struct ProcScr CONST_DATA ProcScr_TerrainMapUi[] =
{
    PROC_19,
    PROC_19,
    PROC_SLEEP(0),

    PROC_CALL(TerrainMapUi_Init),

PROC_LABEL(0),
    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(TerrainMapUi_TerrainChange),
    PROC_REPEAT(TerrainMapUi_ShowLoop),

    PROC_REPEAT(TerrainMapUi_Loop),

    PROC_REPEAT(TerrainMapUi_HideLoop),
    PROC_GOTO(0),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_UnitMapUi[] =
{
    PROC_19,
    PROC_19,
    PROC_SLEEP(0),

    PROC_CALL(UnitMapUi_Init),

PROC_LABEL(0),
    PROC_REPEAT(UnitMapUi_HiddenLoop),
    PROC_REPEAT(UnitMapUi_ShowLoop),

PROC_LABEL(2),
    PROC_REPEAT(UnitMapUi_Loop),

PROC_LABEL(3),
    PROC_REPEAT(UnitMapUi_HideLoop),
    PROC_GOTO(0),

PROC_LABEL(1),
    PROC_CALL(UnitMapUi_UnitChange),
    PROC_GOTO(2),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_UnitBurstMapUi[] =
{
    PROC_19,
    PROC_19,
    PROC_SLEEP(0),

    PROC_CALL(UnitBurstMapUi_Init),
    PROC_REPEAT(UnitBurstMapUi_Loop),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_StartMapUi[] =
{
    PROC_WHILE(IsMapFadeActive),
    PROC_CALL(DoStartMapUi),
    PROC_END,
};

void PutMapUiHpBarLeft(u16 * tm, fi16 fill, int tile)
{
    if (fill > 5)
        fill = 5;

    *tm = fill + tile;
}

void PutMapUiHpBarMid(u16 * tm, fi16 fill, int tile)
{
    int i;

    int div = fill >> 3; // divide by 8
    int mod = fill & 7; // modulus 8

    for (i = 0; i < 4; i++)
    {
        if (i < div) // full
            *tm = tile + 6 + 8;
        else if (i == div) // partial
            *tm = tile + 6 + mod;
        else // empty
            *tm = tile + 6 + 0;

        tm++;
    }
}

void PutMapUiHpBarRight(u16 * tm, fi16 fill, int tile)
{
    if (fill > 4)
        fill = 5;

    if (fill < 0)
        fill = 0;

    *tm = 15 + tile + fill;
}

void PutMapUiHpBar(u16 * tm, struct Unit * unit, int tile)
{
    fi16 hp_ratio;

    hp_ratio = 42 * GetUnitCurrentHp(unit);
    hp_ratio = Div(hp_ratio, GetUnitMaxHp(unit));

    PutMapUiHpBarLeft(tm + 0, hp_ratio, tile);
    PutMapUiHpBarMid(tm + 1, hp_ratio - 5, tile);
    PutMapUiHpBarRight(tm + 5, hp_ratio - 37, tile);
}

void UnitMapUi_ShowLoop(struct MapUiProc * proc)
{
    int offset;

    proc->hide_contents = TRUE;

    CpuFastFill(0, gBg0Tm, 6 * 0x20 * sizeof(u16));
    CpuFastFill(0, gBg1Tm, 6 * 0x20 * sizeof(u16));

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    offset = gUnitMapUiShowOffsetTable[proc->show_hide_clock];

    if (proc->screen_side < 0)
    {
        TmCopyRect(gUiTmScratchA + TM_OFFSET(12 - offset, 0), gBg0Tm + TM_OFFSET(0, 0), offset, 6);
        TmCopyRect(gUiTmScratchB + TM_OFFSET(12 - offset, 0), gBg1Tm + TM_OFFSET(0, 0), offset, 6);
    }
    else
    {
        TmCopyRect(gUiTmScratchA + TM_OFFSET(0, 0), gBg0Tm + TM_OFFSET(30 - offset, 0), offset, 6);
        TmCopyRect(gUiTmScratchB + TM_OFFSET(0, 0), gBg1Tm + TM_OFFSET(30 - offset, 0), offset, 6);
    }

    proc->show_hide_clock++;

    if (proc->show_hide_clock == 4)
    {
        proc->hide_contents = FALSE;
        proc->show_hide_clock = 0;

        Proc_Break(proc);

        UnitMapUiUpdate(proc, GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]));
    }
}

void UnitMapUi_HideLoop(struct MapUiProc * proc)
{
    int offset;

    proc->hide_contents = TRUE;

    // clear first 6 tm lines
    CpuFastFill(0, gBg0Tm, 6 * 0x20 * sizeof(u16));
    CpuFastFill(0, gBg1Tm, 6 * 0x20 * sizeof(u16));

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    offset = gUnitMapUiHideOffsetTable[proc->show_hide_clock];

    if (proc->screen_side < 0)
    {
        TmCopyRect(gUiTmScratchA + TM_OFFSET(12 - offset, 0), gBg0Tm, offset, 6);
        TmCopyRect(gUiTmScratchB + TM_OFFSET(12 - offset, 0), gBg1Tm, offset, 6);
    }
    else
    {
        TmCopyRect(gUiTmScratchA, gBg0Tm + TM_OFFSET(30 - offset, 0), offset, 6);
        TmCopyRect(gUiTmScratchB, gBg1Tm + TM_OFFSET(30 - offset, 0), offset, 6);
    }

    proc->show_hide_clock++;

    if (proc->show_hide_clock == 3)
    {
        proc->show_hide_clock = 0;

        Proc_Break(proc);
    }
}

void TerrainMapUi_ShowLoop(struct MapUiProc * proc)
{
    int offset;

    proc->hide_contents = TRUE;

    TmFillRect(gBg0Tm + TM_OFFSET(0, 13), 6, 7, 0);
    TmFillRect(gBg1Tm + TM_OFFSET(0, 13), 6, 7, 0);
    TmFillRect(gBg0Tm + TM_OFFSET(24, 13), 6, 7, 0);
    TmFillRect(gBg1Tm + TM_OFFSET(24, 13), 6, 7, 0);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    offset = gTerrainMapUiShowOffsetTable[proc->show_hide_clock];

    if (proc->screen_side < 0)
    {
        TmCopyRect(gUiTmScratchA + TM_OFFSET(6 - offset, 10), gBg0Tm + TM_OFFSET(0, 13), offset, 7);
        TmCopyRect(gUiTmScratchB + TM_OFFSET(6 - offset, 10), gBg1Tm + TM_OFFSET(0, 13), offset, 7);
    }
    else
    {
        TmCopyRect(gUiTmScratchA + TM_OFFSET(0, 10), gBg0Tm + TM_OFFSET(30 - offset, 13), offset, 7);
        TmCopyRect(gUiTmScratchB + TM_OFFSET(0, 10), gBg1Tm + TM_OFFSET(30 - offset, 13), offset, 7);
    }

    proc->show_hide_clock++;

    if (proc->show_hide_clock == 3)
    {
        proc->show_hide_clock = 0;
        proc->hide_contents = FALSE;

        Proc_Break(proc);
    }
}

void TerrainMapUi_HideLoop(struct MapUiProc * proc)
{
    int offset;

    proc->hide_contents = TRUE;

    // clear last 7 tm lines
    CpuFastFill(0, gBg0Tm + TM_OFFSET(0, 13), 7 * 0x20 * sizeof(u16));
    CpuFastFill(0, gBg1Tm + TM_OFFSET(0, 13), 7 * 0x20 * sizeof(u16));

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    offset = gTerrainMapUiHideOffsetTable[proc->show_hide_clock];

    if (proc->screen_side < 0)
    {
        TmCopyRect(gUiTmScratchA + TM_OFFSET(6 - offset, 10), gBg0Tm + TM_OFFSET(0, 13), offset, 7);
        TmCopyRect(gUiTmScratchB + TM_OFFSET(6 - offset, 10), gBg1Tm + TM_OFFSET(0, 13), offset, 7);
    }
    else
    {
        TmCopyRect(gUiTmScratchA + TM_OFFSET(0, 10), gBg0Tm + TM_OFFSET(30 - offset, 13), offset, 7);
        TmCopyRect(gUiTmScratchB + TM_OFFSET(0, 10), gBg1Tm + TM_OFFSET(30 - offset, 13), offset, 7);
    }

    proc->show_hide_clock++;

    if (proc->show_hide_clock == 3)
    {
        proc->show_hide_clock = 0;
        proc->hide_contents = FALSE;

        Proc_Break(proc);
    }
}

void PutUnitMapUi(struct MapUiProc * proc)
{
    int x;

    if (proc->screen_side < 0)
        x = 0;
    else
        x = 18;

    TmCopyRect(gUiTmScratchA + TM_OFFSET(0, 0), gBg0Tm + TM_OFFSET(x, 0), 12, 6);
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void PutTerrainMapUi(struct MapUiProc * proc)
{
    int x;

    if (proc->screen_side < 0)
        x = 0;
    else
        x = 24;

    TmCopyRect(gUiTmScratchA + TM_OFFSET(0, 10), gBg0Tm + TM_OFFSET(x, 13), 6, 7);
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void ApplyUnitMapUiFramePal(int faction, int pal_id)
{
    u16 const * pal = NULL;

    switch (faction)
    {
        case FACTION_BLUE:
            pal = Pal_UnitMapUiFrame_Blue;
            break;

        case FACTION_RED:
            pal = Pal_UnitMapUiFrame_Red;
            break;

        case FACTION_GREEN:
            pal = Pal_UnitMapUiFrame_Green;
            break;

        default:
            func_fe6_08018CDC();
            break;

    }

    ApplyPalette(pal, pal_id);
}

int GetUnitMapUiScreenSide(void)
{
    int x = gBmSt.cursor.x * 16 - gBmSt.camera.x;

    if (x < 7 * 16)
        return +1;

    if (x > 7 * 16)
        return -1;

    return 0;
}

int GetTerrainMapUiScreenSide(void)
{
    int y_opp, x_opp;

    int x = gBmSt.cursor.x - gBmSt.camera.x / 16;
    int y = gBmSt.cursor.y - gBmSt.camera.y / 16;

    y_opp = 9 - y;

    if ((x * x) + (y_opp * y_opp) <= 3 * 16)
        return +1;

    x_opp = 14 - x;

    if ((x_opp * x_opp) + (y_opp * y_opp) <= 3 * 16)
        return -1;

    return 0;
}

void ClearUnitMapUiStatus(u16 * tm, struct Unit * unit)
{
    tm[0] = TILEREF(BGCHR_MAPUI_100 + 0x20, 0);
    tm[1] = TILEREF(BGCHR_MAPUI_100 + 0x21, 0);
    tm[2] = 0;
    tm[3] = TILEREF(BGCHR_MAPUI_100 + 0x3E, 0);
    tm[4] = TILEREF(BGCHR_MAPUI_100 + 0x3F, 0);
    tm[5] = 0;
}

void PutUnitMapUiStatus(u16 * tm, struct Unit * unit)
{
    int tile = TILEREF(BGCHR_MAPUI_100, BGPAL_MAPUI_0);

    if (unit == NULL)
        return;

    switch (unit->status)
    {
        case UNIT_STATUS_SLEEP:
            tile = tile + 0x60;
            break;

        case UNIT_STATUS_POISON:
            tile = tile + 0x64;
            break;

        case UNIT_STATUS_BERSERK:
            tile = tile + 0x68;
            break;

        case UNIT_STATUS_SILENCED:
            tile = tile + 0x6C;
            break;

        case UNIT_STATUS_NONE:
            return;
    }

    tm[0] = tile++;
    tm[1] = tile++;
    tm[2] = tile++;
    tm[3] = tile++;
    tm[4] = 0;
    tm[5] = TILEREF(BGCHR_MAPUI_128 + unit->status_duration, BGPAL_MAPUI_0);
}

void UnitMapUiUpdate(struct MapUiProc * proc, struct Unit * unit)
{
    int x_digits, y_digits, x_digit1;

    if ((proc->unit_clock & 0x3F) == 0)
    {
        if ((proc->unit_clock & 0x40) != 0)
        {
            PutUnitMapUiStatus(proc->status_tm, unit);
            EnableBgSync(BG0_SYNC_BIT);
        }
        else
        {
            ClearUnitMapUiStatus(proc->status_tm, unit);
            EnableBgSync(BG0_SYNC_BIT);

            GenNumberStr(GetUnitCurrentHp(unit));
            proc->hp_cur_hi = gNumberStr[6] - '0';
            proc->hp_cur_lo = gNumberStr[7] - '0';

            GenNumberStr(GetUnitMaxHp(unit));
            proc->hp_max_hi = gNumberStr[6] - '0';
            proc->hp_max_lo = gNumberStr[7] - '0';
        }
    }

    if (proc->hide_contents)
        return;

    if ((proc->unit_clock & 0x40) != 0 && unit->status != UNIT_STATUS_NONE)
        return;

    x_digits = proc->hp_x * 8;
    x_digit1 = proc->hp_x * 8 + 16;
    y_digits = proc->hp_y * 8;

    // check if first digit isn't a space
    if (proc->hp_cur_hi != (u8)(' ' - '0'))
        PutOamHi(x_digit1, y_digits, Sprite_8x8, OAM2_CHR(OBCHR_MAPUI_NUMBERS) + OAM2_PAL(OBPAL_MAPUI_8) + proc->hp_cur_hi);

    PutOamHi(x_digits + 23, y_digits, Sprite_8x8, OAM2_CHR(OBCHR_MAPUI_NUMBERS) + OAM2_PAL(OBPAL_MAPUI_8) + proc->hp_cur_lo);

    // BUG: this assumes max hp will always be 2 digits
    // this is fixed in fe8 (fe7 unsure)

#if BUGFIX
    if (proc->hp_max_hi != (u8)(' ' - '0'))
        PutOamHi(x_digits + 34, y_digits, Sprite_8x8, OAM2_CHR(OBCHR_MAPUI_NUMBERS) + OAM2_PAL(OBPAL_MAPUI_8) + proc->hp_max_hi);
#else
    PutOamHi(x_digits + 34, y_digits, Sprite_8x8, OAM2_CHR(OBCHR_MAPUI_NUMBERS) + OAM2_PAL(OBPAL_MAPUI_8) + proc->hp_max_hi);
#endif

    PutOamHi(x_digits + 41, y_digits, Sprite_8x8, OAM2_CHR(OBCHR_MAPUI_NUMBERS) + OAM2_PAL(OBPAL_MAPUI_8) + proc->hp_max_lo);
}

void DrawUnitMapUi(struct MapUiProc * proc, struct Unit * unit)
{
    char const * text_str;
    int text_x;

    CpuFastFill(0, gUiTmScratchA, 6 * 0x20 * sizeof(u16));

    text_str = DecodeMsg(unit->pinfo->msg_name);
    text_x = GetStringTextCenteredPos(6 * 8, text_str);

    ClearText(&proc->text);
    Text_SetParams(&proc->text, text_x, TEXT_COLOR_0030);
    Text_DrawString(&proc->text, text_str);
    PutText(&proc->text, gUiTmScratchA + TM_OFFSET(5, 1));

    PutFaceChibi(GetUnitChibiId(unit),
        gUiTmScratchA + TM_OFFSET(1, 1),
        BGCHR_MAPUI_CHIBI, BGPAL_MAPUI_CHIBI, FALSE);

    proc->status_tm = gUiTmScratchA + TM_OFFSET(5, 3);
    proc->unit_clock = 0;

    if (proc->screen_side < 0)
        proc->hp_x = 5;
    else
        proc->hp_x = 23;

    proc->hp_y = 3;

    UnitMapUiUpdate(proc, unit);
    PutMapUiHpBar(gUiTmScratchA + TM_OFFSET(5, 4), unit, TILEREF(BGCHR_MAPUI_140, BGPAL_MAPUI_3));

    TmApplyTsa(gUiTmScratchB, Tsa_UnitMapUi_Frame, TILEREF(BGCHR_MAPUI_100, BGPAL_MAPUI_3));
    ApplyUnitMapUiFramePal(UNIT_FACTION(unit), BGPAL_MAPUI_3);
}

int GetUnitBurstMapUiOrientationAt(int x, int y)
{
    int result = 1;

    if (y < 6)
        result = 4;

    if (x < 2)
        result = result - 1;

    if (x > 22)
        result = result + 1;

    return result;
}

void DrawUnitBurstMapUi(struct MapUiProc * proc, struct Unit * unit)
{
    int x, y;
    int orientation;

    char const * text_str;
    int text_x;

    x = (unit->x * 16 - gBmSt.camera.x) / 8;
    y = (unit->y * 16 - gBmSt.camera.y) / 8;

    orientation = GetUnitBurstMapUiOrientationAt(x, y);

    x = x + gUnitBurstMapUiXOffsetTable[orientation];
    y = y + gUnitBurstMapUiYOffsetTable[orientation];

    proc->x_burst = x;
    proc->y_burst = y;
    proc->w_burst = 8;
    proc->h_burst = 5;

    text_str = DecodeMsg(unit->pinfo->msg_name);
    text_x = GetStringTextCenteredPos(6 * 8, text_str);

    ClearText(&proc->text);
    Text_SetParams(&proc->text, text_x, TEXT_COLOR_0030);
    Text_DrawString(&proc->text, text_str);
    PutText(&proc->text, gBg0Tm + TM_OFFSET(
        x + gUnitBurstMapUiTextXTable[orientation],
        y + gUnitBurstMapUiTextYTable[orientation]));

    proc->status_tm = gBg0Tm + TM_OFFSET(x + 1, y + 3);
    proc->unit_clock = 0;

    proc->hp_x = x + 1;
    proc->hp_y = y + 3;

    UnitMapUiUpdate(proc, unit);

    TmApplyTsa(gBg1Tm + TM_OFFSET(x, y), gUnitBurstMapUiFrameTsaTable[orientation], TILEREF(BGCHR_MAPUI_100, BGPAL_MAPUI_3));
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    ApplyUnitMapUiFramePal(UNIT_FACTION(unit), BGPAL_MAPUI_3);
}

void ClearUnitBurstMapUi(struct MapUiProc * proc)
{
    if (proc->w_burst == 8 && proc->h_burst == 5)
    {
        TmFillRect(gBg0Tm + TM_OFFSET(proc->x_burst, proc->y_burst), proc->w_burst, proc->h_burst, 0);
        TmFillRect(gBg1Tm + TM_OFFSET(proc->x_burst, proc->y_burst), proc->w_burst, proc->h_burst, 0);

        EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

        proc->w_burst = 0;
        proc->h_burst = 0;
    }
}

void DrawTerrainMapUi(struct MapUiProc * proc)
{
    char const * text_str;
    int number;

    int terrain = gMapTerrain[gBmSt.cursor.y][gBmSt.cursor.x];

    CpuFastFill(0, gUiTmScratchA + TM_OFFSET(0, 10), 7 * 0x20 * sizeof(u16));

    text_str = GetTerrainName(terrain);
    number = GetStringTextCenteredPos(4 * 8, text_str);

    ClearText(&proc->text);
    Text_SetParams(&proc->text, number, TEXT_COLOR_0123);
    Text_DrawString(&proc->text, text_str);
    PutText(&proc->text, gUiTmScratchA + TM_OFFSET(1, 12));

    TmApplyTsa(gUiTmScratchA + TM_OFFSET(1, 14), Tsa_TerrainMapUi_Labels, TILEREF(BGCHR_MAPUI_100, BGPAL_MAPUI_0));

    if (MoveTable_Berserker[terrain] > 0)
    {
        GenNumberStr(TerrainDefTable_Default[terrain]);
        PutDigits(gUiTmScratchA + TM_OFFSET(4, 14), gNumberStr + 7, BGCHR_MAPUI_128, BGPAL_MAPUI_2);

        GenNumberStr(TerrainAvoTable_Default[terrain]);
        PutDigits(gUiTmScratchA + TM_OFFSET(4, 15), gNumberStr + 7, BGCHR_MAPUI_128, BGPAL_MAPUI_2);
    }

    switch (terrain)
    {
        case TERRAIN_WALL_BREAKABLE:
            TmApplyTsa(gUiTmScratchA + TM_OFFSET(1, 14), Tsa_TerrainMapUi_ObstacleLabels, TILEREF(BGCHR_MAPUI_100, BGPAL_MAPUI_2));

            number = GetObstacleHpAt(gBmSt.cursor.x, gBmSt.cursor.y);

            if (number == 100)
            {
                TmApplyTsa(gUiTmScratchA + TM_OFFSET(3, 15), Tsa_TerrainMapUi_ObstacleFullHp, TILEREF(BGCHR_MAPUI_100, BGPAL_MAPUI_0));
                break;
            }

            GenNumberStr(number);
            PutDigits(gUiTmScratchA + TM_OFFSET(4, 15), gNumberStr + 7, BGCHR_MAPUI_128, BGPAL_MAPUI_2);

            break;

        case TERRAIN_BALLISTA:
        case TERRAIN_LONGBALLISTA:
        case TERRAIN_KILLERBALLISTA:
            TmApplyTsa(gUiTmScratchA + TM_OFFSET(1, 14), Tsa_TerrainMapUi_BallistaLabels, TILEREF(BGCHR_MAPUI_100, BGPAL_MAPUI_0));

            GenNumberStr(GetBallistaUsesAt(gBmSt.cursor.x, gBmSt.cursor.y));
            PutDigits(gUiTmScratchA + TM_OFFSET(4, 14), gNumberStr + 7, BGCHR_MAPUI_128, BGPAL_MAPUI_2);

            break;
    }

    TmApplyTsa(gUiTmScratchB + TM_OFFSET(0, 10), Tsa_TerrainMapUi_Frame, TILEREF(BGCHR_MAPUI_100, BGPAL_WINDOWFRAME));
}

void TerrainMapUi_Init(struct MapUiProc * proc)
{
    proc->show_hide_clock = 0;
    proc->screen_side = 1;

    InitTextDb(&proc->text, 4);
}

void TerrainMapUi_TerrainChange(struct MapUiProc * proc)
{
    proc->screen_side = GetTerrainMapUiScreenSide();

    if (proc->screen_side == 0)
        proc->screen_side = -1;

    DrawTerrainMapUi(proc);

    proc->x_cursor = gBmSt.cursor.x;
    proc->y_cursor = gBmSt.cursor.y;
}

void TerrainMapUi_Loop(struct MapUiProc * proc)
{
    proc->x_cursor_prev = proc->x_cursor;
    proc->y_cursor_prev = proc->y_cursor;

    proc->x_cursor = gBmSt.cursor.x;
    proc->y_cursor = gBmSt.cursor.y;

    if (proc->x_cursor == proc->x_cursor_prev && proc->y_cursor == proc->y_cursor_prev)
        return;

    if (FindProc(ProcScr_CamMove) == NULL)
    {
        int side = GetTerrainMapUiScreenSide();

        if (proc->screen_side == side || side == 0)
        {
            DrawTerrainMapUi(proc);
            PutTerrainMapUi(proc);
            return;
        }
    }

    Proc_Break(proc);
}

void UnitMapUi_Init(struct MapUiProc * proc)
{
    InitTextDb(&proc->text, 6);
    proc->show_hide_clock = 0;
}

void UnitMapUi_HiddenLoop(struct MapUiProc * proc)
{
    struct Unit * unit;

    proc->hide_contents = TRUE;

    unit = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

    if (unit == NULL)
        return;

    if (FindProc(ProcScr_CamMove) == NULL)
    {
        proc->screen_side = GetUnitMapUiScreenSide();

        if (proc->screen_side == 0)
            proc->screen_side = 1;

        proc->x_cursor = gBmSt.cursor.x;
        proc->y_cursor = gBmSt.cursor.y;

        DrawUnitMapUi(proc, unit);
        Proc_Break(proc);
    }
}

void UnitMapUi_Loop(struct MapUiProc * proc)
{
    struct Unit * unit = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

    proc->unit_clock++;

    UnitMapUiUpdate(proc, unit);

    if ((proc->unit_clock & 0x3F) == 0)
    {
        PutUnitMapUi(proc);
    }

    proc->x_cursor_prev = proc->x_cursor;
    proc->y_cursor_prev = proc->y_cursor;

    proc->x_cursor = gBmSt.cursor.x;
    proc->y_cursor = gBmSt.cursor.y;

    if (proc->x_cursor == proc->x_cursor_prev && proc->y_cursor == proc->y_cursor_prev)
        return;

    if (unit != NULL && FindProc(ProcScr_CamMove) == NULL)
    {
        int side = GetUnitMapUiScreenSide();

        if (proc->screen_side == side || side == 0)
        {
            Proc_Goto(proc, 1);
            return;
        }
    }

    Proc_Break(proc);
}

void UnitMapUi_UnitChange(struct MapUiProc * proc)
{
    struct Unit * unit = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

    if (unit == NULL)
    {
        Proc_Goto(proc, 3);
        return;
    }

    DrawUnitMapUi(proc, unit);
    PutUnitMapUi(proc);
}

void UnitBurstMapUi_Init(struct MapUiProc * proc)
{
    InitTextDb(&proc->text, 6);

    proc->burst_unit_id = 0;
    proc->hide_contents = FALSE;
    proc->show_hide_clock = 0;
    proc->w_burst = 0;
    proc->h_burst = 0;
}

void UnitBurstMapUi_Loop(struct MapUiProc * proc)
{
    struct MapUiProc * terrain_ui_proc;

    proc->burst_unit_id_prev = proc->burst_unit_id;
    proc->burst_unit_id = gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x];

    if (proc->burst_unit_id_prev != proc->burst_unit_id && proc->burst_unit_id_prev != 0)
    {
        ClearUnitBurstMapUi(proc);
        proc->show_hide_clock = 0;
        return;
    }

    if (proc->burst_unit_id != 0 && FindProc(ProcScr_CamMove) == NULL)
    {
        terrain_ui_proc = FindProc(ProcScr_TerrainMapUi);

        if (terrain_ui_proc != NULL && terrain_ui_proc->hide_contents)
        {
            if (proc->show_hide_clock < 4)
                proc->show_hide_clock++;

            return;
        }

        proc->show_hide_clock++;

        if (proc->show_hide_clock < 5)
            return;

        if (proc->show_hide_clock == 5)
        {
            DrawUnitBurstMapUi(proc, GetUnit(proc->burst_unit_id));
            return;
        }

        proc->unit_clock++;

        if (terrain_ui_proc != NULL)
            proc->hide_contents = terrain_ui_proc->hide_contents;
        else
            proc->hide_contents = FALSE;

        UnitMapUiUpdate(proc, GetUnit(proc->burst_unit_id));
    }
}

void DoStartMapUi(void)
{
    SetWinEnable(0, 0, 0);
    SetWOutLayers(1, 1, 1, 1, 1);
    gDispIo.win_ct.wout_enable_blend = TRUE;

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, 0, 0);

    SetBlendAlpha(15, 4);
    SetBlendTargetA(0, 1, 0, 0, 0); SetBlendBackdropA(0);
    SetBlendTargetB(0, 0, 1, 1, 1);

    Decompress(Img_MapUiElements, (void *) VRAM + BGCHR_MAPUI_100 * CHR_SIZE);
    CpuFastCopy((void *) VRAM + BGCHR_MAPUI_128 * CHR_SIZE, OBJ_VRAM0 + OBCHR_MAPUI_NUMBERS * CHR_SIZE, 10 * CHR_SIZE);
    ApplyPalette(gPal + BGPAL_MAPUI_0 * 0x20, 0x10 + OBPAL_MAPUI_8);
    ApplyIconPalette(1, BGPAL_MAPUI_2);

    ResetTextFont();

    if (gPlaySt.config_terrain_mapui == 0)
        SpawnProc(ProcScr_TerrainMapUi, PROC_TREE_3);

    if (gPlaySt.config_unit_mapui == 0)
        SpawnProc(ProcScr_UnitMapUi, PROC_TREE_3);

    if (gPlaySt.config_unit_mapui == 1)
        SpawnProc(ProcScr_UnitBurstMapUi, PROC_TREE_3);
}

void StartMapUi(void)
{
    SpawnProc(ProcScr_StartMapUi, PROC_TREE_3);
}

void EndMapUi(void)
{
    Proc_EndEach(ProcScr_UnitMapUi);
    Proc_EndEach(ProcScr_UnitBurstMapUi);
    Proc_EndEach(ProcScr_TerrainMapUi);

    SetBlendNone();
    ClearUi();
}
