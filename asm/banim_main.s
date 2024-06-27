	.include "macro.inc"
	.syntax unified

	thumb_func_start BattleAIS_ExecCommands
BattleAIS_ExecCommands: @ 0x0804A5DC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	movs r2, #0
.L00804A5E8: @ 0x0804A5E8
	ldr r1, .L0804A640 @ =gAnims
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r7, [r0]
	adds r2, #1
	mov sb, r2
	cmp r7, #0
	bne .L0804A5FC
	bl .L0804AF52
.L0804A5FC:
	movs r0, #0xf0
	lsls r0, r0, #8
	ldrh r1, [r7, #0xc]
	ands r1, r0
	mov r8, r1
	cmp r1, #0
	bne .L0804A60E
	bl .L0804AF52
.L0804A60E:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	bne .L0804A61A
	b .L0804AD94
.L0804A61A:
	ldrb r0, [r7, #0x14]
	cmp r0, #0
	bne .L0804A622
	b .L0804AD8A
.L0804A622:
	subs r1, r0, #1
	adds r2, r7, #0
	adds r2, #0x15
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r3, r0, #0
	cmp r1, #0x4a
	bls .L0804A634
	b .L0804AD82
.L0804A634:
	lsls r0, r1, #2
	ldr r1, .L0804A644 @ =.L0804A648
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804A640: .4byte gAnims
.L0804A644: .4byte .L0804A648
.L0804A648: @ jump table
	.4byte .L0804AD82 @ case 0
	.4byte .L0804A774 @ case 1
	.4byte .L0804A7B4 @ case 2
	.4byte .L0804A7C8 @ case 3
	.4byte .L0804A7EE @ case 4
	.4byte .L0804A874 @ case 5
	.4byte .L0804A8C8 @ case 6
	.4byte .L0804AD82 @ case 7
	.4byte .L0804A8F8 @ case 8
	.4byte .L0804A8F8 @ case 9
	.4byte .L0804A8F8 @ case 10
	.4byte .L0804A8F8 @ case 11
	.4byte .L0804A8F8 @ case 12
	.4byte .L0804A968 @ case 13
	.4byte .L0804AD82 @ case 14
	.4byte .L0804AD82 @ case 15
	.4byte .L0804AD82 @ case 16
	.4byte .L0804AD82 @ case 17
	.4byte .L0804AD82 @ case 18
	.4byte .L0804AB08 @ case 19
	.4byte .L0804AB38 @ case 20
	.4byte .L0804AB4C @ case 21
	.4byte .L0804AD82 @ case 22
	.4byte .L0804AD82 @ case 23
	.4byte .L0804AB60 @ case 24
	.4byte .L0804AD60 @ case 25
	.4byte .L0804AB9C @ case 26
	.4byte .L0804AD60 @ case 27
	.4byte .L0804AD60 @ case 28
	.4byte .L0804AD60 @ case 29
	.4byte .L0804AD60 @ case 30
	.4byte .L0804AD60 @ case 31
	.4byte .L0804AD60 @ case 32
	.4byte .L0804AD60 @ case 33
	.4byte .L0804AD60 @ case 34
	.4byte .L0804AD60 @ case 35
	.4byte .L0804AD60 @ case 36
	.4byte .L0804AD60 @ case 37
	.4byte .L0804ABF2 @ case 38
	.4byte .L0804AC08 @ case 39
	.4byte .L0804AD60 @ case 40
	.4byte .L0804AD60 @ case 41
	.4byte .L0804AD60 @ case 42
	.4byte .L0804AD60 @ case 43
	.4byte .L0804AC1E @ case 44
	.4byte .L0804AC32 @ case 45
	.4byte .L0804AC3A @ case 46
	.4byte .L0804AC50 @ case 47
	.4byte .L0804AC66 @ case 48
	.4byte .L0804AC7C @ case 49
	.4byte .L0804AC92 @ case 50
	.4byte .L0804AD60 @ case 51
	.4byte .L0804AD60 @ case 52
	.4byte .L0804AD60 @ case 53
	.4byte .L0804AD60 @ case 54
	.4byte .L0804AD60 @ case 55
	.4byte .L0804AD60 @ case 56
	.4byte .L0804ACA6 @ case 57
	.4byte .L0804ACEC @ case 58
	.4byte .L0804AD14 @ case 59
	.4byte .L0804AD60 @ case 60
	.4byte .L0804AD60 @ case 61
	.4byte .L0804AD60 @ case 62
	.4byte .L0804AD60 @ case 63
	.4byte .L0804AD60 @ case 64
	.4byte .L0804AD60 @ case 65
	.4byte .L0804AD60 @ case 66
	.4byte .L0804AD60 @ case 67
	.4byte .L0804AD3C @ case 68
	.4byte .L0804AD4E @ case 69
	.4byte .L0804AD60 @ case 70
	.4byte .L0804AD6E @ case 71
	.4byte .L0804AD76 @ case 72
	.4byte .L0804AD76 @ case 73
	.4byte .L0804AD76 @ case 74
.L0804A774:
	ldr r0, .L0804A784 @ =gAnimC01Blocking
	ldr r0, [r0]
	cmp r0, #1
	bne .L0804A788
	ldr r0, [r7, #0x24]
	str r0, [r7, #0x20]
	b .L0804AD82
	.align 2, 0
.L0804A784: .4byte gAnimC01Blocking
.L0804A788:
	ldrh r1, [r7, #0x10]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne .L0804A794
	b .L0804ACDC
.L0804A794:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L0804A79E
	b .L0804AD82
.L0804A79E:
	bl CheckEkrHitDone
	cmp r0, #1
	beq .L0804A7A8
	b .L0804AD82
.L0804A7A8:
	ldr r0, .L0804A7B0 @ =0x0000FFF2
	ldrh r2, [r7, #0x10]
	ands r0, r2
	b .L0804ACDA
	.align 2, 0
.L0804A7B0: .4byte 0x0000FFF2
.L0804A7B4:
	ldrh r1, [r7, #0x10]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0804A7C0
	b .L0804AD82
.L0804A7C0:
	ldr r0, .L0804A7C4 @ =0x0000FFFE
	b .L0804ACD8
	.align 2, 0
.L0804A7C4: .4byte 0x0000FFFE
.L0804A7C8:
	ldrh r1, [r7, #0x10]
	movs r2, #0x20
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0804A7EA
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r7, #0x10]
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804A7EA
	adds r0, r7, #0
	bl func_fe6_08057860
.L0804A7EA:
	ldrh r1, [r7, #0x10]
	b .L0804ACCA
.L0804A7EE:
	ldrh r1, [r7, #0x10]
	movs r2, #0x20
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0804A804
	adds r0, r2, #0
	orrs r0, r1
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r7, #0x10]
.L0804A804:
	ldrh r2, [r7, #0x10]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	bne .L0804A810
	b .L0804AD82
.L0804A810:
	ldr r1, .L0804A86C @ =0x0000FFDF
	ands r1, r2
	ldr r0, .L0804A870 @ =0x0000FFBF
	ands r1, r0
	ldr r0, [r7, #0x20]
	adds r0, #4
	str r0, [r7, #0x20]
	movs r5, #9
	movs r6, #0
	orrs r1, r5
	strh r1, [r7, #0x10]
	adds r0, r7, #0
	bl GetAnimAnotherSide
	adds r2, r0, #0
	adds r0, r7, #0
	str r2, [sp]
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	mov r4, r8
	adds r0, r4, #0
	bl CheckRoundMiss
	ldr r2, [sp]
	cmp r0, #1
	beq .L0804A84C
	b .L0804AD82
.L0804A84C:
	cmp r2, #0
	bne .L0804A852
	b .L0804AD82
.L0804A852:
	ldrh r0, [r2, #0x10]
	orrs r0, r5
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	str r2, [sp]
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804A866
	b .L0804AD82
.L0804A866:
	adds r0, r4, #0
	b .L0804A958
	.align 2, 0
.L0804A86C: .4byte 0x0000FFDF
.L0804A870: .4byte 0x0000FFBF
.L0804A874:
	ldrh r1, [r7, #0x10]
	movs r2, #0x20
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0804A88A
	adds r0, r2, #0
	orrs r0, r1
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r7, #0x10]
.L0804A88A:
	ldrh r2, [r7, #0x10]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	bne .L0804A896
	b .L0804AD82
.L0804A896:
	ldr r1, .L0804A8C0 @ =0x0000FFDF
	ands r1, r2
	ldr r0, .L0804A8C4 @ =0x0000FFBF
	ands r1, r0
	ldr r0, [r7, #0x20]
	adds r0, #4
	str r0, [r7, #0x20]
	movs r0, #9
	orrs r1, r0
	strh r1, [r7, #0x10]
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804A8B6
	b .L0804AD82
.L0804A8B6:
	adds r0, r7, #0
	bl StartSpellAnimation
	b .L0804AD82
	.align 2, 0
.L0804A8C0: .4byte 0x0000FFDF
.L0804A8C4: .4byte 0x0000FFBF
.L0804A8C8:
	adds r0, r7, #0
	bl GetAnimAnotherSide
	adds r2, r0, #0
	cmp r2, #0
	bne .L0804A8D6
	b .L0804AD82
.L0804A8D6:
	str r2, [sp]
	bl GetAnimNextRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r0, #1
	rsbs r0, r0, #0
	ldr r2, [sp]
	cmp r8, r0
	bne .L0804A8EE
	b .L0804AD82
.L0804A8EE:
	movs r0, #2
	ldrh r3, [r2, #0x10]
	orrs r0, r3
	strh r0, [r2, #0x10]
	b .L0804AD82
.L0804A8F8:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804A904
	b .L0804AD82
.L0804A904:
	adds r0, r7, #0
	bl GetAnimAnotherSide
	adds r2, r0, #0
	adds r0, r7, #0
	str r2, [sp]
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	bl CheckRoundMiss
	ldr r2, [sp]
	cmp r0, #0
	bne .L0804A93C
	adds r0, r2, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp]
	cmp r0, #2
	beq .L0804A93C
	adds r0, r2, #0
	bl func_fe6_08056B08
	ldr r2, [sp]
.L0804A93C:
	cmp r2, #0
	bne .L0804A942
	b .L0804AD82
.L0804A942:
	movs r0, #9
	ldrh r1, [r2, #0x10]
	orrs r0, r1
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	str r2, [sp]
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
.L0804A958:
	bl CheckRoundMiss
	adds r1, r0, #0
	ldr r2, [sp]
	adds r0, r2, #0
	bl StartBattleAnimHitEffectsDefault
	b .L0804AD82
.L0804A968:
	adds r0, r7, #0
	bl GetAnimNextRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	ldr r4, .L0804A9A8 @ =gAnims
	adds r0, r7, #0
	bl GetAnimPosition
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r2, [r0]
	adds r0, r7, #0
	str r2, [sp]
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r6, [r0]
	ldrb r0, [r7, #0x12]
	ldr r2, [sp]
	cmp r0, #9
	bls .L0804A99E
	b .L0804AD82
.L0804A99E:
	lsls r0, r0, #2
	ldr r1, .L0804A9AC @ =.L0804A9B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804A9A8: .4byte gAnims
.L0804A9AC: .4byte .L0804A9B0
.L0804A9B0: @ jump table
	.4byte .L0804A9D8 @ case 0
	.4byte .L0804A9D8 @ case 1
	.4byte .L0804A9D8 @ case 2
	.4byte .L0804A9D8 @ case 3
	.4byte .L0804AAE0 @ case 4
	.4byte .L0804AAE0 @ case 5
	.4byte .L0804AAEE @ case 6
	.4byte .L0804AAEE @ case 7
	.4byte .L0804AAEE @ case 8
	.4byte .L0804A9D8 @ case 9
.L0804A9D8:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	bne .L0804A9E2
	b .L0804AAE0
.L0804A9E2:
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	adds r0, r2, #0
	mov r1, r8
	str r2, [sp]
	bl SwitchAISFrameDataFromBARoundType
	adds r0, r6, #0
	mov r1, r8
	bl SwitchAISFrameDataFromBARoundType
	movs r1, #4
	ldr r2, [sp]
	ldrh r0, [r2, #0x10]
	orrs r0, r1
	strh r0, [r2, #0x10]
	ldrh r0, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	ldr r1, .L0804AA38 @ =gUnk_081122C0
	ldr r0, .L0804AA3C @ =gEkrDistanceType
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r8, r0
	ldr r1, .L0804AA40 @ =gUnk_08112298
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r4, [r0]
	adds r0, r7, #0
	str r2, [sp]
	bl GetAnimPosition
	ldr r2, [sp]
	cmp r0, #0
	bne .L0804AA48
	ldr r0, .L0804AA44 @ =gUnk_Banim_02000054
	b .L0804AA4A
	.align 2, 0
.L0804AA38: .4byte gUnk_081122C0
.L0804AA3C: .4byte gEkrDistanceType
.L0804AA40: .4byte gUnk_08112298
.L0804AA44: .4byte gUnk_Banim_02000054
.L0804AA48:
	ldr r0, .L0804AACC @ =gUnk_Banim_02000058
.L0804AA4A:
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r7, #0
	str r2, [sp]
	bl GetAnimPosition
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #9
	ldr r0, .L0804AAD0 @ =gUnk_Banim_0200F1C0
	adds r1, r1, r0
	adds r1, r4, r1
	ldr r0, [r1, #4]
	ldr r2, [sp]
	str r0, [r2, #0x28]
	ldr r4, [r2, #0x30]
	ldr r1, [r1, #8]
	adds r4, r4, r1
	str r4, [r2, #0x3c]
	ldr r4, [r6, #0x30]
	ldr r0, .L0804AAD4 @ =0x000057F0
	adds r4, r4, r0
	str r4, [r6, #0x3c]
	ldr r4, .L0804AAD8 @ =0x0203CD98
	adds r0, r7, #0
	str r2, [sp]
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [sp]
	cmp r0, #0
	beq .L0804AA98
	b .L0804AD8A
.L0804AA98:
	ldr r4, .L0804AADC @ =gpImgSheet
	adds r0, r2, #0
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, [r0]
	ldr r2, [sp]
	ldr r0, [r2, #0x28]
	cmp r1, r0
	bne .L0804AAB0
	b .L0804AD8A
.L0804AAB0:
	adds r0, r2, #0
	bl NewEkrChienCHR
	ldr r2, [sp]
	adds r0, r2, #0
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r2, [sp]
	ldr r1, [r2, #0x28]
	str r1, [r0]
	b .L0804AD8A
	.align 2, 0
.L0804AACC: .4byte gUnk_Banim_02000058
.L0804AAD0: .4byte gUnk_Banim_0200F1C0
.L0804AAD4: .4byte 0x000057F0
.L0804AAD8: .4byte 0x0203CD98
.L0804AADC: .4byte gpImgSheet
.L0804AAE0:
	ldr r1, .L0804AB00 @ =gUnk_081122C0
	ldr r0, .L0804AB04 @ =gEkrDistanceType
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r8, r0
.L0804AAEE:
	adds r0, r2, #0
	mov r1, r8
	bl SwitchAISFrameDataFromBARoundType
	adds r0, r6, #0
	mov r1, r8
	bl SwitchAISFrameDataFromBARoundType
	b .L0804AD8A
	.align 2, 0
.L0804AB00: .4byte gUnk_081122C0
.L0804AB04: .4byte gEkrDistanceType
.L0804AB08:
	ldrh r2, [r7, #0x10]
	movs r1, #0x20
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne .L0804AB1C
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r7, #0x10]
	b .L0804AD82
.L0804AB1C:
	ldr r1, .L0804AB30 @ =gUnk_Banim_02017750
	ldr r0, [r1]
	cmp r0, #1
	beq .L0804AB26
	b .L0804AD82
.L0804AB26:
	movs r0, #0
	str r0, [r1]
	ldr r0, .L0804AB34 @ =0x0000FFDF
	ands r0, r2
	b .L0804ACDA
	.align 2, 0
.L0804AB30: .4byte gUnk_Banim_02017750
.L0804AB34: .4byte 0x0000FFDF
.L0804AB38:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804AB44
	b .L0804AD82
.L0804AB44:
	movs r0, #3
	bl NewEfxQuake
	b .L0804AD82
.L0804AB4C:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804AB58
	b .L0804AD82
.L0804AB58:
	movs r0, #0
	bl NewEfxQuake
	b .L0804AD82
.L0804AB60:
	ldrh r1, [r7, #0x10]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0804AB6C
	b .L0804AD82
.L0804AB6C:
	ldr r0, .L0804AB94 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r7, #0x10]
	ldr r0, [r7, #0x20]
	adds r0, #4
	str r0, [r7, #0x20]
	ldr r0, .L0804AB98 @ =0x0000F3FF
	ldrh r1, [r7, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r7, #8]
	movs r0, #0x8c
	strh r0, [r7, #0xa]
	bl BasSort
	b .L0804AD82
	.align 2, 0
.L0804AB94: .4byte 0x0000FFFE
.L0804AB98: .4byte 0x0000F3FF
.L0804AB9C:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804ABA8
	b .L0804AD82
.L0804ABA8:
	adds r0, r7, #0
	bl GetAnimAnotherSide
	adds r2, r0, #0
	cmp r2, #0
	beq .L0804ABDA
	movs r0, #9
	ldrh r3, [r2, #0x10]
	orrs r0, r3
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	str r2, [sp]
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	bl CheckRoundMiss
	adds r1, r0, #0
	ldr r2, [sp]
	adds r0, r2, #0
	bl StartBattleAnimHitEffectsDefault
	ldr r2, [sp]
.L0804ABDA:
	adds r0, r2, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L0804ABEA
	b .L0804AD82
.L0804ABEA:
	adds r0, r7, #0
	bl func_fe6_08056C3C
	b .L0804AD82
.L0804ABF2:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804ABFE
	b .L0804AD82
.L0804ABFE:
	adds r0, r7, #0
	movs r1, #0
	bl NewEfxYushaSpinShield
	b .L0804AD82
.L0804AC08:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804AC14
	b .L0804AD82
.L0804AC14:
	adds r0, r7, #0
	movs r1, #1
	bl NewEfxYushaSpinShield
	b .L0804AD82
.L0804AC1E:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804AC2A
	b .L0804AD82
.L0804AC2A:
	adds r0, r7, #0
	bl NewEfxHurtmutEff00
	b .L0804AD82
.L0804AC32:
	adds r0, r7, #0
	bl GetAnimLayer
	b .L0804AD82
.L0804AC3A:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804AC46
	b .L0804AD82
.L0804AC46:
	adds r0, r7, #0
	movs r1, #0
	bl func_fe6_080571A0
	b .L0804AD82
.L0804AC50:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804AC5C
	b .L0804AD82
.L0804AC5C:
	adds r0, r7, #0
	movs r1, #1
	bl func_fe6_080571A0
	b .L0804AD82
.L0804AC66:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804AC72
	b .L0804AD82
.L0804AC72:
	adds r0, r7, #0
	movs r1, #0
	bl func_fe6_08057344
	b .L0804AD82
.L0804AC7C:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	beq .L0804AC88
	b .L0804AD82
.L0804AC88:
	adds r0, r7, #0
	movs r1, #1
	bl func_fe6_08057344
	b .L0804AD82
.L0804AC92:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	movs r1, #2
	bl func_fe6_08057344
	b .L0804AD82
.L0804ACA6:
	ldrh r1, [r7, #0x10]
	movs r2, #0x20
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0804ACCA
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r7, #0x10]
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	bl NewEfxKingPika
	b .L0804AD82
.L0804ACCA:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L0804AD82
	ldr r0, .L0804ACE4 @ =0x0000FFDF
	ands r0, r1
	ldr r1, .L0804ACE8 @ =0x0000FFBF
.L0804ACD8:
	ands r0, r1
.L0804ACDA:
	strh r0, [r7, #0x10]
.L0804ACDC:
	ldr r0, [r7, #0x20]
	adds r0, #4
	str r0, [r7, #0x20]
	b .L0804AD82
	.align 2, 0
.L0804ACE4: .4byte 0x0000FFDF
.L0804ACE8: .4byte 0x0000FFBF
.L0804ACEC:
	ldrh r0, [r7, #2]
	adds r0, #0x20
	strh r0, [r7, #2]
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	bl GetAnimPosition
	ldr r1, .L0804AD10 @ =gEkrXPosReal
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #0x20
	strh r1, [r0]
	b .L0804AD82
	.align 2, 0
.L0804AD10: .4byte gEkrXPosReal
.L0804AD14:
	ldrh r0, [r7, #2]
	subs r0, #0x20
	strh r0, [r7, #2]
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	bl GetAnimPosition
	ldr r1, .L0804AD38 @ =gEkrXPosReal
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	subs r1, #0x20
	strh r1, [r0]
	b .L0804AD82
	.align 2, 0
.L0804AD38: .4byte gEkrXPosReal
.L0804AD3C:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	bl NewEfxFlashFX
	b .L0804AD82
.L0804AD4E:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	bl NewEfxSongOBJ2
	b .L0804AD82
.L0804AD60:
	subs r0, r3, #1
	adds r0, r2, r0
	ldrb r1, [r0]
	adds r0, r7, #0
	bl EfxPlaySEwithCmdCtrl
	b .L0804AD82
.L0804AD6E:
	adds r0, r7, #0
	bl NewEfxMantBatabata
	b .L0804AD82
.L0804AD76:
	subs r0, r3, #1
	adds r0, r2, r0
	ldrb r1, [r0]
	adds r0, r7, #0
	bl EfxPlaySEwithCmdCtrl
.L0804AD82:
	ldrb r0, [r7, #0x14]
	subs r0, #1
	strb r0, [r7, #0x14]
	b .L0804A61A
.L0804AD8A:
	movs r0, #0xe7
	lsls r0, r0, #8
	ldrh r1, [r7, #0xc]
	ands r0, r1
	strh r0, [r7, #0xc]
.L0804AD94:
	movs r0, #0x80
	lsls r0, r0, #6
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq .L0804ADFA
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804ADF0
	ldr r4, .L0804AE4C @ =0x0203CD98
	adds r0, r7, #0
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #0
	bne .L0804ADF0
	movs r0, #0x80
	lsls r0, r0, #7
	ldrh r3, [r7, #0x10]
	ands r0, r3
	cmp r0, #0
	bne .L0804ADF0
	ldr r4, .L0804AE50 @ =gpImgSheet
	adds r0, r7, #0
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, [r0]
	ldr r0, [r7, #0x28]
	cmp r1, r0
	beq .L0804ADF0
	adds r0, r7, #0
	bl RegisterAISSheetGraphics
	adds r0, r7, #0
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, [r7, #0x28]
	str r1, [r0]
.L0804ADF0:
	movs r0, #0xd7
	lsls r0, r0, #8
	ldrh r1, [r7, #0xc]
	ands r0, r1
	strh r0, [r7, #0xc]
.L0804ADFA:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ands r2, r0
	cmp r2, #0
	bne .L0804AE10
	ldr r0, .L0804AE54 @ =gAnimC01Blocking
	ldr r0, [r0]
	cmp r0, #1
	beq .L0804AE10
	b .L0804AF52
.L0804AE10:
	ldrh r1, [r7, #0x10]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0804AE98
	adds r0, r7, #0
	bl GetAnimNextRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	beq .L0804AE60
	ldr r6, .L0804AE58 @ =gAnims
	adds r0, r7, #0
	bl GetAnimPosition
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r2, [r0]
	adds r0, r2, #0
	mov r1, r8
	str r2, [sp]
	bl SwitchAISFrameDataFromBARoundType
	ldr r4, .L0804AE5C @ =0x0000FFFD
	b .L0804AED0
	.align 2, 0
.L0804AE4C: .4byte 0x0203CD98
.L0804AE50: .4byte gpImgSheet
.L0804AE54: .4byte gAnimC01Blocking
.L0804AE58: .4byte gAnims
.L0804AE5C: .4byte 0x0000FFFD
.L0804AE60:
	ldr r5, .L0804AE90 @ =gAnims
	adds r0, r7, #0
	bl GetAnimPosition
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r2, [r0]
	ldr r4, .L0804AE94 @ =0x0000FFFD
	adds r0, r4, #0
	ldrh r1, [r2, #0x10]
	ands r0, r1
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r6, [r0]
	ldrh r2, [r6, #0x10]
	ands r4, r2
	strh r4, [r6, #0x10]
	b .L0804AF52
	.align 2, 0
.L0804AE90: .4byte gAnims
.L0804AE94: .4byte 0x0000FFFD
.L0804AE98:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L0804AF18
	adds r0, r7, #0
	bl GetAnimNextRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	beq .L0804AF52
	ldr r6, .L0804AF10 @ =gAnims
	adds r0, r7, #0
	bl GetAnimPosition
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r2, [r0]
	adds r0, r2, #0
	mov r1, r8
	str r2, [sp]
	bl SwitchAISFrameDataFromBARoundType
	ldr r4, .L0804AF14 @ =0x00007FFF
.L0804AED0:
	adds r0, r4, #0
	ldr r2, [sp]
	ldrh r3, [r2, #0x10]
	ands r0, r3
	movs r5, #4
	orrs r0, r5
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	str r2, [sp]
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r6, [r0]
	adds r0, r6, #0
	mov r1, r8
	bl SwitchAISFrameDataFromBARoundType
	ldrh r0, [r6, #0x10]
	ands r4, r0
	orrs r4, r5
	strh r4, [r6, #0x10]
	ldr r2, [sp]
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	b .L0804AF52
	.align 2, 0
.L0804AF10: .4byte gAnims
.L0804AF14: .4byte 0x00007FFF
.L0804AF18:
	adds r0, r7, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804AF52
	adds r0, r7, #0
	bl GetAnimPosition
	adds r1, r0, #0
	ldrh r2, [r7, #0xe]
	lsls r0, r2, #1
	adds r0, r0, r1
	bl GetBattleAnimRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	bne .L0804AF52
	adds r0, r7, #0
	bl GetAnimPosition
	ldr r1, .L0804AF6C @ =gBanimDoneFlag
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
.L0804AF52:
	mov r2, sb
	cmp r2, #3
	bhi .L0804AF5C
	bl .L00804A5E8
.L0804AF5C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804AF6C: .4byte gBanimDoneFlag
