
	.include "macro.inc"

	.syntax unified

	thumb_func_start sub_8041284
sub_8041284: @ 0x08041284
	push {lr}
	adds r3, r0, #0
	cmp r3, #0
	bge _0804128E
	movs r3, #1
_0804128E:
	ldr r2, _080412A8 @ =gUnk_085CB3B4
	ldr r1, _080412AC @ =gPlaySt
	movs r0, #0xc
	ldrb r1, [r1, #0x1d]
	ands r0, r1
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r3, #5
	movs r2, #0x20
	bl ApplyPaletteExt
	pop {r0}
	bx r0
	.align 2, 0
_080412A8: .4byte gUnk_085CB3B4
_080412AC: .4byte gPlaySt

	thumb_func_start sub_80412B0
sub_80412B0: @ 0x080412B0
	push {lr}
	adds r3, r0, #0
	cmp r3, #0
	bne _080412BC
	movs r3, #0xc0
	lsls r3, r3, #0x13
_080412BC:
	ldr r2, _080412D4 @ =gUnk_085CB3C4
	ldr r1, _080412D8 @ =gPlaySt
	movs r0, #0xc
	ldrb r1, [r1, #0x1d]
	ands r0, r1
	adds r0, r0, r2
	ldr r0, [r0]
	adds r1, r3, #0
	bl Decompress
	pop {r0}
	bx r0
	.align 2, 0
_080412D4: .4byte gUnk_085CB3C4
_080412D8: .4byte gPlaySt

	thumb_func_start sub_80412DC
sub_80412DC: @ 0x080412DC
	push {lr}
	adds r3, r0, #0
	cmp r3, #0
	bge _080412E6
	movs r3, #6
_080412E6:
	ldr r2, _08041300 @ =gUnk_085CB3D4
	ldr r1, _08041304 @ =gPlaySt
	movs r0, #0xc
	ldrb r1, [r1, #0x1d]
	ands r0, r1
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r3, #5
	movs r2, #0x20
	bl ApplyPaletteExt
	pop {r0}
	bx r0
	.align 2, 0
_08041300: .4byte gUnk_085CB3D4
_08041304: .4byte gPlaySt

	thumb_func_start sub_8041308
sub_8041308: @ 0x08041308
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	cmp r5, #0
	bge _08041318
	ldr r0, _0804134C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1c
	lsrs r5, r0, #0x1e
_08041318:
	ldr r0, _08041350 @ =gUnk_085CB3C4
	lsls r5, r5, #2
	adds r5, r5, r0
	ldr r0, [r5]
	bl GetDataSize
	adds r6, r0, #0
	ldr r4, _08041354 @ =gUnk_020210E8
	subs r4, r4, r6
	ldr r0, [r5]
	adds r1, r4, #0
	bl Decompress
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r4, #0
	adds r2, r6, #0
	bl RegisterDataMove
	movs r0, #1
	rsbs r0, r0, #0
	bl sub_8041284
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804134C: .4byte gPlaySt
_08041350: .4byte gUnk_085CB3C4
_08041354: .4byte gUnk_020210E8

	thumb_func_start sub_8041358
sub_8041358: @ 0x08041358
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	str r0, [sp]
	mov sb, r1
	ldr r0, [sp, #0x50]
	ldr r1, _080415C0 @ =gUnk_085CB3A8
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	ldr r0, [sp]
	adds r2, r0, r2
	subs r2, #1
	str r2, [sp, #4]
	add r3, sb
	subs r3, #1
	str r3, [sp, #8]
	mov r4, sb
	adds r4, #1
	cmp r4, r3
	bge _08041402
	ldr r1, _080415C4 @ =gBg1Tm
	mov sl, r1
_0804138C:
	ldr r7, [sp]
	adds r7, #1
	adds r2, r4, #2
	mov r8, r2
	ldr r0, [sp, #4]
	cmp r7, r0
	bge _080413FA
	ldr r1, _080415C8 @ =gBg0Tm
	mov ip, r1
	movs r5, #0
	mov r3, sl
_080413A2:
	lsls r0, r4, #5
	adds r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r0, #1
	mov r1, ip
	adds r1, r2, r1
	strh r5, [r1]
	adds r2, r2, r3
	ldrh r1, [r6, #0xa]
	strh r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r0, #1
	mov r1, ip
	adds r1, r2, r1
	strh r5, [r1]
	adds r2, r2, r3
	ldrh r1, [r6, #0xc]
	strh r1, [r2]
	adds r0, #0x1f
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r0, #1
	mov r1, ip
	adds r1, r2, r1
	strh r5, [r1]
	adds r2, r2, r3
	ldrh r1, [r6, #0x12]
	strh r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	mov r2, ip
	adds r1, r0, r2
	strh r5, [r1]
	adds r0, r0, r3
	ldrh r1, [r6, #0x14]
	strh r1, [r0]
	adds r7, #2
	ldr r0, [sp, #4]
	cmp r7, r0
	blt _080413A2
_080413FA:
	mov r4, r8
	ldr r1, [sp, #8]
	cmp r4, r1
	blt _0804138C
_08041402:
	ldr r7, [sp]
	adds r7, #1
	mov r2, sb
	adds r2, #1
	str r2, [sp, #0xc]
	mov r4, sb
	lsls r4, r4, #5
	str r4, [sp, #0x10]
	ldr r0, [sp, #8]
	lsls r0, r0, #5
	str r0, [sp, #0x14]
	ldr r1, [sp, #4]
	cmp r7, r1
	bge _080414B2
	adds r5, r4, #0
	adds r5, #1
	adds r3, r0, #0
	adds r3, #1
	lsls r2, r7, #1
	ldr r4, [sp, #8]
	lsls r0, r4, #6
	ldr r4, _080415C4 @ =gBg1Tm
	adds r1, r0, r4
	adds r1, r2, r1
	str r1, [sp, #0x1c]
	ldr r1, _080415C8 @ =gBg0Tm
	adds r0, r0, r1
	adds r0, r0, r2
	mov sl, r0
	mov r4, sb
	lsls r0, r4, #6
	ldr r4, _080415C4 @ =gBg1Tm
	adds r1, r0, r4
	adds r1, r1, r2
	mov sb, r1
	ldr r1, _080415C8 @ =gBg0Tm
	adds r0, r0, r1
	adds r0, r0, r2
	mov r8, r0
	lsls r3, r3, #1
	adds r0, r3, r4
	adds r0, r0, r2
	mov ip, r0
	adds r3, r3, r1
	adds r1, r2, r3
	lsls r5, r5, #1
	adds r4, r5, r4
	str r4, [sp, #0x24]
	adds r3, r2, r4
	ldr r0, _080415C8 @ =gBg0Tm
	adds r5, r5, r0
	adds r2, r2, r5
_0804146A:
	movs r0, #0
	mov r4, r8
	strh r0, [r4]
	ldrh r0, [r6, #2]
	mov r4, sb
	strh r0, [r4]
	movs r0, #0
	strh r0, [r2]
	ldrh r0, [r6, #4]
	strh r0, [r3]
	movs r0, #0
	mov r4, sl
	strh r0, [r4]
	ldrh r0, [r6, #0x1a]
	ldr r4, [sp, #0x1c]
	strh r0, [r4]
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r6, #0x1c]
	mov r4, ip
	strh r0, [r4]
	ldr r0, [sp, #0x1c]
	adds r0, #4
	str r0, [sp, #0x1c]
	movs r4, #4
	add sl, r4
	add sb, r4
	add r8, r4
	add ip, r4
	adds r1, #4
	adds r3, #4
	adds r2, #4
	adds r7, #2
	ldr r0, [sp, #4]
	cmp r7, r0
	blt _0804146A
_080414B2:
	ldr r4, [sp, #0xc]
	ldr r1, [sp, #8]
	cmp r4, r1
	bge _08041548
	movs r2, #0
	mov sl, r2
	ldr r5, _080415C4 @ =gBg1Tm
	lsls r2, r4, #5
	adds r2, #0x20
	ldr r7, [sp, #4]
	adds r7, r2, r7
	str r7, [sp, #0x18]
	ldr r0, [sp]
	adds r2, r2, r0
	lsls r3, r4, #6
	ldr r1, [sp, #4]
	lsls r0, r1, #1
	adds r1, r0, r5
	adds r1, r1, r3
	mov sb, r1
	ldr r7, _080415C8 @ =gBg0Tm
	adds r0, r0, r7
	adds r0, r0, r3
	mov r8, r0
	ldr r1, [sp]
	lsls r0, r1, #1
	adds r1, r0, r5
	adds r1, r1, r3
	mov ip, r1
	adds r0, r0, r7
	adds r3, r3, r0
	lsls r2, r2, #1
	adds r7, r2, r5
	str r7, [sp, #0x2c]
	ldr r0, _080415C8 @ =gBg0Tm
	adds r2, r2, r0
	ldr r1, [sp, #0x18]
	lsls r1, r1, #1
	str r1, [sp, #0x20]
	adds r5, r1, r5
	adds r1, r1, r0
_08041504:
	mov r7, sl
	strh r7, [r3]
	ldrh r0, [r6, #8]
	mov r7, ip
	strh r0, [r7]
	mov r7, sl
	mov r0, r8
	strh r7, [r0]
	ldrh r0, [r6, #0xe]
	mov r7, sb
	strh r0, [r7]
	mov r0, sl
	strh r0, [r2]
	ldrh r0, [r6, #0x10]
	ldr r7, [sp, #0x2c]
	strh r0, [r7]
	mov r0, sl
	strh r0, [r1]
	ldrh r0, [r6, #0x16]
	strh r0, [r5]
	adds r5, #0x80
	adds r1, #0x80
	adds r7, #0x80
	str r7, [sp, #0x2c]
	adds r2, #0x80
	movs r0, #0x80
	add sb, r0
	add r8, r0
	add ip, r0
	adds r3, #0x80
	adds r4, #2
	ldr r7, [sp, #8]
	cmp r4, r7
	blt _08041504
_08041548:
	ldr r0, [sp, #0x10]
	ldr r1, [sp]
	adds r5, r0, r1
	lsls r5, r5, #1
	ldr r2, _080415C8 @ =gBg0Tm
	adds r0, r5, r2
	movs r7, #0
	strh r7, [r0]
	ldr r4, [sp, #0x10]
	ldr r0, [sp, #4]
	adds r3, r4, r0
	lsls r3, r3, #1
	adds r0, r3, r2
	strh r7, [r0]
	ldr r4, [sp, #0x14]
	adds r2, r4, r1
	lsls r2, r2, #1
	ldr r1, _080415C8 @ =gBg0Tm
	adds r0, r2, r1
	strh r7, [r0]
	ldr r0, [sp, #4]
	adds r1, r4, r0
	lsls r1, r1, #1
	ldr r4, _080415C8 @ =gBg0Tm
	adds r0, r1, r4
	strh r7, [r0]
	ldr r7, _080415C4 @ =gBg1Tm
	adds r5, r5, r7
	ldrh r0, [r6]
	strh r0, [r5]
	adds r3, r3, r7
	ldrh r0, [r6, #6]
	strh r0, [r3]
	adds r2, r2, r7
	ldrh r0, [r6, #0x18]
	strh r0, [r2]
	adds r1, r1, r7
	ldrh r0, [r6, #0x1e]
	strh r0, [r1]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #3
	bl EnableBgSync
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080415C0: .4byte gUnk_085CB3A8
_080415C4: .4byte gBg1Tm
_080415C8: .4byte gBg0Tm

	thumb_func_start sub_80415CC
sub_80415CC: @ 0x080415CC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	bl GetGameTime
	subs r0, #1
	ldr r7, _0804162C @ =0x0203C9D8
	ldr r1, [r7]
	cmp r0, r1
	bne _080415F4
	ldr r0, _08041630 @ =0x0203C9D4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r1, r5, r1
	asrs r5, r1, #1
	movs r1, #2
	ldrsh r0, [r0, r1]
	adds r0, r6, r0
	asrs r6, r0, #1
_080415F4:
	ldr r0, _08041630 @ =0x0203C9D4
	movs r4, #0
	strh r5, [r0]
	strh r6, [r0, #2]
	bl GetGameTime
	str r0, [r7]
	bl GetGameTime
	adds r3, r5, #0
	subs r3, #0xe
	ldr r2, _08041634 @ =gUnk_085CB3EC
	movs r1, #0x1f
	ands r1, r0
	adds r1, r1, r2
	ldrb r1, [r1]
	adds r5, r1, r3
	ldr r3, _08041638 @ =gUnk_085CB3E4
	str r4, [sp]
	movs r0, #2
	adds r1, r5, #0
	adds r2, r6, #0
	bl PutSprite
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804162C: .4byte 0x0203C9D8
_08041630: .4byte 0x0203C9D4
_08041634: .4byte gUnk_085CB3EC
_08041638: .4byte gUnk_085CB3E4

	thumb_func_start sub_804163C
sub_804163C: @ 0x0804163C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r2, r1, #0
	subs r4, #0xc
	ldr r3, _0804165C @ =gUnk_085CB3E4
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	adds r1, r4, #0
	bl PutSprite
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804165C: .4byte gUnk_085CB3E4

	thumb_func_start sub_8041660
sub_8041660: @ 0x08041660
	ldr r0, _08041668 @ =0x0203C9D4
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08041668: .4byte 0x0203C9D4

	thumb_func_start sub_804166C
sub_804166C: @ 0x0804166C
	ldr r0, _08041674 @ =0x0203C9D4
	movs r1, #2
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08041674: .4byte 0x0203C9D4

	thumb_func_start ClearBg0Bg1
ClearBg0Bg1: @ 0x08041678
	push {lr}
	ldr r0, _08041694 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, _08041698 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	movs r0, #3
	bl EnableBgSync
	pop {r0}
	bx r0
	.align 2, 0
_08041694: .4byte gBg0Tm
_08041698: .4byte gBg1Tm

	thumb_func_start sub_804169C
sub_804169C: @ 0x0804169C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r5, r1, #0
	mov sb, r2
	adds r0, r4, r2
	subs r6, r0, #1
	adds r5, #1
	ldr r3, _08041708 @ =gBg1Tm
	lsls r7, r5, #5
	adds r0, r7, r4
	lsls r0, r0, #1
	adds r0, r0, r3
	ldr r2, _0804170C @ =gUnk_0810F734
	ldrh r1, [r2]
	strh r1, [r0]
	adds r4, #1
	mov r8, r3
	mov ip, r2
	cmp r4, r6
	bge _080416EC
	ldrh r3, [r2, #8]
	adds r0, r7, #1
	ldrh r7, [r2, #2]
	lsls r2, r4, #1
	lsls r1, r5, #6
	add r1, r8
	adds r1, r2, r1
	lsls r0, r0, #1
	add r0, r8
	adds r0, r2, r0
_080416DE:
	strh r3, [r1]
	strh r7, [r0]
	adds r1, #4
	adds r0, #4
	adds r4, #2
	cmp r4, r6
	blt _080416DE
_080416EC:
	lsls r0, r5, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	mov r2, r8
	adds r1, r0, r2
	movs r0, #1
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _08041710
	mov r0, ip
	ldrh r2, [r0, #4]
	b _08041714
	.align 2, 0
_08041708: .4byte gBg1Tm
_0804170C: .4byte gUnk_0810F734
_08041710:
	mov r0, ip
	ldrh r2, [r0, #0xa]
_08041714:
	strh r2, [r1]
	movs r0, #2
	bl EnableBgSync
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_8041728
sub_8041728: @ 0x08041728
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r3, r0, #0
	adds r4, r1, #0
	mov sb, r2
	adds r0, r3, r2
	subs r5, r0, #1
	adds r4, #1
	ldr r0, _08041788 @ =gBg1Tm
	mov r8, r0
	ldr r1, _0804178C @ =gUnk_0810F734
	mov ip, r1
	cmp r3, r5
	bge _0804176C
	lsls r0, r4, #5
	ldrh r7, [r1, #0xc]
	adds r0, #1
	ldrh r6, [r1, #0xe]
	lsls r2, r3, #1
	lsls r1, r4, #6
	add r1, r8
	adds r1, r2, r1
	lsls r0, r0, #1
	add r0, r8
	adds r2, r2, r0
_0804175E:
	strh r7, [r1]
	strh r6, [r2]
	adds r1, #4
	adds r2, #4
	adds r3, #2
	cmp r3, r5
	blt _0804175E
_0804176C:
	lsls r0, r4, #5
	adds r0, r0, r5
	lsls r0, r0, #1
	mov r2, r8
	adds r1, r0, r2
	movs r0, #1
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _08041790
	mov r2, ip
	ldrh r0, [r2, #0xc]
	b _08041794
	.align 2, 0
_08041788: .4byte gBg1Tm
_0804178C: .4byte gUnk_0810F734
_08041790:
	mov r2, ip
	ldrh r0, [r2, #0xe]
_08041794:
	strh r0, [r1]
	movs r0, #2
	bl EnableBgSync
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80417A8
sub_80417A8: @ 0x080417A8
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _080417CC @ =gUnk_08111970
	adds r1, r3, #0
	bl Decompress
	ldr r0, _080417D0 @ =gUnk_08111BC4
	lsls r4, r4, #5
	lsls r5, r5, #5
	adds r1, r4, #0
	adds r2, r5, #0
	bl ApplyPaletteExt
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080417CC: .4byte gUnk_08111970
_080417D0: .4byte gUnk_08111BC4

	thumb_func_start LoadUiFrameGraphics
LoadUiFrameGraphics: @ 0x080417D4
	push {lr}
	movs r0, #0
	bl sub_80412B0
	movs r0, #1
	rsbs r0, r0, #0
	bl sub_8041284
	pop {r0}
	bx r0

	thumb_func_start sub_80417E8
sub_80417E8: @ 0x080417E8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r2, #0
	ldr r2, [r4]
	cmp r1, #0x77
	bgt _080417F8
	lsls r0, r3, #0x18
	b _080417FA
_080417F8:
	lsls r0, r0, #0x18
_080417FA:
	lsrs r0, r0, #0x18
	ldr r1, _08041814 @ =0xFFFFFF00
	ands r2, r1
	orrs r2, r0
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #0
	bl sub_8041844
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08041814: .4byte 0xFFFFFF00

	thumb_func_start sub_8041818
sub_8041818: @ 0x08041818
	push {lr}
	adds r2, r1, #0
	ldr r1, [r0]
	bl sub_8041844
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8041828
sub_8041828: @ 0x08041828
	push {lr}
	movs r2, #0
	bl sub_8041844
	pop {r1}
	bx r1

	thumb_func_start sub_8041834
sub_8041834: @ 0x08041834
	push {lr}
	ldr r1, [r0]
	movs r2, #0
	bl sub_8041844
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8041844
sub_8041844: @ 0x08041844
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp]
	mov sb, r1
	adds r4, r2, #0
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	adds r0, #1
	str r0, [sp, #4]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	mov r8, r0
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r0, _080418A0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0804188A
	movs r0, #0x68
	bl m4aSongNumStart
_0804188A:
	cmp r4, #0
	beq _080418A8
	ldr r0, _080418A4 @ =gUnk_085CB424
	adds r1, r4, #0
	bl SpawnProcLocking
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x63
	movs r0, #0
	b _080418BC
	.align 2, 0
_080418A0: .4byte gPlaySt
_080418A4: .4byte gUnk_085CB424
_080418A8:
	bl LockGame
	ldr r0, _080419C0 @ =gUnk_085CB424
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x63
	movs r0, #1
_080418BC:
	strb r0, [r1]
	mov r1, sb
	asrs r0, r1, #0x18
	str r0, [sp, #0x18]
	cmp r0, #0
	bge _080418D4
	adds r1, r4, #0
	adds r1, #0x63
	movs r0, #8
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
_080418D4:
	movs r7, #0
	movs r3, #0
	mov sl, r3
	ldr r0, [sp]
	ldr r1, [r0, #8]
	ldr r0, [r1, #0xc]
	mov r2, sb
	lsls r2, r2, #0x10
	str r2, [sp, #0x14]
	adds r3, r4, #0
	adds r3, #0x60
	str r3, [sp, #8]
	adds r2, r4, #0
	adds r2, #0x61
	str r2, [sp, #0xc]
	adds r3, #2
	str r3, [sp, #0x10]
	cmp r0, #0
	beq _08041976
	movs r6, #0
_080418FC:
	adds r0, r6, r1
	ldr r2, [r0, #0xc]
	adds r1, r7, #0
	bl _call_via_r2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #2
	beq _08041966
	ldr r0, _080419C4 @ =gUnk_085CB464
	adds r1, r4, #0
	bl SpawnProc
	adds r2, r0, #0
	mov r0, sl
	lsls r1, r0, #2
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r1
	str r2, [r0]
	movs r1, #1
	add sl, r1
	ldr r3, [sp]
	ldr r0, [r3, #8]
	adds r0, r0, r6
	str r0, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x3c
	strb r7, [r0]
	adds r0, #1
	strb r5, [r0]
	mov r0, sp
	ldrh r0, [r0, #4]
	strh r0, [r2, #0x2a]
	mov r1, r8
	strh r1, [r2, #0x2c]
	adds r1, r4, #0
	adds r1, #0x63
	movs r0, #8
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08041962
	adds r0, r2, #0
	adds r0, #0x34
	mov r2, sb
	lsls r1, r2, #8
	asrs r1, r1, #0x18
	subs r1, #2
	bl InitText
_08041962:
	movs r3, #2
	add r8, r3
_08041966:
	adds r6, #0x24
	adds r7, #1
	ldr r0, [sp]
	ldr r1, [r0, #8]
	adds r0, r6, r1
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _080418FC
_08041976:
	ldr r1, [sp]
	str r1, [r4, #0x30]
	mov r2, sb
	str r2, [r4, #0x2c]
	movs r2, #0
	mov r0, sl
	ldr r3, [sp, #8]
	strb r0, [r3]
	ldr r1, [sp, #0xc]
	strb r2, [r1]
	movs r0, #0xff
	ldr r3, [sp, #0x10]
	strb r0, [r3]
	ldr r0, [sp, #0x14]
	asrs r1, r0, #0x18
	ldr r3, [sp, #0x18]
	adds r0, r1, r3
	cmp r0, r8
	bge _080419A8
	subs r0, r1, #1
	mov r1, r8
	subs r0, r1, r0
	adds r1, r4, #0
	adds r1, #0x2f
	strb r0, [r1]
_080419A8:
	ldr r0, _080419C8 @ =gKeySt
	ldr r0, [r0]
	strh r2, [r0, #8]
	adds r0, r4, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080419C0: .4byte gUnk_085CB424
_080419C4: .4byte gUnk_085CB464
_080419C8: .4byte gKeySt

	thumb_func_start sub_80419CC
sub_80419CC: @ 0x080419CC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x61
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r1
	ldr r1, [r0]
	adds r5, r4, #0
	adds r5, #0x63
	movs r0, #4
	ldrb r2, [r5]
	orrs r0, r2
	strb r0, [r5]
	ldr r0, [r1, #0x30]
	ldr r2, [r0, #0x20]
	cmp r2, #0
	beq _080419F8
	adds r0, r4, #0
	bl _call_via_r2
_080419F8:
	ldr r0, [r4, #0x30]
	ldr r1, [r0, #0x10]
	cmp r1, #0
	beq _08041A06
	adds r0, r4, #0
	bl _call_via_r1
_08041A06:
	movs r0, #1
	ldrb r5, [r5]
	ands r0, r5
	cmp r0, #0
	beq _08041A14
	bl UnlockGame
_08041A14:
	adds r0, r4, #0
	bl Proc_End
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r0, [r4, #0x14]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8041A38
sub_8041A38: @ 0x08041A38
	push {lr}
	ldr r0, _08041A48 @ =gUnk_085CB424
	ldr r1, _08041A4C @ =sub_80419CC
	bl Proc_ForEach
	pop {r0}
	bx r0
	.align 2, 0
_08041A48: .4byte gUnk_085CB424
_08041A4C: .4byte sub_80419CC

	thumb_func_start sub_8041A50
sub_8041A50: @ 0x08041A50
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x30]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _08041A62
	adds r0, r4, #0
	bl _call_via_r1
_08041A62:
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r1, r4, #0
	adds r1, #0x34
	adds r1, r1, r0
	ldr r1, [r1]
	ldr r0, [r1, #0x30]
	ldr r2, [r0, #0x1c]
	cmp r2, #0
	beq _08041A80
	adds r0, r4, #0
	bl _call_via_r2
_08041A80:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8041A88
sub_8041A88: @ 0x08041A88
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0x63
	movs r0, #8
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08041B68
	adds r0, r6, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r6, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r6, #0
	adds r2, #0x2e
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r3, r6, #0
	adds r3, #0x2f
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	ldr r4, [r6, #0x30]
	ldrb r4, [r4, #4]
	str r4, [sp]
	bl sub_8041358
	movs r7, #0
	adds r0, r6, #0
	adds r0, #0x60
	mov r8, r0
	movs r0, #0x61
	adds r0, r0, r6
	mov sb, r0
	mov r1, r8
	ldrb r1, [r1]
	cmp r7, r1
	bge _08041B56
_08041AEA:
	lsls r1, r7, #2
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r1, [r4, #0x30]
	ldr r2, [r1, #0x10]
	cmp r2, #0
	beq _08041B06
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
	b _08041B4C
_08041B06:
	ldrb r0, [r1, #8]
	adds r5, r4, #0
	adds r5, #0x34
	cmp r0, #0
	beq _08041B18
	adds r1, r0, #0
	adds r0, r5, #0
	bl Text_SetColor
_08041B18:
	adds r0, r4, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	cmp r0, #1
	bne _08041B2A
	adds r0, r5, #0
	movs r1, #1
	bl Text_SetColor
_08041B2A:
	ldr r0, [r4, #0x30]
	ldr r1, [r0]
	adds r0, r5, #0
	bl Text_DrawString
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	lsls r1, r1, #5
	movs r2, #0x2a
	ldrsh r0, [r4, r2]
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, _08041B78 @ =gBg0Tm
	adds r1, r1, r0
	adds r0, r5, #0
	bl PutText
_08041B4C:
	adds r7, #1
	mov r0, r8
	ldrb r0, [r0]
	cmp r7, r0
	blt _08041AEA
_08041B56:
	mov r2, sb
	ldrb r1, [r2]
	adds r0, r6, #0
	movs r2, #1
	bl sub_8041B7C
	movs r0, #3
	bl EnableBgSync
_08041B68:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08041B78: .4byte gBg0Tm

	thumb_func_start sub_8041B7C
sub_8041B7C: @ 0x08041B7C
	push {r4, lr}
	mov ip, r0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	mov r3, ip
	adds r3, #0x63
	movs r0, #0x10
	ldrb r3, [r3]
	ands r0, r3
	cmp r0, #0
	bne _08041BD2
	mov r0, ip
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r0, #1
	lsls r1, r1, #2
	mov r0, ip
	adds r0, #0x34
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0x2c
	ldrsh r1, [r0, r2]
	mov r0, ip
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r2, r0, #2
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08041BCC
	cmp r0, #1
	bne _08041BD2
	adds r0, r3, #0
	bl sub_804169C
	b _08041BD2
_08041BCC:
	adds r0, r3, #0
	bl sub_8041728
_08041BD2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8041BD8
sub_8041BD8: @ 0x08041BD8
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x63
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08041BFE
	add r2, sp, #4
	adds r0, r5, #0
	mov r1, sp
	bl sub_8041E24
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl sub_804163C
	b _08041CBE
_08041BFE:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08041C0E
	adds r0, r5, #0
	bl sub_80419CC
	b _08041CBE
_08041C0E:
	adds r0, r5, #0
	bl sub_8041CCC
	adds r0, r5, #0
	bl sub_8041DA8
	adds r4, r0, #0
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _08041C2A
	adds r0, r5, #0
	bl sub_80419CC
_08041C2A:
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _08041C42
	ldr r0, _08041CC8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _08041C42
	movs r0, #0x6a
	bl m4aSongNumStart
_08041C42:
	movs r0, #8
	ands r0, r4
	cmp r0, #0
	beq _08041C5A
	ldr r0, _08041CC8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _08041C5A
	movs r0, #0x6b
	bl m4aSongNumStart
_08041C5A:
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0
	beq _08041C66
	bl ClearBg0Bg1
_08041C66:
	movs r6, #0x20
	adds r0, r4, #0
	ands r0, r6
	cmp r0, #0
	beq _08041C76
	movs r0, #0
	bl EndFaceById
_08041C76:
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _08041C8A
	adds r1, r5, #0
	adds r1, #0x63
	movs r0, #0x80
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
_08041C8A:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _08041CBE
	adds r1, r5, #0
	adds r1, #0x63
	adds r0, r6, #0
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08041CBE
	add r4, sp, #4
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl sub_8041E24
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl sub_8042070
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl sub_80415CC
_08041CBE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08041CC8: .4byte gPlaySt

	thumb_func_start sub_8041CCC
sub_8041CCC: @ 0x08041CCC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r2, r6, #0
	adds r2, #0x61
	ldrb r0, [r2]
	adds r1, r6, #0
	adds r1, #0x62
	strb r0, [r1]
	ldr r1, _08041DA0 @ =gKeySt
	ldr r3, [r1]
	ldrh r4, [r3, #6]
	movs r0, #0x40
	ands r0, r4
	cmp r0, #0
	beq _08041D04
	ldrb r0, [r2]
	cmp r0, #0
	bne _08041CFE
	ldrh r3, [r3, #8]
	cmp r4, r3
	bne _08041D9A
	adds r0, r6, #0
	adds r0, #0x60
	ldrb r0, [r0]
	strb r0, [r2]
_08041CFE:
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
_08041D04:
	ldr r1, [r1]
	ldrh r3, [r1, #6]
	movs r0, #0x80
	ands r0, r3
	adds r4, r6, #0
	adds r4, #0x61
	cmp r0, #0
	beq _08041D32
	ldrb r2, [r4]
	adds r0, r6, #0
	adds r0, #0x60
	ldrb r0, [r0]
	subs r0, #1
	cmp r2, r0
	bne _08041D2C
	ldrh r1, [r1, #8]
	cmp r3, r1
	bne _08041D9A
	movs r0, #0xff
	strb r0, [r4]
_08041D2C:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_08041D32:
	adds r0, r6, #0
	adds r0, #0x62
	adds r5, r0, #0
	ldrb r0, [r5]
	ldrb r1, [r4]
	cmp r0, r1
	beq _08041D64
	ldrb r1, [r5]
	adds r0, r6, #0
	movs r2, #0
	bl sub_8041B7C
	ldrb r1, [r4]
	adds r0, r6, #0
	movs r2, #1
	bl sub_8041B7C
	ldr r0, _08041DA4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _08041D64
	movs r0, #0x66
	bl m4aSongNumStart
_08041D64:
	ldrb r0, [r4]
	ldrb r1, [r5]
	cmp r0, r1
	beq _08041D9A
	lsls r0, r1, #2
	adds r5, r6, #0
	adds r5, #0x34
	adds r0, r5, r0
	ldr r1, [r0]
	ldr r0, [r1, #0x30]
	ldr r2, [r0, #0x20]
	cmp r2, #0
	beq _08041D84
	adds r0, r6, #0
	bl _call_via_r2
_08041D84:
	ldrb r4, [r4]
	lsls r0, r4, #2
	adds r0, r5, r0
	ldr r1, [r0]
	ldr r0, [r1, #0x30]
	ldr r2, [r0, #0x1c]
	cmp r2, #0
	beq _08041D9A
	adds r0, r6, #0
	bl _call_via_r2
_08041D9A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08041DA0: .4byte gKeySt
_08041DA4: .4byte gPlaySt

	thumb_func_start sub_8041DA8
sub_8041DA8: @ 0x08041DA8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	adds r0, #0x61
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r6, [r5, #0x30]
	ldr r2, [r6, #0x18]
	cmp r2, #0
	beq _08041DCC
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
_08041DCC:
	ldr r0, _08041DE0 @ =gKeySt
	ldr r0, [r0]
	ldrh r1, [r0, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08041DE4
	ldr r2, [r6, #0x14]
	b _08041DF0
	.align 2, 0
_08041DE0: .4byte gKeySt
_08041DE4:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08041E02
	ldr r0, [r4, #0x30]
	ldr r2, [r0, #0x18]
_08041DF0:
	cmp r2, #0
	beq _08041E1A
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	b _08041E1A
_08041E02:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08041E1A
	ldr r0, [r4, #0x30]
	ldr r1, [r0, #0x1c]
	cmp r1, #0
	beq _08041E1A
	adds r0, r4, #0
	bl _call_via_r1
_08041E1A:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8041E24
sub_8041E24: @ 0x08041E24
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r3
	mov ip, r0
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r1, r3, #0
	adds r1, #0x34
	adds r0, r1, r0
	ldr r0, [r0]
	movs r5, #0x2a
	ldrsh r0, [r0, r5]
	lsls r0, r0, #3
	str r0, [r4]
	mov r6, ip
	ldrb r6, [r6]
	lsls r0, r6, #2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r1, #0x2c
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	str r0, [r2]
	ldr r0, [r3, #0x30]
	ldrb r0, [r0, #4]
	cmp r0, #0
	beq _08041E64
	ldr r0, [r4]
	subs r0, #4
	str r0, [r4]
_08041E64:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8041E6C
sub_8041E6C: @ 0x08041E6C
	movs r0, #0
	bx lr

	thumb_func_start sub_8041E70
sub_8041E70: @ 0x08041E70
	movs r0, #1
	bx lr

	thumb_func_start sub_8041E74
sub_8041E74: @ 0x08041E74
	movs r0, #0x1b
	bx lr

	thumb_func_start sub_8041E78
sub_8041E78: @ 0x08041E78
	push {lr}
	movs r2, #0x2a
	ldrsh r0, [r1, r2]
	lsls r0, r0, #3
	movs r2, #0x2c
	ldrsh r3, [r1, r2]
	lsls r3, r3, #3
	ldr r1, [r1, #0x30]
	ldrh r2, [r1, #6]
	adds r1, r3, #0
	bl sub_80706C8
	pop {r1}
	bx r1

	thumb_func_start sub_8041E94
sub_8041E94: @ 0x08041E94
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl sub_8070E70
	ldr r2, [r4, #0x30]
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [r2, #0x20]
	adds r0, r4, #0
	bl _call_via_r2
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8041EC4
sub_8041EC4: @ 0x08041EC4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	bl sub_8041CCC
	add r4, sp, #4
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl sub_8041E24
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl sub_8042070
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl sub_80415CC
	ldr r0, _08041F0C @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _08041F14
	bl sub_807089C
	ldr r1, _08041F10 @ =gUnk_085CB40C
	adds r0, r5, #0
	bl Proc_GotoScript
	b _08041F3A
	.align 2, 0
_08041F0C: .4byte gKeySt
_08041F10: .4byte gUnk_085CB40C
_08041F14:
	adds r1, r5, #0
	adds r1, #0x61
	adds r0, r5, #0
	adds r0, #0x62
	ldrb r2, [r1]
	ldrb r0, [r0]
	cmp r2, r0
	beq _08041F3A
	ldr r2, [r5, #0x30]
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r0, r5, #0
	adds r0, #0x34
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [r2, #0x20]
	adds r0, r5, #0
	bl _call_via_r2
_08041F3A:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8041F44
sub_8041F44: @ 0x08041F44
	push {lr}
	ldr r1, _08041F50 @ =gUnk_085CB46C
	bl Proc_GotoScript
	pop {r1}
	bx r1
	.align 2, 0
_08041F50: .4byte gUnk_085CB46C

	thumb_func_start sub_8041F54
sub_8041F54: @ 0x08041F54
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	add r4, sp, #4
	mov r1, sp
	adds r2, r4, #0
	bl sub_8041E24
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl sub_8042070
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl sub_804163C
	ldr r0, _08041F9C @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _08041F92
	bl sub_807089C
	ldr r1, _08041FA0 @ =gUnk_085CB40C
	adds r0, r5, #0
	bl Proc_GotoScript
_08041F92:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08041F9C: .4byte gKeySt
_08041FA0: .4byte gUnk_085CB40C

	thumb_func_start MenuFrozenHelpBox
MenuFrozenHelpBox: @ 0x08041FA4
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r1, _08041FD4 @ =gUnk_085CB484
	bl Proc_GotoScript
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl sub_8070E70
	bl sub_8041660
	adds r4, r0, #0
	bl sub_804166C
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl sub_80706C8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08041FD4: .4byte gUnk_085CB484

	thumb_func_start sub_8041FD8
sub_8041FD8: @ 0x08041FD8
	push {lr}
	ldr r0, _08041FF4 @ =gUnk_085CB424
	bl Proc_Find
	cmp r0, #0
	beq _08041FEE
	adds r0, #0x63
	movs r1, #0x40
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
_08041FEE:
	pop {r0}
	bx r0
	.align 2, 0
_08041FF4: .4byte gUnk_085CB424

	thumb_func_start sub_8041FF8
sub_8041FF8: @ 0x08041FF8
	push {lr}
	ldr r0, _08042014 @ =gUnk_085CB424
	bl Proc_Find
	cmp r0, #0
	beq _08042010
	adds r1, r0, #0
	adds r1, #0x63
	movs r0, #0xbf
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
_08042010:
	pop {r0}
	bx r0
	.align 2, 0
_08042014: .4byte gUnk_085CB424

	thumb_func_start sub_8042018
sub_8042018: @ 0x08042018
	push {r4, r5, r6, r7, lr}
	bl sub_80417E8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x60
	ldrb r0, [r1]
	cmp r0, #6
	bls _08042062
	adds r2, r4, #0
	adds r2, #0x2d
	ldr r5, _0804206C @ =gUnk_085CB494
	ldrb r3, [r1]
	adds r0, r3, r5
	ldrb r7, [r2]
	ldrb r0, [r0]
	subs r0, r7, r0
	strb r0, [r2]
	movs r3, #0
	ldrb r0, [r1]
	cmp r3, r0
	bge _08042062
	adds r6, r5, #0
	adds r2, r1, #0
	adds r5, r4, #0
	adds r5, #0x34
_0804204C:
	ldm r5!, {r0}
	ldrb r7, [r2]
	adds r1, r7, r6
	ldrh r7, [r0, #0x2c]
	ldrb r1, [r1]
	subs r1, r7, r1
	strh r1, [r0, #0x2c]
	adds r3, #1
	ldrb r0, [r2]
	cmp r3, r0
	blt _0804204C
_08042062:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804206C: .4byte gUnk_085CB494

	thumb_func_start sub_8042070
sub_8042070: @ 0x08042070
	push {r4, r5, r6, lr}
	adds r1, r0, #0
	adds r6, r2, #0
	adds r0, #0x60
	ldrb r2, [r0]
	cmp r2, #9
	bls _080420AE
	lsls r0, r2, #4
	subs r0, #0x90
	adds r1, #0x61
	ldrb r1, [r1]
	muls r0, r1, r0
	movs r1, #9
	bl __divsi3
	adds r5, r0, #0
	lsls r4, r5, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl SetBgOffset
	ldr r0, [r6]
	subs r0, r0, r5
	str r0, [r6]
_080420AE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_80420B4
sub_80420B4: @ 0x080420B4
	adds r1, r0, #0
	adds r1, #0x61
	adds r0, #0x62
	ldrb r0, [r0]
	ldrb r1, [r1]
	eors r0, r1
	adds r1, r0, #0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	bx lr
	.align 2, 0

	thumb_func_start BeginTargetList
BeginTargetList: @ 0x080420CC
	ldr r2, _080420DC @ =0x0203C9DC
	movs r3, #0
	strh r0, [r2]
	strh r1, [r2, #2]
	ldr r0, _080420E0 @ =0x0203CCE0
	str r3, [r0]
	bx lr
	.align 2, 0
_080420DC: .4byte 0x0203C9DC
_080420E0: .4byte 0x0203CCE0

	thumb_func_start EnlistTarget
EnlistTarget: @ 0x080420E4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r4, _08042130 @ =0x0203C9E0
	mov r8, r4
	ldr r6, _08042134 @ =0x0203CCE0
	ldr r5, [r6]
	lsls r4, r5, #1
	adds r4, r4, r5
	lsls r4, r4, #2
	add r4, r8
	strb r0, [r4]
	ldr r4, [r6]
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	add r0, r8
	strb r1, [r0, #1]
	ldr r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	strb r2, [r0, #2]
	ldr r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	strb r3, [r0, #3]
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08042130: .4byte 0x0203C9E0
_08042134: .4byte 0x0203CCE0

	thumb_func_start sub_8042138
sub_8042138: @ 0x08042138
	push {r4, r5, r6, lr}
	movs r2, #0
	ldr r0, _08042178 @ =0x0203CCE0
	ldr r1, [r0]
	adds r6, r0, #0
	ldr r4, _0804217C @ =0x0203C9E0
	cmp r2, r1
	bge _08042162
	adds r5, r6, #0
	adds r3, r4, #0
	adds r3, #0xc
	adds r1, r4, #0
	subs r1, #0xc
_08042152:
	str r1, [r1, #0x14]
	str r3, [r1, #0x10]
	adds r3, #0xc
	adds r1, #0xc
	adds r2, #1
	ldr r0, [r5]
	cmp r2, r0
	blt _08042152
_08042162:
	ldr r1, [r6]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	str r0, [r4, #8]
	str r4, [r0, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08042178: .4byte 0x0203CCE0
_0804217C: .4byte 0x0203C9E0

	thumb_func_start sub_8042180
sub_8042180: @ 0x08042180
	ldr r3, [r0, #0x30]
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #4
	str r0, [r1]
	movs r0, #1
	ldrsb r0, [r3, r0]
	lsls r0, r0, #4
	str r0, [r2]
	bx lr

	thumb_func_start sub_8042194
sub_8042194: @ 0x08042194
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x34
	movs r0, #0x40
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _080421BE
	add r2, sp, #4
	adds r0, r4, #0
	mov r1, sp
	bl sub_8042180
	ldr r0, [sp]
	ldr r1, [sp, #4]
	movs r2, #4
	bl PutMapCursor
	b _08042256
_080421BE:
	adds r0, r4, #0
	bl sub_8042310
	adds r0, r4, #0
	bl sub_8042388
	adds r5, r0, #0
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq _080421DA
	adds r0, r4, #0
	bl EndMapSelect
_080421DA:
	movs r0, #4
	ands r0, r5
	cmp r0, #0
	beq _080421F2
	ldr r0, _08042260 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _080421F2
	movs r0, #0x6a
	bl m4aSongNumStart
_080421F2:
	movs r0, #8
	ands r0, r5
	cmp r0, #0
	beq _0804220A
	ldr r0, _08042260 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0804220A
	movs r0, #0x6b
	bl m4aSongNumStart
_0804220A:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq _08042216
	bl ClearBg0Bg1
_08042216:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq _08042224
	movs r0, #0
	bl EndFaceById
_08042224:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	bne _08042256
	add r2, sp, #4
	adds r0, r4, #0
	mov r1, sp
	bl sub_8042180
	ldr r1, [sp]
	asrs r1, r1, #4
	ldr r2, [sp, #4]
	asrs r2, r2, #4
	adds r0, r4, #0
	bl CameraMoveWatchPosition
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08042256
	ldr r0, [sp]
	ldr r1, [sp, #4]
	movs r2, #2
	bl PutMapCursor
_08042256:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08042260: .4byte gPlaySt

	thumb_func_start StartMapSelect
StartMapSelect: @ 0x08042264
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl LockGame
	ldr r0, _080422C4 @ =gUnk_085CB4A0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x34
	movs r6, #0
	movs r0, #1
	strb r0, [r1]
	str r4, [r5, #0x2c]
	bl sub_8042534
	str r0, [r5, #0x30]
	str r6, [r5, #0x38]
	ldr r0, [r5, #0x2c]
	ldr r1, [r0]
	cmp r1, #0
	beq _08042298
	adds r0, r5, #0
	bl _call_via_r1
_08042298:
	ldr r0, [r5, #0x2c]
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _080422A6
	adds r0, r5, #0
	bl _call_via_r1
_080422A6:
	ldr r0, [r5, #0x2c]
	ldr r2, [r0, #0xc]
	cmp r2, #0
	beq _080422B6
	ldr r1, [r5, #0x30]
	adds r0, r5, #0
	bl _call_via_r2
_080422B6:
	ldr r0, _080422C8 @ =gKeySt
	ldr r0, [r0]
	strh r6, [r0, #8]
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080422C4: .4byte gUnk_085CB4A0
_080422C8: .4byte gKeySt

	thumb_func_start StartMapSelectExt
StartMapSelectExt: @ 0x080422CC
	push {r4, lr}
	adds r4, r1, #0
	bl StartMapSelect
	str r4, [r0, #0x38]
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EndMapSelect
EndMapSelect: @ 0x080422DC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x2c]
	ldr r1, [r0, #4]
	cmp r1, #0
	beq _080422EE
	adds r0, r4, #0
	bl _call_via_r1
_080422EE:
	adds r1, r4, #0
	adds r1, #0x34
	movs r0, #1
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08042300
	bl UnlockGame
_08042300:
	adds r0, r4, #0
	bl Proc_End
	ldr r0, [r4, #0x14]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8042310
sub_8042310: @ 0x08042310
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r4, #0x30]
	ldr r2, _08042380 @ =gKeySt
	ldr r1, [r2]
	movs r0, #0x60
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq _0804232C
	ldr r0, [r3, #4]
	cmp r0, #0
	beq _0804232C
	str r0, [r4, #0x30]
_0804232C:
	ldr r1, [r2]
	movs r0, #0x90
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq _08042342
	ldr r0, [r4, #0x30]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _08042342
	str r0, [r4, #0x30]
_08042342:
	ldr r0, [r4, #0x30]
	cmp r0, r3
	beq _08042378
	ldr r0, [r4, #0x2c]
	ldr r2, [r0, #0x10]
	cmp r2, #0
	beq _08042358
	adds r0, r4, #0
	adds r1, r3, #0
	bl _call_via_r2
_08042358:
	ldr r0, [r4, #0x2c]
	ldr r2, [r0, #0xc]
	cmp r2, #0
	beq _08042368
	ldr r1, [r4, #0x30]
	adds r0, r4, #0
	bl _call_via_r2
_08042368:
	ldr r0, _08042384 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _08042378
	movs r0, #0x67
	bl m4aSongNumStart
_08042378:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08042380: .4byte gKeySt
_08042384: .4byte gPlaySt

	thumb_func_start sub_8042388
sub_8042388: @ 0x08042388
	push {r4, lr}
	adds r2, r0, #0
	movs r4, #0
	ldr r0, _080423A8 @ =gKeySt
	ldr r0, [r0]
	ldrh r1, [r0, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080423AC
	ldr r3, [r2, #0x38]
	cmp r3, #0
	bne _080423CC
	ldr r0, [r2, #0x2c]
	ldr r3, [r0, #0x14]
	b _080423C8
	.align 2, 0
_080423A8: .4byte gKeySt
_080423AC:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080423BA
	ldr r0, [r2, #0x2c]
	ldr r3, [r0, #0x18]
	b _080423C8
_080423BA:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080423D8
	ldr r0, [r2, #0x2c]
	ldr r3, [r0, #0x1c]
_080423C8:
	cmp r3, #0
	beq _080423D8
_080423CC:
	ldr r1, [r2, #0x30]
	adds r0, r2, #0
	bl _call_via_r3
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080423D8:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_80423E0
sub_80423E0: @ 0x080423E0
	push {lr}
	ldr r0, _080423FC @ =gUnk_085CB4A0
	bl Proc_Find
	cmp r0, #0
	beq _080423F6
	adds r0, #0x34
	movs r1, #0x40
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
_080423F6:
	pop {r0}
	bx r0
	.align 2, 0
_080423FC: .4byte gUnk_085CB4A0

	thumb_func_start sub_8042400
sub_8042400: @ 0x08042400
	push {lr}
	ldr r0, _0804241C @ =gUnk_085CB4A0
	bl Proc_Find
	cmp r0, #0
	beq _08042418
	adds r1, r0, #0
	adds r1, #0x34
	movs r0, #0xbf
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
_08042418:
	pop {r0}
	bx r0
	.align 2, 0
_0804241C: .4byte gUnk_085CB4A0

	thumb_func_start sub_8042420
sub_8042420: @ 0x08042420
	push {r4, r5, r6, r7, lr}
	movs r7, #0
	ldr r5, _08042458 @ =0x0203C9E0
	ldr r0, _0804245C @ =0x0203CCE0
	ldr r0, [r0]
	cmp r7, r0
	bge _08042476
	ldr r1, _08042460 @ =0x0203C9DC
	mov ip, r1
	movs r2, #0
	ldrsh r6, [r1, r2]
	adds r4, r0, #0
_08042438:
	movs r0, #0
	ldrsb r0, [r5, r0]
	subs r2, r6, r0
	cmp r2, #0
	bge _08042444
	subs r2, r0, r6
_08042444:
	mov r0, ip
	movs r1, #2
	ldrsh r3, [r0, r1]
	movs r0, #1
	ldrsb r0, [r5, r0]
	subs r1, r3, r0
	cmp r1, #0
	blt _08042464
	adds r0, r2, r1
	b _08042468
	.align 2, 0
_08042458: .4byte 0x0203C9E0
_0804245C: .4byte 0x0203CCE0
_08042460: .4byte 0x0203C9DC
_08042464:
	subs r0, r0, r3
	adds r0, r2, r0
_08042468:
	cmp r7, r0
	bge _0804246E
	adds r7, r0, #0
_0804246E:
	subs r4, #1
	adds r5, #0xc
	cmp r4, #0
	bne _08042438
_08042476:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8042480
sub_8042480: @ 0x08042480
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r7, #0
	movs r5, #0
	movs r4, #0
	ldr r0, _08042514 @ =0x0203CCE0
	mov sb, r0
	ldr r1, _08042518 @ =0x0203C9DC
	mov r8, r1
	ldr r3, _0804251C @ =gUnk_085CB4D0
	mov sl, r3
_0804249E:
	mov r6, r8
	movs r0, #0
	ldrsh r2, [r6, r0]
	lsls r1, r4, #2
	add r1, sl
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r2, r2, r0
	str r2, [sp]
	movs r3, #2
	ldrsh r2, [r6, r3]
	movs r0, #1
	ldrsb r0, [r1, r0]
	adds r2, r2, r0
	movs r1, #0
	ldr r3, _08042520 @ =0x0203C9E0
	mov r6, sb
	ldr r0, [r6]
	adds r4, #1
	cmp r1, r0
	bge _080424F8
	mov ip, sb
_080424CA:
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldr r6, [sp]
	cmp r6, r0
	bne _080424EC
	movs r0, #1
	ldrsb r0, [r3, r0]
	cmp r2, r0
	bne _080424EC
	str r5, [r3, #4]
	cmp r5, #0
	beq _080424E4
	str r3, [r5, #8]
_080424E4:
	cmp r7, #0
	bne _080424EA
	adds r7, r3, #0
_080424EA:
	adds r5, r3, #0
_080424EC:
	adds r1, #1
	adds r3, #0xc
	mov r6, ip
	ldr r0, [r6]
	cmp r1, r0
	blt _080424CA
_080424F8:
	cmp r4, #0xc
	ble _0804249E
	str r5, [r7, #4]
	str r7, [r5, #8]
	adds r0, r7, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08042514: .4byte 0x0203CCE0
_08042518: .4byte 0x0203C9DC
_0804251C: .4byte gUnk_085CB4D0
_08042520: .4byte 0x0203C9E0

	thumb_func_start sub_8042524
sub_8042524: @ 0x08042524
	push {lr}
	bl sub_8042138
	ldr r0, _08042530 @ =0x0203C9E0
	pop {r1}
	bx r1
	.align 2, 0
_08042530: .4byte 0x0203C9E0

	thumb_func_start sub_8042534
sub_8042534: @ 0x08042534
	push {lr}
	bl sub_8042420
	cmp r0, #2
	bgt _08042544
	bl sub_8042480
	b _08042548
_08042544:
	bl sub_8042524
_08042548:
	pop {r1}
	bx r1

	thumb_func_start CountTargets
CountTargets: @ 0x0804254C
	ldr r0, _08042554 @ =0x0203CCE0
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08042554: .4byte 0x0203CCE0

	thumb_func_start GetTarget
GetTarget: @ 0x08042558
	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08042568 @ =0x0203C9E0
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08042568: .4byte 0x0203C9E0
