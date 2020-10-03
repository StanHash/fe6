
#include "common.h"

#include "random.h"
#include "hardware.h"
#include "debug-text.h"
#include "text.h"
#include "face.h"
#include "game-controller.h"
#include "bm.h"
#include "unit.h"
#include "map.h"
#include "bmfx.h"
#include "bmio.h"
#include "chapter.h"
#include "chapter-info.h"
#include "menu.h"

#include "constants/video-global.h"
#include "constants/chapters.h"
#include "constants/faces.h"

enum
{
    DEBUG_WEATHER_NONE,
    DEBUG_WEATHER_SANDSTORM,
    DEBUG_WEATHER_SNOW,
    DEBUG_WEATHER_SNOWSTORM,
    DEBUG_WEATHER_RAIN,
    DEBUG_WEATHER_5,
    DEBUG_WEATHER_FLAMES,

    DEBUG_WEATHER_COUNT,
};

// in main.c
extern void PutBuildInfo(u16* tm);

// sub_801A5AC
// PutDebugTextFrame
// sub_801A674
// sub_801A698
// sub_801A724
// sub_801A748
// sub_801A760
// sub_801A7D4
// sub_801A81C
// sub_801A820
// sub_801A89C
// sub_801A940
// sub_801A944
// sub_801A9A8
// sub_801AA70
// sub_801AA74
// sub_801AA8C
// sub_801AABC
// sub_801AAE0
// sub_801AB64
// sub_801ABE8
// sub_801AC2C
// sub_801ACD8
// sub_801AD14
// sub_801AD28
// sub_801AD3C
// sub_801AD4C
// sub_801AD50
// sub_801AD6C
// sub_801AD84
// sub_801ADB4
// sub_801ADCC
// sub_801ADEC
// sub_801AE60
// sub_801AEB8
// sub_801AEBC
// sub_801AEC8
// sub_801AED8
// sub_801AF78
// sub_801B018

static void DebugTextFrame_DoPut(struct GenericProc* proc);

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

void sub_801A5AC(void)
{
    struct Unit* unit = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

    if (unit)
        UnitApplyBonusLevels(unit, 20);
}

static void DebugTextFrame_DoPut(struct GenericProc* proc)
{
    struct Text text;

    int x = proc->x;
    int y = proc->y;

    int width = proc->unk52;
    char const* str = proc->ptr;

    InitText(&text, width);
    Text_DrawString(&text, str);

    sub_8041358(x, y, width + 2, 4, 0);
    PutText(&text, gBg0Tm + TM_OFFSET(x+1, y+1));

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);
}

void PutDebugTextFrame(int x, int y, int width, char const* str)
{
    struct GenericProc* proc = SpawnProc(ProcScr_DebugTextFrame, PROC_TREE_3);

    proc->x = x;
    proc->y = y;
    proc->ptr = (void*) str;
    proc->unk52 = width;
}

int sub_801A674(struct MenuProc* menu)
{
    sub_80419CC(menu);
    ClearBg0Bg1();

    sub_8041834(&MenuInfo_085C7474);
    DebugInitBg(2, 0);

    return MENU_ACT_SKIPCURSOR;
}

int sub_801A698(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (gKeySt->repeated & DPAD_RIGHT)
        ent->id++;

    if (gKeySt->repeated & DPAD_LEFT)
        ent->id--;

    if (ent->id >= CHAPTER_COUNT)
        ent->id = CHAPTER_COUNT - 1;

    if (ent->id < 1)
        ent->id = 1;

    if (gKeySt->repeated & (DPAD_LEFT | DPAD_RIGHT))
    {
        DebugPutStr(gBg0Tm + TM_OFFSET(7, 3), "        ");
        DebugPutStr(gBg0Tm + TM_OFFSET(7, 3), GetChapterInfo(ent->id)->debugName);

        EnableBgSync(BG0_SYNC_BIT);
    }
}

int sub_801A724(struct MenuProc* menu, struct MenuEntProc* ent)
{
    EndMapMain();

    gPlaySt.chapter = ent->id;
    CleanupUnitsBeforeChapter();
    RestartGameAndChapter();

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801A748(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_80419CC(menu);

    EndFaceById(0);
    ClearBg0Bg1();

    return MENU_ACT_SKIPCURSOR;
}

int sub_801A760(struct MenuProc* menu, struct MenuEntProc* ent)
{
    char const* offon[] =
    {
        TEXT("‚n‚e‚e"),
        TEXT("@‚n‚m"),
    };

    struct GenericProc* proc = Proc_Find(ProcScr_DebugMonitor);

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, TEXT("ƒfƒuî•ñ"));
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, offon[proc->unk66]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

int sub_801A7D4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    struct GenericProc* proc = Proc_Find(ProcScr_DebugMonitor);

    if (gKeySt->pressed & (A_BUTTON | DPAD_RIGHT | DPAD_LEFT))
    {
        proc->unk66 ^= 1;
        sub_801A760(menu, ent);

        DebugInitObj(-1, 9);
    }
}

int sub_801A81C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return 0;
}

int sub_801A820(struct MenuProc* menu, struct MenuEntProc* ent)
{
    char const* weatherNames[] =
    {
        [DEBUG_WEATHER_NONE]      = TEXT("°‚ê"),
        [DEBUG_WEATHER_SANDSTORM] = TEXT("»—’"),
        [DEBUG_WEATHER_SNOW]      = TEXT("á"),
        [DEBUG_WEATHER_SNOWSTORM] = TEXT("á"),
        [DEBUG_WEATHER_RAIN]      = TEXT("‰J"),
        [DEBUG_WEATHER_5]         = TEXT("–é"),
        [DEBUG_WEATHER_FLAMES]    = TEXT("—nŠâ"),
    };

    struct GenericProc* proc = Proc_Find(ProcScr_DebugMonitor);

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8,  TEXT_COLOR_SYSTEM_WHITE, TEXT("“V‹C"));
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, weatherNames[proc->unk58 % DEBUG_WEATHER_COUNT]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

int sub_801A89C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (gKeySt->pressed & (A_BUTTON | DPAD_RIGHT | DPAD_LEFT))
    {
        struct GenericProc* proc = Proc_Find(ProcScr_DebugMonitor);

        proc->unk58++;
        sub_801A820(menu, ent);

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

        case DEBUG_WEATHER_5:
            SetWeather(WEATHER_3);
            break;

        case DEBUG_WEATHER_FLAMES:
            SetWeather(WEATHER_FLAMES);
            break;

        }
    }
}

int sub_801A940(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return 0;
}

int sub_801A944(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, "Žü‰ñ”");
    Text_InsertDrawString(&ent->text, 72, TEXT_COLOR_SYSTEM_BLUE, "Žü–Ú");
    Text_InsertDrawNumberOrBlank(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, GetGlobalCompletedPlaythroughCount() + 1);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}


int sub_801A9A8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    struct GlobalSaveInfo saveInfo;
    int clearCount, i;

    if (!(gKeySt->repeated & (DPAD_RIGHT | DPAD_LEFT)))
        return 0;

    clearCount = GetGlobalCompletedPlaythroughCount();

    if (gKeySt->repeated & DPAD_LEFT)
    {
        if (clearCount >= 0)
            clearCount--;
    }

    if (gKeySt->repeated & DPAD_RIGHT)
    {
        if (clearCount < MAX_SAVED_GAME_CLEARS)
            clearCount++;
    }

    LoadGlobalSaveInfo(&saveInfo);

    for (i = 0; i < MAX_SAVED_GAME_CLEARS; ++i)
        saveInfo.unk_10[i] = 0;

    i = 0;

    while (i < clearCount)
    {
        i++;
        RegisterCompletedPlaythrough(&saveInfo, i);
    }

    if (clearCount == 0)
    {
        saveInfo.unk_0E_0 = FALSE;
        saveInfo.unk_0E_2 = FALSE;
        saveInfo.unk_0E_1 = FALSE;
        saveInfo.unk_0E_3 = FALSE;
    }
    else
    {
        saveInfo.unk_0E_0 = TRUE;
    }

    SaveGlobalSaveInfo(&saveInfo);

    sub_801A944(menu, ent);
}

int sub_801AA70(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801AA74(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ClearBg0Bg1();
    sub_8041834(&MenuInfo_085C73E4);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

int sub_801AA8C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    // required for a match
    u32 unused[4];

    // required for a match
    if (gPlaySt.playId != 0) {}

    sub_8084EA4();

    gPlaySt.flags &= ~PLAY_FLAG_4;

    CleanupUnitsBeforeChapter();
    sub_8085110(sub_8084F94());

    SoftReset(0xFF);
}

int sub_801AABC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    DebugPutStr(gBg0Tm + TM_OFFSET(7, 3), GetChapterInfo(1)->debugName);
    EnableBgSync(BG0_SYNC_BIT);
}

void sub_801AAE0(void)
{
    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    InitBmDisplay();

    DebugInitBg(2, 0);

    if (!IsSramWorking())
        PutDrawText(NULL, gBg0Tm + TM_OFFSET(0, 18), 0, 0, 30, "‚r‚q‚`‚l‚ª‘•’…‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ");

    sub_806EA24(sub_8041834(&MenuInfo_085C742C), (u8*) BG_VRAM + CHR_SIZE * 0x580, -1);

    PutBuildInfo(gBg2Tm + TM_OFFSET(0, 1));
    DebugPutStr(gBg2Tm + TM_OFFSET(0, 2), "DB INTERRUPT AVAILABLE");
}

int sub_801AB64(struct MenuProc* menu)
{
    struct SaveBlockInfo blockInfo;

    EnableBgSync(BG0_SYNC_BIT);

    menu->entries[3]->id = 1;

    if (sub_8084438(&blockInfo, SAVE_ID_SUSPEND0) != TRUE || ((blockInfo.checksum32 + (blockInfo.checksum32>>16)) & 0xFF) != 0)
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

int sub_801ABE8(struct MenuProc* menu)
{
    EndFaceById(0);
    EndFaceById(1);

    SetDispEnable(0, 0, 0, 0, 0);

    gPal[0] = 0;
    EnablePalSync();
}

int sub_801AC2C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int x = menu->rect.x + 2;
    int y = menu->rect.y + 8;

    if (gKeySt->repeated & DPAD_RIGHT)
        ent->id++;

    if (gKeySt->repeated & DPAD_LEFT)
        ent->id--;

    if (ent->id >= CHAPTER_COUNT)
        ent->id = CHAPTER_COUNT - 1;

    if (ent->id < 1)
        ent->id = 1;

    if (gKeySt->repeated & (DPAD_RIGHT | DPAD_LEFT))
    {
        DebugPutStr(gBg0Tm + TM_OFFSET(x, y), "        ");
        DebugPutStr(gBg0Tm + TM_OFFSET(x, y), GetChapterInfo(ent->id)->debugName);

        EnableBgSync(BG0_SYNC_BIT);
    }
}

int sub_801ACD8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    RandInit(GetGameTime());

    InitUnits();

    sub_808505C(SAVE_ID_GAME0, FALSE);
    gPlaySt.chapter = ent->id;

    sub_8085110(0);
    CleanupUnitsBeforeChapter();

    RestartGameAndChapter();

    return MENU_ACT_END;
}

int sub_801AD14(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_8041834(&MenuInfo_085C7450);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801AD28(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_8041834(&MenuInfo_085C7408);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801AD3C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_8089234(PROC_TREE_3);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801AD4C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return MENU_ACT_SKIPCURSOR;
}

int sub_801AD50(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability != 0)
        return MENU_ACT_SE_6B;

    sub_80857B0(SAVE_ID_SUSPEND1);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

Bool sub_801AD6C(void)
{
    return !sub_80859E0(SAVE_ID_SUSPEND1) ? TRUE : FALSE;
}

int sub_801AD84(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability != 0)
        return MENU_ACT_SE_6B;

    if (Proc_Find(ProcScr_BmMain) != NULL)
        EndMapMain();

    sub_80858E4(SAVE_ID_SUSPEND1);
    RestartGameAndLoadSuspend();

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

Bool sub_801ADB4(void)
{
    return !sub_80859E0(SAVE_ID_SUSPEND0) ? TRUE : FALSE;
}

int sub_801ADCC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability != 0)
        return MENU_ACT_SE_6B;

    sub_80858E4(SAVE_ID_SUSPEND0);
    RestartGameAndLoadSuspend();

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801ADEC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    char const* offon[] =
    {
        "‚n‚e‚e",
        "‚n‚m",
    };

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, "‚³‚­“G");
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, offon[gPlaySt.vision != 0]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

int sub_801AE60(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (IsMapFadeActive())
        return 0;

    if (gKeySt->pressed & (A_BUTTON | DPAD_RIGHT | DPAD_LEFT))
    {
        if (gPlaySt.vision == 0)
            SetFogVision(GetChapterInfo(gPlaySt.chapter)->fog);
        else
            SetFogVision(0);

        sub_801ADEC(menu, ent);
    }
}

int sub_801AEB8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return 0;
}

int sub_801AEBC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    StartGame();

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

int sub_801AEC8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_800285C(0x300);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801AED8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    char const* strings[] =
    {
        "‚b‚o",
        "lŠÔ",
        "•sŽQ‰Á",
    };

    int state;

    if (ent->id != 0)
        state = gPlaySt.debugGreenControl;
    else
        state = gPlaySt.debugRedControl;

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, ent->id != 0 ? "—ÎŒR" : "ÔŒR");
    Text_InsertDrawString(&ent->text, 32, TEXT_COLOR_SYSTEM_BLUE, strings[state]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));

    return 0;
}

int sub_801AF78(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (gKeySt->pressed & (A_BUTTON | DPAD_RIGHT | DPAD_LEFT))
    {
        int state;

        if (ent->id != 0)
            state = gPlaySt.debugGreenControl;
        else
            state = gPlaySt.debugRedControl;

        if (gKeySt->pressed & DPAD_LEFT)
            state--;

        if (gKeySt->pressed & (DPAD_RIGHT | A_BUTTON))
            state++;

        if (state > 2)
            state = 2;

        if (state < 0)
            state = 0;

        if (ent->id != 0)
            gPlaySt.debugGreenControl = state;
        else
            gPlaySt.debugRedControl = state;

        sub_801AED8(menu, ent);
    }

    return 0;
}

int sub_801B018(struct MenuProc* menu, struct MenuEntProc* ent)
{
    RestartGameAndChapter();
    Proc_Goto(Proc_Find(ProcScr_GameController), L_GAMECTRL_SRAMRESET);
}
