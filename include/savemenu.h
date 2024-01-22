#ifndef SAVEMENU_H
#define SAVEMENU_H

#include "prelude.h"

// TODO: MOVE
enum
{
    BGCHR_SAVEMENU_0 = 0,
    BGCHR_SAVEMENU_2_0 = 0, // 8000

    OBCHR_SAVEMENU_1C0 = 0x1C0,
    OBCHR_SAVEMENU_200 = 0x200,

    OBPAL_SAVEMENU_9 = 9,

    OBPAL_SAVEMENU_1 = 1,
    OBPAL_SAVEMENU_2 = 2,
};

enum
{
    L_SAVEMENU_BEGIN = 0,
    L_SAVEMENU_1 = 1,
    L_SAVEMENU_2 = 2,
    L_SAVEMENU_3 = 3,
    L_SAVEMENU_4 = 4,
    L_SAVEMENU_5 = 5,
    L_SAVEMENU_6 = 6,
    L_SAVEMENU_7 = 7,
    L_SAVEMENU_8 = 8,
    L_SAVEMENU_9 = 9,
    L_SAVEMENU_10 = 10,
    L_SAVEMENU_11 = 11,
    L_SAVEMENU_12 = 12,
    L_SAVEMENU_13 = 13,
    L_SAVEMENU_14 = 14,
    L_SAVEMENU_15 = 15,
    L_SAVEMENU_16 = 16,
};

enum
{
    // those are the shift of UNK_SAVEMENU_... values
    // TODO: names

    SAVEMENU_PROMPT_0 = 0,
    SAVEMENU_PROMPT_1,
    SAVEMENU_PROMPT_2,
    SAVEMENU_PROMPT_3,
    SAVEMENU_PROMPT_4,
    SAVEMENU_PROMPT_5,
    SAVEMENU_PROMPT_6,
};

enum
{
    UNK_SAVEMENU_0 = 1 << 0,
    UNK_SAVEMENU_1 = 1 << 1,
    UNK_SAVEMENU_2 = 1 << 2,
    UNK_SAVEMENU_3 = 1 << 3,
    UNK_SAVEMENU_4 = 1 << 4,
    UNK_SAVEMENU_5 = 1 << 5,
    UNK_SAVEMENU_6 = 1 << 6, // save screen
    UNK_SAVEMENU_7 = 1 << 7,
};

struct UnkProc_0868A28C;
struct UnkProc_0868A2AC;
struct UnkProc_0868A2CC;

struct SaveMenuProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 anim_clock;
    /* 2A */ u8 unk_2A;
    /* 2B */ u8 selected_id;
    /* 2C */ u8 copy_from_id;
    /* 2D */ u8 unk_2D; // proc label
    /* 2E */ u8 unk_2E;
    /* 2F */ u8 unk_2F;
    /* 30 */ u8 unk_30;
    /* 31 */ u8 unk_31;
    /* 32 */ u8 unk_32;
    /* 33 */ u8 unk_33;
    /* 34 */ u8 unk_34;
    /* 35 */ u8 unk_35;
    /* 36 */ u8 unk_36;
    /* 37 */ u8 unk_37[3]; // unsure of length
    /* 3A */ u8 unk_3A[3];
    /* 3D */ u8 unk_3D;
    /* 3E */ u8 unk_3E;
    /* 3F */ u8 unk_3F;
    /* 40 */ u16 unk_40;
    /* 42 */ u16 unk_42;
    /* 44 */ u32 unk_44[3]; // time value
    /* 50 */ u32 unk_50; // time value
    /* 54 */ struct UnkProc_0868A28C * unk_54;
    /* 58 */ struct UnkProc_0868A2AC * unk_58;
    /* 5C */ ProcPtr unk_5C; // sprite anim proc
};

struct SaveMenuUnkPalProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 unk_29;
};

struct UnkProc_0868A28C
{
    /* 00 */ PROC_HEADER_EXT(struct SaveMenuProc);
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ u16 unk_2A;
    /* 2C */ u16 unk_2C;
    /* 2E */ u16 unk_2E;
    /* 30 */ u16 unk_30;
    /* 30 */ u8 unk_32;
    /* 33 */ u8 unk_33;
    /* 34 */ struct UnkProc_0868A2CC * unk_34;
    /* 38 */ STRUCT_PAD(0x38, 0x39);
    /* 39 */ u8 unk_39;
    /* 3A */ u8 unk_3A;
    /* 3B */ u8 unk_3B;
    /* 3C */ u8 unk_3C;
};

struct UnkProc_0868A2AC
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ u16 unk_2A;
    /* 2C */ u16 unk_2C;
    /* 2E */ STRUCT_PAD(0x2E, 0x30);
    /* 30 */ struct SaveMenuProc * sm_proc;
    /* 34 */ u8 unk_34;
    /* 35 */ u8 unk_35;
    /* 36 */ u8 unk_36;
    /* 37 */ u8 unk_37;
    /* 38 */ u8 unk_38;
    /* 39 */ u8 unk_39;
    /* 3A */ u8 unk_3A;
    /* 3B */ u8 unk_3B;
    /* 3C */ STRUCT_PAD(0x3C, 0x3D);
    /* 3D */ u8 unk_3D;
};

struct UnkProc_0868A2CC
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ u16 unk_2A;
    /* 2C */ u8 unk_2C;
    /* 2D */ u8 unk_2D;
    /* 2E */ u8 unk_2E;
    /* 2F */ u8 unk_2F;
    /* 30 */ u8 unk_30;
    /* 31 */ u8 unk_31;
    /* 32 */ u8 unk_32;
    /* 33 */ u8 unk_33;
    /* 34 */ u8 unk_34;
    /* 35 */ u8 unk_35;
};

// SaveMenuOnHBlank
// func_fe6_08087C60
fu8 func_fe6_08087C78(fu8 byte, int num);
fu8 func_fe6_08087CB0(fu8 byte);
// func_fe6_08087CD4
// SaveMenu_InitSong
// SaveMenu_InitDisplay
// SaveMenu_PutScreen
// func_fe6_08088094
// func_fe6_080881B8
// func_fe6_080881C8
// func_fe6_08088404
// func_fe6_080885DC
// func_fe6_08088854
// func_fe6_08088860
// func_fe6_08088870
// func_fe6_08088B40
// func_fe6_08088B9C
// func_fe6_08088C04
// func_fe6_08088C58
// func_fe6_08088CB0
// func_fe6_08088D0C
// func_fe6_08088D6C
// func_fe6_08088EB8
// func_fe6_08088F60
// func_fe6_080890B8
// SaveMenu_Finish
// func_fe6_08089180
// func_fe6_080891DC
void StartMainMenu(ProcPtr parent);
void StartSaveMenu(ProcPtr parent);

// func_fe6_08089254
// func_fe6_0808927C
// func_fe6_08089310
// func_fe6_080893D0
// func_fe6_08089490
// func_fe6_08089550
// func_fe6_08089564
// func_fe6_08089578
// func_fe6_0808958C
void func_fe6_080895A0(u16 const * src, u16 * dst, int count);
// func_fe6_080895B8
// func_fe6_08089684
// func_fe6_08089894
// func_fe6_080898F0
// func_fe6_080899F0
// func_fe6_08089A3C
// func_fe6_08089ABC
// func_fe6_08089B3C
// func_fe6_08089C70
// func_fe6_08089D30
// func_fe6_0808A14C
// func_fe6_0808A160
// func_fe6_0808A194
// func_fe6_0808A210
// func_fe6_0808A228
// func_fe6_0808A25C
void func_fe6_0808A3C8(int a, int b, fu8 c, struct UnkProc_0868A28C * proc);
void func_fe6_0808A3E8(int a, fu8 b, struct UnkProc_0868A28C * proc);
struct UnkProc_0868A2CC * func_fe6_0808A418(ProcPtr parent);
void func_fe6_0808A42C(void);
// func_fe6_0808A454
// func_fe6_0808A4B8
void func_fe6_0808A4F0(void);
void func_fe6_0808A524(struct SaveMenuProc * proc);
// func_fe6_0808A658
// func_fe6_0808A6C8
// func_fe6_0808A79C
// func_fe6_0808A7B8
// func_fe6_0808A8B4
// func_fe6_0808A8E8
// func_fe6_0808A904
void func_fe6_0808A918(fu8 arg_0, struct SaveMenuProc * proc);
void func_fe6_0808A9F4(fu8 save_id);
fu8 func_fe6_0808AA54(fu8 end_mask, struct SaveMenuProc * proc);

extern u16 gUnk_Savemenu_02000000;
extern u16 gUnk_Savemenu_02000002[0x200];

extern u16 gUnk_Savemenu_02000404[0x20];

#endif // SAVEMENU_H
