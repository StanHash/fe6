
	.include "macro.inc"

	.syntax unified

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
