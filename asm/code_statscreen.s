	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_0806FD68
func_fe6_0806FD68: @ 0x0806FD68
	push {r4, lr}
	sub sp, #4
	ldr r4, .L0806FDA4 @ =gStatScreenSt
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r0, #6
	ldrsh r2, [r4, r0]
	ldr r3, .L0806FDA8 @ =gUnk_086775D4
	movs r0, #0xb9
	lsls r0, r0, #6
	str r0, [sp]
	movs r0, #0xc
	bl PutSprite
	movs r0, #4
	ldrsh r1, [r4, r0]
	adds r1, #0x40
	movs r0, #6
	ldrsh r2, [r4, r0]
	adds r2, #0x83
	ldr r3, .L0806FDAC @ =Sprite_32x16
	ldr r0, .L0806FDB0 @ =0x00004E90
	str r0, [sp]
	movs r0, #0xb
	bl PutSprite
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FDA4: .4byte gStatScreenSt
.L0806FDA8: .4byte gUnk_086775D4
.L0806FDAC: .4byte Sprite_32x16
.L0806FDB0: .4byte 0x00004E90

	thumb_func_start func_fe6_0806FDB4
func_fe6_0806FDB4: @ 0x0806FDB4
	push {r4, r5, lr}
	sub sp, #0xc
	bl GetGameTime
	movs r2, #0
	movs r1, #0x1f
	ands r1, r0
	cmp r1, #0x13
	bhi .L0806FDC8
	movs r2, #1
.L0806FDC8:
	adds r5, r2, #0
	ldr r1, .L0806FE70 @ =gUnk_083195C8
	add r0, sp, #4
	movs r2, #6
	bl memcpy
	ldr r4, .L0806FE74 @ =gStatScreenSt
	movs r0, #8
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne .L0806FE68
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0806FE30
	ldr r1, [r4, #0xc]
	movs r0, #0x10
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	beq .L0806FE30
	movs r0, #0x78
	movs r1, #0x28
	movs r2, #1
	bl PutSysArrow
	movs r0, #0x78
	movs r1, #0x38
	movs r2, #1
	bl PutSysArrow
	cmp r5, #0
	beq .L0806FE30
	ldr r3, .L0806FE78 @ =Sprite_8x8
	ldr r0, [r4, #0xc]
	ldrb r0, [r0, #0x19]
	lsrs r0, r0, #6
	lsls r0, r0, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #4
	movs r0, #0xf
	ldrh r1, [r1]
	ands r0, r1
	lsls r0, r0, #0xc
	ldr r1, .L0806FE7C @ =0x00000803
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #4
	movs r1, #0xb8
	movs r2, #0x4e
	bl PutSprite
.L0806FE30:
	ldr r0, .L0806FE74 @ =gStatScreenSt
	ldr r1, [r0, #0xc]
	movs r0, #0x20
	ldrh r2, [r1, #0xc]
	ands r0, r2
	cmp r0, #0
	beq .L0806FE68
	cmp r5, #0
	beq .L0806FE68
	ldr r3, .L0806FE78 @ =Sprite_8x8
	ldrb r1, [r1, #0x19]
	lsrs r0, r1, #6
	lsls r0, r0, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #4
	movs r0, #0xf
	ldrh r1, [r1]
	ands r0, r1
	lsls r0, r0, #0xc
	ldr r1, .L0806FE7C @ =0x00000803
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #4
	movs r1, #0x20
	movs r2, #0x56
	bl PutSprite
.L0806FE68:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FE70: .4byte gUnk_083195C8
.L0806FE74: .4byte gStatScreenSt
.L0806FE78: .4byte Sprite_8x8
.L0806FE7C: .4byte 0x00000803

	thumb_func_start func_fe6_0806FE80
func_fe6_0806FE80: @ 0x0806FE80
	push {r4, lr}
	ldr r3, .L0806FEDC @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r3, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r3, #1]
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0xc0
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x44
	movs r2, #0
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	movs r4, #0x46
	movs r0, #0x10
	strb r0, [r4, r3]
	ldr r0, .L0806FEE0 @ =0x0000FFE0
	ldrh r4, [r3, #0x3c]
	ands r0, r4
	strh r0, [r3, #0x3c]
	movs r0, #0x20
	ldrb r3, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, .L0806FEE4 @ =gPal
	strh r2, [r0]
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FEDC: .4byte gDispIo
.L0806FEE0: .4byte 0x0000FFE0
.L0806FEE4: .4byte gPal

	thumb_func_start func_fe6_0806FEE8
func_fe6_0806FEE8: @ 0x0806FEE8
	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r1, .L0806FFA0 @ =gUnk_083195CE
	mov r0, sp
	movs r2, #0x18
	bl memcpy
	mov r0, sp
	bl InitBgs
	movs r0, #0x80
	lsls r0, r0, #3
	bl SetBlankChr
	ldr r0, .L0806FFA4 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	movs r0, #4
	bl EnableBgSync
	bl ApplySystemGraphics
	bl ApplyUnitSpritePalettes
	ldr r1, .L0806FFA8 @ =0x0600B000
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #0
	bl StartMuralBackground
	ldr r0, .L0806FFAC @ =gUnk_083080D0
	ldr r1, .L0806FFB0 @ =0x06014800
	bl Decompress
	movs r0, #4
	bl ApplyIconPalettes
	movs r0, #6
	bl ApplyUiStatBarPal
	movs r0, #1
	movs r1, #0x13
	bl ApplyIconPalette
	ldr r0, .L0806FFB4 @ =gUnk_08307CEC
	ldr r4, .L0806FFB8 @ =gBuf
	adds r1, r4, #0
	bl Decompress
	ldr r0, .L0806FFBC @ =gBg1Tm
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, #0
	bl TmApplyTsa_t
	ldr r0, .L0806FFC0 @ =gUnk_08307ED4
	ldr r1, .L0806FFC4 @ =0x06008C00
	bl Decompress
	ldr r0, .L0806FFC8 @ =gUnk_08308050
	movs r1, #0xe0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0806FFCC @ =gPal+0x20
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #8
	bl CpuFastSet
	movs r0, #1
	movs r1, #0x14
	bl ApplyIconPalette
	ldr r0, .L0806FFD0 @ =gUnk_08308920
	ldr r1, .L0806FFD4 @ =0x06004E00
	bl Decompress
	ldr r1, .L0806FFD8 @ =gStatScreenSt
	movs r0, #0
	str r0, [r1, #0x10]
	adds r0, r5, #0
	bl StatScreenUnitSlide_End
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FFA0: .4byte gUnk_083195CE
.L0806FFA4: .4byte gBg2Tm
.L0806FFA8: .4byte 0x0600B000
.L0806FFAC: .4byte gUnk_083080D0
.L0806FFB0: .4byte 0x06014800
.L0806FFB4: .4byte gUnk_08307CEC
.L0806FFB8: .4byte gBuf
.L0806FFBC: .4byte gBg1Tm
.L0806FFC0: .4byte gUnk_08307ED4
.L0806FFC4: .4byte 0x06008C00
.L0806FFC8: .4byte gUnk_08308050
.L0806FFCC: .4byte gPal+0x20
.L0806FFD0: .4byte gUnk_08308920
.L0806FFD4: .4byte 0x06004E00
.L0806FFD8: .4byte gStatScreenSt

	thumb_func_start func_fe6_0806FFDC
func_fe6_0806FFDC: @ 0x0806FFDC
	push {r4, r5, lr}
	ldr r2, .L08070000 @ =gStatScreenSt
	ldr r1, [r2, #0xc]
	movs r0, #0xc0
	ldrb r1, [r1, #0xb]
	ands r0, r1
	cmp r0, #0
	beq .L0806FFF8
	ldr r1, .L08070004 @ =gBmSt
	movs r0, #0x40
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L08070008
.L0806FFF8:
	movs r0, #3
	strb r0, [r2, #1]
	b .L08070016
	.align 2, 0
.L08070000: .4byte gStatScreenSt
.L08070004: .4byte gBmSt
.L08070008:
	movs r0, #2
	strb r0, [r2, #1]
	ldrb r0, [r2]
	cmp r0, #2
	bne .L08070016
	movs r0, #1
	strb r0, [r2]
.L08070016:
	bl ResetText
	bl InitIcons
	bl func_fe6_0806EAF0
	ldr r5, .L08070088 @ =gBg2Tm+0x42
	ldr r4, .L0807008C @ =gStatScreenSt
	ldr r0, [r4, #0xc]
	bl GetUnitFid
	adds r1, r0, #0
	movs r2, #0x9c
	lsls r2, r2, #3
	adds r0, r5, #0
	movs r3, #0xd
	bl PutFace80x72
	bl EndAllMus
	ldr r0, [r4, #0xc]
	movs r1, #0x50
	movs r2, #0x8a
	bl StartUiMu
	str r0, [r4, #0x10]
	bl func_fe6_0806EB48
	ldrb r0, [r4]
	bl func_fe6_0806F3DC
	ldr r0, .L08070090 @ =gUnk_Tm_02003238
	ldr r1, .L08070094 @ =gBg0Tm+0x98
	movs r2, #0x12
	movs r3, #0x12
	bl TmCopyRect_t
	ldr r0, .L08070098 @ =gUnk_Tm_02003738
	ldr r1, .L0807009C @ =gBg1Tm+0x98
	movs r2, #0x12
	movs r3, #0x12
	bl TmCopyRect_t
	ldr r0, .L080700A0 @ =gUnk_Tm_02003C38
	adds r5, #0x56
	adds r1, r5, #0
	movs r2, #0x12
	movs r3, #0x12
	bl TmCopyRect_t
	movs r0, #7
	bl EnableBgSync
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08070088: .4byte gBg2Tm+0x42
.L0807008C: .4byte gStatScreenSt
.L08070090: .4byte gUnk_Tm_02003238
.L08070094: .4byte gBg0Tm+0x98
.L08070098: .4byte gUnk_Tm_02003738
.L0807009C: .4byte gBg1Tm+0x98
.L080700A0: .4byte gUnk_Tm_02003C38

	thumb_func_start func_fe6_080700A4
func_fe6_080700A4: @ 0x080700A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, .L08070128 @ =gKeySt
	ldr r2, [r1]
	movs r0, #2
	ldrh r3, [r2, #8]
	ands r0, r3
	adds r3, r1, #0
	cmp r0, #0
	beq .L0807013C
	ldr r3, .L0807012C @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r4, [r3, #1]
	ands r0, r4
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r3, #1]
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0xc0
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x44
	movs r2, #0
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r4, r3, #0
	adds r4, #0x46
	movs r0, #0x10
	strb r0, [r4]
	ldr r0, .L08070130 @ =0x0000FFE0
	ldrh r4, [r3, #0x3c]
	ands r0, r4
	strh r0, [r3, #0x3c]
	movs r0, #0x20
	ldrb r3, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, .L08070134 @ =gPal
	strh r2, [r0]
	bl EnablePalSync
	adds r0, r5, #0
	bl Proc_Break
	ldr r0, .L08070138 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L08070120
	b .L08070220
.L08070120:
	movs r0, #0x6b
	bl m4aSongNumStart
	b .L08070220
	.align 2, 0
.L08070128: .4byte gKeySt
.L0807012C: .4byte gDispIo
.L08070130: .4byte 0x0000FFE0
.L08070134: .4byte gPal
.L08070138: .4byte gPlaySt
.L0807013C:
	ldrh r1, [r2, #6]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L08070160
	ldr r4, .L0807015C @ =gStatScreenSt
	ldrb r1, [r4, #1]
	ldrb r2, [r4]
	adds r0, r2, r1
	subs r0, #1
	bl __modsi3
	strb r0, [r4]
	ldrb r1, [r4]
	movs r0, #0x20
	b .L0807017E
	.align 2, 0
.L0807015C: .4byte gStatScreenSt
.L08070160:
	movs r6, #0x10
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L0807018C
	ldr r4, .L08070188 @ =gStatScreenSt
	ldrb r1, [r4, #1]
	ldrb r3, [r4]
	adds r0, r3, r1
	adds r0, #1
	bl __modsi3
	strb r0, [r4]
	ldrb r1, [r4]
	movs r0, #0x10
.L0807017E:
	adds r2, r5, #0
	bl StartStatScreenPageSlide
	b .L08070220
	.align 2, 0
.L08070188: .4byte gStatScreenSt
.L0807018C:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080701AC
	ldr r0, .L080701A8 @ =gStatScreenSt
	ldr r0, [r0, #0xc]
	movs r4, #1
	rsbs r4, r4, #0
	adds r1, r4, #0
	bl func_fe6_0806F430
	adds r2, r0, #0
	adds r1, r4, #0
	b .L080701F4
	.align 2, 0
.L080701A8: .4byte gStatScreenSt
.L080701AC:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080701C8
	ldr r0, .L080701C4 @ =gStatScreenSt
	ldr r0, [r0, #0xc]
	movs r1, #1
	bl func_fe6_0806F430
	adds r2, r0, #0
	movs r1, #1
	b .L080701F4
	.align 2, 0
.L080701C4: .4byte gStatScreenSt
.L080701C8:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08070200
	ldr r4, .L080701FC @ =gStatScreenSt
	ldr r2, [r4, #0xc]
	ldrb r0, [r2, #0x19]
	cmp r0, #0
	beq .L08070200
	bl GetUnit
	adds r2, r0, #0
	ldr r1, [r4, #0xc]
	adds r0, r6, #0
	ldrh r1, [r1, #0xc]
	ands r0, r1
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq .L080701F2
	movs r1, #1
.L080701F2:
	adds r0, r2, #0
.L080701F4:
	adds r2, r5, #0
	bl StartStatScreenUnitSlide
	b .L08070220
	.align 2, 0
.L080701FC: .4byte gStatScreenSt
.L08070200:
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08070220
	adds r0, r5, #0
	movs r1, #0
	bl Proc_Goto
	ldr r0, .L08070228 @ =gStatScreenSt
	ldrb r0, [r0]
	adds r1, r5, #0
	bl func_fe6_0807030C
.L08070220:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08070228: .4byte gStatScreenSt

	thumb_func_start func_fe6_0807022C
func_fe6_0807022C: @ 0x0807022C
	push {r4, lr}
	ldr r3, .L08070258 @ =gPlaySt
	movs r1, #0xfc
	ldrb r0, [r3, #0x14]
	ands r1, r0
	ldr r2, .L0807025C @ =gStatScreenSt
	movs r0, #3
	ldrb r4, [r2]
	ands r0, r4
	orrs r1, r0
	strb r1, [r3, #0x14]
	ldr r1, .L08070260 @ =gStatScreenInfo
	ldr r0, [r2, #0xc]
	ldrb r0, [r0, #0xb]
	strb r0, [r1, #1]
	movs r0, #0
	bl SetOnVMatch
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08070258: .4byte gPlaySt
.L0807025C: .4byte gStatScreenSt
.L08070260: .4byte gStatScreenInfo

	thumb_func_start func_fe6_08070264
func_fe6_08070264: @ 0x08070264
	push {lr}
	bl func_fe6_08070CA8
	ldr r1, .L08070274 @ =gStatScreenSt
	str r0, [r1, #0x14]
	pop {r0}
	bx r0
	.align 2, 0
.L08070274: .4byte gStatScreenSt

	thumb_func_start func_fe6_08070278
func_fe6_08070278: @ 0x08070278
	push {r4, lr}
	ldr r0, .L080702AC @ =gStatScreenSt
	movs r1, #6
	ldrsh r4, [r0, r1]
	rsbs r4, r4, #0
	movs r0, #0xff
	ands r4, r0
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl SetBgOffset
	movs r0, #2
	movs r1, #0
	adds r2, r4, #0
	bl SetBgOffset
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080702AC: .4byte gStatScreenSt

	thumb_func_start func_fe6_080702B0
func_fe6_080702B0: @ 0x080702B0
	push {lr}
	bl EndMuralBackground
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start StartStatScreen
StartStatScreen: @ 0x080702BC
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	ldr r2, .L08070300 @ =gStatScreenSt
	movs r5, #0
	movs r3, #0
	strh r3, [r2, #4]
	strh r3, [r2, #6]
	ldr r4, .L08070304 @ =gPlaySt
	movs r1, #3
	ldrb r7, [r4, #0x14]
	ands r1, r7
	strb r1, [r2]
	str r0, [r2, #0xc]
	str r3, [r2, #0x14]
	strh r3, [r2, #2]
	strb r5, [r2, #8]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	bl func_fe6_08084BB8
	ldrb r4, [r4, #0x1d]
	lsls r0, r4, #0x1e
	cmp r0, #0
	blt .L080702F2
	movs r0, #0x6a
	bl m4aSongNumStart
.L080702F2:
	ldr r0, .L08070308 @ =gUnk_08677680
	adds r1, r6, #0
	bl SpawnProcLocking
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08070300: .4byte gStatScreenSt
.L08070304: .4byte gPlaySt
.L08070308: .4byte gUnk_08677680

	thumb_func_start func_fe6_0807030C
func_fe6_0807030C: @ 0x0807030C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl func_fe6_08070E70
	ldr r1, .L08070334 @ =gStatScreenSt
	ldr r0, [r1, #0x14]
	cmp r0, #0
	bne .L08070354
	cmp r4, #1
	beq .L08070348
	cmp r4, #1
	bgt .L08070338
	cmp r4, #0
	beq .L0807033E
	b .L08070354
	.align 2, 0
.L08070334: .4byte gStatScreenSt
.L08070338:
	cmp r4, #2
	beq .L08070350
	b .L08070354
.L0807033E:
	ldr r0, .L08070344 @ =gUnk_08677824
	b .L08070352
	.align 2, 0
.L08070344: .4byte gUnk_08677824
.L08070348:
	ldr r0, .L0807034C @ =gUnk_08677A00
	b .L08070352
	.align 2, 0
.L0807034C: .4byte gUnk_08677A00
.L08070350:
	ldr r0, .L08070364 @ =gUnk_08677BA4
.L08070352:
	str r0, [r1, #0x14]
.L08070354:
	ldr r0, .L08070368 @ =gStatScreenSt
	ldr r0, [r0, #0x14]
	adds r1, r5, #0
	bl StartMovingHelpBox
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08070364: .4byte gUnk_08677BA4
.L08070368: .4byte gStatScreenSt

	thumb_func_start func_fe6_0807036C
func_fe6_0807036C: @ 0x0807036C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08070394 @ =gStatScreenSt
	ldr r0, [r0, #0xc]
	ldr r1, [r4, #0x2c]
	ldrh r1, [r1, #0x12]
	lsls r1, r1, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x4e
	strh r0, [r1]
	bl GetItemDescMsg
	adds r4, #0x4c
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08070394: .4byte gStatScreenSt

	thumb_func_start func_fe6_08070398
func_fe6_08070398: @ 0x08070398
	adds r2, r0, #0
	ldr r0, .L080703B4 @ =gStatScreenSt
	ldr r0, [r0, #0xc]
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	cmp r0, #4
	bhi .L08070408
	lsls r0, r0, #2
	ldr r1, .L080703B8 @ =.L080703BC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080703B4: .4byte gStatScreenSt
.L080703B8: .4byte .L080703BC
.L080703BC: @ jump table
	.4byte .L080703D0 @ case 0
	.4byte .L080703DA @ case 1
	.4byte .L080703E8 @ case 2
	.4byte .L080703F4 @ case 3
	.4byte .L08070400 @ case 4
.L080703D0:
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0xb5
	lsls r0, r0, #3
	b .L08070406
.L080703DA:
	adds r1, r2, #0
	adds r1, #0x4c
	ldr r0, .L080703E4 @ =0x000005A9
	b .L08070406
	.align 2, 0
.L080703E4: .4byte 0x000005A9
.L080703E8:
	adds r1, r2, #0
	adds r1, #0x4c
	ldr r0, .L080703F0 @ =0x000005AA
	b .L08070406
	.align 2, 0
.L080703F0: .4byte 0x000005AA
.L080703F4:
	adds r1, r2, #0
	adds r1, #0x4c
	ldr r0, .L080703FC @ =0x000005AC
	b .L08070406
	.align 2, 0
.L080703FC: .4byte 0x000005AC
.L08070400:
	adds r1, r2, #0
	adds r1, #0x4c
	ldr r0, .L0807040C @ =0x000005AB
.L08070406:
	strh r0, [r1]
.L08070408:
	bx lr
	.align 2, 0
.L0807040C: .4byte 0x000005AB

	thumb_func_start func_fe6_08070410
func_fe6_08070410: @ 0x08070410
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0807042C @ =gStatScreenSt
	ldr r0, [r0, #0xc]
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08070434
	adds r1, r4, #0
	adds r1, #0x4c
	ldr r0, .L08070430 @ =0x0000059D
	b .L0807043A
	.align 2, 0
.L0807042C: .4byte gStatScreenSt
.L08070430: .4byte 0x0000059D
.L08070434:
	adds r1, r4, #0
	adds r1, #0x4c
	ldr r0, .L08070444 @ =0x0000059C
.L0807043A:
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08070444: .4byte 0x0000059C

	thumb_func_start func_fe6_08070448
func_fe6_08070448: @ 0x08070448
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, .L08070488 @ =gStatScreenSt
	ldr r0, [r5, #0xc]
	ldrh r0, [r0, #0x1c]
	cmp r0, #0
	bne .L0807045C
	adds r0, r4, #0
	bl func_fe6_08070BEC
.L0807045C:
	ldr r0, [r5, #0xc]
	ldr r1, [r4, #0x2c]
	ldrh r1, [r1, #0x12]
	lsls r1, r1, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08070496
	adds r0, r4, #0
	adds r0, #0x50
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08070480
	cmp r0, #0x10
	beq .L08070480
	cmp r0, #0x40
	bne .L0807048C
.L08070480:
	adds r0, r4, #0
	bl func_fe6_08070B8C
	b .L08070496
	.align 2, 0
.L08070488: .4byte gStatScreenSt
.L0807048C:
	cmp r0, #0x80
	bne .L08070496
	adds r0, r4, #0
	bl func_fe6_08070BBC
.L08070496:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807049C
func_fe6_0807049C: @ 0x0807049C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, .L080704D4 @ =gUnk_083195E6
	mov r0, sp
	movs r2, #0x10
	bl memcpy
	ldr r0, [r5, #0x2c]
	ldrh r4, [r0, #0x12]
	ldr r0, .L080704D8 @ =gStatScreenSt
	ldr r0, [r0, #0xc]
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080704C0
	adds r4, #4
.L080704C0:
	lsls r0, r4, #1
	add r0, sp
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x4c
	strh r1, [r0]
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080704D4: .4byte gUnk_083195E6
.L080704D8: .4byte gStatScreenSt

	thumb_func_start func_fe6_080704DC
func_fe6_080704DC: @ 0x080704DC
	adds r1, r0, #0
	ldr r0, .L080704F4 @ =gStatScreenSt
	ldr r0, [r0, #0xc]
	ldr r0, [r0]
	ldrh r2, [r0, #2]
	cmp r2, #0
	beq .L080704F8
	adds r0, r1, #0
	adds r0, #0x4c
	strh r2, [r0]
	b .L080704FE
	.align 2, 0
.L080704F4: .4byte gStatScreenSt
.L080704F8:
	adds r1, #0x4c
	ldr r0, .L08070500 @ =0x0000066D
	strh r0, [r1]
.L080704FE:
	bx lr
	.align 2, 0
.L08070500: .4byte 0x0000066D

	thumb_func_start func_fe6_08070504
func_fe6_08070504: @ 0x08070504
	ldr r1, .L08070514 @ =gStatScreenSt
	ldr r1, [r1, #0xc]
	ldr r1, [r1, #4]
	ldrh r1, [r1, #2]
	adds r0, #0x4c
	strh r1, [r0]
	bx lr
	.align 2, 0
.L08070514: .4byte gStatScreenSt

	thumb_func_start func_fe6_08070518
func_fe6_08070518: @ 0x08070518
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0807053C @ =gStatScreenSt
	ldr r0, [r0, #0xc]
	bl GetUnitTotalSupportLevel
	cmp r0, #0
	bne .L08070546
	adds r0, r4, #0
	adds r0, #0x50
	ldrh r0, [r0]
	cmp r0, #0x80
	bne .L08070540
	adds r0, r4, #0
	bl func_fe6_08070BBC
	b .L08070546
	.align 2, 0
.L0807053C: .4byte gStatScreenSt
.L08070540:
	adds r0, r4, #0
	bl func_fe6_08070B8C
.L08070546:
	pop {r4}
	pop {r0}
	bx r0
