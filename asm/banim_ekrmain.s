	.include "macro.inc"
	.syntax unified

	.section .data

	.global AnimScr_DefaultAnim
AnimScr_DefaultAnim: @ 085CBDA0
	.incbin "fe6-base.gba", 0x5CBDA0, (0x5CBDB0 - 0x5CBDA0) @ length: 0010

	.global gUnk_085CBDB0
gUnk_085CBDB0: @ 085CBDB0
	.incbin "fe6-base.gba", 0x5CBDB0, (0x5CBDD8 - 0x5CBDB0) @ length: 0028

	.global ProcScr_EkrChienCHR
ProcScr_EkrChienCHR: @ 085CBDD8
	.incbin "fe6-base.gba", 0x5CBDD8, (0x5CBDF0 - 0x5CBDD8) @ length: 0018

	.section .text
	thumb_func_start NewEkrChienCHR
NewEkrChienCHR: @ 0x0804AF70
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0804AF84 @ =ProcScr_EkrChienCHR
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804AF84: .4byte ProcScr_EkrChienCHR

	thumb_func_start EkrChienCHRMain
EkrChienCHRMain: @ 0x0804AF88
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl RegisterAISSheetGraphics
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start RegisterAISSheetGraphics
RegisterAISSheetGraphics: @ 0x0804AFA0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0804AFCC @ =0x000003FF
	ldrh r0, [r5, #8]
	ands r4, r0
	lsls r4, r4, #5
	ldr r0, .L0804AFD0 @ =0x06010000
	adds r4, r4, r0
	ldr r0, [r5, #0x28]
	ldr r1, [r5, #0x2c]
	bl LZ77UnCompWram
	ldr r0, [r5, #0x2c]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r4, #0
	bl RegisterDataMove
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804AFCC: .4byte 0x000003FF
.L0804AFD0: .4byte 0x06010000

	thumb_func_start func_fe6_0804AFD4
func_fe6_0804AFD4: @ 0x0804AFD4
	adds r2, r0, #0
	ldr r0, .L0804AFF8 @ =0x0203CDD0
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq .L0804AFF4
	movs r1, #0
	adds r3, r2, #0
	adds r3, #0x80
.L0804AFEA:
	ldm r3!, {r0}
	stm r2!, {r0}
	adds r1, #1
	cmp r1, #7
	bls .L0804AFEA
.L0804AFF4:
	bx lr
	.align 2, 0
.L0804AFF8: .4byte 0x0203CDD0

	thumb_func_start GetBanimPalette
GetBanimPalette: @ 0x0804AFFC
	adds r2, r0, #0
	cmp r1, #0
	bne .L0804B00C
	ldr r0, .L0804B008 @ =gpEkrBattleUnitLeft
	b .L0804B00E
	.align 2, 0
.L0804B008: .4byte gpEkrBattleUnitLeft
.L0804B00C:
	ldr r0, .L0804B024 @ =gpEkrBattleUnitRight
.L0804B00E:
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x11
	beq .L0804B036
	cmp r0, #0x11
	bhi .L0804B028
	cmp r0, #0x10
	beq .L0804B032
	b .L0804B042
	.align 2, 0
.L0804B024: .4byte gpEkrBattleUnitRight
.L0804B028:
	cmp r0, #0x12
	beq .L0804B03A
	cmp r0, #0x13
	beq .L0804B03E
	b .L0804B042
.L0804B032:
	movs r0, #0xe
	b .L0804B044
.L0804B036:
	movs r0, #0xf
	b .L0804B044
.L0804B03A:
	movs r0, #4
	b .L0804B044
.L0804B03E:
	movs r0, #5
	b .L0804B044
.L0804B042:
	adds r0, r2, #0
.L0804B044:
	bx lr
	.align 2, 0

	thumb_func_start UpdateBanimFrame
UpdateBanimFrame: @ 0x0804B048
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, .L0804B0F8 @ =banim_data
	mov sl, r0
	ldr r1, .L0804B0FC @ =gpImgSheet
	movs r0, #0
	str r0, [r1, #4]
	str r0, [r1]
	ldr r0, .L0804B100 @ =gBanimValid
	ldrh r1, [r0]
	cmp r1, #1
	bne .L0804B140
	ldr r0, .L0804B104 @ =gBanimIdx
	movs r2, #0
	ldrsh r7, [r0, r2]
	ldr r0, .L0804B108 @ =gBanimFactionPal
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r8, r1
	ldr r0, .L0804B10C @ =gBanimUniquePal
	movs r1, #0
	ldrsh r4, [r0, r1]
	lsls r0, r7, #5
	ldr r2, .L0804B0F8 @ =banim_data
	adds r6, r0, r2
	ldr r0, [r6, #0x10]
	ldr r1, .L0804B110 @ =gUnk_Banim_0200F1C0
	bl LZ77UnCompWram
	ldr r1, .L0804B114 @ =gUnk_Banim_02000054
	ldr r0, [r6, #0xc]
	str r0, [r1]
	adds r0, r7, #0
	movs r1, #0
	bl GetBanimPalette
	lsls r0, r0, #5
	ldr r1, .L0804B0F8 @ =banim_data
	adds r0, r0, r1
	ldr r0, [r0, #0x1c]
	ldr r5, .L0804B118 @ =gUnk_Banim_02004080
	adds r1, r5, #0
	bl LZ77UnCompWram
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0804B0C4
	lsls r0, r4, #4
	ldr r2, .L0804B11C @ =0x087FC008
	adds r0, r0, r2
	ldr r0, [r0, #0xc]
	adds r1, r5, #0
	bl LZ77UnCompWram
	adds r0, r5, #0
	movs r1, #0
	bl func_fe6_0804AFD4
.L0804B0C4:
	ldr r1, .L0804B120 @ =gpEfxUnitPaletteBackup
	mov r2, r8
	lsls r0, r2, #5
	adds r0, r0, r5
	str r0, [r1]
	ldr r4, .L0804B124 @ =gPal+0x2E0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0804B128 @ =0x0203CD90
	ldr r0, [r0]
	adds r4, #0x20
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	cmp r7, #0x74
	beq .L0804B130
	ldr r0, [r6, #0x18]
	ldr r1, .L0804B12C @ =gUnk_Banim_020041C0
	bl LZ77UnCompWram
	b .L0804B138
	.align 2, 0
.L0804B0F8: .4byte banim_data
.L0804B0FC: .4byte gpImgSheet
.L0804B100: .4byte gBanimValid
.L0804B104: .4byte gBanimIdx
.L0804B108: .4byte gBanimFactionPal
.L0804B10C: .4byte gBanimUniquePal
.L0804B110: .4byte gUnk_Banim_0200F1C0
.L0804B114: .4byte gUnk_Banim_02000054
.L0804B118: .4byte gUnk_Banim_02004080
.L0804B11C: .4byte 0x087FC008
.L0804B120: .4byte gpEfxUnitPaletteBackup
.L0804B124: .4byte gPal+0x2E0
.L0804B128: .4byte 0x0203CD90
.L0804B12C: .4byte gUnk_Banim_020041C0
.L0804B130:
	ldr r0, [r6, #0x14]
	ldr r1, .L0804B254 @ =gUnk_Banim_020041C0
	bl LZ77UnCompWram
.L0804B138:
	ldr r4, .L0804B258 @ =gUnk_Banim_020099B0
	movs r0, #1
	str r0, [r4]
	ldr r0, .L0804B25C @ =gBanimValid
.L0804B140:
	movs r2, #2
	ldrsh r1, [r0, r2]
	mov sb, r1
	cmp r1, #1
	bne .L0804B1DE
	ldr r0, .L0804B260 @ =gBanimIdx
	movs r1, #2
	ldrsh r7, [r0, r1]
	ldr r0, .L0804B264 @ =gBanimFactionPal
	movs r1, #2
	ldrsh r2, [r0, r1]
	mov r8, r2
	ldr r0, .L0804B268 @ =gBanimUniquePal
	movs r2, #2
	ldrsh r4, [r0, r2]
	lsls r0, r7, #5
	mov r1, sl
	adds r6, r0, r1
	ldr r0, [r6, #0x10]
	ldr r1, .L0804B26C @ =gUnk_Banim_02011BC0
	bl LZ77UnCompWram
	ldr r1, .L0804B270 @ =gUnk_Banim_02000058
	ldr r0, [r6, #0xc]
	str r0, [r1]
	adds r0, r7, #0
	movs r1, #1
	bl GetBanimPalette
	lsls r0, r0, #5
	add r0, sl
	ldr r0, [r0, #0x1c]
	ldr r5, .L0804B274 @ =gUnk_Banim_02004120
	adds r1, r5, #0
	bl LZ77UnCompWram
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0804B1A6
	lsls r0, r4, #4
	ldr r2, .L0804B278 @ =0x087FC008
	adds r0, r0, r2
	ldr r0, [r0, #0xc]
	adds r1, r5, #0
	bl LZ77UnCompWram
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_0804AFD4
.L0804B1A6:
	ldr r1, .L0804B27C @ =gpEfxUnitPaletteBackup
	mov r2, r8
	lsls r0, r2, #5
	adds r0, r0, r5
	str r0, [r1, #4]
	ldr r4, .L0804B280 @ =gPal+0x320
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0804B284 @ =0x0203CD90
	ldr r0, [r0, #4]
	adds r4, #0x20
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	ldr r0, [r6, #0x14]
	ldr r4, .L0804B288 @ =gUnk_Banim_020099C0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L0804B28C @ =0x000057F0
	adds r4, r4, r0
	mov r1, sb
	str r1, [r4]
.L0804B1DE:
	ldr r6, .L0804B290 @ =gpEkrTriangleUnits
	ldr r0, [r6]
	cmp r0, #0
	beq .L0804B246
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x30]
	movs r1, #0
	bl GetBattleAnimationId_WithUnique
	lsls r0, r0, #0x10
	ldr r5, .L0804B284 @ =0x0203CD90
	lsrs r0, r0, #0xb
	add r0, sl
	ldr r0, [r0, #0x1c]
	str r0, [r5]
	ldr r0, [r6]
	bl func_fe6_0804A49C
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	movs r7, #1
	rsbs r7, r7, #0
	cmp r4, r7
	beq .L0804B218
	lsls r0, r4, #4
	ldr r2, .L0804B278 @ =0x087FC008
	adds r0, r0, r2
	ldr r0, [r0, #0xc]
	str r0, [r5]
.L0804B218:
	ldr r0, [r6, #4]
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x30]
	movs r1, #0
	bl GetBattleAnimationId_WithUnique
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xb
	add r0, sl
	ldr r0, [r0, #0x1c]
	str r0, [r5, #4]
	ldr r0, [r6, #4]
	bl func_fe6_0804A49C
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, r7
	beq .L0804B246
	lsls r0, r4, #4
	ldr r1, .L0804B278 @ =0x087FC008
	adds r0, r0, r1
	ldr r0, [r0, #0xc]
	str r0, [r5, #4]
.L0804B246:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B254: .4byte gUnk_Banim_020041C0
.L0804B258: .4byte gUnk_Banim_020099B0
.L0804B25C: .4byte gBanimValid
.L0804B260: .4byte gBanimIdx
.L0804B264: .4byte gBanimFactionPal
.L0804B268: .4byte gBanimUniquePal
.L0804B26C: .4byte gUnk_Banim_02011BC0
.L0804B270: .4byte gUnk_Banim_02000058
.L0804B274: .4byte gUnk_Banim_02004120
.L0804B278: .4byte 0x087FC008
.L0804B27C: .4byte gpEfxUnitPaletteBackup
.L0804B280: .4byte gPal+0x320
.L0804B284: .4byte 0x0203CD90
.L0804B288: .4byte gUnk_Banim_020099C0
.L0804B28C: .4byte 0x000057F0
.L0804B290: .4byte gpEkrTriangleUnits

	thumb_func_start InitMainAnims
InitMainAnims: @ 0x0804B294
	push {lr}
	ldr r0, .L0804B2AC @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bhi .L0804B30E
	lsls r0, r0, #2
	ldr r1, .L0804B2B0 @ =.L0804B2B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B2AC: .4byte gEkrDistanceType
.L0804B2B0: .4byte .L0804B2B4
.L0804B2B4: @ jump table
	.4byte .L0804B2C8 @ case 0
	.4byte .L0804B2D2 @ case 1
	.4byte .L0804B2DC @ case 2
	.4byte .L0804B2C8 @ case 3
	.4byte .L0804B2C8 @ case 4
.L0804B2C8:
	movs r0, #6
	movs r1, #6
	bl InitBattleAnimFrame
	b .L0804B30E
.L0804B2D2:
	movs r0, #8
	movs r1, #8
	bl InitBattleAnimFrame
	b .L0804B30E
.L0804B2DC:
	movs r0, #8
	movs r1, #8
	bl InitBattleAnimFrame
	bl GetBanimInitPosReal
	cmp r0, #0
	bne .L0804B300
	ldr r1, .L0804B2FC @ =gAnims
	ldr r2, [r1, #8]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r2, #2]
	ldr r1, [r1, #0xc]
	b .L0804B30C
	.align 2, 0
.L0804B2FC: .4byte gAnims
.L0804B300:
	ldr r1, .L0804B31C @ =gAnims
	ldr r2, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r2, #2]
	ldr r1, [r1, #4]
.L0804B30C:
	strh r0, [r1, #2]
.L0804B30E:
	ldr r1, .L0804B320 @ =gEfxHpLutOff
	movs r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	pop {r0}
	bx r0
	.align 2, 0
.L0804B31C: .4byte gAnims
.L0804B320: .4byte gEfxHpLutOff

	thumb_func_start InitBattleAnimFrame
InitBattleAnimFrame: @ 0x0804B324
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r6, r1, #0
	ldr r4, .L0804B370 @ =gAnims
	movs r0, #0
	str r0, [r4]
	str r0, [r4, #4]
	str r0, [r4, #8]
	str r0, [r4, #0xc]
	ldr r5, .L0804B374 @ =gBanimValid
	ldrh r0, [r5]
	cmp r0, #1
	bne .L0804B344
	adds r0, r2, #0
	bl InitLeftAnim
.L0804B344:
	ldrh r5, [r5, #2]
	cmp r5, #1
	bne .L0804B350
	adds r0, r6, #0
	bl InitRightAnim
.L0804B350:
	ldr r0, .L0804B378 @ =gEkrDistanceType
	ldrh r0, [r0]
	cmp r0, #4
	bne .L0804B36A
	ldr r1, [r4]
	movs r2, #2
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldr r1, [r4, #4]
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
.L0804B36A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B370: .4byte gAnims
.L0804B374: .4byte gBanimValid
.L0804B378: .4byte gEkrDistanceType

	thumb_func_start InitLeftAnim
InitLeftAnim: @ 0x0804B37C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r2, .L0804B484 @ =gUnk_08112298
	lsls r1, r7, #2
	adds r0, r1, r2
	ldrb r5, [r0]
	adds r0, r1, #1
	adds r0, r0, r2
	ldrb r6, [r0]
	adds r0, r1, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	mov r8, r0
	adds r1, #3
	adds r1, r1, r2
	ldrb r1, [r1]
	mov sb, r1
	ldr r0, .L0804B488 @ =gUnk_081122C5
	ldr r1, .L0804B48C @ =gEkrDistanceType
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r1, r0
	ldrb r4, [r0]
	ldr r3, .L0804B490 @ =gEkrXPosBase
	ldr r0, .L0804B494 @ =gUnk_081122D0
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	rsbs r1, r1, #0
	movs r2, #0
	strh r1, [r3]
	ldr r0, .L0804B498 @ =gEkrYPosBase
	strh r2, [r0]
	ldr r0, .L0804B49C @ =gEkrXPosReal
	adds r1, r1, r4
	strh r1, [r0]
	ldr r1, .L0804B4A0 @ =gEkrYPosReal
	movs r0, #0x58
	strh r0, [r1]
	ldr r0, .L0804B4A4 @ =gUnk_Banim_02000054
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B4A8 @ =gUnk_Banim_0200F1C0
	adds r0, r1, r0
	cmp r5, #0xff
	bne .L0804B3E4
	ldr r0, .L0804B4AC @ =AnimScr_DefaultAnim
.L0804B3E4:
	adds r1, r6, #0
	bl BasCreate
	adds r2, r0, #0
	ldr r1, .L0804B49C @ =gEkrXPosReal
	ldr r0, .L0804B4B0 @ =gEkrBgPosition
	ldrh r1, [r1]
	ldrh r0, [r0]
	subs r0, r1, r0
	movs r1, #0
	strh r0, [r2, #2]
	ldr r0, .L0804B4A0 @ =gEkrYPosReal
	ldrh r0, [r0]
	strh r0, [r2, #4]
	movs r0, #0xf4
	lsls r0, r0, #7
	strh r0, [r2, #8]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r3, #0
	ldrh r3, [r2, #0xc]
	orrs r0, r3
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strb r7, [r2, #0x12]
	ldr r0, .L0804B4B4 @ =gUnk_Banim_02000080
	str r0, [r2, #0x2c]
	ldr r0, .L0804B4B8 @ =gUnk_Banim_020041C0
	str r0, [r2, #0x30]
	ldr r0, .L0804B4BC @ =gAnims
	str r2, [r0]
	ldr r0, .L0804B4A4 @ =gUnk_Banim_02000054
	ldr r1, [r0]
	mov r2, r8
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B4A8 @ =gUnk_Banim_0200F1C0
	adds r0, r1, r0
	cmp r2, #0xff
	bne .L0804B438
	ldr r0, .L0804B4AC @ =AnimScr_DefaultAnim
.L0804B438:
	mov r1, sb
	bl BasCreate
	adds r2, r0, #0
	ldr r1, .L0804B49C @ =gEkrXPosReal
	ldr r0, .L0804B4B0 @ =gEkrBgPosition
	ldrh r1, [r1]
	ldrh r0, [r0]
	subs r0, r1, r0
	movs r1, #0
	strh r0, [r2, #2]
	ldr r0, .L0804B4A0 @ =gEkrYPosReal
	ldrh r0, [r0]
	strh r0, [r2, #4]
	movs r0, #0xf4
	lsls r0, r0, #7
	strh r0, [r2, #8]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r0, r3, #0
	ldrh r3, [r2, #0xc]
	orrs r0, r3
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strb r7, [r2, #0x12]
	ldr r0, .L0804B4B4 @ =gUnk_Banim_02000080
	str r0, [r2, #0x2c]
	ldr r0, .L0804B4B8 @ =gUnk_Banim_020041C0
	str r0, [r2, #0x30]
	ldr r0, .L0804B4BC @ =gAnims
	str r2, [r0, #4]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B484: .4byte gUnk_08112298
.L0804B488: .4byte gUnk_081122C5
.L0804B48C: .4byte gEkrDistanceType
.L0804B490: .4byte gEkrXPosBase
.L0804B494: .4byte gUnk_081122D0
.L0804B498: .4byte gEkrYPosBase
.L0804B49C: .4byte gEkrXPosReal
.L0804B4A0: .4byte gEkrYPosReal
.L0804B4A4: .4byte gUnk_Banim_02000054
.L0804B4A8: .4byte gUnk_Banim_0200F1C0
.L0804B4AC: .4byte AnimScr_DefaultAnim
.L0804B4B0: .4byte gEkrBgPosition
.L0804B4B4: .4byte gUnk_Banim_02000080
.L0804B4B8: .4byte gUnk_Banim_020041C0
.L0804B4BC: .4byte gAnims

	thumb_func_start InitRightAnim
InitRightAnim: @ 0x0804B4C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r2, .L0804B5A8 @ =gUnk_08112298
	lsls r1, r5, #2
	adds r0, r1, r2
	ldrb r3, [r0]
	adds r0, r1, #1
	adds r0, r0, r2
	ldrb r4, [r0]
	adds r0, r1, #2
	adds r0, r0, r2
	ldrb r6, [r0]
	adds r1, #3
	adds r1, r1, r2
	ldrb r7, [r1]
	ldr r1, .L0804B5AC @ =gUnk_081122CA
	ldr r0, .L0804B5B0 @ =gEkrDistanceType
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r0, .L0804B5B4 @ =gEkrXPosBase
	movs r1, #0
	strh r1, [r0, #2]
	ldr r0, .L0804B5B8 @ =gEkrYPosBase
	strh r1, [r0, #2]
	ldr r0, .L0804B5BC @ =gEkrXPosReal
	strh r2, [r0, #2]
	ldr r1, .L0804B5C0 @ =gEkrYPosReal
	movs r0, #0x58
	strh r0, [r1, #2]
	ldr r0, .L0804B5C4 @ =gUnk_Banim_02000058
	ldr r1, [r0]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B5C8 @ =gUnk_Banim_02011BC0
	adds r0, r1, r0
	cmp r3, #0xff
	bne .L0804B512
	ldr r0, .L0804B5CC @ =AnimScr_DefaultAnim
.L0804B512:
	adds r1, r4, #0
	bl BasCreate
	adds r2, r0, #0
	ldr r1, .L0804B5BC @ =gEkrXPosReal
	ldr r0, .L0804B5D0 @ =gEkrBgPosition
	ldrh r1, [r1, #2]
	ldrh r0, [r0]
	subs r0, r1, r0
	movs r1, #0
	strh r0, [r2, #2]
	ldr r0, .L0804B5C0 @ =gEkrYPosReal
	ldrh r0, [r0, #2]
	strh r0, [r2, #4]
	movs r0, #0x9b
	lsls r0, r0, #8
	strh r0, [r2, #8]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r0, r3, #0
	ldrh r3, [r2, #0xc]
	orrs r0, r3
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strb r5, [r2, #0x12]
	ldr r0, .L0804B5D4 @ =gUnk_Banim_02002080
	str r0, [r2, #0x2c]
	ldr r0, .L0804B5D8 @ =gUnk_Banim_020099C0
	str r0, [r2, #0x30]
	ldr r0, .L0804B5DC @ =gAnims
	str r2, [r0, #8]
	ldr r0, .L0804B5C4 @ =gUnk_Banim_02000058
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B5C8 @ =gUnk_Banim_02011BC0
	adds r0, r1, r0
	cmp r6, #0xff
	bne .L0804B564
	ldr r0, .L0804B5CC @ =AnimScr_DefaultAnim
.L0804B564:
	adds r1, r7, #0
	bl BasCreate
	adds r2, r0, #0
	ldr r1, .L0804B5BC @ =gEkrXPosReal
	ldr r0, .L0804B5D0 @ =gEkrBgPosition
	ldrh r1, [r1, #2]
	ldrh r0, [r0]
	subs r0, r1, r0
	movs r1, #0
	strh r0, [r2, #2]
	ldr r0, .L0804B5C0 @ =gEkrYPosReal
	ldrh r0, [r0, #2]
	strh r0, [r2, #4]
	movs r0, #0x9b
	lsls r0, r0, #8
	strh r0, [r2, #8]
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r0, r3, #0
	ldrh r3, [r2, #0xc]
	orrs r0, r3
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strb r5, [r2, #0x12]
	ldr r0, .L0804B5D4 @ =gUnk_Banim_02002080
	str r0, [r2, #0x2c]
	ldr r0, .L0804B5D8 @ =gUnk_Banim_020099C0
	str r0, [r2, #0x30]
	ldr r0, .L0804B5DC @ =gAnims
	str r2, [r0, #0xc]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B5A8: .4byte gUnk_08112298
.L0804B5AC: .4byte gUnk_081122CA
.L0804B5B0: .4byte gEkrDistanceType
.L0804B5B4: .4byte gEkrXPosBase
.L0804B5B8: .4byte gEkrYPosBase
.L0804B5BC: .4byte gEkrXPosReal
.L0804B5C0: .4byte gEkrYPosReal
.L0804B5C4: .4byte gUnk_Banim_02000058
.L0804B5C8: .4byte gUnk_Banim_02011BC0
.L0804B5CC: .4byte AnimScr_DefaultAnim
.L0804B5D0: .4byte gEkrBgPosition
.L0804B5D4: .4byte gUnk_Banim_02002080
.L0804B5D8: .4byte gUnk_Banim_020099C0
.L0804B5DC: .4byte gAnims

	thumb_func_start SwitchAISFrameDataFromBARoundType
SwitchAISFrameDataFromBARoundType: @ 0x0804B5E0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804B600
	ldr r0, .L0804B5FC @ =gUnk_08112298
	lsls r1, r6, #2
	adds r2, r1, r0
	ldrb r5, [r2]
	adds r1, #1
	adds r1, r1, r0
	b .L0804B60E
	.align 2, 0
.L0804B5FC: .4byte gUnk_08112298
.L0804B600:
	ldr r2, .L0804B62C @ =gUnk_08112298
	lsls r1, r6, #2
	adds r0, r1, #2
	adds r0, r0, r2
	ldrb r5, [r0]
	adds r1, #3
	adds r1, r1, r2
.L0804B60E:
	ldrb r7, [r1]
	cmp r5, #0xff
	beq .L0804B654
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804B638
	ldr r0, .L0804B630 @ =gUnk_Banim_02000054
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B634 @ =gUnk_Banim_0200F1C0
	b .L0804B644
	.align 2, 0
.L0804B62C: .4byte gUnk_08112298
.L0804B630: .4byte gUnk_Banim_02000054
.L0804B634: .4byte gUnk_Banim_0200F1C0
.L0804B638:
	ldr r0, .L0804B64C @ =gUnk_Banim_02000058
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B650 @ =gUnk_Banim_02011BC0
.L0804B644:
	adds r1, r1, r0
	str r1, [r4, #0x24]
	str r1, [r4, #0x20]
	b .L0804B65E
	.align 2, 0
.L0804B64C: .4byte gUnk_Banim_02000058
.L0804B650: .4byte gUnk_Banim_02011BC0
.L0804B654:
	ldr r0, .L0804B6A4 @ =AnimScr_DefaultAnim
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #0x10]
.L0804B65E:
	movs r3, #0
	movs r2, #0
	strh r7, [r4, #0xa]
	ldr r0, .L0804B6A8 @ =0x0000F3FF
	ldrh r1, [r4, #8]
	ands r0, r1
	movs r5, #0x80
	lsls r5, r5, #4
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r4, #8]
	strh r2, [r4, #6]
	movs r0, #0xe0
	lsls r0, r0, #3
	ldrh r1, [r4, #0xc]
	ands r0, r1
	strh r0, [r4, #0xc]
	strb r6, [r4, #0x12]
	strb r3, [r4, #0x14]
	adds r0, r4, #0
	bl GetAnimPosition
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	subs r1, r1, r0
	lsls r1, r1, #0xb
	ldr r0, .L0804B6AC @ =gUnk_Banim_020041C0
	adds r1, r1, r0
	str r1, [r4, #0x30]
	bl BasSort
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B6A4: .4byte AnimScr_DefaultAnim
.L0804B6A8: .4byte 0x0000F3FF
.L0804B6AC: .4byte gUnk_Banim_020041C0

	thumb_func_start GetAnimLayer
GetAnimLayer: @ 0x0804B6B0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r0, #0xc]
	ands r1, r0
	cmp r1, #0
	beq .L0804B6C0
	movs r0, #1
	b .L0804B6C2
.L0804B6C0:
	movs r0, #0
.L0804B6C2:
	bx lr

	thumb_func_start GetAnimPosition
GetAnimPosition: @ 0x0804B6C4
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r0, #0xc]
	ands r1, r0
	cmp r1, #0
	beq .L0804B6D4
	movs r0, #1
	b .L0804B6D6
.L0804B6D4:
	movs r0, #0
.L0804B6D6:
	bx lr

	thumb_func_start CheckRoundMiss
CheckRoundMiss: @ 0x0804B6D8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bhi .L0804B71C
	lsls r0, r0, #2
	ldr r1, .L0804B6EC @ =.L0804B6F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B6EC: .4byte .L0804B6F0
.L0804B6F0: @ jump table
	.4byte .L0804B71C @ case 0
	.4byte .L0804B71C @ case 1
	.4byte .L0804B71C @ case 2
	.4byte .L0804B71C @ case 3
	.4byte .L0804B718 @ case 4
	.4byte .L0804B718 @ case 5
	.4byte .L0804B71C @ case 6
	.4byte .L0804B71C @ case 7
	.4byte .L0804B71C @ case 8
	.4byte .L0804B71C @ case 9
.L0804B718:
	movs r0, #1
	b .L0804B71E
.L0804B71C:
	movs r0, #0
.L0804B71E:
	bx lr

	thumb_func_start CheckRound1
CheckRound1: @ 0x0804B720
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bhi .L0804B764
	lsls r0, r0, #2
	ldr r1, .L0804B734 @ =.L0804B738
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B734: .4byte .L0804B738
.L0804B738: @ jump table
	.4byte .L0804B764 @ case 0
	.4byte .L0804B764 @ case 1
	.4byte .L0804B764 @ case 2
	.4byte .L0804B764 @ case 3
	.4byte .L0804B764 @ case 4
	.4byte .L0804B764 @ case 5
	.4byte .L0804B760 @ case 6
	.4byte .L0804B760 @ case 7
	.4byte .L0804B760 @ case 8
	.4byte .L0804B764 @ case 9
.L0804B760:
	movs r0, #1
	b .L0804B766
.L0804B764:
	movs r0, #0
.L0804B766:
	bx lr

	thumb_func_start CheckRound2
CheckRound2: @ 0x0804B768
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bhi .L0804B7AC
	lsls r0, r0, #2
	ldr r1, .L0804B77C @ =.L0804B780
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B77C: .4byte .L0804B780
.L0804B780: @ jump table
	.4byte .L0804B7A8 @ case 0
	.4byte .L0804B7A8 @ case 1
	.4byte .L0804B7A8 @ case 2
	.4byte .L0804B7A8 @ case 3
	.4byte .L0804B7AC @ case 4
	.4byte .L0804B7AC @ case 5
	.4byte .L0804B7AC @ case 6
	.4byte .L0804B7AC @ case 7
	.4byte .L0804B7AC @ case 8
	.4byte .L0804B7A8 @ case 9
.L0804B7A8:
	movs r0, #1
	b .L0804B7AE
.L0804B7AC:
	movs r0, #0
.L0804B7AE:
	bx lr

	thumb_func_start CheckRoundCrit
CheckRoundCrit: @ 0x0804B7B0
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x12]
	cmp r0, #9
	bhi .L0804B806
	lsls r0, r0, #2
	ldr r1, .L0804B7C4 @ =.L0804B7C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B7C4: .4byte .L0804B7C8
.L0804B7C8: @ jump table
	.4byte .L0804B806 @ case 0
	.4byte .L0804B802 @ case 1
	.4byte .L0804B806 @ case 2
	.4byte .L0804B7F0 @ case 3
	.4byte .L0804B806 @ case 4
	.4byte .L0804B806 @ case 5
	.4byte .L0804B806 @ case 6
	.4byte .L0804B806 @ case 7
	.4byte .L0804B806 @ case 8
	.4byte .L0804B806 @ case 9
.L0804B7F0:
	adds r0, r2, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804B802
	bl GetEkrDragonStateTypeIdunn
	cmp r0, #0
	bne .L0804B806
.L0804B802:
	movs r0, #1
	b .L0804B808
.L0804B806:
	movs r0, #0
.L0804B808:
	pop {r1}
	bx r1

	thumb_func_start GetAnimAnotherSide
GetAnimAnotherSide: @ 0x0804B80C
	push {r4, lr}
	ldr r4, .L0804B824 @ =gAnims
	bl GetAnimPosition
	movs r1, #1
	eors r1, r0
	lsls r1, r1, #3
	adds r1, r1, r4
	ldr r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0804B824: .4byte gAnims

	thumb_func_start GetAnimRoundType
GetAnimRoundType: @ 0x0804B828
	push {r4, lr}
	adds r4, r0, #0
	bl GetAnimPosition
	adds r1, r0, #0
	ldrh r0, [r4, #0xe]
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	bl GetBattleAnimRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start GetAnimNextRoundType
GetAnimNextRoundType: @ 0x0804B848
	push {r4, lr}
	adds r4, r0, #0
	bl GetAnimPosition
	adds r1, r0, #0
	ldrh r4, [r4, #0xe]
	lsls r0, r4, #1
	adds r0, r0, r1
	bl GetBattleAnimRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start GetAnimRoundTypeAnotherSide
GetAnimRoundTypeAnotherSide: @ 0x0804B868
	push {r4, lr}
	adds r4, r0, #0
	bl GetAnimPosition
	adds r2, r0, #0
	ldrh r0, [r4, #0xe]
	subs r0, #1
	lsls r0, r0, #1
	movs r1, #1
	eors r1, r2
	adds r0, r0, r1
	bl GetBattleAnimRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start GetAnimNextRoundTypeAnotherSide
GetAnimNextRoundTypeAnotherSide: @ 0x0804B88C
	push {r4, lr}
	adds r4, r0, #0
	bl GetAnimPosition
	adds r2, r0, #0
	ldrh r4, [r4, #0xe]
	lsls r0, r4, #1
	movs r1, #1
	eors r1, r2
	adds r0, r0, r1
	bl GetBattleAnimRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start SetAnimStateHidden
SetAnimStateHidden: @ 0x0804B8B0
	cmp r0, #0
	bne .L0804B8C8
	ldr r2, .L0804B8C4 @ =gAnims
	ldr r3, [r2]
	movs r1, #2
	ldrh r0, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r3, [r2, #4]
	b .L0804B8DA
	.align 2, 0
.L0804B8C4: .4byte gAnims
.L0804B8C8:
	cmp r0, #1
	bne .L0804B8E0
	ldr r2, .L0804B8E4 @ =gAnims
	ldr r3, [r2, #8]
	movs r1, #2
	ldrh r0, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r3, [r2, #0xc]
.L0804B8DA:
	ldrh r0, [r3]
	orrs r0, r1
	strh r0, [r3]
.L0804B8E0:
	bx lr
	.align 2, 0
.L0804B8E4: .4byte gAnims

	thumb_func_start SetAnimStateUnHidden
SetAnimStateUnHidden: @ 0x0804B8E8
	push {r4, lr}
	cmp r0, #0
	bne .L0804B908
	ldr r2, .L0804B900 @ =gAnims
	ldr r3, [r2]
	ldr r1, .L0804B904 @ =0x0000FFFD
	adds r0, r1, #0
	ldrh r4, [r3]
	ands r0, r4
	strh r0, [r3]
	ldr r3, [r2, #4]
	b .L0804B91C
	.align 2, 0
.L0804B900: .4byte gAnims
.L0804B904: .4byte 0x0000FFFD
.L0804B908:
	cmp r0, #1
	bne .L0804B922
	ldr r2, .L0804B928 @ =gAnims
	ldr r3, [r2, #8]
	ldr r1, .L0804B92C @ =0x0000FFFD
	adds r0, r1, #0
	ldrh r4, [r3]
	ands r0, r4
	strh r0, [r3]
	ldr r3, [r2, #0xc]
.L0804B91C:
	ldrh r0, [r3]
	ands r1, r0
	strh r1, [r3]
.L0804B922:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B928: .4byte gAnims
.L0804B92C: .4byte 0x0000FFFD
