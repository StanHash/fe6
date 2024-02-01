#include "common.h"
#include "proc.h"
#include "sound.h"
#include "banim_sprite.h"
#include "banim.h"

struct ProcScr CONST_DATA ProcScr_EkrLvupFan[] =
{
    PROC_19,
    PROC_REPEAT(EkrLvupFanMain),
    PROC_END,
};

void NewEkrLvlupFan(void)
{
    struct ProcEfx * proc = SpawnProc(ProcScr_EkrLvupFan, PROC_TREE_3);
    proc->timer = 0;
    SetBgmVolume(0x80);
}

void EkrLvupFanMain(struct ProcEfx * proc)
{
    int timer = ++proc->timer;
    if (timer == 0x10)
    {
        EfxPlaySE(0x5B, 0x100);
        M4aPlayWithPostionCtrl(0x5B, 0x78, 0);
    }
    else if (timer == 0x74)
    {
        SetBgmVolume(0x100);
        Proc_Break(proc);
    }
}
