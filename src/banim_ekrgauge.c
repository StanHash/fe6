#include "prelude.h"
#include "banim_sprite.h"
#include "banim.h"
#include "hardware.h"

void func_fe6_080435EC(void *_src, void *_dst)
{
    u16 *src = _src;
    u16 *dst = _dst;
    u32 i, val;

    for (i = 0; i < 11; i++) {
        u32 val = *src == 0xFF ? 0xF : *src;
        CpuFastCopy(Pal_08113224 + BGPAL_OFFSET(val), dst + BGPAL_OFFSET(i), 0x20);
        src++;
    }

    CpuFastFill(0, dst + BGPAL_OFFSET(12), 0x20);
}

void EkrGaugeModDec(i16 val, u16 buf[])
{
    int val2;

    if (val == -1) {
        buf[0] = 11;
        buf[1] = 10;
        buf[2] = 10;
        return;
    }

    buf[0] = Div(val, 100);

    val -= buf[0] * 100;

    buf[1] = Div(val, 10);
    buf[2] = val - buf[1] * 10;

    if ((buf[0] + buf[1]) == 0)
        buf[1] = 11;

    if (buf[0] == 0)
        buf[0] = 11;
}
