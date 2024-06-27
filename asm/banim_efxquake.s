	.include "macro.inc"

	.syntax unified

	.section .text

	thumb_func_start NewEfxHitQuake
NewEfxHitQuake: @ 0x080462BC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	mov r8, r1
	adds r6, r2, #0
	ldr r0, .L08046300 @ =gUnk_Banim_02017738
	ldr r7, [r0]
	cmp r7, #0
	beq .L080462D4
	b .L08046446
.L080462D4:
	movs r4, #1
	str r4, [r0]
	ldr r0, .L08046304 @ =ProcScr_EfxHitQuake
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	mov r0, sb
	str r0, [r5, #0x5c]
	mov r1, r8
	str r1, [r5, #0x60]
	strh r7, [r5, #0x2c]
	adds r0, r5, #0
	adds r0, #0x29
	strb r4, [r0]
	cmp r6, #0
	beq .L0804633C
	cmp r6, #1
	bne .L0804630C
	ldr r0, .L08046308 @ =gEfxQuakePureVec2
	b .L0804633E
	.align 2, 0
.L08046300: .4byte gUnk_Banim_02017738
.L08046304: .4byte ProcScr_EfxHitQuake
.L08046308: .4byte gEfxQuakePureVec2
.L0804630C:
	cmp r6, #2
	bne .L08046318
	ldr r0, .L08046314 @ =gEfxQuakePureVec3
	b .L0804633E
	.align 2, 0
.L08046314: .4byte gEfxQuakePureVec3
.L08046318:
	cmp r6, #3
	bne .L08046324
	ldr r0, .L08046320 @ =gEfxQuakePureVec4
	b .L0804633E
	.align 2, 0
.L08046320: .4byte gEfxQuakePureVec4
.L08046324:
	cmp r6, #4
	bne .L08046330
	ldr r0, .L0804632C @ =gEfxQuakeVec_08111F30
	b .L0804633E
	.align 2, 0
.L0804632C: .4byte gEfxQuakeVec_08111F30
.L08046330:
	cmp r6, #5
	bne .L0804633C
	ldr r0, .L08046338 @ =gEfxQuakeVec_08111FC6
	b .L0804633E
	.align 2, 0
.L08046338: .4byte gEfxQuakeVec_08111FC6
.L0804633C:
	ldr r0, .L08046354 @ =gEfxQuakePureVec1
.L0804633E:
	str r0, [r5, #0x44]
	movs r0, #1
	str r0, [r5, #0x48]
	bl GetEkrDragonStateTypeIdunn
	adds r4, r0, #0
	cmp r4, #0
	beq .L08046358
	movs r0, #0
	str r0, [r5, #0x64]
	b .L08046446
	.align 2, 0
.L08046354: .4byte gEfxQuakePureVec1
.L08046358:
	bl GetBattleAnimArenaFlag
	cmp r0, #0
	beq .L08046364
	str r4, [r5, #0x64]
	b .L08046446
.L08046364:
	ldr r0, .L08046374 @ =gEkrDistanceType
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L08046378
	str r0, [r5, #0x64]
	b .L08046446
	.align 2, 0
.L08046374: .4byte gEkrDistanceType
.L08046378:
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	ldr r1, .L080463A8 @ =gEkrBgPosition
	ldr r1, [r1]
	ldr r2, .L080463AC @ =gEkrXPosBase
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov r0, sb
	bl GetAnimPosition
	cmp r0, #0
	bne .L080463B4
	movs r0, #0x40
	strh r0, [r5, #0x36]
	movs r0, #0x68
	strh r0, [r5, #0x3e]
	ldr r0, .L080463B0 @ =gUnk_085CCE38
	b .L080463BE
	.align 2, 0
.L080463A8: .4byte gEkrBgPosition
.L080463AC: .4byte gEkrXPosBase
.L080463B0: .4byte gUnk_085CCE38
.L080463B4:
	movs r0, #0xb0
	strh r0, [r5, #0x36]
	movs r0, #0x68
	strh r0, [r5, #0x3e]
	ldr r0, .L080463E4 @ =gUnk_085CCDAC
.L080463BE:
	movs r1, #5
	bl BasCreate
	adds r1, r0, #0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r5, #0x36]
	subs r0, r2, r0
	strh r0, [r1, #2]
	ldrh r0, [r5, #0x3e]
	strh r0, [r1, #4]
	ldr r0, .L080463E8 @ =gUnk_Banim_02017754
	ldr r0, [r0]
	cmp r0, #1
	bne .L080463EC
	movs r0, #0xd3
	lsls r0, r0, #6
	b .L080463F0
	.align 2, 0
.L080463E4: .4byte gUnk_085CCDAC
.L080463E8: .4byte gUnk_Banim_02017754
.L080463EC:
	movs r0, #0xf3
	lsls r0, r0, #6
.L080463F0:
	strh r0, [r1, #8]
	str r1, [r5, #0x64]
	ldr r4, .L08046454 @ =gUnk_Banim_02000034
	mov r0, sb
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r1, .L08046458 @ =0x06011800
	movs r2, #0x80
	lsls r2, r2, #4
	bl RegisterDataMove
	ldr r4, .L0804645C @ =gUnk_Banim_02000044
	mov r0, sb
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r1, .L08046460 @ =gPal+0x260
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	ldr r0, .L08046464 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r4, [r0, r1]
	mov r0, sb
	bl GetAnimPosition
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl func_fe6_0804C478
	ldr r0, .L08046468 @ =gEkrBgPosition
	ldr r0, [r0]
	bl func_fe6_08045EE8
.L08046446:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08046454: .4byte gUnk_Banim_02000034
.L08046458: .4byte 0x06011800
.L0804645C: .4byte gUnk_Banim_02000044
.L08046460: .4byte gPal+0x260
.L08046464: .4byte gEkrDistanceType
.L08046468: .4byte gEkrBgPosition

	thumb_func_start EfxHitQuake_Loop
EfxHitQuake_Loop: @ 0x0804646C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r5, [r6, #0x44]
	movs r1, #0x2c
	ldrsh r0, [r6, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, .L080464B4 @ =0x00007FFF
	ldrh r0, [r0]
	cmp r0, r1
	beq .L0804648A
	b .L08046598
.L0804648A:
	ldr r0, .L080464B8 @ =gEkrDistanceType
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080464BC
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L080464DE
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
	b .L080464DE
	.align 2, 0
.L080464B4: .4byte 0x00007FFF
.L080464B8: .4byte gEkrDistanceType
.L080464BC:
	cmp r0, #0
	blt .L080464DE
	cmp r0, #2
	bgt .L080464DE
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L080464D6
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
.L080464D6:
	ldr r0, .L08046580 @ =gEkrBgPosition
	ldr r0, [r0]
	bl func_fe6_08045EE8
.L080464DE:
	ldr r0, [r6, #0x64]
	cmp r0, #0
	beq .L080464EE
	bl BasRemove
	ldr r0, .L08046584 @ =gUnk_Banim_0201E0FC
	bl func_fe6_0804C330
.L080464EE:
	ldr r3, .L08046588 @ =gEkrXPosReal
	movs r4, #0
	ldrsh r2, [r3, r4]
	ldr r0, .L08046580 @ =gEkrBgPosition
	ldr r1, [r0]
	subs r7, r2, r1
	ldr r2, .L0804658C @ =gEkrYPosReal
	movs r5, #2
	ldrsh r0, [r3, r5]
	subs r4, r0, r1
	movs r0, #2
	ldrsh r5, [r2, r0]
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	movs r3, #0
	ldrsh r2, [r2, r3]
	movs r0, #0
	bl SetEkrFrontAnimPostion
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r2, r5, #0
	movs r0, #1
	bl SetEkrFrontAnimPostion
	ldr r1, .L08046590 @ =gUnk_Banim_02017738
	movs r0, #0
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08046576
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L08046542
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
.L08046542:
	ldr r4, .L08046594 @ =gEkrBg0QuakeVec
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #0
	bl SetBgOffset
	ldrh r5, [r4]
	rsbs r0, r5, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r4, #2]
	rsbs r1, r2, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_fe6_0804392C
	ldrh r3, [r4]
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r4, #2]
	rsbs r1, r4, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl func_fe6_08044230
.L08046576:
	adds r0, r6, #0
	bl Proc_End
	b .L08046786
	.align 2, 0
.L08046580: .4byte gEkrBgPosition
.L08046584: .4byte gUnk_Banim_0201E0FC
.L08046588: .4byte gEkrXPosReal
.L0804658C: .4byte gEkrYPosReal
.L08046590: .4byte gUnk_Banim_02017738
.L08046594: .4byte gEkrBg0QuakeVec
.L08046598:
	movs r0, #0x2c
	ldrsh r4, [r6, r0]
	cmp r4, #0
	bne .L080465C4
	ldr r0, [r6, #0x64]
	cmp r0, #0
	beq .L080465C4
	ldr r0, [r6, #0x5c]
	bl GetAnimPosition
	adds r1, r0, #0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	ldr r1, .L0804661C @ =gBg2Tm+0x2C0
	adds r0, r0, r1
	str r4, [sp]
	movs r1, #0xf
	movs r2, #5
	movs r3, #0
	bl FillBGRect
.L080465C4:
	ldr r4, .L08046620 @ =gEkrBg2QuakeVec
	movs r1, #0x2c
	ldrsh r0, [r6, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	strh r0, [r4]
	movs r3, #0x2c
	ldrsh r0, [r6, r3]
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r5, #2
	ldrsh r0, [r0, r5]
	strh r0, [r4, #2]
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	ldr r0, [r6, #0x64]
	cmp r0, #0
	beq .L0804662C
	ldr r0, [r6, #0x5c]
	bl GetAnimPosition
	ldr r1, .L08046624 @ =gEkrBgPosition
	ldr r1, [r1]
	ldr r2, .L08046628 @ =gEkrXPosBase
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	ldr r2, [r6, #0x64]
	ldrh r3, [r6, #0x36]
	ldrh r5, [r4]
	adds r0, r3, r5
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #0x3e]
	ldrh r4, [r4, #2]
	subs r0, r1, r4
	strh r0, [r2, #4]
	b .L08046636
	.align 2, 0
.L0804661C: .4byte gBg2Tm+0x2C0
.L08046620: .4byte gEkrBg2QuakeVec
.L08046624: .4byte gEkrBgPosition
.L08046628: .4byte gEkrXPosBase
.L0804662C:
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #2
	bl SetBgOffset
.L08046636:
	adds r0, r6, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08046696
	ldr r5, .L080466CC @ =gEkrBg2QuakeVec
	ldr r4, .L080466D0 @ =gEkrBg0QuakeVec
	ldrh r2, [r5]
	ldrh r3, [r4]
	adds r1, r2, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r5, #2]
	ldrh r3, [r4, #2]
	adds r2, r0, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	bl SetBgOffset
	ldrh r1, [r5]
	ldrh r2, [r4]
	adds r0, r1, r2
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r5, #2]
	ldrh r2, [r4, #2]
	adds r1, r3, r2
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_fe6_0804392C
	ldrh r3, [r5]
	ldrh r1, [r4]
	adds r0, r3, r1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r5, [r5, #2]
	ldrh r4, [r4, #2]
	adds r1, r5, r4
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl func_fe6_08044230
.L08046696:
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L080466B0
	ldr r0, .L080466CC @ =gEkrBg2QuakeVec
	ldrh r1, [r0]
	ldrh r2, [r0, #2]
	adds r2, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #3
	bl SetBgOffset
.L080466B0:
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L080466D8
	ldr r2, .L080466D4 @ =gEkrXPosReal
	mov ip, r2
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r2, .L080466CC @ =gEkrBg2QuakeVec
	movs r4, #0
	ldrsh r0, [r2, r4]
	subs r1, r1, r0
	b .L080466E8
	.align 2, 0
.L080466CC: .4byte gEkrBg2QuakeVec
.L080466D0: .4byte gEkrBg0QuakeVec
.L080466D4: .4byte gEkrXPosReal
.L080466D8:
	ldr r0, .L08046740 @ =gEkrXPosReal
	mov ip, r0
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, .L08046744 @ =gEkrBg2QuakeVec
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r1, r1, r0
.L080466E8:
	ldr r4, .L08046748 @ =gEkrBgPosition
	ldr r0, [r4]
	subs r7, r1, r0
	ldr r3, .L0804674C @ =gEkrYPosReal
	movs r5, #0
	ldrsh r1, [r3, r5]
	movs r5, #2
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	mov r8, r1
	mov r5, ip
	movs r1, #2
	ldrsh r0, [r5, r1]
	movs r5, #0
	ldrsh r1, [r2, r5]
	adds r0, r0, r1
	ldr r1, [r4]
	subs r4, r0, r1
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	subs r5, r1, r0
	ldr r0, .L08046750 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08046754
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	mov r3, r8
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	movs r0, #0
	bl SetEkrFrontAnimPostion
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl SetEkrFrontAnimPostion
	b .L08046786
	.align 2, 0
.L08046740: .4byte gEkrXPosReal
.L08046744: .4byte gEkrBg2QuakeVec
.L08046748: .4byte gEkrBgPosition
.L0804674C: .4byte gEkrYPosReal
.L08046750: .4byte gEkrDistanceType
.L08046754:
	cmp r0, #0
	blt .L08046786
	cmp r0, #2
	bgt .L08046786
	ldr r0, [r6, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08046778
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	mov r4, r8
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	movs r0, #0
	bl SetEkrFrontAnimPostion
	b .L08046786
.L08046778:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl SetEkrFrontAnimPostion
.L08046786:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
