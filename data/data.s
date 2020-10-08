
	.data

	BEGIN = 0x5C8388
	END   = 0x69B668

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)

	.fill (0x6A0000 - END), 1, -1
