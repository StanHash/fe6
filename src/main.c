
#include "gba/gba.h"

#include "m4a.h"

#include "irq.h"
#include "random.h"
#include "hardware.h"
#include "ramfunc.h"
#include "proc.h"

void sub_80127C8(void);
void sub_805F7E4(void);
void sub_80841FC(void);
void sub_808439C(void);

void StartGameControl(void);

void sub_80158C0(void);

s8 LoadGeneralGameMetadata(void* buf);

NAKEDFUNC void AgbMain(void)
{
    // NOTE: ?????
    asm("\n\
        sub sp, #0x10\n\
        push {r4, lr}\n\
        add r4, sp, #0x18\n\
        str r4, [sp, #0x0C]\n\
        mov r4, pc\n\
        str r4, [sp, #0x14]\n\
        mov r4, r11\n\
        str r4, [sp, #0x08]\n\
        mov r4, lr\n\
        str r4, [sp, #0x10]\n\
        add r4, sp, #0x14\n\
        mov r11, r4\n\
        sub sp, sp, #4\n\
    ");

    // clear RAM
    DmaFill32(3, 0, (void*) IWRAM_START, 0x7F80);
    CpuFastFill(0, (void*) EWRAM_START, 0x40000);

    REG_WAITCNT = 0x45B4;

    IrqInit();
    SetOnVBlank(NULL);

    REG_DISPSTAT = 8;
    REG_IME = 1;

    InitKeySt(gKeySt);
    RefreshKeySt(gKeySt);

    InitRamFuncs();
    sub_80841FC();
    InitProcs();
    sub_80127C8();
    sub_805F7E4();

    RandInitB(0x42D690E9);
    RandInit(RandNextB());

    if (!LoadGeneralGameMetadata(NULL))
        sub_808439C();

    m4aSoundInit();
    SetOnVBlank(sub_80158C0);

    StartGameControl();

    while (TRUE)
    {
        RunMainFunc();
        SoftResetIfKeyCombo();
    }
}

static char const sDbgLineA[] = "2002/03/02(SAT) 11:15:03";
static char const sDbgLineB[] = "NARIHIRO";

NAKEDFUNC void sub_8000AFC(void)
{
    asm("\n\
        .syntax unified\n\
        sub sp, #0x10\n\
        push {r4, lr}\n\
        add r4, sp, #0x18\n\
        str r4, [sp, #0xc]\n\
        mov r4, pc\n\
        str r4, [sp, #0x14]\n\
        mov r4, fp\n\
        str r4, [sp, #8]\n\
        mov r4, lr\n\
        str r4, [sp, #0x10]\n\
        add r4, sp, #0x14\n\
        mov fp, r4\n\
        adds r4, r0, #0\n\
        ldr r1, _08000B30 @ =sDbgLineA\n\
        bl DebugPutStr\n\
        subs r4, #0x40\n\
        ldr r1, _08000B34 @ =sDbgLineB\n\
        adds r0, r4, #0\n\
        bl DebugPutStr\n\
        pop {r4}\n\
        pop {r0, r1, r2}\n\
        mov fp, r1\n\
        mov sp, r2\n\
        bx r0\n\
        .align 2, 0\n\
    _08000B30: .4byte sDbgLineA\n\
    _08000B34: .4byte sDbgLineB\n\
        .syntax divided\n\
    ");
}
