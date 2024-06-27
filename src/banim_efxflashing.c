#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "banim_sprite.h"
#include "banim.h"
#include "banim_ekrdragon.h"

struct ProcScr CONST_DATA ProcScr_EfxFlashUnit[] =
{
    PROC_19,
    PROC_MARK(10),
    PROC_REPEAT(EfxFlashUnit_Loop),
    PROC_REPEAT(EfxFlashUnit_RestorePal),
    PROC_END,
};

void NewEfxFlashUnit(struct BaSprite * anim, u16 dura1, u16 dura2, int flag)
{
    struct ProcEfxFlashing * proc = SpawnProc(ProcScr_EfxFlashUnit, PROC_TREE_4);
    proc->anim = anim;
    proc->timer = 0;
    proc->terminator = dura1;
    proc->terminator2 = dura2;
    proc->flag = flag;
}

void EfxFlashUnit_Loop(struct ProcEfxFlashing * proc)
{
    u32 ret = GetEkrDragonStateType();

    if (++proc->timer < proc->terminator)
        return;

    if (GetAnimPosition(proc->anim) == POS_L)
    {
        CpuFastCopy(Pal_BanimUnitFlashing, gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_L), 0x20);

        if (proc->flag == 0)
        {
            if (ret & EDRAGON_TYPE_MANAKETE_L)
                EfxBodyFlashingForDragon(POS_L);

            if (ret & EDRAGON_TYPE_IDUNN_L)
                EfxBodyFlashingForDragon(POS_L);
        }
    }
    else
    {
        CpuFastCopy(Pal_BanimUnitFlashing, gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_R), 0x20);

        if (proc->flag == 0)
        {
            if (ret & EDRAGON_TYPE_MANAKETE_R)
                EfxBodyFlashingForDragon(POS_R);

            if (ret & EDRAGON_TYPE_IDUNN_R)
                EfxBodyFlashingForDragon(POS_R);
        }
    }

    EnablePalSync();

    if (proc->timer >= proc->terminator2)
        Proc_Break(proc);
}

void EfxFlashUnit_RestorePal(struct ProcEfxFlashing * proc)
{
    u32 ret = GetEkrDragonStateType();

    if (GetAnimPosition(proc->anim) == POS_L)
    {
        CpuFastCopy(gpEfxUnitPaletteBackup[POS_L], gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_L), 0x20);

        if (proc->flag == 0)
        {
            if (ret & EDRAGON_TYPE_MANAKETE_L)
                RestoreBodyFlashingPalForManakete(POS_L);

            if (ret & EDRAGON_TYPE_IDUNN_L)
                RestoreBodyFlashingPalForIdunn(POS_L);
        }
    }
    else
    {
        CpuFastCopy(gpEfxUnitPaletteBackup[POS_R], gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_R), 0x20);

        if (proc->flag == 0)
        {
            if (ret & EDRAGON_TYPE_MANAKETE_R)
                RestoreBodyFlashingPalForManakete(POS_R);

            if (ret & EDRAGON_TYPE_IDUNN_R)
                RestoreBodyFlashingPalForIdunn(POS_R);
        }
    }
    EnablePalSync();
    Proc_Break(proc);
}
