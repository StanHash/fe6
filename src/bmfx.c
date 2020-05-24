
// TODO: better name for this file

#include "common.h"

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "icon.h"
#include "sound.h"
#include "sprite.h"
#include "face.h"
#include "anim.h"
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

extern u16 gChapterIntroMotifTmBuf[];

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

struct ShowMapChangeProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ int mcId;
    /* 30 */ int altSong;
    /* 34 */ int sndx;
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

static void PhaseIntroText_Init(struct GenericProc* proc);
static void PhaseIntroText_PutText(struct GenericProc* proc);
static void PhaseIntroText_InLoop(struct GenericProc* proc);
static void PhaseIntroText_OutLoop(struct GenericProc* proc);
static void PhaseIntroText_Clear(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_PhaseIntroText[] =
{
    PROC_CALL(PhaseIntroText_Init),

    PROC_SLEEP(6),

    PROC_CALL(PhaseIntroText_PutText),

    PROC_REPEAT(PhaseIntroText_InLoop),
    PROC_SLEEP(14),
    PROC_REPEAT(PhaseIntroText_OutLoop),

    PROC_CALL(PhaseIntroText_Clear),

    PROC_END,
};

static void PhaseIntroSquares_Init(struct GenericProc* proc);
static void PhaseIntroSquares_InLoop(struct GenericProc* proc);
static void PhaseIntroSquares_OutLoop(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_PhaseIntroSquares[] =
{
    PROC_CALL(PhaseIntroSquares_Init),
    PROC_REPEAT(PhaseIntroSquares_InLoop),
    PROC_REPEAT(PhaseIntroSquares_OutLoop),

    PROC_END,
};

static void PhaseIntroBlendBox_Init(struct GenericProc* proc);
static void PhaseIntroBlendBox_InLoop(struct GenericProc* proc);
static void PhaseIntroBlendBox_OutLoop(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_PhaseIntroBlendBox[] =
{
    PROC_CALL(PhaseIntroBlendBox_Init),
    PROC_REPEAT(PhaseIntroBlendBox_InLoop),
    PROC_REPEAT(PhaseIntroBlendBox_OutLoop),

    PROC_END,
};

static void PhaseIntro_EndIfNoUnits(ProcPtr proc);
static void PhaseIntro_InitGraphics(ProcPtr proc);
static void PhaseIntro_InitDisp(ProcPtr proc);
static void PhaseIntro_WaitForEnd(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_PhaseIntro[] =
{
    PROC_CALL(PhaseIntro_EndIfNoUnits),
    PROC_CALL(PhaseIntro_InitGraphics),

    PROC_START_CHILD(ProcScr_PhaseIntroText),
    PROC_START_CHILD(ProcScr_PhaseIntroSquares),
    PROC_START_CHILD(ProcScr_PhaseIntroBlendBox),

    PROC_CALL(PhaseIntro_InitDisp),

    PROC_REPEAT(PhaseIntro_WaitForEnd),

    PROC_CALL(StartMapSongBgm),

    PROC_END,
};

static void GasTrapAnim_Init(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_GasTrapAnim[] =
{
    PROC_SLEEP(0),

    PROC_CALL(GasTrapAnim_Init),
    PROC_WHILE(AnimProcExists),

    PROC_END,
};

static void FireTrapAnim_Init(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_FireTrapAnim[] =
{
    PROC_SLEEP(0),

    PROC_CALL(FireTrapAnim_Init),
    PROC_WHILE(AnimProcExists),

    PROC_END,
};

static void ArrowTrapAnim_Init(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_ArrowTrapAnim[] =
{
    PROC_SLEEP(0),

    PROC_CALL(ArrowTrapAnim_Init),
    PROC_WHILE(AnimProcExists),

    PROC_SLEEP(15),

    PROC_END,
};

static void sub_801D8B8(struct ShowMapChangeProc* proc);
static void sub_801D8E4(struct ShowMapChangeProc* proc);

struct ProcScr CONST_DATA ProcScr_MapChange_085C5B50[] =
{
    PROC_SLEEP(0),

    PROC_CALL(sub_801D8B8),
    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(sub_801D8E4),
    PROC_WHILE(IsMapFadeActive),

    PROC_END,
};

static void sub_801D95C(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_PikeTrapAnim[] =
{
    PROC_SLEEP(0),

    PROC_CALL(sub_801D95C),
    PROC_WHILE(AnimProcExists),

    PROC_END,
};

static void sub_801DA1C(struct GenericProc* proc);
static void sub_801DA24(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C5BA0[] =
{
    PROC_CALL(sub_801DA1C),
    PROC_REPEAT(sub_801DA24),

    PROC_CALL(ClearBg0Bg1),

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

static void PhaseIntroVMatchHi(void);
static void PhaseIntroVMatchMid(void);
static void PhaseIntroVMatchLo(void);

static void PhaseIntroVMatchHi(void)
{
    REG_BLDCNT = BLDCNT_ALPHA
        | BLDCNT_TARGETA(0, 1, 0, 0, 0)
        | BLDCNT_TARGETB(0, 0, 1, 1, 1) | BLDCNT_TARGETB_BD;

    REG_BLDCA = gBmSt.altBlendB_ca;
    REG_BLDCB = gBmSt.altBlendB_cb;

    SetNextVCount(72);
    SetOnVMatch(PhaseIntroVMatchMid);
}

static void PhaseIntroVMatchMid(void)
{
    REG_BLDCNT = BLDCNT_ALPHA
        | BLDCNT_TARGETA(1, 0, 0, 0, 0)
        | BLDCNT_TARGETB(0, 1, 1, 1, 1) | BLDCNT_TARGETB_BD;

    REG_BLDCA = gBmSt.altBlendA_ca;
    REG_BLDCB = gBmSt.altBlendA_cb;

    SetNextVCount(96);
    SetOnVMatch(PhaseIntroVMatchLo);
}

static void PhaseIntroVMatchLo(void)
{
    REG_BLDCNT = BLDCNT_ALPHA
        | BLDCNT_TARGETA(0, 1, 0, 0, 0)
        | BLDCNT_TARGETB(0, 0, 1, 1, 1) | BLDCNT_TARGETB_BD;

    REG_BLDCA = gBmSt.altBlendB_ca;
    REG_BLDCB = gBmSt.altBlendB_cb;

    SetNextVCount(0);
    SetOnVMatch(PhaseIntroVMatchHi);
}

static void PhaseIntroText_PutText(struct GenericProc* proc)
{
    u16* tm = gBg0Tm + TM_OFFSET(0, 9);
    int i;

    for (i = 0; i < 0x60; ++i)
        *tm++ = TILEREF(BGCHR_PHASE_CHANGE_NAME + i, BGPAL_PHASE_CHANGE);

    EnableBgSync(BG0_SYNC_BIT);
}

static void PhaseIntroText_Init(struct GenericProc* proc)
{
    if (GetCurrentBgmSong() != GetActiveMapSong())
        FadeBgmOut(4);

    PlaySe(0x73); // TODO: song ids

    proc->unk4C = 15;
}

static void PhaseIntroText_InLoop(struct GenericProc* proc)
{
    SetBgOffset(0, Interpolate(INTERPOLATE_CUBIC, -28, -64, proc->unk4C, 0x10), 0);

    gBmSt.altBlendA_ca++;
    gBmSt.altBlendA_cb--;

    proc->unk4C--;

    if (proc->unk4C < 0)
    {
        proc->unk4C = 15;
        Proc_Break(proc);
    }
}

static void PhaseIntroText_OutLoop(struct GenericProc* proc)
{
    SetBgOffset(0, Interpolate(INTERPOLATE_RCUBIC, +36, -28, proc->unk4C, 0x10), 0);

    gBmSt.altBlendA_ca--;
    gBmSt.altBlendA_cb++;

    proc->unk4C--;

    if (proc->unk4C < 0)
    {
        proc->unk4C = 15;
        Proc_Break(proc);
    }
}

static void PhaseIntroText_Clear(struct GenericProc* proc)
{
    TmFill(gBg0Tm, 0);
    EnableBgSync(BG0_SYNC_BIT);
}

static void PhaseIntroSquares_Init(struct GenericProc* proc)
{
    proc->unk4C = 4;
}

static void PhaseIntroSquares_InLoop(struct GenericProc* proc)
{
    int ix, iy;

    for (iy = 10-1; iy >= 0; --iy)
    {
        for (ix = 15-1; ix >= 0; --ix)
        {
            int num = (1 - proc->unk4C) + (10 + ix) + (10 - iy);

            if (num > 0x10)
                num = 0x10;

            if (num < 0)
                num = 0;

            num = (0x10 - num) & 0xFE;

            gBg1Tm[TM_OFFSET(ix*2+0, iy*2+0)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x00, BGPAL_PHASE_CHANGE);
            gBg1Tm[TM_OFFSET(ix*2+1, iy*2+0)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x01, BGPAL_PHASE_CHANGE);
            gBg1Tm[TM_OFFSET(ix*2+0, iy*2+1)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x20, BGPAL_PHASE_CHANGE);
            gBg1Tm[TM_OFFSET(ix*2+1, iy*2+1)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x21, BGPAL_PHASE_CHANGE);
        }
    }

    proc->unk4C++;

    EnableBgSync(BG1_SYNC_BIT);

    if (proc->unk4C == 0x22)
    {
        proc->unk4C = 0;
        Proc_Break(proc);
    }
}

static void PhaseIntroSquares_OutLoop(struct GenericProc* proc)
{
    int ix, iy;

    for (iy = 10-1; iy >= 0; --iy)
    {
        for (ix = 15-1; ix >= 0; --ix)
        {
            int num = (1 - proc->unk4C) + (10 + ix) + (10 - iy);

            if (num > 0x10)
                num = 0x10;

            if (num < 0)
                num = 0;

            num = num & 0xFE;

            gBg1Tm[TM_OFFSET(ix*2+0, iy*2+0)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x01, BGPAL_PHASE_CHANGE) + TILE_HFLIP;
            gBg1Tm[TM_OFFSET(ix*2+1, iy*2+0)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x00, BGPAL_PHASE_CHANGE) + TILE_HFLIP;
            gBg1Tm[TM_OFFSET(ix*2+0, iy*2+1)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x21, BGPAL_PHASE_CHANGE) + TILE_HFLIP;
            gBg1Tm[TM_OFFSET(ix*2+1, iy*2+1)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x20, BGPAL_PHASE_CHANGE) + TILE_HFLIP;
        }
    }

    proc->unk4C++;

    EnableBgSync(BG1_SYNC_BIT);

    if (proc->unk4C == 0x24)
    {
        proc->unk4C = 0;
        Proc_Break(proc);
    }
}

static void PhaseIntroBlendBox_Init(struct GenericProc* proc)
{
    proc->unk4C = 4;
}

static void PhaseIntroBlendBox_InLoop(struct GenericProc* proc)
{
    int yoff, blend;

    yoff = Interpolate(INTERPOLATE_RCUBIC, 16, 60, proc->unk4C, 0x20);

    SetWin0Box(0, 8 + yoff, DISPLAY_WIDTH, -0x60 - yoff);

    blend = Interpolate(INTERPOLATE_LINEAR, 0, 7, proc->unk4C, 0x20);

    gBmSt.altBlendB_ca = blend;
    gBmSt.altBlendB_cb = 0x10 - blend;

    proc->unk4C++;

    if (proc->unk4C == 0x20)
        Proc_Break(proc);
}

static void PhaseIntroBlendBox_OutLoop(struct GenericProc* proc)
{
    int yoff, blend;

    yoff = Interpolate(INTERPOLATE_RCUBIC, 0, 60, proc->unk4C, 0x20);

    SetWin0Box(0, 8 + yoff, DISPLAY_WIDTH, -0x60 - yoff);

    blend = Interpolate(INTERPOLATE_LINEAR, 0, 7, proc->unk4C, 0x20);

    gBmSt.altBlendB_ca = blend;
    gBmSt.altBlendB_cb = 0x10 - blend;

    proc->unk4C--;

    if (proc->unk4C < 0)
        Proc_Break(proc);
}

static void PhaseIntro_EndIfNoUnits(ProcPtr proc)
{
    if (sub_802097C(gPlaySt.faction) == 0)
        Proc_End(proc);
}

static void PhaseIntro_InitGraphics(ProcPtr proc)
{
    Decompress(Img_PhaseChangeSquares, (u8*) VRAM + CHR_SIZE*BGCHR_PHASE_CHANGE_SQUARES);

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, 0, 0);

    switch (gPlaySt.faction)
    {

    case FACTION_BLUE:
        Decompress(Img_PhaseChangePlayer, (u8*) VRAM + CHR_SIZE*BGCHR_PHASE_CHANGE_NAME);
        ApplyPalette(Pal_PhaseChangePlayer, BGPAL_PHASE_CHANGE);

        break;

    case FACTION_RED:
        Decompress(Img_PhaseChangeEnemy, (u8*) VRAM + CHR_SIZE*BGCHR_PHASE_CHANGE_NAME);
        ApplyPalette(Pal_PhaseChangeEnemy, BGPAL_PHASE_CHANGE);

        break;

    case FACTION_GREEN:
        Decompress(Img_PhaseChangeOther, (u8*) VRAM + CHR_SIZE*BGCHR_PHASE_CHANGE_NAME);
        ApplyPalette(Pal_PhaseChangeOther, BGPAL_PHASE_CHANGE);

        break;

    }
}

static void PhaseIntro_InitDisp(ProcPtr proc)
{
    SetWinEnable(1, 0, 0);

    SetWin0Box(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);

    SetWin0Layers(1, 0, 1, 1, 1);
    SetWOutLayers(1, 1, 1, 1, 1);

    gDispIo.winCt.win0_enableBlend = 1;
    gDispIo.winCt.wout_enableBlend = 1;

    gBmSt.altBlendB_ca = 0;
    gBmSt.altBlendB_cb = 0x10;

    gBmSt.altBlendA_ca = 0;
    gBmSt.altBlendA_cb = 0x10;

    SetBlendAlpha(gBmSt.altBlendB_ca, gBmSt.altBlendB_cb);

    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 1, 1);

    SetVCount(0);
    SetOnVMatch(PhaseIntroVMatchHi);
}

static void PhaseIntro_WaitForEnd(ProcPtr proc)
{
    SetBlendAlpha(gBmSt.altBlendB_ca, gBmSt.altBlendB_cb);

    if (Proc_Find(ProcScr_PhaseIntroText) == NULL && Proc_Find(ProcScr_PhaseIntroSquares) == NULL && Proc_Find(ProcScr_PhaseIntroBlendBox) == NULL)
    {
        ClearBg0Bg1();

        SetOnVMatch(NULL);

        SetBgOffset(0, 0, 0);
        SetBgOffset(1, 0, 0);
        SetBgOffset(2, 0, 0);

        Proc_Break(proc);
    }
}

void sub_801D680(int x, int y)
{
    int cmd = MOVE_CMD_FACE_BASE + sub_80629FC(gActiveUnit->x, gActiveUnit->y, x, y);

    gWorkingMoveScr[0] = cmd;
    gWorkingMoveScr[1] = MOVE_CMD_HALT;

    sub_805FC80(gWorkingMoveScr);
}

static void GasTrapAnim_Init(struct GenericProc* proc)
{
    int x, y, oam2;

    u8 const* img = NULL;
    u16 const* anim = NULL;
    int animNum = 0;

    switch (proc->unk4A)
    {

    case FACING_UP:
        img = Img_GasTrapVertical;
        anim = Anim_GasTrapVertical;
        break;

    case FACING_DOWN:
        img = Img_GasTrapVertical;
        anim = Anim_GasTrapVertical;
        animNum = 1;
        break;

    case FACING_LEFT:
        img = Img_GasTrapHorizontal;
        anim = Anim_GasTrapHorizontal;
        animNum = 1;
        break;

    case FACING_RIGHT:
        img = Img_GasTrapHorizontal;
        anim = Anim_GasTrapHorizontal;
        break;

    }

    Decompress(img, (u8*) OBJ_VRAM0 + CHR_SIZE*OBJCHR_TRAPFX);
    ApplyPalette(Pal_GasTrap, 0x10 + OBJPAL_TRAPFX);

    x = proc->x*16 + 8 - gBmSt.camera.x;
    y = proc->y*16 + 8 - gBmSt.camera.y;
    oam2 = OAM2_CHR(OBJCHR_TRAPFX) | OAM2_PAL(OBJPAL_TRAPFX) | OAM2_LAYER(1);

    StartAnimProc(anim, x, y, oam2, animNum, 0);
    PlaySeSpacial(0xBA, x+8); // TODO: song ids
}

void StartGasTrapAnim(ProcPtr parent, int x, int y, int facing)
{
    struct GenericProc* proc;

    proc = SpawnProcLocking(ProcScr_GasTrapAnim, parent);

    proc->x = x;
    proc->y = y;
    proc->unk4A = facing;
}

static void FireTrapAnim_Init(struct GenericProc* proc)
{
    int x, y, oam2;

    Decompress(Img_FireTrap, (u8*) OBJ_VRAM0 + CHR_SIZE*OBJCHR_TRAPFX);
    ApplyPalette(Pal_FireTrap, 0x10 + OBJPAL_TRAPFX);

    x = proc->x*16 + 8 - gBmSt.camera.x;
    y = proc->y*16 + 8 - gBmSt.camera.y;
    oam2 = OAM2_CHR(OBJCHR_TRAPFX) | OAM2_PAL(OBJPAL_TRAPFX) | OAM2_LAYER(1);

    StartAnimProc(Anim_FireTrap, x, y, oam2, 0, 0);
    PlaySeSpacial(0xBF, x+8); // TODO: song ids
}

void StartFireTrapAnim(ProcPtr parent, int x, int y)
{
    struct GenericProc* proc;

    proc = SpawnProcLocking(ProcScr_FireTrapAnim, parent);

    proc->x = x;
    proc->y = y;
}

static void ArrowTrapAnim_Init(struct GenericProc* proc)
{
    int x, oam2;

    Decompress(Img_ArrowTrap, (u8*) OBJ_VRAM0 + CHR_SIZE*OBJCHR_TRAPFX);
    ApplyPalette(Pal_ArrowTrap, 0x10 + OBJPAL_TRAPFX);

    x = proc->x*16 + 8 - gBmSt.camera.x;
    oam2 = OAM2_CHR(OBJCHR_TRAPFX) | OAM2_PAL(OBJPAL_TRAPFX) | OAM2_LAYER(1);

    StartAnimProc(Anim_ArrowTrap, x, DISPLAY_HEIGHT/2, oam2, 0, 0);
    PlaySeSpacial(0xBC, x+8); // TODO: song ids

    CameraMoveWatchPosition(proc, proc->x, 31);
}

void StartArrowTrapAnim(ProcPtr parent, int x)
{
    struct GenericProc* proc;

    proc = SpawnProcLocking(ProcScr_ArrowTrapAnim, parent);
    proc->x = x;
}

static void sub_801D8B8(struct ShowMapChangeProc* proc)
{
    struct MapChangeInfo const* info = GetMapChange(proc->mcId);

    int x = info->x + info->width/2;
    int y = info->y + info->height/2;

    CameraMoveWatchPosition(proc, x, y);

    proc->sndx = x;
}

static void sub_801D8E4(struct ShowMapChangeProc* proc)
{
    int x, song;

    RenderMapForFade();

    sub_80188F4();
    RenderMap();

    StartMapFade(FALSE);

    if (proc->altSong)
        song = 0xBE; // TODO: song ids
    else
        song = 0xBD; // TODO: song ids

    PlaySeSpacial(song, proc->sndx /* *16 + 8 */ - gBmSt.camera.x);
}

void sub_801D920(ProcPtr parent, int unused, int trapid)
{
    struct ShowMapChangeProc* proc;
    struct Trap* trap;

    proc = SpawnProcLocking(ProcScr_MapChange_085C5B50, parent);

    trap = GetTrap(trapid);
    trap->extra ^= 1;

    if (trap->extra != 0)
        proc->mcId = trap->y;
    else
        proc->mcId = trap->x;

    proc->altSong = trap->extra;
}

static void sub_801D95C(struct GenericProc* proc)
{
    int x, y, oam2;

    Decompress(Img_PikeTrap, (u8*) OBJ_VRAM0 + CHR_SIZE*OBJCHR_TRAPFX);
    ApplyPalette(Pal_PikeTrap, 0x10 + OBJPAL_TRAPFX);

    x = proc->x*16 + 8 - gBmSt.camera.x;
    y = proc->y*16 + 8 - gBmSt.camera.y;
    oam2 = OAM2_CHR(OBJCHR_TRAPFX) | OAM2_PAL(OBJPAL_TRAPFX) | OAM2_LAYER(1);

    StartAnimProc(Anim_PikeTrap, x, y, oam2, proc->unk4A, 0);
    PlaySeSpacial(0xBB, x + 8);
}

void sub_801D9D0(ProcPtr parent, int x, int y, int facing)
{
    struct GenericProc* proc;

    proc = SpawnProcLocking(ProcScr_PikeTrapAnim, parent);

    proc->x = x;
    proc->y = y;

    switch (facing)
    {

    case FACING_RIGHT:
        proc->unk4A = 0;
        break;

    case FACING_LEFT:
        proc->unk4A = 1;
        break;

    case FACING_UP:
        proc->unk4A = 2;
        break;

    }
}

static void sub_801DA1C(struct GenericProc* proc)
{
    proc->unk4C = 120; // 2 seconds
}

static void sub_801DA24(struct GenericProc* proc)
{
    proc->unk4C--;

    if (proc->unk4C < 0 || (gKeySt->pressed & (A_BUTTON | B_BUTTON)))
        Proc_Break(proc);
}

void sub_801DA54(ProcPtr parent, int icon, char const* str)
{
    int x, len = GetStringTextLen(str);

    if (icon >= 0)
        len += 16;

    len += 24;

    x = (DISPLAY_WIDTH - len) / 16;

    sub_8041358(x, 8, len / 8, 4, 0);

    if (icon >= 0)
    {
        InitIcons();
        ApplyIconPalettes(BGPAL_ICONS);

        PutIcon(gBg0Tm + TM_OFFSET(1 + x, 9), icon, TILEREF(0, BGPAL_ICONS));
        x += 2;
    }

    ResetTextFont();
    PutDrawText(NULL, gBg0Tm + TM_OFFSET(1 + x, 9), TEXT_COLOR_SYSTEM_WHITE, 0, 20, str);

    SpawnProcLocking(ProcScr_Unk_085C5BA0, parent);
}

void sub_801DAE4(void)
{
    int offset = (GetGameTime()/2) % 0x100;

    SetBgOffset(3, offset, offset);
}

void sub_801DB00(struct GenericProc* proc)
{
    struct GenericProc* parent = proc->proc_parent;

    parent->unk50 = 0;
    proc->unk50 = 0;
}

void sub_801DB10(struct GenericProc* proc)
{
    if (gKeySt->pressed & (A_BUTTON | B_BUTTON | START_BUTTON))
        proc->unk50 = 1;

    if (proc->unk50 != 0)
    {
        struct GenericProc* parent = proc->proc_parent;

        if (parent->unk50)
        {
            Proc_Goto(parent, parent->unk50);
            Proc_End(proc);
        }
    }
}

void sub_801DB5C(void)
{
    int ix, iy;
    int tile = 0;

    TmFill(gBg2Tm, 0);

    Decompress(Tm_ChapterIntroMotif, gChapterIntroMotifTmBuf);

    for (iy = 0; iy < 18; ++iy)
        for (ix = 0; ix < 24; ++ix)
            gBg2Tm[TM_OFFSET(3 + ix, 1 + iy)] = TILEREF(1 + gChapterIntroMotifTmBuf[tile++], BGPAL_CHAPTERINTRO_MOTIF);
}

void sub_801DBC8(void)
{
    int ix, iy;

    int tilerefA = TILEREF(0x3FF & (BGCHR_CHAPTERINTRO_FOG+0x00), BGPAL_CHAPTERINTRO_FOG);
    int tilerefB = TILEREF(0x3FF & (BGCHR_CHAPTERINTRO_FOG+0x10), BGPAL_CHAPTERINTRO_FOG);

    for (iy = 0; iy < 8; ++iy)
    {
        for (ix = 0; ix < 16; ++ix)
        {
            gBg3Tm[TM_OFFSET(0x00+ix, iy+0x00)] = tilerefA;
            gBg3Tm[TM_OFFSET(0x10+ix, iy+0x00)] = tilerefA;
            gBg3Tm[TM_OFFSET(0x00+ix, iy+0x10)] = tilerefA;
            gBg3Tm[TM_OFFSET(0x10+ix, iy+0x10)] = tilerefA;

            gBg3Tm[TM_OFFSET(0x00+ix, iy+0x08)] = tilerefB;
            gBg3Tm[TM_OFFSET(0x10+ix, iy+0x08)] = tilerefB;
            gBg3Tm[TM_OFFSET(0x00+ix, iy+0x18)] = tilerefB;
            gBg3Tm[TM_OFFSET(0x10+ix, iy+0x18)] = tilerefB;

            tilerefA += 1;
            tilerefB += 1;
        }

        tilerefA += 0x10;
        tilerefB += 0x10;
    }
}

void sub_801DC9C(void)
{
    int ix, iy;

    int tilerefA = TILEREF(0x3FF & (BGCHR_CHAPTERINTRO_FOG+0x00), BGPAL_CHAPTERINTRO_FOG);
    int tilerefB = TILEREF(0x3FF & (BGCHR_CHAPTERINTRO_FOG+0x10), BGPAL_CHAPTERINTRO_FOG);

    for (iy = 0; iy < 8; ++iy)
    {
        for (ix = 0; ix < 16; ++ix)
        {
            gBg2Tm[TM_OFFSET(0x0F-ix, iy+0x00)] = tilerefA + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x1F-ix, iy+0x00)] = tilerefA + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x0F-ix, iy+0x10)] = tilerefA + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x1F-ix, iy+0x10)] = tilerefA + TILE_HFLIP;

            gBg2Tm[TM_OFFSET(0x0F-ix, iy+0x08)] = tilerefB + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x1F-ix, iy+0x08)] = tilerefB + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x0F-ix, iy+0x18)] = tilerefB + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x1F-ix, iy+0x18)] = tilerefB + TILE_HFLIP;

            tilerefA += 1;
            tilerefB += 1;
        }

        tilerefA += 0x10;
        tilerefB += 0x10;
    }
}

void sub_801DD84(void)
{
    InitBmBgLayers();

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, 0, 0);
    SetBgOffset(3, 0, 0);

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    TmFill(gBg2Tm, 0);
    TmFill(gBg3Tm, 0);

    SetBgChrOffset(2, CHR_SIZE*BGCHR_CHAPTERINTRO_MOTIF);

    SetWinEnable(1, 0, 0);

    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(0, 0, 1, 1, 1);

    gDispIo.winCt.win0_enableBlend = 1;
    gDispIo.winCt.wout_enableBlend = 1;

    SetWin0Box(0, 0, 0, 0);

    sub_8070CB4(8, BGPAL_CHAPTERINTRO_0);
    sub_8070CB4(0, BGPAL_CHAPTERINTRO_1);

    sub_8070D78(BGCHR_CHAPTERINTRO_80);

    sub_8070D08(BGCHR_CHAPTERINTRO_100, sub_8070E0C(&gPlaySt));

    sub_8070DE8(gBg1Tm + TM_OFFSET(0, 8), BGPAL_CHAPTERINTRO_0);
    sub_8070DA8(gBg0Tm + TM_OFFSET(3, 9), BGPAL_CHAPTERINTRO_1);

    sub_8001D0C();
    sub_8001E68(BGPAL_CHAPTERINTRO_0, 2, 0x40, -1);

    sub_8000234_t();

    EnablePalSync();

    Decompress(Img_ChapterIntroFog, (u8*) VRAM + CHR_SIZE*BGCHR_CHAPTERINTRO_FOG);
    ApplyPalette(Pal_ChapterIntroFog, BGPAL_CHAPTERINTRO_FOG);

    Decompress(Img_ChapterIntroMotif, (u8*) VRAM + CHR_SIZE*(BGCHR_CHAPTERINTRO_MOTIF+1));
    ApplyPalette(Pal_ChapterIntroMotif, BGPAL_CHAPTERINTRO_MOTIF);

    SetBlankChr(BGCHR_CHAPTERINTRO_MOTIF);

    gPal[0] = 0;
    sub_801DB5C();
    sub_801DBC8();

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT + BG2_SYNC_BIT + BG3_SYNC_BIT);
}

void sub_801DF34(struct GenericProc* proc)
{
    SetDispEnable(0, 0, 0, 1, 1);
    SetBlendTargetA(0, 0, 0, 1, 1);

    proc->unk4C = 12;

    FadeBgmOut(2);
}

void sub_801DF78(struct GenericProc* proc)
{
    SetBlendDarken(proc->unk4C);

    if (proc->unk50 == 3 || (GetGameTime() % 4) == 0)
    {
        proc->unk4C--;

        if (proc->unk4C < 0)
            Proc_Break(proc);
    }
}
