#include "common.h"

#include "gbaio.h"
#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
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

    OBJPAL_SAVEMENU_9 = 9,
};

struct SaveMenuProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 unk_29;
    /* 2A */ u8 unk_2A;
    /* 2B */ u8 unk_2B; // save id
    /* 2C */ u8 unk_2C; // save id
    /* 2D */ u8 unk_2D;
    /* 2E */ u8 unk_2E;
    /* 2F */ u8 unk_2F;
    /* 30 */ u8 unk_30;
    /* 31 */ u8 unk_31;
    /* 32 */ STRUCT_PAD(0x32, 0x33);
    /* 33 */ u8 unk_33;
    /* 34 */ u8 unk_34;
    /* 35 */ u8 unk_35;
    /* 36 */ u8 unk_36;
    /* 37 */ u8 unk_37[3]; // unsure of length
    /* 3A */ STRUCT_PAD(0x3A, 0x3D);
    /* 3D */ u8 unk_3D;
    /* 3E */ u8 unk_3E;
    /* 3F */ u8 unk_3F;
    /* 40 */ u16 unk_40;
    /* 42 */ u16 unk_42;
    /* 44 */ STRUCT_PAD(0x44, 0x54);
    /* 54 */ ProcPtr unk_54;
    /* 58 */ ProcPtr unk_58;
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

extern u16 const gUnk_0832C35C[];
extern u16 gUnk_Savemenu_02000000;
extern u16 gUnk_Savemenu_02000404[];

extern u16 CONST_DATA gUnk_08689E84[12]; // bg config

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

void func_fe6_08087C60(ProcPtr proc)
{
    Proc_Goto(proc, 0x10);
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

void func_fe6_08087D44(struct SaveMenuProc * proc)
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

void func_fe6_08087DA4(struct SaveMenuProc * proc)
{
    InitBgs(gUnk_08689E84);

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

    func_fe6_08087D44(proc);
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
            func_fe6_08070E70(OBJ_VRAM0 + 0x4000, 9);
        }
    }
    else
    {
        if (proc->unk_2E == 0x40)
        {
            proc->unk_2D = 4;
            proc->unk_2B = ReadLastGameSaveId();
        }
        else
        {
            proc->unk_2D = 1;
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

    if (proc->unk_2D == 1)
        proc->unk_2F = 0;

    if (proc->unk_2D == 4)
        proc->unk_2F = 0xDC;
}

void func_fe6_080881B8(struct SaveMenuProc * proc)
{
    Proc_Goto(proc, proc->unk_2D);
}

void func_fe6_080881C8(struct SaveMenuProc * proc)
{
    proc->unk_2D = 1;

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
                Proc_Goto(proc, 2);
                break;

            case 0x02:
                proc->unk_2B = func_fe6_0808A658(ReadLastGameSaveId(), 1, 1);
                Proc_Goto(proc, 2);
                break;

            case 0x04:
                proc->unk_2B = func_fe6_0808A658(ReadLastGameSaveId(), 1, 1);
                Proc_Goto(proc, 2);
                break;

            case 0x08:
                proc->unk_2B = func_fe6_0808A658(ReadLastGameSaveId(), 1, 1);
                Proc_Goto(proc, 2);
                break;

            case 0x10:
                proc->unk_2B = func_fe6_0808A658(proc->unk_2B, 0, 1);
                Proc_Goto(proc, 2);
                break;

            case 0x20:
                if (proc->unk_34 >= proc->unk_33)
                    proc->unk_34 = 0;

                Proc_Goto(proc, 7);
                break;
        }
    }
    else if ((gKeySt->pressed & KEY_BUTTON_B) != 0)
    {
        PlaySe(SONG_6B);
        Proc_Goto(proc, 16);
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
                    Proc_Goto(proc, 5);
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
                    ReadGameSave(proc->unk_2B);
                    Proc_Goto(proc, 0xD);
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

                    Proc_Goto(proc, 5);
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
                    Proc_Goto(proc, 5);
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
                    Proc_Goto(proc, 5);
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
    proc->unk_2D = 4;

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
                        Proc_Goto(proc, 6);
                        return;
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

                        Proc_Goto(proc, 5);
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
            return;
        }
        else if (proc->unk_2E == 0x40)
        {
            Proc_Goto(proc, 15);
        }
        else
        {
            Proc_Goto(proc, 3);
        }
    }
}

void func_fe6_08088854(struct SaveMenuProc * proc)
{
    func_fe6_08088404(proc);
}

void func_fe6_08088860(struct SaveMenuProc * proc)
{
    proc->unk_2D = 5;
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
            Proc_Goto(proc, 16);
            StartBgmVolumeChange(0x80, 0, 0x10, 0);
        }
        else if (proc->unk_2E == 0x40)
        {
            Proc_Goto(proc, 15);
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

                Proc_Goto(proc, 4);
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

        Proc_Goto(proc, 3);
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
    int r4;

    proc->unk_2D = 2;
    proc->unk_29++;

    // TODO: what
    r4 = proc->unk_29 * 7;
    r4 = r4 * 8 - proc->unk_29;
    proc->unk_2F = ((r4 << 3) - (220 * proc->unk_29 * proc->unk_29 / 14)) / 14;

    if (proc->unk_29 == 14)
    {
        func_fe6_08070E70(OBJ_VRAM0 + OBJCHR_SAVEMENU_1C0 * CHR_SIZE, OBJPAL_SAVEMENU_9);
        Proc_Break(proc);
    }
}
