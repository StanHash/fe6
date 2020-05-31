
	.section .rodata

	BEGIN = 0x105A1C
	END   = 0x105CBC

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)

	.data

	BEGIN = 0x5C6448
	END   = 0x5C788C

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
