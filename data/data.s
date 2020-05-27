
	.data

	BEGIN = 0x5C6140
	END   = 0x800000

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
