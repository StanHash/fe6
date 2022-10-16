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

	.global EventScr_0866AAF8
EventScr_0866AAF8: @ 0866AAF8
	.incbin "fe6-base.gba", 0x66AAF8, (0x66ACCC - 0x66AAF8) @ length: 01D4

	.global gUnk_0866ACCC
gUnk_0866ACCC: @ 0866ACCC
	.incbin "fe6-base.gba", 0x66ACCC, (0x66ACE8 - 0x66ACCC) @ length: 001C

	.global gUnk_0866ACE8
gUnk_0866ACE8: @ 0866ACE8
	.incbin "fe6-base.gba", 0x66ACE8, (0x66AD00 - 0x66ACE8) @ length: 0018

	.global gUnk_0866AD00
gUnk_0866AD00: @ 0866AD00
	.incbin "fe6-base.gba", 0x66AD00, (0x66AEA8 - 0x66AD00) @ length: 01A8

	.global gUnk_0866AEA8
gUnk_0866AEA8: @ 0866AEA8
	.incbin "fe6-base.gba", 0x66AEA8, (0x66AEE0 - 0x66AEA8) @ length: 0038

	.global gUnk_0866AEE0
gUnk_0866AEE0: @ 0866AEE0
	.incbin "fe6-base.gba", 0x66AEE0, (0x66AF28 - 0x66AEE0) @ length: 0048

	.global gUnk_0866AF28
gUnk_0866AF28: @ 0866AF28
	.incbin "fe6-base.gba", 0x66AF28, (0x66AF5C - 0x66AF28) @ length: 0034

	.global gUnk_0866AF5C
gUnk_0866AF5C: @ 0866AF5C
	.incbin "fe6-base.gba", 0x66AF5C, (0x66AFEC - 0x66AF5C) @ length: 0090

	.global gUnk_0866AFEC
gUnk_0866AFEC: @ 0866AFEC
	.incbin "fe6-base.gba", 0x66AFEC, (0x66B07C - 0x66AFEC) @ length: 0090

	.global gUnk_0866B07C
gUnk_0866B07C: @ 0866B07C
	.incbin "fe6-base.gba", 0x66B07C, (0x66B10C - 0x66B07C) @ length: 0090

	.global gUnk_0866B10C
gUnk_0866B10C: @ 0866B10C
	.incbin "fe6-base.gba", 0x66B10C, (0x672458 - 0x66B10C) @ length: 734C

	.global gUnk_08672458
gUnk_08672458: @ 08672458
	.incbin "fe6-base.gba", 0x672458, (0x67507C - 0x672458) @ length: 2C24

	.global gUnk_0867507C
gUnk_0867507C: @ 0867507C
	.incbin "fe6-base.gba", 0x67507C, (0x675750 - 0x67507C) @ length: 06D4

	.global gUnk_08675750
gUnk_08675750: @ 08675750
	.incbin "fe6-base.gba", 0x675750, (0x675B90 - 0x675750) @ length: 0440

	.global gUnk_08675B90
gUnk_08675B90: @ 08675B90
	.incbin "fe6-base.gba", 0x675B90, (0x67619C - 0x675B90) @ length: 060C

	.global gUnk_0867619C
gUnk_0867619C: @ 0867619C
	.incbin "fe6-base.gba", 0x67619C, (0x676220 - 0x67619C) @ length: 0084

	.global gUnk_08676220
gUnk_08676220: @ 08676220
	.incbin "fe6-base.gba", 0x676220, (0x676738 - 0x676220) @ length: 0518

	.global gUnk_08676738
gUnk_08676738: @ 08676738
	.incbin "fe6-base.gba", 0x676738, (0x676844 - 0x676738) @ length: 010C

	.global gUnk_08676844
gUnk_08676844: @ 08676844
	.incbin "fe6-base.gba", 0x676844, (0x676854 - 0x676844) @ length: 0010

	.global gUnk_08676854
gUnk_08676854: @ 08676854
	.incbin "fe6-base.gba", 0x676854, (0x67686C - 0x676854) @ length: 0018

	.global gUnk_0867686C
gUnk_0867686C: @ 0867686C
	.incbin "fe6-base.gba", 0x67686C, (0x67688C - 0x67686C) @ length: 0020

	.global gUnk_0867688C
gUnk_0867688C: @ 0867688C
	.incbin "fe6-base.gba", 0x67688C, (0x6768C4 - 0x67688C) @ length: 0038

	.global gUnk_086768C4
gUnk_086768C4: @ 086768C4
	.incbin "fe6-base.gba", 0x6768C4, (0x6768DC - 0x6768C4) @ length: 0018

	.global gUnk_086768DC
gUnk_086768DC: @ 086768DC
	.incbin "fe6-base.gba", 0x6768DC, (0x6768FC - 0x6768DC) @ length: 0020

	.global gUnk_086768FC
gUnk_086768FC: @ 086768FC
	.incbin "fe6-base.gba", 0x6768FC, (0x676914 - 0x6768FC) @ length: 0018

	.global gUnk_08676914
gUnk_08676914: @ 08676914
	.incbin "fe6-base.gba", 0x676914, (0x67692C - 0x676914) @ length: 0018

	.global gUnk_0867692C
gUnk_0867692C: @ 0867692C
	.incbin "fe6-base.gba", 0x67692C, (0x67695C - 0x67692C) @ length: 0030

	.global gUnk_0867695C
gUnk_0867695C: @ 0867695C
	.incbin "fe6-base.gba", 0x67695C, (0x6770D4 - 0x67695C) @ length: 0778

	.global gUnk_086770D4
gUnk_086770D4: @ 086770D4
	.incbin "fe6-base.gba", 0x6770D4, (0x6772FC - 0x6770D4) @ length: 0228

	.global gUnk_086772FC
gUnk_086772FC: @ 086772FC
	.incbin "fe6-base.gba", 0x6772FC, (0x67730C - 0x6772FC) @ length: 0010

	.global gUnk_0867730C
gUnk_0867730C: @ 0867730C
	.incbin "fe6-base.gba", 0x67730C, (0x67731C - 0x67730C) @ length: 0010

	.global gUnk_0867731C
gUnk_0867731C: @ 0867731C
	.incbin "fe6-base.gba", 0x67731C, (0x677327 - 0x67731C) @ length: 000B

	.global gUnk_08677327
gUnk_08677327: @ 08677327
	.incbin "fe6-base.gba", 0x677327, (0x677348 - 0x677327) @ length: 0021

	.global ProcScr_Unk_08677348
ProcScr_Unk_08677348: @ 08677348
	.incbin "fe6-base.gba", 0x677348, (0x677360 - 0x677348) @ length: 0018

	.global gUnk_08677360
gUnk_08677360: @ 08677360
	.incbin "fe6-base.gba", 0x677360, (0x677378 - 0x677360) @ length: 0018

	.global ProcScr_Unk_08677378
ProcScr_Unk_08677378: @ 08677378
	.incbin "fe6-base.gba", 0x677378, (0x6773D8 - 0x677378) @ length: 0060
