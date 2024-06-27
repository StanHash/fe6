#include "prelude.h"
#include "proc.h"
#include "hardware.h"

#include "banim_sprite.h"
#include "banim.h"
#include "banim_data.h"
#include "banim_ekrbattle.h"
#include "banim_ekrdragon.h"

struct ProcScr CONST_DATA ProcScr_EkrDragonFae[] =
{
    PROC_19,
    PROC_REPEAT(EkrFae_PauseOnStart),
    PROC_REPEAT(EkrFae_StartTransfer),
    PROC_REPEAT(EkrFae_UpdateBanimfx),
    PROC_REPEAT(EkrFae_WaitBattleDone),
    PROC_REPEAT(EkrFae_ReloadBanimBak),
    PROC_REPEAT(EkrFae_PauseOnEnd),
    PROC_REPEAT(EkrFae_TriggerEnding),
    PROC_END,
};

void NewEkrDragonFae(struct BaSprite * anim)
{
    struct ProcEkrDragon * proc;

    EkrDragonProcs[GetAnimPosition(anim)] = proc = SpawnProc(ProcScr_EkrDragonFae, PROC_TREE_3);;
    gEkrDragonState[GetAnimPosition(anim)] = DRAGON_STATE_1;

    proc->anim = anim;

    if (CheckSkipDragonTransfer(anim) == TRUE)
        proc->timer = 60;
    else
        proc->timer = 0;
}

void EkrFae_PauseOnStart(struct ProcEkrDragon * proc)
{
    if (++proc->timer == 61)
        Proc_Break(proc);
}

void EkrFae_StartTransfer(struct ProcEkrDragon * proc)
{
    int pos, pal_off;
    u16 * pal_dst;
    struct BattleAnim * banim;
    int faction_pal = gBanimFactionPal[GetAnimPosition(proc->anim)];

    banim = &banim_data[0x5B];
    LZ77UnCompWram(banim->pal, gPal_Banim);

    pos = GetAnimPosition(proc->anim);
    pal_off = (BGPAL_OFFSET(0x1A));
    if (pos == POS_L)
        pal_off = (BGPAL_OFFSET(0x18));

    CpuFastCopy(
        gPal_Banim + BGPAL_OFFSET(faction_pal),
        gPal + pal_off,
        0x20);

    EnablePalSync();

    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        Proc_Break(proc);
        return;
    }
    else
    {
        proc->timer = 0;
        EkrPrepareBanimfx(proc->anim, 0x6B); /* Fae tranfer anim */
        SwitchAISFrameDataFromBARoundType(proc->anim, BANIM_MODE_NORMAL_ATK);
        Proc_Break(proc);
    }
}

void EkrFae_UpdateBanimfx(struct ProcEkrDragon * proc)
{
    const u8 * scr;

    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        EkrPrepareBanimfx(proc->anim, 0x5B); /* Fae dragon anim */
        gEkrDragonIntroDone[GetAnimPosition(proc->anim)] = TRUE;
        Proc_Break(proc);
        return;
    }

    if (++proc->timer == 26)
    {
        EfxPlaySE(0xDC, 0x100);
        M4aPlayWithPostionCtrl(0xDC, proc->anim->xPosition, 1);
    }

    scr = (const u8 *)proc->anim->scrCur;
    if ((scr[3] & 0x3F) == BAS_INS_KIND_STOP)
    {
        EfxPlaySE(0xDE, 0x100);
        M4aPlayWithPostionCtrl(0xDE, proc->anim->xPosition, 1);
        EkrPrepareBanimfx(proc->anim, 0x5B); /* Fae dragon anim */
        gEkrDragonIntroDone[GetAnimPosition(proc->anim)] = TRUE;
        Proc_Break(proc);
        return;
    }
}

void EkrFae_WaitBattleDone(struct ProcEkrDragon * proc)
{
    if (gEkrDragonState[GetAnimPosition(proc->anim)] != DRAGON_STATE_ENDING)
        return;

    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        Proc_Break(proc);
        return;
    }

    EfxPlaySE(0xDD, 0x100);
    M4aPlayWithPostionCtrl(0xDD, proc->anim->xPosition, 1);
    EkrPrepareBanimfx(proc->anim, 0x6C); /* Fae dragon anim for enemy */
    SwitchAISFrameDataFromBARoundType(proc->anim, BANIM_MODE_NORMAL_ATK);
    StartEkrFaeTransferfx(proc->anim);
    Proc_Break(proc);
}

void EkrFae_ReloadBanimBak(struct ProcEkrDragon * proc)
{
    const u8 * scr;

    if (CheckSkipDragonTransfer(proc->anim) == TRUE)
    {
        proc->timer = 60;
        Proc_Break(proc);
        return;
    }

    scr = (const u8 *)proc->anim->scrCur;
    if ((scr[3] & 0x3F) == BAS_INS_KIND_STOP)
    {
        EkrPrepareBanimfx(proc->anim, gBanimIdx_bak[GetAnimPosition(proc->anim)]);
        proc->timer = 0;
        Proc_Break(proc);
        return;
    }
}

void EkrFae_PauseOnEnd(struct ProcEkrDragon * proc)
{
    if (++proc->timer == 61)
        Proc_Break(proc);
}

void EkrFae_TriggerEnding(struct ProcEkrDragon * proc)
{
    gEkrDragonIntroDone[GetAnimPosition(proc->anim)] = 2;
    Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrFaefx[] =
{
    PROC_19,
    PROC_REPEAT(EkrFaeTransferBackfx_Loop),
    PROC_END,
};

const u16 * CONST_DATA TsaLut_EkrFaefx[] =
{
    Tsa_EkrFaefx1,
    Tsa_EkrFaefx2,
    Tsa_EkrFaefx3,
    Tsa_EkrFaefx4,
    Tsa_EkrFaefx5,
    Tsa_EkrFaefx6,
    Tsa_EkrFaefx7,
    Tsa_EkrFaefx8,
    Tsa_EkrFaefx9,
    Tsa_EkrFaefx10,
    Tsa_EkrFaefx11,
    Tsa_EkrFaefx12,
};

void StartEkrFaeTransferfx(struct BaSprite * anim)
{
    struct ProcEkrFaefx * proc;

    gEfxBgSemaphore++;
    proc = SpawnProc(ProcScr_EkrFaefx, PROC_TREE_3);

    proc->anim = anim;
    proc->timer = 0;
    proc->frame = 0;

    proc->frame_config = FrameLut_EkrFaefx;
    proc->tsal = TsaLut_EkrFaefx;
    proc->tsar = TsaLut_EkrFaefx;

    SpellFx_RegisterBgGfx(Img_EkrFaefx, 0x2000);
    SpellFx_RegisterBgPal(Pal_EkrFaefx, 0x20);
    SpellFx_SetSomeColorEffect();

    if (gEkrDistanceType != EKR_DISTANCE_CLOSE)
    {
        if (GetAnimPosition(proc->anim) == POS_L)
            SetBgOffset(1, 0x18, 0);
        else
            SetBgOffset(1, 0xE8, 0);
    }
    else
        SetBgOffset(1, 0, 0);


    SetBlendAlpha(0x10, 0);
}

void EkrFaeTransferBackfx_Loop(struct ProcEkrFaefx * proc)
{
    int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);
    if (ret >= 0)
    {
        const u16 ** tsaL = proc->tsal;
        const u16 ** tsaR = proc->tsar;
        SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));
    }
    else if (ret == -1)
    {
        SpellFx_ClearBG1();
        gEfxBgSemaphore--;
        SpellFx_ClearColorEffects();
        Proc_Break(proc);
    }
}
