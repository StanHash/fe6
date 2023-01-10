	.include "macro.inc"

	.syntax unified

	thumb_func_start LoadSuspendedGame
LoadSuspendedGame: @ 0x080858E4
	push {r4, r5, r6, lr}
	ldr r1, .L080859B0 @ =0x0203DA14
	ldrb r1, [r1]
	adds r0, r1, r0
	bl GetSaveSourceAddress
	adds r6, r0, #0
	ldr r5, .L080859B4 @ =ReadSramFast
	ldr r4, .L080859B8 @ =gPlaySt
	ldr r3, [r5]
	adds r1, r4, #0
	movs r2, #0x20
	bl _call_via_r3
	ldr r0, [r4]
	bl SetGameTime
	adds r0, r6, #0
	adds r0, #0x20
	ldr r1, .L080859BC @ =gAction
	ldr r3, [r5]
	movs r2, #0x18
	bl _call_via_r3
	bl RestoreActionRand
	bl InitUnits
	movs r4, #0
	movs r5, #0
.L08085920:
	movs r0, #0x34
	muls r0, r4, r0
	adds r0, #0x38
	adds r0, r6, r0
	ldr r1, .L080859C0 @ =gUnitArrayBlue
	adds r1, r5, r1
	bl LoadUnitFormSuspend
	adds r5, #0x48
	adds r4, #1
	cmp r4, #0x33
	ble .L08085920
	movs r4, #0
	movs r5, #0
.L0808593C:
	movs r0, #0x34
	muls r0, r4, r0
	ldr r1, .L080859C4 @ =0x00000AC8
	adds r0, r0, r1
	adds r0, r6, r0
	ldr r1, .L080859C8 @ =gUnitArrayRed
	adds r1, r5, r1
	bl LoadUnitFormSuspend
	adds r5, #0x48
	adds r4, #1
	cmp r4, #0x31
	ble .L0808593C
	movs r4, #0
	movs r5, #0
.L0808595A:
	movs r0, #0x34
	muls r0, r4, r0
	ldr r1, .L080859CC @ =0x000014F0
	adds r0, r0, r1
	adds r0, r6, r0
	ldr r1, .L080859D0 @ =gUnitArrayGreen
	adds r1, r5, r1
	bl LoadUnitFormSuspend
	adds r5, #0x48
	adds r4, #1
	cmp r4, #9
	ble .L0808595A
	movs r1, #0xc6
	lsls r1, r1, #5
	adds r0, r6, r1
	bl LoadPidStats
	movs r1, #0xe9
	lsls r1, r1, #5
	adds r0, r6, r1
	bl LoadChWinData
	ldr r1, .L080859D4 @ =0x000017F8
	adds r0, r6, r1
	bl LoadSupplyItems
	movs r1, #0xed
	lsls r1, r1, #5
	adds r0, r6, r1
	bl LoadPermanentFlagBits
	ldr r1, .L080859D8 @ =0x00001DA5
	adds r0, r6, r1
	bl LoadChapterFlagBits
	ldr r1, .L080859DC @ =0x000016F8
	adds r0, r6, r1
	bl LoadTraps
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080859B0: .4byte 0x0203DA14
.L080859B4: .4byte ReadSramFast
.L080859B8: .4byte gPlaySt
.L080859BC: .4byte gAction
.L080859C0: .4byte gUnitArrayBlue
.L080859C4: .4byte 0x00000AC8
.L080859C8: .4byte gUnitArrayRed
.L080859CC: .4byte 0x000014F0
.L080859D0: .4byte gUnitArrayGreen
.L080859D4: .4byte 0x000017F8
.L080859D8: .4byte 0x00001DA5
.L080859DC: .4byte 0x000016F8

	thumb_func_start func_fe6_080859E0
func_fe6_080859E0: @ 0x080859E0
	push {r4, lr}
	adds r4, r0, #0
	bl IsSramWorking
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08085A24
	cmp r4, #3
	bne .L08085A24
	ldr r4, .L08085A28 @ =0x0203DA14
	bl GetLastSuspendSlotId
	strb r0, [r4]
	adds r1, r0, #0
	adds r1, #3
	movs r0, #0
	bl LoadSaveBlockInfo
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08085A2C
	bl GetNextSuspendSaveId
	strb r0, [r4]
	adds r1, r0, #0
	adds r1, #3
	movs r0, #0
	bl LoadSaveBlockInfo
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08085A2C
	movs r0, #0x7f
	strb r0, [r4]
.L08085A24:
	movs r0, #0
	b .L08085A2E
	.align 2, 0
.L08085A28: .4byte 0x0203DA14
.L08085A2C:
	movs r0, #1
.L08085A2E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08085A34
func_fe6_08085A34: @ 0x08085A34
	push {lr}
	ldr r2, .L08085A44 @ =0x0203DA14
	ldrb r2, [r2]
	adds r0, r2, r0
	bl LoadPlaySt
	pop {r0}
	bx r0
	.align 2, 0
.L08085A44: .4byte 0x0203DA14

	thumb_func_start PackUnitForSuspend
PackUnitForSuspend: @ 0x08085A48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	mov ip, r1
	ldr r0, [r6]
	cmp r0, #0
	bne .L08085A62
	strb r0, [r1]
	b .L08085CAE
.L08085A62:
	ldrb r0, [r0, #4]
	mov r1, ip
	strb r0, [r1]
	ldr r0, [r6, #4]
	ldrb r0, [r0, #4]
	strb r0, [r1, #1]
	movs r1, #8
	ldrsb r1, [r6, r1]
	mov r2, ip
	adds r2, #0x28
	movs r4, #0x1f
	ands r1, r4
	movs r3, #0x20
	rsbs r3, r3, #0
	adds r0, r3, #0
	ldrb r5, [r2]
	ands r0, r5
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #9]
	mov r7, ip
	strb r0, [r7, #0xe]
	ldrh r0, [r6, #0xc]
	strh r0, [r7, #4]
	movs r1, #0xe
	ldrsb r1, [r6, r1]
	movs r0, #0x3f
	ands r1, r0
	lsls r1, r1, #5
	ldr r0, .L08085CC0 @ =0xFFFFF81F
	ldrh r2, [r7, #0x28]
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x28]
	movs r1, #0x3f
	ldrb r5, [r6, #0xf]
	ands r1, r5
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x28]
	ldr r2, .L08085CC4 @ =0xFFFE07FF
	ands r0, r2
	orrs r0, r1
	str r0, [r7, #0x28]
	ldrb r0, [r6, #0x10]
	strb r0, [r7, #0xc]
	ldrb r0, [r6, #0x11]
	strb r0, [r7, #0xd]
	movs r1, #0x12
	ldrsb r1, [r6, r1]
	mov r2, ip
	adds r2, #0x2a
	ands r1, r4
	lsls r1, r1, #1
	movs r0, #0x3f
	rsbs r0, r0, #0
	ldrb r7, [r2]
	ands r0, r7
	orrs r0, r1
	strb r0, [r2]
	movs r1, #0x13
	ldrsb r1, [r6, r1]
	movs r2, #0x1f
	ands r1, r2
	lsls r1, r1, #6
	ldr r0, .L08085CC8 @ =0xFFFFF83F
	mov r5, ip
	ldrh r5, [r5, #0x2a]
	ands r0, r5
	orrs r0, r1
	mov r7, ip
	strh r0, [r7, #0x2a]
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	movs r0, #0x2b
	add r0, ip
	mov r8, r0
	lsls r1, r1, #3
	movs r5, #7
	mov sb, r5
	movs r0, #7
	mov r7, r8
	ldrb r7, [r7]
	ands r0, r7
	orrs r0, r1
	mov r1, r8
	strb r0, [r1]
	movs r0, #0x15
	ldrsb r0, [r6, r0]
	mov r1, ip
	adds r1, #0x2c
	ands r0, r4
	ldrb r5, [r1]
	ands r3, r5
	orrs r3, r0
	strb r3, [r1]
	movs r1, #0x16
	ldrsb r1, [r6, r1]
	ands r1, r2
	lsls r1, r1, #5
	ldr r0, .L08085CCC @ =0xFFFFFC1F
	mov r7, ip
	ldrh r7, [r7, #0x2c]
	ands r0, r7
	orrs r0, r1
	mov r1, ip
	strh r0, [r1, #0x2c]
	movs r1, #0x17
	ldrsb r1, [r6, r1]
	mov r2, ip
	adds r2, #0x2d
	ands r1, r4
	lsls r1, r1, #2
	movs r0, #0x7d
	rsbs r0, r0, #0
	ldrb r3, [r2]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0x18
	ldrsb r2, [r6, r2]
	movs r3, #0x1f
	ands r2, r3
	lsls r2, r2, #0xf
	mov r4, ip
	ldr r0, [r4, #0x2c]
	ldr r1, .L08085CD0 @ =0xFFF07FFF
	ands r0, r1
	orrs r0, r2
	str r0, [r4, #0x2c]
	adds r0, r6, #0
	adds r0, #0x2e
	ldrb r2, [r0]
	lsls r1, r2, #0x1c
	lsrs r1, r1, #0x1c
	adds r4, #0x2e
	mov r5, sb
	ands r1, r5
	lsls r1, r1, #4
	movs r0, #0x71
	rsbs r0, r0, #0
	ldrb r7, [r4]
	ands r0, r7
	orrs r0, r1
	strb r0, [r4]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x1c
	movs r0, #7
	ands r2, r0
	lsls r2, r2, #7
	ldr r0, .L08085CD4 @ =0xFFFFFC7F
	mov r1, ip
	ldrh r1, [r1, #0x2e]
	ands r0, r1
	orrs r0, r2
	mov r2, ip
	strh r0, [r2, #0x2e]
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r1, r2, #0x1c
	lsrs r1, r1, #0x1c
	adds r4, #1
	ands r1, r5
	lsls r1, r1, #2
	movs r0, #0x1d
	rsbs r0, r0, #0
	ldrb r5, [r4]
	ands r0, r5
	orrs r0, r1
	lsrs r2, r2, #4
	lsls r2, r2, #5
	ands r0, r3
	orrs r0, r2
	strb r0, [r4]
	ldrb r0, [r6, #0x19]
	mov r7, ip
	strb r0, [r7, #3]
	movs r1, #0x1a
	ldrsb r1, [r6, r1]
	mov r2, ip
	adds r2, #0x30
	movs r0, #0xf
	ands r1, r0
	movs r0, #0x10
	rsbs r0, r0, #0
	ldrb r3, [r2]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r6, #0x1c]
	strh r0, [r7, #6]
	ldrh r0, [r6, #0x1e]
	strh r0, [r7, #8]
	ldrh r0, [r6, #0x20]
	strh r0, [r7, #0xa]
	ldr r1, .L08085CD8 @ =0x00003FFF
	ldrh r4, [r6, #0x22]
	ands r1, r4
	lsls r1, r1, #4
	ldr r0, [r7, #0x30]
	ldr r2, .L08085CDC @ =0xFFFC000F
	ands r0, r2
	orrs r0, r1
	str r0, [r7, #0x30]
	ldrh r5, [r6, #0x24]
	lsls r1, r5, #2
	movs r0, #3
	ldrh r7, [r7, #0x32]
	ands r0, r7
	orrs r0, r1
	mov r1, ip
	strh r0, [r1, #0x32]
	movs r2, #0
	mov r5, ip
	adds r5, #0x18
	adds r7, r6, #0
	adds r7, #0x30
	movs r3, #0x42
	adds r3, r3, r6
	mov r8, r3
	adds r4, r6, #0
	adds r4, #0x43
	str r4, [sp, #0xc]
	movs r0, #0x22
	add r0, ip
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x44
	str r1, [sp, #0x10]
	movs r3, #0x23
	add r3, ip
	mov sl, r3
	adds r4, #2
	str r4, [sp, #0x14]
	mov r0, ip
	adds r0, #0x26
	str r0, [sp]
	subs r1, #4
	str r1, [sp, #8]
	adds r3, r6, #0
	adds r3, #0x46
	str r3, [sp, #0x18]
	mov r4, ip
	adds r4, #0x27
	str r4, [sp, #4]
	ldrb r1, [r6, #0xa]
	mov r0, sp
	strb r1, [r0, #0x1c]
	subs r4, #0x17
	subs r3, #0x20
.L08085C56:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #7
	ble .L08085C56
	movs r2, #0
	adds r4, r5, #0
	adds r3, r7, #0
.L08085C6A:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #9
	ble .L08085C6A
	mov r2, r8
	ldrb r0, [r2]
	mov r3, ip
	strb r0, [r3, #2]
	ldr r4, [sp, #0xc]
	ldrb r0, [r4]
	mov r5, sb
	strb r0, [r5]
	ldr r7, [sp, #0x10]
	ldrb r0, [r7]
	mov r1, sl
	strb r0, [r1]
	ldr r2, [sp, #0x14]
	ldrb r0, [r2]
	ldr r3, [sp]
	strb r0, [r3]
	ldr r4, [sp, #8]
	ldrh r0, [r4]
	mov r5, ip
	strh r0, [r5, #0x24]
	ldr r7, [sp, #0x18]
	ldrb r0, [r7]
	ldr r1, [sp, #4]
	strb r0, [r1]
	mov r2, sp
	ldrb r2, [r2, #0x1c]
	strb r2, [r5, #0xf]
.L08085CAE:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08085CC0: .4byte 0xFFFFF81F
.L08085CC4: .4byte 0xFFFE07FF
.L08085CC8: .4byte 0xFFFFF83F
.L08085CCC: .4byte 0xFFFFFC1F
.L08085CD0: .4byte 0xFFF07FFF
.L08085CD4: .4byte 0xFFFFFC7F
.L08085CD8: .4byte 0x00003FFF
.L08085CDC: .4byte 0xFFFC000F

	thumb_func_start LoadUnitFormSuspend
LoadUnitFormSuspend: @ 0x08085CE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r4, r1, #0
	ldr r1, .L08085EB0 @ =ReadSramFast
	ldr r3, [r1]
	mov r1, sp
	movs r2, #0x34
	bl _call_via_r3
	mov r0, sp
	ldrb r0, [r0]
	bl GetPInfo
	str r0, [r4]
	mov r0, sp
	ldrb r0, [r0, #1]
	bl GetJInfo
	str r0, [r4, #4]
	add r0, sp, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1b
	strb r0, [r4, #8]
	mov r0, sp
	ldrb r0, [r0, #0xe]
	strb r0, [r4, #9]
	mov r0, sp
	ldrh r0, [r0, #4]
	strh r0, [r4, #0xc]
	mov r0, sp
	ldrh r0, [r0, #0x28]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x1a
	strb r0, [r4, #0xe]
	ldr r0, [sp, #0x28]
	lsls r0, r0, #0xf
	lsrs r0, r0, #0x1a
	strb r0, [r4, #0xf]
	mov r0, sp
	ldrb r0, [r0, #0xc]
	strb r0, [r4, #0x10]
	mov r0, sp
	ldrb r0, [r0, #0xd]
	strb r0, [r4, #0x11]
	mov r0, sp
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x12]
	mov r0, sp
	ldrh r0, [r0, #0x2a]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x13]
	mov r0, sp
	adds r0, #0x2b
	ldrb r0, [r0]
	lsrs r0, r0, #3
	strb r0, [r4, #0x14]
	add r0, sp, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x15]
	mov r0, sp
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x16]
	mov r0, sp
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x17]
	ldr r0, [sp, #0x2c]
	lsls r0, r0, #0xc
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x18]
	mov r0, sp
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r1, r0, #0x19
	adds r2, r4, #0
	adds r2, #0x2e
	mov r0, sp
	ldrh r0, [r0, #0x2e]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x1d
	lsls r0, r0, #4
	lsrs r1, r1, #0x1d
	orrs r1, r0
	strb r1, [r2]
	mov r0, sp
	adds r0, #0x2f
	ldrb r0, [r0]
	lsls r1, r0, #0x1b
	adds r2, #1
	lsrs r0, r0, #5
	lsls r0, r0, #4
	lsrs r1, r1, #0x1d
	orrs r1, r0
	strb r1, [r2]
	mov r0, sp
	ldrb r0, [r0, #3]
	strb r0, [r4, #0x19]
	add r0, sp, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	strb r0, [r4, #0x1a]
	mov r0, sp
	ldrh r0, [r0, #6]
	strh r0, [r4, #0x1c]
	mov r0, sp
	ldrh r0, [r0, #8]
	strh r0, [r4, #0x1e]
	mov r0, sp
	ldrh r0, [r0, #0xa]
	strh r0, [r4, #0x20]
	ldr r0, [sp, #0x30]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x12
	strh r0, [r4, #0x22]
	mov r0, sp
	ldrh r1, [r0, #0x32]
	lsrs r0, r1, #2
	strh r0, [r4, #0x24]
	movs r2, #0
	add r0, sp, #0x18
	mov sl, r0
	mov r1, sp
	adds r1, #0x22
	str r1, [sp, #0x34]
	mov r0, sp
	adds r0, #0x23
	str r0, [sp, #0x38]
	adds r1, #4
	str r1, [sp, #0x3c]
	adds r0, #4
	str r0, [sp, #0x40]
	adds r5, r4, #0
	adds r5, #0x26
	add r3, sp, #0x10
.L08085E0C:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #7
	ble .L08085E0C
	movs r2, #0
	movs r1, #0x42
	adds r1, r1, r4
	mov ip, r1
	adds r6, r4, #0
	adds r6, #0x43
	adds r7, r4, #0
	adds r7, #0x44
	movs r0, #0x45
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0x40
	adds r1, r1, r4
	mov sb, r1
	adds r0, r4, #0
	adds r0, #0x46
	str r0, [sp, #0x44]
	adds r5, r4, #0
	adds r5, #0x30
	mov r3, sl
.L08085E42:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #9
	ble .L08085E42
	mov r0, sp
	ldrb r0, [r0, #2]
	mov r1, ip
	strb r0, [r1]
	ldr r1, [sp, #0x34]
	ldrb r0, [r1]
	strb r0, [r6]
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	strb r0, [r7]
	ldr r1, [sp, #0x3c]
	ldrb r0, [r1]
	mov r1, r8
	strb r0, [r1]
	mov r0, sp
	ldrh r0, [r0, #0x24]
	mov r1, sb
	strh r0, [r1]
	ldr r1, [sp, #0x40]
	ldrb r0, [r1]
	ldr r1, [sp, #0x44]
	strb r0, [r1]
	mov r0, sp
	ldrb r0, [r0, #0xf]
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #9]
	cmp r0, #0x7f
	bne .L08085E8C
	movs r0, #0xff
	strb r0, [r4, #9]
.L08085E8C:
	ldrb r0, [r4, #0xe]
	cmp r0, #0x3f
	bne .L08085E96
	movs r0, #0xff
	strb r0, [r4, #0xe]
.L08085E96:
	ldrb r0, [r4, #0xf]
	cmp r0, #0x3f
	bne .L08085EA0
	movs r0, #0xff
	strb r0, [r4, #0xf]
.L08085EA0:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08085EB0: .4byte ReadSramFast

	thumb_func_start SaveTraps
SaveTraps: @ 0x08085EB4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	bl GetTrap
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, #0
	bl WriteAndVerifySramFast
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start LoadTraps
LoadTraps: @ 0x08085ED0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L08085EF0 @ =ReadSramFast
	movs r0, #0
	bl GetTrap
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r3, [r4]
	adds r0, r5, #0
	bl _call_via_r3
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08085EF0: .4byte ReadSramFast

	thumb_func_start GetLastSuspendSlotId
GetLastSuspendSlotId: @ 0x08085EF4
	push {lr}
	sub sp, #0x20
	mov r0, sp
	bl LoadGlobalSaveInfo
	mov r0, sp
	ldrb r0, [r0, #0x1f]
	cmp r0, #1
	beq .L08085F0A
	movs r0, #0
	b .L08085F0C
.L08085F0A:
	movs r0, #1
.L08085F0C:
	add sp, #0x20
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start GetNextSuspendSaveId
GetNextSuspendSaveId: @ 0x08085F14
	push {lr}
	bl GetLastSuspendSlotId
	adds r1, r0, #0
	movs r0, #1
	subs r0, r0, r1
	pop {r1}
	bx r1

	thumb_func_start ChangeSuspendSlotId
ChangeSuspendSlotId: @ 0x08085F24
	push {lr}
	sub sp, #0x20
	mov r0, sp
	bl LoadGlobalSaveInfo
	mov r1, sp
	movs r2, #0
	mov r0, sp
	ldrb r0, [r0, #0x1f]
	cmp r0, #0
	bne .L08085F3C
	movs r2, #1
.L08085F3C:
	strb r2, [r1, #0x1f]
	mov r0, sp
	bl SaveGlobalSaveInfoNoChecksum
	add sp, #0x20
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start GetCkSum32FromSRAM
GetCkSum32FromSRAM: @ 0x08085F4C
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r1, .L08085F6C @ =ReadSramFast
	ldr r4, .L08085F70 @ =gBuf
	ldr r3, [r1]
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	adds r0, r4, #0
	adds r1, r5, #0
	bl Checksum32_t
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08085F6C: .4byte ReadSramFast
.L08085F70: .4byte gBuf

	thumb_func_start CkSum32SaveBlockInfo
CkSum32SaveBlockInfo: @ 0x08085F74
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r5, [r4, #0xa]
	ldrh r0, [r4, #8]
	bl SramOffsetToPointer
	adds r1, r5, #0
	bl GetCkSum32FromSRAM
	ldr r1, [r4, #0xc]
	cmp r1, r0
	bne .L08085F90
	movs r0, #1
	b .L08085F92
.L08085F90:
	movs r0, #0
.L08085F92:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start GenerateSaveBlockInfoCkSum32
GenerateSaveBlockInfoCkSum32: @ 0x08085F98
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r5, [r4, #0xa]
	ldrh r0, [r4, #8]
	bl SramOffsetToPointer
	adds r1, r5, #0
	bl GetCkSum32FromSRAM
	str r0, [r4, #0xc]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ComputeSaveDataCkSum32
ComputeSaveDataCkSum32: @ 0x08085FB4
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, .L0808607C @ =gUnitArrayBlue
	movs r5, #0x33
.L08085FBC:
	ldr r0, [r4]
	cmp r0, #0
	beq .L08085FD4
	movs r0, #0
	str r0, [r4, #0x3c]
	adds r0, r4, #0
	movs r1, #0x24
	bl GetCkSum32FromSRAM
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L08085FD4:
	adds r4, #0x48
	subs r5, #1
	cmp r5, #0
	bge .L08085FBC
	ldr r4, .L08086080 @ =gUnitArrayRed
	movs r5, #0x31
.L08085FE0:
	ldr r0, [r4]
	cmp r0, #0
	beq .L08085FF8
	movs r0, #0
	str r0, [r4, #0x3c]
	adds r0, r4, #0
	movs r1, #0x24
	bl GetCkSum32FromSRAM
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L08085FF8:
	adds r4, #0x48
	subs r5, #1
	cmp r5, #0
	bge .L08085FE0
	ldr r4, .L08086084 @ =gUnitArrayGreen
	movs r5, #9
.L08086004:
	ldr r0, [r4]
	cmp r0, #0
	beq .L0808601C
	movs r0, #0
	str r0, [r4, #0x3c]
	adds r0, r4, #0
	movs r1, #0x24
	bl GetCkSum32FromSRAM
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0808601C:
	adds r4, #0x48
	subs r5, #1
	cmp r5, #0
	bge .L08086004
	bl GetPermanentFlagBits
	adds r4, r0, #0
	bl GetPermanentFlagBitsSize
	adds r1, r0, #0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	adds r0, r4, #0
	bl GetCkSum32FromSRAM
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	bl GetChapterFlagBits
	adds r4, r0, #0
	bl GetChapterFlagBitsSize
	adds r1, r0, #0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	adds r0, r4, #0
	bl GetCkSum32FromSRAM
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	bl GetTrap
	movs r1, #0x80
	bl GetCkSum32FromSRAM
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L0808607C: .4byte gUnitArrayBlue
.L08086080: .4byte gUnitArrayRed
.L08086084: .4byte gUnitArrayGreen

	thumb_func_start func_fe6_08086088
func_fe6_08086088: @ 0x08086088
	sub sp, #8
	add sp, #8
	bx lr
	.align 2, 0

	thumb_func_start VerifySaveBlockInfoByIndex2
VerifySaveBlockInfoByIndex2: @ 0x08086090
	push {lr}
	adds r1, r0, #0
	movs r0, #0
	bl LoadSaveBlockInfo
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_080860A4
func_fe6_080860A4: @ 0x080860A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x6c
	movs r0, #5
	bl GetSaveTargetAddress
	mov r8, r0
	add r0, sp, #0x5c
	movs r4, #0
	strh r4, [r0]
	add r5, sp, #0x10
	ldr r2, .L080861D8 @ =0x01000014
	adds r1, r5, #0
	bl CpuSet
	mov r0, sp
	adds r0, #0x5e
	strh r4, [r0]
	add r4, sp, #0x38
	ldr r2, .L080861DC @ =0x01000007
	adds r1, r4, #0
	bl CpuSet
	movs r7, #0
	mov sb, r5
	add r0, sp, #0x60
	mov sl, r0
	mov r1, sp
	adds r1, #0x48
	str r1, [sp, #0x64]
	mov r3, sp
	adds r3, #0x4c
	str r3, [sp, #0x68]
	mov r6, r8
.L080860EE:
	movs r0, #0xd8
	muls r0, r7, r0
	adds r0, #0x10
	mov r1, r8
	adds r4, r1, r0
	movs r5, #4
.L080860FA:
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0x28
	bl WriteAndVerifySramFast
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge .L080860FA
	add r0, sp, #0x38
	adds r1, r6, #0
	movs r2, #0xf
	bl WriteAndVerifySramFast
	adds r6, #0xd8
	adds r7, #1
	cmp r7, #9
	ble .L080860EE
	movs r0, #7
	mov r3, sl
	strh r0, [r3]
	movs r1, #0x87
	lsls r1, r1, #4
	add r1, r8
	mov r0, sl
	movs r2, #2
	bl WriteAndVerifySramFast
	ldr r6, [sp, #0x64]
	mov sl, r6
	ldr r0, .L080861E0 @ =gUnk_0832731C
	movs r1, #3
	mov sb, r1
	ldr r5, .L080861E4 @ =0x00000874
	add r5, r8
	adds r3, r0, #4
	mov r8, r3
	adds r4, r0, #0
	movs r7, #9
.L08086148:
	ldrb r3, [r4]
	lsls r0, r3, #0x1e
	lsrs r0, r0, #0x1e
	mov r6, sb
	ands r0, r6
	movs r1, #4
	rsbs r1, r1, #0
	adds r2, r1, #0
	mov r6, sl
	ldrb r6, [r6]
	ands r2, r6
	orrs r2, r0
	lsls r0, r3, #0x1c
	lsrs r0, r0, #0x1e
	mov r1, sb
	ands r0, r1
	lsls r0, r0, #2
	movs r6, #0xd
	rsbs r6, r6, #0
	adds r1, r6, #0
	ands r2, r1
	orrs r2, r0
	movs r1, #0x10
	ands r1, r3
	movs r3, #0x11
	rsbs r3, r3, #0
	adds r0, r3, #0
	ands r2, r0
	orrs r2, r1
	mov r6, sl
	strb r2, [r6]
	ldr r2, [r4]
	lsrs r2, r2, #5
	lsls r2, r2, #5
	ldr r0, [sp, #0x48]
	movs r1, #0x1f
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x48]
	mov r0, r8
	ldr r1, [sp, #0x68]
	bl func_fe6_080368DC
	mov r0, sl
	adds r1, r5, #0
	movs r2, #0x14
	bl WriteAndVerifySramFast
	adds r5, #0x14
	movs r0, #0x14
	add r8, r0
	adds r4, #0x14
	subs r7, #1
	cmp r7, #0
	bge .L08086148
	ldr r0, .L080861E8 @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl WriteSaveBlockInfo
	add sp, #0x6c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080861D8: .4byte 0x01000014
.L080861DC: .4byte 0x01000007
.L080861E0: .4byte gUnk_0832731C
.L080861E4: .4byte 0x00000874
.L080861E8: .4byte 0x00020112

	thumb_func_start func_fe6_080861EC
func_fe6_080861EC: @ 0x080861EC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #5
	bl GetSaveSourceAddress
	ldr r2, .L08086214 @ =ReadSramFast
	movs r1, #0xd8
	muls r1, r4, r1
	adds r0, r0, r1
	ldr r3, [r2]
	adds r1, r5, #0
	movs r2, #0xd8
	bl _call_via_r3
	ldrb r0, [r5]
	cmp r0, #0
	beq .L08086218
	movs r0, #1
	b .L0808621A
	.align 2, 0
.L08086214: .4byte ReadSramFast
.L08086218:
	movs r0, #0
.L0808621A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08086220
func_fe6_08086220: @ 0x08086220
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #5
	bl GetSaveSourceAddress
	ldr r2, .L08086254 @ =ReadSramFast
	movs r1, #0xd8
	muls r1, r4, r1
	adds r0, r0, r1
	ldr r4, .L08086258 @ =0x0203DA18
	ldr r3, [r2]
	adds r1, r4, #0
	movs r2, #0xd8
	bl _call_via_r3
	ldrb r0, [r4]
	cmp r0, #0
	beq .L0808625C
	adds r0, r4, #0
	adds r1, r5, #0
	bl func_fe6_080368DC
	movs r0, #1
	b .L0808625E
	.align 2, 0
.L08086254: .4byte ReadSramFast
.L08086258: .4byte 0x0203DA18
.L0808625C:
	movs r0, #0
.L0808625E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08086264
func_fe6_08086264: @ 0x08086264
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r6, r0, #0
	movs r0, #5
	bl GetSaveTargetAddress
	adds r4, r0, #0
	add r0, sp, #0x10
	movs r1, #0
	strh r1, [r0]
	ldr r5, .L080862AC @ =0x0203DA18
	ldr r2, .L080862B0 @ =0x0100006C
	adds r1, r5, #0
	bl CpuSet
	movs r0, #0xd8
	muls r0, r6, r0
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xd8
	bl WriteAndVerifySramFast
	ldr r0, .L080862B4 @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl WriteSaveBlockInfo
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080862AC: .4byte 0x0203DA18
.L080862B0: .4byte 0x0100006C
.L080862B4: .4byte 0x00020112

	thumb_func_start func_fe6_080862B8
func_fe6_080862B8: @ 0x080862B8
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x10
	adds r6, r0, #0
	mov sb, r1
	movs r0, #5
	bl GetSaveSourceAddress
	adds r4, r0, #0
	movs r0, #5
	bl GetSaveTargetAddress
	adds r5, r0, #0
	ldr r1, .L08086324 @ =ReadSramFast
	movs r0, #0xd8
	mov r8, r0
	mov r0, r8
	muls r0, r6, r0
	adds r4, r4, r0
	ldr r6, .L08086328 @ =0x0203DA18
	ldr r3, [r1]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xd8
	bl _call_via_r3
	mov r1, r8
	mov r0, sb
	muls r0, r1, r0
	adds r5, r5, r0
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xd8
	bl WriteAndVerifySramFast
	ldr r0, .L0808632C @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl WriteSaveBlockInfo
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08086324: .4byte ReadSramFast
.L08086328: .4byte 0x0203DA18
.L0808632C: .4byte 0x00020112

	thumb_func_start func_fe6_08086330
func_fe6_08086330: @ 0x08086330
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	mov sl, r1
	movs r0, #5
	bl GetSaveSourceAddress
	adds r5, r0, #0
	movs r0, #5
	bl GetSaveTargetAddress
	adds r6, r0, #0
	ldr r0, .L080863BC @ =ReadSramFast
	mov sb, r0
	movs r4, #0xd8
	mov r7, r8
	muls r7, r4, r7
	adds r0, r5, r7
	mov r1, sb
	ldr r3, [r1]
	ldr r1, .L080863C0 @ =0x0203DA18
	movs r2, #0xd8
	bl _call_via_r3
	mov r0, sl
	muls r0, r4, r0
	adds r4, r0, #0
	adds r5, r5, r4
	ldr r1, .L080863C4 @ =0x0203DAF0
	mov r8, r1
	mov r0, sb
	ldr r3, [r0]
	adds r0, r5, #0
	movs r2, #0xd8
	bl _call_via_r3
	adds r4, r6, r4
	ldr r0, .L080863C0 @ =0x0203DA18
	adds r1, r4, #0
	movs r2, #0xd8
	bl WriteAndVerifySramFast
	adds r6, r6, r7
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0xd8
	bl WriteAndVerifySramFast
	ldr r0, .L080863C8 @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl WriteSaveBlockInfo
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080863BC: .4byte ReadSramFast
.L080863C0: .4byte 0x0203DA18
.L080863C4: .4byte 0x0203DAF0
.L080863C8: .4byte 0x00020112

	thumb_func_start func_fe6_080863CC
func_fe6_080863CC: @ 0x080863CC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x10
	adds r4, r0, #0
	mov r8, r1
	adds r6, r2, #0
	movs r0, #5
	bl GetSaveTargetAddress
	adds r5, r0, #0
	movs r0, #0xd8
	muls r4, r0, r4
	adds r1, r5, r4
	adds r0, r6, #0
	movs r2, #0xf
	bl WriteAndVerifySramFast
	adds r4, #0x10
	adds r5, r5, r4
	mov r4, r8
	movs r6, #4
.L080863F8:
	adds r0, r4, #0
	adds r1, r5, #0
	bl SaveUnit
	adds r5, #0x28
	adds r4, #0x48
	subs r6, #1
	cmp r6, #0
	bge .L080863F8
	ldr r0, .L08086428 @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl WriteSaveBlockInfo
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08086428: .4byte 0x00020112

	thumb_func_start func_fe6_0808642C
func_fe6_0808642C: @ 0x0808642C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, #0
	adds r5, r2, #0
	movs r0, #5
	bl GetSaveSourceAddress
	adds r7, r0, #0
	ldr r1, .L08086480 @ =ReadSramFast
	movs r0, #0xd8
	mov r4, r8
	muls r4, r0, r4
	adds r0, r7, r4
	ldr r3, [r1]
	adds r1, r5, #0
	movs r2, #0xf
	bl _call_via_r3
	adds r4, #0x10
	adds r4, r7, r4
	movs r5, #4
.L0808645A:
	adds r0, r4, #0
	adds r1, r6, #0
	bl LoadUnit
	adds r6, #0x48
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge .L0808645A
	movs r0, #0xd8
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r7, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08086484
	movs r0, #1
	b .L08086486
	.align 2, 0
.L08086480: .4byte ReadSramFast
.L08086484:
	movs r0, #0
.L08086486:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08086490
func_fe6_08086490: @ 0x08086490
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #5
	bl GetSaveTargetAddress
	adds r1, r0, #0
	ldr r0, .L080864C4 @ =0x00000874
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #0xc8
	bl WriteAndVerifySramFast
	ldr r0, .L080864C8 @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl WriteSaveBlockInfo
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080864C4: .4byte 0x00000874
.L080864C8: .4byte 0x00020112

	thumb_func_start func_fe6_080864CC
func_fe6_080864CC: @ 0x080864CC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #5
	bl GetSaveSourceAddress
	ldr r1, .L080864EC @ =ReadSramFast
	ldr r2, .L080864F0 @ =0x00000874
	adds r0, r0, r2
	ldr r3, [r1]
	adds r1, r4, #0
	movs r2, #0xc8
	bl _call_via_r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080864EC: .4byte ReadSramFast
.L080864F0: .4byte 0x00000874

	thumb_func_start func_fe6_080864F4
func_fe6_080864F4: @ 0x080864F4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #5
	bl GetSaveTargetAddress
	adds r1, r0, #0
	movs r0, #0x87
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #2
	bl WriteAndVerifySramFast
	ldr r0, .L0808652C @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl WriteSaveBlockInfo
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808652C: .4byte 0x00020112

	thumb_func_start func_fe6_08086530
func_fe6_08086530: @ 0x08086530
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #5
	bl GetSaveSourceAddress
	ldr r1, .L08086554 @ =ReadSramFast
	movs r2, #0x87
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r3, [r1]
	adds r1, r4, #0
	movs r2, #2
	bl _call_via_r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08086554: .4byte ReadSramFast

	thumb_func_start func_fe6_08086558
func_fe6_08086558: @ 0x08086558
	push {r4, lr}
	sub sp, #0x10
	movs r0, #5
	bl VerifySaveBlockInfoByIndex2
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0808656E
	b .L08086586
.L0808656A:
	movs r0, #1
	b .L08086588
.L0808656E:
	movs r4, #0
.L08086570:
	adds r0, r4, #0
	mov r1, sp
	bl func_fe6_08086220
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L0808656A
	adds r4, #1
	cmp r4, #9
	ble .L08086570
.L08086586:
	movs r0, #0
.L08086588:
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08086590
func_fe6_08086590: @ 0x08086590
	push {r4, r5, lr}
	ldr r1, .L080865D0 @ =ReadSramFast
	ldr r5, .L080865D4 @ =gUnk_08689DDC
	ldr r0, [r5]
	ldr r4, .L080865D8 @ =0x0203DBC8
	ldr r3, [r1]
	adds r1, r4, #0
	movs r2, #0x1c
	bl _call_via_r3
	ldr r1, [r4]
	ldr r0, .L080865DC @ =0x50414D58
	cmp r1, r0
	bne .L080865E4
	bl GetLang
	lsls r0, r0, #0x18
	ldr r1, .L080865E0 @ =0x00020223
	adds r0, r0, r1
	ldr r1, [r4, #8]
	cmp r1, r0
	bne .L080865E4
	ldr r0, [r4, #0x10]
	ldr r1, [r5]
	adds r0, r0, r1
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x18]
	adds r0, r0, r1
	str r0, [r4, #0x18]
	movs r0, #1
	b .L080865E6
	.align 2, 0
.L080865D0: .4byte ReadSramFast
.L080865D4: .4byte gUnk_08689DDC
.L080865D8: .4byte 0x0203DBC8
.L080865DC: .4byte 0x50414D58
.L080865E0: .4byte 0x00020223
.L080865E4:
	movs r0, #0
.L080865E6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_080865EC
func_fe6_080865EC: @ 0x080865EC
	ldr r2, .L080865FC @ =0x0203DBC8
	ldr r1, [r2]
	ldr r0, .L08086600 @ =0x50414D58
	cmp r1, r0
	bne .L08086604
	ldr r0, [r2, #0x10]
	b .L08086606
	.align 2, 0
.L080865FC: .4byte 0x0203DBC8
.L08086600: .4byte 0x50414D58
.L08086604:
	movs r0, #0
.L08086606:
	bx lr

	thumb_func_start func_fe6_08086608
func_fe6_08086608: @ 0x08086608
	ldr r2, .L08086618 @ =0x0203DBC8
	ldr r1, [r2]
	ldr r0, .L0808661C @ =0x50414D58
	cmp r1, r0
	bne .L08086620
	movs r1, #0x14
	ldrsh r0, [r2, r1]
	b .L08086622
	.align 2, 0
.L08086618: .4byte 0x0203DBC8
.L0808661C: .4byte 0x50414D58
.L08086620:
	movs r0, #0
.L08086622:
	bx lr

	thumb_func_start func_fe6_08086624
func_fe6_08086624: @ 0x08086624
	ldr r2, .L08086634 @ =0x0203DBC8
	ldr r1, [r2]
	ldr r0, .L08086638 @ =0x50414D58
	cmp r1, r0
	bne .L0808663C
	ldr r0, [r2, #0x18]
	b .L0808663E
	.align 2, 0
.L08086634: .4byte 0x0203DBC8
.L08086638: .4byte 0x50414D58
.L0808663C:
	movs r0, #0
.L0808663E:
	bx lr

	thumb_func_start func_fe6_08086640
func_fe6_08086640: @ 0x08086640
	ldr r2, .L08086650 @ =0x0203DBC8
	ldr r1, [r2]
	ldr r0, .L08086654 @ =0x50414D58
	cmp r1, r0
	bne .L08086658
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	b .L0808665A
	.align 2, 0
.L08086650: .4byte 0x0203DBC8
.L08086654: .4byte 0x50414D58
.L08086658:
	movs r0, #0
.L0808665A:
	bx lr

	thumb_func_start func_fe6_0808665C
func_fe6_0808665C: @ 0x0808665C
	adds r2, r0, #0
	movs r3, #0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	cmp r3, r1
	bge .L08086676
.L0808666A:
	ldrh r0, [r2]
	adds r3, r0, r3
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne .L0808666A
.L08086676:
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	bx lr

	thumb_func_start func_fe6_0808667C
func_fe6_0808667C: @ 0x0808667C
	push {r4, lr}
	ldr r4, .L080866D0 @ =gBuf
	bl IsSramWorking
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080866E4
	ldr r1, .L080866D4 @ =ReadSramFast
	ldr r0, .L080866D8 @ =0x0E007000
	movs r2, #0x80
	lsls r2, r2, #5
	ldr r3, [r1]
	adds r1, r4, #0
	bl _call_via_r3
	ldr r1, [r4]
	ldr r0, .L080866DC @ =0x50414D58
	cmp r1, r0
	bne .L080866E4
	bl GetLang
	lsls r0, r0, #0x18
	ldr r1, .L080866E0 @ =0x00020223
	adds r0, r0, r1
	ldr r1, [r4, #8]
	cmp r1, r0
	bne .L080866E4
	ldrh r0, [r4, #4]
	cmp r0, #0
	beq .L080866E4
	adds r0, r4, #0
	adds r0, #8
	ldrh r1, [r4, #4]
	bl func_fe6_0808665C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r4, #6]
	cmp r4, r0
	bne .L080866E4
	movs r0, #1
	b .L080866E6
	.align 2, 0
.L080866D0: .4byte gBuf
.L080866D4: .4byte ReadSramFast
.L080866D8: .4byte 0x0E007000
.L080866DC: .4byte 0x50414D58
.L080866E0: .4byte 0x00020223
.L080866E4:
	movs r0, #0
.L080866E6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_080866EC
func_fe6_080866EC: @ 0x080866EC
	push {r4, r5, r6, lr}
	bl func_fe6_08086590
	ldr r5, .L08086754 @ =ReadSramFast
	bl func_fe6_08086624
	adds r4, r0, #0
	ldr r6, .L08086758 @ =gBuf
	bl func_fe6_08086640
	adds r2, r0, #0
	ldr r3, [r5]
	adds r0, r4, #0
	adds r1, r6, #0
	bl _call_via_r3
	ldr r4, .L0808675C @ =gTrialLoadInfo
	ldr r1, [r4]
	adds r0, r6, #0
	bl Decompress
	ldr r1, [r4]
	ldr r0, .L08086760 @ =gPlaySt
	str r0, [r1, #0x18]
	ldr r0, .L08086764 @ =gBmSt
	str r0, [r1, #0x1c]
	ldr r0, .L08086768 @ =gActiveUnit
	str r0, [r1, #0x20]
	ldr r0, .L0808676C @ =gUnitLut
	str r0, [r1, #0x24]
	ldr r0, .L08086770 @ =gBattleUnitA
	str r0, [r1, #0x28]
	ldr r0, .L08086774 @ =gBattleUnitB
	str r0, [r1, #0x2c]
	ldr r0, .L08086778 @ =gBattleHits
	str r0, [r1, #0x30]
	movs r0, #0
	bl GetTrap
	ldr r1, [r4]
	str r0, [r1, #0x34]
	bl GetPermanentFlagBits
	ldr r1, [r4]
	str r0, [r1, #0x38]
	bl GetChapterFlagBits
	ldr r1, [r4]
	str r0, [r1, #0x3c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08086754: .4byte ReadSramFast
.L08086758: .4byte gBuf
.L0808675C: .4byte gTrialLoadInfo
.L08086760: .4byte gPlaySt
.L08086764: .4byte gBmSt
.L08086768: .4byte gActiveUnit
.L0808676C: .4byte gUnitLut
.L08086770: .4byte gBattleUnitA
.L08086774: .4byte gBattleUnitB
.L08086778: .4byte gBattleHits

	thumb_func_start func_fe6_0808677C
func_fe6_0808677C: @ 0x0808677C
	push {r4, lr}
	sub sp, #0x20
	adds r4, r0, #0
	mov r0, sp
	bl LoadGlobalSaveInfo
	movs r0, #0x28
	strb r0, [r4]
	adds r4, #1
	movs r0, #0x29
	strb r0, [r4]
	adds r4, #1
	mov r1, sp
	movs r0, #4
	ldrb r1, [r1, #0xe]
	ands r0, r1
	cmp r0, #0
	beq .L080867A6
	movs r0, #0x2a
	strb r0, [r4]
	adds r4, #1
.L080867A6:
	mov r1, sp
	movs r0, #2
	ldrb r1, [r1, #0xe]
	ands r0, r1
	cmp r0, #0
	beq .L080867B8
	movs r0, #0x2b
	strb r0, [r4]
	adds r4, #1
.L080867B8:
	mov r1, sp
	movs r0, #8
	ldrb r1, [r1, #0xe]
	ands r0, r1
	cmp r0, #0
	beq .L080867CA
	movs r0, #0x2c
	strb r0, [r4]
	adds r4, #1
.L080867CA:
	bl func_fe6_0808667C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080867E2
	bl func_fe6_080866EC
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r1, #0
	strb r0, [r4]
	adds r4, #1
.L080867E2:
	movs r0, #0
	strb r0, [r4]
	movs r0, #1
	add sp, #0x20
	pop {r4}
	pop {r1}
	bx r1
