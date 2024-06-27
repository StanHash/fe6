#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "move.h"
#include "hardware.h"
#include "constants/jids.h"
#include "constants/videoalloc_banim.h"

#include "banim_sprite.h"
#include "banim.h"
#include "banim_ekrbattle.h"
#include "banim_ekrdragon.h"

void ResetEkrDragonStatus(void)
{
    EkrDragonProcs[POS_L] = NULL;
    EkrDragonProcs[POS_R] = NULL;
    gpProcEkrIdunnBodyFlashing = NULL;
    gEkrDragonIntroDone[POS_L] = FALSE;
    gEkrDragonIntroDone[POS_R] = FALSE;
    gEkrDragonFastenConf[POS_L] = 0;
    gEkrDragonFastenConf[POS_R] = 0;
    gEkrDragonState[POS_L] = DRAGON_STATE_DEFAULT;
    gEkrDragonState[POS_R] = DRAGON_STATE_DEFAULT;
}

bool EkrDragonIntroDone(struct BaSprite * anim)
{
    if (gEkrDragonIntroDone[GetAnimPosition(anim)] == 1)
        return TRUE;

    return FALSE;
}

void TriggerEkrDragonEnding(struct BaSprite * anim)
{
    gEkrDragonState[GetAnimPosition(anim)] = DRAGON_STATE_ENDING;
}

bool CheckEkrDragonEndingDone(struct BaSprite * anim)
{
    if (gEkrDragonIntroDone[GetAnimPosition(anim)] == 2)
        return TRUE;

    return FALSE;
}

u32 GetEkrDragonStateTypeGeneric(void)
{
    u32 ret = 0;

    if (*GetEkrDragonJid(POS_L) == 0x53)
        ret |= EDRAGON_TYPE_MANAKETE_L;

    if (*GetEkrDragonJid(POS_R) == 0x53)
        ret |= EDRAGON_TYPE_MANAKETE_R;

    if (*GetEkrDragonJid(POS_L) == 0x54)
        ret |= EDRAGON_TYPE_FAE_L;

    if (*GetEkrDragonJid(POS_R) == 0x54)
        ret |= EDRAGON_TYPE_FAE_R;

    if (*GetEkrDragonJid(POS_L) == 0x70)
        ret |= EDRAGON_TYPE_IDUNN_L;

    if (*GetEkrDragonJid(POS_R) == 0x70)
        ret |= EDRAGON_TYPE_IDUNN_R;

    return ret;
}

u32 GetEkrDragonStateType(void)
{
    u32 ret = 0;

    if (*GetEkrDragonJid(POS_L) == 0x53)
        ret |= EDRAGON_TYPE_MANAKETE_L;

    if (*GetEkrDragonJid(POS_R) == 0x53)
        ret |= EDRAGON_TYPE_MANAKETE_R;

    if (*GetEkrDragonJid(POS_L) == 0x70)
        ret |= EDRAGON_TYPE_IDUNN_L;

    if (*GetEkrDragonJid(POS_R) == 0x70)
        ret |= EDRAGON_TYPE_IDUNN_R;

    return ret;
}

u32 GetEkrDragonStateTypeIdunn(void)
{
    u32 ret = 0;

    if (*GetEkrDragonJid(POS_L) == 0x70)
        ret |= EDRAGON_TYPE_IDUNN_L;

    if (*GetEkrDragonJid(POS_R) == 0x70)
        ret |= EDRAGON_TYPE_IDUNN_R;

    return ret;
}

bool CheckSkipDragonTransfer(struct BaSprite * anim)
{
    if (*CheckEkrDragonFasten(anim) == TRUE)
        return TRUE;

    if (gEkrDistanceType != EKR_DISTANCE_FARFAR || GetAnimPosition(anim) == gEkrInitPosReal)
        return FALSE;

    return TRUE;
}

u16 * GetEkrDragonJid(int pos)
{
    return gEkrDragonJid + pos;
}

u16 * CheckEkrDragonFasten(struct BaSprite * anim)
{
    return gEkrDragonFastenConf + GetAnimPosition(anim);
}

ProcPtr GetEkrDragonProc(struct BaSprite * anim)
{
    return EkrDragonProcs[GetAnimPosition(anim)];
}

void EndEkrDragonDaemon(struct BaSprite * anim)
{
    Proc_End(gEkrDragonDeamonProcs[GetAnimPosition(anim)]);
}

void SetDragonBasLayer(u8 layer)
{
    struct BaSprite * anim_l = MAIN_ANIM_FRONT(POS_L);
    struct BaSprite * anim_r = MAIN_ANIM_FRONT(POS_R);

    anim_l->oam2 = (anim_l->oam2 & (OAM2_PAL_MASK | OAM2_CHR_MASK)) | (layer * 0x0400);
    anim_r->oam2 = (anim_r->oam2 & (OAM2_PAL_MASK | OAM2_CHR_MASK)) | (layer * 0x0400);
}

void PutManaketeBodyPalette(struct ProcEkrDragon * proc)
{
    CpuFastCopy(Pal_EkrManaketefx, &PAL_BG_COLOR(1, 0), 0x20);

    if (GetAnimPosition(proc->anim) == POS_L)
    {
        CpuFastCopy(Pal_EkrManaketefx, &PAL_BG_COLOR(6, 0), 0x20);
    }
    else
    {
        CpuFastCopy(Pal_EkrManaketefx, &PAL_BG_COLOR(7, 0), 0x20);
    }
    EnablePalSync();
}

void PutManaketeBodyIntro2(struct ProcEkrDragon * proc)
{
    LZ77UnCompWram(Img_ManaketeBodyIntro2, gSpellAnimBgfx);
    LZ77UnCompWram(Tsa_ManaketeBodyIntro2, gEkrTsaBuffer);
    EfxTmFill(0);

    if (GetAnimPosition(proc->anim) == POS_L)
    {
        int x = gEkrDistanceType == EKR_DISTANCE_CLOSE ? 0x23 : 0x1D;

        EfxTmCpyExtHFlip(
            gEkrTsaBuffer, -1,
            EFX_TILEMAP_LOC(gTmB_Banim, x, 0), EFX_BG_WIDTH,
            0xF, 0x16, 0x6, 0
        );

        EfxTmCpyExt(
            EFX_TILEMAP_LOC(gTmB_Banim, 0x21, 0), EFX_BG_WIDTH,
            gBg3Tm, 0x20,
            0x20, 0x16, -1, -1
        );

        RegisterVramMove(gSpellAnimBgfx, CHR_SIZE * BGCHR_EKRDRAGON_400, CHR_SIZE * 0x100);
    }
    EnableBgSync(BG3_SYNC_BIT);
}

void PutManaketeBodyIntro1(struct ProcEkrDragon * proc)
{
    LZ77UnCompWram(Img_ManaketeBodyIntro1, gSpellAnimBgfx);
    LZ77UnCompWram(Tsa_ManaketeBodyIntro1, gEkrTsaBuffer);
    EfxTmFill(0);

    if (GetAnimPosition(proc->anim) == POS_L)
    {
        int x = gEkrDistanceType == EKR_DISTANCE_CLOSE ? 0x21 : 0x1B;

        EfxTmCpyExtHFlip(
            gEkrTsaBuffer, -1,
            EFX_TILEMAP_LOC(gTmB_Banim, x, 0), EFX_BG_WIDTH,
            0xF, 0x16, 0x6, 0
        );

        EfxTmCpyExt(
            EFX_TILEMAP_LOC(gTmB_Banim, 0x21, 0), EFX_BG_WIDTH,
            gBg3Tm, 0x20,
            0x20, 0x16, -1, -1
        );

        RegisterVramMove(gSpellAnimBgfx, CHR_SIZE * BGCHR_EKRDRAGON_400, CHR_SIZE * 0x100);
    }
    EnableBgSync(BG3_SYNC_BIT);
}

void PutManaketeBodyStd(struct ProcEkrDragon * proc)
{
    LZ77UnCompWram(Img_ManaketeBodyStd, gSpellAnimBgfx);
    LZ77UnCompWram(Tsa_ManaketeBodyStd, gEkrTsaBuffer);
    EfxTmFill(0);

    if (GetAnimPosition(proc->anim) == POS_L)
    {
        int x;

#if NONMATCHING
        switch (gEkrDistanceType) {
        case EKR_DISTANCE_CLOSE:
            x = 0x21;
            break;

        default:
            x = 1;
            break;

        case EKR_DISTANCE_FAR:
            x = 0x1B;
            break;
        }
#else
        int distance = gEkrDistanceType;
        x = 0x21;
        if (distance != EKR_DISTANCE_CLOSE)
        {
            x = 1;
            if (distance == EKR_DISTANCE_FAR)
                x = 0x1B;
        }
#endif

        EfxTmCpyExtHFlip(
            gEkrTsaBuffer, -1,
            EFX_TILEMAP_LOC(gTmB_Banim, x, 0), EFX_BG_WIDTH,
            0xF, 0x16, 0x6, 0
        );

        EfxTmCpyExt(
            EFX_TILEMAP_LOC(gTmB_Banim, 0x21, 0), EFX_BG_WIDTH,
            gBg3Tm, 0x20,
            0x20, 0x16, -1, -1
        );

        RegisterVramMove(gSpellAnimBgfx, CHR_SIZE * BGCHR_EKRDRAGON_400, CHR_SIZE * 0x100);
    }
    EnableBgSync(BG3_SYNC_BIT);
}

struct ProcScr CONST_DATA ProcScr_EkrDragonMoveBg3[] = {
    PROC_19,
    PROC_REPEAT(EkrDragonMoveBg3_Loop),
    PROC_END,
};

void EkrDragonMoveBg3(int x)
{
    struct ProcEkrDragonMoveBg3 * proc;
    proc = SpawnProc(ProcScr_EkrDragonMoveBg3, PROC_TREE_4);
    proc->timer = 0;
    proc->x = x;
}

void EkrDragonMoveBg3_Loop(struct ProcEkrDragonMoveBg3 * proc)
{
    SetBgOffset(3, proc->x, 0x10);

    if (++proc->timer == 0x46)
        Proc_Break(proc);
}

void PutManaketeTotalImg(struct ProcEkrDragon * proc)
{
    int pos;

    LZ77UnCompWram(Img_081BE490, gSpellAnimBgfx);
    RegisterVramMove(gSpellAnimBgfx, CHR_SIZE * BGCHR_EKRDRAGON_400, CHR_SIZE * 0x100);
    EfxTmFill(0);

    pos = GetAnimPosition(proc->anim);
    if (pos == POS_L)
    {
        LZ77UnCompWram(Tsa_081BFA34, gEkrTsaBuffer);
        EfxTmCpyBgHFlip(gEkrTsaBuffer, gBg3Tm, 30, 22, 6, pos);

        switch (gEkrDistanceType) {
        case EKR_DISTANCE_CLOSE:
            SetBgOffset(3, 0, 16);
            break;

        case EKR_DISTANCE_FAR:
            EkrDragonMoveBg3(gEkrBgPosition + 48);
            SetBgOffset(3, gEkrBgPosition + 48, 16);

            if (gEkrBgPosition == 0)
            {
                FillBGRect(gBg3Tm, 2, 22, 240, 0);
                FillBGRect(gBg3Tm + 2, 2, 22, 240, 0);
            }
            break;

        case EKR_DISTANCE_FARFAR:
            EkrDragonMoveBg3(16);
            SetBgOffset(3, 16, 16);
            break;
        }
    }
    EnableBgSync(BG3_SYNC_BIT);
}

void ResetDragonAnimfx(void)
{
    CpuFastFill16(0, gPal_Banim, 0x20);
    RegisterVramMove(gPal_Banim, 0x8000, 0x20);
}

void RestoreBodyFlashingPalForManakete(int pos)
{
    if (pos == POS_L)
        CpuFastCopy(Pal_EkrManaketefx, gPal + BGPAL_OFFSET(6), 0x20);
    else
        CpuFastCopy(Pal_EkrManaketefx, gPal + BGPAL_OFFSET(7), 0x20);

    EnablePalSync();
}

void RestoreBodyFlashingPalForIdunn(int pos)
{
    if (pos == POS_L)
        CpuFastCopy(Pal_081C4DE8, gPal + BGPAL_OFFSET(6), 0x20);
    else
        CpuFastCopy(Pal_081C4DE8, gPal + BGPAL_OFFSET(7), 0x20);

    EnablePalSync();
}

void EfxBodyFlashingForDragon(int pos)
{
    if (pos == POS_L)
        CpuFastCopy(Pal_BanimUnitFlashing, gPal + BGPAL_OFFSET(6), 0x20);
    else
        CpuFastCopy(Pal_BanimUnitFlashing, gPal + BGPAL_OFFSET(7), 0x20);

    EnablePalSync();
}

int GetDragonPosition(void)
{
    int type = GetEkrDragonStateTypeIdunn();
    if (type & EDRAGON_TYPE_IDUNN_L)
        return POS_L;

    if (type & EDRAGON_TYPE_IDUNN_R)
        return POS_R;

    return 2;
}

void InitEkrDragonStatus(void)
{
    SetAnimStateHidden(GetDragonPosition());
}

int func_fe6_08058F38(void)
{
    if (GetEkrDragonStateTypeIdunn() == 0)
        return 0;

    if (*CheckEkrDragonFasten(MAIN_ANIM_FRONT(POS_L)) != 1)
        return 0;

    return 1;
}

void EkrDragonTmCpyExt(int x)
{
    int _x, tmp1;
    u16 * buf;

    _x = x >> 3;
    tmp1 = 7;

    SetBgOffset(3, x & tmp1, 16);

    buf = gTmB_Banim + 0x21 + _x;

    EfxTmCpyExt(
        buf,
        EFX_BG_WIDTH,
        gBg3Tm,
        TILE_SIZE_4BPP, TILE_SIZE_4BPP, 22, -1, -1);

    EnableBgSync(BG3_SYNC_BIT);
}

void func_fe6_08058FA8(const u8 * tsa)
{
    LZ77UnCompWram(tsa, gEkrTsaBuffer);

    if (gEkrDistanceType == EKR_DISTANCE_CLOSE)
    {
        EfxTmCpyExt(
            gEkrTsaBuffer,
            -1,
            gBg3Tm,
            TILE_SIZE_4BPP, 30, 30, 6, 0);
    }
    else
    {
        EfxTmCpyExt(
            gEkrTsaBuffer + 4,
            30,
            gBg3Tm,
            TILE_SIZE_4BPP, 26, 30, 6, 0);
    }
    EnableBgSync(BG3_SYNC_BIT);
}

void func_fe6_08059018(const u8 * tsa)
{
    int loc, distance;

    LZ77UnCompWram(tsa, gUnk_Banim_0201E7CC);

    if (gEkrDistanceType == EKR_DISTANCE_CLOSE)
        loc = TM_OFFSET(1, 1);
    else if (gEkrDistanceType == EKR_DISTANCE_FAR)
        loc = TM_OFFSET(29, 0);
    else
        loc = TM_OFFSET(3, 0);

    EfxTmCpyExt(
        gUnk_Banim_0201E7CC,
        -1,
        gTmB_Banim + loc,
        EFX_BG_WIDTH, 30, 22,
        6, 0);

    EkrDragonTmCpyExt(gEkrBgPosition);
}

struct ProcScr CONST_DATA ProcScr_EkrDragonBark[] =
{
    PROC_19,
    PROC_SLEEP(20),
    PROC_REPEAT(EkrDragonBarkExt),
    PROC_END,
};

void NewEkrDragonBark(struct BaSprite * anim)
{
    struct ProcEkrDragonBark * proc;
    proc = SpawnProc(ProcScr_EkrDragonBark, PROC_TREE_3);
    proc->anim = anim;
}

void EkrDragonBarkExt(struct ProcEkrDragonBark * proc)
{
    struct BaSprite * anim = proc->anim;

    EfxPlaySE(0x0E6, 0x100);
    M4aPlayWithPostionCtrl(0x0E6, anim->xPosition, 1);
    Proc_Break(proc);
}
