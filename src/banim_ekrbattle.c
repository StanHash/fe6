#include "prelude.h"
#include "proc.h"
#include "bm.h"
#include "sprite.h"
#include "eventinfo.h"
#include "hardware.h"
#include "battle.h"
#include "arena.h"
#include "manim.h"
#include "move.h"
#include "banim_sprite.h"
#include "banim.h"
#include "banim_ekrbattle.h"
#include "banim_ekrdragon.h"

EWRAM_DATA i32 gBanimLinkArenaFlag = FALSE;
EWRAM_DATA i32 gBattleDeamonActive = FALSE;
EWRAM_DATA  struct Proc * gpProcEkrBattleDeamon = NULL;
EWRAM_DATA i16 gEkrDebugModeMaybe = FALSE;
// EWRAM_DATA i16 gEkrInitialHitSide = FALSE;


CONST_DATA char gNopStr[] = "\0";

void SetBanimLinkArenaFlag(int flag)
{
    gBanimLinkArenaFlag = flag;
}

int GetBanimLinkArenaFlag(void)
{
    return gBanimLinkArenaFlag;
}

struct ProcScr CONST_DATA ProcScr_EkrBattleDeamon[] =
{
    PROC_NAME_DEBUG("ekrBattleDaemon"),
    PROC_ONEND(EkrBattleDeamon_OnEnd),
    PROC_REPEAT(EkrBattleDeamonMain),
    PROC_END,
};

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

void EkrBattleDeamonMain(ProcPtr proc)
{
    return;
}

struct ProcScr CONST_DATA ProcScr_EkrBattle[] =
{
    PROC_NAME_DEBUG("ekrBattle"),
    PROC_ONEND(EkrBattle_End),
    PROC_REPEAT(EkrBattle_Init),
    PROC_REPEAT(EkrBattle_Main),
    PROC_END,
};

void NewEkrBattle(void)
{
    BasInit();
    gpProcEkrBattle = SpawnProc(ProcScr_EkrBattle, PROC_TREE_3);
    SetMainFunc(InBattleMainRoutine);
    EkrEfxStatusClear();
    ResetEkrDragonStatus();

    gEkrBattleEndFlag = 0;
    gEkrDebugTimer = 0;
    gEkrDebugFlag1 = 0;
    gEkrDebugFlag2 = 0;
    gAnimC01Blocking = 0;

    if (0 == gEkrDebugModeMaybe)
        EkrPlayMainBGM();
}

void InBattleMainRoutine(void)
{
    RefreshKeySt(gKeySt);

    if (gEkrDebugFlag1 == FALSE)
        MainUpdateEkrBattle();
    else if (gEkrDebugFlag2 == TRUE)
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

    gEkrDebugFlag2 = FALSE;

    if ((gBanimDoneFlag[POS_L] + gBanimDoneFlag[POS_R]) != 2)
        gEkrDebugTimer++;

    PutSpriteLayerOam(13);
}

void EkrBattle_End(struct ProcEkrBattle * proc)
{
    return;
}

void EkrBattle_Init(struct ProcEkrBattle * proc)
{
    gEkrBgPosition = 0;
    if (gEkrInitPosReal == POS_L)
    {
        if (gEkrDistanceType == EKR_DISTANCE_FAR)
            gEkrBgPosition = -0x20;
        else
            gEkrBgPosition = -0xF0;
    }

    InitMainAnims();
    InitEkrDragonStatus();

    gAnimC01Blocking = TRUE;

    if (GetBattleAnimArenaFlag() == TRUE)
        proc->timer = 0;
    else
        proc->timer = 0x1E;

    if (POS_L == gEkrInitialHitSide)
        proc->quote = CheckBattleTalk(gEkrPids[POS_L], gEkrPids[POS_R]);
    else
        proc->quote = CheckBattleTalk(gEkrPids[POS_R], gEkrPids[POS_L]);

    proc->unk58 = 0;
    Proc_Break(proc);
}

void EkrBattle_Main(struct ProcEkrBattle * proc)
{
    if (++proc->timer == 0x1F)
    {
        if (GetBanimLinkArenaFlag() != 1 && (proc->quote == TRUE || proc->unk58 == TRUE))
        {
            NewEkrWindowAppear(1, 7);
            NewEkrNamewinAppear(1, 7, 0);
            proc->proc_repeat_func = (ProcFunc)EkrBattleStartBattleQuote;
            proc->timer = 0;
        }
        else
        {
            proc->proc_repeat_func = (ProcFunc)EkrBattlePreDragonIntro;
            proc->timer = 0;
        }
    }
}

void EkrBattleStartBattleQuote(struct ProcEkrBattle * proc)
{
    if (CheckEkrWindowAppearUnexist() != TRUE)
        return;

    EnableEkrGauge();
    EkrGauge_08044264();
    CpuFastFill(0, gBg0Tm, 0x800);
    SetBgOffset(0, gEkrBg0QuakeVec.x, gEkrBg0QuakeVec.y);
    SetBgOffset(1, 0, 0);
    EnableBgSync(BG0_SYNC_BIT);
    EkrGauge_080438D8();

    if (proc->quote == TRUE)
    {
        if (gEkrInitialHitSide == POS_L)
            StartBattleTalk(gEkrPids[POS_L], gEkrPids[POS_R]);
        else
            StartBattleTalk(gEkrPids[POS_R], gEkrPids[POS_L]);

        proc->quote = FALSE;
    }
    proc->proc_repeat_func = (ProcFunc)EkrBattleWaitBattleQuote;
}

void EkrBattleWaitBattleQuote(struct ProcEkrBattle * proc)
{
    if (IsEventRunning() != FALSE)
        return;

    EfxPrepareScreenFx();
    EnableBgSync(BG0_SYNC_BIT);
    NewEkrWindowAppear(0, 7);
    NewEkrNamewinAppear(0, 7, 0);
    DisableEkrGauge();
    UnAsyncEkrDispUP();
    EkrGauge_080438C8();
    proc->proc_repeat_func = (ProcFunc)EkrBattleWaitWindowAppear;
}

void EkrBattleWaitWindowAppear(struct ProcEkrBattle * proc)
{
    if (CheckEkrWindowAppearUnexist() == TRUE)
    {
        proc->proc_repeat_func = (ProcFunc)EkrBattlePreDragonIntro;
        proc->timer = 0;
    }
}

void EkrBattlePreDragonIntro(struct ProcEkrBattle * proc)
{
    proc->side = gEkrInitialHitSide;
    proc->counter = 0;
    proc->proc_repeat_func = (ProcFunc)EkrBattleExecDragonIntro;
}

void EkrBattleExecDragonIntro(struct ProcEkrBattle * proc)
{
    u32 conf = GetEkrDragonStateTypeGeneric();

    if (proc->counter == 2)
    {
        proc->proc_repeat_func = (ProcFunc)EkrBattlePostDragonIntro;
        return;
    }

    if (proc->side == POS_L)
    {
        /* Left position */
        proc->anim = MAIN_ANIM_FRONT(POS_L);
        if (conf & EDRAGON_TYPE_MANAKETE_L)
        {
            NewEkrManakete(proc->anim);
            proc->proc_repeat_func = (ProcFunc)EkrBattleWaitDragonIntro;
        }
        if (conf & EDRAGON_TYPE_FAE_L)
        {
            NewEkrDragonFae(proc->anim);
            proc->proc_repeat_func = (ProcFunc)EkrBattleWaitDragonIntro;
        }
        if (conf & EDRAGON_TYPE_IDUNN_L)
        {
            NewEkrDragonIdunn(proc->anim);
            proc->proc_repeat_func = (ProcFunc)EkrBattleWaitDragonIntro;
        }
        proc->side = POS_R;
    }
    else
    {
        /* Right position */
        proc->anim = MAIN_ANIM_FRONT(POS_R);
        if (conf & EDRAGON_TYPE_MANAKETE_R)
        {
            NewEkrManakete(proc->anim);
            proc->proc_repeat_func = (ProcFunc)EkrBattleWaitDragonIntro;
        }
        if (conf & EDRAGON_TYPE_FAE_R)
        {
            NewEkrDragonFae(proc->anim);
            proc->proc_repeat_func = (ProcFunc)EkrBattleWaitDragonIntro;
        }
        proc->side = POS_L;
    }

    proc->counter++;
}

void EkrBattleWaitDragonIntro(struct ProcEkrBattle * proc)
{
    if (EkrDragonIntroDone(proc->anim) == TRUE)
        proc->proc_repeat_func = (ProcFunc)EkrBattleExecDragonIntro;
}

void EkrBattlePostDragonIntro(struct ProcEkrBattle * proc)
{
    if (gEkrInitialHitSide != gEkrInitPosReal)
    {
        NewEfxFarAttackWithDistance(MAIN_ANIM_FRONT(gEkrInitPosReal), -1);
        proc->timer = 0;
        proc->proc_repeat_func = (ProcFunc)EkrBattlePostDragonIntroDelay;
    }
    else
    {
        proc->proc_repeat_func = (ProcFunc)EkrBattleSetUnitFlashing;
    }
}

void EkrBattlePostDragonIntroDelay(struct ProcEkrBattle * proc)
{
    if (++proc->timer == 8)
        proc->proc_repeat_func = (ProcFunc)EkrBattleSetUnitFlashing;
}

void EkrBattleSetUnitFlashing(struct ProcEkrBattle * proc)
{
    NewEfxStatusUnit(MAIN_ANIM_FRONT(POS_L));
    NewEfxStatusUnit(MAIN_ANIM_FRONT(POS_R));
    NewEfxWeaponIcon(gEkrPairEffectiveAgainst[0], gEkrPairEffectiveAgainst[1]);

    if (gBattleSt.flags & BATTLE_FLAG_REFRESH)
        DisableEfxStatusUnits(MAIN_ANIM_FRONT(POS_L));

    NewEfxHpBarColorChange(MAIN_ANIM_FRONT(POS_L));
    proc->proc_repeat_func = (ProcFunc)EkrBattleExecTriangleAtk;
}

void EkrBattleExecTriangleAtk(struct ProcEkrBattle * proc)
{
    if (gpEkrTriangleUnits[0] != NULL)
    {
        NewEkrTriangle(MAIN_ANIM_FRONT(POS_R));
        proc->proc_repeat_func = (ProcFunc)EkrBattleWaitTriangleIdle;
    }
    else
    {
        proc->proc_repeat_func = (ProcFunc)EkrBattleTriggerNewRoundStart;
    }
}

void EkrBattleWaitTriangleIdle(struct ProcEkrBattle * proc)
{
    if (CheckEkrTriangleInvalid() == TRUE)
    {
        DebugEkrTriangleMsg();
        proc->timer = 0x1E;
        proc->proc_repeat_func = (ProcFunc)EkrBattleTriggerNewRoundStart;
    }
}

void EkrBattleTriggerNewRoundStart(struct ProcEkrBattle * proc)
{
    struct BaSprite * anim;

    if (++proc->timer <= 0x1E)
        return;

    if (gBanimValid[POS_L] == TRUE)
    {
        anim = MAIN_ANIM_FRONT(POS_L);
        anim->flags3 = ANIM_BIT3_NEW_ROUND_START;
        anim->flags2 |= ANIM_BIT2_STOP;

        anim = MAIN_ANIM_BACK(POS_L);
        anim->flags3 = ANIM_BIT3_NEW_ROUND_START;
        anim->flags2 |= ANIM_BIT2_STOP;
    }

    if (gBanimValid[POS_R] == TRUE)
    {
        anim = MAIN_ANIM_FRONT(POS_R);
        anim->flags3 = ANIM_BIT3_NEW_ROUND_START;
        anim->flags2 |= ANIM_BIT2_STOP;

        anim = MAIN_ANIM_BACK(POS_R);
        anim->flags3 = ANIM_BIT3_NEW_ROUND_START;
        anim->flags2 |= ANIM_BIT2_STOP;
    }

    gBanimDoneFlag[POS_L] = FALSE;
    gBanimDoneFlag[POS_R] = FALSE;
    proc->proc_repeat_func = (ProcFunc)EkrBattleReleaseStandingAnim;
}

void EkrBattleReleaseStandingAnim(struct ProcEkrBattle * proc)
{
    gAnimC01Blocking = FALSE;
    proc->proc_repeat_func = (ProcFunc)EkrBattleStartPromotion;
}

void EkrBattleStartPromotion(struct ProcEkrBattle * proc)
{
    if (gEkrDistanceType == EKR_DISTANCE_PROMOTION)
    {
        NewEkrClassChg(MAIN_ANIM_FRONT(POS_R));
        proc->proc_repeat_func = (ProcFunc)EkrBattleWaitPromotion;
    }
    else
    {
        proc->speedup = FALSE;
        proc->proc_repeat_func = (ProcFunc)EkrBattleInRound;
    }
}

void EkrBattleWaitPromotion(struct ProcEkrBattle * proc)
{
    if (EkrClasschgFinished() == TRUE)
    {
        EndEkrClasschg();
        gEkrPairExpGain[POS_L] = 1;
        proc->proc_repeat_func = (ProcFunc)EkrBattleExecEkrLvup;
    }
}

void EkrBattleInRound(struct ProcEkrBattle * proc)
{
    int ret = 0;
    if (gKeySt->held & KEY_BUTTON_B)
        proc->speedup = TRUE;

    switch (gEkrDistanceType) {
    case EKR_DISTANCE_CLOSE:
    case EKR_DISTANCE_FAR:
    case EKR_DISTANCE_FARFAR:
        if ((gBanimDoneFlag[0] + gBanimDoneFlag[1]) == 2)
        {
            if (GetBattleAnimArenaFlag() == FALSE)
            {
                ret = 1;
            }
            else
            {
                gEkrPairExpGain[0] = gpEkrBattleUnitLeft->exp_gain;
                gEkrPairExpGain[1] = gpEkrBattleUnitRight->exp_gain;

                if (gEkrGaugeHp[POS_L] == 0)
                {
                    ArenaSetResult(1);
                    ret = 1;
                }
                else if (gEkrGaugeHp[POS_R] == 0)
                {
                    ArenaSetResult(2);
                    gEkrPairExpGain[POS_R] = 0;
                    ret = 1;
                }
                else if (proc->speedup == TRUE)
                {
                    func_fe6_0804C56C();
                    ArenaSetResult(4);
                    gEkrPairExpGain[POS_R] = 0;
                    ret = 1;
                }
                else
                {
                    ArenaContinueBattle();
                    ParseBattleHitToBanimCmd();
                    BasInit();
                    UpdateBanimFrame();
                    InitMainAnims();

                    proc->timer = 0;
                    proc->proc_repeat_func = (ProcFunc)EkrBattleTriggerNewRoundStart;
                }
            }
        }
        break;

    case EKR_DISTANCE_MONOCOMBAT:
        if ((gBanimDoneFlag[0] + gBanimDoneFlag[1]) == 1)
            ret = 1;
        break;

    case EKR_DISTANCE_PROMOTION:
        ret = 1;
        break;
    }

    if (ret == 1)
        proc->proc_repeat_func = (ProcFunc)EkrBattleTriggerEnding;
}

void EkrBattleTriggerEnding(struct ProcEkrBattle * proc)
{
    proc->speedup = FALSE;
    proc->proc_repeat_func = (ProcFunc)EkrBattleWaitNamewinAppear;
}

void EkrBattleWaitNamewinAppear(struct ProcEkrBattle * proc)
{
    int pos, ret, _ret;

    if (gEkrHpBarCount != 0)
        return;

    if (gEkrDeadEventExist != 0)
        return;

    if (CheckEkrNamewinAppearUnexist() != TRUE)
        return;

    proc->timer = 0;
    proc->proc_repeat_func = (ProcFunc)EkrBattleWaitForPostBattleAct;

    if (GetEkrDragonStateTypeIdunn() != FALSE && *CheckEkrDragonFasten(MAIN_ANIM_FRONT(POS_L)) == TRUE)
        return;

    if (gEkrPairExpGain[POS_L] != 0)
        pos = POS_L;
    else
        pos = POS_R;

    if (pos != gEkrInitPosReal)
        proc->speedup = TRUE;

    if (proc->speedup == TRUE)
        NewEfxFarAttackWithDistance(MAIN_ANIM_FRONT(gEkrInitPosReal), -1);
}

void EkrBattleWaitForPostBattleAct(struct ProcEkrBattle * proc)
{
    if (++proc->timer < 0x1E)
        return;

    if (GetBanimLinkArenaFlag() != 1 && gEkrPairExpGain[POS_L] != -gEkrPairExpGain[POS_R])
        proc->proc_repeat_func = (ProcFunc)EkrBattleExecExpGain;
    else
        proc->proc_repeat_func = (ProcFunc)EkrBattleExecPopup;
}

void EkrBattleExecExpGain(struct ProcEkrBattle * proc)
{
    int i;
    u32 ret, val0, val1, val2, val3;

    u16 * buf = gEkrBarfxBuf;
    u16 * buf0 = gEkrBarfxBuf + 0x80;

    SetBgOffset(1, 0, 0);
    SetWinEnable(1, 0, 0);
    SetWin0Box(0, 0x94, 0xF0, 0x94);
    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(1, 0, 1, 1, 1);

    gDispIo.win_ct.win0_enable_blend = FALSE;
    gDispIo.win_ct.wout_enable_blend = FALSE;

    RegisterDataMove(Img_EkrExpBar, (void *)0x6002000, 0x300);
    EfxTmCpyBG(Tsa_EkrExpBar, gBg1Tm + TM_OFFSET(6, 17), 18, 3, 1, 0x100);
    CpuFastCopy(Pal_EkrExpBar, &PAL_BG_COLOR(1, 0), 0x20);
    EnableBgSync(BG1_SYNC_BIT);
    EnablePalSync();
    ret = GetEkrDragonStateType();

    switch (ret) {
    case 0:
        gDispIo.bg1_ct.priority = 0;
        gDispIo.bg0_ct.priority = 1;
        gDispIo.bg2_ct.priority = 2;
        gDispIo.bg3_ct.priority = 3;
        break;

    default:
        gDispIo.bg1_ct.priority = 0;
        gDispIo.bg0_ct.priority = 1;
        gDispIo.bg3_ct.priority = 2;
        gDispIo.bg2_ct.priority = 3;
        break;
    }

    EkrGauge_08043908(1);

    if (gEkrPairExpGain[POS_L] != 0)
        val0 = gEkrPairExpPrevious[POS_L];
    else
        val0 = gEkrPairExpPrevious[POS_R];

    val1 = DivRem(val0, 100);
    val2 = Div(val1, 10);
    val3 = val1 - val2 * 10;

    if (val2 == 0)
        val2 = 10;

    EkrModifyBarfx(gEkrBarfxBuf, val1);

    for (i = 0; i < 13; i++)
    {
        CpuFastCopy(&Img_EkrExpBarChange[buf[i] * 0x20], &buf0[0x10 * i], 0x20);
    }

    CpuFastCopy(&Img_BarNumfx[val2 * 0x20], &buf0[0xD0], 0x20);
    CpuFastCopy(&Img_BarNumfx[val3 * 0x20], &buf0[0xE0], 0x20);
    RegisterDataMove(buf0, (void *)0x60020E0, 0x1E0);

    proc->timer = 0;
    proc->proc_repeat_func = (ProcFunc)func_fe6_08043078;
}

void func_fe6_08043078(struct ProcEkrBattle * proc)
{
    if (++proc->timer > 12)
    {
        proc->timer = 0;
        proc->proc_repeat_func = (ProcFunc)EkrBattleExecExpBar;
    }
    else
    {
        SetWin0Box(0, -108 - proc->timer, 240, proc->timer - 108);
    }
}

void EkrBattleExecExpBar(struct ProcEkrBattle * proc)
{
    if (++proc->timer > 10)
    {
        if (gEkrPairExpGain[POS_L] != 0)
        {
            proc->timer = gEkrPairExpPrevious[POS_L];
            proc->end = gEkrPairExpPrevious[POS_L] + gEkrPairExpGain[POS_L];
        }
        else if (gEkrPairExpGain[POS_R] != 0)
        {
            proc->timer = gEkrPairExpPrevious[POS_R];
            proc->end = gEkrPairExpPrevious[POS_R] + gEkrPairExpGain[POS_R];
        }

        proc->proc_repeat_func = (ProcFunc)EkrBattleWaitExpBar;
        EfxPlaySE(0x74, 0x100);
        M4aPlayWithPostionCtrl(0x74, 0x78, 0);
    }
}

void EkrBattleWaitExpBar(struct ProcEkrBattle * proc)
{
    int i, val1, val2, val3;

    u16 *buf0;
    u16 *buf;
    buf = gEkrBarfxBuf;
    buf0 = gEkrBarfxBuf + 0x80;

    val1 = DivRem(proc->timer, 100);
    val2 = Div(val1, 10);
    val3 = val1 - val2 * 10;

    if (val2 == 0)
        val2 = 10;

    EkrModifyBarfx(buf, val1);

    for (i = 0; i < 13; i++)
    {
        CpuFastSet(&Img_EkrExpBarChange[buf[i] * 0x20], &buf0[0x10 * i], 8);
    }

    CpuFastSet(&Img_BarNumfx[val2 * 0x20], &buf0[0xD0], 8);
    CpuFastSet(&Img_BarNumfx[val3 * 0x20], &buf0[0xE0], 8);
    RegisterDataMove(buf0, (void *)0x60020E0, 0x1E0);

    if (++proc->timer > proc->end) {
        proc->timer = 0;
        proc->proc_repeat_func = (ProcFunc)EkrBattlePostExpBarDelay;
    }
}

void EkrBattlePostExpBarDelay(struct ProcEkrBattle * proc)
{
    if (proc->timer == 0)
        DoM4aSongNumStop(0x74);

    if (++proc->timer > 30)
    {
        proc->timer = 0;
        proc->proc_repeat_func = (ProcFunc)EkrBattleMergeLvupImgBG;
    }
}

void EkrBattleMergeLvupImgBG(struct ProcEkrBattle * proc)
{
    if (++proc->timer > 12)
    {
        proc->timer = 0;
        proc->proc_repeat_func = (ProcFunc)EkrBattleLvupHanlder;
    }
    else
    {
        SetWin0Box(0, proc->timer - 120, 240, -96 - proc->timer);
    }
}

void EkrBattleLvupHanlder(struct ProcEkrBattle *proc)
{
    int exp_gain;

    if (++proc->timer == 0x18) {
        if (gEkrPairExpGain[POS_L] != 0)
            exp_gain = gEkrPairExpPrevious[POS_L] + gEkrPairExpGain[POS_L];
        else
            exp_gain = gEkrPairExpPrevious[POS_R] + gEkrPairExpGain[POS_R];
        if (exp_gain >= 100)
            NewEkrLvlupFan();
    }

    if (proc->timer <= 0x28)
        return;

    SpellFx_ClearBG1();
    EkrGauge_08043908(0);

    switch (GetEkrDragonStateType()) {
    case 0:
        gDispIo.bg0_ct.priority = 0;
        gDispIo.bg1_ct.priority = 1;
        gDispIo.bg2_ct.priority = 2;
        gDispIo.bg3_ct.priority = 3;
        break;

    default:
        gDispIo.bg0_ct.priority = 0;
        gDispIo.bg1_ct.priority = 1;
        gDispIo.bg3_ct.priority = 2;
        gDispIo.bg2_ct.priority = 3;
    }

    SetWin0Box(0, 0, 0xF0, 0xA0);

    if (gEkrPairExpGain[POS_L] != 0)
        exp_gain = gEkrPairExpPrevious[POS_L] + gEkrPairExpGain[POS_L];
    else
        exp_gain = gEkrPairExpPrevious[POS_R] + gEkrPairExpGain[POS_R];

    if (exp_gain >= 100)
        proc->proc_repeat_func = (ProcFunc)EkrBattleExecEkrLvup;
    else
        proc->proc_repeat_func = (ProcFunc)EkrBattleExecPopup;
}

void EkrBattleExecEkrLvup(struct ProcEkrBattle * proc)
{
    struct BaSprite * anim;

    if (gEkrPairExpGain[POS_L] != 0)
        anim = MAIN_ANIM_FRONT(POS_L);
    else
        anim = MAIN_ANIM_FRONT(POS_R);

    NewEkrLevelup(anim);
    proc->proc_repeat_func = (ProcFunc)EkrBattleWaitLvup;
}

void EkrBattleWaitLvup(struct ProcEkrBattle * proc)
{
    if (CheckEkrLvupDone() == TRUE)
    {
        EndEkrLevelUp();
        proc->proc_repeat_func = (ProcFunc)EkrBattleExecPopup;
    }
}

void EkrBattleExecPopup(struct ProcEkrBattle *proc)
{
    NewEkrPopup();
    proc->proc_repeat_func = (ProcFunc)EkrBattleWaitPopup;
}

void EkrBattleWaitPopup(struct ProcEkrBattle *proc)
{
    if (CheckEkrPopupDone() == TRUE)
    {
        EndEkrPopup();
        proc->proc_repeat_func = (ProcFunc)EkrBattlePrepareEnding;
    }
}

void EkrBattlePrepareEnding(struct ProcEkrBattle * proc)
{
    EndEfxStatusUnits(MAIN_ANIM_FRONT(POS_L));
    EndEfxStatusUnits(MAIN_ANIM_FRONT(POS_R));
    EndProcEfxWeaponIcon();
    EndEfxHPBarColorChange();
    proc->side = gEkrInitialHitSide;
    proc->counter = 0;
    proc->proc_repeat_func = (ProcFunc)EkrBattleStartDragonEnding;
}

void EkrBattleStartDragonEnding(struct ProcEkrBattle * proc)
{
    int val;

    u32 conf = GetEkrDragonStateTypeGeneric();

    /* If both side is not the ekrdragon, get here */
    if (proc->counter == 2)
    {
        proc->proc_repeat_func = (ProcFunc)EkrBattlePostDragonEnding;
        return;
    }

    if (proc->side == POS_L)
    {
        proc->anim = MAIN_ANIM_FRONT(POS_L);
        if (conf & EDRAGON_TYPE_MANAKETE_L)
        {
            TriggerEkrDragonEnding(proc->anim);
            proc->proc_repeat_func = (ProcFunc)EkrBattleWaitDragonEnding;
        }
        if (conf & EDRAGON_TYPE_FAE_L)
        {
            TriggerEkrDragonEnding(proc->anim);
            proc->proc_repeat_func = (ProcFunc)EkrBattleWaitDragonEnding;
        }
        if (conf & EDRAGON_TYPE_IDUNN_L)
        {
            TriggerEkrDragonEnding(proc->anim);
            proc->proc_repeat_func = (ProcFunc)EkrBattleWaitDragonEnding;
        }
        proc->side = POS_R;
        proc->counter++;
    }
    else
    {
        proc->anim = MAIN_ANIM_FRONT(POS_R);
        if (conf & EDRAGON_TYPE_MANAKETE_R)
        {
            TriggerEkrDragonEnding(proc->anim);
            proc->proc_repeat_func = (ProcFunc)EkrBattleWaitDragonEnding;
        }
        if (conf & EDRAGON_TYPE_FAE_R)
        {
            TriggerEkrDragonEnding(proc->anim);
            proc->proc_repeat_func = (ProcFunc)EkrBattleWaitDragonEnding;
        }
        proc->side = POS_L;
        proc->counter++;
    }
}

void EkrBattleWaitDragonEnding(struct ProcEkrBattle * proc)
{
    if (CheckEkrDragonEndingDone(proc->anim) == TRUE)
        proc->proc_repeat_func = (ProcFunc)EkrBattleStartDragonEnding;
}

void EkrBattlePostDragonEnding(struct ProcEkrBattle * proc)
{
    gEkrBattleEndFlag = TRUE;

    if (gEkrDebugModeMaybe == FALSE)
    {
        NewEkrNamewinAppear(2, 7, 0);
        EkrRestoreBGM();
    }

    proc->proc_repeat_func = (ProcFunc)EkrBattlePostEndDelay;
}

void EkrBattlePostEndDelay(struct ProcEkrBattle * proc)
{
    return;
}
