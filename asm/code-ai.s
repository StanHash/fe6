
	.include "macro.inc"

	.syntax unified

	thumb_func_start sub_8032DF4
sub_8032DF4: @ 0x08032DF4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	movs r0, #0
	ldr r1, [sp, #0x3c]
	strh r0, [r1]
	ldr r2, [sp, #0x10]
	strh r0, [r2]
	ldr r3, [sp, #0xc]
	strh r0, [r3]
	ldr r0, _08032F38 @ =gMapOther
	ldr r0, [r0]
	movs r1, #0
	bl MapFill
	movs r4, #1
_08032E22:
	adds r0, r4, #0
	bl GetUnit
	adds r5, r0, #0
	adds r4, #1
	str r4, [sp, #0x14]
	cmp r5, #0
	beq _08032F12
	ldr r0, [r5]
	cmp r0, #0
	beq _08032F12
	movs r0, #0x21
	ldrh r7, [r5, #0xc]
	ands r0, r7
	cmp r0, #0
	bne _08032F12
	ldr r0, _08032F3C @ =gActiveUnitId
	ldrb r0, [r0]
	movs r1, #0xb
	ldrsb r1, [r5, r1]
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08032F12
	adds r0, r5, #0
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl sub_8032FF4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08032F12
	adds r0, r5, #0
	bl MapFlood_08019344
	ldr r4, _08032F40 @ =gMapMovement
	ldr r1, [r4]
	ldr r2, [sp, #8]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, [sp, #4]
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08032F12
	adds r0, r5, #0
	mov r1, sp
	bl sub_8033038
	adds r6, r0, #0
	mov r0, sp
	ldrh r0, [r0]
	bl GetItemMinRange
	cmp r0, #1
	ble _08032EA0
	ldr r7, [sp, #0xc]
	ldrh r7, [r7]
	adds r0, r7, r6
	ldr r1, [sp, #0xc]
	strh r0, [r1]
_08032EA0:
	mov r0, sp
	ldrh r0, [r0]
	bl GetItemMaxRange
	cmp r0, #1
	bne _08032EB6
	ldr r2, [sp, #0x10]
	ldrh r2, [r2]
	adds r0, r2, r6
	ldr r3, [sp, #0x10]
	strh r0, [r3]
_08032EB6:
	ldr r1, _08032F44 @ =gMapSize
	movs r7, #2
	ldrsh r0, [r1, r7]
	subs r2, r0, #1
	mov sl, r1
	cmp r2, #0
	blt _08032F12
	mov sb, r4
	ldr r0, _08032F38 @ =gMapOther
	mov r8, r0
_08032ECA:
	mov r1, sl
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r3, r0, #1
	subs r7, r2, #1
	str r7, [sp, #0x18]
	cmp r3, #0
	blt _08032F0C
	lsls r4, r2, #2
	mov r1, sb
	mov r5, r8
	movs r0, #0xff
	mov ip, r0
_08032EE4:
	ldr r0, [r1]
	adds r0, r4, r0
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi _08032F06
	ldr r0, [r5]
	adds r0, r4, r0
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r7, [r0]
	adds r2, r7, r6
	cmp r2, #0xff
	ble _08032F04
	mov r2, ip
_08032F04:
	strb r2, [r0]
_08032F06:
	subs r3, #1
	cmp r3, #0
	bge _08032EE4
_08032F0C:
	ldr r2, [sp, #0x18]
	cmp r2, #0
	bge _08032ECA
_08032F12:
	ldr r4, [sp, #0x14]
	cmp r4, #0xbf
	ble _08032E22
	ldr r3, [sp, #0xc]
	ldrh r7, [r3]
	ldr r3, [sp, #0x10]
	ldrh r3, [r3]
	adds r0, r7, r3
	ldr r7, [sp, #0x3c]
	strh r0, [r7]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08032F38: .4byte gMapOther
_08032F3C: .4byte gActiveUnitId
_08032F40: .4byte gMapMovement
_08032F44: .4byte gMapSize

	thumb_func_start sub_8032F48
sub_8032F48: @ 0x08032F48
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #1
	rsbs r5, r5, #0
	movs r4, #0
	movs r3, #0
	movs r7, #0xff
	lsls r7, r7, #8
_08032F58:
	ldrh r0, [r1]
	cmp r0, #0
	beq _08032F72
	adds r2, r0, #0
	ands r0, r6
	cmp r0, #0
	beq _08032F72
	adds r0, r7, #0
	ands r0, r2
	cmp r0, r4
	bls _08032F72
	adds r4, r0, #0
	adds r5, r3, #0
_08032F72:
	adds r1, #2
	adds r3, #1
	cmp r3, #4
	ble _08032F58
	cmp r5, #0
	ble _08032F88
	ldr r0, _08032F90 @ =gActiveUnit
	ldr r0, [r0]
	adds r1, r5, #0
	bl UnitEquipItemSlot
_08032F88:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08032F90: .4byte gActiveUnit

	thumb_func_start sub_8032F94
sub_8032F94: @ 0x08032F94
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmn r1, r0
	beq _08032FB8
	cmp r1, r0
	blo _08032FB0
	movs r0, #1
	adds r1, r3, #0
	bl sub_8032F48
	b _08032FB8
_08032FB0:
	movs r0, #2
	adds r1, r3, #0
	bl sub_8032F48
_08032FB8:
	pop {r0}
	bx r0

	thumb_func_start sub_8032FBC
sub_8032FBC: @ 0x08032FBC
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIid
	cmp r0, #0x43
	blt _08032FEC
	cmp r0, #0x47
	ble _08032FD4
	cmp r0, #0x4e
	beq _08032FE0
	b _08032FEC
_08032FD4:
	ldr r0, _08032FDC @ =gActiveUnit
	ldr r1, [r0]
	movs r0, #4
	b _08032FE6
	.align 2, 0
_08032FDC: .4byte gActiveUnit
_08032FE0:
	ldr r0, _08032FF0 @ =gActiveUnit
	ldr r1, [r0]
	movs r0, #0x10
_08032FE6:
	ldrb r2, [r1, #0xa]
	orrs r0, r2
	strb r0, [r1, #0xa]
_08032FEC:
	pop {r0}
	bx r0
	.align 2, 0
_08032FF0: .4byte gActiveUnit

	thumb_func_start sub_8032FF4
sub_8032FF4: @ 0x08032FF4
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r0, #0x1a
	ldrsb r0, [r3, r0]
	ldr r1, [r3, #4]
	ldrb r1, [r1, #0x12]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r5, r0, r1
	movs r0, #0xe
	ldrsb r0, [r3, r0]
	subs r1, r4, r0
	cmp r1, #0
	bge _08033014
	subs r1, r0, r4
_08033014:
	movs r0, #0xf
	ldrsb r0, [r3, r0]
	subs r3, r2, r0
	cmp r3, #0
	blt _08033022
	adds r0, r1, r3
	b _08033026
_08033022:
	subs r0, r0, r2
	adds r0, r1, r0
_08033026:
	cmp r5, r0
	bge _0803302E
	movs r0, #0
	b _08033030
_0803302E:
	movs r0, #1
_08033030:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8033038
sub_8033038: @ 0x08033038
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	bl GetUnitEquippedWeapon
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	strh r4, [r6]
	adds r0, r5, #0
	bl GetUnitPower
	adds r5, r0, #0
	adds r0, r4, #0
	bl GetItemMight
	adds r5, r5, r0
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start AiTryDanceOrStealAfterMove
AiTryDanceOrStealAfterMove: @ 0x08033064
	push {r4, lr}
	ldr r4, _0803308C @ =gAiDecision
	ldrb r0, [r4]
	cmp r0, #2
	beq _08033086
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	bl sub_80330C8
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08033086
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	bl sub_80331EC
_08033086:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803308C: .4byte gAiDecision

	thumb_func_start AiTryActionAfterMove
AiTryActionAfterMove: @ 0x08033090
	push {r4, lr}
	ldr r4, _080330C4 @ =gAiDecision
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	bl sub_80330C8
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _080330BC
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	bl sub_80331EC
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _080330BC
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	bl sub_8033250
_080330BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080330C4: .4byte gAiDecision

	thumb_func_start sub_80330C8
sub_80330C8: @ 0x080330C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	str r1, [sp, #0xc]
	movs r0, #0
	mov r8, r0
	mov sb, r0
	ldr r0, _080331A8 @ =gActiveUnit
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, [r1, #0x28]
	ldr r1, [r2, #0x24]
	orrs r0, r1
	movs r1, #0x30
	ands r0, r1
	cmp r0, #0
	beq _080331A4
	ldr r0, _080331AC @ =gMapMovement
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	bl MapFill
	mov r0, sl
	ldr r1, [sp, #0xc]
	movs r2, #1
	movs r3, #1
	bl MapAddInRange
	ldr r0, _080331B0 @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r1, r0, #1
	cmp r1, #0
	blt _0803319E
_08033118:
	ldr r0, _080331B0 @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r7, r1, #1
	cmp r4, #0
	blt _08033198
	lsls r5, r1, #2
_08033128:
	ldr r0, _080331AC @ =gMapMovement
	ldr r0, [r0]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi _08033192
	ldr r6, _080331B4 @ =gMapUnit
	ldr r0, [r6]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033192
	ldr r0, _080331B8 @ =gActiveUnitId
	ldrb r0, [r0]
	ldrb r1, [r1]
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08033192
	ldr r0, [r6]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl GetUnit
	adds r2, r0, #0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r0, [r0, #0x28]
	ldr r1, [r1, #0x24]
	orrs r0, r1
	movs r1, #0x30
	ands r0, r1
	cmp r0, #0
	bne _08033192
	movs r0, #8
	ldrsb r0, [r2, r0]
	cmp r8, r0
	bge _08033192
	ldrb r2, [r2, #8]
	mov r8, r2
	ldr r0, [r6]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	mov sb, r0
_08033192:
	subs r4, #1
	cmp r4, #0
	bge _08033128
_08033198:
	adds r1, r7, #0
	cmp r1, #0
	bge _08033118
_0803319E:
	mov r0, r8
	cmp r0, #0
	bne _080331BC
_080331A4:
	movs r0, #0
	b _080331DA
	.align 2, 0
_080331A8: .4byte gActiveUnit
_080331AC: .4byte gMapMovement
_080331B0: .4byte gMapSize
_080331B4: .4byte gMapUnit
_080331B8: .4byte gActiveUnitId
_080331BC:
	mov r1, sl
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0xc]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #7
	mov r3, sb
	bl AiSetDecision
	movs r0, #1
_080331DA:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_80331EC
sub_80331EC: @ 0x080331EC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _08033240 @ =gActiveUnit
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, [r1, #0x28]
	ldr r1, [r2, #0x24]
	orrs r0, r1
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803323C
	ldr r4, _08033244 @ =gMapMovement
	ldr r0, [r4]
	movs r5, #1
	rsbs r5, r5, #0
	adds r1, r5, #0
	bl MapFill
	ldr r1, [r4]
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r0, r6
	movs r1, #0
	strb r1, [r0]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #1
	movs r3, #0x78
	bl MapAddInRange
	bl AiAttemptStealActionWithinMovement
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r5
	bne _08033248
_0803323C:
	movs r0, #0
	b _0803324A
	.align 2, 0
_08033240: .4byte gActiveUnit
_08033244: .4byte gMapMovement
_08033248:
	movs r0, #1
_0803324A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_8033250
sub_8033250: @ 0x08033250
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	mov sl, r1
	ldr r0, _08033274 @ =gActiveUnit
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	bne _080332A8
	b _0803335E
	.align 2, 0
_08033274: .4byte gActiveUnit
_08033278:
	ldr r0, _080332A4 @ =gActiveUnit
	ldr r0, [r0]
	bl GetUnitEquippedWeaponSlot
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, sb
	asrs r2, r1, #0x10
	mov r3, r8
	asrs r1, r3, #0x10
	ldrb r3, [r5, #0xb]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r2, #0
	movs r2, #1
	bl AiSetDecision
	movs r0, #1
	b _08033360
	.align 2, 0
_080332A4: .4byte gActiveUnit
_080332A8:
	ldr r0, _08033370 @ =gMapMovement
	ldr r0, [r0]
	movs r1, #0
	bl MapFill
	ldr r0, [sp, #0xc]
	lsls r0, r0, #0x10
	mov sb, r0
	asrs r6, r0, #0x10
	mov r1, sl
	lsls r1, r1, #0x10
	mov r8, r1
	asrs r5, r1, #0x10
	adds r0, r7, #0
	bl GetItemMinRange
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r7, #0
	bl GetItemMaxRange
	adds r3, r0, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl MapIncInBoundedRange
	ldr r0, _08033374 @ =gMapSize
	movs r3, #2
	ldrsh r0, [r0, r3]
	subs r7, r0, #1
	cmp r7, #0
	blt _0803335E
_080332F0:
	ldr r0, _08033374 @ =gMapSize
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r4, r0, #1
	cmp r4, #0
	blt _08033358
	lsls r6, r7, #2
_080332FE:
	ldr r0, _08033370 @ =gMapMovement
	ldr r0, [r0]
	adds r0, r6, r0
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08033352
	ldr r5, _08033378 @ =gMapUnit
	ldr r0, [r5]
	adds r0, r6, r0
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033352
	ldr r0, _0803337C @ =gActiveUnitId
	ldrb r0, [r0]
	ldrb r1, [r1]
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08033352
	ldr r0, [r5]
	adds r0, r6, r0
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl GetUnit
	adds r5, r0, #0
	ldr r0, [sp, #0xc]
	mov r1, sl
	adds r2, r5, #0
	bl AiGetInRangeCombatPositionScoreComponent
	cmp r0, #0
	bne _08033278
_08033352:
	subs r4, #1
	cmp r4, #0
	bge _080332FE
_08033358:
	subs r7, #1
	cmp r7, #0
	bge _080332F0
_0803335E:
	movs r0, #0
_08033360:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08033370: .4byte gMapMovement
_08033374: .4byte gMapSize
_08033378: .4byte gMapUnit
_0803337C: .4byte gActiveUnitId

	thumb_func_start sub_8033380
sub_8033380: @ 0x08033380
	ldr r2, _080333A4 @ =gMapUnit
	ldr r2, [r2]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	adds r1, r1, r0
	ldrb r1, [r1]
	cmp r1, #0
	beq _080333A0
	ldr r0, _080333A8 @ =gActiveUnitId
	ldrb r0, [r0]
	eors r0, r1
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	bne _080333AC
_080333A0:
	movs r0, #0
	b _080333AE
	.align 2, 0
_080333A4: .4byte gMapUnit
_080333A8: .4byte gActiveUnitId
_080333AC:
	movs r0, #1
_080333AE:
	bx lr

	thumb_func_start sub_80333B0
sub_80333B0: @ 0x080333B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r7, #0
	ldr r4, _08033448 @ =gActiveUnit
	ldr r0, [r4]
	movs r1, #0x1a
	ldrsb r1, [r0, r1]
	ldr r2, [r0, #4]
	ldrb r2, [r2, #0x12]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r1, r1, r2
	mov r2, r8
	ldrb r2, [r2]
	muls r1, r2, r1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x14
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov r3, r8
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _08033454
	cmp r2, #0
	beq _08033454
	ldr r0, [r4]
	adds r1, r5, #0
	bl AiFloodMovementAndRange
	ldr r0, _0803344C @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt _080334CA
_080333FE:
	ldr r0, _0803344C @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r6, r5, #1
	cmp r4, #0
	blt _0803343E
_0803340C:
	ldr r0, _08033450 @ =gMapRange
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08033438
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_8033380
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08033438
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
_08033438:
	subs r4, #1
	cmp r4, #0
	bge _0803340C
_0803343E:
	adds r5, r6, #0
	cmp r5, #0
	bge _080333FE
	b _080334CA
	.align 2, 0
_08033448: .4byte gActiveUnit
_0803344C: .4byte gMapSize
_08033450: .4byte gMapRange
_08033454:
	ldr r4, _080334E4 @ =gActiveUnit
	ldr r0, [r4]
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r0, _080334E8 @ =gMapRange
	ldr r0, [r0]
	bl SetWorkingMap
	ldr r1, [r4]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	ldrb r1, [r1, #0xf]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r5, #0
	movs r3, #0
	bl BeginMapFlood
	ldr r0, _080334EC @ =gMapSize
	movs r3, #2
	ldrsh r0, [r0, r3]
	subs r5, r0, #1
	cmp r5, #0
	blt _080334CA
_08033488:
	ldr r0, _080334EC @ =gMapSize
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r4, r0, #1
	subs r6, r5, #1
	cmp r4, #0
	blt _080334C4
_08033496:
	ldr r0, _080334E8 @ =gMapRange
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi _080334BE
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_8033380
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080334BE
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
_080334BE:
	subs r4, #1
	cmp r4, #0
	bge _08033496
_080334C4:
	adds r5, r6, #0
	cmp r5, #0
	bge _08033488
_080334CA:
	ldr r0, _080334F0 @ =gAiSt
	adds r0, #0x86
	mov r2, r8
	ldrb r2, [r2, #2]
	adds r0, r2, r0
	strb r7, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080334E4: .4byte gActiveUnit
_080334E8: .4byte gMapRange
_080334EC: .4byte gMapSize
_080334F0: .4byte gAiSt

	thumb_func_start sub_80334F4
sub_80334F4: @ 0x080334F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, _08033590 @ =gActiveUnit
	ldr r0, [r5]
	movs r1, #0x1a
	ldrsb r1, [r0, r1]
	ldr r2, [r0, #4]
	ldrb r2, [r2, #0x12]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r1, r1, r2
	ldrb r2, [r4, #4]
	muls r1, r2, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x14
	str r1, [sp, #4]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldr r2, [r5]
	adds r1, r2, #0
	adds r1, #0x40
	movs r0, #0xfe
	lsls r0, r0, #5
	ldrh r1, [r1]
	ands r0, r1
	lsrs r0, r0, #8
	ldr r1, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r1, [r0]
	mov r8, r1
	ldrb r0, [r0, #1]
	mov sb, r0
	movs r6, #0xe
	ldrsb r6, [r2, r6]
	movs r7, #0xf
	ldrsb r7, [r2, r7]
	strb r1, [r2, #0xe]
	ldr r0, [r5]
	mov r2, sb
	strb r2, [r0, #0xf]
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08033598
	mov r0, sl
	cmp r0, #0
	beq _08033598
	ldr r0, [r5]
	ldr r1, [sp, #4]
	mov r2, sl
	bl AiFloodMovementAndRange
	ldr r0, _08033594 @ =gMapRange
	ldr r1, [r0]
	mov r2, sb
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080335D2
_08033584:
	ldr r0, [r5]
	strb r6, [r0, #0xe]
	ldr r0, [r5]
	strb r7, [r0, #0xf]
	b _08033684
	.align 2, 0
_08033590: .4byte gActiveUnit
_08033594: .4byte gMapRange
_08033598:
	ldr r5, _08033634 @ =gActiveUnit
	ldr r0, [r5]
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r4, _08033638 @ =gMapRange
	ldr r0, [r4]
	bl SetWorkingMap
	ldr r1, [r5]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	ldrb r1, [r1, #0xf]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldr r2, [sp, #4]
	movs r3, #0
	bl BeginMapFlood
	ldr r1, [r4]
	mov r2, sb
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi _08033584
_080335D2:
	ldr r1, _08033634 @ =gActiveUnit
	ldr r0, [r1]
	strb r6, [r0, #0xe]
	ldr r0, [r1]
	strb r7, [r0, #0xf]
	ldr r0, [r1]
	bl MapFlood_08019344
	ldr r1, _0803363C @ =gMapSize
	movs r2, #2
	ldrsh r0, [r1, r2]
	subs r4, r0, #1
	cmp r4, #0
	blt _08033676
_080335EE:
	ldr r1, _0803363C @ =gMapSize
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r2, r0, #1
	subs r0, r4, #1
	mov ip, r0
	cmp r2, #0
	blt _08033670
	ldr r7, _08033640 @ =gMapMovement
	ldr r6, _08033638 @ =gMapRange
	movs r1, #1
	rsbs r1, r1, #0
	adds r5, r1, #0
_08033608:
	mov r0, sl
	cmp r0, #0
	beq _08033644
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r0, [r0]
	adds r3, r0, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0x77
	bgt _08033668
	ldr r0, [r6]
	adds r0, r1, r0
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803366A
	b _08033668
	.align 2, 0
_08033634: .4byte gActiveUnit
_08033638: .4byte gMapRange
_0803363C: .4byte gMapSize
_08033640: .4byte gMapMovement
_08033644:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r0, [r0]
	adds r3, r0, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0x77
	bgt _08033668
	ldr r0, [r6]
	adds r0, r1, r0
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x77
	ble _0803366A
_08033668:
	strb r5, [r3]
_0803366A:
	subs r2, #1
	cmp r2, #0
	bge _08033608
_08033670:
	mov r4, ip
	cmp r4, #0
	bge _080335EE
_08033676:
	ldr r0, _080336A8 @ =AiIsUnitEnemy
	bl AiAttemptCombatWithinMovement
	ldr r0, _080336AC @ =gAiDecision
	ldrb r0, [r0, #0xa]
	cmp r0, #1
	beq _08033694
_08033684:
	mov r0, r8
	mov r1, sb
	movs r2, #1
	str r2, [sp]
	movs r2, #0
	movs r3, #0xff
	bl AiTryMoveTowards
_08033694:
	movs r0, #1
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080336A8: .4byte AiIsUnitEnemy
_080336AC: .4byte gAiDecision

	thumb_func_start sub_80336B0
sub_80336B0: @ 0x080336B0
	ldr r1, _080336C4 @ =gAiSt
	ldr r0, _080336C8 @ =gActiveUnit
	ldr r0, [r0]
	adds r0, #0x46
	ldrb r0, [r0]
	adds r1, #0x86
	strb r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_080336C4: .4byte gAiSt
_080336C8: .4byte gActiveUnit

	thumb_func_start sub_80336CC
sub_80336CC: @ 0x080336CC
	push {r4, r5, lr}
	bl GetActiveFactionAlliance
	adds r4, r0, #1
	adds r0, #0x80
	cmp r4, r0
	bge _080336E8
	adds r5, r0, #0
_080336DC:
	adds r0, r4, #0
	bl GetUnit
	adds r4, #1
	cmp r4, r5
	blt _080336DC
_080336E8:
	ldr r0, _080336F8 @ =gAiSt
	adds r0, #0x79
	movs r1, #0
	strb r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080336F8: .4byte gAiSt

	thumb_func_start sub_80336FC
sub_80336FC: @ 0x080336FC
	push {r4, r5, lr}
	bl GetActiveFactionAlliance
	adds r4, r0, #1
	adds r0, #0x80
	cmp r4, r0
	bge _08033718
	adds r5, r0, #0
_0803370C:
	adds r0, r4, #0
	bl GetUnit
	adds r4, #1
	cmp r4, r5
	blt _0803370C
_08033718:
	ldr r0, _08033728 @ =gAiSt
	adds r0, #0x79
	movs r1, #0
	strb r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08033728: .4byte gAiSt

	thumb_func_start sub_803372C
sub_803372C: @ 0x0803372C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, _08033760 @ =gActiveUnit
	ldr r2, [r7]
	adds r1, r2, #0
	adds r1, #0x40
	movs r0, #0xfe
	lsls r0, r0, #5
	ldrh r1, [r1]
	ands r0, r1
	lsrs r3, r0, #8
	adds r5, r2, #0
	adds r5, #0x46
	ldrb r4, [r5]
	ldr r0, _08033764 @ =gUnk_085C8878
	ldr r1, [r0]
	cmp r1, #0
	beq _0803375A
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	bne _08033768
_0803375A:
	movs r0, #0
	b _080337AA
	.align 2, 0
_08033760: .4byte gActiveUnit
_08033764: .4byte gUnk_085C8878
_08033768:
	lsls r0, r4, #2
	adds r3, r2, r0
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0803377E
	movs r4, #0
	strb r4, [r5]
	adds r3, r2, #0
_0803377E:
	ldrh r0, [r3]
	strh r0, [r6]
	ldrh r0, [r3, #2]
	strh r0, [r6, #2]
	movs r1, #2
	ldrsh r0, [r3, r1]
	ldr r1, _080337B0 @ =gMapMovement
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r3, r2]
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _080337A8
	adds r4, #1
	ldr r0, [r7]
	adds r0, #0x46
	strb r4, [r0]
_080337A8:
	movs r0, #1
_080337AA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080337B0: .4byte gMapMovement

	thumb_func_start sub_80337B4
sub_80337B4: @ 0x080337B4
	push {r4, lr}
	sub sp, #8
	ldr r4, _080337E4 @ =gActiveUnit
	ldr r0, [r4]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080337EC
	ldr r0, [r4]
	bl AiMakeMoveRangeMapsForUnitAndWeapon
	bl AiCountEnemyUnitsInRange
	adds r1, r0, #0
	cmp r1, #0
	beq _080337F2
	ldr r0, _080337E8 @ =gAiSt
	adds r0, #0x86
	strb r1, [r0]
	movs r0, #0
	b _0803381C
	.align 2, 0
_080337E4: .4byte gActiveUnit
_080337E8: .4byte gAiSt
_080337EC:
	ldr r0, [r4]
	bl MapFlood_08019344
_080337F2:
	add r4, sp, #4
	adds r0, r4, #0
	bl sub_803372C
	lsls r0, r0, #0x18
	asrs r2, r0, #0x18
	cmp r2, #1
	beq _08033806
	movs r0, #0
	b _0803381C
_08033806:
	add r0, sp, #4
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #2
	ldrsh r1, [r4, r3]
	str r2, [sp]
	movs r2, #0
	movs r3, #0xff
	bl AiTryMoveTowards
	movs r0, #1
_0803381C:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_8033824
sub_8033824: @ 0x08033824
	adds r1, r0, #0
	ldr r0, _08033850 @ =gActiveUnit
	ldr r0, [r0]
	ldrb r2, [r0, #0xe]
	ldrb r0, [r0, #0xf]
	ldrb r3, [r1]
	cmp r3, r2
	bhi _08033858
	ldrb r3, [r1, #2]
	cmp r3, r2
	blo _08033858
	ldrb r2, [r1, #1]
	cmp r2, r0
	bhi _08033858
	ldrb r1, [r1, #3]
	cmp r1, r0
	blo _08033858
	ldr r0, _08033854 @ =gAiSt
	adds r0, #0x86
	movs r1, #1
	b _0803385E
	.align 2, 0
_08033850: .4byte gActiveUnit
_08033854: .4byte gAiSt
_08033858:
	ldr r0, _08033864 @ =gAiSt
	adds r0, #0x86
	movs r1, #0
_0803385E:
	strb r1, [r0]
	movs r0, #0
	bx lr
	.align 2, 0
_08033864: .4byte gAiSt

	thumb_func_start AiFunc_DecideTalk
AiFunc_DecideTalk: @ 0x08033868
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4]
	bl GetUnitByPid
	ldrb r5, [r0, #0xb]
	ldrb r0, [r4, #1]
	bl GetUnitByPid
	ldrb r3, [r0, #0xb]
	movs r0, #0xff
	str r0, [sp]
	movs r0, #8
	movs r1, #0
	adds r2, r5, #0
	bl AiUpdateDecision
	movs r0, #1
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8033898
sub_8033898: @ 0x08033898
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r5, #0
	ldr r7, _080338D0 @ =gActiveUnitId
	ldrb r0, [r7]
	mov r8, r0
	ldr r4, _080338D4 @ =gActiveUnit
	ldr r6, [r4]
	adds r0, r6, #0
	bl GetUnitLeaderPid
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08033942
	bl GetUnitByPid
	adds r1, r0, #0
	str r1, [r4]
	cmp r1, #0
	bne _080338DC
	str r6, [r4]
	ldr r0, _080338D8 @ =gAiSt
	adds r0, #0x87
	movs r1, #1
	strb r1, [r0]
	b _08033942
	.align 2, 0
_080338D0: .4byte gActiveUnitId
_080338D4: .4byte gActiveUnit
_080338D8: .4byte gAiSt
_080338DC:
	ldrb r0, [r1, #0xb]
	strb r0, [r7]
	adds r0, r1, #0
	adds r0, #0x42
	ldrb r4, [r0]
	adds r0, #1
	ldrb r7, [r0]
_080338EA:
	bl AiTryExecScriptA
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08033900
	adds r5, #1
	cmp r5, #0xff
	ble _080338EA
	bl AiExecFallbackScriptA
_08033900:
	ldr r1, _08033918 @ =gAiDecision
	ldrb r2, [r1, #0xa]
	cmp r2, #1
	bne _08033920
	ldrb r0, [r1]
	cmp r0, #1
	bne _08033920
	ldr r0, _0803391C @ =gAiSt
	ldrb r1, [r1, #6]
	adds r0, #0x86
	b _08033926
	.align 2, 0
_08033918: .4byte gAiDecision
_0803391C: .4byte gAiSt
_08033920:
	ldr r0, _08033950 @ =gAiSt
	adds r0, #0x86
	movs r1, #0
_08033926:
	strb r1, [r0]
	bl AiClearDecision
	ldr r1, _08033954 @ =gActiveUnit
	ldr r0, [r1]
	adds r0, #0x42
	strb r4, [r0]
	ldr r0, [r1]
	adds r0, #0x43
	strb r7, [r0]
	ldr r0, _08033958 @ =gActiveUnitId
	mov r2, r8
	strb r2, [r0]
	str r6, [r1]
_08033942:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08033950: .4byte gAiSt
_08033954: .4byte gActiveUnit
_08033958: .4byte gActiveUnitId

	thumb_func_start sub_803395C
sub_803395C: @ 0x0803395C
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2]
	ldr r0, _08033988 @ =gUnk_Pid_02039694
	ldrb r1, [r1, #4]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08033990
	ldr r0, _0803398C @ =gActiveUnit
	ldr r0, [r0]
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0xb
	ldrsb r1, [r2, r1]
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033990
	movs r0, #1
	b _08033992
	.align 2, 0
_08033988: .4byte gUnk_Pid_02039694
_0803398C: .4byte gActiveUnit
_08033990:
	movs r0, #0
_08033992:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8033998
sub_8033998: @ 0x08033998
	push {lr}
	ldr r2, _080339B8 @ =gUnk_Pid_02039694
	ldrb r1, [r0]
	strb r1, [r2]
	ldrb r0, [r0]
	bl AiUnitWithPidExists
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _080339C0
	ldr r0, _080339BC @ =gAiSt
	adds r0, #0x87
	movs r1, #1
	strb r1, [r0]
	b _080339E6
	.align 2, 0
_080339B8: .4byte gUnk_Pid_02039694
_080339BC: .4byte gAiSt
_080339C0:
	ldr r0, _080339EC @ =sub_803395C
	bl AiAttemptOffensiveAction
	ldr r0, _080339F0 @ =gAiSt
	adds r1, r0, #0
	adds r1, #0x86
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080339F4 @ =gAiDecision
	ldrb r2, [r0, #0xa]
	cmp r2, #1
	bne _080339E2
	ldrb r2, [r0]
	cmp r2, #1
	bne _080339E2
	ldrb r0, [r0, #6]
	strb r0, [r1]
_080339E2:
	bl AiClearDecision
_080339E6:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080339EC: .4byte sub_803395C
_080339F0: .4byte gAiSt
_080339F4: .4byte gAiDecision

	thumb_func_start sub_80339F8
sub_80339F8: @ 0x080339F8
	push {lr}
	movs r1, #0xb
	ldrsb r1, [r0, r1]
	ldr r0, _08033A20 @ =gAiSt
	adds r0, #0x86
	ldrb r0, [r0]
	cmp r1, r0
	bne _08033A28
	ldr r0, _08033A24 @ =gActiveUnit
	ldr r0, [r0]
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033A28
	movs r0, #1
	b _08033A2A
	.align 2, 0
_08033A20: .4byte gAiSt
_08033A24: .4byte gActiveUnit
_08033A28:
	movs r0, #0
_08033A2A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8033A30
sub_8033A30: @ 0x08033A30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _08033A90 @ =gAiSt
	adds r0, #0x86
	ldrb r0, [r0]
	bl GetUnit
	movs r2, #0xe
	ldrsb r2, [r0, r2]
	ldr r1, _08033A94 @ =gActiveUnit
	ldr r1, [r1]
	movs r3, #0xe
	ldrsb r3, [r1, r3]
	subs r7, r2, r3
	ldrb r0, [r0, #0xf]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r2, #0xf
	ldrsb r2, [r1, r2]
	subs r0, r0, r2
	mov r8, r0
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	subs r5, r0, r3
	movs r0, #0xf
	ldrsb r0, [r4, r0]
	subs r6, r0, r2
	movs r0, #0xb
	ldrsb r0, [r1, r0]
	movs r1, #0xb
	ldrsb r1, [r4, r1]
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033A98
	adds r0, r7, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _08033A98
	mov r0, r8
	muls r0, r6, r0
	cmp r0, #0
	blt _08033A98
	movs r0, #1
	b _08033A9A
	.align 2, 0
_08033A90: .4byte gAiSt
_08033A94: .4byte gActiveUnit
_08033A98:
	movs r0, #0
_08033A9A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_8033AA4
sub_8033AA4: @ 0x08033AA4
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _08033AF4 @ =gAiSt
	adds r1, r0, #0
	adds r1, #0x86
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033AEA
	ldrb r0, [r1]
	bl GetUnit
	adds r4, r0, #0
	ldr r0, _08033AF8 @ =sub_80339F8
	bl AiAttemptOffensiveAction
	ldr r5, _08033AFC @ =gAiDecision
	ldrb r0, [r5, #0xa]
	cmp r0, #1
	beq _08033AEA
	ldr r0, _08033B00 @ =sub_8033A30
	bl AiAttemptOffensiveAction
	ldrb r5, [r5, #0xa]
	cmp r5, #1
	beq _08033AEA
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	movs r1, #0xf
	ldrsb r1, [r4, r1]
	movs r2, #1
	str r2, [sp]
	movs r2, #0
	movs r3, #0xff
	bl AiTryMoveTowards
_08033AEA:
	movs r0, #1
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08033AF4: .4byte gAiSt
_08033AF8: .4byte sub_80339F8
_08033AFC: .4byte gAiDecision
_08033B00: .4byte sub_8033A30

	thumb_func_start sub_8033B04
sub_8033B04: @ 0x08033B04
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x64
	bl RandNext
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _08033B38 @ =gAiSt
	ldrb r2, [r4, #1]
	adds r1, r3, #0
	adds r1, #0x7c
	strb r2, [r1]
	ldrb r4, [r4]
	cmp r0, r4
	bhi _08033B40
	ldr r4, _08033B3C @ =AiIsUnitEnemy
	adds r0, r4, #0
	bl sub_8033C04
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033B48
	adds r0, r4, #0
	bl AiAttemptOffensiveAction
	b _08033B48
	.align 2, 0
_08033B38: .4byte gAiSt
_08033B3C: .4byte AiIsUnitEnemy
_08033B40:
	adds r1, r3, #0
	adds r1, #0x79
	movs r0, #4
	strb r0, [r1]
_08033B48:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_8033B50
sub_8033B50: @ 0x08033B50
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x64
	bl RandNext
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	ldrb r0, [r5]
	cmp r4, r0
	bhi _08033B88
	bl AiTryDoSpecialItems
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033B90
	movs r0, #0x64
	bl RandNext
	ldrb r5, [r5, #1]
	cmp r4, r5
	bhi _08033B90
	ldr r0, _08033B84 @ =AiIsUnitEnemy
	bl AiAttemptOffensiveAction
	b _08033B90
	.align 2, 0
_08033B84: .4byte AiIsUnitEnemy
_08033B88:
	ldr r0, _08033B98 @ =gAiSt
	adds r0, #0x79
	movs r1, #4
	strb r1, [r0]
_08033B90:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08033B98: .4byte gAiSt

	thumb_func_start sub_8033B9C
sub_8033B9C: @ 0x08033B9C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r5, #0
	ldr r0, _08033BB8 @ =gActiveUnit
	ldr r0, [r0]
	adds r1, r4, #0
	bl CanUnitUseStaff
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033BC0
	b _08033BF4
	.align 2, 0
_08033BB8: .4byte gActiveUnit
_08033BBC:
	adds r0, r5, #0
	b _08033BF8
_08033BC0:
	adds r0, r4, #0
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r4, _08033C00 @ =gUnk_0810DB34
	ldrh r0, [r4]
	cmp r0, #0
	beq _08033BF4
	movs r3, #0
	adds r2, r4, #4
	adds r1, r4, #0
_08033BD8:
	ldrh r0, [r1]
	cmp r6, r0
	bne _08033BE4
	ldr r0, [r2]
	cmp r0, #0
	bne _08033BBC
_08033BE4:
	adds r3, #8
	adds r2, #8
	adds r1, #8
	adds r5, #1
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _08033BD8
_08033BF4:
	movs r0, #1
	rsbs r0, r0, #0
_08033BF8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08033C00: .4byte gUnk_0810DB34

	thumb_func_start sub_8033C04
sub_8033C04: @ 0x08033C04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r6, #0
	movs r5, #0
	ldr r0, _08033C80 @ =gActiveUnit
	ldr r0, [r0]
	ldrh r4, [r0, #0x1c]
	cmp r4, #0
	beq _08033C6C
	ldr r0, _08033C84 @ =gUnk_0810DB34+0x4
	mov r8, r0
_08033C1E:
	adds r0, r4, #0
	bl GetItemAttributes
	adds r0, r4, #0
	bl GetItemRequiredExp
	cmp r0, r6
	blt _08033C56
	adds r0, r4, #0
	bl sub_8033B9C
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08033C56
	lsls r0, r1, #3
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r7, #0
	bl _call_via_r2
	adds r0, r4, #0
	bl GetItemRequiredExp
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_08033C56:
	adds r5, #1
	cmp r5, #4
	bgt _08033C6C
	ldr r0, _08033C80 @ =gActiveUnit
	ldr r0, [r0]
	lsls r1, r5, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _08033C1E
_08033C6C:
	ldr r0, _08033C88 @ =gAiDecision
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08033C80: .4byte gActiveUnit
_08033C84: .4byte gUnk_0810DB34+0x4
_08033C88: .4byte gAiDecision

	thumb_func_start sub_8033C8C
sub_8033C8C: @ 0x08033C8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	str r1, [sp, #4]
	mov r8, r2
	movs r0, #0
	mov sl, r0
	ldr r2, _08033D30 @ =gUnk_085C98D0
	movs r1, #3
	mov sb, r1
_08033CA8:
	ldr r0, [r2]
	ldr r1, [sp]
	adds r5, r1, r0
	ldr r0, [r2, #4]
	ldr r1, [sp, #4]
	adds r7, r1, r0
	ldr r0, _08033D34 @ =gMapMovement
	ldr r0, [r0]
	lsls r6, r7, #2
	adds r0, r6, r0
	ldr r0, [r0]
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0x77
	bhi _08033D16
	ldr r0, _08033D38 @ =gMapUnit
	ldr r0, [r0]
	adds r0, r6, r0
	ldr r0, [r0]
	adds r0, r0, r5
	ldrb r1, [r0]
	cmp r1, #0
	beq _08033CDE
	ldr r0, _08033D3C @ =gActiveUnitId
	ldrb r0, [r0]
	cmp r1, r0
	bne _08033D16
_08033CDE:
	adds r0, r5, #0
	adds r1, r7, #0
	str r2, [sp, #8]
	bl AiGetTerrainCombatPositionScoreComponent
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r7, #0
	bl AiGetFriendZoneCombatPositionScoreComponent
	adds r4, r4, r0
	ldr r0, _08033D40 @ =gMapOther
	ldr r0, [r0]
	adds r0, r6, r0
	ldr r0, [r0]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsrs r0, r0, #3
	subs r4, r4, r0
	ldr r0, _08033D44 @ =0x7FFFFFFF
	adds r4, r4, r0
	ldr r2, [sp, #8]
	cmp sl, r4
	bhs _08033D16
	mov r1, r8
	strh r5, [r1]
	strh r7, [r1, #2]
	mov sl, r4
_08033D16:
	adds r2, #8
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _08033CA8
	mov r0, sl
	cmp r0, #0
	bne _08033D48
	movs r0, #0
	b _08033D4A
	.align 2, 0
_08033D30: .4byte gUnk_085C98D0
_08033D34: .4byte gMapMovement
_08033D38: .4byte gMapUnit
_08033D3C: .4byte gActiveUnitId
_08033D40: .4byte gMapOther
_08033D44: .4byte 0x7FFFFFFF
_08033D48:
	movs r0, #1
_08033D4A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8033D5C
sub_8033D5C: @ 0x08033D5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x10]
	mov sb, r1
	movs r0, #0x64
	mov sl, r0
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x18]
	str r1, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x1c]
	ldr r0, _08033EAC @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
	bl MapMovementMarkFloodEdges
	ldr r0, _08033EB0 @ =gAiSt
	adds r1, r0, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033D98
	adds r1, r0, #0
	mov sl, r1
_08033D98:
	ldr r0, _08033EB4 @ =gMapSize
	movs r4, #2
	ldrsh r0, [r0, r4]
	subs r7, r0, #1
	cmp r7, #0
	blt _08033E78
_08033DA4:
	ldr r0, _08033EB4 @ =gMapSize
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r6, r0, #1
	subs r2, r7, #1
	str r2, [sp, #0x20]
	cmp r6, #0
	blt _08033E72
	lsls r4, r7, #2
	mov r8, r4
_08033DB8:
	ldr r0, _08033EB8 @ =gMapMovement
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi _08033E6C
	ldr r0, _08033EBC @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r2, r0, r6
	ldrb r1, [r2]
	cmp r1, #0
	beq _08033E6C
	ldr r0, _08033EC0 @ =gActiveUnitId
	ldrb r0, [r0]
	cmp r1, r0
	beq _08033E6C
	adds r0, r1, #0
	bl GetUnit
	adds r5, r0, #0
	movs r0, #4
	ldr r1, _08033EC4 @ =gAiSt+0x7B
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08033E08
	mov r2, sb
	cmp r2, #0
	beq _08033E08
	adds r0, r5, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08033E6C
_08033E08:
	ldr r4, _08033EC8 @ =gAiSt+0x7C
	ldrb r0, [r4]
	cmp r0, #0
	bne _08033E1A
	movs r0, #1
	ldrb r1, [r5, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _08033E6C
_08033E1A:
	adds r0, r5, #0
	bl GetUnitCurrentHp
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	adds r0, r5, #0
	bl GetUnitMaxHp
	adds r1, r0, #0
	adds r0, r4, #0
	bl Div
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, sl
	bhi _08033E6C
	add r5, sp, #0xc
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl sub_8033C8C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08033E6C
	mov sl, r4
	add r0, sp, #0xc
	movs r4, #0
	ldrsh r2, [r0, r4]
	str r2, [sp, #0x14]
	movs r1, #2
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x18]
	ldr r0, _08033EBC @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r6
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
_08033E6C:
	subs r6, #1
	cmp r6, #0
	bge _08033DB8
_08033E72:
	ldr r7, [sp, #0x20]
	cmp r7, #0
	bge _08033DA4
_08033E78:
	movs r0, #1
	rsbs r0, r0, #0
	ldr r2, [sp, #0x14]
	cmp r2, r0
	beq _08033E9C
	adds r0, r2, #0
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
_08033E9C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033EAC: .4byte gActiveUnit
_08033EB0: .4byte gAiSt
_08033EB4: .4byte gMapSize
_08033EB8: .4byte gMapMovement
_08033EBC: .4byte gMapUnit
_08033EC0: .4byte gActiveUnitId
_08033EC4: .4byte gAiSt+0x7B
_08033EC8: .4byte gAiSt+0x7C

	thumb_func_start sub_8033ECC
sub_8033ECC: @ 0x08033ECC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r0, [sp, #0x10]
	mov sb, r1
	movs r0, #0x64
	mov sl, r0
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x18]
	str r1, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x1c]
	ldr r4, _08034078 @ =gAiSt
	adds r5, r4, #0
	adds r5, #0x7b
	movs r0, #4
	ldrb r3, [r5]
	ands r0, r3
	cmp r0, #0
	beq _08033EFE
	b _08034066
_08033EFE:
	ldr r0, _0803407C @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
	adds r1, r4, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033F14
	adds r4, r0, #0
	mov sl, r4
_08033F14:
	movs r0, #1
	mov r8, r0
_08033F18:
	mov r0, r8
	bl GetUnit
	adds r6, r0, #0
	cmp r6, #0
	bne _08033F26
	b _08034036
_08033F26:
	ldr r0, [r6]
	cmp r0, #0
	bne _08033F2E
	b _08034036
_08033F2E:
	movs r1, #0xf
	ldrsb r1, [r6, r1]
	ldr r0, _08034080 @ =gMapUnit
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r2, #0xe
	ldrsb r2, [r6, r2]
	ldr r0, [r1]
	adds r0, r0, r2
	ldr r1, _08034084 @ =gActiveUnitId
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _08034036
	movs r0, #5
	ldrh r1, [r6, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _08034036
	movs r0, #4
	ldr r2, _08034088 @ =gAiSt+0x7B
	ldrb r2, [r2]
	ands r0, r2
	cmp r0, #0
	bne _08033F76
	mov r3, sb
	cmp r3, #0
	beq _08033F76
	adds r0, r6, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08034036
_08033F76:
	ldr r4, _0803408C @ =gAiSt+0x7C
	ldrb r0, [r4]
	cmp r0, #0
	bne _08033F88
	movs r0, #1
	ldrb r1, [r6, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _08034036
_08033F88:
	ldr r7, _0803407C @ =gActiveUnit
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
	beq _08034036
	ldr r0, _08034090 @ =gMapRange
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
	add r5, sp, #0xc
	adds r0, r5, #0
	bl sub_8030AB4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08034036
	adds r0, r6, #0
	bl GetUnitCurrentHp
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	adds r0, r6, #0
	bl GetUnitMaxHp
	adds r1, r0, #0
	adds r0, r4, #0
	bl Div
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, sl
	bhi _08034036
	mov sl, r0
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r4, [r0, r1]
	str r4, [sp, #0x14]
	movs r3, #2
	ldrsh r2, [r5, r3]
	str r2, [sp, #0x18]
	movs r1, #0xf
	ldrsb r1, [r6, r1]
	ldr r0, _08034080 @ =gMapUnit
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r2, #0xe
	ldrsb r2, [r6, r2]
	ldr r0, [r1]
	adds r0, r0, r2
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
_08034036:
	movs r4, #1
	add r8, r4
	mov r0, r8
	cmp r0, #0xbf
	bgt _08034042
	b _08033F18
_08034042:
	movs r0, #1
	rsbs r0, r0, #0
	ldr r1, [sp, #0x14]
	cmp r1, r0
	beq _08034066
	adds r0, r1, #0
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
_08034066:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034078: .4byte gAiSt
_0803407C: .4byte gActiveUnit
_08034080: .4byte gMapUnit
_08034084: .4byte gActiveUnitId
_08034088: .4byte gAiSt+0x7B
_0803408C: .4byte gAiSt+0x7C
_08034090: .4byte gMapRange

	thumb_func_start sub_8034094
sub_8034094: @ 0x08034094
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	movs r7, #0
	movs r0, #0
	mov r8, r0
	mov sb, r0
	ldr r1, _08034164 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08034152
	bl sub_8030B94
	cmp r0, #2
	ble _08034152
	ldr r0, _08034168 @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
	ldr r0, _0803416C @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt _0803412C
_080340D4:
	ldr r0, _0803416C @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r6, r5, #1
	cmp r4, #0
	blt _08034126
_080340E2:
	ldr r0, _08034170 @ =gMapMovement
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi _08034120
	ldr r0, _08034174 @ =gMapRange
	ldr r0, [r0]
	movs r1, #0
	bl MapFill
	ldr r0, _08034168 @ =gActiveUnit
	ldr r0, [r0]
	bl GetUnitMagRange
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MapAddInRange
	bl sub_8030BDC
	cmp r0, r7
	ble _08034120
	adds r7, r0, #0
	mov r8, r4
	mov sb, r5
_08034120:
	subs r4, #1
	cmp r4, #0
	bge _080340E2
_08034126:
	adds r5, r6, #0
	cmp r5, #0
	bge _080340D4
_0803412C:
	cmp r7, #1
	ble _08034152
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	mov r2, sb
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	mov r3, sl
	lsls r2, r3, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #5
	movs r3, #0
	bl AiSetDecision
_08034152:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034164: .4byte gAiSt
_08034168: .4byte gActiveUnit
_0803416C: .4byte gMapSize
_08034170: .4byte gMapMovement
_08034174: .4byte gMapRange

	thumb_func_start sub_8034178
sub_8034178: @ 0x08034178
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
	ldr r1, _080342B0 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _080342A0
	ldr r0, _080342B4 @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
	bl MapMovementMarkFloodEdges
	ldr r0, _080342B8 @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r7, r0, #1
	cmp r7, #0
	blt _0803426A
_080341BE:
	ldr r0, _080342B8 @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r5, r7, #1
	str r5, [sp, #0x20]
	cmp r4, #0
	blt _08034264
	lsls r0, r7, #2
	mov r8, r0
_080341D2:
	ldr r0, _080342BC @ =gMapMovement
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi _0803425E
	ldr r0, _080342C0 @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803425E
	bl GetUnit
	adds r5, r0, #0
	ldr r1, _080342B0 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0803421A
	mov r1, sb
	cmp r1, #0
	beq _0803421A
	adds r0, r5, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0803425E
_0803421A:
	movs r0, #9
	ldrb r2, [r5, #0xa]
	ands r0, r2
	cmp r0, #0
	bne _0803425E
	movs r0, #8
	ldrsb r0, [r5, r0]
	cmp r0, sl
	blt _0803425E
	add r6, sp, #0xc
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl sub_8033C8C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803425E
	ldrb r5, [r5, #8]
	mov sl, r5
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r5, [r0, r1]
	str r5, [sp, #0x14]
	movs r5, #2
	ldrsh r2, [r6, r5]
	str r2, [sp, #0x18]
	ldr r0, _080342C0 @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
_0803425E:
	subs r4, #1
	cmp r4, #0
	bge _080341D2
_08034264:
	ldr r7, [sp, #0x20]
	cmp r7, #0
	bge _080341BE
_0803426A:
	mov r0, sl
	cmp r0, #0
	beq _080342A0
	add r4, sp, #0xc
	adds r0, r4, #0
	bl sub_80348DC
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080342A0
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
_080342A0:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080342B0: .4byte gAiSt
_080342B4: .4byte gActiveUnit
_080342B8: .4byte gMapSize
_080342BC: .4byte gMapMovement
_080342C0: .4byte gMapUnit

	thumb_func_start sub_80342C4
sub_80342C4: @ 0x080342C4
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
	ldr r1, _080343EC @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _080343DA
	ldr r0, _080343F0 @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
	bl MapMovementMarkFloodEdges
	ldr r0, _080343F4 @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r7, r0, #1
	cmp r7, #0
	blt _080343BA
_0803430A:
	ldr r0, _080343F4 @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r0, r7, #1
	str r0, [sp, #0x20]
	cmp r4, #0
	blt _080343B4
	lsls r1, r7, #2
	mov r8, r1
_0803431E:
	ldr r0, _080343F8 @ =gMapMovement
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi _080343AE
	ldr r0, _080343FC @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _080343AE
	bl GetUnit
	adds r5, r0, #0
	ldr r1, _080343EC @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08034366
	mov r2, sb
	cmp r2, #0
	beq _08034366
	adds r0, r5, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _080343AE
_08034366:
	adds r1, r5, #0
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _080343AE
	movs r0, #8
	ldrsb r0, [r5, r0]
	cmp r0, sl
	blt _080343AE
	add r6, sp, #0xc
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl sub_8033C8C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080343AE
	ldrb r5, [r5, #8]
	mov sl, r5
	add r0, sp, #0xc
	movs r2, #0
	ldrsh r1, [r0, r2]
	str r1, [sp, #0x14]
	movs r1, #2
	ldrsh r0, [r6, r1]
	str r0, [sp, #0x18]
	ldr r0, _080343FC @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
_080343AE:
	subs r4, #1
	cmp r4, #0
	bge _0803431E
_080343B4:
	ldr r7, [sp, #0x20]
	cmp r7, #0
	bge _0803430A
_080343BA:
	mov r2, sl
	cmp r2, #0
	beq _080343DA
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
_080343DA:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080343EC: .4byte gAiSt
_080343F0: .4byte gActiveUnit
_080343F4: .4byte gMapSize
_080343F8: .4byte gMapMovement
_080343FC: .4byte gMapUnit

	thumb_func_start sub_8034400
sub_8034400: @ 0x08034400
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
_08034406:
	lsls r0, r6, #1
	adds r1, r5, #0
	adds r1, #0x1c
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	beq _0803444E
	adds r0, r4, #0
	bl GetItemAttributes
	ldr r1, _08034444 @ =0x00000405
	ands r1, r0
	cmp r1, #0
	beq _08034448
	adds r0, r5, #0
	adds r1, r4, #0
	bl CanUnitUseWeapon
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034440
	adds r0, r5, #0
	adds r1, r4, #0
	bl CanUnitUseStaff
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08034448
_08034440:
	movs r0, #1
	b _08034450
	.align 2, 0
_08034444: .4byte 0x00000405
_08034448:
	adds r6, #1
	cmp r6, #4
	ble _08034406
_0803444E:
	movs r0, #0
_08034450:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8034458
sub_8034458: @ 0x08034458
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08034474 @ =gActiveUnit
	ldr r0, [r0]
	adds r1, r5, #0
	bl GetOffensiveStaffAccuracy
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #4
	bhi _08034478
	movs r0, #0
	b _080344A4
	.align 2, 0
_08034474: .4byte gActiveUnit
_08034478:
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
	beq _080344A2
	bl GetItemAttributes
	movs r1, #2
	ands r1, r0
	cmp r1, #0
	beq _080344A2
	lsls r0, r4, #0x19
	lsrs r4, r0, #0x18
_080344A2:
	adds r0, r4, #0
_080344A4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_80344AC
sub_80344AC: @ 0x080344AC
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
	ldr r1, _08034620 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _080344DC
	b _08034610
_080344DC:
	ldr r0, _08034624 @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
	movs r4, #1
	mov sb, r4
_080344E8:
	mov r0, sb
	bl GetUnit
	adds r6, r0, #0
	cmp r6, #0
	beq _080345E0
	ldr r0, [r6]
	cmp r0, #0
	beq _080345E0
	movs r0, #5
	ldrh r1, [r6, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _080345E0
	ldr r1, _08034620 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08034524
	mov r2, sl
	cmp r2, #0
	beq _08034524
	adds r0, r6, #0
	bl _call_via_sl
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080345E0
_08034524:
	adds r1, r6, #0
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #3
	beq _080345E0
	adds r0, r6, #0
	bl AiUnitHasAnyStaff
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080345E0
	ldr r3, _08034624 @ =gActiveUnit
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
	beq _080345E0
	adds r0, r6, #0
	bl sub_8034400
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080345E0
	adds r0, r6, #0
	bl sub_8034458
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _080345E0
	ldr r4, [sp, #0x14]
	cmp r7, r4
	blo _080345E0
	ldr r0, _08034628 @ =gMapRange
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
	bl sub_8030AB4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080345E0
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
_080345E0:
	movs r2, #1
	add sb, r2
	mov r3, sb
	cmp r3, #0xbf
	bgt _080345EC
	b _080344E8
_080345EC:
	ldr r4, [sp, #0x14]
	cmp r4, #0
	beq _08034610
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
_08034610:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034620: .4byte gAiSt
_08034624: .4byte gActiveUnit
_08034628: .4byte gMapRange

	thumb_func_start sub_803462C
sub_803462C: @ 0x0803462C
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
	ldr r1, _08034798 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _0803465C
	b _08034786
_0803465C:
	ldr r0, _0803479C @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
	movs r4, #1
	mov r8, r4
_08034668:
	mov r0, r8
	bl GetUnit
	adds r6, r0, #0
	cmp r6, #0
	beq _08034756
	ldr r0, [r6]
	cmp r0, #0
	beq _08034756
	movs r0, #5
	ldrh r1, [r6, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _08034756
	ldr r1, _08034798 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _080346A4
	mov r2, sb
	cmp r2, #0
	beq _080346A4
	adds r0, r6, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08034756
_080346A4:
	adds r1, r6, #0
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08034756
	ldr r7, _0803479C @ =gActiveUnit
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
	beq _08034756
	adds r0, r6, #0
	bl sub_8034400
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08034756
	ldr r0, [r7]
	adds r1, r6, #0
	bl GetOffensiveStaffAccuracy
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #4
	bls _08034756
	movs r0, #8
	ldrsb r0, [r6, r0]
	adds r0, r1, r0
	cmp r0, sl
	blt _08034756
	ldr r0, _080347A0 @ =gMapRange
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
	bl sub_8030AB4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08034756
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
_08034756:
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #0xbf
	bgt _08034762
	b _08034668
_08034762:
	mov r3, sl
	cmp r3, #0
	beq _08034786
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
_08034786:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034798: .4byte gAiSt
_0803479C: .4byte gActiveUnit
_080347A0: .4byte gMapRange

	thumb_func_start sub_80347A4
sub_80347A4: @ 0x080347A4
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
	ldr r1, _080348C8 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _080348B6
	ldr r0, _080348CC @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
	bl MapMovementMarkFloodEdges
	ldr r0, _080348D0 @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r7, r0, #1
	cmp r7, #0
	blt _08034896
_080347EA:
	ldr r0, _080348D0 @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r0, r7, #1
	str r0, [sp, #0x20]
	cmp r4, #0
	blt _08034890
	lsls r1, r7, #2
	mov r8, r1
_080347FE:
	ldr r0, _080348D4 @ =gMapMovement
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi _0803488A
	ldr r0, _080348D8 @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803488A
	bl GetUnit
	adds r5, r0, #0
	ldr r1, _080348C8 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08034846
	mov r2, sb
	cmp r2, #0
	beq _08034846
	adds r0, r5, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0803488A
_08034846:
	adds r0, r5, #0
	bl GetUnitResistance
	cmp r0, sl
	bgt _0803488A
	add r6, sp, #0xc
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl sub_8033C8C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803488A
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
	ldr r0, _080348D8 @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
_0803488A:
	subs r4, #1
	cmp r4, #0
	bge _080347FE
_08034890:
	ldr r7, [sp, #0x20]
	cmp r7, #0
	bge _080347EA
_08034896:
	mov r2, sl
	cmp r2, #0xff
	beq _080348B6
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
_080348B6:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080348C8: .4byte gAiSt
_080348CC: .4byte gActiveUnit
_080348D0: .4byte gMapSize
_080348D4: .4byte gMapMovement
_080348D8: .4byte gMapUnit

	thumb_func_start sub_80348DC
sub_80348DC: @ 0x080348DC
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
	ldr r0, _080349B0 @ =gActiveUnit
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
	blt _08034916
	b _08034A3A
_08034916:
	adds r0, r4, #0
	bl GetUnit
	adds r7, r0, #0
	ldr r1, [sp, #0x14]
	adds r1, #0x80
	str r1, [sp, #0x1c]
	adds r4, #1
	str r4, [sp, #0x18]
	cmp r7, #0
	bne _0803492E
	b _08034A30
_0803492E:
	ldr r0, [r7]
	cmp r0, #0
	bne _08034936
	b _08034A30
_08034936:
	movs r0, #0x25
	ldrh r1, [r7, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _08034A30
	adds r0, r7, #0
	bl sub_8035028
	ldr r0, _080349B4 @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r6, r0, #1
	cmp r6, #0
	blt _08034A0A
_08034952:
	ldr r0, _080349B4 @ =gMapSize
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r4, r0, #1
	subs r0, r6, #1
	mov sb, r0
	cmp r4, #0
	blt _08034A04
	ldr r3, _080349B8 @ =gMapRange
	lsls r5, r6, #2
_08034966:
	ldr r0, [r3]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r2, r0, r4
	ldrb r1, [r2]
	cmp r1, #0x78
	bhi _080349FE
	ldr r0, _080349BC @ =gMapUnit
	ldr r0, [r0]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _080349C0
	movs r0, #0xb
	ldrsb r0, [r7, r0]
	ldrb r1, [r1]
	str r3, [sp, #0x20]
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	ldr r3, [sp, #0x20]
	cmp r0, #0
	bne _080349FE
	ldr r0, [r3]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r8, r0
	ble _080349FE
	ldrb r1, [r1]
	mov r8, r1
	b _080349FE
	.align 2, 0
_080349B0: .4byte gActiveUnit
_080349B4: .4byte gMapSize
_080349B8: .4byte gMapRange
_080349BC: .4byte gMapUnit
_080349C0:
	ldr r0, _08034A44 @ =gMapTerrain
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
	ble _080349FE
	ldr r0, _08034A48 @ =gMapMovement
	ldr r0, [r0]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x78
	ble _080349FE
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp sl, r0
	ble _080349FE
	str r4, [sp, #8]
	str r6, [sp, #0xc]
	ldrb r2, [r2]
	mov sl, r2
_080349FE:
	subs r4, #1
	cmp r4, #0
	bge _08034966
_08034A04:
	mov r6, sb
	cmp r6, #0
	bge _08034952
_08034A0A:
	mov r0, r8
	cmp r0, #0xff
	beq _08034A30
	ldr r1, [sp, #4]
	cmp r1, r8
	blo _08034A30
	mov r0, sl
	cmp r0, #0xff
	beq _08034A30
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
_08034A30:
	ldr r4, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	cmp r4, r0
	bge _08034A3A
	b _08034916
_08034A3A:
	ldr r1, [sp, #4]
	cmp r1, #0xff
	bne _08034A4C
	movs r0, #0
	b _08034A4E
	.align 2, 0
_08034A44: .4byte gMapTerrain
_08034A48: .4byte gMapMovement
_08034A4C:
	movs r0, #1
_08034A4E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8034A60
sub_8034A60: @ 0x08034A60
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r5, #0
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r6, _08034AA8 @ =gUnk_0810DB9C
	ldrh r0, [r6]
	cmp r0, #0
	beq _08034ABE
	movs r4, #0
	adds r2, r6, #0
_08034A7C:
	ldrh r0, [r2]
	cmp r3, r0
	bne _08034AB0
	cmp r3, #0x67
	bne _08034A9C
	ldr r0, _08034AAC @ =gActiveUnit
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r0, [r0, #4]
	ldr r1, [r1, #0x28]
	ldr r0, [r0, #0x24]
	orrs r1, r0
	movs r0, #4
	ands r1, r0
	cmp r1, #0
	beq _08034AB6
_08034A9C:
	ldr r0, [r2, #4]
	cmp r0, #0
	beq _08034AB0
	adds r0, r5, #0
	b _08034AC2
	.align 2, 0
_08034AA8: .4byte gUnk_0810DB9C
_08034AAC: .4byte gActiveUnit
_08034AB0:
	adds r4, #8
	adds r2, #8
	adds r5, #1
_08034AB6:
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08034A7C
_08034ABE:
	movs r0, #1
	rsbs r0, r0, #0
_08034AC2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start AiTryDoSpecialItems
AiTryDoSpecialItems: @ 0x08034AC8
	push {r4, r5, r6, lr}
	ldr r1, _08034ADC @ =gAiSt
	adds r1, #0x7b
	movs r0, #2
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08034AE0
	movs r0, #0
	b _08034B52
	.align 2, 0
_08034ADC: .4byte gAiSt
_08034AE0:
	movs r5, #0
	ldr r0, _08034B40 @ =gActiveUnit
	ldr r0, [r0]
	ldrh r4, [r0, #0x1c]
	cmp r4, #0
	beq _08034B2A
	ldr r6, _08034B44 @ =gUnk_0810DB9C+0x4
_08034AEE:
	adds r0, r4, #0
	bl GetItemKind
	cmp r0, #0
	beq _08034B14
	adds r0, r4, #0
	bl sub_8034A60
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08034B14
	lsls r0, r1, #3
	adds r0, r0, r6
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_08034B14:
	adds r5, #1
	cmp r5, #4
	bgt _08034B2A
	ldr r0, _08034B40 @ =gActiveUnit
	ldr r0, [r0]
	lsls r1, r5, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _08034AEE
_08034B2A:
	ldr r0, _08034B48 @ =gAiSt
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034B50
	ldr r0, _08034B4C @ =gAiDecision
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _08034B52
	.align 2, 0
_08034B40: .4byte gActiveUnit
_08034B44: .4byte gUnk_0810DB9C+0x4
_08034B48: .4byte gAiSt
_08034B4C: .4byte gAiDecision
_08034B50:
	movs r0, #1
_08034B52:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_8034B58
sub_8034B58: @ 0x08034B58
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r4, _08034BE0 @ =gAiSt
	adds r0, r4, #0
	adds r0, #0x80
	ldr r0, [r0]
	ldr r1, _08034BE4 @ =0x80000001
	ands r0, r1
	cmp r0, #0
	beq _08034BD8
	ldr r0, _08034BE8 @ =gActiveUnit
	ldr r0, [r0]
	add r6, sp, #0xc
	adds r1, r6, #0
	bl sub_8034D80
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08034BD8
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
	ldr r5, _08034BEC @ =gAiDecision
	movs r4, #0xa
	ldrsb r4, [r5, r4]
	cmp r4, #1
	bne _08034BD8
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
	bne _08034BD8
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
_08034BD8:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034BE0: .4byte gAiSt
_08034BE4: .4byte 0x80000001
_08034BE8: .4byte gActiveUnit
_08034BEC: .4byte gAiDecision

	thumb_func_start sub_8034BF0
sub_8034BF0: @ 0x08034BF0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	movs r5, #0
	ldr r6, _08034C30 @ =gAiSt
	adds r0, r6, #0
	adds r0, #0x80
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08034CAC
	ldr r4, _08034C34 @ =gActiveUnit
	ldr r0, [r4]
	bl GetUnitItemCount
	cmp r0, #4
	ble _08034C38
	ldr r2, [r4]
	ldrb r1, [r2, #0xa]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08034C38
	movs r0, #8
	orrs r0, r1
	strb r0, [r2, #0xa]
	adds r0, r6, #0
	adds r0, #0x79
	strb r5, [r0]
	b _08034CAC
	.align 2, 0
_08034C30: .4byte gAiSt
_08034C34: .4byte gActiveUnit
_08034C38:
	ldr r4, _08034CB4 @ =gActiveUnit
	ldr r0, [r4]
	bl GetUnitItemCount
	cmp r0, #4
	ble _08034C48
	movs r0, #4
	orrs r5, r0
_08034C48:
	ldr r0, [r4]
	add r6, sp, #0xc
	adds r1, r5, #0
	adds r2, r6, #0
	bl sub_8034DFC
	cmp r0, #1
	bne _08034CAC
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #2
	ldrsh r1, [r6, r2]
	ldr r2, _08034CB8 @ =gAiSt
	adds r2, #0x7e
	ldrb r3, [r2]
	movs r5, #0
	str r5, [sp]
	movs r2, #0
	bl AiTryMoveTowards
	ldr r4, _08034CBC @ =gAiDecision
	ldrb r0, [r4, #0xa]
	cmp r0, #1
	bne _08034CAC
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
	bne _08034CAC
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
_08034CAC:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034CB4: .4byte gActiveUnit
_08034CB8: .4byte gAiSt
_08034CBC: .4byte gAiDecision

	thumb_func_start sub_8034CC0
sub_8034CC0: @ 0x08034CC0
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _08034D20 @ =gAiSt
	adds r0, #0x80
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08034D16
	ldr r0, _08034D24 @ =gActiveUnit
	ldr r2, [r0]
	adds r1, r2, #0
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #1
	bne _08034D16
	add r4, sp, #0xc
	adds r0, r2, #0
	adds r1, r4, #0
	bl AiFindSafestReachableLocation
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08034D16
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
_08034D16:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034D20: .4byte gAiSt
_08034D24: .4byte gActiveUnit

	thumb_func_start sub_8034D28
sub_8034D28: @ 0x08034D28
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r1, _08034D60 @ =gMapRange
	ldr r0, [r1]
	lsls r2, r4, #2
	adds r0, r2, r0
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x77
	bgt _08034D5C
	ldr r0, _08034D64 @ =gMapUnit
	ldr r0, [r0]
	adds r0, r2, r0
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r2, [r0]
	cmp r2, #0
	beq _08034D6C
	ldr r0, _08034D68 @ =gActiveUnitId
	ldrb r0, [r0]
	cmp r2, r0
	beq _08034D6C
_08034D5C:
	movs r0, #0xff
	b _08034D78
	.align 2, 0
_08034D60: .4byte gMapRange
_08034D64: .4byte gMapUnit
_08034D68: .4byte gActiveUnitId
_08034D6C:
	ldr r1, [r1]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r0, [r0]
_08034D78:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8034D80
sub_8034D80: @ 0x08034D80
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl sub_8034FF8
	ldr r0, _08034DC4 @ =gUnk_085C98F0
	movs r1, #0
	adds r2, r4, #0
	bl AiFindClosestTerrainAdjacentPosition
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08034DCC
	adds r0, r5, #0
	bl sub_8034F34
	movs r1, #2
	ldrsh r0, [r4, r1]
	ldr r1, _08034DC8 @ =gMapRange
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
	bgt _08034DCC
	movs r0, #1
	b _08034DCE
	.align 2, 0
_08034DC4: .4byte gUnk_085C98F0
_08034DC8: .4byte gMapRange
_08034DCC:
	movs r0, #0
_08034DCE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_8034DD4
sub_8034DD4: @ 0x08034DD4
	push {r4, lr}
	adds r4, r1, #0
	bl sub_8034F34
	ldr r0, _08034DF0 @ =gUnk_085C98F2
	movs r1, #0
	adds r2, r4, #0
	bl AiFindClosestTerrainPosition
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08034DF4
	movs r0, #1
	b _08034DF6
	.align 2, 0
_08034DF0: .4byte gUnk_085C98F2
_08034DF4:
	movs r0, #0
_08034DF6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_8034DFC
sub_8034DFC: @ 0x08034DFC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	bl sub_8034F04
	adds r0, r5, #0
	bl sub_8034FC4
	movs r0, #1
	orrs r0, r6
	adds r1, r4, #0
	bl AiFindClosestUnlockPosition
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08034E48
	movs r1, #2
	ldrsh r0, [r4, r1]
	ldr r1, _08034E44 @ =gMapMovement
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
	bgt _08034E48
_08034E3E:
	movs r0, #1
	b _08034E8E
	.align 2, 0
_08034E44: .4byte gMapMovement
_08034E48:
	adds r0, r5, #0
	bl sub_8034FF8
	adds r0, r6, #0
	adds r1, r4, #0
	bl AiFindClosestUnlockPosition
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08034E8C
	movs r3, #2
	ldrsh r1, [r4, r3]
	ldr r0, _08034E94 @ =gMapMovement
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
	bgt _08034E3E
	ldr r0, _08034E98 @ =gMapUnit
	ldr r0, [r0]
	adds r0, r1, r0
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08034E3E
_08034E8C:
	movs r0, #0
_08034E8E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08034E94: .4byte gMapMovement
_08034E98: .4byte gMapUnit

	thumb_func_start sub_8034E9C
sub_8034E9C: @ 0x08034E9C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r2, #1
	ldr r3, _08034EBC @ =gWorkingMovTable
	movs r5, #1
_08034EA6:
	adds r0, r4, r2
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08034EC0
	adds r0, r2, r3
	strb r1, [r0]
	b _08034EC4
	.align 2, 0
_08034EBC: .4byte gWorkingMovTable
_08034EC0:
	adds r0, r2, r3
	strb r5, [r0]
_08034EC4:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x32
	bls _08034EA6
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8034ED4
sub_8034ED4: @ 0x08034ED4
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	movs r2, #1
	ldr r6, _08034F00 @ =gWorkingMovTable
	adds r4, r6, #0
_08034EE0:
	adds r1, r2, r4
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x32
	bls _08034EE0
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034F00: .4byte gWorkingMovTable

	thumb_func_start sub_8034F04
sub_8034F04: @ 0x08034F04
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r0, _08034F30 @ =gMapMovement
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
_08034F30: .4byte gMapMovement

	thumb_func_start sub_8034F34
sub_8034F34: @ 0x08034F34
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r0, _08034F60 @ =gMapRange
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
_08034F60: .4byte gMapRange

	thumb_func_start sub_8034F64
sub_8034F64: @ 0x08034F64
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl sub_8034E9C
	ldr r0, _08034F90 @ =gMapMovement
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
_08034F90: .4byte gMapMovement

	thumb_func_start sub_8034F94
sub_8034F94: @ 0x08034F94
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl sub_8034E9C
	ldr r0, _08034FC0 @ =gMapMovement
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
_08034FC0: .4byte gMapMovement

	thumb_func_start sub_8034FC4
sub_8034FC4: @ 0x08034FC4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	movs r1, #0x1e
	bl sub_8034ED4
	ldr r0, _08034FF4 @ =gMapRange
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
_08034FF4: .4byte gMapRange

	thumb_func_start sub_8034FF8
sub_8034FF8: @ 0x08034FF8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	movs r1, #0x1e
	bl sub_8034ED4
	ldr r0, _08035024 @ =gMapRange
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
_08035024: .4byte gMapRange

	thumb_func_start sub_8035028
sub_8035028: @ 0x08035028
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r0, _08035060 @ =gMapRange
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
_08035060: .4byte gMapRange

	thumb_func_start sub_8035064
sub_8035064: @ 0x08035064
	adds r0, #0x40
	movs r1, #0x80
	lsls r1, r1, #6
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _08035084
	ldr r0, _08035080 @ =gAiSt
	adds r0, #0x7b
	movs r1, #2
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
	b _08035090
	.align 2, 0
_08035080: .4byte gAiSt
_08035084:
	ldr r1, _08035094 @ =gAiSt
	adds r1, #0x7b
	movs r0, #0xfd
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
_08035090:
	bx lr
	.align 2, 0
_08035094: .4byte gAiSt

	thumb_func_start sub_8035098
sub_8035098: @ 0x08035098
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r0, _080350C4 @ =gMapRange
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
_080350C4: .4byte gMapRange
