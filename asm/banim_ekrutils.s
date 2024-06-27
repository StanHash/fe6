
	.include "macro.inc"

	.syntax unified

	thumb_func_start SpellFx_Begin
SpellFx_Begin: @ 0x080474B0
	ldr r1, .L080474B8 @ =gEfxSpellAnimExists
	movs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L080474B8: .4byte gEfxSpellAnimExists

	thumb_func_start SpellFx_Finish
SpellFx_Finish: @ 0x080474BC
	ldr r1, .L080474C4 @ =gEfxSpellAnimExists
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
.L080474C4: .4byte gEfxSpellAnimExists

	thumb_func_start SpellFx_SetBG1Position
SpellFx_SetBG1Position: @ 0x080474C8
	push {lr}
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	pop {r0}
	bx r0

	thumb_func_start SpellFx_ClearBG1
SpellFx_ClearBG1: @ 0x080474D8
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080474F8 @ =gBg1Tm
	ldr r2, .L080474FC @ =0x01000200
	mov r0, sp
	bl CpuFastSet
	movs r0, #2
	bl EnableBgSync
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
.L080474F8: .4byte gBg1Tm
.L080474FC: .4byte 0x01000200

	thumb_func_start SpellFx_SetSomeColorEffect
SpellFx_SetSomeColorEffect: @ 0x08047500
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, .L080475CC @ =gDispIo
	mov ip, r0
	mov r2, ip
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	mov r1, ip
	adds r1, #0x44
	movs r2, #0
	movs r3, #0x10
	mov r8, r3
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strb r2, [r0]
	ldr r0, .L080475D0 @ =0x0000FFE0
	mov r1, ip
	ldrh r1, [r1, #0x3c]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, .L080475D4 @ =0x0000E0FF
	ands r0, r1
	movs r3, #0xe0
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	mov r1, ip
	strh r0, [r1, #0x3c]
	movs r5, #0x20
	ldrb r0, [r1, #1]
	orrs r0, r5
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r3, ip
	strb r0, [r3, #1]
	mov r0, ip
	adds r0, #0x2d
	strb r2, [r0]
	adds r0, #4
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x2c
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	mov r6, ip
	adds r6, #0x34
	movs r0, #1
	ldrb r1, [r6]
	orrs r1, r0
	movs r2, #2
	orrs r1, r2
	movs r4, #4
	orrs r1, r4
	movs r3, #8
	orrs r1, r3
	mov r2, r8
	orrs r1, r2
	mov r7, ip
	adds r7, #0x36
	ldrb r2, [r7]
	orrs r0, r2
	movs r2, #3
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r4
	orrs r0, r3
	mov r3, r8
	orrs r0, r3
	orrs r1, r5
	strb r1, [r6]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r7]
	mov r0, ip
	adds r0, #0x3d
	ldrb r1, [r0]
	orrs r5, r1
	strb r5, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080475CC: .4byte gDispIo
.L080475D0: .4byte 0x0000FFE0
.L080475D4: .4byte 0x0000E0FF

	thumb_func_start SpellFx_ClearColorEffects
SpellFx_ClearColorEffects: @ 0x080475D8
	ldr r3, .L080475FC @ =gDispIo
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	adds r1, #8
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x45
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	bx lr
	.align 2, 0
.L080475FC: .4byte gDispIo

	thumb_func_start StartBattleAnimHitEffectsDefault
StartBattleAnimHitEffectsDefault: @ 0x08047600
	push {lr}
	movs r2, #3
	movs r3, #4
	bl StartBattleAnimHitEffects
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08047610
func_fe6_08047610: @ 0x08047610
	push {lr}
	movs r2, #5
	movs r3, #5
	bl StartBattleAnimHitEffects
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start StartBattleAnimHitEffects
StartBattleAnimHitEffects: @ 0x08047620
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r1, #0
	str r2, [sp]
	mov sl, r3
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804764C
	ldr r0, .L08047648 @ =gAnims
	ldr r7, [r0, #8]
	ldr r1, [r0, #0xc]
	mov sb, r1
	ldr r5, [r0]
	ldr r0, [r0, #4]
	b .L08047658
	.align 2, 0
.L08047648: .4byte gAnims
.L0804764C:
	ldr r0, .L08047668 @ =gAnims
	ldr r7, [r0]
	ldr r1, [r0, #4]
	mov sb, r1
	ldr r5, [r0, #8]
	ldr r0, [r0, #0xc]
.L08047658:
	mov r8, r0
	cmp r4, #0
	beq .L0804766C
	cmp r4, #1
	bne .L08047664
	b .L08047796
.L08047664:
	b .L0804779C
	.align 2, 0
.L08047668: .4byte gAnims
.L0804766C:
	adds r0, r7, #0
	bl GetAnimPosition
	adds r1, r0, #0
	ldrh r0, [r7, #0xe]
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	bl GetBattleAnimRoundTypeFlags
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r5, #0
	bl GetAnimPosition
	adds r1, r0, #0
	ldrh r0, [r5, #0xe]
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	bl GetBattleAnimRoundTypeFlags
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #6
	ands r0, r1
	cmp r0, #0
	beq .L080476BC
	adds r0, r7, #0
	bl GetUnitEfxDebuff
	cmp r0, #0
	bne .L080476BC
	adds r0, r7, #0
	movs r1, #1
	bl SetUnitEfxDebuff
.L080476BC:
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #6
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	beq .L080476DE
	adds r0, r5, #0
	bl GetUnitEfxDebuff
	cmp r0, #0
	bne .L080476DE
	adds r0, r5, #0
	movs r1, #1
	bl SetUnitEfxDebuff
.L080476DE:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L080476F4
	asrs r0, r4, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080476FC
.L080476F4:
	adds r0, r5, #0
	adds r5, r7, #0
	adds r7, r0, #0
	mov r8, sb
.L080476FC:
	ldr r4, .L08047764 @ =gEfxHpLutOff
	adds r0, r5, #0
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r0, r5, #0
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r4, #1
	adds r0, r5, #0
	bl GetAnimPosition
	adds r1, r0, #0
	lsls r0, r6, #1
	adds r0, r0, r1
	bl GetEfxHp
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	adds r0, r5, #0
	bl GetAnimPosition
	adds r1, r0, #0
	lsls r0, r4, #1
	adds r0, r0, r1
	bl GetEfxHp
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r6, r4
	beq .L0804778A
	adds r0, r5, #0
	bl NewEfxHpBar
	adds r0, r7, #0
	bl CheckRoundCrit
	cmp r0, #1
	bne .L08047768
	adds r0, r5, #0
	adds r1, r7, #0
	mov r2, sl
	bl NewEfxHitQuake
	b .L08047772
	.align 2, 0
.L08047764: .4byte gEfxHpLutOff
.L08047768:
	adds r0, r5, #0
	adds r1, r7, #0
	ldr r2, [sp]
	bl NewEfxHitQuake
.L08047772:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #5
	bl NewEfxFlashHPBar
	adds r0, r5, #0
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl NewEfxFlashUnit
	b .L0804779C
.L0804778A:
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0
	bl NewEfxNoDamage
	b .L0804779C
.L08047796:
	adds r0, r5, #0
	bl NewEfxAvoid
.L0804779C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start StartBattleAnimResireHitEffects
StartBattleAnimResireHitEffects: @ 0x080477AC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r1
	bl GetAnimPosition
	cmp r0, #0
	bne .L080477CC
	ldr r0, .L080477C8 @ =gAnims
	ldr r7, [r0, #8]
	ldr r5, [r0]
	ldr r0, [r0, #4]
	b .L080477D4
	.align 2, 0
.L080477C8: .4byte gAnims
.L080477CC:
	ldr r0, .L0804782C @ =gAnims
	ldr r7, [r0]
	ldr r5, [r0, #8]
	ldr r0, [r0, #0xc]
.L080477D4:
	mov r8, r0
	ldr r4, .L08047830 @ =gEfxHpLutOff
	adds r0, r5, #0
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r0, r5, #0
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r4, #1
	adds r0, r5, #0
	bl GetAnimPosition
	adds r1, r0, #0
	lsls r0, r6, #1
	adds r0, r0, r1
	bl GetEfxHp
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	adds r0, r5, #0
	bl GetAnimPosition
	adds r1, r0, #0
	lsls r0, r4, #1
	adds r0, r0, r1
	bl GetEfxHp
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	mov r0, sb
	cmp r0, #0
	beq .L08047834
	cmp r0, #1
	beq .L0804788C
	b .L08047892
	.align 2, 0
.L0804782C: .4byte gAnims
.L08047830: .4byte gEfxHpLutOff
.L08047834:
	cmp r6, r4
	beq .L08047876
	adds r0, r5, #0
	bl NewEfxHpBarResire
	adds r0, r7, #0
	bl CheckRoundCrit
	cmp r0, #1
	bne .L08047854
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #4
	bl NewEfxHitQuake
	b .L0804785E
.L08047854:
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #3
	bl NewEfxHitQuake
.L0804785E:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #5
	bl NewEfxFlashHPBar
	adds r0, r5, #0
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl NewEfxFlashUnit
	b .L08047892
.L08047876:
	ldr r1, .L08047888 @ =gEfxHpBarResireFlag
	movs r0, #2
	str r0, [r1]
	adds r0, r5, #0
	mov r1, r8
	movs r2, #1
	bl NewEfxNoDamage
	b .L08047892
	.align 2, 0
.L08047888: .4byte gEfxHpBarResireFlag
.L0804788C:
	adds r0, r5, #0
	bl NewEfxAvoid
.L08047892:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start StartBattleAnimStatusChgHitEffects
StartBattleAnimStatusChgHitEffects: @ 0x080478A0
	push {r4, lr}
	adds r4, r1, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L080478B8
	ldr r0, .L080478B4 @ =gAnims
	ldr r0, [r0]
	b .L080478BC
	.align 2, 0
.L080478B4: .4byte gAnims
.L080478B8:
	ldr r0, .L080478C8 @ =gAnims
	ldr r0, [r0, #8]
.L080478BC:
	cmp r4, #0
	beq .L080478CC
	cmp r4, #1
	beq .L080478D2
	b .L080478D6
	.align 2, 0
.L080478C8: .4byte gAnims
.L080478CC:
	bl NewEfxStatusCHG
	b .L080478D6
.L080478D2:
	bl NewEfxAvoid
.L080478D6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start EfxCreateFrontAnim
EfxCreateFrontAnim: @ 0x080478DC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r3, #0
	ldr r0, .L08047900 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08047908
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08047904
	adds r0, r7, #0
	b .L08047918
	.align 2, 0
.L08047900: .4byte gEkrDistanceType
.L08047904:
	adds r0, r6, #0
	b .L08047918
.L08047908:
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08047916
	adds r0, r5, #0
	b .L08047918
.L08047916:
	ldr r0, [sp, #0x14]
.L08047918:
	movs r1, #0x78
	bl BasCreate
	adds r1, r0, #0
	movs r0, #0xa1
	lsls r0, r0, #6
	strh r0, [r1, #8]
	ldrh r0, [r4, #2]
	strh r0, [r1, #2]
	ldrh r0, [r4, #4]
	strh r0, [r1, #4]
	adds r0, r1, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EfxCreateBackAnim
EfxCreateBackAnim: @ 0x08047938
	push {r4, lr}
	sub sp, #8
	adds r3, r0, #0
	ldr r0, .L0804796C @ =gEkrDistanceType
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r4, r2, #0
	cmp r0, #0
	bne .L0804794C
	adds r4, r1, #0
.L0804794C:
	adds r0, r3, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08047974
	ldr r1, .L08047970 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl EfxTmCpyBgHFlip
	b .L08047988
	.align 2, 0
.L0804796C: .4byte gEkrDistanceType
.L08047970: .4byte gBg1Tm
.L08047974:
	ldr r1, .L08047998 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl EfxTmCpyBG
.L08047988:
	movs r0, #2
	bl EnableBgSync
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08047998: .4byte gBg1Tm

	thumb_func_start SpellFx_WriteBgMap
SpellFx_WriteBgMap: @ 0x0804799C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, .L080479B8 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080479C0
	ldr r1, .L080479BC @ =gEkrTsaBuffer
	adds r0, r3, #0
	bl LZ77UnCompWram
	b .L080479C8
	.align 2, 0
.L080479B8: .4byte gEkrDistanceType
.L080479BC: .4byte gEkrTsaBuffer
.L080479C0:
	ldr r1, .L080479EC @ =gEkrTsaBuffer
	adds r0, r2, #0
	bl LZ77UnCompWram
.L080479C8:
	ldr r5, .L080479EC @ =gEkrTsaBuffer
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L080479F4
	ldr r1, .L080479F0 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl EfxTmCpyBgHFlip
	b .L08047A08
	.align 2, 0
.L080479EC: .4byte gEkrTsaBuffer
.L080479F0: .4byte gBg1Tm
.L080479F4:
	ldr r1, .L08047A18 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl EfxTmCpyBG
.L08047A08:
	movs r0, #2
	bl EnableBgSync
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08047A18: .4byte gBg1Tm

	thumb_func_start SpellFx_WriteBgMapExt
SpellFx_WriteBgMapExt: @ 0x08047A1C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r7, .L08047A54 @ =gEkrTsaBuffer
	adds r1, r7, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08047A5C
	ldr r1, .L08047A58 @ =gBg1Tm
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r6, #0x10
	lsrs r3, r3, #0x10
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r7, #0
	bl EfxTmCpyBgHFlip
	b .L08047A74
	.align 2, 0
.L08047A54: .4byte gEkrTsaBuffer
.L08047A58: .4byte gBg1Tm
.L08047A5C:
	ldr r1, .L08047A84 @ =gBg1Tm
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r6, #0x10
	lsrs r3, r3, #0x10
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r7, #0
	bl EfxTmCpyBG
.L08047A74:
	movs r0, #2
	bl EnableBgSync
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08047A84: .4byte gBg1Tm

	thumb_func_start SpellFx_RegisterObjGfx
SpellFx_RegisterObjGfx: @ 0x08047A88
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	ldr r5, .L08047AA8 @ =0x06010800
	ldr r4, .L08047AAC @ =gBuf_Banim
	adds r1, r4, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl RegisterDataMove
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08047AA8: .4byte 0x06010800
.L08047AAC: .4byte gBuf_Banim

	thumb_func_start SpellFx_RegisterObjPal
SpellFx_RegisterObjPal: @ 0x08047AB0
	push {lr}
	adds r2, r1, #0
	ldr r1, .L08047AC8 @ =gPal+0x240
	lsls r2, r2, #9
	lsrs r2, r2, #0xb
	bl CpuFastSet
	bl EnablePalSync
	pop {r0}
	bx r0
	.align 2, 0
.L08047AC8: .4byte gPal+0x240

	thumb_func_start SpellFx_RegisterBgGfx
SpellFx_RegisterBgGfx: @ 0x08047ACC
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	ldr r5, .L08047AEC @ =0x06002000
	ldr r4, .L08047AF0 @ =gSpellAnimBgfx
	adds r1, r4, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl RegisterDataMove
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08047AEC: .4byte 0x06002000
.L08047AF0: .4byte gSpellAnimBgfx

	thumb_func_start SpellFx_RegisterBgPal
SpellFx_RegisterBgPal: @ 0x08047AF4
	push {lr}
	adds r2, r1, #0
	ldr r1, .L08047B0C @ =gPal+0x20
	lsls r2, r2, #9
	lsrs r2, r2, #0xb
	bl CpuFastSet
	bl EnablePalSync
	pop {r0}
	bx r0
	.align 2, 0
.L08047B0C: .4byte gPal+0x20

	thumb_func_start func_fe6_08047B10
func_fe6_08047B10: @ 0x08047B10
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r3, #0
	ldr r4, [sp, #0x10]
	movs r3, #0
	cmp r3, r4
	bhs .L08047B36
.L08047B1E:
	cmp r2, r5
	blo .L08047B24
	movs r2, #0
.L08047B24:
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	adds r2, #1
	cmp r3, r4
	blo .L08047B1E
.L08047B36:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08047B3C
func_fe6_08047B3C: @ 0x08047B3C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r3, #0
	ldr r4, [sp, #0x10]
	movs r3, #0
	cmp r3, r4
	bhs .L08047B62
.L08047B4A:
	cmp r2, r5
	blo .L08047B50
	movs r2, #0
.L08047B50:
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r1, #0x20]
	adds r1, #2
	adds r3, #1
	adds r2, #1
	cmp r3, r4
	blo .L08047B4A
.L08047B62:
	bl EnablePalSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08047B6C
func_fe6_08047B6C: @ 0x08047B6C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r3, #0
	ldr r4, [sp, #0x10]
	movs r3, #0
	cmp r3, r4
	bhs .L08047B98
	movs r0, #0x90
	lsls r0, r0, #2
	adds r1, r1, r0
.L08047B80:
	cmp r2, r5
	blo .L08047B86
	movs r2, #0
.L08047B86:
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	adds r2, #1
	cmp r3, r4
	blo .L08047B80
.L08047B98:
	bl EnablePalSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EfxAdvanceFrameLut
EfxAdvanceFrameLut: @ 0x08047BA4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	ldrh r0, [r5]
	adds r6, r0, #0
	cmp r6, #0
	bne .L08047C0C
	ldrh r0, [r3]
	mov ip, r0
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r4, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L08047BD0
	movs r0, #4
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08047BD4
.L08047BD0:
	adds r0, r1, #0
	b .L08047C14
.L08047BD4:
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08047BE2
	strh r6, [r3]
	ldrh r4, [r2]
	b .L08047BF6
.L08047BE2:
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08047BF6
	mov r0, ip
	subs r0, #1
	strh r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r4, [r0]
.L08047BF6:
	ldrh r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	adds r1, #1
	strh r1, [r3]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	b .L08047C14
.L08047C0C:
	subs r0, #1
	strh r0, [r5]
	movs r0, #5
	rsbs r0, r0, #0
.L08047C14:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08047C1C
func_fe6_08047C1C: @ 0x08047C1C
	ldr r1, .L08047C24 @ =gUnk_Banim_02017754
	movs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L08047C24: .4byte gUnk_Banim_02017754

	thumb_func_start EfxGetCamMovDuration
EfxGetCamMovDuration: @ 0x08047C28
	ldr r0, .L08047C38 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #2
	bne .L08047C3C
	movs r0, #0x18
	b .L08047C46
	.align 2, 0
.L08047C38: .4byte gEkrDistanceType
.L08047C3C:
	cmp r0, #1
	beq .L08047C44
	movs r0, #0
	b .L08047C46
.L08047C44:
	movs r0, #0x10
.L08047C46:
	bx lr

	thumb_func_start func_fe6_08047C48
func_fe6_08047C48: @ 0x08047C48
	push {lr}
	sub sp, #4
	ldr r1, .L08047C60 @ =gTmA_Banim
	str r0, [sp]
	ldr r2, .L08047C64 @ =0x050002D6
	mov r0, sp
	bl CpuSet
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
.L08047C60: .4byte gTmA_Banim
.L08047C64: .4byte 0x050002D6

	thumb_func_start EfxTmFill
EfxTmFill: @ 0x08047C68
	push {lr}
	sub sp, #4
	ldr r1, .L08047C80 @ =gTmB_Banim
	str r0, [sp]
	ldr r2, .L08047C84 @ =0x050002D6
	mov r0, sp
	bl CpuSet
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
.L08047C80: .4byte gTmB_Banim
.L08047C84: .4byte 0x050002D6

	thumb_func_start SetEkrFrontAnimPostion
SetEkrFrontAnimPostion: @ 0x08047C88
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r0, #0
	bne .L08047CA4
	ldr r0, .L08047CA0 @ =gAnims
	ldr r3, [r0]
	strh r1, [r3, #2]
	strh r2, [r3, #4]
	ldr r3, [r0, #4]
	b .L08047CAE
	.align 2, 0
.L08047CA0: .4byte gAnims
.L08047CA4:
	ldr r0, .L08047CB4 @ =gAnims
	ldr r3, [r0, #8]
	strh r1, [r3, #2]
	strh r2, [r3, #4]
	ldr r3, [r0, #0xc]
.L08047CAE:
	strh r1, [r3, #2]
	strh r2, [r3, #4]
	bx lr
	.align 2, 0
.L08047CB4: .4byte gAnims
