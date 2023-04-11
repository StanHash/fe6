
	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_08034178
func_fe6_08034178: @ 0x08034178
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x10]
	mov sb, r1
	movs r0, #0
	mov sl, r0
	movs r1, #0
	str r1, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x18]
	movs r5, #0
	str r5, [sp, #0x1c]
	ldr r1, .L080342B0 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L080342A0
	ldr r0, .L080342B4 @ =gActiveUnit
	ldr r0, [r0]
	bl func_fe6_08030CBC
	bl MapMovementMarkFloodEdges
	ldr r0, .L080342B8 @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r7, r0, #1
	cmp r7, #0
	blt .L0803426A
.L080341BE:
	ldr r0, .L080342B8 @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r5, r7, #1
	str r5, [sp, #0x20]
	cmp r4, #0
	blt .L08034264
	lsls r0, r7, #2
	mov r8, r0
.L080341D2:
	ldr r0, .L080342BC @ =gMapMovement
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi .L0803425E
	ldr r0, .L080342C0 @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq .L0803425E
	bl GetUnit
	adds r5, r0, #0
	ldr r1, .L080342B0 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L0803421A
	mov r1, sb
	cmp r1, #0
	beq .L0803421A
	adds r0, r5, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L0803425E
.L0803421A:
	movs r0, #9
	ldrb r2, [r5, #0xa]
	ands r0, r2
	cmp r0, #0
	bne .L0803425E
	movs r0, #8
	ldrsb r0, [r5, r0]
	cmp r0, sl
	blt .L0803425E
	add r6, sp, #0xc
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl func_fe6_08033C8C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0803425E
	ldrb r5, [r5, #8]
	mov sl, r5
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r5, [r0, r1]
	str r5, [sp, #0x14]
	movs r5, #2
	ldrsh r2, [r6, r5]
	str r2, [sp, #0x18]
	ldr r0, .L080342C0 @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
.L0803425E:
	subs r4, #1
	cmp r4, #0
	bge .L080341D2
.L08034264:
	ldr r7, [sp, #0x20]
	cmp r7, #0
	bge .L080341BE
.L0803426A:
	mov r0, sl
	cmp r0, #0
	beq .L080342A0
	add r4, sp, #0xc
	adds r0, r4, #0
	bl func_fe6_080348DC
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080342A0
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	ldr r5, [sp, #0x10]
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	add r2, sp, #0xc
	ldrb r2, [r2]
	str r2, [sp, #4]
	ldrh r2, [r4, #2]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #8]
	movs r2, #5
	bl AiSetDecision
.L080342A0:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080342B0: .4byte gAiSt
.L080342B4: .4byte gActiveUnit
.L080342B8: .4byte gMapSize
.L080342BC: .4byte gMapMovement
.L080342C0: .4byte gMapUnit

	thumb_func_start func_fe6_080342C4
func_fe6_080342C4: @ 0x080342C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x10]
	mov sb, r1
	movs r0, #0
	mov sl, r0
	movs r1, #0
	str r1, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x18]
	movs r4, #0
	str r4, [sp, #0x1c]
	ldr r1, .L080343EC @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L080343DA
	ldr r0, .L080343F0 @ =gActiveUnit
	ldr r0, [r0]
	bl func_fe6_08030CBC
	bl MapMovementMarkFloodEdges
	ldr r0, .L080343F4 @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r7, r0, #1
	cmp r7, #0
	blt .L080343BA
.L0803430A:
	ldr r0, .L080343F4 @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r0, r7, #1
	str r0, [sp, #0x20]
	cmp r4, #0
	blt .L080343B4
	lsls r1, r7, #2
	mov r8, r1
.L0803431E:
	ldr r0, .L080343F8 @ =gMapMovement
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi .L080343AE
	ldr r0, .L080343FC @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080343AE
	bl GetUnit
	adds r5, r0, #0
	ldr r1, .L080343EC @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L08034366
	mov r2, sb
	cmp r2, #0
	beq .L08034366
	adds r0, r5, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L080343AE
.L08034366:
	adds r1, r5, #0
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L080343AE
	movs r0, #8
	ldrsb r0, [r5, r0]
	cmp r0, sl
	blt .L080343AE
	add r6, sp, #0xc
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl func_fe6_08033C8C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080343AE
	ldrb r5, [r5, #8]
	mov sl, r5
	add r0, sp, #0xc
	movs r2, #0
	ldrsh r1, [r0, r2]
	str r1, [sp, #0x14]
	movs r1, #2
	ldrsh r0, [r6, r1]
	str r0, [sp, #0x18]
	ldr r0, .L080343FC @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
.L080343AE:
	subs r4, #1
	cmp r4, #0
	bge .L0803431E
.L080343B4:
	ldr r7, [sp, #0x20]
	cmp r7, #0
	bge .L0803430A
.L080343BA:
	mov r2, sl
	cmp r2, #0
	beq .L080343DA
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	ldr r4, [sp, #0x10]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #5
	bl AiSetDecision
.L080343DA:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080343EC: .4byte gAiSt
.L080343F0: .4byte gActiveUnit
.L080343F4: .4byte gMapSize
.L080343F8: .4byte gMapMovement
.L080343FC: .4byte gMapUnit

	thumb_func_start func_fe6_08034400
func_fe6_08034400: @ 0x08034400
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
.L08034406:
	lsls r0, r6, #1
	adds r1, r5, #0
	adds r1, #0x1c
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	beq .L0803444E
	adds r0, r4, #0
	bl GetItemAttributes
	ldr r1, .L08034444 @ =0x00000405
	ands r1, r0
	cmp r1, #0
	beq .L08034448
	adds r0, r5, #0
	adds r1, r4, #0
	bl CanUnitUseWeapon
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08034440
	adds r0, r5, #0
	adds r1, r4, #0
	bl CanUnitUseStaff
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08034448
.L08034440:
	movs r0, #1
	b .L08034450
	.align 2, 0
.L08034444: .4byte 0x00000405
.L08034448:
	adds r6, #1
	cmp r6, #4
	ble .L08034406
.L0803444E:
	movs r0, #0
.L08034450:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08034458
func_fe6_08034458: @ 0x08034458
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08034474 @ =gActiveUnit
	ldr r0, [r0]
	adds r1, r5, #0
	bl GetOffensiveStaffAccuracy
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #4
	bhi .L08034478
	movs r0, #0
	b .L080344A4
	.align 2, 0
.L08034474: .4byte gActiveUnit
.L08034478:
	adds r0, r5, #0
	bl GetUnitPower
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r5, #0
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq .L080344A2
	bl GetItemAttributes
	movs r1, #2
	ands r1, r0
	cmp r1, #0
	beq .L080344A2
	lsls r0, r4, #0x19
	lsrs r4, r0, #0x18
.L080344A2:
	adds r0, r4, #0
.L080344A4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_080344AC
func_fe6_080344AC: @ 0x080344AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x10]
	mov sl, r1
	movs r0, #0
	str r0, [sp, #0x14]
	movs r1, #0
	str r1, [sp, #0x18]
	movs r2, #0
	str r2, [sp, #0x1c]
	movs r3, #0
	str r3, [sp, #0x20]
	ldr r1, .L08034620 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L080344DC
	b .L08034610
.L080344DC:
	ldr r0, .L08034624 @ =gActiveUnit
	ldr r0, [r0]
	bl func_fe6_08030CBC
	movs r4, #1
	mov sb, r4
.L080344E8:
	mov r0, sb
	bl GetUnit
	adds r6, r0, #0
	cmp r6, #0
	beq .L080345E0
	ldr r0, [r6]
	cmp r0, #0
	beq .L080345E0
	movs r0, #5
	ldrh r1, [r6, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L080345E0
	ldr r1, .L08034620 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L08034524
	mov r2, sl
	cmp r2, #0
	beq .L08034524
	adds r0, r6, #0
	bl _call_via_sl
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080345E0
.L08034524:
	adds r1, r6, #0
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #3
	beq .L080345E0
	adds r0, r6, #0
	bl AiUnitHasAnyStaff
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080345E0
	ldr r3, .L08034624 @ =gActiveUnit
	mov r8, r3
	ldr r0, [r3]
	bl GetUnitMagRange
	mov r4, r8
	ldr r2, [r4]
	ldr r1, [r2, #4]
	ldrb r3, [r2, #0x1a]
	ldrb r1, [r1, #0x12]
	adds r1, r3, r1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0xe
	ldrsb r4, [r2, r4]
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	ldrb r2, [r6, #0xe]
	ldrb r3, [r6, #0xf]
	str r0, [sp]
	adds r0, r4, #0
	bl AiIsWithinRectDistance
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080345E0
	adds r0, r6, #0
	bl func_fe6_08034400
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080345E0
	adds r0, r6, #0
	bl func_fe6_08034458
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq .L080345E0
	ldr r4, [sp, #0x14]
	cmp r7, r4
	blo .L080345E0
	ldr r0, .L08034628 @ =gMapRange
	ldr r0, [r0]
	movs r1, #0
	bl MapFill
	movs r4, #0xe
	ldrsb r4, [r6, r4]
	movs r5, #0xf
	ldrsb r5, [r6, r5]
	mov r1, r8
	ldr r0, [r1]
	bl GetUnitMagRange
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MapAddInRange
	add r4, sp, #0xc
	adds r0, r4, #0
	bl func_fe6_08030AB4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080345E0
	str r7, [sp, #0x14]
	add r0, sp, #0xc
	movs r3, #0
	ldrsh r2, [r0, r3]
	str r2, [sp, #0x18]
	movs r1, #2
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x1c]
	ldrb r6, [r6, #0xb]
	lsls r6, r6, #0x18
	asrs r6, r6, #0x18
	str r6, [sp, #0x20]
.L080345E0:
	movs r2, #1
	add sb, r2
	mov r3, sb
	cmp r3, #0xbf
	bgt .L080345EC
	b .L080344E8
.L080345EC:
	ldr r4, [sp, #0x14]
	cmp r4, #0
	beq .L08034610
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #0x20]
	lsls r3, r2, #0x18
	lsrs r3, r3, #0x18
	ldr r4, [sp, #0x10]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #5
	bl AiSetDecision
.L08034610:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08034620: .4byte gAiSt
.L08034624: .4byte gActiveUnit
.L08034628: .4byte gMapRange

	thumb_func_start func_fe6_0803462C
func_fe6_0803462C: @ 0x0803462C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r0, [sp, #0x10]
	mov sb, r1
	movs r0, #0
	mov sl, r0
	movs r1, #0
	str r1, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x18]
	movs r3, #0
	str r3, [sp, #0x1c]
	ldr r1, .L08034798 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0803465C
	b .L08034786
.L0803465C:
	ldr r0, .L0803479C @ =gActiveUnit
	ldr r0, [r0]
	bl func_fe6_08030CBC
	movs r4, #1
	mov r8, r4
.L08034668:
	mov r0, r8
	bl GetUnit
	adds r6, r0, #0
	cmp r6, #0
	beq .L08034756
	ldr r0, [r6]
	cmp r0, #0
	beq .L08034756
	movs r0, #5
	ldrh r1, [r6, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L08034756
	ldr r1, .L08034798 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L080346A4
	mov r2, sb
	cmp r2, #0
	beq .L080346A4
	adds r0, r6, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08034756
.L080346A4:
	adds r1, r6, #0
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L08034756
	ldr r7, .L0803479C @ =gActiveUnit
	ldr r0, [r7]
	bl GetUnitMagRange
	ldr r2, [r7]
	ldr r1, [r2, #4]
	ldrb r3, [r2, #0x1a]
	ldrb r1, [r1, #0x12]
	adds r1, r3, r1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0xe
	ldrsb r4, [r2, r4]
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	ldrb r2, [r6, #0xe]
	ldrb r3, [r6, #0xf]
	str r0, [sp]
	adds r0, r4, #0
	bl AiIsWithinRectDistance
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08034756
	adds r0, r6, #0
	bl func_fe6_08034400
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08034756
	ldr r0, [r7]
	adds r1, r6, #0
	bl GetOffensiveStaffAccuracy
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #4
	bls .L08034756
	movs r0, #8
	ldrsb r0, [r6, r0]
	adds r0, r1, r0
	cmp r0, sl
	blt .L08034756
	ldr r0, .L080347A0 @ =gMapRange
	ldr r0, [r0]
	movs r1, #0
	bl MapFill
	movs r4, #0xe
	ldrsb r4, [r6, r4]
	movs r5, #0xf
	ldrsb r5, [r6, r5]
	ldr r0, [r7]
	bl GetUnitMagRange
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MapAddInRange
	add r4, sp, #0xc
	adds r0, r4, #0
	bl func_fe6_08030AB4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08034756
	ldrb r0, [r6, #8]
	mov sl, r0
	add r0, sp, #0xc
	movs r2, #0
	ldrsh r1, [r0, r2]
	str r1, [sp, #0x14]
	movs r0, #2
	ldrsh r3, [r4, r0]
	str r3, [sp, #0x18]
	ldrb r6, [r6, #0xb]
	lsls r6, r6, #0x18
	asrs r6, r6, #0x18
	str r6, [sp, #0x1c]
.L08034756:
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #0xbf
	bgt .L08034762
	b .L08034668
.L08034762:
	mov r3, sl
	cmp r3, #0
	beq .L08034786
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	ldr r4, [sp, #0x1c]
	lsls r3, r4, #0x18
	lsrs r3, r3, #0x18
	ldr r4, [sp, #0x10]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #5
	bl AiSetDecision
.L08034786:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08034798: .4byte gAiSt
.L0803479C: .4byte gActiveUnit
.L080347A0: .4byte gMapRange

	thumb_func_start func_fe6_080347A4
func_fe6_080347A4: @ 0x080347A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x10]
	mov sb, r1
	movs r0, #0xff
	mov sl, r0
	movs r1, #0
	str r1, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x18]
	movs r4, #0
	str r4, [sp, #0x1c]
	ldr r1, .L080348C8 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L080348B6
	ldr r0, .L080348CC @ =gActiveUnit
	ldr r0, [r0]
	bl func_fe6_08030CBC
	bl MapMovementMarkFloodEdges
	ldr r0, .L080348D0 @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r7, r0, #1
	cmp r7, #0
	blt .L08034896
.L080347EA:
	ldr r0, .L080348D0 @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r0, r7, #1
	str r0, [sp, #0x20]
	cmp r4, #0
	blt .L08034890
	lsls r1, r7, #2
	mov r8, r1
.L080347FE:
	ldr r0, .L080348D4 @ =gMapMovement
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi .L0803488A
	ldr r0, .L080348D8 @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq .L0803488A
	bl GetUnit
	adds r5, r0, #0
	ldr r1, .L080348C8 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L08034846
	mov r2, sb
	cmp r2, #0
	beq .L08034846
	adds r0, r5, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L0803488A
.L08034846:
	adds r0, r5, #0
	bl GetUnitResistance
	cmp r0, sl
	bgt .L0803488A
	add r6, sp, #0xc
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl func_fe6_08033C8C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0803488A
	adds r0, r5, #0
	bl GetUnitResistance
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	add r0, sp, #0xc
	movs r2, #0
	ldrsh r1, [r0, r2]
	str r1, [sp, #0x14]
	movs r1, #2
	ldrsh r0, [r6, r1]
	str r0, [sp, #0x18]
	ldr r0, .L080348D8 @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
.L0803488A:
	subs r4, #1
	cmp r4, #0
	bge .L080347FE
.L08034890:
	ldr r7, [sp, #0x20]
	cmp r7, #0
	bge .L080347EA
.L08034896:
	mov r2, sl
	cmp r2, #0xff
	beq .L080348B6
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	ldr r4, [sp, #0x10]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #5
	bl AiSetDecision
.L080348B6:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080348C8: .4byte gAiSt
.L080348CC: .4byte gActiveUnit
.L080348D0: .4byte gMapSize
.L080348D4: .4byte gMapMovement
.L080348D8: .4byte gMapUnit

	thumb_func_start func_fe6_080348DC
func_fe6_080348DC: @ 0x080348DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	mov r8, r0
	mov sl, r0
	movs r1, #0
	str r1, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r0, .L080349B0 @ =gActiveUnit
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x34]
	str r0, [sp, #0x10]
	bl GetActiveFactionAlliance
	str r0, [sp, #0x14]
	adds r4, r0, #0
	adds r4, #1
	adds r0, #0x80
	cmp r4, r0
	blt .L08034916
	b .L08034A3A
.L08034916:
	adds r0, r4, #0
	bl GetUnit
	adds r7, r0, #0
	ldr r1, [sp, #0x14]
	adds r1, #0x80
	str r1, [sp, #0x1c]
	adds r4, #1
	str r4, [sp, #0x18]
	cmp r7, #0
	bne .L0803492E
	b .L08034A30
.L0803492E:
	ldr r0, [r7]
	cmp r0, #0
	bne .L08034936
	b .L08034A30
.L08034936:
	movs r0, #0x25
	ldrh r1, [r7, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L08034A30
	adds r0, r7, #0
	bl func_fe6_08035028
	ldr r0, .L080349B4 @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r6, r0, #1
	cmp r6, #0
	blt .L08034A0A
.L08034952:
	ldr r0, .L080349B4 @ =gMapSize
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r4, r0, #1
	subs r0, r6, #1
	mov sb, r0
	cmp r4, #0
	blt .L08034A04
	ldr r3, .L080349B8 @ =gMapRange
	lsls r5, r6, #2
.L08034966:
	ldr r0, [r3]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r2, r0, r4
	ldrb r1, [r2]
	cmp r1, #0x78
	bhi .L080349FE
	ldr r0, .L080349BC @ =gMapUnit
	ldr r0, [r0]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080349C0
	movs r0, #0xb
	ldrsb r0, [r7, r0]
	ldrb r1, [r1]
	str r3, [sp, #0x20]
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	ldr r3, [sp, #0x20]
	cmp r0, #0
	bne .L080349FE
	ldr r0, [r3]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r8, r0
	ble .L080349FE
	ldrb r1, [r1]
	mov r8, r1
	b .L080349FE
	.align 2, 0
.L080349B0: .4byte gActiveUnit
.L080349B4: .4byte gMapSize
.L080349B8: .4byte gMapRange
.L080349BC: .4byte gMapUnit
.L080349C0:
	ldr r0, .L08034A44 @ =gMapTerrain
	ldr r0, [r0]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r1, [sp, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble .L080349FE
	ldr r0, .L08034A48 @ =gMapMovement
	ldr r0, [r0]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x78
	ble .L080349FE
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp sl, r0
	ble .L080349FE
	str r4, [sp, #8]
	str r6, [sp, #0xc]
	ldrb r2, [r2]
	mov sl, r2
.L080349FE:
	subs r4, #1
	cmp r4, #0
	bge .L08034966
.L08034A04:
	mov r6, sb
	cmp r6, #0
	bge .L08034952
.L08034A0A:
	mov r0, r8
	cmp r0, #0xff
	beq .L08034A30
	ldr r1, [sp, #4]
	cmp r1, r8
	blo .L08034A30
	mov r0, sl
	cmp r0, #0xff
	beq .L08034A30
	mov r1, sp
	ldrh r0, [r1, #8]
	ldr r1, [sp]
	strh r0, [r1]
	mov r1, sp
	ldrh r0, [r1, #0xc]
	ldr r1, [sp]
	strh r0, [r1, #2]
	mov r1, r8
	str r1, [sp, #4]
.L08034A30:
	ldr r4, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	cmp r4, r0
	bge .L08034A3A
	b .L08034916
.L08034A3A:
	ldr r1, [sp, #4]
	cmp r1, #0xff
	bne .L08034A4C
	movs r0, #0
	b .L08034A4E
	.align 2, 0
.L08034A44: .4byte gMapTerrain
.L08034A48: .4byte gMapMovement
.L08034A4C:
	movs r0, #1
.L08034A4E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08034A60
func_fe6_08034A60: @ 0x08034A60
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r5, #0
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r6, .L08034AA8 @ =gUnk_0810DB9C
	ldrh r0, [r6]
	cmp r0, #0
	beq .L08034ABE
	movs r4, #0
	adds r2, r6, #0
.L08034A7C:
	ldrh r0, [r2]
	cmp r3, r0
	bne .L08034AB0
	cmp r3, #0x67
	bne .L08034A9C
	ldr r0, .L08034AAC @ =gActiveUnit
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r0, [r0, #4]
	ldr r1, [r1, #0x28]
	ldr r0, [r0, #0x24]
	orrs r1, r0
	movs r0, #4
	ands r1, r0
	cmp r1, #0
	beq .L08034AB6
.L08034A9C:
	ldr r0, [r2, #4]
	cmp r0, #0
	beq .L08034AB0
	adds r0, r5, #0
	b .L08034AC2
	.align 2, 0
.L08034AA8: .4byte gUnk_0810DB9C
.L08034AAC: .4byte gActiveUnit
.L08034AB0:
	adds r4, #8
	adds r2, #8
	adds r5, #1
.L08034AB6:
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08034A7C
.L08034ABE:
	movs r0, #1
	rsbs r0, r0, #0
.L08034AC2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start AiTryDoSpecialItems
AiTryDoSpecialItems: @ 0x08034AC8
	push {r4, r5, r6, lr}
	ldr r1, .L08034ADC @ =gAiSt
	adds r1, #0x7b
	movs r0, #2
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L08034AE0
	movs r0, #0
	b .L08034B52
	.align 2, 0
.L08034ADC: .4byte gAiSt
.L08034AE0:
	movs r5, #0
	ldr r0, .L08034B40 @ =gActiveUnit
	ldr r0, [r0]
	ldrh r4, [r0, #0x1c]
	cmp r4, #0
	beq .L08034B2A
	ldr r6, .L08034B44 @ =gUnk_0810DB9C+0x4
.L08034AEE:
	adds r0, r4, #0
	bl GetItemKind
	cmp r0, #0
	beq .L08034B14
	adds r0, r4, #0
	bl func_fe6_08034A60
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L08034B14
	lsls r0, r1, #3
	adds r0, r0, r6
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
.L08034B14:
	adds r5, #1
	cmp r5, #4
	bgt .L08034B2A
	ldr r0, .L08034B40 @ =gActiveUnit
	ldr r0, [r0]
	lsls r1, r5, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne .L08034AEE
.L08034B2A:
	ldr r0, .L08034B48 @ =gAiSt
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08034B50
	ldr r0, .L08034B4C @ =gAiDecision
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L08034B52
	.align 2, 0
.L08034B40: .4byte gActiveUnit
.L08034B44: .4byte gUnk_0810DB9C+0x4
.L08034B48: .4byte gAiSt
.L08034B4C: .4byte gAiDecision
.L08034B50:
	movs r0, #1
.L08034B52:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08034B58
func_fe6_08034B58: @ 0x08034B58
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r4, .L08034BE0 @ =gAiSt
	adds r0, r4, #0
	adds r0, #0x80
	ldr r0, [r0]
	ldr r1, .L08034BE4 @ =0x80000001
	ands r0, r1
	cmp r0, #0
	beq .L08034BD8
	ldr r0, .L08034BE8 @ =gActiveUnit
	ldr r0, [r0]
	add r6, sp, #0xc
	adds r1, r6, #0
	bl func_fe6_08034D80
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08034BD8
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #2
	ldrsh r1, [r6, r2]
	adds r2, r4, #0
	adds r2, #0x7e
	ldrb r3, [r2]
	movs r2, #1
	str r2, [sp]
	movs r2, #0
	bl AiTryMoveTowards
	ldr r5, .L08034BEC @ =gAiDecision
	movs r4, #0xa
	ldrsb r4, [r5, r4]
	cmp r4, #1
	bne .L08034BD8
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #2
	ldrsh r1, [r6, r2]
	ldrb r2, [r5, #2]
	ldrb r3, [r5, #3]
	str r4, [sp]
	bl AiIsWithinRectDistance
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08034BD8
	ldrb r0, [r5, #2]
	ldrb r1, [r5, #3]
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #6
	movs r3, #0
	bl AiSetDecision
.L08034BD8:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08034BE0: .4byte gAiSt
.L08034BE4: .4byte 0x80000001
.L08034BE8: .4byte gActiveUnit
.L08034BEC: .4byte gAiDecision

	thumb_func_start func_fe6_08034BF0
func_fe6_08034BF0: @ 0x08034BF0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	movs r5, #0
	ldr r6, .L08034C30 @ =gAiSt
	adds r0, r6, #0
	adds r0, #0x80
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq .L08034CAC
	ldr r4, .L08034C34 @ =gActiveUnit
	ldr r0, [r4]
	bl GetUnitItemCount
	cmp r0, #4
	ble .L08034C38
	ldr r2, [r4]
	ldrb r1, [r2, #0xa]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L08034C38
	movs r0, #8
	orrs r0, r1
	strb r0, [r2, #0xa]
	adds r0, r6, #0
	adds r0, #0x79
	strb r5, [r0]
	b .L08034CAC
	.align 2, 0
.L08034C30: .4byte gAiSt
.L08034C34: .4byte gActiveUnit
.L08034C38:
	ldr r4, .L08034CB4 @ =gActiveUnit
	ldr r0, [r4]
	bl GetUnitItemCount
	cmp r0, #4
	ble .L08034C48
	movs r0, #4
	orrs r5, r0
.L08034C48:
	ldr r0, [r4]
	add r6, sp, #0xc
	adds r1, r5, #0
	adds r2, r6, #0
	bl func_fe6_08034DFC
	cmp r0, #1
	bne .L08034CAC
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #2
	ldrsh r1, [r6, r2]
	ldr r2, .L08034CB8 @ =gAiSt
	adds r2, #0x7e
	ldrb r3, [r2]
	movs r5, #0
	str r5, [sp]
	movs r2, #0
	bl AiTryMoveTowards
	ldr r4, .L08034CBC @ =gAiDecision
	ldrb r0, [r4, #0xa]
	cmp r0, #1
	bne .L08034CAC
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #2
	ldrsh r1, [r6, r2]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	str r5, [sp]
	bl AiIsWithinRectDistance
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08034CAC
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	movs r2, #6
	movs r3, #0
	bl AiSetDecision
.L08034CAC:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08034CB4: .4byte gActiveUnit
.L08034CB8: .4byte gAiSt
.L08034CBC: .4byte gAiDecision

	thumb_func_start func_fe6_08034CC0
func_fe6_08034CC0: @ 0x08034CC0
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, .L08034D20 @ =gAiSt
	adds r0, #0x80
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq .L08034D16
	ldr r0, .L08034D24 @ =gActiveUnit
	ldr r2, [r0]
	adds r1, r2, #0
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #1
	bne .L08034D16
	add r4, sp, #0xc
	adds r0, r2, #0
	adds r1, r4, #0
	bl AiFindSafestReachableLocation
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08034D16
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #2
	ldrsh r1, [r4, r2]
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #6
	movs r3, #0
	bl AiSetDecision
.L08034D16:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08034D20: .4byte gAiSt
.L08034D24: .4byte gActiveUnit

	thumb_func_start func_fe6_08034D28
func_fe6_08034D28: @ 0x08034D28
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r1, .L08034D60 @ =gMapRange
	ldr r0, [r1]
	lsls r2, r4, #2
	adds r0, r2, r0
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x77
	bgt .L08034D5C
	ldr r0, .L08034D64 @ =gMapUnit
	ldr r0, [r0]
	adds r0, r2, r0
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r2, [r0]
	cmp r2, #0
	beq .L08034D6C
	ldr r0, .L08034D68 @ =gActiveUnitId
	ldrb r0, [r0]
	cmp r2, r0
	beq .L08034D6C
.L08034D5C:
	movs r0, #0xff
	b .L08034D78
	.align 2, 0
.L08034D60: .4byte gMapRange
.L08034D64: .4byte gMapUnit
.L08034D68: .4byte gActiveUnitId
.L08034D6C:
	ldr r1, [r1]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r0, [r0]
.L08034D78:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08034D80
func_fe6_08034D80: @ 0x08034D80
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl func_fe6_08034FF8
	ldr r0, .L08034DC4 @ =gUnk_085C98F0
	movs r1, #0
	adds r2, r4, #0
	bl AiFindClosestTerrainAdjacentPosition
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08034DCC
	adds r0, r5, #0
	bl func_fe6_08034F34
	movs r1, #2
	ldrsh r0, [r4, r1]
	ldr r1, .L08034DC8 @ =gMapRange
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x77
	bgt .L08034DCC
	movs r0, #1
	b .L08034DCE
	.align 2, 0
.L08034DC4: .4byte gUnk_085C98F0
.L08034DC8: .4byte gMapRange
.L08034DCC:
	movs r0, #0
.L08034DCE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08034DD4
func_fe6_08034DD4: @ 0x08034DD4
	push {r4, lr}
	adds r4, r1, #0
	bl func_fe6_08034F34
	ldr r0, .L08034DF0 @ =gUnk_085C98F2
	movs r1, #0
	adds r2, r4, #0
	bl AiFindClosestTerrainPosition
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08034DF4
	movs r0, #1
	b .L08034DF6
	.align 2, 0
.L08034DF0: .4byte gUnk_085C98F2
.L08034DF4:
	movs r0, #0
.L08034DF6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08034DFC
func_fe6_08034DFC: @ 0x08034DFC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	bl func_fe6_08034F04
	adds r0, r5, #0
	bl func_fe6_08034FC4
	movs r0, #1
	orrs r0, r6
	adds r1, r4, #0
	bl AiFindClosestUnlockPosition
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08034E48
	movs r1, #2
	ldrsh r0, [r4, r1]
	ldr r1, .L08034E44 @ =gMapMovement
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x77
	bgt .L08034E48
.L08034E3E:
	movs r0, #1
	b .L08034E8E
	.align 2, 0
.L08034E44: .4byte gMapMovement
.L08034E48:
	adds r0, r5, #0
	bl func_fe6_08034FF8
	adds r0, r6, #0
	adds r1, r4, #0
	bl AiFindClosestUnlockPosition
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08034E8C
	movs r3, #2
	ldrsh r1, [r4, r3]
	ldr r0, .L08034E94 @ =gMapMovement
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r0, r1, r0
	movs r3, #0
	ldrsh r2, [r4, r3]
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x77
	bgt .L08034E3E
	ldr r0, .L08034E98 @ =gMapUnit
	ldr r0, [r0]
	adds r0, r1, r0
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08034E3E
.L08034E8C:
	movs r0, #0
.L08034E8E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L08034E94: .4byte gMapMovement
.L08034E98: .4byte gMapUnit

	thumb_func_start func_fe6_08034E9C
func_fe6_08034E9C: @ 0x08034E9C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r2, #1
	ldr r3, .L08034EBC @ =gWorkingMovTable
	movs r5, #1
.L08034EA6:
	adds r0, r4, r2
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble .L08034EC0
	adds r0, r2, r3
	strb r1, [r0]
	b .L08034EC4
	.align 2, 0
.L08034EBC: .4byte gWorkingMovTable
.L08034EC0:
	adds r0, r2, r3
	strb r5, [r0]
.L08034EC4:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x32
	bls .L08034EA6
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08034ED4
func_fe6_08034ED4: @ 0x08034ED4
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	movs r2, #1
	ldr r6, .L08034F00 @ =gWorkingMovTable
	adds r4, r6, #0
.L08034EE0:
	adds r1, r2, r4
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x32
	bls .L08034EE0
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08034F00: .4byte gWorkingMovTable

	thumb_func_start func_fe6_08034F04
func_fe6_08034F04: @ 0x08034F04
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r0, .L08034F30 @ =gMapMovement
	ldr r0, [r0]
	bl SetWorkingMap
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	movs r1, #0xf
	ldrsb r1, [r4, r1]
	movs r3, #0xb
	ldrsb r3, [r4, r3]
	movs r2, #0x7c
	bl BeginMapFlood
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08034F30: .4byte gMapMovement

	thumb_func_start func_fe6_08034F34
func_fe6_08034F34: @ 0x08034F34
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r0, .L08034F60 @ =gMapRange
	ldr r0, [r0]
	bl SetWorkingMap
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	movs r1, #0xf
	ldrsb r1, [r4, r1]
	movs r3, #0xb
	ldrsb r3, [r4, r3]
	movs r2, #0x7c
	bl BeginMapFlood
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08034F60: .4byte gMapRange

	thumb_func_start func_fe6_08034F64
func_fe6_08034F64: @ 0x08034F64
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl func_fe6_08034E9C
	ldr r0, .L08034F90 @ =gMapMovement
	ldr r0, [r0]
	bl SetWorkingMap
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	movs r1, #0xf
	ldrsb r1, [r4, r1]
	movs r3, #0xb
	ldrsb r3, [r4, r3]
	movs r2, #0x7c
	bl BeginMapFlood
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08034F90: .4byte gMapMovement

	thumb_func_start func_fe6_08034F94
func_fe6_08034F94: @ 0x08034F94
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl func_fe6_08034E9C
	ldr r0, .L08034FC0 @ =gMapMovement
	ldr r0, [r0]
	bl SetWorkingMap
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	movs r1, #0xf
	ldrsb r1, [r4, r1]
	movs r2, #0x7c
	movs r3, #0
	bl BeginMapFlood
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08034FC0: .4byte gMapMovement

	thumb_func_start func_fe6_08034FC4
func_fe6_08034FC4: @ 0x08034FC4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	movs r1, #0x1e
	bl func_fe6_08034ED4
	ldr r0, .L08034FF4 @ =gMapRange
	ldr r0, [r0]
	bl SetWorkingMap
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	movs r1, #0xf
	ldrsb r1, [r4, r1]
	movs r3, #0xb
	ldrsb r3, [r4, r3]
	movs r2, #0x7c
	bl BeginMapFlood
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08034FF4: .4byte gMapRange

	thumb_func_start func_fe6_08034FF8
func_fe6_08034FF8: @ 0x08034FF8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	movs r1, #0x1e
	bl func_fe6_08034ED4
	ldr r0, .L08035024 @ =gMapRange
	ldr r0, [r0]
	bl SetWorkingMap
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	movs r1, #0xf
	ldrsb r1, [r4, r1]
	movs r2, #0x7c
	movs r3, #0
	bl BeginMapFlood
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08035024: .4byte gMapRange

	thumb_func_start func_fe6_08035028
func_fe6_08035028: @ 0x08035028
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r0, .L08035060 @ =gMapRange
	ldr r0, [r0]
	bl SetWorkingMap
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	movs r1, #0xf
	ldrsb r1, [r4, r1]
	movs r2, #0x1a
	ldrsb r2, [r4, r2]
	ldr r3, [r4, #4]
	ldrb r3, [r3, #0x12]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r2, r2, r3
	movs r3, #0xb
	ldrsb r3, [r4, r3]
	bl BeginMapFlood
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08035060: .4byte gMapRange

	thumb_func_start func_fe6_08035064
func_fe6_08035064: @ 0x08035064
	adds r0, #0x40
	movs r1, #0x80
	lsls r1, r1, #6
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq .L08035084
	ldr r0, .L08035080 @ =gAiSt
	adds r0, #0x7b
	movs r1, #2
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
	b .L08035090
	.align 2, 0
.L08035080: .4byte gAiSt
.L08035084:
	ldr r1, .L08035094 @ =gAiSt
	adds r1, #0x7b
	movs r0, #0xfd
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
.L08035090:
	bx lr
	.align 2, 0
.L08035094: .4byte gAiSt

	thumb_func_start func_fe6_08035098
func_fe6_08035098: @ 0x08035098
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r0, .L080350C4 @ =gMapRange
	ldr r0, [r0]
	bl SetWorkingMap
	movs r3, #0xb
	ldrsb r3, [r4, r3]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x7c
	bl BeginMapFlood
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080350C4: .4byte gMapRange
