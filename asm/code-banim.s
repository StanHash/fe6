	.include "macro.inc"
	.syntax unified

	thumb_func_start NewEfxYushaSpinShield
NewEfxYushaSpinShield: @ 0x08056D80
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08056DA4 @ =ProcScr_EfxYushaSpinShield
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	adds r0, r4, #0
	adds r1, r5, #0
	bl NewEfxYushaSpinShieldOBJ
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056DA4: .4byte ProcScr_EfxYushaSpinShield

	thumb_func_start func_fe6_08056DA8
func_fe6_08056DA8: @ 0x08056DA8
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NewEfxYushaSpinShieldOBJ
NewEfxYushaSpinShieldOBJ: @ 0x08056DB4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, .L08056DDC @ =ProcScr_EfxYushaSpinShieldOBJ
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	adds r0, #0x29
	strb r4, [r0]
	cmp r4, #0
	bne .L08056DE8
	ldr r2, .L08056DE0 @ =gUnk_085DC850
	ldr r3, .L08056DE4 @ =gUnk_085DDAF0
	b .L08056DEC
	.align 2, 0
.L08056DDC: .4byte ProcScr_EfxYushaSpinShieldOBJ
.L08056DE0: .4byte gUnk_085DC850
.L08056DE4: .4byte gUnk_085DDAF0
.L08056DE8:
	ldr r2, .L08056E18 @ =gUnk_085DEDC0
	ldr r3, .L08056E1C @ =gUnk_085E0090
.L08056DEC:
	str r2, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	bl EfxCreateFrontAnim
	adds r4, r0, #0
	str r4, [r5, #0x60]
	movs r0, #0xc0
	lsls r0, r0, #4
	ldrh r1, [r4, #8]
	ands r0, r1
	movs r5, #0
	strh r0, [r4, #8]
	adds r0, r6, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08056E20
	movs r1, #0xe4
	lsls r1, r1, #7
	b .L08056E24
	.align 2, 0
.L08056E18: .4byte gUnk_085DEDC0
.L08056E1C: .4byte gUnk_085E0090
.L08056E20:
	movs r1, #0x93
	lsls r1, r1, #8
.L08056E24:
	adds r0, r1, #0
	ldrh r1, [r4, #8]
	orrs r0, r1
	strh r0, [r4, #8]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08056E34
func_fe6_08056E34: @ 0x08056E34
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x45
	bne .L08056E92
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08056E6C
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08056E64
	ldr r0, .L08056E60 @ =gUnk_085DDBF4
	b .L08056E82
	.align 2, 0
.L08056E60: .4byte gUnk_085DDBF4
.L08056E64:
	ldr r0, .L08056E68 @ =gUnk_085DC954
	b .L08056E82
	.align 2, 0
.L08056E68: .4byte gUnk_085DC954
.L08056E6C:
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08056E80
	ldr r0, .L08056E7C @ =gUnk_085E0194
	b .L08056E82
	.align 2, 0
.L08056E7C: .4byte gUnk_085E0194
.L08056E80:
	ldr r0, .L08056E98 @ =gUnk_085DEEC4
.L08056E82:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L08056E92:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056E98: .4byte gUnk_085DEEC4

	thumb_func_start func_fe6_08056E9C
func_fe6_08056E9C: @ 0x08056E9C
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x5c]
	ldrh r2, [r0, #0x10]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq .L08056EBE
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq .L08056EBE
	movs r0, #0
	strh r0, [r1, #0x2c]
	adds r0, r1, #0
	bl Proc_Break
.L08056EBE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08056EC4
func_fe6_08056EC4: @ 0x08056EC4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	bl CheckEkrHitDone
	cmp r0, #1
	bne .L08056F1E
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08056EF8
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08056EF0
	ldr r0, .L08056EEC @ =gUnk_085DDC1C
	b .L08056F0E
	.align 2, 0
.L08056EEC: .4byte gUnk_085DDC1C
.L08056EF0:
	ldr r0, .L08056EF4 @ =gUnk_085DC97C
	b .L08056F0E
	.align 2, 0
.L08056EF4: .4byte gUnk_085DC97C
.L08056EF8:
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08056F0C
	ldr r0, .L08056F08 @ =gUnk_085E01BC
	b .L08056F0E
	.align 2, 0
.L08056F08: .4byte gUnk_085E01BC
.L08056F0C:
	ldr r0, .L08056F24 @ =gUnk_085DEEEC
.L08056F0E:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L08056F1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056F24: .4byte gUnk_085DEEEC

	thumb_func_start func_fe6_08056F28
func_fe6_08056F28: @ 0x08056F28
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	bne .L08056F4A
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08056F4A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start NewEfxHurtmutEff00
NewEfxHurtmutEff00: @ 0x08056F50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L08056F7C @ =gEfxBgSemaphore
	ldr r5, [r0]
	cmp r5, #0
	bne .L08056F8E
	ldr r0, .L08056F80 @ =gUnk_085D3594
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	strh r5, [r0, #0x2c]
	ldr r0, .L08056F84 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08056F88
	adds r0, r4, #0
	bl func_fe6_08056FA0
	b .L08056F8E
	.align 2, 0
.L08056F7C: .4byte gEfxBgSemaphore
.L08056F80: .4byte gUnk_085D3594
.L08056F84: .4byte gEkrDistanceType
.L08056F88:
	adds r0, r4, #0
	bl func_fe6_080570A0
.L08056F8E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08056F94
func_fe6_08056F94: @ 0x08056F94
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08056FA0
func_fe6_08056FA0: @ 0x08056FA0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08056FD8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08056FDC @ =gUnk_085D35AC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L08056FE0 @ =AnimScr_ManaketeFlame
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056FD8: .4byte gEfxBgSemaphore
.L08056FDC: .4byte gUnk_085D35AC
.L08056FE0: .4byte AnimScr_ManaketeFlame

	thumb_func_start func_fe6_08056FE4
func_fe6_08056FE4: @ 0x08056FE4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #1
	bne .L08056FFC
	ldr r0, .L08056FF8 @ =gUnk_085D7190
	b .L08056FFE
	.align 2, 0
.L08056FF8: .4byte gUnk_085D7190
.L08056FFC:
	ldr r0, .L08057024 @ =gUnk_085D74FC
.L08056FFE:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	ldr r0, .L08057028 @ =gUnk_08121498
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805702C @ =gUnk_08120414
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057024: .4byte gUnk_085D74FC
.L08057028: .4byte gUnk_08121498
.L0805702C: .4byte gUnk_08120414

	thumb_func_start func_fe6_08057030
func_fe6_08057030: @ 0x08057030
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #1
	bne .L08057048
	ldr r0, .L08057044 @ =gUnk_085D77E4
	b .L0805704A
	.align 2, 0
.L08057044: .4byte gUnk_085D77E4
.L08057048:
	ldr r0, .L08057070 @ =gUnk_085D7A40
.L0805704A:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	ldr r0, .L08057074 @ =gUnk_08121498
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08057078 @ =gUnk_08120CB4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057070: .4byte gUnk_085D7A40
.L08057074: .4byte gUnk_08121498
.L08057078: .4byte gUnk_08120CB4

	thumb_func_start func_fe6_0805707C
func_fe6_0805707C: @ 0x0805707C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0805709C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805709C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080570A0
func_fe6_080570A0: @ 0x080570A0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L080570D8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080570DC @ =gUnk_085D35E4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L080570E0 @ =AnimScr_ManaketeFlame
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080570D8: .4byte gEfxBgSemaphore
.L080570DC: .4byte gUnk_085D35E4
.L080570E0: .4byte AnimScr_ManaketeFlame

	thumb_func_start func_fe6_080570E4
func_fe6_080570E4: @ 0x080570E4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #1
	bne .L080570FC
	ldr r0, .L080570F8 @ =gUnk_085D71D8
	b .L080570FE
	.align 2, 0
.L080570F8: .4byte gUnk_085D71D8
.L080570FC:
	ldr r0, .L08057124 @ =gUnk_085D7544
.L080570FE:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	ldr r0, .L08057128 @ =gUnk_08121498
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805712C @ =gUnk_08120414
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057124: .4byte gUnk_085D7544
.L08057128: .4byte gUnk_08121498
.L0805712C: .4byte gUnk_08120414

	thumb_func_start func_fe6_08057130
func_fe6_08057130: @ 0x08057130
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #1
	bne .L08057148
	ldr r0, .L08057144 @ =gUnk_085D77F4
	b .L0805714A
	.align 2, 0
.L08057144: .4byte gUnk_085D77F4
.L08057148:
	ldr r0, .L08057170 @ =gUnk_085D7A50
.L0805714A:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	ldr r0, .L08057174 @ =gUnk_08121498
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08057178 @ =gUnk_08120CB4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057170: .4byte gUnk_085D7A50
.L08057174: .4byte gUnk_08121498
.L08057178: .4byte gUnk_08120CB4

	thumb_func_start func_fe6_0805717C
func_fe6_0805717C: @ 0x0805717C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0805719C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805719C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080571A0
func_fe6_080571A0: @ 0x080571A0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, .L080571EC @ =gEfxBgSemaphore
	ldr r4, [r0]
	cmp r4, #0
	bne .L08057200
	bl SpellFx_SetBG1Position
	ldr r0, .L080571F0 @ =gUnk_085D361C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	strh r4, [r5, #0x2c]
	ldr r4, .L080571F4 @ =gBanimIdx
	adds r0, r6, #0
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x11
	beq .L080571F8
	cmp r0, #0x11
	bgt .L080571F8
	cmp r0, #0xd
	bgt .L080571F8
	cmp r0, #0xc
	blt .L080571F8
	ldr r0, [r5, #0x5c]
	adds r1, r7, #0
	bl func_fe6_08057224
	b .L08057200
	.align 2, 0
.L080571EC: .4byte gEfxBgSemaphore
.L080571F0: .4byte gUnk_085D361C
.L080571F4: .4byte gBanimIdx
.L080571F8:
	ldr r0, [r5, #0x5c]
	adds r1, r7, #2
	bl func_fe6_08057224
.L08057200:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08057208
func_fe6_08057208: @ 0x08057208
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	bne .L08057220
	adds r0, r1, #0
	bl Proc_Break
.L08057220:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08057224
func_fe6_08057224: @ 0x08057224
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, .L08057258 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805725C @ =gUnk_085D3634
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	cmp r6, #1
	beq .L08057270
	cmp r6, #1
	blo .L08057260
	cmp r6, #2
	beq .L08057280
	cmp r6, #3
	beq .L08057288
	b .L08057292
	.align 2, 0
.L08057258: .4byte gEfxBgSemaphore
.L0805725C: .4byte gUnk_085D3634
.L08057260:
	ldr r0, .L08057268 @ =gUnk_0811AEA0
	str r0, [r5, #0x48]
	ldr r0, .L0805726C @ =gUnk_085D364C
	b .L0805728E
	.align 2, 0
.L08057268: .4byte gUnk_0811AEA0
.L0805726C: .4byte gUnk_085D364C
.L08057270:
	ldr r0, .L08057278 @ =gUnk_0811AEB6
	str r0, [r5, #0x48]
	ldr r0, .L0805727C @ =gUnk_085D364C
	b .L0805728E
	.align 2, 0
.L08057278: .4byte gUnk_0811AEB6
.L0805727C: .4byte gUnk_085D364C
.L08057280:
	ldr r0, .L08057284 @ =gUnk_0811AEBC
	b .L0805728A
	.align 2, 0
.L08057284: .4byte gUnk_0811AEBC
.L08057288:
	ldr r0, .L080572C8 @ =gUnk_0811AEDE
.L0805728A:
	str r0, [r5, #0x48]
	ldr r0, .L080572CC @ =gUnk_085D3664
.L0805728E:
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
.L08057292:
	ldr r0, .L080572D0 @ =gUnk_08129504
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, .L080572D4 @ =gUnk_0812A258
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L080572D8 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080572E6
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L080572DC
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L080572E6
	.align 2, 0
.L080572C8: .4byte gUnk_0811AEDE
.L080572CC: .4byte gUnk_085D3664
.L080572D0: .4byte gUnk_08129504
.L080572D4: .4byte gUnk_0812A258
.L080572D8: .4byte gEkrDistanceType
.L080572DC:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L080572E6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080572EC
func_fe6_080572EC: @ 0x080572EC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L0805731A
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	b .L08057338
.L0805731A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L08057338
	bl SpellFx_ClearBG1
	ldr r1, .L08057340 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_End
.L08057338:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057340: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08057344
func_fe6_08057344: @ 0x08057344
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, .L0805736C @ =gEfxBgSemaphore
	ldr r4, [r0]
	cmp r4, #0
	bne .L08057366
	ldr r0, .L08057370 @ =gUnk_085D36A4
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	strh r4, [r0, #0x2c]
	adds r0, r5, #0
	adds r1, r6, #0
	bl func_fe6_08057380
.L08057366:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805736C: .4byte gEfxBgSemaphore
.L08057370: .4byte gUnk_085D36A4

	thumb_func_start func_fe6_08057374
func_fe6_08057374: @ 0x08057374
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08057380
func_fe6_08057380: @ 0x08057380
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, .L080573E8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080573EC @ =gUnk_085D36BC
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	ldr r2, .L080573F0 @ =gUnk_085E0280
	cmp r4, #0
	beq .L080573AE
	ldr r2, .L080573F4 @ =gUnk_085E0510
	cmp r4, #1
	bne .L080573AE
	ldr r2, .L080573F8 @ =gUnk_085E03C8
.L080573AE:
	ldr r3, .L080573FC @ =gUnk_085E0324
	cmp r4, #0
	beq .L080573BC
	ldr r3, .L08057400 @ =gUnk_085E05B4
	cmp r4, #1
	bne .L080573BC
	ldr r3, .L08057404 @ =gUnk_085E046C
.L080573BC:
	str r2, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r5, #0x60]
	ldr r4, .L08057408 @ =0x0203CDC0
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x32
	bls .L080573DE
	b .L08057510
.L080573DE:
	lsls r0, r0, #2
	ldr r1, .L0805740C @ =.L08057410
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080573E8: .4byte gEfxBgSemaphore
.L080573EC: .4byte gUnk_085D36BC
.L080573F0: .4byte gUnk_085E0280
.L080573F4: .4byte gUnk_085E0510
.L080573F8: .4byte gUnk_085E03C8
.L080573FC: .4byte gUnk_085E0324
.L08057400: .4byte gUnk_085E05B4
.L08057404: .4byte gUnk_085E046C
.L08057408: .4byte 0x0203CDC0
.L0805740C: .4byte .L08057410
.L08057410: @ jump table
	.4byte .L08057510 @ case 0
	.4byte .L080574DC @ case 1
	.4byte .L080574DC @ case 2
	.4byte .L080574DC @ case 3
	.4byte .L080574DC @ case 4
	.4byte .L080574DC @ case 5
	.4byte .L08057508 @ case 6
	.4byte .L08057508 @ case 7
	.4byte .L08057508 @ case 8
	.4byte .L08057508 @ case 9
	.4byte .L080574DC @ case 10
	.4byte .L08057508 @ case 11
	.4byte .L080574DC @ case 12
	.4byte .L080574DC @ case 13
	.4byte .L080574DC @ case 14
	.4byte .L080574DC @ case 15
	.4byte .L080574F8 @ case 16
	.4byte .L080574DC @ case 17
	.4byte .L080574DC @ case 18
	.4byte .L080574DC @ case 19
	.4byte .L080574E4 @ case 20
	.4byte .L080574F8 @ case 21
	.4byte .L080574F8 @ case 22
	.4byte .L08057508 @ case 23
	.4byte .L08057508 @ case 24
	.4byte .L080574DC @ case 25
	.4byte .L080574DC @ case 26
	.4byte .L080574DC @ case 27
	.4byte .L080574DC @ case 28
	.4byte .L08057508 @ case 29
	.4byte .L08057508 @ case 30
	.4byte .L08057508 @ case 31
	.4byte .L08057508 @ case 32
	.4byte .L08057508 @ case 33
	.4byte .L080574DC @ case 34
	.4byte .L080574DC @ case 35
	.4byte .L08057508 @ case 36
	.4byte .L080574DC @ case 37
	.4byte .L080574DC @ case 38
	.4byte .L080574DC @ case 39
	.4byte .L080574DC @ case 40
	.4byte .L080574DC @ case 41
	.4byte .L080574DC @ case 42
	.4byte .L080574DC @ case 43
	.4byte .L08057510 @ case 44
	.4byte .L08057508 @ case 45
	.4byte .L08057510 @ case 46
	.4byte .L080574DC @ case 47
	.4byte .L08057508 @ case 48
	.4byte .L08057508 @ case 49
	.4byte .L08057508 @ case 50
.L080574DC:
	ldr r0, .L080574E0 @ =gUnk_0812C62C
	b .L080574FA
	.align 2, 0
.L080574E0: .4byte gUnk_0812C62C
.L080574E4:
	ldr r0, [r5, #0x5c]
	bl func_fe6_0805C2B0
	cmp r0, #0
	beq .L080574F8
	ldr r0, .L080574F4 @ =gUnk_0812C62C
	b .L080574FA
	.align 2, 0
.L080574F4: .4byte gUnk_0812C62C
.L080574F8:
	ldr r0, .L08057504 @ =gUnk_0812C64C
.L080574FA:
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	b .L08057510
	.align 2, 0
.L08057504: .4byte gUnk_0812C64C
.L08057508:
	ldr r0, .L08057524 @ =gUnk_0812C66C
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
.L08057510:
	ldr r0, .L08057528 @ =gUnk_0812C1BC
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08057524: .4byte gUnk_0812C66C
.L08057528: .4byte gUnk_0812C1BC

	thumb_func_start func_fe6_0805752C
func_fe6_0805752C: @ 0x0805752C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L08057552
	ldr r0, .L08057558 @ =gEfxBgSemaphore
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08057552:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057558: .4byte gEfxBgSemaphore

	thumb_func_start NewEfxKingPika
NewEfxKingPika: @ 0x0805755C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08057574 @ =gUnk_085D36D4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057574: .4byte gUnk_085D36D4

	thumb_func_start func_fe6_08057578
func_fe6_08057578: @ 0x08057578
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, [r7, #0x5c]
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805759A
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x28
	movs r3, #0
	bl NewEfxFlashUnit
	b .L080575DE
.L0805759A:
	cmp r0, #0xa
	bne .L080575A8
	adds r0, r6, #0
	movs r1, #0x14
	bl NewEfxFlashBgWhite
	b .L080575DE
.L080575A8:
	cmp r0, #0x2d
	bne .L080575DE
	ldr r5, .L080575E4 @ =gAnims
	adds r0, r6, #0
	bl GetAnimPosition
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r4, [r0]
	adds r0, r6, #0
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r2, [r0]
	movs r0, #0x40
	ldrh r1, [r4, #0x10]
	orrs r1, r0
	strh r1, [r4, #0x10]
	ldrh r1, [r2, #0x10]
	orrs r0, r1
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	bl Proc_Break
.L080575DE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080575E4: .4byte gAnims

	thumb_func_start NewEfxFlashFX
NewEfxFlashFX: @ 0x080575E8
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08057648 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805764C @ =gUnk_085D36EC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x28
	strh r0, [r4, #0x2e]
	ldr r3, .L08057650 @ =gUnk_085D55C0
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L08057654 @ =gUnk_0811CAD8
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08057658 @ =gUnk_0811C964
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xee
	movs r3, #1
	bl func_fe6_0805C804
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057648: .4byte gEfxBgSemaphore
.L0805764C: .4byte gUnk_085D36EC
.L08057650: .4byte gUnk_085D55C0
.L08057654: .4byte gUnk_0811CAD8
.L08057658: .4byte gUnk_0811C964

	thumb_func_start func_fe6_0805765C
func_fe6_0805765C: @ 0x0805765C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x18
	bne .L08057680
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xee
	movs r3, #1
	bl func_fe6_0805C804
.L08057680:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble .L080576A0
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L080576A8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080576A0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080576A8: .4byte gEfxBgSemaphore

	thumb_func_start NewEfxSongOBJ2
NewEfxSongOBJ2: @ 0x080576AC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0805770C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08057710 @ =gUnk_085D3704
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x19
	strh r0, [r4, #0x2e]
	ldr r3, .L08057714 @ =gUnk_085D5590
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L08057718 @ =gUnk_0811CAD8
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805771C @ =gUnk_0811C964
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xe1
	movs r3, #1
	bl func_fe6_0805C804
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805770C: .4byte gEfxBgSemaphore
.L08057710: .4byte gUnk_085D3704
.L08057714: .4byte gUnk_085D5590
.L08057718: .4byte gUnk_0811CAD8
.L0805771C: .4byte gUnk_0811C964

	thumb_func_start func_fe6_08057720
func_fe6_08057720: @ 0x08057720
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08057748
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L08057750 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08057748:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057750: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08057754
func_fe6_08057754: @ 0x08057754
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	bl GetEkrDragonStateType
	adds r4, r0, #0
	cmp r4, #0
	bne .L0805778E
	ldr r1, .L08057794 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08057798 @ =gUnk_085D371C
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r2, #0
	strh r4, [r0, #0x2c]
	strh r6, [r0, #0x2e]
	strh r7, [r0, #0x30]
	ldr r1, .L0805779C @ =gDispIo
	movs r0, #0x40
	ldrb r3, [r1, #0x18]
	orrs r0, r3
	strb r0, [r1, #0x18]
	adds r1, #0x38
	strb r2, [r1]
.L0805778E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08057794: .4byte gEfxBgSemaphore
.L08057798: .4byte gUnk_085D371C
.L0805779C: .4byte gDispIo

	thumb_func_start func_fe6_080577A0
func_fe6_080577A0: @ 0x080577A0
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x30
	ldrsh r2, [r4, r0]
	movs r1, #0x2c
	ldrsh r3, [r4, r1]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	ldr r2, .L080577F0 @ =gDispIo
	adds r2, #0x38
	movs r3, #0xf
	adds r1, r0, #0
	ands r1, r3
	lsls r0, r0, #4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L080577E6
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L080577E6:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080577F0: .4byte gDispIo

	thumb_func_start func_fe6_080577F4
func_fe6_080577F4: @ 0x080577F4
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0
	bl Interpolate
	ldr r3, .L08057858 @ =gDispIo
	adds r5, r3, #0
	adds r5, #0x38
	movs r2, #0xf
	adds r1, r0, #0
	ands r1, r2
	lsls r0, r0, #4
	orrs r0, r1
	strb r0, [r5]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805784E
	ldr r1, .L0805785C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	movs r0, #0x41
	rsbs r0, r0, #0
	ldrb r1, [r3, #0x18]
	ands r0, r1
	strb r0, [r3, #0x18]
	movs r0, #0
	strb r0, [r5]
	adds r0, r4, #0
	bl Proc_Break
.L0805784E:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057858: .4byte gDispIo
.L0805785C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08057860
func_fe6_08057860: @ 0x08057860
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, .L08057894 @ =gUnk_Banim_02017760
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080578BC
	adds r0, r5, #0
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #1
	strh r1, [r0]
	adds r0, r5, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0805789C
	ldr r0, .L08057898 @ =gpEkrBattleUnitLeft
	b .L0805789E
	.align 2, 0
.L08057894: .4byte gUnk_Banim_02017760
.L08057898: .4byte gpEkrBattleUnitLeft
.L0805789C:
	ldr r0, .L080578EC @ =gpEkrBattleUnitRight
.L0805789E:
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x4a
	ldrh r0, [r4]
	bl GetItemKind
	ldrh r0, [r4]
	bl GetItemRequiredExp
	movs r1, #0
	cmp r0, #0xfb
	bne .L080578B8
	movs r1, #1
.L080578B8:
	cmp r1, #0
	bne .L080578F4
.L080578BC:
	ldr r4, .L080578F0 @ =gAnims
	adds r0, r5, #0
	bl GetAnimPosition
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r6, [r0]
	adds r0, r5, #0
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r2, [r0]
	movs r1, #0x40
	ldrh r0, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	ldrh r0, [r2, #0x10]
	orrs r0, r1
	strh r0, [r2, #0x10]
	b .L08057916
	.align 2, 0
.L080578EC: .4byte gpEkrBattleUnitRight
.L080578F0: .4byte gAnims
.L080578F4:
	ldr r0, .L0805791C @ =gUnk_085D373C
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xf0
	movs r2, #0x78
	movs r3, #0
	bl func_fe6_0805C804
	adds r0, r5, #0
	bl func_fe6_0805792C
.L08057916:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805791C: .4byte gUnk_085D373C

	thumb_func_start func_fe6_08057920
func_fe6_08057920: @ 0x08057920
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805792C
func_fe6_0805792C: @ 0x0805792C
	push {r4, lr}
	adds r4, r0, #0
	bl SpellFx_SetBG1Position
	ldr r0, .L08057948 @ =gUnk_085D3754
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057948: .4byte gUnk_085D3754

	thumb_func_start func_fe6_0805794C
func_fe6_0805794C: @ 0x0805794C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08057966
	ldr r0, [r6, #0x5c]
	bl func_fe6_080579C0
	b .L080579B6
.L08057966:
	cmp r0, #0x15
	bne .L08057980
	ldr r0, [r6, #0x5c]
	ldr r2, .L0805797C @ =func_fe6_08057A34
	movs r1, #0x2d
	bl func_fe6_0804CC68
	bl func_fe6_08057A5C
	b .L080579B6
	.align 2, 0
.L0805797C: .4byte func_fe6_08057A34
.L08057980:
	cmp r0, #0x46
	bne .L080579B6
	ldr r5, .L080579BC @ =gAnims
	ldr r0, [r6, #0x5c]
	bl GetAnimPosition
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r4, [r0]
	ldr r0, [r6, #0x5c]
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r2, [r0]
	movs r0, #0x40
	ldrh r1, [r4, #0x10]
	orrs r1, r0
	strh r1, [r4, #0x10]
	ldrh r1, [r2, #0x10]
	orrs r0, r1
	strh r0, [r2, #0x10]
	adds r0, r6, #0
	bl Proc_Break
.L080579B6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080579BC: .4byte gAnims

	thumb_func_start func_fe6_080579C0
func_fe6_080579C0: @ 0x080579C0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L080579FC @ =gUnk_085D376C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, .L08057A00 @ =gUnk_08124618
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, .L08057A04 @ =gUnk_081246D8
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, [r4, #0x5c]
	ldr r2, .L08057A08 @ =gUnk_081246F8
	adds r1, r2, #0
	bl SpellFx_WriteBgMap
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080579FC: .4byte gUnk_085D376C
.L08057A00: .4byte gUnk_08124618
.L08057A04: .4byte gUnk_081246D8
.L08057A08: .4byte gUnk_081246F8

	thumb_func_start func_fe6_08057A0C
func_fe6_08057A0C: @ 0x08057A0C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3c
	bne .L08057A2C
	bl SpellFx_ClearBG1
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L08057A2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08057A34
func_fe6_08057A34: @ 0x08057A34
	ldr r0, .L08057A50 @ =0x04000004
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08057A4E
	ldr r3, .L08057A54 @ =0x04000016
	ldr r2, .L08057A58 @ =gUnk_Banim_0201E3E0
	ldr r0, [r2]
	ldrh r1, [r0]
	strh r1, [r3]
	adds r0, #2
	str r0, [r2]
.L08057A4E:
	bx lr
	.align 2, 0
.L08057A50: .4byte 0x04000004
.L08057A54: .4byte 0x04000016
.L08057A58: .4byte gUnk_Banim_0201E3E0

	thumb_func_start func_fe6_08057A5C
func_fe6_08057A5C: @ 0x08057A5C
	push {lr}
	ldr r0, .L08057A78 @ =gUnk_085D3784
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r1, [r0, #0x44]
	bl func_fe6_08057B2C
	pop {r0}
	bx r0
	.align 2, 0
.L08057A78: .4byte gUnk_085D3784

	thumb_func_start func_fe6_08057A7C
func_fe6_08057A7C: @ 0x08057A7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	ldr r0, .L08057AD8 @ =gUnk_Banim_0201E3D8
	ldr r0, [r0]
	ldr r5, .L08057ADC @ =gUnk_Banim_0201E158
	cmp r0, #0
	bne .L08057A92
	ldr r5, .L08057AE0 @ =gUnk_Banim_0201E298
.L08057A92:
	ldr r4, .L08057AE4 @ =gUnk_Banim_0201E3E4
	cmp r0, #0
	bne .L08057A9A
	ldr r4, .L08057AE8 @ =gUnk_Banim_0201E524
.L08057A9A:
	movs r3, #0
	movs r0, #0
	mov r8, r0
	movs r1, #0x88
	lsls r1, r1, #0x10
	mov ip, r1
	movs r7, #0x88
	ldr r6, .L08057AEC @ =gUnk_085D37B4
.L08057AAA:
	cmp r3, #0x77
	bhi .L08057B04
	movs r2, #0
	ldrsh r1, [r6, r2]
	mov r2, sb
	ldr r0, [r2, #0x44]
	muls r0, r1, r0
	lsls r0, r0, #4
	lsrs r2, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	beq .L08057AFC
	cmp r3, #0x3b
	bhi .L08057AF4
	adds r0, r3, #0
	subs r0, #0x88
	cmp r1, r0
	bhs .L08057AFC
	ldr r1, .L08057AF0 @ =0x0000FF78
	adds r0, r3, r1
	lsls r0, r0, #0x10
	b .L08057AFA
	.align 2, 0
.L08057AD8: .4byte gUnk_Banim_0201E3D8
.L08057ADC: .4byte gUnk_Banim_0201E158
.L08057AE0: .4byte gUnk_Banim_0201E298
.L08057AE4: .4byte gUnk_Banim_0201E3E4
.L08057AE8: .4byte gUnk_Banim_0201E524
.L08057AEC: .4byte gUnk_085D37B4
.L08057AF0: .4byte 0x0000FF78
.L08057AF4:
	cmp r1, r7
	bls .L08057AFC
	mov r0, ip
.L08057AFA:
	lsrs r2, r0, #0x10
.L08057AFC:
	strh r2, [r5]
	adds r5, #2
	strh r2, [r4]
	b .L08057B0C
.L08057B04:
	mov r1, r8
	strh r1, [r5]
	adds r5, #2
	strh r1, [r4]
.L08057B0C:
	adds r4, #2
	ldr r2, .L08057B28 @ =0xFFFF0000
	add ip, r2
	subs r7, #1
	adds r6, #2
	adds r3, #1
	cmp r3, #0x9f
	bls .L08057AAA
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08057B28: .4byte 0xFFFF0000

	thumb_func_start func_fe6_08057B2C
func_fe6_08057B2C: @ 0x08057B2C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08057B48 @ =gUnk_085D379C
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	movs r1, #0x28
	strh r1, [r0, #0x2e]
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057B48: .4byte gUnk_085D379C

	thumb_func_start func_fe6_08057B4C
func_fe6_08057B4C: @ 0x08057B4C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, [r4, #0x5c]
	movs r2, #0x80
	lsls r2, r2, #0xb
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	str r0, [r5, #0x44]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08057B88
	adds r0, r5, #0
	bl Proc_End
	adds r0, r4, #0
	bl Proc_Break
.L08057B88:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08057B90
func_fe6_08057B90: @ 0x08057B90
	push {r4, lr}
	adds r4, r0, #0
	bl SpellFx_SetBG1Position
	ldr r0, .L08057BAC @ =gUnk_085D38A4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057BAC: .4byte gUnk_085D38A4

	thumb_func_start func_fe6_08057BB0
func_fe6_08057BB0: @ 0x08057BB0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	bne .L08057BE6
	ldr r0, [r5, #0x5c]
	movs r1, #0x49
	bl func_fe6_08057BF8
	movs r4, #0xa0
	lsls r4, r4, #1
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, #0
	bl EfxPlaySE
	ldr r0, [r5, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	movs r2, #1
	bl M4aPlayWithPostionCtrl
.L08057BE6:
	ldrh r0, [r5, #0x2c]
	cmp r0, #0x64
	bne .L08057BF2
	adds r0, r5, #0
	bl Proc_Break
.L08057BF2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08057BF8
func_fe6_08057BF8: @ 0x08057BF8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08057C78 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08057C7C @ =gUnk_085D38BC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r1, [r0, #0x44]
	ldr r1, .L08057C80 @ =gUnk_0811AF00
	str r1, [r0, #0x48]
	ldr r1, .L08057C84 @ =gUnk_085D38D4
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r0, .L08057C88 @ =gUnk_0812BE10
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08057C8C @ =gUnk_0812B19C
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	bl SpellFx_SetSomeColorEffect
	ldr r3, .L08057C90 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x14]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x14]
	ldrb r0, [r3, #0x10]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x10]
	movs r0, #3
	ldrb r1, [r3, #0x18]
	orrs r0, r1
	strb r0, [r3, #0x18]
	movs r0, #1
	movs r1, #0x10
	movs r2, #0
	bl SetBgOffset
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057C78: .4byte gEfxBgSemaphore
.L08057C7C: .4byte gUnk_085D38BC
.L08057C80: .4byte gUnk_0811AF00
.L08057C84: .4byte gUnk_085D38D4
.L08057C88: .4byte gUnk_0812BE10
.L08057C8C: .4byte gUnk_0812B19C
.L08057C90: .4byte gDispIo

	thumb_func_start func_fe6_08057C94
func_fe6_08057C94: @ 0x08057C94
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L08057CC0
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
.L08057CC0:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08057D12
	ldr r3, .L08057D18 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x18]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x18]
	movs r0, #3
	ldrb r1, [r3, #0x14]
	orrs r0, r1
	strb r0, [r3, #0x14]
	bl SpellFx_ClearBG1
	ldr r1, .L08057D1C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L08057D12:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057D18: .4byte gDispIo
.L08057D1C: .4byte gEfxBgSemaphore

	thumb_func_start NewEfxMantBatabata
NewEfxMantBatabata: @ 0x08057D20
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	bl GetAnimPosition
	ldr r1, .L08057D4C @ =gBanimIdx
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #0xc
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x29
	bhi .L08057E1C
	lsls r0, r0, #2
	ldr r1, .L08057D50 @ =.L08057D54
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08057D4C: .4byte gBanimIdx
.L08057D50: .4byte .L08057D54
.L08057D54: @ jump table
	.4byte .L08057DFC @ case 0
	.4byte .L08057DFC @ case 1
	.4byte .L08057E1C @ case 2
	.4byte .L08057E1C @ case 3
	.4byte .L08057E1C @ case 4
	.4byte .L08057E0C @ case 5
	.4byte .L08057E1C @ case 6
	.4byte .L08057E1C @ case 7
	.4byte .L08057E1C @ case 8
	.4byte .L08057E1C @ case 9
	.4byte .L08057E1C @ case 10
	.4byte .L08057E1C @ case 11
	.4byte .L08057E1C @ case 12
	.4byte .L08057E1C @ case 13
	.4byte .L08057E1C @ case 14
	.4byte .L08057E1C @ case 15
	.4byte .L08057E1C @ case 16
	.4byte .L08057E1C @ case 17
	.4byte .L08057E1C @ case 18
	.4byte .L08057E1C @ case 19
	.4byte .L08057E1C @ case 20
	.4byte .L08057E1C @ case 21
	.4byte .L08057E1C @ case 22
	.4byte .L08057E1C @ case 23
	.4byte .L08057E1C @ case 24
	.4byte .L08057E1C @ case 25
	.4byte .L08057E1C @ case 26
	.4byte .L08057E1C @ case 27
	.4byte .L08057E1C @ case 28
	.4byte .L08057E1C @ case 29
	.4byte .L08057E1C @ case 30
	.4byte .L08057E1C @ case 31
	.4byte .L08057E1C @ case 32
	.4byte .L08057E1C @ case 33
	.4byte .L08057E1C @ case 34
	.4byte .L08057E1C @ case 35
	.4byte .L08057E1C @ case 36
	.4byte .L08057E1C @ case 37
	.4byte .L08057E1C @ case 38
	.4byte .L08057E1C @ case 39
	.4byte .L08057E1C @ case 40
	.4byte .L08057E0C @ case 41
.L08057DFC:
	ldr r6, .L08057E04 @ =gUnk_085E0748
	ldr r4, .L08057E08 @ =gUnk_085E08DC
	b .L08057E20
	.align 2, 0
.L08057E04: .4byte gUnk_085E0748
.L08057E08: .4byte gUnk_085E08DC
.L08057E0C:
	ldr r6, .L08057E14 @ =gUnk_085E0A88
	ldr r4, .L08057E18 @ =gUnk_085E0C34
	b .L08057E20
	.align 2, 0
.L08057E14: .4byte gUnk_085E0A88
.L08057E18: .4byte gUnk_085E0C34
.L08057E1C:
	ldr r6, .L08057E68 @ =gUnk_085E0DE0
	ldr r4, .L08057E6C @ =gUnk_085E0F88
.L08057E20:
	ldr r0, .L08057E70 @ =gUnk_085D38E4
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x5c]
	movs r0, #0
	mov r8, r0
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r6, [sp]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	adds r3, r4, #0
	bl EfxCreateFrontAnim
	adds r4, r0, #0
	str r4, [r5, #0x60]
	movs r0, #0xc0
	lsls r0, r0, #4
	ldrh r1, [r4, #8]
	ands r0, r1
	strh r0, [r4, #8]
	movs r0, #0x64
	strh r0, [r4, #0xa]
	bl BasSort
	adds r0, r7, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08057E74
	movs r1, #0xe4
	lsls r1, r1, #7
	b .L08057E78
	.align 2, 0
.L08057E68: .4byte gUnk_085E0DE0
.L08057E6C: .4byte gUnk_085E0F88
.L08057E70: .4byte gUnk_085D38E4
.L08057E74:
	movs r1, #0x93
	lsls r1, r1, #8
.L08057E78:
	adds r0, r1, #0
	ldrh r1, [r4, #8]
	orrs r0, r1
	strh r0, [r4, #8]
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	bl SetAnimStateHidden
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08057E98
func_fe6_08057E98: @ 0x08057E98
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x60]
	ldr r0, [r2, #0x5c]
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	ldr r0, [r2, #0x5c]
	ldrh r1, [r0, #0x10]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L08057EBE
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L08057EBE
	adds r0, r2, #0
	bl Proc_Break
.L08057EBE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08057EC4
func_fe6_08057EC4: @ 0x08057EC4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x5c]
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	bl CheckEkrHitDone
	cmp r0, #1
	bne .L08057EEE
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	bl SetAnimStateUnHidden
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08057EEE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08057EF4
func_fe6_08057EF4: @ 0x08057EF4
	ldr r0, .L08057F00 @ =0x0203CDD8
	movs r1, #0
	str r1, [r0]
	ldr r0, .L08057F04 @ =0x0203CDDC
	str r1, [r0]
	bx lr
	.align 2, 0
.L08057F00: .4byte 0x0203CDD8
.L08057F04: .4byte 0x0203CDDC

	thumb_func_start func_fe6_08057F08
func_fe6_08057F08: @ 0x08057F08
	push {r4, lr}
	ldr r4, .L08057F20 @ =0x0203CDD8
	ldr r0, [r4]
	cmp r0, #0
	beq .L08057F1A
	bl Proc_End
	movs r0, #0
	str r0, [r4]
.L08057F1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057F20: .4byte 0x0203CDD8

	thumb_func_start func_fe6_08057F24
func_fe6_08057F24: @ 0x08057F24
	push {r4, lr}
	ldr r4, .L08057F3C @ =0x0203CDDC
	ldr r0, [r4]
	cmp r0, #0
	beq .L08057F36
	bl Proc_End
	movs r0, #0
	str r0, [r4]
.L08057F36:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057F3C: .4byte 0x0203CDDC

	thumb_func_start func_fe6_08057F40
func_fe6_08057F40: @ 0x08057F40
	ldr r1, .L08057F48 @ =0x0203CDD8
	str r0, [r1]
	bx lr
	.align 2, 0
.L08057F48: .4byte 0x0203CDD8

	thumb_func_start func_fe6_08057F4C
func_fe6_08057F4C: @ 0x08057F4C
	ldr r1, .L08057F54 @ =0x0203CDDC
	str r0, [r1]
	bx lr
	.align 2, 0
.L08057F54: .4byte 0x0203CDDC

	thumb_func_start func_fe6_08057F58
func_fe6_08057F58: @ 0x08057F58
	ldr r0, [r0, #0x44]
	ldr r0, [r0, #0x2c]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08057F60
func_fe6_08057F60: @ 0x08057F60
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08057F7C
	ldr r0, .L08057F78 @ =gUnk_081122C5
	ldrh r1, [r4, #2]
	ldrb r0, [r0]
	subs r0, r1, r0
	b .L08057F84
	.align 2, 0
.L08057F78: .4byte gUnk_081122C5
.L08057F7C:
	ldr r0, .L08057FB4 @ =gUnk_081122CA
	ldrb r0, [r0]
	ldrh r3, [r4, #2]
	subs r0, r0, r3
.L08057F84:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0x58
	ldrh r4, [r4, #4]
	subs r2, r2, r4
	ldrh r0, [r5, #0x12]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r3, [r5, #2]
	subs r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r5, [r5, #4]
	subs r2, r2, r5
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl SetBgOffset
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057FB4: .4byte gUnk_081122CA

	thumb_func_start func_fe6_08057FB8
func_fe6_08057FB8: @ 0x08057FB8
	push {r4, lr}
	sub sp, #4
	bl func_fe6_08057F58
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r1, [r4, #0x14]
	ldr r2, .L08057FE4 @ =0x01000200
	mov r0, sp
	bl CpuFastSet
	movs r0, #1
	ldrh r4, [r4, #0x12]
	lsls r0, r4
	bl EnableBgSync
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057FE4: .4byte 0x01000200

	thumb_func_start func_fe6_08057FE8
func_fe6_08057FE8: @ 0x08057FE8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	adds r6, r3, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl func_fe6_08057F58
	mov r8, r0
	cmp r4, #0
	bne .L08058008
	adds r0, r7, #0
	b .L0805800A
.L08058008:
	adds r0, r6, #0
.L0805800A:
	movs r1, #0x78
	bl BasCreate
	adds r2, r0, #0
	mov r1, r8
	ldrh r1, [r1, #0x10]
	lsls r0, r1, #0xc
	mov r3, r8
	ldrh r3, [r3, #0xe]
	orrs r0, r3
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #8]
	ldrh r0, [r5, #2]
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	strh r0, [r2, #4]
	adds r0, r2, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0805803C
func_fe6_0805803C: @ 0x0805803C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r2, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r5, r3, #0
	bl func_fe6_08057F58
	adds r4, r0, #0
	cmp r5, #1
	bne .L0805805E
	ldr r1, [r4, #0x1c]
	adds r0, r6, #0
	bl LZ77UnCompWram
.L0805805E:
	adds r2, r6, #0
	cmp r5, #1
	bne .L08058066
	ldr r2, [r4, #0x1c]
.L08058066:
	cmp r7, #0
	bne .L08058080
	ldr r1, [r4, #0x14]
	ldrh r0, [r4, #0xc]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl EfxTmCpyBgHFlip
	b .L08058094
.L08058080:
	ldr r1, [r4, #0x14]
	ldrh r0, [r4, #0xc]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl EfxTmCpyBG
.L08058094:
	movs r0, #1
	ldrh r4, [r4, #0x12]
	lsls r0, r4
	bl EnableBgSync
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080580A8
func_fe6_080580A8: @ 0x080580A8
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	bl func_fe6_08057F58
	adds r4, r0, #0
	ldrh r0, [r4, #0xa]
	lsls r5, r0, #5
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r5, r5, r0
	ldr r1, [r4, #0x18]
	adds r0, r6, #0
	bl LZ77UnCompWram
	ldr r0, [r4, #0x18]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r5, #0
	bl RegisterDataMove
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080580D8
func_fe6_080580D8: @ 0x080580D8
	push {r4, lr}
	adds r4, r1, #0
	bl func_fe6_08057F58
	ldrh r0, [r0, #0xc]
	lsls r1, r0, #5
	ldr r0, .L080580FC @ =gPal
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080580FC: .4byte gPal

	thumb_func_start func_fe6_08058100
func_fe6_08058100: @ 0x08058100
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	bl func_fe6_08057F58
	adds r4, r0, #0
	ldrh r0, [r4, #0xe]
	lsls r5, r0, #5
	ldr r0, .L0805812C @ =0x06010000
	adds r5, r5, r0
	ldr r1, [r4, #0x20]
	adds r0, r6, #0
	bl LZ77UnCompWram
	ldr r0, [r4, #0x20]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r5, #0
	bl RegisterDataMove
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805812C: .4byte 0x06010000

	thumb_func_start func_fe6_08058130
func_fe6_08058130: @ 0x08058130
	push {r4, lr}
	adds r4, r1, #0
	bl func_fe6_08057F58
	ldrh r0, [r0, #0x10]
	lsls r1, r0, #5
	ldr r0, .L08058154 @ =gPal+0x200
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08058154: .4byte gPal+0x200

	thumb_func_start func_fe6_08058158
func_fe6_08058158: @ 0x08058158
	push {r4, lr}
	adds r4, r0, #0
	bl func_fe6_08057F58
	ldr r1, .L08058178 @ =gUnk_085D3904
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08058178: .4byte gUnk_085D3904

	thumb_func_start func_fe6_0805817C
func_fe6_0805817C: @ 0x0805817C
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08058180
func_fe6_08058180: @ 0x08058180
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L0805819C @ =gUnk_085D3924
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	bl func_fe6_08057F40
	str r4, [r5, #0x5c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805819C: .4byte gUnk_085D3924

	thumb_func_start func_fe6_080581A0
func_fe6_080581A0: @ 0x080581A0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl func_fe6_080581C0
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl func_fe6_0805826C
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080581C0
func_fe6_080581C0: @ 0x080581C0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl func_fe6_08057F58
	adds r6, r0, #0
	ldr r0, .L0805820C @ =gUnk_085D394C
	adds r1, r4, #0
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L08058210 @ =gUnk_0811AF20
	str r0, [r4, #0x48]
	ldr r0, .L08058214 @ =gUnk_085D3964
	str r0, [r4, #0x4c]
	ldr r1, .L08058218 @ =gUnk_0812E4A4
	adds r0, r5, #0
	bl func_fe6_080580D8
	ldr r0, [r4, #0x5c]
	ldr r1, .L0805821C @ =gUnk_0812D8AC
	bl func_fe6_080580A8
	ldr r0, [r6, #0x24]
	bl _call_via_r0
	ldr r0, [r4, #0x5c]
	adds r1, r6, #0
	bl func_fe6_08057F60
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805820C: .4byte gUnk_085D394C
.L08058210: .4byte gUnk_0811AF20
.L08058214: .4byte gUnk_085D3964
.L08058218: .4byte gUnk_0812E4A4
.L0805821C: .4byte gUnk_0812D8AC

	thumb_func_start func_fe6_08058220
func_fe6_08058220: @ 0x08058220
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0805824C
	ldr r2, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #1
	movs r3, #1
	bl func_fe6_0805803C
	b .L08058264
.L0805824C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08058264
	ldr r0, [r4, #0x5c]
	bl func_fe6_08057FB8
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L08058264:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805826C
func_fe6_0805826C: @ 0x0805826C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl func_fe6_08057F58
	adds r7, r0, #0
	ldr r0, .L080582A8 @ =gUnk_085D3994
	adds r1, r4, #0
	bl SpawnProc
	adds r6, r0, #0
	str r5, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	ldr r2, .L080582AC @ =gUnk_085E2CA8
	ldr r3, .L080582B0 @ =gUnk_085E2920
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_08057FE8
	adds r4, r0, #0
	str r4, [r6, #0x60]
	adds r0, r5, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L080582B4
	ldrh r0, [r5, #2]
	subs r0, #8
	b .L080582B8
	.align 2, 0
.L080582A8: .4byte gUnk_085D3994
.L080582AC: .4byte gUnk_085E2CA8
.L080582B0: .4byte gUnk_085E2920
.L080582B4:
	ldrh r0, [r5, #2]
	adds r0, #8
.L080582B8:
	strh r0, [r4, #2]
	ldrh r0, [r5, #4]
	adds r0, #8
	strh r0, [r4, #4]
	ldrh r2, [r4, #2]
	ldrh r3, [r7, #6]
	adds r1, r2, r3
	strh r1, [r4, #2]
	ldrh r7, [r7, #8]
	adds r0, r7, r0
	strh r0, [r4, #4]
	ldr r0, [r6, #0x5c]
	ldr r1, .L080582E4 @ =gUnk_0812FFD8
	bl func_fe6_08058130
	ldr r0, [r6, #0x5c]
	ldr r1, .L080582E8 @ =gUnk_0812F9DC
	bl func_fe6_08058100
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080582E4: .4byte gUnk_0812FFD8
.L080582E8: .4byte gUnk_0812F9DC

	thumb_func_start func_fe6_080582EC
func_fe6_080582EC: @ 0x080582EC
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble .L0805830A
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805830A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08058310
func_fe6_08058310: @ 0x08058310
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L0805832C @ =gUnk_085D39AC
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	bl func_fe6_08057F40
	str r4, [r5, #0x5c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805832C: .4byte gUnk_085D39AC

	thumb_func_start func_fe6_08058330
func_fe6_08058330: @ 0x08058330
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl func_fe6_08058358
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl func_fe6_08058438
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl func_fe6_080584AC
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08058358
func_fe6_08058358: @ 0x08058358
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl func_fe6_08057F58
	adds r6, r0, #0
	ldr r0, .L080583A0 @ =gUnk_085D39D4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L080583A4 @ =gUnk_0811AF52
	str r0, [r4, #0x48]
	ldr r0, .L080583A8 @ =gUnk_085D39EC
	str r0, [r4, #0x4c]
	ldr r1, .L080583AC @ =gUnk_0812CF48
	adds r0, r5, #0
	bl func_fe6_080580D8
	ldr r0, [r4, #0x5c]
	ldr r1, .L080583B0 @ =gUnk_0812C68C
	bl func_fe6_080580A8
	ldr r0, [r6, #0x24]
	bl _call_via_r0
	ldr r0, [r4, #0x5c]
	adds r1, r6, #0
	bl func_fe6_08057F60
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080583A0: .4byte gUnk_085D39D4
.L080583A4: .4byte gUnk_0811AF52
.L080583A8: .4byte gUnk_085D39EC
.L080583AC: .4byte gUnk_0812CF48
.L080583B0: .4byte gUnk_0812C68C

	thumb_func_start func_fe6_080583B4
func_fe6_080583B4: @ 0x080583B4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r7, #0
	ldr r0, [r4, #0x5c]
	bl func_fe6_08057F58
	adds r6, r0, #0
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L08058416
	ldr r2, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r1, r5, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #0
	movs r3, #1
	bl func_fe6_0805803C
	cmp r5, #0
	bne .L080583F8
	ldrh r0, [r6, #0xa]
	adds r0, #0x1f
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L080583F8:
	cmp r5, #1
	bne .L08058404
	ldrh r0, [r6, #0xa]
	adds r0, #0x50
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08058404:
	ldr r0, [r6, #0x14]
	adds r0, #0x3c
	ldrh r3, [r6, #0xc]
	str r7, [sp]
	movs r1, #2
	movs r2, #0x14
	bl FillBGRect
	b .L0805842E
.L08058416:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0805842E
	ldr r0, [r4, #0x5c]
	bl func_fe6_08057FB8
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L0805842E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08058438
func_fe6_08058438: @ 0x08058438
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08058460 @ =gUnk_085D39F4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	bl func_fe6_08057F4C
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L08058464 @ =gUnk_0811AF5C
	str r0, [r4, #0x48]
	ldr r0, .L08058468 @ =gUnk_0812CF48
	str r0, [r4, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08058460: .4byte gUnk_085D39F4
.L08058464: .4byte gUnk_0811AF5C
.L08058468: .4byte gUnk_0812CF48

	thumb_func_start func_fe6_0805846C
func_fe6_0805846C: @ 0x0805846C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L08058492
	ldr r1, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #5
	adds r1, r1, r2
	bl func_fe6_080580D8
	b .L080584A4
.L08058492:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L080584A4
	bl func_fe6_08057F24
	adds r0, r4, #0
	bl Proc_Break
.L080584A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080584AC
func_fe6_080584AC: @ 0x080584AC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl func_fe6_08057F58
	adds r7, r0, #0
	ldr r0, .L080584E8 @ =gUnk_085D3A14
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r5, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	ldr r2, .L080584EC @ =gUnk_085E2508
	ldr r3, .L080584F0 @ =gUnk_085E19DC
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_08057FE8
	adds r4, r0, #0
	str r4, [r6, #0x60]
	adds r0, r5, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L080584F4
	ldrh r0, [r5, #2]
	adds r0, #0x38
	b .L080584F8
	.align 2, 0
.L080584E8: .4byte gUnk_085D3A14
.L080584EC: .4byte gUnk_085E2508
.L080584F0: .4byte gUnk_085E19DC
.L080584F4:
	ldrh r0, [r5, #2]
	subs r0, #0x38
.L080584F8:
	strh r0, [r4, #2]
	ldrh r1, [r4, #2]
	ldrh r2, [r7, #6]
	adds r0, r1, r2
	strh r0, [r4, #2]
	ldrh r1, [r4, #4]
	ldrh r7, [r7, #8]
	adds r0, r1, r7
	strh r0, [r4, #4]
	ldr r0, [r6, #0x5c]
	ldr r1, .L08058520 @ =gUnk_0812D80C
	bl func_fe6_08058130
	ldr r0, [r6, #0x5c]
	ldr r1, .L08058524 @ =gUnk_0812D374
	bl func_fe6_08058100
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08058520: .4byte gUnk_0812D80C
.L08058524: .4byte gUnk_0812D374

	thumb_func_start func_fe6_08058528
func_fe6_08058528: @ 0x08058528
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble .L08058546
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08058546:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805854C
func_fe6_0805854C: @ 0x0805854C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08058564 @ =gUnk_085D3A2C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08058564: .4byte gUnk_085D3A2C

	thumb_func_start func_fe6_08058568
func_fe6_08058568: @ 0x08058568
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl func_fe6_080587C0
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl func_fe6_080585DC
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl func_fe6_0805867C
	ldr r3, .L080585D8 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	movs r1, #0
	strb r1, [r0]
	adds r2, #9
	movs r0, #0x10
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x46
	strb r1, [r0]
	ldr r0, [r4, #0x5c]
	str r4, [sp]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl func_fe6_080586F0
	ldr r0, [r4, #0x5c]
	str r4, [sp]
	movs r1, #0x23
	movs r2, #0x19
	movs r3, #1
	bl func_fe6_080586F0
	adds r0, r4, #0
	bl Proc_Break
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080585D8: .4byte gDispIo

	thumb_func_start func_fe6_080585DC
func_fe6_080585DC: @ 0x080585DC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl func_fe6_08057F58
	adds r6, r0, #0
	ldr r0, .L08058620 @ =gUnk_085D3A54
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	bl func_fe6_08057F40
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L08058624 @ =gUnk_0811AF9E
	str r0, [r4, #0x48]
	ldr r0, .L08058628 @ =gUnk_085D3A6C
	str r0, [r4, #0x4c]
	ldr r1, .L0805862C @ =gUnk_081AB1B0
	adds r0, r5, #0
	bl func_fe6_080580A8
	ldr r0, [r6, #0x24]
	bl _call_via_r0
	ldr r0, [r4, #0x5c]
	adds r1, r6, #0
	bl func_fe6_08057F60
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08058620: .4byte gUnk_085D3A54
.L08058624: .4byte gUnk_0811AF9E
.L08058628: .4byte gUnk_085D3A6C
.L0805862C: .4byte gUnk_081AB1B0

	thumb_func_start func_fe6_08058630
func_fe6_08058630: @ 0x08058630
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0805865C
	ldr r2, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #1
	movs r3, #0
	bl func_fe6_0805803C
	b .L08058674
.L0805865C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08058674
	ldr r0, [r4, #0x5c]
	bl func_fe6_08057FB8
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L08058674:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805867C
func_fe6_0805867C: @ 0x0805867C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L080586A4 @ =gUnk_085D3A70
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	bl func_fe6_08057F4C
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L080586A8 @ =gUnk_0811AFA4
	str r0, [r4, #0x48]
	ldr r0, .L080586AC @ =gUnk_081ABCA0
	str r0, [r4, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080586A4: .4byte gUnk_085D3A70
.L080586A8: .4byte gUnk_0811AFA4
.L080586AC: .4byte gUnk_081ABCA0

	thumb_func_start func_fe6_080586B0
func_fe6_080586B0: @ 0x080586B0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L080586D6
	ldr r1, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #5
	adds r1, r1, r2
	bl func_fe6_080580D8
	b .L080586E8
.L080586D6:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L080586E8
	bl func_fe6_08057F24
	adds r0, r4, #0
	bl Proc_Break
.L080586E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080586F0
func_fe6_080586F0: @ 0x080586F0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r0, .L0805871C @ =gUnk_085D3A90
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	strh r5, [r0, #0x2c]
	strh r6, [r0, #0x2e]
	adds r0, #0x29
	mov r1, r8
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805871C: .4byte gUnk_085D3A90

	thumb_func_start func_fe6_08058720
func_fe6_08058720: @ 0x08058720
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	subs r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08058736
	adds r0, r1, #0
	bl Proc_Break
.L08058736:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805873C
func_fe6_0805873C: @ 0x0805873C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble .L08058756
	adds r0, r4, #0
	bl Proc_Break
	b .L080587B4
.L08058756:
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08058772
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	b .L08058782
.L08058772:
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
.L08058782:
	bl Interpolate
	adds r5, r0, #0
	ldr r3, .L080587BC @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	movs r1, #0
	strb r5, [r0]
	adds r2, #9
	movs r0, #0x10
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x46
	strb r1, [r0]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L080587B4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080587BC: .4byte gDispIo

	thumb_func_start func_fe6_080587C0
func_fe6_080587C0: @ 0x080587C0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl func_fe6_08057F58
	adds r6, r0, #0
	ldr r0, .L08058814 @ =gUnk_085D3AB0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x33
	strh r0, [r4, #0x2e]
	ldr r3, .L08058818 @ =gUnk_085F0A14
	adds r0, r5, #0
	movs r1, #1
	adds r2, r3, #0
	bl func_fe6_08057FE8
	str r0, [r4, #0x60]
	ldrh r2, [r0, #2]
	ldrh r3, [r6, #6]
	adds r1, r2, r3
	strh r1, [r0, #2]
	ldrh r2, [r0, #4]
	ldrh r6, [r6, #8]
	adds r1, r2, r6
	strh r1, [r0, #4]
	ldr r0, [r4, #0x5c]
	ldr r1, .L0805881C @ =gUnk_081AC0F4
	bl func_fe6_08058130
	ldr r0, [r4, #0x5c]
	ldr r1, .L08058820 @ =gUnk_081ABEA0
	bl func_fe6_08058100
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08058814: .4byte gUnk_085D3AB0
.L08058818: .4byte gUnk_085F0A14
.L0805881C: .4byte gUnk_081AC0F4
.L08058820: .4byte gUnk_081ABEA0

	thumb_func_start func_fe6_08058824
func_fe6_08058824: @ 0x08058824
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08058844
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08058844:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
