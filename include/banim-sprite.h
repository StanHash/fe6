#pragma once

#include "gba/gba.h"

struct BaSprite
{
    /* 00 */ u16 flags;
    /* 02 */ short xPosition;
    /* 04 */ short yPosition;
    /* 06 */ short timer;
    /* 08 */ u16 oam2;
    /* 0A */ u16 priority;
    /* 0C */ u16 flags2;
    /* 0E */ u16 nextRoundId;
    /* 10 */ u16 flags3;
    /* 12 */ u8 currentRoundType;
    /* 13 */ u8 unk13;

    // Command queue
    /* 14 */ u8 cqSize;
    /* 15 */ u8 cq[7];

    /* 1C */ u32 oam01;

    /* 20 */ u32 const* scrCur;
    /* 24 */ u32 const* script;

    /* 28 */ void const* imgSheet;
    /* 2C */ void const* unk2C;
    /* 30 */ void const* sprDataPool; // aka "OAM data"

    /* 34 */ struct BaSprite* prev;
    /* 38 */ struct BaSprite* next;

    /* 3C */ void const* sprData;
    /* 40 */ void const* unk40;
    /* 44 */ void const* unk_44;
};

enum
{
    // Command Identifiers

    // TODO: complete during battle anim decomp

    BAS_CMD_NOP     = 0x00,
    BAS_CMD_WAIT_01 = 0x01, // wait for hp depletion
    BAS_CMD_WAIT_02 = 0x02, // wait for dodge start, then dodge
    BAS_CMD_WAIT_03 = 0x03, // wait for attack start
    BAS_CMD_WAIT_04 = 0x04,
    BAS_CMD_WAIT_05 = 0x05, // wait for spell anim?
    // TODO: more
    BAS_CMD_WAIT_13 = 0x13, // unk
    BAS_CMD_WAIT_18 = 0x18, // wait for dodge start, then forward dodge
    BAS_CMD_WAIT_39 = 0x39, // unk
};

void BasUpdateAll(void);
void BasInit(void);
struct BaSprite* BasCreate2(void const* script);
struct BaSprite* BasCreate(void const* script, u16 displayPriority);
void BasSort(void);
void BasRemove(struct BaSprite* BaSprite);
void BasPutOam(struct BaSprite* BaSprite);

#define BAS_IS_DISABLED(BaSprite) ((BaSprite)->flags == 0)

/*

    BATTLE ANIM INSTRUCTION FORMAT:

    CallFunc(function):
        +00bit | 28bit | function
        +28bit | 4bit  | 1100b

    GotoScript(script):
        +00bit | 28bit | script
        +28bit | 4bit  | 1101b

    Stop:
        +00bit | 24bit | -
        +24bit | 8bit  | 10000000b

    End:
        +00bit | 24bit | -
        +24bit | 8bit  | 10000001b

    Loop:
        +00bit | 24bit | -
        +24bit | 8bit  | 10000010b

    Wait(duration):
        +00bit | 16bit | duration
        +16bit | 8bit  | -
        +24bit | 8bit  | 10000011b

    Move(x_offset, y_offset):
        +00bit | 8bit  | x_offset
        +08bit | 8bit  | y_offset
        +16bit | 8bit  | -
        +24bit | 8bit  | 10000100b

    Command(command):
        +00bit | 8bit  | command
        +08bit | 16bit | -
        +24bit | 8bit  | 10000101b

    Frame(delay, unk, sheet, sprOff):
        +00bit | 16bit | delay
        +16bit | 8bit  | unk
        +24bit | 8bit  | 10000110b
        +4byte | 4byte | sheet
        +8byte | 8byte | sprOff

    SetSpriteData(delay, address):
        +00bit | 2bit  | delay (lo 2 bits)
        +02bit | 26bit | address (minus lo 2 bits which are implied zeroes)
        +28bit | 3bit  | delay (hi 3 bits)
        +31bit | 1bit  | 0b

*/
