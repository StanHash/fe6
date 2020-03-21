
	.section .rodata

	.global gIconImg
gIconImg: @ 080F9D80
	.incbin "fe6-base.gba", 0x0F9D80, (0x0FED80 - 0x0F9D80)

	.global gIconPal
gIconPal: @ 080FED80
	.incbin "fe6-base.gba", 0x0FED80, (0x0FEDC0 - 0x0FED80)

	.global gFactionMiniCardImg
gFactionMiniCardImg: @ 080FEDC0
	.incbin "fe6-base.gba", 0x0FEDC0, (0x0FFBC0 - 0x0FEDC0)

	.global gFactionMiniCardPal
gFactionMiniCardPal: @ 080FFBC0
	.incbin "fe6-base.gba", 0x0FFBC0, (0x0FFC00 - 0x0FFBC0)
