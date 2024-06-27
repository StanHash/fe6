#ifndef BANIM_SPRITE_H
#define BANIM_SPRITE_H

#include "prelude.h"

typedef u32 AnimScr;

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

    /* 20 */ u32 const * scrCur;
    /* 24 */ u32 const * script;

    /* 28 */ void const * imgSheet;
    /* 2C */ void const * unk2C;
    /* 30 */ void const * sprDataPool; // aka "OAM data"

    /* 34 */ struct BaSprite * prev;
    /* 38 */ struct BaSprite * next;

    /* 3C */ void const * sprData;
    /* 40 */ void const * unk40;
    /* 44 */ void const * unk_44;
};

enum
{
    // For use with BaSprite::flags

    BAS_BIT_ENABLED = (1 << 0),
    BAS_BIT_HIDDEN  = (1 << 1),
    BAS_BIT_2       = (1 << 2),
    BAS_BIT_FROZEN  = (1 << 3),
};

enum
{
    // For use with BaSprite::currentRoundType

    ANIM_ROUND_HIT_CLOSE,
    ANIM_ROUND_CRIT_CLOSE,
    ANIM_ROUND_NONCRIT_FAR,
    ANIM_ROUND_CRIT_FAR,
    ANIM_ROUND_TAKING_MISS_CLOSE,
    ANIM_ROUND_TAKING_MISS_FAR,
    ANIM_ROUND_TAKING_HIT_CLOSE,
    ANIM_ROUND_STANDING,
    ANIM_ROUND_TAKING_HIT_FAR,
    ANIM_ROUND_MISS_CLOSE,
    ANIM_ROUND_MAX,

    ANIM_ROUND_INVALID = -1,
};

enum
{
    BAS_MAX_COUNT = 50,
};

enum
{
    BAS_INS_KIND_STOP    = 0,
    BAS_INS_KIND_END     = 1,
    BAS_INS_KIND_LOOP    = 2,
    BAS_INS_KIND_MOVE    = 3,
    BAS_INS_KIND_WAIT    = 4,
    BAS_INS_KIND_COMMAND = 5,
    BAS_INS_KIND_FRAME   = 6,
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

enum anim_flag2 
{
    ANIM_BIT2_0001        = (1 << 0),
    ANIM_BIT2_0002        = (1 << 1),
    ANIM_BIT2_0004        = (1 << 2),
    ANIM_BIT2_0008        = (1 << 3),
    ANIM_BIT2_0010        = (1 << 4),
    ANIM_BIT2_0020        = (1 << 5),
    ANIM_BIT2_0040        = (1 << 6),
    ANIM_BIT2_0080        = (1 << 7),

    ANIM_BIT2_FRONT_FRAME = (1 << 8),
    ANIM_BIT2_BACK_FRAME  = (0 << 8),

    ANIM_BIT2_POS_RIGHT   = (1 << 9),
    ANIM_BIT2_POS_LEFT    = (0 << 9),

    ANIM_BIT2_0400        = (1 << 10),
    ANIM_BIT2_0800        = (1 << 11),
    ANIM_BIT2_COMMAND     = (1 << 12), /* 0x1000 */
    ANIM_BIT2_FRAME       = (1 << 13), /* 0x2000 */
    ANIM_BIT2_STOP        = (1 << 14), /* 0x4000 */
    ANIM_BIT2_8000        = (1 << 15), /* 0x8000 */
};

#define ANIM_BIT2_CMD_MASK (ANIM_BIT2_COMMAND | ANIM_BIT2_FRAME | ANIM_BIT2_STOP | ANIM_BIT2_8000)

enum anim_flag3
{
    ANIM_BIT3_TAKE_BACK_ENABLE   = (1 << 0),
    ANIM_BIT3_NEXT_ROUND_START   = (1 << 1),

    /**
     * If set, C01 will block the anim
     * set bit when hit effect applied
     * and then cleared after hitted
     */
    ANIM_BIT3_C01_BLOCKING_IN_BATTLE = (1 << 2),
    ANIM_BIT3_HIT_EFFECT_APPLIED = (1 << 3),
    ANIM_BIT3_0010               = (1 << 4),
    ANIM_BIT3_BLOCKING           = (1 << 5),
    ANIM_BIT3_BLOCKEND           = (1 << 6),
    ANIM_BIT3_0080               = (1 << 7),
    ANIM_BIT3_0100               = (1 << 8),
    ANIM_BIT3_0200               = (1 << 9),
    ANIM_BIT3_0400               = (1 << 10),
    ANIM_BIT3_0800               = (1 << 11),
    ANIM_BIT3_1000               = (1 << 12),
    ANIM_BIT3_2000               = (1 << 13),
    ANIM_BIT3_4000               = (1 << 14),
    ANIM_BIT3_NEW_ROUND_START    = (1 << 15),
};

void BasUpdateAll(void);
void BasInit(void);
struct BaSprite * BasCreate2(void const * script);
struct BaSprite * BasCreate(void const * script, u16 displayPriority);
void BasSort(void);
void BasRemove(struct BaSprite * banim_sprite);
void BasPutOam(struct BaSprite * banim_sprite);

#define BAS_IS_DISABLED(banim_sprite) ((banim_sprite)->flags == 0)

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

struct BaSpriteData
{
    /* 00 */ u32 header;

    union
    {

    struct
    {
        /* 04 */ u16 pa;
        /* 06 */ u16 pb;
        /* 08 */ u16 pc;
        /* 0A */ u16 pd;
    } affine;

    struct
    {
        /* 04 */ u16 oam2;
        /* 06 */ short x;
        /* 08 */ short y;
    } object;

    } as;
};

#endif // BANIM_SPRITE_H
