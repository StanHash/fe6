
#include "chapter.h"

#include "hardware.h"
#include "gamecontroller.h"
#include "bm.h"
#include "map.h"
#include "faction.h"
#include "battle.h"
#include "trap.h"
#include "unitsprite.h"
#include "bmio.h"
#include "arena.h"
#include "action.h"
#include "chapterinfo.h"
#include "ui.h"
#include "mu.h"
#include "eventinfo.h"
#include "save_core.h"
#include "save_stats.h"
#include "save_xmap.h"

#include "constants/chapters.h"

// compiler needs to think func returns int (not u8) to match
#if BUGFIX
  #include "eventfunctions.h"
#else
  int GetEndingId(void);
#endif

struct ProcScr CONST_DATA ProcScr_DelayedUnlockBmDisplay[] =
{
    PROC_SLEEP(0),

    PROC_CALL(UnlockBmDisplay),
    PROC_END,
};

int GetTextPrintDelay(void)
{
    SHOULD_BE_STATIC u8 SHOULD_BE_CONST lut[4] = { 8, 4, 1, 0 };

    return lut[gPlaySt.config_talk_speed];
}

int IsFirstPlaythrough(void)
{
    if (!IsNotFirstPlaythrough())
        return TRUE;

    if (gPlaySt.flags & PLAY_FLAG_COMPLETE)
        return FALSE;

    return gPlaySt.unk_1D_5;
}

void InitPlayConfig(int is_hard)
{
    CpuFill16(0, &gPlaySt, sizeof(gPlaySt));

    gPlaySt.chapter = CHAPTER_1;

    if (is_hard)
        gPlaySt.flags |= PLAY_FLAG_HARD;

    gPlaySt.config_battle_anim = 0; // TODO: battle anim type constants
    gPlaySt.config_terrain_mapui = 0;
    gPlaySt.config_unit_mapui = 0;
    gPlaySt.config_no_auto_cursor = FALSE;
    gPlaySt.config_talk_speed = 1;
    gPlaySt.config_walk_speed = 0;
    gPlaySt.config_bgm_disable = FALSE;
    gPlaySt.config_se_disable = FALSE;
    gPlaySt.config_window_theme = UI_WINDOW_THEME_BLUE;
    gPlaySt.config_no_auto_end_turn = FALSE;
    gPlaySt.config_no_subtitle_help = FALSE;
    gPlaySt.config_battle_preview_kind = 0;
    gPlaySt.debug_control_red = 0;
    gPlaySt.debug_control_green = 0;
    gPlaySt.unk_1C_1 = 0;
    gPlaySt.unk_1D_5 = 0;
}

void ResetBmSt(void)
{
    int lock = gBmSt.lock;

    CpuFill16(0, &gBmSt, sizeof(gBmSt));

    gBmSt.lock = lock;
}

void StartChapter(struct GenericProc * parent)
{
    InitBgs(NULL);

    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    ResetBmSt();

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();
    ResetChapterFlags();
    ResetUnitSprites();
    InitTraps();

    gPlaySt.faction = FACTION_GREEN;
    gPlaySt.turn = 0;
    gPlaySt.vision = GetChapterInfo(gPlaySt.chapter)->fog;
    gPlaySt.weather = GetChapterInfo(gPlaySt.chapter)->weather;

    InitBmBgLayers();

    InitMapForChapter(gPlaySt.chapter);
    InitMapTraps();

    gPlaySt.time_chapter_started = GetGameTime();
    gPlaySt.support_gain = 0;

    CreateInitialRedUnits();

    StartMapMain(parent);

    SetBackdropColor(0);
    SetBlendTargetA(1, 1, 1, 1, 1); SetBlendBackdropA(1);
    SetBlendDarken(0x10);
}

void func_fe6_08029084(void)
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

    SetBackdropColor(0);
    SetDispEnable(1, 1, 1, 0, 0);
}

void ResumeChapterFromSuspend(struct GenericProc * parent)
{
    ProcPtr mapmain;

    if (gPlaySt.chapter < 0)
        ReadExtraMapInfo();

    InitBgs(NULL);

    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    ResetBmSt();

    SetMapCursorPosition(gPlaySt.x_cursor, gPlaySt.y_cursor);

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();
    ResetUnitSprites();

    InitMapForChapter(gPlaySt.chapter);

    gBmSt.just_resumed = TRUE;

    mapmain = StartMapMain(parent);

    gBmSt.camera.x = GetCameraCenteredX(16*gBmSt.cursor.x);
    gBmSt.camera.y = GetCameraCenteredY(16*gBmSt.cursor.y);

    switch (gAction.suspend_point)
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

void func_fe6_08029240(void)
{
    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();
    ClearUi();
    SetWinEnable(0, 0, 0);
    SetBlendNone();

    SetBlankChr(0);

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_080292B8(void)
{
    ApplySystemObjectsGraphics();

    StartMu(&gBattleUnitA.unit);
    SetAutoMuDefaultFacing();

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

ProcPtr StartMapMain(struct GenericProc * parent)
{
    struct GenericProc * proc = SpawnProc(ProcScr_BmMain, PROC_TREE_2);
    proc->ptr = parent;

    parent->proc_lock_cnt++;

    StartBmVSync();
    SpawnProc(ProcScr_MapTask, PROC_TREE_4);

    return proc;
}

void EndMapMain(void)
{
    struct GenericProc * mapmain;
    struct GenericProc * parent;

    Proc_EndEachMarked(PROC_MARK_1);

    mapmain = FindProc(ProcScr_BmMain);
    parent = mapmain->ptr;

    parent->proc_lock_cnt--;

    Proc_End(mapmain);
}

void CleanupUnitsBeforeChapter(void)
{
    // Clear non-blue units

    FOR_UNITS(FACTION_GREEN + 1, FACTION_RED + 0x40, unit,
    {
        ClearUnit(unit);
    })

    // Cleanup blue unit states

    if (gPlaySt.chapter != CHAPTER_FINAL)
    {
        FOR_UNITS(FACTION_BLUE + 1, FACTION_BLUE + 0x40, unit,
        {
            SetUnitHp(unit, GetUnitMaxHp(unit));
            SetUnitStatus(unit, UNIT_STATUS_NONE);

            unit->torch = 0;
            unit->barrier = 0;

            unit->flags &= UNIT_FLAG_DEAD | UNIT_FLAG_SOLOANIM_1 | UNIT_FLAG_SOLOANIM_2;

            if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_SUPPLY)
                unit->flags &= ~UNIT_FLAG_DEAD;

            unit->flags |= UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED;

            unit->rescue = 0;
        })

        gPlaySt.flags &= ~PLAY_FLAG_4;
    }
    else
    {
        FOR_UNITS(FACTION_BLUE + 1, FACTION_BLUE + 0x40, unit,
        {
            unit->x = -1;
            unit->y = +1;

            SetUnitHp(unit, GetUnitMaxHp(unit));
            SetUnitStatus(unit, UNIT_STATUS_NONE);

            unit->torch = 0;
            unit->barrier = 0;

            unit->flags &= UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED | UNIT_FLAG_SOLOANIM_1 | UNIT_FLAG_SOLOANIM_2;

            if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_SUPPLY)
                unit->flags &= ~UNIT_FLAG_DEAD;

            unit->flags |= UNIT_FLAG_HIDDEN;

            unit->rescue = 0;
        })

        gPlaySt.flags &= ~PLAY_FLAG_4;
    }
}

void ResumeMapMainDuringPhase(ProcPtr mapmain)
{
    RefreshEntityMaps();
    RefreshUnitSprites();

    SetDispEnable(0, 0, 0, 0, 0);

    Proc_Goto(mapmain, L_BMMAIN_2);
}

void ResumeMapMainDuringAction(ProcPtr mapmain)
{
    RefreshEntityMaps();
    RefreshUnitSprites();

    SetDispEnable(0, 0, 0, 0, 0);

    Proc_Goto(mapmain, L_BMMAIN_4);

    gActiveUnit = GetUnit(gAction.instigator);

    gMapUnit[gActiveUnit->y][gActiveUnit->x] = 0;
    HideUnitSprite(GetUnit(gAction.instigator));
    StartMu(gActiveUnit);
    SetAutoMuDefaultFacing();
}

void ResumeMapMainDuringBerserk(ProcPtr mapmain)
{
    RefreshEntityMaps();
    RefreshUnitSprites();

    SetDispEnable(0, 0, 0, 0, 0);

    Proc_Goto(mapmain, L_BMMAIN_5);
}

void ResumeMapMainDuringArena(ProcPtr mapmain)
{
    gActiveUnit = GetUnit(gAction.instigator);

    ArenaResume(gActiveUnit);

    BattleGenerateArena(gActiveUnit);
    BeginBattleAnimations();

    SetDispEnable(0, 0, 0, 0, 0);

    RefreshEntityMaps();
    gMapUnit[gAction.y_move][gAction.x_move] = 0;
    RefreshUnitSprites();

    Proc_Goto(mapmain, L_BMMAIN_8);

    func_fe6_08097EAC();
}

void ResumeMapMainDuringPhaseChange(ProcPtr mapmain)
{
    RefreshEntityMaps();
    RefreshUnitSprites();

    SetDispEnable(0, 0, 0, 0, 0);

    Proc_Goto(mapmain, L_BMMAIN_6);
}

void func_fe6_08029654(void)
{
    SetNextGameAction(GAME_ACTION_2);

    gPlaySt.ending_id = GetEndingId();

    RegisterChapterStats(&gPlaySt);
    WriteCompletedPlaythroughSaveData();
}
