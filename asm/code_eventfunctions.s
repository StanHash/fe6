	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_0806BB34
func_fe6_0806BB34: @ 0x0806BB34
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xa
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BB5E
	bl IsKleinInNonBlueTeam
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BB5E
	adds r0, r4, #0
	movs r1, #0x31
	movs r2, #0x2e
	bl EventInfoCheckTalk
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806BB60
.L0806BB5E:
	movs r0, #0
.L0806BB60:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806BB68
func_fe6_0806BB68: @ 0x0806BB68
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #7
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BB92
	bl IsKleinInBlueTeam
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BB92
	adds r0, r4, #0
	movs r1, #0x31
	movs r2, #0x2e
	bl EventInfoCheckTalk
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806BB94
.L0806BB92:
	movs r0, #0
.L0806BB94:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806BB9C
func_fe6_0806BB9C: @ 0x0806BB9C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #7
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BBC6
	bl IsKleinInBlueTeam
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BBC6
	adds r0, r4, #0
	movs r1, #0x31
	movs r2, #0x2e
	bl EventInfoCheckTalk
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806BBC8
.L0806BBC6:
	movs r0, #0
.L0806BBC8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806BBD0
func_fe6_0806BBD0: @ 0x0806BBD0
	push {lr}
	ldr r0, .L0806BBEC @ =gPlaySt
	ldrh r0, [r0, #0x10]
	cmp r0, #3
	bls .L0806BBF0
	movs r0, #0x14
	movs r1, #0
	movs r2, #0x2d
	movs r3, #0x18
	bl CheckAnyBlueUnitArea
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806BBF2
	.align 2, 0
.L0806BBEC: .4byte gPlaySt
.L0806BBF0:
	movs r0, #0
.L0806BBF2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806BBF8
func_fe6_0806BBF8: @ 0x0806BBF8
	push {lr}
	ldr r0, .L0806BC14 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	bne .L0806BC10
	bl RandNextB
	movs r1, #0xb
	bl DivRem
	cmp r0, #0
	beq .L0806BC18
.L0806BC10:
	movs r0, #0
	b .L0806BC1A
	.align 2, 0
.L0806BC14: .4byte gPlaySt
.L0806BC18:
	movs r0, #1
.L0806BC1A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806BC20
func_fe6_0806BC20: @ 0x0806BC20
	push {r4, lr}
	adds r4, r0, #0
	bl func_fe6_0806C158
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BC4E
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x1d
	bl EventInfoCheckTalk
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BC52
	adds r0, r4, #0
	movs r1, #0x1d
	movs r2, #1
	bl EventInfoCheckTalk
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BC52
.L0806BC4E:
	movs r0, #0
	b .L0806BC54
.L0806BC52:
	movs r0, #1
.L0806BC54:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806BC5C
func_fe6_0806BC5C: @ 0x0806BC5C
	push {r4, lr}
	ldr r4, .L0806BC98 @ =gPlaySt
	ldrb r0, [r4, #0xf]
	cmp r0, #0x80
	bne .L0806BC9C
	movs r0, #4
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BC9C
	movs r0, #5
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BC9C
	movs r0, #1
	ldrh r4, [r4, #0x10]
	ands r0, r4
	cmp r0, #0
	bne .L0806BC9C
	movs r0, #0x11
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BC9C
	movs r0, #1
	b .L0806BC9E
	.align 2, 0
.L0806BC98: .4byte gPlaySt
.L0806BC9C:
	movs r0, #0
.L0806BC9E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806BCA4
func_fe6_0806BCA4: @ 0x0806BCA4
	push {r4, lr}
	ldr r4, .L0806BCE0 @ =gPlaySt
	ldrb r0, [r4, #0xf]
	cmp r0, #0x80
	bne .L0806BCE4
	movs r0, #5
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BCE4
	movs r0, #6
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BCE4
	movs r0, #1
	ldrh r4, [r4, #0x10]
	ands r0, r4
	cmp r0, #0
	beq .L0806BCE4
	movs r0, #0x11
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BCE4
	movs r0, #1
	b .L0806BCE6
	.align 2, 0
.L0806BCE0: .4byte gPlaySt
.L0806BCE4:
	movs r0, #0
.L0806BCE6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806BCEC
func_fe6_0806BCEC: @ 0x0806BCEC
	push {r4, lr}
	ldr r4, .L0806BD28 @ =gPlaySt
	ldrb r0, [r4, #0xf]
	cmp r0, #0x80
	bne .L0806BD2C
	movs r0, #6
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BD2C
	movs r0, #7
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BD2C
	movs r0, #1
	ldrh r4, [r4, #0x10]
	ands r0, r4
	cmp r0, #0
	bne .L0806BD2C
	movs r0, #0x11
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BD2C
	movs r0, #1
	b .L0806BD2E
	.align 2, 0
.L0806BD28: .4byte gPlaySt
.L0806BD2C:
	movs r0, #0
.L0806BD2E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806BD34
func_fe6_0806BD34: @ 0x0806BD34
	push {r4, lr}
	ldr r4, .L0806BD70 @ =gPlaySt
	ldrb r0, [r4, #0xf]
	cmp r0, #0x80
	bne .L0806BD74
	movs r0, #7
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BD74
	movs r0, #8
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BD74
	movs r0, #1
	ldrh r4, [r4, #0x10]
	ands r0, r4
	cmp r0, #0
	beq .L0806BD74
	movs r0, #0x11
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BD74
	movs r0, #1
	b .L0806BD76
	.align 2, 0
.L0806BD70: .4byte gPlaySt
.L0806BD74:
	movs r0, #0
.L0806BD76:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806BD7C
func_fe6_0806BD7C: @ 0x0806BD7C
	push {r4, lr}
	ldr r4, .L0806BDB8 @ =gPlaySt
	ldrb r0, [r4, #0xf]
	cmp r0, #0x80
	bne .L0806BDBC
	movs r0, #8
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BDBC
	movs r0, #9
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BDBC
	movs r0, #1
	ldrh r4, [r4, #0x10]
	ands r0, r4
	cmp r0, #0
	bne .L0806BDBC
	movs r0, #0x11
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BDBC
	movs r0, #1
	b .L0806BDBE
	.align 2, 0
.L0806BDB8: .4byte gPlaySt
.L0806BDBC:
	movs r0, #0
.L0806BDBE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806BDC4
func_fe6_0806BDC4: @ 0x0806BDC4
	push {r4, lr}
	ldr r4, .L0806BDF4 @ =gPlaySt
	ldrb r0, [r4, #0xf]
	cmp r0, #0x80
	bne .L0806BDF8
	movs r0, #9
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BDF8
	movs r0, #1
	ldrh r4, [r4, #0x10]
	ands r0, r4
	cmp r0, #0
	beq .L0806BDF8
	movs r0, #0x11
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BDF8
	movs r0, #1
	b .L0806BDFA
	.align 2, 0
.L0806BDF4: .4byte gPlaySt
.L0806BDF8:
	movs r0, #0
.L0806BDFA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806BE00
func_fe6_0806BE00: @ 0x0806BE00
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #8
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BE28
	bl IsKleinInNonBlueTeam
	cmp r0, #0
	beq .L0806BE28
	adds r0, r4, #0
	movs r1, #0x31
	movs r2, #0x2e
	bl EventInfoCheckTalk
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806BE2A
.L0806BE28:
	movs r0, #0
.L0806BE2A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806BE30
func_fe6_0806BE30: @ 0x0806BE30
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #5
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BE58
	bl IsKleinInBlueTeam
	cmp r0, #0
	beq .L0806BE58
	adds r0, r4, #0
	movs r1, #0x31
	movs r2, #0x2e
	bl EventInfoCheckTalk
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806BE5A
.L0806BE58:
	movs r0, #0
.L0806BE5A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806BE60
func_fe6_0806BE60: @ 0x0806BE60
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #5
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BE88
	bl IsKleinInBlueTeam
	cmp r0, #0
	beq .L0806BE88
	adds r0, r4, #0
	movs r1, #0x31
	movs r2, #0x2e
	bl EventInfoCheckTalk
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806BE8A
.L0806BE88:
	movs r0, #0
.L0806BE8A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806BE90
func_fe6_0806BE90: @ 0x0806BE90
	push {r4, lr}
	adds r4, r0, #0
	bl func_fe6_0806C3CC
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BEAE
	adds r0, r4, #0
	movs r1, #0x31
	movs r2, #0x2e
	bl EventInfoCheckTalk
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806BEB0
.L0806BEAE:
	movs r0, #0
.L0806BEB0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806BEB8
func_fe6_0806BEB8: @ 0x0806BEB8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #9
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BEE2
	bl func_fe6_0806C3CC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BEE2
	adds r0, r4, #0
	movs r1, #0x31
	movs r2, #0x2e
	bl EventInfoCheckTalk
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806BEE4
.L0806BEE2:
	movs r0, #0
.L0806BEE4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806BEEC
func_fe6_0806BEEC: @ 0x0806BEEC
	push {lr}
	ldr r0, .L0806BF08 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0x80
	bne .L0806BF0C
	movs r0, #0xa
	movs r1, #0xe
	movs r2, #0xa
	movs r3, #0xe
	bl func_fe6_0806AE7C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806BF0E
	.align 2, 0
.L0806BF08: .4byte gPlaySt
.L0806BF0C:
	movs r0, #0
.L0806BF0E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806BF14
func_fe6_0806BF14: @ 0x0806BF14
	push {lr}
	movs r0, #4
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806BF32
	movs r0, #0xda
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806BF32
	movs r0, #1
	b .L0806BF34
.L0806BF32:
	movs r0, #0
.L0806BF34:
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806BF38
func_fe6_0806BF38: @ 0x0806BF38
	ldr r0, .L0806BF68 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bgt .L0806BF6C
	cmp r0, #2
	beq .L0806BF6C
	cmp r0, #3
	beq .L0806BF6C
	cmp r0, #4
	beq .L0806BF6C
	cmp r0, #5
	beq .L0806BF6C
	cmp r0, #6
	beq .L0806BF6C
	cmp r0, #7
	beq .L0806BF6C
	cmp r0, #8
	beq .L0806BF6C
	cmp r0, #0x20
	beq .L0806BF6C
	movs r0, #0
	b .L0806BF6E
	.align 2, 0
.L0806BF68: .4byte gPlaySt
.L0806BF6C:
	movs r0, #1
.L0806BF6E:
	bx lr

	thumb_func_start func_fe6_0806BF70
func_fe6_0806BF70: @ 0x0806BF70
	push {lr}
	movs r0, #0xfe
	bl SoftReset
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806BF7C
func_fe6_0806BF7C: @ 0x0806BF7C
	ldr r0, .L0806BF90 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	bne .L0806BF94
	movs r0, #1
	b .L0806BF96
	.align 2, 0
.L0806BF90: .4byte gKeySt
.L0806BF94:
	movs r0, #0
.L0806BF96:
	bx lr

	thumb_func_start func_fe6_0806BF98
func_fe6_0806BF98: @ 0x0806BF98
	push {lr}
	movs r0, #0xfe
	bl SoftReset
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806BFA4
func_fe6_0806BFA4: @ 0x0806BFA4
	ldr r0, .L0806BFB8 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	bne .L0806BFBC
	movs r0, #0
	b .L0806BFBE
	.align 2, 0
.L0806BFB8: .4byte gKeySt
.L0806BFBC:
	movs r0, #1
.L0806BFBE:
	bx lr

	thumb_func_start func_fe6_0806BFC0
func_fe6_0806BFC0: @ 0x0806BFC0
	push {lr}
	movs r0, #0
	bl SetFogVision
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806BFCC
func_fe6_0806BFCC: @ 0x0806BFCC
	push {lr}
	bl GetGold
	ldr r1, .L0806BFE0 @ =0x00001388
	adds r0, r0, r1
	bl SetGold
	pop {r0}
	bx r0
	.align 2, 0
.L0806BFE0: .4byte 0x00001388

	thumb_func_start func_fe6_0806BFE4
func_fe6_0806BFE4: @ 0x0806BFE4
	push {r4, lr}
	adds r4, r0, #0
	bl GetGold
	cmp r0, r4
	blt .L0806BFFA
	bl GetGold
	subs r0, r0, r4
	bl SetGold
.L0806BFFA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806C000
func_fe6_0806C000: @ 0x0806C000
	adds r1, r0, #0
	ldrb r2, [r1, #0x10]
	movs r0, #0x10
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble .L0806C010
	subs r0, r2, #1
	strb r0, [r1, #0x10]
.L0806C010:
	ldrb r2, [r1, #0x12]
	movs r0, #0x12
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble .L0806C01E
	subs r0, r2, #1
	strb r0, [r1, #0x12]
.L0806C01E:
	ldrb r2, [r1, #0x13]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble .L0806C02C
	subs r0, r2, #1
	strb r0, [r1, #0x13]
.L0806C02C:
	ldrb r2, [r1, #0x14]
	movs r0, #0x14
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble .L0806C03A
	subs r0, r2, #1
	strb r0, [r1, #0x14]
.L0806C03A:
	ldrb r2, [r1, #0x15]
	movs r0, #0x15
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble .L0806C048
	subs r0, r2, #1
	strb r0, [r1, #0x15]
.L0806C048:
	ldrb r2, [r1, #0x16]
	movs r0, #0x16
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble .L0806C056
	subs r0, r2, #1
	strb r0, [r1, #0x16]
.L0806C056:
	ldrb r2, [r1, #0x17]
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble .L0806C064
	subs r0, r2, #1
	strb r0, [r1, #0x17]
.L0806C064:
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0806C068
func_fe6_0806C068: @ 0x0806C068
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetUnitByPid
	bl func_fe6_0806C000
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806C07C
func_fe6_0806C07C: @ 0x0806C07C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #1
.L0806C084:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806C0AA
	ldr r2, [r1]
	cmp r2, #0
	beq .L0806C0AA
	movs r0, #0xc
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L0806C0AA
	ldrb r2, [r2, #4]
	cmp r2, r5
	bne .L0806C0AA
	movs r0, #1
	b .L0806C0B2
.L0806C0AA:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0806C084
	movs r0, #0
.L0806C0B2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C0B8
func_fe6_0806C0B8: @ 0x0806C0B8
	push {lr}
	movs r0, #0x26
	bl func_fe6_0806C07C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C0C8
func_fe6_0806C0C8: @ 0x0806C0C8
	push {lr}
	movs r0, #0x1f
	bl func_fe6_0806C07C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C0D8
func_fe6_0806C0D8: @ 0x0806C0D8
	push {lr}
	movs r0, #0x42
	bl func_fe6_0806C07C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C0E8
func_fe6_0806C0E8: @ 0x0806C0E8
	push {lr}
	movs r0, #0x2c
	bl func_fe6_0806C07C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C0F8
func_fe6_0806C0F8: @ 0x0806C0F8
	push {lr}
	movs r0, #0x3c
	bl func_fe6_0806C07C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C108
func_fe6_0806C108: @ 0x0806C108
	push {lr}
	movs r0, #4
	bl func_fe6_0806C07C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C118
func_fe6_0806C118: @ 0x0806C118
	push {lr}
	movs r0, #6
	bl func_fe6_0806C07C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C128
func_fe6_0806C128: @ 0x0806C128
	push {lr}
	movs r0, #5
	bl func_fe6_0806C07C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C138
func_fe6_0806C138: @ 0x0806C138
	push {lr}
	movs r0, #0x37
	bl func_fe6_0806C07C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C148
func_fe6_0806C148: @ 0x0806C148
	push {lr}
	movs r0, #0x32
	bl func_fe6_0806C07C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C158
func_fe6_0806C158: @ 0x0806C158
	push {lr}
	movs r0, #0x1d
	bl func_fe6_0806C07C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start IsPidInBlueTeam
IsPidInBlueTeam: @ 0x0806C168
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #1
.L0806C170:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806C196
	ldr r2, [r1]
	cmp r2, #0
	beq .L0806C196
	movs r0, #4
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L0806C196
	ldrb r2, [r2, #4]
	cmp r2, r5
	bne .L0806C196
	movs r0, #1
	b .L0806C19E
.L0806C196:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0806C170
	movs r0, #0
.L0806C19E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C1A4
func_fe6_0806C1A4: @ 0x0806C1A4
	push {lr}
	movs r0, #9
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C1B4
func_fe6_0806C1B4: @ 0x0806C1B4
	push {lr}
	movs r0, #0x26
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C1C4
func_fe6_0806C1C4: @ 0x0806C1C4
	push {lr}
	movs r0, #0x11
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C1D4
func_fe6_0806C1D4: @ 0x0806C1D4
	push {lr}
	movs r0, #0x2a
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C1E4
func_fe6_0806C1E4: @ 0x0806C1E4
	push {lr}
	movs r0, #5
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C1F4
func_fe6_0806C1F4: @ 0x0806C1F4
	push {lr}
	movs r0, #0x35
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C204
func_fe6_0806C204: @ 0x0806C204
	push {lr}
	movs r0, #0x37
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C214
func_fe6_0806C214: @ 0x0806C214
	push {lr}
	movs r0, #0x32
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C224
func_fe6_0806C224: @ 0x0806C224
	push {lr}
	movs r0, #0x36
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C234
func_fe6_0806C234: @ 0x0806C234
	push {lr}
	movs r0, #0x2c
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C244
func_fe6_0806C244: @ 0x0806C244
	push {lr}
	movs r0, #0x3c
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C254
func_fe6_0806C254: @ 0x0806C254
	push {lr}
	movs r0, #0x34
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start IsItTeamFae
IsItTeamFae: @ 0x0806C264
	push {lr}
	movs r0, #3
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C274
func_fe6_0806C274: @ 0x0806C274
	push {lr}
	movs r0, #4
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C284
func_fe6_0806C284: @ 0x0806C284
	push {lr}
	movs r0, #6
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start IsKleinInBlueTeam
IsKleinInBlueTeam: @ 0x0806C294
	push {lr}
	movs r0, #0xf
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C2A4
func_fe6_0806C2A4: @ 0x0806C2A4
	push {lr}
	movs r0, #0x2e
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C2B4
func_fe6_0806C2B4: @ 0x0806C2B4
	push {lr}
	movs r0, #0xb
	bl IsPidInBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C2C4
func_fe6_0806C2C4: @ 0x0806C2C4
	push {r4, lr}
	movs r4, #0x41
.L0806C2C8:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806C2E8
	ldr r0, [r1]
	cmp r0, #0
	beq .L0806C2E8
	movs r0, #4
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L0806C2E8
	movs r0, #1
	b .L0806C2F0
.L0806C2E8:
	adds r4, #1
	cmp r4, #0xbf
	ble .L0806C2C8
	movs r0, #0
.L0806C2F0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806C2F8
func_fe6_0806C2F8: @ 0x0806C2F8
	push {lr}
	bl func_fe6_0806C2C4
	movs r1, #0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806C308
	movs r1, #1
.L0806C308:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start IsPidInNonBlueTeam
IsPidInNonBlueTeam: @ 0x0806C310
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #0x41
.L0806C318:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806C33E
	ldr r2, [r1]
	cmp r2, #0
	beq .L0806C33E
	movs r0, #4
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L0806C33E
	ldrb r2, [r2, #4]
	cmp r2, r5
	bne .L0806C33E
	movs r0, #1
	b .L0806C346
.L0806C33E:
	adds r4, #1
	cmp r4, #0xbf
	ble .L0806C318
	movs r0, #0
.L0806C346:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C34C
func_fe6_0806C34C: @ 0x0806C34C
	push {lr}
	movs r0, #0x2e
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C35C
func_fe6_0806C35C: @ 0x0806C35C
	push {lr}
	movs r0, #0x5e
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start IsKleinInNonBlueTeam
IsKleinInNonBlueTeam: @ 0x0806C36C
	push {lr}
	movs r0, #0xf
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C37C
func_fe6_0806C37C: @ 0x0806C37C
	push {lr}
	movs r0, #0x35
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C38C
func_fe6_0806C38C: @ 0x0806C38C
	push {lr}
	movs r0, #0x27
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C39C
func_fe6_0806C39C: @ 0x0806C39C
	push {lr}
	movs r0, #0x33
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C3AC
func_fe6_0806C3AC: @ 0x0806C3AC
	push {lr}
	movs r0, #0xc4
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C3BC
func_fe6_0806C3BC: @ 0x0806C3BC
	push {lr}
	movs r0, #0xc6
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C3CC
func_fe6_0806C3CC: @ 0x0806C3CC
	push {lr}
	movs r0, #0xb
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C3DC
func_fe6_0806C3DC: @ 0x0806C3DC
	push {lr}
	movs r0, #0x1d
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C3EC
func_fe6_0806C3EC: @ 0x0806C3EC
	push {lr}
	movs r0, #0xd5
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C3FC
func_fe6_0806C3FC: @ 0x0806C3FC
	push {lr}
	movs r0, #0xd6
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C40C
func_fe6_0806C40C: @ 0x0806C40C
	push {lr}
	movs r0, #0xd7
	bl IsPidInNonBlueTeam
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C41C
func_fe6_0806C41C: @ 0x0806C41C
	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r6, #0
	adds r4, r5, #1
	b .L0806C450
.L0806C42A:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806C44E
	ldr r2, [r1]
	cmp r2, #0
	beq .L0806C44E
	movs r0, #4
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L0806C44E
	ldrb r2, [r2, #4]
	cmp r2, r7
	bne .L0806C44E
	adds r6, #1
.L0806C44E:
	adds r4, #1
.L0806C450:
	adds r0, r5, #0
	adds r0, #0x40
	cmp r4, r0
	blt .L0806C42A
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C460
func_fe6_0806C460: @ 0x0806C460
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	adds r4, r5, #1
	b .L0806C48C
.L0806C46A:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806C488
	ldr r0, [r1]
	cmp r0, #0
	beq .L0806C488
	movs r0, #4
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L0806C488
	adds r6, #1
.L0806C488:
	adds r4, #1
	adds r0, r5, #0
.L0806C48C:
	adds r0, #0x40
	cmp r4, r0
	blt .L0806C46A
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806C49C
func_fe6_0806C49C: @ 0x0806C49C
	ldr r0, .L0806C4A8 @ =gPlaySt
	ldrh r0, [r0, #0x10]
	cmp r0, #0x14
	bhi .L0806C4AC
	movs r0, #0
	b .L0806C4AE
	.align 2, 0
.L0806C4A8: .4byte gPlaySt
.L0806C4AC:
	movs r0, #1
.L0806C4AE:
	bx lr

	thumb_func_start func_fe6_0806C4B0
func_fe6_0806C4B0: @ 0x0806C4B0
	ldr r0, .L0806C4BC @ =gPlaySt
	ldrh r0, [r0, #0x10]
	cmp r0, #0x19
	bhi .L0806C4C0
	movs r0, #0
	b .L0806C4C2
	.align 2, 0
.L0806C4BC: .4byte gPlaySt
.L0806C4C0:
	movs r0, #1
.L0806C4C2:
	bx lr

	thumb_func_start func_fe6_0806C4C4
func_fe6_0806C4C4: @ 0x0806C4C4
	ldr r0, .L0806C4D0 @ =gPlaySt
	ldrh r0, [r0, #0x10]
	cmp r0, #0x1e
	bhi .L0806C4D4
	movs r0, #0
	b .L0806C4D6
	.align 2, 0
.L0806C4D0: .4byte gPlaySt
.L0806C4D4:
	movs r0, #1
.L0806C4D6:
	bx lr

	thumb_func_start func_fe6_0806C4D8
func_fe6_0806C4D8: @ 0x0806C4D8
	ldr r0, .L0806C4E4 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	bne .L0806C4E8
	movs r0, #1
	b .L0806C4EA
	.align 2, 0
.L0806C4E4: .4byte gPlaySt
.L0806C4E8:
	movs r0, #0
.L0806C4EA:
	bx lr

	thumb_func_start func_fe6_0806C4EC
func_fe6_0806C4EC: @ 0x0806C4EC
	ldr r0, .L0806C4F8 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0x80
	bne .L0806C4FC
	movs r0, #1
	b .L0806C4FE
	.align 2, 0
.L0806C4F8: .4byte gPlaySt
.L0806C4FC:
	movs r0, #0
.L0806C4FE:
	bx lr

	thumb_func_start func_fe6_0806C500
func_fe6_0806C500: @ 0x0806C500
	ldr r0, .L0806C51C @ =gActiveUnit
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, [r1, #0x28]
	ldr r1, [r2, #0x24]
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne .L0806C520
	movs r0, #1
	b .L0806C522
	.align 2, 0
.L0806C51C: .4byte gActiveUnit
.L0806C520:
	movs r0, #0
.L0806C522:
	bx lr

	thumb_func_start func_fe6_0806C524
func_fe6_0806C524: @ 0x0806C524
	push {lr}
	bl GetGold
	ldr r1, .L0806C534 @ =9999
	cmp r0, r1
	ble .L0806C538
	movs r0, #1
	b .L0806C53A
	.align 2, 0
.L0806C534: .4byte 9999
.L0806C538:
	movs r0, #0
.L0806C53A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806C540
func_fe6_0806C540: @ 0x0806C540
	push {lr}
	bl GetGold
	ldr r1, .L0806C550 @ =0x00001F3F
	cmp r0, r1
	ble .L0806C554
	movs r0, #1
	b .L0806C556
	.align 2, 0
.L0806C550: .4byte 0x00001F3F
.L0806C554:
	movs r0, #0
.L0806C556:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806C55C
func_fe6_0806C55C: @ 0x0806C55C
	push {lr}
	bl GetGold
	ldr r1, .L0806C56C @ =0x0000176F
	cmp r0, r1
	ble .L0806C570
	movs r0, #1
	b .L0806C572
	.align 2, 0
.L0806C56C: .4byte 0x0000176F
.L0806C570:
	movs r0, #0
.L0806C572:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806C578
func_fe6_0806C578: @ 0x0806C578
	push {lr}
	bl GetGold
	ldr r1, .L0806C588 @ =0x00001387
	cmp r0, r1
	ble .L0806C58C
	movs r0, #1
	b .L0806C58E
	.align 2, 0
.L0806C588: .4byte 0x00001387
.L0806C58C:
	movs r0, #0
.L0806C58E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806C594
func_fe6_0806C594: @ 0x0806C594
	push {lr}
	bl GetTalkChoiceResult
	cmp r0, #1
	beq .L0806C5A2
	movs r0, #0
	b .L0806C5A4
.L0806C5A2:
	movs r0, #1
.L0806C5A4:
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806C5A8
func_fe6_0806C5A8: @ 0x0806C5A8
	push {r4, r5, lr}
	movs r0, #5
	bl func_fe6_08084F4C
	adds r2, r0, #0
	ldrb r1, [r2, #7]
	lsrs r0, r1, #4
	ldrb r2, [r2, #8]
	lsls r5, r2, #4
	orrs r5, r0
	movs r0, #4
	bl func_fe6_08084F4C
	adds r2, r0, #0
	ldrb r0, [r2, #7]
	lsrs r1, r0, #4
	ldrb r2, [r2, #8]
	lsls r0, r2, #4
	orrs r0, r1
	adds r5, r5, r0
	movs r0, #0x2e
	bl func_fe6_08084F4C
	adds r2, r0, #0
	ldrb r1, [r2, #7]
	lsrs r0, r1, #4
	ldrb r2, [r2, #8]
	lsls r4, r2, #4
	orrs r4, r0
	movs r0, #0x31
	bl func_fe6_08084F4C
	adds r2, r0, #0
	ldrb r0, [r2, #7]
	lsrs r1, r0, #4
	ldrb r2, [r2, #8]
	lsls r0, r2, #4
	orrs r0, r1
	adds r4, r4, r0
	cmp r5, r4
	bhi .L0806C5FE
	movs r0, #0
	b .L0806C600
.L0806C5FE:
	movs r0, #1
.L0806C600:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806C608
func_fe6_0806C608: @ 0x0806C608
	push {lr}
	ldr r1, .L0806C628 @ =gPlaySt
	movs r0, #8
	ldrb r2, [r1, #0x14]
	ands r0, r2
	cmp r0, #0
	bne .L0806C61E
	ldrb r1, [r1, #0x1d]
	lsls r0, r1, #0x1f
	cmp r0, #0
	bne .L0806C624
.L0806C61E:
	movs r0, #4
	bl FadeBgmOut
.L0806C624:
	pop {r0}
	bx r0
	.align 2, 0
.L0806C628: .4byte gPlaySt

	thumb_func_start func_fe6_0806C62C
func_fe6_0806C62C: @ 0x0806C62C
	ldr r0, .L0806C644 @ =gPlaySt
	ldrb r1, [r0, #0x14]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0806C648
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L0806C648
	movs r0, #0
	b .L0806C64A
	.align 2, 0
.L0806C644: .4byte gPlaySt
.L0806C648:
	movs r0, #1
.L0806C64A:
	bx lr

	thumb_func_start func_fe6_0806C64C
func_fe6_0806C64C: @ 0x0806C64C
	push {lr}
	ldr r1, .L0806C668 @ =gUnk_030048A8
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x16
	bl ClearFlag
	bl func_fe6_0802BA08
	ldr r1, .L0806C66C @ =0x0203D358
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L0806C668: .4byte gUnk_030048A8
.L0806C66C: .4byte 0x0203D358

	thumb_func_start func_fe6_0806C670
func_fe6_0806C670: @ 0x0806C670
	push {lr}
	ldr r1, .L0806C688 @ =gUnk_030048A8
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0806C682
	adds r0, #1
	strb r0, [r1]
	bl FreezeMenu
.L0806C682:
	pop {r0}
	bx r0
	.align 2, 0
.L0806C688: .4byte gUnk_030048A8

	thumb_func_start func_fe6_0806C68C
func_fe6_0806C68C: @ 0x0806C68C
	ldr r0, .L0806C698 @ =gUnk_030048A8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bx lr
	.align 2, 0
.L0806C698: .4byte gUnk_030048A8

	thumb_func_start func_fe6_0806C69C
func_fe6_0806C69C: @ 0x0806C69C
	push {lr}
	ldr r1, .L0806C6AC @ =gUnk_030048A8
	movs r0, #0
	strb r0, [r1]
	bl ResumeMenu
	pop {r0}
	bx r0
	.align 2, 0
.L0806C6AC: .4byte gUnk_030048A8

	thumb_func_start func_fe6_0806C6B0
func_fe6_0806C6B0: @ 0x0806C6B0
	push {lr}
	bl func_fe6_0802B9DC
	ldr r1, .L0806C6D0 @ =0x0203D354
	str r0, [r1]
	ldr r0, .L0806C6D4 @ =gActiveUnit
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #0xd
	beq .L0806C6F0
	cmp r0, #0xd
	bgt .L0806C6D8
	cmp r0, #1
	beq .L0806C6E2
	b .L0806C70E
	.align 2, 0
.L0806C6D0: .4byte 0x0203D354
.L0806C6D4: .4byte gActiveUnit
.L0806C6D8:
	cmp r0, #0x1b
	beq .L0806C708
	cmp r0, #0x26
	beq .L0806C6FC
	b .L0806C70E
.L0806C6E2:
	ldr r0, .L0806C6EC @ =gUnk_0866AF5C
	bl StartEvent
	b .L0806C70E
	.align 2, 0
.L0806C6EC: .4byte gUnk_0866AF5C
.L0806C6F0:
	ldr r0, .L0806C6F8 @ =gUnk_0866AFEC
	bl StartEvent
	b .L0806C70E
	.align 2, 0
.L0806C6F8: .4byte gUnk_0866AFEC
.L0806C6FC:
	ldr r0, .L0806C704 @ =gUnk_0866B07C
	bl StartEvent
	b .L0806C70E
	.align 2, 0
.L0806C704: .4byte gUnk_0866B07C
.L0806C708:
	ldr r0, .L0806C714 @ =gUnk_0866B10C
	bl StartEvent
.L0806C70E:
	pop {r0}
	bx r0
	.align 2, 0
.L0806C714: .4byte gUnk_0866B10C

	thumb_func_start func_fe6_0806C718
func_fe6_0806C718: @ 0x0806C718
	push {lr}
	movs r0, #9
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806C72C
	ldr r0, .L0806C730 @ =gUnk_0866AEA8
	bl StartEvent
.L0806C72C:
	pop {r0}
	bx r0
	.align 2, 0
.L0806C730: .4byte gUnk_0866AEA8

	thumb_func_start func_fe6_0806C734
func_fe6_0806C734: @ 0x0806C734
	push {lr}
	movs r0, #0xa
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806C748
	ldr r0, .L0806C74C @ =gUnk_0866AEE0
	bl StartEvent
.L0806C748:
	pop {r0}
	bx r0
	.align 2, 0
.L0806C74C: .4byte gUnk_0866AEE0

	thumb_func_start func_fe6_0806C750
func_fe6_0806C750: @ 0x0806C750
	push {lr}
	movs r0, #0xb
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806C764
	ldr r0, .L0806C768 @ =gUnk_0866AF28
	bl StartEvent
.L0806C764:
	pop {r0}
	bx r0
	.align 2, 0
.L0806C768: .4byte gUnk_0866AF28

	thumb_func_start func_fe6_0806C76C
func_fe6_0806C76C: @ 0x0806C76C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	movs r0, #8
	str r0, [sp]
	movs r0, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0806C7B0 @ =gUnk_08342A98
	ldr r4, .L0806C7B4 @ =gPal+0x240
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0806C7B8 @ =0xFFFFFDC0
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #1
	adds r3, r5, #0
	bl func_fe6_0805B644
	bl EnablePalSync
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806C7B0: .4byte gUnk_08342A98
.L0806C7B4: .4byte gPal+0x240
.L0806C7B8: .4byte 0xFFFFFDC0

	thumb_func_start func_fe6_0806C7BC
func_fe6_0806C7BC: @ 0x0806C7BC
	push {lr}
	adds r1, r0, #0
	adds r1, #0x64
	movs r2, #0
	strh r2, [r1]
	adds r0, #0x66
	strh r2, [r0]
	ldr r0, .L0806C7DC @ =gUnk_08342A98
	movs r1, #0x90
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	pop {r0}
	bx r0
	.align 2, 0
.L0806C7DC: .4byte gUnk_08342A98

	thumb_func_start func_fe6_0806C7E0
func_fe6_0806C7E0: @ 0x0806C7E0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	ldr r0, .L0806C7FC @ =0x0203D35D
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0806C86C
	cmp r0, #1
	bgt .L0806C800
	cmp r0, #0
	beq .L0806C806
	b .L0806C8C6
	.align 2, 0
.L0806C7FC: .4byte 0x0203D35D
.L0806C800:
	cmp r0, #2
	beq .L0806C8A0
	b .L0806C8C6
.L0806C806:
	movs r4, #0
	ldr r0, .L0806C85C @ =0x0203D35C
	ldrb r0, [r0]
	cmp r4, r0
	bge .L0806C8C6
	ldr r5, .L0806C860 @ =gBmSt
.L0806C812:
	adds r0, r4, #0
	bl GetTarget
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #4
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r2, r1, r2
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #4
	movs r3, #0xe
	ldrsh r1, [r5, r3]
	subs r3, r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r2, r1
	subs r1, #1
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r3, r2
	movs r2, #0xff
	ands r1, r2
	ldr r2, .L0806C864 @ =gUnk_0866ACCC
	ldr r3, .L0806C868 @ =0x00002822
	bl PutOamHiRam
	adds r4, #1
	ldr r0, .L0806C85C @ =0x0203D35C
	ldrb r0, [r0]
	cmp r4, r0
	blt .L0806C812
	b .L0806C8C6
	.align 2, 0
.L0806C85C: .4byte 0x0203D35C
.L0806C860: .4byte gBmSt
.L0806C864: .4byte gUnk_0866ACCC
.L0806C868: .4byte 0x00002822
.L0806C86C:
	ldr r1, .L0806C894 @ =gBmSt
	movs r3, #0xc
	ldrsh r0, [r1, r3]
	movs r2, #0xb4
	lsls r2, r2, #2
	movs r3, #0xe
	ldrsh r1, [r1, r3]
	movs r3, #0xb8
	lsls r3, r3, #1
	subs r0, r2, r0
	subs r2, #0xd1
	ands r0, r2
	subs r1, r3, r1
	movs r2, #0xff
	ands r1, r2
	ldr r2, .L0806C898 @ =gUnk_0866ACCC
	ldr r3, .L0806C89C @ =0x00002822
	bl PutOamHiRam
	b .L0806C8C6
	.align 2, 0
.L0806C894: .4byte gBmSt
.L0806C898: .4byte gUnk_0866ACCC
.L0806C89C: .4byte 0x00002822
.L0806C8A0:
	ldr r1, .L0806C908 @ =gBmSt
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	movs r2, #0xd8
	lsls r2, r2, #2
	movs r3, #0xe
	ldrsh r1, [r1, r3]
	movs r3, #0xa0
	lsls r3, r3, #1
	subs r0, r2, r0
	ldr r2, .L0806C90C @ =0x000001FF
	ands r0, r2
	subs r1, r3, r1
	movs r2, #0xff
	ands r1, r2
	ldr r2, .L0806C910 @ =gUnk_0866ACCC
	ldr r3, .L0806C914 @ =0x00002822
	bl PutOamHiRam
.L0806C8C6:
	bl GetGameTime
	adds r5, r0, #0
	movs r0, #1
	mov sb, r0
	ands r5, r0
	cmp r5, #0
	bne .L0806C93C
	mov r6, r8
	adds r6, #0x66
	movs r1, #0
	ldrsh r7, [r6, r1]
	cmp r7, #0
	beq .L0806C918
	mov r4, r8
	adds r4, #0x64
	movs r3, #0
	ldrsh r2, [r4, r3]
	movs r0, #0x10
	movs r1, #0
	bl func_fe6_0806C76C
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble .L0806C93C
	strh r5, [r4]
	strh r5, [r6]
	b .L0806C93C
	.align 2, 0
.L0806C908: .4byte gBmSt
.L0806C90C: .4byte 0x000001FF
.L0806C910: .4byte gUnk_0866ACCC
.L0806C914: .4byte 0x00002822
.L0806C918:
	mov r4, r8
	adds r4, #0x64
	movs r0, #0
	ldrsh r2, [r4, r0]
	movs r0, #0
	movs r1, #0x10
	bl func_fe6_0806C76C
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble .L0806C93C
	strh r7, [r4]
	mov r1, sb
	strh r1, [r6]
.L0806C93C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806C948
func_fe6_0806C948: @ 0x0806C948
	adds r0, #0x64
	movs r1, #0x3c
	strh r1, [r0]
	bx lr

	thumb_func_start func_fe6_0806C950
func_fe6_0806C950: @ 0x0806C950
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x64
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0806C97E
	bl func_fe6_080718E0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806C98A
	ldr r0, .L0806C990 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0806C98A
.L0806C97E:
	ldr r0, .L0806C994 @ =gUnk_0866ACE8
	bl Proc_EndEach
	adds r0, r4, #0
	bl Proc_Break
.L0806C98A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806C990: .4byte gKeySt
.L0806C994: .4byte gUnk_0866ACE8

	thumb_func_start func_fe6_0806C998
func_fe6_0806C998: @ 0x0806C998
	push {r4, r5, lr}
	ldr r1, .L0806C9E8 @ =0x0203D35D
	strb r0, [r1]
	ldr r5, .L0806C9EC @ =gActiveUnit
	ldr r0, [r5]
	bl func_fe6_0802BA44
	ldr r4, .L0806C9F0 @ =0x0203D35C
	bl CountTargets
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806C9E0
	ldr r0, .L0806C9F4 @ =gUnk_0866ACE8
	movs r1, #3
	bl SpawnProc
	movs r0, #0
	bl GetTarget
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r2, #1
	ldrsb r2, [r0, r2]
	movs r0, #0
	bl CameraMoveWatchPosition
	ldr r1, [r5]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	ldrb r1, [r1, #0xf]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl SetMapCursorPosition
.L0806C9E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806C9E8: .4byte 0x0203D35D
.L0806C9EC: .4byte gActiveUnit
.L0806C9F0: .4byte 0x0203D35C
.L0806C9F4: .4byte gUnk_0866ACE8

	thumb_func_start func_fe6_0806C9F8
func_fe6_0806C9F8: @ 0x0806C9F8
	push {r4, lr}
	bl func_fe6_080718E0
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #0
	bne .L0806CA0E
	ldr r0, .L0806CA18 @ =gUnk_0866AD00
	movs r1, #3
	bl SpawnProc
.L0806CA0E:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0806CA18: .4byte gUnk_0866AD00

	thumb_func_start func_fe6_0806CA1C
func_fe6_0806CA1C: @ 0x0806CA1C
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x19
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CA30
func_fe6_0806CA30: @ 0x0806CA30
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x1a
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CA44
func_fe6_0806CA44: @ 0x0806CA44
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x1e
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CA58
func_fe6_0806CA58: @ 0x0806CA58
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x1f
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CA6C
func_fe6_0806CA6C: @ 0x0806CA6C
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x20
	movs r3, #0
	bl func_fe6_08071B80
	movs r0, #0
	bl func_fe6_0806C998
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806CA84
func_fe6_0806CA84: @ 0x0806CA84
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x23
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CA98
func_fe6_0806CA98: @ 0x0806CA98
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x24
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CAAC
func_fe6_0806CAAC: @ 0x0806CAAC
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x25
	movs r3, #0
	bl func_fe6_08071B80
	movs r0, #0
	bl func_fe6_0806C998
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806CAC4
func_fe6_0806CAC4: @ 0x0806CAC4
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x29
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CAD8
func_fe6_0806CAD8: @ 0x0806CAD8
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x2a
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CAEC
func_fe6_0806CAEC: @ 0x0806CAEC
	push {lr}
	movs r0, #0x28
	movs r1, #0x68
	movs r2, #0x2b
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CB00
func_fe6_0806CB00: @ 0x0806CB00
	push {lr}
	movs r0, #0x10
	movs r1, #0x10
	movs r2, #0x2d
	movs r3, #0
	bl func_fe6_08071B80
	movs r0, #1
	bl func_fe6_0806C998
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806CB18
func_fe6_0806CB18: @ 0x0806CB18
	push {lr}
	movs r0, #0x10
	movs r1, #0x38
	movs r2, #0x2e
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CB2C
func_fe6_0806CB2C: @ 0x0806CB2C
	push {lr}
	movs r0, #0x10
	movs r1, #0x10
	movs r2, #0x30
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CB40
func_fe6_0806CB40: @ 0x0806CB40
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x45
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CB54
func_fe6_0806CB54: @ 0x0806CB54
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x1b
	movs r3, #0
	bl func_fe6_08071B80
	movs r0, #0
	bl func_fe6_0806C998
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806CB6C
func_fe6_0806CB6C: @ 0x0806CB6C
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x40
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CB80
func_fe6_0806CB80: @ 0x0806CB80
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x3f
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CB94
func_fe6_0806CB94: @ 0x0806CB94
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x3e
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CBA8
func_fe6_0806CBA8: @ 0x0806CBA8
	push {lr}
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x42
	movs r3, #0
	bl func_fe6_08071B80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806CBBC
func_fe6_0806CBBC: @ 0x0806CBBC
	push {lr}
	ldr r0, .L0806CBD4 @ =gActiveUnit
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #0xd
	beq .L0806CBEA
	cmp r0, #0xd
	bgt .L0806CBD8
	cmp r0, #1
	beq .L0806CBE2
	b .L0806CC04
	.align 2, 0
.L0806CBD4: .4byte gActiveUnit
.L0806CBD8:
	cmp r0, #0x1b
	beq .L0806CBE2
	cmp r0, #0x26
	beq .L0806CBF8
	b .L0806CC04
.L0806CBE2:
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x1c
	b .L0806CBF0
.L0806CBEA:
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x21
.L0806CBF0:
	movs r3, #0
	bl func_fe6_08071B80
	b .L0806CC04
.L0806CBF8:
	movs r0, #0x10
	movs r1, #0x68
	movs r2, #0x26
	movs r3, #0
	bl func_fe6_08071B80
.L0806CC04:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806CC08
func_fe6_0806CC08: @ 0x0806CC08
	movs r1, #0
	ldr r0, .L0806CC1C @ =gActiveUnit
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #1
	bne .L0806CC18
	movs r1, #1
.L0806CC18:
	adds r0, r1, #0
	bx lr
	.align 2, 0
.L0806CC1C: .4byte gActiveUnit

	thumb_func_start func_fe6_0806CC20
func_fe6_0806CC20: @ 0x0806CC20
	movs r1, #0
	ldr r0, .L0806CC34 @ =gActiveUnit
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #0xd
	bne .L0806CC30
	movs r1, #1
.L0806CC30:
	adds r0, r1, #0
	bx lr
	.align 2, 0
.L0806CC34: .4byte gActiveUnit

	thumb_func_start func_fe6_0806CC38
func_fe6_0806CC38: @ 0x0806CC38
	movs r1, #0
	ldr r0, .L0806CC4C @ =gActiveUnit
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #0x26
	bne .L0806CC48
	movs r1, #1
.L0806CC48:
	adds r0, r1, #0
	bx lr
	.align 2, 0
.L0806CC4C: .4byte gActiveUnit

	thumb_func_start func_fe6_0806CC50
func_fe6_0806CC50: @ 0x0806CC50
	movs r1, #0
	ldr r0, .L0806CC64 @ =gActiveUnit
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #0x1b
	bne .L0806CC60
	movs r1, #1
.L0806CC60:
	adds r0, r1, #0
	bx lr
	.align 2, 0
.L0806CC64: .4byte gActiveUnit

	thumb_func_start func_fe6_0806CC68
func_fe6_0806CC68: @ 0x0806CC68
	ldr r0, .L0806CC78 @ =0x0203D354
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne .L0806CC7C
	movs r0, #0
	b .L0806CC7E
	.align 2, 0
.L0806CC78: .4byte 0x0203D354
.L0806CC7C:
	movs r0, #1
.L0806CC7E:
	bx lr

	thumb_func_start func_fe6_0806CC80
func_fe6_0806CC80: @ 0x0806CC80
	movs r1, #0
	ldr r0, .L0806CC90 @ =gAction
	ldrb r0, [r0, #0x11]
	cmp r0, #2
	bne .L0806CC8C
	movs r1, #1
.L0806CC8C:
	adds r0, r1, #0
	bx lr
	.align 2, 0
.L0806CC90: .4byte gAction

	thumb_func_start func_fe6_0806CC94
func_fe6_0806CC94: @ 0x0806CC94
	push {lr}
	movs r0, #0x16
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806CCAA
	ldr r0, .L0806CCB0 @ =gAction
	ldrb r0, [r0, #0x11]
	cmp r0, #0xe
	beq .L0806CCB4
.L0806CCAA:
	movs r0, #0
	b .L0806CCBC
	.align 2, 0
.L0806CCB0: .4byte gAction
.L0806CCB4:
	movs r0, #0x16
	bl SetFlag
	movs r0, #1
.L0806CCBC:
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806CCC0
func_fe6_0806CCC0: @ 0x0806CCC0
	movs r0, #0
	bx lr

	thumb_func_start func_fe6_0806CCC4
func_fe6_0806CCC4: @ 0x0806CCC4
	push {lr}
	movs r0, #0x12
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806CCE4
	movs r0, #0x13
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806CCE4
	movs r0, #0x12
	bl SetFlag
.L0806CCE4:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806CCE8
func_fe6_0806CCE8: @ 0x0806CCE8
	push {r4, r5, r6, lr}
	movs r6, #1
.L0806CCEC:
	adds r0, r6, #0
	bl GetUnit
	adds r5, r0, #0
	cmp r5, #0
	beq .L0806CD26
	ldr r0, [r5]
	cmp r0, #0
	beq .L0806CD26
	ldrb r0, [r0, #4]
	cmp r0, #1
	beq .L0806CD10
	cmp r0, #0xd
	beq .L0806CD10
	cmp r0, #0x26
	beq .L0806CD10
	cmp r0, #0x1b
	bne .L0806CD26
.L0806CD10:
	adds r0, r5, #0
	bl GetUnitCurrentHp
	adds r4, r0, #0
	adds r0, r5, #0
	bl GetUnitMaxHp
	cmp r4, r0
	bge .L0806CD26
	movs r0, #1
	b .L0806CD2E
.L0806CD26:
	adds r6, #1
	cmp r6, #0x3f
	ble .L0806CCEC
	movs r0, #0
.L0806CD2E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806CD34
func_fe6_0806CD34: @ 0x0806CD34
	push {r4, lr}
	movs r4, #1
.L0806CD38:
	adds r0, r4, #0
	bl GetUnit
	cmp r0, #0
	beq .L0806CD68
	ldr r1, [r0]
	cmp r1, #0
	beq .L0806CD68
	ldrb r1, [r1, #4]
	cmp r1, #1
	beq .L0806CD5A
	cmp r1, #0xd
	beq .L0806CD5A
	cmp r1, #0x26
	beq .L0806CD5A
	cmp r1, #0x1b
	bne .L0806CD68
.L0806CD5A:
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x10
	ble .L0806CD68
	movs r0, #1
	b .L0806CD70
.L0806CD68:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0806CD38
	movs r0, #0
.L0806CD70:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806CD78
func_fe6_0806CD78: @ 0x0806CD78
	push {r4, lr}
	movs r4, #0x41
.L0806CD7C:
	adds r0, r4, #0
	bl GetUnit
	cmp r0, #0
	beq .L0806CD9C
	ldr r0, [r0]
	cmp r0, #0
	beq .L0806CD9C
	ldr r0, [r0, #0x28]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L0806CD9C
	movs r0, #0
	b .L0806CDA4
.L0806CD9C:
	adds r4, #1
	cmp r4, #0xbf
	ble .L0806CD7C
	movs r0, #1
.L0806CDA4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806CDAC
func_fe6_0806CDAC: @ 0x0806CDAC
	ldr r0, .L0806CDB8 @ =gPlaySt
	ldrh r0, [r0, #0x10]
	cmp r0, #1
	bhi .L0806CDBC
	movs r0, #0
	b .L0806CDBE
	.align 2, 0
.L0806CDB8: .4byte gPlaySt
.L0806CDBC:
	movs r0, #1
.L0806CDBE:
	bx lr

	thumb_func_start func_fe6_0806CDC0
func_fe6_0806CDC0: @ 0x0806CDC0
	push {lr}
	ldr r0, .L0806CDD8 @ =gActiveUnit
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #0xd
	beq .L0806CDEA
	cmp r0, #0xd
	bgt .L0806CDDC
	cmp r0, #1
	beq .L0806CDE6
	b .L0806CDFA
	.align 2, 0
.L0806CDD8: .4byte gActiveUnit
.L0806CDDC:
	cmp r0, #0x1b
	beq .L0806CDE6
	cmp r0, #0x26
	beq .L0806CDEE
	b .L0806CDFA
.L0806CDE6:
	movs r0, #0xe
	b .L0806CDF0
.L0806CDEA:
	movs r0, #0xf
	b .L0806CDF0
.L0806CDEE:
	movs r0, #0x10
.L0806CDF0:
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806CE06
.L0806CDFA:
	ldr r0, .L0806CE0C @ =0x0203D358
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne .L0806CE10
.L0806CE06:
	movs r0, #0
	b .L0806CE12
	.align 2, 0
.L0806CE0C: .4byte 0x0203D358
.L0806CE10:
	movs r0, #1
.L0806CE12:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806CE18
func_fe6_0806CE18: @ 0x0806CE18
	ldr r0, .L0806CE2C @ =0x0203D358
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L0806CE30
	movs r0, #0
	b .L0806CE32
	.align 2, 0
.L0806CE2C: .4byte 0x0203D358
.L0806CE30:
	movs r0, #1
.L0806CE32:
	bx lr

	thumb_func_start func_fe6_0806CE34
func_fe6_0806CE34: @ 0x0806CE34
	ldr r0, .L0806CE48 @ =0x0203D358
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	ands r0, r1
	cmp r0, #0
	bne .L0806CE4C
	movs r0, #0
	b .L0806CE4E
	.align 2, 0
.L0806CE48: .4byte 0x0203D358
.L0806CE4C:
	movs r0, #1
.L0806CE4E:
	bx lr

	thumb_func_start func_fe6_0806CE50
func_fe6_0806CE50: @ 0x0806CE50
	push {lr}
	movs r0, #0x12
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806CE78
	ldr r0, .L0806CE70 @ =0x0203D358
	ldr r0, [r0]
	ldr r1, .L0806CE74 @ =0x00018002
	ands r0, r1
	cmp r0, #0
	bne .L0806CE78
	movs r0, #1
	b .L0806CE7A
	.align 2, 0
.L0806CE70: .4byte 0x0203D358
.L0806CE74: .4byte 0x00018002
.L0806CE78:
	movs r0, #0
.L0806CE7A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806CE80
func_fe6_0806CE80: @ 0x0806CE80
	push {lr}
	movs r0, #0x14
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806CE9C
	ldr r0, .L0806CEA0 @ =0x0203D358
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L0806CEA4
.L0806CE9C:
	movs r0, #0
	b .L0806CEA6
	.align 2, 0
.L0806CEA0: .4byte 0x0203D358
.L0806CEA4:
	movs r0, #1
.L0806CEA6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806CEAC
func_fe6_0806CEAC: @ 0x0806CEAC
	push {lr}
	movs r0, #0x15
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806CEC8
	ldr r0, .L0806CECC @ =0x0203D358
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne .L0806CED0
.L0806CEC8:
	movs r0, #0
	b .L0806CED2
	.align 2, 0
.L0806CECC: .4byte 0x0203D358
.L0806CED0:
	movs r0, #1
.L0806CED2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806CED8
func_fe6_0806CED8: @ 0x0806CED8
	push {lr}
	movs r0, #2
	bl GetUnitByPid
	ldr r1, .L0806CEEC @ =0x0000FFFD
	ldrh r2, [r0, #0xc]
	ands r1, r2
	strh r1, [r0, #0xc]
	pop {r0}
	bx r0
	.align 2, 0
.L0806CEEC: .4byte 0x0000FFFD

	thumb_func_start func_fe6_0806CEF0
func_fe6_0806CEF0: @ 0x0806CEF0
	push {lr}
	ldr r0, .L0806CF0C @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0x80
	bne .L0806CF34
	movs r0, #6
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806CF10
	movs r0, #1
	b .L0806CF36
	.align 2, 0
.L0806CF0C: .4byte gPlaySt
.L0806CF10:
	movs r0, #5
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806CF22
	movs r0, #6
	bl SetFlag
.L0806CF22:
	movs r0, #4
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806CF34
	movs r0, #5
	bl SetFlag
.L0806CF34:
	movs r0, #0
.L0806CF36:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806CF3C
func_fe6_0806CF3C: @ 0x0806CF3C
	push {lr}
	ldr r0, .L0806CF58 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0x80
	bne .L0806CF80
	movs r0, #0xa
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806CF5C
	movs r0, #1
	b .L0806CF82
	.align 2, 0
.L0806CF58: .4byte gPlaySt
.L0806CF5C:
	movs r0, #9
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806CF6E
	movs r0, #0xa
	bl SetFlag
.L0806CF6E:
	movs r0, #8
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806CF80
	movs r0, #9
	bl SetFlag
.L0806CF80:
	movs r0, #0
.L0806CF82:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806CF88
func_fe6_0806CF88: @ 0x0806CF88
	push {lr}
	movs r0, #6
	movs r1, #1
	bl GetTrapAt
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806CF9C
	movs r0, #0xa
	strb r0, [r1, #3]
.L0806CF9C:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806CFA0
func_fe6_0806CFA0: @ 0x0806CFA0
	push {lr}
	ldr r0, .L0806CFB0 @ =gMusicPlayer_MainBgm
	ldr r1, .L0806CFB4 @ =0x0857B774
	bl m4aMPlayStart
	pop {r0}
	bx r0
	.align 2, 0
.L0806CFB0: .4byte gMusicPlayer_MainBgm
.L0806CFB4: .4byte 0x0857B774

	thumb_func_start func_fe6_0806CFB8
func_fe6_0806CFB8: @ 0x0806CFB8
	push {lr}
	ldr r0, .L0806CFC8 @ =gMusicPlayer_MainBgm
	ldr r1, .L0806CFCC @ =0x0857C95C
	bl m4aMPlayStart
	pop {r0}
	bx r0
	.align 2, 0
.L0806CFC8: .4byte gMusicPlayer_MainBgm
.L0806CFCC: .4byte 0x0857C95C

	thumb_func_start func_fe6_0806CFD0
func_fe6_0806CFD0: @ 0x0806CFD0
	push {lr}
	ldr r0, .L0806CFE0 @ =gMusicPlayer_MainBgm
	ldr r1, .L0806CFE4 @ =0x0857C1E4
	bl m4aMPlayStart
	pop {r0}
	bx r0
	.align 2, 0
.L0806CFE0: .4byte gMusicPlayer_MainBgm
.L0806CFE4: .4byte 0x0857C1E4

	thumb_func_start func_fe6_0806CFE8
func_fe6_0806CFE8: @ 0x0806CFE8
	push {lr}
	ldr r0, .L0806CFF8 @ =gMusicPlayer_MainBgm
	ldr r1, .L0806CFFC @ =0x0857A61C
	bl m4aMPlayStart
	pop {r0}
	bx r0
	.align 2, 0
.L0806CFF8: .4byte gMusicPlayer_MainBgm
.L0806CFFC: .4byte 0x0857A61C

	thumb_func_start func_fe6_0806D000
func_fe6_0806D000: @ 0x0806D000
	push {lr}
	ldr r0, .L0806D018 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0806D012
	movs r0, #0xc4
	bl m4aSongNumStart
.L0806D012:
	pop {r0}
	bx r0
	.align 2, 0
.L0806D018: .4byte gPlaySt

	thumb_func_start func_fe6_0806D01C
func_fe6_0806D01C: @ 0x0806D01C
	push {lr}
	movs r0, #0
	bl func_fe6_080030B4
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806D028
func_fe6_0806D028: @ 0x0806D028
	push {lr}
	ldr r0, .L0806D054 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	bne .L0806D050
	ldr r0, .L0806D058 @ =gActiveUnit
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x34
	beq .L0806D05C
	cmp r0, #0x35
	beq .L0806D05C
	bl RandNextB
	movs r1, #0xb
	bl DivRem
	cmp r0, #0
	beq .L0806D05C
.L0806D050:
	movs r0, #0
	b .L0806D05E
	.align 2, 0
.L0806D054: .4byte gPlaySt
.L0806D058: .4byte gActiveUnit
.L0806D05C:
	movs r0, #1
.L0806D05E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806D064
func_fe6_0806D064: @ 0x0806D064
	push {lr}
	movs r0, #0xf
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806D078
	ldr r0, .L0806D0D8 @ =0x00002710
	bl func_fe6_0806BFE4
.L0806D078:
	movs r0, #0x10
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806D092
	movs r0, #0x27
	bl func_fe6_0806C068
	movs r0, #0xfa
	lsls r0, r0, #5
	bl func_fe6_0806BFE4
.L0806D092:
	movs r0, #0x11
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806D0B0
	movs r0, #0x27
	bl func_fe6_0806C068
	movs r0, #0x27
	bl func_fe6_0806C068
	ldr r0, .L0806D0DC @ =0x00001770
	bl func_fe6_0806BFE4
.L0806D0B0:
	movs r0, #0x12
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806D0D4
	movs r0, #0x27
	bl func_fe6_0806C068
	movs r0, #0x27
	bl func_fe6_0806C068
	movs r0, #0x27
	bl func_fe6_0806C068
	ldr r0, .L0806D0E0 @ =0x00001388
	bl func_fe6_0806BFE4
.L0806D0D4:
	pop {r0}
	bx r0
	.align 2, 0
.L0806D0D8: .4byte 0x00002710
.L0806D0DC: .4byte 0x00001770
.L0806D0E0: .4byte 0x00001388

	thumb_func_start func_fe6_0806D0E4
func_fe6_0806D0E4: @ 0x0806D0E4
	push {lr}
	bl func_fe6_08073324
	movs r0, #1
	bl GetUnitByPid
	movs r1, #0xf
	bl func_fe6_08027DB4
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806D0FC
func_fe6_0806D0FC: @ 0x0806D0FC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl FindSupplyItem
	cmp r0, #0
	blt .L0806D10C
.L0806D108:
	movs r0, #1
	b .L0806D14A
.L0806D10C:
	movs r6, #1
.L0806D10E:
	adds r0, r6, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806D142
	ldr r0, [r1]
	cmp r0, #0
	beq .L0806D142
	movs r0, #4
	ldrh r2, [r1, #0xc]
	ands r0, r2
	cmp r0, #0
	bne .L0806D142
	movs r5, #0
	adds r4, r1, #0
	adds r4, #0x1c
.L0806D130:
	ldrh r0, [r4]
	bl GetItemIid
	cmp r0, r7
	beq .L0806D108
	adds r4, #2
	adds r5, #1
	cmp r5, #4
	ble .L0806D130
.L0806D142:
	adds r6, #1
	cmp r6, #0x3f
	ble .L0806D10E
	movs r0, #0
.L0806D14A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806D150
func_fe6_0806D150: @ 0x0806D150
	push {r4, lr}
	ldr r4, .L0806D158 @ =gUnk_08672458
	b .L0806D16E
	.align 2, 0
.L0806D158: .4byte gUnk_08672458
.L0806D15C:
	ldrb r0, [r4]
	bl func_fe6_0806D0FC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806D16C
	movs r0, #0
	b .L0806D176
.L0806D16C:
	adds r4, #1
.L0806D16E:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0806D15C
	movs r0, #1
.L0806D176:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806D17C
func_fe6_0806D17C: @ 0x0806D17C
	push {lr}
	movs r0, #0x16
	movs r1, #0x17
	bl GetMapChangeIdAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl StartMapChangeEvent
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806D194
func_fe6_0806D194: @ 0x0806D194
	push {r4, lr}
	movs r4, #0
.L0806D198:
	adds r0, r4, #0
	adds r0, #0xd
	bl ClearFlag
	adds r4, #1
	cmp r4, #4
	ble .L0806D198
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806D1AC
func_fe6_0806D1AC: @ 0x0806D1AC
	push {r4, r5, lr}
	movs r5, #0
.L0806D1B0:
	adds r4, r5, #0
	adds r4, #0xd
	adds r0, r4, #0
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806D1C8
	adds r0, r4, #0
	bl SetFlag
	b .L0806D1CE
.L0806D1C8:
	adds r5, #1
	cmp r5, #4
	ble .L0806D1B0
.L0806D1CE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806D1D4
func_fe6_0806D1D4: @ 0x0806D1D4
	ldr r0, .L0806D1EC @ =0x0203D360
	movs r1, #0
	strb r1, [r0]
	ldr r0, .L0806D1F0 @ =0x0203D361
	strb r1, [r0]
	ldr r0, .L0806D1F4 @ =0x0203D362
	strb r1, [r0]
	ldr r1, .L0806D1F8 @ =0x0203D364
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
.L0806D1EC: .4byte 0x0203D360
.L0806D1F0: .4byte 0x0203D361
.L0806D1F4: .4byte 0x0203D362
.L0806D1F8: .4byte 0x0203D364

	thumb_func_start func_fe6_0806D1FC
func_fe6_0806D1FC: @ 0x0806D1FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x46
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0806D21A
	bl EndTalk
.L0806D216:
	movs r0, #0
	b .L0806D34C
.L0806D21A:
	bl IsTalkActive
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #0
	beq .L0806D228
	b .L0806D34A
.L0806D228:
	ldr r6, .L0806D23C @ =0x0203D360
	ldrb r0, [r6]
	cmp r0, #1
	beq .L0806D2C0
	cmp r0, #1
	bgt .L0806D240
	cmp r0, #0
	beq .L0806D246
	b .L0806D34A
	.align 2, 0
.L0806D23C: .4byte 0x0203D360
.L0806D240:
	cmp r0, #2
	beq .L0806D318
	b .L0806D34A
.L0806D246:
	movs r5, #1
	ldr r1, .L0806D2B4 @ =0x0203D361
	ldrb r0, [r1]
	cmp r0, #0
	beq .L0806D252
	adds r5, r0, #0
.L0806D252:
	cmp r5, #0x3f
	bgt .L0806D216
	ldr r0, .L0806D2B8 @ =0x0203D362
	mov r8, r0
.L0806D25A:
	adds r0, r5, #0
	bl GetUnit
	adds r4, r0, #0
	adds r6, r5, #1
	cmp r4, #0
	beq .L0806D2AC
	ldr r1, [r4]
	cmp r1, #0
	beq .L0806D2AC
	movs r0, #0xc
	ldrh r4, [r4, #0xc]
	ands r0, r4
	cmp r0, #0
	bne .L0806D2AC
	ldrb r0, [r1, #4]
	mov r1, r8
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #1
	beq .L0806D2AC
	ldr r0, .L0806D2BC @ =gBattleDefeatTalkList
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq .L0806D2AC
	adds r4, r2, #0
	adds r2, r5, #0
	movs r3, #0
	adds r1, r5, #0
.L0806D298:
	adds r0, r3, #0
	ldrb r7, [r1]
	cmp r4, r7
	beq .L0806D2F0
	adds r2, #0x10
	adds r3, #0x10
	adds r1, #0x10
	ldrb r0, [r2]
	cmp r0, #0
	bne .L0806D298
.L0806D2AC:
	adds r5, r6, #0
	cmp r5, #0x3f
	ble .L0806D25A
	b .L0806D216
	.align 2, 0
.L0806D2B4: .4byte 0x0203D361
.L0806D2B8: .4byte 0x0203D362
.L0806D2BC: .4byte gBattleDefeatTalkList
.L0806D2C0:
	ldr r0, .L0806D2EC @ =0x0203D362
	ldrb r0, [r0]
	bl GetUnitByPid
	adds r4, r0, #0
	movs r1, #0xe
	ldrsb r1, [r4, r1]
	movs r2, #0xf
	ldrsb r2, [r4, r2]
	adds r0, r5, #0
	bl CameraMoveWatchPosition
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	movs r1, #0xf
	ldrsb r1, [r4, r1]
	bl SetMapCursorPosition
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b .L0806D34A
	.align 2, 0
.L0806D2EC: .4byte 0x0203D362
.L0806D2F0:
	ldr r1, .L0806D30C @ =0x0203D364
	adds r0, r5, #0
	adds r0, #0xc
	adds r0, r3, r0
	ldr r0, [r0]
	strh r0, [r1]
	ldr r0, .L0806D310 @ =0x0203D361
	strb r6, [r0]
	ldr r1, .L0806D314 @ =0x0203D360
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b .L0806D34A
	.align 2, 0
.L0806D30C: .4byte 0x0203D364
.L0806D310: .4byte 0x0203D361
.L0806D314: .4byte 0x0203D360
.L0806D318:
	bl SetInitTalkTextFont
	bl ClearTalkText
	bl ClearPutTalkText
	bl ClearTalk
	ldr r0, .L0806D358 @ =0x0203D364
	ldrh r0, [r0]
	bl DecodeMsg
	adds r2, r0, #0
	movs r0, #0xa
	movs r1, #0xe
	adds r3, r5, #0
	bl StartTalkExt
	movs r0, #1
	bl SetTalkPrintColor
	movs r0, #1
	bl SetActiveTalkFace
	strb r4, [r6]
.L0806D34A:
	movs r0, #1
.L0806D34C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0806D358: .4byte 0x0203D364

	thumb_func_start func_fe6_0806D35C
func_fe6_0806D35C: @ 0x0806D35C
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0x41
.L0806D362:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806D380
	ldr r0, [r1]
	cmp r0, #0
	beq .L0806D380
	movs r0, #4
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L0806D380
	adds r5, #1
.L0806D380:
	adds r4, #1
	cmp r4, #0xbf
	ble .L0806D362
	cmp r5, #2
	ble .L0806D38E
	movs r0, #1
	b .L0806D390
.L0806D38E:
	movs r0, #0
.L0806D390:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806D398
func_fe6_0806D398: @ 0x0806D398
	push {lr}
	bl RandNextB
	movs r1, #5
	bl DivRem
	cmp r0, #0
	beq .L0806D3AC
	movs r0, #0
	b .L0806D3AE
.L0806D3AC:
	movs r0, #1
.L0806D3AE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806D3B4
func_fe6_0806D3B4: @ 0x0806D3B4
	push {r4, lr}
	bl func_fe6_0806D398
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806D3D8
	ldr r0, .L0806D3D4 @ =gChapterFlagBits
	ldrb r4, [r0, #3]
	adds r4, #4
	movs r0, #0x80
	bl func_fe6_0806C460
	cmp r4, r0
	beq .L0806D3D8
	movs r0, #1
	b .L0806D3DA
	.align 2, 0
.L0806D3D4: .4byte gChapterFlagBits
.L0806D3D8:
	movs r0, #0
.L0806D3DA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806D3E0
func_fe6_0806D3E0: @ 0x0806D3E0
	push {r4, lr}
	ldr r4, .L0806D404 @ =gChapterFlagBits
	ldrb r0, [r4, #2]
	adds r0, #1
	strb r0, [r4, #2]
	movs r0, #0x80
	bl func_fe6_0806C460
	strb r0, [r4, #3]
	bl EvtCheck_IsHard
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806D408
	ldrb r4, [r4, #2]
	cmp r4, #0xa
	beq .L0806D414
	b .L0806D40E
	.align 2, 0
.L0806D404: .4byte gChapterFlagBits
.L0806D408:
	ldrb r4, [r4, #2]
	cmp r4, #5
	beq .L0806D414
.L0806D40E:
	movs r0, #6
	bl ClearFlag
.L0806D414:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806D41C
func_fe6_0806D41C: @ 0x0806D41C
	push {lr}
	movs r0, #0xa
	movs r1, #0x16
	movs r2, #1
	movs r3, #4
	bl AddFireTrap
	movs r0, #0xe
	movs r1, #0x15
	movs r2, #2
	movs r3, #3
	bl AddFireTrap
	movs r0, #0xe
	movs r1, #0x17
	movs r2, #2
	movs r3, #5
	bl AddFireTrap
	movs r0, #0x11
	movs r1, #0x16
	movs r2, #4
	movs r3, #2
	bl AddFireTrap
	movs r0, #0x13
	movs r1, #0x15
	movs r2, #4
	movs r3, #6
	bl AddFireTrap
	movs r0, #0x17
	movs r1, #0x12
	movs r2, #6
	movs r3, #4
	bl AddFireTrap
	movs r0, #0x19
	movs r1, #0x12
	movs r2, #6
	movs r3, #3
	bl AddFireTrap
	movs r0, #0x17
	movs r1, #0x10
	movs r2, #5
	movs r3, #3
	bl AddFireTrap
	movs r0, #0x18
	movs r1, #9
	movs r2, #5
	movs r3, #2
	bl AddFireTrap
	movs r0, #0x17
	movs r1, #8
	movs r2, #6
	movs r3, #5
	bl AddFireTrap
	movs r0, #0x19
	movs r1, #8
	movs r2, #5
	movs r3, #4
	bl AddFireTrap
	movs r0, #0x14
	movs r1, #1
	movs r2, #7
	movs r3, #5
	bl AddFireTrap
	movs r0, #0x13
	movs r1, #3
	movs r2, #6
	movs r3, #6
	bl AddFireTrap
	movs r0, #0xe
	movs r1, #8
	movs r2, #9
	movs r3, #2
	bl AddFireTrap
	movs r0, #0xf
	movs r1, #9
	movs r2, #3
	movs r3, #3
	bl AddFireTrap
	movs r0, #0xd
	movs r1, #9
	movs r2, #9
	movs r3, #4
	bl AddFireTrap
	movs r0, #0xe
	movs r1, #0xa
	movs r2, #0xb
	movs r3, #3
	bl AddFireTrap
	movs r0, #0xc
	movs r1, #0xc
	movs r2, #1
	movs r3, #5
	bl AddFireTrap
	movs r0, #0xb
	movs r1, #0xb
	movs r2, #1
	movs r3, #3
	bl AddFireTrap
	movs r0, #0xb
	movs r1, #0xd
	movs r2, #7
	movs r3, #3
	bl AddFireTrap
	movs r0, #9
	movs r1, #0xd
	movs r2, #8
	movs r3, #4
	bl AddFireTrap
	movs r0, #9
	movs r1, #0xb
	movs r2, #2
	movs r3, #4
	bl AddFireTrap
	movs r0, #8
	movs r1, #0xc
	movs r2, #6
	movs r3, #2
	bl AddFireTrap
	movs r0, #7
	movs r1, #0xb
	movs r2, #5
	movs r3, #3
	bl AddFireTrap
	movs r0, #7
	movs r1, #0xd
	movs r2, #4
	movs r3, #5
	bl AddFireTrap
	movs r0, #3
	movs r1, #0xa
	movs r2, #1
	movs r3, #3
	bl AddFireTrap
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806D55C
func_fe6_0806D55C: @ 0x0806D55C
	ldr r1, .L0806D564 @ =gPlaySt
	movs r0, #0x20
	strb r0, [r1, #0xe]
	bx lr
	.align 2, 0
.L0806D564: .4byte gPlaySt

	thumb_func_start func_fe6_0806D568
func_fe6_0806D568: @ 0x0806D568
	push {r4, lr}
	sub sp, #4
	movs r4, #8
	str r4, [sp]
	movs r0, #1
	movs r1, #2
	movs r2, #2
	movs r3, #1
	bl AddGasTrap
	str r4, [sp]
	movs r0, #1
	movs r1, #0xe
	movs r2, #1
	movs r3, #7
	bl AddGasTrap
	str r4, [sp]
	movs r0, #0xa
	movs r1, #7
	movs r2, #0
	movs r3, #2
	bl AddGasTrap
	str r4, [sp]
	movs r0, #8
	movs r1, #0xd
	movs r2, #1
	movs r3, #3
	bl AddGasTrap
	str r4, [sp]
	movs r0, #0xb
	movs r1, #2
	movs r2, #2
	movs r3, #5
	bl AddGasTrap
	str r4, [sp]
	movs r0, #0xd
	movs r1, #0xd
	movs r2, #2
	movs r3, #4
	bl AddGasTrap
	str r4, [sp]
	movs r0, #0xe
	movs r1, #0x11
	movs r2, #3
	movs r3, #1
	bl AddGasTrap
	str r4, [sp]
	movs r0, #0xf
	movs r1, #1
	movs r2, #3
	movs r3, #5
	bl AddGasTrap
	str r4, [sp]
	movs r0, #0x14
	movs r1, #0x12
	movs r2, #0
	movs r3, #2
	bl AddGasTrap
	str r4, [sp]
	movs r0, #0x15
	movs r1, #9
	movs r2, #0
	movs r3, #6
	bl AddGasTrap
	str r4, [sp]
	movs r0, #0x17
	movs r1, #0xc
	movs r2, #1
	movs r3, #3
	bl AddGasTrap
	str r4, [sp]
	movs r0, #0x17
	movs r1, #0x14
	movs r2, #1
	movs r3, #7
	bl AddGasTrap
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806D620
func_fe6_0806D620: @ 0x0806D620
	push {r4, r5, lr}
	movs r4, #0
	ldr r5, .L0806D644 @ =gUnk_0867507C
.L0806D626:
	adds r0, r4, #0
	adds r0, #0x1a
	ldr r2, [r5]
	ldr r3, [r5, #4]
	adds r1, r4, #0
	bl func_fe6_08026BA4
	adds r5, #8
	adds r4, #1
	cmp r4, #0x19
	ble .L0806D626
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806D644: .4byte gUnk_0867507C

	thumb_func_start func_fe6_0806D648
func_fe6_0806D648: @ 0x0806D648
	push {lr}
	movs r0, #0xe
	movs r1, #3
	movs r2, #5
	bl AddArrowTrap
	movs r0, #6
	movs r1, #1
	movs r2, #9
	bl AddArrowTrap
	movs r0, #8
	movs r1, #4
	movs r2, #9
	bl AddArrowTrap
	movs r0, #4
	movs r1, #7
	movs r2, #9
	bl AddArrowTrap
	movs r0, #0xd
	movs r1, #8
	movs r2, #9
	bl AddArrowTrap
	movs r0, #0x10
	movs r1, #3
	movs r2, #5
	bl AddArrowTrap
	movs r0, #0x18
	movs r1, #2
	movs r2, #9
	bl AddArrowTrap
	movs r0, #0x1a
	movs r1, #5
	movs r2, #9
	bl AddArrowTrap
	movs r0, #0x16
	movs r1, #9
	movs r2, #9
	bl AddArrowTrap
	movs r0, #0x11
	movs r1, #6
	movs r2, #9
	bl AddArrowTrap
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806D6B4
func_fe6_0806D6B4: @ 0x0806D6B4
	push {r4, lr}
	ldr r4, .L0806D6D4 @ =gUnk_08675750
	bl RandNextB
	movs r1, #6
	bl DivRem
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	bl SetFlag
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806D6D4: .4byte gUnk_08675750

	thumb_func_start func_fe6_0806D6D8
func_fe6_0806D6D8: @ 0x0806D6D8
	push {lr}
	movs r0, #6
	movs r1, #6
	bl func_fe6_08026BC0
	movs r0, #7
	movs r1, #8
	bl func_fe6_08026BC0
	movs r0, #6
	movs r1, #0xa
	bl func_fe6_08026BC0
	movs r0, #7
	movs r1, #0xd
	bl func_fe6_08026BC0
	movs r0, #6
	movs r1, #0xf
	bl func_fe6_08026BC0
	movs r0, #7
	movs r1, #0x11
	bl func_fe6_08026BC0
	movs r0, #0x18
	movs r1, #6
	bl func_fe6_08026BC0
	movs r0, #0x17
	movs r1, #8
	bl func_fe6_08026BC0
	movs r0, #0x18
	movs r1, #0xa
	bl func_fe6_08026BC0
	movs r0, #0x17
	movs r1, #0xd
	bl func_fe6_08026BC0
	movs r0, #0x18
	movs r1, #0x10
	bl func_fe6_08026BC0
	movs r0, #0x17
	movs r1, #0x11
	bl func_fe6_08026BC0
	movs r0, #0xc
	movs r1, #0xe
	movs r2, #3
	bl func_fe6_08026BD0
	movs r0, #0x12
	movs r1, #0xe
	movs r2, #3
	bl func_fe6_08026BD0
	movs r0, #0xa
	movs r1, #7
	movs r2, #1
	bl func_fe6_08026BD0
	movs r0, #0x14
	movs r1, #7
	movs r2, #0
	bl func_fe6_08026BD0
	movs r0, #0xe
	movs r1, #7
	movs r2, #1
	bl func_fe6_08026BD0
	movs r0, #0x10
	movs r1, #7
	movs r2, #0
	bl func_fe6_08026BD0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806D77C
func_fe6_0806D77C: @ 0x0806D77C
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	movs r5, #0
	ldr r7, .L0806D7BC @ =gUnk_08675B90
.L0806D784:
	adds r0, r6, #0
	movs r1, #6
	bl __modsi3
	lsls r0, r0, #2
	adds r4, r0, r7
	ldr r0, [r4]
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806D7B6
	bl RandNextB
	movs r1, #0xb
	bl DivRem
	cmp r0, #0
	bne .L0806D7B6
	ldr r0, [r4]
	bl SetFlag
	adds r5, #1
	cmp r5, #3
	beq .L0806D7C0
.L0806D7B6:
	adds r6, #1
	b .L0806D784
	.align 2, 0
.L0806D7BC: .4byte gUnk_08675B90
.L0806D7C0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806D7C8
func_fe6_0806D7C8: @ 0x0806D7C8
	push {lr}
	bl func_fe6_08013A64
	movs r0, #1
	bl SetNextGameAction
	ldr r0, .L0806D7E0 @ =gUnk_08676220
	movs r1, #4
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0806D7E0: .4byte gUnk_08676220

	thumb_func_start func_fe6_0806D7E4
func_fe6_0806D7E4: @ 0x0806D7E4
	ldr r1, .L0806D7F0 @ =gPlaySt
	movs r0, #3
	ldrb r2, [r1, #0x1e]
	orrs r0, r2
	strb r0, [r1, #0x1e]
	bx lr
	.align 2, 0
.L0806D7F0: .4byte gPlaySt

	thumb_func_start func_fe6_0806D7F4
func_fe6_0806D7F4: @ 0x0806D7F4
	ldr r1, .L0806D804 @ =gPlaySt
	movs r0, #4
	rsbs r0, r0, #0
	ldrb r2, [r1, #0x1e]
	ands r0, r2
	strb r0, [r1, #0x1e]
	bx lr
	.align 2, 0
.L0806D804: .4byte gPlaySt

	thumb_func_start func_fe6_0806D808
func_fe6_0806D808: @ 0x0806D808
	push {lr}
	bl InitUnits
	bl ClearTalk
	movs r0, #1
	bl Proc_EndEachMarked
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806D81C
func_fe6_0806D81C: @ 0x0806D81C
	push {lr}
	ldr r0, .L0806D828 @ =gUnk_08676220
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
.L0806D828: .4byte gUnk_08676220

	thumb_func_start func_fe6_0806D82C
func_fe6_0806D82C: @ 0x0806D82C
	push {lr}
	adds r2, r0, #0
	ldr r0, .L0806D848 @ =gKeySt
	ldr r1, [r0]
	ldr r0, .L0806D84C @ =0x0000030B
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0806D844
	adds r0, r2, #0
	bl Proc_Break
.L0806D844:
	pop {r0}
	bx r0
	.align 2, 0
.L0806D848: .4byte gKeySt
.L0806D84C: .4byte 0x0000030B

	thumb_func_start func_fe6_0806D850
func_fe6_0806D850: @ 0x0806D850
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	bl SetNextGameAction
	adds r4, #0x4c
	movs r0, #0x1f
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806D868
func_fe6_0806D868: @ 0x0806D868
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x4c
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #0x20
	subs r0, r0, r1
	bl DarkenPals
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L0806D88E
	adds r0, r5, #0
	bl Proc_Break
.L0806D88E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806D894
func_fe6_0806D894: @ 0x0806D894
	push {lr}
	movs r0, #0
	bl CleanupGame
	bl SyncHiOam
	bl func_fe6_0806D808
	bl func_fe6_0806D81C
	bl KillTalkAndEvent
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806D8B0
func_fe6_0806D8B0: @ 0x0806D8B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r2, .L0806D994 @ =gDispIo
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
	bl ResetText
	bl ResetTextFont
	bl InitTalkTextFont
	ldr r0, .L0806D998 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	ldr r2, .L0806D99C @ =0x01000008
	mov r0, sp
	bl CpuFastSet
	ldr r0, .L0806D9A0 @ =gUnk_08677FE0
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	movs r5, #0
	ldr r1, .L0806D9A4 @ =gUnk_0867619C
	mov r8, r1
.L0806D91C:
	lsls r4, r5, #3
	ldr r0, .L0806D9A8 @ =0x0203D370
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x18
	bl InitText
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	lsls r1, r5, #2
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r1
	str r4, [r0]
	lsls r1, r5, #1
	ldr r7, .L0806D9AC @ =0x0203D36C
	ldr r0, [r7]
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0, #2]
	adds r1, r0, r1
	lsls r1, r1, #6
	ldr r0, .L0806D9B0 @ =gBg0Tm+0x6
	adds r1, r1, r0
	adds r0, r4, #0
	bl PutText
	adds r5, #1
	cmp r5, #5
	ble .L0806D91C
	movs r1, #0
	str r1, [r6, #0x30]
	adds r0, r6, #0
	adds r0, #0x5c
	strh r1, [r0]
	ldr r1, .L0806D9A4 @ =gUnk_0867619C
	ldr r0, [r7]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	bl DecodeMsg
	str r0, [r6, #0x2c]
	ldr r0, [r7]
	adds r0, #1
	str r0, [r7]
	movs r0, #1
	bl EnableBgSync
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806D994: .4byte gDispIo
.L0806D998: .4byte gBg0Tm
.L0806D99C: .4byte 0x01000008
.L0806D9A0: .4byte gUnk_08677FE0
.L0806D9A4: .4byte gUnk_0867619C
.L0806D9A8: .4byte 0x0203D370
.L0806D9AC: .4byte 0x0203D36C
.L0806D9B0: .4byte gBg0Tm+0x6

	thumb_func_start func_fe6_0806D9B4
func_fe6_0806D9B4: @ 0x0806D9B4
	push {lr}
	sub sp, #4
	ldr r2, .L0806D9E8 @ =gDispIo
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
	movs r0, #0
	str r0, [sp]
	ldr r1, .L0806D9EC @ =0x06006000
	ldr r2, .L0806D9F0 @ =0x01000800
	mov r0, sp
	bl CpuFastSet
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
.L0806D9E8: .4byte gDispIo
.L0806D9EC: .4byte 0x06006000
.L0806D9F0: .4byte 0x01000800

	thumb_func_start func_fe6_0806D9F4
func_fe6_0806D9F4: @ 0x0806D9F4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r5, r1, #0
	adds r6, r2, #0
	bl InitUnits
	ldr r4, .L0806DA4C @ =gPlaySt
	mov r0, r8
	strb r0, [r4, #0xe]
	bl func_fe6_08029084
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	bl GetChapterInfo
	ldrb r0, [r0, #0xc]
	strb r0, [r4, #0xd]
	lsls r5, r5, #4
	adds r5, #8
	adds r0, r5, #0
	bl GetCameraCenteredX
	ldr r4, .L0806DA50 @ =gBmSt
	strh r0, [r4, #0xc]
	lsls r6, r6, #4
	adds r6, #8
	adds r0, r6, #0
	bl GetCameraCenteredY
	strh r0, [r4, #0xe]
	bl RefreshEntityMaps
	bl RenderMap
	bl RefreshUnitSprites
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0806DA4C: .4byte gPlaySt
.L0806DA50: .4byte gBmSt

	thumb_func_start func_fe6_0806DA54
func_fe6_0806DA54: @ 0x0806DA54
	push {r4, lr}
	movs r0, #4
	movs r1, #0xb
	movs r2, #0xb
	bl func_fe6_0806D9F4
	ldr r4, .L0806DA88 @ =gPal+0x160
	adds r1, r4, #0
	subs r1, #0xa0
	adds r0, r4, #0
	movs r2, #0x28
	bl CpuFastSet
	ldr r0, .L0806DA8C @ =0xFFFFFEA0
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #6
	movs r3, #8
	bl func_fe6_0805B644
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806DA88: .4byte gPal+0x160
.L0806DA8C: .4byte 0xFFFFFEA0

	thumb_func_start func_fe6_0806DA90
func_fe6_0806DA90: @ 0x0806DA90
	push {lr}
	movs r0, #1
	movs r1, #7
	movs r2, #5
	bl func_fe6_0806D9F4
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806DAA0
func_fe6_0806DAA0: @ 0x0806DAA0
	push {lr}
	movs r0, #0xa
	movs r1, #0
	movs r2, #0x14
	bl func_fe6_0806D9F4
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806DAB0
func_fe6_0806DAB0: @ 0x0806DAB0
	push {lr}
	movs r0, #2
	movs r1, #7
	movs r2, #0xa
	bl func_fe6_0806D9F4
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806DAC0
func_fe6_0806DAC0: @ 0x0806DAC0
	push {lr}
	movs r0, #0x16
	movs r1, #0xf
	movs r2, #9
	bl func_fe6_0806D9F4
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806DAD0
func_fe6_0806DAD0: @ 0x0806DAD0
	push {r4, lr}
	movs r0, #1
	bl GetUnitByPid
	adds r4, r0, #0
	bl GetUnitCurrentHp
	adds r1, r0, #0
	subs r1, #0xa
	adds r0, r4, #0
	bl SetUnitHp
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806DAF0
func_fe6_0806DAF0: @ 0x0806DAF0
	ldr r0, .L0806DAFC @ =gUnk_08676738
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bx lr
	.align 2, 0
.L0806DAFC: .4byte gUnk_08676738

	thumb_func_start func_fe6_0806DB00
func_fe6_0806DB00: @ 0x0806DB00
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, .L0806DB20 @ =gUnk_08676738
	lsls r0, r4, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl StartEventLocking
	ldr r0, .L0806DB24 @ =0x0203D368
	str r4, [r0]
	ldr r1, .L0806DB28 @ =0x0203D36C
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806DB20: .4byte gUnk_08676738
.L0806DB24: .4byte 0x0203D368
.L0806DB28: .4byte 0x0203D36C

	thumb_func_start func_fe6_0806DB2C
func_fe6_0806DB2C: @ 0x0806DB2C
	push {lr}
	movs r0, #1
	bl Proc_EndEachMarked
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806DB38
func_fe6_0806DB38: @ 0x0806DB38
	push {lr}
	bl GetGameTime
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L0806DB50
	ldr r1, .L0806DB54 @ =gBmSt
	movs r0, #2
	ldrh r2, [r1, #0xc]
	eors r0, r2
	strh r0, [r1, #0xc]
.L0806DB50:
	pop {r0}
	bx r0
	.align 2, 0
.L0806DB54: .4byte gBmSt

	thumb_func_start func_fe6_0806DB58
func_fe6_0806DB58: @ 0x0806DB58
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0806DB7C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0806DB6C
	ldr r0, .L0806DB80 @ =0x0000026A
	bl m4aSongNumStart
.L0806DB6C:
	ldr r0, .L0806DB84 @ =gUnk_08676844
	adds r1, r4, #0
	bl SpawnProc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806DB7C: .4byte gPlaySt
.L0806DB80: .4byte 0x0000026A
.L0806DB84: .4byte gUnk_08676844

	thumb_func_start func_fe6_0806DB88
func_fe6_0806DB88: @ 0x0806DB88
	push {lr}
	ldr r0, .L0806DB9C @ =gUnk_08676844
	bl Proc_EndEach
	movs r0, #4
	bl func_fe6_080030B4
	pop {r0}
	bx r0
	.align 2, 0
.L0806DB9C: .4byte gUnk_08676844

	thumb_func_start func_fe6_0806DBA0
func_fe6_0806DBA0: @ 0x0806DBA0
	adds r0, #0x64
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start func_fe6_0806DBA8
func_fe6_0806DBA8: @ 0x0806DBA8
	push {r4, lr}
	adds r4, r0, #0
	bl GetGameTime
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L0806DBDA
	ldr r1, .L0806DC20 @ =gBmSt
	movs r0, #2
	ldrh r2, [r1, #0xc]
	eors r0, r2
	strh r0, [r1, #0xc]
	adds r1, r4, #0
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble .L0806DBDA
	adds r0, r4, #0
	bl Proc_Break
.L0806DBDA:
	ldr r4, .L0806DC20 @ =gBmSt
	ldrh r0, [r4, #0x24]
	lsls r1, r0, #4
	ldrh r2, [r4, #0xc]
	subs r1, r2, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r4, #0x26]
	lsls r2, r0, #4
	ldrh r0, [r4, #0xe]
	subs r2, r0, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #2
	bl SetBgOffset
	ldrh r2, [r4, #0x24]
	lsls r1, r2, #4
	ldrh r0, [r4, #0xc]
	subs r1, r0, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r4, #0x26]
	lsls r2, r0, #4
	ldrh r4, [r4, #0xe]
	subs r2, r4, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #3
	bl SetBgOffset
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806DC20: .4byte gBmSt

	thumb_func_start func_fe6_0806DC24
func_fe6_0806DC24: @ 0x0806DC24
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0806DC34 @ =gUnk_08676854
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0806DC34: .4byte gUnk_08676854

	thumb_func_start func_fe6_0806DC38
func_fe6_0806DC38: @ 0x0806DC38
	push {lr}
	ldr r0, .L0806DC44 @ =gUnk_08676854
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
.L0806DC44: .4byte gUnk_08676854

	thumb_func_start func_fe6_0806DC48
func_fe6_0806DC48: @ 0x0806DC48
	adds r0, #0x64
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start func_fe6_0806DC50
func_fe6_0806DC50: @ 0x0806DC50
	push {r4, lr}
	adds r4, r0, #0
	bl GetGameTime
	movs r1, #7
	ands r1, r0
	cmp r1, #0
	bne .L0806DC8A
	adds r0, r4, #0
	adds r0, #0x64
	ldrh r1, [r0]
	adds r2, r1, #1
	strh r2, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xb
	ble .L0806DC78
	adds r0, r4, #0
	bl Proc_Break
.L0806DC78:
	movs r3, #1
	rsbs r3, r3, #0
	movs r0, #0
	movs r1, #0x20
	movs r2, #0x20
	bl func_fe6_08001E68
	bl func_fe6_080024A4
.L0806DC8A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806DC90
func_fe6_0806DC90: @ 0x0806DC90
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0806DCA0 @ =gUnk_0867686C
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0806DCA0: .4byte gUnk_0867686C

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
	ldr r0, .L0806DEEC @ =func_fe6_0806C1B4
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
.L0806DEEC: .4byte func_fe6_0806C1B4
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
	bl IsItTeamFae
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
