
	.section .rodata

	.global Img_Icons
Img_Icons: @ 080F9D80
	.incbin "fe6-base.gba", 0x0F9D80, (0x0FED80 - 0x0F9D80)

	.global Pal_Icons
Pal_Icons: @ 080FED80
	.incbin "fe6-base.gba", 0x0FED80, (0x0FEDC0 - 0x0FED80)

	.global Img_FactionMiniCard
Img_FactionMiniCard: @ 080FEDC0
	.incbin "fe6-base.gba", 0x0FEDC0, (0x0FFBC0 - 0x0FEDC0)

	.global Pal_FactionMiniCard
Pal_FactionMiniCard: @ 080FFBC0
	.incbin "fe6-base.gba", 0x0FFBC0, (0x0FFC00 - 0x0FFBC0)
