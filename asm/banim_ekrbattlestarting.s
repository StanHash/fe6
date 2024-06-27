	.include "macro.inc"

	.syntax unified

	.section .data

	.global ProcScr_EkrBattleStarting
ProcScr_EkrBattleStarting: @ 085CBB18
	.incbin "fe6-base.gba", 0x5CBB18, (0x5CBB60 - 0x5CBB18) @ length: 0048

	.section .text
	thumb_func_start SetupBanim
SetupBanim: @ 0x08047CB8
	push {lr}
	bl _SetupBanim
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start BeginAnimsOnBattleAnimations
BeginAnimsOnBattleAnimations: @ 0x08047CC8
	push {lr}
	bl GetBattleAnimArenaFlag
	cmp r0, #1
	bne .L08047CD8
	bl BeginAnimsOnBattle_Arena
	b .L08047D04
.L08047CD8:
	bl NewEkrBattleDeamon
	bl BasInit
	bl GetBanimInitPosReal
	ldr r1, .L08047D08 @ =gEkrInitPosReal
	str r0, [r1]
	bl NewEkrBattleStarting
	ldr r1, .L08047D0C @ =gAnims
	movs r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	str r0, [r1, #0xc]
	ldr r0, .L08047D10 @ =OnMainBas
	bl SetMainFunc
	movs r0, #0
	bl SetOnHBlankA
.L08047D04:
	pop {r0}
	bx r0
	.align 2, 0
.L08047D08: .4byte gEkrInitPosReal
.L08047D0C: .4byte gAnims
.L08047D10: .4byte OnMainBas

	thumb_func_start EkrMainEndExec
EkrMainEndExec: @ 0x08047D14
	push {lr}
	bl GetBattleAnimArenaFlag
	cmp r0, #1
	bne .L08047D24
	bl ExecBattleAnimArenaExit
	b .L08047D2E
.L08047D24:
	bl NewEkrbattleending
	ldr r0, .L08047D34 @ =OnMainBas
	bl SetMainFunc
.L08047D2E:
	pop {r0}
	bx r0
	.align 2, 0
.L08047D34: .4byte OnMainBas

	thumb_func_start OnMainBas
OnMainBas: @ 0x08047D38
	push {r4, lr}
	ldr r0, .L08047D9C @ =gKeySt
	ldr r0, [r0]
	bl RefreshKeySt
	bl ClearSprites
	ldr r4, .L08047DA0 @ =gProcTreeRootArray
	ldr r0, [r4, #4]
	bl Proc_Run
	bl GetGameLock
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08047D5E
	ldr r0, [r4, #8]
	bl Proc_Run
.L08047D5E:
	ldr r0, [r4, #0xc]
	bl Proc_Run
	ldr r0, [r4, #0x14]
	bl Proc_Run
	movs r0, #0
	bl PutSpriteLayerOam
	ldr r0, [r4, #0x10]
	bl Proc_Run
	bl BasUpdateAll
	bl BattleAIS_ExecCommands
	movs r0, #0xd
	bl PutSpriteLayerOam
	ldr r1, .L08047DA4 @ =gBmSt
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L08047DA8 @ =0x04000006
	ldrh r0, [r0]
	strh r0, [r1, #6]
	bl VBlankIntrWait
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08047D9C: .4byte gKeySt
.L08047DA0: .4byte gProcTreeRootArray
.L08047DA4: .4byte gBmSt
.L08047DA8: .4byte 0x04000006

	thumb_func_start NewEkrBattleStarting
NewEkrBattleStarting: @ 0x08047DAC
	push {lr}
	ldr r0, .L08047DBC @ =ProcScr_EkrBattleStarting
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L08047DBC: .4byte ProcScr_EkrBattleStarting

	thumb_func_start EkrBaStart_InitScreen
EkrBaStart_InitScreen: @ 0x08047DC0
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	adds r5, r0, #0
	movs r4, #0
	movs r3, #0
	strh r3, [r5, #0x2c]
	movs r0, #0xf
	strh r0, [r5, #0x2e]
	ldr r2, .L08047EC0 @ =gEkrBmLocation
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r6, #4
	ldrsh r1, [r2, r6]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x32]
	movs r1, #2
	ldrsh r0, [r2, r1]
	movs r6, #6
	ldrsh r1, [r2, r6]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r5, #0x3c]
	strh r0, [r5, #0x3a]
	str r3, [sp]
	ldr r1, .L08047EC4 @ =gBg2Tm
	ldr r2, .L08047EC8 @ =0x01000200
	mov r0, sp
	bl CpuFastSet
	movs r0, #4
	bl EnableBgSync
	ldr r6, .L08047ECC @ =gDispIo
	adds r1, r6, #0
	adds r1, #0x3c
	movs r0, #0xc0
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r1, #0xa
	movs r0, #4
	mov sl, r0
	movs r0, #4
	strb r0, [r1]
	ldr r0, .L08047ED0 @ =0x0000FFE0
	ldrh r1, [r6, #0x3c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r6, #0x3c]
	movs r2, #0x20
	mov sb, r2
	mov r0, sb
	ldrb r1, [r6, #1]
	orrs r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r6, #1]
	adds r0, r6, #0
	adds r0, #0x2d
	strb r4, [r0]
	adds r0, #4
	strb r4, [r0]
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	movs r2, #0x34
	adds r2, r2, r6
	mov r8, r2
	movs r0, #1
	ldrb r1, [r2]
	orrs r1, r0
	movs r4, #2
	orrs r1, r4
	mov r2, sl
	orrs r1, r2
	movs r3, #8
	orrs r1, r3
	movs r2, #0x10
	orrs r1, r2
	adds r6, #0x36
	ldrb r2, [r6]
	orrs r0, r2
	orrs r0, r4
	mov r2, sl
	orrs r0, r2
	orrs r0, r3
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r0, r2
	subs r2, #0x10
	ands r1, r2
	mov r2, r8
	strb r1, [r2]
	mov r1, sb
	orrs r0, r1
	strb r0, [r6]
	adds r0, r5, #0
	bl Proc_Break
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08047EC0: .4byte gEkrBmLocation
.L08047EC4: .4byte gBg2Tm
.L08047EC8: .4byte 0x01000200
.L08047ECC: .4byte gDispIo
.L08047ED0: .4byte 0x0000FFE0

	thumb_func_start EkrBaStart_SreenFailIn
EkrBaStart_SreenFailIn: @ 0x08047ED4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldrh r0, [r7, #0x2c]
	ldrh r1, [r7, #0x2e]
	cmp r0, r1
	beq .L08047EEC
	adds r0, #1
	strh r0, [r7, #0x2c]
.L08047EEC:
	movs r0, #0x32
	ldrsh r2, [r7, r0]
	movs r1, #0x2c
	ldrsh r3, [r7, r1]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	adds r6, r0, #0
	movs r0, #0x3a
	ldrsh r2, [r7, r0]
	movs r1, #0x2c
	ldrsh r3, [r7, r1]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	adds r5, r0, #0
	movs r0, #0x34
	ldrsh r2, [r7, r0]
	movs r1, #0x2c
	ldrsh r3, [r7, r1]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0xf0
	bl Interpolate
	adds r4, r0, #0
	movs r0, #0x3c
	ldrsh r2, [r7, r0]
	movs r1, #0x2c
	ldrsh r3, [r7, r1]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0xa0
	bl Interpolate
	ldr r1, .L08047FD4 @ =gDispIo
	movs r2, #0x2d
	adds r2, r2, r1
	mov r8, r2
	movs r2, #0
	mov sb, r2
	mov r2, r8
	strb r6, [r2]
	adds r6, r1, #0
	adds r6, #0x31
	strb r5, [r6]
	adds r5, r1, #0
	adds r5, #0x2c
	strb r4, [r5]
	adds r4, r1, #0
	adds r4, #0x30
	strb r0, [r4]
	ldrh r0, [r7, #0x2c]
	ldrh r2, [r7, #0x2e]
	cmp r0, r2
	bne .L08047FC4
	adds r2, r1, #0
	adds r2, #0x36
	movs r0, #1
	ldrb r1, [r2]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0
	bl InitOam
	bl LockBmDisplay
	mov r0, sb
	mov r2, r8
	strb r0, [r2]
	strb r0, [r6]
	movs r0, #0xf0
	strb r0, [r5]
	movs r0, #0xa0
	strb r0, [r4]
	ldr r0, .L08047FD8 @ =gPal
	movs r1, #6
	movs r2, #0xa
	movs r3, #4
	bl EfxPalBlackInOut
	bl EnablePalSync
	bl EndAllMus
	adds r0, r7, #0
	bl Proc_Break
.L08047FC4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08047FD4: .4byte gDispIo
.L08047FD8: .4byte gPal

	thumb_func_start EkrBaStart_InitBattleScreen
EkrBaStart_InitBattleScreen: @ 0x08047FDC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08048008 @ =gEkrDebugModeMaybe
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08048040
	bl NewEkrGauge
	bl NewEkrDispUP
	ldr r0, .L0804800C @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	beq .L08048010
	cmp r0, #3
	ble .L08048040
	cmp r0, #4
	beq .L08048038
	b .L08048040
	.align 2, 0
.L08048008: .4byte gEkrDebugModeMaybe
.L0804800C: .4byte gEkrDistanceType
.L08048010:
	ldr r4, .L08048034 @ =gBanimValid
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L08048022
	bl func_fe6_080438E8
	bl func_fe6_080441FC
.L08048022:
	movs r1, #2
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L08048040
	bl func_fe6_080438F8
	bl func_fe6_0804420C
	b .L08048040
	.align 2, 0
.L08048034: .4byte gBanimValid
.L08048038:
	bl func_fe6_080438E8
	bl func_fe6_080441FC
.L08048040:
	bl EfxClearScreenFx
	movs r0, #0
	bl NewEkrUnitKakudai
	movs r0, #0
	bl NewEkrBaseKaiten
	movs r0, #0
	movs r1, #0xb
	bl NewEkrWindowAppear
	movs r0, #0
	movs r1, #0xb
	movs r2, #0
	bl NewEkrNamewinAppear
	movs r0, #0
	movs r1, #0xb
	bl NewEkrBaseAppear
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EkrBaStart_ExecEkrBattle
EkrBaStart_ExecEkrBattle: @ 0x0804807C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble .L080480BC
	ldr r0, .L080480AC @ =gBanimBackgroundIndex
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080480A0
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L080480B0
.L080480A0:
	bl NewEkrBattle
	adds r0, r4, #0
	bl Proc_End
	b .L080480BC
	.align 2, 0
.L080480AC: .4byte gBanimBackgroundIndex
.L080480B0:
	strh r0, [r4, #0x2c]
	bl NewEkrBattle
	adds r0, r4, #0
	bl Proc_Break
.L080480BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080480C4
func_fe6_080480C4: @ 0x080480C4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #0
	movs r1, #4
	movs r2, #0x10
	bl Interpolate
	bl EfxChapterMapFadeOUT
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L080480F8
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L080480F8:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08048100
func_fe6_08048100: @ 0x08048100
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08048114 @ =gEkrSnowWeather
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0804811C
	ldr r1, .L08048118 @ =gUnk_Banim_0201E0F8
	movs r0, #6
	b .L08048120
	.align 2, 0
.L08048114: .4byte gEkrSnowWeather
.L08048118: .4byte gUnk_Banim_0201E0F8
.L0804811C:
	ldr r1, .L08048148 @ =gUnk_Banim_0201E0F8
	movs r0, #0xa
.L08048120:
	str r0, [r1]
	ldr r0, .L0804814C @ =gBanimBackgroundIndex
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r0, #1
	bl func_fe6_0805F100
	ldr r0, .L08048150 @ =gPal
	movs r1, #6
	movs r2, #0xa
	movs r3, #0x10
	bl EfxPalBlackInOut
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08048148: .4byte gUnk_Banim_0201E0F8
.L0804814C: .4byte gBanimBackgroundIndex
.L08048150: .4byte gPal

	thumb_func_start func_fe6_08048154
func_fe6_08048154: @ 0x08048154
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r4, r0, #0
	ldr r0, .L080481AC @ =gBanimBackgroundIndex
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r0, #1
	bl func_fe6_0805F0DC
	ldr r0, .L080481B0 @ =gPal
	movs r1, #6
	movs r2, #0xa
	adds r3, r4, #0
	bl EfxPalBlackInOut
	bl EnablePalSync
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L080481A2
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L080481A2:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080481AC: .4byte gBanimBackgroundIndex
.L080481B0: .4byte gPal
