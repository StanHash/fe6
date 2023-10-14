#include "common.h"

#include "irq.h"
#include "random.h"
#include "hardware.h"
#include "armfunc.h"
#include "proc.h"
#include "spriteanim.h"
#include "debugtext.h"
#include "gamecontroller.h"
#include "bm.h"
#include "mu.h"
#include "save_core.h"

#include "m4a.h"

void SramInit(void);
void InitGlobalSaveInfo(void);

void AgbMain(void)
{
    // clear RAM
    DmaFill32(3, 0, (void *) IWRAM_START, 0x7F80);
    CpuFastFill(0, (void *) EWRAM_START, 0x40000);

    REG_WAITCNT = WAITCNT_SRAM_4
        | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1
        | WAITCNT_WS1_N_3 | WAITCNT_WS1_S_1
        | WAITCNT_WS2_N_3 | WAITCNT_WS2_S_1
        | WAITCNT_PHI_OUT_NONE
        | WAITCNT_PREFETCH_ENABLE;

    IrqInit();
    SetOnVBlank(NULL);

    REG_DISPSTAT = 8;
    REG_IME = 1;

    InitKeySt(gKeySt);
    RefreshKeySt(gKeySt);

    InitRamFuncs();
    SramInit();
    InitProcs();
    InitSpriteAnims();
    InitMus();

    RandInitB(0x42D690E9);
    RandInit(RandNextB());

    if (!ReadGlobalSaveInfo(NULL))
        InitGlobalSaveInfo();

    m4aSoundInit();
    SetOnVBlank(OnVBlank);

    StartGame();

    while (TRUE)
    {
        RunMainFunc();
        SoftResetIfKeyCombo();
    }
}

void PutBuildInfo(u16 * tm)
{
    DebugPutStr(tm + TM_OFFSET(0, 0), "2002/03/02(SAT) 11:15:03");
    DebugPutStr(tm - TM_OFFSET(0, 1), "NARIHIRO");
}
