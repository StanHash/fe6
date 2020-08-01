
#include "chapter.h"

#include "hardware.h"
#include "game-controller.h"
#include "bm.h"
#include "map.h"
#include "faction.h"
#include "battle.h"
#include "trap.h"
#include "unitsprite.h"
#include "bmio.h"
#include "arena.h"
#include "action.h"
#include "chapter-info.h"
#include "mu.h"

#include "constants/chapters.h"

static void ResumeMapMainDuringPhase(ProcPtr mapmain);
static void ResumeMapMainDuringAction(ProcPtr mapmain);
static void ResumeMapMainDuringBerserk(ProcPtr mapmain);
static void ResumeMapMainDuringArena(ProcPtr mapmain);
static void ResumeMapMainDuringPhaseChange(ProcPtr mapmain);

struct ProcScr CONST_DATA ProcScr_DelayedUnlockBmDisplay[] =
{
    PROC_SLEEP(0),

    PROC_CALL(UnlockBmDisplay),
    PROC_END,
};

int GetTextPrintDelay(void)
{
    u8 lut[4] = { 8, 4, 1, 0 };

    return lut[gPlaySt.configTextSpeed];
}

Bool IsFirstPlaythrough(void)
{
    if (!sub_80846F0())
        return TRUE;

    if (gPlaySt.flags & PLAY_FLAG_5)
        return FALSE;

    return gPlaySt.unk_1D_5;
}

void InitPlayConfig(int isHardMode)
{
    CpuFill16(0, &gPlaySt, sizeof(gPlaySt));

    gPlaySt.chapter = CHAPTER_CH01;

    if (isHardMode)
        gPlaySt.flags |= PLAY_FLAG_HARD;

    gPlaySt.configBattleAnim = 0; // TODO: battle anim type constants
    gPlaySt.unk_1C_2 = 0;
    gPlaySt.unk_1C_3 = 0;
    gPlaySt.configNoAutoCursor = FALSE;
    gPlaySt.configTextSpeed = 1;
    gPlaySt.unk_1C_8 = 0;
    gPlaySt.configBgmDisable = FALSE;
    gPlaySt.configSeDisable = FALSE;
    gPlaySt.configWindowColor = 0;
    gPlaySt.configNoAutoEndTurn = FALSE;
    gPlaySt.unk_1D_8 = 0;
    gPlaySt.unk_1E_3 = 0;
    gPlaySt.debugRedControl = 0;
    gPlaySt.debugGreenControl = 0;
    gPlaySt.unk_1C_1 = 0;
    gPlaySt.unk_1D_5 = 0;
}

void ResetBmSt(void)
{
    int lock = gBmSt.lock;

    CpuFill16(0, &gBmSt, sizeof(gBmSt));

    gBmSt.lock = lock;
}

void StartChapter(struct GenericProc* parent)
{
    InitBgs(NULL);

    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    ResetBmSt();

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();
    sub_806B970();
    ResetUnitSprites();
    InitTraps();

    gPlaySt.faction = FACTION_GREEN;
    gPlaySt.turn = 0;
    gPlaySt.vision = GetChapterInfo(gPlaySt.chapter)->fog;
    gPlaySt.weather = GetChapterInfo(gPlaySt.chapter)->weather;

    InitBmBgLayers();

    InitMapForChapter(gPlaySt.chapter);
    InitMapTraps();

    gPlaySt.unk_04 = GetGameTime();
    gPlaySt.supportGain = 0;

    sub_806B604();

    StartMapMain(parent);

    gPal[0] = 0;
    EnablePalSync();

    SetBlendTargetA(1, 1, 1, 1, 1); SetBlendBackdropA(1);
    SetBlendDarken(0x10);
}

void sub_8029084(void)
{
    InitBgs(NULL);

    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();
    ResetUnitSprites();

    gBmSt.flags |= BM_FLAG_5;

    InitTraps();

    gPlaySt.weather = GetChapterInfo(gPlaySt.chapter)->weather;

    InitBmBgLayers();

    InitMapForChapter(gPlaySt.chapter);
    InitMapTraps();

    EndBmVSync();
    StartBmVSync();
    SpawnProc(ProcScr_MapTask, PROC_TREE_4);

    gPal[0] = 0;
    EnablePalSync();

    SetDispEnable(1, 1, 1, 0, 0);
}

void ResumeChapterFromSuspend(struct GenericProc* parent)
{
    ProcPtr mapmain;

    if (gPlaySt.chapter < 0)
        sub_80866EC();

    InitBgs(NULL);

    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    ResetBmSt();

    SetMapCursorPosition(gPlaySt.xCursor, gPlaySt.yCursor);

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();
    ResetUnitSprites();

    InitMapForChapter(gPlaySt.chapter);

    gBmSt.unk_3C = TRUE;

    mapmain = StartMapMain(parent);

    gBmSt.camera.x = GetCameraCenteredX(16*gBmSt.cursor.x);
    gBmSt.camera.y = GetCameraCenteredY(16*gBmSt.cursor.y);

    switch (gAction.suspendPoint)
    {

    case SUSPEND_POINT_DURING_ACTION:
        ResumeMapMainDuringAction(mapmain);
        break;

    case SUSPEND_POINT_PLAYER_PHASE:
    case SUSPEND_POINT_AI_PHASE:
        ResumeMapMainDuringPhase(mapmain);
        break;

    case SUSPEND_POINT_BERSERK_PHASE:
        ResumeMapMainDuringBerserk(mapmain);
        break;

    case SUSPEND_POINT_DURING_ARENA:
        ResumeMapMainDuringArena(mapmain);
        break;

    case SUSPEND_POINT_CHANGE_PHASE:
        ResumeMapMainDuringPhaseChange(mapmain);
        break;

    }

    SetBlendTargetA(1, 1, 1, 1, 1); SetBlendBackdropA(1);
    SetBlendDarken(0x10);
}

void sub_8029240(void)
{
    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();
    ClearBg0Bg1();
    SetWinEnable(0, 0, 0);
    SetBlendNone();

    SetBlankChr(0);

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
}

void sub_80292B8(void)
{
    ApplySystemObjectsGraphics();

    MU_Start(&gBattleUnitA.unit);
    MU_SetDefaultFacing_Auto();

    SpawnProc(ProcScr_DelayedUnlockBmDisplay, PROC_TREE_3);
}

void InitBmDisplay(void)
{
    InitBgs(NULL);
    ApplySystemGraphics();
    ApplyChapterMapGraphics(gPlaySt.chapter);
    AllocWeatherParticles(gPlaySt.weather);
    RenderMap();
    RefreshUnitSprites();
    ApplyUnitSpritePalettes();
    ForceSyncUnitSpriteSheet();
    InitSystemTextFont();
}

ProcPtr StartMapMain(struct GenericProc* parent)
{
    struct GenericProc* proc = SpawnProc(ProcScr_BmMain, PROC_TREE_2);
    proc->ptr = parent;

    parent->proc_lockCnt++;

    StartBmVSync();
    SpawnProc(ProcScr_MapTask, PROC_TREE_4);

    return proc;
}

void EndMapMain(void)
{
    struct GenericProc* mapmain;
    struct GenericProc* parent;

    Proc_EndEachMarked(PROC_MARK_1);

    mapmain = Proc_Find(ProcScr_BmMain);
    parent = mapmain->ptr;

    parent->proc_lockCnt--;

    Proc_End(mapmain);
}

#if NONMATCHING

void CleanupUnitsBeforeChapter(void)
{
    // Clear non-blue units

    FOR_UNITS(FACTION_GREEN+1, FACTION_PURPLE, unit,
    {
        ClearUnit(unit);
    })

    // Cleanup blue unit states

    if (gPlaySt.chapter != CHAPTER_UNK_19)
    {
        FOR_UNITS(FACTION_BLUE+1, FACTION_BLUE+0x40, unit,
        {
            SetUnitHp(unit, GetUnitMaxHp(unit));
            SetUnitStatus(unit, UNIT_STATUS_NONE);

            unit->torch = 0;
            unit->barrier = 0;

            unit->state &= US_DEAD | US_SOLOANIM_1 | US_SOLOANIM_2;

            if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_SUPPLY)
                unit->state &= ~US_DEAD;

            unit->state |= US_HIDDEN | US_NOT_DEPLOYED;

            unit->rescue = 0;
        })
    }
    else
    {
        FOR_UNITS(FACTION_BLUE+1, FACTION_BLUE+0x40, unit,
        {
            unit->x = -1;
            unit->y = +1;

            SetUnitHp(unit, GetUnitMaxHp(unit));
            SetUnitStatus(unit, UNIT_STATUS_NONE);

            unit->torch = 0;
            unit->barrier = 0;

            unit->state &= US_DEAD | US_NOT_DEPLOYED | US_SOLOANIM_1 | US_SOLOANIM_2;

            if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_SUPPLY)
                unit->state &= ~US_DEAD;

            unit->state |= US_HIDDEN;

            unit->rescue = 0;
        })
    }

    gPlaySt.flags &= ~PLAY_FLAG_4;
}

#else // if !NONMATCHING

NAKEDFUNC
void CleanupUnitsBeforeChapter(void)
{
    asm("\
        .syntax unified\n\
        push {r4, r5, r6, r7, lr}\n\
        movs r4, #0x41\n\
    _08029374:\n\
        adds r0, r4, #0\n\
        bl GetUnit\n\
        adds r1, r0, #0\n\
        cmp r1, #0\n\
        beq _0802938C\n\
        ldr r0, [r1]\n\
        cmp r0, #0\n\
        beq _0802938C\n\
        adds r0, r1, #0\n\
        bl ClearUnit\n\
    _0802938C:\n\
        adds r4, #1\n\
        cmp r4, #0xbf\n\
        ble _08029374\n\
        ldr r0, _08029408 @ =gPlaySt\n\
        ldrb r0, [r0, #0xe]\n\
        cmp r0, #0x19\n\
        beq _08029414\n\
        movs r5, #1\n\
    _0802939C:\n\
        adds r0, r5, #0\n\
        bl GetUnit\n\
        adds r4, r0, #0\n\
        cmp r4, #0\n\
        beq _080293FE\n\
        ldr r0, [r4]\n\
        cmp r0, #0\n\
        beq _080293FE\n\
        adds r0, r4, #0\n\
        bl GetUnitMaxHp\n\
        adds r1, r0, #0\n\
        adds r0, r4, #0\n\
        bl SetUnitHp\n\
        adds r0, r4, #0\n\
        movs r1, #0\n\
        bl SetUnitStatus\n\
        adds r1, r4, #0\n\
        adds r1, #0x2f\n\
        movs r0, #0\n\
        strb r0, [r1]\n\
        ldr r1, _0802940C @ =0x0000C004\n\
        adds r0, r1, #0\n\
        ldrh r3, [r4, #0xc]\n\
        ands r3, r0\n\
        movs r6, #0\n\
        strh r3, [r4, #0xc]\n\
        ldr r0, [r4]\n\
        ldr r2, [r4, #4]\n\
        ldr r1, [r0, #0x28]\n\
        ldr r0, [r2, #0x24]\n\
        orrs r1, r0\n\
        movs r0, #0x80\n\
        lsls r0, r0, #2\n\
        ands r1, r0\n\
        cmp r1, #0\n\
        beq _080293F4\n\
        ldr r2, _08029410 @ =0x0000FFFB\n\
        adds r0, r2, #0\n\
        ands r3, r0\n\
        strh r3, [r4, #0xc]\n\
    _080293F4:\n\
        movs r0, #9\n\
        ldrh r1, [r4, #0xc]\n\
        orrs r0, r1\n\
        strh r0, [r4, #0xc]\n\
        strb r6, [r4, #0x19]\n\
    _080293FE:\n\
        adds r5, #1\n\
        cmp r5, #0x3f\n\
        ble _0802939C\n\
        b _08029486\n\
        .align 2, 0\n\
    _08029408: .4byte gPlaySt\n\
    _0802940C: .4byte 0x0000C004\n\
    _08029410: .4byte 0x0000FFFB\n\
    _08029414:\n\
        movs r5, #1\n\
        movs r7, #0\n\
    _08029418:\n\
        adds r0, r5, #0\n\
        bl GetUnit\n\
        adds r4, r0, #0\n\
        cmp r4, #0\n\
        beq _08029480\n\
        ldr r0, [r4]\n\
        cmp r0, #0\n\
        beq _08029480\n\
        movs r0, #0xff\n\
        strb r0, [r4, #0xe]\n\
        movs r0, #1\n\
        strb r0, [r4, #0xf]\n\
        adds r0, r4, #0\n\
        bl GetUnitMaxHp\n\
        adds r1, r0, #0\n\
        adds r0, r4, #0\n\
        bl SetUnitHp\n\
        adds r0, r4, #0\n\
        movs r1, #0\n\
        bl SetUnitStatus\n\
        adds r0, r4, #0\n\
        adds r0, #0x2f\n\
        strb r7, [r0]\n\
        ldr r1, _08029498 @ =0x0000C00C\n\
        adds r0, r1, #0\n\
        ldrh r3, [r4, #0xc]\n\
        ands r3, r0\n\
        movs r6, #0\n\
        strh r3, [r4, #0xc]\n\
        ldr r0, [r4]\n\
        ldr r2, [r4, #4]\n\
        ldr r1, [r0, #0x28]\n\
        ldr r0, [r2, #0x24]\n\
        orrs r1, r0\n\
        movs r0, #0x80\n\
        lsls r0, r0, #2\n\
        ands r1, r0\n\
        cmp r1, #0\n\
        beq _08029476\n\
        ldr r2, _0802949C @ =0x0000FFFB\n\
        adds r0, r2, #0\n\
        ands r3, r0\n\
        strh r3, [r4, #0xc]\n\
    _08029476:\n\
        movs r0, #1\n\
        ldrh r1, [r4, #0xc]\n\
        orrs r0, r1\n\
        strh r0, [r4, #0xc]\n\
        strb r6, [r4, #0x19]\n\
    _08029480:\n\
        adds r5, #1\n\
        cmp r5, #0x3f\n\
        ble _08029418\n\
    _08029486:\n\
        ldr r1, _080294A0 @ =gPlaySt\n\
        movs r0, #0xef\n\
        ldrb r2, [r1, #0x14]\n\
        ands r0, r2\n\
        strb r0, [r1, #0x14]\n\
        pop {r4, r5, r6, r7}\n\
        pop {r0}\n\
        bx r0\n\
        .align 2, 0\n\
    _08029498: .4byte 0x0000C00C\n\
    _0802949C: .4byte 0x0000FFFB\n\
    _080294A0: .4byte gPlaySt\n\
        .syntax divided\n\
    ");
}

#endif // NONMATCHING

static void ResumeMapMainDuringPhase(ProcPtr mapmain)
{
    RefreshEntityMaps();
    RefreshUnitSprites();

    SetDispEnable(0, 0, 0, 0, 0);

    Proc_Goto(mapmain, L_BMMAIN_2);
}

static void ResumeMapMainDuringAction(ProcPtr mapmain)
{
    RefreshEntityMaps();
    RefreshUnitSprites();

    SetDispEnable(0, 0, 0, 0, 0);

    Proc_Goto(mapmain, L_BMMAIN_4);

    gActiveUnit = GetUnit(gAction.instigator);

    gMapUnit[gActiveUnit->y][gActiveUnit->x] = 0;
    HideUnitSprite(GetUnit(gAction.instigator));
    MU_Start(gActiveUnit);
    MU_SetDefaultFacing_Auto();
}

static void ResumeMapMainDuringBerserk(ProcPtr mapmain)
{
    RefreshEntityMaps();
    RefreshUnitSprites();

    SetDispEnable(0, 0, 0, 0, 0);

    Proc_Goto(mapmain, L_BMMAIN_5);
}

static void ResumeMapMainDuringArena(ProcPtr mapmain)
{
    gActiveUnit = GetUnit(gAction.instigator);

    ArenaResume(gActiveUnit);

    BattleGenerateArena(gActiveUnit);
    BeginBattleAnimations();

    SetDispEnable(0, 0, 0, 0, 0);

    RefreshEntityMaps();
    gMapUnit[gAction.yMove][gAction.xMove] = 0;
    RefreshUnitSprites();

    Proc_Goto(mapmain, L_BMMAIN_8);

    sub_8097EAC();
}

static void ResumeMapMainDuringPhaseChange(ProcPtr mapmain)
{
    RefreshEntityMaps();
    RefreshUnitSprites();

    SetDispEnable(0, 0, 0, 0, 0);

    Proc_Goto(mapmain, L_BMMAIN_6);
}

void sub_8029654(void)
{
    SetNextGameAction(GAME_ACTION_2);

    gPlaySt.endingId = GetEndingId();

    sub_8084908(&gPlaySt);
    sub_8084EA4();
}
