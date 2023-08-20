#include "common.h"

#include "gbaio.h"
#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "sprite.h"
#include "spriteanim.h"
#include "gamecontroller.h"
#include "util.h"
#include "ui.h"
#include "helpbox.h"
#include "save_core.h"
#include "save_game.h"

#include "constants/songs.h"
#include "constants/msg.h"

#include "constants/videoalloc_global.h"

enum
{
    BGCHR_SAVEMENU_0 = 0,
    BGCHR_SAVEMENU_2_0 = 0, // 8000

    OBJCHR_SAVEMENU_1C0 = 0x1C0,
    OBJCHR_SAVEMENU_200 = 0x200,

    OBJPAL_SAVEMENU_9 = 9,

    OBJPAL_SAVEMENU_1 = 1,
    OBJPAL_SAVEMENU_2 = 2,
};

enum
{
    L_SAVEMENU_BEGIN = 0,
    L_SAVEMENU_1 = 1,
    L_SAVEMENU_2 = 2,
    L_SAVEMENU_3 = 3,
    L_SAVEMENU_4 = 4,
    L_SAVEMENU_5 = 5,
    L_SAVEMENU_6 = 6,
    L_SAVEMENU_7 = 7,
    L_SAVEMENU_8 = 8,
    L_SAVEMENU_9 = 9,
    L_SAVEMENU_10 = 10,
    L_SAVEMENU_11 = 11,
    L_SAVEMENU_12 = 12,
    L_SAVEMENU_13 = 13,
    L_SAVEMENU_14 = 14,
    L_SAVEMENU_15 = 15,
    L_SAVEMENU_16 = 16,
};

enum
{
    UNK_SAVEMENU_0 = 1 << 0,
    UNK_SAVEMENU_1 = 1 << 1,
    UNK_SAVEMENU_2 = 1 << 2,
    UNK_SAVEMENU_3 = 1 << 3,
    UNK_SAVEMENU_4 = 1 << 4,
    UNK_SAVEMENU_5 = 1 << 5,
    UNK_SAVEMENU_6 = 1 << 6,
    UNK_SAVEMENU_7 = 1 << 7,
};

struct UnkProc_0868A28C;

struct SaveMenuProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 anim_clock;
    /* 2A */ u8 unk_2A;
    /* 2B */ u8 selected_id;
    /* 2C */ u8 copy_from_id;
    /* 2D */ u8 unk_2D; // proc label
    /* 2E */ u8 unk_2E;
    /* 2F */ u8 unk_2F;
    /* 30 */ u8 unk_30;
    /* 31 */ u8 unk_31;
    /* 32 */ u8 unk_32;
    /* 33 */ u8 unk_33;
    /* 34 */ u8 unk_34;
    /* 35 */ u8 unk_35;
    /* 36 */ u8 unk_36;
    /* 37 */ u8 unk_37[3]; // unsure of length
    /* 3A */ u8 unk_3A[3];
    /* 3D */ u8 unk_3D;
    /* 3E */ u8 unk_3E;
    /* 3F */ u8 unk_3F;
    /* 40 */ u16 unk_40;
    /* 42 */ u16 unk_42;
    /* 44 */ u32 unk_44[3]; // time value
    /* 50 */ u32 unk_50; // time value
    /* 54 */ struct UnkProc_0868A28C * unk_54;
    /* 58 */ ProcPtr unk_58;
    /* 5C */ ProcPtr unk_5C; // sprite anim proc
};

struct SaveMenuUnkPalProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 unk_29;
};

struct UnkProc_0868A28C
{
    /* 00 */ PROC_HEADER_EXT(struct SaveMenuProc);
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ u16 unk_2A;
    /* 2C */ u16 unk_2C;
    /* 2E */ u16 unk_2E;
    /* 30 */ u16 unk_30;
    /* 30 */ u8 unk_32;
    /* 33 */ u8 unk_33;
    /* 34 */ ProcPtr unk_34;
    /* 38 */ STRUCT_PAD(0x38, 0x39);
    /* 39 */ u8 unk_39;
    /* 3A */ u8 unk_3A;
    /* 3B */ u8 unk_3B;
    /* 3C */ u8 unk_3C;
};

struct UnkProc_0868A2AC
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ u16 unk_2A;
    /* 2C */ u16 unk_2C;
    /* 2E */ STRUCT_PAD(0x2E, 0x30);
    /* 30 */ struct SaveMenuProc * sm_proc;
    /* 34 */ u8 unk_34;
    /* 35 */ u8 unk_35;
    /* 36 */ u8 unk_36;
    /* 37 */ u8 unk_37;
    /* 38 */ u8 unk_38;
    /* 39 */ u8 unk_39;
    /* 3A */ u8 unk_3A;
    /* 3B */ u8 unk_3B;
    /* 3C */ STRUCT_PAD(0x3C, 0x3D);
    /* 3D */ u8 unk_3D;
};

extern u16 const gUnk_083278AC[]; // pal x2
extern u8 const gUnk_083278EC[]; // tsa
extern u16 const gUnk_0832BDE8[]; // pal x8
extern u8 const gUnk_0832A29C[]; // lz img
extern u8 const gUnk_0832B554[]; // lz img

extern u8 const gUnk_083280B0[]; // lz img
extern u8 const gUnk_0832A130[]; // affine tm (spinny boi)

extern u16 const gUnk_0832C39C[]; // sprite anim

struct Unk_0868A518
{
    /* 00 */ u16 const * sprite;
    /* 04 */ u8 unk_04;
};

extern struct Unk_0868A518 gUnk_0868A4F8[];
extern struct Unk_0868A518 gUnk_0868A518[];

extern u16 const * gUnk_0868A550[]; // sprites
extern u16 const * gUnk_0868A55C[]; // sprites

void func_fe6_0808A918(fu8 arg_0, struct SaveMenuProc * proc);
void func_fe6_0808A42C(void);
void func_fe6_0808A524(struct SaveMenuProc * proc);
int func_fe6_0808AA54(int arg_0, struct SaveMenuProc * proc);
void func_fe6_0808A9F4(int save_id);
struct UnkProc_0868A28C * func_fe6_0808A14C(struct SaveMenuProc * parent);
struct UnkProc_0868A2AC * func_fe6_0808A210(struct SaveMenuProc * parent);
int func_fe6_0808A658(fu8 save_id, int arg_1, int arg_2);
bool func_fe6_0808A6C8(struct SaveMenuProc * proc, int arg_1);
void func_fe6_0808A4B8(struct SaveMenuProc * proc, int arg_1);
void func_fe6_0808A454(char const * string, bool arg_1);
bool func_fe6_0808A79C(struct SaveMenuProc * proc);
bool func_fe6_08088EB8(struct SaveMenuProc * proc, int direction);
void func_fe6_0808A8B4(ProcPtr parent, int arg_1, int arg_2);
void func_fe6_0808B578(fu8 arg_0, ProcPtr parent);
void func_fe6_0808BD58(ProcPtr parent);
void func_fe6_08089550(ProcPtr parent);
void func_fe6_08089564(ProcPtr parent);
void func_fe6_08089578(ProcPtr parent);

extern u16 const gUnk_0832C35C[]; // colors
extern u16 gUnk_Savemenu_02000000;
extern u16 gUnk_Savemenu_02000002[];
extern u16 gUnk_Savemenu_02000404[];

extern char const gUnk_08336C60[]; // string

#define REG_BLDY_16 (*(u16 volatile *) &REG_BLDY)

void SaveMenuOnHBlank(void)
{
    u16 vcount = REG_VCOUNT + 1;

    if (vcount > DISPLAY_HEIGHT)
        vcount = 0;

    if (vcount < 60)
    {
        REG_BLDCNT = 0xC1;
        REG_BLDY_16 = 15 - vcount / 4;
    }

    if (vcount > 100)
    {
        REG_BLDCNT = 0xA2 << 1;
        REG_BLDALPHA = 0x100A;
    }
}

void func_fe6_08087C60(struct SaveMenuProc * proc)
{
    Proc_Goto(proc, L_SAVEMENU_16);
    StartBgmVolumeChange(0x80, 0x00, 0x10, NULL);
}

// gets the mask for the num-th set bit in byte
fu8 func_fe6_08087C78(fu8 byte, int num)
{
    int i, count = 0;

    for (i = 0; i < CHAR_BIT; i++)
    {
        if (((byte >> i) & 1) != 0)
        {
            count++;

            if (num + 1 == count)
                return 1 << i;
        }
    }

    return UINT8_MAX;
}

// slow ctz
fu8 func_fe6_08087CB0(fu8 byte)
{
    int i, count = 0;

    for (i = 0; i < CHAR_BIT; i++)
    {
        if (((byte >> i) & 1) != 0)
            return i;
    }

    return UINT8_MAX;
}

void func_fe6_08087CD4(struct SaveMenuProc * proc)
{
    if ((proc->unk_3F == 0xFF) || (proc->unk_36 == 0))
    {
        CloseHelpBox();
        proc->unk_3E = 0;

        return;
    }

    switch (proc->unk_2E)
    {
        case UNK_SAVEMENU_1:
        case UNK_SAVEMENU_4:
        case UNK_SAVEMENU_5:
            if (proc->unk_3D != 0 && proc->unk_36 != 0 && proc->unk_3E == 0)
            {
                StartHelpBox_08070804(0x30, 0x30, MSG_6C3);
                proc->unk_3E = 1;
            }

            break;
    }
}

void SaveMenu_InitSong(struct SaveMenuProc * proc)
{
    if ((proc->unk_2E == UNK_SAVEMENU_7 && (GetCurrentBgmSong() == SONG_01 || GetCurrentBgmSong() == SONG_44 || GetCurrentBgmSong() == SONG_01))
        || proc->unk_2E == UNK_SAVEMENU_6)
    {
        StartBgmVolumeChange(0x100, 0x80, 0x20, NULL);
        return;
    }

    if (proc->unk_35 != 1)
    {
        StartBgmCore(SONG_01, NULL);
        StartBgmVolumeChange(0, 0x80, 60, NULL);
    }
}

void SaveMenu_InitDisplay(struct SaveMenuProc * proc)
{
    static u16 SHOULD_BE_CONST savemenu_bg_config[12] =
    {
        0x0000, 0x6000, BG_SIZE_256x256,
        0xC000, 0x6800, BG_SIZE_256x256,
        0x8000, 0x7800, BG_SIZE_256x256,
        0x8000, 0x7800, BG_SIZE_256x256,
    };

    InitBgs(savemenu_bg_config);

    gDispIo.disp_ct.mode = BG_MODE_MIXED;

    gDispIo.bg2_ct.size = BG_SIZE_512x256;
    gDispIo.bg2_ct.wrap = 0;

    SetDispEnable(0, 0, 0, 0, 0);

    gDispIo.bg0_ct.priority = 3;
    gDispIo.bg1_ct.priority = 0;
    gDispIo.bg2_ct.priority = 1;
    gDispIo.bg3_ct.priority = 1;

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, 0, 0);
    SetBgOffset(3, 0, 0);

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    TmFill(gBg2Tm, 0);
    TmFill(gBg3Tm, 0);

    SaveMenu_InitSong(proc);
}

void SaveMenu_PutScreen(struct SaveMenuProc * proc)
{
    int i;

    ResetTextFont();
    ApplySystemObjectsGraphics();
    ApplyPalettes(gUnk_083278AC, 2, 2);
    Decompress(Img_MuralBackground, ((void *) VRAM) + GetBgChrOffset(0) + CHR_SIZE * BGCHR_SAVEMENU_0);
    TmApplyTsa(gBg0Tm, gUnk_083278EC, 0);
    ApplyPalettes(gUnk_0832BDE8, 0x11, 8);
    func_fe6_08070E70(OBJ_VRAM0 + CHR_SIZE * OBJCHR_SAVEMENU_1C0, OBJPAL_SAVEMENU_9);
    func_fe6_080895A0(gUnk_0832C35C, gUnk_Savemenu_02000404, 2);
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    proc->anim_clock = 0;

    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.win1_enable_blend = 1;

    Decompress(gUnk_0832A29C, OBJ_VRAM0 + 0x1000);

    if (proc->unk_2E == UNK_SAVEMENU_6)
    {
        func_fe6_08070E70(OBJ_VRAM0 + CHR_SIZE * OBJCHR_SAVEMENU_1C0, OBJPAL_SAVEMENU_9);
    }
    else
    {
        Decompress(gUnk_0832B554, OBJ_VRAM0 + CHR_SIZE * OBJCHR_SAVEMENU_1C0);
    }

    if (proc->unk_2E == UNK_SAVEMENU_5)
    {
        if (proc->unk_35 == 1)
        {
            func_fe6_08070E70(OBJ_VRAM0 + CHR_SIZE * OBJCHR_SAVEMENU_200, 9);
        }
    }
    else
    {
        if (proc->unk_2E == UNK_SAVEMENU_6)
        {
            proc->unk_2D = L_SAVEMENU_4;
            proc->selected_id = ReadLastGameSaveId();
        }
        else
        {
            proc->unk_2D = L_SAVEMENU_1;
            proc->selected_id = 0;
        }

        proc->unk_2A = 0;
        proc->unk_34 = 0;
        proc->unk_42 = 0;
    }

    proc->unk_36 = 0;
    proc->copy_from_id = UINT8_MAX;
    proc->unk_3D = 1;

    func_fe6_0808A4F0();

    for (i = 0; i < 4; i++)
    {
        SetObjAffineAuto(i, 0, 0x100, 0x100);
    }

    proc->unk_40 = 0x100;
    proc->unk_3F = 0xFF;
    proc->unk_3E = 0;

    gUnk_Savemenu_02000000 = 0;

    SetOnHBlankA(SaveMenuOnHBlank);
}

void func_fe6_08088094(struct SaveMenuProc * proc)
{
    int i;

    SetDispEnable(1, 1, 1, 1, 1);

    Decompress(gUnk_083280B0, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_SAVEMENU_2_0);

    // SPINNY BOI LETSGO
    func_fe6_08001B8C(gBg3Tm, gUnk_0832A130, 0, 5 /* 32 bytes per line */);
    EnableBgSync(BG3_SYNC_BIT);

    for (i = 0; i < 4; i++)
    {
        func_fe6_0808A918(i, proc);
    }

    func_fe6_0808A42C();

    if (proc->unk_2E == UNK_SAVEMENU_6)
    {
        proc->unk_30 = 0x40;
        proc->unk_2E = UNK_SAVEMENU_6;
        proc->unk_31 = 0;
    }
    else
    {
        func_fe6_0808A524(proc);

        if (proc->unk_2E == UNK_SAVEMENU_5)
        {
            proc->unk_2A = func_fe6_0808AA54(0x20, proc);
        }
        else
        {
            proc->unk_2E = func_fe6_08087C78(proc->unk_30, proc->unk_2A);
        }
    }

    EnableBgSync(BG1_SYNC_BIT);
    SetWinEnable(0, 0, 0);
    SetBackdropColor(0);

    func_fe6_0808A9F4(proc->selected_id);
    proc->unk_54 = func_fe6_0808A14C(proc);
    proc->unk_58 = func_fe6_0808A210(proc);

    if (proc->unk_2D == L_SAVEMENU_1)
        proc->unk_2F = 0;

    if (proc->unk_2D == L_SAVEMENU_4)
        proc->unk_2F = 220;
}

void func_fe6_080881B8(struct SaveMenuProc * proc)
{
    Proc_Goto(proc, proc->unk_2D);
}

void func_fe6_080881C8(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_1;

    if ((gKeySt->repeated & KEY_DPAD_UP) != 0)
    {
        if (proc->unk_2A != 0)
        {
            proc->unk_2A--;
            PlaySe(SONG_66);
        }
        else if ((gKeySt->pressed & KEY_DPAD_UP) != 0)
        {
            proc->unk_2A = proc->unk_31 - 1;
            PlaySe(SONG_66);
        }
    }
    else if ((gKeySt->repeated & KEY_DPAD_DOWN) != 0)
    {
        if (proc->unk_2A < proc->unk_31 - 1)
        {
            proc->unk_2A++;
            PlaySe(SONG_66);
        }
        else if ((gKeySt->pressed & KEY_DPAD_DOWN) != 0)
        {
            proc->unk_2A = 0;
            PlaySe(SONG_66);
        }
    }

    if ((gKeySt->pressed & KEY_BUTTON_A) != 0)
    {
        proc->unk_2E = func_fe6_08087C78(proc->unk_30, proc->unk_2A);
        PlaySe(SONG_6A);

        proc->anim_clock = 0;

        switch (proc->unk_2E)
        {
            case UNK_SAVEMENU_0:
                proc->selected_id = proc->unk_3F;
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case UNK_SAVEMENU_1:
                proc->selected_id = func_fe6_0808A658(ReadLastGameSaveId(), 1, 1);
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case UNK_SAVEMENU_2:
                proc->selected_id = func_fe6_0808A658(ReadLastGameSaveId(), 1, 1);
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case UNK_SAVEMENU_3:
                proc->selected_id = func_fe6_0808A658(ReadLastGameSaveId(), 1, 1);
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case UNK_SAVEMENU_4:
                proc->selected_id = func_fe6_0808A658(proc->selected_id, 0, 1);
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case UNK_SAVEMENU_5:
                if (proc->unk_34 >= proc->unk_33)
                    proc->unk_34 = 0;

                Proc_Goto(proc, L_SAVEMENU_7);
                break;
        }
    }
    else if ((gKeySt->pressed & KEY_BUTTON_B) != 0)
    {
        PlaySe(SONG_6B);
        Proc_Goto(proc, L_SAVEMENU_16);
        proc->unk_2E = UNK_SAVEMENU_7;
    }
}

void func_fe6_08088404(struct SaveMenuProc * proc)
{
    if (proc->unk_36 == 0)
    {
        PlaySe(SONG_6A);

        switch (proc->unk_2E)
        {
            case UNK_SAVEMENU_2:
                if (proc->copy_from_id == UINT8_MAX)
                {
                    proc->copy_from_id = proc->selected_id;
                    func_fe6_0808A6C8(proc, 1);
                }
                else
                {
                    CopyGameSave(proc->copy_from_id, proc->selected_id);
                    Proc_Goto(proc, L_SAVEMENU_5);
                }

                return;

            case UNK_SAVEMENU_3:
                proc->unk_36 = 2;
                func_fe6_0808A4B8(proc, 1);
                break;

            case UNK_SAVEMENU_1:
            case UNK_SAVEMENU_4:
            case UNK_SAVEMENU_5:
            case UNK_SAVEMENU_6:
                proc->unk_36 = 2;
                func_fe6_0808A4B8(proc, 1);
                break;
        }

        func_fe6_08087CD4(proc);
    }
    else
    {
        switch (proc->unk_2E)
        {
            case UNK_SAVEMENU_5:
                if (proc->unk_36 == 1)
                {
                    proc->unk_40 = 0xF0;
                    ReadGameSave(SAVE_GAME0 + proc->selected_id);
                    Proc_Goto(proc, L_SAVEMENU_13);
                    PlaySe(SONG_6A);
                }
                else
                {
                    PlaySe(SONG_6B);
                }

                break;

            case UNK_SAVEMENU_1:
                if (proc->unk_36 == 1)
                {
                    proc->unk_40 = 0xF0;
                    PlaySe(SONG_6A);
                    func_fe6_08087C60(proc);
                }
                else
                {
                    PlaySe(SONG_6B);
                }

                break;

            case UNK_SAVEMENU_4:
                if (proc->unk_36 == 1)
                {
                    if (proc->unk_3D == 1)
                    {
                        WriteNewGameSave(proc->selected_id, FALSE);
                    }
                    else if (proc->unk_3D == 2)
                    {
                        WriteNewGameSave(proc->selected_id, TRUE);
                    }

                    Proc_Goto(proc, L_SAVEMENU_5);
                    PlaySe(SONG_60);
                }
                else
                {
                    PlaySe(SONG_6B);
                }

                break;

            case UNK_SAVEMENU_3:
                if (proc->unk_36 == 1)
                {
                    InvalidateGameSave(proc->selected_id);
                    Proc_Goto(proc, L_SAVEMENU_5);
                    PlaySe(SONG_6A);
                }
                else
                {
                    PlaySe(SONG_6B);
                }

                break;

            case UNK_SAVEMENU_6:
                if (proc->unk_36 == 1)
                {
                    WriteGameSave(proc->selected_id);
                    Proc_Goto(proc, L_SAVEMENU_5);
                    PlaySe(SONG_60);
                }
                else
                {
                    PlaySe(SONG_6B);
                }

                break;
        }

        func_fe6_0808A4B8(proc, 0);
        func_fe6_08087CD4(proc);
    }
}

void func_fe6_080885DC(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_4;

    if (proc->unk_36 == 0)
    {
        if ((gKeySt->pressed & KEY_DPAD_UP) != 0)
        {
            if (func_fe6_0808A6C8(proc, -1))
                PlaySe(SONG_66);
        }
        else if ((gKeySt->pressed & KEY_DPAD_DOWN) != 0)
        {
            if (func_fe6_0808A6C8(proc, +1))
                PlaySe(SONG_66);
        }
    }
    else if ((gKeySt->pressed & KEY_DPAD_LEFT) != 0)
    {
        if (proc->unk_36 != 1)
        {
            proc->unk_36 = 1;
            PlaySe(SONG_67);
            func_fe6_08087CD4(proc);
        }
    }
    else if ((gKeySt->pressed & KEY_DPAD_RIGHT) != 0)
    {
        if (proc->unk_36 != 2)
        {
            proc->unk_36 = 2;
            PlaySe(SONG_67);
            func_fe6_08087CD4(proc);
        }
    }

    if ((gKeySt->pressed & KEY_BUTTON_A) != 0)
    {
        proc->anim_clock = 0;

        switch (proc->unk_2E)
        {
            case UNK_SAVEMENU_1:
                if (proc->unk_3F == 0xFF)
                {
                    PlaySe(SONG_6A);
                    func_fe6_08087C60(proc);
                }
                else
                {
                    func_fe6_08088404(proc);
                }

                break;

            case UNK_SAVEMENU_0:
                PlaySe(SONG_6A);
                func_fe6_08087C60(proc);
                break;

            case UNK_SAVEMENU_2:
            case UNK_SAVEMENU_3:
            case UNK_SAVEMENU_6:
                func_fe6_08088404(proc);
                break;

            case UNK_SAVEMENU_4:
                if (proc->unk_3D == 0)
                {
                    if (proc->unk_36 == 1)
                        proc->unk_3D = 1;
                    else
                        proc->unk_3D = 2;

                    func_fe6_0808A4B8(proc, 0);

                    if (proc->unk_3F != 0xFF)
                    {
                        Proc_Goto(proc, L_SAVEMENU_6);
                        break;
                    }
                }
                else if (IsNotFirstPlaythrough() && proc->unk_36 == 0)
                {
                    proc->unk_3D = 0;
                    proc->unk_36 = 1;
                    // NOTE: this "\0\0\0" is a hack to align the next item in rodata.
                    // this file was probably split in two
                    func_fe6_0808A454(JTEXT("ノーマル　ハード" "\0\0\0"), TRUE);
                    PlaySe(SONG_6A);
                }

                if (proc->unk_3D != 0)
                {
                    if (proc->unk_3F != 0xFF)
                    {
                        func_fe6_08088404(proc);
                    }
                    else
                    {
                        if (proc->unk_3D == 1)
                        {
                            WriteNewGameSave(proc->selected_id, 0);
                        }
                        else if (proc->unk_3D == 2)
                        {
                            WriteNewGameSave(proc->selected_id, 1);
                        }

                        Proc_Goto(proc, L_SAVEMENU_5);
                        PlaySe(SONG_60);
                    }
                }

                break;
        }
    }
    else if ((gKeySt->pressed & KEY_BUTTON_B) != 0)
    {
        proc->anim_clock = 0;
        PlaySe(SONG_6B);

        if (proc->unk_36 != 0)
        {
            proc->unk_3D = 1;
            func_fe6_0808A4B8(proc, 0);
            func_fe6_08087CD4(proc);
        }
        else if (proc->copy_from_id != UINT8_MAX)
        {
            proc->selected_id = proc->copy_from_id;
            proc->copy_from_id = UINT8_MAX;
        }
        else if (proc->unk_2E == UNK_SAVEMENU_6)
        {
            Proc_Goto(proc, L_SAVEMENU_15);
        }
        else
        {
            Proc_Goto(proc, L_SAVEMENU_3);
        }
    }
}

void func_fe6_08088854(struct SaveMenuProc * proc)
{
    func_fe6_08088404(proc);
}

void func_fe6_08088860(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_5;
    proc->anim_clock = 0;
}

void func_fe6_08088870(struct SaveMenuProc * proc)
{
    if (proc->anim_clock == 8)
    {
        func_fe6_0808A918(proc->selected_id, proc);
        func_fe6_0808A918(4, proc);

        if (proc->unk_37[proc->selected_id] != 0xFF)
        {
            // tyvm Eebit
            // TODO: there's probably something better to do here
            func_fe6_08070D08(((u32)(proc->selected_id * 0x800 + 0x16800) & 0x0001FFFF) >> 5, proc->unk_37[proc->selected_id]);
        }
        else
        {
            func_fe6_08070D08(((u32)(proc->selected_id * 0x800 + 0x16800) & 0x0001FFFF) >> 5, -1);
        }

        func_fe6_0808A9F4(proc->selected_id);
    }
    else if (proc->anim_clock == 0x20)
    {
        func_fe6_0808A524(proc);

        if (proc->unk_2E == UNK_SAVEMENU_4)
        {
            Proc_Goto(proc, L_SAVEMENU_16);
            StartBgmVolumeChange(0x80, 0, 0x10, 0);
        }
        else if (proc->unk_2E == UNK_SAVEMENU_6)
        {
            Proc_Goto(proc, L_SAVEMENU_15);
        }
        else
        {
            if (func_fe6_0808A79C(proc))
            {
                if (proc->copy_from_id != UINT8_MAX)
                {
                    proc->selected_id = proc->copy_from_id;
                    proc->copy_from_id = UINT8_MAX;
                }
                else
                {
                    proc->selected_id = func_fe6_0808A658(proc->selected_id, 1, 1);
                }

                Proc_Goto(proc, L_SAVEMENU_4);
            }
        }
    }
    else if (proc->anim_clock == 0x30)
    {
        proc->selected_id = 0;
        proc->copy_from_id = UINT8_MAX;
        proc->anim_clock = 0;
        proc->unk_2A = 0;
        proc->unk_2E = func_fe6_08087C78(proc->unk_30, 0);

        PlaySe(SONG_6B);

        Proc_Goto(proc, L_SAVEMENU_3);
        return;
    }

    if (proc->anim_clock == 0x10)
    {
        SetObjAffineAuto(proc->selected_id, 0, 0x100, 0x100);
    }
    else if (proc->anim_clock < 8)
    {
        SetObjAffineAuto(proc->selected_id, 0, 0x100, (proc->anim_clock * -0x20) + 0x100);
    }
    else if (proc->anim_clock < 0x10)
    {
        SetObjAffineAuto(proc->selected_id, 0, 0x100, (proc->anim_clock * 0x20) - 0xE0);
    }

    proc->anim_clock++;
}

void func_fe6_08088B40(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_2;
    proc->anim_clock++;

    // TODO: what
    proc->unk_2F = (((7 * proc->anim_clock * 8 - proc->anim_clock) * 8) - (220 * proc->anim_clock * proc->anim_clock / 14)) / 14;

    if (proc->anim_clock == 14)
    {
        func_fe6_08070E70(OBJ_VRAM0 + OBJCHR_SAVEMENU_1C0 * CHR_SIZE, OBJPAL_SAVEMENU_9);
        Proc_Break(proc);
    }
}

void func_fe6_08088B9C(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_3;
    proc->anim_clock++;

    // TODO: what
    proc->unk_2F = -36 - (((7 * proc->anim_clock * 8 - proc->anim_clock) * 8) - (220 * proc->anim_clock * proc->anim_clock / 14)) / 14;

    if (proc->anim_clock == 14)
    {
        Decompress(gUnk_0832B554, OBJ_VRAM0 + OBJCHR_SAVEMENU_1C0 * CHR_SIZE);
        Proc_Break(proc);
    }
}

void func_fe6_08088C04(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_7;
    proc->anim_clock++;

    // TODO: what
    proc->unk_42 = (((7 * proc->anim_clock * 8 - proc->anim_clock) * 8) - (220 * proc->anim_clock * proc->anim_clock / 14)) / 14;

    if (proc->anim_clock == 14)
    {
        Proc_Goto(proc, L_SAVEMENU_9);
    }
}

void func_fe6_08088C58(struct SaveMenuProc * proc)
{
    proc->unk_2D = 7;
    proc->anim_clock++;

    // TODO: what
    proc->unk_42 = 220 - (((7 * proc->anim_clock * 8 - proc->anim_clock) * 8) - (220 * proc->anim_clock * proc->anim_clock / 14)) / 14;

    if (proc->anim_clock == 14)
    {
        Proc_Goto(proc, L_SAVEMENU_1);
    }
}

void func_fe6_08088CB0(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_11;
    proc->anim_clock++;

    // TODO: what
    proc->unk_42 = 220 + (((7 * proc->anim_clock * 8 - proc->anim_clock) * 8) - (220 * proc->anim_clock * proc->anim_clock / 14)) / 14;
    proc->unk_2F = proc->unk_42 + 36;

    if (proc->anim_clock == 14)
    {
        Proc_Goto(proc, L_SAVEMENU_10);
    }
}

void func_fe6_08088D0C(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_12;
    proc->anim_clock++;

    // TODO: what
    proc->unk_42 = 440 - (((7 * proc->anim_clock * 8 - proc->anim_clock) * 8) - (220 * proc->anim_clock * proc->anim_clock / 14)) / 14;
    proc->unk_2F = proc->unk_42 + 36;

    if (proc->anim_clock == 14)
    {
        Proc_Goto(proc, L_SAVEMENU_9);
    }
}

void func_fe6_08088D6C(struct SaveMenuProc * proc)
{
    int previous = proc->unk_34;

    proc->unk_2D = L_SAVEMENU_9;

    if ((gKeySt->repeated & KEY_DPAD_UP) != 0)
    {
        if (proc->unk_34 != 0)
        {
            proc->unk_34--;
        }
        else 
        {
            if ((gKeySt->pressed & KEY_DPAD_UP) != 0)
            {
                proc->unk_34 = proc->unk_33 - 1;
            }
        }
    }
    else if ((gKeySt->repeated & KEY_DPAD_DOWN) != 0)
    {
        if (proc->unk_34 < proc->unk_33 - 1)
        {
            proc->unk_34++;
        }
        else 
        {
            if ((gKeySt->pressed & KEY_DPAD_DOWN) != 0)
            {
                proc->unk_34 = 0;
            }
        }
    }

    if (previous != proc->unk_34)
    {
        PlaySe(SONG_66);
    }

    if ((gKeySt->pressed & KEY_BUTTON_A) != 0)
    {
        proc->unk_35 = func_fe6_08087C78(proc->unk_32, proc->unk_34);
        PlaySe(SONG_6A);

        proc->anim_clock = 0;

        switch (proc->unk_35)
        {
            default:
                func_fe6_08087C60(proc);
                Proc_Goto(proc, L_SAVEMENU_16);
                break;

            case 1:
                proc->selected_id = func_fe6_0808A658(ReadLastGameSaveId(), 1, 1);
                func_fe6_08088EB8(proc, 0);
                Proc_Goto(proc, L_SAVEMENU_11);
                break;

            case 8:
                Proc_Goto(proc, L_SAVEMENU_13);
                break;
        }
    }
    else if ((gKeySt->pressed & KEY_BUTTON_B) != 0)
    {
        proc->anim_clock = 0;
        Proc_Goto(proc, L_SAVEMENU_8);
        PlaySe(SONG_6B);
    }
}

bool func_fe6_08088EB8(struct SaveMenuProc * proc, int direction)
{
    int i;

    fu8 previous = proc->selected_id;

    if (direction == 0)
    {
        if ((proc->unk_3A[proc->selected_id] & 1) != 0)
            return TRUE;

        direction = 1;
    }

    if (direction > 0)
    {
        for (i = 0; i < 3; i++)
        {
            if (proc->selected_id < 2)
                proc->selected_id++;
            else
                proc->selected_id = 0;

            if ((proc->unk_3A[proc->selected_id] & 1) != 0)
                break;
        }
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            if (proc->selected_id == 0)
                proc->selected_id = 2;
            else
                proc->selected_id = proc->selected_id - 1;

            if ((proc->unk_3A[proc->selected_id] & 1) != 0)
                break;
        }
    }

    if (previous != proc->selected_id)
    {
        PlaySe(SONG_66);
        return TRUE;
    }

    return FALSE;
}

void func_fe6_08088F60(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_4;

    if (proc->unk_36 == 0)
    {
        if ((gKeySt->pressed & KEY_DPAD_UP) != 0)
        {
            func_fe6_08088EB8(proc, -1);
        }
        else if ((gKeySt->pressed & KEY_DPAD_DOWN) != 0)
        {
            func_fe6_08088EB8(proc, +1);
        }
    }
    else
    {
        if ((gKeySt->pressed & KEY_DPAD_LEFT) != 0)
        {
            if (proc->unk_36 != 1)
            {
                proc->unk_36 = 1;
                PlaySe(SONG_67);
            }
        }
        else if ((gKeySt->pressed & KEY_DPAD_RIGHT) != 0)
        {
            if (proc->unk_36 != 2)
            {
                proc->unk_36 = 2;
                PlaySe(SONG_67);
            }
        }
    }

    if ((gKeySt->pressed & KEY_BUTTON_A) != 0)
    {
        if (proc->unk_3F == 0xFF)
        {
            ReadGameSave(SAVE_GAME0 + proc->selected_id);
            Proc_Goto(proc, L_SAVEMENU_13);
            PlaySe(SONG_6A);
        }
        else
        {
            if (proc->unk_3E == 0)
            {
                func_fe6_08070E70(OBJ_VRAM0 + CHR_SIZE * 0x200, OBJPAL_SAVEMENU_9);
            }

            func_fe6_08088404(proc);
        }
    }
    else if ((gKeySt->pressed & KEY_BUTTON_B) != 0)
    {
        PlaySe(SONG_6B);

        if (proc->unk_36 != 0)
        {
            func_fe6_0808A4B8(proc, 0);
            func_fe6_08087CD4(proc);
        }
        else
        {
            Decompress(gUnk_0832B554, OBJ_VRAM0 + OBJCHR_SAVEMENU_1C0 * CHR_SIZE);
            proc->anim_clock = 0;
            Proc_Goto(proc, L_SAVEMENU_12);
        }
    }
}

void func_fe6_080890B8(struct SaveMenuProc * proc)
{
    func_fe6_0808A8B4(proc, 1, 2);
    Proc_Break(proc);
}

void SaveMenu_Finish(struct SaveMenuProc * proc)
{
    if (proc->unk_5C != NULL)
        EndSpriteAnimProc(proc->unk_5C);

    Proc_End(proc->unk_54);
    Proc_End(proc->unk_58);

    SetOnHBlankA(NULL);

    if (proc->unk_2E == UNK_SAVEMENU_5)
    {
        switch (proc->unk_35)
        {
            case 2:
                SetNextGameAction(GAME_ACTION_5);
                break;

            case 4:
                SetNextGameAction(GAME_ACTION_8);
                break;

            case 8:
                SetNextGameAction(GAME_ACTION_7);
                break;
        }
    }
    else if (proc->unk_2E != UNK_SAVEMENU_6)
    {
        if (proc->unk_2E == UNK_SAVEMENU_0)
        {
            ReadSuspendSave(SAVE_SUSPEND);
            SetNextGameAction(GAME_ACTION_3);
        }
        else if (proc->unk_2E == UNK_SAVEMENU_1)
        {
            ReadGameSave(SAVE_GAME0 + proc->selected_id);
            SetNextGameAction(GAME_ACTION_0 + proc->selected_id);
        }
        else if (proc->unk_2E == UNK_SAVEMENU_4)
        {
            SetNextGameAction(GAME_ACTION_0);
        }
        else if (proc->unk_2E == UNK_SAVEMENU_7)
        {
            StartBgmVolumeChange(0x80, 0x100, 0x10, NULL);
            SetNextGameAction(GAME_ACTION_4);
        }
    }
}

void func_fe6_08089180(struct SaveMenuProc * proc)
{
    proc->unk_2E = UNK_SAVEMENU_5;

    Proc_End(proc->unk_54);
    Proc_End(proc->unk_58);

    SetOnHBlankA(NULL);

    if (proc->unk_5C != NULL)
        EndSpriteAnimProc(proc->unk_5C);

    switch (proc->unk_35)
    {
        case 1:
            func_fe6_0808B578(0, proc);
            break;

        case 8:
            StartBgmVolumeChange(0x80, 0, 0x20, NULL);
            func_fe6_0808BD58(proc);
            break;
    }
}

void func_fe6_080891DC(struct SaveMenuProc * proc)
{
    switch (proc->unk_35)
    {
        case 1:
            Proc_Goto(proc, L_SAVEMENU_10);
            break;

        case 8:
            Proc_Goto(proc, L_SAVEMENU_9);
            break;
    }
}

struct ProcScr CONST_DATA ProcScr_SaveMenu[] =
{
    PROC_19,

PROC_LABEL(L_SAVEMENU_BEGIN),
    PROC_SLEEP(0),

    PROC_CALL(SaveMenu_InitDisplay),
    PROC_SLEEP(0),

    PROC_CALL(SaveMenu_PutScreen),
    PROC_CALL(func_fe6_08088094),
    PROC_CALL(func_fe6_08089550),
    PROC_SLEEP(0),

    PROC_CALL(func_fe6_080881B8),

PROC_LABEL(L_SAVEMENU_1),
    PROC_REPEAT(func_fe6_080881C8),
    PROC_GOTO(L_SAVEMENU_14),

PROC_LABEL(L_SAVEMENU_4),
    PROC_REPEAT(func_fe6_080885DC),
    PROC_GOTO(L_SAVEMENU_14),

PROC_LABEL(L_SAVEMENU_6),
    PROC_SLEEP(5),

    PROC_CALL(func_fe6_08088854),
    PROC_GOTO(L_SAVEMENU_4),

PROC_LABEL(L_SAVEMENU_5),
    PROC_SLEEP(1),

    PROC_CALL(func_fe6_08088860),
    PROC_SLEEP(1),

    PROC_REPEAT(func_fe6_08088870),
    PROC_GOTO(L_SAVEMENU_4),

PROC_LABEL(L_SAVEMENU_2),
    PROC_REPEAT(func_fe6_08088B40),
    PROC_GOTO(L_SAVEMENU_4),

PROC_LABEL(L_SAVEMENU_3),
    PROC_REPEAT(func_fe6_08088B9C),
    PROC_GOTO(L_SAVEMENU_1),

PROC_LABEL(L_SAVEMENU_7),
    PROC_REPEAT(func_fe6_08088C04),

PROC_LABEL(L_SAVEMENU_8),
    PROC_REPEAT(func_fe6_08088C58),

PROC_LABEL(L_SAVEMENU_11),
    PROC_REPEAT(func_fe6_08088CB0),

PROC_LABEL(L_SAVEMENU_12),
    PROC_REPEAT(func_fe6_08088D0C),

PROC_LABEL(L_SAVEMENU_9),
    PROC_REPEAT(func_fe6_08088D6C),

PROC_LABEL(L_SAVEMENU_10),
    PROC_REPEAT(func_fe6_08088F60),

PROC_LABEL(L_SAVEMENU_13),
    PROC_CALL(func_fe6_08089564),
    PROC_SLEEP(0),

    PROC_CALL(func_fe6_08089180),
    PROC_SLEEP(0),

    PROC_CALL(SaveMenu_InitDisplay),
    PROC_SLEEP(0),

    PROC_CALL(SaveMenu_PutScreen),
    PROC_CALL(func_fe6_08088094),
    PROC_CALL(func_fe6_08089550),
    PROC_CALL(func_fe6_080891DC),

PROC_LABEL(L_SAVEMENU_16),
    PROC_CALL(func_fe6_08089578),
    PROC_GOTO(L_SAVEMENU_14),

PROC_LABEL(L_SAVEMENU_15),
    PROC_CALL(func_fe6_08089564),

PROC_LABEL(L_SAVEMENU_14),
    PROC_SLEEP(0),

    PROC_CALL(SaveMenu_Finish),
    PROC_END,
};

void func_fe6_08089200(ProcPtr parent)
{
    struct SaveMenuProc * proc;

    proc = SpawnProcLocking(ProcScr_SaveMenu, parent);

    proc->unk_2E = UNK_SAVEMENU_7;
    proc->unk_35 = 0;

    gPlaySt.config_talk_speed = 2;
}

void func_fe6_08089234(ProcPtr parent)
{
    struct SaveMenuProc * proc;

    proc = SpawnProcLocking(ProcScr_SaveMenu, parent);

    proc->unk_2E = UNK_SAVEMENU_6;
    proc->unk_35 = 0;
}

void func_fe6_08089254(struct SaveMenuUnkPalProc * proc)
{
    int i;

    proc->unk_29 = 0;

    for (i = 0; i < (int)ARRAY_COUNT(gPal); i++)
    {
        gUnk_Savemenu_02000002[i] = gPal[i];
    }
}

void func_fe6_0808927C(struct SaveMenuUnkPalProc * proc)
{
    #define SCALE 0x10

    int i;
    fu8 coef = proc->unk_29;

    for (i = 0; i < (int)ARRAY_COUNT(gPal); i++)
    {
        int b_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();

    proc->unk_29++;

    if (coef == SCALE)
    {
        Proc_Break(proc);
    }

    #undef SCALE
}

void func_fe6_08089310(struct SaveMenuUnkPalProc * proc)
{
    #define SCALE 0x10

    int i;
    fu8 coef = SCALE - proc->unk_29;

    for (i = 0; i < (int)ARRAY_COUNT(gPal); i++)
    {
        int b_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();

    proc->unk_29++;

    if (coef == 0)
    {
        SetDispEnable(0, 0, 0, 0, 0);
        Proc_Break(proc);
    }

    #undef SCALE
}

void func_fe6_080893D0(struct SaveMenuUnkPalProc * proc)
{
    #define SCALE 0x20

    int i;
    fu8 coef = SCALE - proc->unk_29;

    for (i = 0; i < (int)ARRAY_COUNT(gPal); i++)
    {
        int b_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();

    proc->unk_29++;

    if (coef == 0)
    {
        SetDispEnable(0, 0, 0, 0, 0);
        Proc_Break(proc);
    }

    #undef SCALE
}

void func_fe6_08089490(struct SaveMenuUnkPalProc * proc)
{
    #define SCALE 0x40

    int i;
    fu8 coef = SCALE - proc->unk_29;

    for (i = 0; i < (int)ARRAY_COUNT(gPal); i++)
    {
        int b_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();

    proc->unk_29++;

    if (coef == 0)
    {
        SetDispEnable(0, 0, 0, 0, 0);
        Proc_Break(proc);
    }

    #undef SCALE
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A09C[] =
{
    PROC_CALL(func_fe6_08089254),
    PROC_REPEAT(func_fe6_0808927C),
    PROC_END,
};

void func_fe6_08089550(ProcPtr parent)
{
    SpawnProcLocking(ProcScr_Unk_0868A09C, parent);
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A0B4[] =
{
    PROC_CALL(func_fe6_08089254),
    PROC_REPEAT(func_fe6_08089310),
    PROC_END,
};

void func_fe6_08089564(ProcPtr parent)
{
    SpawnProcLocking(ProcScr_Unk_0868A0B4, parent);
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A0CC[] =
{
    PROC_CALL(func_fe6_08089254),
    PROC_REPEAT(func_fe6_080893D0),
    PROC_END,
};

void func_fe6_08089578(ProcPtr parent)
{
    SpawnProcLocking(ProcScr_Unk_0868A0CC, parent);
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A0E4[] =
{
    PROC_CALL(func_fe6_08089254),
    PROC_REPEAT(func_fe6_08089490),
    PROC_END,
};

void func_fe6_0808958C(ProcPtr parent)
{
    SpawnProcLocking(ProcScr_Unk_0868A0E4, parent);
}

void func_fe6_080895A0(u16 const * src, u16 * dst, int count)
{
    int i;

    for (i = 0; i < count * 0x10; i++)
        dst[i] = src[i];
}

void func_fe6_080895B8(u32 point)
{
    int i;

    point = point % 0x40;

    if ((point & 0x20) != 0)
        point = 0x20 - (point % 0x20);

    for (i = 1; i < 0x10; i++)
    {
        if (i < 8 || i > 10)
        {
            int r, g, b;
            u16 r_out, g_out, b_out;

            u16 source = gPal[OBPAL_OFFSET(OBJPAL_SAVEMENU_2) + i];
            int blend = gUnk_Savemenu_02000404[0x10 + i];

            b = (RGB5_MASK_B & source) * (0x20 - point);
            b += (RGB5_MASK_B & blend) * (point);
            b_out = RGB5_MASK_B & (b >> 5);

            g = (RGB5_MASK_G & source) * (0x20 - point);
            g += (RGB5_MASK_G & blend) * (point);
            g_out = RGB5_MASK_G & (g >> 5);

            r = (RGB5_MASK_R & source) * (0x20 - point);
            r += (RGB5_MASK_R & blend) * (point);
            r_out = RGB5_MASK_R & (r >> 5);

            gPal[OBPAL_OFFSET(OBJPAL_SAVEMENU_1) + i] = b_out | g_out | r_out;
        }
    }

    EnablePalSync();
}

u16 CONST_DATA Sprite_0868A0FC[] =
{
    4,
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x80) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x81) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(64), OAM2_CHR(0x81) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(96), OAM2_CHR(0x82) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A116[] =
{
    3,
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x80) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x81) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(64), OAM2_CHR(0x82) + OAM2_LAYER(1),
};

// unused?
u16 CONST_DATA Sprite_0868A12A[] =
{
    6,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x80) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x82) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16 + OAM0_Y(16), OAM1_SIZE_32x16, OAM2_CHR(0xA0) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16 + OAM0_Y(16), OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0xA2) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16, OAM2_CHR(0xC0) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0xC2) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A150[] =
{
    1,
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x11C),
};

u16 CONST_DATA Sprite_0868A158[] =
{
    1,
    OAM0_SHAPE_32x32 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x32 + OAM1_AFFINE_ID(3), OAM2_CHR(0x158) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A160[] =
{
    3,
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x100) + OAM2_LAYER(1),
    OAM0_SHAPE_16x32, OAM1_SIZE_16x32 + OAM1_X(32), OAM2_CHR(0x101) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(48), OAM2_CHR(0x102) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A174[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x9E) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A17C[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x9F) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A184[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xBE) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A18C[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xBF) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A194[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xDE) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A19C[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xDF) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1A4[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xFE) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1AC[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xFF) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1B4[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x188) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1BC[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x189) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1C4[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x18A) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1CC[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x146) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1D4[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x147) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1DC[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x148) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1E4[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x149) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1EC[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14A) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1F4[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14B) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1FC[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14C) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A204[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14D) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A20C[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14E) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A214[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14F) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A21C[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x150) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A224[] =
{
    2,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8, OAM2_CHR(0x180) + OAM2_LAYER(1),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(32), OAM2_CHR(0x184) + OAM2_LAYER(1),
};

u16 const * CONST_DATA gUnk_0868A234[] =
{
    Sprite_0868A174,
    Sprite_0868A17C,
    Sprite_0868A184,
    Sprite_0868A18C,
    Sprite_0868A194,
    Sprite_0868A19C,
    Sprite_0868A1A4,
    Sprite_0868A1AC,
    Sprite_0868A1B4,
    Sprite_0868A1BC,
    Sprite_0868A1C4,
};

u16 const * CONST_DATA gUnk_0868A260[] =
{
    Sprite_0868A1CC,
    Sprite_0868A1D4,
    Sprite_0868A1DC,
    Sprite_0868A1E4,
    Sprite_0868A1EC,
    Sprite_0868A1F4,
    Sprite_0868A1FC,
    Sprite_0868A204,
    Sprite_0868A20C,
    Sprite_0868A214,
    Sprite_0868A21C,
};

void func_fe6_08089684(ProcPtr proc)
{
    struct SaveMenuProc * sm_proc = ((struct GenericProc *) proc)->proc_parent;

    fu8 y, x;
    u16 hours, minutes, seconds;

    y = (0x20 - (sm_proc->unk_2F * 0x20 / 220));
    y = y + 144;
    x = 144;

    if (sm_proc->unk_2E == 1)
    {
        FormatTime(sm_proc->unk_50, &hours, &minutes, &seconds);
    }
    else
    {
        FormatTime(sm_proc->unk_44[sm_proc->selected_id], &hours, &minutes, &seconds);
    }

    PutSpriteExt(13, x + 0x10, y - 14, Sprite_0868A160, OAM2_PAL(2));
    PutSpriteExt(13, x + 0x14, y - 14, Sprite_0868A224, OAM2_PAL(5));

    if (hours >= 100)
    {
        PutSpriteExt(13, x + 0x12, y - 8, gUnk_0868A260[hours / 100], OAM2_PAL(5));
        hours = hours - (hours / 100 * 100); // sure, 'hours % 100' would have been fine too
    }

    if (hours >= 10)
    {
        PutSpriteExt(13, x + 0x1A, y - 8, gUnk_0868A260[hours / 10], OAM2_PAL(5));
    }

    PutSpriteExt(13, x + 0x22, y - 8, gUnk_0868A260[hours % 10], OAM2_PAL(5));

    PutSpriteExt(13, x + 0x2A, y - 7, gUnk_0868A260[10], OAM2_PAL(5));

    PutSpriteExt(13, x + 0x32, y - 8, gUnk_0868A260[minutes / 10], OAM2_PAL(5));
    PutSpriteExt(13, x + 0x3A, y - 8, gUnk_0868A260[minutes % 10], OAM2_PAL(5));

    PutSpriteExt(13, x + 0x42, y + 1, gUnk_0868A234[10], OAM2_PAL(5));

    PutSpriteExt(13, x + 0x4A, y, gUnk_0868A234[seconds / 10], OAM2_PAL(5));
    PutSpriteExt(13, x + 0x52, y, gUnk_0868A234[seconds % 10], OAM2_PAL(5));
}

void func_fe6_08089894(fu8 bg, i32 scr_x, i32 scr_y, i32 tex_x, i32 tex_y, fi16 angle, fi16 scale)
{
    struct BgAffineSetSrc affine_src;

    affine_src.tex_x = tex_x;
    affine_src.tex_y = tex_y;
    affine_src.scr_x = scr_x >> 8;
    affine_src.scr_y = scr_y >> 8;
    affine_src.sx = 0x10000 / scale;
    affine_src.sy = 0x10000 / scale;
    affine_src.alpha = angle << 6;

    // TODO: put proper affine structs inside gDispIo instead of using bg[23]pa directly
    BgAffineSet(&affine_src, (bg == 2) ? (void *)&gDispIo.bg2pa : (void *)&gDispIo.bg3pa, 1);
}

void func_fe6_080898F0(struct UnkProc_0868A28C * proc)
{
    fu8 i;

    proc->unk_2C = 0;
    proc->unk_2E = 0x100;

    proc->unk_3A = 0;
    proc->unk_3B = 40;

    func_fe6_08070D48(0xAC << 4);

    for (i = 0; i < 3; i++)
    {
        // TODO: make sense of these constants

        if (proc->proc_parent->unk_37[i] != 0xFF)
        {
            func_fe6_08070D08(((u32) (0x16800 + 0x800 * i) & 0x1FFFF) >> 5,
                proc->proc_parent->unk_37[i]);
        }
        else
        {
            func_fe6_08070D08(((u32) (0x16800 + 0x800 * i) & 0x1FFFF) >> 5, -1);
        }
    }

    proc->unk_30 = 0;
    proc->unk_32 = 0;

    SetObjAffine(0, 0x100, 0, 0, 0x100);
    SetObjAffine(1, 0x100, 0, 0, 0x100);
    SetObjAffine(2, 0x100, 0, 0, 0x100);

    proc->unk_2A = 0;

    proc->unk_34 = func_fe6_0808A418(proc);
    proc->unk_39 = 0;

    if (proc->proc_parent->unk_3F == 0xFF)
    {
        proc->proc_parent->unk_5C = NULL;
    }
    else
    {
        proc->proc_parent->unk_5C = StartSpriteAnimProc(
            gUnk_0832C39C, 320, 0x30 + proc->proc_parent->unk_3F * 0x20, 0x1A0, 0, 4);
    }

    proc->unk_3C = proc->proc_parent->selected_id;
}

void func_fe6_080899F0(bool arg_0, fu16 arg_1)
{
    if (arg_0)
    {
        gPal[OBPAL_OFFSET(6) + 8] = gPal[OBPAL_OFFSET(9) + (arg_1 / 4) % 0x10];
    }
    else
    {
        gPal[OBPAL_OFFSET(6) + 8] = gPal[OBPAL_OFFSET(9) + 13];
    }

    EnablePalSync();
}

void func_fe6_08089A3C(ProcPtr proc, int x, int y, fu8 arg_3, fu8 pal_a, fu8 pal_b)
{
    PutSpriteExt(4, OAM1_X(x), y, Sprite_0868A0FC, OAM2_PAL(pal_a));

    PutSpriteExt(4, OAM1_X(x + 8 + gUnk_0868A518[arg_3].unk_04), y + 8,
        gUnk_0868A518[arg_3].sprite, OAM2_PAL(pal_b));
}

void func_fe6_08089ABC(ProcPtr proc, int x, int y, fu8 arg_3, fu8 pal_a, fu8 pal_b)
{
    PutSpriteExt(4, OAM1_X(x), y, Sprite_0868A0FC, OAM2_PAL(pal_a));

    PutSpriteExt(4, OAM1_X(x + 8 + gUnk_0868A4F8[arg_3].unk_04), y + 8,
        gUnk_0868A4F8[arg_3].sprite, OAM2_PAL(pal_b));
}

void func_fe6_08089B3C(struct UnkProc_0868A28C * proc)
{
    if (proc->unk_3C != proc->proc_parent->selected_id)
    {
        func_fe6_0808A9F4(proc->proc_parent->selected_id);
        proc->unk_3C = proc->proc_parent->selected_id;
    }

    gPal[OBPAL_OFFSET(1) + 10] = gUnk_Savemenu_02000404[(proc->unk_2A / 4) % 0x10];
    EnablePalSync();

    if (proc->proc_parent->unk_3F != 0xFF && proc->proc_parent->unk_40 != 0x100)
    {
        if (proc->proc_parent->unk_40 < 0x10)
        {
            proc->proc_parent->unk_3F = 0xFF;
        }
        else
        {
            // angle = scale???
            SetObjAffineAuto(3, proc->proc_parent->unk_40, proc->proc_parent->unk_40, proc->proc_parent->unk_40);
        }

        proc->proc_parent->unk_40 -= 0x10;
    }

    func_fe6_080895B8(proc->unk_2A);
    proc->unk_2A++;
}

void func_fe6_08089C70(struct UnkProc_0868A28C * proc)
{
    fu8 id;
    fu16 y;

    y = (0x100 + (0xD0 + proc->proc_parent->unk_2F * 48 / 220)) & 0x1FF;

    PutSpriteExt(4, 0x38, y, Sprite_0868A0FC, OAM2_PAL(2));

    if (proc->proc_parent->unk_42 != 0)
    {
        id = func_fe6_08087CB0(proc->proc_parent->unk_35);

        PutSpriteExt(4, 0x40 + gUnk_0868A518[id].unk_04, (y + 8) & 0x1FF,
            gUnk_0868A4F8[id].sprite, OAM2_PAL(3));
    }
    else
    {
        id = func_fe6_08087CB0(proc->proc_parent->unk_2E);

        PutSpriteExt(4, 0x40 + gUnk_0868A518[id].unk_04, (y + 8) & 0x1FF,
            gUnk_0868A518[id].sprite, OAM2_PAL(3));
    }
}

void func_fe6_08089D30(struct UnkProc_0868A28C * proc)
{
    // TODO: clean up

    fu8 i;
    fu8 id;
    int r5;
    fu8 r4;

    if (proc->proc_parent->unk_2E < 0x80)
    {
        if (proc->proc_parent->unk_2E == 0x20)
        {
            proc->unk_33 = proc->proc_parent->unk_35;
        }
        else
        {
            proc->unk_33 = proc->proc_parent->unk_2E;
        }
    }

    r5 = proc->proc_parent->unk_2F + proc->proc_parent->unk_42;

    if (r5 < 0xDC)
    {
        r4 = (6 - proc->proc_parent->unk_31) * 8;

        for (i = 0; i < proc->proc_parent->unk_31; i++)
        {
            id = func_fe6_08087C78(proc->proc_parent->unk_30, i);
            id = func_fe6_08087CB0(id);

            if (i == proc->proc_parent->unk_2A)
            {
                func_fe6_08089A3C(proc, 0x38 - r5, r4 + i * 24, id, 1, 3);
            }
            else
            {
                func_fe6_08089A3C(proc, 0x38 - r5, r4 + i * 24, id, 4, 8);
            }
        }

        if (proc->proc_parent->unk_2D == 1)
        {
            func_fe6_0808A3C8(0, 0x24, r4 + proc->proc_parent->unk_2A * 24, proc);
        }
    }

    if (proc->proc_parent->unk_42 > 0 && proc->proc_parent->unk_42 < 0x1B8)
    {
        r4 = (6 - proc->proc_parent->unk_33) * 8;

        for (i = 0; i < proc->proc_parent->unk_33; i++)
        {
            id = func_fe6_08087C78(proc->proc_parent->unk_32, i);
            id = func_fe6_08087CB0(id);

            if (i == proc->proc_parent->unk_34)
            {
                func_fe6_08089ABC(proc, 0x114 - proc->proc_parent->unk_42, r4 + i * 26, id, 1, 3);
            }
            else
            {
                func_fe6_08089ABC(proc, 0x114 - proc->proc_parent->unk_42, r4 + i * 26, id, 4, 8);
            }
        }

        if (proc->proc_parent->unk_2D == 9)
        {
            func_fe6_0808A3C8(0, 0x24, r4 + proc->proc_parent->unk_34 * 26, proc);
        }
    }

    if (proc->proc_parent->unk_2F != 0)
    {
        func_fe6_08089684(proc);
        func_fe6_08089C70(proc);

        for (i = 0; i < 3; i++)
        {
            u32 r2 = (proc->proc_parent->unk_2D == 5 && proc->proc_parent->selected_id == i) ? 0x100 : 0;

            PutSpriteExt(4, OAM1_X(0xF4 - proc->proc_parent->unk_2F), 0x20 + r2 + i * 0x20, gUnk_0868A55C[i], OAM2_PAL(10 + i * 2));
            PutSpriteExt(4, OAM1_X(0xF4 - proc->proc_parent->unk_2F), 0x20 + r2 + i * 0x20 + 8, gUnk_0868A550[i], OAM2_PAL(11 + i * 2));
        }

        if (proc->proc_parent->unk_3F != 0xFF)
        {
            if (proc->proc_parent->unk_40 != 0x100)
            {
                if (proc->proc_parent->unk_5C != NULL)
                {
                    EndSpriteAnimProc(proc->proc_parent->unk_5C);
                    proc->proc_parent->unk_5C = NULL;
                }

                if (proc->proc_parent->unk_2E == 1)
                {
                    PutSpriteExt(4, 0xC2, 0x1E + proc->proc_parent->unk_3F * 0x20, Sprite_0868A158, 0);
                }
                else
                {
                    PutSpriteExt(4, 0xC2, 0x1E + proc->proc_parent->unk_3F * 0x20, Sprite_0868A158, OAM2_PAL(6));
                }
            }
            else
            {
                if (proc->proc_parent->unk_2E == 1)
                {
                    SetSpriteAnimProcParameters(proc->proc_parent->unk_5C,
                        0x1AC - proc->proc_parent->unk_2F, 0x34 + proc->proc_parent->unk_3F * 0x20, 0x1A0);
                }
                else
                {
                    SetSpriteAnimProcParameters(proc->proc_parent->unk_5C,
                        0x140, 0x34 + proc->proc_parent->unk_3F * 0x20, 0x1A0);

                    PutSpriteExt(4, 0x19E - proc->proc_parent->unk_2F, 0x1E + proc->proc_parent->unk_3F * 0x20,
                        Sprite_0868A158, OAM2_PAL(6));
                }
            }
        }
    }

    if (proc->proc_parent->unk_2D == 4 || proc->proc_parent->unk_2D == 5)
    {
        if (proc->proc_parent->unk_36 != 0)
        {
            int tmp;
            PutSpriteExt(4, 0x28, 0x80, Sprite_0868A116, 0x2000);

            tmp = proc->proc_parent->unk_36 - 1;
            PutUiHand(0x34 + (tmp - tmp / 2 * 2) * 0x28, 0x88);

            func_fe6_0808A3C8(1, 12, 0x20 + proc->proc_parent->selected_id * 0x20, proc);
        }
        else
        {
            if (proc->proc_parent->selected_id != 0xFF)
            {
                func_fe6_0808A3C8(1, 12, 0x20 + proc->proc_parent->selected_id * 0x20, proc);
            }
        }

        if (proc->proc_parent->copy_from_id != 0xFF)
        {
            func_fe6_0808A3E8(1, 0x20 + proc->proc_parent->copy_from_id * 0x20, proc);
        }
    }

    func_fe6_08089B3C(proc);
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A28C[] =
{
    PROC_19,
    PROC_CALL(func_fe6_080898F0),
    PROC_REPEAT(func_fe6_08089D30),
    PROC_END,
};

struct UnkProc_0868A28C * func_fe6_0808A14C(struct SaveMenuProc * parent)
{
    return SpawnProc(ProcScr_Unk_0868A28C, parent);
}

void func_fe6_0808A160(struct UnkProc_0868A2AC * proc)
{
    proc->unk_39 = 0;
    proc->unk_2A = 0;
    proc->unk_35 = 0;
    proc->unk_36 = 0;
    proc->unk_37 = 0;
    proc->unk_38 = 0;
    proc->unk_3A = 0;
    proc->unk_3B = 0;
    proc->unk_3D = 0;
    proc->unk_34 = 0;
}

void func_fe6_0808A194(struct UnkProc_0868A2AC * proc)
{
    SHOULD_BE_STATIC u8 SHOULD_BE_CONST ALIGNED(4) unk_08336C74[8] =
    {
        0, 1, 2, 3,
        3, 2, 1, 0,
    };

    proc->unk_2A++;
    proc->unk_2C++;

    func_fe6_08089894(2, 0x7800, 0x14000, 0x4C00, 0x4C00, proc->unk_2C, 0x180);

    gDispIo.bg2pb *= 2;
    gDispIo.bg2pd *= 2;

    // TODO: this is bad, esp. for MODERN
    #define SET_REG(type, reg, src) *((type*) &REG_##reg) = *((type*) &(src))

    SET_REG(u32, BG2PA, gDispIo.bg2pa); // set both with a single 32-bit copy
    SET_REG(u32, BG2PC, gDispIo.bg2pc); // set both with a single 32-bit copy
    SET_REG(u32, BG2X,  gDispIo.bg2x);
    SET_REG(u32, BG2Y,  gDispIo.bg2y);

    #undef SET_REG
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A2AC[] =
{
    PROC_19,
    PROC_CALL(func_fe6_0808A160),
    PROC_REPEAT(func_fe6_0808A194),
    PROC_END,
};

struct UnkProc_0868A2AC * func_fe6_0808A210(struct SaveMenuProc * parent)
{
    struct UnkProc_0868A2AC * proc;

    proc = SpawnProc(ProcScr_Unk_0868A2AC, PROC_TREE_VSYNC);
    proc->sm_proc = parent;

    return proc;
}
