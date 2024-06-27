#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "move.h"
#include "util.h"
#include "map.h"
#include "unit.h"
#include "hardware.h"
#include "constants/jids.h"

#include "banim_sprite.h"
#include "banim.h"
#include "banim_ekrbattle.h"
#include "banim_ekrdragon.h"

/**
 * Manakete
 */
struct ProcScr CONST_DATA ProcScr_EkrManakete[] =
{
    PROC_19,
    PROC_REPEAT(EkrManakete_BgFadeIn),
    PROC_REPEAT(func_fe6_08059144),
    PROC_REPEAT(EkrManakete_PauseOnStart),
    PROC_REPEAT(func_fe6_080591CC),
    PROC_REPEAT(func_fe6_080592D0),
    PROC_REPEAT(EkrManakete_UpdateBanimfx),
    PROC_REPEAT(EkrManakete_BlockingInBattle),
    PROC_REPEAT(EkrManakete_EndDeamon),
    PROC_REPEAT(EkrManakete_StartExit),
    PROC_REPEAT(func_fe6_0805946C),
    PROC_REPEAT(func_fe6_080594CC),
    PROC_REPEAT(func_fe6_08059578),
    PROC_REPEAT(func_fe6_080595EC),
    PROC_REPEAT(EkrManakete_ReloadBg),
    PROC_REPEAT(EkrManakete_TriggerEnding),
    PROC_END,
};

void NewEkrManakete(struct BaSprite * anim)
{
    struct ProcEkrDragon * proc;

    EkrDragonProcs[GetAnimPosition(anim)] = proc = SpawnProc(ProcScr_EkrManakete, PROC_TREE_3);
    gEkrDragonState[GetAnimPosition(anim)] = DRAGON_STATE_1;

    proc->anim = anim;
    proc->timer = 0;
}

void EkrManakete_BgFadeIn(struct ProcEkrDragon * proc)
{
    EfxChapterMapFadeOUT(Interpolate(INTERPOLATE_SQUARE, 4, 0x10, proc->timer, 8));

    if (++proc->timer == 0x9)
    {
        proc->timer = 0;
        NewEfxFlashUnit(proc->anim, 0, 10, 1);
        Proc_Break(proc);
    }
}

void func_fe6_08059144(struct ProcEkrDragon * proc)
{
    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        proc->timer = 60;
        Proc_Break(proc);
        return;
    }

    if (++proc->timer == 11)
    {
        proc->anim->flags |= BAS_BIT_HIDDEN;
        StartManaketeTransferAnim(proc->anim, 0);
        EfxPlaySE(0xE8, 0x100);
        M4aPlayWithPostionCtrl(0x0E8, proc->anim->xPosition, 1);
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void EkrManakete_PauseOnStart(struct ProcEkrDragon * proc)
{
    if (++proc->timer == 61)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void func_fe6_080591CC(struct ProcEkrDragon * proc)
{
    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        ResetDragonAnimfx();
        TmFill(gBg3Tm, 0xF000);
        SetBgOffset(3, 0, 0x10);
        EnableBgSync(BG3_SYNC_BIT);

        gDispIo.bg0_ct.priority = 0;
        gDispIo.bg1_ct.priority = 1;
        gDispIo.bg3_ct.priority = 2;
        gDispIo.bg2_ct.priority = 3;

        SetDragonBasLayer(1);
        proc->timer = 0;
        Proc_Break(proc);
        return;
    }

    if (proc->timer == 0)
    {
        ResetDragonAnimfx();
        TmFill(gBg3Tm, 0xF000);
        SetBgOffset(3, 0, 0x10);

        gDispIo.bg0_ct.priority = 0;
        gDispIo.bg1_ct.priority = 1;
        gDispIo.bg3_ct.priority = 2;
        gDispIo.bg2_ct.priority = 3;

        EnableBgSync(BG3_SYNC_BIT);
        SetDragonBasLayer(1);
        PutManaketeBodyPalette(proc);
        PutManaketeBodyIntro2(proc);
    }

    if (++proc->timer == 6)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void func_fe6_080592D0(struct ProcEkrDragon * proc)
{
    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        proc->timer = 0;
        Proc_Break(proc);
        return;
    }

    if (proc->timer == 0)
    {
        PutManaketeBodyIntro1(proc);
        NewEfxQuake(5);
    }

    if (++proc->timer == 11)
    {
        proc->timer = 0;
        NewEkrDragonBark(proc->anim);
        Proc_Break(proc);
    }
}

void EkrManakete_UpdateBanimfx(struct ProcEkrDragon * proc)
{
    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        PutManaketeBodyStd(proc);
        NewEkrManaketeDeamon(proc->anim);
        proc->anim->flags &= ~BAS_BIT_HIDDEN;
        EkrPrepareBanimfx(proc->anim, 0x55);
        gEkrDragonIntroDone[GetAnimPosition(proc->anim)] = TRUE;
        proc->timer = 0;
        Proc_Break(proc);
        return;
    }

    if (proc->timer == 0)
    {
        PutManaketeBodyStd(proc);
        NewEkrManaketeDeamon(proc->anim);
        proc->anim->flags &= ~BAS_BIT_HIDDEN;
        EkrPrepareBanimfx(proc->anim, 0x55);
    }

    if (++proc->timer == 61)
    {
        gEkrDragonIntroDone[GetAnimPosition(proc->anim)] = TRUE;
        Proc_Break(proc);
    }
}

void EkrManakete_BlockingInBattle(struct ProcEkrDragon * proc)
{
    if (gEkrDragonState[GetAnimPosition(proc->anim)] == DRAGON_STATE_ENDING)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void EkrManakete_EndDeamon(struct ProcEkrDragon * proc)
{
    EndEkrDragonDaemon(proc->anim);
    Proc_Break(proc);
}

void EkrManakete_StartExit(struct ProcEkrDragon * proc)
{
    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        proc->timer = 0;
        Proc_Break(proc);
        return;
    }

    if (proc->timer == 0)
    {
        PutManaketeBodyIntro1(proc);
        proc->anim->flags |= BAS_BIT_HIDDEN;
    }

    if (++proc->timer == 6)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void func_fe6_0805946C(struct ProcEkrDragon * proc)
{
    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        ResetDragonAnimfx();
        proc->timer = 0;
        Proc_Break(proc);
        return;
    }

    if (proc->timer == 0)
    {
        ResetDragonAnimfx();
        EfxChapterMapFadeOUT(0x10);
        PutManaketeBodyPalette(proc);
        PutManaketeBodyIntro2(proc);
    }

    if (++proc->timer == 6)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void func_fe6_080594CC(struct ProcEkrDragon * proc)
{
    if (proc->timer == 0 && CheckSkipDragonTransfer(proc->anim) == FALSE)
    {
        StartManaketeTransferAnim(proc->anim, 1);
        EfxPlaySE(0xE9, 0x100);
        M4aPlayWithPostionCtrl(0xE9, proc->anim->xPosition, 1);
    }

    if (++proc->timer == 6)
    {
        TmFill(gBg3Tm, 0xF000);
        SetBgOffset(3, 0, 0);
        EnableBgSync(BG3_SYNC_BIT);

        gDispIo.bg0_ct.priority = 0;
        gDispIo.bg1_ct.priority = 1;
        gDispIo.bg2_ct.priority = 2;
        gDispIo.bg3_ct.priority = 3;

        SetDragonBasLayer(2);
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void func_fe6_08059578(struct ProcEkrDragon * proc)
{
    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        proc->timer = 80;
        Proc_Break(proc);
        return;
    }

    if (++proc->timer == 61)
    {
        proc->anim->flags &= ~BAS_BIT_HIDDEN;
        EkrPrepareBanimfx(proc->anim, gBanimIdx_bak[GetAnimPosition(proc->anim)]);
        NewEfxFlashUnit(proc->anim, 0, 10, 1);
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void func_fe6_080595EC(struct ProcEkrDragon * proc)
{
    if (++proc->timer == 81)
    {
        EfxChapterMapFadeOUT(0x10);
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void EkrManakete_ReloadBg(struct ProcEkrDragon * proc)
{
    if (proc->timer == 0)
    {
        ApplyChapterMapGraphics(gPlaySt.chapter);
        RenderMap();
    }

    EfxChapterMapFadeOUT(Interpolate(INTERPOLATE_RSQUARE, 0x10, 4, proc->timer, 8));

    if (++proc->timer == 0x9)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void EkrManakete_TriggerEnding(struct ProcEkrDragon * proc)
{
    gEkrDragonIntroDone[GetAnimPosition(proc->anim)] = 2;
    Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrManaketeEnterfx[] =
{
    PROC_19,
    PROC_ONEND(EkrManakete_OnEnd),
    PROC_REPEAT(EkrManaketeEnter1),
    PROC_SLEEP(20),
    PROC_REPEAT(EkrManaketeEnter2),
    PROC_SLEEP(26),
    PROC_REPEAT(EkrManaketeEnter3),
    PROC_SLEEP(9),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EkrManaketeExitfx[] =
{
    PROC_19,
    PROC_ONEND(EkrManakete_OnEnd),
    PROC_REPEAT(EkrManaketeExit1),
    PROC_SLEEP(9),
    PROC_REPEAT(EkrManaketeExit2),
    PROC_SLEEP(26),
    PROC_REPEAT(EkrManaketeExit3),
    PROC_SLEEP(20),
    PROC_END,
};

void StartManaketeTransferAnim(struct BaSprite * anim, int type)
{
    struct BaSprite * animfx;
    struct ProcEkrManaketefx * proc;

    gEfxBgSemaphore++;

    if (type == 0)
        proc = SpawnProc(ProcScr_EkrManaketeEnterfx, PROC_TREE_3);
    else
        proc = SpawnProc(ProcScr_EkrManaketeExitfx, PROC_TREE_3);

    proc->anim = anim;
    proc->animfx = animfx = EfxCreateFrontAnim(anim, AnimScr_ManaketeFlame, AnimScr_ManaketeFlame, AnimScr_ManaketeFlame, AnimScr_ManaketeFlame);
    animfx->oam2 = OAM2_CHR(0x200) + OAM2_LAYER(1) + OAM2_PAL(2);
    animfx->oam01 |= OAM1_AFFINE_ID(2);
    animfx->yPosition += 8;

    proc->timer = 0;
    SpellFx_SetSomeColorEffect();

    SetBlendTargetA(0, 0, 0, 0, 0);
    SetBlendTargetB(0, 1, 1, 1, 0);

    SpellFx_RegisterObjPal(Pal_ManaketeBodyStd, 0x20);
    anim->flags |= BAS_BIT_FROZEN;
}

void EkrManakete_OnEnd(struct ProcEkrManaketefx * proc)
{
    struct BaSprite * anim = proc->anim;

    gEfxBgSemaphore--;
    BasRemove(proc->animfx);
    anim->flags &= ~BAS_BIT_FROZEN;
}

void EkrManaketeEnter1(struct ProcEkrManaketefx * proc)
{
    struct BaSprite * animfx = proc->animfx;
    const void * src;
    void * buf, * dst;

    animfx->script = AnimScr_ManaketeEnter1;
    animfx->scrCur = AnimScr_ManaketeEnter1;
    animfx->timer = 0;

    src = Img_ManaketeObjfx1;
    dst = OBJ_VRAM0 + 0x4000;
    buf = gBuf_Banim;

    LZ77UnCompWram(src, buf);
    RegisterDataMove(buf, dst, 0x2000);
    Proc_Break(proc);
}

void EkrManaketeEnter2(struct ProcEkrManaketefx * proc)
{
    struct BaSprite * animfx = proc->animfx;
    const void * src;
    void * buf, * dst;

    animfx->script = AnimScr_ManaketeEnter2;
    animfx->scrCur = AnimScr_ManaketeEnter2;
    animfx->timer = 0;

    src = Img_ManaketeObjfx2;
    dst = OBJ_VRAM0 + 0x4000;
    buf = gBuf_Banim;

    LZ77UnCompWram(src, buf);
    RegisterDataMove(buf, dst, 0x2000);
    Proc_Break(proc);
}

void EkrManaketeEnter3(struct ProcEkrManaketefx * proc)
{
    struct BaSprite * animfx = proc->animfx;
    const void * src;
    void * buf, * dst;

    animfx->script = AnimScr_ManaketeEnter3;
    animfx->scrCur = AnimScr_ManaketeEnter3;
    animfx->timer = 0;

    src = Img_ManaketeObjfx3;
    dst = OBJ_VRAM0 + 0x4000;
    buf = gBuf_Banim;

    LZ77UnCompWram(src, buf);
    RegisterDataMove(buf, dst, 0x2000);
    Proc_Break(proc);
}

void EkrManaketeExit3(struct ProcEkrManaketefx * proc)
{
    struct BaSprite * animfx = proc->animfx;
    const void * src;
    void * buf, * dst;

    animfx->script = AnimScr_ManaketeExit3;
    animfx->scrCur = AnimScr_ManaketeExit3;
    animfx->timer = 0;

    src = Img_ManaketeObjfx1;
    dst = OBJ_VRAM0 + 0x4000;
    buf = gBuf_Banim;

    LZ77UnCompWram(src, buf);
    RegisterDataMove(buf, dst, 0x2000);
    Proc_Break(proc);
}

void EkrManaketeExit2(struct ProcEkrManaketefx * proc)
{
    struct BaSprite * animfx = proc->animfx;
    const void * src;
    void * buf, * dst;

    animfx->script = AnimScr_ManaketeExit2;
    animfx->scrCur = AnimScr_ManaketeExit2;
    animfx->timer = 0;

    src = Img_ManaketeObjfx2;
    dst = OBJ_VRAM0 + 0x4000;
    buf = gBuf_Banim;

    LZ77UnCompWram(src, buf);
    RegisterDataMove(buf, dst, 0x2000);
    Proc_Break(proc);
}

void EkrManaketeExit1(struct ProcEkrManaketefx * proc)
{
    struct BaSprite * animfx = proc->animfx;
    const void * src;
    void * buf, * dst;

    animfx->script = AnimScr_ManaketeExit1;
    animfx->scrCur = AnimScr_ManaketeExit1;
    animfx->timer = 0;

    src = Img_ManaketeObjfx3;
    dst = OBJ_VRAM0 + 0x4000;
    buf = gBuf_Banim;

    LZ77UnCompWram(src, buf);
    RegisterDataMove(buf, dst, 0x2000);
    Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrManaketefx[] =
{
    PROC_19,
    PROC_REPEAT(EkrManaketeDeamon_Loop),
    PROC_END,
};

void NewEkrManaketeDeamon(struct BaSprite * anim)
{
    struct ProcEkrDragonDeamon * proc;

    gEkrDragonDeamonProcs[GetAnimPosition(anim)] = proc = SpawnProc(ProcScr_EkrManaketefx, PROC_TREE_4);
    proc->fxtype = 0;
    proc->anim = anim;
    proc->round_cur = anim->currentRoundType;
}

void EkrManaketeDeamon_Loop(struct ProcEkrDragonDeamon * proc)
{
    i16 ret;

    if (GetUnitEfxDebuff(proc->anim) != UNIT_STATUS_NONE)
        return;

    switch (proc->fxtype) {
    case 0:
        proc->timer = 0;
        proc->frame = 0;
        proc->conf = FrameLut_EkrManaketefxNormalAttack;
        proc->pal = Pal_EkrManaketefx;
        proc->fxtype = 2;
        break;

    /* critial attack */
    case 1:
        proc->timer = 0;
        proc->frame = 0;
        proc->conf = FrameLut_EkrManaketefxCriticalAttack;
        proc->pal = Pal_EkrManaketefx;
        proc->fxtype = 2;
        break;

    default:
        break;
    }

    ret = EfxAdvanceFrameLut((void *)&proc->timer, (void *)&proc->frame, (const i16 *)proc->conf);
    if (ret >= 0)
    {
        const u16 * pal = proc->pal;
        CpuFastCopy(pal + PAL_OFFSET(ret), gPal + PAL_OFFSET(6), 0x20);
        EnablePalSync();
    }
    else if (ret == -1)
    {
        proc->fxtype = 0;
    }

    if (proc->anim->currentRoundType != proc->round_cur)
    {
        register int rtype asm("r0");
        rtype = proc->anim->currentRoundType;

        /* Config round switch */
        switch (rtype) {
        case ANIM_ROUND_CRIT_CLOSE:
        case ANIM_ROUND_CRIT_FAR:
            proc->fxtype = 1;
            break;

        default:
            break;
        }
    }
    proc->round_cur = proc->anim->currentRoundType;
}
