#include "prelude.h"
#include "proc.h"
#include "util.h"
#include "hardware.h"

#include "banim_sprite.h"
#include "banim.h"
#include "banim_data.h"
#include "banim_ekrbattle.h"
#include "banim_ekrdragon.h"

struct ProcScr CONST_DATA ProcScr_EkrDragonIdunn[] =
{
    PROC_19,
    PROC_REPEAT(EkrIdunn_BgFadeIn),
    PROC_REPEAT(EkrIdunn_InitBanimfx),
    PROC_REPEAT(EkrIdunn_InitBodyfx),
    PROC_REPEAT(EkrIdunn_PreMainBodyIntro),
    PROC_REPEAT(EkrIdunn_InitIntroBodyPosition),
    PROC_REPEAT(func_fe6_0805A0BC),
    PROC_REPEAT(EkrIdunn_BodyFallInAndTriggerBattleStart),
    PROC_REPEAT(EkrIdunn_BlockingInBattle),
    PROC_REPEAT(func_fe6_0805A270),
    PROC_REPEAT(func_fe6_0805A2BC),
    PROC_REPEAT(func_fe6_0805A35C),
    PROC_REPEAT(func_fe6_0805A394),
    PROC_REPEAT(func_fe6_0805A3EC),
    PROC_END,
};

void NewEkrDragonIdunn(struct BaSprite * anim)
{
    struct ProcEkrDragon * proc;

    EkrDragonProcs[GetAnimPosition(anim)] = proc = SpawnProc(ProcScr_EkrDragonIdunn, PROC_TREE_3);;
    gEkrDragonState[GetAnimPosition(anim)] = DRAGON_STATE_1;

    proc->anim = anim;
    proc->timer = 0;
}

void EkrIdunn_BgFadeIn(struct ProcEkrDragon * proc)
{
    EfxChapterMapFadeOUT(Interpolate(INTERPOLATE_SQUARE, 4, 0x10, proc->timer, 8));

    if (++proc->timer == 0x9)
        Proc_Break(proc);
}

void EkrIdunn_InitBanimfx(struct ProcEkrDragon * proc)
{
    struct BaSprite * animf, * animr;

    EkrPrepareBanimfx(proc->anim, 0x74);

    animf = MAIN_ANIM_FRONT(POS_L);
    animr = MAIN_ANIM_BACK(POS_L);

    gEkrXPosReal[POS_L] = gEkrXPosBase[POS_L] + 0x54;
    animf->xPosition = gEkrXPosBase[POS_L] + 0x54 - gEkrBgPosition;
    animr->xPosition = gEkrXPosReal[POS_L] - gEkrBgPosition;

    if (CheckSkipDragonTransfer(proc->anim) != TRUE)
    {
        gEkrDragonDeamonProcs[0] = NewEkrIdunnIntroDeamon1(proc->anim);
        gEkrDragonDeamonProcs[0]->x_hi = gEkrXPosBase[POS_L] - (gEkrBgPosition - 0x4E);
        gEkrDragonDeamonProcs[0]->y_hi = 0x50;
    }
    proc->timer = 0;
    Proc_Break(proc);
}

void EkrIdunn_InitBodyfx(struct ProcEkrDragon * proc)
{
    LZ77UnCompVram(Img_EkrIdunn_081C1C94, (void *)BG_VRAM + 0x8000);
    LZ77UnCompWram(Tsa_EkrIdunn_081C5AAC, gEkrTsaBuffer);

    EfxTmFill(0x001F001F);
    TmFill(gBg3Tm, 0x1F);
    EnableBgSync(BG3_SYNC_BIT);

    CpuFastCopy(Pal_081C4DE8, gPal + BGPAL_OFFSET(6), 0x20);

    CpuFastCopy(gPal + BGPAL_OFFSET(6), gEkrBgPaletteBackup1, 0x20);
    CpuFastCopy(gPal + OBPAL_OFFSET(7), gEkrBgPaletteBackup2, 0x20);
    CpuFastCopy(gPal + BGPAL_OFFSET(4), gEkrBgPaletteBackup3, 0x40);

    CpuFastFill16(0, gPal + BGPAL_OFFSET(6), 0x20);
    EnablePalSync();
    Proc_Break(proc);
}

void EkrIdunn_PreMainBodyIntro(struct ProcEkrDragon * proc)
{
    struct ProcEkrDragonDeamon * procfx = gEkrDragonDeamonProcs[0];

    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        Proc_Break(proc);
        return;
    }

    procfx->x = Interpolate(
        INTERPOLATE_SQUARE,
        procfx->x_hi + 0x30,
        procfx->x_hi,
        proc->timer,
        16);

    procfx->y = Interpolate(
        INTERPOLATE_SQUARE,
        procfx->y_hi - 0x80,
        procfx->y_hi,
        proc->timer,
        16);

    if (++proc->timer == 0x11)
    {

        CpuFastCopy(gEkrBgPaletteBackup1, gPal + BGPAL_OFFSET(6), 0x20);
        CpuFastCopy(gEkrBgPaletteBackup2, gPal + OBPAL_OFFSET(7), 0x20);
        func_fe6_08058FA8(Tsa_EkrIdunn_081C4E28);
        NewEfxWhiteOUT(proc->anim, 3, 100);
        EfxPlaySE(0x13F, 0x100);
        M4aPlayWithPostionCtrl(0x13F, proc->anim->xPosition, 1);

        /* ? */
        procfx = NewEfxQuake(6);
        procfx->y_hi = 0x72;

        Proc_Break(proc);
    }
}

void EkrIdunn_InitIntroBodyPosition(struct ProcEkrDragon * proc)
{
    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        proc->procfx = NewEfxIdunnIntro(proc->anim);
        Proc_Break(proc);
        return;
    }

    gEkrDragonDeamonProcs[0]->x = gEkrXPosBase[POS_L] - (gEkrBgPosition - 0x4E);
    gEkrDragonDeamonProcs[0]->y = 0x50;

    if (gEkrBg2QuakeVec.x != 0x7FFF)
    {
        gEkrDragonDeamonProcs[0]->x += gEkrBg2QuakeVec.x;
        gEkrDragonDeamonProcs[0]->y += gEkrBg2QuakeVec.y;
    }

    if (gEfxQuakeExist == 0)
    {
        SetBgOffset(3, 0, 0x82);
        gEkrDragonDeamonProcs[0]->x = gEkrXPosBase[POS_L] - (gEkrBgPosition - 0x4E);
        gEkrDragonDeamonProcs[0]->y = 0x50;
        proc->procfx = NewEfxIdunnIntro(proc->anim);
        Proc_Break(proc);
    }
}

void func_fe6_0805A0BC(struct ProcEkrDragon * proc)
{
    int x, _0;
    u8 *pflag = &proc->procfx->flag;

    if (*pflag != 1)
        return;

    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        Proc_Break(proc);
        return;
    }

    _0 = 0;
    *pflag = 2;
    proc->timer = _0;
    proc->procfx = NewEfxIdunnMain(proc->anim);

    gEkrDragonDeamonProcs[1] = NewEkrIdunnIntroDeamon2(proc->anim);

    if (gEkrDistanceType == EKR_DISTANCE_CLOSE)
        gEkrDragonDeamonProcs[1]->x = 0x54;
    else
        gEkrDragonDeamonProcs[1]->x = 0x34;

    gEkrDragonDeamonProcs[1]->y = -11;

    EfxPlaySE(0x144, 0x100);
    Proc_Break(proc);
}

void EkrIdunn_BodyFallInAndTriggerBattleStart(struct ProcEkrDragon * proc)
{
    int ret;
    struct ProcEkrDragonIntroFx * procf = proc->procfx;
    struct ProcEkrDragonDeamon * procd1 = gEkrDragonDeamonProcs[0];
    struct ProcEkrDragonDeamon * procd2 = gEkrDragonDeamonProcs[1];

    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        SetAnimStateUnHidden(GetAnimPosition(proc->anim));
        CpuFastCopy(gEkrBgPaletteBackup1, gPal + PAL_OFFSET(6), 0x20);
        gEkrDragonIntroDone[GetAnimPosition(proc->anim)] = TRUE;
        NewEkrIdunnBodyFlashing(proc->anim);
        Proc_Break(proc);
        return;
    }

    ret = Interpolate(INTERPOLATE_LINEAR, 0, 0x72, proc->timer, 0x120);
    procf->y = -ret + 0x82;
    procd1->y = ret + 0x50;
    procd2->y = ret - 11;

    if (++proc->timer == 0xFF)
    {
        procf->flag = 1;
        gEkrDragonDeamonProcs[0]->fxtype = 1;
        gEkrDragonDeamonProcs[1]->fxtype = 1;
        SetAnimStateUnHidden(GetAnimPosition(proc->anim));
        gEkrDragonIntroDone[GetAnimPosition(proc->anim)] = TRUE;
        NewEkrIdunnBodyFlashing(proc->anim);
        Proc_Break(proc);
        return;
    }
}

void EkrIdunn_BlockingInBattle(struct ProcEkrDragon * proc)
{
    if (gEkrDragonState[GetAnimPosition(proc->anim)] != DRAGON_STATE_ENDING)
        return;

    EndEkrIdunnBodyFlashing();

    if (gEkrDragonFastenConf[GetAnimPosition(proc->anim)] == 1)
        proc->procfx = NewEkrIdunnExitAnim1(proc->anim);

    Proc_Break(proc);
}

void func_fe6_0805A270(struct ProcEkrDragon * proc)
{
    struct ProcEkrDragonIntroFx * procfx = proc->procfx;
    if (gEkrDragonFastenConf[GetAnimPosition(proc->anim)] == 0)
    {
        proc->procfx = NewEkrIdunnExitAnim2(proc->anim, 1, 0x20);
        Proc_Break(proc);
        return;
    }

    if (procfx->flag == 1)
    {
        procfx->flag = 2;
        Proc_Break(proc);
    }
}
