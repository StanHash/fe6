
	.data

	BEGIN = 0x58E5C4
	END   = 0x800000

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
