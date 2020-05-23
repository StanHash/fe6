
// TODO: better name for this file

#include "common.h"

#include "hardware.h"
#include "icon.h"
#include "sound.h"
#include "sprite.h"
#include "face.h"
#include "util.h"
#include "msg.h"
#include "bm.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "menu.h"
#include "mu.h"

#include "constants/video-global.h"
#include "constants/pids.h"
#include "constants/jids.h"
#include "constants/icons.h"

struct UnkProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ int facing;
    /* 30 */ struct Unit* unit;
    /* 34 */ struct MuProc* mu;
    /* 38 */ u8 moveScript[4];
    /* 3C */ Bool unk_3C;
};

struct EquipInfoWindowProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Unit* unit;
    /* 30 */ u8 x;
    /* 31 */ u8 y;
    /* 32 */ u8 iconPalid;
    /* 33 */ s8 compareWeaponSlot;
    /* 34 */ struct Text text[3];
};

struct UnkProc2
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Unit* unit;
    /* 30 */ short unk_30;
    /* 32 */ short unk_32;
    /* 34 */ short unk_34;
    /* 36 */ short unk_36;
    /* 38 */ int pad_38;
    /* 3C */ short unk_3C;
    /* 3E */ short unk_3E;
    /* 40 */ int pad_40;
    /* 44 */ int unk_44;
};

static void sub_801C1D0(struct UnkProc* proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C58F8[] =
{
    PROC_19,

    PROC_REPEAT(sub_801C1D0),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_085C5910[] =
{
    PROC_19,

    PROC_CALL(LockGame),
    PROC_REPEAT(sub_801C1D0),
    PROC_CALL(UnlockGame),

    PROC_END,
};

static void MapFade_Init(struct GenericProc* proc);
static void MapFade_Loop(struct GenericProc* proc);
static void MapFade_End(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_MapFade[] =
{
    PROC_19,
    PROC_END_IF_DUP,

    PROC_ONEND(MapFade_End),

    PROC_CALL(MapFade_Init),

    PROC_CALL(MapFade_Loop),
    PROC_REPEAT(MapFade_Loop),

    PROC_END,
};

static void sub_801C49C(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C5970[] =
{
    PROC_CALL(sub_801C49C),
    PROC_SLEEP(0),

    PROC_END,
};

static void sub_801C510(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C5988[] =
{
    PROC_19,

    PROC_CALL(sub_801C510),
    PROC_SLEEP(1),

    PROC_END,
};

static int sub_801C540(ProcPtr proc);
static int sub_801C560(ProcPtr proc);
static int sub_801C58C(ProcPtr proc);
static int sub_801C59C(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C59A8[] =
{
    PROC_CALL_2(sub_801C540),
    PROC_CALL_2(sub_801C560),
    PROC_SLEEP(1),

    PROC_CALL_2(sub_801C58C),
    PROC_CALL_2(sub_801C59C),

PROC_LABEL(99),
    PROC_END,
};

static void EquipInfoWindow_Loop(struct EquipInfoWindowProc* proc);

struct ProcScr CONST_DATA ProcScr_EquipInfoWindow[] =
{
    PROC_19,

    PROC_REPEAT(EquipInfoWindow_Loop),

    PROC_END,
};

static void sub_801CD60(struct UnkProc2* proc);
static void sub_801CDE4(struct UnkProc2* proc);
static void sub_801CEE0(struct UnkProc2* proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C59F8[] =
{
    PROC_SLEEP(0),

    PROC_CALL(sub_801CD60),
    PROC_REPEAT(sub_801CDE4),

    PROC_CALL(sub_801CEE0),

    PROC_END,
};

int sub_801C160(int xa, int ya, int xb, int yb)
{
    if (xa == xb)
    {
        if (ya < yb)
            return FACING_UP;

        if (ya > yb)
            return FACING_DOWN;
    }

    if (ya == yb)
    {
        if (xa < xb)
            return FACING_LEFT;

        if (xa > xb)
            return FACING_RIGHT;
    }

    return FACING_LEFT;
}

struct MuProc* sub_801C188(struct Unit* unit)
{
    if (!(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_MOUNTED))
        return MU_Start(unit);

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_FEMALE)
        return sub_805F820(unit->x, unit->y, JID_DISMOUNTED_F, 12);
    else
        return sub_805F820(unit->x, unit->y, JID_DISMOUNTED_M, 12);
}

static void sub_801C1D0(struct UnkProc* proc)
{
    if (MU_IsAnyActive())
        return;

    sub_80608EC(proc->mu);
    Proc_Break(proc);

    if (proc->unk_3C)
    {
        RefreshEntityMaps();
        RefreshMapSprites();
        sub_8021FE8();
    }
}

void sub_801C20C(struct Unit* unit, int facing, Bool arg_2, ProcPtr parent)
{
    struct UnkProc* proc;

    proc = SpawnProcLocking(ProcScr_Unk_085C58F8, parent);

    proc->unit = unit;
    proc->facing = facing;

    proc->moveScript[0] = MOVE_CMD_CAMERA_OFF;
    proc->moveScript[1] = MOVE_CMD_MOVE_BASE + facing;
    proc->moveScript[2] = MOVE_CMD_HALT;

    proc->unk_3C = arg_2;

    proc->mu = sub_801C188(unit);
    sub_805FD78(proc->mu, proc->moveScript);
}

void sub_801C264(struct Unit* unit, int facing)
{
    struct UnkProc* proc;

    proc = SpawnProc(ProcScr_Unk_085C5910, PROC_TREE_3);

    proc->unit = unit;
    proc->facing = facing;

    proc->moveScript[0] = MOVE_CMD_CAMERA_OFF;
    proc->moveScript[1] = MOVE_CMD_MOVE_BASE + facing;
    proc->moveScript[2] = MOVE_CMD_HALT;

    proc->unk_3C = FALSE;

    proc->mu = sub_801C188(unit);
    sub_805FD78(proc->mu, proc->moveScript);
}

static void MapFade_Init(struct GenericProc* proc)
{
    proc->unk4C = 0x10;

    InitBmBgLayers();

    SetBlendTargetA(0, 0, 1, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 1);
}

static void MapFade_Loop(struct GenericProc* proc)
{
    SetBlendAlpha(proc->unk4C, 0x10 - proc->unk4C);

    proc->unk4C--;

    if (proc->unk4C < 0)
    {
        Proc_Break(proc);

        SetBlendNone();

        SetBgChrOffset(2, 0);
        TmFill(gBg2Tm, 0);

        EnableBgSync(BG2_SYNC_BIT);
    }
}

static void MapFade_End(struct GenericProc* proc)
{
    sub_801809C();

    if (proc->unk4E)
        UnlockGame();
}

void StartMapFade(Bool locksGame)
{
    struct GenericProc* proc;

    proc = SpawnProc(ProcScr_MapFade, PROC_TREE_3);
    proc->unk4E = locksGame;

    if (locksGame)
        LockGame();
}

Bool IsMapFadeActive(void)
{
    return Proc_Find(ProcScr_MapFade) ? TRUE : FALSE;
}

void GetPlayerInitialCursorPosition(int* xOut, int* yOut)
{
    struct Unit* unit;

    if (gPlaySt.turn == 1)
    {
        unit = GetUnitByPid(PID_ROY);

        gPlaySt.xCursor = unit->x;
        gPlaySt.yCursor = unit->y;
    }

    if (!gPlaySt.configNoAutoCursor)
    {
        unit = GetUnitByPid(PID_ROY);

        *xOut = unit->x;
        *yOut = unit->y;
    }
    else
    {
        *xOut = gPlaySt.xCursor;
        *yOut = gPlaySt.yCursor;
    }
}

void GetAiInitialCursorPosition(int* xOut, int* yOut)
{
    int i;

    for (i = gPlaySt.faction + 1; i < gPlaySt.faction + 0x40; ++i)
    {
        struct Unit* unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->person)
            continue;

        if (unit->state & (US_HIDDEN | US_BIT9))
            continue;

        *xOut = unit->x;
        *yOut = unit->y;

        if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_BOSS)
            return;
    }
}

static void sub_801C49C(ProcPtr proc)
{
    int x = -1;
    int y = -1;

    if (sub_802097C(gPlaySt.faction) == 0)
    {
        Proc_End(proc);
        return;
    }

    switch (gPlaySt.faction)
    {

    case FACTION_BLUE:
        GetPlayerInitialCursorPosition(&x, &y);
        break;

    case FACTION_RED:
    case FACTION_GREEN:
        GetAiInitialCursorPosition(&x, &y);
        break;

    }

    if (x >= 0 && y >= 0)
    {
        CameraMoveWatchPosition(proc, x, y);
        SetMapCursorPosition(x, y);
    }
}

static void sub_801C510(ProcPtr proc)
{
    struct Unit* unit = GetUnit(sub_806EACC());

    if (unit != NULL)
    {
        int x = unit->x;
        int y = unit->y;

        CameraMoveWatchPosition(proc, x, y);
        SetMapCursorPosition(x, y);
    }
}

static int sub_801C540(ProcPtr proc)
{
    ApplyIconPalettes(BGPAL_ICONS);
    sub_8041818(&MenuInfo_085C74E0, proc);

    return FALSE;
}

static int sub_801C560(ProcPtr proc)
{
    sub_802CB50();
    EndEquipInfoWindow();

    if (gBmSt.unk_2E == 0)
    {
        Proc_Goto(proc, 99);
        return TRUE;
    }

    return FALSE;
}

static int sub_801C58C(ProcPtr proc)
{
    sub_8081620(NULL, proc);
    return FALSE;
}

static int sub_801C59C(ProcPtr proc)
{
    return sub_8029714(gBmSt.unk_2E);
}

void sub_801C5B0(struct Unit* unit, int item, ProcPtr parent)
{
    gActiveUnit = unit;

    if (!UnitAddItem(unit, item))
    {
        gBmSt.itemOverflow = item;

        StartFace(0, GetUnitFid(unit), 22*8, 4, FACE_DISP_KIND(FACE_96x80));
        StartEquipInfoWindow(parent, unit, 15, 10);
        sub_802CB14(parent, DecodeMsg(0xC26)); // TODO: msgids

        SpawnProcLocking(ProcScr_Unk_085C59A8, parent);
    }
}

int sub_801C620(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return sub_801F708(menu, ent);
}

int sub_801C62C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int item = gBmSt.itemOverflow;

    Text_SetColor(&ent->text, TEXT_COLOR_SYSTEM_BLUE);
    sub_80167E4(&ent->text, item, gBg0Tm + TM_OFFSET(ent->x, ent->y));

    EnableBgSync(BG0_SYNC_BIT);
}

int sub_801C670(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_8029714(gActiveUnit->items[ent->id]);

    UnitRemoveItem(gActiveUnit, ent->id);
    UnitAddItem(gActiveUnit, gBmSt.itemOverflow);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR | MENU_ACT_ENDFACE;
}

int sub_801C6B0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_8029714(gBmSt.itemOverflow);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR | MENU_ACT_ENDFACE;
}

void sub_801C6C4(int vision)
{
    if (vision < 0)
        vision = GetChapterInfo(gPlaySt.chapter)->fog;

    RenderMapForFade();

    gPlaySt.vision = vision;

    RefreshEntityMaps();
    RefreshMapSprites();
    RenderMap();

    StartMapFade(TRUE);
}

void sub_801C700(struct Unit* actor, struct Unit* target)
{
    int ix, iy;

    MapFill(gMapMovement, -1);
    MapFill(gMapRange, 0);

    SetWorkingMap(gMapMovement);

    MapIncInBoundedRange(target->x, target->y, 1, GetUnitMagRange(actor));

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (!CanUnitCrossTerrain(target, gMapTerrain[iy][ix]) || gMapUnit[iy][ix] != 0 || gMapFog[iy][ix] == 0)
                gMapMovementSigned[iy][ix] = -1;
        }
    }

    gMapMovementSigned[actor->y][actor->x] = -1;
}

static void EquipInfoWindow_Loop(struct EquipInfoWindowProc* proc)
{
    if (proc->compareWeaponSlot < 0)
        return;

    if (gBattleUnitA.battleAttack > gBattleUnitB.battleAttack)
        PutSysArrow(51 + 8*proc->x, 8*(proc->y+3), FALSE);

    if (gBattleUnitA.battleAttack < gBattleUnitB.battleAttack)
        PutSysArrow(51 + 8*proc->x, 8*(proc->y+3), TRUE);

    if (gBattleUnitA.battleHit > gBattleUnitB.battleHit)
        PutSysArrow(51 + 8*proc->x, 8*(proc->y+5), FALSE);

    if (gBattleUnitA.battleHit < gBattleUnitB.battleHit)
        PutSysArrow(51 + 8*proc->x, 8*(proc->y+5), TRUE);

    if (gBattleUnitA.battleCrit > gBattleUnitB.battleCrit)
        PutSysArrow(99 + 8*proc->x, 8*(proc->y+3), FALSE);

    if (gBattleUnitA.battleCrit < gBattleUnitB.battleCrit)
        PutSysArrow(99 + 8*proc->x, 8*(proc->y+3), TRUE);

    if (gBattleUnitA.battleAvoid > gBattleUnitB.battleAvoid)
        PutSysArrow(99 + 8*proc->x, 8*(proc->y+5), FALSE);

    if (gBattleUnitA.battleAvoid < gBattleUnitB.battleAvoid)
        PutSysArrow(99 + 8*proc->x, 8*(proc->y+5), TRUE);
}

void StartEquipInfoWindow(ProcPtr parent, struct Unit* unit, int x, int y)
{
    struct EquipInfoWindowProc* proc;

    if (Proc_Find(ProcScr_EquipInfoWindow) != NULL)
        return;

    proc = SpawnProc(ProcScr_EquipInfoWindow, parent);

    proc->unit = unit;
    proc->x = x;
    proc->y = y;
    proc->iconPalid = BGPAL_EQUIP_INFO_ICON;
    proc->compareWeaponSlot = GetUnitEquippedWeaponSlot(unit);

    InitTextDb(proc->text + 0, 12);
    InitTextDb(proc->text + 1, 12);
    InitTextDb(proc->text + 2, 12);

    ApplyIconPalette(1, proc->iconPalid);

    sub_802430C(proc->unit, -1);

    gBattleUnitB.battleAttack = gBattleUnitA.battleAttack;
    gBattleUnitB.battleHit = gBattleUnitA.battleHit;
    gBattleUnitB.battleCrit = gBattleUnitA.battleCrit;
    gBattleUnitB.battleAvoid = gBattleUnitA.battleAvoid;
}

void UpdateEquipInfoWindow(int itemSlot)
{
    struct EquipInfoWindowProc* proc = Proc_Find(ProcScr_EquipInfoWindow);

    int item;

    ClearText(proc->text + 0);
    ClearText(proc->text + 1);
    ClearText(proc->text + 2);

    sub_8041358(proc->x, proc->y, 14, 8, 0);

    switch (itemSlot)
    {

    case 0 ... 4:
        item = proc->unit->items[itemSlot];
        break;

    case 5:
        item = gBmSt.itemOverflow;
        break;

    default:
        item = itemSlot;
        itemSlot = 8;

    }

    switch (GetItemKind(item))
    {

    case ITEM_KIND_STAFF:
    case ITEM_KIND_UNK9:
    case ITEM_KIND_UNK11:
    {
        // print use description

        char const* str = DecodeMsg(GetItemUseDescMsg(item));
        int line = 0;

        while (TRUE)
        {
            Text_InsertDrawString(proc->text + line, 0, TEXT_COLOR_SYSTEM_WHITE, str);
            str = GetStringLineEnd(str);

            if (str[0] == '\0')
                break;

            str++;
            line++;
        }

        gBattleUnitA.battleAttack = gBattleUnitB.battleAttack;
        gBattleUnitA.battleHit = gBattleUnitB.battleHit;
        gBattleUnitA.battleCrit = gBattleUnitB.battleCrit;
        gBattleUnitA.battleAvoid = gBattleUnitB.battleAvoid;

        PutText(proc->text + 0, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+1));
        PutText(proc->text + 1, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+3));
        PutText(proc->text + 2, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+5));

        break;
    }

    default:
    {
        // print stats

        int color;

        sub_802430C(proc->unit, itemSlot);

        if (itemSlot == 8)
        {
            gBattleUnitB.battleAttack = gBattleUnitA.battleAttack;
            gBattleUnitB.battleHit = gBattleUnitA.battleHit;
            gBattleUnitB.battleCrit = gBattleUnitA.battleCrit;
            gBattleUnitB.battleAvoid = gBattleUnitA.battleAvoid;
        }

        if (CanUnitUseWeapon(proc->unit, gBattleUnitA.weapon))
            color = TEXT_COLOR_SYSTEM_BLUE;
        else
            color = TEXT_COLOR_SYSTEM_GRAY;

        Text_InsertDrawString(proc->text + 0, 0x20,   TEXT_COLOR_SYSTEM_WHITE, "‘®«");
        Text_InsertDrawString(proc->text + 1, 0x00+2, TEXT_COLOR_SYSTEM_WHITE, "UŒ‚");
        Text_InsertDrawString(proc->text + 2, 0x00+2, TEXT_COLOR_SYSTEM_WHITE, "–½’†");
        Text_InsertDrawString(proc->text + 1, 0x30+2, TEXT_COLOR_SYSTEM_WHITE, "•KŽE");
        Text_InsertDrawString(proc->text + 2, 0x30+2, TEXT_COLOR_SYSTEM_WHITE, "‰ñ”ð");

        Text_InsertDrawNumberOrBlank(proc->text + 1, 0x20+4, color, gBattleUnitA.battleAttack);
        Text_InsertDrawNumberOrBlank(proc->text + 2, 0x20+4, color, gBattleUnitA.battleHit);
        Text_InsertDrawNumberOrBlank(proc->text + 1, 0x50+4, color, gBattleUnitA.battleCrit);
        Text_InsertDrawNumberOrBlank(proc->text + 2, 0x50+4, color, gBattleUnitA.battleAvoid);

        PutText(proc->text + 0, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+1));
        PutText(proc->text + 1, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+3));
        PutText(proc->text + 2, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+5));

        PutIcon(gBg0Tm + TM_OFFSET(proc->x+7, proc->y+1),
            ICON_ITEM_KIND_BASE + GetItemKind(gBattleUnitA.weapon), TILEREF(0, BGPAL_EQUIP_INFO_ICON));

        break;
    }

    }

    EnableBgSync(BG0_SYNC_BIT);
}

void EndEquipInfoWindow(void)
{
    Proc_EndEach(ProcScr_EquipInfoWindow);
}

static void sub_801CD60(struct UnkProc2* proc)
{
    int xd, yd, dist;

    proc->unk_30 = proc->unit->x << 4;
    proc->unk_32 = proc->unit->y << 4;

    xd = proc->unk_34 - proc->unk_30;
    yd = proc->unk_36 - proc->unk_32;

    dist = Sqrt(xd * xd + yd * yd);

    proc->unk_44 = Interpolate(INTERPOLATE_LINEAR, 0x01 << 12, 0x20 << 12, dist, 0x200);
    proc->unk_3E = Interpolate(INTERPOLATE_LINEAR, 12, 48, dist, 0x200);

    proc->unk_3C = 0;
}

static void sub_801CDE4(struct UnkProc2* proc)
{
    int var = Interpolate(INTERPOLATE_LINEAR, 0, 1 << 16, proc->unk_3C, proc->unk_3E);

    int xd = proc->unk_34 - proc->unk_30;
    int yd = proc->unk_36 - proc->unk_32;

    int xunk = xd * SIN_Q12(var >> 9) / proc->unk_44;
    int yunk = yd * SIN_Q12(var >> 9) / proc->unk_44;

    int x = ((xd * var) >> 16) + yunk;
    int y = ((yd * var) >> 16) - xunk;

    x = x + proc->unk_30 - gBmSt.camera.x;
    y = y + proc->unk_32 - gBmSt.camera.y;

    if ((x >= -16 && x <= DISPLAY_WIDTH) && (y >= -32 && y <= DISPLAY_HEIGHT))
    {
        PutSprite(4, x, y - 12, Sprite_16x16, TILEREF(6, 0));
        sub_8022774(4, x, y, proc->unit);
    }

    proc->unk_3C++;

    if (proc->unk_3C > proc->unk_3E)
        Proc_Break(proc);
}

static void sub_801CEE0(struct UnkProc2* proc)
{
    proc->unit->x = proc->unk_34 / 16;
    proc->unit->y = proc->unk_36 / 16;

    RefreshEntityMaps();
    RefreshMapSprites();
}

void sub_801CF10(ProcPtr parent, struct Unit* unit, int x, int y)
{
    struct UnkProc2* proc;

    proc = SpawnProcLocking(ProcScr_Unk_085C59F8, parent);

    proc->unit = unit;

    proc->unk_34 = x * 16;
    proc->unk_36 = y * 16;

    HideUnitSMS(unit);
}

void sub_801CF48(void);
void sub_801CF8C(void);
void sub_801CFD0(void);

void sub_801CF48(void)
{
    REG_BLDCNT = 0x3C42;

    REG_BLDCA = gBmSt.unk_3A;
    REG_BLDCB = gBmSt.unk_3B;

    SetNextVCount(72);
    SetOnVMatch(sub_801CF8C);
}

void sub_801CF8C(void)
{
    REG_BLDCNT = 0x3E41;

    REG_BLDCA = gBmSt.unk_38;
    REG_BLDCB = gBmSt.unk_39;

    SetNextVCount(96);
    SetOnVMatch(sub_801CFD0);
}

void sub_801CFD0(void)
{
    REG_BLDCNT = 0x3C42;

    REG_BLDCA = gBmSt.unk_3A;
    REG_BLDCB = gBmSt.unk_3B;

    SetNextVCount(0);
    SetOnVMatch(sub_801CF48);
}

void sub_801D014(void)
{
    u16* tm = gBg0Tm + TM_OFFSET(0, 9);
    int i;

    for (i = 0; i < 0x60; ++i)
        *tm++ = TILEREF(0x140 + i, 5);

    EnableBgSync(BG0_SYNC_BIT);
}

void sub_801D03C(struct GenericProc* proc)
{
    if (GetCurrentBgmSong() != GetActiveMapSong())
        FadeBgmOut(4);

    PlaySe(0x73); // TODO: song ids

    proc->unk4C = 15;
}
