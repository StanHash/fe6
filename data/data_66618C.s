	.data

	.global gBattleTalkList
gBattleTalkList: @ 0866618C
	.incbin "fe6-base.gba", 0x66618C, (0x6663CC - 0x66618C) @ length: 0240

	.global gBattleTalkExtList
gBattleTalkExtList: @ 086663CC
	.incbin "fe6-base.gba", 0x6663CC, (0x666528 - 0x6663CC) @ length: 015C

	.global gTriangleAttackTalkList
gTriangleAttackTalkList: @ 08666528
	.incbin "fe6-base.gba", 0x666528, (0x666598 - 0x666528) @ length: 0070

	.global gBattleDefeatTalkList
gBattleDefeatTalkList: @ 08666598
	.incbin "fe6-base.gba", 0x666598, (0x666C78 - 0x666598) @ length: 06E0

	.global gHardModeBonusLevelsOverrideList
gHardModeBonusLevelsOverrideList: @ 08666C78
	.incbin "fe6-base.gba", 0x666C78, (0x666CF8 - 0x666C78) @ length: 0080

	.global gSupportTalkList
gSupportTalkList: @ 08666CF8
	.incbin "fe6-base.gba", 0x666CF8, (0x6676E0 - 0x666CF8) @ length: 09E8

	.global EventListScr_Tutorial_ActionSelect
EventListScr_Tutorial_ActionSelect: @ 086676E0
	.incbin "fe6-base.gba", 0x6676E0, (0x66AAF8 - 0x6676E0) @ length: 3418
