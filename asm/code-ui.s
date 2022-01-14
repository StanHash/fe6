
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

	thumb_func_start func_fe6_080415CC
func_fe6_080415CC: @ 0x080415CC
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

	thumb_func_start func_fe6_0804163C
func_fe6_0804163C: @ 0x0804163C
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

	thumb_func_start func_fe6_08041660
func_fe6_08041660: @ 0x08041660
	ldr r0, .L08041668 @ =0x0203C9D4
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
.L08041668: .4byte 0x0203C9D4

	thumb_func_start func_fe6_0804166C
func_fe6_0804166C: @ 0x0804166C
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

	thumb_func_start func_fe6_0804169C
func_fe6_0804169C: @ 0x0804169C
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

	thumb_func_start func_fe6_08041728
func_fe6_08041728: @ 0x08041728
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

	thumb_func_start func_fe6_080417E8
func_fe6_080417E8: @ 0x080417E8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r2, #0
	ldr r2, [r4]
	cmp r1, #0x77
	bgt .L080417F8
	lsls r0, r3, #0x18
	b .L080417FA
.L080417F8:
	lsls r0, r0, #0x18
.L080417FA:
	lsrs r0, r0, #0x18
	ldr r1, .L08041814 @ =0xFFFFFF00
	ands r2, r1
	orrs r2, r0
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #0
	bl func_fe6_08041844
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L08041814: .4byte 0xFFFFFF00

	thumb_func_start func_fe6_08041818
func_fe6_08041818: @ 0x08041818
	push {lr}
	adds r2, r1, #0
	ldr r1, [r0]
	bl func_fe6_08041844
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08041828
func_fe6_08041828: @ 0x08041828
	push {lr}
	movs r2, #0
	bl func_fe6_08041844
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08041834
func_fe6_08041834: @ 0x08041834
	push {lr}
	ldr r1, [r0]
	movs r2, #0
	bl func_fe6_08041844
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08041844
func_fe6_08041844: @ 0x08041844
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
	ldr r0, .L080418A0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0804188A
	movs r0, #0x68
	bl m4aSongNumStart
.L0804188A:
	cmp r4, #0
	beq .L080418A8
	ldr r0, .L080418A4 @ =gUnk_085CB424
	adds r1, r4, #0
	bl SpawnProcLocking
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x63
	movs r0, #0
	b .L080418BC
	.align 2, 0
.L080418A0: .4byte gPlaySt
.L080418A4: .4byte gUnk_085CB424
.L080418A8:
	bl LockGame
	ldr r0, .L080419C0 @ =gUnk_085CB424
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x63
	movs r0, #1
.L080418BC:
	strb r0, [r1]
	mov r1, sb
	asrs r0, r1, #0x18
	str r0, [sp, #0x18]
	cmp r0, #0
	bge .L080418D4
	adds r1, r4, #0
	adds r1, #0x63
	movs r0, #8
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
.L080418D4:
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
	beq .L08041976
	movs r6, #0
.L080418FC:
	adds r0, r6, r1
	ldr r2, [r0, #0xc]
	adds r1, r7, #0
	bl _call_via_r2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #2
	beq .L08041966
	ldr r0, .L080419C4 @ =gUnk_085CB464
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
	bne .L08041962
	adds r0, r2, #0
	adds r0, #0x34
	mov r2, sb
	lsls r1, r2, #8
	asrs r1, r1, #0x18
	subs r1, #2
	bl InitText
.L08041962:
	movs r3, #2
	add r8, r3
.L08041966:
	adds r6, #0x24
	adds r7, #1
	ldr r0, [sp]
	ldr r1, [r0, #8]
	adds r0, r6, r1
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne .L080418FC
.L08041976:
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
	bge .L080419A8
	subs r0, r1, #1
	mov r1, r8
	subs r0, r1, r0
	adds r1, r4, #0
	adds r1, #0x2f
	strb r0, [r1]
.L080419A8:
	ldr r0, .L080419C8 @ =gKeySt
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
.L080419C0: .4byte gUnk_085CB424
.L080419C4: .4byte gUnk_085CB464
.L080419C8: .4byte gKeySt

	thumb_func_start func_fe6_080419CC
func_fe6_080419CC: @ 0x080419CC
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
	beq .L080419F8
	adds r0, r4, #0
	bl _call_via_r2
.L080419F8:
	ldr r0, [r4, #0x30]
	ldr r1, [r0, #0x10]
	cmp r1, #0
	beq .L08041A06
	adds r0, r4, #0
	bl _call_via_r1
.L08041A06:
	movs r0, #1
	ldrb r5, [r5]
	ands r0, r5
	cmp r0, #0
	beq .L08041A14
	bl UnlockGame
.L08041A14:
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

	thumb_func_start func_fe6_08041A38
func_fe6_08041A38: @ 0x08041A38
	push {lr}
	ldr r0, .L08041A48 @ =gUnk_085CB424
	ldr r1, .L08041A4C @ =func_fe6_080419CC
	bl Proc_ForEach
	pop {r0}
	bx r0
	.align 2, 0
.L08041A48: .4byte gUnk_085CB424
.L08041A4C: .4byte func_fe6_080419CC

	thumb_func_start func_fe6_08041A50
func_fe6_08041A50: @ 0x08041A50
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x30]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq .L08041A62
	adds r0, r4, #0
	bl _call_via_r1
.L08041A62:
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
	beq .L08041A80
	adds r0, r4, #0
	bl _call_via_r2
.L08041A80:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08041A88
func_fe6_08041A88: @ 0x08041A88
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
	bne .L08041B68
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
	bl func_fe6_08041358
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
	bge .L08041B56
.L08041AEA:
	lsls r1, r7, #2
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r1, [r4, #0x30]
	ldr r2, [r1, #0x10]
	cmp r2, #0
	beq .L08041B06
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
	b .L08041B4C
.L08041B06:
	ldrb r0, [r1, #8]
	adds r5, r4, #0
	adds r5, #0x34
	cmp r0, #0
	beq .L08041B18
	adds r1, r0, #0
	adds r0, r5, #0
	bl Text_SetColor
.L08041B18:
	adds r0, r4, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08041B2A
	adds r0, r5, #0
	movs r1, #1
	bl Text_SetColor
.L08041B2A:
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
	ldr r0, .L08041B78 @ =gBg0Tm
	adds r1, r1, r0
	adds r0, r5, #0
	bl PutText
.L08041B4C:
	adds r7, #1
	mov r0, r8
	ldrb r0, [r0]
	cmp r7, r0
	blt .L08041AEA
.L08041B56:
	mov r2, sb
	ldrb r1, [r2]
	adds r0, r6, #0
	movs r2, #1
	bl func_fe6_08041B7C
	movs r0, #3
	bl EnableBgSync
.L08041B68:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08041B78: .4byte gBg0Tm

	thumb_func_start func_fe6_08041B7C
func_fe6_08041B7C: @ 0x08041B7C
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
	bne .L08041BD2
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
	beq .L08041BCC
	cmp r0, #1
	bne .L08041BD2
	adds r0, r3, #0
	bl func_fe6_0804169C
	b .L08041BD2
.L08041BCC:
	adds r0, r3, #0
	bl func_fe6_08041728
.L08041BD2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08041BD8
func_fe6_08041BD8: @ 0x08041BD8
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x63
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L08041BFE
	add r2, sp, #4
	adds r0, r5, #0
	mov r1, sp
	bl func_fe6_08041E24
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl func_fe6_0804163C
	b .L08041CBE
.L08041BFE:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08041C0E
	adds r0, r5, #0
	bl func_fe6_080419CC
	b .L08041CBE
.L08041C0E:
	adds r0, r5, #0
	bl func_fe6_08041CCC
	adds r0, r5, #0
	bl func_fe6_08041DA8
	adds r4, r0, #0
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq .L08041C2A
	adds r0, r5, #0
	bl func_fe6_080419CC
.L08041C2A:
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq .L08041C42
	ldr r0, .L08041CC8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08041C42
	movs r0, #0x6a
	bl m4aSongNumStart
.L08041C42:
	movs r0, #8
	ands r0, r4
	cmp r0, #0
	beq .L08041C5A
	ldr r0, .L08041CC8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08041C5A
	movs r0, #0x6b
	bl m4aSongNumStart
.L08041C5A:
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0
	beq .L08041C66
	bl ClearBg0Bg1
.L08041C66:
	movs r6, #0x20
	adds r0, r4, #0
	ands r0, r6
	cmp r0, #0
	beq .L08041C76
	movs r0, #0
	bl EndFaceById
.L08041C76:
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq .L08041C8A
	adds r1, r5, #0
	adds r1, #0x63
	movs r0, #0x80
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
.L08041C8A:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne .L08041CBE
	adds r1, r5, #0
	adds r1, #0x63
	adds r0, r6, #0
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L08041CBE
	add r4, sp, #4
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl func_fe6_08041E24
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl func_fe6_08042070
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl func_fe6_080415CC
.L08041CBE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08041CC8: .4byte gPlaySt

	thumb_func_start func_fe6_08041CCC
func_fe6_08041CCC: @ 0x08041CCC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r2, r6, #0
	adds r2, #0x61
	ldrb r0, [r2]
	adds r1, r6, #0
	adds r1, #0x62
	strb r0, [r1]
	ldr r1, .L08041DA0 @ =gKeySt
	ldr r3, [r1]
	ldrh r4, [r3, #6]
	movs r0, #0x40
	ands r0, r4
	cmp r0, #0
	beq .L08041D04
	ldrb r0, [r2]
	cmp r0, #0
	bne .L08041CFE
	ldrh r3, [r3, #8]
	cmp r4, r3
	bne .L08041D9A
	adds r0, r6, #0
	adds r0, #0x60
	ldrb r0, [r0]
	strb r0, [r2]
.L08041CFE:
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
.L08041D04:
	ldr r1, [r1]
	ldrh r3, [r1, #6]
	movs r0, #0x80
	ands r0, r3
	adds r4, r6, #0
	adds r4, #0x61
	cmp r0, #0
	beq .L08041D32
	ldrb r2, [r4]
	adds r0, r6, #0
	adds r0, #0x60
	ldrb r0, [r0]
	subs r0, #1
	cmp r2, r0
	bne .L08041D2C
	ldrh r1, [r1, #8]
	cmp r3, r1
	bne .L08041D9A
	movs r0, #0xff
	strb r0, [r4]
.L08041D2C:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
.L08041D32:
	adds r0, r6, #0
	adds r0, #0x62
	adds r5, r0, #0
	ldrb r0, [r5]
	ldrb r1, [r4]
	cmp r0, r1
	beq .L08041D64
	ldrb r1, [r5]
	adds r0, r6, #0
	movs r2, #0
	bl func_fe6_08041B7C
	ldrb r1, [r4]
	adds r0, r6, #0
	movs r2, #1
	bl func_fe6_08041B7C
	ldr r0, .L08041DA4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08041D64
	movs r0, #0x66
	bl m4aSongNumStart
.L08041D64:
	ldrb r0, [r4]
	ldrb r1, [r5]
	cmp r0, r1
	beq .L08041D9A
	lsls r0, r1, #2
	adds r5, r6, #0
	adds r5, #0x34
	adds r0, r5, r0
	ldr r1, [r0]
	ldr r0, [r1, #0x30]
	ldr r2, [r0, #0x20]
	cmp r2, #0
	beq .L08041D84
	adds r0, r6, #0
	bl _call_via_r2
.L08041D84:
	ldrb r4, [r4]
	lsls r0, r4, #2
	adds r0, r5, r0
	ldr r1, [r0]
	ldr r0, [r1, #0x30]
	ldr r2, [r0, #0x1c]
	cmp r2, #0
	beq .L08041D9A
	adds r0, r6, #0
	bl _call_via_r2
.L08041D9A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08041DA0: .4byte gKeySt
.L08041DA4: .4byte gPlaySt

	thumb_func_start func_fe6_08041DA8
func_fe6_08041DA8: @ 0x08041DA8
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
	beq .L08041DCC
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
.L08041DCC:
	ldr r0, .L08041DE0 @ =gKeySt
	ldr r0, [r0]
	ldrh r1, [r0, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08041DE4
	ldr r2, [r6, #0x14]
	b .L08041DF0
	.align 2, 0
.L08041DE0: .4byte gKeySt
.L08041DE4:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08041E02
	ldr r0, [r4, #0x30]
	ldr r2, [r0, #0x18]
.L08041DF0:
	cmp r2, #0
	beq .L08041E1A
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	b .L08041E1A
.L08041E02:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08041E1A
	ldr r0, [r4, #0x30]
	ldr r1, [r0, #0x1c]
	cmp r1, #0
	beq .L08041E1A
	adds r0, r4, #0
	bl _call_via_r1
.L08041E1A:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08041E24
func_fe6_08041E24: @ 0x08041E24
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
	beq .L08041E64
	ldr r0, [r4]
	subs r0, #4
	str r0, [r4]
.L08041E64:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08041E6C
func_fe6_08041E6C: @ 0x08041E6C
	movs r0, #0
	bx lr

	thumb_func_start func_fe6_08041E70
func_fe6_08041E70: @ 0x08041E70
	movs r0, #1
	bx lr

	thumb_func_start func_fe6_08041E74
func_fe6_08041E74: @ 0x08041E74
	movs r0, #0x1b
	bx lr

	thumb_func_start func_fe6_08041E78
func_fe6_08041E78: @ 0x08041E78
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
	bl func_fe6_080706C8
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08041E94
func_fe6_08041E94: @ 0x08041E94
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl func_fe6_08070E70
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

	thumb_func_start func_fe6_08041EC4
func_fe6_08041EC4: @ 0x08041EC4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	bl func_fe6_08041CCC
	add r4, sp, #4
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl func_fe6_08041E24
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl func_fe6_08042070
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl func_fe6_080415CC
	ldr r0, .L08041F0C @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08041F14
	bl func_fe6_0807089C
	ldr r1, .L08041F10 @ =gUnk_085CB40C
	adds r0, r5, #0
	bl Proc_GotoScript
	b .L08041F3A
	.align 2, 0
.L08041F0C: .4byte gKeySt
.L08041F10: .4byte gUnk_085CB40C
.L08041F14:
	adds r1, r5, #0
	adds r1, #0x61
	adds r0, r5, #0
	adds r0, #0x62
	ldrb r2, [r1]
	ldrb r0, [r0]
	cmp r2, r0
	beq .L08041F3A
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
.L08041F3A:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08041F44
func_fe6_08041F44: @ 0x08041F44
	push {lr}
	ldr r1, .L08041F50 @ =gUnk_085CB46C
	bl Proc_GotoScript
	pop {r1}
	bx r1
	.align 2, 0
.L08041F50: .4byte gUnk_085CB46C

	thumb_func_start func_fe6_08041F54
func_fe6_08041F54: @ 0x08041F54
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	add r4, sp, #4
	mov r1, sp
	adds r2, r4, #0
	bl func_fe6_08041E24
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl func_fe6_08042070
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl func_fe6_0804163C
	ldr r0, .L08041F9C @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08041F92
	bl func_fe6_0807089C
	ldr r1, .L08041FA0 @ =gUnk_085CB40C
	adds r0, r5, #0
	bl Proc_GotoScript
.L08041F92:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08041F9C: .4byte gKeySt
.L08041FA0: .4byte gUnk_085CB40C

	thumb_func_start MenuFrozenHelpBox
MenuFrozenHelpBox: @ 0x08041FA4
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r1, .L08041FD4 @ =gUnk_085CB484
	bl Proc_GotoScript
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl func_fe6_08070E70
	bl func_fe6_08041660
	adds r4, r0, #0
	bl func_fe6_0804166C
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl func_fe6_080706C8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08041FD4: .4byte gUnk_085CB484

	thumb_func_start func_fe6_08041FD8
func_fe6_08041FD8: @ 0x08041FD8
	push {lr}
	ldr r0, .L08041FF4 @ =gUnk_085CB424
	bl Proc_Find
	cmp r0, #0
	beq .L08041FEE
	adds r0, #0x63
	movs r1, #0x40
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
.L08041FEE:
	pop {r0}
	bx r0
	.align 2, 0
.L08041FF4: .4byte gUnk_085CB424

	thumb_func_start func_fe6_08041FF8
func_fe6_08041FF8: @ 0x08041FF8
	push {lr}
	ldr r0, .L08042014 @ =gUnk_085CB424
	bl Proc_Find
	cmp r0, #0
	beq .L08042010
	adds r1, r0, #0
	adds r1, #0x63
	movs r0, #0xbf
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
.L08042010:
	pop {r0}
	bx r0
	.align 2, 0
.L08042014: .4byte gUnk_085CB424

	thumb_func_start func_fe6_08042018
func_fe6_08042018: @ 0x08042018
	push {r4, r5, r6, r7, lr}
	bl func_fe6_080417E8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x60
	ldrb r0, [r1]
	cmp r0, #6
	bls .L08042062
	adds r2, r4, #0
	adds r2, #0x2d
	ldr r5, .L0804206C @ =gUnk_085CB494
	ldrb r3, [r1]
	adds r0, r3, r5
	ldrb r7, [r2]
	ldrb r0, [r0]
	subs r0, r7, r0
	strb r0, [r2]
	movs r3, #0
	ldrb r0, [r1]
	cmp r3, r0
	bge .L08042062
	adds r6, r5, #0
	adds r2, r1, #0
	adds r5, r4, #0
	adds r5, #0x34
.L0804204C:
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
	blt .L0804204C
.L08042062:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0804206C: .4byte gUnk_085CB494

	thumb_func_start func_fe6_08042070
func_fe6_08042070: @ 0x08042070
	push {r4, r5, r6, lr}
	adds r1, r0, #0
	adds r6, r2, #0
	adds r0, #0x60
	ldrb r2, [r0]
	cmp r2, #9
	bls .L080420AE
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
.L080420AE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080420B4
func_fe6_080420B4: @ 0x080420B4
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
	ldr r2, .L080420DC @ =0x0203C9DC
	movs r3, #0
	strh r0, [r2]
	strh r1, [r2, #2]
	ldr r0, .L080420E0 @ =0x0203CCE0
	str r3, [r0]
	bx lr
	.align 2, 0
.L080420DC: .4byte 0x0203C9DC
.L080420E0: .4byte 0x0203CCE0

	thumb_func_start EnlistTarget
EnlistTarget: @ 0x080420E4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r4, .L08042130 @ =0x0203C9E0
	mov r8, r4
	ldr r6, .L08042134 @ =0x0203CCE0
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
.L08042130: .4byte 0x0203C9E0
.L08042134: .4byte 0x0203CCE0

	thumb_func_start func_fe6_08042138
func_fe6_08042138: @ 0x08042138
	push {r4, r5, r6, lr}
	movs r2, #0
	ldr r0, .L08042178 @ =0x0203CCE0
	ldr r1, [r0]
	adds r6, r0, #0
	ldr r4, .L0804217C @ =0x0203C9E0
	cmp r2, r1
	bge .L08042162
	adds r5, r6, #0
	adds r3, r4, #0
	adds r3, #0xc
	adds r1, r4, #0
	subs r1, #0xc
.L08042152:
	str r1, [r1, #0x14]
	str r3, [r1, #0x10]
	adds r3, #0xc
	adds r1, #0xc
	adds r2, #1
	ldr r0, [r5]
	cmp r2, r0
	blt .L08042152
.L08042162:
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
.L08042178: .4byte 0x0203CCE0
.L0804217C: .4byte 0x0203C9E0

	thumb_func_start func_fe6_08042180
func_fe6_08042180: @ 0x08042180
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

	thumb_func_start func_fe6_08042194
func_fe6_08042194: @ 0x08042194
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x34
	movs r0, #0x40
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L080421BE
	add r2, sp, #4
	adds r0, r4, #0
	mov r1, sp
	bl func_fe6_08042180
	ldr r0, [sp]
	ldr r1, [sp, #4]
	movs r2, #4
	bl PutMapCursor
	b .L08042256
.L080421BE:
	adds r0, r4, #0
	bl func_fe6_08042310
	adds r0, r4, #0
	bl func_fe6_08042388
	adds r5, r0, #0
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080421DA
	adds r0, r4, #0
	bl EndMapSelect
.L080421DA:
	movs r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080421F2
	ldr r0, .L08042260 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080421F2
	movs r0, #0x6a
	bl m4aSongNumStart
.L080421F2:
	movs r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L0804220A
	ldr r0, .L08042260 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0804220A
	movs r0, #0x6b
	bl m4aSongNumStart
.L0804220A:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L08042216
	bl ClearBg0Bg1
.L08042216:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L08042224
	movs r0, #0
	bl EndFaceById
.L08042224:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	bne .L08042256
	add r2, sp, #4
	adds r0, r4, #0
	mov r1, sp
	bl func_fe6_08042180
	ldr r1, [sp]
	asrs r1, r1, #4
	ldr r2, [sp, #4]
	asrs r2, r2, #4
	adds r0, r4, #0
	bl CameraMoveWatchPosition
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L08042256
	ldr r0, [sp]
	ldr r1, [sp, #4]
	movs r2, #2
	bl PutMapCursor
.L08042256:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08042260: .4byte gPlaySt

	thumb_func_start StartMapSelect
StartMapSelect: @ 0x08042264
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl LockGame
	ldr r0, .L080422C4 @ =gUnk_085CB4A0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x34
	movs r6, #0
	movs r0, #1
	strb r0, [r1]
	str r4, [r5, #0x2c]
	bl func_fe6_08042534
	str r0, [r5, #0x30]
	str r6, [r5, #0x38]
	ldr r0, [r5, #0x2c]
	ldr r1, [r0]
	cmp r1, #0
	beq .L08042298
	adds r0, r5, #0
	bl _call_via_r1
.L08042298:
	ldr r0, [r5, #0x2c]
	ldr r1, [r0, #8]
	cmp r1, #0
	beq .L080422A6
	adds r0, r5, #0
	bl _call_via_r1
.L080422A6:
	ldr r0, [r5, #0x2c]
	ldr r2, [r0, #0xc]
	cmp r2, #0
	beq .L080422B6
	ldr r1, [r5, #0x30]
	adds r0, r5, #0
	bl _call_via_r2
.L080422B6:
	ldr r0, .L080422C8 @ =gKeySt
	ldr r0, [r0]
	strh r6, [r0, #8]
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L080422C4: .4byte gUnk_085CB4A0
.L080422C8: .4byte gKeySt

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
	beq .L080422EE
	adds r0, r4, #0
	bl _call_via_r1
.L080422EE:
	adds r1, r4, #0
	adds r1, #0x34
	movs r0, #1
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L08042300
	bl UnlockGame
.L08042300:
	adds r0, r4, #0
	bl Proc_End
	ldr r0, [r4, #0x14]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08042310
func_fe6_08042310: @ 0x08042310
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r4, #0x30]
	ldr r2, .L08042380 @ =gKeySt
	ldr r1, [r2]
	movs r0, #0x60
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L0804232C
	ldr r0, [r3, #4]
	cmp r0, #0
	beq .L0804232C
	str r0, [r4, #0x30]
.L0804232C:
	ldr r1, [r2]
	movs r0, #0x90
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L08042342
	ldr r0, [r4, #0x30]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq .L08042342
	str r0, [r4, #0x30]
.L08042342:
	ldr r0, [r4, #0x30]
	cmp r0, r3
	beq .L08042378
	ldr r0, [r4, #0x2c]
	ldr r2, [r0, #0x10]
	cmp r2, #0
	beq .L08042358
	adds r0, r4, #0
	adds r1, r3, #0
	bl _call_via_r2
.L08042358:
	ldr r0, [r4, #0x2c]
	ldr r2, [r0, #0xc]
	cmp r2, #0
	beq .L08042368
	ldr r1, [r4, #0x30]
	adds r0, r4, #0
	bl _call_via_r2
.L08042368:
	ldr r0, .L08042384 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08042378
	movs r0, #0x67
	bl m4aSongNumStart
.L08042378:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042380: .4byte gKeySt
.L08042384: .4byte gPlaySt

	thumb_func_start func_fe6_08042388
func_fe6_08042388: @ 0x08042388
	push {r4, lr}
	adds r2, r0, #0
	movs r4, #0
	ldr r0, .L080423A8 @ =gKeySt
	ldr r0, [r0]
	ldrh r1, [r0, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080423AC
	ldr r3, [r2, #0x38]
	cmp r3, #0
	bne .L080423CC
	ldr r0, [r2, #0x2c]
	ldr r3, [r0, #0x14]
	b .L080423C8
	.align 2, 0
.L080423A8: .4byte gKeySt
.L080423AC:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080423BA
	ldr r0, [r2, #0x2c]
	ldr r3, [r0, #0x18]
	b .L080423C8
.L080423BA:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080423D8
	ldr r0, [r2, #0x2c]
	ldr r3, [r0, #0x1c]
.L080423C8:
	cmp r3, #0
	beq .L080423D8
.L080423CC:
	ldr r1, [r2, #0x30]
	adds r0, r2, #0
	bl _call_via_r3
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
.L080423D8:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_080423E0
func_fe6_080423E0: @ 0x080423E0
	push {lr}
	ldr r0, .L080423FC @ =gUnk_085CB4A0
	bl Proc_Find
	cmp r0, #0
	beq .L080423F6
	adds r0, #0x34
	movs r1, #0x40
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
.L080423F6:
	pop {r0}
	bx r0
	.align 2, 0
.L080423FC: .4byte gUnk_085CB4A0

	thumb_func_start func_fe6_08042400
func_fe6_08042400: @ 0x08042400
	push {lr}
	ldr r0, .L0804241C @ =gUnk_085CB4A0
	bl Proc_Find
	cmp r0, #0
	beq .L08042418
	adds r1, r0, #0
	adds r1, #0x34
	movs r0, #0xbf
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
.L08042418:
	pop {r0}
	bx r0
	.align 2, 0
.L0804241C: .4byte gUnk_085CB4A0

	thumb_func_start func_fe6_08042420
func_fe6_08042420: @ 0x08042420
	push {r4, r5, r6, r7, lr}
	movs r7, #0
	ldr r5, .L08042458 @ =0x0203C9E0
	ldr r0, .L0804245C @ =0x0203CCE0
	ldr r0, [r0]
	cmp r7, r0
	bge .L08042476
	ldr r1, .L08042460 @ =0x0203C9DC
	mov ip, r1
	movs r2, #0
	ldrsh r6, [r1, r2]
	adds r4, r0, #0
.L08042438:
	movs r0, #0
	ldrsb r0, [r5, r0]
	subs r2, r6, r0
	cmp r2, #0
	bge .L08042444
	subs r2, r0, r6
.L08042444:
	mov r0, ip
	movs r1, #2
	ldrsh r3, [r0, r1]
	movs r0, #1
	ldrsb r0, [r5, r0]
	subs r1, r3, r0
	cmp r1, #0
	blt .L08042464
	adds r0, r2, r1
	b .L08042468
	.align 2, 0
.L08042458: .4byte 0x0203C9E0
.L0804245C: .4byte 0x0203CCE0
.L08042460: .4byte 0x0203C9DC
.L08042464:
	subs r0, r0, r3
	adds r0, r2, r0
.L08042468:
	cmp r7, r0
	bge .L0804246E
	adds r7, r0, #0
.L0804246E:
	subs r4, #1
	adds r5, #0xc
	cmp r4, #0
	bne .L08042438
.L08042476:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08042480
func_fe6_08042480: @ 0x08042480
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r7, #0
	movs r5, #0
	movs r4, #0
	ldr r0, .L08042514 @ =0x0203CCE0
	mov sb, r0
	ldr r1, .L08042518 @ =0x0203C9DC
	mov r8, r1
	ldr r3, .L0804251C @ =gUnk_085CB4D0
	mov sl, r3
.L0804249E:
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
	ldr r3, .L08042520 @ =0x0203C9E0
	mov r6, sb
	ldr r0, [r6]
	adds r4, #1
	cmp r1, r0
	bge .L080424F8
	mov ip, sb
.L080424CA:
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldr r6, [sp]
	cmp r6, r0
	bne .L080424EC
	movs r0, #1
	ldrsb r0, [r3, r0]
	cmp r2, r0
	bne .L080424EC
	str r5, [r3, #4]
	cmp r5, #0
	beq .L080424E4
	str r3, [r5, #8]
.L080424E4:
	cmp r7, #0
	bne .L080424EA
	adds r7, r3, #0
.L080424EA:
	adds r5, r3, #0
.L080424EC:
	adds r1, #1
	adds r3, #0xc
	mov r6, ip
	ldr r0, [r6]
	cmp r1, r0
	blt .L080424CA
.L080424F8:
	cmp r4, #0xc
	ble .L0804249E
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
.L08042514: .4byte 0x0203CCE0
.L08042518: .4byte 0x0203C9DC
.L0804251C: .4byte gUnk_085CB4D0
.L08042520: .4byte 0x0203C9E0

	thumb_func_start func_fe6_08042524
func_fe6_08042524: @ 0x08042524
	push {lr}
	bl func_fe6_08042138
	ldr r0, .L08042530 @ =0x0203C9E0
	pop {r1}
	bx r1
	.align 2, 0
.L08042530: .4byte 0x0203C9E0

	thumb_func_start func_fe6_08042534
func_fe6_08042534: @ 0x08042534
	push {lr}
	bl func_fe6_08042420
	cmp r0, #2
	bgt .L08042544
	bl func_fe6_08042480
	b .L08042548
.L08042544:
	bl func_fe6_08042524
.L08042548:
	pop {r1}
	bx r1

	thumb_func_start CountTargets
CountTargets: @ 0x0804254C
	ldr r0, .L08042554 @ =0x0203CCE0
	ldr r0, [r0]
	bx lr
	.align 2, 0
.L08042554: .4byte 0x0203CCE0

	thumb_func_start GetTarget
GetTarget: @ 0x08042558
	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L08042568 @ =0x0203C9E0
	adds r0, r0, r1
	bx lr
	.align 2, 0
.L08042568: .4byte 0x0203C9E0
