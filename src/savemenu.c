#include "common.h"

#include "gbaio.h"
#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "spriteanim.h"
#include "gamecontroller.h"
#include "util.h"
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

struct SaveMenuProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 unk_29;
    /* 2A */ u8 unk_2A;
    /* 2B */ u8 unk_2B; // save id
    /* 2C */ u8 unk_2C; // save id
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
    /* 44 */ STRUCT_PAD(0x44, 0x54);
    /* 54 */ ProcPtr unk_54;
    /* 58 */ ProcPtr unk_58;
    /* 5C */ ProcPtr unk_5C; // sprite anim proc
};

extern u16 const gUnk_083278AC[]; // pal x2
extern u8 const gUnk_083278EC[]; // tsa
extern u16 const gUnk_0832BDE8[]; // pal x8
extern u8 const gUnk_0832A29C[]; // lz img
extern u8 const gUnk_0832B554[]; // lz img

extern u8 const gUnk_083280B0[]; // lz img
extern u8 const gUnk_0832A130[]; // affine tm (spinny boi)

void func_fe6_0808A918(fu8 arg_0, struct SaveMenuProc * proc);
void func_fe6_0808A42C(void);
void func_fe6_0808A524(struct SaveMenuProc * proc);
int func_fe6_0808AA54(int arg_0, struct SaveMenuProc * proc);
void func_fe6_0808A9F4(int arg_0);
ProcPtr func_fe6_0808A14C(ProcPtr parent);
ProcPtr func_fe6_0808A210(ProcPtr parent);
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

extern u16 const gUnk_0832C35C[];
extern u16 gUnk_Savemenu_02000000;
extern u16 gUnk_Savemenu_02000404[];

extern char const gUnk_08336C60[]; // string

#define REG_BLDY_16 (*(u16 volatile *) &REG_BLDY)

void func_fe6_08087C14(void)
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
        case 0x02:
        case 0x10:
        case 0x20:
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
    if ((proc->unk_2E == 0x80 && (GetCurrentBgmSong() == SONG_01 || GetCurrentBgmSong() == SONG_44 || GetCurrentBgmSong() == SONG_01))
        || proc->unk_2E == 0x40)
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

void func_fe6_08087E7C(struct SaveMenuProc * proc)
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

    proc->unk_29 = 0;

    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.win1_enable_blend = 1;

    Decompress(gUnk_0832A29C, OBJ_VRAM0 + 0x1000);

    if (proc->unk_2E == 0x40)
    {
        func_fe6_08070E70(OBJ_VRAM0 + CHR_SIZE * OBJCHR_SAVEMENU_1C0, OBJPAL_SAVEMENU_9);
    }
    else
    {
        Decompress(gUnk_0832B554, OBJ_VRAM0 + CHR_SIZE * OBJCHR_SAVEMENU_1C0);
    }

    if (proc->unk_2E == 0x20)
    {
        if (proc->unk_35 == 1)
        {
            func_fe6_08070E70(OBJ_VRAM0 + CHR_SIZE * OBJCHR_SAVEMENU_200, 9);
        }
    }
    else
    {
        if (proc->unk_2E == 0x40)
        {
            proc->unk_2D = L_SAVEMENU_4;
            proc->unk_2B = ReadLastGameSaveId();
        }
        else
        {
            proc->unk_2D = L_SAVEMENU_1;
            proc->unk_2B = 0;
        }

        proc->unk_2A = 0;
        proc->unk_34 = 0;
        proc->unk_42 = 0;
    }

    proc->unk_36 = 0;
    proc->unk_2C = 0xFF;
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

    SetOnHBlankA(func_fe6_08087C14);
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

    if (proc->unk_2E == 0x40)
    {
        proc->unk_30 = 0x40;
        proc->unk_2E = 0x40;
        proc->unk_31 = 0;
    }
    else
    {
        func_fe6_0808A524(proc);

        if (proc->unk_2E == 0x20)
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

    func_fe6_0808A9F4(proc->unk_2B);
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

        proc->unk_29 = 0;

        switch (proc->unk_2E)
        {
            case 0x01:
                proc->unk_2B = proc->unk_3F;
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case 0x02:
                proc->unk_2B = func_fe6_0808A658(ReadLastGameSaveId(), 1, 1);
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case 0x04:
                proc->unk_2B = func_fe6_0808A658(ReadLastGameSaveId(), 1, 1);
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case 0x08:
                proc->unk_2B = func_fe6_0808A658(ReadLastGameSaveId(), 1, 1);
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case 0x10:
                proc->unk_2B = func_fe6_0808A658(proc->unk_2B, 0, 1);
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case 0x20:
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
        proc->unk_2E = 0x80;
    }
}

void func_fe6_08088404(struct SaveMenuProc * proc)
{
    if (proc->unk_36 == 0)
    {
        PlaySe(SONG_6A);

        switch (proc->unk_2E)
        {
            case 0x04:
                if (proc->unk_2C == 0xFF)
                {
                    proc->unk_2C = proc->unk_2B;
                    func_fe6_0808A6C8(proc, 1);
                }
                else
                {
                    CopyGameSave(proc->unk_2C, proc->unk_2B);
                    Proc_Goto(proc, L_SAVEMENU_5);
                }

                return;

            case 0x08:
                proc->unk_36 = 2;
                func_fe6_0808A4B8(proc, 1);
                break;

            case 0x02:
            case 0x10:
            case 0x20:
            case 0x40:
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
            case 0x20:
                if (proc->unk_36 == 1)
                {
                    proc->unk_40 = 0xF0;
                    ReadGameSave(SAVE_GAME0 + proc->unk_2B);
                    Proc_Goto(proc, L_SAVEMENU_13);
                    PlaySe(SONG_6A);
                }
                else
                {
                    PlaySe(SONG_6B);
                }

                break;

            case 0x02:
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

            case 0x10:
                if (proc->unk_36 == 1)
                {
                    if (proc->unk_3D == 1)
                    {
                        WriteNewGameSave(proc->unk_2B, FALSE);
                    }
                    else if (proc->unk_3D == 2)
                    {
                        WriteNewGameSave(proc->unk_2B, TRUE);
                    }

                    Proc_Goto(proc, L_SAVEMENU_5);
                    PlaySe(SONG_60);
                }
                else
                {
                    PlaySe(SONG_6B);
                }

                break;

            case 0x08:
                if (proc->unk_36 == 1)
                {
                    InvalidateGameSave(proc->unk_2B);
                    Proc_Goto(proc, L_SAVEMENU_5);
                    PlaySe(SONG_6A);
                }
                else
                {
                    PlaySe(SONG_6B);
                }

                break;

            case 0x40:
                if (proc->unk_36 == 1)
                {
                    WriteGameSave(proc->unk_2B);
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
        proc->unk_29 = 0;

        switch (proc->unk_2E)
        {
            case 0x02:
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

            case 0x01:
                PlaySe(SONG_6A);
                func_fe6_08087C60(proc);
                break;

            case 0x04:
            case 0x08:
            case 0x40:
                func_fe6_08088404(proc);
                break;

            case 0x10:
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
                    func_fe6_0808A454(gUnk_08336C60, TRUE);
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
                            WriteNewGameSave(proc->unk_2B, 0);
                        }
                        else if (proc->unk_3D == 2)
                        {
                            WriteNewGameSave(proc->unk_2B, 1);
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
        proc->unk_29 = 0;
        PlaySe(SONG_6B);

        if (proc->unk_36 != 0)
        {
            proc->unk_3D = 1;
            func_fe6_0808A4B8(proc, 0);
            func_fe6_08087CD4(proc);
        }
        else if (proc->unk_2C != 0xFF)
        {
            proc->unk_2B = proc->unk_2C;
            proc->unk_2C = -1;
        }
        else if (proc->unk_2E == 0x40)
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
    proc->unk_29 = 0;
}

void func_fe6_08088870(struct SaveMenuProc * proc)
{
    if (proc->unk_29 == 8)
    {
        func_fe6_0808A918(proc->unk_2B, proc);
        func_fe6_0808A918(4, proc);

        if (proc->unk_37[proc->unk_2B] != 0xFF)
        {
            // tyvm Eebit
            // TODO: there's probably something better to do here
            func_fe6_08070D08(((u32)(proc->unk_2B * 0x800 + 0x16800) & 0x0001FFFF) >> 5, proc->unk_37[proc->unk_2B]);
        }
        else
        {
            func_fe6_08070D08(((u32)(proc->unk_2B * 0x800 + 0x16800) & 0x0001FFFF) >> 5, -1);
        }

        func_fe6_0808A9F4(proc->unk_2B);
    }
    else if (proc->unk_29 == 0x20)
    {
        func_fe6_0808A524(proc);

        if (proc->unk_2E == 0x10)
        {
            Proc_Goto(proc, L_SAVEMENU_16);
            StartBgmVolumeChange(0x80, 0, 0x10, 0);
        }
        else if (proc->unk_2E == 0x40)
        {
            Proc_Goto(proc, L_SAVEMENU_15);
        }
        else
        {
            if (func_fe6_0808A79C(proc))
            {
                if (proc->unk_2C != 0xFF)
                {
                    proc->unk_2B = proc->unk_2C;
                    proc->unk_2C = -1;
                }
                else
                {
                    proc->unk_2B = func_fe6_0808A658(proc->unk_2B, 1, 1);
                }

                Proc_Goto(proc, L_SAVEMENU_4);
            }
        }
    }
    else if (proc->unk_29 == 0x30)
    {
        proc->unk_2B = 0;
        proc->unk_2C = -1;
        proc->unk_29 = 0;
        proc->unk_2A = 0;
        proc->unk_2E = func_fe6_08087C78(proc->unk_30, 0);

        PlaySe(SONG_6B);

        Proc_Goto(proc, L_SAVEMENU_3);
        return;
    }

    if (proc->unk_29 == 0x10)
    {
        SetObjAffineAuto(proc->unk_2B, 0, 0x100, 0x100);
    }
    else if (proc->unk_29 < 8)
    {
        SetObjAffineAuto(proc->unk_2B, 0, 0x100, (proc->unk_29 * -0x20) + 0x100);
    }
    else if (proc->unk_29 < 0x10)
    {
        SetObjAffineAuto(proc->unk_2B, 0, 0x100, (proc->unk_29 * 0x20) - 0xE0);
    }

    proc->unk_29++;
}

void func_fe6_08088B40(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_2;
    proc->unk_29++;

    // TODO: what
    proc->unk_2F = (((7 * proc->unk_29 * 8 - proc->unk_29) * 8) - (220 * proc->unk_29 * proc->unk_29 / 14)) / 14;

    if (proc->unk_29 == 14)
    {
        func_fe6_08070E70(OBJ_VRAM0 + OBJCHR_SAVEMENU_1C0 * CHR_SIZE, OBJPAL_SAVEMENU_9);
        Proc_Break(proc);
    }
}

void func_fe6_08088B9C(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_3;
    proc->unk_29++;

    // TODO: what
    proc->unk_2F = -36 - (((7 * proc->unk_29 * 8 - proc->unk_29) * 8) - (220 * proc->unk_29 * proc->unk_29 / 14)) / 14;

    if (proc->unk_29 == 14)
    {
        Decompress(gUnk_0832B554, OBJ_VRAM0 + OBJCHR_SAVEMENU_1C0 * CHR_SIZE);
        Proc_Break(proc);
    }
}

void func_fe6_08088C04(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_7;
    proc->unk_29++;

    // TODO: what
    proc->unk_42 = (((7 * proc->unk_29 * 8 - proc->unk_29) * 8) - (220 * proc->unk_29 * proc->unk_29 / 14)) / 14;

    if (proc->unk_29 == 14)
    {
        Proc_Goto(proc, L_SAVEMENU_9);
    }
}

void func_fe6_08088C58(struct SaveMenuProc * proc)
{
    proc->unk_2D = 7;
    proc->unk_29++;

    // TODO: what
    proc->unk_42 = 220 - (((7 * proc->unk_29 * 8 - proc->unk_29) * 8) - (220 * proc->unk_29 * proc->unk_29 / 14)) / 14;

    if (proc->unk_29 == 14)
    {
        Proc_Goto(proc, L_SAVEMENU_1);
    }
}

void func_fe6_08088CB0(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_11;
    proc->unk_29++;

    // TODO: what
    proc->unk_42 = 220 + (((7 * proc->unk_29 * 8 - proc->unk_29) * 8) - (220 * proc->unk_29 * proc->unk_29 / 14)) / 14;
    proc->unk_2F = proc->unk_42 + 36;

    if (proc->unk_29 == 14)
    {
        Proc_Goto(proc, L_SAVEMENU_10);
    }
}

void func_fe6_08088D0C(struct SaveMenuProc * proc)
{
    proc->unk_2D = L_SAVEMENU_12;
    proc->unk_29++;

    // TODO: what
    proc->unk_42 = 440 - (((7 * proc->unk_29 * 8 - proc->unk_29) * 8) - (220 * proc->unk_29 * proc->unk_29 / 14)) / 14;
    proc->unk_2F = proc->unk_42 + 36;

    if (proc->unk_29 == 14)
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

        proc->unk_29 = 0;

        switch (proc->unk_35)
        {
            default:
                func_fe6_08087C60(proc);
                Proc_Goto(proc, L_SAVEMENU_16);
                break;

            case 1:
                proc->unk_2B = func_fe6_0808A658(ReadLastGameSaveId(), 1, 1);
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
        proc->unk_29 = 0;
        Proc_Goto(proc, L_SAVEMENU_8);
        PlaySe(SONG_6B);
    }
}

bool func_fe6_08088EB8(struct SaveMenuProc * proc, int direction)
{
    int i;

    fu8 previous = proc->unk_2B;

    if (direction == 0)
    {
        if ((proc->unk_3A[proc->unk_2B] & 1) != 0)
            return TRUE;

        direction = 1;
    }

    if (direction > 0)
    {
        for (i = 0; i < 3; i++)
        {
            if (proc->unk_2B < 2)
                proc->unk_2B++;
            else
                proc->unk_2B = 0;

            if ((proc->unk_3A[proc->unk_2B] & 1) != 0)
                break;
        }
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            if (proc->unk_2B == 0)
                proc->unk_2B = 2;
            else
                proc->unk_2B = proc->unk_2B - 1;

            if ((proc->unk_3A[proc->unk_2B] & 1) != 0)
                break;
        }
    }

    if (previous != proc->unk_2B)
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
            ReadGameSave(SAVE_GAME0 + proc->unk_2B);
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
            proc->unk_29 = 0;
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

    if (proc->unk_2E == 0x20)
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
    else if (proc->unk_2E != 0x40)
    {
        if (proc->unk_2E == 1)
        {
            ReadSuspendSave(SAVE_SUSPEND);
            SetNextGameAction(GAME_ACTION_3);
        }
        else if (proc->unk_2E == 2)
        {
            ReadGameSave(SAVE_GAME0 + proc->unk_2B);
            SetNextGameAction(GAME_ACTION_0 + proc->unk_2B);
        }
        else if (proc->unk_2E == 0x10)
        {
            SetNextGameAction(GAME_ACTION_0);
        }
        else if (proc->unk_2E == 0x80)
        {
            StartBgmVolumeChange(0x80, 0x100, 0x10, NULL);
            SetNextGameAction(GAME_ACTION_4);
        }
    }
}

void func_fe6_08089180(struct SaveMenuProc * proc)
{
    proc->unk_2E = 0x20;

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

    PROC_CALL(func_fe6_08087E7C),
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

    PROC_CALL(func_fe6_08087E7C),
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

    proc->unk_2E = 0x80;
    proc->unk_35 = 0;

    gPlaySt.config_talk_speed = 2;
}

void func_fe6_08089234(ProcPtr parent)
{
    struct SaveMenuProc * proc;

    proc = SpawnProcLocking(ProcScr_SaveMenu, parent);

    proc->unk_2E = 0x40;
    proc->unk_35 = 0;
}
