
	.data

	.global TextGlyphs_System
TextGlyphs_System: @ 0859027C
	.incbin "fe6-base.gba", 0x59027C, (0x5A8204 - 0x59027C)

	.global TextGlyphs_Special
TextGlyphs_Special: @ 085A8204
	.incbin "fe6-base.gba", 0x5A8204, (0x5A82B0 - 0x5A8204)

	.global TextGlyphs_Talk
TextGlyphs_Talk: @ 085A82B0
	.incbin "fe6-base.gba", 0x5A82B0, (0x5C39A0 - 0x5A82B0)
