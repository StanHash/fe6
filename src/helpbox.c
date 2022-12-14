#include "helpbox.h"

#include "armfunc.h"
#include "sound.h"
#include "oam.h"
#include "text.h"
#include "sprite.h"
#include "msg.h"
#include "util.h"
#include "item.h"
#include "chapterinfo.h"
#include "ui.h"

#include "constants/songs.h"
#include "constants/chapters.h"
#include "constants/videoalloc_global.h"

extern u16 const Pal_Unk_08309474[];
extern u16 const Pal_Unk_083094F4[];
extern u16 const Pal_Unk_0830D5E4[];

extern u8 const * CONST_DATA gUnk_08677F20[]; // array img ref
extern u8 const gUnk_0830C804[]; // img
extern u8 const gUnk_0830CFE0[]; // img
extern u8 const gUnk_0830D4F0[]; // tsa
extern u8 const gUnk_08308A78[]; // img
extern u16 const Pal_08100A48[]; // pal

struct HelpBoxInfo EWRAM_DATA gMutableHelpBoxInfo = { 0 };
struct HelpBoxInfo const * EWRAM_DATA gLastHelpBoxInfo = NULL;
struct Vec2i EWRAM_DATA gHelpBoxOrigin = { 0 };

extern char const gUnk_08319894[]; // JTEXT("射程");
extern char const gUnk_0831989C[]; // JTEXT("重さ");
extern char const gUnk_083198A4[]; // JTEXT("威力");
extern char const gUnk_083198AC[]; // JTEXT("命中");
extern char const gUnk_083198B4[]; // JTEXT("必殺");
extern char const gUnk_083198BC[]; // JTEXT("杖");

void UpdateHelpBoxDisplay(struct HelpBoxProc * proc, int interpolate_method)
{
    proc->x_box = Interpolate(interpolate_method, proc->x_box_init, proc->x_box_fini, proc->timer, proc->timer_end);
    proc->y_box = Interpolate(interpolate_method, proc->y_box_init, proc->y_box_fini, proc->timer, proc->timer_end);
    proc->w_box = Interpolate(interpolate_method, proc->w_box_init, proc->w_box_fini, proc->timer, proc->timer_end);
    proc->h_box = Interpolate(interpolate_method, proc->h_box_init, proc->h_box_fini, proc->timer, proc->timer_end);

    func_fe6_08070F64(proc->x_box, proc->y_box, proc->w_box, proc->h_box);

    if (proc->unk_52 == 0)
    {
        PutSprite(0, proc->x_box, proc->y_box - 11, Sprite_32x16, OAM2_CHR(11));
    }
}

void HelpBox_OnOpen(struct HelpBoxProc * proc)
{
    if (proc->unk_52 == 0)
    {
        PlaySe(SONG_70);
    }
}

void HelpBox_OnLoop(struct HelpBoxProc * proc)
{
    UpdateHelpBoxDisplay(proc, INTERPOLATE_RCUBIC);

    if (proc->timer < proc->timer_end)
        proc->timer++;
}

void HelpBox_OnClose(struct HelpBoxProc * proc)
{
    if (proc->unk_52 == 0)
    {
        PlaySe(SONG_71);

        ResetHelpBoxInitSize(proc);
        SetHelpBoxInitPosition(proc, proc->info->x, proc->info->y);
    }
}

void HelpBox_WaitClose(struct HelpBoxProc * proc)
{
    UpdateHelpBoxDisplay(proc, INTERPOLATE_LINEAR);

    proc->timer -= 3;

    if (proc->timer < 0)
        Proc_Break(proc);
}

void StartHelpBox(int x, int y, int msg)
{
    gMutableHelpBoxInfo.adjUp = NULL;
    gMutableHelpBoxInfo.adjDown = NULL;
    gMutableHelpBoxInfo.adjLeft = NULL;
    gMutableHelpBoxInfo.adjRight = NULL;
    gMutableHelpBoxInfo.x = x;
    gMutableHelpBoxInfo.y = y;
    gMutableHelpBoxInfo.msg = msg;
    gMutableHelpBoxInfo.redirect = NULL;
    gMutableHelpBoxInfo.populate = NULL;

    gHelpBoxOrigin.x = 0;
    gHelpBoxOrigin.y = 0;

    StartHelpBoxExt(&gMutableHelpBoxInfo, 0);
}

void StartItemHelpBox(int x, int y, int item)
{
    gMutableHelpBoxInfo.adjUp = NULL;
    gMutableHelpBoxInfo.adjDown = NULL;
    gMutableHelpBoxInfo.adjLeft = NULL;
    gMutableHelpBoxInfo.adjRight = NULL;
    gMutableHelpBoxInfo.x = x;
    gMutableHelpBoxInfo.y = y;
    gMutableHelpBoxInfo.msg = item;
    gMutableHelpBoxInfo.redirect = NULL;
    gMutableHelpBoxInfo.populate = HelpBoxPopulateAutoItem;

    gHelpBoxOrigin.x = 0;
    gHelpBoxOrigin.y = 0;

    StartHelpBoxExt(&gMutableHelpBoxInfo, 0);
}

struct ProcScr CONST_DATA ProcScr_HelpBox[] =
{
    PROC_SLEEP(0),

    PROC_CALL(HelpBox_OnOpen),
    PROC_REPEAT(HelpBox_OnLoop),

PROC_LABEL(99),
    PROC_CALL(HelpBox_OnClose),
    PROC_REPEAT(HelpBox_WaitClose),

    PROC_END,
};

void StartHelpBoxExt(struct HelpBoxInfo const * info, int unk)
{
    struct HelpBoxProc * proc;
    int w_inner, h_inner;

    proc = Proc_Find(ProcScr_HelpBox);

    if (proc == NULL)
    {
        proc = SpawnProc(ProcScr_HelpBox, PROC_TREE_3);

        proc->unk_52 = unk;
        SetHelpBoxInitPosition(proc, info->x, info->y);
        ResetHelpBoxInitSize(proc);
    }
    else
    {
        proc->x_box_init = proc->x_box;
        proc->y_box_init = proc->y_box;
        proc->w_box_init = proc->w_box;
        proc->h_box_init = proc->h_box;
    }

    proc->info = info;
    proc->timer = 0;
    proc->timer_end = 12;
    proc->item = 0;
    proc->msg = info->msg;

    if (proc->info->populate != NULL)
        proc->info->populate(proc);

    SetTextFontGlyphs(TEXT_GLYPHS_TALK);
    GetStringTextBox(DecodeMsg(proc->msg), &w_inner, &h_inner);
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);

    ApplyHelpBoxContentSize(proc, w_inner, h_inner);
    ApplyHelpBoxPosition(proc, info->x, info->y);

    func_fe6_08071514();
    func_fe6_080714F8(proc->item, proc->msg);

    gLastHelpBoxInfo = info;
}

void StartHelpBox_08070804(int x, int y, int msg)
{
    struct HelpBoxProc * proc;
    int w_inner, h_inner;

    proc = SpawnProc(ProcScr_HelpBox, PROC_TREE_3);

    proc->unk_52 = TRUE;
    proc->timer = 0;
    proc->timer_end = 12;
    proc->item = 0;
    proc->msg = msg;

    SetTextFontGlyphs(TEXT_GLYPHS_TALK);
    GetStringTextBox(DecodeMsg(proc->msg), &w_inner, &h_inner);
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);

    ResetHelpBoxInitSize(proc);
    ApplyHelpBoxContentSize(proc, w_inner, h_inner);

    proc->x_box_init = x + 8;
    proc->y_box_init = y + 8;

    proc->x_box_fini = x + 8;
    proc->y_box_fini = y + 8;

    func_fe6_08071514();
    func_fe6_080714F8(proc->item, proc->msg);
}

void CloseHelpBox(void)
{
    struct HelpBoxProc * proc = Proc_Find(ProcScr_HelpBox);

    if (proc != NULL)
    {
        func_fe6_08071514();
        Proc_Goto(proc, 99);
    }
}

void KillHelpBox(void)
{
    struct HelpBoxProc * proc = Proc_Find(ProcScr_HelpBox);

    if (proc != NULL)
    {
        func_fe6_08071514();
        Proc_End(proc);
    }
}

void HelpBoxMoveControl_OnInitBox(struct HelpBoxProc * proc)
{
    proc->move_key_bit = 0;

    if (proc->info->redirect)
        proc->info->redirect(proc);

    StartHelpBoxExt(proc->info, FALSE);
}

void HelpBoxMoveControl_OnIdle(struct HelpBoxProc * proc)
{
    bool box_moved = FALSE;

    PutUiHand(
        gHelpBoxOrigin.x * 8 + proc->info->x,
        gHelpBoxOrigin.y * 8 + proc->info->y);

    if (gKeySt->repeated & KEY_DPAD_UP)
        box_moved |= HelpBoxTryRelocateUp(proc);

    if (gKeySt->repeated & KEY_DPAD_DOWN)
        box_moved |= HelpBoxTryRelocateDown(proc);

    if (gKeySt->repeated & KEY_DPAD_LEFT)
        box_moved |= HelpBoxTryRelocateLeft(proc);

    if (gKeySt->repeated & KEY_DPAD_RIGHT)
        box_moved |= HelpBoxTryRelocateRight(proc);

    if (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R))
    {
        Proc_Break(proc);
        return;
    }

    if (box_moved)
    {
        PlaySe(SONG_67);
        Proc_Goto(proc, 0);
    }
}

void HelpBoxMoveControl_OnEnd(struct HelpBoxProc * proc)
{
    CloseHelpBox();
    Proc_End(proc);
}

struct ProcScr CONST_DATA ProcScr_HelpBoxMoveControl[] =
{
    PROC_SLEEP(1),

PROC_LABEL(0),
    PROC_CALL(HelpBoxMoveControl_OnInitBox),
    PROC_REPEAT(HelpBoxMoveControl_OnIdle),

    PROC_CALL(CloseHelpBox),
    PROC_END,
};

void StartMovingHelpBox(struct HelpBoxInfo const * info, ProcPtr parent)
{
    struct HelpBoxProc * proc = SpawnProcLocking(ProcScr_HelpBoxMoveControl, parent);

    gHelpBoxOrigin.x = 0;
    gHelpBoxOrigin.y = 0;

    proc->info = info;
}

void StartMovingHelpBoxExt(struct HelpBoxInfo const * info, ProcPtr parent, int x, int y)
{
    struct HelpBoxProc * proc = SpawnProcLocking(ProcScr_HelpBoxMoveControl, parent);

    gHelpBoxOrigin.x = x;
    gHelpBoxOrigin.y = y;

    proc->info = info;
}

void ApplyHelpBoxContentSize(struct HelpBoxProc * proc, int w_inner, int h_inner)
{
    w_inner = 0xE0 & (w_inner + 31); // align to 32 pixel multiple

    switch (func_fe6_08070B30(proc->item))
    {
        // TODO: enum constants

    case 1: // weapon
        w_inner = 0xA0;
        h_inner += 0x20;
        break;

    case 2: // staff
        if (w_inner < 0x60)
            w_inner = 0x60;
        h_inner += 0x10;
        break;

    }

    proc->w_box_fini = w_inner;
    proc->h_box_fini = h_inner;
}

void ApplyHelpBoxPosition(struct HelpBoxProc * proc, int x, int y)
{
    int x_span = proc->w_box_fini + 0x10;
    int y_span = proc->h_box_fini + 0x10;

    x += gHelpBoxOrigin.x * 8;
    y += gHelpBoxOrigin.y * 8;

    proc->x_box_fini = x - 0x10 - x_span / 6;

    if (proc->x_box_fini < 0)
        proc->x_box_fini = 0;

    if (proc->x_box_fini + x_span > DISPLAY_WIDTH)
        proc->x_box_fini = DISPLAY_WIDTH - x_span;

    proc->y_box_fini = y + 0x10;

    if (proc->y_box_fini + y_span > DISPLAY_HEIGHT)
        proc->y_box_fini = y - y_span;

    proc->x_box_fini += 8;
    proc->y_box_fini += 8;
}

void SetHelpBoxInitPosition(struct HelpBoxProc * proc, int x, int y)
{
    x += gHelpBoxOrigin.x * 8;
    y += gHelpBoxOrigin.y * 8;

    proc->x_box_init = x;
    proc->y_box_init = y;
}

void ResetHelpBoxInitSize(struct HelpBoxProc * proc)
{
    proc->w_box_init = 32;
    proc->h_box_init = 16;
}

int func_fe6_08070B30(int item)
{
    if (GetItemAttributes(item) & ITEM_ATTR_LOCK_DRAGON)
        return HELPBOX_INFO_NONE;

    if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
        return HELPBOX_INFO_WEAPON;

    if (GetItemAttributes(item) & ITEM_ATTR_STAFF)
        return HELPBOX_INFO_STAFF;

    return HELPBOX_INFO_NONE;
}

void HelpBoxPopulateAutoItem(struct HelpBoxProc * proc)
{
    int item = proc->info->msg;

    proc->item = item;
    proc->msg = GetItemDescMsg(item);
}

int HelpBoxTryRelocateUp(struct HelpBoxProc* proc)
{
    if (proc->info->adjUp == NULL)
        return FALSE;

    proc->info = proc->info->adjUp;
    proc->move_key_bit = KEY_DPAD_UP;

    if (proc->info->redirect)
        proc->info->redirect(proc);

    return TRUE;
}

int HelpBoxTryRelocateDown(struct HelpBoxProc* proc)
{
    if (proc->info->adjDown == NULL)
        return FALSE;

    proc->info = proc->info->adjDown;
    proc->move_key_bit = KEY_DPAD_DOWN;

    if (proc->info->redirect)
        proc->info->redirect(proc);

    return TRUE;
}

int HelpBoxTryRelocateLeft(struct HelpBoxProc* proc)
{
    if (proc->info->adjLeft == NULL)
        return FALSE;

    proc->info = proc->info->adjLeft;
    proc->move_key_bit = KEY_DPAD_LEFT;

    if (proc->info->redirect)
        proc->info->redirect(proc);

    return TRUE;
}

int HelpBoxTryRelocateRight(struct HelpBoxProc * proc)
{
    if (proc->info->adjRight == NULL)
        return FALSE;

    proc->info = proc->info->adjRight;
    proc->move_key_bit = KEY_DPAD_RIGHT;

    if (proc->info->redirect)
        proc->info->redirect(proc);

    return TRUE;
}

void func_fe6_08070C4C(ProcPtr proc)
{
    if (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R))
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_HelpBoxLockHelper[] =
{
    PROC_REPEAT(func_fe6_08070C4C),
    PROC_END,
};

// unused
int StartLockingHelpBox(int msg, ProcPtr parent)
{
    func_fe6_08070E70(NULL, -1);

    StartHelpBox(GetUiHandPrevX(), GetUiHandPrevY(), msg);
    SpawnProcLocking(ProcScr_HelpBoxLockHelper, parent);

    return TRUE;
}

struct HelpBoxInfo const * func_fe6_08070CA8(void)
{
    return gLastHelpBoxInfo;
}

// TODO: move

struct Unk_0203D404
{
    u16 unk_00;
    u16 unk_02;
};

struct Unk_0203D404 EWRAM_DATA gUnk_0203D404 = { 0 };

int EWRAM_DATA unused_0203D408 = 0;

struct Unk_0203D40C
{
    /* 00 */ struct Font font;
    /* 18 */ struct Text text[3];
    /* 30 */ u16 unk_30;
};

struct Unk_0203D40C EWRAM_DATA gUnk_0203D40C = { { 0 } };

void func_fe6_08070CB4(int flags, int pal)
{
    u16 const * pal_src;

    if (flags & 8)
    {
        ApplyPalette(Pal_Unk_0830D5E4, pal);
        return;
    }

    pal_src = (flags & 1) != 0
        ? Pal_Unk_08309474
        : Pal_Unk_083094F4;

    if (flags & 2)
        pal_src = pal_src + 0x10;

    if (flags & 4)
        pal_src = pal_src + 0x20;

    ApplyPalette(pal_src, pal);
}

void func_fe6_08070D08(int chr, int title_id)
{
    // TODO: is this really chapter?
    if (title_id < 0 || title_id >= CHAPTER_COUNT)
        title_id = CHAPTER_UNK_26;

    gUnk_0203D404.unk_02 = chr & 0x3FF;
    Decompress(gUnk_08677F20[title_id], ((void *) VRAM) + chr * CHR_SIZE);
}

void func_fe6_08070D48(int chr)
{
    gUnk_0203D404.unk_00 = chr & 0x3FF;
    Decompress(gUnk_0830C804, ((void *) VRAM) + chr * CHR_SIZE);
}

void func_fe6_08070D78(int chr)
{
    gUnk_0203D404.unk_00 = chr & 0x3FF;
    Decompress(gUnk_0830CFE0, ((void *) VRAM) + chr * CHR_SIZE);
}

void func_fe6_08070DA8(u16 * tm, int pal)
{
    int i, tile = TILEREF(gUnk_0203D404.unk_02, pal);

    for (i = 0; i < 0x40; i++)
        *tm++ = tile++;
}

void func_fe6_08070DC8(u16 * tm, int pal)
{
    int i, tile = TILEREF(gUnk_0203D404.unk_00, pal);

    for (i = 0; i < 0x80; i++)
        *tm++ = tile++;
}

void func_fe6_08070DE8(u16 * tm, int pal)
{
    TmApplyTsa_t(tm, gUnk_0830D4F0, TILEREF(gUnk_0203D404.unk_00, pal));
}

int func_fe6_08070E0C(struct PlaySt const * play_st)
{
    if (play_st == NULL)
        return 0x26;

    switch (play_st->chapter)
    {

    case -1:
    case 0x28 ... 0x2C:
        return 0x2B;

    default:
        if (play_st->flags & PLAY_FLAG_5)
        {
            switch (play_st->ending_id)
            {

            case 0:
                return 0x2A;

            case 1:
                return 0x29;

            case 2:
                return 0x28;

            }
        }

        return GetChapterInfo(play_st->chapter)->title_id;
    }
}

void func_fe6_08070E70(void * vram, int pal)
{
    if (vram == NULL)
        vram = ((void *) VRAM) + 0x10000 + OBJCHR_HELPBOX_180 * CHR_SIZE;

    if (pal < 0)
        pal = OBJPAL_HELPBOX_5;

    pal = (pal & 15) + 0x10;

    Decompress(gUnk_08308A78, vram);

    InitSpriteTextFont(&gUnk_0203D40C.font, vram, pal);
    InitSpriteText(gUnk_0203D40C.text + 0);
    InitSpriteText(gUnk_0203D40C.text + 1);
    InitSpriteText(gUnk_0203D40C.text + 2);
    SetTextFont(NULL);

    ApplyPalette(Pal_08100A48, pal);

    gUnk_0203D40C.unk_30 = OAM2_CHR(((uptr) vram) / CHR_SIZE) + OAM2_PAL(pal);
}

void func_fe6_08070EEC(void * vram, int pal)
{
    if (vram == NULL)
        vram = ((void *) VRAM) + 0x10000 + OBJCHR_HELPBOX_180 * CHR_SIZE;

    if (pal < 0)
        pal = OBJPAL_HELPBOX_5;

    pal = (pal & 15) + 0x10;

    Decompress(gUnk_08308A78, vram);

    InitSpriteTextFont(&gUnk_0203D40C.font, vram, pal);
    InitSpriteText(gUnk_0203D40C.text + 0);
    InitSpriteText(gUnk_0203D40C.text + 1);
    gUnk_0203D40C.text[2].tile_width = 0; // ok???
    SetTextFont(NULL);

    ApplyPalette(Pal_08100A48, pal);

    gUnk_0203D40C.unk_30 = OAM2_CHR(((uptr) vram) / CHR_SIZE) + OAM2_PAL(pal);
}

void func_fe6_08070F64(int x_box, int y_box, int w_box, int h_box)
{
    int y_count, x_count;
    int iy, ix, x_px, y_px;

    if (w_box < 0x20)
        w_box = 0x20;

    if (w_box > 0xC0)
        w_box = 0xC0;

    if (h_box < 0x10)
        h_box = 0x10;

    if (h_box > 0x30)
        h_box = 0x30;

    x_count = (w_box + 0x1F) / 0x20;
    y_count = (h_box + 0x0F) / 0x10;

    for (ix = x_count - 1; ix >= 0; ix--)
    {
        for (iy = y_count; iy >= 0; iy--)
        {
            x_px = (ix + 1) * 0x20;
            if (x_px > w_box)
                x_px = w_box;
            x_px = x_px - 0x20;

            y_px = (iy + 1) * 0x10;
            if (y_px > h_box)
                y_px = h_box;
            y_px = y_px - 0x10;

            PutSprite(0, x_box + x_px, y_box + y_px, Sprite_32x16, gUnk_0203D40C.unk_30 + ix * 4 + iy * 0x40);
        }
    }

    for (ix = x_count - 1; ix >= 0; ix--)
    {
        x_px = (ix + 1) * 0x20;
        if (x_px > w_box)
            x_px = w_box;
        x_px = x_px - 0x20;

        PutSprite(0, x_box + x_px, y_box - 8, Sprite_32x8, gUnk_0203D40C.unk_30 + 0x1B);
        PutSprite(0, x_box + x_px, y_box + h_box, Sprite_32x8_VFlipped, gUnk_0203D40C.unk_30 + 0x1B);
    }

    for (iy = y_count; iy >= 0; iy--)
    {
        y_px = (iy + 1) * 0x10;
        if (y_px > h_box)
            y_px = h_box;
        y_px -= 0x10;

        PutSprite(0, x_box - 8, y_box + y_px, Sprite_8x16, gUnk_0203D40C.unk_30 + 0x1F);
        PutSprite(0, x_box + w_box, y_box + y_px, Sprite_8x16_HFlipped, gUnk_0203D40C.unk_30 + 0x1F);
    }

    PutSprite(0, x_box - 8, y_box - 8, Sprite_8x8, gUnk_0203D40C.unk_30 + 0x3E);
    PutSprite(0, x_box + w_box, y_box - 8, Sprite_8x8_HFlipped, gUnk_0203D40C.unk_30 + 0x3E);
    PutSprite(0, x_box - 8, y_box + h_box, Sprite_8x8_VFlipped, gUnk_0203D40C.unk_30 + 0x3E);
    PutSprite(0, x_box + w_box, y_box + h_box, Sprite_8x8_HFlipped_VFlipped, gUnk_0203D40C.unk_30 + 0x3E);
}

int func_fe6_08071120(int item)
{
    Text_InsertDrawString(&gUnk_0203D40C.text[0], 0x00, TEXT_COLOR_47CF, GetItemKindString(GetItemKind(item)));
    Text_InsertDrawString(&gUnk_0203D40C.text[0], 0x24, TEXT_COLOR_47CF, gUnk_08319894);
    Text_InsertDrawString(&gUnk_0203D40C.text[0], 0x60, TEXT_COLOR_47CF, gUnk_0831989C);
    Text_InsertDrawString(&gUnk_0203D40C.text[1], 0x00, TEXT_COLOR_47CF, gUnk_083198A4);
    Text_InsertDrawString(&gUnk_0203D40C.text[1], 0x30, TEXT_COLOR_47CF, gUnk_083198AC);
    Text_InsertDrawString(&gUnk_0203D40C.text[1], 0x60, TEXT_COLOR_47CF, gUnk_083198B4);

    return 2; // TODO: what?
}

void func_fe6_08071198(int item)
{
    Text_InsertDrawString(&gUnk_0203D40C.text[0], 0x0C, TEXT_COLOR_456F, GetWeaponLevelStringFromExp(GetItemRequiredExp(item)));
    Text_InsertDrawString(&gUnk_0203D40C.text[0], 0x38, TEXT_COLOR_456F, GetItemRangeString(item));
    Text_InsertDrawNumberOrBlank(&gUnk_0203D40C.text[0], 0x80, TEXT_COLOR_456F, GetItemWeight(item));
    Text_InsertDrawNumberOrBlank(&gUnk_0203D40C.text[1], 0x20, TEXT_COLOR_456F, GetItemMight(item));
    Text_InsertDrawNumberOrBlank(&gUnk_0203D40C.text[1], 0x50, TEXT_COLOR_456F, GetItemHit(item));
    Text_InsertDrawNumberOrBlank(&gUnk_0203D40C.text[1], 0x80, TEXT_COLOR_456F, GetItemCrit(item));
}

int func_fe6_08071218(int item)
{
    Text_InsertDrawString(&gUnk_0203D40C.text[0], 0x00, TEXT_COLOR_47CF, gUnk_083198BC);
    Text_InsertDrawString(&gUnk_0203D40C.text[0], 0x0C, TEXT_COLOR_456F, GetWeaponLevelStringFromExp(GetItemRequiredExp(item)));
    Text_InsertDrawString(&gUnk_0203D40C.text[0], 0x24, TEXT_COLOR_47CF, gUnk_08319894);
    Text_InsertDrawString(&gUnk_0203D40C.text[0], 0x38, TEXT_COLOR_456F, GetItemRangeString(item));

    return 1; // TODO: what?
}

struct UnkPrintProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ char const * str_it;
    /* 30 */ struct Font * font;
    /* 34 */ struct Text * text[6];
    /* 4C */ u8 pad_4C[0x5C - 0x4C];
    /* 5C */ i16 line;
    /* 5E */ i16 clock;
    /* 60 */ i16 clock_interval;
    /* 62 */ i16 chars_per_print;
};

struct UnkProc2
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x58 - 0x29];
    /* 58 */ i32 item;
    /* 5C */ i32 msg;
    /* 60 */ u8 pad_60[0x64 - 0x60];
    /* 64 */ i16 unk_64; // NOTE: might not be same proc
};

void func_fe6_08071274(struct UnkPrintProc * proc)
{
    int i;

    proc->clock--;

    if (proc->clock > 0)
        return;

    proc->clock = proc->clock_interval;

    SetTextFont(proc->font);

    for (i = 0; i < proc->chars_per_print; i++)
    {
        switch (*proc->str_it)
        {

        case 0:
            Proc_Break(proc);
            break;

        case 1:
            proc->str_it++;
            proc->line++;
            continue;

        case 4:
            proc->str_it++;
            continue;

        default:
            proc->str_it = Text_DrawCharacter(proc->text[proc->line], proc->str_it);
            continue;

        }

        break;
    }

    SetTextFont(NULL);
}

void func_fe6_08071308(struct UnkPrintProc * proc)
{
    int i;

    SetTextFont(proc->font);

    // jumping around switches and for loops requires me to use labels
    // not the nicest

    for (i = 0; i < 6; i++)
    {
        struct Text * text = proc->text[i];

        Text_SetCursor(text, GetStringTextCenteredPos(text->tile_width * 8, proc->str_it));

        for (;;)
        {
            switch (*proc->str_it)
            {

            case 0:
                goto end;

            case 4:
            case 5:
                proc->str_it++;
                continue;

            case 1:
                proc->str_it++;
                goto next_line;

            default:
                proc->str_it = Text_DrawCharacter(text, proc->str_it);
                continue;

            }
        }

    next_line:;
    }

end:
    // NOTE: is this supposed to be NULL?
    SetTextFont(proc->font);
}

/*
struct ProcScr CONST_DATA gUnk_08677FD0[] =
{
    PROC_REPEAT(func_fe6_08071274),
    PROC_END,
};
// end at 08677FE0
*/

extern struct ProcScr CONST_DATA gUnk_08677FD0[];

void func_fe6_08071374(struct UnkProc2 * proc)
{
    int item = proc->item;

    SetTextFont(&gUnk_0203D40C.font);
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);

    switch (func_fe6_08070B30(item))
    {

    case HELPBOX_INFO_NONE:
        proc->unk_64 = 0;
        break;

    case HELPBOX_INFO_WEAPON:
        func_fe6_08071120(item);
        proc->unk_64 = 2;
        break;

    case HELPBOX_INFO_STAFF:
        func_fe6_08071218(item);
        proc->unk_64 = 1;
        break;

    }

    SetTextFont(NULL);

    Proc_Break(proc);
}

void func_fe6_080713DC(struct UnkProc2 * proc)
{
    int item = proc->item;

    SetTextFont(&gUnk_0203D40C.font);

    if (func_fe6_08070B30(item) == HELPBOX_INFO_WEAPON)
    {
        func_fe6_08071198(item);
    }

    SetTextFont(NULL);

    Proc_Break(proc);
}

void func_fe6_08071410(struct UnkProc2 * proc)
{
    struct UnkPrintProc * print_proc;

    SetTextFont(&gUnk_0203D40C.font);
    SetTextFontGlyphs(TEXT_GLYPHS_TALK);
    Text_SetColor(&gUnk_0203D40C.text[0], TEXT_COLOR_4DEF);
    Text_SetColor(&gUnk_0203D40C.text[1], TEXT_COLOR_4DEF);
    Text_SetColor(&gUnk_0203D40C.text[2], TEXT_COLOR_4DEF);
    SetTextFont(NULL);

    Proc_EndEach(gUnk_08677FD0);

    print_proc = SpawnProc(gUnk_08677FD0, PROC_TREE_3);
    print_proc->font = &gUnk_0203D40C.font;
    print_proc->text[0] = &gUnk_0203D40C.text[0];
    print_proc->text[1] = &gUnk_0203D40C.text[1];
    print_proc->text[2] = &gUnk_0203D40C.text[2];
    print_proc->line = proc->unk_64;
    print_proc->str_it = DecodeMsg(proc->msg);
    print_proc->chars_per_print = 1;
    print_proc->clock = 0;

    switch (gPlaySt.config_talk_speed)
    {

    case 0:
        print_proc->clock_interval = 2;
        break;

    case 1:
        print_proc->clock_interval = 1;
        break;

    case 2:
        print_proc->clock_interval = 1;
        print_proc->chars_per_print = 2;
        break;

    case 3:
        print_proc->clock_interval = 0;
        print_proc->chars_per_print = INT8_MAX;
        break;

    }
}

extern struct ProcScr CONST_DATA gUnk_08677FF8[];
/*
struct ProcScr CONST_DATA gUnk_08677FF8[] =
{
    PROC_SLEEP(6),
    PROC_REPEAT(func_fe6_08071374),
    PROC_REPEAT(func_fe6_080713DC),
    PROC_CALL(func_fe6_08071410),
    PROC_END,
};
// end at 08678020
*/

void func_fe6_080714F8(int item, int msg)
{
    struct UnkProc2 * proc;

    proc = SpawnProc(gUnk_08677FF8, PROC_TREE_3);

    proc->item = item;
    proc->msg = msg;
}

void func_fe6_08071514(void)
{
    SetTextFont(&gUnk_0203D40C.font);

    SpriteText_DrawBackground(&gUnk_0203D40C.text[0]);
    SpriteText_DrawBackground(&gUnk_0203D40C.text[1]);
    SpriteText_DrawBackground(&gUnk_0203D40C.text[2]);

    Proc_EndEach(gUnk_08677FD0);
    Proc_EndEach(gUnk_08677FF8);

    SetTextFont(NULL);
}

void func_fe6_0807155C(struct HelpBoxProc * proc)
{
    UpdateHelpBoxDisplay(proc, INTERPOLATE_RCUBIC);

    if (proc->timer < proc->timer_end)
        proc->timer++;
}

void func_fe6_08071584(struct HelpBoxProc * proc)
{
    func_fe6_08071838(proc);
    func_fe6_08071830(proc, proc->info->x, proc->info->y);

    proc->timer_end = proc->timer_end / 3;
    proc->timer = proc->timer_end;
}

void func_fe6_080715B4(struct HelpBoxProc * proc)
{
    UpdateHelpBoxDisplay(proc, INTERPOLATE_LINEAR);

    proc->timer--;

    if (proc->timer < 0)
        Proc_Break(proc);
}
