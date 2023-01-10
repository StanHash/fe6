#include "debugmenu.h"

#include "random.h"
#include "hardware.h"
#include "debugtext.h"
#include "text.h"
#include "face.h"
#include "gamecontroller.h"
#include "bm.h"
#include "unit.h"
#include "map.h"
#include "bmfx.h"
#include "bmio.h"
#include "chapter.h"
#include "chapterinfo.h"
#include "menuinfo.h"
#include "ui.h"
#include "menu.h"
#include "statscreen.h" // StartMuralBackground

#include "constants/videoalloc_global.h"
#include "constants/chapters.h"
#include "constants/faces.h"

enum
{
    DEBUG_WEATHER_NONE,
    DEBUG_WEATHER_SANDSTORM,
    DEBUG_WEATHER_SNOW,
    DEBUG_WEATHER_SNOWSTORM,
    DEBUG_WEATHER_RAIN,
    DEBUG_WEATHER_NIGHT,
    DEBUG_WEATHER_FLAMES,

    DEBUG_WEATHER_COUNT,
};

// in main.c
extern void PutBuildInfo(u16 * tm);

static void DebugTextFrame_DoPut(struct GenericProc * proc);

struct ProcScr CONST_DATA ProcScr_DebugMonitor[] =
{
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_DebugTextFrame[] =
{
    PROC_SLEEP(1),

    PROC_CALL(DebugTextFrame_DoPut),
    PROC_END,
};

void func_fe6_0801A5AC(void)
{
    struct Unit * unit = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

    if (unit)
        UnitApplyBonusLevels(unit, 20);
}

static void DebugTextFrame_DoPut(struct GenericProc * proc)
{
    struct Text text;

    int x = proc->x;
    int y = proc->y;

    int width = proc->unk52;
    char const * str = proc->ptr;

    InitText(&text, width);
    Text_DrawString(&text, str);

    PutUiWindowFrame(x, y, width + 2, 4, UI_WINDOW_REGULAR);
    PutText(&text, gBg0Tm + TM_OFFSET(x+1, y+1));

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);
}

void PutDebugTextFrame(int x, int y, int width, char const * str)
{
    struct GenericProc * proc = SpawnProc(ProcScr_DebugTextFrame, PROC_TREE_3);

    proc->x = x;
    proc->y = y;
    proc->ptr = (void *) str;
    proc->unk52 = width;
}

fu8 func_fe6_0801A674(struct MenuProc * menu)
{
    EndMenu(menu);
    ClearUi();

    StartMenu(&MenuInfo_Debug_085C7474);
    DebugInitBg(2, 0);

    return MENU_ACTION_NOCURSOR;
}

fu8 func_fe6_0801A698(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (gKeySt->repeated & KEY_DPAD_RIGHT)
        ent->id++;

    if (gKeySt->repeated & KEY_DPAD_LEFT)
        ent->id--;

    if (ent->id >= CHAPTER_COUNT)
        ent->id = CHAPTER_COUNT - 1;

    if (ent->id < 1)
        ent->id = 1;

    if (gKeySt->repeated & (KEY_DPAD_LEFT | KEY_DPAD_RIGHT))
    {
        DebugPutStr(gBg0Tm + TM_OFFSET(7, 3), "        ");
        DebugPutStr(gBg0Tm + TM_OFFSET(7, 3), GetChapterInfo(ent->id)->debug_name);

        EnableBgSync(BG0_SYNC_BIT);
    }
}

fu8 func_fe6_0801A724(struct MenuProc * menu, struct MenuEntProc * ent)
{
    EndMapMain();

    gPlaySt.chapter = ent->id;
    CleanupUnitsBeforeChapter();
    RestartGameAndChapter();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 func_fe6_0801A748(struct MenuProc * menu, struct MenuEntProc * ent)
{
    EndMenu(menu);

    EndFaceById(0);
    ClearUi();

    return MENU_ACTION_NOCURSOR;
}

u32 func_fe6_0801A760(struct MenuProc * menu, struct MenuEntProc * ent)
{
    char const * offon[] =
    {
        JTEXT("ＯＦＦ"),
        JTEXT("　ＯＮ"),
    };

    struct GenericProc * proc = FindProc(ProcScr_DebugMonitor);

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, JTEXT("デブ情報"));
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, offon[proc->unk66]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

fu8 func_fe6_0801A7D4(struct MenuProc * menu, struct MenuEntProc * ent)
{
    struct GenericProc * proc = FindProc(ProcScr_DebugMonitor);

    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        proc->unk66 ^= 1;
        func_fe6_0801A760(menu, ent);

        DebugInitObj(-1, 9);
    }
}

fu8 func_fe6_0801A81C(struct MenuProc * menu, struct MenuEntProc * ent)
{
    return 0;
}

u32 func_fe6_0801A820(struct MenuProc * menu, struct MenuEntProc * ent)
{
    char const * weatherNames[] =
    {
        [DEBUG_WEATHER_NONE]      = TEXT("晴れ", "None"),
        [DEBUG_WEATHER_SANDSTORM] = TEXT("砂嵐", "Sandstorm"),
        [DEBUG_WEATHER_SNOW]      = TEXT("雪", "Snow"),
        [DEBUG_WEATHER_SNOWSTORM] = TEXT("吹雪", "Snowstorm"),
        [DEBUG_WEATHER_RAIN]      = TEXT("雨", "Rain"),
        [DEBUG_WEATHER_NIGHT]     = TEXT("夜", "Night"),
        [DEBUG_WEATHER_FLAMES]    = TEXT("溶岩", "Flames"),
    };

    struct GenericProc * proc = FindProc(ProcScr_DebugMonitor);

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8,  TEXT_COLOR_SYSTEM_WHITE, TEXT("天気", "Weather"));
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, weatherNames[proc->unk58 % DEBUG_WEATHER_COUNT]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

fu8 func_fe6_0801A89C(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        struct GenericProc * proc = FindProc(ProcScr_DebugMonitor);

        proc->unk58++;
        func_fe6_0801A820(menu, ent);

        switch (proc->unk58 % DEBUG_WEATHER_COUNT)
        {

        case DEBUG_WEATHER_NONE:
            SetWeather(WEATHER_NONE);
            break;

        case DEBUG_WEATHER_SANDSTORM:
            SetWeather(WEATHER_SANDSTORM);
            break;

        case DEBUG_WEATHER_SNOW:
            SetWeather(WEATHER_SNOW);
            break;

        case DEBUG_WEATHER_SNOWSTORM:
            SetWeather(WEATHER_SNOWSTORM);
            break;

        case DEBUG_WEATHER_RAIN:
            SetWeather(WEATHER_RAIN);
            break;

        case DEBUG_WEATHER_NIGHT:
            SetWeather(WEATHER_NIGHT);
            break;

        case DEBUG_WEATHER_FLAMES:
            SetWeather(WEATHER_FLAMES);
            break;

        }
    }
}

fu8 func_fe6_0801A940(struct MenuProc * menu, struct MenuEntProc * ent)
{
    return 0;
}

u32 func_fe6_0801A944(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, "\x8E\xFC\x89\xF1\x90\x94"); // "周回数"
    Text_InsertDrawString(&ent->text, 72, TEXT_COLOR_SYSTEM_BLUE, "\x8E\xFC\x96\xDA"); // "周目"
    Text_InsertDrawNumberOrBlank(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, GetGlobalCompletedPlaythroughCount() + 1);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}


fu8 func_fe6_0801A9A8(struct MenuProc * menu, struct MenuEntProc * ent)
{
    struct GlobalSaveInfo saveInfo;
    int clearCount, i;

    if (!(gKeySt->repeated & (KEY_DPAD_RIGHT | KEY_DPAD_LEFT)))
        return 0;

    clearCount = GetGlobalCompletedPlaythroughCount();

    if (gKeySt->repeated & KEY_DPAD_LEFT)
    {
        if (clearCount >= 0)
            clearCount--;
    }

    if (gKeySt->repeated & KEY_DPAD_RIGHT)
    {
        if (clearCount < MAX_SAVED_GAME_CLEARS)
            clearCount++;
    }

    LoadGlobalSaveInfo(&saveInfo);

    for (i = 0; i < MAX_SAVED_GAME_CLEARS; ++i)
        saveInfo.playThrough[i] = 0;

    i = 0;

    while (i < clearCount)
    {
        i++;
        RegisterCompletedPlaythrough(&saveInfo, i);
    }

    if (clearCount == 0)
    {
        saveInfo.playedThrough = FALSE;
        saveInfo.unk_0E_2 = FALSE;
        saveInfo.unk_0E_1 = FALSE;
        saveInfo.unk_0E_3 = FALSE;
    }
    else
    {
        saveInfo.playedThrough = TRUE;
    }

    SaveGlobalSaveInfo(&saveInfo);

    func_fe6_0801A944(menu, ent);
}

fu8 func_fe6_0801AA70(struct MenuProc * menu, struct MenuEntProc * ent)
{
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 func_fe6_0801AA74(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ClearUi();
    StartMenu(&MenuInfo_Debug_085C73E4);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

fu8 func_fe6_0801AA8C(struct MenuProc * menu, struct MenuEntProc * ent)
{
    // required for a match
    u32 unused[4];

    // required for a match
    if (gPlaySt.playthrough_id != 0) {}

    SavePlayThroughData();

    gPlaySt.flags &= ~PLAY_FLAG_4;

    CleanupUnitsBeforeChapter();
    SaveGame(GetLastUsedGameSaveSlot());

    SoftReset(GBA_RESET_ALL);
}

fu8 func_fe6_0801AABC(struct MenuProc * menu)
{
    DebugPutStr(gBg0Tm + TM_OFFSET(7, 3), GetChapterInfo(1)->debug_name);
    EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_0801AAE0(void)
{
    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    InitBmDisplay();

    DebugInitBg(2, 0);

    if (!IsSramWorking())
        PutDrawText(NULL, gBg0Tm + TM_OFFSET(0, 18), 0, 0, 30, "\x82\x72\x82\x71\x82\x60\x82\x6C\x82\xAA\x91\x95\x92\x85\x82\xB3\x82\xEA\x82\xC4\x82\xA2\x82\xDC\x82\xB9\x82\xF1"); // "ＳＲＡＭが装着されていません"

    StartMuralBackground(StartMenu(&MenuInfo_Debug_085C742C), (u8 *) BG_VRAM + CHR_SIZE * 0x580, -1);

    PutBuildInfo(gBg2Tm + TM_OFFSET(0, 1));
    DebugPutStr(gBg2Tm + TM_OFFSET(0, 2), "DB INTERRUPT AVAILABLE");
}

fu8 func_fe6_0801AB64(struct MenuProc * menu)
{
    struct SaveBlockInfo blockInfo;

    EnableBgSync(BG0_SYNC_BIT);

    menu->entries[3]->id = 1;

    if (LoadSaveBlockInfo(&blockInfo, SAVE_ID_SUSPEND0) != TRUE || ((blockInfo.checksum32 + (blockInfo.checksum32>>16)) & 0xFF) != 0)
    {
        StartFace(0, FID_63, 32, 80, FACE_DISP_KIND(FACE_96x80_FLIPPED) | FACE_DISP_HLAYER(4));
        StartFace(1, FID_61, DISPLAY_WIDTH - 32, 80, FACE_DISP_KIND(FACE_96x80) | FACE_DISP_HLAYER(4));

        return 0;
    }
    else
    {
        StartFace(0, FID_67, 32, 80, FACE_DISP_KIND(FACE_96x80_FLIPPED) | FACE_DISP_HLAYER(4));
        StartFace(1, FID_66, DISPLAY_WIDTH - 32, 80, FACE_DISP_KIND(FACE_96x80) | FACE_DISP_HLAYER(4));

        return 0;
    }
}

fu8 func_fe6_0801ABE8(struct MenuProc * menu)
{
    EndFaceById(0);
    EndFaceById(1);

    SetDispEnable(0, 0, 0, 0, 0);
    SetBackdropColor(0);
}

fu8 func_fe6_0801AC2C(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int x = menu->rect.x + 2;
    int y = menu->rect.y + 8;

    if (gKeySt->repeated & KEY_DPAD_RIGHT)
        ent->id++;

    if (gKeySt->repeated & KEY_DPAD_LEFT)
        ent->id--;

    if (ent->id >= CHAPTER_COUNT)
        ent->id = CHAPTER_COUNT - 1;

    if (ent->id < 1)
        ent->id = 1;

    if (gKeySt->repeated & (KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        DebugPutStr(gBg0Tm + TM_OFFSET(x, y), "        ");
        DebugPutStr(gBg0Tm + TM_OFFSET(x, y), GetChapterInfo(ent->id)->debug_name);

        EnableBgSync(BG0_SYNC_BIT);
    }
}

fu8 func_fe6_0801ACD8(struct MenuProc * menu, struct MenuEntProc * ent)
{
    RandInit(GetGameTime());

    InitUnits();

    SaveNewGame(SAVE_ID_GAME0, FALSE);
    gPlaySt.chapter = ent->id;

    SaveGame(0);
    CleanupUnitsBeforeChapter();

    RestartGameAndChapter();

    return MENU_ACTION_END;
}

fu8 func_fe6_0801AD14(struct MenuProc * menu, struct MenuEntProc * ent)
{
    StartMenu(&MenuInfo_Debug_085C7450);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 func_fe6_0801AD28(struct MenuProc * menu, struct MenuEntProc * ent)
{
    StartMenu(&MenuInfo_DebugCpControl);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 func_fe6_0801AD3C(struct MenuProc * menu, struct MenuEntProc * ent)
{
    func_fe6_08089234(PROC_TREE_3);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 func_fe6_0801AD4C(struct MenuEntInfo const * info, int id)
{
    return MENU_ACTION_NOCURSOR;
}

fu8 func_fe6_0801AD50(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability != 0)
        return MENU_ACTION_SE_6B;

    SaveSuspendedGame(SAVE_ID_SUSPEND1);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 func_fe6_0801AD6C(struct MenuEntInfo const * info, int id)
{
    return !func_fe6_080859E0(SAVE_ID_SUSPEND1) ? MENU_ENTRY_DISABLED : MENU_ENTRY_ENABLED;
}

fu8 func_fe6_0801AD84(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability != 0)
        return MENU_ACTION_SE_6B;

    if (FindProc(ProcScr_BmMain) != NULL)
        EndMapMain();

    LoadSuspendedGame(SAVE_ID_SUSPEND1);
    RestartGameAndLoadSuspend();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 func_fe6_0801ADB4(struct MenuEntInfo const * info, int id)
{
    return !func_fe6_080859E0(SAVE_ID_SUSPEND0) ? MENU_ENTRY_DISABLED : MENU_ENTRY_ENABLED;
}

fu8 func_fe6_0801ADCC(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability != 0)
        return MENU_ACTION_SE_6B;

    LoadSuspendedGame(SAVE_ID_SUSPEND0);
    RestartGameAndLoadSuspend();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u32 func_fe6_0801ADEC(struct MenuProc * menu, struct MenuEntProc * ent)
{
    char const * offon[] =
    {
        "\x82\x6E\x82\x65\x82\x65", // "ＯＦＦ"
        "\x82\x6E\x82\x6D", // "ＯＮ"
    };

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, "\x82\xB3\x82\xAD\x93\x47"); // "さく敵"
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, offon[gPlaySt.vision != 0]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

fu8 func_fe6_0801AE60(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (IsMapFadeActive())
        return 0;

    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        if (gPlaySt.vision == 0)
            SetFogVision(GetChapterInfo(gPlaySt.chapter)->fog);
        else
            SetFogVision(0);

        func_fe6_0801ADEC(menu, ent);
    }
}

fu8 func_fe6_0801AEB8(struct MenuProc * menu, struct MenuEntProc * ent)
{
    return 0;
}

fu8 func_fe6_0801AEBC(struct MenuProc * menu, struct MenuEntProc * ent)
{
    StartGame();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

fu8 func_fe6_0801AEC8(struct MenuProc * menu, struct MenuEntProc * ent)
{
    func_fe6_0800285C(0x300);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u32 DebugCpControlMenu_Entry_Display(struct MenuProc * menu, struct MenuEntProc * ent)
{
    char const * strings[] =
    {
        JTEXT("ＣＰ"),
        JTEXT("人間"),
        JTEXT("不参加"),
    };

    int state;

    if (ent->id != 0)
        state = gPlaySt.debug_control_green;
    else
        state = gPlaySt.debug_control_red;

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, ent->id != 0 ? JTEXT("緑軍") : JTEXT("赤軍"));
    Text_InsertDrawString(&ent->text, 32, TEXT_COLOR_SYSTEM_BLUE, strings[state]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));

    return 0;
}

fu8 DebugCpControlMenu_Entry_Idle(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        int state;

        if (ent->id != 0)
            state = gPlaySt.debug_control_green;
        else
            state = gPlaySt.debug_control_red;

        if (gKeySt->pressed & KEY_DPAD_LEFT)
            state--;

        if (gKeySt->pressed & (KEY_DPAD_RIGHT | KEY_BUTTON_A))
            state++;

        if (state > 2)
            state = 2;

        if (state < 0)
            state = 0;

        if (ent->id != 0)
            gPlaySt.debug_control_green = state;
        else
            gPlaySt.debug_control_red = state;

        DebugCpControlMenu_Entry_Display(menu, ent);
    }

    return 0;
}

fu8 func_fe6_0801B018(struct MenuProc * menu, struct MenuEntProc * ent)
{
    RestartGameAndChapter();
    Proc_Goto(FindProc(ProcScr_GameController), L_GAMECTRL_SRAMRESET);
}
