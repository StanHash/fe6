#pragma once

#include "common.h"

#include "proc.h"
#include "text.h"
#include "unit.h"

enum
{
    STATSCREEN_TEXT_PNAME = 0,
    STATSCREEN_TEXT_JNAME = 1,
    STATSCREEN_TEXT_2 = 2,
    STATSCREEN_TEXT_3 = 3,
    STATSCREEN_TEXT_4 = 4,
    STATSCREEN_TEXT_5 = 5,
    STATSCREEN_TEXT_6 = 6,
    STATSCREEN_TEXT_7 = 7,
    STATSCREEN_TEXT_8 = 8,
    STATSCREEN_TEXT_9 = 9,
    STATSCREEN_TEXT_10 = 10,
    STATSCREEN_TEXT_11 = 11,
    STATSCREEN_TEXT_12 = 12,
    STATSCREEN_TEXT_13 = 13,
    STATSCREEN_TEXT_14 = 14,
    STATSCREEN_TEXT_15 = 15,
    STATSCREEN_TEXT_16 = 16,
    STATSCREEN_TEXT_17 = 17,
    STATSCREEN_TEXT_18 = 18,
    STATSCREEN_TEXT_19 = 19,
    STATSCREEN_TEXT_20 = 20,
    STATSCREEN_TEXT_21 = 21,
    STATSCREEN_TEXT_22 = 22,
    STATSCREEN_TEXT_23 = 23,
    STATSCREEN_TEXT_24 = 24,
    STATSCREEN_TEXT_25 = 25,
    STATSCREEN_TEXT_26 = 26,
    STATSCREEN_TEXT_27 = 27,
    STATSCREEN_TEXT_28 = 28,
    STATSCREEN_TEXT_29 = 29,
    STATSCREEN_TEXT_30 = 30,
    STATSCREEN_TEXT_31 = 31,
    STATSCREEN_TEXT_32 = 32,
    STATSCREEN_TEXT_33 = 33,
    STATSCREEN_TEXT_BWL = 34,

    MAX_STATSCREEN_TEXT,
};

enum
{
    STATSCREEN_PAGE_0,
    STATSCREEN_PAGE_1,
    STATSCREEN_PAGE_2,
};

// TODO: rename (the use of "Info" in this name doesn't fit convention used elsewhere in the source)
// ("Info" should refer to something const)
struct StatScreenInfo
{
    /* 00 */ u8 unk_00;
    /* 01 */ u8 unit_id;
    /* 02 */ u16 excluded_unit_flags;
};

struct StatScreenSt
{
    /* 00 */ u8 page;
    /* 01 */ u8 page_count;
    /* 02 */ u16 page_slide_key_bit;
    /* 04 */ i16 x_disp_off; // Note: Always 0, not properly taked into account by most things
    /* 06 */ i16 y_disp_off;
    /* 08 */ bool8 is_transitioning;
    /* 0C */ struct Unit * unit;
    /* 10 */ struct MuProc * mu;
    /* 14 */ struct HelpBoxInfo const * help;
    /* 18 */ struct Text text[MAX_STATSCREEN_TEXT];
};

struct StatScreenTextInfo
{
    /* 00 */ struct Text * text;
    /* 04 */ u16 * tm;
    /* 08 */ u8 color;
    /* 09 */ u8 x_offset;
    /* 0C */ char const * const * str_list;
};

struct MuralBackgroundProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 pad_29[0x4C - 0x29];
    /* 4C */ i16 offset;
};

struct StatScreenPageSlideProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x4A - 0x29];
    /* 4A */ i16 new_page;
    /* 4C */ i16 clock;
    /* 4E */ u8 pad_4E[0x52 - 0x4E];
    /* 52 */ u16 key_bit;
};

struct StatScreenUnitSlideProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x38 - 0x29];
    /* 38 */ i32 direction;
    /* 3C */ i32 y_disp_init;
    /* 40 */ i32 y_disp_fini;
    /* 44 */ u8 pad_44[0x4A - 0x44];
    /* 4A */ i16 new_unit_id;
    /* 4C */ i16 clock;
};

struct StatScreenPageNameProc
{
    /* 00 */ PROC_HEADER;

    // number sprite proc only
    /* 2A */ i16 x_left;
    /* 2C */ i16 x_right;
    /* 2E */ u16 clock_left;
    /* 30 */ u16 clock_right;
    /* 32 */ i16 anim_speed_left;
    /* 34 */ i16 anim_speed_right;

    // name sprite proc only
    /* 36 */ u8 page_id;
    /* 38 */ i16 vertical_scale; // int 6 == 1:1 (1.0) scale
};

// DrawUiGaugeBitmapEdgeColumn
// DrawUiGaugeBitmapBaseColumn
// DrawUiGaugeBitmapFilledColumn
// DrawUiGaugeBitmapBonusColumn
// DrawUiGauge
// PutDrawUiGauge

// BackgroundSlide_Init
// BackgroundSlide_Loop
ProcPtr StartMuralBackground(ProcPtr parent, void * vram, int pal);
void EndMuralBackground(void);

int GetLastStatScreenUnitId(void);
// SetStatScreenLastUnitId
void SetStatScreenExcludedUnitFlags(int flags);
// InitStatScreenText
// PutStatScreenText
// PutStatScreenLeftPanelInfo
// PutStatScreenStatWithBar
// PutStatScreenPersonalInfoPage
// PutStatScreenItemsPage
// PutStatScreenSupportList
// PutStatScreenWeaponExpBar
// PutStatScreenWeaponExpAndSupportsPage
// PutStatScreenPage
// FindNextStatScreenUnit
void StatScreenPageSlide_Loop(struct StatScreenPageSlideProc * proc);
void StatScreenPageSlide_End(struct StatScreenPageSlideProc * proc);
void StartStatScreenPageSlide(fu16 key_bit, int new_page, ProcPtr parent);
void StatScreenUnitSlide_FadeOutInit(struct StatScreenUnitSlideProc * proc);
// StatScreenUnitSlide_FadeOutLoop
// StatScreenUnitSlide_FadeInInit
// StatScreenUnitSlide_FadeInLoop
// StatScreenUnitSlide_ChangeUnit
// StatScreenUnitSlide_End
// StartStatScreenUnitSlide
// PutUpdateStatScreenPageName
// StatScreenPageName_Init
// StatScreenPageName_Main
// StatScreenPageName_CloseMain
// StatScreenPageName_OpenMain
// StatScreenSprites_Init
// StatScreenSprites_BumpCheck
// StatScreenSprites_PutArrows
// StatScreenSprites_PutNumberLabel
// StatScreenSprites_PutMuAreaSprites
// StatScreenSprites_PutRescueMarkers
// StatScreen_DisableScreen
// StatScreen_Init
void StatScreen_InitUnit(ProcPtr proc);
// StatScreen_Main
// StatScreen_BackUpStatus
// StatScreen_UpdateLastHelpInfo
// SyncStatScreenBgOffset
// StatScreen_CleanUp
void StartStatScreen(struct Unit * unit, ProcPtr parent);
void StartStatScreenHelp(int page_id, ProcPtr proc);
// HelpBoxPopulateStatScreenItem
// HelpBoxPopulateStatScreenStatus
// HelpBoxPopulateStatScreenPower
// HelpBoxRedirectStatScreenItem
// HelpBoxPopulateStatScreenWeaponExp
// HelpBoxPopulateStatScreenPInfo
// HelpBoxPopulateStatScreenJInfo
// HelpBoxRedirectStatScreenSupports
