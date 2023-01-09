#include "save.h"

#include "sram.h"
#include "gbaio.h"
#include "util.h"

u8 EWRAM_DATA gUnk_0203D524[0xA] = {0};
i8 EWRAM_DATA gBoolSramWorking = 0;

void SramInit()
{
    u32 buf[2];
    buf[0] = 0x12345678;
    buf[1] = 0x87654321;

    SetSramFastFunc();
    REG_IE |= 0x2000;
    WriteSramFast((u8*)(&buf[0]), gpSramEntry + 0x6EF4, 4);
    (*ReadSramFast)(gpSramEntry + 0x6EF4,(u8*)(&buf[1]), 4);

    gBoolSramWorking = (buf[1] == buf[0])
                     ? 1
                     : 0;
}

bool IsSramWorking(void)
{
    return gBoolSramWorking;
}

void EraseSaveData()
{
    int buf[0x10];
    int i;

    for (i = 0; i < 0x10; i++)
        buf[i] = -1;

    for (i = 0; i < 0x200; i++)
        WriteAndVerifySramFast((u8*)buf, gpSramEntry + i * 0x40, 0x40);
}

u16 ComputeChecksum16(const u16* data, int size)
{
    int i;
    u32 addAcc = 0;
    u32 xorAcc = 0;
    
    for (i = 0; i < size/2; ++i) {
        addAcc += data[i];
        xorAcc ^= data[i];
    }
    
    return addAcc + xorAcc;
}

bool LoadGlobalSaveInfo(struct GlobalSaveInfo *saveInfo)
{
    struct GlobalSaveInfo info_;
    struct GlobalSaveInfo *info = saveInfo;

    if (!IsSramWorking())
        return 0;

    if (NULL == saveInfo)
        info = &info_;

    (*ReadSramFast)((u8*)gpSramEntry, (u8*)info, sizeof(struct GlobalSaveInfo));

    if ((0 != StringEquals(info->name, gGlobalSaveInfoName)) &&
        (0x11217 == info->magic_a) &&
        (0x200A == info->magic_b) &&
        (info->cksum16 == ComputeChecksum16((u16*)info, sizeof(struct GlobalSaveInfo) - 4)))
        return 1;

    return 0;
}

void SaveGlobalSaveInfo(struct GlobalSaveInfo *saveInfo)
{
    saveInfo->cksum16 = ComputeChecksum16((u16*)saveInfo, sizeof(struct GlobalSaveInfo) - 4);
    WriteAndVerifySramFast((u8*)saveInfo, gpSramEntry, sizeof(struct GlobalSaveInfo));
}

void SaveGlobalSaveInfoNoChecksum(struct GlobalSaveInfo *saveInfo)
{
    WriteAndVerifySramFast((u8*)saveInfo, gpSramEntry, sizeof(struct GlobalSaveInfo));
}

#if NONMATCHING

void InitGlobalSaveInfo()
{
    int i;
    struct GlobalSaveInfo info;

    EraseSaveData();
    StringCopy(info.name, gGlobalSaveInfoName);

    info.magic_a = 0x11217;
    info.magic_b = 0x200A;

    info.unk_0E_0 = 0;
    info.unk_0E_2 = 0;
    info.unk_0E_1 = 0;
    info.unk_0E_3 = 0;
    info.unk_0E_4 = 0;
    
    info.unk1F = 0;
    info.slot_sa = 0;
    info.slot_su = 0;

    for (i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
        info.unk_10[i] = 0;

    SaveGlobalSaveInfo(&info);
}

#else // if !NONMATCHING

NAKEDFUNC
void InitGlobalSaveInfo()
{
    asm("\
        .syntax unified\n\
        push {lr}\n\
        sub sp, #0x20\n\
        bl EraseSaveData\n\
        ldr r1, .L08084408\n\
        mov r0, sp\n\
        bl StringCopy\n\
        ldr r0, .L0808440C\n\
        str r0, [sp, #8]\n\
        mov r1, sp\n\
        movs r3, #0\n\
        ldr r0, .L08084410\n\
        strh r0, [r1, #0xc]\n\
        movs r0, #2\n\
        rsbs r0, r0, #0\n\
        ldrb r2, [r1, #0xe]\n\
        ands r0, r2\n\
        strb r0, [r1, #0xe]\n\
        mov r2, sp\n\
        movs r1, #5\n\
        rsbs r1, r1, #0\n\
        ands r1, r0\n\
        strb r1, [r2, #0xe]\n\
        mov r0, sp\n\
        movs r2, #3\n\
        rsbs r2, r2, #0\n\
        ands r2, r1\n\
        strb r2, [r0, #0xe]\n\
        mov r1, sp\n\
        movs r0, #9\n\
        rsbs r0, r0, #0\n\
        ands r0, r2\n\
        strb r0, [r1, #0xe]\n\
        movs r0, #0xf\n\
        ldrh r2, [r1, #0xe]\n\
        ands r0, r2\n\
        strh r0, [r1, #0xe]\n\
        mov r0, sp\n\
        strb r3, [r0, #0x1f]\n\
        strb r3, [r0, #0x1e]\n\
        add r1, sp, #0x10\n\
        movs r2, #0\n\
        adds r0, #0x1b\n\
    .L080843F4:\n\
        strb r2, [r0]\n\
        subs r0, #1\n\
        cmp r0, r1\n\
        bge .L080843F4\n\
        mov r0, sp\n\
        bl SaveGlobalSaveInfo\n\
        add sp, #0x20\n\
        pop {r0}\n\
        bx r0\n\
        .align 2, 0\n\
    .L08084408: .4byte gGlobalSaveInfoName\n\
    .L0808440C: .4byte 0x00011217\n\
    .L08084410: .4byte 0x0000200A\n\
        .syntax divided\n\
    ");
}

#endif // if !NONMATCHING

u8 *SramOffsetToPointer(u16 off)
{
    return gpSramEntry + off;
}

u16 SramPointerToOffset(u8 *addr)
{
    return addr - gpSramEntry;
}
