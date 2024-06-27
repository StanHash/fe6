
	.include "animscr.inc"
	.section .data

	.global gUnk_085CCC40
gUnk_085CCC40: @ 085CCC40
	.incbin "fe6-base.gba", 0x5CCC40, (0x5CCDAC - 0x5CCC40) @ length: 016C

	.global gUnk_085CCDAC
gUnk_085CCDAC: @ 085CCDAC
	.incbin "fe6-base.gba", 0x5CCDAC, (0x5CCE38 - 0x5CCDAC) @ length: 008C

	.global gUnk_085CCE38
gUnk_085CCE38: @ 085CCE38
	.incbin "fe6-base.gba", 0x5CCE38, (0x5CCEB8 - 0x5CCE38) @ length: 0080

	.global gUnk_085CCEB8
gUnk_085CCEB8: @ 085CCEB8
	.incbin "fe6-base.gba", 0x5CCEB8, (0x5CCF38 - 0x5CCEB8) @ length: 0080

	.global gUnk_085CCF38
gUnk_085CCF38: @ 085CCF38
	.incbin "fe6-base.gba", 0x5CCF38, (0x5CDCA4 - 0x5CCF38) @ length: 0D6C

	.global gUnk_085CDCA4
gUnk_085CDCA4: @ 085CDCA4
	.incbin "fe6-base.gba", 0x5CDCA4, (0x5CDD18 - 0x5CDCA4) @ length: 0074

	.global gUnk_085CDD18
gUnk_085CDD18: @ 085CDD18
	.incbin "fe6-base.gba", 0x5CDD18, (0x5D0DA0 - 0x5CDD18) @ length: 3088

	.global gUnk_085D0DA0
gUnk_085D0DA0: @ 085D0DA0
	.incbin "fe6-base.gba", 0x5D0DA0, (0x5D0E80 - 0x5D0DA0) @ length: 00EC

AnimSprite_ManaketeFlame:
    ANIM_SPRITE_END

	.global AnimScr_ManaketeFlame
AnimScr_ManaketeFlame: @ 085D0E8C
    ANIMSCR_FORCE_SPRITE AnimSprite_ManaketeFlame, 1
    ANIMSCR_BLOCKED

	.global gUnk_085D0E94
gUnk_085D0E94: @ 085D0E94
	.incbin "fe6-base.gba", 0x5D0E94, (0x5D0EB4 - 0x5D0E94) @ length: 0020

	.global gUnk_085D0EB4
gUnk_085D0EB4: @ 085D0EB4
	.incbin "fe6-base.gba", 0x5D0EB4, (0x5D0ED4 - 0x5D0EB4) @ length: 0020

	.global gUnk_085D0ED4
gUnk_085D0ED4: @ 085D0ED4
	.incbin "fe6-base.gba", 0x5D0ED4, (0x5D0EEC - 0x5D0ED4) @ length: 0018

	.global gUnk_085D0EEC
gUnk_085D0EEC: @ 085D0EEC
	.incbin "fe6-base.gba", 0x5D0EEC, (0x5D0F0C - 0x5D0EEC) @ length: 0020

	.global gUnk_085D0F0C
gUnk_085D0F0C: @ 085D0F0C
	.incbin "fe6-base.gba", 0x5D0F0C, (0x5D0F24 - 0x5D0F0C) @ length: 0018

	.global gUnk_085D0F24
gUnk_085D0F24: @ 085D0F24
	.incbin "fe6-base.gba", 0x5D0F24, (0x5D0F3C - 0x5D0F24) @ length: 0018

	.global gUnk_085D0F3C
gUnk_085D0F3C: @ 085D0F3C
	.incbin "fe6-base.gba", 0x5D0F3C, (0x5D0F54 - 0x5D0F3C) @ length: 0018

	.global gUnk_085D0F54
gUnk_085D0F54: @ 085D0F54
	.incbin "fe6-base.gba", 0x5D0F54, (0x5D0F6C - 0x5D0F54) @ length: 0018

	.global gUnk_085D0F6C
gUnk_085D0F6C: @ 085D0F6C
	.incbin "fe6-base.gba", 0x5D0F6C, (0x5D0F84 - 0x5D0F6C) @ length: 0018

	.global gUnk_085D0F84
gUnk_085D0F84: @ 085D0F84
	.incbin "fe6-base.gba", 0x5D0F84, (0x5D0FA4 - 0x5D0F84) @ length: 0020

	.global gUnk_085D0FA4
gUnk_085D0FA4: @ 085D0FA4
	.incbin "fe6-base.gba", 0x5D0FA4, (0x5D0FBC - 0x5D0FA4) @ length: 0018

	.global gUnk_085D0FBC
gUnk_085D0FBC: @ 085D0FBC
	.incbin "fe6-base.gba", 0x5D0FBC, (0x5D0FDC - 0x5D0FBC) @ length: 0020

	.global gUnk_085D0FDC
gUnk_085D0FDC: @ 085D0FDC
	.incbin "fe6-base.gba", 0x5D0FDC, (0x5D0FF4 - 0x5D0FDC) @ length: 0018

	.global gUnk_085D0FF4
gUnk_085D0FF4: @ 085D0FF4
	.incbin "fe6-base.gba", 0x5D0FF4, (0x5D100C - 0x5D0FF4) @ length: 0018

	.global gUnk_085D100C
gUnk_085D100C: @ 085D100C
	.incbin "fe6-base.gba", 0x5D100C, (0x5D1024 - 0x5D100C) @ length: 0018

	.global gUnk_085D1024
gUnk_085D1024: @ 085D1024
	.incbin "fe6-base.gba", 0x5D1024, (0x5D103C - 0x5D1024) @ length: 0018

	.global gUnk_085D103C
gUnk_085D103C: @ 085D103C
	.incbin "fe6-base.gba", 0x5D103C, (0x5D1054 - 0x5D103C) @ length: 0018

	.global gUnk_085D1054
gUnk_085D1054: @ 085D1054
	.incbin "fe6-base.gba", 0x5D1054, (0x5D106C - 0x5D1054) @ length: 0018

	.global gUnk_085D106C
gUnk_085D106C: @ 085D106C
	.incbin "fe6-base.gba", 0x5D106C, (0x5D108C - 0x5D106C) @ length: 0020

	.global gUnk_085D108C
gUnk_085D108C: @ 085D108C
	.incbin "fe6-base.gba", 0x5D108C, (0x5D10A4 - 0x5D108C) @ length: 0018

	.global gUnk_085D10A4
gUnk_085D10A4: @ 085D10A4
	.incbin "fe6-base.gba", 0x5D10A4, (0x5D10BC - 0x5D10A4) @ length: 0018

	.global gUnk_085D10BC
gUnk_085D10BC: @ 085D10BC
	.incbin "fe6-base.gba", 0x5D10BC, (0x5D10D4 - 0x5D10BC) @ length: 0018

	.global gUnk_085D10D4
gUnk_085D10D4: @ 085D10D4
	.incbin "fe6-base.gba", 0x5D10D4, (0x5D10EC - 0x5D10D4) @ length: 0018

	.global gUnk_085D10EC
gUnk_085D10EC: @ 085D10EC
	.incbin "fe6-base.gba", 0x5D10EC, (0x5D1104 - 0x5D10EC) @ length: 0018

	.global gUnk_085D1104
gUnk_085D1104: @ 085D1104
	.incbin "fe6-base.gba", 0x5D1104, (0x5D111C - 0x5D1104) @ length: 0018

	.global gUnk_085D111C
gUnk_085D111C: @ 085D111C
	.incbin "fe6-base.gba", 0x5D111C, (0x5D113C - 0x5D111C) @ length: 0020

	.global gUnk_085D113C
gUnk_085D113C: @ 085D113C
	.incbin "fe6-base.gba", 0x5D113C, (0x5D1154 - 0x5D113C) @ length: 0018

	.global gUnk_085D1154
gUnk_085D1154: @ 085D1154
	.incbin "fe6-base.gba", 0x5D1154, (0x5D116C - 0x5D1154) @ length: 0018

	.global gUnk_085D116C
gUnk_085D116C: @ 085D116C
	.incbin "fe6-base.gba", 0x5D116C, (0x5D1184 - 0x5D116C) @ length: 0018

	.global gUnk_085D1184
gUnk_085D1184: @ 085D1184
	.incbin "fe6-base.gba", 0x5D1184, (0x5D119C - 0x5D1184) @ length: 0018

	.global gUnk_085D119C
gUnk_085D119C: @ 085D119C
	.incbin "fe6-base.gba", 0x5D119C, (0x5D11B4 - 0x5D119C) @ length: 0018

	.global gUnk_085D11B4
gUnk_085D11B4: @ 085D11B4
	.incbin "fe6-base.gba", 0x5D11B4, (0x5D11D4 - 0x5D11B4) @ length: 0020

	.global gUnk_085D11D4
gUnk_085D11D4: @ 085D11D4
	.incbin "fe6-base.gba", 0x5D11D4, (0x5D11EC - 0x5D11D4) @ length: 0018

	.global gUnk_085D11EC
gUnk_085D11EC: @ 085D11EC
	.incbin "fe6-base.gba", 0x5D11EC, (0x5D120C - 0x5D11EC) @ length: 0020

	.global gUnk_085D120C
gUnk_085D120C: @ 085D120C
	.incbin "fe6-base.gba", 0x5D120C, (0x5D1224 - 0x5D120C) @ length: 0018

	.global gUnk_085D1224
gUnk_085D1224: @ 085D1224
	.incbin "fe6-base.gba", 0x5D1224, (0x5D123C - 0x5D1224) @ length: 0018

	.global gUnk_085D123C
gUnk_085D123C: @ 085D123C
	.incbin "fe6-base.gba", 0x5D123C, (0x5D126C - 0x5D123C) @ length: 0030

	.global gUnk_085D126C
gUnk_085D126C: @ 085D126C
	.incbin "fe6-base.gba", 0x5D126C, (0x5D128C - 0x5D126C) @ length: 0020

	.global gUnk_085D128C
gUnk_085D128C: @ 085D128C
	.incbin "fe6-base.gba", 0x5D128C, (0x5D12A4 - 0x5D128C) @ length: 0018

	.global gUnk_085D12A4
gUnk_085D12A4: @ 085D12A4
	.incbin "fe6-base.gba", 0x5D12A4, (0x5D12BC - 0x5D12A4) @ length: 0018

	.global gUnk_085D12BC
gUnk_085D12BC: @ 085D12BC
	.incbin "fe6-base.gba", 0x5D12BC, (0x5D12D4 - 0x5D12BC) @ length: 0018

	.global gUnk_085D12D4
gUnk_085D12D4: @ 085D12D4
	.incbin "fe6-base.gba", 0x5D12D4, (0x5D12DC - 0x5D12D4) @ length: 0008

	.global gUnk_085D12DC
gUnk_085D12DC: @ 085D12DC
	.incbin "fe6-base.gba", 0x5D12DC, (0x5D12E4 - 0x5D12DC) @ length: 0008

	.global gUnk_085D12E4
gUnk_085D12E4: @ 085D12E4
	.incbin "fe6-base.gba", 0x5D12E4, (0x5D1304 - 0x5D12E4) @ length: 0020

	.global gUnk_085D1304
gUnk_085D1304: @ 085D1304
	.incbin "fe6-base.gba", 0x5D1304, (0x5D131C - 0x5D1304) @ length: 0018

	.global gUnk_085D131C
gUnk_085D131C: @ 085D131C
	.incbin "fe6-base.gba", 0x5D131C, (0x5D1334 - 0x5D131C) @ length: 0018

	.global gUnk_085D1334
gUnk_085D1334: @ 085D1334
	.incbin "fe6-base.gba", 0x5D1334, (0x5D134C - 0x5D1334) @ length: 0018

	.global gUnk_085D134C
gUnk_085D134C: @ 085D134C
	.incbin "fe6-base.gba", 0x5D134C, (0x5D137C - 0x5D134C) @ length: 0030

	.global gUnk_085D137C
gUnk_085D137C: @ 085D137C
	.incbin "fe6-base.gba", 0x5D137C, (0x5D13AC - 0x5D137C) @ length: 0030

	.global gUnk_085D13AC
gUnk_085D13AC: @ 085D13AC
	.incbin "fe6-base.gba", 0x5D13AC, (0x5D13C4 - 0x5D13AC) @ length: 0018

	.global gUnk_085D13C4
gUnk_085D13C4: @ 085D13C4
	.incbin "fe6-base.gba", 0x5D13C4, (0x5D13DC - 0x5D13C4) @ length: 0018

	.global gUnk_085D13DC
gUnk_085D13DC: @ 085D13DC
	.incbin "fe6-base.gba", 0x5D13DC, (0x5D1430 - 0x5D13DC) @ length: 0054

	.global gUnk_085D1430
gUnk_085D1430: @ 085D1430
	.incbin "fe6-base.gba", 0x5D1430, (0x5D1484 - 0x5D1430) @ length: 0054

	.global gUnk_085D1484
gUnk_085D1484: @ 085D1484
	.incbin "fe6-base.gba", 0x5D1484, (0x5D149C - 0x5D1484) @ length: 0018

	.global gUnk_085D149C
gUnk_085D149C: @ 085D149C
	.incbin "fe6-base.gba", 0x5D149C, (0x5D14BC - 0x5D149C) @ length: 0020

	.global gUnk_085D14BC
gUnk_085D14BC: @ 085D14BC
	.incbin "fe6-base.gba", 0x5D14BC, (0x5D14D4 - 0x5D14BC) @ length: 0018

	.global gUnk_085D14D4
gUnk_085D14D4: @ 085D14D4
	.incbin "fe6-base.gba", 0x5D14D4, (0x5D14EC - 0x5D14D4) @ length: 0018

	.global gUnk_085D14EC
gUnk_085D14EC: @ 085D14EC
	.incbin "fe6-base.gba", 0x5D14EC, (0x5D1504 - 0x5D14EC) @ length: 0018

	.global gUnk_085D1504
gUnk_085D1504: @ 085D1504
	.incbin "fe6-base.gba", 0x5D1504, (0x5D151C - 0x5D1504) @ length: 0018

	.global gUnk_085D151C
gUnk_085D151C: @ 085D151C
	.incbin "fe6-base.gba", 0x5D151C, (0x5D1534 - 0x5D151C) @ length: 0018

	.global gUnk_085D1534
gUnk_085D1534: @ 085D1534
	.incbin "fe6-base.gba", 0x5D1534, (0x5D154C - 0x5D1534) @ length: 0018

	.global gUnk_085D154C
gUnk_085D154C: @ 085D154C
	.incbin "fe6-base.gba", 0x5D154C, (0x5D1578 - 0x5D154C) @ length: 002C

	.global gUnk_085D1578
gUnk_085D1578: @ 085D1578
	.incbin "fe6-base.gba", 0x5D1578, (0x5D15A4 - 0x5D1578) @ length: 002C

	.global gUnk_085D15A4
gUnk_085D15A4: @ 085D15A4
	.incbin "fe6-base.gba", 0x5D15A4, (0x5D15BC - 0x5D15A4) @ length: 0018

	.global gUnk_085D15BC
gUnk_085D15BC: @ 085D15BC
	.incbin "fe6-base.gba", 0x5D15BC, (0x5D15D4 - 0x5D15BC) @ length: 0018

	.global gUnk_085D15D4
gUnk_085D15D4: @ 085D15D4
	.incbin "fe6-base.gba", 0x5D15D4, (0x5D15EC - 0x5D15D4) @ length: 0018

	.global gUnk_085D15EC
gUnk_085D15EC: @ 085D15EC
	.incbin "fe6-base.gba", 0x5D15EC, (0x5D1604 - 0x5D15EC) @ length: 0018

	.global gUnk_085D1604
gUnk_085D1604: @ 085D1604
	.incbin "fe6-base.gba", 0x5D1604, (0x5D161C - 0x5D1604) @ length: 0018

	.global gUnk_085D161C
gUnk_085D161C: @ 085D161C
	.incbin "fe6-base.gba", 0x5D161C, (0x5D1648 - 0x5D161C) @ length: 002C

	.global gUnk_085D1648
gUnk_085D1648: @ 085D1648
	.incbin "fe6-base.gba", 0x5D1648, (0x5D1674 - 0x5D1648) @ length: 002C

	.global gUnk_085D1674
gUnk_085D1674: @ 085D1674
	.incbin "fe6-base.gba", 0x5D1674, (0x5D169C - 0x5D1674) @ length: 0028

	.global gUnk_085D169C
gUnk_085D169C: @ 085D169C
	.incbin "fe6-base.gba", 0x5D169C, (0x5D16DC - 0x5D169C) @ length: 0040

	.global gUnk_085D16DC
gUnk_085D16DC: @ 085D16DC
	.incbin "fe6-base.gba", 0x5D16DC, (0x5D16FC - 0x5D16DC) @ length: 0020

	.global gUnk_085D16FC
gUnk_085D16FC: @ 085D16FC
	.incbin "fe6-base.gba", 0x5D16FC, (0x5D1714 - 0x5D16FC) @ length: 0018

	.global gUnk_085D1714
gUnk_085D1714: @ 085D1714
	.incbin "fe6-base.gba", 0x5D1714, (0x5D172C - 0x5D1714) @ length: 0018

	.global gUnk_085D172C
gUnk_085D172C: @ 085D172C
	.incbin "fe6-base.gba", 0x5D172C, (0x5D1734 - 0x5D172C) @ length: 0008

	.global gUnk_085D1734
gUnk_085D1734: @ 085D1734
	.incbin "fe6-base.gba", 0x5D1734, (0x5D1754 - 0x5D1734) @ length: 0020

	.global gUnk_085D1754
gUnk_085D1754: @ 085D1754
	.incbin "fe6-base.gba", 0x5D1754, (0x5D176C - 0x5D1754) @ length: 0018

	.global gUnk_085D176C
gUnk_085D176C: @ 085D176C
	.incbin "fe6-base.gba", 0x5D176C, (0x5D1784 - 0x5D176C) @ length: 0018

	.global gUnk_085D1784
gUnk_085D1784: @ 085D1784
	.incbin "fe6-base.gba", 0x5D1784, (0x5D179C - 0x5D1784) @ length: 0018

	.global gUnk_085D179C
gUnk_085D179C: @ 085D179C
	.incbin "fe6-base.gba", 0x5D179C, (0x5D1840 - 0x5D179C) @ length: 00A4

	.global gUnk_085D1840
gUnk_085D1840: @ 085D1840
	.incbin "fe6-base.gba", 0x5D1840, (0x5D18E4 - 0x5D1840) @ length: 00A4

	.global gUnk_085D18E4
gUnk_085D18E4: @ 085D18E4
	.incbin "fe6-base.gba", 0x5D18E4, (0x5D192C - 0x5D18E4) @ length: 0048

	.global gUnk_085D192C
gUnk_085D192C: @ 085D192C
	.incbin "fe6-base.gba", 0x5D192C, (0x5D195C - 0x5D192C) @ length: 0030

	.global gUnk_085D195C
gUnk_085D195C: @ 085D195C
	.incbin "fe6-base.gba", 0x5D195C, (0x5D1974 - 0x5D195C) @ length: 0018

	.global gUnk_085D1974
gUnk_085D1974: @ 085D1974
	.incbin "fe6-base.gba", 0x5D1974, (0x5D19A4 - 0x5D1974) @ length: 0030

	.global gUnk_085D19A4
gUnk_085D19A4: @ 085D19A4
	.incbin "fe6-base.gba", 0x5D19A4, (0x5D19BC - 0x5D19A4) @ length: 0018

	.global gUnk_085D19BC
gUnk_085D19BC: @ 085D19BC
	.incbin "fe6-base.gba", 0x5D19BC, (0x5D1A88 - 0x5D19BC) @ length: 00CC

	.global gUnk_085D1A88
gUnk_085D1A88: @ 085D1A88
	.incbin "fe6-base.gba", 0x5D1A88, (0x5D1B54 - 0x5D1A88) @ length: 00CC

	.global gUnk_085D1B54
gUnk_085D1B54: @ 085D1B54
	.incbin "fe6-base.gba", 0x5D1B54, (0x5D1B6C - 0x5D1B54) @ length: 0018

	.global gUnk_085D1B6C
gUnk_085D1B6C: @ 085D1B6C
	.incbin "fe6-base.gba", 0x5D1B6C, (0x5D1B84 - 0x5D1B6C) @ length: 0018

	.global gUnk_085D1B84
gUnk_085D1B84: @ 085D1B84
	.incbin "fe6-base.gba", 0x5D1B84, (0x5D1B9C - 0x5D1B84) @ length: 0018

	.global gUnk_085D1B9C
gUnk_085D1B9C: @ 085D1B9C
	.incbin "fe6-base.gba", 0x5D1B9C, (0x5D1C20 - 0x5D1B9C) @ length: 0084

	.global gUnk_085D1C20
gUnk_085D1C20: @ 085D1C20
	.incbin "fe6-base.gba", 0x5D1C20, (0x5D1CA4 - 0x5D1C20) @ length: 0084

	.global gUnk_085D1CA4
gUnk_085D1CA4: @ 085D1CA4
	.incbin "fe6-base.gba", 0x5D1CA4, (0x5D1D28 - 0x5D1CA4) @ length: 0084

	.global gUnk_085D1D28
gUnk_085D1D28: @ 085D1D28
	.incbin "fe6-base.gba", 0x5D1D28, (0x5D1D40 - 0x5D1D28) @ length: 0018

	.global gUnk_085D1D40
gUnk_085D1D40: @ 085D1D40
	.incbin "fe6-base.gba", 0x5D1D40, (0x5D1D58 - 0x5D1D40) @ length: 0018

	.global gUnk_085D1D58
gUnk_085D1D58: @ 085D1D58
	.incbin "fe6-base.gba", 0x5D1D58, (0x5D1E90 - 0x5D1D58) @ length: 0138

	.global gUnk_085D1E90
gUnk_085D1E90: @ 085D1E90
	.incbin "fe6-base.gba", 0x5D1E90, (0x5D1FC8 - 0x5D1E90) @ length: 0138

	.global gUnk_085D1FC8
gUnk_085D1FC8: @ 085D1FC8
	.incbin "fe6-base.gba", 0x5D1FC8, (0x5D2100 - 0x5D1FC8) @ length: 0138

	.global gUnk_085D2100
gUnk_085D2100: @ 085D2100
	.incbin "fe6-base.gba", 0x5D2100, (0x5D2120 - 0x5D2100) @ length: 0020

	.global gUnk_085D2120
gUnk_085D2120: @ 085D2120
	.incbin "fe6-base.gba", 0x5D2120, (0x5D2158 - 0x5D2120) @ length: 0038

	.global gUnk_085D2158
gUnk_085D2158: @ 085D2158
	.incbin "fe6-base.gba", 0x5D2158, (0x5D2178 - 0x5D2158) @ length: 0020

	.global gUnk_085D2178
gUnk_085D2178: @ 085D2178
	.incbin "fe6-base.gba", 0x5D2178, (0x5D2190 - 0x5D2178) @ length: 0018

	.global gUnk_085D2190
gUnk_085D2190: @ 085D2190
	.incbin "fe6-base.gba", 0x5D2190, (0x5D21A8 - 0x5D2190) @ length: 0018

	.global gUnk_085D21A8
gUnk_085D21A8: @ 085D21A8
	.incbin "fe6-base.gba", 0x5D21A8, (0x5D21DC - 0x5D21A8) @ length: 0034

	.global gUnk_085D21DC
gUnk_085D21DC: @ 085D21DC
	.incbin "fe6-base.gba", 0x5D21DC, (0x5D2210 - 0x5D21DC) @ length: 0034

	.global gUnk_085D2210
gUnk_085D2210: @ 085D2210
	.incbin "fe6-base.gba", 0x5D2210, (0x5D2230 - 0x5D2210) @ length: 0020

	.global gUnk_085D2230
gUnk_085D2230: @ 085D2230
	.incbin "fe6-base.gba", 0x5D2230, (0x5D2270 - 0x5D2230) @ length: 0040

	.global gUnk_085D2270
gUnk_085D2270: @ 085D2270
	.incbin "fe6-base.gba", 0x5D2270, (0x5D2288 - 0x5D2270) @ length: 0018

	.global gUnk_085D2288
gUnk_085D2288: @ 085D2288
	.incbin "fe6-base.gba", 0x5D2288, (0x5D22E0 - 0x5D2288) @ length: 0058

	.global gUnk_085D22E0
gUnk_085D22E0: @ 085D22E0
	.incbin "fe6-base.gba", 0x5D22E0, (0x5D22F8 - 0x5D22E0) @ length: 0018

	.global gUnk_085D22F8
gUnk_085D22F8: @ 085D22F8
	.incbin "fe6-base.gba", 0x5D22F8, (0x5D2310 - 0x5D22F8) @ length: 0018

	.global gUnk_085D2310
gUnk_085D2310: @ 085D2310
	.incbin "fe6-base.gba", 0x5D2310, (0x5D2328 - 0x5D2310) @ length: 0018

	.global gUnk_085D2328
gUnk_085D2328: @ 085D2328
	.incbin "fe6-base.gba", 0x5D2328, (0x5D2340 - 0x5D2328) @ length: 0018

	.global gUnk_085D2340
gUnk_085D2340: @ 085D2340
	.incbin "fe6-base.gba", 0x5D2340, (0x5D2358 - 0x5D2340) @ length: 0018

	.global gUnk_085D2358
gUnk_085D2358: @ 085D2358
	.incbin "fe6-base.gba", 0x5D2358, (0x5D2370 - 0x5D2358) @ length: 0018

	.global gUnk_085D2370
gUnk_085D2370: @ 085D2370
	.incbin "fe6-base.gba", 0x5D2370, (0x5D2388 - 0x5D2370) @ length: 0018

	.global gUnk_085D2388
gUnk_085D2388: @ 085D2388
	.incbin "fe6-base.gba", 0x5D2388, (0x5D23D8 - 0x5D2388) @ length: 0050

	.global gUnk_085D23D8
gUnk_085D23D8: @ 085D23D8
	.incbin "fe6-base.gba", 0x5D23D8, (0x5D2428 - 0x5D23D8) @ length: 0050

	.global gUnk_085D2428
gUnk_085D2428: @ 085D2428
	.incbin "fe6-base.gba", 0x5D2428, (0x5D2434 - 0x5D2428) @ length: 000C

	.global gUnk_085D2434
gUnk_085D2434: @ 085D2434
	.incbin "fe6-base.gba", 0x5D2434, (0x5D2440 - 0x5D2434) @ length: 000C

	.global gUnk_085D2440
gUnk_085D2440: @ 085D2440
	.incbin "fe6-base.gba", 0x5D2440, (0x5D2494 - 0x5D2440) @ length: 0054

	.global gUnk_085D2494
gUnk_085D2494: @ 085D2494
	.incbin "fe6-base.gba", 0x5D2494, (0x5D24E8 - 0x5D2494) @ length: 0054

	.global gUnk_085D24E8
gUnk_085D24E8: @ 085D24E8
	.incbin "fe6-base.gba", 0x5D24E8, (0x5D2500 - 0x5D24E8) @ length: 0018

	.global gUnk_085D2500
gUnk_085D2500: @ 085D2500
	.incbin "fe6-base.gba", 0x5D2500, (0x5D2518 - 0x5D2500) @ length: 0018

	.global gUnk_085D2518
gUnk_085D2518: @ 085D2518
	.incbin "fe6-base.gba", 0x5D2518, (0x5D2530 - 0x5D2518) @ length: 0018

	.global gUnk_085D2530
gUnk_085D2530: @ 085D2530
	.incbin "fe6-base.gba", 0x5D2530, (0x5D2544 - 0x5D2530) @ length: 0014

	.global gUnk_085D2544
gUnk_085D2544: @ 085D2544
	.incbin "fe6-base.gba", 0x5D2544, (0x5D2558 - 0x5D2544) @ length: 0014

	.global gUnk_085D2558
gUnk_085D2558: @ 085D2558
	.incbin "fe6-base.gba", 0x5D2558, (0x5D2570 - 0x5D2558) @ length: 0018

	.global gUnk_085D2570
gUnk_085D2570: @ 085D2570
	.incbin "fe6-base.gba", 0x5D2570, (0x5D2590 - 0x5D2570) @ length: 0020

	.global gUnk_085D2590
gUnk_085D2590: @ 085D2590
	.incbin "fe6-base.gba", 0x5D2590, (0x5D25A8 - 0x5D2590) @ length: 0018

	.global gUnk_085D25A8
gUnk_085D25A8: @ 085D25A8
	.incbin "fe6-base.gba", 0x5D25A8, (0x5D25C0 - 0x5D25A8) @ length: 0018

	.global gUnk_085D25C0
gUnk_085D25C0: @ 085D25C0
	.incbin "fe6-base.gba", 0x5D25C0, (0x5D25D8 - 0x5D25C0) @ length: 0018

	.global gUnk_085D25D8
gUnk_085D25D8: @ 085D25D8
	.incbin "fe6-base.gba", 0x5D25D8, (0x5D25F0 - 0x5D25D8) @ length: 0018

	.global gUnk_085D25F0
gUnk_085D25F0: @ 085D25F0
	.incbin "fe6-base.gba", 0x5D25F0, (0x5D2608 - 0x5D25F0) @ length: 0018

	.global gUnk_085D2608
gUnk_085D2608: @ 085D2608
	.incbin "fe6-base.gba", 0x5D2608, (0x5D2620 - 0x5D2608) @ length: 0018

	.global gUnk_085D2620
gUnk_085D2620: @ 085D2620
	.incbin "fe6-base.gba", 0x5D2620, (0x5D2638 - 0x5D2620) @ length: 0018

	.global gUnk_085D2638
gUnk_085D2638: @ 085D2638
	.incbin "fe6-base.gba", 0x5D2638, (0x5D2658 - 0x5D2638) @ length: 0020

	.global gUnk_085D2658
gUnk_085D2658: @ 085D2658
	.incbin "fe6-base.gba", 0x5D2658, (0x5D2678 - 0x5D2658) @ length: 0020

	.global gUnk_085D2678
gUnk_085D2678: @ 085D2678
	.incbin "fe6-base.gba", 0x5D2678, (0x5D26B0 - 0x5D2678) @ length: 0038

	.global gUnk_085D26B0
gUnk_085D26B0: @ 085D26B0
	.incbin "fe6-base.gba", 0x5D26B0, (0x5D26D0 - 0x5D26B0) @ length: 0020

	.global gUnk_085D26D0
gUnk_085D26D0: @ 085D26D0
	.incbin "fe6-base.gba", 0x5D26D0, (0x5D26F0 - 0x5D26D0) @ length: 0020

	.global gUnk_085D26F0
gUnk_085D26F0: @ 085D26F0
	.incbin "fe6-base.gba", 0x5D26F0, (0x5D2708 - 0x5D26F0) @ length: 0018

	.global gUnk_085D2708
gUnk_085D2708: @ 085D2708
	.incbin "fe6-base.gba", 0x5D2708, (0x5D2720 - 0x5D2708) @ length: 0018

	.global gUnk_085D2720
gUnk_085D2720: @ 085D2720
	.incbin "fe6-base.gba", 0x5D2720, (0x5D2740 - 0x5D2720) @ length: 0020

	.global gUnk_085D2740
gUnk_085D2740: @ 085D2740
	.incbin "fe6-base.gba", 0x5D2740, (0x5D2758 - 0x5D2740) @ length: 0018

	.global gUnk_085D2758
gUnk_085D2758: @ 085D2758
	.incbin "fe6-base.gba", 0x5D2758, (0x5D2768 - 0x5D2758) @ length: 0010

	.global gUnk_085D2768
gUnk_085D2768: @ 085D2768
	.incbin "fe6-base.gba", 0x5D2768, (0x5D2778 - 0x5D2768) @ length: 0010

	.global gUnk_085D2778
gUnk_085D2778: @ 085D2778
	.incbin "fe6-base.gba", 0x5D2778, (0x5D2798 - 0x5D2778) @ length: 0020

	.global gUnk_085D2798
gUnk_085D2798: @ 085D2798
	.incbin "fe6-base.gba", 0x5D2798, (0x5D27B0 - 0x5D2798) @ length: 0018

	.global gUnk_085D27B0
gUnk_085D27B0: @ 085D27B0
	.incbin "fe6-base.gba", 0x5D27B0, (0x5D287C - 0x5D27B0) @ length: 00CC

	.global gUnk_085D287C
gUnk_085D287C: @ 085D287C
	.incbin "fe6-base.gba", 0x5D287C, (0x5D2944 - 0x5D287C) @ length: 00C8

	.global gUnk_085D2944
gUnk_085D2944: @ 085D2944
	.incbin "fe6-base.gba", 0x5D2944, (0x5D2A0C - 0x5D2944) @ length: 00C8

	.global gUnk_085D2A0C
gUnk_085D2A0C: @ 085D2A0C
	.incbin "fe6-base.gba", 0x5D2A0C, (0x5D2A24 - 0x5D2A0C) @ length: 0018

	.global gUnk_085D2A24
gUnk_085D2A24: @ 085D2A24
	.incbin "fe6-base.gba", 0x5D2A24, (0x5D2A3C - 0x5D2A24) @ length: 0018

	.global gUnk_085D2A3C
gUnk_085D2A3C: @ 085D2A3C
	.incbin "fe6-base.gba", 0x5D2A3C, (0x5D2A54 - 0x5D2A3C) @ length: 0018

	.global gUnk_085D2A54
gUnk_085D2A54: @ 085D2A54
	.incbin "fe6-base.gba", 0x5D2A54, (0x5D2AC0 - 0x5D2A54) @ length: 006C

	.global gUnk_085D2AC0
gUnk_085D2AC0: @ 085D2AC0
	.incbin "fe6-base.gba", 0x5D2AC0, (0x5D2B2C - 0x5D2AC0) @ length: 006C

	.global gUnk_085D2B2C
gUnk_085D2B2C: @ 085D2B2C
	.incbin "fe6-base.gba", 0x5D2B2C, (0x5D2B74 - 0x5D2B2C) @ length: 0048

	.global gUnk_085D2B74
gUnk_085D2B74: @ 085D2B74
	.incbin "fe6-base.gba", 0x5D2B74, (0x5D2B8C - 0x5D2B74) @ length: 0018

	.global gUnk_085D2B8C
gUnk_085D2B8C: @ 085D2B8C
	.incbin "fe6-base.gba", 0x5D2B8C, (0x5D2BA4 - 0x5D2B8C) @ length: 0018

	.global gUnk_085D2BA4
gUnk_085D2BA4: @ 085D2BA4
	.incbin "fe6-base.gba", 0x5D2BA4, (0x5D2BC4 - 0x5D2BA4) @ length: 0020

	.global gUnk_085D2BC4
gUnk_085D2BC4: @ 085D2BC4
	.incbin "fe6-base.gba", 0x5D2BC4, (0x5D2BDC - 0x5D2BC4) @ length: 0018

	.global gUnk_085D2BDC
gUnk_085D2BDC: @ 085D2BDC
	.incbin "fe6-base.gba", 0x5D2BDC, (0x5D2BFC - 0x5D2BDC) @ length: 0020

	.global gUnk_085D2BFC
gUnk_085D2BFC: @ 085D2BFC
	.incbin "fe6-base.gba", 0x5D2BFC, (0x5D2C24 - 0x5D2BFC) @ length: 0028

	.global gUnk_085D2C24
gUnk_085D2C24: @ 085D2C24
	.incbin "fe6-base.gba", 0x5D2C24, (0x5D2C3C - 0x5D2C24) @ length: 0018

	.global gUnk_085D2C3C
gUnk_085D2C3C: @ 085D2C3C
	.incbin "fe6-base.gba", 0x5D2C3C, (0x5D2C54 - 0x5D2C3C) @ length: 0018

	.global gUnk_085D2C54
gUnk_085D2C54: @ 085D2C54
	.incbin "fe6-base.gba", 0x5D2C54, (0x5D2D20 - 0x5D2C54) @ length: 00CC

	.global gUnk_085D2D20
gUnk_085D2D20: @ 085D2D20
	.incbin "fe6-base.gba", 0x5D2D20, (0x5D2DEC - 0x5D2D20) @ length: 00CC

	.global gUnk_085D2DEC
gUnk_085D2DEC: @ 085D2DEC
	.incbin "fe6-base.gba", 0x5D2DEC, (0x5D2E04 - 0x5D2DEC) @ length: 0018

	.global gUnk_085D2E04
gUnk_085D2E04: @ 085D2E04
	.incbin "fe6-base.gba", 0x5D2E04, (0x5D2E1C - 0x5D2E04) @ length: 0018

	.global gUnk_085D2E1C
gUnk_085D2E1C: @ 085D2E1C
	.incbin "fe6-base.gba", 0x5D2E1C, (0x5D2E3C - 0x5D2E1C) @ length: 0020

	.global gUnk_085D2E3C
gUnk_085D2E3C: @ 085D2E3C
	.incbin "fe6-base.gba", 0x5D2E3C, (0x5D2E54 - 0x5D2E3C) @ length: 0018

	.global gUnk_085D2E54
gUnk_085D2E54: @ 085D2E54
	.incbin "fe6-base.gba", 0x5D2E54, (0x5D2E6C - 0x5D2E54) @ length: 0018

	.global gUnk_085D2E6C
gUnk_085D2E6C: @ 085D2E6C
	.incbin "fe6-base.gba", 0x5D2E6C, (0x5D2E84 - 0x5D2E6C) @ length: 0018

	.global gUnk_085D2E84
gUnk_085D2E84: @ 085D2E84
	.incbin "fe6-base.gba", 0x5D2E84, (0x5D2E9C - 0x5D2E84) @ length: 0018

	.global gUnk_085D2E9C
gUnk_085D2E9C: @ 085D2E9C
	.incbin "fe6-base.gba", 0x5D2E9C, (0x5D2EB4 - 0x5D2E9C) @ length: 0018

	.global gUnk_085D2EB4
gUnk_085D2EB4: @ 085D2EB4
	.incbin "fe6-base.gba", 0x5D2EB4, (0x5D2ED4 - 0x5D2EB4) @ length: 0020

	.global gUnk_085D2ED4
gUnk_085D2ED4: @ 085D2ED4
	.incbin "fe6-base.gba", 0x5D2ED4, (0x5D2EF4 - 0x5D2ED4) @ length: 0020

	.global gUnk_085D2EF4
gUnk_085D2EF4: @ 085D2EF4
	.incbin "fe6-base.gba", 0x5D2EF4, (0x5D2F0C - 0x5D2EF4) @ length: 0018

	.global gUnk_085D2F0C
gUnk_085D2F0C: @ 085D2F0C
	.incbin "fe6-base.gba", 0x5D2F0C, (0x5D2F2C - 0x5D2F0C) @ length: 0020

	.global gUnk_085D2F2C
gUnk_085D2F2C: @ 085D2F2C
	.incbin "fe6-base.gba", 0x5D2F2C, (0x5D2F4C - 0x5D2F2C) @ length: 0020

	.global gUnk_085D2F4C
gUnk_085D2F4C: @ 085D2F4C
	.incbin "fe6-base.gba", 0x5D2F4C, (0x5D2F64 - 0x5D2F4C) @ length: 0018

	.global gUnk_085D2F64
gUnk_085D2F64: @ 085D2F64
	.incbin "fe6-base.gba", 0x5D2F64, (0x5D2F7C - 0x5D2F64) @ length: 0018

	.global gUnk_085D2F7C
gUnk_085D2F7C: @ 085D2F7C
	.incbin "fe6-base.gba", 0x5D2F7C, (0x5D2F8C - 0x5D2F7C) @ length: 0010

	.global gUnk_085D2F8C
gUnk_085D2F8C: @ 085D2F8C
	.incbin "fe6-base.gba", 0x5D2F8C, (0x5D2FAC - 0x5D2F8C) @ length: 0020

	.global gUnk_085D2FAC
gUnk_085D2FAC: @ 085D2FAC
	.incbin "fe6-base.gba", 0x5D2FAC, (0x5D2FC4 - 0x5D2FAC) @ length: 0018

	.global gUnk_085D2FC4
gUnk_085D2FC4: @ 085D2FC4
	.incbin "fe6-base.gba", 0x5D2FC4, (0x5D2FC8 - 0x5D2FC4) @ length: 0004

	.global gUnk_085D2FC8
gUnk_085D2FC8: @ 085D2FC8
	.incbin "fe6-base.gba", 0x5D2FC8, (0x5D2FE8 - 0x5D2FC8) @ length: 0020

	.global gUnk_085D2FE8
gUnk_085D2FE8: @ 085D2FE8
	.incbin "fe6-base.gba", 0x5D2FE8, (0x5D3000 - 0x5D2FE8) @ length: 0018

	.global gUnk_085D3000
gUnk_085D3000: @ 085D3000
	.incbin "fe6-base.gba", 0x5D3000, (0x5D3018 - 0x5D3000) @ length: 0018

	.global gUnk_085D3018
gUnk_085D3018: @ 085D3018
	.incbin "fe6-base.gba", 0x5D3018, (0x5D304C - 0x5D3018) @ length: 0034

	.global gUnk_085D304C
gUnk_085D304C: @ 085D304C
	.incbin "fe6-base.gba", 0x5D304C, (0x5D3080 - 0x5D304C) @ length: 0034

	.global gUnk_085D3080
gUnk_085D3080: @ 085D3080
	.incbin "fe6-base.gba", 0x5D3080, (0x5D30A0 - 0x5D3080) @ length: 0020

	.global gUnk_085D30A0
gUnk_085D30A0: @ 085D30A0
	.incbin "fe6-base.gba", 0x5D30A0, (0x5D30B8 - 0x5D30A0) @ length: 0018

	.global gUnk_085D30B8
gUnk_085D30B8: @ 085D30B8
	.incbin "fe6-base.gba", 0x5D30B8, (0x5D30D0 - 0x5D30B8) @ length: 0018

	.global gUnk_085D30D0
gUnk_085D30D0: @ 085D30D0
	.incbin "fe6-base.gba", 0x5D30D0, (0x5D3118 - 0x5D30D0) @ length: 0048

	.global gUnk_085D3118
gUnk_085D3118: @ 085D3118
	.incbin "fe6-base.gba", 0x5D3118, (0x5D3138 - 0x5D3118) @ length: 0020

	.global gUnk_085D3138
gUnk_085D3138: @ 085D3138
	.incbin "fe6-base.gba", 0x5D3138, (0x5D3150 - 0x5D3138) @ length: 0018

	.global gUnk_085D3150
gUnk_085D3150: @ 085D3150
	.incbin "fe6-base.gba", 0x5D3150, (0x5D3168 - 0x5D3150) @ length: 0018

	.global gUnk_085D3168
gUnk_085D3168: @ 085D3168
	.incbin "fe6-base.gba", 0x5D3168, (0x5D31A8 - 0x5D3168) @ length: 0040

	.global gUnk_085D31A8
gUnk_085D31A8: @ 085D31A8
	.incbin "fe6-base.gba", 0x5D31A8, (0x5D31C8 - 0x5D31A8) @ length: 0020

	.global gUnk_085D31C8
gUnk_085D31C8: @ 085D31C8
	.incbin "fe6-base.gba", 0x5D31C8, (0x5D31E8 - 0x5D31C8) @ length: 0020

	.global gUnk_085D31E8
gUnk_085D31E8: @ 085D31E8
	.incbin "fe6-base.gba", 0x5D31E8, (0x5D3230 - 0x5D31E8) @ length: 0048

	.global gUnk_085D3230
gUnk_085D3230: @ 085D3230
	.incbin "fe6-base.gba", 0x5D3230, (0x5D3248 - 0x5D3230) @ length: 0018

	.global gUnk_085D3248
gUnk_085D3248: @ 085D3248
	.incbin "fe6-base.gba", 0x5D3248, (0x5D3260 - 0x5D3248) @ length: 0018

	.global gUnk_085D3260
gUnk_085D3260: @ 085D3260
	.incbin "fe6-base.gba", 0x5D3260, (0x5D3294 - 0x5D3260) @ length: 0034

	.global gUnk_085D3294
gUnk_085D3294: @ 085D3294
	.incbin "fe6-base.gba", 0x5D3294, (0x5D32C8 - 0x5D3294) @ length: 0034

	.global gUnk_085D32C8
gUnk_085D32C8: @ 085D32C8
	.incbin "fe6-base.gba", 0x5D32C8, (0x5D32E8 - 0x5D32C8) @ length: 0020

	.global gUnk_085D32E8
gUnk_085D32E8: @ 085D32E8
	.incbin "fe6-base.gba", 0x5D32E8, (0x5D3300 - 0x5D32E8) @ length: 0018

	.global gUnk_085D3300
gUnk_085D3300: @ 085D3300
	.incbin "fe6-base.gba", 0x5D3300, (0x5D3318 - 0x5D3300) @ length: 0018

	.global gUnk_085D3318
gUnk_085D3318: @ 085D3318
	.incbin "fe6-base.gba", 0x5D3318, (0x5D3338 - 0x5D3318) @ length: 0020

	.global gUnk_085D3338
gUnk_085D3338: @ 085D3338
	.incbin "fe6-base.gba", 0x5D3338, (0x5D33F0 - 0x5D3338) @ length: 00B8

	.global gUnk_085D33F0
gUnk_085D33F0: @ 085D33F0
	.incbin "fe6-base.gba", 0x5D33F0, (0x5D3408 - 0x5D33F0) @ length: 0018

	.global gUnk_085D3408
gUnk_085D3408: @ 085D3408
	.incbin "fe6-base.gba", 0x5D3408, (0x5D3420 - 0x5D3408) @ length: 0018

	.global gUnk_085D3420
gUnk_085D3420: @ 085D3420
	.incbin "fe6-base.gba", 0x5D3420, (0x5D3434 - 0x5D3420) @ length: 0014

	.global gUnk_085D3434
gUnk_085D3434: @ 085D3434
	.incbin "fe6-base.gba", 0x5D3434, (0x5D3454 - 0x5D3434) @ length: 0020

	.global gUnk_085D3454
gUnk_085D3454: @ 085D3454
	.incbin "fe6-base.gba", 0x5D3454, (0x5D3474 - 0x5D3454) @ length: 0020

	.global ProcScr_EfxDamageMojiEffect
ProcScr_EfxDamageMojiEffect: @ 085D3474
	.incbin "fe6-base.gba", 0x5D3474, (0x5D348C - 0x5D3474) @ length: 0018

	.global gUnk_085D348C
gUnk_085D348C: @ 085D348C
	.incbin "fe6-base.gba", 0x5D348C, (0x5D34A4 - 0x5D348C) @ length: 0018

	.global gUnk_085D34A4
gUnk_085D34A4: @ 085D34A4
	.incbin "fe6-base.gba", 0x5D34A4, (0x5D34BC - 0x5D34A4) @ length: 0018

	.global gUnk_085D34BC
gUnk_085D34BC: @ 085D34BC
	.incbin "fe6-base.gba", 0x5D34BC, (0x5D34D4 - 0x5D34BC) @ length: 0018

	.global gUnk_085D34D4
gUnk_085D34D4: @ 085D34D4
	.incbin "fe6-base.gba", 0x5D34D4, (0x5D34F4 - 0x5D34D4) @ length: 0020

	.global gUnk_085D34F4
gUnk_085D34F4: @ 085D34F4
	.incbin "fe6-base.gba", 0x5D34F4, (0x5D350C - 0x5D34F4) @ length: 0018

	.global gUnk_085D350C
gUnk_085D350C: @ 085D350C
	.incbin "fe6-base.gba", 0x5D350C, (0x5D3524 - 0x5D350C) @ length: 0018

	.global gUnk_085D3524
gUnk_085D3524: @ 085D3524
	.incbin "fe6-base.gba", 0x5D3524, (0x5D354C - 0x5D3524) @ length: 0028

	.global ProcScr_EfxYushaSpinShield
ProcScr_EfxYushaSpinShield: @ 085D354C
	.incbin "fe6-base.gba", 0x5D354C, (0x5D3564 - 0x5D354C) @ length: 0018

	.global ProcScr_EfxYushaSpinShieldOBJ
ProcScr_EfxYushaSpinShieldOBJ: @ 085D3564
	.incbin "fe6-base.gba", 0x5D3564, (0x5D3594 - 0x5D3564) @ length: 0030

	.global gUnk_085D3594
gUnk_085D3594: @ 085D3594
	.incbin "fe6-base.gba", 0x5D3594, (0x5D35AC - 0x5D3594) @ length: 0018

	.global gUnk_085D35AC
gUnk_085D35AC: @ 085D35AC
	.incbin "fe6-base.gba", 0x5D35AC, (0x5D35E4 - 0x5D35AC) @ length: 0038

	.global gUnk_085D35E4
gUnk_085D35E4: @ 085D35E4
	.incbin "fe6-base.gba", 0x5D35E4, (0x5D361C - 0x5D35E4) @ length: 0038

	.global gUnk_085D361C
gUnk_085D361C: @ 085D361C
	.incbin "fe6-base.gba", 0x5D361C, (0x5D3634 - 0x5D361C) @ length: 0018

	.global gUnk_085D3634
gUnk_085D3634: @ 085D3634
	.incbin "fe6-base.gba", 0x5D3634, (0x5D364C - 0x5D3634) @ length: 0018

	.global gUnk_085D364C
gUnk_085D364C: @ 085D364C
	.incbin "fe6-base.gba", 0x5D364C, (0x5D3664 - 0x5D364C) @ length: 0018

	.global gUnk_085D3664
gUnk_085D3664: @ 085D3664
	.incbin "fe6-base.gba", 0x5D3664, (0x5D36A4 - 0x5D3664) @ length: 0040

	.global gUnk_085D36A4
gUnk_085D36A4: @ 085D36A4
	.incbin "fe6-base.gba", 0x5D36A4, (0x5D36BC - 0x5D36A4) @ length: 0018

	.global gUnk_085D36BC
gUnk_085D36BC: @ 085D36BC
	.incbin "fe6-base.gba", 0x5D36BC, (0x5D36D4 - 0x5D36BC) @ length: 0018

	.global gUnk_085D36D4
gUnk_085D36D4: @ 085D36D4
	.incbin "fe6-base.gba", 0x5D36D4, (0x5D36EC - 0x5D36D4) @ length: 0018

	.global gUnk_085D36EC
gUnk_085D36EC: @ 085D36EC
	.incbin "fe6-base.gba", 0x5D36EC, (0x5D3704 - 0x5D36EC) @ length: 0018

	.global gUnk_085D3704
gUnk_085D3704: @ 085D3704
	.incbin "fe6-base.gba", 0x5D3704, (0x5D371C - 0x5D3704) @ length: 0018

	.global gUnk_085D371C
gUnk_085D371C: @ 085D371C
	.incbin "fe6-base.gba", 0x5D371C, (0x5D373C - 0x5D371C) @ length: 0020

	.global gUnk_085D373C
gUnk_085D373C: @ 085D373C
	.incbin "fe6-base.gba", 0x5D373C, (0x5D3754 - 0x5D373C) @ length: 0018

	.global gUnk_085D3754
gUnk_085D3754: @ 085D3754
	.incbin "fe6-base.gba", 0x5D3754, (0x5D376C - 0x5D3754) @ length: 0018

	.global gUnk_085D376C
gUnk_085D376C: @ 085D376C
	.incbin "fe6-base.gba", 0x5D376C, (0x5D3784 - 0x5D376C) @ length: 0018

	.global gUnk_085D3784
gUnk_085D3784: @ 085D3784
	.incbin "fe6-base.gba", 0x5D3784, (0x5D379C - 0x5D3784) @ length: 0018

	.global gUnk_085D379C
gUnk_085D379C: @ 085D379C
	.incbin "fe6-base.gba", 0x5D379C, (0x5D37B4 - 0x5D379C) @ length: 0018

	.global gUnk_085D37B4
gUnk_085D37B4: @ 085D37B4
	.incbin "fe6-base.gba", 0x5D37B4, (0x5D38A4 - 0x5D37B4) @ length: 00F0

	.global gUnk_085D38A4
gUnk_085D38A4: @ 085D38A4
	.incbin "fe6-base.gba", 0x5D38A4, (0x5D38BC - 0x5D38A4) @ length: 0018

	.global gUnk_085D38BC
gUnk_085D38BC: @ 085D38BC
	.incbin "fe6-base.gba", 0x5D38BC, (0x5D38D4 - 0x5D38BC) @ length: 0018

	.global gUnk_085D38D4
gUnk_085D38D4: @ 085D38D4
	.incbin "fe6-base.gba", 0x5D38D4, (0x5D38E4 - 0x5D38D4) @ length: 0010

	.global gUnk_085D38E4
gUnk_085D38E4: @ 085D38E4
	.incbin "fe6-base.gba", 0x5D38E4, (0x5D3904 - 0x5D38E4) @ length: 0020

	.global gUnk_085D3904
gUnk_085D3904: @ 085D3904
	.incbin "fe6-base.gba", 0x5D3904, (0x5D3924 - 0x5D3904) @ length: 0020

	.global gUnk_085D3924
gUnk_085D3924: @ 085D3924
	.incbin "fe6-base.gba", 0x5D3924, (0x5D394C - 0x5D3924) @ length: 0028

	.global gUnk_085D394C
gUnk_085D394C: @ 085D394C
	.incbin "fe6-base.gba", 0x5D394C, (0x5D3964 - 0x5D394C) @ length: 0018

	.global gUnk_085D3964
gUnk_085D3964: @ 085D3964
	.incbin "fe6-base.gba", 0x5D3964, (0x5D3994 - 0x5D3964) @ length: 0030

	.global gUnk_085D3994
gUnk_085D3994: @ 085D3994
	.incbin "fe6-base.gba", 0x5D3994, (0x5D39AC - 0x5D3994) @ length: 0018

	.global gUnk_085D39AC
gUnk_085D39AC: @ 085D39AC
	.incbin "fe6-base.gba", 0x5D39AC, (0x5D39D4 - 0x5D39AC) @ length: 0028

	.global gUnk_085D39D4
gUnk_085D39D4: @ 085D39D4
	.incbin "fe6-base.gba", 0x5D39D4, (0x5D39EC - 0x5D39D4) @ length: 0018

	.global gUnk_085D39EC
gUnk_085D39EC: @ 085D39EC
	.incbin "fe6-base.gba", 0x5D39EC, (0x5D39F4 - 0x5D39EC) @ length: 0008

	.global gUnk_085D39F4
gUnk_085D39F4: @ 085D39F4
	.incbin "fe6-base.gba", 0x5D39F4, (0x5D3A14 - 0x5D39F4) @ length: 0020

	.global gUnk_085D3A14
gUnk_085D3A14: @ 085D3A14
	.incbin "fe6-base.gba", 0x5D3A14, (0x5D3A2C - 0x5D3A14) @ length: 0018

	.global gUnk_085D3A2C
gUnk_085D3A2C: @ 085D3A2C
	.incbin "fe6-base.gba", 0x5D3A2C, (0x5D3A54 - 0x5D3A2C) @ length: 0028

	.global gUnk_085D3A54
gUnk_085D3A54: @ 085D3A54
	.incbin "fe6-base.gba", 0x5D3A54, (0x5D3A6C - 0x5D3A54) @ length: 0018

	.global gUnk_085D3A6C
gUnk_085D3A6C: @ 085D3A6C
	.incbin "fe6-base.gba", 0x5D3A6C, (0x5D3A70 - 0x5D3A6C) @ length: 0004

	.global gUnk_085D3A70
gUnk_085D3A70: @ 085D3A70
	.incbin "fe6-base.gba", 0x5D3A70, (0x5D3A90 - 0x5D3A70) @ length: 0020

	.global gUnk_085D3A90
gUnk_085D3A90: @ 085D3A90
	.incbin "fe6-base.gba", 0x5D3A90, (0x5D3AB0 - 0x5D3A90) @ length: 0020

	.global gUnk_085D3AB0
gUnk_085D3AB0: @ 085D3AB0
	.incbin "fe6-base.gba", 0x5D3AB0, (0x5D3DB0 - 0x5D3AB0) @ length: 0300

	.global gUnk_085D3DB0
gUnk_085D3DB0: @ 085D3DB0
	.incbin "fe6-base.gba", 0x5D3DB0, (0x5D3E0C - 0x5D3DB0) @ length: 005C

	.global gUnk_085D3E0C
gUnk_085D3E0C: @ 085D3E0C
	.incbin "fe6-base.gba", 0x5D3E0C, (0x5D3E2C - 0x5D3E0C) @ length: 0020

	.global gUnk_085D3E2C
gUnk_085D3E2C: @ 085D3E2C
	.incbin "fe6-base.gba", 0x5D3E2C, (0x5D4148 - 0x5D3E2C) @ length: 031C

	.global gUnk_085D4148
gUnk_085D4148: @ 085D4148
	.incbin "fe6-base.gba", 0x5D4148, (0x5D41A4 - 0x5D4148) @ length: 005C

	.global gUnk_085D41A4
gUnk_085D41A4: @ 085D41A4
	.incbin "fe6-base.gba", 0x5D41A4, (0x5D41C4 - 0x5D41A4) @ length: 0020

	.global gUnk_085D41C4
gUnk_085D41C4: @ 085D41C4
	.incbin "fe6-base.gba", 0x5D41C4, (0x5D4264 - 0x5D41C4) @ length: 00A0

	.global gUnk_085D4264
gUnk_085D4264: @ 085D4264
	.incbin "fe6-base.gba", 0x5D4264, (0x5D4274 - 0x5D4264) @ length: 0010

	.global gUnk_085D4274
gUnk_085D4274: @ 085D4274
	.incbin "fe6-base.gba", 0x5D4274, (0x5D42F0 - 0x5D4274) @ length: 007C

	.global gUnk_085D42F0
gUnk_085D42F0: @ 085D42F0
	.incbin "fe6-base.gba", 0x5D42F0, (0x5D4300 - 0x5D42F0) @ length: 0010

	.global gUnk_085D4300
gUnk_085D4300: @ 085D4300
	.incbin "fe6-base.gba", 0x5D4300, (0x5D44E4 - 0x5D4300) @ length: 01E4

	.global gUnk_085D44E4
gUnk_085D44E4: @ 085D44E4
	.incbin "fe6-base.gba", 0x5D44E4, (0x5D4738 - 0x5D44E4) @ length: 0254

	.global gUnk_085D4738
gUnk_085D4738: @ 085D4738
	.incbin "fe6-base.gba", 0x5D4738, (0x5D4998 - 0x5D4738) @ length: 0260

	.global gUnk_085D4998
gUnk_085D4998: @ 085D4998
	.incbin "fe6-base.gba", 0x5D4998, (0x5D4BF8 - 0x5D4998) @ length: 0260

	.global gUnk_085D4BF8
gUnk_085D4BF8: @ 085D4BF8
	.incbin "fe6-base.gba", 0x5D4BF8, (0x5D4CFC - 0x5D4BF8) @ length: 0104

	.global gUnk_085D4CFC
gUnk_085D4CFC: @ 085D4CFC
	.incbin "fe6-base.gba", 0x5D4CFC, (0x5D4D98 - 0x5D4CFC) @ length: 009C

	.global gUnk_085D4D98
gUnk_085D4D98: @ 085D4D98
	.incbin "fe6-base.gba", 0x5D4D98, (0x5D5590 - 0x5D4D98) @ length: 07F8

	.global gUnk_085D5590
gUnk_085D5590: @ 085D5590
	.incbin "fe6-base.gba", 0x5D5590, (0x5D55C0 - 0x5D5590) @ length: 0030

	.global gUnk_085D55C0
gUnk_085D55C0: @ 085D55C0
	.incbin "fe6-base.gba", 0x5D55C0, (0x5D6218 - 0x5D55C0) @ length: 0C58

	.global gUnk_085D6218
gUnk_085D6218: @ 085D6218
	.incbin "fe6-base.gba", 0x5D6218, (0x5D6E78 - 0x5D6218) @ length: 0C60

	.global gUnk_085D6E78
gUnk_085D6E78: @ 085D6E78
	.incbin "fe6-base.gba", 0x5D6E78, (0x5D7190 - 0x5D6E78) @ length: 0318

	.global gUnk_085D7190
gUnk_085D7190: @ 085D7190
	.incbin "fe6-base.gba", 0x5D7190, (0x5D71D8 - 0x5D7190) @ length: 0048

	.global gUnk_085D71D8
gUnk_085D71D8: @ 085D71D8
	.incbin "fe6-base.gba", 0x5D71D8, (0x5D74FC - 0x5D71D8) @ length: 0324

	.global gUnk_085D74FC
gUnk_085D74FC: @ 085D74FC
	.incbin "fe6-base.gba", 0x5D74FC, (0x5D7544 - 0x5D74FC) @ length: 0048

	.global gUnk_085D7544
gUnk_085D7544: @ 085D7544
	.incbin "fe6-base.gba", 0x5D7544, (0x5D77E4 - 0x5D7544) @ length: 02A0

	.global gUnk_085D77E4
gUnk_085D77E4: @ 085D77E4
	.incbin "fe6-base.gba", 0x5D77E4, (0x5D77F4 - 0x5D77E4) @ length: 0010

	.global gUnk_085D77F4
gUnk_085D77F4: @ 085D77F4
	.incbin "fe6-base.gba", 0x5D77F4, (0x5D7A40 - 0x5D77F4) @ length: 024C

	.global gUnk_085D7A40
gUnk_085D7A40: @ 085D7A40
	.incbin "fe6-base.gba", 0x5D7A40, (0x5D7A50 - 0x5D7A40) @ length: 0010

	.global gUnk_085D7A50
gUnk_085D7A50: @ 085D7A50
	.incbin "fe6-base.gba", 0x5D7A50, (0x5D8608 - 0x5D7A50) @ length: 0BB8

	.global gUnk_085D8608
gUnk_085D8608: @ 085D8608
	.incbin "fe6-base.gba", 0x5D8608, (0x5D9208 - 0x5D8608) @ length: 0C00

	.global gUnk_085D9208
gUnk_085D9208: @ 085D9208
	.incbin "fe6-base.gba", 0x5D9208, (0x5D9E38 - 0x5D9208) @ length: 0C30

	.global gUnk_085D9E38
gUnk_085D9E38: @ 085D9E38
	.incbin "fe6-base.gba", 0x5D9E38, (0x5DAA68 - 0x5D9E38) @ length: 0C30

	.global gUnk_085DAA68
gUnk_085DAA68: @ 085DAA68
	.incbin "fe6-base.gba", 0x5DAA68, (0x5DB6A4 - 0x5DAA68) @ length: 0C3C

	.global gUnk_085DB6A4
gUnk_085DB6A4: @ 085DB6A4
	.incbin "fe6-base.gba", 0x5DB6A4, (0x5DC850 - 0x5DB6A4) @ length: 11AC

	.global gUnk_085DC850
gUnk_085DC850: @ 085DC850
	.incbin "fe6-base.gba", 0x5DC850, (0x5DC954 - 0x5DC850) @ length: 0104

	.global gUnk_085DC954
gUnk_085DC954: @ 085DC954
	.incbin "fe6-base.gba", 0x5DC954, (0x5DC97C - 0x5DC954) @ length: 0028

	.global gUnk_085DC97C
gUnk_085DC97C: @ 085DC97C
	.incbin "fe6-base.gba", 0x5DC97C, (0x5DDAF0 - 0x5DC97C) @ length: 1174

	.global gUnk_085DDAF0
gUnk_085DDAF0: @ 085DDAF0
	.incbin "fe6-base.gba", 0x5DDAF0, (0x5DDBF4 - 0x5DDAF0) @ length: 0104

	.global gUnk_085DDBF4
gUnk_085DDBF4: @ 085DDBF4
	.incbin "fe6-base.gba", 0x5DDBF4, (0x5DDC1C - 0x5DDBF4) @ length: 0028

	.global gUnk_085DDC1C
gUnk_085DDC1C: @ 085DDC1C
	.incbin "fe6-base.gba", 0x5DDC1C, (0x5DEDC0 - 0x5DDC1C) @ length: 11A4

	.global gUnk_085DEDC0
gUnk_085DEDC0: @ 085DEDC0
	.incbin "fe6-base.gba", 0x5DEDC0, (0x5DEEC4 - 0x5DEDC0) @ length: 0104

	.global gUnk_085DEEC4
gUnk_085DEEC4: @ 085DEEC4
	.incbin "fe6-base.gba", 0x5DEEC4, (0x5DEEEC - 0x5DEEC4) @ length: 0028

	.global gUnk_085DEEEC
gUnk_085DEEEC: @ 085DEEEC
	.incbin "fe6-base.gba", 0x5DEEEC, (0x5E0090 - 0x5DEEEC) @ length: 11A4

	.global gUnk_085E0090
gUnk_085E0090: @ 085E0090
	.incbin "fe6-base.gba", 0x5E0090, (0x5E0194 - 0x5E0090) @ length: 0104

	.global gUnk_085E0194
gUnk_085E0194: @ 085E0194
	.incbin "fe6-base.gba", 0x5E0194, (0x5E01BC - 0x5E0194) @ length: 0028

	.global gUnk_085E01BC
gUnk_085E01BC: @ 085E01BC
	.incbin "fe6-base.gba", 0x5E01BC, (0x5E0280 - 0x5E01BC) @ length: 00C4

	.global gUnk_085E0280
gUnk_085E0280: @ 085E0280
	.incbin "fe6-base.gba", 0x5E0280, (0x5E0324 - 0x5E0280) @ length: 00A4

	.global gUnk_085E0324
gUnk_085E0324: @ 085E0324
	.incbin "fe6-base.gba", 0x5E0324, (0x5E03C8 - 0x5E0324) @ length: 00A4

	.global gUnk_085E03C8
gUnk_085E03C8: @ 085E03C8
	.incbin "fe6-base.gba", 0x5E03C8, (0x5E046C - 0x5E03C8) @ length: 00A4

	.global gUnk_085E046C
gUnk_085E046C: @ 085E046C
	.incbin "fe6-base.gba", 0x5E046C, (0x5E0510 - 0x5E046C) @ length: 00A4

	.global gUnk_085E0510
gUnk_085E0510: @ 085E0510
	.incbin "fe6-base.gba", 0x5E0510, (0x5E05B4 - 0x5E0510) @ length: 00A4

	.global gUnk_085E05B4
gUnk_085E05B4: @ 085E05B4
	.incbin "fe6-base.gba", 0x5E05B4, (0x5E0748 - 0x5E05B4) @ length: 0194

	.global gUnk_085E0748
gUnk_085E0748: @ 085E0748
	.incbin "fe6-base.gba", 0x5E0748, (0x5E08DC - 0x5E0748) @ length: 0194

	.global gUnk_085E08DC
gUnk_085E08DC: @ 085E08DC
	.incbin "fe6-base.gba", 0x5E08DC, (0x5E0A88 - 0x5E08DC) @ length: 01AC

	.global gUnk_085E0A88
gUnk_085E0A88: @ 085E0A88
	.incbin "fe6-base.gba", 0x5E0A88, (0x5E0C34 - 0x5E0A88) @ length: 01AC

	.global gUnk_085E0C34
gUnk_085E0C34: @ 085E0C34
	.incbin "fe6-base.gba", 0x5E0C34, (0x5E0DE0 - 0x5E0C34) @ length: 01AC

	.global gUnk_085E0DE0
gUnk_085E0DE0: @ 085E0DE0
	.incbin "fe6-base.gba", 0x5E0DE0, (0x5E0F88 - 0x5E0DE0) @ length: 01A8

	.global gUnk_085E0F88
gUnk_085E0F88: @ 085E0F88
	.incbin "fe6-base.gba", 0x5E0F88, (0x5E19DC - 0x5E0F88) @ length: 0A54

	.global gUnk_085E19DC
gUnk_085E19DC: @ 085E19DC
	.incbin "fe6-base.gba", 0x5E19DC, (0x5E2508 - 0x5E19DC) @ length: 0B2C

	.global gUnk_085E2508
gUnk_085E2508: @ 085E2508
	.incbin "fe6-base.gba", 0x5E2508, (0x5E2920 - 0x5E2508) @ length: 0418

	.global gUnk_085E2920
gUnk_085E2920: @ 085E2920
	.incbin "fe6-base.gba", 0x5E2920, (0x5E294C - 0x5E2920) @ length: 002C

	.global gUnk_085E294C
gUnk_085E294C: @ 085E294C
	.incbin "fe6-base.gba", 0x5E294C, (0x5E2CA8 - 0x5E294C) @ length: 035C

	.global gUnk_085E2CA8
gUnk_085E2CA8: @ 085E2CA8
	.incbin "fe6-base.gba", 0x5E2CA8, (0x5E2CD4 - 0x5E2CA8) @ length: 002C

	.global gUnk_085E2CD4
gUnk_085E2CD4: @ 085E2CD4
	.incbin "fe6-base.gba", 0x5E2CD4, (0x5E3AA4 - 0x5E2CD4) @ length: 0DD0

	.global gUnk_085E3AA4
gUnk_085E3AA4: @ 085E3AA4
	.incbin "fe6-base.gba", 0x5E3AA4, (0x5E48C4 - 0x5E3AA4) @ length: 0E20

	.global gUnk_085E48C4
gUnk_085E48C4: @ 085E48C4
	.incbin "fe6-base.gba", 0x5E48C4, (0x5E5858 - 0x5E48C4) @ length: 0F94

	.global gUnk_085E5858
gUnk_085E5858: @ 085E5858
	.incbin "fe6-base.gba", 0x5E5858, (0x5E5C10 - 0x5E5858) @ length: 03B8

	.global gUnk_085E5C10
gUnk_085E5C10: @ 085E5C10
	.incbin "fe6-base.gba", 0x5E5C10, (0x5E5C2C - 0x5E5C10) @ length: 001C

	.global gUnk_085E5C2C
gUnk_085E5C2C: @ 085E5C2C
	.incbin "fe6-base.gba", 0x5E5C2C, (0x5E5C34 - 0x5E5C2C) @ length: 0008

	.global gUnk_085E5C34
gUnk_085E5C34: @ 085E5C34
	.incbin "fe6-base.gba", 0x5E5C34, (0x5E5C3C - 0x5E5C34) @ length: 0008

	.global gUnk_085E5C3C
gUnk_085E5C3C: @ 085E5C3C
	.incbin "fe6-base.gba", 0x5E5C3C, (0x5E5C44 - 0x5E5C3C) @ length: 0008

	.global gUnk_085E5C44
gUnk_085E5C44: @ 085E5C44
	.incbin "fe6-base.gba", 0x5E5C44, (0x5E79F8 - 0x5E5C44) @ length: 1DB4

	.global gUnk_085E79F8
gUnk_085E79F8: @ 085E79F8
	.incbin "fe6-base.gba", 0x5E79F8, (0x5E7A64 - 0x5E79F8) @ length: 006C

	.global gUnk_085E7A64
gUnk_085E7A64: @ 085E7A64
	.incbin "fe6-base.gba", 0x5E7A64, (0x5E7AC4 - 0x5E7A64) @ length: 0060

	.global gUnk_085E7AC4
gUnk_085E7AC4: @ 085E7AC4
	.incbin "fe6-base.gba", 0x5E7AC4, (0x5E7ACC - 0x5E7AC4) @ length: 0008

	.global gUnk_085E7ACC
gUnk_085E7ACC: @ 085E7ACC
	.incbin "fe6-base.gba", 0x5E7ACC, (0x5E90AC - 0x5E7ACC) @ length: 15E0

	.global gUnk_085E90AC
gUnk_085E90AC: @ 085E90AC
	.incbin "fe6-base.gba", 0x5E90AC, (0x5E9160 - 0x5E90AC) @ length: 00B4

	.global gUnk_085E9160
gUnk_085E9160: @ 085E9160
	.incbin "fe6-base.gba", 0x5E9160, (0x5EA7F0 - 0x5E9160) @ length: 1690

	.global gUnk_085EA7F0
gUnk_085EA7F0: @ 085EA7F0
	.incbin "fe6-base.gba", 0x5EA7F0, (0x5EA8A4 - 0x5EA7F0) @ length: 00B4

	.global gUnk_085EA8A4
gUnk_085EA8A4: @ 085EA8A4
	.incbin "fe6-base.gba", 0x5EA8A4, (0x5EABC0 - 0x5EA8A4) @ length: 031C

	.global gUnk_085EABC0
gUnk_085EABC0: @ 085EABC0
	.incbin "fe6-base.gba", 0x5EABC0, (0x5EAC34 - 0x5EABC0) @ length: 0074

	.global gUnk_085EAC34
gUnk_085EAC34: @ 085EAC34
	.incbin "fe6-base.gba", 0x5EAC34, (0x5EADB0 - 0x5EAC34) @ length: 017C

	.global gUnk_085EADB0
gUnk_085EADB0: @ 085EADB0
	.incbin "fe6-base.gba", 0x5EADB0, (0x5EB1A8 - 0x5EADB0) @ length: 03F8

	.global gUnk_085EB1A8
gUnk_085EB1A8: @ 085EB1A8
	.incbin "fe6-base.gba", 0x5EB1A8, (0x5EB1DC - 0x5EB1A8) @ length: 0034

	.global gUnk_085EB1DC
gUnk_085EB1DC: @ 085EB1DC
	.incbin "fe6-base.gba", 0x5EB1DC, (0x5EB264 - 0x5EB1DC) @ length: 0088

	.global gUnk_085EB264
gUnk_085EB264: @ 085EB264
	.incbin "fe6-base.gba", 0x5EB264, (0x5EB83C - 0x5EB264) @ length: 05D8

	.global gUnk_085EB83C
gUnk_085EB83C: @ 085EB83C
	.incbin "fe6-base.gba", 0x5EB83C, (0x5EBF40 - 0x5EB83C) @ length: 0704

	.global gUnk_085EBF40
gUnk_085EBF40: @ 085EBF40
	.incbin "fe6-base.gba", 0x5EBF40, (0x5EBF50 - 0x5EBF40) @ length: 0010

	.global gUnk_085EBF50
gUnk_085EBF50: @ 085EBF50
	.incbin "fe6-base.gba", 0x5EBF50, (0x5EBF58 - 0x5EBF50) @ length: 0008

	.global gUnk_085EBF58
gUnk_085EBF58: @ 085EBF58
	.incbin "fe6-base.gba", 0x5EBF58, (0x5EBF60 - 0x5EBF58) @ length: 0008

	.global gUnk_085EBF60
gUnk_085EBF60: @ 085EBF60
	.incbin "fe6-base.gba", 0x5EBF60, (0x5EC478 - 0x5EBF60) @ length: 0518

	.global gUnk_085EC478
gUnk_085EC478: @ 085EC478
	.incbin "fe6-base.gba", 0x5EC478, (0x5EC630 - 0x5EC478) @ length: 01B8

	.global gUnk_085EC630
gUnk_085EC630: @ 085EC630
	.incbin "fe6-base.gba", 0x5EC630, (0x5EC938 - 0x5EC630) @ length: 0308

	.global gUnk_085EC938
gUnk_085EC938: @ 085EC938
	.incbin "fe6-base.gba", 0x5EC938, (0x5ECC34 - 0x5EC938) @ length: 02FC

	.global gUnk_085ECC34
gUnk_085ECC34: @ 085ECC34
	.incbin "fe6-base.gba", 0x5ECC34, (0x5ED8CC - 0x5ECC34) @ length: 0C98

	.global gUnk_085ED8CC
gUnk_085ED8CC: @ 085ED8CC
	.incbin "fe6-base.gba", 0x5ED8CC, (0x5ED8F8 - 0x5ED8CC) @ length: 002C

	.global gUnk_085ED8F8
gUnk_085ED8F8: @ 085ED8F8
	.incbin "fe6-base.gba", 0x5ED8F8, (0x5ED924 - 0x5ED8F8) @ length: 002C

	.global gUnk_085ED924
gUnk_085ED924: @ 085ED924
	.incbin "fe6-base.gba", 0x5ED924, (0x5EDCC8 - 0x5ED924) @ length: 03A4

	.global gUnk_085EDCC8
gUnk_085EDCC8: @ 085EDCC8
	.incbin "fe6-base.gba", 0x5EDCC8, (0x5F0A14 - 0x5EDCC8) @ length: 2D4C

	.global gUnk_085F0A14
gUnk_085F0A14: @ 085F0A14
	.incbin "fe6-base.gba", 0x5F0A14, (0x5F0AA4 - 0x5F0A14) @ length: 0090

	.global gUnk_085F0AA4
gUnk_085F0AA4: @ 085F0AA4
	.incbin "fe6-base.gba", 0x5F0AA4, (0x5F1FC0 - 0x5F0AA4) @ length: 151C

	.global gUnk_085F1FC0
gUnk_085F1FC0: @ 085F1FC0
	.incbin "fe6-base.gba", 0x5F1FC0, (0x5F2034 - 0x5F1FC0) @ length: 0074

	.global gUnk_085F2034
gUnk_085F2034: @ 085F2034
	.incbin "fe6-base.gba", 0x5F2034, (0x5F35C0 - 0x5F2034) @ length: 158C

	.global gUnk_085F35C0
gUnk_085F35C0: @ 085F35C0
	.incbin "fe6-base.gba", 0x5F35C0, (0x5F3634 - 0x5F35C0) @ length: 0074

	.global gUnk_085F3634
gUnk_085F3634: @ 085F3634
	.incbin "fe6-base.gba", 0x5F3634, (0x5F63A8 - 0x5F3634) @ length: 2D74

	.global gUnk_085F63A8
gUnk_085F63A8: @ 085F63A8
	.incbin "fe6-base.gba", 0x5F63A8, (0x5F6674 - 0x5F63A8) @ length: 02CC

	.global gUnk_085F6674
gUnk_085F6674: @ 085F6674
	.incbin "fe6-base.gba", 0x5F6674, (0x5F9358 - 0x5F6674) @ length: 2CE4

	.global gUnk_085F9358
gUnk_085F9358: @ 085F9358
	.incbin "fe6-base.gba", 0x5F9358, (0x5FE3C4 - 0x5F9358) @ length: 506C

	.global gUnk_085FE3C4
gUnk_085FE3C4: @ 085FE3C4
	.incbin "fe6-base.gba", 0x5FE3C4, (0x5FE544 - 0x5FE3C4) @ length: 0180

	.global gUnk_085FE544
gUnk_085FE544: @ 085FE544
	.incbin "fe6-base.gba", 0x5FE544, (0x5FEAF8 - 0x5FE544) @ length: 05B4

	.global gUnk_085FEAF8
gUnk_085FEAF8: @ 085FEAF8
	.incbin "fe6-base.gba", 0x5FEAF8, (0x5FEB0C - 0x5FEAF8) @ length: 0014

	.global gUnk_085FEB0C
gUnk_085FEB0C: @ 085FEB0C
	.incbin "fe6-base.gba", 0x5FEB0C, (0x5FEB20 - 0x5FEB0C) @ length: 0014

	.global gUnk_085FEB20
gUnk_085FEB20: @ 085FEB20
	.incbin "fe6-base.gba", 0x5FEB20, (0x5FEB34 - 0x5FEB20) @ length: 0014

	.global gUnk_085FEB34
gUnk_085FEB34: @ 085FEB34
	.incbin "fe6-base.gba", 0x5FEB34, (0x5FEB48 - 0x5FEB34) @ length: 0014

	.global gUnk_085FEB48
gUnk_085FEB48: @ 085FEB48
	.incbin "fe6-base.gba", 0x5FEB48, (0x5FEEBC - 0x5FEB48) @ length: 0374

	.global gUnk_085FEEBC
gUnk_085FEEBC: @ 085FEEBC
	.incbin "fe6-base.gba", 0x5FEEBC, (0x5FEEC8 - 0x5FEEBC) @ length: 000C

	.global gUnk_085FEEC8
gUnk_085FEEC8: @ 085FEEC8
	.incbin "fe6-base.gba", 0x5FEEC8, (0x5FEED4 - 0x5FEEC8) @ length: 000C

	.global gUnk_085FEED4
gUnk_085FEED4: @ 085FEED4
	.incbin "fe6-base.gba", 0x5FEED4, (0x5FEEE0 - 0x5FEED4) @ length: 000C

	.global gUnk_085FEEE0
gUnk_085FEEE0: @ 085FEEE0
	.incbin "fe6-base.gba", 0x5FEEE0, (0x5FEEEC - 0x5FEEE0) @ length: 000C

	.global gUnk_085FEEEC
gUnk_085FEEEC: @ 085FEEEC
	.incbin "fe6-base.gba", 0x5FEEEC, (0x602FAC - 0x5FEEEC) @ length: 40C0

	.global gUnk_08602FAC
gUnk_08602FAC: @ 08602FAC
	.incbin "fe6-base.gba", 0x602FAC, (0x6030FC - 0x602FAC) @ length: 0150

	.global gUnk_086030FC
gUnk_086030FC: @ 086030FC
	.incbin "fe6-base.gba", 0x6030FC, (0x603B1C - 0x6030FC) @ length: 0A20

	.global gUnk_08603B1C
gUnk_08603B1C: @ 08603B1C
	.incbin "fe6-base.gba", 0x603B1C, (0x603B24 - 0x603B1C) @ length: 0008

	.global gUnk_08603B24
gUnk_08603B24: @ 08603B24
	.incbin "fe6-base.gba", 0x603B24, (0x603B2C - 0x603B24) @ length: 0008

	.global gUnk_08603B2C
gUnk_08603B2C: @ 08603B2C
	.incbin "fe6-base.gba", 0x603B2C, (0x603B34 - 0x603B2C) @ length: 0008

	.global gUnk_08603B34
gUnk_08603B34: @ 08603B34
	.incbin "fe6-base.gba", 0x603B34, (0x603B58 - 0x603B34) @ length: 0024

	.global gUnk_08603B58
gUnk_08603B58: @ 08603B58
	.incbin "fe6-base.gba", 0x603B58, (0x603BA4 - 0x603B58) @ length: 004C

	.global gUnk_08603BA4
gUnk_08603BA4: @ 08603BA4
	.incbin "fe6-base.gba", 0x603BA4, (0x603BC0 - 0x603BA4) @ length: 001C

	.global gUnk_08603BC0
gUnk_08603BC0: @ 08603BC0
	.incbin "fe6-base.gba", 0x603BC0, (0x6046D8 - 0x603BC0) @ length: 0B18
