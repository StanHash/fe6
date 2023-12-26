#include "common.h"
#include "proc.h"
#include "bm.h"
#include "sprite.h"
#include "hardware.h"
#include "banim_sprite.h"
#include "banim_ekrbattle.h"

EWRAM_DATA i32 gBanimLinkArenaFlag = FALSE;
EWRAM_DATA i32 gBattleDeamonActive = FALSE;
EWRAM_DATA struct ProcEkrBattleDeamon * gpProcEkrBattleDeamon = NULL;
EWRAM_DATA i16 gEkrDebugModeMaybe = FALSE;

CONST_DATA char gNopStr[] = "\0";

void SetBanimLinkArenaFlag(int flag)
{
    gBanimLinkArenaFlag = flag;
}

int GetBanimLinkArenaFlag(void)
{
    return gBanimLinkArenaFlag;
}

void NewEkrBattleDeamon(void)
{
    gpProcEkrBattleDeamon = SpawnProc(ProcScr_EkrBattleDeamon, PROC_TREE_3);
    gBattleDeamonActive = TRUE;
    LockGame();
}

void EndEkrBattleDeamon(void)
{
    Proc_End(gpProcEkrBattleDeamon);
}

bool IsBattleDeamonActive(void)
{
    if (gBattleDeamonActive == TRUE)
        return TRUE;

    return FALSE;
}

void EkrBattleDeamon_OnEnd(void)
{
    gBattleDeamonActive = FALSE;
    UnlockGame();
}

void null_080425EC(void)
{
    return;
}

void NewEkrBattle(void)
{
    BasInit();
    gpProcEkrBattle = SpawnProc(ProcScr_EkrBattle, PROC_TREE_3);
    SetMainFunc(InBattleMainRoutine);
    EkrEfxStatusClear();
    func_fe6_0805884C();

    gEkrBattleEndFlag = 0;
    gEkrDebugTimer = 0;
    gEkrDebugUnk1 = 0;
    gEkrDebugUnk2 = 0;
    gCtrlC01Blocking = 0;

    if (0 == gEkrDebugModeMaybe)
        EkrPlayMainBGM();
}

void InBattleMainRoutine(void)
{
    RefreshKeySt(gKeySt);

    if (gEkrDebugUnk1 == FALSE)
        MainUpdateEkrBattle();
    else if (gEkrDebugUnk2 == TRUE)
        MainUpdateEkrBattle();

    switch (gEkrBattleEndFlag) {
    case 0:
        break;

    case 1:
        if (FALSE == gEkrDebugModeMaybe)
        {
            Proc_End(gpProcEkrBattle);
            EkrMainEndExec();
        }
        break;

    case 2:
        if (FALSE == gEkrDebugModeMaybe)
        {
            Proc_End(gpProcEkrBattle);
            EkrMainEndExec();
        }
        else
        {
            Proc_End(gpProcEkrBattle);
            EndEkrGauge();
        }
        break;

    default:
        break;
    }

    gBmSt.main_loop_ended = TRUE;
    gBmSt.main_loop_end_scanline = REG_VCOUNT;
    VBlankIntrWait();
}

void MainUpdateEkrBattle(void)
{
    ClearSprites();
    UnregisterEfxSoundSeExist();

    if (GetGameLock() == 0)
        Proc_Run(gProcTreeRootArray[2]);

    Proc_Run(gProcTreeRootArray[3]);
    Proc_Run(gProcTreeRootArray[5]);

    PutSpriteLayerOam(0);

    Proc_Run(gProcTreeRootArray[1]);

    BasUpdateAll();
    BattleAIS_ExecCommands();

    Proc_Run(gProcTreeRootArray[4]);

    gEkrDebugUnk2 = FALSE;

    if ((gBanimDoneFlag[POS_L] + gBanimDoneFlag[POS_R]) != 2)
        gEkrDebugTimer++;

    PutSpriteLayerOam(13);
}

void null_08042780(void)
{
    return;
}
