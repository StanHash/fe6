
	.section .rodata

	BEGIN = 0x0F9998
	END   = 0x0F9C18

	@ TODO: extract that into a C file, included into hardware.c

	.global gSinLut
gSinLut: @ 080F9998
	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
