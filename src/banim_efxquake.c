#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "banim.h"
#include "banim_ekrbattle.h"
#include "banim_ekrdragon.h"

struct ProcScr CONST_DATA ProcScr_EfxQuakePure[] =
{
    PROC_19,
    PROC_REPEAT(EfxQuakePure_Loop),
    PROC_END,
};

const void * CONST_DATA EfxQuakePureVecs[] =
{
    gEfxQuakePureVec1, 0,
    gEfxQuakePureVec2, 0,
    gEfxQuakePureVec3, 0,
    gEfxQuakePureVec4, 0,
    gEfxQuakePureVec5, 0,
    gEfxQuakePureVec6, 0,
    gEfxQuakePureVec7, 0,
    gEfxQuakePureVec8, 0,
    gEfxQuakePureVec9, 0,
    gEfxQuakePureVec10, 0,
    gEfxQuakePureVec11, 0,
};

ProcPtr NewEfxQuakePure(int index, int kind)
{
    struct ProcEfxQuake * proc = SpawnProc(ProcScr_EfxQuakePure, PROC_TREE_3);

    proc->vec = (i16 *)EfxQuakePureVecs[index * 2];
    proc->quake_ui = (int)EfxQuakePureVecs[index * 2 + 1];

    proc->kind = kind;
    proc->timer = 0;

    return proc;
}

void EfxQuakePure_Loop(struct ProcEfxQuake * proc)
{
    const i16 * vec = proc->vec;

    if (vec[proc->timer * 2 + 0] != INT16_MAX)
    {
        SetEkrBg2QuakeVec(vec[proc->timer * 2 + 0], vec[proc->timer * 2 + 1]);
        proc->timer++;
    }
    else
    {
        switch (proc->kind) {
        case 0:
            proc->timer = 0;
            SetEkrBg2QuakeVec(vec[0], vec[1]);
            break;

        case 1:
            gEkrBg2QuakeVec.y = 0;
            gEkrBg2QuakeVec.x = 0;
            break;
        }
    }
}

struct ProcScr CONST_DATA ProcScr_EfxHitQuakePure[] =
{
    PROC_19,
    PROC_REPEAT(EfxHitQuakePure_Loop),
    PROC_END,
};

ProcPtr NewEfxHitQuakePure(void)
{
    return SpawnProc(ProcScr_EfxHitQuakePure, PROC_TREE_3);
}

void EfxHitQuakePure_Loop(struct ProcEfxQuake * proc)
{
    return;
}

struct ProcScr CONST_DATA ProcScr_EfxQuake[] =
{
    PROC_19,
    PROC_REPEAT(EfxQuake_Loop),
    PROC_END,
};

ProcPtr NewEfxQuake(int kind)
{
    struct ProcEfxQuake * proc;

    if (gEfxFarAttackExist == 1)
    {
        return NULL;
    }

    gEfxQuakeExist = 1;
    proc = SpawnProc(ProcScr_EfxQuake, PROC_TREE_3);

    proc->timer = 0;

    proc->anim_l = MAIN_ANIM_FRONT(POS_L);
    proc->anim_r = MAIN_ANIM_FRONT(POS_R);

    switch (kind) {
    case 0:
        proc->vec = gEfxQuakePureVec1;
        proc->quake_ui = 0;

        break;

    case 1:
        proc->vec = gEfxQuakePureVec2;
        proc->quake_ui = 0;

        break;

    case 2:
        proc->vec = gEfxQuakePureVec3;
        proc->quake_ui = 0;

        break;

    case 3:
        proc->vec = gEfxQuakePureVec4;
        proc->quake_ui = 0;

        break;

    case 4:
        proc->vec = gEfxQuakePureVec5;
        proc->quake_ui = 0;

        break;

    case 5:
        proc->vec = gEfxQuakePureVec6;
        proc->quake_ui = 1;

        break;

    case 6:
        proc->vec = gEfxQuakeVec_08111E14;
        proc->quake_ui = 1;

        break;

    default:
        proc->vec = gEfxQuakePureVec1;
        proc->quake_ui = 0;

        break;
    }

    proc->ix = 0;
    proc->iy = 0;

    return proc;
}

void EfxQuake_Loop(struct ProcEfxQuake * proc)
{
    int x1, y1, x2, y2;
    const i16 * vec = proc->vec;
    u32 time = (u16)proc->timer;

    if (vec[proc->timer * 2 + 0] == INT16_MAX)
    {
        x1 = gEkrXPosReal[POS_L] - gEkrBgPosition;
        y1 = gEkrYPosReal[POS_L];
        x2 = gEkrXPosReal[POS_R] - gEkrBgPosition;
        y2 = gEkrYPosReal[POS_R];

        SetEkrFrontAnimPostion(POS_L, x1, y1);
        SetEkrFrontAnimPostion(POS_R, x2, y2);

        SetBgOffset(2, 0, 0);

        if (GetEkrDragonStateType() != 0)
            SetBgOffset(3, proc->ix, proc->iy + 0x10);

        gEfxQuakeExist = 0;
        Proc_End(proc);
    }
    else
    {
        SetEkrBg2QuakeVec(vec[proc->timer * 2 + 0], vec[proc->timer * 2 + 1]);
        proc->timer = time + 1;
        SetBgOffset(2, gEkrBg2QuakeVec.x, gEkrBg2QuakeVec.y);

        if (GetEkrDragonStateType() != 0)
            SetBgOffset(3, proc->ix + gEkrBg2QuakeVec.x, proc->iy + gEkrBg2QuakeVec.y + 0x10);

        if (GetEkrDragonStateType() != 0)
        {
            x1 = (gEkrXPosReal[0] - gEkrBg2QuakeVec.x) - gEkrBgPosition;
            y1 = gEkrYPosReal[0] - gEkrBg2QuakeVec.y;
        }
        else
        {
            x1 = (gEkrXPosReal[0] + gEkrBg2QuakeVec.x) - gEkrBgPosition;
            y1 = gEkrYPosReal[0] - gEkrBg2QuakeVec.y;
        }

        x2 = (gEkrXPosReal[1] + gEkrBg2QuakeVec.x) - gEkrBgPosition;
        y2 = gEkrYPosReal[1] - gEkrBg2QuakeVec.y;

        switch (gEkrDistanceType) {
        case EKR_DISTANCE_CLOSE:
            SetEkrFrontAnimPostion(POS_L, x1, y1);
            SetEkrFrontAnimPostion(POS_R, x2, y2);
            break;

        case EKR_DISTANCE_FAR:
        case EKR_DISTANCE_FARFAR:
            if (GetAnimPosition(proc->anim_l) == POS_L)
                SetEkrFrontAnimPostion(POS_L, x1, y1);
            else
                SetEkrFrontAnimPostion(POS_R, x2, y2);

            break;
        }
    }
}

struct ProcScr CONST_DATA ProcScr_EfxHitQuake[] =
{
    PROC_19,
    PROC_REPEAT(EfxHitQuake_Loop),
    PROC_END,
};
