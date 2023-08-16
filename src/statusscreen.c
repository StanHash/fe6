#include "statusscreen.h"

#include "hardware.h"
#include "oam.h"
#include "armfunc.h"
#include "sound.h"
#include "icon.h"
#include "sprite.h"
#include "face.h"
#include "msg.h"
#include "util.h"
#include "unit.h"
#include "chapterinfo.h"
#include "chapter.h"
#include "gold.h"
#include "faction.h"
#include "bm.h"
#include "bmio.h"
#include "ui.h"
#include "statscreen.h"
#include "helpbox.h"
#include "save_core.h"
#include "save_stats.h"
#include "save_xmap.h"

#include "constants/msg.h"
#include "constants/pids.h"
#include "constants/faces.h"
#include "constants/songs.h"

#include "constants/videoalloc_global.h"

// TODO: put in ewram overlay properly
extern struct StatusScreenSt gStatusScreenSt;

void StatusScreenFadeIn_Init(struct StatusScreenProc * proc)
{
    proc->clock = 3;
    ColorFadeSetupFromBlack(+8);
}

void StatusScreenFadeOut_Init(struct StatusScreenProc * proc)
{
    proc->clock = 3;
    ColorFadeSetupFromColorToBlack(-8);
}

void StatusScreenFade_Loop(struct StatusScreenProc * proc)
{
    ColorFadeTick();
    EnablePalSync();

    proc->clock--;

    if (proc->clock < 0)
        Proc_Break(proc);
}

void StatusScreenFadeOut_Fini(struct StatusScreenProc * proc)
{
    SetBlendDarken(0x10);
    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);
}

struct ProcScr CONST_DATA ProcScr_StatusScreenFadeIn[] =
{
    PROC_CALL(StatusScreenFadeIn_Init),
    PROC_REPEAT(StatusScreenFade_Loop),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_StatusScreenFadeOut[] =
{
    PROC_CALL(StatusScreenFadeOut_Init),
    PROC_REPEAT(StatusScreenFade_Loop),
    PROC_CALL(StatusScreenFadeOut_Fini),
    PROC_END,
};

u16 CONST_DATA Sprite_086782D4[] =
{
    12,
    OAM0_SHAPE_8x8 + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_HFLIP, OAM2_CHR(4),
    OAM0_SHAPE_8x8 + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_X(8), OAM2_CHR(0),
    OAM0_SHAPE_8x8 + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_X(16), OAM2_CHR(0),
    OAM0_SHAPE_8x8 + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_X(24), OAM2_CHR(0),
    OAM0_SHAPE_8x8 + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_X(32), OAM2_CHR(0),
    OAM0_SHAPE_8x8 + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_X(40), OAM2_CHR(4),
    OAM0_SHAPE_8x8 + OAM0_Y(8) + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_HFLIP + OAM1_VFLIP, OAM2_CHR(4),
    OAM0_SHAPE_8x8 + OAM0_Y(8) + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_X(8) + OAM1_VFLIP, OAM2_CHR(0),
    OAM0_SHAPE_8x8 + OAM0_Y(8) + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_X(16) + OAM1_VFLIP, OAM2_CHR(0),
    OAM0_SHAPE_8x8 + OAM0_Y(8) + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_X(24) + OAM1_VFLIP, OAM2_CHR(0),
    OAM0_SHAPE_8x8 + OAM0_Y(8) + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_X(32) + OAM1_VFLIP, OAM2_CHR(0),
    OAM0_SHAPE_8x8 + OAM0_Y(8) + OAM0_BLEND, OAM1_SIZE_8x8 + OAM1_X(40) + OAM1_VFLIP, OAM2_CHR(4),
};

void StatusScreenSprites_Loop(struct StatusScreenProc * proc)
{
    if (gStatusScreenSt.in_transition)
        return;

    if (gStatusScreenSt.page == 0)
    {
        if (gStatusScreenSt.put_playthrough_number)
        {
            PutSprite(4, 0, 144, Sprite_086782D4, OAM2_CHR(0x240) + OAM2_PAL(4) + OAM2_LAYER(2));
        }

        PutTime(gBg0Tm + TM_OFFSET(20, 17), TEXT_COLOR_SYSTEM_BLUE, GetGameTime(), FALSE);
        EnableBgSync(BG0_SYNC_BIT);
    }

    if ((gPlaySt.flags & PLAY_FLAG_COMPLETE) != 0)
    {
        // D=
        register int oam2 asm("r4") = OAM2_CHR(0x280 + 10) + OAM2_PAL(3) + (GetGameTime() / 8) % 6;

        if (gStatusScreenSt.page == 0)
        {
            PutSprite(4, DISPLAY_WIDTH - 8, 104, Sprite_8x16_HFlipped, oam2);
        }
        else
        {
            PutSprite(4, 0, 104, Sprite_8x16, oam2);
        }
    }
}

struct ProcScr CONST_DATA ProcScr_StatusScreenSprites[] =
{
    PROC_REPEAT(StatusScreenSprites_Loop),
    PROC_END,
};

char const * GetRedLeaderName(void)
{
    FOR_UNITS_FACTION(FACTION_RED, unit,
    {
        if ((UNIT_ATTRIBUTES(unit) & UNIT_ATTR_BOSS) != 0)
            return DecodeMsg(unit->pinfo->msg_name);
    })

    return DecodeMsg(MSG_727);
}

void func_fe6_080736C8(void)
{
    int hard_flag = (gPlaySt.flags & PLAY_FLAG_HARD) != 0 ? 4 : 0;

    func_fe6_08070CB4(hard_flag + 0, BGPAL_STATUSSCREEN_4);
    func_fe6_08070CB4(hard_flag + 1, BGPAL_STATUSSCREEN_5);
    func_fe6_08070D08(0x400 + BGCHR_B_STATUSSCREEN_3C0, func_fe6_08070E0C(&gPlaySt));
    func_fe6_08070D48(BGCHR_STATUSSCREEN_280);
    func_fe6_08070DA8(gBg2Tm + TM_OFFSET(3, 1), BGPAL_STATUSSCREEN_4);
    func_fe6_08070DC8(gBg1Tm + TM_OFFSET(3, 0), BGPAL_STATUSSCREEN_5);
}

void func_fe6_0807372C(struct StatusScreenProc * proc)
{
    Text_InsertDrawString(gStatusScreenSt.text + 1, 2, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_724));
    PutDrawText(gStatusScreenSt.text + 1, gBg0Tm + TM_OFFSET(1, 5), TEXT_COLOR_SYSTEM_BLUE, 25, 0,
        DecodeMsg(GetChapterInfo(gPlaySt.chapter)->msg_30));

    Text_InsertDrawString(gStatusScreenSt.text + 2, 0, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_725));
    Text_SetParams(gStatusScreenSt.text + 2, 74, TEXT_COLOR_SYSTEM_BLUE);
    Text_DrawNumber(gStatusScreenSt.text + 2, gPlaySt.turn);
    PutText(gStatusScreenSt.text + 2, gBg0Tm + TM_OFFSET(18, 4));

    Text_InsertDrawString(gStatusScreenSt.text + 3, 0, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_726));
    Text_InsertDrawString(gStatusScreenSt.text + 3, 82, TEXT_COLOR_SYSTEM_GOLD, JTEXT("Ｇ"));
    Text_InsertDrawNumberOrBlank(gStatusScreenSt.text + 3, 74, 2, GetGold());
    PutText(gStatusScreenSt.text + 3, gBg0Tm + TM_OFFSET(18, 6));
}

void func_fe6_08073808(struct StatusScreenProc * proc)
{
    char const * text_str;
    int x_text;

    Text_InsertDrawString(gStatusScreenSt.text + 1, 2, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_724));
    PutDrawText(gStatusScreenSt.text + 1, gBg0Tm + TM_OFFSET(1, 6), TEXT_COLOR_SYSTEM_BLUE, 25, 0,
        func_fe6_080867FC(gPlaySt.chapter));

    Text_InsertDrawString(gStatusScreenSt.text + 2, 0, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_725));
    Text_SetParams(gStatusScreenSt.text + 2, 50, TEXT_COLOR_SYSTEM_BLUE);
    Text_DrawNumber(gStatusScreenSt.text + 2, gPlaySt.turn);
    PutText(gStatusScreenSt.text + 2, gBg0Tm + TM_OFFSET(21, 6));

    SetTextFontGlyphs(TEXT_GLYPHS_TALK);
    gActiveFont->tileref |= TILE_PAL_SAFE(BGPAL_STATUSSCREEN_TALKTEXT);

    text_str = func_fe6_080867F0(gPlaySt.chapter);
    x_text = GetStringTextCenteredPos(12 * 8, text_str);

    Text_InsertDrawString(gStatusScreenSt.text + 0, x_text, 0, text_str);
    PutText(gStatusScreenSt.text + 0, gBg0Tm + TM_OFFSET(9, 4));

    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);
    gActiveFont->tileref &= ~TILE_PAL_SAFE(-1);
}

void func_fe6_080738FC(struct StatusScreenProc * proc)
{
    Text_InsertDrawString(gStatusScreenSt.text + 4, 0, TEXT_COLOR_SYSTEM_WHITE,
        DecodeMsg(GetChapterInfo(gPlaySt.chapter)->msg_32));
    Text_SetParams(gStatusScreenSt.text + 4, 69, TEXT_COLOR_SYSTEM_BLUE);
    Text_DrawNumber(gStatusScreenSt.text + 4,
        CountFactionUnitsWithoutFlags(FACTION_BLUE, UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED));

    Text_InsertDrawString(gStatusScreenSt.text + 5, 0, TEXT_COLOR_SYSTEM_WHITE,
        DecodeMsg(GetChapterInfo(gPlaySt.chapter)->msg_34));
    Text_SetParams(gStatusScreenSt.text + 5, 69, TEXT_COLOR_SYSTEM_BLUE);
    Text_DrawNumber(gStatusScreenSt.text + 5,
        CountFactionUnitsWithoutFlags(FACTION_RED, UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED));

    Text_InsertDrawString(gStatusScreenSt.text + 6, 0, TEXT_COLOR_SYSTEM_WHITE,
        DecodeMsg(GetUnitByPid(PID_ROY)->pinfo->msg_name));

    Text_InsertDrawString(gStatusScreenSt.text + 7, 0, TEXT_COLOR_SYSTEM_WHITE, GetRedLeaderName());

    Text_InsertDrawString(gStatusScreenSt.text + 8, 0, TEXT_COLOR_SYSTEM_GOLD, JTEXT("周目"));
}

void DrawStatusScreenPageA(int unused)
{
    int chibi = GetChapterInfo(gPlaySt.chapter)->chibi_36;

    PutFaceChibi(FID_FACTION_CHIBI,
        gUiTmScratchC + TM_OFFSET(4, 0), 0x400 + BGCHR_B_STATUSSCREEN_280 + 1, 8, FALSE);
    PutFaceChibi(FID_FACTION_CHIBI + chibi,
        gUiTmScratchC + TM_OFFSET(4, 4), 0x400 + BGCHR_B_STATUSSCREEN_280 + 1 + 0x10, 9, FALSE);

    TmApplyTsa(gUiTmScratchB + TM_OFFSET(0, 0), gUnk_0833C6F4, TILEREF(0, 2));
    TmApplyTsa(gUiTmScratchB + TM_OFFSET(19, 8), gUnk_0833C8D8, TILEREF(0, 2));

    PutText(gStatusScreenSt.text + 4, gUiTmScratchA + TM_OFFSET(8, 1));
    PutText(gStatusScreenSt.text + 5, gUiTmScratchA + TM_OFFSET(8, 5));
    PutText(gStatusScreenSt.text + 6, gUiTmScratchA + TM_OFFSET(20, 1));
    PutText(gStatusScreenSt.text + 7, gUiTmScratchA + TM_OFFSET(20, 5));

    TmApplyTsa(gUiTmScratchC + TM_OFFSET(18, 1), Tsa_StatusScreen_FactionInfoFrame, TILEREF(BGCHR_B_STATUSSCREEN_380, 6));
    TmApplyTsa(gUiTmScratchC + TM_OFFSET(18, 5), Tsa_StatusScreen_FactionInfoFrame, TILEREF(BGCHR_B_STATUSSCREEN_380, 6));
    TmApplyTsa(gUiTmScratchC + TM_OFFSET(20, 8), Tsa_StatusScreen_PlaytimeFrame, TILEREF(BGCHR_B_STATUSSCREEN_380, 6));

    PutTime(gUiTmScratchA + TM_OFFSET(20, 9), 2, GetGameTime(), FALSE);
}

void func_fe6_08073AC8(struct StatusScreenProc * proc)
{
    struct HelpBoxPrintProc * print_proc;
    int i;

    SetTextFontGlyphs(TEXT_GLYPHS_TALK);

    print_proc = SpawnProc(ProcScr_Unk_08677FD0, PROC_TREE_3);

    print_proc->font = NULL;
    print_proc->line = 0;
    print_proc->str_it = func_fe6_08086910(gPlaySt.chapter);
    print_proc->chars_per_print = UINT8_MAX;
    print_proc->clock_interval = 0;
    print_proc->clock = 0;

    for (i = 0; i < 5; i++)
        print_proc->text[i] = gStatusScreenSt.text + 9 + i;

    GetStringTextBox(print_proc->str_it, &gStatusScreenSt.trial_something_width, &gStatusScreenSt.trial_something_height);

    func_fe6_08071274(print_proc);
    Proc_End(print_proc);

    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);
}

void DrawStatusScreenPageB(int unused)
{
    int x, y, i;

    gActiveFont->tileref |= TILE_PAL_SAFE(BGPAL_STATUSSCREEN_TALKTEXT);

    x = (24 - gStatusScreenSt.trial_something_width / 8) / 2 + 3;
    y = (6 - gStatusScreenSt.trial_something_height / 16);

    for (i = 0; i < 5; i++)
    {
        PutText(gStatusScreenSt.text + 9 + i, gUiTmScratchA + TM_OFFSET(x, y + i * 2));
    }

    gActiveFont->tileref &= ~TILE_PAL_SAFE(-1);

    Decompress(gUnk_08309408, gBuf);
    TmApplyTsa(gUiTmScratchB + TM_OFFSET(2, 0), gBuf, TILEREF(0, BGPAL_STATUSSCREEN_2));
}

void DrawStatusScreenPage(struct StatusScreenProc * proc, int page)
{
    CpuFastFill(0, gUiTmScratchA, 12 * 0x20 * sizeof(u16));
    CpuFastFill(0, gUiTmScratchB, 12 * 0x20 * sizeof(u16));
    CpuFastFill16(TILEREF(0x280, 0) | TILE_HFLIP, gUiTmScratchC, 12 * 0x20 * sizeof(u16));

    switch (page)
    {
        case 0:
            DrawStatusScreenPageA(0);
            break;

        case 1:
            DrawStatusScreenPageB(0);
            break;
    }
}

struct TextInitInfo CONST_DATA gUnk_08678330[] =
{
    { gStatusScreenSt.text + 1, 22 },
    { gStatusScreenSt.text + 2, 11 },
    { gStatusScreenSt.text + 3, 12 },
    { gStatusScreenSt.text + 4, 10 },
    { gStatusScreenSt.text + 5, 10 },
    { gStatusScreenSt.text + 6,  7 },
    { gStatusScreenSt.text + 7,  7 },
    { gStatusScreenSt.text + 8,  2 },
    { 0 }, // end
};

struct TextInitInfo CONST_DATA gUnk_08678378[] =
{
    { gStatusScreenSt.text + 0,  12 },
    { gStatusScreenSt.text + 9,  24 },
    { gStatusScreenSt.text + 10, 24 },
    { gStatusScreenSt.text + 11, 24 },
    { gStatusScreenSt.text + 12, 24 },
    { gStatusScreenSt.text + 13, 24 },
    { 0 },
};

void StatusScreen_Init(struct StatusScreenProc * proc)
{
    InitBgs(NULL);

    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg2_ct.priority = 1;
    gDispIo.bg1_ct.priority = 2;
    gDispIo.bg3_ct.priority = 3;

    SetBgChrOffset(2, 0x8000);
    SetBlankChr(0x400 + BGCHR_B_STATUSSCREEN_280);

    ResetText();

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, 0, 0);

    ClearUi();

    TmFill(gBg2Tm, BGCHR_B_STATUSSCREEN_280 | TILE_HFLIP);

    ApplyPalettes(Pal_Text, 0, 2);
    ApplyPalettes(Pal_Unk_0833C944, BGPAL_STATUSSCREEN_2, 2);
    ApplyUiWindowFramePal(0x10 + 4);
    ApplyIconPalette(1, 6);
    ApplyIconPalette(1, 0x10 + 3);

    Decompress(Img_Unk_083092CC, (void *) VRAM + CHR_SIZE * (0x400 + BGCHR_B_STATUSSCREEN_380));
    Decompress(Img_Unk_0833C378, (void *) VRAM + CHR_SIZE * 0);
    Decompress(gUnk_083080D0, (void *) OBJ_VRAM0 + CHR_SIZE * 0x240);

    func_fe6_080736C8();

    InitTextList(gUnk_08678330);

    func_fe6_080738FC(proc);

    if ((gPlaySt.flags & PLAY_FLAG_COMPLETE) == 0)
    {
        func_fe6_0807372C(proc);
    }
    else
    {
        InitTextList(gUnk_08678378);
        func_fe6_08073808(proc);
        func_fe6_08073AC8(proc);
    }

    DrawStatusScreenPage(proc, 0);

    CpuFastCopy(gUiTmScratchA, gBg0Tm + TM_OFFSET(0, 8), 12 * 0x20 * sizeof(u16));
    CpuFastCopy(gUiTmScratchB, gBg1Tm + TM_OFFSET(0, 8), 12 * 0x20 * sizeof(u16));
    CpuFastCopy(gUiTmScratchC, gBg2Tm + TM_OFFSET(0, 8), 12 * 0x20 * sizeof(u16));

    gStatusScreenSt.page = 0;
    gStatusScreenSt.in_transition = FALSE;
    gStatusScreenSt.put_playthrough_number = FALSE;

    SetBlendNone();

    func_fe6_0808C390(proc, 0, -1);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);
}

void StatusScreenPageSlide_Loop(struct StatusScreenProc * proc)
{
    int offset, width, scratch_off, tm_off;

    static i8 SHOULD_BE_CONST offset_table[] =
    {
        -5, -10, -15, -19, -23, -26,
        INT8_MAX,
        +25, +21, +16, +12, +8, +5, +3, +2, +1, 0,
        INT8_MIN,
    };

    CpuFastFill(0, gBg0Tm + TM_OFFSET(0, 8), 12 * 0x20 * sizeof(u16));
    CpuFastFill(0, gBg1Tm + TM_OFFSET(0, 8), 12 * 0x20 * sizeof(u16));
    CpuFastFill16(TILEREF(0x280, 0) | TILE_HFLIP, gBg2Tm + TM_OFFSET(0, 8), 12 * 0x20 * sizeof(u16));

    offset = offset_table[proc->clock];

    if (offset == INT8_MAX)
    {
        DrawStatusScreenPage(proc, proc->slide_target_page);

        proc->clock++;
        offset = offset_table[proc->clock];
    }

    if (proc->slide_direction < 0)
        offset = -offset;

    width = 30 - ABS(offset);

    if (offset < 0)
    {
        tm_off = 0;
        scratch_off = -offset;
    }
    else
    {
        tm_off = offset;
        scratch_off = 0;
    }

    TmCopyRect(gUiTmScratchA + TM_OFFSET(scratch_off, 0), gBg0Tm + TM_OFFSET(tm_off, 8), width, 12);
    TmCopyRect(gUiTmScratchB + TM_OFFSET(scratch_off, 0), gBg1Tm + TM_OFFSET(tm_off, 8), width, 12);
    TmCopyRect(gUiTmScratchC + TM_OFFSET(scratch_off, 0), gBg2Tm + TM_OFFSET(tm_off, 8), width, 12);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);

    proc->clock++;
    offset = offset_table[proc->clock];

    if (offset == INT8_MIN)
        Proc_Break(proc);
}

void StatusScreenPageSlide_Init(struct StatusScreenProc * proc)
{
    gStatusScreenSt.in_transition = TRUE;
}

void StatusScreenPageSlide_Fini(struct StatusScreenProc * proc)
{
    gStatusScreenSt.in_transition = FALSE;
}

struct ProcScr CONST_DATA ProcScr_StatusScreenPageSlide[] =
{
    PROC_CALL(StatusScreenPageSlide_Init),
    PROC_REPEAT(StatusScreenPageSlide_Loop),
    PROC_CALL(StatusScreenPageSlide_Fini),
    PROC_END,
};

void StartStatusScreenPageSlide(struct StatusScreenProc * parent, int direction, int page)
{
    struct StatusScreenProc * proc;

    if (FindProc(ProcScr_StatusScreenPageSlide) != NULL)
        return;

    proc = SpawnProcLocking(ProcScr_StatusScreenPageSlide, parent);

    proc->slide_direction = direction;
    proc->slide_target_page = page;
    proc->clock = 0;

    gStatusScreenSt.page = page;

    PlaySe(SONG_6F);
}

void func_fe6_08073F90(struct StatusScreenProc * proc)
{
    struct HelpBoxInfo const * help;

    if ((gPlaySt.flags & PLAY_FLAG_COMPLETE) != 0)
    {
        help = gStatusScreenSt.page != 0 ? &HelpInfo_0868B3C4 : &HelpInfo_0868B2C8;
    }
    else
    {
        help = &HelpInfo_0868B1B0;
    }

    func_fe6_08070E70(NULL, -1);
    StartMovingHelpBox(help, proc);
}

void func_fe6_08073FE0(int is_first_playthrough)
{
    if (is_first_playthrough == 0)
    {
        SetBlendAlpha(6, 8);
        SetBlendTargetA(0, 0, 0, 0, 0);
        SetBlendTargetB(0, 0, 0, 1, 0);

        PutText(gStatusScreenSt.text + 8, gBg0Tm + TM_OFFSET(3, 18));
        PutNumber(gBg0Tm + TM_OFFSET(2, 18), 2, 1 + GetGlobalCompletedPlaythroughCount());

        gStatusScreenSt.put_playthrough_number = TRUE;
    }
    else
    {
        TmFillRect(gBg0Tm + TM_OFFSET(0, 18), 6, 2, 0);

        gStatusScreenSt.put_playthrough_number = FALSE;
    }

    EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_08074084(struct StatusScreenProc * proc)
{
    if (IsNotFirstPlaythrough() && (gPlaySt.flags & PLAY_FLAG_COMPLETE) == 0)
    {
        gPlaySt.unk_1D_5 ^= 1;

        func_fe6_08073FE0(IsFirstPlaythrough());

        PlaySe(SONG_77);
    }
}

void func_fe6_080740D0(void)
{
    Proc_EndEach(ProcScr_StatusScreenSprites);
    EndMuralBackground();
}

void func_fe6_080740E4(void)
{
    InitTextList(gUnk_08678330);
}

void StatusScreen_Loop(struct StatusScreenProc * proc)
{
    if ((gKeySt->pressed & KEY_BUTTON_B) != 0)
    {
        PlaySe(SONG_6B);

        Proc_Goto(proc, 99);
        return;
    }

    if ((gKeySt->pressed & KEY_BUTTON_R) != 0)
    {
        func_fe6_08073F90(proc);
        return;
    }

    if ((gKeySt->pressed & KEY_BUTTON_L) != 0)
    {
        func_fe6_08074084(proc);
        return;
    }

    if ((gPlaySt.flags & PLAY_FLAG_COMPLETE) != 0)
    {
        if (gStatusScreenSt.page == 0 && (gKeySt->pressed & KEY_DPAD_RIGHT) != 0)
        {
            StartStatusScreenPageSlide(proc, +1, 1);
            return;
        }

        if (gStatusScreenSt.page == 1 && (gKeySt->pressed & KEY_DPAD_LEFT) != 0)
        {
            StartStatusScreenPageSlide(proc, -1, 0);
            return;
        }
    }
}

void StatusScreen_InitPlaythroughCount(struct StatusScreenProc * proc)
{
    if ((gPlaySt.flags & PLAY_FLAG_COMPLETE) != 0)
        return;

    func_fe6_08073FE0(IsFirstPlaythrough());
}

struct ProcScr CONST_DATA ProcScr_StatusScreen[] =
{
    PROC_CALL(LockGame),

    PROC_CALL(StartFastFadeToBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(LockBmDisplay),
    PROC_CALL(StatusScreen_Init),
    PROC_CALL(StatusScreen_InitPlaythroughCount),
    PROC_START_CHILD(ProcScr_StatusScreenSprites),
    PROC_START_CHILD_LOCKING(ProcScr_StatusScreenFadeIn),

    PROC_REPEAT(StatusScreen_Loop),
    PROC_GOTO(99),

PROC_LABEL(99),
    PROC_START_CHILD_LOCKING(ProcScr_StatusScreenFadeOut),
    PROC_END_EACH(ProcScr_StatusScreenSprites),
    PROC_CALL(EndMuralBackground),
    PROC_CALL(UnlockBmDisplay),
    PROC_CALL(InitBmDisplay),

    PROC_CALL(StartFastFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(UnlockGame),
    PROC_END,
};

void StartStatusScreen(ProcPtr parent)
{
    if (parent != NULL)
        SpawnProcLocking(ProcScr_StatusScreen, parent);
    else
        SpawnProc(ProcScr_StatusScreen, PROC_TREE_3);
}
