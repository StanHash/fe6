	.section .rodata

	.global gUnk_083273E4
gUnk_083273E4: @ 083273E4
	.incbin "fe6-base.gba", 0x3273E4, (0x3277BC - 0x3273E4) @ length: 03D8

	.global gUnk_083277BC
gUnk_083277BC: @ 083277BC
	.incbin "fe6-base.gba", 0x3277BC, (0x3277DC - 0x3277BC) @ length: 0020

	.global gUnk_083277DC
gUnk_083277DC: @ 083277DC
	.incbin "fe6-base.gba", 0x3277DC, (0x32785C - 0x3277DC) @ length: 0080
