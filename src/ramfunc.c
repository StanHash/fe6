
#include "ramfunc.h"
#include "armfunc.h"

extern u8 RamFuncArea[];

extern void (* DrawGlyphRamFunc)(u16 const * cvtLut, void * chr, u32 const * glyph, int offset);
extern void (* DecodeStringRamFunc)(char const * src, char * dst);
extern void (* PutOamHiRamFunc)(int x, int y, u16 const * oam_list, int oam2);
extern void (* PutOamLoRamFunc)(int x, int y, u16 const * oam_list, int oam2);
extern void (* MapFloodCoreStepRamFunc)();
extern void (* MapFloodCoreRamFunc)(void);

void InitRamFuncs(void)
{
    int size = ArmCodeEnd - ArmCodeStart;

    CpuCopy16(ArmCodeStart, RamFuncArea, size);

    DrawGlyphRamFunc        = (void *) RamFuncArea + (((u8 *) (void *) DrawGlyph)        - ArmCodeStart);
    DecodeStringRamFunc     = (void *) RamFuncArea + (((u8 *) (void *) DecodeString)     - ArmCodeStart);
    PutOamHiRamFunc         = (void *) RamFuncArea + (((u8 *) (void *) PutOamHi)         - ArmCodeStart);
    PutOamLoRamFunc         = (void *) RamFuncArea + (((u8 *) (void *) PutOamLo)         - ArmCodeStart);
    MapFloodCoreStepRamFunc = (void *) RamFuncArea + (((u8 *) (void *) MapFloodCoreStep) - ArmCodeStart);
    MapFloodCoreRamFunc     = (void *) RamFuncArea + (((u8 *) (void *) MapFloodCore)     - ArmCodeStart);
}

void DrawGlyphRam(u16 const * cvtLut, void * chr, u32 const * glyph, int offset)
{
    DrawGlyphRamFunc(cvtLut, chr, glyph, offset);
}

void DecodeStringRam(char const * src, char * dst)
{
    DecodeStringRamFunc(src, dst);
}

void PutOamHiRam(int x, int y, u16 const * oam_list, int oam2)
{
    PutOamHiRamFunc(x, y, oam_list, oam2);
}

void PutOamLoRam(int x, int y, u16 const * oam_list, int oam2)
{
    PutOamLoRamFunc(x, y, oam_list, oam2);
}

void MapFloodCoreStepRam(int connect, int x, int y)
{
    MapFloodCoreStepRamFunc(connect, x, y);
}

void MapFloodCoreRam(void)
{
    MapFloodCoreRamFunc();
}
