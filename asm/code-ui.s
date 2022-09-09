
	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_08041284
func_fe6_08041284: @ 0x08041284
	push {lr}
	adds r3, r0, #0
	cmp r3, #0
	bge .L0804128E
	movs r3, #1
.L0804128E:
	ldr r2, .L080412A8 @ =gUnk_085CB3B4
	ldr r1, .L080412AC @ =gPlaySt
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
.L080412A8: .4byte gUnk_085CB3B4
.L080412AC: .4byte gPlaySt

	thumb_func_start func_fe6_080412B0
func_fe6_080412B0: @ 0x080412B0
	push {lr}
	adds r3, r0, #0
	cmp r3, #0
	bne .L080412BC
	movs r3, #0xc0
	lsls r3, r3, #0x13
.L080412BC:
	ldr r2, .L080412D4 @ =gUnk_085CB3C4
	ldr r1, .L080412D8 @ =gPlaySt
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
.L080412D4: .4byte gUnk_085CB3C4
.L080412D8: .4byte gPlaySt

	thumb_func_start func_fe6_080412DC
func_fe6_080412DC: @ 0x080412DC
	push {lr}
	adds r3, r0, #0
	cmp r3, #0
	bge .L080412E6
	movs r3, #6
.L080412E6:
	ldr r2, .L08041300 @ =gUnk_085CB3D4
	ldr r1, .L08041304 @ =gPlaySt
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
.L08041300: .4byte gUnk_085CB3D4
.L08041304: .4byte gPlaySt

	thumb_func_start func_fe6_08041308
func_fe6_08041308: @ 0x08041308
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	cmp r5, #0
	bge .L08041318
	ldr r0, .L0804134C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1c
	lsrs r5, r0, #0x1e
.L08041318:
	ldr r0, .L08041350 @ =gUnk_085CB3C4
	lsls r5, r5, #2
	adds r5, r5, r0
	ldr r0, [r5]
	bl GetDataSize
	adds r6, r0, #0
	ldr r4, .L08041354 @ =gUnk_020210E8
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
	bl func_fe6_08041284
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804134C: .4byte gPlaySt
.L08041350: .4byte gUnk_085CB3C4
.L08041354: .4byte gUnk_020210E8

	thumb_func_start func_fe6_08041358
func_fe6_08041358: @ 0x08041358
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	str r0, [sp]
	mov sb, r1
	ldr r0, [sp, #0x50]
	ldr r1, .L080415C0 @ =gUnk_085CB3A8
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
	bge .L08041402
	ldr r1, .L080415C4 @ =gBg1Tm
	mov sl, r1
.L0804138C:
	ldr r7, [sp]
	adds r7, #1
	adds r2, r4, #2
	mov r8, r2
	ldr r0, [sp, #4]
	cmp r7, r0
	bge .L080413FA
	ldr r1, .L080415C8 @ =gBg0Tm
	mov ip, r1
	movs r5, #0
	mov r3, sl
.L080413A2:
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
	blt .L080413A2
.L080413FA:
	mov r4, r8
	ldr r1, [sp, #8]
	cmp r4, r1
	blt .L0804138C
.L08041402:
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
	bge .L080414B2
	adds r5, r4, #0
	adds r5, #1
	adds r3, r0, #0
	adds r3, #1
	lsls r2, r7, #1
	ldr r4, [sp, #8]
	lsls r0, r4, #6
	ldr r4, .L080415C4 @ =gBg1Tm
	adds r1, r0, r4
	adds r1, r2, r1
	str r1, [sp, #0x1c]
	ldr r1, .L080415C8 @ =gBg0Tm
	adds r0, r0, r1
	adds r0, r0, r2
	mov sl, r0
	mov r4, sb
	lsls r0, r4, #6
	ldr r4, .L080415C4 @ =gBg1Tm
	adds r1, r0, r4
	adds r1, r1, r2
	mov sb, r1
	ldr r1, .L080415C8 @ =gBg0Tm
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
	ldr r0, .L080415C8 @ =gBg0Tm
	adds r5, r5, r0
	adds r2, r2, r5
.L0804146A:
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
	blt .L0804146A
.L080414B2:
	ldr r4, [sp, #0xc]
	ldr r1, [sp, #8]
	cmp r4, r1
	bge .L08041548
	movs r2, #0
	mov sl, r2
	ldr r5, .L080415C4 @ =gBg1Tm
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
	ldr r7, .L080415C8 @ =gBg0Tm
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
	ldr r0, .L080415C8 @ =gBg0Tm
	adds r2, r2, r0
	ldr r1, [sp, #0x18]
	lsls r1, r1, #1
	str r1, [sp, #0x20]
	adds r5, r1, r5
	adds r1, r1, r0
.L08041504:
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
	blt .L08041504
.L08041548:
	ldr r0, [sp, #0x10]
	ldr r1, [sp]
	adds r5, r0, r1
	lsls r5, r5, #1
	ldr r2, .L080415C8 @ =gBg0Tm
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
	ldr r1, .L080415C8 @ =gBg0Tm
	adds r0, r2, r1
	strh r7, [r0]
	ldr r0, [sp, #4]
	adds r1, r4, r0
	lsls r1, r1, #1
	ldr r4, .L080415C8 @ =gBg0Tm
	adds r0, r1, r4
	strh r7, [r0]
	ldr r7, .L080415C4 @ =gBg1Tm
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
.L080415C0: .4byte gUnk_085CB3A8
.L080415C4: .4byte gBg1Tm
.L080415C8: .4byte gBg0Tm

	thumb_func_start PutUiHand
PutUiHand: @ 0x080415CC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	bl GetGameTime
	subs r0, #1
	ldr r7, .L0804162C @ =0x0203C9D8
	ldr r1, [r7]
	cmp r0, r1
	bne .L080415F4
	ldr r0, .L08041630 @ =0x0203C9D4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r1, r5, r1
	asrs r5, r1, #1
	movs r1, #2
	ldrsh r0, [r0, r1]
	adds r0, r6, r0
	asrs r6, r0, #1
.L080415F4:
	ldr r0, .L08041630 @ =0x0203C9D4
	movs r4, #0
	strh r5, [r0]
	strh r6, [r0, #2]
	bl GetGameTime
	str r0, [r7]
	bl GetGameTime
	adds r3, r5, #0
	subs r3, #0xe
	ldr r2, .L08041634 @ =gUnk_085CB3EC
	movs r1, #0x1f
	ands r1, r0
	adds r1, r1, r2
	ldrb r1, [r1]
	adds r5, r1, r3
	ldr r3, .L08041638 @ =gUnk_085CB3E4
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
.L0804162C: .4byte 0x0203C9D8
.L08041630: .4byte 0x0203C9D4
.L08041634: .4byte gUnk_085CB3EC
.L08041638: .4byte gUnk_085CB3E4

	thumb_func_start PutFrozenUiHand
PutFrozenUiHand: @ 0x0804163C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r2, r1, #0
	subs r4, #0xc
	ldr r3, .L0804165C @ =gUnk_085CB3E4
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
.L0804165C: .4byte gUnk_085CB3E4

	thumb_func_start GetUiHandPrevX
GetUiHandPrevX: @ 0x08041660
	ldr r0, .L08041668 @ =0x0203C9D4
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
.L08041668: .4byte 0x0203C9D4

	thumb_func_start GetUiHandPrevY
GetUiHandPrevY: @ 0x0804166C
	ldr r0, .L08041674 @ =0x0203C9D4
	movs r1, #2
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
.L08041674: .4byte 0x0203C9D4

	thumb_func_start ClearBg0Bg1
ClearBg0Bg1: @ 0x08041678
	push {lr}
	ldr r0, .L08041694 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08041698 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	movs r0, #3
	bl EnableBgSync
	pop {r0}
	bx r0
	.align 2, 0
.L08041694: .4byte gBg0Tm
.L08041698: .4byte gBg1Tm

	thumb_func_start PutUiEntryHover
PutUiEntryHover: @ 0x0804169C
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
	ldr r3, .L08041708 @ =gBg1Tm
	lsls r7, r5, #5
	adds r0, r7, r4
	lsls r0, r0, #1
	adds r0, r0, r3
	ldr r2, .L0804170C @ =gUnk_0810F734
	ldrh r1, [r2]
	strh r1, [r0]
	adds r4, #1
	mov r8, r3
	mov ip, r2
	cmp r4, r6
	bge .L080416EC
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
.L080416DE:
	strh r3, [r1]
	strh r7, [r0]
	adds r1, #4
	adds r0, #4
	adds r4, #2
	cmp r4, r6
	blt .L080416DE
.L080416EC:
	lsls r0, r5, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	mov r2, r8
	adds r1, r0, r2
	movs r0, #1
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq .L08041710
	mov r0, ip
	ldrh r2, [r0, #4]
	b .L08041714
	.align 2, 0
.L08041708: .4byte gBg1Tm
.L0804170C: .4byte gUnk_0810F734
.L08041710:
	mov r0, ip
	ldrh r2, [r0, #0xa]
.L08041714:
	strh r2, [r1]
	movs r0, #2
	bl EnableBgSync
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start ClearUiEntryHover
ClearUiEntryHover: @ 0x08041728
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
	ldr r0, .L08041788 @ =gBg1Tm
	mov r8, r0
	ldr r1, .L0804178C @ =gUnk_0810F734
	mov ip, r1
	cmp r3, r5
	bge .L0804176C
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
.L0804175E:
	strh r7, [r1]
	strh r6, [r2]
	adds r1, #4
	adds r2, #4
	adds r3, #2
	cmp r3, r5
	blt .L0804175E
.L0804176C:
	lsls r0, r4, #5
	adds r0, r0, r5
	lsls r0, r0, #1
	mov r2, r8
	adds r1, r0, r2
	movs r0, #1
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq .L08041790
	mov r2, ip
	ldrh r0, [r2, #0xc]
	b .L08041794
	.align 2, 0
.L08041788: .4byte gBg1Tm
.L0804178C: .4byte gUnk_0810F734
.L08041790:
	mov r2, ip
	ldrh r0, [r2, #0xe]
.L08041794:
	strh r0, [r1]
	movs r0, #2
	bl EnableBgSync
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080417A8
func_fe6_080417A8: @ 0x080417A8
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, .L080417CC @ =gUnk_08111970
	adds r1, r3, #0
	bl Decompress
	ldr r0, .L080417D0 @ =gUnk_08111BC4
	lsls r4, r4, #5
	lsls r5, r5, #5
	adds r1, r4, #0
	adds r2, r5, #0
	bl ApplyPaletteExt
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080417CC: .4byte gUnk_08111970
.L080417D0: .4byte gUnk_08111BC4

	thumb_func_start LoadUiFrameGraphics
LoadUiFrameGraphics: @ 0x080417D4
	push {lr}
	movs r0, #0
	bl func_fe6_080412B0
	movs r0, #1
	rsbs r0, r0, #0
	bl func_fe6_08041284
	pop {r0}
	bx r0
