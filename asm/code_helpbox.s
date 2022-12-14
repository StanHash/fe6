	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_080715DC
func_fe6_080715DC: @ 0x080715DC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080715F8 @ =0x0203D440
	movs r3, #0
	strb r4, [r0, #0x10]
	strb r1, [r0, #0x11]
	strh r2, [r0, #0x12]
	str r3, [r0, #0x14]
	str r3, [r0, #0x18]
	bl func_fe6_08071748
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080715F8: .4byte 0x0203D440

	thumb_func_start func_fe6_080715FC
func_fe6_080715FC: @ 0x080715FC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r4, .L0807163C @ =gUnk_08678020
	adds r0, r4, #0
	bl Proc_Find
	adds r5, r0, #0
	cmp r5, #0
	bne .L08071644
	adds r0, r4, #0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	ldr r0, .L08071640 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807162A
	movs r0, #0x70
	bl m4aSongNumStart
.L0807162A:
	ldrb r1, [r6, #0x10]
	ldrb r2, [r6, #0x11]
	adds r0, r5, #0
	bl func_fe6_08071830
	adds r0, r5, #0
	bl func_fe6_08071838
	b .L08071660
	.align 2, 0
.L0807163C: .4byte gUnk_08678020
.L08071640: .4byte gPlaySt
.L08071644:
	ldrh r0, [r5, #0x30]
	strh r0, [r5, #0x38]
	ldrh r0, [r5, #0x32]
	strh r0, [r5, #0x3a]
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r1, [r0]
	subs r0, #4
	strh r1, [r0]
	adds r0, #6
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0x42
	strh r0, [r1]
.L08071660:
	str r6, [r5, #0x2c]
	adds r1, r5, #0
	adds r1, #0x48
	movs r0, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xc
	strh r0, [r1]
	ldrh r0, [r6, #0x12]
	adds r4, r5, #0
	adds r4, #0x4c
	strh r0, [r4]
	movs r0, #1
	bl SetTextFontGlyphs
	ldrh r0, [r4]
	bl DecodeMsg
	add r2, sp, #4
	mov r1, sp
	bl GetStringTextBox
	movs r0, #0
	bl SetTextFontGlyphs
	ldr r1, [sp]
	ldr r2, [sp, #4]
	adds r0, r5, #0
	bl func_fe6_08071778
	ldrb r1, [r6, #0x10]
	ldrb r2, [r6, #0x11]
	adds r0, r5, #0
	bl func_fe6_080717B8
	bl func_fe6_08071514
	adds r0, r5, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	ldrh r1, [r4]
	bl func_fe6_080714F8
	ldr r0, .L080716C4 @ =0x0203D45C
	str r6, [r0]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080716C4: .4byte 0x0203D45C

	thumb_func_start func_fe6_080716C8
func_fe6_080716C8: @ 0x080716C8
	push {lr}
	ldr r0, .L080716E8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080716DA
	movs r0, #0x71
	bl m4aSongNumStart
.L080716DA:
	bl func_fe6_08071514
	ldr r0, .L080716EC @ =gUnk_08678020
	bl Proc_BreakEach
	pop {r0}
	bx r0
	.align 2, 0
.L080716E8: .4byte gPlaySt
.L080716EC: .4byte gUnk_08678020

	thumb_func_start func_fe6_080716F0
func_fe6_080716F0: @ 0x080716F0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x50
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r4, #0x2c]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq .L08071708
	adds r0, r4, #0
	bl _call_via_r1
.L08071708:
	ldr r0, [r4, #0x2c]
	bl func_fe6_080715FC
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071714
func_fe6_08071714: @ 0x08071714
	push {lr}
	adds r2, r0, #0
	ldr r0, .L08071730 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807172C
	adds r0, r2, #0
	bl Proc_Break
.L0807172C:
	pop {r0}
	bx r0
	.align 2, 0
.L08071730: .4byte gKeySt

	thumb_func_start func_fe6_08071734
func_fe6_08071734: @ 0x08071734
	push {r4, lr}
	adds r4, r0, #0
	bl func_fe6_080716C8
	adds r0, r4, #0
	bl Proc_End
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071748
func_fe6_08071748: @ 0x08071748
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0807175C @ =gUnk_08678040
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807175C: .4byte gUnk_08678040

	thumb_func_start func_fe6_08071760
func_fe6_08071760: @ 0x08071760
	push {lr}
	ldr r0, .L08071774 @ =gUnk_08678040
	bl Proc_Find
	cmp r0, #0
	beq .L0807176E
	movs r0, #1
.L0807176E:
	pop {r1}
	bx r1
	.align 2, 0
.L08071774: .4byte gUnk_08678040

	thumb_func_start func_fe6_08071778
func_fe6_08071778: @ 0x08071778
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r4, #0x1f
	movs r0, #0xe0
	ands r4, r0
	adds r0, r6, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	bl func_fe6_08071848
	cmp r0, #1
	beq .L0807179A
	cmp r0, #2
	beq .L080717A0
	b .L080717A8
.L0807179A:
	movs r4, #0xa0
	adds r5, #0x20
	b .L080717A8
.L080717A0:
	cmp r4, #0x5f
	bgt .L080717A6
	movs r4, #0x60
.L080717A6:
	adds r5, #0x10
.L080717A8:
	adds r0, r6, #0
	adds r0, #0x44
	strh r4, [r0]
	adds r0, #2
	strh r5, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080717B8
func_fe6_080717B8: @ 0x080717B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	mov r8, r2
	adds r0, #0x44
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r6, r0, #0
	adds r6, #0x10
	adds r0, r5, #0
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r7, r0, #0
	adds r7, #0x10
	adds r0, r6, #0
	movs r1, #6
	bl __divsi3
	adds r0, #0x10
	subs r4, r4, r0
	strh r4, [r5, #0x3c]
	lsls r4, r4, #0x10
	cmp r4, #0
	bge .L080717F2
	movs r0, #0
	strh r0, [r5, #0x3c]
.L080717F2:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	adds r0, r0, r6
	cmp r0, #0xf0
	ble .L08071802
	movs r0, #0xf0
	subs r0, r0, r6
	strh r0, [r5, #0x3c]
.L08071802:
	mov r0, r8
	adds r0, #0x10
	strh r0, [r5, #0x3e]
	movs r1, #0x3e
	ldrsh r0, [r5, r1]
	adds r0, r0, r7
	cmp r0, #0xa0
	ble .L08071818
	mov r1, r8
	subs r0, r1, r7
	strh r0, [r5, #0x3e]
.L08071818:
	ldrh r0, [r5, #0x3c]
	adds r0, #8
	strh r0, [r5, #0x3c]
	ldrh r0, [r5, #0x3e]
	adds r0, #8
	strh r0, [r5, #0x3e]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08071830
func_fe6_08071830: @ 0x08071830
	strh r1, [r0, #0x38]
	strh r2, [r0, #0x3a]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08071838
func_fe6_08071838: @ 0x08071838
	adds r2, r0, #0
	adds r2, #0x40
	movs r1, #0x20
	strh r1, [r2]
	adds r0, #0x42
	movs r1, #0x10
	strh r1, [r0]
	bx lr

	thumb_func_start func_fe6_08071848
func_fe6_08071848: @ 0x08071848
	push {r4, lr}
	adds r4, r0, #0
	bl GetItemAttributes
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	bne .L0807187A
	adds r0, r4, #0
	bl GetItemAttributes
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L0807186C
	movs r0, #1
	b .L08071880
.L0807186C:
	adds r0, r4, #0
	bl GetItemAttributes
	movs r1, #4
	ands r1, r0
	cmp r1, #0
	bne .L0807187E
.L0807187A:
	movs r0, #0
	b .L08071880
.L0807187E:
	movs r0, #2
.L08071880:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08071888
func_fe6_08071888: @ 0x08071888
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080718A4 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L080718A0
	adds r0, r2, #0
	bl Proc_Break
.L080718A0:
	pop {r0}
	bx r0
	.align 2, 0
.L080718A4: .4byte gKeySt

	thumb_func_start func_fe6_080718A8
func_fe6_080718A8: @ 0x080718A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl func_fe6_08070E70
	bl GetUiHandPrevX
	adds r4, r0, #0
	bl GetUiHandPrevY
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl func_fe6_080715DC
	ldr r0, .L080718DC @ =gUnk_08678070
	adds r1, r6, #0
	bl SpawnProcLocking
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L080718DC: .4byte gUnk_08678070

	thumb_func_start func_fe6_080718E0
func_fe6_080718E0: @ 0x080718E0
	push {lr}
	ldr r0, .L080718F0 @ =gUnk_08678080
	bl Proc_Find
	cmp r0, #0
	bne .L080718F4
	movs r0, #0
	b .L080718F6
	.align 2, 0
.L080718F0: .4byte gUnk_08678080
.L080718F4:
	movs r0, #1
.L080718F6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_080718FC
func_fe6_080718FC: @ 0x080718FC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	cmp r7, #0
	bne .L08071908
	ldr r7, .L08071968 @ =0x06013000
.L08071908:
	cmp r5, #0
	bge .L0807190E
	movs r5, #5
.L0807190E:
	movs r4, #0xf
	adds r0, r4, #0
	ands r0, r5
	adds r5, r0, #0
	adds r5, #0x10
	ldr r0, .L0807196C @ =gUnk_08308A78
	adds r1, r7, #0
	bl Decompress
	ldr r6, .L08071970 @ =0x0203D460
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl InitSpriteTextFont
	adds r0, r6, #0
	adds r0, #0x18
	bl InitSpriteText
	adds r0, r6, #0
	adds r0, #0x20
	bl InitSpriteText
	adds r0, r6, #0
	adds r0, #0x28
	bl InitSpriteText
	movs r0, #0
	bl SetTextFont
	ldr r0, .L08071974 @ =Pal_08100A48
	lsls r1, r5, #5
	movs r2, #0x20
	bl ApplyPaletteExt
	lsls r0, r7, #0x11
	lsrs r0, r0, #0x16
	ands r5, r4
	lsls r1, r5, #0xc
	adds r0, r0, r1
	strh r0, [r6, #0x30]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08071968: .4byte 0x06013000
.L0807196C: .4byte gUnk_08308A78
.L08071970: .4byte 0x0203D460
.L08071974: .4byte Pal_08100A48

	thumb_func_start func_fe6_08071978
func_fe6_08071978: @ 0x08071978
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r0, #0
	adds r2, #0x10
	adds r1, r3, #0
	adds r1, #0x44
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #0xbf
	ble .L0807199A
	movs r0, #0xc0
	strh r0, [r1]
.L0807199A:
	movs r6, #0
	ldrsh r0, [r1, r6]
	adds r1, r0, #0
	adds r1, #0x10
	strh r4, [r3, #0x3c]
	movs r4, #0x3c
	ldrsh r0, [r3, r4]
	adds r0, r0, r1
	cmp r0, #0xf0
	ble .L080719B4
	movs r0, #0xf0
	subs r0, r0, r1
	strh r0, [r3, #0x3c]
.L080719B4:
	adds r0, r5, #0
	adds r0, #8
	strh r0, [r3, #0x3e]
	movs r6, #0x3e
	ldrsh r0, [r3, r6]
	adds r0, r0, r2
	cmp r0, #0xa0
	ble .L080719CA
	subs r0, r5, r2
	subs r0, #8
	strh r0, [r3, #0x3e]
.L080719CA:
	ldrh r0, [r3, #0x3c]
	adds r0, #8
	strh r0, [r3, #0x3c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080719D8
func_fe6_080719D8: @ 0x080719D8
	adds r1, #0x27
	movs r3, #0xe0
	ands r1, r3
	adds r3, r0, #0
	adds r3, #0x44
	strh r1, [r3]
	adds r0, #0x46
	strh r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_080719EC
func_fe6_080719EC: @ 0x080719EC
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x38
	ldrb r0, [r1]
	cmp r0, #0xff
	bne .L08071A06
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl func_fe6_080718FC
	b .L08071A0E
.L08071A06:
	ldrb r1, [r1]
	movs r0, #0
	bl func_fe6_080718FC
.L08071A0E:
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	ldr r2, [r4, #0x34]
	bl func_fe6_08071D04
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08071A20
func_fe6_08071A20: @ 0x08071A20
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08071A24
func_fe6_08071A24: @ 0x08071A24
	push {lr}
	movs r0, #0
	bl SetTextFontGlyphs
	bl func_fe6_08071B6C
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071A34
func_fe6_08071A34: @ 0x08071A34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r1, #0
	movs r0, #0x38
	ldrsh r1, [r7, r0]
	movs r3, #0x3c
	ldrsh r2, [r7, r3]
	adds r4, r7, #0
	adds r4, #0x48
	movs r0, #0
	ldrsh r6, [r4, r0]
	mov r8, r6
	movs r3, #0x4a
	adds r3, r3, r7
	mov sl, r3
	movs r6, #0
	ldrsh r0, [r3, r6]
	str r0, [sp]
	adds r0, r5, #0
	mov r3, r8
	bl Interpolate
	mov sb, r0
	movs r0, #0x3a
	ldrsh r1, [r7, r0]
	movs r3, #0x3e
	ldrsh r2, [r7, r3]
	movs r0, #0
	ldrsh r6, [r4, r0]
	mov r8, r6
	mov r3, sl
	movs r6, #0
	ldrsh r0, [r3, r6]
	str r0, [sp]
	adds r0, r5, #0
	mov r3, r8
	bl Interpolate
	mov r8, r0
	adds r0, r7, #0
	adds r0, #0x40
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, #4
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	ldrsh r6, [r4, r0]
	mov ip, r6
	mov r3, sl
	movs r6, #0
	ldrsh r0, [r3, r6]
	str r0, [sp]
	adds r0, r5, #0
	mov r3, ip
	bl Interpolate
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r0, #0x42
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, #4
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r6, #0
	ldrsh r3, [r4, r6]
	mov r4, sl
	movs r6, #0
	ldrsh r0, [r4, r6]
	str r0, [sp]
	adds r0, r5, #0
	bl Interpolate
	adds r3, r0, #0
	mov r0, sb
	strh r0, [r7, #0x30]
	mov r2, r8
	strh r2, [r7, #0x32]
	mov r0, sb
	mov r1, r8
	ldr r2, [sp, #4]
	bl func_fe6_08071D94
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08071AF8
func_fe6_08071AF8: @ 0x08071AF8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #5
	bl func_fe6_08071A34
	adds r2, r4, #0
	adds r2, #0x48
	adds r4, #0x4a
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bge .L08071B1A
	adds r0, r3, #1
	strh r0, [r2]
.L08071B1A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071B20
func_fe6_08071B20: @ 0x08071B20
	push {r4, r5, lr}
	adds r4, r0, #0
	bl ResetHelpBoxInitSize
	adds r5, r4, #0
	adds r5, #0x4a
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __divsi3
	strh r0, [r5]
	adds r4, #0x48
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08071B44
func_fe6_08071B44: @ 0x08071B44
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	bl func_fe6_08071A34
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L08071B64
	adds r0, r4, #0
	bl Proc_Break
.L08071B64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08071B6C
func_fe6_08071B6C: @ 0x08071B6C
	push {lr}
	bl func_fe6_080721D0
	ldr r0, .L08071B7C @ =gUnk_086780C8
	bl Proc_BreakEach
	pop {r0}
	bx r0
	.align 2, 0
.L08071B7C: .4byte gUnk_086780C8

	thumb_func_start func_fe6_08071B80
func_fe6_08071B80: @ 0x08071B80
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	cmp r3, #0
	bne .L08071B9C
	ldr r0, .L08071B98 @ =gUnk_08678080
	movs r1, #3
	bl SpawnProc
	b .L08071BA4
	.align 2, 0
.L08071B98: .4byte gUnk_08678080
.L08071B9C:
	ldr r0, .L08071BBC @ =gUnk_08678080
	adds r1, r3, #0
	bl SpawnProcLocking
.L08071BA4:
	adds r3, r0, #0
	str r4, [r3, #0x2c]
	str r5, [r3, #0x30]
	str r6, [r3, #0x34]
	adds r1, r3, #0
	adds r1, #0x38
	movs r0, #0xff
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08071BBC: .4byte gUnk_08678080

	thumb_func_start func_fe6_08071BC0
func_fe6_08071BC0: @ 0x08071BC0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, [sp, #0x14]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r3, #0
	bne .L08071BE0
	ldr r0, .L08071BDC @ =gUnk_08678080
	movs r1, #3
	bl SpawnProc
	b .L08071BE8
	.align 2, 0
.L08071BDC: .4byte gUnk_08678080
.L08071BE0:
	ldr r0, .L08071BFC @ =gUnk_08678080
	adds r1, r3, #0
	bl SpawnProcLocking
.L08071BE8:
	adds r3, r0, #0
	str r5, [r3, #0x2c]
	str r6, [r3, #0x30]
	str r7, [r3, #0x34]
	adds r0, r3, #0
	adds r0, #0x38
	strb r4, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08071BFC: .4byte gUnk_08678080

	thumb_func_start func_fe6_08071C00
func_fe6_08071C00: @ 0x08071C00
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	movs r7, #0
	movs r6, #0x10
	str r7, [r4]
	str r7, [r5]
.L08071C12:
	ldrb r0, [r3]
	cmp r0, #4
	bhi .L08071C74
	lsls r0, r0, #2
	ldr r1, .L08071C24 @ =.L08071C28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08071C24: .4byte .L08071C28
.L08071C28: @ jump table
	.4byte .L08071C62 @ case 0
	.4byte .L08071C3C @ case 1
	.4byte .L08071C4C @ case 2
	.4byte .L08071C4C @ case 3
	.4byte .L08071C48 @ case 4
.L08071C3C:
	adds r6, #0x10
	ldr r0, [r4]
	cmp r0, r7
	bge .L08071C46
	str r7, [r4]
.L08071C46:
	movs r7, #0
.L08071C48:
	adds r3, #1
	b .L08071C12
.L08071C4C:
	ldr r0, [r4]
	cmp r0, r7
	bge .L08071C54
	str r7, [r4]
.L08071C54:
	movs r7, #0
	ldr r0, [r5]
	cmp r0, r6
	bge .L08071C5E
	str r6, [r5]
.L08071C5E:
	movs r6, #0
	b .L08071C48
.L08071C62:
	ldr r0, [r4]
	cmp r0, r7
	bge .L08071C6A
	str r7, [r4]
.L08071C6A:
	ldr r0, [r5]
	cmp r0, r6
	bge .L08071C84
	str r6, [r5]
	b .L08071C84
.L08071C74:
	adds r0, r3, #0
	mov r1, sp
	bl GetCharTextLen
	adds r3, r0, #0
	ldr r0, [sp]
	adds r7, r7, r0
	b .L08071C12
.L08071C84:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071C8C
func_fe6_08071C8C: @ 0x08071C8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r1, #0
	mov r8, r2
	movs r6, #0
	movs r5, #0
	adds r4, r0, #0
	strb r5, [r7]
	strb r5, [r2]
	movs r0, #1
	bl SetTextFontGlyphs
.L08071CA8:
	ldrb r0, [r4]
	cmp r0, #4
	bhi .L08071CDC
	lsls r0, r0, #2
	ldr r1, .L08071CB8 @ =.L08071CBC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08071CB8: .4byte .L08071CBC
.L08071CBC: @ jump table
	.4byte .L08071CEC @ case 0
	.4byte .L08071CD4 @ case 1
	.4byte .L08071CEC @ case 2
	.4byte .L08071CEC @ case 3
	.4byte .L08071CD0 @ case 4
.L08071CD0:
	adds r4, #1
	b .L08071CA8
.L08071CD4:
	adds r4, #1
	adds r5, #0x10
	movs r6, #0
	b .L08071CA8
.L08071CDC:
	adds r0, r4, #0
	mov r1, sp
	bl GetCharTextLen
	adds r4, r0, #0
	ldr r0, [sp]
	adds r6, r6, r0
	b .L08071CA8
.L08071CEC:
	adds r0, r6, #2
	strb r0, [r7]
	adds r0, r5, #0
	adds r0, #8
	mov r1, r8
	strb r0, [r1]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071D04
func_fe6_08071D04: @ 0x08071D04
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	mov r8, r0
	mov sb, r1
	adds r6, r2, #0
	ldr r0, .L08071D90 @ =gUnk_086780C8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	mov r1, r8
	mov r2, sb
	bl SetHelpBoxInitPosition
	adds r0, r4, #0
	bl ResetHelpBoxInitSize
	movs r1, #0
	str r1, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x48
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	movs r0, #0xc
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x4e
	strh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x4c
	strh r6, [r5]
	movs r0, #1
	bl SetTextFontGlyphs
	ldrh r0, [r5]
	bl DecodeMsg
	add r2, sp, #4
	mov r1, sp
	bl func_fe6_08071C00
	movs r0, #0
	bl SetTextFontGlyphs
	ldr r1, [sp]
	ldr r2, [sp, #4]
	adds r0, r4, #0
	bl func_fe6_080719D8
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	bl func_fe6_08071978
	bl func_fe6_080721D0
	ldrh r0, [r5]
	bl func_fe6_080721B8
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08071D90: .4byte gUnk_086780C8

	thumb_func_start func_fe6_08071D94
func_fe6_08071D94: @ 0x08071D94
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	mov sl, r1
	adds r7, r2, #0
	mov r8, r3
	cmp r7, #0x1f
	bgt .L08071DAE
	movs r7, #0x20
.L08071DAE:
	cmp r7, #0xc0
	ble .L08071DB4
	movs r7, #0xc0
.L08071DB4:
	mov r0, r8
	cmp r0, #0xf
	bgt .L08071DBE
	movs r1, #0x10
	mov r8, r1
.L08071DBE:
	mov r3, r8
	cmp r3, #0x30
	ble .L08071DC8
	movs r0, #0x30
	mov r8, r0
.L08071DC8:
	adds r0, r7, #0
	adds r0, #0x1f
	cmp r0, #0
	bge .L08071DD2
	adds r0, #0x1f
.L08071DD2:
	asrs r0, r0, #5
	mov r1, r8
	adds r1, #0xf
	cmp r1, #0
	bge .L08071DDE
	adds r1, #0xf
.L08071DDE:
	asrs r1, r1, #4
	str r1, [sp, #4]
	subs r6, r0, #1
	str r6, [sp, #8]
	mov r1, sl
	subs r1, #8
	str r1, [sp, #0x18]
	mov r3, sl
	add r3, r8
	str r3, [sp, #0x10]
	mov r0, sb
	subs r0, #8
	str r0, [sp, #0x14]
	mov r1, sb
	adds r1, r1, r7
	str r1, [sp, #0xc]
	cmp r6, #0
	blt .L08071E4A
.L08071E02:
	ldr r5, [sp, #4]
	subs r4, r6, #1
	cmp r5, #0
	blt .L08071E44
.L08071E0A:
	adds r0, r6, #1
	lsls r1, r0, #5
	cmp r1, r7
	ble .L08071E14
	adds r1, r7, #0
.L08071E14:
	subs r1, #0x20
	adds r0, r5, #1
	lsls r0, r0, #4
	cmp r0, r8
	ble .L08071E20
	mov r0, r8
.L08071E20:
	subs r0, #0x10
	add r1, sb
	mov r3, sl
	adds r2, r3, r0
	ldr r3, .L08071F28 @ =0x0203D460
	lsls r0, r6, #2
	ldrh r3, [r3, #0x30]
	adds r0, r3, r0
	lsls r3, r5, #6
	adds r0, r0, r3
	str r0, [sp]
	movs r0, #2
	ldr r3, .L08071F2C @ =Sprite_32x16
	bl PutSprite
	subs r5, #1
	cmp r5, #0
	bge .L08071E0A
.L08071E44:
	adds r6, r4, #0
	cmp r6, #0
	bge .L08071E02
.L08071E4A:
	ldr r6, [sp, #8]
	cmp r6, #0
	blt .L08071E8C
	ldr r5, .L08071F28 @ =0x0203D460
.L08071E52:
	adds r0, r6, #1
	lsls r1, r0, #5
	cmp r1, r7
	ble .L08071E5C
	adds r1, r7, #0
.L08071E5C:
	subs r1, #0x20
	mov r0, sb
	adds r4, r0, r1
	ldrh r0, [r5, #0x30]
	adds r0, #0x1b
	str r0, [sp]
	movs r0, #2
	adds r1, r4, #0
	ldr r2, [sp, #0x18]
	ldr r3, .L08071F30 @ =Sprite_32x8
	bl PutSprite
	ldrh r0, [r5, #0x30]
	adds r0, #0x1b
	str r0, [sp]
	movs r0, #2
	adds r1, r4, #0
	ldr r2, [sp, #0x10]
	ldr r3, .L08071F34 @ =Sprite_32x8_VFlipped
	bl PutSprite
	subs r6, #1
	cmp r6, #0
	bge .L08071E52
.L08071E8C:
	ldr r5, [sp, #4]
	cmp r5, #0
	blt .L08071ECE
	ldr r6, .L08071F28 @ =0x0203D460
.L08071E94:
	adds r0, r5, #1
	lsls r0, r0, #4
	cmp r0, r8
	ble .L08071E9E
	mov r0, r8
.L08071E9E:
	subs r0, #0x10
	mov r1, sl
	adds r4, r1, r0
	ldrh r0, [r6, #0x30]
	adds r0, #0x1f
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0x14]
	adds r2, r4, #0
	ldr r3, .L08071F38 @ =Sprite_8x16
	bl PutSprite
	ldrh r0, [r6, #0x30]
	adds r0, #0x1f
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0xc]
	adds r2, r4, #0
	ldr r3, .L08071F3C @ =Sprite_8x16_HFlipped
	bl PutSprite
	subs r5, #1
	cmp r5, #0
	bge .L08071E94
.L08071ECE:
	ldr r3, .L08071F40 @ =Sprite_8x8
	ldr r4, .L08071F28 @ =0x0203D460
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	bl PutSprite
	ldr r3, .L08071F44 @ =Sprite_8x8_HFlipped
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x18]
	bl PutSprite
	ldr r3, .L08071F48 @ =Sprite_8x8_VFlipped
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x10]
	bl PutSprite
	ldr r3, .L08071F4C @ =Sprite_8x8_HFlipped_VFlipped
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	bl PutSprite
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08071F28: .4byte 0x0203D460
.L08071F2C: .4byte Sprite_32x16
.L08071F30: .4byte Sprite_32x8
.L08071F34: .4byte Sprite_32x8_VFlipped
.L08071F38: .4byte Sprite_8x16
.L08071F3C: .4byte Sprite_8x16_HFlipped
.L08071F40: .4byte Sprite_8x8
.L08071F44: .4byte Sprite_8x8_HFlipped
.L08071F48: .4byte Sprite_8x8_VFlipped
.L08071F4C: .4byte Sprite_8x8_HFlipped_VFlipped

	thumb_func_start func_fe6_08071F50
func_fe6_08071F50: @ 0x08071F50
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x2c]
	adds r1, r2, #0
	adds r1, #0x56
	adds r2, #0x57
	bl func_fe6_08071C8C
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071F64
func_fe6_08071F64: @ 0x08071F64
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x58
	ldrb r0, [r5]
	cmp r0, #1
	bne .L08071FA4
	ldr r4, .L08071FA0 @ =0x0203D460
	adds r0, r4, #0
	bl SetTextFont
	adds r0, r4, #0
	adds r0, #0x18
	bl SpriteText_DrawBackground
	adds r0, r4, #0
	adds r0, #0x20
	bl SpriteText_DrawBackground
	adds r4, #0x28
	adds r0, r4, #0
	bl SpriteText_DrawBackground
	movs r0, #0
	bl SetTextFont
	movs r0, #0
	strb r0, [r5]
	b .L080720D4
	.align 2, 0
.L08071FA0: .4byte 0x0203D460
.L08071FA4:
	adds r0, r6, #0
	adds r0, #0x52
	movs r1, #0
	ldrsh r7, [r0, r1]
	ldr r0, .L08071FC0 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0xf3
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08071FC4
	movs r7, #0x80
	b .L08071FDE
	.align 2, 0
.L08071FC0: .4byte gKeySt
.L08071FC4:
	adds r1, r6, #0
	adds r1, #0x4e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble .L08071FD6
	b .L080720D4
.L08071FD6:
	adds r0, r6, #0
	adds r0, #0x50
	ldrh r0, [r0]
	strh r0, [r1]
.L08071FDE:
	ldr r0, [r6, #0x30]
	bl SetTextFont
	movs r5, #0
	cmp r5, r7
	bge .L080720CE
.L08071FEA:
	ldr r2, [r6, #0x2c]
	ldrb r0, [r2]
	adds r3, r2, #0
	cmp r0, #4
	bhi .L0807208C
	lsls r0, r0, #2
	ldr r1, .L08072000 @ =.L08072004
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08072000: .4byte .L08072004
.L08072004: @ jump table
	.4byte .L08072018 @ case 0
	.4byte .L08072020 @ case 1
	.4byte .L08072036 @ case 2
	.4byte .L08072036 @ case 3
	.4byte .L08072030 @ case 4
.L08072018:
	adds r0, r6, #0
	bl Proc_Break
	b .L080720CE
.L08072020:
	adds r0, r3, #1
	str r0, [r6, #0x2c]
	adds r1, r6, #0
	adds r1, #0x4c
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b .L080720C8
.L08072030:
	adds r0, r3, #1
	str r0, [r6, #0x2c]
	b .L080720C8
.L08072036:
	adds r1, r6, #0
	adds r1, #0x4c
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r6, #0x2c]
	adds r0, #1
	str r0, [r6, #0x2c]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x2c]
	ldrb r2, [r0]
	cmp r2, #1
	bne .L08072056
	adds r0, #1
	str r0, [r6, #0x2c]
.L08072056:
	ldr r0, .L08072088 @ =gUnk_086780C8
	bl Proc_Find
	movs r3, #0x3c
	ldrsh r1, [r0, r3]
	adds r5, r6, #0
	adds r5, #0x56
	ldrb r2, [r5]
	adds r1, r2, r1
	movs r3, #0x3e
	ldrsh r2, [r0, r3]
	adds r4, r6, #0
	adds r4, #0x57
	ldrb r0, [r4]
	adds r2, r0, r2
	adds r0, r6, #0
	bl StartTalkWaitForInput
	ldr r0, [r6, #0x2c]
	adds r1, r5, #0
	adds r2, r4, #0
	bl func_fe6_08071C8C
	b .L080720CE
	.align 2, 0
.L08072088: .4byte gUnk_086780C8
.L0807208C:
	adds r0, r6, #0
	adds r0, #0x4c
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	subs r0, #0x18
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r2, #0
	bl Text_DrawCharacter
	str r0, [r6, #0x2c]
	bl GetTextPrintDelay
	adds r4, r0, #0
	cmp r4, #1
	bne .L080720B8
	bl GetGameTime
	ands r0, r4
	cmp r0, #0
	beq .L080720C8
.L080720B8:
	ldr r0, .L080720DC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080720C8
	movs r0, #0x6e
	bl m4aSongNumStart
.L080720C8:
	adds r5, #1
	cmp r5, r7
	blt .L08071FEA
.L080720CE:
	movs r0, #0
	bl SetTextFont
.L080720D4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080720DC: .4byte gPlaySt

	thumb_func_start func_fe6_080720E0
func_fe6_080720E0: @ 0x080720E0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080720FC @ =gUnk_08678080
	bl Proc_Find
	movs r1, #0
	bl Proc_Goto
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080720FC: .4byte gUnk_08678080

	thumb_func_start func_fe6_08072100
func_fe6_08072100: @ 0x08072100
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	mov sl, r0
	ldr r5, .L080721B0 @ =0x0203D460
	adds r0, r5, #0
	bl SetTextFont
	movs r0, #0
	bl SetTextFontGlyphs
	movs r0, #1
	bl SetTextFontGlyphs
	movs r0, #0x18
	adds r0, r0, r5
	mov sb, r0
	movs r1, #6
	bl Text_SetColor
	movs r1, #0x20
	adds r1, r1, r5
	mov r8, r1
	mov r0, r8
	movs r1, #6
	bl Text_SetColor
	adds r6, r5, #0
	adds r6, #0x28
	adds r0, r6, #0
	movs r1, #6
	bl Text_SetColor
	movs r0, #0
	bl SetTextFont
	ldr r4, .L080721B4 @ =gUnk_086780E8
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x30]
	mov r0, sb
	str r0, [r4, #0x34]
	mov r1, r8
	str r1, [r4, #0x38]
	str r6, [r4, #0x3c]
	adds r0, r4, #0
	adds r0, #0x4c
	movs r5, #0
	strh r5, [r0]
	mov r1, sl
	ldr r0, [r1, #0x5c]
	bl DecodeMsg
	str r0, [r4, #0x2c]
	bl GetTextPrintDelay
	adds r1, r4, #0
	adds r1, #0x50
	strh r0, [r1]
	lsls r0, r0, #0x10
	movs r1, #0x80
	cmp r0, #0
	beq .L08072190
	movs r1, #1
.L08072190:
	adds r0, r4, #0
	adds r0, #0x52
	strh r1, [r0]
	subs r0, #4
	strh r5, [r0]
	adds r1, r4, #0
	adds r1, #0x58
	movs r0, #0
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080721B0: .4byte 0x0203D460
.L080721B4: .4byte gUnk_086780E8

	thumb_func_start func_fe6_080721B8
func_fe6_080721B8: @ 0x080721B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080721CC @ =gUnk_08678110
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080721CC: .4byte gUnk_08678110

	thumb_func_start func_fe6_080721D0
func_fe6_080721D0: @ 0x080721D0
	push {r4, lr}
	ldr r4, .L0807220C @ =0x0203D460
	adds r0, r4, #0
	bl SetTextFont
	adds r0, r4, #0
	adds r0, #0x18
	bl SpriteText_DrawBackground
	adds r0, r4, #0
	adds r0, #0x20
	bl SpriteText_DrawBackground
	adds r4, #0x28
	adds r0, r4, #0
	bl SpriteText_DrawBackground
	ldr r0, .L08072210 @ =gUnk_086780E8
	bl Proc_EndEach
	ldr r0, .L08072214 @ =gUnk_08678110
	bl Proc_EndEach
	movs r0, #0
	bl SetTextFont
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807220C: .4byte 0x0203D460
.L08072210: .4byte gUnk_086780E8
.L08072214: .4byte gUnk_08678110
