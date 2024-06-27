#include "prelude.h"
#include "eventinfo.h"
#include "proc.h"
#include "hardware.h"
#include "banim.h"
#include "banim_ekrbattle.h"
#include "banim_ekrdragon.h"
#include "constants/pids.h"

struct ProcScr CONST_DATA ProcScr_EfxHpBar[] =
{
    PROC_19,
    PROC_REPEAT(EfxHpBar_DeclineToDeath),
    PROC_REPEAT(EfxHpBar_MoveCameraOnEnd),
    PROC_REPEAT(EfxHpBar_WaitCameraMove),
    PROC_END,
};

int CheckEkrHitDone(void)
{
    if (gEkrHpBarCount == 0 && gEfxSpellAnimExists == 0)
        return TRUE;
    else
        return FALSE;
}

i16 CheckEkrHitNow(int pos)
{
    return gEkrHitNow[pos];
}

void NewEfxHpBar(struct BaSprite * anim)
{
    struct ProcEfxHpBar * proc;
    i16 off_this, off_next;

    if (gEkrHpBarCount != 0)
        return;

    gEkrHpBarCount = 1;

    proc = SpawnProc(ProcScr_EfxHpBar, PROC_TREE_3);
    proc->anim_this = anim;

    if (GetAnimPosition(anim) == POS_L)
    {
        proc->anim_main_other = MAIN_ANIM_FRONT(POS_R);
        proc->anim_main_this  = MAIN_ANIM_FRONT(POS_L);
    }
    else
    {
        proc->anim_main_other = MAIN_ANIM_FRONT(POS_L);
        proc->anim_main_this  = MAIN_ANIM_FRONT(POS_R);
    }

    off_this = gEfxHpLutOff[GetAnimPosition(proc->anim_main_this)];
    off_next = off_this + 1;

    proc->this = GetEfxHp(off_this * 2 + GetAnimPosition(proc->anim_main_this));
    proc->next = GetEfxHp(off_next * 2 + GetAnimPosition(proc->anim_main_this));

    if (proc->this > proc->next)
        proc->diff = -1;
    else
        proc->diff = 1;

    proc->timer = 0;
    proc->cur = proc->this;
    proc->timer2 = 0;
    proc->finished = FALSE;
    gEkrHitNow[GetAnimPosition(proc->anim_main_this)] = 1;
}

void EfxHpBar_DeclineToDeath(struct ProcEfxHpBar * proc)
{
    struct BaSprite * anim_f = gAnims[GetAnimPosition(proc->anim_main_this) * 2];
    struct BaSprite * anim_b = gAnims[GetAnimPosition(proc->anim_main_this) * 2 + 1];

    if (proc->finished == FALSE)
    {
        if (++proc->timer == 2)
        {
            proc->timer = 0;
            proc->cur += proc->diff;
            gEkrGaugeHp[GetAnimPosition(proc->anim_main_this)] += proc->diff;

            if (proc->cur == proc->next)
                proc->finished = TRUE;
        }
    }

    /* For Idunn and Fae, wait for a longer time? */
    if (gEkrPids[GetAnimPosition(proc->anim_main_this)] == PID_IDUNN_DRAGON || gEkrPids[GetAnimPosition(proc->anim_main_this)] == PID_FAE)
    {
        if (proc->timer2 == 0x50 && proc->finished == TRUE)
        {
            gEfxHpLutOff[GetAnimPosition(proc->anim_main_this)]++;
            gEkrHitNow[GetAnimPosition(proc->anim_main_this)] = 0;

            if (proc->next == 0)
            {
                int ret;
                if (GetBanimLinkArenaFlag() == TRUE)
                    ret = 0;
                else
                    ret = CheckBattleDefeatTalk(gEkrPids[GetAnimPosition(anim_f)]);

                if (ret == TRUE)
                    NewEfxDeadEvent(anim_f, anim_b);
                else
                {
                    PlayDeathSoundForArena();
                    NewEfxDead(anim_f, anim_b);
                    gBanimValid[GetAnimPosition(proc->anim_main_this)] = FALSE;
                }
            }
            Proc_Break(proc);
            return;
        }
        else if (++proc->timer2 >= 0x50)
            proc->timer2 = 0x50;

        return;
    }

    if (proc->timer2 == 0x1E && proc->finished == TRUE)
    {
        gEfxHpLutOff[GetAnimPosition(proc->anim_main_this)]++;
        gEkrHitNow[GetAnimPosition(proc->anim_main_this)] = 0;
    
        if (proc->next == 0)
        {
            int ret;
            if (GetBanimLinkArenaFlag() == TRUE)
                ret = 0;
            else
                ret = CheckBattleDefeatTalk(gEkrPids[GetAnimPosition(anim_f)]);

            if (ret == TRUE)
                NewEfxDeadEvent(anim_f, anim_b);
            else
            {
                PlayDeathSoundForArena();
                NewEfxDead(anim_f, anim_b);
                gBanimValid[GetAnimPosition(proc->anim_main_this)] = FALSE;
            }
        }

        Proc_Break(proc);
        return;
    }

    if (++proc->timer2 >= 0x1Eu)
        proc->timer2 = 0x1E;
}

void EfxHpBar_MoveCameraOnEnd(struct ProcEfxHpBar * proc)
{
    struct BaSprite *anim;

    if (gEfxBgSemaphore == 0 && gEfxSpellAnimExists == 0)
    {
        proc->timer = 0;
        proc->cur = 1;
        anim = GetAnimAnotherSide(proc->anim_this);

        if (CheckRound2(GetAnimNextRoundType(anim)) == 1)
        {
            switch (gEkrDistanceType) {
            case EKR_DISTANCE_CLOSE:
            case EKR_DISTANCE_FAR:
            case EKR_DISTANCE_MONOCOMBAT:
            case EKR_DISTANCE_PROMOTION:
                proc->cur = 16;
                NewEfxFarAttackWithDistance(GetAnimAnotherSide(anim), -1);
                break;

            case EKR_DISTANCE_FARFAR:
                proc->cur = 20;
                NewEfxFarAttackWithDistance(GetAnimAnotherSide(anim), -1);
                break;
            }
        }

        Proc_Break(proc);
    }
}

void EfxHpBar_WaitCameraMove(struct ProcEfxHpBar * proc)
{
    if (++proc->timer == (proc->cur - 4))
    {
        GetAnimAnotherSide(proc->anim_this);
        EnableBgSync(BG2_SYNC_BIT);
    }
    else if (proc->timer == proc->cur)
    {
        gEkrHpBarCount--;
        Proc_Break(proc);
    }
}

struct ProcScr CONST_DATA ProcScr_EfxHpBarResire[] =
{
    PROC_19,
    PROC_REPEAT(EfxHpBarResire_WaitOnCurrentSide),
    PROC_REPEAT(EfxHpBarResire_SetAnotherSide),
    PROC_REPEAT(EfxHpBarResire_DeclineToDeath),
    PROC_REPEAT(EfxHpBar_MoveCameraOnEnd),
    PROC_REPEAT(EfxHpBar_WaitCameraMove),
    PROC_END,
};

void NewEfxHpBarResire(struct BaSprite * anim)
{
    i16 off_this, off_next;
    struct ProcEfxHpBar * proc;

    if (gEkrHpBarCount != 0)
        return;

    gEkrHpBarCount = 1;

    proc = SpawnProc(ProcScr_EfxHpBarResire, PROC_TREE_3);
    proc->anim_this = GetAnimAnotherSide(anim);

    if (GetAnimPosition(anim) == POS_L)
    {
        proc->anim_main_other = gAnims[POS_R * 2];
        proc->anim_main_this  = gAnims[POS_L * 2];
    }
    else
    {
        proc->anim_main_other = gAnims[POS_L * 2];
        proc->anim_main_this  = gAnims[POS_R * 2];
    }

    off_this = gEfxHpLutOff[GetAnimPosition(proc->anim_main_this)];
    off_next = off_this + 1;

    proc->this = GetEfxHp(off_this * 2 + GetAnimPosition(proc->anim_main_this));
    proc->next = GetEfxHp(off_next * 2 + GetAnimPosition(proc->anim_main_this));

    if (proc->this > proc->next)
        proc->diff = -1;
    else
        proc->diff = 1;

    proc->death = FALSE;
    proc->timer = 0;
    proc->cur = proc->this;
    proc->timer2 = 0;
    proc->finished = FALSE;
    gEfxHpBarResireFlag = 0;
    gEkrHitNow[GetAnimPosition(proc->anim_main_this)] = 1;
}

void EfxHpBarResire_WaitOnCurrentSide(struct ProcEfxHpBar * proc)
{
    GetAnimPosition(proc->anim_main_this);
    GetAnimPosition(proc->anim_main_this);

    if (proc->finished == FALSE)
    {
        if (++proc->timer == 2)
        {
            proc->timer = 0;
            proc->cur += proc->diff;
            gEkrGaugeHp[GetAnimPosition(proc->anim_main_this)] += proc->diff;

            if (proc->cur == proc->next)
                proc->finished = TRUE;
        }
    }

    if (proc->timer2 == 0x54 && proc->finished == TRUE)
    {
        gEfxHpLutOff[GetAnimPosition(proc->anim_main_this)]++;
        gEkrHitNow[GetAnimPosition(proc->anim_main_this)] = 0;

        if (proc->next == 0)
            proc->death = TRUE;

        proc->timer = 0;
        proc->cur = 10;
        gEfxHpBarResireFlag = 1;

        Proc_Break(proc);
        return;
    }

    if (++proc->timer2 >= 0x54u)
        proc->timer2 = 0x54;
}

void EfxHpBarResire_SetAnotherSide(struct ProcEfxHpBar * proc)
{
    i16 off_this, off_next;

    if (++proc->timer <= proc->cur)
        return;

    off_this = gEfxHpLutOff[GetAnimPosition(proc->anim_main_other)];
    off_next = off_this + 1;

    proc->this = GetEfxHp(off_this * 2 + GetAnimPosition(proc->anim_main_other));
    proc->next = GetEfxHp(off_next * 2 + GetAnimPosition(proc->anim_main_other));

    proc->timer = 0;
    proc->cur = proc->this;
    proc->timer2 = 0;
    proc->finished = FALSE;

    if (proc->this == proc->next)
        proc->finished = TRUE;

    if (proc->this > proc->next)
        proc->diff = -1;
    else
        proc->diff = 1;

    Proc_Break(proc);
    gEkrHitNow[GetAnimPosition(proc->anim_main_other)] = 2;
}

void EfxHpBarResire_DeclineToDeath(struct ProcEfxHpBar * proc)
{
    struct BaSprite * anim_main_other_f, * anim_main_other_b, * anim_main_this_f, * anim_main_this_b;

    anim_main_other_f = gAnims[GetAnimPosition(proc->anim_main_other) * 2];
    anim_main_other_b = gAnims[GetAnimPosition(proc->anim_main_other) * 2 + 1];
    anim_main_this_f  = gAnims[GetAnimPosition(proc->anim_main_this) * 2];
    anim_main_this_b  = gAnims[GetAnimPosition(proc->anim_main_this) * 2 + 1];

    if (proc->finished == FALSE)
    {
        if (++proc->timer == 4)
        {
            proc->timer = 0;
            proc->cur += proc->diff;
            gEkrGaugeHp[GetAnimPosition(proc->anim_main_other)] += proc->diff;
            EfxPlaySE(0x75, 0x100);
            M4aPlayWithPostionCtrl(0x75, anim_main_other_f->xPosition, 1);

            if (proc->cur == proc->next)
                proc->finished = TRUE;
        }
    }

    if (proc->timer2 == 30 && proc->finished == TRUE)
    {
        gEfxHpLutOff[GetAnimPosition(proc->anim_main_other)]++;
        gEkrHitNow[GetAnimPosition(proc->anim_main_other)] = 0;
    
        if (proc->death == TRUE)
        {
            int ret;
            if (GetBanimLinkArenaFlag() == TRUE)
                ret = 0;
            else
                ret = CheckBattleDefeatTalk(gEkrPids[GetAnimPosition(anim_main_this_f)]);

            if (ret == TRUE)
                NewEfxDeadEvent(anim_main_this_f, anim_main_this_b);
            else
            {
                PlayDeathSoundForArena();
                NewEfxDead(anim_main_this_f, anim_main_this_b);
                gBanimValid[GetAnimPosition(proc->anim_main_this)] = FALSE;
            }
        }
    
        Proc_Break(proc);
        return;
    }

    if (++proc->timer2 >= 0x1Eu)
        proc->timer2 = 0x1E;
}

struct ProcScr CONST_DATA ProcScr_EfxAvoid[] =
{
    PROC_19,
    PROC_REPEAT(EfxAvoid_Loop),
    PROC_REPEAT(EfxHpBar_MoveCameraOnEnd),
    PROC_REPEAT(EfxHpBar_WaitCameraMove),
    PROC_END,
};

void NewEfxAvoid(struct BaSprite * anim)
{
    i16 off_this, off_next;
    struct ProcEfxHpBar * proc;

    u32 ref, dragon_type = GetEkrDragonStateTypeGeneric();

    if (gEkrHpBarCount != 0)
        return;

    gEkrHpBarCount = 1;

    proc = SpawnProc(ProcScr_EfxAvoid, PROC_TREE_3);
    proc->timer = 0;

    if (GetAnimPosition(anim) == POS_L)
    {
        proc->anim_main_other = MAIN_ANIM_FRONT(POS_R);
        proc->anim_main_this  = MAIN_ANIM_FRONT(POS_L);
    }
    else
    {
        proc->anim_main_other = MAIN_ANIM_FRONT(POS_L);
        proc->anim_main_this  = MAIN_ANIM_FRONT(POS_R);
    }

    NewEfxDamageMojiEffect(proc->anim_main_this, 1);
    proc->anim_this = anim;
    proc->death = FALSE;

    /* A special effect on dragon body avoid of Idunn (which is displayed on BG3) */
    if (GetAnimPosition(anim) == POS_L)
    {
        if (dragon_type & EDRAGON_TYPE_IDUNN_L)
            proc->death = TRUE;
    }
    else
    {
        if (dragon_type & EDRAGON_TYPE_IDUNN_R)
            proc->death = TRUE;
    }

    if (proc->death == TRUE)
        NewEfxAvoidForIdunn(anim);

    EfxPlaySE(0xD7, 0x100);
    M4aPlayWithPostionCtrl(0xD7, anim->xPosition, 1);
}

void EfxAvoid_Loop(struct ProcEfxHpBar * proc)
{
    if (proc->death == FALSE)
    {
        if (gEkrPids[GetAnimPosition(proc->anim_main_this)] == PID_FAE)
        {
            if (++proc->timer == 0x50)
                Proc_Break(proc);
        }
        else
        {
            if (++proc->timer == 0x1E)
                Proc_Break(proc);
        }
    }
    else if (++proc->timer == 0x50)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxHpBarLive[] =
{
    PROC_19,
    PROC_REPEAT(EfxHpBarLive_Loop),
    PROC_REPEAT(EfxHpBar_MoveCameraOnEnd),
    PROC_REPEAT(EfxHpBar_WaitCameraMove),
    PROC_END,
};

void NewEfxHpBarLive(struct BaSprite * anim)
{
    i16 off_this, off_next;
    struct ProcEfxHpBar * proc;

    if (gEkrHpBarCount != 0)
        return;

    gEkrHpBarCount = 1;

    proc = SpawnProc(ProcScr_EfxHpBarLive, PROC_TREE_3);


    if (GetAnimPosition(anim) == POS_L)
    {
        proc->anim_main_other = MAIN_ANIM_FRONT(POS_R);
        proc->anim_main_this  = MAIN_ANIM_FRONT(POS_L);
    }
    else
    {
        proc->anim_main_other = MAIN_ANIM_FRONT(POS_L);
        proc->anim_main_this  = MAIN_ANIM_FRONT(POS_R);
    }

    off_this = gEfxHpLutOff[GetAnimPosition(proc->anim_main_this)];
    off_next = off_this + 1;

    proc->this = GetEfxHp(off_this * 2 + GetAnimPosition(proc->anim_main_this));
    proc->next = GetEfxHp(off_next * 2 + GetAnimPosition(proc->anim_main_this));

    proc->timer2 = 0;
    proc->finished = FALSE;
    
    if (proc->this == proc->next)
        proc->finished = TRUE;
    else if (proc->this > proc->next)
        proc->diff = -1;
    else
        proc->diff = 1;

    proc->timer = 0;
    proc->cur = proc->this;
    proc->anim_this = anim;
    gEkrHitNow[GetAnimPosition(proc->anim_main_other)] = 2;
}

void EfxHpBarLive_Loop(struct ProcEfxHpBar * proc)
{
    struct BaSprite * anim = proc->anim_main_this;

    if (proc->finished == FALSE)
    {
        if (++proc->timer == 4)
        {
            proc->timer = 0;
            proc->cur += proc->diff;
            gEkrGaugeHp[GetAnimPosition(anim)] += proc->diff;

            EfxPlaySE(0x75, 0x100);
            M4aPlayWithPostionCtrl(0x75, anim->xPosition, 1);

            if (proc->cur == proc->next)
                proc->finished = TRUE;
        }
    }

    if (proc->timer2 == 0x1E && proc->finished == TRUE)
    {
        gEfxHpLutOff[GetAnimPosition(anim)]++;
        gEkrHitNow[GetAnimPosition(anim)] = 0;
        Proc_Break(proc);
        return;
    }

    if (++proc->timer2 >= 0x1Eu)
        proc->timer2 = 0x1E;
}

struct ProcScr CONST_DATA ProcScr_EfxNoDmage[] =
{
    PROC_19,
    PROC_REPEAT(EfxNoDmage_Loop),
    PROC_REPEAT(EfxHpBar_MoveCameraOnEnd),
    PROC_REPEAT(EfxHpBar_WaitCameraMove),
    PROC_END,
};

void NewEfxNoDamage(struct BaSprite * anim1, struct BaSprite * anim2, int death)
{
    struct ProcEfxHpBar * proc;

    gEkrHpBarCount++;

    proc = SpawnProc(ProcScr_EfxNoDmage, PROC_TREE_3);
    proc->anim_main_other = anim1;
    proc->anim_main_this = anim2;
    proc->timer = 0;
    proc->death = death;
    proc->anim_this = anim1;

    NewEfxDamageMojiEffect(proc->anim_main_other, 0);
    NewEfxNoDamageYure(proc->anim_main_other, proc->anim_main_this);
}

void EfxNoDmage_Loop(struct ProcEfxHpBar * proc)
{
    int time;
    struct BaSprite * anim = GetAnimAnotherSide(proc->anim_main_other);

    if (gEkrPids[GetAnimPosition(proc->anim_main_other)] == PID_IDUNN_DRAGON || gEkrPids[GetAnimPosition(proc->anim_main_other)] == PID_FAE)
    {
        ++proc->timer;
        time = proc->timer;
        if (time == 0x3A)
        {
            gEfxHpLutOff[GetAnimPosition(proc->anim_main_other)]++;

            if (proc->death == TRUE)
                gEfxHpLutOff[GetAnimPosition(anim)]++;

            Proc_Break(proc);
        }
    }
    else
    {
        ++proc->timer;
        time = proc->timer;
        if (time == 8)
        {
            gEfxHpLutOff[GetAnimPosition(proc->anim_main_other)]++;

            if (proc->death == TRUE)
                gEfxHpLutOff[GetAnimPosition(anim)]++;

            Proc_Break(proc);
        }
    }
}

struct ProcScr CONST_DATA ProcScr_EfxNoDamageYure[] =
{
    PROC_19,
    PROC_REPEAT(EfxNoDamageYure_Loop),
    PROC_END,
};

void NewEfxNoDamageYure(struct BaSprite * anim1, struct BaSprite * anim2)
{
    struct ProcEfxHpBar *proc = SpawnProc(ProcScr_EfxNoDamageYure, PROC_TREE_3);
    proc->anim_main_other = anim1;
    proc->anim_main_this = anim2;
    proc->timer = 0;
    proc->cur = 0;
}

void EfxNoDamageYure_Loop(struct ProcEfxHpBar * proc)
{
    i16 off_this;
    struct BaSprite * anim1 = proc->anim_main_other;
    struct BaSprite * anim2 = proc->anim_main_this;

    if (gEfxNoDmgBgShakeOff[proc->timer] == -1)
    {
        anim1->xPosition = gEkrXPosReal[GetAnimPosition(proc->anim_main_other)] - gEkrBgPosition;
        anim2->xPosition = gEkrXPosReal[GetAnimPosition(proc->anim_main_this)]  - gEkrBgPosition;
        Proc_Break(proc);
    }
    else
    {
        if (GetAnimPosition(anim1) == POS_R)
            off_this = -gEfxNoDmgBgShakeOff[proc->timer];
        else
            off_this =  gEfxNoDmgBgShakeOff[proc->timer];

        anim1->xPosition = gEkrXPosReal[GetAnimPosition(proc->anim_main_other)] - (i32)gEkrBgPosition + off_this;
        anim2->xPosition = gEkrXPosReal[GetAnimPosition(proc->anim_main_this)]  - (i32)gEkrBgPosition + off_this;
        proc->timer++;
    }
}

struct ProcScr CONST_DATA ProcScr_EfxStatusCHG[] =
{
    PROC_19,
    PROC_MARK(10),
    PROC_REPEAT(EfxStatusCHG_Loop),
    PROC_REPEAT(EfxHpBar_MoveCameraOnEnd),
    PROC_REPEAT(EfxHpBar_WaitCameraMove),
    PROC_END,
};

void NewEfxStatusCHG(struct BaSprite * anim)
{
    struct ProcEfxHpBar *proc;

    if (gEkrHpBarCount == 0) {
        gEkrHpBarCount = 1;
        proc = SpawnProc(ProcScr_EfxStatusCHG, PROC_TREE_3);
        proc->timer = 0;
        proc->anim_this = anim;
    }
}

void EfxStatusCHG_Loop(struct ProcEfxHpBar * proc)
{
    if (++proc->timer == 0x11)
        Proc_Break(proc);
}
