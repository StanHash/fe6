
	.section .rodata

	.incbin "fe6-base.gba", 0x105A1C, (0x105CBC - 0x105A1C)

	.data

	.incbin "fe6-base.gba", 0x5C6448, (0x5C73C0 - 0x5C6448)

	.global MenuInfo_085C73C0
MenuInfo_085C73C0: @ 085C73C0
	.incbin "fe6-base.gba", 0x5C73C0, (0x5C73E4 - 0x5C73C0) @ length: 0024

	.global MenuInfo_085C73E4
MenuInfo_085C73E4: @ 085C73E4
	.incbin "fe6-base.gba", 0x5C73E4, (0x5C7408 - 0x5C73E4) @ length: 0024

	.global MenuInfo_085C7408
MenuInfo_085C7408: @ 085C7408
	.incbin "fe6-base.gba", 0x5C7408, (0x5C742C - 0x5C7408) @ length: 0024

	.global MenuInfo_085C742C
MenuInfo_085C742C: @ 085C742C
	.incbin "fe6-base.gba", 0x5C742C, (0x5C7450 - 0x5C742C) @ length: 0024

	.global MenuInfo_085C7450
MenuInfo_085C7450: @ 085C7450
	.incbin "fe6-base.gba", 0x5C7450, (0x5C7474 - 0x5C7450) @ length: 0024

	.global MenuInfo_085C7474
MenuInfo_085C7474: @ 085C7474
	.incbin "fe6-base.gba", 0x5C7474, (0x5C7498 - 0x5C7474) @ length: 0024

	.global MenuInfo_085C7498
MenuInfo_085C7498: @ 085C7498
	.incbin "fe6-base.gba", 0x5C7498, (0x5C74BC - 0x5C7498) @ length: 0024

	.global MenuInfo_085C74BC
MenuInfo_085C74BC: @ 085C74BC
	.incbin "fe6-base.gba", 0x5C74BC, (0x5C74E0 - 0x5C74BC) @ length: 0024

	.global MenuInfo_085C74E0
MenuInfo_085C74E0: @ 085C74E0
	.incbin "fe6-base.gba", 0x5C74E0, (0x5C7504 - 0x5C74E0) @ length: 0024

	.global MenuInfo_085C7504
MenuInfo_085C7504: @ 085C7504
	.incbin "fe6-base.gba", 0x5C7504, (0x5C7528 - 0x5C7504) @ length: 0024

	.global MenuInfo_085C7528
MenuInfo_085C7528: @ 085C7528
	.incbin "fe6-base.gba", 0x5C7528, (0x5C754C - 0x5C7528) @ length: 0024

	.global MenuInfo_085C754C
MenuInfo_085C754C: @ 085C754C
	.incbin "fe6-base.gba", 0x5C754C, (0x5C7570 - 0x5C754C) @ length: 0024

	.global MenuInfo_085C7570
MenuInfo_085C7570: @ 085C7570
	.incbin "fe6-base.gba", 0x5C7570, (0x5C7594 - 0x5C7570) @ length: 0024

	.global MenuInfo_085C7594
MenuInfo_085C7594: @ 085C7594
	.incbin "fe6-base.gba", 0x5C7594, (0x5C75B8 - 0x5C7594) @ length: 0024

	.global MenuInfo_085C75B8
MenuInfo_085C75B8: @ 085C75B8
	.incbin "fe6-base.gba", 0x5C75B8, (0x5C75DC - 0x5C75B8) @ length: 0024

	.global MenuInfo_085C75DC
MenuInfo_085C75DC: @ 085C75DC
	.incbin "fe6-base.gba", 0x5C75DC, (0x5C7600 - 0x5C75DC) @ length: 0024

	.global MenuInfo_UnitMenu
MenuInfo_UnitMenu: @ 085C7600
	.incbin "fe6-base.gba", 0x5C7600, (0x5C7624 - 0x5C7600) @ length: 0024

	.global MenuInfo_085C7624
MenuInfo_085C7624: @ 085C7624
	.incbin "fe6-base.gba", 0x5C7624, (0x5C7648 - 0x5C7624) @ length: 0024

	.global MenuInfo_085C7648
MenuInfo_085C7648: @ 085C7648
	.incbin "fe6-base.gba", 0x5C7648, (0x5C766C - 0x5C7648) @ length: 0024

	.global MapSelectInfo_AttackStaff
MapSelectInfo_AttackStaff: @ 085C766C
	.incbin "fe6-base.gba", 0x5C766C, (0x5C768C - 0x5C766C) @ length: 0020

	.global MapSelectInfo_Barrier
MapSelectInfo_Barrier: @ 085C768C
	.incbin "fe6-base.gba", 0x5C768C, (0x5C76AC - 0x5C768C) @ length: 0020

	.global MapSelectInfo_Restore
MapSelectInfo_Restore: @ 085C76AC
	.incbin "fe6-base.gba", 0x5C76AC, (0x5C76CC - 0x5C76AC) @ length: 0020

	.global MapSelectInfo_Heal
MapSelectInfo_Heal: @ 085C76CC
	.incbin "fe6-base.gba", 0x5C76CC, (0x5C76EC - 0x5C76CC) @ length: 0020

	.global MapSelectInfo_085C76EC
MapSelectInfo_085C76EC: @ 085C76EC
	.incbin "fe6-base.gba", 0x5C76EC, (0x5C770C - 0x5C76EC) @ length: 0020

	.global MapSelectInfo_085C770C
MapSelectInfo_085C770C: @ 085C770C
	.incbin "fe6-base.gba", 0x5C770C, (0x5C772C - 0x5C770C) @ length: 0020

	.global MapSelectInfo_085C772C
MapSelectInfo_085C772C: @ 085C772C
	.incbin "fe6-base.gba", 0x5C772C, (0x5C774C - 0x5C772C) @ length: 0020

	.global MapSelectInfo_Steal
MapSelectInfo_Steal: @ 085C774C
	.incbin "fe6-base.gba", 0x5C774C, (0x5C776C - 0x5C774C) @ length: 0020

	.global MapSelectInfo_085C776C
MapSelectInfo_085C776C: @ 085C776C
	.incbin "fe6-base.gba", 0x5C776C, (0x5C778C - 0x5C776C) @ length: 0020

	.global MapSelectInfo_085C778C
MapSelectInfo_085C778C: @ 085C778C
	.incbin "fe6-base.gba", 0x5C778C, (0x5C77AC - 0x5C778C) @ length: 0020

	.global MapSelectInfo_Repair
MapSelectInfo_Repair: @ 085C77AC
	.incbin "fe6-base.gba", 0x5C77AC, (0x5C77CC - 0x5C77AC) @ length: 0020

	.global MapSelectInfo_085C77CC
MapSelectInfo_085C77CC: @ 085C77CC
	.incbin "fe6-base.gba", 0x5C77CC, (0x5C77EC - 0x5C77CC) @ length: 0020

	.global MapSelectInfo_085C77EC
MapSelectInfo_085C77EC: @ 085C77EC
	.incbin "fe6-base.gba", 0x5C77EC, (0x5C780C - 0x5C77EC) @ length: 0020

	.global MapSelectInfo_085C780C
MapSelectInfo_085C780C: @ 085C780C
	.incbin "fe6-base.gba", 0x5C780C, (0x5C782C - 0x5C780C) @ length: 0020

	.global MapSelectInfo_085C782C
MapSelectInfo_085C782C: @ 085C782C
	.incbin "fe6-base.gba", 0x5C782C, (0x5C784C - 0x5C782C) @ length: 0020

	.global MapSelectInfo_085C784C
MapSelectInfo_085C784C: @ 085C784C
	.incbin "fe6-base.gba", 0x5C784C, (0x5C786C - 0x5C784C) @ length: 0020

	.global MapSelectInfo_085C786C
MapSelectInfo_085C786C: @ 085C786C
	.incbin "fe6-base.gba", 0x5C786C, (0x5C788C - 0x5C786C) @ length: 0020
