	.include "macro.inc"
	.syntax unified

	thumb_func_start _SetupBanim
_SetupBanim: @ 0x08049058
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	movs r0, #1
	str r0, [sp, #0x18]
	ldr r1, .L0804907C @ =gBattleSt
	movs r0, #0x20
	ldrb r1, [r1, #1]
	ands r0, r1
	cmp r0, #0
	bne .L08049080
	movs r0, #0
	bl SetBanimArenaFlag
	b .L08049086
	.align 2, 0
.L0804907C: .4byte gBattleSt
.L08049080:
	movs r0, #1
	bl SetBanimArenaFlag
.L08049086:
	ldr r1, .L0804909C @ =gBmSt
	movs r0, #0x40
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	bne .L080490A0
	movs r0, #0
	bl SetBanimLinkArenaFlag
	b .L080490A6
	.align 2, 0
.L0804909C: .4byte gBmSt
.L080490A0:
	movs r0, #1
	bl SetBanimLinkArenaFlag
.L080490A6:
	ldr r1, .L080490C0 @ =gBattleSt
	movs r0, #0x10
	ldrb r1, [r1, #1]
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq .L080490C8
	ldr r1, .L080490C4 @ =gEkrDistanceType
	movs r0, #4
	strh r0, [r1]
	adds r0, r1, #0
	b .L080490CC
	.align 2, 0
.L080490C0: .4byte gBattleSt
.L080490C4: .4byte gEkrDistanceType
.L080490C8:
	ldr r0, .L080490F8 @ =gEkrDistanceType
	strh r2, [r0]
.L080490CC:
	ldrh r0, [r0]
	cmp r0, #4
	bne .L08049114
	ldr r1, .L080490FC @ =gpEkrBattleUnitLeft
	ldr r0, .L08049100 @ =gBattleUnitA
	str r0, [r1]
	str r0, [sp]
	ldr r1, .L08049104 @ =gpEkrBattleUnitRight
	ldr r0, .L08049108 @ =gBattleUnitB
	str r0, [r1]
	str r0, [sp, #4]
	ldr r1, .L0804910C @ =0x0203CCFC
	movs r0, #0
	strh r0, [r1, #2]
	strh r0, [r1]
	ldr r0, .L08049110 @ =gBanimValid
	movs r1, #1
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r7, [sp]
	adds r3, r0, #0
	b .L0804920E
	.align 2, 0
.L080490F8: .4byte gEkrDistanceType
.L080490FC: .4byte gpEkrBattleUnitLeft
.L08049100: .4byte gBattleUnitA
.L08049104: .4byte gpEkrBattleUnitRight
.L08049108: .4byte gBattleUnitB
.L0804910C: .4byte 0x0203CCFC
.L08049110: .4byte gBanimValid
.L08049114:
	ldr r5, .L0804914C @ =gBattleUnitA
	movs r4, #0x40
	rsbs r4, r4, #0
	adds r0, r4, #0
	ldrb r1, [r5, #0xb]
	ands r0, r1
	bl GetBanimFactionPalette
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, .L08049150 @ =gBattleUnitB
	ldrb r0, [r0, #0xb]
	ands r4, r0
	adds r0, r4, #0
	bl GetBanimFactionPalette
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r1, .L08049154 @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	cmp r0, #0
	beq .L08049158
	movs r2, #2
	str r2, [sp, #0x18]
	b .L0804917C
	.align 2, 0
.L0804914C: .4byte gBattleUnitA
.L08049150: .4byte gBattleUnitB
.L08049154: .4byte gBattleSt
.L08049158:
	adds r1, r5, #0
	adds r1, #0x4a
	ldrh r0, [r1]
	cmp r0, #0
	bne .L08049168
	movs r3, #2
	str r3, [sp, #0x18]
	b .L0804917C
.L08049168:
	ldrh r0, [r1]
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetWeaponAnimActorCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x18]
.L0804917C:
	ldr r1, .L080491D0 @ =gBanimValid
	movs r0, #1
	strh r0, [r1, #2]
	strh r0, [r1]
	movs r4, #0
	bl GetBanimLinkArenaFlag
	cmp r0, #1
	beq .L080491A4
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	beq .L080491A2
	cmp r0, #2
	beq .L080491A2
	cmp r0, #1
	bne .L080491A4
	cmp r6, #1
	bne .L080491A4
.L080491A2:
	movs r4, #1
.L080491A4:
	adds r2, r4, #0
	cmp r2, #1
	bne .L080491E8
	ldr r1, .L080491D4 @ =gpEkrBattleUnitLeft
	ldr r0, .L080491D8 @ =gBattleUnitB
	str r0, [r1]
	str r0, [sp]
	ldr r1, .L080491DC @ =gpEkrBattleUnitRight
	ldr r0, .L080491E0 @ =gBattleUnitA
	str r0, [r1]
	str r0, [sp, #4]
	ldr r0, .L080491E4 @ =0x0203CCFC
	movs r1, #0
	strh r2, [r0]
	strh r1, [r0, #2]
	ldr r7, [sp, #4]
	ldr r3, .L080491D0 @ =gBanimValid
	ldr r4, [sp, #0x18]
	cmp r4, #1
	bne .L0804920E
	strh r1, [r3]
	b .L0804920E
	.align 2, 0
.L080491D0: .4byte gBanimValid
.L080491D4: .4byte gpEkrBattleUnitLeft
.L080491D8: .4byte gBattleUnitB
.L080491DC: .4byte gpEkrBattleUnitRight
.L080491E0: .4byte gBattleUnitA
.L080491E4: .4byte 0x0203CCFC
.L080491E8:
	ldr r1, .L080492C4 @ =gpEkrBattleUnitLeft
	ldr r0, .L080492C8 @ =gBattleUnitA
	str r0, [r1]
	str r0, [sp]
	ldr r1, .L080492CC @ =gpEkrBattleUnitRight
	ldr r0, .L080492D0 @ =gBattleUnitB
	str r0, [r1]
	str r0, [sp, #4]
	ldr r1, .L080492D4 @ =0x0203CCFC
	movs r2, #0
	strh r2, [r1]
	movs r0, #1
	strh r0, [r1, #2]
	ldr r7, [sp]
	ldr r3, .L080492D8 @ =gBanimValid
	ldr r0, [sp, #0x18]
	cmp r0, #1
	bne .L0804920E
	strh r2, [r3, #2]
.L0804920E:
	ldr r1, [sp]
	str r1, [sp, #0x10]
	ldr r2, [sp, #4]
	mov sl, r2
	ldr r4, [r1]
	str r4, [sp, #8]
	ldr r0, [r2]
	str r0, [sp, #0xc]
	movs r1, #0
	mov sb, r1
	mov r8, r1
	ldrh r1, [r3, #2]
	ldrh r2, [r3]
	str r2, [sp, #0x14]
	movs r4, #0
	ldrsh r6, [r3, r4]
	cmp r6, #0
	beq .L0804923A
	ldr r2, [sp, #0x10]
	ldr r0, [r2, #4]
	ldr r0, [r0, #0x30]
	mov r8, r0
.L0804923A:
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	str r0, [sp, #0x20]
	cmp r5, #0
	beq .L0804924C
	mov r3, sl
	ldr r0, [r3, #4]
	ldr r0, [r0, #0x30]
	mov sb, r0
.L0804924C:
	cmp r6, #0
	beq .L08049278
	ldr r3, .L080492DC @ =gEkrBmLocation
	ldr r4, [sp, #0x10]
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	lsls r0, r0, #4
	ldr r2, .L080492E0 @ =gBmSt
	movs r4, #0xc
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r3]
	ldr r1, [sp, #0x10]
	movs r0, #0xf
	ldrsb r0, [r1, r0]
	lsls r0, r0, #4
	movs r4, #0xe
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r3, #2]
.L08049278:
	cmp r5, #0
	beq .L080492A4
	ldr r3, .L080492DC @ =gEkrBmLocation
	mov r1, sl
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	lsls r0, r0, #4
	ldr r2, .L080492E0 @ =gBmSt
	movs r4, #0xc
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r3, #4]
	mov r1, sl
	movs r0, #0xf
	ldrsb r0, [r1, r0]
	lsls r0, r0, #4
	movs r4, #0xe
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r3, #6]
.L080492A4:
	ldr r4, .L080492E4 @ =gEkrDistanceType
	ldrh r0, [r4]
	cmp r0, #4
	beq .L08049372
	adds r0, r7, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemAttributes
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq .L080492E8
	movs r0, #2
	strh r0, [r4]
	b .L0804936A
	.align 2, 0
.L080492C4: .4byte gpEkrBattleUnitLeft
.L080492C8: .4byte gBattleUnitA
.L080492CC: .4byte gpEkrBattleUnitRight
.L080492D0: .4byte gBattleUnitB
.L080492D4: .4byte 0x0203CCFC
.L080492D8: .4byte gBanimValid
.L080492DC: .4byte gEkrBmLocation
.L080492E0: .4byte gBmSt
.L080492E4: .4byte gEkrDistanceType
.L080492E8:
	movs r0, #3
	strh r0, [r4]
	adds r0, r6, r5
	cmp r0, #2
	bne .L0804936A
	ldr r0, .L0804930C @ =gEkrBmLocation
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #4
	ldrsh r2, [r0, r3]
	subs r1, r1, r2
	adds r2, r0, #0
	cmp r1, #0
	blt .L08049310
	ldrh r4, [r2]
	ldrh r1, [r2, #4]
	subs r0, r4, r1
	b .L08049316
	.align 2, 0
.L0804930C: .4byte gEkrBmLocation
.L08049310:
	ldrh r3, [r2, #4]
	ldrh r4, [r2]
	subs r0, r3, r4
.L08049316:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r3, r0, #0
	movs r1, #2
	ldrsh r0, [r2, r1]
	movs r4, #6
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	cmp r0, #0
	blt .L08049330
	ldrh r1, [r2, #2]
	ldrh r4, [r2, #6]
	b .L08049334
.L08049330:
	ldrh r1, [r2, #6]
	ldrh r4, [r2, #2]
.L08049334:
	subs r0, r1, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r1, r0
	cmp r0, #1
	bgt .L08049354
	ldr r1, .L08049350 @ =gEkrDistanceType
	movs r0, #0
	b .L08049368
	.align 2, 0
.L08049350: .4byte gEkrDistanceType
.L08049354:
	cmp r0, #3
	bgt .L08049364
	ldr r1, .L08049360 @ =gEkrDistanceType
	movs r0, #1
	b .L08049368
	.align 2, 0
.L08049360: .4byte gEkrDistanceType
.L08049364:
	ldr r1, .L080493A0 @ =gEkrDistanceType
	movs r0, #2
.L08049368:
	strh r0, [r1]
.L0804936A:
	ldr r0, .L080493A0 @ =gEkrDistanceType
	ldrh r0, [r0]
	cmp r0, #4
	bne .L080493AC
.L08049372:
	ldr r0, [sp]
	adds r0, #0x48
	ldrh r1, [r0]
	mov r0, r8
	bl GetBattleAnimationId_WithUnique
	ldr r5, .L080493A4 @ =gBanimIdx
	ldr r4, .L080493A8 @ =gBanimIdx_bak
	strh r0, [r4]
	strh r0, [r5]
	ldr r0, [sp, #4]
	adds r0, #0x48
	ldrh r1, [r0]
	mov r0, sb
	bl GetBattleAnimationId_WithUnique
	strh r0, [r4, #2]
	strh r0, [r5, #2]
	ldr r0, [sp, #0x14]
	lsls r0, r0, #0x10
	str r0, [sp, #0x1c]
	b .L080493E4
	.align 2, 0
.L080493A0: .4byte gEkrDistanceType
.L080493A4: .4byte gBanimIdx
.L080493A8: .4byte gBanimIdx_bak
.L080493AC:
	ldr r1, [sp, #0x14]
	lsls r0, r1, #0x10
	str r0, [sp, #0x1c]
	cmp r0, #0
	beq .L080493CA
	ldr r0, [sp]
	adds r0, #0x4a
	ldrh r1, [r0]
	mov r0, r8
	bl GetBattleAnimationId_WithUnique
	ldr r2, .L08049514 @ =gBanimIdx
	ldr r1, .L08049518 @ =gBanimIdx_bak
	strh r0, [r1]
	strh r0, [r2]
.L080493CA:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	beq .L080493E4
	ldr r0, [sp, #4]
	adds r0, #0x4a
	ldrh r1, [r0]
	mov r0, sb
	bl GetBattleAnimationId_WithUnique
	ldr r2, .L08049514 @ =gBanimIdx
	ldr r1, .L08049518 @ =gBanimIdx_bak
	strh r0, [r1, #2]
	strh r0, [r2, #2]
.L080493E4:
	ldr r3, [sp, #0x1c]
	asrs r7, r3, #0x10
	cmp r7, #0
	beq .L080493F6
	ldr r0, [sp, #0x10]
	bl func_fe6_0804A49C
	ldr r1, .L0804951C @ =gBanimUniquePal
	strh r0, [r1]
.L080493F6:
	ldr r4, [sp, #0x20]
	asrs r4, r4, #0x10
	mov r8, r4
	cmp r4, #0
	beq .L0804940A
	mov r0, sl
	bl func_fe6_0804A49C
	ldr r1, .L0804951C @ =gBanimUniquePal
	strh r0, [r1, #2]
.L0804940A:
	cmp r7, #0
	beq .L08049422
	ldr r0, .L08049514 @ =gBanimIdx
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [sp]
	adds r1, #0x4a
	ldrh r1, [r1]
	bl FilterBattleAnimCharacterPalette
	ldr r1, .L08049520 @ =0x0203CD90
	str r0, [r1]
.L08049422:
	mov r2, r8
	cmp r2, #0
	beq .L0804943C
	ldr r0, .L08049514 @ =gBanimIdx
	movs r3, #2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, #4]
	adds r1, #0x4a
	ldrh r1, [r1]
	bl FilterBattleAnimCharacterPalette
	ldr r1, .L08049520 @ =0x0203CD90
	str r0, [r1, #4]
.L0804943C:
	ldr r4, .L08049524 @ =0x0203CDC0
	mov sb, r4
	ldr r2, [sp]
	adds r2, #0x53
	ldrb r0, [r2]
	strh r0, [r4]
	ldr r6, [sp, #4]
	adds r6, #0x53
	ldrb r0, [r6]
	strh r0, [r4, #2]
	ldr r5, .L08049528 @ =gBanimFloorfx
	ldr r1, .L0804952C @ =0x0000FFFF
	adds r0, r1, #0
	ldrh r1, [r5, #2]
	orrs r1, r0
	strh r1, [r5, #2]
	ldrh r3, [r5]
	orrs r0, r3
	strh r0, [r5]
	cmp r7, #0
	beq .L0804947E
	ldrb r4, [r2]
	ldr r0, .L08049530 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	ldrb r1, [r0, #0x12]
	adds r0, r4, #0
	bl func_fe6_08049C5C
	strh r0, [r5]
.L0804947E:
	mov r4, r8
	cmp r4, #0
	beq .L0804949C
	ldrb r4, [r6]
	ldr r0, .L08049530 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	ldrb r1, [r0, #0x12]
	adds r0, r4, #0
	bl func_fe6_08049C5C
	strh r0, [r5, #2]
.L0804949C:
	ldr r1, .L08049534 @ =gBmSt
	movs r0, #0x40
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L080494EA
	movs r0, #0x30
	mov r1, sb
	strh r0, [r1]
	strh r0, [r1, #2]
	cmp r7, #0
	beq .L080494CA
	ldr r0, .L08049530 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	ldrb r1, [r0, #0x12]
	movs r0, #0x30
	bl func_fe6_08049C5C
	strh r0, [r5]
.L080494CA:
	mov r2, r8
	cmp r2, #0
	beq .L080494EA
	mov r3, sb
	ldrh r4, [r3, #2]
	ldr r0, .L08049530 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	ldrb r1, [r0, #0x12]
	adds r0, r4, #0
	bl func_fe6_08049C5C
	strh r0, [r5, #2]
.L080494EA:
	ldr r0, .L08049538 @ =gEkrDistanceType
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt .L08049502
	cmp r0, #3
	ble .L08049502
	cmp r0, #4
	bne .L08049502
	ldr r1, .L08049528 @ =gBanimFloorfx
	ldrh r0, [r1, #2]
	strh r0, [r1]
.L08049502:
	ldr r0, .L08049530 @ =gPlaySt
	ldrb r0, [r0, #0x15]
	cmp r0, #2
	bgt .L08049540
	cmp r0, #1
	blt .L08049540
	ldr r1, .L0804953C @ =gEkrSnowWeather
	movs r0, #1
	b .L08049544
	.align 2, 0
.L08049514: .4byte gBanimIdx
.L08049518: .4byte gBanimIdx_bak
.L0804951C: .4byte gBanimUniquePal
.L08049520: .4byte 0x0203CD90
.L08049524: .4byte 0x0203CDC0
.L08049528: .4byte gBanimFloorfx
.L0804952C: .4byte 0x0000FFFF
.L08049530: .4byte gPlaySt
.L08049534: .4byte gBmSt
.L08049538: .4byte gEkrDistanceType
.L0804953C: .4byte gEkrSnowWeather
.L08049540:
	ldr r1, .L080495C0 @ =gEkrSnowWeather
	movs r0, #0
.L08049544:
	strh r0, [r1]
	ldr r0, [sp, #0x1c]
	asrs r4, r0, #0x10
	cmp r4, #0
	beq .L0804955C
	ldr r0, .L080495C4 @ =0x0203CDC4
	ldr r2, [sp, #0x10]
	ldr r1, [r2, #4]
	ldrb r1, [r1, #0x11]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r0]
.L0804955C:
	ldr r3, [sp, #0x20]
	asrs r5, r3, #0x10
	cmp r5, #0
	beq .L08049572
	ldr r0, .L080495C4 @ =0x0203CDC4
	mov r2, sl
	ldr r1, [r2, #4]
	ldrb r1, [r1, #0x11]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r0, #2]
.L08049572:
	cmp r4, #0
	beq .L0804958E
	ldr r1, .L080495C8 @ =gEkrGaugeHp
	ldr r0, [sp]
	adds r0, #0x6e
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, .L080495CC @ =0x0203CDA4
	ldr r3, [sp, #0x10]
	movs r0, #0x10
	ldrsb r0, [r3, r0]
	strh r0, [r1]
.L0804958E:
	cmp r5, #0
	beq .L080495AA
	ldr r1, .L080495C8 @ =gEkrGaugeHp
	ldr r0, [sp, #4]
	adds r0, #0x6e
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
	ldr r1, .L080495CC @ =0x0203CDA4
	mov r2, sl
	movs r0, #0x10
	ldrsb r0, [r2, r0]
	strh r0, [r1, #2]
.L080495AA:
	bl ParseBattleHitToBanimCmd
	ldr r0, .L080495D0 @ =gEkrDistanceType
	ldrh r0, [r0]
	cmp r0, #4
	bne .L080495D8
	ldr r1, .L080495D4 @ =gEkrSpellAnimIndex
	movs r0, #1
	strh r0, [r1, #2]
	strh r0, [r1]
	b .L08049634
	.align 2, 0
.L080495C0: .4byte gEkrSnowWeather
.L080495C4: .4byte 0x0203CDC4
.L080495C8: .4byte gEkrGaugeHp
.L080495CC: .4byte 0x0203CDA4
.L080495D0: .4byte gEkrDistanceType
.L080495D4: .4byte gEkrSpellAnimIndex
.L080495D8:
	cmp r4, #0
	beq .L080495F0
	ldr r3, [sp, #0x10]
	ldr r0, [r3, #4]
	ldrb r0, [r0, #4]
	ldr r1, [sp]
	adds r1, #0x4a
	ldrh r1, [r1]
	bl func_fe6_08049D98
	ldr r1, .L08049918 @ =gEkrSpellAnimIndex
	strh r0, [r1]
.L080495F0:
	cmp r5, #0
	beq .L08049608
	mov r4, sl
	ldr r0, [r4, #4]
	ldrb r0, [r0, #4]
	ldr r1, [sp, #4]
	adds r1, #0x4a
	ldrh r1, [r1]
	bl func_fe6_08049D98
	ldr r1, .L08049918 @ =gEkrSpellAnimIndex
	strh r0, [r1, #2]
.L08049608:
	ldr r1, .L0804991C @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	cmp r0, #0
	beq .L08049634
	mov r1, sl
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x36
	bne .L08049624
	ldr r1, .L08049918 @ =gEkrSpellAnimIndex
	movs r0, #0xe
	strh r0, [r1, #2]
.L08049624:
	mov r2, sl
	ldr r0, [r2, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x37
	bne .L08049634
	ldr r1, .L08049918 @ =gEkrSpellAnimIndex
	movs r0, #0xf
	strh r0, [r1, #2]
.L08049634:
	ldr r3, [sp, #0x1c]
	asrs r5, r3, #0x10
	cmp r5, #0
	beq .L0804964A
	ldr r0, .L08049918 @ =gEkrSpellAnimIndex
	ldr r1, [sp]
	adds r1, #0x4a
	ldrh r2, [r1]
	movs r1, #0
	bl func_fe6_08049E9C
.L0804964A:
	ldr r4, [sp, #0x20]
	cmp r4, #0
	beq .L0804965E
	ldr r0, .L08049920 @ =0x0203CD0E
	ldr r1, [sp, #4]
	adds r1, #0x4a
	ldrh r2, [r1]
	movs r1, #1
	bl func_fe6_08049E9C
.L0804965E:
	movs r0, #0
	bl GetEkrDragonJid
	movs r4, #0
	strh r4, [r0]
	movs r0, #1
	bl GetEkrDragonJid
	strh r4, [r0]
	ldr r0, .L08049924 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt .L08049730
	cmp r0, #2
	bgt .L08049730
	cmp r5, #0
	beq .L0804969A
	ldr r0, [sp]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x53
	bne .L0804969A
	movs r0, #0
	bl GetEkrDragonJid
	strh r4, [r0]
.L0804969A:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	beq .L080496B8
	ldr r0, [sp, #4]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x53
	bne .L080496B8
	movs r0, #1
	bl GetEkrDragonJid
	strh r4, [r0]
.L080496B8:
	ldr r3, [sp, #0x1c]
	cmp r3, #0
	beq .L080496D6
	ldr r0, [sp]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x54
	bne .L080496D6
	movs r0, #0
	bl GetEkrDragonJid
	strh r4, [r0]
.L080496D6:
	ldr r4, [sp, #0x20]
	cmp r4, #0
	beq .L080496F4
	ldr r0, [sp, #4]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x54
	bne .L080496F4
	movs r0, #1
	bl GetEkrDragonJid
	strh r4, [r0]
.L080496F4:
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq .L08049712
	ldr r0, [sp]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x70
	bne .L08049712
	movs r0, #0
	bl GetEkrDragonJid
	strh r4, [r0]
.L08049712:
	ldr r1, [sp, #0x20]
	cmp r1, #0
	beq .L08049730
	ldr r0, [sp, #4]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x70
	bne .L08049730
	movs r0, #1
	bl GetEkrDragonJid
	strh r4, [r0]
.L08049730:
	ldr r2, [sp, #0x1c]
	asrs r5, r2, #0x10
	cmp r5, #0
	beq .L0804974A
	movs r0, #0x40
	rsbs r0, r0, #0
	ldr r3, [sp, #0x10]
	ldrb r3, [r3, #0xb]
	ands r0, r3
	bl GetBanimFactionPalette
	ldr r1, .L08049928 @ =gBanimFactionPal
	strh r0, [r1]
.L0804974A:
	ldr r0, [sp, #0x20]
	asrs r4, r0, #0x10
	cmp r4, #0
	beq .L08049764
	movs r0, #0x40
	rsbs r0, r0, #0
	mov r1, sl
	ldrb r1, [r1, #0xb]
	ands r0, r1
	bl GetBanimFactionPalette
	ldr r1, .L08049928 @ =gBanimFactionPal
	strh r0, [r1, #2]
.L08049764:
	ldr r1, .L0804992C @ =gEkrPids
	movs r3, #0
	strb r3, [r1, #1]
	strb r3, [r1]
	cmp r5, #0
	beq .L08049776
	ldr r2, [sp, #8]
	ldrb r0, [r2, #4]
	strb r0, [r1]
.L08049776:
	cmp r4, #0
	beq .L08049780
	ldr r2, [sp, #0xc]
	ldrb r0, [r2, #4]
	strb r0, [r1, #1]
.L08049780:
	ldr r0, .L08049930 @ =0x0203CDAC
	mov r8, r0
	cmp r5, #0
	beq .L08049792
	ldr r0, [sp]
	adds r0, #0x62
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
.L08049792:
	cmp r4, #0
	beq .L080497A0
	ldr r0, [sp, #4]
	adds r0, #0x62
	ldrh r0, [r0]
	mov r2, r8
	strh r0, [r2, #2]
.L080497A0:
	mov r4, r8
	ldrh r0, [r4]
	adds r1, r0, #0
	cmp r1, #0xff
	bne .L080497AE
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r4]
.L080497AE:
	mov r2, r8
	ldrh r0, [r2, #2]
	adds r4, r0, #0
	cmp r4, #0xff
	bne .L080497BC
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r2, #2]
.L080497BC:
	cmp r5, #0
	beq .L080497E4
	ldr r2, .L08049938 @ =0x0203CDB0
	ldr r1, [sp]
	adds r1, #0x58
	ldr r0, [sp, #4]
	adds r0, #0x5a
	ldrh r4, [r1]
	ldrh r0, [r0]
	subs r0, r4, r0
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L080497DA
	strh r3, [r2]
.L080497DA:
	ldrh r1, [r1]
	cmp r1, #0xff
	bne .L080497E4
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r2]
.L080497E4:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq .L08049810
	ldr r2, .L08049938 @ =0x0203CDB0
	ldr r1, [sp, #4]
	adds r1, #0x58
	ldr r0, [sp]
	adds r0, #0x5a
	ldrh r3, [r1]
	ldrh r0, [r0]
	subs r0, r3, r0
	strh r0, [r2, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L08049806
	movs r0, #0
	strh r0, [r2, #2]
.L08049806:
	ldrh r1, [r1]
	cmp r1, #0xff
	bne .L08049810
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r2, #2]
.L08049810:
	ldr r4, [sp, #0x1c]
	asrs r7, r4, #0x10
	ldr r3, .L0804993C @ =0x0203CDB4
	cmp r7, #0
	beq .L08049822
	ldr r0, [sp]
	adds r0, #0x68
	ldrh r0, [r0]
	strh r0, [r3]
.L08049822:
	ldr r0, [sp, #0x20]
	asrs r6, r0, #0x10
	cmp r6, #0
	beq .L08049832
	ldr r0, [sp, #4]
	adds r0, #0x68
	ldrh r0, [r0]
	strh r0, [r3, #2]
.L08049832:
	adds r1, r3, #0
	ldrh r0, [r1]
	cmp r0, #0xff
	bne .L0804983E
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r1]
.L0804983E:
	ldrh r0, [r1, #2]
	cmp r0, #0xff
	bne .L08049848
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r1, #2]
.L08049848:
	ldr r0, .L08049924 @ =gEkrDistanceType
	ldrh r0, [r0]
	cmp r0, #4
	bne .L0804986A
	ldr r2, .L08049934 @ =0x0000FFFF
	adds r1, r2, #0
	mov r4, r8
	ldrh r0, [r4, #2]
	orrs r0, r1
	strh r0, [r4, #2]
	ldr r2, .L08049938 @ =0x0203CDB0
	ldrh r0, [r2, #2]
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #2]
	orrs r1, r0
	strh r1, [r3, #2]
.L0804986A:
	cmp r7, #0
	beq .L0804987C
	ldr r1, .L08049940 @ =gEkrPairExpPrevious
	ldr r0, [sp]
	adds r0, #0x6d
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
.L0804987C:
	cmp r6, #0
	beq .L0804988E
	ldr r1, .L08049940 @ =gEkrPairExpPrevious
	ldr r0, [sp, #4]
	adds r0, #0x6d
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
.L0804988E:
	cmp r7, #0
	beq .L080498A0
	ldr r1, .L08049944 @ =gEkrPairExpGain
	ldr r0, [sp]
	adds r0, #0x6a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
.L080498A0:
	cmp r6, #0
	beq .L080498B2
	ldr r1, .L08049944 @ =gEkrPairExpGain
	ldr r0, [sp, #4]
	adds r0, #0x6a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
.L080498B2:
	ldr r1, .L08049948 @ =0x0203CDC8
	movs r5, #0
	strh r5, [r1, #2]
	strh r5, [r1]
	cmp r7, #0
	beq .L080498CA
	ldr r0, [sp]
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
.L080498CA:
	cmp r6, #0
	beq .L080498DA
	ldr r0, [sp, #4]
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
.L080498DA:
	ldr r4, .L0804994C @ =gEkrPairEffectiveAgainst
	strh r5, [r4, #2]
	strh r5, [r4]
	cmp r7, #0
	beq .L080498F6
	ldr r0, [sp]
	adds r0, #0x48
	ldrh r0, [r0]
	mov r1, sl
	bl IsItemEffectiveAgainst
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r4]
.L080498F6:
	cmp r6, #0
	beq .L0804990C
	ldr r0, [sp, #4]
	adds r0, #0x48
	ldrh r0, [r0]
	ldr r1, [sp, #0x10]
	bl IsItemEffectiveAgainst
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r4, #2]
.L0804990C:
	ldr r4, .L08049950 @ =0x0203CD98
	str r5, [r4, #4]
	str r5, [r4]
	cmp r7, #0
	b .L08049954
	.align 2, 0
.L08049918: .4byte gEkrSpellAnimIndex
.L0804991C: .4byte gBattleSt
.L08049920: .4byte 0x0203CD0E
.L08049924: .4byte gEkrDistanceType
.L08049928: .4byte gBanimFactionPal
.L0804992C: .4byte gEkrPids
.L08049930: .4byte 0x0203CDAC
.L08049934: .4byte 0x0000FFFF
.L08049938: .4byte 0x0203CDB0
.L0804993C: .4byte 0x0203CDB4
.L08049940: .4byte gEkrPairExpPrevious
.L08049944: .4byte gEkrPairExpGain
.L08049948: .4byte 0x0203CDC8
.L0804994C: .4byte gEkrPairEffectiveAgainst
.L08049950: .4byte 0x0203CD98
.L08049954:
	beq .L08049994
	ldr r0, [sp]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	cmp r0, #0x32
	bgt .L08049994
	cmp r0, #0x30
	blt .L08049994
	ldr r1, [sp, #0x10]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x11
	beq .L08049980
	cmp r0, #0x11
	ble .L08049994
	cmp r0, #0x12
	beq .L08049988
	cmp r0, #0x13
	beq .L08049990
	b .L08049994
.L08049980:
	ldr r0, .L08049984 @ =gUnk_08113FF8
	b .L08049992
	.align 2, 0
.L08049984: .4byte gUnk_08113FF8
.L08049988:
	ldr r0, .L0804998C @ =gUnk_0811446C
	b .L08049992
	.align 2, 0
.L0804998C: .4byte gUnk_0811446C
.L08049990:
	ldr r0, .L080499C4 @ =gUnk_0811490C
.L08049992:
	str r0, [r4]
.L08049994:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	beq .L080499EE
	ldr r0, [sp, #4]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	cmp r0, #0x32
	bgt .L080499EE
	cmp r0, #0x30
	blt .L080499EE
	mov r3, sl
	ldr r0, [r3, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x11
	beq .L080499C8
	cmp r0, #0x11
	ble .L080499EE
	cmp r0, #0x12
	beq .L080499D8
	cmp r0, #0x13
	beq .L080499E8
	b .L080499EE
	.align 2, 0
.L080499C4: .4byte gUnk_0811490C
.L080499C8:
	ldr r1, .L080499D0 @ =0x0203CD98
	ldr r0, .L080499D4 @ =gUnk_08113FF8
	b .L080499EC
	.align 2, 0
.L080499D0: .4byte 0x0203CD98
.L080499D4: .4byte gUnk_08113FF8
.L080499D8:
	ldr r1, .L080499E0 @ =0x0203CD98
	ldr r0, .L080499E4 @ =gUnk_0811446C
	b .L080499EC
	.align 2, 0
.L080499E0: .4byte 0x0203CD98
.L080499E4: .4byte gUnk_0811446C
.L080499E8:
	ldr r1, .L08049A08 @ =0x0203CD98
	ldr r0, .L08049A0C @ =gUnk_0811490C
.L080499EC:
	str r0, [r1, #4]
.L080499EE:
	bl GetBanimLinkArenaFlag
	cmp r0, #1
	beq .L08049A00
	ldr r0, .L08049A10 @ =gPlaySt
	ldrb r0, [r0, #0x1c]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq .L08049A18
.L08049A00:
	ldr r1, .L08049A14 @ =0x0203CDD0
	movs r0, #1
	b .L08049A1C
	.align 2, 0
.L08049A08: .4byte 0x0203CD98
.L08049A0C: .4byte gUnk_0811490C
.L08049A10: .4byte gPlaySt
.L08049A14: .4byte 0x0203CDD0
.L08049A18:
	ldr r1, .L08049A40 @ =0x0203CDD0
	movs r0, #0
.L08049A1C:
	strh r0, [r1, #2]
	strh r0, [r1]
	ldr r5, .L08049A44 @ =gBanimBackgroundIndex
	movs r0, #0
	strh r0, [r5]
	bl GetBattleAnimType
	cmp r0, #3
	bne .L08049A6A
	ldr r0, .L08049A48 @ =gBanimValid
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq .L08049A50
	ldr r0, .L08049A4C @ =0x0203CDC0
	ldrh r4, [r0]
	b .L08049A54
	.align 2, 0
.L08049A40: .4byte 0x0203CDD0
.L08049A44: .4byte gBanimBackgroundIndex
.L08049A48: .4byte gBanimValid
.L08049A4C: .4byte 0x0203CDC0
.L08049A50:
	ldr r0, .L08049B78 @ =0x0203CDC0
	ldrh r4, [r0, #2]
.L08049A54:
	ldr r0, .L08049B7C @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	ldrb r1, [r0, #0x12]
	adds r0, r4, #0
	bl func_fe6_08049CFC
	strh r0, [r5]
.L08049A6A:
	movs r4, #0
	bl GetBattleAnimType
	cmp r0, #0
	bne .L08049A76
	movs r4, #1
.L08049A76:
	bl GetBattleAnimType
	cmp r0, #3
	bne .L08049A80
	movs r4, #1
.L08049A80:
	bl GetBattleAnimType
	cmp r0, #1
	bne .L08049AC8
	ldr r0, .L08049B80 @ =gEkrDistanceType
	ldrh r0, [r0]
	cmp r0, #4
	bne .L08049A92
	movs r4, #1
.L08049A92:
	bl GetBattleAnimArenaFlag
	cmp r0, #1
	bne .L08049A9C
	movs r4, #1
.L08049A9C:
	ldr r1, [sp, #0x10]
	ldr r0, [r1]
	ldrb r0, [r0, #4]
	cmp r0, #0x64
	bne .L08049AB2
	ldr r0, .L08049B84 @ =gBanimFactionPal
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq .L08049AB2
	movs r4, #1
.L08049AB2:
	mov r3, sl
	ldr r0, [r3]
	ldrb r0, [r0, #4]
	cmp r0, #0x64
	bne .L08049AC8
	ldr r0, .L08049B84 @ =gBanimFactionPal
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08049AC8
	movs r4, #1
.L08049AC8:
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldrb r1, [r0, #4]
	cmp r1, #0x42
	beq .L08049B72
	mov r3, sl
	ldr r0, [r3]
	ldrb r0, [r0, #4]
	cmp r0, #0x42
	beq .L08049B72
	ldr r0, [sp, #0x18]
	cmp r0, #1
	beq .L08049AE6
	cmp r1, #0x66
	beq .L08049B98
.L08049AE6:
	cmp r4, #0
	beq .L08049B72
	ldr r0, .L08049B88 @ =gBanimValid
	adds r3, r0, #0
	ldrh r1, [r3]
	cmp r1, #1
	bne .L08049B30
	ldr r1, [sp, #0x10]
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #4
	beq .L08049B72
	ldr r0, .L08049B8C @ =gBanimIdx
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, r2
	beq .L08049B72
	ldr r0, .L08049B90 @ =gEkrSpellAnimIndex
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L08049B72
	ldr r0, .L08049B94 @ =gBanimFloorfx
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r2
	beq .L08049B72
	ldr r0, .L08049B78 @ =0x0203CDC0
	ldrh r0, [r0]
	cmp r0, #0x1b
	beq .L08049B72
.L08049B30:
	ldrh r3, [r3, #2]
	cmp r3, #1
	bne .L08049B98
	mov r1, sl
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #4
	beq .L08049B72
	ldr r0, .L08049B8C @ =gBanimIdx
	movs r2, #2
	ldrsh r0, [r0, r2]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, r2
	beq .L08049B72
	ldr r0, .L08049B90 @ =gEkrSpellAnimIndex
	movs r3, #2
	ldrsh r1, [r0, r3]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L08049B72
	ldr r0, .L08049B94 @ =gBanimFloorfx
	movs r4, #2
	ldrsh r0, [r0, r4]
	cmp r0, r2
	beq .L08049B72
	ldr r0, .L08049B78 @ =0x0203CDC0
	ldrh r0, [r0, #2]
	cmp r0, #0x1b
	bne .L08049B98
.L08049B72:
	movs r0, #0
	b .L08049B9A
	.align 2, 0
.L08049B78: .4byte 0x0203CDC0
.L08049B7C: .4byte gPlaySt
.L08049B80: .4byte gEkrDistanceType
.L08049B84: .4byte gBanimFactionPal
.L08049B88: .4byte gBanimValid
.L08049B8C: .4byte gBanimIdx
.L08049B90: .4byte gEkrSpellAnimIndex
.L08049B94: .4byte gBanimFloorfx
.L08049B98:
	movs r0, #1
.L08049B9A:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start GetBattleAnimationId_WithUnique
GetBattleAnimationId_WithUnique: @ 0x08049BAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	movs r0, #0
	mov sb, r0
	mov r2, sl
	cmp r2, #0
	beq .L08049BD4
	mov r0, r8
	bl GetItemKind
	cmp r0, #9
	bne .L08049BDC
.L08049BD4:
	ldr r0, .L08049BD8 @ =0x0000FFFF
	b .L08049C4A
	.align 2, 0
.L08049BD8: .4byte 0x0000FFFF
.L08049BDC:
	mov r3, r8
	cmp r3, #0
	bne .L08049BE6
	movs r1, #9
	b .L08049BF0
.L08049BE6:
	mov r0, r8
	bl GetItemKind
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
.L08049BF0:
	movs r6, #0
	movs r7, #0
.L08049BF4:
	mov r5, sl
	b .L08049C32
.L08049BF8:
	cmp r6, #0
	bne .L08049C00
	cmp r0, #0xff
	bhi .L08049C30
.L08049C00:
	cmp r6, #1
	bne .L08049C0A
	ldrh r0, [r5]
	cmp r0, #0xff
	bls .L08049C30
.L08049C0A:
	ldrh r4, [r5]
	mov r0, r8
	str r1, [sp]
	bl GetItemIid
	ldr r1, [sp]
	cmp r4, r0
	beq .L08049C24
	ldrh r2, [r5]
	ldr r3, .L08049C2C @ =0xFFFFFF00
	adds r0, r2, r3
	cmp r0, r1
	bne .L08049C30
.L08049C24:
	ldrh r5, [r5, #2]
	mov sb, r5
	movs r7, #1
	b .L08049C38
	.align 2, 0
.L08049C2C: .4byte 0xFFFFFF00
.L08049C30:
	adds r5, #4
.L08049C32:
	ldrh r0, [r5]
	cmp r0, #0
	bne .L08049BF8
.L08049C38:
	cmp r7, #1
	beq .L08049C42
	adds r6, #1
	cmp r6, #1
	ble .L08049BF4
.L08049C42:
	mov r0, sb
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L08049C4A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08049C5C
func_fe6_08049C5C: @ 0x08049C5C
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #9
	bhi .L08049CE8
	lsls r0, r0, #2
	ldr r1, .L08049C74 @ =.L08049C78
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08049C74: .4byte .L08049C78
.L08049C78: @ jump table
	.4byte .L08049CE8 @ case 0
	.4byte .L08049CA0 @ case 1
	.4byte .L08049CA8 @ case 2
	.4byte .L08049CB0 @ case 3
	.4byte .L08049CB8 @ case 4
	.4byte .L08049CC0 @ case 5
	.4byte .L08049CC8 @ case 6
	.4byte .L08049CD0 @ case 7
	.4byte .L08049CD8 @ case 8
	.4byte .L08049CE0 @ case 9
.L08049CA0:
	ldr r0, .L08049CA4 @ =Terrain_BanimUnk_0860CC42
	b .L08049CEA
	.align 2, 0
.L08049CA4: .4byte Terrain_BanimUnk_0860CC42
.L08049CA8:
	ldr r0, .L08049CAC @ =Terrain_BanimUnk_0860CC75
	b .L08049CEA
	.align 2, 0
.L08049CAC: .4byte Terrain_BanimUnk_0860CC75
.L08049CB0:
	ldr r0, .L08049CB4 @ =Terrain_BanimUnk_0860CCA8
	b .L08049CEA
	.align 2, 0
.L08049CB4: .4byte Terrain_BanimUnk_0860CCA8
.L08049CB8:
	ldr r0, .L08049CBC @ =Terrain_BanimUnk_0860CCDB
	b .L08049CEA
	.align 2, 0
.L08049CBC: .4byte Terrain_BanimUnk_0860CCDB
.L08049CC0:
	ldr r0, .L08049CC4 @ =Terrain_BanimUnk_0860CD0E
	b .L08049CEA
	.align 2, 0
.L08049CC4: .4byte Terrain_BanimUnk_0860CD0E
.L08049CC8:
	ldr r0, .L08049CCC @ =Terrain_BanimUnk_0860CD41
	b .L08049CEA
	.align 2, 0
.L08049CCC: .4byte Terrain_BanimUnk_0860CD41
.L08049CD0:
	ldr r0, .L08049CD4 @ =Terrain_BanimUnk_0860CD74
	b .L08049CEA
	.align 2, 0
.L08049CD4: .4byte Terrain_BanimUnk_0860CD74
.L08049CD8:
	ldr r0, .L08049CDC @ =Terrain_BanimUnk_0860CDA7
	b .L08049CEA
	.align 2, 0
.L08049CDC: .4byte Terrain_BanimUnk_0860CDA7
.L08049CE0:
	ldr r0, .L08049CE4 @ =Terrain_BanimUnk_0860CDDA
	b .L08049CEA
	.align 2, 0
.L08049CE4: .4byte Terrain_BanimUnk_0860CDDA
.L08049CE8:
	ldr r0, .L08049CF8 @ =Terrain_BanimUnk_0860CC0F
.L08049CEA:
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	bx lr
	.align 2, 0
.L08049CF8: .4byte Terrain_BanimUnk_0860CC0F

	thumb_func_start func_fe6_08049CFC
func_fe6_08049CFC: @ 0x08049CFC
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #9
	bhi .L08049D88
	lsls r0, r0, #2
	ldr r1, .L08049D14 @ =.L08049D18
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08049D14: .4byte .L08049D18
.L08049D18: @ jump table
	.4byte .L08049D88 @ case 0
	.4byte .L08049D40 @ case 1
	.4byte .L08049D48 @ case 2
	.4byte .L08049D50 @ case 3
	.4byte .L08049D58 @ case 4
	.4byte .L08049D60 @ case 5
	.4byte .L08049D68 @ case 6
	.4byte .L08049D70 @ case 7
	.4byte .L08049D78 @ case 8
	.4byte .L08049D80 @ case 9
.L08049D40:
	ldr r0, .L08049D44 @ =Terrain_BanimUnk_0860CE40
	b .L08049D8A
	.align 2, 0
.L08049D44: .4byte Terrain_BanimUnk_0860CE40
.L08049D48:
	ldr r0, .L08049D4C @ =Terrain_BanimUnk_0860CE73
	b .L08049D8A
	.align 2, 0
.L08049D4C: .4byte Terrain_BanimUnk_0860CE73
.L08049D50:
	ldr r0, .L08049D54 @ =Terrain_BanimUnk_0860CEA6
	b .L08049D8A
	.align 2, 0
.L08049D54: .4byte Terrain_BanimUnk_0860CEA6
.L08049D58:
	ldr r0, .L08049D5C @ =Terrain_BanimUnk_0860CED9
	b .L08049D8A
	.align 2, 0
.L08049D5C: .4byte Terrain_BanimUnk_0860CED9
.L08049D60:
	ldr r0, .L08049D64 @ =Terrain_BanimUnk_0860CF0C
	b .L08049D8A
	.align 2, 0
.L08049D64: .4byte Terrain_BanimUnk_0860CF0C
.L08049D68:
	ldr r0, .L08049D6C @ =Terrain_BanimUnk_0860CF3F
	b .L08049D8A
	.align 2, 0
.L08049D6C: .4byte Terrain_BanimUnk_0860CF3F
.L08049D70:
	ldr r0, .L08049D74 @ =Terrain_BanimUnk_0860CF72
	b .L08049D8A
	.align 2, 0
.L08049D74: .4byte Terrain_BanimUnk_0860CF72
.L08049D78:
	ldr r0, .L08049D7C @ =Terrain_BanimUnk_0860CFA5
	b .L08049D8A
	.align 2, 0
.L08049D7C: .4byte Terrain_BanimUnk_0860CFA5
.L08049D80:
	ldr r0, .L08049D84 @ =Terrain_BanimUnk_0860CFD8
	b .L08049D8A
	.align 2, 0
.L08049D84: .4byte Terrain_BanimUnk_0860CFD8
.L08049D88:
	ldr r0, .L08049D94 @ =Terrain_BanimUnk_0860CE0D
.L08049D8A:
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bx lr
	.align 2, 0
.L08049D94: .4byte Terrain_BanimUnk_0860CE0D

	thumb_func_start func_fe6_08049D98
func_fe6_08049D98: @ 0x08049D98
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, .L08049DB4 @ =gUnk_08662E4C
	ldrh r1, [r3]
	ldr r2, .L08049DB8 @ =0x0000FFFF
	b .L08049DC0
	.align 2, 0
.L08049DB4: .4byte gUnk_08662E4C
.L08049DB8: .4byte 0x0000FFFF
.L08049DBC:
	adds r3, #0x10
	ldrh r1, [r3]
.L08049DC0:
	cmp r1, r2
	beq .L08049DC8
	cmp r1, r0
	bne .L08049DBC
.L08049DC8:
	ldrh r2, [r3, #4]
	ldrh r3, [r3, #4]
	cmp r3, #3
	bne .L08049E92
	adds r0, r4, #0
	subs r0, #0xe
	cmp r0, #0x22
	bhi .L08049E92
	lsls r0, r0, #2
	ldr r1, .L08049DE4 @ =.L08049DE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08049DE4: .4byte .L08049DE8
.L08049DE8: @ jump table
	.4byte .L08049E90 @ case 0
	.4byte .L08049E90 @ case 1
	.4byte .L08049E92 @ case 2
	.4byte .L08049E92 @ case 3
	.4byte .L08049E92 @ case 4
	.4byte .L08049E92 @ case 5
	.4byte .L08049E92 @ case 6
	.4byte .L08049E92 @ case 7
	.4byte .L08049E92 @ case 8
	.4byte .L08049E92 @ case 9
	.4byte .L08049E92 @ case 10
	.4byte .L08049E92 @ case 11
	.4byte .L08049E92 @ case 12
	.4byte .L08049E92 @ case 13
	.4byte .L08049E92 @ case 14
	.4byte .L08049E92 @ case 15
	.4byte .L08049E92 @ case 16
	.4byte .L08049E92 @ case 17
	.4byte .L08049E74 @ case 18
	.4byte .L08049E74 @ case 19
	.4byte .L08049E7C @ case 20
	.4byte .L08049E7C @ case 21
	.4byte .L08049E92 @ case 22
	.4byte .L08049E92 @ case 23
	.4byte .L08049E92 @ case 24
	.4byte .L08049E92 @ case 25
	.4byte .L08049E92 @ case 26
	.4byte .L08049E92 @ case 27
	.4byte .L08049E80 @ case 28
	.4byte .L08049E84 @ case 29
	.4byte .L08049E88 @ case 30
	.4byte .L08049E88 @ case 31
	.4byte .L08049E8C @ case 32
	.4byte .L08049E8C @ case 33
	.4byte .L08049E78 @ case 34
.L08049E74:
	movs r2, #4
	b .L08049E92
.L08049E78:
	movs r2, #5
	b .L08049E92
.L08049E7C:
	movs r2, #6
	b .L08049E92
.L08049E80:
	movs r2, #7
	b .L08049E92
.L08049E84:
	movs r2, #8
	b .L08049E92
.L08049E88:
	movs r2, #9
	b .L08049E92
.L08049E8C:
	movs r2, #0xa
	b .L08049E92
.L08049E90:
	movs r2, #0xb
.L08049E92:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08049E9C
func_fe6_08049E9C: @ 0x08049E9C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, r2, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08049EC2
	movs r0, #0
	strh r0, [r4]
.L08049EC2:
	ldr r0, .L08049EE0 @ =gEkrInitialHitSide
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r5
	beq .L08049F14
	adds r0, r2, #0
	subs r0, #0x48
	cmp r0, #9
	bhi .L08049F14
	lsls r0, r0, #2
	ldr r1, .L08049EE4 @ =.L08049EE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08049EE0: .4byte gEkrInitialHitSide
.L08049EE4: .4byte .L08049EE8
.L08049EE8: @ jump table
	.4byte .L08049F10 @ case 0
	.4byte .L08049F10 @ case 1
	.4byte .L08049F14 @ case 2
	.4byte .L08049F14 @ case 3
	.4byte .L08049F14 @ case 4
	.4byte .L08049F10 @ case 5
	.4byte .L08049F14 @ case 6
	.4byte .L08049F10 @ case 7
	.4byte .L08049F14 @ case 8
	.4byte .L08049F10 @ case 9
.L08049F10:
	movs r0, #0
	strh r0, [r4]
.L08049F14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ParseBattleHitToBanimCmd
ParseBattleHitToBanimCmd: @ 0x08049F1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r0, .L08049F58 @ =gBattleHits
	str r0, [sp, #4]
	ldr r0, .L08049F5C @ =gpEkrTriangleUnits
	movs r3, #0
	str r3, [r0, #4]
	str r3, [r0]
	ldr r2, .L08049F60 @ =gEkrDistanceType
	movs r5, #0
	ldrsh r1, [r2, r5]
	cmp r1, #4
	bne .L08049F6C
	ldr r0, .L08049F64 @ =0x0203CD1E
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r2, .L08049F68 @ =0x0000FFFF
	adds r1, r2, #0
	ldrh r2, [r0, #4]
	orrs r2, r1
	strh r2, [r0, #4]
	ldrh r5, [r0, #6]
	orrs r1, r5
	strh r1, [r0, #6]
	b .L0804A46E
	.align 2, 0
.L08049F58: .4byte gBattleHits
.L08049F5C: .4byte gpEkrTriangleUnits
.L08049F60: .4byte gEkrDistanceType
.L08049F64: .4byte 0x0203CD1E
.L08049F68: .4byte 0x0000FFFF
.L08049F6C:
	ldr r1, .L08049F94 @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	cmp r0, #0
	beq .L08049FA0
	ldr r2, .L08049F98 @ =0x0203CD1E
	movs r0, #6
	strh r0, [r2]
	strh r3, [r2, #2]
	ldr r1, .L08049F9C @ =0x0000FFFF
	adds r0, r1, #0
	ldrh r1, [r2, #4]
	orrs r1, r0
	strh r1, [r2, #4]
	ldrh r5, [r2, #6]
	orrs r0, r5
	strh r0, [r2, #6]
	b .L0804A46E
	.align 2, 0
.L08049F94: .4byte gBattleSt
.L08049F98: .4byte 0x0203CD1E
.L08049F9C: .4byte 0x0000FFFF
.L08049FA0:
	ldrh r2, [r2]
	str r2, [sp, #0x18]
	str r2, [sp, #0x1c]
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r0, .L0804A0A4 @ =gpEkrBattleUnitLeft
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r0, .L0804A0A8 @ =gpEkrBattleUnitRight
	ldr r0, [r0]
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	cmp r0, #0x7d
	bne .L08049FCE
	ldr r1, [sp, #0x18]
	cmp r1, #0
	bne .L08049FCE
	movs r2, #1
	str r2, [sp, #0x18]
.L08049FCE:
	ldr r4, [sp, #0xc]
	adds r4, #0x4a
	ldrh r0, [r4]
	bl GetItemIid
	adds r5, r4, #0
	cmp r0, #0x7d
	bne .L08049FE8
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	bne .L08049FE8
	movs r1, #1
	str r1, [sp, #0x1c]
.L08049FE8:
	ldr r4, [sp, #8]
	adds r4, #0x4a
	ldrh r0, [r4]
	bl GetItemIid
	cmp r0, #0x20
	bne .L0804A000
	ldr r2, [sp, #0x18]
	cmp r2, #0
	bne .L0804A000
	movs r0, #1
	str r0, [sp, #0x18]
.L0804A000:
	ldrh r0, [r5]
	bl GetItemIid
	cmp r0, #0x20
	bne .L0804A014
	ldr r1, [sp, #0x1c]
	cmp r1, #0
	bne .L0804A014
	movs r2, #1
	str r2, [sp, #0x1c]
.L0804A014:
	ldrh r0, [r4]
	bl GetItemIid
	cmp r0, #0x7f
	bne .L0804A028
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne .L0804A028
	movs r1, #1
	str r1, [sp, #0x18]
.L0804A028:
	ldrh r0, [r5]
	bl GetItemIid
	cmp r0, #0x7f
	bne .L0804A03C
	ldr r2, [sp, #0x1c]
	cmp r2, #0
	bne .L0804A03C
	movs r5, #1
	str r5, [sp, #0x1c]
.L0804A03C:
	ldrh r0, [r4]
	bl GetItemIid
	cmp r0, #0x53
	bne .L0804A050
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne .L0804A050
	movs r1, #1
	str r1, [sp, #0x18]
.L0804A050:
	ldrh r0, [r4]
	bl GetItemIid
	cmp r0, #0x70
	bne .L0804A05E
	movs r2, #1
	str r2, [sp, #0x20]
.L0804A05E:
	movs r2, #0
	ldr r4, .L0804A0AC @ =gEfxHpLut
	ldr r5, .L0804A0B0 @ =gEkrGaugeHp
	ldr r0, .L0804A0B4 @ =0x0000FFFF
	adds r3, r0, #0
	ldr r1, .L0804A0B8 @ =0x0203CD1E
.L0804A06A:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #0x13
	bls .L0804A06A
	movs r2, #0
	ldr r0, .L0804A0AC @ =gEfxHpLut
	ldr r1, .L0804A0B4 @ =0x0000FFFF
	adds r3, r1, #0
	adds r1, r0, #4
.L0804A082:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #0x13
	bls .L0804A082
	ldrh r0, [r5]
	strh r0, [r4]
	ldrh r0, [r5, #2]
	strh r0, [r4, #2]
	movs r2, #0
	str r2, [sp, #0x10]
	mov r8, r2
	movs r7, #0
	ldr r5, [sp, #4]
	b .L0804A462
	.align 2, 0
.L0804A0A4: .4byte gpEkrBattleUnitLeft
.L0804A0A8: .4byte gpEkrBattleUnitRight
.L0804A0AC: .4byte gEfxHpLut
.L0804A0B0: .4byte gEkrGaugeHp
.L0804A0B4: .4byte 0x0000FFFF
.L0804A0B8: .4byte 0x0203CD1E
.L0804A0BC:
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	str r0, [sp, #0x14]
	ldr r0, .L0804A0F4 @ =0x0203CCFC
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x14]
	cmp r0, r2
	bne .L0804A0FC
	mov r5, sp
	movs r0, #2
	add r0, sp
	mov sb, r0
	ldr r4, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	mov sl, r1
	ldr r6, [sp, #8]
	ldr r3, [sp, #0x20]
	ldr r2, [sp, #0x10]
	cmp r2, #0
	bne .L0804A118
	ldr r0, .L0804A0F8 @ =gEkrInitialHitSide
	strh r2, [r0]
	b .L0804A118
	.align 2, 0
.L0804A0F4: .4byte 0x0203CCFC
.L0804A0F8: .4byte gEkrInitialHitSide
.L0804A0FC:
	mov r5, sp
	adds r5, #2
	mov sb, sp
	ldr r4, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	mov sl, r0
	ldr r6, [sp, #0xc]
	movs r3, #0
	ldr r1, [sp, #0x10]
	cmp r1, #0
	bne .L0804A118
	ldr r1, .L0804A150 @ =gEkrInitialHitSide
	movs r0, #1
	strh r0, [r1]
.L0804A118:
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r2, #0
	ldr r1, [sp, #4]
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0804A134
	ldr r2, .L0804A154 @ =gpEkrTriangleUnits
	ldr r1, .L0804A158 @ =gBattleSt
	ldr r0, [r1, #0xc]
	str r0, [r2]
	ldr r0, [r1, #0x10]
	str r0, [r2, #4]
.L0804A134:
	movs r0, #1
	ldr r2, [sp, #4]
	ldrh r2, [r2]
	ands r0, r2
	cmp r0, #0
	beq .L0804A168
	adds r0, r6, #0
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0804A160
	ldr r0, .L0804A15C @ =gUnk_08112248
	b .L0804A1B6
	.align 2, 0
.L0804A150: .4byte gEkrInitialHitSide
.L0804A154: .4byte gpEkrTriangleUnits
.L0804A158: .4byte gBattleSt
.L0804A15C: .4byte gUnk_08112248
.L0804A160:
	ldr r0, .L0804A164 @ =gUnk_08112270
	b .L0804A1B6
	.align 2, 0
.L0804A164: .4byte gUnk_08112270
.L0804A168:
	cmp r3, #0
	bne .L0804A188
	adds r0, r6, #0
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0804A180
	ldr r0, .L0804A17C @ =gUnk_08112234
	b .L0804A1B6
	.align 2, 0
.L0804A17C: .4byte gUnk_08112234
.L0804A180:
	ldr r0, .L0804A184 @ =gUnk_08112266
	b .L0804A1B6
	.align 2, 0
.L0804A184: .4byte gUnk_08112266
.L0804A188:
	movs r0, #2
	bl func_fe6_0805B9C8
	cmp r0, #1
	beq .L0804A1AC
	cmp r0, #1
	bgt .L0804A19C
	cmp r0, #0
	beq .L0804A1A2
	b .L0804A1C0
.L0804A19C:
	cmp r0, #2
	beq .L0804A1B4
	b .L0804A1C0
.L0804A1A2:
	ldr r0, .L0804A1A8 @ =gUnk_0811227A
	b .L0804A1B6
	.align 2, 0
.L0804A1A8: .4byte gUnk_0811227A
.L0804A1AC:
	ldr r0, .L0804A1B0 @ =gUnk_08112284
	b .L0804A1B6
	.align 2, 0
.L0804A1B0: .4byte gUnk_08112284
.L0804A1B4:
	ldr r0, .L0804A1DC @ =gUnk_0811228E
.L0804A1B6:
	lsls r1, r4, #0x10
	asrs r1, r1, #0xf
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r5]
.L0804A1C0:
	movs r0, #2
	ldr r1, [sp, #4]
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0804A1FC
	adds r0, r6, #0
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0804A1E4
	ldr r0, .L0804A1E0 @ =gUnk_0811223E
	b .L0804A1E6
	.align 2, 0
.L0804A1DC: .4byte gUnk_0811228E
.L0804A1E0: .4byte gUnk_0811223E
.L0804A1E4:
	ldr r0, .L0804A1F4 @ =gUnk_08112266
.L0804A1E6:
	lsls r1, r4, #0x10
	asrs r1, r1, #0xf
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r5]
	ldr r0, .L0804A1F8 @ =gUnk_08112252
	b .L0804A1FE
	.align 2, 0
.L0804A1F4: .4byte gUnk_08112266
.L0804A1F8: .4byte gUnk_08112252
.L0804A1FC:
	ldr r0, .L0804A27C @ =gUnk_0811225C
.L0804A1FE:
	mov r2, sl
	lsls r1, r2, #0x10
	asrs r1, r1, #0xf
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r5, sb
	strh r0, [r5]
	ldr r1, .L0804A280 @ =0x0203CD1E
	ldr r2, [sp, #0x10]
	lsls r0, r2, #2
	adds r5, r0, r1
	mov r0, sp
	ldrh r0, [r0]
	movs r6, #0
	strh r0, [r5]
	lsls r0, r2, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r4, r0, r1
	mov r1, sp
	ldrh r0, [r1, #2]
	strh r0, [r4]
	ldr r2, [sp, #4]
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0804A238
	b .L0804A456
.L0804A238:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L0804A2D0
	ldr r0, .L0804A284 @ =0x0203CCFC
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x14]
	cmp r0, r2
	bne .L0804A290
	lsls r0, r7, #1
	bl GetEfxHp
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A264
	movs r2, #0
.L0804A264:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r0, r7, #2
	ldr r1, .L0804A288 @ =gEfxHpLut
	adds r0, r0, r1
	strh r2, [r0]
	ldr r2, .L0804A28C @ =0xFFFF8000
	adds r0, r2, #0
	ldrh r1, [r5]
	orrs r0, r1
	b .L0804A454
	.align 2, 0
.L0804A27C: .4byte gUnk_0811225C
.L0804A280: .4byte 0x0203CD1E
.L0804A284: .4byte 0x0203CCFC
.L0804A288: .4byte gEfxHpLut
.L0804A28C: .4byte 0xFFFF8000
.L0804A290:
	mov r2, r8
	lsls r0, r2, #1
	adds r0, #1
	bl GetEfxHp
	ldr r5, [sp, #4]
	movs r1, #3
	ldrsb r1, [r5, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A2AC
	movs r2, #0
.L0804A2AC:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	ldr r1, .L0804A2C8 @ =gEfxHpLut
	adds r0, r0, r1
	strh r2, [r0]
	ldr r2, .L0804A2CC @ =0xFFFF8000
	b .L0804A406
	.align 2, 0
.L0804A2C8: .4byte gEfxHpLut
.L0804A2CC: .4byte 0xFFFF8000
.L0804A2D0:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0804A3B8
	ldr r0, .L0804A344 @ =0x0203CCFC
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r1, [sp, #0x14]
	cmp r0, r1
	bne .L0804A350
	mov r2, r8
	lsls r0, r2, #1
	adds r0, #1
	bl GetEfxHp
	ldr r5, [sp, #4]
	movs r1, #3
	ldrsb r1, [r5, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A304
	movs r2, #0
.L0804A304:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r4, .L0804A348 @ =gEfxHpLut
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r2, [r0]
	lsls r0, r7, #1
	bl GetEfxHp
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r3, .L0804A34C @ =0x0203CDA4
	lsrs r2, r0, #0x10
	ldrh r5, [r3]
	lsls r1, r5, #0x10
	cmp r0, r1
	ble .L0804A338
	ldrh r2, [r3]
.L0804A338:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r0, r7, #2
	b .L0804A3A8
	.align 2, 0
.L0804A344: .4byte 0x0203CCFC
.L0804A348: .4byte gEfxHpLut
.L0804A34C: .4byte 0x0203CDA4
.L0804A350:
	lsls r0, r7, #1
	bl GetEfxHp
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A368
	movs r2, #0
.L0804A368:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r4, .L0804A3B0 @ =gEfxHpLut
	lsls r0, r7, #2
	adds r0, r0, r4
	strh r2, [r0]
	mov r5, r8
	lsls r0, r5, #1
	adds r0, #1
	bl GetEfxHp
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r3, .L0804A3B4 @ =0x0203CDA4
	lsrs r2, r0, #0x10
	ldrh r5, [r3, #2]
	lsls r1, r5, #0x10
	cmp r0, r1
	ble .L0804A398
	ldrh r2, [r3, #2]
.L0804A398:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
.L0804A3A8:
	adds r0, r0, r4
	strh r2, [r0]
	b .L0804A456
	.align 2, 0
.L0804A3B0: .4byte gEfxHpLut
.L0804A3B4: .4byte 0x0203CDA4
.L0804A3B8:
	ldr r0, .L0804A410 @ =0x0203CCFC
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x14]
	cmp r0, r2
	bne .L0804A418
	mov r5, r8
	lsls r0, r5, #1
	adds r0, #1
	bl GetEfxHp
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A3E0
	movs r2, #0
.L0804A3E0:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	ldr r5, .L0804A414 @ =gEfxHpLut
	adds r0, r0, r5
	strh r2, [r0]
	movs r0, #0x40
	ldr r1, [sp, #4]
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0804A456
	movs r2, #0x80
	lsls r2, r2, #6
.L0804A406:
	adds r0, r2, #0
	ldrh r5, [r4]
	orrs r0, r5
	strh r0, [r4]
	b .L0804A456
	.align 2, 0
.L0804A410: .4byte 0x0203CCFC
.L0804A414: .4byte gEfxHpLut
.L0804A418:
	lsls r0, r7, #1
	bl GetEfxHp
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A430
	movs r2, #0
.L0804A430:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r0, r7, #2
	ldr r1, .L0804A480 @ =gEfxHpLut
	adds r0, r0, r1
	strh r2, [r0]
	movs r0, #0x40
	ldr r2, [sp, #4]
	ldrh r2, [r2]
	ands r0, r2
	cmp r0, #0
	beq .L0804A456
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	ldrh r2, [r5]
	orrs r0, r2
.L0804A454:
	strh r0, [r5]
.L0804A456:
	ldr r5, [sp, #4]
	adds r5, #4
	str r5, [sp, #4]
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
.L0804A462:
	ldrb r1, [r5, #2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne .L0804A46E
	b .L0804A0BC
.L0804A46E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804A480: .4byte gEfxHpLut

	thumb_func_start CheckBattleHasHit
CheckBattleHasHit: @ 0x0804A484
	ldr r1, .L0804A494 @ =gBattleHits
	movs r0, #2
	ldrb r1, [r1, #2]
	ands r0, r1
	cmp r0, #0
	bne .L0804A498
	movs r0, #0
	b .L0804A49A
	.align 2, 0
.L0804A494: .4byte gBattleHits
.L0804A498:
	movs r0, #1
.L0804A49A:
	bx lr

	thumb_func_start func_fe6_0804A49C
func_fe6_0804A49C: @ 0x0804A49C
	ldr r2, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r2, #0x28]
	ldr r1, [r1, #0x24]
	orrs r0, r1
	lsrs r0, r0, #8
	movs r1, #1
	ands r0, r1
	adds r2, #0x23
	adds r2, r2, r0
	ldrb r0, [r2]
	subs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FilterBattleAnimCharacterPalette
FilterBattleAnimCharacterPalette: @ 0x0804A4B8
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x67
	bne .L0804A4F8
	adds r0, r1, #0
	bl GetItemIid
	cmp r0, #0x31
	beq .L0804A4E8
	cmp r0, #0x31
	bgt .L0804A4DA
	cmp r0, #0x30
	beq .L0804A4E0
	b .L0804A4F8
.L0804A4DA:
	cmp r0, #0x32
	beq .L0804A4F0
	b .L0804A4F8
.L0804A4E0:
	ldr r0, .L0804A4E4 @ =gUnk_08113FB8
	b .L0804A4FA
	.align 2, 0
.L0804A4E4: .4byte gUnk_08113FB8
.L0804A4E8:
	ldr r0, .L0804A4EC @ =gUnk_08113F98
	b .L0804A4FA
	.align 2, 0
.L0804A4EC: .4byte gUnk_08113F98
.L0804A4F0:
	ldr r0, .L0804A4F4 @ =gUnk_08113FD8
	b .L0804A4FA
	.align 2, 0
.L0804A4F4: .4byte gUnk_08113FD8
.L0804A4F8:
	movs r0, #0
.L0804A4FA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start GetBanimFactionPalette
GetBanimFactionPalette: @ 0x0804A500
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #0x40
	beq .L0804A51C
	cmp r0, #0x40
	ble .L0804A524
	cmp r1, #0x80
	beq .L0804A518
	cmp r1, #0xc0
	beq .L0804A520
	b .L0804A524
.L0804A518:
	movs r0, #1
	b .L0804A526
.L0804A51C:
	movs r0, #2
	b .L0804A526
.L0804A520:
	movs r0, #3
	b .L0804A526
.L0804A524:
	movs r0, #0
.L0804A526:
	bx lr

	thumb_func_start EkrPrepareBanimfx
EkrPrepareBanimfx: @ 0x0804A528
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	bl GetAnimPosition
	ldr r1, .L0804A550 @ =gBanimIdx
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	bl UpdateBanimFrame
	adds r0, r5, #0
	movs r1, #6
	bl SwitchAISFrameDataFromBARoundType
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804A550: .4byte gBanimIdx

	thumb_func_start GetBattleAnimRoundType
GetBattleAnimRoundType: @ 0x0804A554
	ldr r1, .L0804A570 @ =0x0203CD1E
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0804A578
	ldr r0, .L0804A574 @ =0x00000FFF
	ands r0, r2
	b .L0804A57A
	.align 2, 0
.L0804A570: .4byte 0x0203CD1E
.L0804A574: .4byte 0x00000FFF
.L0804A578:
	adds r0, r1, #0
.L0804A57A:
	bx lr

	thumb_func_start GetBattleAnimRoundTypeFlags
GetBattleAnimRoundTypeFlags: @ 0x0804A57C
	ldr r1, .L0804A59C @ =0x0203CD1E
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0804A5A4
	ldr r0, .L0804A5A0 @ =0xFFFFF000
	ands r0, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L0804A5A6
	.align 2, 0
.L0804A59C: .4byte 0x0203CD1E
.L0804A5A0: .4byte 0xFFFFF000
.L0804A5A4:
	movs r0, #0
.L0804A5A6:
	bx lr

	thumb_func_start GetEfxHp
GetEfxHp: @ 0x0804A5A8
	ldr r1, .L0804A5B8 @ =gEfxHpLut
	lsls r0, r0, #1
	adds r0, r0, r1
	ldr r1, .L0804A5BC @ =0x00000FFF
	ldrh r0, [r0]
	ands r1, r0
	adds r0, r1, #0
	bx lr
	.align 2, 0
.L0804A5B8: .4byte gEfxHpLut
.L0804A5BC: .4byte 0x00000FFF

	thumb_func_start func_fe6_0804A5C0
func_fe6_0804A5C0: @ 0x0804A5C0
	ldr r1, .L0804A5D4 @ =gEfxHpLut
	lsls r0, r0, #1
	adds r0, r0, r1
	ldr r1, .L0804A5D8 @ =0xFFFFF000
	ldrh r0, [r0]
	ands r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	bx lr
	.align 2, 0
.L0804A5D4: .4byte gEfxHpLut
.L0804A5D8: .4byte 0xFFFFF000
