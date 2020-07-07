
	.data

	BEGIN = 0x6A0000
	END   = 0x7FF0A4

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
