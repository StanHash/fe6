	.section .rodata

	.incbin "fe6-base.gba", 0x307544, (0x3075B4 - 0x307544)

	.global gManimMuSpriteLayerLut
gManimMuSpriteLayerLut: @ 083075B4
	.incbin "fe6-base.gba", 0x3075B4, (0x307928 - 0x3075B4) @ length: 0374

	.global gUnk_08307928
gUnk_08307928: @ 08307928
	.incbin "fe6-base.gba", 0x307928, (0x307944 - 0x307928) @ length: 001C

	.global gUnk_08307944
gUnk_08307944: @ 08307944
	.incbin "fe6-base.gba", 0x307944, (0x307970 - 0x307944) @ length: 002C

	.global gUnk_08307970
gUnk_08307970: @ 08307970
	.incbin "fe6-base.gba", 0x307970, (0x307A10 - 0x307970) @ length: 00A0

	.global gUnk_08307A10
gUnk_08307A10: @ 08307A10
	.incbin "fe6-base.gba", 0x307A10, (0x307CEC - 0x307A10) @ length: 02DC

	.global gUnk_08307CEC
gUnk_08307CEC: @ 08307CEC
	.incbin "fe6-base.gba", 0x307CEC, (0x307D58 - 0x307CEC) @ length: 006C

	.global gUnk_08307D58
gUnk_08307D58: @ 08307D58
	.incbin "fe6-base.gba", 0x307D58, (0x307DD4 - 0x307D58) @ length: 007C

	.global gUnk_08307DD4
gUnk_08307DD4: @ 08307DD4
	.incbin "fe6-base.gba", 0x307DD4, (0x307E50 - 0x307DD4) @ length: 007C

	.global gUnk_08307E50
gUnk_08307E50: @ 08307E50
	.incbin "fe6-base.gba", 0x307E50, (0x307ED4 - 0x307E50) @ length: 0084

	.global gUnk_08307ED4
gUnk_08307ED4: @ 08307ED4
	.incbin "fe6-base.gba", 0x307ED4, (0x308050 - 0x307ED4) @ length: 017C

	.global gUnk_08308050
gUnk_08308050: @ 08308050
	.incbin "fe6-base.gba", 0x308050, (0x308070 - 0x308050) @ length: 0020

	.global gUnk_08308070
gUnk_08308070: @ 08308070
	.incbin "fe6-base.gba", 0x308070, (0x3080AC - 0x308070) @ length: 003C

	.global gUnk_083080AC
gUnk_083080AC: @ 083080AC
	.incbin "fe6-base.gba", 0x3080AC, (0x3080D0 - 0x3080AC) @ length: 0024

	.global gUnk_083080D0
gUnk_083080D0: @ 083080D0
	.incbin "fe6-base.gba", 0x3080D0, (0x3087C8 - 0x3080D0) @ length: 06F8

	.global Pal_Unk_083087C8
Pal_Unk_083087C8: @ 083087C8
	.incbin "fe6-base.gba", 0x3087C8, (0x308920 - 0x3087C8) @ length: 0158

	.global gUnk_08308920
gUnk_08308920: @ 08308920
	.incbin "fe6-base.gba", 0x308920, (0x308A78 - 0x308920) @ length: 0158

	.global gUnk_08308A78
gUnk_08308A78: @ 08308A78
	.incbin "fe6-base.gba", 0x308A78, (0x308B98 - 0x308A78) @ length: 0120

	.global Img_LimitViewSquares
Img_LimitViewSquares: @ 08308B98
	.incbin "fe6-base.gba", 0x308B98, (0x308E98 - 0x308B98) @ length: 0300

	.global Pal_LimitViewBlue
Pal_LimitViewBlue: @ 08308E98
	.incbin "fe6-base.gba", 0x308E98, (0x308EF8 - 0x308E98) @ length: 0060

	.global Pal_LimitViewRed
Pal_LimitViewRed: @ 08308EF8
	.incbin "fe6-base.gba", 0x308EF8, (0x308F58 - 0x308EF8) @ length: 0060

	.global Pal_LimitViewGreen
Pal_LimitViewGreen: @ 08308F58
	.incbin "fe6-base.gba", 0x308F58, (0x308FB8 - 0x308F58) @ length: 0060

	.global Img_MovePath
Img_MovePath: @ 08308FB8
	.incbin "fe6-base.gba", 0x308FB8, (0x3091F0 - 0x308FB8) @ length: 0238

	.global Pal_MovePath
Pal_MovePath: @ 083091F0
	.incbin "fe6-base.gba", 0x3091F0, (0x309210 - 0x3091F0) @ length: 0020

	.global Img_StatusHealEffect
Img_StatusHealEffect: @ 08309210
	.incbin "fe6-base.gba", 0x309210, (0x309298 - 0x309210) @ length: 0088

	.global Pal_StatusHealEffect
Pal_StatusHealEffect: @ 08309298
	.incbin "fe6-base.gba", 0x309298, (0x3092B8 - 0x309298) @ length: 0020

	.global Tsa_StatusHealEffect
Tsa_StatusHealEffect: @ 083092B8
	.incbin "fe6-base.gba", 0x3092B8, (0x3092CC - 0x3092B8) @ length: 0014

	.global gUnk_083092CC
gUnk_083092CC: @ 083092CC
	.incbin "fe6-base.gba", 0x3092CC, (0x3093EC - 0x3092CC) @ length: 0120

	.global gUnk_083093EC
gUnk_083093EC: @ 083093EC
	.incbin "fe6-base.gba", 0x3093EC, (0x3093F8 - 0x3093EC) @ length: 000C

	.global gUnk_083093F8
gUnk_083093F8: @ 083093F8
	.incbin "fe6-base.gba", 0x3093F8, (0x309408 - 0x3093F8) @ length: 0010

	.global gUnk_08309408
gUnk_08309408: @ 08309408
	.incbin "fe6-base.gba", 0x309408, (0x309474 - 0x309408) @ length: 006C

	.global gUnk_08309474
gUnk_08309474: @ 08309474
	.incbin "fe6-base.gba", 0x309474, (0x3094F4 - 0x309474) @ length: 0080

	.global gUnk_083094F4
gUnk_083094F4: @ 083094F4
	.incbin "fe6-base.gba", 0x3094F4, (0x309574 - 0x3094F4) @ length: 0080

	.global Img_ChapterIntroMotif
Img_ChapterIntroMotif: @ 08309574
	.incbin "fe6-base.gba", 0x309574, (0x30A574 - 0x309574) @ length: 1000

	.global Tm_ChapterIntroMotif
Tm_ChapterIntroMotif: @ 0830A574
	.incbin "fe6-base.gba", 0x30A574, (0x30A770 - 0x30A574) @ length: 01FC

	.global Pal_ChapterIntroMotif
Pal_ChapterIntroMotif: @ 0830A770
	.incbin "fe6-base.gba", 0x30A770, (0x30A790 - 0x30A770) @ length: 0020

	.global Img_ChapterIntroFog
Img_ChapterIntroFog: @ 0830A790
	.incbin "fe6-base.gba", 0x30A790, (0x30C414 - 0x30A790) @ length: 1C84

	.global Pal_ChapterIntroFog
Pal_ChapterIntroFog: @ 0830C414
	.incbin "fe6-base.gba", 0x30C414, (0x30C804 - 0x30C414) @ length: 03F0

	.global gUnk_0830C804
gUnk_0830C804: @ 0830C804
	.incbin "fe6-base.gba", 0x30C804, (0x30CFE0 - 0x30C804) @ length: 07DC

	.global gUnk_0830CFE0
gUnk_0830CFE0: @ 0830CFE0
	.incbin "fe6-base.gba", 0x30CFE0, (0x30D4F0 - 0x30CFE0) @ length: 0510

	.global gUnk_0830D4F0
gUnk_0830D4F0: @ 0830D4F0
	.incbin "fe6-base.gba", 0x30D4F0, (0x30D5E4 - 0x30D4F0) @ length: 00F4

	.global gUnk_0830D5E4
gUnk_0830D5E4: @ 0830D5E4
	.incbin "fe6-base.gba", 0x30D5E4, (0x30D604 - 0x30D5E4) @ length: 0020

	.global Img_GameOverText
Img_GameOverText: @ 0830D604
	.incbin "fe6-base.gba", 0x30D604, (0x30D93C - 0x30D604) @ length: 0338

	.global Pal_GameOverText
Pal_GameOverText: @ 0830D93C
	.incbin "fe6-base.gba", 0x30D93C, (0x30D95C - 0x30D93C) @ length: 0020

	.global Pal_Unk_0830D95C
Pal_Unk_0830D95C: @ 0830D95C
	.incbin "fe6-base.gba", 0x30D95C, (0x30D97C - 0x30D95C) @ length: 0020

	.global Tsa_Unk_0830D97C
Tsa_Unk_0830D97C: @ 0830D97C
	.incbin "fe6-base.gba", 0x30D97C, (0x3189B4 - 0x30D97C) @ length: B038

	.global gUnk_083189B4
gUnk_083189B4: @ 083189B4
	.incbin "fe6-base.gba", 0x3189B4, (0x31906C - 0x3189B4) @ length: 06B8

	.global gUnk_0831906C
gUnk_0831906C: @ 0831906C
	.incbin "fe6-base.gba", 0x31906C, (0x31908C - 0x31906C) @ length: 0020

	.global gUnk_0831908C
gUnk_0831908C: @ 0831908C
	.incbin "fe6-base.gba", 0x31908C, (0x3190AC - 0x31908C) @ length: 0020

	.global gUnk_083190AC
gUnk_083190AC: @ 083190AC
	.incbin "fe6-base.gba", 0x3190AC, (0x3190CC - 0x3190AC) @ length: 0020

	.global gUnk_083190CC
gUnk_083190CC: @ 083190CC
	.incbin "fe6-base.gba", 0x3190CC, (0x319124 - 0x3190CC) @ length: 0058

	.global gUnk_08319124
gUnk_08319124: @ 08319124
	.incbin "fe6-base.gba", 0x319124, (0x3193B0 - 0x319124) @ length: 028C

	.global gUnk_083193B0
gUnk_083193B0: @ 083193B0
	.incbin "fe6-base.gba", 0x3193B0, (0x3193BC - 0x3193B0) @ length: 000C

	.global gUnk_083193BC
gUnk_083193BC: @ 083193BC
	.incbin "fe6-base.gba", 0x3193BC, (0x3193C4 - 0x3193BC) @ length: 0008

	.global gUnk_083193C4
gUnk_083193C4: @ 083193C4
	.incbin "fe6-base.gba", 0x3193C4, (0x3193D0 - 0x3193C4) @ length: 000C

	.global gUnk_083193D0
gUnk_083193D0: @ 083193D0
	.incbin "fe6-base.gba", 0x3193D0, (0x3193EC - 0x3193D0) @ length: 001C
