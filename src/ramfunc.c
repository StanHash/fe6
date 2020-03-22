
#include "ramfunc.h"
#include "armfunc.h"

extern u8 RamFuncArea[];

extern void(*DrawGlyphRamFunc)(u16 const* cvtLut, void* chr, u32 const* glyph, int offset);
extern void(*DecodeStringRamFunc)(char const* src, char* dst);
extern void(*PutOamHiRamFunc)(int x, int y, u16 const* oamList, int oam2);
extern void(*PutOamLoRamFunc)(int x, int y, u16 const* oamList, int oam2);
extern void(*MoveFillStepRamFunc)();
extern void(*MoveFillRamFunc)(void);

void InitRamFuncs(void)
{
    int size = ArmCodeEnd - ArmCodeStart;

    CpuCopy16(ArmCodeStart, RamFuncArea, size);

    DrawGlyphRamFunc    = (void*) RamFuncArea + (((u8*) DrawGlyph)    - ArmCodeStart);
    DecodeStringRamFunc = (void*) RamFuncArea + (((u8*) DecodeString) - ArmCodeStart);
    PutOamHiRamFunc     = (void*) RamFuncArea + (((u8*) PutOamHi)     - ArmCodeStart);
    PutOamLoRamFunc     = (void*) RamFuncArea + (((u8*) PutOamLo)     - ArmCodeStart);
    MoveFillStepRamFunc = (void*) RamFuncArea + (((u8*) MoveFillStep) - ArmCodeStart);
    MoveFillRamFunc     = (void*) RamFuncArea + (((u8*) MoveFill)     - ArmCodeStart);
}

void DrawGlyphRam(u16 const* cvtLut, void* chr, u32 const* glyph, int offset)
{
    DrawGlyphRamFunc(cvtLut, chr, glyph, offset);
}

void DecodeStringRam(char const* src, char* dst)
{
    DecodeStringRamFunc(src, dst);
}

void PutOamHiRam(int x, int y, u16 const* oamList, int oam2)
{
    PutOamHiRamFunc(x, y, oamList, oam2);
}

void PutOamLoRam(int x, int y, u16 const* oamList, int oam2)
{
    PutOamLoRamFunc(x, y, oamList, oam2);
}

void MoveFillStepRam(int arg0, int arg1, int arg2)
{
    MoveFillStepRamFunc(arg0, arg1, arg2);
}

void MoveFillRam(void)
{
    MoveFillRamFunc();
}
