
#include "gba/gba.h"

#include "hardware.h"

struct UnkSprite
{
    /* 00 */ int oam01;
    /* 02 */ u16 oam2;
    /* 04 */ short x;
    /* 06 */ short y;
};

struct OamView { u16 oam0, oam1, oam2, aff; };

void InitOam(int loSz);
int GetOamSplice(void);
void SyncHiOam(void);
void SyncLoOam(void);
void SetObjAffine(int id, fi16 pa, fi16 pb, fi16 pc, fi16 pd);
void PutUnkSprite(struct UnkSprite * sprites, int xBase, int yBase);

extern u16 gOam[0x200];
extern u16 * gOamHiPutIt;
extern u16 * gOamLoPutIt;
extern struct OamView * gOamAffinePutIt;
extern u16 gOamAffinePutId;

#define OAM0_Y(ay)          ((ay) & 0x00FF)
#define OAM0_Y_MASK         0x00FF
#define OAM0_AFFINE_ENABLE  0x0100
#define OAM0_DOUBLESIZE     0x0200
#define OAM0_DISABLE        0x0200
#define OAM0_BLEND          0x0400
#define OAM0_WINDOW         0x0800
#define OAM0_MOSAIC         0x1000
#define OAM0_256COLORS      0x2000
#define OAM0_SHAPE_8x8      0x0000
#define OAM0_SHAPE_16x16    0x0000
#define OAM0_SHAPE_32x32    0x0000
#define OAM0_SHAPE_64x64    0x0000
#define OAM0_SHAPE_16x8     0x4000
#define OAM0_SHAPE_32x8     0x4000
#define OAM0_SHAPE_32x16    0x4000
#define OAM0_SHAPE_64x32    0x4000
#define OAM0_SHAPE_8x16     0x8000
#define OAM0_SHAPE_8x32     0x8000
#define OAM0_SHAPE_16x32    0x8000
#define OAM0_SHAPE_32x64    0x8000

#define OAM1_X(ax)          ((ax) & 0x01FF)
#define OAM1_X_MASK         0x01FF
#define OAM1_AFFINE_ID(ai)  (((ai) << 9) & 0x3E00)
#define OAM1_AFFINE_ID_MASK 0x3E00
#define OAM1_HFLIP          0x1000
#define OAM1_VFLIP          0x2000
#define OAM1_SIZE_8x8       0x0000
#define OAM1_SIZE_16x8      0x0000
#define OAM1_SIZE_8x16      0x0000
#define OAM1_SIZE_16x16     0x4000
#define OAM1_SIZE_32x8      0x4000
#define OAM1_SIZE_8x32      0x4000
#define OAM1_SIZE_32x32     0x8000
#define OAM1_SIZE_32x16     0x8000
#define OAM1_SIZE_16x32     0x8000
#define OAM1_SIZE_64x64     0xC000
#define OAM1_SIZE_64x32     0xC000
#define OAM1_SIZE_32x64     0xC000

#define OAM2_CHR(ac)        ((ac) & 0x03FF)
#define OAM2_CHR_MASK       0x03FF
#define OAM2_LAYER(al)      (((al) & 0x3) * 0x0400)
#define OAM2_LAYER_MASK     0xC000
#define OAM2_PAL(ap)        (((ap) & 0xF) * 0x1000)
#define OAM2_PAL_MASK       0xF000

#define SetObjAffineAuto(id, angle, x_scale, y_scale) \
    SetObjAffine((id), \
        Div(+COS_Q12((angle)) << 4, (x_scale)), \
        Div(-SIN_Q12((angle)) << 4, (y_scale)), \
        Div(+SIN_Q12((angle)) << 4, (x_scale)), \
        Div(+COS_Q12((angle)) << 4, (y_scale)))
