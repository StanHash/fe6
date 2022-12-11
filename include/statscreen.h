#pragma once

#include "common.h"

#include "proc.h"
#include "text.h"
#include "unit.h"

enum
{
    STATSCREEN_TEXT_PNAME,
    STATSCREEN_TEXT_JNAME,
    STATSCREEN_TEXT_UNUSED,
    STATSCREEN_TEXT_POW,
    STATSCREEN_TEXT_SKL,
    STATSCREEN_TEXT_SPD,
    STATSCREEN_TEXT_LCK,
    STATSCREEN_TEXT_DEF,
    STATSCREEN_TEXT_RES,
    STATSCREEN_TEXT_MOV,
    STATSCREEN_TEXT_CON,
    STATSCREEN_TEXT_AID,
    STATSCREEN_TEXT_RESCUE,
    STATSCREEN_TEXT_AFFINITY,
    STATSCREEN_TEXT_STATUS,
    // TODO: assert that there are as many items here than in inv
    STATSCREEN_TEXT_ITEM_A,
    STATSCREEN_TEXT_ITEM_B,
    STATSCREEN_TEXT_ITEM_C,
    STATSCREEN_TEXT_ITEM_D,
    STATSCREEN_TEXT_ITEM_E,
    STATSCREEN_TEXT_EQUIPRANGE,
    STATSCREEN_TEXT_EQUIPATTACK,
    STATSCREEN_TEXT_EQUIPHIT,
    STATSCREEN_TEXT_EQUIPCRIT,
    STATSCREEN_TEXT_EQUIPAVOID,
    STATSCREEN_TEXT_WEXP_A,
    STATSCREEN_TEXT_WEXP_B,
    STATSCREEN_TEXT_WEXP_C,
    STATSCREEN_TEXT_WEXP_D,
    STATSCREEN_TEXT_SUPPORT_A,
    STATSCREEN_TEXT_SUPPORT_B,
    STATSCREEN_TEXT_SUPPORT_C,
    STATSCREEN_TEXT_SUPPORT_D,
    STATSCREEN_TEXT_SUPPORT_E,
    STATSCREEN_TEXT_BWL,

    MAX_STATSCREEN_TEXT,
};

enum
{
    STATSCREEN_PAGE_PERSONALINFO,
    STATSCREEN_PAGE_ITEMS,
    STATSCREEN_PAGE_WEXPANDSUPPORTS,
};

// TODO: rename (the use of "Info" in this name doesn't fit convention used elsewhere in the source)
// (tl;dr "Info" should imply const)
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

struct StatScreenSpritesProc
{
    /* 00 */ PROC_HEADER;

    // sprites proc only
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

void DrawUiGaugeBitmapEdgeColumn(u8 * bitmap, int pixels_per_line, int column);
void DrawUiGaugeBitmapBaseColumn(u8 * bitmap, int pixels_per_line, int column);
void DrawUiGaugeBitmapFilledColumn(u8 * bitmap, int pixels_per_line, int column);
void DrawUiGaugeBitmapBonusColumn(u8 * bitmap, int pixels_per_line, int column);
void DrawUiGauge(int chr, int dot_x, int chr_count, int dot_width, int dot_plain, int dot_bonus);
void PutDrawUiGauge(int chr, int width, u16 * tm, int tileref, int dot_width, int dot_plain, int dot_bonus);

void BackgroundSlide_Init(struct MuralBackgroundProc * proc);
void BackgroundSlide_Loop(struct MuralBackgroundProc * proc);
ProcPtr StartMuralBackground(ProcPtr parent, void * vram, int pal);
void EndMuralBackground(void);

int GetLastStatScreenUnitId(void);
void SetStatScreenLastUnitId(int unit_id);
void SetStatScreenExcludedUnitFlags(int flags);
void InitStatScreenText(void);
void PutStatScreenText(struct StatScreenTextInfo const * list);
void PutStatScreenLeftPanelInfo(void);
void PutStatScreenStatWithBar(int num, int x, int y, int base, int total, int max);
void PutStatScreenPersonalInfoPage(void);
void PutStatScreenItemsPage(void);
void PutStatScreenSupportList(void);
void PutStatScreenWeaponExpBar(int num, int x, int y, int item_kind);
void PutStatScreenWeaponExpAndSupportsPage(void);
void PutStatScreenPage(int page_id);
struct Unit * FindNextStatScreenUnit(struct Unit * current_unit, int iter_step);
void StatScreenPageSlide_Loop(struct StatScreenPageSlideProc * proc);
void StatScreenPageSlide_End(struct StatScreenPageSlideProc * proc);
void StartStatScreenPageSlide(fu16 key_bit, int new_page, ProcPtr parent);
void StatScreenUnitSlide_FadeOutInit(struct StatScreenUnitSlideProc * proc);
void StatScreenUnitSlide_FadeOutLoop(struct StatScreenUnitSlideProc * proc);
void StatScreenUnitSlide_FadeInInit(struct StatScreenUnitSlideProc * proc);
void StatScreenUnitSlide_FadeInLoop(struct StatScreenUnitSlideProc * proc);
void StatScreenUnitSlide_ChangeUnit(struct StatScreenUnitSlideProc * proc);
void StatScreenUnitSlide_End(struct StatScreenUnitSlideProc * proc);
void StartStatScreenUnitSlide(struct Unit * unit, int direction, ProcPtr parent);
void PutUpdateStatScreenPageName(int page_id);
void StatScreenPageName_Init(struct StatScreenSpritesProc * proc);
void StatScreenPageName_Main(struct StatScreenSpritesProc * proc);
void StatScreenPageName_CloseMain(struct StatScreenSpritesProc * proc);
void StatScreenPageName_OpenMain(struct StatScreenSpritesProc * proc);
void StatScreenSprites_Init(struct StatScreenSpritesProc * proc);
void StatScreenSprites_BumpCheck(struct StatScreenSpritesProc * proc);
void StatScreenSprites_PutArrows(struct StatScreenSpritesProc * proc);
void StatScreenSprites_PutNumberLabel(struct StatScreenSpritesProc * proc);
void StatScreenSprites_PutMuAreaSprites(struct StatScreenSpritesProc * proc);
void StatScreenSprites_PutRescueMarkers(struct StatScreenSpritesProc * proc);
void StatScreen_DisableScreen(ProcPtr proc);
void StatScreen_Init(ProcPtr proc);
void StatScreen_InitUnit(ProcPtr proc);
void StatScreen_Main(ProcPtr proc);
void StatScreen_BackUpStatus(ProcPtr proc);
void StatScreen_UpdateLastHelpInfo(ProcPtr proc);
void SyncStatScreenBgOffset(void);
void StatScreen_CleanUp(ProcPtr proc);
void StartStatScreen(struct Unit * unit, ProcPtr parent);
void StartStatScreenHelp(int page_id, ProcPtr proc);

void HelpBoxPopulateStatScreenItem(struct HelpBoxProc * proc);
void HelpBoxPopulateStatScreenStatus(struct HelpBoxProc * proc);
void HelpBoxPopulateStatScreenPower(struct HelpBoxProc * proc);
void HelpBoxRedirectStatScreenItem(struct HelpBoxProc * proc);
void HelpBoxPopulateStatScreenWeaponExp(struct HelpBoxProc * proc);
void HelpBoxPopulateStatScreenPInfo(struct HelpBoxProc * proc);
void HelpBoxPopulateStatScreenJInfo(struct HelpBoxProc * proc);
void HelpBoxRedirectStatScreenSupports(struct HelpBoxProc * proc);

extern struct ProcScr CONST_DATA ProcScr_BackgroundSlide[];
extern struct ProcScr CONST_DATA ProcScr_StatScreenPageSlide[];
extern struct ProcScr CONST_DATA ProcScr_StatScreenUnitSlide[];
extern struct ProcScr CONST_DATA ProcScr_StatScreenPageName[];
extern struct ProcScr CONST_DATA ProcScr_StatScreenSprites[];
extern struct ProcScr CONST_DATA ProcScr_SyncStatScreenBgOffset[];
extern struct ProcScr CONST_DATA ProcScr_StatScreen[];

extern struct StatScreenInfo gStatScreenInfo;
extern struct StatScreenSt gStatScreenSt;
