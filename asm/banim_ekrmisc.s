	.include "macro.inc"

	.syntax unified

	thumb_func_start GetBanimInitPosReal
GetBanimInitPosReal: @ 0x08044870
	push {r4, r5, lr}
	ldr r0, .L08044888 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bhi .L080448B0
	lsls r0, r0, #2
	ldr r1, .L0804488C @ =.L08044890
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08044888: .4byte gEkrDistanceType
.L0804488C: .4byte .L08044890
.L08044890: @ jump table
	.4byte .L080448F8 @ case 0
	.4byte .L080448A4 @ case 1
	.4byte .L080448B0 @ case 2
	.4byte .L080448F8 @ case 3
	.4byte .L080448F8 @ case 4
.L080448A4:
	ldr r0, .L080448AC @ =gEkrInitialHitSide
	movs r2, #0
	ldrsh r0, [r0, r2]
	b .L080448FA
	.align 2, 0
.L080448AC: .4byte gEkrInitialHitSide
.L080448B0:
	movs r1, #0
	movs r5, #0
	ldr r0, .L080448E0 @ =gEkrDebugModeMaybe
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080448D8
	ldr r4, .L080448E4 @ =gEkrPids
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	bl CheckBattleTalk
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	ldrb r0, [r4, #1]
	ldrb r1, [r4]
	bl CheckBattleTalk
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
.L080448D8:
	cmp r5, #1
	bne .L080448E8
	movs r0, #0
	b .L080448FA
	.align 2, 0
.L080448E0: .4byte gEkrDebugModeMaybe
.L080448E4: .4byte gEkrPids
.L080448E8:
	cmp r1, #1
	beq .L080448F8
	ldr r0, .L080448F4 @ =gEkrInitialHitSide
	movs r1, #0
	ldrsh r0, [r0, r1]
	b .L080448FA
	.align 2, 0
.L080448F4: .4byte gEkrInitialHitSide
.L080448F8:
	movs r0, #1
.L080448FA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start EkrEfxStatusClear
EkrEfxStatusClear: @ 0x08044900
	push {r4, lr}
	ldr r0, .L0804496C @ =gEkrHpBarCount
	movs r4, #0
	str r4, [r0]
	ldr r0, .L08044970 @ =gEfxSpellAnimExists
	str r4, [r0]
	ldr r0, .L08044974 @ =gUnk_Banim_02017728
	str r4, [r0]
	ldr r0, .L08044978 @ =gEkrDeadEventExist
	str r4, [r0]
	ldr r0, .L0804497C @ =gEfxQuakeExist
	str r4, [r0]
	ldr r0, .L08044980 @ =gUnk_Banim_02017738
	str r4, [r0]
	ldr r0, .L08044984 @ =gEfxFarAttackExist
	str r4, [r0]
	ldr r0, .L08044988 @ =gEfxBgSemaphore
	str r4, [r0]
	ldr r0, .L0804498C @ =gEfxHpBarResireFlag
	str r4, [r0]
	ldr r0, .L08044990 @ =gUnk_Banim_0201774C
	str r4, [r0]
	ldr r0, .L08044994 @ =gUnk_Banim_02017750
	str r4, [r0]
	ldr r0, .L08044998 @ =gUnk_Banim_02017754
	str r4, [r0]
	ldr r0, .L0804499C @ =gEkrBg2QuakeVec
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, .L080449A0 @ =gUnk_Banim_0201775C
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, .L080449A4 @ =gUnk_Banim_02017760
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, .L080449A8 @ =gEkrHitNow
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, .L080449AC @ =gUnk_Banim_02017764
	str r4, [r0]
	str r4, [r0, #4]
	ldr r0, .L080449B0 @ =gUnk_Banim_02017770
	str r4, [r0]
	ldr r0, .L080449B4 @ =gUnk_Banim_02017774
	str r4, [r0]
	ldr r0, .L080449B8 @ =gUnk_08113D70
	ldr r1, .L080449BC @ =0x06012000
	bl LZ77UnCompVram
	ldr r0, .L080449C0 @ =gUnk_Banim_0201E7A4
	str r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804496C: .4byte gEkrHpBarCount
.L08044970: .4byte gEfxSpellAnimExists
.L08044974: .4byte gUnk_Banim_02017728
.L08044978: .4byte gEkrDeadEventExist
.L0804497C: .4byte gEfxQuakeExist
.L08044980: .4byte gUnk_Banim_02017738
.L08044984: .4byte gEfxFarAttackExist
.L08044988: .4byte gEfxBgSemaphore
.L0804498C: .4byte gEfxHpBarResireFlag
.L08044990: .4byte gUnk_Banim_0201774C
.L08044994: .4byte gUnk_Banim_02017750
.L08044998: .4byte gUnk_Banim_02017754
.L0804499C: .4byte gEkrBg2QuakeVec
.L080449A0: .4byte gUnk_Banim_0201775C
.L080449A4: .4byte gUnk_Banim_02017760
.L080449A8: .4byte gEkrHitNow
.L080449AC: .4byte gUnk_Banim_02017764
.L080449B0: .4byte gUnk_Banim_02017770
.L080449B4: .4byte gUnk_Banim_02017774
.L080449B8: .4byte gUnk_08113D70
.L080449BC: .4byte 0x06012000
.L080449C0: .4byte gUnk_Banim_0201E7A4
