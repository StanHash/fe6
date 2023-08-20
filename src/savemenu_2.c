#include "savemenu.h"

#include "armfunc.h"
#include "hardware.h"
#include "move.h"
#include "oam.h"
#include "proc.h"
#include "sprite.h"
#include "spriteanim.h"
#include "text.h"
#include "ui.h"
#include "helpbox.h"
#include "save_core.h"
#include "save_game.h"

extern u16 const gUnk_0832C39C[]; // sprite anim

struct Unk_0868A518
{
    /* 00 */ u16 const * sprite;
    /* 04 */ u8 unk_04;
};

extern struct Unk_0868A518 gUnk_0868A4F8[];
extern struct Unk_0868A518 gUnk_0868A518[];

extern u16 const * gUnk_0868A550[]; // sprites
extern u16 const * gUnk_0868A55C[]; // sprites

u16 EWRAM_OVERLAY(savemenu) gUnk_Savemenu_02000404[0x20] = { 0 };

struct Font EWRAM_OVERLAY(savemenu) gSaveMenuFont = { 0 };
struct Text EWRAM_OVERLAY(savemenu) gSaveMenuText = { 0 };

u8 EWRAM_OVERLAY(savemenu) gUnk_Savemenu_02000464[3] = { 0 };

void func_fe6_08089254(struct SaveMenuUnkPalProc * proc)
{
    int i;

    proc->unk_29 = 0;

    for (i = 0; i < (int)ARRAY_COUNT(gPal); i++)
    {
        gUnk_Savemenu_02000002[i] = gPal[i];
    }
}

void func_fe6_0808927C(struct SaveMenuUnkPalProc * proc)
{
    #define SCALE 0x10

    int i;
    fu8 coef = proc->unk_29;

    for (i = 0; i < (int)ARRAY_COUNT(gPal); i++)
    {
        int b_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();

    proc->unk_29++;

    if (coef == SCALE)
    {
        Proc_Break(proc);
    }

    #undef SCALE
}

void func_fe6_08089310(struct SaveMenuUnkPalProc * proc)
{
    #define SCALE 0x10

    int i;
    fu8 coef = SCALE - proc->unk_29;

    for (i = 0; i < (int)ARRAY_COUNT(gPal); i++)
    {
        int b_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();

    proc->unk_29++;

    if (coef == 0)
    {
        SetDispEnable(0, 0, 0, 0, 0);
        Proc_Break(proc);
    }

    #undef SCALE
}

void func_fe6_080893D0(struct SaveMenuUnkPalProc * proc)
{
    #define SCALE 0x20

    int i;
    fu8 coef = SCALE - proc->unk_29;

    for (i = 0; i < (int)ARRAY_COUNT(gPal); i++)
    {
        int b_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();

    proc->unk_29++;

    if (coef == 0)
    {
        SetDispEnable(0, 0, 0, 0, 0);
        Proc_Break(proc);
    }

    #undef SCALE
}

void func_fe6_08089490(struct SaveMenuUnkPalProc * proc)
{
    #define SCALE 0x40

    int i;
    fu8 coef = SCALE - proc->unk_29;

    for (i = 0; i < (int)ARRAY_COUNT(gPal); i++)
    {
        int b_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gUnk_Savemenu_02000002[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();

    proc->unk_29++;

    if (coef == 0)
    {
        SetDispEnable(0, 0, 0, 0, 0);
        Proc_Break(proc);
    }

    #undef SCALE
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A09C[] =
{
    PROC_CALL(func_fe6_08089254),
    PROC_REPEAT(func_fe6_0808927C),
    PROC_END,
};

void func_fe6_08089550(ProcPtr parent)
{
    SpawnProcLocking(ProcScr_Unk_0868A09C, parent);
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A0B4[] =
{
    PROC_CALL(func_fe6_08089254),
    PROC_REPEAT(func_fe6_08089310),
    PROC_END,
};

void func_fe6_08089564(ProcPtr parent)
{
    SpawnProcLocking(ProcScr_Unk_0868A0B4, parent);
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A0CC[] =
{
    PROC_CALL(func_fe6_08089254),
    PROC_REPEAT(func_fe6_080893D0),
    PROC_END,
};

void func_fe6_08089578(ProcPtr parent)
{
    SpawnProcLocking(ProcScr_Unk_0868A0CC, parent);
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A0E4[] =
{
    PROC_CALL(func_fe6_08089254),
    PROC_REPEAT(func_fe6_08089490),
    PROC_END,
};

void func_fe6_0808958C(ProcPtr parent)
{
    SpawnProcLocking(ProcScr_Unk_0868A0E4, parent);
}

void func_fe6_080895A0(u16 const * src, u16 * dst, int count)
{
    int i;

    for (i = 0; i < count * 0x10; i++)
        dst[i] = src[i];
}

void func_fe6_080895B8(u32 point)
{
    int i;

    point = point % 0x40;

    if ((point & 0x20) != 0)
        point = 0x20 - (point % 0x20);

    for (i = 1; i < 0x10; i++)
    {
        if (i < 8 || i > 10)
        {
            int r, g, b;
            u16 r_out, g_out, b_out;

            u16 source = gPal[OBPAL_OFFSET(OBJPAL_SAVEMENU_2) + i];
            int blend = gUnk_Savemenu_02000404[0x10 + i];

            b = (RGB5_MASK_B & source) * (0x20 - point);
            b += (RGB5_MASK_B & blend) * (point);
            b_out = RGB5_MASK_B & (b >> 5);

            g = (RGB5_MASK_G & source) * (0x20 - point);
            g += (RGB5_MASK_G & blend) * (point);
            g_out = RGB5_MASK_G & (g >> 5);

            r = (RGB5_MASK_R & source) * (0x20 - point);
            r += (RGB5_MASK_R & blend) * (point);
            r_out = RGB5_MASK_R & (r >> 5);

            gPal[OBPAL_OFFSET(OBJPAL_SAVEMENU_1) + i] = b_out | g_out | r_out;
        }
    }

    EnablePalSync();
}

u16 CONST_DATA Sprite_0868A0FC[] =
{
    4,
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x80) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x81) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(64), OAM2_CHR(0x81) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(96), OAM2_CHR(0x82) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A116[] =
{
    3,
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x80) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x81) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(64), OAM2_CHR(0x82) + OAM2_LAYER(1),
};

// unused?
u16 CONST_DATA Sprite_0868A12A[] =
{
    6,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x80) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x82) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16 + OAM0_Y(16), OAM1_SIZE_32x16, OAM2_CHR(0xA0) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16 + OAM0_Y(16), OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0xA2) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16, OAM2_CHR(0xC0) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0xC2) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A150[] =
{
    1,
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x11C),
};

u16 CONST_DATA Sprite_0868A158[] =
{
    1,
    OAM0_SHAPE_32x32 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x32 + OAM1_AFFINE_ID(3), OAM2_CHR(0x158) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A160[] =
{
    3,
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x100) + OAM2_LAYER(1),
    OAM0_SHAPE_16x32, OAM1_SIZE_16x32 + OAM1_X(32), OAM2_CHR(0x101) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(48), OAM2_CHR(0x102) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A174[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x9E) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A17C[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x9F) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A184[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xBE) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A18C[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xBF) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A194[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xDE) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A19C[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xDF) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1A4[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xFE) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1AC[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xFF) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1B4[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x188) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1BC[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x189) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1C4[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x18A) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1CC[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x146) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1D4[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x147) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1DC[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x148) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1E4[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x149) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1EC[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14A) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1F4[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14B) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1FC[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14C) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A204[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14D) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A20C[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14E) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A214[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x14F) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A21C[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x150) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A224[] =
{
    2,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8, OAM2_CHR(0x180) + OAM2_LAYER(1),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(32), OAM2_CHR(0x184) + OAM2_LAYER(1),
};

u16 const * CONST_DATA gUnk_0868A234[] =
{
    Sprite_0868A174,
    Sprite_0868A17C,
    Sprite_0868A184,
    Sprite_0868A18C,
    Sprite_0868A194,
    Sprite_0868A19C,
    Sprite_0868A1A4,
    Sprite_0868A1AC,
    Sprite_0868A1B4,
    Sprite_0868A1BC,
    Sprite_0868A1C4,
};

u16 const * CONST_DATA gUnk_0868A260[] =
{
    Sprite_0868A1CC,
    Sprite_0868A1D4,
    Sprite_0868A1DC,
    Sprite_0868A1E4,
    Sprite_0868A1EC,
    Sprite_0868A1F4,
    Sprite_0868A1FC,
    Sprite_0868A204,
    Sprite_0868A20C,
    Sprite_0868A214,
    Sprite_0868A21C,
};

void func_fe6_08089684(ProcPtr proc)
{
    struct SaveMenuProc * sm_proc = ((struct GenericProc *) proc)->proc_parent;

    fu8 y, x;
    u16 hours, minutes, seconds;

    y = (0x20 - (sm_proc->unk_2F * 0x20 / 220));
    y = y + 144;
    x = 144;

    if (sm_proc->unk_2E == 1)
    {
        FormatTime(sm_proc->unk_50, &hours, &minutes, &seconds);
    }
    else
    {
        FormatTime(sm_proc->unk_44[sm_proc->selected_id], &hours, &minutes, &seconds);
    }

    PutSpriteExt(13, x + 0x10, y - 14, Sprite_0868A160, OAM2_PAL(2));
    PutSpriteExt(13, x + 0x14, y - 14, Sprite_0868A224, OAM2_PAL(5));

    if (hours >= 100)
    {
        PutSpriteExt(13, x + 0x12, y - 8, gUnk_0868A260[hours / 100], OAM2_PAL(5));
        hours = hours - (hours / 100 * 100); // sure, 'hours % 100' would have been fine too
    }

    if (hours >= 10)
    {
        PutSpriteExt(13, x + 0x1A, y - 8, gUnk_0868A260[hours / 10], OAM2_PAL(5));
    }

    PutSpriteExt(13, x + 0x22, y - 8, gUnk_0868A260[hours % 10], OAM2_PAL(5));

    PutSpriteExt(13, x + 0x2A, y - 7, gUnk_0868A260[10], OAM2_PAL(5));

    PutSpriteExt(13, x + 0x32, y - 8, gUnk_0868A260[minutes / 10], OAM2_PAL(5));
    PutSpriteExt(13, x + 0x3A, y - 8, gUnk_0868A260[minutes % 10], OAM2_PAL(5));

    PutSpriteExt(13, x + 0x42, y + 1, gUnk_0868A234[10], OAM2_PAL(5));

    PutSpriteExt(13, x + 0x4A, y, gUnk_0868A234[seconds / 10], OAM2_PAL(5));
    PutSpriteExt(13, x + 0x52, y, gUnk_0868A234[seconds % 10], OAM2_PAL(5));
}

void func_fe6_08089894(fu8 bg, i32 scr_x, i32 scr_y, i32 tex_x, i32 tex_y, fi16 angle, fi16 scale)
{
    struct BgAffineSetSrc affine_src;

    affine_src.tex_x = tex_x;
    affine_src.tex_y = tex_y;
    affine_src.scr_x = scr_x >> 8;
    affine_src.scr_y = scr_y >> 8;
    affine_src.sx = 0x10000 / scale;
    affine_src.sy = 0x10000 / scale;
    affine_src.alpha = angle << 6;

    // TODO: put proper affine structs inside gDispIo instead of using bg[23]pa directly
    BgAffineSet(&affine_src, (bg == 2) ? (void *)&gDispIo.bg2pa : (void *)&gDispIo.bg3pa, 1);
}

void func_fe6_080898F0(struct UnkProc_0868A28C * proc)
{
    fu8 i;

    proc->unk_2C = 0;
    proc->unk_2E = 0x100;

    proc->unk_3A = 0;
    proc->unk_3B = 40;

    func_fe6_08070D48(0xAC << 4);

    for (i = 0; i < 3; i++)
    {
        // TODO: make sense of these constants

        if (proc->proc_parent->unk_37[i] != 0xFF)
        {
            func_fe6_08070D08(((u32) (0x16800 + 0x800 * i) & 0x1FFFF) >> 5,
                proc->proc_parent->unk_37[i]);
        }
        else
        {
            func_fe6_08070D08(((u32) (0x16800 + 0x800 * i) & 0x1FFFF) >> 5, -1);
        }
    }

    proc->unk_30 = 0;
    proc->unk_32 = 0;

    SetObjAffine(0, 0x100, 0, 0, 0x100);
    SetObjAffine(1, 0x100, 0, 0, 0x100);
    SetObjAffine(2, 0x100, 0, 0, 0x100);

    proc->unk_2A = 0;

    proc->unk_34 = func_fe6_0808A418(proc);
    proc->unk_39 = 0;

    if (proc->proc_parent->unk_3F == 0xFF)
    {
        proc->proc_parent->unk_5C = NULL;
    }
    else
    {
        proc->proc_parent->unk_5C = StartSpriteAnimProc(
            gUnk_0832C39C, 320, 0x30 + proc->proc_parent->unk_3F * 0x20, 0x1A0, 0, 4);
    }

    proc->unk_3C = proc->proc_parent->selected_id;
}

void func_fe6_080899F0(bool arg_0, fu16 arg_1)
{
    if (arg_0)
    {
        gPal[OBPAL_OFFSET(6) + 8] = gPal[OBPAL_OFFSET(9) + (arg_1 / 4) % 0x10];
    }
    else
    {
        gPal[OBPAL_OFFSET(6) + 8] = gPal[OBPAL_OFFSET(9) + 13];
    }

    EnablePalSync();
}

void func_fe6_08089A3C(ProcPtr proc, int x, int y, fu8 arg_3, fu8 pal_a, fu8 pal_b)
{
    PutSpriteExt(4, OAM1_X(x), y, Sprite_0868A0FC, OAM2_PAL(pal_a));

    PutSpriteExt(4, OAM1_X(x + 8 + gUnk_0868A518[arg_3].unk_04), y + 8,
        gUnk_0868A518[arg_3].sprite, OAM2_PAL(pal_b));
}

void func_fe6_08089ABC(ProcPtr proc, int x, int y, fu8 arg_3, fu8 pal_a, fu8 pal_b)
{
    PutSpriteExt(4, OAM1_X(x), y, Sprite_0868A0FC, OAM2_PAL(pal_a));

    PutSpriteExt(4, OAM1_X(x + 8 + gUnk_0868A4F8[arg_3].unk_04), y + 8,
        gUnk_0868A4F8[arg_3].sprite, OAM2_PAL(pal_b));
}

void func_fe6_08089B3C(struct UnkProc_0868A28C * proc)
{
    if (proc->unk_3C != proc->proc_parent->selected_id)
    {
        func_fe6_0808A9F4(proc->proc_parent->selected_id);
        proc->unk_3C = proc->proc_parent->selected_id;
    }

    gPal[OBPAL_OFFSET(1) + 10] = gUnk_Savemenu_02000404[(proc->unk_2A / 4) % 0x10];
    EnablePalSync();

    if (proc->proc_parent->unk_3F != 0xFF && proc->proc_parent->unk_40 != 0x100)
    {
        if (proc->proc_parent->unk_40 < 0x10)
        {
            proc->proc_parent->unk_3F = 0xFF;
        }
        else
        {
            // angle = scale???
            SetObjAffineAuto(3, proc->proc_parent->unk_40, proc->proc_parent->unk_40, proc->proc_parent->unk_40);
        }

        proc->proc_parent->unk_40 -= 0x10;
    }

    func_fe6_080895B8(proc->unk_2A);
    proc->unk_2A++;
}

void func_fe6_08089C70(struct UnkProc_0868A28C * proc)
{
    fu8 id;
    fu16 y;

    y = (0x100 + (0xD0 + proc->proc_parent->unk_2F * 48 / 220)) & 0x1FF;

    PutSpriteExt(4, 0x38, y, Sprite_0868A0FC, OAM2_PAL(2));

    if (proc->proc_parent->unk_42 != 0)
    {
        id = func_fe6_08087CB0(proc->proc_parent->unk_35);

        PutSpriteExt(4, 0x40 + gUnk_0868A518[id].unk_04, (y + 8) & 0x1FF,
            gUnk_0868A4F8[id].sprite, OAM2_PAL(3));
    }
    else
    {
        id = func_fe6_08087CB0(proc->proc_parent->unk_2E);

        PutSpriteExt(4, 0x40 + gUnk_0868A518[id].unk_04, (y + 8) & 0x1FF,
            gUnk_0868A518[id].sprite, OAM2_PAL(3));
    }
}

void func_fe6_08089D30(struct UnkProc_0868A28C * proc)
{
    // TODO: clean up

    fu8 i;
    fu8 id;
    int r5;
    fu8 r4;

    if (proc->proc_parent->unk_2E < 0x80)
    {
        if (proc->proc_parent->unk_2E == 0x20)
        {
            proc->unk_33 = proc->proc_parent->unk_35;
        }
        else
        {
            proc->unk_33 = proc->proc_parent->unk_2E;
        }
    }

    r5 = proc->proc_parent->unk_2F + proc->proc_parent->unk_42;

    if (r5 < 0xDC)
    {
        r4 = (6 - proc->proc_parent->unk_31) * 8;

        for (i = 0; i < proc->proc_parent->unk_31; i++)
        {
            id = func_fe6_08087C78(proc->proc_parent->unk_30, i);
            id = func_fe6_08087CB0(id);

            if (i == proc->proc_parent->unk_2A)
            {
                func_fe6_08089A3C(proc, 0x38 - r5, r4 + i * 24, id, 1, 3);
            }
            else
            {
                func_fe6_08089A3C(proc, 0x38 - r5, r4 + i * 24, id, 4, 8);
            }
        }

        if (proc->proc_parent->unk_2D == 1)
        {
            func_fe6_0808A3C8(0, 0x24, r4 + proc->proc_parent->unk_2A * 24, proc);
        }
    }

    if (proc->proc_parent->unk_42 > 0 && proc->proc_parent->unk_42 < 0x1B8)
    {
        r4 = (6 - proc->proc_parent->unk_33) * 8;

        for (i = 0; i < proc->proc_parent->unk_33; i++)
        {
            id = func_fe6_08087C78(proc->proc_parent->unk_32, i);
            id = func_fe6_08087CB0(id);

            if (i == proc->proc_parent->unk_34)
            {
                func_fe6_08089ABC(proc, 0x114 - proc->proc_parent->unk_42, r4 + i * 26, id, 1, 3);
            }
            else
            {
                func_fe6_08089ABC(proc, 0x114 - proc->proc_parent->unk_42, r4 + i * 26, id, 4, 8);
            }
        }

        if (proc->proc_parent->unk_2D == 9)
        {
            func_fe6_0808A3C8(0, 0x24, r4 + proc->proc_parent->unk_34 * 26, proc);
        }
    }

    if (proc->proc_parent->unk_2F != 0)
    {
        func_fe6_08089684(proc);
        func_fe6_08089C70(proc);

        for (i = 0; i < 3; i++)
        {
            u32 r2 = (proc->proc_parent->unk_2D == 5 && proc->proc_parent->selected_id == i) ? 0x100 : 0;

            PutSpriteExt(4, OAM1_X(0xF4 - proc->proc_parent->unk_2F), 0x20 + r2 + i * 0x20, gUnk_0868A55C[i], OAM2_PAL(10 + i * 2));
            PutSpriteExt(4, OAM1_X(0xF4 - proc->proc_parent->unk_2F), 0x20 + r2 + i * 0x20 + 8, gUnk_0868A550[i], OAM2_PAL(11 + i * 2));
        }

        if (proc->proc_parent->unk_3F != 0xFF)
        {
            if (proc->proc_parent->unk_40 != 0x100)
            {
                if (proc->proc_parent->unk_5C != NULL)
                {
                    EndSpriteAnimProc(proc->proc_parent->unk_5C);
                    proc->proc_parent->unk_5C = NULL;
                }

                if (proc->proc_parent->unk_2E == 1)
                {
                    PutSpriteExt(4, 0xC2, 0x1E + proc->proc_parent->unk_3F * 0x20, Sprite_0868A158, 0);
                }
                else
                {
                    PutSpriteExt(4, 0xC2, 0x1E + proc->proc_parent->unk_3F * 0x20, Sprite_0868A158, OAM2_PAL(6));
                }
            }
            else
            {
                if (proc->proc_parent->unk_2E == 1)
                {
                    SetSpriteAnimProcParameters(proc->proc_parent->unk_5C,
                        0x1AC - proc->proc_parent->unk_2F, 0x34 + proc->proc_parent->unk_3F * 0x20, 0x1A0);
                }
                else
                {
                    SetSpriteAnimProcParameters(proc->proc_parent->unk_5C,
                        0x140, 0x34 + proc->proc_parent->unk_3F * 0x20, 0x1A0);

                    PutSpriteExt(4, 0x19E - proc->proc_parent->unk_2F, 0x1E + proc->proc_parent->unk_3F * 0x20,
                        Sprite_0868A158, OAM2_PAL(6));
                }
            }
        }
    }

    if (proc->proc_parent->unk_2D == 4 || proc->proc_parent->unk_2D == 5)
    {
        if (proc->proc_parent->unk_36 != 0)
        {
            int tmp;
            PutSpriteExt(4, 0x28, 0x80, Sprite_0868A116, 0x2000);

            tmp = proc->proc_parent->unk_36 - 1;
            PutUiHand(0x34 + (tmp - tmp / 2 * 2) * 0x28, 0x88);

            func_fe6_0808A3C8(1, 12, 0x20 + proc->proc_parent->selected_id * 0x20, proc);
        }
        else
        {
            if (proc->proc_parent->selected_id != 0xFF)
            {
                func_fe6_0808A3C8(1, 12, 0x20 + proc->proc_parent->selected_id * 0x20, proc);
            }
        }

        if (proc->proc_parent->copy_from_id != 0xFF)
        {
            func_fe6_0808A3E8(1, 0x20 + proc->proc_parent->copy_from_id * 0x20, proc);
        }
    }

    func_fe6_08089B3C(proc);
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A28C[] =
{
    PROC_19,
    PROC_CALL(func_fe6_080898F0),
    PROC_REPEAT(func_fe6_08089D30),
    PROC_END,
};

struct UnkProc_0868A28C * func_fe6_0808A14C(struct SaveMenuProc * parent)
{
    return SpawnProc(ProcScr_Unk_0868A28C, parent);
}

void func_fe6_0808A160(struct UnkProc_0868A2AC * proc)
{
    proc->unk_39 = 0;
    proc->unk_2A = 0;
    proc->unk_35 = 0;
    proc->unk_36 = 0;
    proc->unk_37 = 0;
    proc->unk_38 = 0;
    proc->unk_3A = 0;
    proc->unk_3B = 0;
    proc->unk_3D = 0;
    proc->unk_34 = 0;
}

void func_fe6_0808A194(struct UnkProc_0868A2AC * proc)
{
    SHOULD_BE_STATIC u8 SHOULD_BE_CONST ALIGNED(4) unk_08336C74[8] =
    {
        0, 1, 2, 3,
        3, 2, 1, 0,
    };

    proc->unk_2A++;
    proc->unk_2C++;

    func_fe6_08089894(2, 0x7800, 0x14000, 0x4C00, 0x4C00, proc->unk_2C, 0x180);

    gDispIo.bg2pb *= 2;
    gDispIo.bg2pd *= 2;

    // TODO: this is bad, esp. for MODERN
    #define SET_REG(type, reg, src) *((type*) &REG_##reg) = *((type*) &(src))

    SET_REG(u32, BG2PA, gDispIo.bg2pa); // set both with a single 32-bit copy
    SET_REG(u32, BG2PC, gDispIo.bg2pc); // set both with a single 32-bit copy
    SET_REG(u32, BG2X,  gDispIo.bg2x);
    SET_REG(u32, BG2Y,  gDispIo.bg2y);

    #undef SET_REG
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A2AC[] =
{
    PROC_19,
    PROC_CALL(func_fe6_0808A160),
    PROC_REPEAT(func_fe6_0808A194),
    PROC_END,
};

struct UnkProc_0868A2AC * func_fe6_0808A210(struct SaveMenuProc * parent)
{
    struct UnkProc_0868A2AC * proc;

    proc = SpawnProc(ProcScr_Unk_0868A2AC, PROC_TREE_VSYNC);
    proc->sm_proc = parent;

    return proc;
}

void func_fe6_0808A228(struct UnkProc_0868A2CC * proc)
{
    proc->unk_31 = 0;
    proc->unk_2A = 0;
    proc->unk_2D = 0;
    proc->unk_2E = 0;
    proc->unk_2F = 0;
    proc->unk_30 = 0;
    proc->unk_32 = 0;
    proc->unk_33 = 0;
    proc->unk_35 = 0;
    proc->unk_2C = 0;
}

void func_fe6_0808A25C(struct UnkProc_0868A2CC * proc)
{
    SHOULD_BE_STATIC u8 SHOULD_BE_CONST ALIGNED(4) unk_08336C74[8] =
    {
        0, 1, 2, 3,
        3, 2, 1, 0,
    };

    proc->unk_2A++;

    if (proc->unk_2C < 4)
        proc->unk_2C++;

    if (proc->unk_31 != 0)
    {
        fu8 r8 = proc->unk_2F;
        fu8 r5 = proc->unk_2D;
        fu8 r6;

        if (proc->unk_2C < 4)
        {
            r8 = (r8 + proc->unk_30) / 2;
            r5 = (r5 + proc->unk_2E) / 2;
        }

        if (proc->unk_35 == 0)
        {
            r6 = 0x86 + r5;
        }
        else
        {
            r6 = 0xB8 + r5;
        }

        proc->unk_30 = proc->unk_2F;
        proc->unk_2E = proc->unk_2D;

        if (proc->unk_35 == 0)
        {
            PutSpriteExt(4, r5, unk_08336C74[(proc->unk_2A / 8) & 7] + r8, Sprite_0868A150, OAM2_PAL(1));
            PutSpriteExt(4, r6 | OAM1_HFLIP, unk_08336C74[(proc->unk_2A / 8) & 7] + r8, Sprite_0868A150, OAM2_PAL(1));
        }
        else
        {
            PutSpriteExt(4, r5, unk_08336C74[(proc->unk_2A / 8) & 7] + r8, Sprite_0868A150, OAM2_PAL(2));
        }

        proc->unk_2C = 0;
    }
    else
    {
        if (proc->unk_2C == 4)
            proc->unk_31 = 0;
    }

    if (proc->unk_33 != 0)
    {
        PutSpriteExt(4, 12, proc->unk_32, Sprite_0868A150, OAM2_PAL(2));
    }

    if (proc->unk_34 != 0)
        proc->unk_33 = 0;

    proc->unk_31 = 0;
    proc->unk_34 = 1;
}

void func_fe6_0808A3C8(int a, int b, fu8 c, struct UnkProc_0868A28C * proc)
{
    struct UnkProc_0868A2CC * self = proc->unk_34;

    self->unk_2F = c;
    self->unk_2D = b;
    self->unk_31 = 1;
    self->unk_35 = a;
}

void func_fe6_0808A3E8(int a, fu8 b, struct UnkProc_0868A28C * proc)
{
    struct UnkProc_0868A2CC * self = proc->unk_34;

    self->unk_32 = b;
    self->unk_33 = 1;
    self->unk_35 = a;
    self->unk_34 = 0;
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A2CC[] =
{
    PROC_19,
    PROC_CALL(func_fe6_0808A228),
    PROC_REPEAT(func_fe6_0808A25C),
    PROC_END,
};

struct UnkProc_0868A2CC * func_fe6_0808A418(ProcPtr parent)
{
    return SpawnProc(ProcScr_Unk_0868A2CC, parent);
}

void func_fe6_0808A42C(void)
{
    InitTextFont(&gSaveMenuFont, (void *) VRAM + 0x601 * 0x20, 1, 0);
    InitText(&gSaveMenuText, 10);
}

void func_fe6_0808A454(char const * string, bool display)
{
    if (display)
    {
        SetTextFont(&gSaveMenuFont);
        ClearText(&gSaveMenuText);
        Text_SetCursor(&gSaveMenuText, 0);
        Text_SetColor(&gSaveMenuText, 0);
        Text_DrawString(&gSaveMenuText, string);
        PutText(&gSaveMenuText, gBg1Tm + TM_OFFSET(7, 17));
    }
    else
    {
        TmFillRect(gBg1Tm + TM_OFFSET(7, 17), 10, 1, 0);
    }

    EnableBgSync(BG1_SYNC_BIT);
}

char const * CONST_DATA SaveMenuPromptTextTable[] =
{
    [SAVEMENU_PROMPT_0] = JTEXT(""),
    [SAVEMENU_PROMPT_1] = JTEXT("はじめる　やめる"),
    [SAVEMENU_PROMPT_2] = JTEXT("うつす　　やめる"),
    [SAVEMENU_PROMPT_3] = JTEXT("消す　　　やめる"),
    [SAVEMENU_PROMPT_4] = JTEXT("はじめる　やめる"),
    [SAVEMENU_PROMPT_5] = JTEXT("はじめる　やめる"),
    [SAVEMENU_PROMPT_6] = JTEXT("記録　　　やめる"),
};

void func_fe6_0808A4B8(struct SaveMenuProc * proc, bool display)
{
    func_fe6_0808A454(SaveMenuPromptTextTable[func_fe6_08087CB0(proc->unk_2E)], display);

    if (!display)
        proc->unk_36 = 0;
}

void func_fe6_0808A4F0(void)
{
    CpuFastFill(0, (void *) VRAM + 0x8000, 0x40 * 0x20);
    CpuFastFill(0, (void *) VRAM + 0xC000, 0x40 * 0x20);
}

void func_fe6_0808A524(struct SaveMenuProc * proc)
{
    int i, save_count = 0;

    proc->unk_31 = 0;
    proc->unk_30 = 0;
    proc->unk_32 = 0;
    proc->unk_33 = 0;

    if (proc->unk_40 == 0x100)
    {
        proc->unk_30 |= 1;
        proc->unk_31++;
    }

    for (i = 0; i < 3; i++)
    {
        if (proc->unk_37[i] != 0xFF)
            save_count++;
    }

    if (save_count > 0)
    {
        proc->unk_30 |= 2;
        proc->unk_31++;

        if (save_count < 3)
        {
            proc->unk_30 |= 4;
            proc->unk_31++;
        }

        proc->unk_30 |= 8;
        proc->unk_31++;
    }

    if (save_count < 3)
    {
        proc->unk_30 |= 16;
        proc->unk_31++;
    }

    if (func_fe6_08084714())
    {
        proc->unk_32 |= 4;
        proc->unk_33++;
    }

    if (IsMultiArenaAvailable())
    {
        proc->unk_32 |= 2;
        proc->unk_33++;
    }

    if (IsNotFirstPlaythrough_2())
    {
        proc->unk_32 |= 8;
        proc->unk_33++;
    }

    if (CheckHasCompletedSave())
    {
        proc->unk_32 |= 1;
        proc->unk_33++;
    }

    if (proc->unk_32 != 0)
    {
        proc->unk_30 |= 32;
        proc->unk_31++;
    }
}

fu8 func_fe6_0808A658(fu8 save_id, bool valid, fi8 direction)
{
    fu8 i;

    if (direction > 0)
    {
        for (i = 0; i < 3; i++)
        {
            if (IsSaveValid(save_id) == valid)
                return save_id;

            if (save_id == 2)
                save_id = 0;
            else
                save_id++;
        }
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            if (IsSaveValid(save_id) == valid)
                return save_id;

            if (save_id == 0)
                save_id = 2;
            else
                save_id--;
        }
    }

    return UINT8_MAX;
}

bool func_fe6_0808A6C8(struct SaveMenuProc * proc, fi8 direction)
{
    int valid = FALSE;
    fu8 prev_selected_id = proc->selected_id;

    switch (proc->unk_2E)
    {
        case UNK_SAVEMENU_0:
            return FALSE;

        case UNK_SAVEMENU_1:
            valid = TRUE;
            break;

        case UNK_SAVEMENU_2:
            if (proc->copy_from_id == 0xFF)
                valid = TRUE;
            else
                valid = FALSE;
            break;

        case UNK_SAVEMENU_3:
            valid = TRUE;
            break;

        case UNK_SAVEMENU_4:
            valid = FALSE;
            break;
    }

    if (direction > 0)
    {
        if (proc->selected_id == 2)
            proc->selected_id = 0;
        else
            proc->selected_id++;
    }
    else
    {
        if (proc->selected_id == 0)
            proc->selected_id = 2;
        else
            proc->selected_id--;
    }

    if (proc->unk_2E == UNK_SAVEMENU_6)
        return TRUE;

    proc->selected_id = func_fe6_0808A658(proc->selected_id, valid, direction);

    if (prev_selected_id == proc->selected_id)
        return FALSE;

    return TRUE;
}

bool func_fe6_0808A79C(struct SaveMenuProc * proc)
{
    if ((proc->unk_2E & proc->unk_30) != 0)
        return TRUE;

    return FALSE;
}

struct UnkProc_0868A308
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 clock;
    /* 2A */ i8 anim_direction;
    /* 2B */ u8 anim_speed;
};

void func_fe6_0808A7B8(struct UnkProc_0868A308 * proc)
{
    // this function makes the following assumption
    STATIC_ASSERT(DISPLAY_WIDTH / 3 == DISPLAY_HEIGHT / 2);

    proc->clock += proc->anim_speed;

    SetWinEnable(0, 1, 0);

    if (proc->anim_direction > 0)
    {
        SetWin1Box(
            proc->clock * 3, proc->clock * 2,
            DISPLAY_WIDTH - proc->clock * 3, DISPLAY_HEIGHT - proc->clock * 2);
    }
    else
    {
        SetWin1Box(
            (DISPLAY_WIDTH / 2) - proc->clock * 3, (DISPLAY_HEIGHT / 2) - proc->clock * 2,
            (DISPLAY_WIDTH / 2) + proc->clock * 3, (DISPLAY_HEIGHT / 2) + proc->clock * 2);
    }

    SetWin1Layers(1, 1, 1, 1, 1);
    SetWOutLayers(0, 0, 0, 0, 0);

    if (proc->clock >= (DISPLAY_WIDTH / 6))
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A308[] =
{
    PROC_19,
    PROC_SLEEP(1),
    PROC_REPEAT(func_fe6_0808A7B8),
    PROC_END,
};

void func_fe6_0808A8B4(ProcPtr parent, fi8 anim_direction, fu8 anim_speed)
{
    struct UnkProc_0868A308 * proc;

    proc = SpawnProcLocking(ProcScr_Unk_0868A308, parent);

    proc->anim_direction = anim_direction;
    proc->anim_speed = anim_speed;
    proc->clock = 0;
}

void func_fe6_0808A8E8(ProcPtr proc)
{
    RegisterDataMove(gBg2Tm, (void *) VRAM + 0x7000, sizeof(gBg2Tm));
}

struct ProcScr CONST_DATA ProcScr_Unk_0868A328[] =
{
    PROC_19,
    PROC_SLEEP(1),
    PROC_REPEAT(func_fe6_0808A8E8),
    PROC_END,
};

ProcPtr func_fe6_0808A904(ProcPtr parent)
{
    return SpawnProc(ProcScr_Unk_0868A328, parent);
}

void func_fe6_0808A918(fu8 save_id, struct SaveMenuProc * proc)
{
    struct PlaySt play_st;

    if (save_id < 3)
    {
        if (IsSaveValid(save_id))
        {
            ReadGameSavePlaySt(save_id, &play_st);

            proc->unk_37[save_id] = func_fe6_08070E0C(&play_st);
            proc->unk_44[save_id] = play_st.time_saved;

            if ((play_st.flags & PLAY_FLAG_COMPLETE) != 0)
                proc->unk_3A[save_id] = 1;
            else
                proc->unk_3A[save_id] = 0;

            gUnk_Savemenu_02000464[save_id] = play_st.flags;
        }
        else
        {
            proc->unk_37[save_id] = 0xFF;
            proc->unk_3A[save_id] = 0;
            proc->unk_44[save_id] = 0;
            gUnk_Savemenu_02000464[save_id] = 0;
        }
    }
    else if (proc->unk_40 == 0x100)
    {
        if (IsValidSuspendSave(SAVE_SUSPEND))
        {
            ReadSuspendSavePlaySt(SAVE_SUSPEND, &play_st);
            proc->unk_3F = play_st.save_id;
            proc->unk_50 = play_st.time_saved;
        }
        else
        {
            proc->unk_40 = 0xF0;
        }
    }
}

void func_fe6_0808A9F4(fu8 save_id)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        fu8 flags = (gUnk_Savemenu_02000464[i] & PLAY_FLAG_HARD) != 0 ? 4 : 0;

        if (i != save_id)
            flags |= 2;

        func_fe6_08070CB4(flags | 1, 0x1A + i * 2);
        func_fe6_08070CB4(flags | 0, 0x1B + i * 2);
    }

    EnablePalSync();
}

fu8 func_fe6_0808AA54(fu8 end_mask, struct SaveMenuProc * proc)
{
    int mask, count = 0;

    for (mask = 1; mask < end_mask; mask <<= 1)
    {
        if ((proc->unk_30 & mask) != 0)
            count++;
    }

    return count;
}
