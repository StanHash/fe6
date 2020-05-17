
	.data

	BEGIN = 0x5C4F5C
	END   = 0x800000

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
