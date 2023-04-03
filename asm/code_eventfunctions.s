	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_0806DCA4
func_fe6_0806DCA4: @ 0x0806DCA4
	push {r4, lr}
	sub sp, #8
	movs r0, #0
	bl InitBgs
	ldr r2, .L0806DCF8 @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	movs r4, #0
	str r4, [sp]
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	ldr r2, .L0806DCFC @ =0x01000008
	mov r0, sp
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r1, .L0806DD00 @ =0x06006000
	ldr r2, .L0806DD04 @ =0x01000800
	bl CpuFastSet
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806DCF8: .4byte gDispIo
.L0806DCFC: .4byte 0x01000008
.L0806DD00: .4byte 0x06006000
.L0806DD04: .4byte 0x01000800

	thumb_func_start func_fe6_0806DD08
func_fe6_0806DD08: @ 0x0806DD08
	push {r4, r5, lr}
	sub sp, #8
	ldr r2, .L0806DD74 @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r4, .L0806DD78 @ =gBg0Tm
	adds r0, r4, #0
	movs r1, #0
	bl TmFill
	bl ResetText
	bl InitTalkTextFont
	ldr r5, .L0806DD7C @ =0x0203D3A0
	adds r0, r5, #0
	movs r1, #0xe
	bl InitText
	ldr r0, .L0806DD80 @ =0x0000024A
	bl DecodeMsg
	movs r1, #0x94
	lsls r1, r1, #2
	adds r4, r4, r1
	movs r1, #0
	str r1, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl PutDrawText
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806DD74: .4byte gDispIo
.L0806DD78: .4byte gBg0Tm
.L0806DD7C: .4byte 0x0203D3A0
.L0806DD80: .4byte 0x0000024A

	thumb_func_start func_fe6_0806DD84
func_fe6_0806DD84: @ 0x0806DD84
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0806DD94 @ =gUnk_0867688C
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0806DD94: .4byte gUnk_0867688C

	thumb_func_start func_fe6_0806DD98
func_fe6_0806DD98: @ 0x0806DD98
	push {lr}
	ldr r0, .L0806DDB4 @ =gUnk_0867688C
	bl FindProc
	cmp r0, #0
	bne .L0806DDBC
	ldr r0, .L0806DDB8 @ =gUnk_08677FE0
	bl Proc_EndEach
	bl func_fe6_0806DCA4
	movs r0, #0
	b .L0806DDBE
	.align 2, 0
.L0806DDB4: .4byte gUnk_0867688C
.L0806DDB8: .4byte gUnk_08677FE0
.L0806DDBC:
	movs r0, #1
.L0806DDBE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806DDC4
func_fe6_0806DDC4: @ 0x0806DDC4
	adds r0, #0x44
	movs r1, #0xff
	strb r1, [r0]
	bx lr

	thumb_func_start func_fe6_0806DDCC
func_fe6_0806DDCC: @ 0x0806DDCC
	adds r0, #0x45
	movs r1, #1
	strb r1, [r0]
	bx lr

	thumb_func_start func_fe6_0806DDD4
func_fe6_0806DDD4: @ 0x0806DDD4
	push {lr}
	movs r0, #0
	bl SetWeather
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806DDE0
func_fe6_0806DDE0: @ 0x0806DDE0
	push {lr}
	ldr r0, .L0806DDFC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0806DDF2
	movs r0, #0xc4
	bl m4aSongNumStart
.L0806DDF2:
	movs r0, #6
	bl SetWeather
	pop {r0}
	bx r0
	.align 2, 0
.L0806DDFC: .4byte gPlaySt

	thumb_func_start func_fe6_0806DE00
func_fe6_0806DE00: @ 0x0806DE00
	push {lr}
	ldr r0, .L0806DE18 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0806DE12
	ldr r0, .L0806DE1C @ =0x00000269
	bl m4aSongNumStart
.L0806DE12:
	pop {r0}
	bx r0
	.align 2, 0
.L0806DE18: .4byte gPlaySt
.L0806DE1C: .4byte 0x00000269

	thumb_func_start func_fe6_0806DE20
func_fe6_0806DE20: @ 0x0806DE20
	push {lr}
	ldr r0, .L0806DE38 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0806DE32
	ldr r0, .L0806DE3C @ =0x00000269
	bl m4aSongNumStart
.L0806DE32:
	pop {r0}
	bx r0
	.align 2, 0
.L0806DE38: .4byte gPlaySt
.L0806DE3C: .4byte 0x00000269

	thumb_func_start func_fe6_0806DE40
func_fe6_0806DE40: @ 0x0806DE40
	push {lr}
	ldr r0, .L0806DE58 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0806DE52
	movs r0, #0x6a
	bl m4aSongNumStart
.L0806DE52:
	pop {r0}
	bx r0
	.align 2, 0
.L0806DE58: .4byte gPlaySt

	thumb_func_start func_fe6_0806DE5C
func_fe6_0806DE5C: @ 0x0806DE5C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x43
	movs r1, #0
	bl StartBgm
	adds r4, #0x64
	ldr r0, .L0806DE74 @ =0x000044C0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806DE74: .4byte 0x000044C0

	thumb_func_start func_fe6_0806DE78
func_fe6_0806DE78: @ 0x0806DE78
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x64
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0806DE9A
	movs r0, #0x34
	movs r1, #0
	bl StartBgm
	adds r0, r4, #0
	bl Proc_Break
.L0806DE9A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806DEA0
func_fe6_0806DEA0: @ 0x0806DEA0
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0806DEB0 @ =gUnk_086768C4
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0806DEB0: .4byte gUnk_086768C4

	thumb_func_start func_fe6_0806DEB4
func_fe6_0806DEB4: @ 0x0806DEB4
	push {lr}
	ldr r0, .L0806DEC0 @ =gUnk_086768C4
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
.L0806DEC0: .4byte gUnk_086768C4

	thumb_func_start func_fe6_0806DEC4
func_fe6_0806DEC4: @ 0x0806DEC4
	push {r4, lr}
	ldr r0, .L0806DEEC @ =IsLilinaBlue
	cmp r0, #0
	beq .L0806DEF0
	movs r0, #1
	bl GetUnitByPid
	adds r4, r0, #0
	movs r1, #0x26
	bl GetUnitSupportNumByPid
	adds r1, r0, #0
	adds r0, r4, #0
	bl GetUnitSupportLevel
	cmp r0, #2
	ble .L0806DEF0
	movs r0, #1
	b .L0806DEF2
	.align 2, 0
.L0806DEEC: .4byte IsLilinaBlue
.L0806DEF0:
	movs r0, #0
.L0806DEF2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806DEF8
func_fe6_0806DEF8: @ 0x0806DEF8
	push {lr}
	bl RenderMapForFade
	ldr r1, .L0806DF14 @ =gPlaySt
	movs r0, #0
	strb r0, [r1, #0xd]
	bl RefreshEntityMaps
	bl RefreshUnitSprites
	bl RenderMap
	pop {r0}
	bx r0
	.align 2, 0
.L0806DF14: .4byte gPlaySt

	thumb_func_start func_fe6_0806DF18
func_fe6_0806DF18: @ 0x0806DF18
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x64
	movs r0, #1
	strh r0, [r4]
	movs r0, #0x7b
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806DF34
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
.L0806DF34:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806DF3C
func_fe6_0806DF3C: @ 0x0806DF3C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
.L0806DF40:
	bl CanStartMu
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806DF8E
	adds r5, r6, #0
	adds r5, #0x64
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl GetNextAvailableBlueUnitId
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0806DF88
	ldr r4, [r6, #0x4c]
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl GetUnit
	adds r1, r0, #0
	ldr r0, .L0806DF84 @ =gBmSt
	ldrh r0, [r0, #0xc]
	lsls r3, r0, #0x10
	asrs r3, r3, #0x14
	adds r3, #0xd
	adds r0, r4, #0
	movs r2, #8
	bl TryMoveUnitDisplayed
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b .L0806DF40
	.align 2, 0
.L0806DF84: .4byte gBmSt
.L0806DF88:
	adds r0, r6, #0
	bl Proc_Break
.L0806DF8E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806DF94
func_fe6_0806DF94: @ 0x0806DF94
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0806DFA8 @ =gUnk_086768DC
	adds r1, r4, #0
	bl SpawnProc
	str r4, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806DFA8: .4byte gUnk_086768DC

	thumb_func_start func_fe6_0806DFAC
func_fe6_0806DFAC: @ 0x0806DFAC
	push {lr}
	ldr r0, .L0806DFC0 @ =gUnk_086768DC
	bl FindProc
	cmp r0, #0
	beq .L0806DFBA
	movs r0, #1
.L0806DFBA:
	pop {r1}
	bx r1
	.align 2, 0
.L0806DFC0: .4byte gUnk_086768DC

	thumb_func_start func_fe6_0806DFC4
func_fe6_0806DFC4: @ 0x0806DFC4
	adds r0, #0x64
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0806DFD0
func_fe6_0806DFD0: @ 0x0806DFD0
	adds r0, #0x64
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start func_fe6_0806DFD8
func_fe6_0806DFD8: @ 0x0806DFD8
	push {r4, lr}
	adds r1, r0, #0
	adds r4, r1, #0
	adds r4, #0x64
	ldrh r0, [r4]
	subs r0, #3
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt .L0806DFF6
	movs r0, #0
	strh r0, [r4]
	adds r0, r1, #0
	bl Proc_Break
.L0806DFF6:
	movs r1, #0
	ldrsh r0, [r4, r1]
	bl SetBgmVolume
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806E004
func_fe6_0806E004: @ 0x0806E004
	push {r4, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x66
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L0806E03A
	adds r4, r2, #0
	adds r4, #0x64
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	ble .L0806E032
	adds r0, r2, #0
	bl Proc_Break
.L0806E032:
	movs r1, #0
	ldrsh r0, [r4, r1]
	bl SetBgmVolume
.L0806E03A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806E040
func_fe6_0806E040: @ 0x0806E040
	push {lr}
	movs r0, #0
	bl func_fe6_080030B4
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806E04C
func_fe6_0806E04C: @ 0x0806E04C
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0806E05C @ =gUnk_086768FC
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0806E05C: .4byte gUnk_086768FC

	thumb_func_start func_fe6_0806E060
func_fe6_0806E060: @ 0x0806E060
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0806E070 @ =gUnk_08676914
	bl SpawnProcLocking
	pop {r0}
	bx r0
	.align 2, 0
.L0806E070: .4byte gUnk_08676914

	thumb_func_start func_fe6_0806E074
func_fe6_0806E074: @ 0x0806E074
	push {r4, r5, lr}
	movs r4, #0
	ldr r0, .L0806E0B4 @ =0x0000FFF4
	adds r5, r0, #0
.L0806E07C:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806E09E
	ldr r0, [r1]
	cmp r0, #0
	beq .L0806E09E
	ldrh r2, [r1, #0xc]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	bne .L0806E09E
	adds r0, r2, #0
	ands r0, r5
	strh r0, [r1, #0xc]
.L0806E09E:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0806E07C
	bl RefreshEntityMaps
	bl RefreshUnitSprites
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806E0B4: .4byte 0x0000FFF4

	thumb_func_start func_fe6_0806E0B8
func_fe6_0806E0B8: @ 0x0806E0B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r6, #1
	movs r4, #1
	movs r0, #1
	rsbs r0, r0, #0
	mov sb, r0
	ldr r1, .L0806E10C @ =gUnk_0867692C
	mov r8, r1
.L0806E0D0:
	adds r0, r4, #0
	bl GetUnit
	adds r2, r0, #0
	adds r7, r4, #1
	mov ip, r7
	cmp r2, #0
	beq .L0806E154
	ldr r1, [r2]
	cmp r1, #0
	beq .L0806E154
	ldrh r3, [r2, #0xc]
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	bne .L0806E154
	ldrb r1, [r1, #4]
	cmp r1, #1
	bne .L0806E114
	ldr r1, .L0806E110 @ =0x0000FFF6
	adds r0, r1, #0
	ands r0, r3
	strh r0, [r2, #0xc]
	mov r7, r8
	ldrb r0, [r7]
	strb r0, [r2, #0xe]
	ldrb r0, [r7, #1]
	strb r0, [r2, #0xf]
	b .L0806E154
	.align 2, 0
.L0806E10C: .4byte gUnk_0867692C
.L0806E110: .4byte 0x0000FFF6
.L0806E114:
	ldr r1, .L0806E170 @ =0x0203DCA7
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, sb
	beq .L0806E154
	ldr r0, .L0806E174 @ =0x0000FFF6
	mov sl, r0
	movs r5, #1
	rsbs r5, r5, #0
	adds r3, r1, #0
	lsls r0, r6, #2
	mov r7, r8
	adds r1, r0, r7
.L0806E12E:
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, r4
	bne .L0806E14A
	mov r0, sl
	ldrh r7, [r2, #0xc]
	ands r0, r7
	strh r0, [r2, #0xc]
	ldrb r0, [r1]
	strb r0, [r2, #0xe]
	ldrb r0, [r1, #1]
	strb r0, [r2, #0xf]
	adds r1, #4
	adds r6, #1
.L0806E14A:
	adds r3, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, r5
	bne .L0806E12E
.L0806E154:
	mov r4, ip
	cmp r4, #0x3f
	ble .L0806E0D0
	bl RefreshEntityMaps
	bl RefreshUnitSprites
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806E170: .4byte 0x0203DCA7
.L0806E174: .4byte 0x0000FFF6

	thumb_func_start func_fe6_0806E178
func_fe6_0806E178: @ 0x0806E178
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r5, #1
	movs r0, #1
	rsbs r0, r0, #0
	mov sb, r0
	ldr r7, .L0806E1CC @ =gUnk_0867695C
	adds r6, r7, #0
	adds r6, #8
	ldr r1, .L0806E1D0 @ =0x0000FFF6
	mov r8, r1
.L0806E192:
	adds r0, r5, #0
	bl GetUnit
	adds r2, r0, #0
	adds r0, r5, #1
	mov ip, r0
	cmp r2, #0
	beq .L0806E224
	ldr r3, [r2]
	cmp r3, #0
	beq .L0806E224
	ldrh r1, [r2, #0xc]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne .L0806E224
	ldrb r0, [r3, #4]
	cmp r0, #1
	beq .L0806E1D8
	cmp r0, #0x42
	beq .L0806E1E8
	movs r3, #0
	ldr r0, .L0806E1D4 @ =0x0203DCA7
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r4, r0, #0
	cmp r1, sb
	beq .L0806E224
	b .L0806E1F8
	.align 2, 0
.L0806E1CC: .4byte gUnk_0867695C
.L0806E1D0: .4byte 0x0000FFF6
.L0806E1D4: .4byte 0x0203DCA7
.L0806E1D8:
	movs r0, #1
	orrs r0, r1
	strh r0, [r2, #0xc]
	ldrb r0, [r7]
	strb r0, [r2, #0xe]
	ldrb r0, [r7, #1]
	strb r0, [r2, #0xf]
	b .L0806E224
.L0806E1E8:
	mov r0, r8
	ands r0, r1
	strh r0, [r2, #0xc]
	ldrb r0, [r7, #4]
	strb r0, [r2, #0xe]
	ldrb r0, [r7, #5]
	strb r0, [r2, #0xf]
	b .L0806E224
.L0806E1F8:
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r5
	bne .L0806E216
	mov r0, r8
	ldrh r1, [r2, #0xc]
	ands r0, r1
	strh r0, [r2, #0xc]
	ldrb r0, [r6]
	strb r0, [r2, #0xe]
	ldrb r0, [r6, #1]
	strb r0, [r2, #0xf]
	adds r6, #4
.L0806E216:
	adds r3, #1
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, sb
	bne .L0806E1F8
.L0806E224:
	mov r5, ip
	cmp r5, #0x3f
	ble .L0806E192
	bl RefreshEntityMaps
	bl RefreshUnitSprites
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806E240
func_fe6_0806E240: @ 0x0806E240
	push {r4, r5, lr}
	movs r4, #1
	ldr r0, .L0806E268 @ =0x0000FFF6
	adds r5, r0, #0
.L0806E248:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806E26C
	ldr r0, [r1]
	cmp r0, #0
	beq .L0806E26C
	ldrb r0, [r0, #4]
	cmp r0, #1
	bne .L0806E26C
	ldrh r0, [r1, #0xc]
	ands r0, r5
	strh r0, [r1, #0xc]
	b .L0806E272
	.align 2, 0
.L0806E268: .4byte 0x0000FFF6
.L0806E26C:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0806E248
.L0806E272:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806E278
func_fe6_0806E278: @ 0x0806E278
	push {lr}
	ldr r0, .L0806E2A0 @ =gBattleUnitA
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	cmp r0, #0xf
	beq .L0806E296
	ldr r0, .L0806E2A4 @ =gBattleUnitB
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	cmp r0, #0xf
	bne .L0806E29C
.L0806E296:
	movs r0, #0x7b
	bl SetFlag
.L0806E29C:
	pop {r0}
	bx r0
	.align 2, 0
.L0806E2A0: .4byte gBattleUnitA
.L0806E2A4: .4byte gBattleUnitB

	thumb_func_start UpdateEndingId
UpdateEndingId: @ 0x0806E2A8
	push {lr}
	ldr r0, .L0806E2D0 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	cmp r0, #0x19
	bne .L0806E2E4
	movs r0, #0x7b
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806E2D8
	bl IsFaeBlue
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806E2D8
	ldr r1, .L0806E2D4 @ =0x0203D3D9
	movs r0, #0
	b .L0806E2E8
	.align 2, 0
.L0806E2D0: .4byte gPlaySt
.L0806E2D4: .4byte 0x0203D3D9
.L0806E2D8:
	ldr r1, .L0806E2E0 @ =0x0203D3D9
	movs r0, #1
	b .L0806E2E8
	.align 2, 0
.L0806E2E0: .4byte 0x0203D3D9
.L0806E2E4:
	ldr r1, .L0806E2F0 @ =0x0203D3D9
	movs r0, #2
.L0806E2E8:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L0806E2F0: .4byte 0x0203D3D9

	thumb_func_start GetEndingId
GetEndingId: @ 0x0806E2F4
	push {lr}
	bl UpdateEndingId
	ldr r0, .L0806E304 @ =0x0203D3D9
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
.L0806E304: .4byte 0x0203D3D9

	thumb_func_start StartGameEndingScene
StartGameEndingScene: @ 0x0806E308
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0806E328 @ =gUnk_086770D4
	bl GetEndingId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r4
	ldr r0, [r0]
	adds r1, r5, #0
	bl StartEventLocking
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806E328: .4byte gUnk_086770D4

	thumb_func_start func_fe6_0806E32C
func_fe6_0806E32C: @ 0x0806E32C
	push {lr}
	bl GetEndingId
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	beq .L0806E34A
	cmp r1, #1
	bgt .L0806E344
	cmp r1, #0
	beq .L0806E34A
	b .L0806E362
.L0806E344:
	cmp r1, #2
	beq .L0806E358
	b .L0806E362
.L0806E34A:
	ldr r0, .L0806E354 @ =0x0203D3D8
	strb r1, [r0]
	bl func_fe6_080914DC
	b .L0806E362
	.align 2, 0
.L0806E354: .4byte 0x0203D3D8
.L0806E358:
	ldr r1, .L0806E368 @ =0x0203D3D8
	movs r0, #0x80
	strb r0, [r1]
	bl func_fe6_0809154C
.L0806E362:
	pop {r0}
	bx r0
	.align 2, 0
.L0806E368: .4byte 0x0203D3D8

	thumb_func_start func_fe6_0806E36C
func_fe6_0806E36C: @ 0x0806E36C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0806E38C @ =gUnk_030048A4
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0806E39C
	ldr r0, .L0806E390 @ =gUnk_0834B69C
	ldr r1, .L0806E394 @ =0x06000020
	bl Decompress
	ldr r0, .L0806E398 @ =gUnk_086772FC
	str r0, [r4, #0x3c]
	movs r0, #0x1c
	rsbs r0, r0, #0
	b .L0806E3F8
	.align 2, 0
.L0806E38C: .4byte gUnk_030048A4
.L0806E390: .4byte gUnk_0834B69C
.L0806E394: .4byte 0x06000020
.L0806E398: .4byte gUnk_086772FC
.L0806E39C:
	cmp r0, #1
	bne .L0806E3C0
	ldr r0, .L0806E3B4 @ =gUnk_0834B69C
	ldr r1, .L0806E3B8 @ =0x06000020
	bl Decompress
	ldr r0, .L0806E3BC @ =gUnk_0867730C
	str r0, [r4, #0x3c]
	movs r0, #0x1c
	rsbs r0, r0, #0
	b .L0806E3F8
	.align 2, 0
.L0806E3B4: .4byte gUnk_0834B69C
.L0806E3B8: .4byte 0x06000020
.L0806E3BC: .4byte gUnk_0867730C
.L0806E3C0:
	cmp r0, #2
	bne .L0806E3E4
	ldr r0, .L0806E3D8 @ =gUnk_08349A98
	ldr r1, .L0806E3DC @ =0x06000020
	bl Decompress
	ldr r0, .L0806E3E0 @ =gUnk_0867731C
	str r0, [r4, #0x3c]
	movs r0, #0x30
	rsbs r0, r0, #0
	b .L0806E3F8
	.align 2, 0
.L0806E3D8: .4byte gUnk_08349A98
.L0806E3DC: .4byte 0x06000020
.L0806E3E0: .4byte gUnk_0867731C
.L0806E3E4:
	cmp r0, #3
	bne .L0806E3FA
	ldr r0, .L0806E424 @ =gUnk_0834E1D4
	ldr r1, .L0806E428 @ =0x06000020
	bl Decompress
	ldr r0, .L0806E42C @ =gUnk_08677327
	str r0, [r4, #0x3c]
	movs r0, #0x18
	rsbs r0, r0, #0
.L0806E3F8:
	str r0, [r4, #0x38]
.L0806E3FA:
	movs r1, #0
	str r1, [r4, #0x30]
	movs r0, #0x90
	rsbs r0, r0, #0
	str r0, [r4, #0x2c]
	str r1, [r4, #0x34]
	str r1, [r4, #0x40]
	ldr r0, [r4, #0x3c]
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0
	bl func_fe6_0806E684
	ldrh r1, [r4, #0x38]
	ldrh r2, [r4, #0x2c]
	movs r0, #0
	bl SetBgOffset
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806E424: .4byte gUnk_0834E1D4
.L0806E428: .4byte 0x06000020
.L0806E42C: .4byte gUnk_08677327

	thumb_func_start func_fe6_0806E430
func_fe6_0806E430: @ 0x0806E430
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x30]
	adds r0, #1
	str r0, [r5, #0x30]
	cmp r0, #6
	ble .L0806E4F6
	movs r0, #0
	str r0, [r5, #0x30]
	ldr r2, [r5, #0x2c]
	adds r2, #1
	str r2, [r5, #0x2c]
	ldrh r1, [r5, #0x38]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl SetBgOffset
	ldr r6, [r5, #0x34]
	adds r4, r6, #1
	str r4, [r5, #0x34]
	adds r0, r4, #0
	movs r1, #0x18
	bl __modsi3
	cmp r0, #0
	bne .L0806E4F6
	ldr r0, [r5, #0x40]
	cmp r0, #0
	beq .L0806E480
	adds r0, r4, #0
	cmp r0, #0
	bge .L0806E474
	adds r0, r6, #0
	adds r0, #8
.L0806E474:
	asrs r0, r0, #3
	movs r1, #3
	rsbs r1, r1, #0
	bl func_fe6_0806E684
	b .L0806E4C8
.L0806E480:
	adds r0, r4, #0
	movs r1, #0x18
	bl __divsi3
	ldr r2, [r5, #0x3c]
	adds r0, r2, r0
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0806E4A6
	ldr r0, .L0806E4FC @ =gUnk_08677327
	cmp r2, r0
	bne .L0806E4A6
	ldr r0, .L0806E500 @ =gUnk_08352160
	ldr r1, .L0806E504 @ =0x06000020
	bl Decompress
.L0806E4A6:
	ldr r0, [r5, #0x34]
	adds r4, r0, #0
	cmp r0, #0
	bge .L0806E4B0
	adds r4, r0, #7
.L0806E4B0:
	asrs r4, r4, #3
	movs r1, #0x18
	bl __divsi3
	ldr r1, [r5, #0x3c]
	adds r1, r1, r0
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r4, #0
	bl func_fe6_0806E684
.L0806E4C8:
	ldr r4, [r5, #0x40]
	cmp r4, #0
	bne .L0806E4E8
	ldr r0, [r5, #0x34]
	movs r1, #0x18
	bl __divsi3
	ldr r1, [r5, #0x3c]
	adds r1, r1, r0
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0806E4F6
.L0806E4E8:
	adds r0, r4, #1
	str r0, [r5, #0x40]
	cmp r0, #4
	bne .L0806E4F6
	ldr r1, .L0806E508 @ =gUnk_030048B8
	movs r0, #1
	strb r0, [r1]
.L0806E4F6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0806E4FC: .4byte gUnk_08677327
.L0806E500: .4byte gUnk_08352160
.L0806E504: .4byte 0x06000020
.L0806E508: .4byte gUnk_030048B8

	thumb_func_start func_fe6_0806E50C
func_fe6_0806E50C: @ 0x0806E50C
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0806E51C @ =ProcScr_Unk_08677348
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0806E51C: .4byte ProcScr_Unk_08677348

	thumb_func_start func_fe6_0806E520
func_fe6_0806E520: @ 0x0806E520
	push {r4, lr}
	sub sp, #4
	ldr r0, .L0806E648 @ =gUnk_08677360
	bl InitBgs
	movs r0, #0xf
	bl DisableBgSync
	ldr r3, .L0806E64C @ =gDispIo
	movs r0, #8
	rsbs r0, r0, #0
	ldrb r1, [r3]
	ands r0, r1
	strb r0, [r3]
	movs r0, #1
	ldrb r2, [r3, #1]
	orrs r0, r2
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #8
	ands r0, r1
	subs r1, #0x10
	ands r0, r1
	subs r1, #0x20
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r3, #1]
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x44
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r2, [r0]
	ldr r0, .L0806E650 @ =0x0000FFE0
	ldrh r2, [r3, #0x3c]
	ands r0, r2
	movs r1, #1
	orrs r0, r1
	ldr r1, .L0806E654 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	bl UnpackUiWindowFrameGraphics
	ldr r0, .L0806E658 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L0806E65C @ =gBg1Tm
	movs r1, #0
	bl TmFill
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r4, .L0806E660 @ =gUnk_0836F6D4
	movs r0, #2
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	adds r0, r4, #0
	bl Decompress
	ldr r0, .L0806E664 @ =gUnk_08373F80
	ldr r1, .L0806E668 @ =gBg2Tm
	bl Decompress
	ldr r0, .L0806E66C @ =gUnk_08374670
	ldr r1, .L0806E670 @ =gBuf
	bl Decompress
	movs r4, #0
.L0806E5E6:
	ldr r0, .L0806E670 @ =gBuf
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl func_fe6_0805B5C8
	adds r4, #1
	cmp r4, #7
	ble .L0806E5E6
	ldr r0, .L0806E670 @ =gBuf
	movs r2, #0x80
	lsls r2, r2, #2
	movs r1, #0
	bl ApplyPaletteExt
	ldr r1, .L0806E674 @ =gPal
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L0806E678 @ =gUnk_08353308
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r0, #1
	str r0, [sp]
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl func_fe6_0809892C
	bl func_fe6_08069C34
	ldr r0, .L0806E67C @ =func_fe6_08069FD8
	bl SetOnHBlankA
	bl func_fe6_0806A7AC
	ldr r0, .L0806E680 @ =gUnk_030048B8
	strb r4, [r0]
	movs r0, #0xf
	bl EnableBgSync
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806E648: .4byte gUnk_08677360
.L0806E64C: .4byte gDispIo
.L0806E650: .4byte 0x0000FFE0
.L0806E654: .4byte 0x0000E0FF
.L0806E658: .4byte gBg0Tm
.L0806E65C: .4byte gBg1Tm
.L0806E660: .4byte gUnk_0836F6D4
.L0806E664: .4byte gUnk_08373F80
.L0806E668: .4byte gBg2Tm
.L0806E66C: .4byte gUnk_08374670
.L0806E670: .4byte gBuf
.L0806E674: .4byte gPal
.L0806E678: .4byte gUnk_08353308
.L0806E67C: .4byte func_fe6_08069FD8
.L0806E680: .4byte gUnk_030048B8

	thumb_func_start func_fe6_0806E684
func_fe6_0806E684: @ 0x0806E684
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	movs r0, #2
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0806E694
	movs r5, #0
.L0806E694:
	movs r4, #1
	rsbs r4, r4, #0
	ldr r0, .L0806E6C4 @ =gBg0Tm
	mov ip, r0
	adds r6, r4, #0
.L0806E69E:
	adds r0, r7, r4
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #6
	mov r1, ip
	adds r3, r0, r1
	cmp r4, r6
	beq .L0806E6B2
	cmp r4, #2
	bne .L0806E6C8
.L0806E6B2:
	adds r4, #1
	movs r0, #0
	movs r2, #0x1f
.L0806E6B8:
	strh r0, [r3]
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bge .L0806E6B8
	b .L0806E700
	.align 2, 0
.L0806E6C4: .4byte gBg0Tm
.L0806E6C8:
	cmp r5, r6
	beq .L0806E6D4
	movs r0, #3
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0806E6E6
.L0806E6D4:
	adds r4, #1
	movs r0, #0
	movs r2, #0x1f
.L0806E6DA:
	strh r0, [r3]
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bge .L0806E6DA
	b .L0806E700
.L0806E6E6:
	lsls r0, r5, #6
	lsls r1, r4, #5
	adds r0, r0, r1
	ldr r2, .L0806E710 @ =0x0000F001
	adds r1, r0, r2
	movs r2, #0
	adds r4, #1
.L0806E6F4:
	adds r0, r1, r2
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x1f
	ble .L0806E6F4
.L0806E700:
	cmp r4, #2
	ble .L0806E69E
	movs r0, #1
	bl EnableBgSync
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806E710: .4byte 0x0000F001

	thumb_func_start func_fe6_0806E714
func_fe6_0806E714: @ 0x0806E714
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0806E72C @ =gUnk_030048B8
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0806E726
	adds r0, r1, #0
	bl Proc_Break
.L0806E726:
	pop {r0}
	bx r0
	.align 2, 0
.L0806E72C: .4byte gUnk_030048B8

	thumb_func_start func_fe6_0806E730
func_fe6_0806E730: @ 0x0806E730
	push {lr}
	movs r0, #0
	bl SetOnHBlankA
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806E73C
func_fe6_0806E73C: @ 0x0806E73C
	push {r4, lr}
	sub sp, #8
	movs r0, #0
	bl InitBgs
	ldr r2, .L0806E790 @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	movs r4, #0
	str r4, [sp]
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	ldr r2, .L0806E794 @ =0x01000008
	mov r0, sp
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r1, .L0806E798 @ =0x06006000
	ldr r2, .L0806E79C @ =0x01000800
	bl CpuFastSet
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806E790: .4byte gDispIo
.L0806E794: .4byte 0x01000008
.L0806E798: .4byte 0x06006000
.L0806E79C: .4byte 0x01000800

	thumb_func_start func_fe6_0806E7A0
func_fe6_0806E7A0: @ 0x0806E7A0
	push {lr}
	adds r1, r0, #0
	ldr r2, .L0806E7B4 @ =gUnk_030048A4
	movs r0, #0
	strb r0, [r2]
	ldr r0, .L0806E7B8 @ =ProcScr_Unk_08677378
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0806E7B4: .4byte gUnk_030048A4
.L0806E7B8: .4byte ProcScr_Unk_08677378

	thumb_func_start func_fe6_0806E7BC
func_fe6_0806E7BC: @ 0x0806E7BC
	push {lr}
	adds r1, r0, #0
	ldr r2, .L0806E7D0 @ =gUnk_030048A4
	movs r0, #1
	strb r0, [r2]
	ldr r0, .L0806E7D4 @ =ProcScr_Unk_08677378
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0806E7D0: .4byte gUnk_030048A4
.L0806E7D4: .4byte ProcScr_Unk_08677378

	thumb_func_start func_fe6_0806E7D8
func_fe6_0806E7D8: @ 0x0806E7D8
	push {lr}
	adds r1, r0, #0
	ldr r2, .L0806E7EC @ =gUnk_030048A4
	movs r0, #2
	strb r0, [r2]
	ldr r0, .L0806E7F0 @ =ProcScr_Unk_08677378
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0806E7EC: .4byte gUnk_030048A4
.L0806E7F0: .4byte ProcScr_Unk_08677378

	thumb_func_start func_fe6_0806E7F4
func_fe6_0806E7F4: @ 0x0806E7F4
	push {lr}
	adds r1, r0, #0
	ldr r2, .L0806E808 @ =gUnk_030048A4
	movs r0, #3
	strb r0, [r2]
	ldr r0, .L0806E80C @ =ProcScr_Unk_08677378
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0806E808: .4byte gUnk_030048A4
.L0806E80C: .4byte ProcScr_Unk_08677378

	thumb_func_start func_fe6_0806E810
func_fe6_0806E810: @ 0x0806E810
	push {lr}
	ldr r0, .L0806E82C @ =ProcScr_Unk_08677378
	bl FindProc
	cmp r0, #0
	bne .L0806E834
	ldr r0, .L0806E830 @ =ProcScr_Unk_08677348
	bl Proc_EndEach
	bl func_fe6_0806DCA4
	movs r0, #0
	b .L0806E836
	.align 2, 0
.L0806E82C: .4byte ProcScr_Unk_08677378
.L0806E830: .4byte ProcScr_Unk_08677348
.L0806E834:
	movs r0, #1
.L0806E836:
	pop {r1}
	bx r1
	.align 2, 0
