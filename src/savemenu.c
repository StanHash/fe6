#include "savemenu.h"

#include "gbaio.h"
#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "sprite.h"
#include "spriteanim.h"
#include "gamecontroller.h"
#include "util.h"
#include "helpbox.h"
#include "save_core.h"
#include "save_game.h"

#include "constants/songs.h"
#include "constants/msg.h"

#include "constants/videoalloc_global.h"

extern u16 const gUnk_083278AC[]; // pal x2
extern u8 const gUnk_083278EC[]; // tsa
extern u16 const gUnk_0832BDE8[]; // pal x8
extern u8 const gUnk_0832A29C[]; // lz img
extern u8 const gUnk_0832B554[]; // lz img

extern u8 const gUnk_083280B0[]; // lz img
extern u8 const gUnk_0832A130[]; // affine tm (spinny boi)

struct UnkProc_0868A28C * func_fe6_0808A14C(struct SaveMenuProc * parent);
struct UnkProc_0868A2AC * func_fe6_0808A210(struct SaveMenuProc * parent);
fu8 func_fe6_0808A658(fu8 save_id, bool valid, fi8 direction);
bool func_fe6_0808A6C8(struct SaveMenuProc * proc, int arg_1);
void func_fe6_0808A4B8(struct SaveMenuProc * proc, int arg_1);
void func_fe6_0808A454(char const * string, bool display);
bool func_fe6_0808A79C(struct SaveMenuProc * proc);
bool func_fe6_08088EB8(struct SaveMenuProc * proc, int direction);
void func_fe6_0808A8B4(ProcPtr parent, int arg_1, int arg_2);
void func_fe6_0808B578(fu8 arg_0, ProcPtr parent);
void func_fe6_0808BD58(ProcPtr parent);
void func_fe6_08089550(ProcPtr parent);
void func_fe6_08089564(ProcPtr parent);
void func_fe6_08089578(ProcPtr parent);

extern u16 const gUnk_0832C35C[]; // colors

#define REG_BLDY_16 (*(u16 volatile *) &REG_BLDY)

u16 EWRAM_OVERLAY(savemenu) gUnk_Savemenu_02000000 = 0;
u16 EWRAM_OVERLAY(savemenu) gUnk_Savemenu_02000002[0x200] = { 0 };

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
    func_fe6_08070E70(OBJ_VRAM0 + CHR_SIZE * OBCHR_SAVEMENU_1C0, OBPAL_SAVEMENU_9);
    func_fe6_080895A0(gUnk_0832C35C, gUnk_Savemenu_02000404, 2);
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    proc->anim_clock = 0;

    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.win1_enable_blend = 1;

    Decompress(gUnk_0832A29C, OBJ_VRAM0 + 0x1000);

    if (proc->unk_2E == UNK_SAVEMENU_6)
    {
        func_fe6_08070E70(OBJ_VRAM0 + CHR_SIZE * OBCHR_SAVEMENU_1C0, OBPAL_SAVEMENU_9);
    }
    else
    {
        Decompress(gUnk_0832B554, OBJ_VRAM0 + CHR_SIZE * OBCHR_SAVEMENU_1C0);
    }

    if (proc->unk_2E == UNK_SAVEMENU_5)
    {
        if (proc->unk_35 == 1)
        {
            func_fe6_08070E70(OBJ_VRAM0 + CHR_SIZE * OBCHR_SAVEMENU_200, 9);
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
        proc->unk_30 = UNK_SAVEMENU_6;
        proc->unk_2E = UNK_SAVEMENU_6;
        proc->unk_31 = 0;
    }
    else
    {
        func_fe6_0808A524(proc);

        if (proc->unk_2E == UNK_SAVEMENU_5)
        {
            proc->unk_2A = func_fe6_0808AA54(UNK_SAVEMENU_5, proc);
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
                proc->selected_id = func_fe6_0808A658(ReadLastGameSaveId(), TRUE, 1);
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case UNK_SAVEMENU_2:
                proc->selected_id = func_fe6_0808A658(ReadLastGameSaveId(), TRUE, 1);
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case UNK_SAVEMENU_3:
                proc->selected_id = func_fe6_0808A658(ReadLastGameSaveId(), TRUE, 1);
                Proc_Goto(proc, L_SAVEMENU_2);
                break;

            case UNK_SAVEMENU_4:
                proc->selected_id = func_fe6_0808A658(proc->selected_id, FALSE, 1);
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
                    func_fe6_0808A454(JTEXT("ノーマル　ハード"), TRUE);
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
                    proc->selected_id = func_fe6_0808A658(proc->selected_id, TRUE, 1);
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
        func_fe6_08070E70(OBJ_VRAM0 + OBCHR_SAVEMENU_1C0 * CHR_SIZE, OBPAL_SAVEMENU_9);
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
        Decompress(gUnk_0832B554, OBJ_VRAM0 + OBCHR_SAVEMENU_1C0 * CHR_SIZE);
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
                proc->selected_id = func_fe6_0808A658(ReadLastGameSaveId(), TRUE, 1);
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
                func_fe6_08070E70(OBJ_VRAM0 + CHR_SIZE * 0x200, OBPAL_SAVEMENU_9);
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
            Decompress(gUnk_0832B554, OBJ_VRAM0 + OBCHR_SAVEMENU_1C0 * CHR_SIZE);
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

void StartMainMenu(ProcPtr parent)
{
    struct SaveMenuProc * proc;

    proc = SpawnProcLocking(ProcScr_SaveMenu, parent);

    proc->unk_2E = UNK_SAVEMENU_7;
    proc->unk_35 = 0;

    gPlaySt.config_talk_speed = 2;
}

void StartSaveMenu(ProcPtr parent)
{
    struct SaveMenuProc * proc;

    proc = SpawnProcLocking(ProcScr_SaveMenu, parent);

    proc->unk_2E = UNK_SAVEMENU_6;
    proc->unk_35 = 0;
}
