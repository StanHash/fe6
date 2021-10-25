
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
	ldr r0, .L08032F38 @ =gMapOther
	ldr r0, [r0]
	movs r1, #0
	bl MapFill
	movs r4, #1
.L08032E22:
	adds r0, r4, #0
	bl GetUnit
	adds r5, r0, #0
	adds r4, #1
	str r4, [sp, #0x14]
	cmp r5, #0
	beq .L08032F12
	ldr r0, [r5]
	cmp r0, #0
	beq .L08032F12
	movs r0, #0x21
	ldrh r7, [r5, #0xc]
	ands r0, r7
	cmp r0, #0
	bne .L08032F12
	ldr r0, .L08032F3C @ =gActiveUnitId
	ldrb r0, [r0]
	movs r1, #0xb
	ldrsb r1, [r5, r1]
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08032F12
	adds r0, r5, #0
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl sub_8032FF4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08032F12
	adds r0, r5, #0
	bl MapFlood_08019344
	ldr r4, .L08032F40 @ =gMapMovement
	ldr r1, [r4]
	ldr r2, [sp, #8]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, [sp, #4]
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0xff
	beq .L08032F12
	adds r0, r5, #0
	mov r1, sp
	bl sub_8033038
	adds r6, r0, #0
	mov r0, sp
	ldrh r0, [r0]
	bl GetItemMinRange
	cmp r0, #1
	ble .L08032EA0
	ldr r7, [sp, #0xc]
	ldrh r7, [r7]
	adds r0, r7, r6
	ldr r1, [sp, #0xc]
	strh r0, [r1]
.L08032EA0:
	mov r0, sp
	ldrh r0, [r0]
	bl GetItemMaxRange
	cmp r0, #1
	bne .L08032EB6
	ldr r2, [sp, #0x10]
	ldrh r2, [r2]
	adds r0, r2, r6
	ldr r3, [sp, #0x10]
	strh r0, [r3]
.L08032EB6:
	ldr r1, .L08032F44 @ =gMapSize
	movs r7, #2
	ldrsh r0, [r1, r7]
	subs r2, r0, #1
	mov sl, r1
	cmp r2, #0
	blt .L08032F12
	mov sb, r4
	ldr r0, .L08032F38 @ =gMapOther
	mov r8, r0
.L08032ECA:
	mov r1, sl
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r3, r0, #1
	subs r7, r2, #1
	str r7, [sp, #0x18]
	cmp r3, #0
	blt .L08032F0C
	lsls r4, r2, #2
	mov r1, sb
	mov r5, r8
	movs r0, #0xff
	mov ip, r0
.L08032EE4:
	ldr r0, [r1]
	adds r0, r4, r0
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi .L08032F06
	ldr r0, [r5]
	adds r0, r4, r0
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r7, [r0]
	adds r2, r7, r6
	cmp r2, #0xff
	ble .L08032F04
	mov r2, ip
.L08032F04:
	strb r2, [r0]
.L08032F06:
	subs r3, #1
	cmp r3, #0
	bge .L08032EE4
.L08032F0C:
	ldr r2, [sp, #0x18]
	cmp r2, #0
	bge .L08032ECA
.L08032F12:
	ldr r4, [sp, #0x14]
	cmp r4, #0xbf
	ble .L08032E22
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
.L08032F38: .4byte gMapOther
.L08032F3C: .4byte gActiveUnitId
.L08032F40: .4byte gMapMovement
.L08032F44: .4byte gMapSize

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
.L08032F58:
	ldrh r0, [r1]
	cmp r0, #0
	beq .L08032F72
	adds r2, r0, #0
	ands r0, r6
	cmp r0, #0
	beq .L08032F72
	adds r0, r7, #0
	ands r0, r2
	cmp r0, r4
	bls .L08032F72
	adds r4, r0, #0
	adds r5, r3, #0
.L08032F72:
	adds r1, #2
	adds r3, #1
	cmp r3, #4
	ble .L08032F58
	cmp r5, #0
	ble .L08032F88
	ldr r0, .L08032F90 @ =gActiveUnit
	ldr r0, [r0]
	adds r1, r5, #0
	bl UnitEquipItemSlot
.L08032F88:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08032F90: .4byte gActiveUnit

	thumb_func_start sub_8032F94
sub_8032F94: @ 0x08032F94
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmn r1, r0
	beq .L08032FB8
	cmp r1, r0
	blo .L08032FB0
	movs r0, #1
	adds r1, r3, #0
	bl sub_8032F48
	b .L08032FB8
.L08032FB0:
	movs r0, #2
	adds r1, r3, #0
	bl sub_8032F48
.L08032FB8:
	pop {r0}
	bx r0

	thumb_func_start sub_8032FBC
sub_8032FBC: @ 0x08032FBC
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIid
	cmp r0, #0x43
	blt .L08032FEC
	cmp r0, #0x47
	ble .L08032FD4
	cmp r0, #0x4e
	beq .L08032FE0
	b .L08032FEC
.L08032FD4:
	ldr r0, .L08032FDC @ =gActiveUnit
	ldr r1, [r0]
	movs r0, #4
	b .L08032FE6
	.align 2, 0
.L08032FDC: .4byte gActiveUnit
.L08032FE0:
	ldr r0, .L08032FF0 @ =gActiveUnit
	ldr r1, [r0]
	movs r0, #0x10
.L08032FE6:
	ldrb r2, [r1, #0xa]
	orrs r0, r2
	strb r0, [r1, #0xa]
.L08032FEC:
	pop {r0}
	bx r0
	.align 2, 0
.L08032FF0: .4byte gActiveUnit

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
	bge .L08033014
	subs r1, r0, r4
.L08033014:
	movs r0, #0xf
	ldrsb r0, [r3, r0]
	subs r3, r2, r0
	cmp r3, #0
	blt .L08033022
	adds r0, r1, r3
	b .L08033026
.L08033022:
	subs r0, r0, r2
	adds r0, r1, r0
.L08033026:
	cmp r5, r0
	bge .L0803302E
	movs r0, #0
	b .L08033030
.L0803302E:
	movs r0, #1
.L08033030:
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
	ldr r4, .L0803308C @ =gAiDecision
	ldrb r0, [r4]
	cmp r0, #2
	beq .L08033086
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	bl sub_80330C8
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L08033086
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	bl sub_80331EC
.L08033086:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0803308C: .4byte gAiDecision

	thumb_func_start AiTryActionAfterMove
AiTryActionAfterMove: @ 0x08033090
	push {r4, lr}
	ldr r4, .L080330C4 @ =gAiDecision
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	bl sub_80330C8
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L080330BC
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	bl sub_80331EC
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L080330BC
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	bl sub_8033250
.L080330BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080330C4: .4byte gAiDecision

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
	ldr r0, .L080331A8 @ =gActiveUnit
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, [r1, #0x28]
	ldr r1, [r2, #0x24]
	orrs r0, r1
	movs r1, #0x30
	ands r0, r1
	cmp r0, #0
	beq .L080331A4
	ldr r0, .L080331AC @ =gMapMovement
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	bl MapFill
	mov r0, sl
	ldr r1, [sp, #0xc]
	movs r2, #1
	movs r3, #1
	bl MapAddInRange
	ldr r0, .L080331B0 @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r1, r0, #1
	cmp r1, #0
	blt .L0803319E
.L08033118:
	ldr r0, .L080331B0 @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r7, r1, #1
	cmp r4, #0
	blt .L08033198
	lsls r5, r1, #2
.L08033128:
	ldr r0, .L080331AC @ =gMapMovement
	ldr r0, [r0]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi .L08033192
	ldr r6, .L080331B4 @ =gMapUnit
	ldr r0, [r6]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq .L08033192
	ldr r0, .L080331B8 @ =gActiveUnitId
	ldrb r0, [r0]
	ldrb r1, [r1]
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08033192
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
	bne .L08033192
	movs r0, #8
	ldrsb r0, [r2, r0]
	cmp r8, r0
	bge .L08033192
	ldrb r2, [r2, #8]
	mov r8, r2
	ldr r0, [r6]
	adds r0, r5, r0
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	mov sb, r0
.L08033192:
	subs r4, #1
	cmp r4, #0
	bge .L08033128
.L08033198:
	adds r1, r7, #0
	cmp r1, #0
	bge .L08033118
.L0803319E:
	mov r0, r8
	cmp r0, #0
	bne .L080331BC
.L080331A4:
	movs r0, #0
	b .L080331DA
	.align 2, 0
.L080331A8: .4byte gActiveUnit
.L080331AC: .4byte gMapMovement
.L080331B0: .4byte gMapSize
.L080331B4: .4byte gMapUnit
.L080331B8: .4byte gActiveUnitId
.L080331BC:
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
.L080331DA:
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
	ldr r0, .L08033240 @ =gActiveUnit
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, [r1, #0x28]
	ldr r1, [r2, #0x24]
	orrs r0, r1
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq .L0803323C
	ldr r4, .L08033244 @ =gMapMovement
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
	bne .L08033248
.L0803323C:
	movs r0, #0
	b .L0803324A
	.align 2, 0
.L08033240: .4byte gActiveUnit
.L08033244: .4byte gMapMovement
.L08033248:
	movs r0, #1
.L0803324A:
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
	ldr r0, .L08033274 @ =gActiveUnit
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	bne .L080332A8
	b .L0803335E
	.align 2, 0
.L08033274: .4byte gActiveUnit
.L08033278:
	ldr r0, .L080332A4 @ =gActiveUnit
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
	b .L08033360
	.align 2, 0
.L080332A4: .4byte gActiveUnit
.L080332A8:
	ldr r0, .L08033370 @ =gMapMovement
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
	ldr r0, .L08033374 @ =gMapSize
	movs r3, #2
	ldrsh r0, [r0, r3]
	subs r7, r0, #1
	cmp r7, #0
	blt .L0803335E
.L080332F0:
	ldr r0, .L08033374 @ =gMapSize
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r4, r0, #1
	cmp r4, #0
	blt .L08033358
	lsls r6, r7, #2
.L080332FE:
	ldr r0, .L08033370 @ =gMapMovement
	ldr r0, [r0]
	adds r0, r6, r0
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq .L08033352
	ldr r5, .L08033378 @ =gMapUnit
	ldr r0, [r5]
	adds r0, r6, r0
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq .L08033352
	ldr r0, .L0803337C @ =gActiveUnitId
	ldrb r0, [r0]
	ldrb r1, [r1]
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L08033352
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
	bne .L08033278
.L08033352:
	subs r4, #1
	cmp r4, #0
	bge .L080332FE
.L08033358:
	subs r7, #1
	cmp r7, #0
	bge .L080332F0
.L0803335E:
	movs r0, #0
.L08033360:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L08033370: .4byte gMapMovement
.L08033374: .4byte gMapSize
.L08033378: .4byte gMapUnit
.L0803337C: .4byte gActiveUnitId

	thumb_func_start sub_8033380
sub_8033380: @ 0x08033380
	ldr r2, .L080333A4 @ =gMapUnit
	ldr r2, [r2]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	adds r1, r1, r0
	ldrb r1, [r1]
	cmp r1, #0
	beq .L080333A0
	ldr r0, .L080333A8 @ =gActiveUnitId
	ldrb r0, [r0]
	eors r0, r1
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	bne .L080333AC
.L080333A0:
	movs r0, #0
	b .L080333AE
	.align 2, 0
.L080333A4: .4byte gMapUnit
.L080333A8: .4byte gActiveUnitId
.L080333AC:
	movs r0, #1
.L080333AE:
	bx lr

	thumb_func_start sub_80333B0
sub_80333B0: @ 0x080333B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r7, #0
	ldr r4, .L08033448 @ =gActiveUnit
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
	beq .L08033454
	cmp r2, #0
	beq .L08033454
	ldr r0, [r4]
	adds r1, r5, #0
	bl AiFloodMovementAndRange
	ldr r0, .L0803344C @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt .L080334CA
.L080333FE:
	ldr r0, .L0803344C @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r6, r5, #1
	cmp r4, #0
	blt .L0803343E
.L0803340C:
	ldr r0, .L08033450 @ =gMapRange
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq .L08033438
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_8033380
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08033438
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
.L08033438:
	subs r4, #1
	cmp r4, #0
	bge .L0803340C
.L0803343E:
	adds r5, r6, #0
	cmp r5, #0
	bge .L080333FE
	b .L080334CA
	.align 2, 0
.L08033448: .4byte gActiveUnit
.L0803344C: .4byte gMapSize
.L08033450: .4byte gMapRange
.L08033454:
	ldr r4, .L080334E4 @ =gActiveUnit
	ldr r0, [r4]
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r0, .L080334E8 @ =gMapRange
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
	ldr r0, .L080334EC @ =gMapSize
	movs r3, #2
	ldrsh r0, [r0, r3]
	subs r5, r0, #1
	cmp r5, #0
	blt .L080334CA
.L08033488:
	ldr r0, .L080334EC @ =gMapSize
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r4, r0, #1
	subs r6, r5, #1
	cmp r4, #0
	blt .L080334C4
.L08033496:
	ldr r0, .L080334E8 @ =gMapRange
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi .L080334BE
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_8033380
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L080334BE
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
.L080334BE:
	subs r4, #1
	cmp r4, #0
	bge .L08033496
.L080334C4:
	adds r5, r6, #0
	cmp r5, #0
	bge .L08033488
.L080334CA:
	ldr r0, .L080334F0 @ =gAiSt
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
.L080334E4: .4byte gActiveUnit
.L080334E8: .4byte gMapRange
.L080334EC: .4byte gMapSize
.L080334F0: .4byte gAiSt

	thumb_func_start sub_80334F4
sub_80334F4: @ 0x080334F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, .L08033590 @ =gActiveUnit
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
	beq .L08033598
	mov r0, sl
	cmp r0, #0
	beq .L08033598
	ldr r0, [r5]
	ldr r1, [sp, #4]
	mov r2, sl
	bl AiFloodMovementAndRange
	ldr r0, .L08033594 @ =gMapRange
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
	bne .L080335D2
.L08033584:
	ldr r0, [r5]
	strb r6, [r0, #0xe]
	ldr r0, [r5]
	strb r7, [r0, #0xf]
	b .L08033684
	.align 2, 0
.L08033590: .4byte gActiveUnit
.L08033594: .4byte gMapRange
.L08033598:
	ldr r5, .L08033634 @ =gActiveUnit
	ldr r0, [r5]
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x34]
	bl SetWorkingMovTable
	ldr r4, .L08033638 @ =gMapRange
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
	bhi .L08033584
.L080335D2:
	ldr r1, .L08033634 @ =gActiveUnit
	ldr r0, [r1]
	strb r6, [r0, #0xe]
	ldr r0, [r1]
	strb r7, [r0, #0xf]
	ldr r0, [r1]
	bl MapFlood_08019344
	ldr r1, .L0803363C @ =gMapSize
	movs r2, #2
	ldrsh r0, [r1, r2]
	subs r4, r0, #1
	cmp r4, #0
	blt .L08033676
.L080335EE:
	ldr r1, .L0803363C @ =gMapSize
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r2, r0, #1
	subs r0, r4, #1
	mov ip, r0
	cmp r2, #0
	blt .L08033670
	ldr r7, .L08033640 @ =gMapMovement
	ldr r6, .L08033638 @ =gMapRange
	movs r1, #1
	rsbs r1, r1, #0
	adds r5, r1, #0
.L08033608:
	mov r0, sl
	cmp r0, #0
	beq .L08033644
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r0, [r0]
	adds r3, r0, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0x77
	bgt .L08033668
	ldr r0, [r6]
	adds r0, r1, r0
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0803366A
	b .L08033668
	.align 2, 0
.L08033634: .4byte gActiveUnit
.L08033638: .4byte gMapRange
.L0803363C: .4byte gMapSize
.L08033640: .4byte gMapMovement
.L08033644:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r0, [r0]
	adds r3, r0, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0x77
	bgt .L08033668
	ldr r0, [r6]
	adds r0, r1, r0
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x77
	ble .L0803366A
.L08033668:
	strb r5, [r3]
.L0803366A:
	subs r2, #1
	cmp r2, #0
	bge .L08033608
.L08033670:
	mov r4, ip
	cmp r4, #0
	bge .L080335EE
.L08033676:
	ldr r0, .L080336A8 @ =AiIsUnitEnemy
	bl AiAttemptCombatWithinMovement
	ldr r0, .L080336AC @ =gAiDecision
	ldrb r0, [r0, #0xa]
	cmp r0, #1
	beq .L08033694
.L08033684:
	mov r0, r8
	mov r1, sb
	movs r2, #1
	str r2, [sp]
	movs r2, #0
	movs r3, #0xff
	bl AiTryMoveTowards
.L08033694:
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
.L080336A8: .4byte AiIsUnitEnemy
.L080336AC: .4byte gAiDecision

	thumb_func_start sub_80336B0
sub_80336B0: @ 0x080336B0
	ldr r1, .L080336C4 @ =gAiSt
	ldr r0, .L080336C8 @ =gActiveUnit
	ldr r0, [r0]
	adds r0, #0x46
	ldrb r0, [r0]
	adds r1, #0x86
	strb r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
.L080336C4: .4byte gAiSt
.L080336C8: .4byte gActiveUnit

	thumb_func_start sub_80336CC
sub_80336CC: @ 0x080336CC
	push {r4, r5, lr}
	bl GetActiveFactionAlliance
	adds r4, r0, #1
	adds r0, #0x80
	cmp r4, r0
	bge .L080336E8
	adds r5, r0, #0
.L080336DC:
	adds r0, r4, #0
	bl GetUnit
	adds r4, #1
	cmp r4, r5
	blt .L080336DC
.L080336E8:
	ldr r0, .L080336F8 @ =gAiSt
	adds r0, #0x79
	movs r1, #0
	strb r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L080336F8: .4byte gAiSt

	thumb_func_start sub_80336FC
sub_80336FC: @ 0x080336FC
	push {r4, r5, lr}
	bl GetActiveFactionAlliance
	adds r4, r0, #1
	adds r0, #0x80
	cmp r4, r0
	bge .L08033718
	adds r5, r0, #0
.L0803370C:
	adds r0, r4, #0
	bl GetUnit
	adds r4, #1
	cmp r4, r5
	blt .L0803370C
.L08033718:
	ldr r0, .L08033728 @ =gAiSt
	adds r0, #0x79
	movs r1, #0
	strb r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08033728: .4byte gAiSt

	thumb_func_start sub_803372C
sub_803372C: @ 0x0803372C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, .L08033760 @ =gActiveUnit
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
	ldr r0, .L08033764 @ =gUnk_085C8878
	ldr r1, [r0]
	cmp r1, #0
	beq .L0803375A
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	bne .L08033768
.L0803375A:
	movs r0, #0
	b .L080337AA
	.align 2, 0
.L08033760: .4byte gActiveUnit
.L08033764: .4byte gUnk_085C8878
.L08033768:
	lsls r0, r4, #2
	adds r3, r2, r0
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0803377E
	movs r4, #0
	strb r4, [r5]
	adds r3, r2, #0
.L0803377E:
	ldrh r0, [r3]
	strh r0, [r6]
	ldrh r0, [r3, #2]
	strh r0, [r6, #2]
	movs r1, #2
	ldrsh r0, [r3, r1]
	ldr r1, .L080337B0 @ =gMapMovement
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r3, r2]
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	beq .L080337A8
	adds r4, #1
	ldr r0, [r7]
	adds r0, #0x46
	strb r4, [r0]
.L080337A8:
	movs r0, #1
.L080337AA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L080337B0: .4byte gMapMovement

	thumb_func_start sub_80337B4
sub_80337B4: @ 0x080337B4
	push {r4, lr}
	sub sp, #8
	ldr r4, .L080337E4 @ =gActiveUnit
	ldr r0, [r4]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq .L080337EC
	ldr r0, [r4]
	bl AiMakeMoveRangeMapsForUnitAndWeapon
	bl AiCountEnemyUnitsInRange
	adds r1, r0, #0
	cmp r1, #0
	beq .L080337F2
	ldr r0, .L080337E8 @ =gAiSt
	adds r0, #0x86
	strb r1, [r0]
	movs r0, #0
	b .L0803381C
	.align 2, 0
.L080337E4: .4byte gActiveUnit
.L080337E8: .4byte gAiSt
.L080337EC:
	ldr r0, [r4]
	bl MapFlood_08019344
.L080337F2:
	add r4, sp, #4
	adds r0, r4, #0
	bl sub_803372C
	lsls r0, r0, #0x18
	asrs r2, r0, #0x18
	cmp r2, #1
	beq .L08033806
	movs r0, #0
	b .L0803381C
.L08033806:
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
.L0803381C:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_8033824
sub_8033824: @ 0x08033824
	adds r1, r0, #0
	ldr r0, .L08033850 @ =gActiveUnit
	ldr r0, [r0]
	ldrb r2, [r0, #0xe]
	ldrb r0, [r0, #0xf]
	ldrb r3, [r1]
	cmp r3, r2
	bhi .L08033858
	ldrb r3, [r1, #2]
	cmp r3, r2
	blo .L08033858
	ldrb r2, [r1, #1]
	cmp r2, r0
	bhi .L08033858
	ldrb r1, [r1, #3]
	cmp r1, r0
	blo .L08033858
	ldr r0, .L08033854 @ =gAiSt
	adds r0, #0x86
	movs r1, #1
	b .L0803385E
	.align 2, 0
.L08033850: .4byte gActiveUnit
.L08033854: .4byte gAiSt
.L08033858:
	ldr r0, .L08033864 @ =gAiSt
	adds r0, #0x86
	movs r1, #0
.L0803385E:
	strb r1, [r0]
	movs r0, #0
	bx lr
	.align 2, 0
.L08033864: .4byte gAiSt

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
	ldr r7, .L080338D0 @ =gActiveUnitId
	ldrb r0, [r7]
	mov r8, r0
	ldr r4, .L080338D4 @ =gActiveUnit
	ldr r6, [r4]
	adds r0, r6, #0
	bl GetUnitLeaderPid
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq .L08033942
	bl GetUnitByPid
	adds r1, r0, #0
	str r1, [r4]
	cmp r1, #0
	bne .L080338DC
	str r6, [r4]
	ldr r0, .L080338D8 @ =gAiSt
	adds r0, #0x87
	movs r1, #1
	strb r1, [r0]
	b .L08033942
	.align 2, 0
.L080338D0: .4byte gActiveUnitId
.L080338D4: .4byte gActiveUnit
.L080338D8: .4byte gAiSt
.L080338DC:
	ldrb r0, [r1, #0xb]
	strb r0, [r7]
	adds r0, r1, #0
	adds r0, #0x42
	ldrb r4, [r0]
	adds r0, #1
	ldrb r7, [r0]
.L080338EA:
	bl AiTryExecScriptA
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L08033900
	adds r5, #1
	cmp r5, #0xff
	ble .L080338EA
	bl AiExecFallbackScriptA
.L08033900:
	ldr r1, .L08033918 @ =gAiDecision
	ldrb r2, [r1, #0xa]
	cmp r2, #1
	bne .L08033920
	ldrb r0, [r1]
	cmp r0, #1
	bne .L08033920
	ldr r0, .L0803391C @ =gAiSt
	ldrb r1, [r1, #6]
	adds r0, #0x86
	b .L08033926
	.align 2, 0
.L08033918: .4byte gAiDecision
.L0803391C: .4byte gAiSt
.L08033920:
	ldr r0, .L08033950 @ =gAiSt
	adds r0, #0x86
	movs r1, #0
.L08033926:
	strb r1, [r0]
	bl AiClearDecision
	ldr r1, .L08033954 @ =gActiveUnit
	ldr r0, [r1]
	adds r0, #0x42
	strb r4, [r0]
	ldr r0, [r1]
	adds r0, #0x43
	strb r7, [r0]
	ldr r0, .L08033958 @ =gActiveUnitId
	mov r2, r8
	strb r2, [r0]
	str r6, [r1]
.L08033942:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L08033950: .4byte gAiSt
.L08033954: .4byte gActiveUnit
.L08033958: .4byte gActiveUnitId

	thumb_func_start sub_803395C
sub_803395C: @ 0x0803395C
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2]
	ldr r0, .L08033988 @ =gUnk_Pid_02039694
	ldrb r1, [r1, #4]
	ldrb r0, [r0]
	cmp r1, r0
	bne .L08033990
	ldr r0, .L0803398C @ =gActiveUnit
	ldr r0, [r0]
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0xb
	ldrsb r1, [r2, r1]
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08033990
	movs r0, #1
	b .L08033992
	.align 2, 0
.L08033988: .4byte gUnk_Pid_02039694
.L0803398C: .4byte gActiveUnit
.L08033990:
	movs r0, #0
.L08033992:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8033998
sub_8033998: @ 0x08033998
	push {lr}
	ldr r2, .L080339B8 @ =gUnk_Pid_02039694
	ldrb r1, [r0]
	strb r1, [r2]
	ldrb r0, [r0]
	bl AiUnitWithPidExists
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L080339C0
	ldr r0, .L080339BC @ =gAiSt
	adds r0, #0x87
	movs r1, #1
	strb r1, [r0]
	b .L080339E6
	.align 2, 0
.L080339B8: .4byte gUnk_Pid_02039694
.L080339BC: .4byte gAiSt
.L080339C0:
	ldr r0, .L080339EC @ =sub_803395C
	bl AiAttemptOffensiveAction
	ldr r0, .L080339F0 @ =gAiSt
	adds r1, r0, #0
	adds r1, #0x86
	movs r0, #0
	strb r0, [r1]
	ldr r0, .L080339F4 @ =gAiDecision
	ldrb r2, [r0, #0xa]
	cmp r2, #1
	bne .L080339E2
	ldrb r2, [r0]
	cmp r2, #1
	bne .L080339E2
	ldrb r0, [r0, #6]
	strb r0, [r1]
.L080339E2:
	bl AiClearDecision
.L080339E6:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
.L080339EC: .4byte sub_803395C
.L080339F0: .4byte gAiSt
.L080339F4: .4byte gAiDecision

	thumb_func_start sub_80339F8
sub_80339F8: @ 0x080339F8
	push {lr}
	movs r1, #0xb
	ldrsb r1, [r0, r1]
	ldr r0, .L08033A20 @ =gAiSt
	adds r0, #0x86
	ldrb r0, [r0]
	cmp r1, r0
	bne .L08033A28
	ldr r0, .L08033A24 @ =gActiveUnit
	ldr r0, [r0]
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl AreUnitIdsAllied
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08033A28
	movs r0, #1
	b .L08033A2A
	.align 2, 0
.L08033A20: .4byte gAiSt
.L08033A24: .4byte gActiveUnit
.L08033A28:
	movs r0, #0
.L08033A2A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8033A30
sub_8033A30: @ 0x08033A30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, .L08033A90 @ =gAiSt
	adds r0, #0x86
	ldrb r0, [r0]
	bl GetUnit
	movs r2, #0xe
	ldrsb r2, [r0, r2]
	ldr r1, .L08033A94 @ =gActiveUnit
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
	bne .L08033A98
	adds r0, r7, #0
	muls r0, r5, r0
	cmp r0, #0
	blt .L08033A98
	mov r0, r8
	muls r0, r6, r0
	cmp r0, #0
	blt .L08033A98
	movs r0, #1
	b .L08033A9A
	.align 2, 0
.L08033A90: .4byte gAiSt
.L08033A94: .4byte gActiveUnit
.L08033A98:
	movs r0, #0
.L08033A9A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_8033AA4
sub_8033AA4: @ 0x08033AA4
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L08033AF4 @ =gAiSt
	adds r1, r0, #0
	adds r1, #0x86
	ldrb r0, [r1]
	cmp r0, #0
	beq .L08033AEA
	ldrb r0, [r1]
	bl GetUnit
	adds r4, r0, #0
	ldr r0, .L08033AF8 @ =sub_80339F8
	bl AiAttemptOffensiveAction
	ldr r5, .L08033AFC @ =gAiDecision
	ldrb r0, [r5, #0xa]
	cmp r0, #1
	beq .L08033AEA
	ldr r0, .L08033B00 @ =sub_8033A30
	bl AiAttemptOffensiveAction
	ldrb r5, [r5, #0xa]
	cmp r5, #1
	beq .L08033AEA
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	movs r1, #0xf
	ldrsb r1, [r4, r1]
	movs r2, #1
	str r2, [sp]
	movs r2, #0
	movs r3, #0xff
	bl AiTryMoveTowards
.L08033AEA:
	movs r0, #1
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08033AF4: .4byte gAiSt
.L08033AF8: .4byte sub_80339F8
.L08033AFC: .4byte gAiDecision
.L08033B00: .4byte sub_8033A30

	thumb_func_start sub_8033B04
sub_8033B04: @ 0x08033B04
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x64
	bl RandNext
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, .L08033B38 @ =gAiSt
	ldrb r2, [r4, #1]
	adds r1, r3, #0
	adds r1, #0x7c
	strb r2, [r1]
	ldrb r4, [r4]
	cmp r0, r4
	bhi .L08033B40
	ldr r4, .L08033B3C @ =AiIsUnitEnemy
	adds r0, r4, #0
	bl sub_8033C04
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08033B48
	adds r0, r4, #0
	bl AiAttemptOffensiveAction
	b .L08033B48
	.align 2, 0
.L08033B38: .4byte gAiSt
.L08033B3C: .4byte AiIsUnitEnemy
.L08033B40:
	adds r1, r3, #0
	adds r1, #0x79
	movs r0, #4
	strb r0, [r1]
.L08033B48:
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
	bhi .L08033B88
	bl AiTryDoSpecialItems
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08033B90
	movs r0, #0x64
	bl RandNext
	ldrb r5, [r5, #1]
	cmp r4, r5
	bhi .L08033B90
	ldr r0, .L08033B84 @ =AiIsUnitEnemy
	bl AiAttemptOffensiveAction
	b .L08033B90
	.align 2, 0
.L08033B84: .4byte AiIsUnitEnemy
.L08033B88:
	ldr r0, .L08033B98 @ =gAiSt
	adds r0, #0x79
	movs r1, #4
	strb r1, [r0]
.L08033B90:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08033B98: .4byte gAiSt

	thumb_func_start sub_8033B9C
sub_8033B9C: @ 0x08033B9C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r5, #0
	ldr r0, .L08033BB8 @ =gActiveUnit
	ldr r0, [r0]
	adds r1, r4, #0
	bl CanUnitUseStaff
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08033BC0
	b .L08033BF4
	.align 2, 0
.L08033BB8: .4byte gActiveUnit
.L08033BBC:
	adds r0, r5, #0
	b .L08033BF8
.L08033BC0:
	adds r0, r4, #0
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r4, .L08033C00 @ =gUnk_0810DB34
	ldrh r0, [r4]
	cmp r0, #0
	beq .L08033BF4
	movs r3, #0
	adds r2, r4, #4
	adds r1, r4, #0
.L08033BD8:
	ldrh r0, [r1]
	cmp r6, r0
	bne .L08033BE4
	ldr r0, [r2]
	cmp r0, #0
	bne .L08033BBC
.L08033BE4:
	adds r3, #8
	adds r2, #8
	adds r1, #8
	adds r5, #1
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08033BD8
.L08033BF4:
	movs r0, #1
	rsbs r0, r0, #0
.L08033BF8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L08033C00: .4byte gUnk_0810DB34

	thumb_func_start sub_8033C04
sub_8033C04: @ 0x08033C04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r6, #0
	movs r5, #0
	ldr r0, .L08033C80 @ =gActiveUnit
	ldr r0, [r0]
	ldrh r4, [r0, #0x1c]
	cmp r4, #0
	beq .L08033C6C
	ldr r0, .L08033C84 @ =gUnk_0810DB34+0x4
	mov r8, r0
.L08033C1E:
	adds r0, r4, #0
	bl GetItemAttributes
	adds r0, r4, #0
	bl GetItemRequiredExp
	cmp r0, r6
	blt .L08033C56
	adds r0, r4, #0
	bl sub_8033B9C
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L08033C56
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
.L08033C56:
	adds r5, #1
	cmp r5, #4
	bgt .L08033C6C
	ldr r0, .L08033C80 @ =gActiveUnit
	ldr r0, [r0]
	lsls r1, r5, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne .L08033C1E
.L08033C6C:
	ldr r0, .L08033C88 @ =gAiDecision
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L08033C80: .4byte gActiveUnit
.L08033C84: .4byte gUnk_0810DB34+0x4
.L08033C88: .4byte gAiDecision

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
	ldr r2, .L08033D30 @ =gUnk_085C98D0
	movs r1, #3
	mov sb, r1
.L08033CA8:
	ldr r0, [r2]
	ldr r1, [sp]
	adds r5, r1, r0
	ldr r0, [r2, #4]
	ldr r1, [sp, #4]
	adds r7, r1, r0
	ldr r0, .L08033D34 @ =gMapMovement
	ldr r0, [r0]
	lsls r6, r7, #2
	adds r0, r6, r0
	ldr r0, [r0]
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0x77
	bhi .L08033D16
	ldr r0, .L08033D38 @ =gMapUnit
	ldr r0, [r0]
	adds r0, r6, r0
	ldr r0, [r0]
	adds r0, r0, r5
	ldrb r1, [r0]
	cmp r1, #0
	beq .L08033CDE
	ldr r0, .L08033D3C @ =gActiveUnitId
	ldrb r0, [r0]
	cmp r1, r0
	bne .L08033D16
.L08033CDE:
	adds r0, r5, #0
	adds r1, r7, #0
	str r2, [sp, #8]
	bl AiGetTerrainCombatPositionScoreComponent
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r7, #0
	bl AiGetFriendZoneCombatPositionScoreComponent
	adds r4, r4, r0
	ldr r0, .L08033D40 @ =gMapOther
	ldr r0, [r0]
	adds r0, r6, r0
	ldr r0, [r0]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsrs r0, r0, #3
	subs r4, r4, r0
	ldr r0, .L08033D44 @ =0x7FFFFFFF
	adds r4, r4, r0
	ldr r2, [sp, #8]
	cmp sl, r4
	bhs .L08033D16
	mov r1, r8
	strh r5, [r1]
	strh r7, [r1, #2]
	mov sl, r4
.L08033D16:
	adds r2, #8
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge .L08033CA8
	mov r0, sl
	cmp r0, #0
	bne .L08033D48
	movs r0, #0
	b .L08033D4A
	.align 2, 0
.L08033D30: .4byte gUnk_085C98D0
.L08033D34: .4byte gMapMovement
.L08033D38: .4byte gMapUnit
.L08033D3C: .4byte gActiveUnitId
.L08033D40: .4byte gMapOther
.L08033D44: .4byte 0x7FFFFFFF
.L08033D48:
	movs r0, #1
.L08033D4A:
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
	ldr r0, .L08033EAC @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
	bl MapMovementMarkFloodEdges
	ldr r0, .L08033EB0 @ =gAiSt
	adds r1, r0, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	cmp r0, #0
	beq .L08033D98
	adds r1, r0, #0
	mov sl, r1
.L08033D98:
	ldr r0, .L08033EB4 @ =gMapSize
	movs r4, #2
	ldrsh r0, [r0, r4]
	subs r7, r0, #1
	cmp r7, #0
	blt .L08033E78
.L08033DA4:
	ldr r0, .L08033EB4 @ =gMapSize
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r6, r0, #1
	subs r2, r7, #1
	str r2, [sp, #0x20]
	cmp r6, #0
	blt .L08033E72
	lsls r4, r7, #2
	mov r8, r4
.L08033DB8:
	ldr r0, .L08033EB8 @ =gMapMovement
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi .L08033E6C
	ldr r0, .L08033EBC @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r2, r0, r6
	ldrb r1, [r2]
	cmp r1, #0
	beq .L08033E6C
	ldr r0, .L08033EC0 @ =gActiveUnitId
	ldrb r0, [r0]
	cmp r1, r0
	beq .L08033E6C
	adds r0, r1, #0
	bl GetUnit
	adds r5, r0, #0
	movs r0, #4
	ldr r1, .L08033EC4 @ =gAiSt+0x7B
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L08033E08
	mov r2, sb
	cmp r2, #0
	beq .L08033E08
	adds r0, r5, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L08033E6C
.L08033E08:
	ldr r4, .L08033EC8 @ =gAiSt+0x7C
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08033E1A
	movs r0, #1
	ldrb r1, [r5, #0xa]
	ands r0, r1
	cmp r0, #0
	beq .L08033E6C
.L08033E1A:
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
	bhi .L08033E6C
	add r5, sp, #0xc
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl sub_8033C8C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08033E6C
	mov sl, r4
	add r0, sp, #0xc
	movs r4, #0
	ldrsh r2, [r0, r4]
	str r2, [sp, #0x14]
	movs r1, #2
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x18]
	ldr r0, .L08033EBC @ =gMapUnit
	ldr r0, [r0]
	add r0, r8
	ldr r0, [r0]
	adds r0, r0, r6
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
.L08033E6C:
	subs r6, #1
	cmp r6, #0
	bge .L08033DB8
.L08033E72:
	ldr r7, [sp, #0x20]
	cmp r7, #0
	bge .L08033DA4
.L08033E78:
	movs r0, #1
	rsbs r0, r0, #0
	ldr r2, [sp, #0x14]
	cmp r2, r0
	beq .L08033E9C
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
.L08033E9C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08033EAC: .4byte gActiveUnit
.L08033EB0: .4byte gAiSt
.L08033EB4: .4byte gMapSize
.L08033EB8: .4byte gMapMovement
.L08033EBC: .4byte gMapUnit
.L08033EC0: .4byte gActiveUnitId
.L08033EC4: .4byte gAiSt+0x7B
.L08033EC8: .4byte gAiSt+0x7C

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
	ldr r4, .L08034078 @ =gAiSt
	adds r5, r4, #0
	adds r5, #0x7b
	movs r0, #4
	ldrb r3, [r5]
	ands r0, r3
	cmp r0, #0
	beq .L08033EFE
	b .L08034066
.L08033EFE:
	ldr r0, .L0803407C @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
	adds r1, r4, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	cmp r0, #0
	beq .L08033F14
	adds r4, r0, #0
	mov sl, r4
.L08033F14:
	movs r0, #1
	mov r8, r0
.L08033F18:
	mov r0, r8
	bl GetUnit
	adds r6, r0, #0
	cmp r6, #0
	bne .L08033F26
	b .L08034036
.L08033F26:
	ldr r0, [r6]
	cmp r0, #0
	bne .L08033F2E
	b .L08034036
.L08033F2E:
	movs r1, #0xf
	ldrsb r1, [r6, r1]
	ldr r0, .L08034080 @ =gMapUnit
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r2, #0xe
	ldrsb r2, [r6, r2]
	ldr r0, [r1]
	adds r0, r0, r2
	ldr r1, .L08034084 @ =gActiveUnitId
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq .L08034036
	movs r0, #5
	ldrh r1, [r6, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L08034036
	movs r0, #4
	ldr r2, .L08034088 @ =gAiSt+0x7B
	ldrb r2, [r2]
	ands r0, r2
	cmp r0, #0
	bne .L08033F76
	mov r3, sb
	cmp r3, #0
	beq .L08033F76
	adds r0, r6, #0
	bl _call_via_r9
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L08034036
.L08033F76:
	ldr r4, .L0803408C @ =gAiSt+0x7C
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08033F88
	movs r0, #1
	ldrb r1, [r6, #0xa]
	ands r0, r1
	cmp r0, #0
	beq .L08034036
.L08033F88:
	ldr r7, .L0803407C @ =gActiveUnit
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
	beq .L08034036
	ldr r0, .L08034090 @ =gMapRange
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
	beq .L08034036
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
	bhi .L08034036
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
	ldr r0, .L08034080 @ =gMapUnit
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r2, #0xe
	ldrsb r2, [r6, r2]
	ldr r0, [r1]
	adds r0, r0, r2
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
.L08034036:
	movs r4, #1
	add r8, r4
	mov r0, r8
	cmp r0, #0xbf
	bgt .L08034042
	b .L08033F18
.L08034042:
	movs r0, #1
	rsbs r0, r0, #0
	ldr r1, [sp, #0x14]
	cmp r1, r0
	beq .L08034066
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
.L08034066:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08034078: .4byte gAiSt
.L0803407C: .4byte gActiveUnit
.L08034080: .4byte gMapUnit
.L08034084: .4byte gActiveUnitId
.L08034088: .4byte gAiSt+0x7B
.L0803408C: .4byte gAiSt+0x7C
.L08034090: .4byte gMapRange

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
	ldr r1, .L08034164 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L08034152
	bl sub_8030B94
	cmp r0, #2
	ble .L08034152
	ldr r0, .L08034168 @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
	ldr r0, .L0803416C @ =gMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt .L0803412C
.L080340D4:
	ldr r0, .L0803416C @ =gMapSize
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r0, #1
	subs r6, r5, #1
	cmp r4, #0
	blt .L08034126
.L080340E2:
	ldr r0, .L08034170 @ =gMapMovement
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi .L08034120
	ldr r0, .L08034174 @ =gMapRange
	ldr r0, [r0]
	movs r1, #0
	bl MapFill
	ldr r0, .L08034168 @ =gActiveUnit
	ldr r0, [r0]
	bl GetUnitMagRange
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MapAddInRange
	bl sub_8030BDC
	cmp r0, r7
	ble .L08034120
	adds r7, r0, #0
	mov r8, r4
	mov sb, r5
.L08034120:
	subs r4, #1
	cmp r4, #0
	bge .L080340E2
.L08034126:
	adds r5, r6, #0
	cmp r5, #0
	bge .L080340D4
.L0803412C:
	cmp r7, #1
	ble .L08034152
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
.L08034152:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08034164: .4byte gAiSt
.L08034168: .4byte gActiveUnit
.L0803416C: .4byte gMapSize
.L08034170: .4byte gMapMovement
.L08034174: .4byte gMapRange

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
	ldr r1, .L080342B0 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L080342A0
	ldr r0, .L080342B4 @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
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
	bl sub_8033C8C
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
	bl sub_80348DC
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
	ldr r1, .L080343EC @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L080343DA
	ldr r0, .L080343F0 @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
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
	bl sub_8033C8C
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

	thumb_func_start sub_8034400
sub_8034400: @ 0x08034400
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

	thumb_func_start sub_8034458
sub_8034458: @ 0x08034458
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
	bl sub_8030CBC
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
	bl sub_8034400
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080345E0
	adds r0, r6, #0
	bl sub_8034458
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
	bl sub_8030AB4
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
	bl sub_8030CBC
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
	bl sub_8034400
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
	bl sub_8030AB4
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
	ldr r1, .L080348C8 @ =gAiSt
	adds r1, #0x7b
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L080348B6
	ldr r0, .L080348CC @ =gActiveUnit
	ldr r0, [r0]
	bl sub_8030CBC
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
	bl sub_8033C8C
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
	bl sub_8035028
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

	thumb_func_start sub_8034A60
sub_8034A60: @ 0x08034A60
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
	bl sub_8034A60
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

	thumb_func_start sub_8034B58
sub_8034B58: @ 0x08034B58
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
	bl sub_8034D80
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

	thumb_func_start sub_8034BF0
sub_8034BF0: @ 0x08034BF0
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
	bl sub_8034DFC
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

	thumb_func_start sub_8034CC0
sub_8034CC0: @ 0x08034CC0
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

	thumb_func_start sub_8034D28
sub_8034D28: @ 0x08034D28
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

	thumb_func_start sub_8034D80
sub_8034D80: @ 0x08034D80
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl sub_8034FF8
	ldr r0, .L08034DC4 @ =gUnk_085C98F0
	movs r1, #0
	adds r2, r4, #0
	bl AiFindClosestTerrainAdjacentPosition
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08034DCC
	adds r0, r5, #0
	bl sub_8034F34
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

	thumb_func_start sub_8034DD4
sub_8034DD4: @ 0x08034DD4
	push {r4, lr}
	adds r4, r1, #0
	bl sub_8034F34
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
	bl sub_8034FF8
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

	thumb_func_start sub_8034E9C
sub_8034E9C: @ 0x08034E9C
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

	thumb_func_start sub_8034ED4
sub_8034ED4: @ 0x08034ED4
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

	thumb_func_start sub_8034F04
sub_8034F04: @ 0x08034F04
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

	thumb_func_start sub_8034F34
sub_8034F34: @ 0x08034F34
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

	thumb_func_start sub_8034F64
sub_8034F64: @ 0x08034F64
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl sub_8034E9C
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

	thumb_func_start sub_8034F94
sub_8034F94: @ 0x08034F94
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	bl sub_8034E9C
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

	thumb_func_start sub_8034FC4
sub_8034FC4: @ 0x08034FC4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	movs r1, #0x1e
	bl sub_8034ED4
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

	thumb_func_start sub_8034FF8
sub_8034FF8: @ 0x08034FF8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	ldr r0, [r0, #0x34]
	movs r1, #0x1e
	bl sub_8034ED4
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

	thumb_func_start sub_8035028
sub_8035028: @ 0x08035028
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

	thumb_func_start sub_8035064
sub_8035064: @ 0x08035064
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

	thumb_func_start sub_8035098
sub_8035098: @ 0x08035098
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
