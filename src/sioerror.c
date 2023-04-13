#include "sioerror.h"

#include "hardware.h"
#include "move.h"
#include "sound.h"
#include "text.h"
#include "msg.h"
#include "helpbox.h"

#include "constants/msg.h"
#include "constants/songs.h"
#include "constants/videoalloc_global.h" // for CHR_SIZE

void OnVBlank_SioError(void)
{
    // TODO: macro
    (*(u16 volatile *)0x03007FF8) = 1;

    SyncDispIo();
    SyncBgsAndPal();
    ApplyDataMoves();
    m4aSoundVSync();
    m4aSoundMain();
}

void OnMain_SioErrorWait(void)
{
    RefreshKeySt(gKeySt);

    if ((gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_START)) != 0)
        SoftReset(GBA_RESET_ALL);

    VBlankIntrWait();
}

void PutSioErrorMessage(void)
{
    struct Text text[3];
    struct HelpBoxPrintProc fake_proc;
    int i;

    struct HelpBoxPrintProc * const proc = &fake_proc;

    ResetText();
    InitTalkTextFont();

    for (i = 0; i < (int) ARRAY_COUNT(text); i++)
    {
        InitText(&text[i], 22);
        Text_SetColor(&text[i], TEXT_COLOR_0123);
    }

    proc->font = NULL;
    proc->text[0] = &text[0];
    proc->text[1] = &text[1];
    proc->text[2] = &text[2];
    proc->line = 0;
    proc->str_it = DecodeMsg(MSG_C48);

    func_fe6_08071308(proc);

    PutText(&text[0], gBg0Tm + TM_OFFSET(4,  6));
    PutText(&text[1], gBg0Tm + TM_OFFSET(4,  9));
    PutText(&text[2], gBg0Tm + TM_OFFSET(4, 11));

    EnableBgSync(BG0_SYNC_BIT);
}

void OnMain_SioError(void)
{
    InitBgs(NULL);
    m4aSoundInit();
    InitProcs();

    SetBgOffset(0, 0, 0);
    SetDispEnable(1, 0, 0, 0, 0);
    SetWinEnable(0, 0, 0);
    SetBlendNone();
    gDispIo.mosaic = 0;
    SyncDispIo();

    CpuFastFill(0, (void *) VRAM + 0x0000, CHR_SIZE);
    CpuFastFill(0, (void *) VRAM + 0x8000, CHR_SIZE);

    PutSioErrorMessage();

    PlaySe(SONG_7B);

    SetMainFunc(OnMain_SioErrorWait);
}

void StartSioErrorScreen(void)
{
    REG_DISPSTAT = DISPSTAT_VBLANK_INT_ENABLE;
    REG_IME = TRUE;
    REG_DISPCNT = 0;

    SetOnVBlank(OnVBlank_SioError);
    SetMainFunc(OnMain_SioError);
}
