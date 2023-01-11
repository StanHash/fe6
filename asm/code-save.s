	.include "macro.inc"

	.syntax unified

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
