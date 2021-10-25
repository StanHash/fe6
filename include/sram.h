#pragma once

#include "common.h"

void WriteSramFast(const u8* src, u8* dest, u32 size);
void SetSramFastFunc(void);
u32 WriteAndVerifySramFast(const u8 *src, u8 *dest, u32 size);

extern u32 (*VerifySramFast)(const u8 *src, u8 *dest, u32 size);
extern void (*ReadSramFast)(const u8 *src, u8 *dest, u32 size);
