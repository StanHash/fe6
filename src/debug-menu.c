
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

// func_fe6_0801A5AC
// PutDebugTextFrame
// func_fe6_0801A674
// func_fe6_0801A698
// func_fe6_0801A724
// func_fe6_0801A748
// func_fe6_0801A760
// func_fe6_0801A7D4
// func_fe6_0801A81C
// func_fe6_0801A820
// func_fe6_0801A89C
// func_fe6_0801A940
// func_fe6_0801A944
// func_fe6_0801A9A8
// func_fe6_0801AA70
// func_fe6_0801AA74
// func_fe6_0801AA8C
// func_fe6_0801AABC
// func_fe6_0801AAE0
// func_fe6_0801AB64
// func_fe6_0801ABE8
// func_fe6_0801AC2C
// func_fe6_0801ACD8
// func_fe6_0801AD14
// func_fe6_0801AD28
// func_fe6_0801AD3C
// func_fe6_0801AD4C
// func_fe6_0801AD50
// func_fe6_0801AD6C
// func_fe6_0801AD84
// func_fe6_0801ADB4
// func_fe6_0801ADCC
// func_fe6_0801ADEC
// func_fe6_0801AE60
// func_fe6_0801AEB8
// func_fe6_0801AEBC
// func_fe6_0801AEC8
// func_fe6_0801AED8
// func_fe6_0801AF78
// func_fe6_0801B018

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

void func_fe6_0801A5AC(void)
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

    func_fe6_08041358(x, y, width + 2, 4, 0);
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

int func_fe6_0801A674(struct MenuProc* menu)
{
    EndMenu(menu);
    ClearBg0Bg1();

    StartMenu(&MenuInfo_085C7474);
    DebugInitBg(2, 0);

    return MENU_ACTION_SKIPCURSOR;
}

int func_fe6_0801A698(struct MenuProc* menu, struct MenuEntProc* ent)
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

int func_fe6_0801A724(struct MenuProc* menu, struct MenuEntProc* ent)
{
    EndMapMain();

    gPlaySt.chapter = ent->id;
    CleanupUnitsBeforeChapter();
    RestartGameAndChapter();

    return MENU_ACTION_SKIPCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801A748(struct MenuProc* menu, struct MenuEntProc* ent)
{
    EndMenu(menu);

    EndFaceById(0);
    ClearBg0Bg1();

    return MENU_ACTION_SKIPCURSOR;
}

int func_fe6_0801A760(struct MenuProc* menu, struct MenuEntProc* ent)
{
    char const* offon[] =
    {
        TEXT("\x82\x6E\x82\x65\x82\x65"), // "ＯＦＦ"
        TEXT("\x81\x40\x82\x6E\x82\x6D"), // "　ＯＮ"
    };

    struct GenericProc* proc = Proc_Find(ProcScr_DebugMonitor);

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, TEXT("\x83\x66\x83\x75\x8F\xEE\x95\xF1")); // "デブ情報"
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, offon[proc->unk66]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

int func_fe6_0801A7D4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    struct GenericProc* proc = Proc_Find(ProcScr_DebugMonitor);

    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        proc->unk66 ^= 1;
        func_fe6_0801A760(menu, ent);

        DebugInitObj(-1, 9);
    }
}

int func_fe6_0801A81C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return 0;
}

int func_fe6_0801A820(struct MenuProc* menu, struct MenuEntProc* ent)
{
    char const* weatherNames[] =
    {
        [DEBUG_WEATHER_NONE]      = TEXT("\x90\xB0\x82\xEA"), // "晴れ"
        [DEBUG_WEATHER_SANDSTORM] = TEXT("\x8D\xBB\x97\x92"), // "砂嵐"
        [DEBUG_WEATHER_SNOW]      = TEXT("\x90\xE1"), // "雪"
        [DEBUG_WEATHER_SNOWSTORM] = TEXT("\x90\x81\x90\xE1"), // "吹雪"
        [DEBUG_WEATHER_RAIN]      = TEXT("\x89\x4A"), // "雨"
        [DEBUG_WEATHER_5]         = TEXT("\x96\xE9"), // "夜"
        [DEBUG_WEATHER_FLAMES]    = TEXT("\x97\x6E\x8A\xE2"), // "溶岩"
    };

    struct GenericProc* proc = Proc_Find(ProcScr_DebugMonitor);

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8,  TEXT_COLOR_SYSTEM_WHITE, TEXT("\x93\x56\x8B\x43")); // "天気"
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, weatherNames[proc->unk58 % DEBUG_WEATHER_COUNT]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

int func_fe6_0801A89C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        struct GenericProc* proc = Proc_Find(ProcScr_DebugMonitor);

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

        case DEBUG_WEATHER_5:
            SetWeather(WEATHER_3);
            break;

        case DEBUG_WEATHER_FLAMES:
            SetWeather(WEATHER_FLAMES);
            break;

        }
    }
}

int func_fe6_0801A940(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return 0;
}

int func_fe6_0801A944(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, "\x8E\xFC\x89\xF1\x90\x94"); // "周回数"
    Text_InsertDrawString(&ent->text, 72, TEXT_COLOR_SYSTEM_BLUE, "\x8E\xFC\x96\xDA"); // "周目"
    Text_InsertDrawNumberOrBlank(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, GetGlobalCompletedPlaythroughCount() + 1);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}


int func_fe6_0801A9A8(struct MenuProc* menu, struct MenuEntProc* ent)
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

    func_fe6_0801A944(menu, ent);
}

int func_fe6_0801AA70(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return MENU_ACTION_SKIPCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801AA74(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ClearBg0Bg1();
    StartMenu(&MenuInfo_085C73E4);

    return MENU_ACTION_SKIPCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

int func_fe6_0801AA8C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    // required for a match
    u32 unused[4];

    // required for a match
    if (gPlaySt.playthrough_id != 0) {}

    func_fe6_08084EA4();

    gPlaySt.flags &= ~PLAY_FLAG_4;

    CleanupUnitsBeforeChapter();
    func_fe6_08085110(func_fe6_08084F94());

    SoftReset(0xFF);
}

int func_fe6_0801AABC(struct MenuProc* menu, struct MenuEntProc* ent)
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

    func_fe6_0806EA24(StartMenu(&MenuInfo_085C742C), (u8*) BG_VRAM + CHR_SIZE * 0x580, -1);

    PutBuildInfo(gBg2Tm + TM_OFFSET(0, 1));
    DebugPutStr(gBg2Tm + TM_OFFSET(0, 2), "DB INTERRUPT AVAILABLE");
}

int func_fe6_0801AB64(struct MenuProc* menu)
{
    struct SaveBlockInfo blockInfo;

    EnableBgSync(BG0_SYNC_BIT);

    menu->entries[3]->id = 1;

    if (func_fe6_08084438(&blockInfo, SAVE_ID_SUSPEND0) != TRUE || ((blockInfo.checksum32 + (blockInfo.checksum32>>16)) & 0xFF) != 0)
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

int func_fe6_0801ABE8(struct MenuProc* menu)
{
    EndFaceById(0);
    EndFaceById(1);

    SetDispEnable(0, 0, 0, 0, 0);

    gPal[0] = 0;
    EnablePalSync();
}

int func_fe6_0801AC2C(struct MenuProc* menu, struct MenuEntProc* ent)
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

int func_fe6_0801ACD8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    RandInit(GetGameTime());

    InitUnits();

    func_fe6_0808505C(SAVE_ID_GAME0, FALSE);
    gPlaySt.chapter = ent->id;

    func_fe6_08085110(0);
    CleanupUnitsBeforeChapter();

    RestartGameAndChapter();

    return MENU_ACTION_END;
}

int func_fe6_0801AD14(struct MenuProc* menu, struct MenuEntProc* ent)
{
    StartMenu(&MenuInfo_085C7450);

    return MENU_ACTION_SKIPCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801AD28(struct MenuProc* menu, struct MenuEntProc* ent)
{
    StartMenu(&MenuInfo_085C7408);

    return MENU_ACTION_SKIPCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801AD3C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    func_fe6_08089234(PROC_TREE_3);

    return MENU_ACTION_SKIPCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801AD4C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return MENU_ACTION_SKIPCURSOR;
}

int func_fe6_0801AD50(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability != 0)
        return MENU_ACTION_SE_6B;

    func_fe6_080857B0(SAVE_ID_SUSPEND1);

    return MENU_ACTION_SKIPCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

bool func_fe6_0801AD6C(void)
{
    return !func_fe6_080859E0(SAVE_ID_SUSPEND1) ? TRUE : FALSE;
}

int func_fe6_0801AD84(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability != 0)
        return MENU_ACTION_SE_6B;

    if (Proc_Find(ProcScr_BmMain) != NULL)
        EndMapMain();

    func_fe6_080858E4(SAVE_ID_SUSPEND1);
    RestartGameAndLoadSuspend();

    return MENU_ACTION_SKIPCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

bool func_fe6_0801ADB4(void)
{
    return !func_fe6_080859E0(SAVE_ID_SUSPEND0) ? TRUE : FALSE;
}

int func_fe6_0801ADCC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability != 0)
        return MENU_ACTION_SE_6B;

    func_fe6_080858E4(SAVE_ID_SUSPEND0);
    RestartGameAndLoadSuspend();

    return MENU_ACTION_SKIPCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801ADEC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    char const* offon[] =
    {
        "\x82\x6E\x82\x65\x82\x65", // "ＯＦＦ"
        "\x82\x6E\x82\x6D", // "ＯＮ"
    };

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, "\x82\xB3\x82\xAD\x93\x47"); // "さく敵"
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, offon[gPlaySt.vision != 0]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

int func_fe6_0801AE60(struct MenuProc* menu, struct MenuEntProc* ent)
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

int func_fe6_0801AEB8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return 0;
}

int func_fe6_0801AEBC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    StartGame();

    return MENU_ACTION_SKIPCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

int func_fe6_0801AEC8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    func_fe6_0800285C(0x300);

    return MENU_ACTION_SKIPCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801AED8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    char const* strings[] =
    {
        "\x82\x62\x82\x6F", // "ＣＰ"
        "\x90\x6C\x8A\xD4", // "人間"
        "\x95\x73\x8E\x51\x89\xC1", // "不参加"
    };

    int state;

    if (ent->id != 0)
        state = gPlaySt.debug_control_green;
    else
        state = gPlaySt.debug_control_red;

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, ent->id != 0 ? "\x97\xCE\x8C\x52" : "\x90\xD4\x8C\x52"); // "緑軍", "赤軍"
    Text_InsertDrawString(&ent->text, 32, TEXT_COLOR_SYSTEM_BLUE, strings[state]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));

    return 0;
}

int func_fe6_0801AF78(struct MenuProc* menu, struct MenuEntProc* ent)
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

        func_fe6_0801AED8(menu, ent);
    }

    return 0;
}

int func_fe6_0801B018(struct MenuProc* menu, struct MenuEntProc* ent)
{
    RestartGameAndChapter();
    Proc_Goto(Proc_Find(ProcScr_GameController), L_GAMECTRL_SRAMRESET);
}
