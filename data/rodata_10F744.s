
	.section .rodata

	.global Img_UiWindowFrame_ThemeBlue
Img_UiWindowFrame_ThemeBlue: @ 0810F744
	.incbin "fe6-base.gba", 0x10F744, (0x10FF78 - 0x10F744)

	.global Pal_UiWindowFrame_ThemeBlue
Pal_UiWindowFrame_ThemeBlue: @ 0810FF78
	.incbin "fe6-base.gba", 0x10FF78, (0x10FF98 - 0x10FF78)

	.global Pal_UiStatBar_ThemeBlue
Pal_UiStatBar_ThemeBlue: @ 0810FF98
	.incbin "fe6-base.gba", 0x10FF98, (0x10FFB8 - 0x10FF98)

	.global Img_UiWindowFrame_ThemeRed
Img_UiWindowFrame_ThemeRed: @ 0810FFB8
	.incbin "fe6-base.gba", 0x10FFB8, (0x110838 - 0x10FFB8)

	.global Pal_UiWindowFrame_ThemeRed
Pal_UiWindowFrame_ThemeRed: @ 08110838
	.incbin "fe6-base.gba", 0x110838, (0x110858 - 0x110838)

	.global Pal_UiStatBar_ThemeRed
Pal_UiStatBar_ThemeRed: @ 08110858
	.incbin "fe6-base.gba", 0x110858, (0x110878 - 0x110858)

	.global Img_UiWindowFrame_ThemeGray
Img_UiWindowFrame_ThemeGray: @ 08110878
	.incbin "fe6-base.gba", 0x110878, (0x111110 - 0x110878)

	.global Pal_UiWindowFrame_ThemeGray
Pal_UiWindowFrame_ThemeGray: @ 08111110
	.incbin "fe6-base.gba", 0x111110, (0x111130 - 0x111110)

	.global Pal_UiStatBar_ThemeGray
Pal_UiStatBar_ThemeGray: @ 08111130
	.incbin "fe6-base.gba", 0x111130, (0x111150 - 0x111130)

	.global Img_UiWindowFrame_ThemeGreen
Img_UiWindowFrame_ThemeGreen: @ 08111150
	.incbin "fe6-base.gba", 0x111150, (0x111930 - 0x111150)

	.global Pal_UiWindowFrame_ThemeGreen
Pal_UiWindowFrame_ThemeGreen: @ 08111930
	.incbin "fe6-base.gba", 0x111930, (0x111950 - 0x111930)

	.global Pal_UiStatBar_ThemeGreen
Pal_UiStatBar_ThemeGreen: @ 08111950
	.incbin "fe6-base.gba", 0x111950, (0x111970 - 0x111950)

	.global Img_UiUnitNameFrame
Img_UiUnitNameFrame: @ 08111970
	.incbin "fe6-base.gba", 0x111970, (0x111BC4 - 0x111970) @ length: 0254

	.global Pal_UiUnitNameFrame
Pal_UiUnitNameFrame: @ 08111BC4
	.incbin "fe6-base.gba", 0x111BC4, (0x111C44 - 0x111BC4) @ length: 0080

	.global gEfxNoDmgBgShakeOff
gEfxNoDmgBgShakeOff: @ 08111C44
	.incbin "fe6-base.gba", 0x111C44, (0x111C60 - 0x111C44) @ length: 001C

	.global gEfxQuakePureVec1
gEfxQuakePureVec1: @ 08111C60
	.incbin "fe6-base.gba", 0x111C60, (0x111C82 - 0x111C60) @ length: 0022

	.global gEfxQuakePureVec2
gEfxQuakePureVec2: @ 08111C82
	.incbin "fe6-base.gba", 0x111C82, (0x111CCC - 0x111C82) @ length: 004A

	.global gEfxQuakePureVec3
gEfxQuakePureVec3: @ 08111CCC
	.incbin "fe6-base.gba", 0x111CCC, (0x111D16 - 0x111CCC) @ length: 004A

	.global gEfxQuakePureVec4
gEfxQuakePureVec4: @ 08111D16
	.incbin "fe6-base.gba", 0x111D16, (0x111D60 - 0x111D16) @ length: 004A

	.global gEfxQuakePureVec5
gEfxQuakePureVec5: @ 08111D60
	.incbin "fe6-base.gba", 0x111D60, (0x111DAA - 0x111D60) @ length: 004A

	.global gEfxQuakePureVec6
gEfxQuakePureVec6: @ 08111DAA
	.incbin "fe6-base.gba", 0x111DAA, (0x111E14 - 0x111DAA) @ length: 006A

	.global gEfxQuakeVec_08111E14
gEfxQuakeVec_08111E14: @ 08111E14
	.incbin "fe6-base.gba", 0x111E14, (0x111EC6 - 0x111E14) @ length: 011C

	.global gEfxQuakePureVec7
gEfxQuakePureVec7:
	.incbin "fe6-base.gba", 0x111EC6, (0x111ED8 - 0x111EC6)

	.global gEfxQuakePureVec8
gEfxQuakePureVec8:
	.incbin "fe6-base.gba", 0x111ED8, (0x111EFA - 0x111ED8)

	.global gEfxQuakePureVec9
gEfxQuakePureVec9:
	.incbin "fe6-base.gba", 0x111EFA, (0x111f0C - 0x111EFA)

	.global gEfxQuakePureVec10
gEfxQuakePureVec10:
	.incbin "fe6-base.gba", 0x111F0C, (0x111F1E - 0x111F0C)

	.global gEfxQuakePureVec11
gEfxQuakePureVec11:
	.incbin "fe6-base.gba", 0x111F1E, (0x111F30 - 0x111F1E)

	.global gEfxQuakeVec_08111F30
gEfxQuakeVec_08111F30: @ 08111F30
	.incbin "fe6-base.gba", 0x111F30, (0x111FC6 - 0x111F30)

	.global gEfxQuakeVec_08111FC6
gEfxQuakeVec_08111FC6: @ 08111FC6
	.incbin "fe6-base.gba", 0x111FC6, (0x1120F8 - 0x111FC6) @ length: 0132

	.global gUnk_081120F8
gUnk_081120F8: @ 081120F8
	.incbin "fe6-base.gba", 0x1120F8, (0x112122 - 0x1120F8) @ length: 002A

	.global gUnk_08112122
gUnk_08112122: @ 08112122
	.incbin "fe6-base.gba", 0x112122, (0x112144 - 0x112122) @ length: 0022

	.global gUnk_08112144
gUnk_08112144: @ 08112144
	.incbin "fe6-base.gba", 0x112144, (0x112234 - 0x112144) @ length: 00F0

	.global gUnk_08112234
gUnk_08112234: @ 08112234
	.incbin "fe6-base.gba", 0x112234, (0x11223E - 0x112234) @ length: 000A

	.global gUnk_0811223E
gUnk_0811223E: @ 0811223E
	.incbin "fe6-base.gba", 0x11223E, (0x112248 - 0x11223E) @ length: 000A

	.global gUnk_08112248
gUnk_08112248: @ 08112248
	.incbin "fe6-base.gba", 0x112248, (0x112252 - 0x112248) @ length: 000A

	.global gUnk_08112252
gUnk_08112252: @ 08112252
	.incbin "fe6-base.gba", 0x112252, (0x11225C - 0x112252) @ length: 000A

	.global gUnk_0811225C
gUnk_0811225C: @ 0811225C
	.incbin "fe6-base.gba", 0x11225C, (0x112266 - 0x11225C) @ length: 000A

	.global gUnk_08112266
gUnk_08112266: @ 08112266
	.incbin "fe6-base.gba", 0x112266, (0x112270 - 0x112266) @ length: 000A

	.global gUnk_08112270
gUnk_08112270: @ 08112270
	.incbin "fe6-base.gba", 0x112270, (0x11227A - 0x112270) @ length: 000A

	.global gUnk_0811227A
gUnk_0811227A: @ 0811227A
	.incbin "fe6-base.gba", 0x11227A, (0x112284 - 0x11227A) @ length: 000A

	.global gUnk_08112284
gUnk_08112284: @ 08112284
	.incbin "fe6-base.gba", 0x112284, (0x11228E - 0x112284) @ length: 000A

	.global gUnk_0811228E
gUnk_0811228E: @ 0811228E
	.incbin "fe6-base.gba", 0x11228E, (0x112298 - 0x11228E) @ length: 000A

	.global gUnk_08112298
gUnk_08112298: @ 08112298
	.incbin "fe6-base.gba", 0x112298, (0x1122C0 - 0x112298) @ length: 0028

	.global gUnk_081122C0
gUnk_081122C0: @ 081122C0
	.incbin "fe6-base.gba", 0x1122C0, (0x1122C5 - 0x1122C0) @ length: 0005

	.global gUnk_081122C5
gUnk_081122C5: @ 081122C5
	.incbin "fe6-base.gba", 0x1122C5, (0x1122CA - 0x1122C5) @ length: 0005

	.global gUnk_081122CA
gUnk_081122CA: @ 081122CA
	.incbin "fe6-base.gba", 0x1122CA, (0x1122D0 - 0x1122CA) @ length: 0006

	.global gUnk_081122D0
gUnk_081122D0: @ 081122D0
	.incbin "fe6-base.gba", 0x1122D0, (0x1122DA - 0x1122D0) @ length: 000A

	.global gUnk_081122DA
gUnk_081122DA: @ 081122DA
	.incbin "fe6-base.gba", 0x1122DA, (0x112370 - 0x1122DA) @ length: 0096

	.global gUnk_08112370
gUnk_08112370: @ 08112370
	.incbin "fe6-base.gba", 0x112370, (0x1125E0 - 0x112370) @ length: 0270

	.global gUnk_081125E0
gUnk_081125E0: @ 081125E0
	.incbin "fe6-base.gba", 0x1125E0, (0x1127F0 - 0x1125E0) @ length: 0210

	.global gUnk_081127F0
gUnk_081127F0: @ 081127F0
	.incbin "fe6-base.gba", 0x1127F0, (0x112840 - 0x1127F0) @ length: 0050

	.global gUnk_08112840
gUnk_08112840: @ 08112840
	.incbin "fe6-base.gba", 0x112840, (0x1128AC - 0x112840) @ length: 006C

	.global gUnk_081128AC
gUnk_081128AC: @ 081128AC
	.incbin "fe6-base.gba", 0x1128AC, (0x1128FC - 0x1128AC) @ length: 0050

	.global gUnk_081128FC
gUnk_081128FC: @ 081128FC
	.incbin "fe6-base.gba", 0x1128FC, (0x112968 - 0x1128FC) @ length: 006C

	.global gUnk_08112968
gUnk_08112968: @ 08112968
	.incbin "fe6-base.gba", 0x112968, (0x112A1C - 0x112968) @ length: 00B4

	.global gUnk_08112A1C
gUnk_08112A1C: @ 08112A1C
	.incbin "fe6-base.gba", 0x112A1C, (0x112AD0 - 0x112A1C) @ length: 00B4

	.global gUnk_08112AD0
gUnk_08112AD0: @ 08112AD0
	.incbin "fe6-base.gba", 0x112AD0, (0x112BA4 - 0x112AD0) @ length: 00D4

	.global gUnk_08112BA4
gUnk_08112BA4: @ 08112BA4
	.incbin "fe6-base.gba", 0x112BA4, (0x112C84 - 0x112BA4) @ length: 00E0

	.global gUnk_08112C84
gUnk_08112C84: @ 08112C84
	.incbin "fe6-base.gba", 0x112C84, (0x112CD4 - 0x112C84) @ length: 0050

	.global gUnk_08112CD4
gUnk_08112CD4: @ 08112CD4
	.incbin "fe6-base.gba", 0x112CD4, (0x112D54 - 0x112CD4) @ length: 0080

	.global gUnk_08112D54
gUnk_08112D54: @ 08112D54
	.incbin "fe6-base.gba", 0x112D54, (0x112DF4 - 0x112D54) @ length: 00A0

	.global gUnk_08112DF4
gUnk_08112DF4: @ 08112DF4
	.incbin "fe6-base.gba", 0x112DF4, (0x113024 - 0x112DF4) @ length: 0230

	.global gUnk_08113024
gUnk_08113024: @ 08113024
	.incbin "fe6-base.gba", 0x113024, (0x1131A4 - 0x113024) @ length: 0180

	.global gUnk_081131A4
gUnk_081131A4: @ 081131A4
	.incbin "fe6-base.gba", 0x1131A4, (0x113224 - 0x1131A4) @ length: 0080

	.global Pal_08113224
Pal_08113224: @ 08113224
	.incbin "fe6-base.gba", 0x113224, (0x113424 - 0x113224) @ length: 0200

	.global gUnk_08113424
gUnk_08113424: @ 08113424
	.incbin "fe6-base.gba", 0x113424, (0x1134A4 - 0x113424) @ length: 0080

	.global gUnk_081134A4
gUnk_081134A4: @ 081134A4
	.incbin "fe6-base.gba", 0x1134A4, (0x1134C4 - 0x1134A4) @ length: 0020

	.global gUnk_081134C4
gUnk_081134C4: @ 081134C4
	.incbin "fe6-base.gba", 0x1134C4, (0x113564 - 0x1134C4) @ length: 00A0

	.global Pal_BanimUnitFlashing
Pal_BanimUnitFlashing: @ 08113564
	.incbin "fe6-base.gba", 0x113564, (0x113584 - 0x113564) @ length: 0020

	.global Img_EkrExpBar
Img_EkrExpBar: @ 08113584
	.incbin "fe6-base.gba", 0x113584, (0x113884 - 0x113584) @ length: 0300

	.global Img_EkrExpBarChange
Img_EkrExpBarChange: @ 08113884
	.incbin "fe6-base.gba", 0x113884, (0x113B84 - 0x113884) @ length: 0300

	.global Img_BarNumfx
Img_BarNumfx: @ 08113B84
	.incbin "fe6-base.gba", 0x113B84, (0x113CE4 - 0x113B84) @ length: 0160

	.global Tsa_EkrExpBar
Tsa_EkrExpBar: @ 08113CE4
	.incbin "fe6-base.gba", 0x113CE4, (0x113D50 - 0x113CE4) @ length: 006C

	.global Pal_EkrExpBar
Pal_EkrExpBar: @ 08113D50
	.incbin "fe6-base.gba", 0x113D50, (0x113D70 - 0x113D50) @ length: 0020

	.global gUnk_08113D70
gUnk_08113D70: @ 08113D70
	.incbin "fe6-base.gba", 0x113D70, (0x113F98 - 0x113D70) @ length: 0228

	.global gUnk_08113F98
gUnk_08113F98: @ 08113F98
	.incbin "fe6-base.gba", 0x113F98, (0x113FB8 - 0x113F98) @ length: 0020

	.global gUnk_08113FB8
gUnk_08113FB8: @ 08113FB8
	.incbin "fe6-base.gba", 0x113FB8, (0x113FD8 - 0x113FB8) @ length: 0020

	.global gUnk_08113FD8
gUnk_08113FD8: @ 08113FD8
	.incbin "fe6-base.gba", 0x113FD8, (0x113FF8 - 0x113FD8) @ length: 0020

	.global gUnk_08113FF8
gUnk_08113FF8: @ 08113FF8
	.incbin "fe6-base.gba", 0x113FF8, (0x11446C - 0x113FF8) @ length: 0474

	.global gUnk_0811446C
gUnk_0811446C: @ 0811446C
	.incbin "fe6-base.gba", 0x11446C, (0x11490C - 0x11446C) @ length: 04A0

	.global gUnk_0811490C
gUnk_0811490C: @ 0811490C
	.incbin "fe6-base.gba", 0x11490C, (0x114D80 - 0x11490C) @ length: 0474

	.global Img_LevelUpFrame
Img_LevelUpFrame: @ 08114D80
	.incbin "fe6-base.gba", 0x114D80, (0x114FCC - 0x114D80) @ length: 024C

	.global Tm_LevelUpFrame
Tm_LevelUpFrame: @ 08114FCC
	.incbin "fe6-base.gba", 0x114FCC, (0x1150C8 - 0x114FCC) @ length: 00FC

	.global Pal_LevelUpFrame
Pal_LevelUpFrame: @ 081150C8
	.incbin "fe6-base.gba", 0x1150C8, (0x1150E8 - 0x1150C8) @ length: 0020

	.global gUnk_081150E8
gUnk_081150E8: @ 081150E8
	.incbin "fe6-base.gba", 0x1150E8, (0x1152FC - 0x1150E8) @ length: 0214

	.global gUnk_081152FC
gUnk_081152FC: @ 081152FC
	.incbin "fe6-base.gba", 0x1152FC, (0x11531C - 0x1152FC) @ length: 0020

	.global gUnk_0811531C
gUnk_0811531C: @ 0811531C
	.incbin "fe6-base.gba", 0x11531C, (0x115378 - 0x11531C) @ length: 005C

	.global gUnk_08115378
gUnk_08115378: @ 08115378
	.incbin "fe6-base.gba", 0x115378, (0x115478 - 0x115378) @ length: 0100

	.global gUnk_08115478
gUnk_08115478: @ 08115478
	.incbin "fe6-base.gba", 0x115478, (0x115498 - 0x115478) @ length: 0020

	.global gUnk_08115498
gUnk_08115498: @ 08115498
	.incbin "fe6-base.gba", 0x115498, (0x115524 - 0x115498) @ length: 008C

	.global gUnk_08115524
gUnk_08115524: @ 08115524
	.incbin "fe6-base.gba", 0x115524, (0x117B90 - 0x115524) @ length: 266C

	.global gUnk_08117B90
gUnk_08117B90: @ 08117B90
	.incbin "fe6-base.gba", 0x117B90, (0x118330 - 0x117B90) @ length: 07A0

	.global gUnk_08118330
gUnk_08118330: @ 08118330
	.incbin "fe6-base.gba", 0x118330, (0x119CD8 - 0x118330) @ length: 19A8

	.global gUnk_08119CD8
gUnk_08119CD8: @ 08119CD8
	.incbin "fe6-base.gba", 0x119CD8, (0x119CDC - 0x119CD8) @ length: 0004

	.global gUnk_08119CDC
gUnk_08119CDC: @ 08119CDC
	.incbin "fe6-base.gba", 0x119CDC, (0x119D56 - 0x119CDC) @ length: 007A

	.global gUnk_08119D56
gUnk_08119D56: @ 08119D56
	.incbin "fe6-base.gba", 0x119D56, (0x119D78 - 0x119D56) @ length: 0022

	.global gUnk_08119D78
gUnk_08119D78: @ 08119D78
	.incbin "fe6-base.gba", 0x119D78, (0x119DEA - 0x119D78) @ length: 0072

	.global gUnk_08119DEA
gUnk_08119DEA: @ 08119DEA
	.incbin "fe6-base.gba", 0x119DEA, (0x119E30 - 0x119DEA) @ length: 0046

	.global gUnk_08119E30
gUnk_08119E30: @ 08119E30
	.incbin "fe6-base.gba", 0x119E30, (0x119ED2 - 0x119E30) @ length: 00A2

	.global gUnk_08119ED2
gUnk_08119ED2: @ 08119ED2
	.incbin "fe6-base.gba", 0x119ED2, (0x119EDC - 0x119ED2) @ length: 000A

	.global gUnk_08119EDC
gUnk_08119EDC: @ 08119EDC
	.incbin "fe6-base.gba", 0x119EDC, (0x119F1E - 0x119EDC) @ length: 0042

	.global gUnk_08119F1E
gUnk_08119F1E: @ 08119F1E
	.incbin "fe6-base.gba", 0x119F1E, (0x119F50 - 0x119F1E) @ length: 0032

	.global gUnk_08119F50
gUnk_08119F50: @ 08119F50
	.incbin "fe6-base.gba", 0x119F50, (0x119FA6 - 0x119F50) @ length: 0056

	.global gUnk_08119FA6
gUnk_08119FA6: @ 08119FA6
	.incbin "fe6-base.gba", 0x119FA6, (0x119FFC - 0x119FA6) @ length: 0056

	.global gUnk_08119FFC
gUnk_08119FFC: @ 08119FFC
	.incbin "fe6-base.gba", 0x119FFC, (0x11A06A - 0x119FFC) @ length: 006E

	.global gUnk_0811A06A
gUnk_0811A06A: @ 0811A06A
	.incbin "fe6-base.gba", 0x11A06A, (0x11A098 - 0x11A06A) @ length: 002E

	.global gUnk_0811A098
gUnk_0811A098: @ 0811A098
	.incbin "fe6-base.gba", 0x11A098, (0x11A0DE - 0x11A098) @ length: 0046

	.global gUnk_0811A0DE
gUnk_0811A0DE: @ 0811A0DE
	.incbin "fe6-base.gba", 0x11A0DE, (0x11A0E8 - 0x11A0DE) @ length: 000A

	.global gUnk_0811A0E8
gUnk_0811A0E8: @ 0811A0E8
	.incbin "fe6-base.gba", 0x11A0E8, (0x11A102 - 0x11A0E8) @ length: 001A

	.global gUnk_0811A102
gUnk_0811A102: @ 0811A102
	.incbin "fe6-base.gba", 0x11A102, (0x11A134 - 0x11A102) @ length: 0032

	.global gUnk_0811A134
gUnk_0811A134: @ 0811A134
	.incbin "fe6-base.gba", 0x11A134, (0x11A1AA - 0x11A134) @ length: 0076

	.global gUnk_0811A1AA
gUnk_0811A1AA: @ 0811A1AA
	.incbin "fe6-base.gba", 0x11A1AA, (0x11A218 - 0x11A1AA) @ length: 006E

	.global gUnk_0811A218
gUnk_0811A218: @ 0811A218
	.incbin "fe6-base.gba", 0x11A218, (0x11A276 - 0x11A218) @ length: 005E

	.global gUnk_0811A276
gUnk_0811A276: @ 0811A276
	.incbin "fe6-base.gba", 0x11A276, (0x11A27C - 0x11A276) @ length: 0006

	.global gUnk_0811A27C
gUnk_0811A27C: @ 0811A27C
	.incbin "fe6-base.gba", 0x11A27C, (0x11A302 - 0x11A27C) @ length: 0086

	.global gUnk_0811A302
gUnk_0811A302: @ 0811A302
	.incbin "fe6-base.gba", 0x11A302, (0x11A478 - 0x11A302) @ length: 0176

	.global gUnk_0811A478
gUnk_0811A478: @ 0811A478
	.incbin "fe6-base.gba", 0x11A478, (0x11A50E - 0x11A478) @ length: 0096

	.global gUnk_0811A50E
gUnk_0811A50E: @ 0811A50E
	.incbin "fe6-base.gba", 0x11A50E, (0x11A520 - 0x11A50E) @ length: 0012

	.global gUnk_0811A520
gUnk_0811A520: @ 0811A520
	.incbin "fe6-base.gba", 0x11A520, (0x11A530 - 0x11A520) @ length: 0010

	.global gUnk_0811A530
gUnk_0811A530: @ 0811A530
	.incbin "fe6-base.gba", 0x11A530, (0x11A59E - 0x11A530) @ length: 006E

	.global gUnk_0811A59E
gUnk_0811A59E: @ 0811A59E
	.incbin "fe6-base.gba", 0x11A59E, (0x11A5AC - 0x11A59E) @ length: 000E

	.global gUnk_0811A5AC
gUnk_0811A5AC: @ 0811A5AC
	.incbin "fe6-base.gba", 0x11A5AC, (0x11A602 - 0x11A5AC) @ length: 0056

	.global gUnk_0811A602
gUnk_0811A602: @ 0811A602
	.incbin "fe6-base.gba", 0x11A602, (0x11A618 - 0x11A602) @ length: 0016

	.global gUnk_0811A618
gUnk_0811A618: @ 0811A618
	.incbin "fe6-base.gba", 0x11A618, (0x11A62A - 0x11A618) @ length: 0012

	.global gUnk_0811A62A
gUnk_0811A62A: @ 0811A62A
	.incbin "fe6-base.gba", 0x11A62A, (0x11A668 - 0x11A62A) @ length: 003E

	.global gUnk_0811A668
gUnk_0811A668: @ 0811A668
	.incbin "fe6-base.gba", 0x11A668, (0x11A67A - 0x11A668) @ length: 0012

	.global gUnk_0811A67A
gUnk_0811A67A: @ 0811A67A
	.incbin "fe6-base.gba", 0x11A67A, (0x11A680 - 0x11A67A) @ length: 0006

	.global gUnk_0811A680
gUnk_0811A680: @ 0811A680
	.incbin "fe6-base.gba", 0x11A680, (0x11A722 - 0x11A680) @ length: 00A2

	.global gUnk_0811A722
gUnk_0811A722: @ 0811A722
	.incbin "fe6-base.gba", 0x11A722, (0x11A758 - 0x11A722) @ length: 0036

	.global gUnk_0811A758
gUnk_0811A758: @ 0811A758
	.incbin "fe6-base.gba", 0x11A758, (0x11A796 - 0x11A758) @ length: 003E

	.global gUnk_0811A796
gUnk_0811A796: @ 0811A796
	.incbin "fe6-base.gba", 0x11A796, (0x11A898 - 0x11A796) @ length: 0102

	.global gUnk_0811A898
gUnk_0811A898: @ 0811A898
	.incbin "fe6-base.gba", 0x11A898, (0x11A89E - 0x11A898) @ length: 0006

	.global gUnk_0811A89E
gUnk_0811A89E: @ 0811A89E
	.incbin "fe6-base.gba", 0x11A89E, (0x11A8A4 - 0x11A89E) @ length: 0006

	.global gUnk_0811A8A4
gUnk_0811A8A4: @ 0811A8A4
	.incbin "fe6-base.gba", 0x11A8A4, (0x11A8AA - 0x11A8A4) @ length: 0006

	.global gUnk_0811A8AA
gUnk_0811A8AA: @ 0811A8AA
	.incbin "fe6-base.gba", 0x11A8AA, (0x11A8B0 - 0x11A8AA) @ length: 0006

	.global gUnk_0811A8B0
gUnk_0811A8B0: @ 0811A8B0
	.incbin "fe6-base.gba", 0x11A8B0, (0x11A8F2 - 0x11A8B0) @ length: 0042

	.global gUnk_0811A8F2
gUnk_0811A8F2: @ 0811A8F2
	.incbin "fe6-base.gba", 0x11A8F2, (0x11A934 - 0x11A8F2) @ length: 0042

	.global gUnk_0811A934
gUnk_0811A934: @ 0811A934
	.incbin "fe6-base.gba", 0x11A934, (0x11A966 - 0x11A934) @ length: 0032

	.global gUnk_0811A966
gUnk_0811A966: @ 0811A966
	.incbin "fe6-base.gba", 0x11A966, (0x11A9A8 - 0x11A966) @ length: 0042

	.global gUnk_0811A9A8
gUnk_0811A9A8: @ 0811A9A8
	.incbin "fe6-base.gba", 0x11A9A8, (0x11A9BA - 0x11A9A8) @ length: 0012

	.global gUnk_0811A9BA
gUnk_0811A9BA: @ 0811A9BA
	.incbin "fe6-base.gba", 0x11A9BA, (0x11A9C2 - 0x11A9BA) @ length: 0008

	.global gUnk_0811A9C2
gUnk_0811A9C2: @ 0811A9C2
	.incbin "fe6-base.gba", 0x11A9C2, (0x11A9CA - 0x11A9C2) @ length: 0008

	.global gUnk_0811A9CA
gUnk_0811A9CA: @ 0811A9CA
	.incbin "fe6-base.gba", 0x11A9CA, (0x11AACC - 0x11A9CA) @ length: 0102

	.global gUnk_0811AACC
gUnk_0811AACC: @ 0811AACC
	.incbin "fe6-base.gba", 0x11AACC, (0x11AAD2 - 0x11AACC) @ length: 0006

	.global gUnk_0811AAD2
gUnk_0811AAD2: @ 0811AAD2
	.incbin "fe6-base.gba", 0x11AAD2, (0x11ABB0 - 0x11AAD2) @ length: 00DE

	.global gUnk_0811ABB0
gUnk_0811ABB0: @ 0811ABB0
	.incbin "fe6-base.gba", 0x11ABB0, (0x11ABE6 - 0x11ABB0) @ length: 0036

	.global gUnk_0811ABE6
gUnk_0811ABE6: @ 0811ABE6
	.incbin "fe6-base.gba", 0x11ABE6, (0x11AC30 - 0x11ABE6) @ length: 004A

	.global gUnk_0811AC30
gUnk_0811AC30: @ 0811AC30
	.incbin "fe6-base.gba", 0x11AC30, (0x11AD32 - 0x11AC30) @ length: 0102

	.global gUnk_0811AD32
gUnk_0811AD32: @ 0811AD32
	.incbin "fe6-base.gba", 0x11AD32, (0x11AD68 - 0x11AD32) @ length: 0036

	.global gUnk_0811AD68
gUnk_0811AD68: @ 0811AD68
	.incbin "fe6-base.gba", 0x11AD68, (0x11AE34 - 0x11AD68) @ length: 00CC

	.global gUnk_0811AE34
gUnk_0811AE34: @ 0811AE34
	.incbin "fe6-base.gba", 0x11AE34, (0x11AE76 - 0x11AE34) @ length: 0042

	.global gUnk_0811AE76
gUnk_0811AE76: @ 0811AE76
	.incbin "fe6-base.gba", 0x11AE76, (0x11AEA0 - 0x11AE76) @ length: 002A

	.global gUnk_0811AEA0
gUnk_0811AEA0: @ 0811AEA0
	.incbin "fe6-base.gba", 0x11AEA0, (0x11AEB6 - 0x11AEA0) @ length: 0016

	.global gUnk_0811AEB6
gUnk_0811AEB6: @ 0811AEB6
	.incbin "fe6-base.gba", 0x11AEB6, (0x11AEBC - 0x11AEB6) @ length: 0006

	.global gUnk_0811AEBC
gUnk_0811AEBC: @ 0811AEBC
	.incbin "fe6-base.gba", 0x11AEBC, (0x11AEDE - 0x11AEBC) @ length: 0022

	.global gUnk_0811AEDE
gUnk_0811AEDE: @ 0811AEDE
	.incbin "fe6-base.gba", 0x11AEDE, (0x11AF00 - 0x11AEDE) @ length: 0022

	.global gUnk_0811AF00
gUnk_0811AF00: @ 0811AF00
	.incbin "fe6-base.gba", 0x11AF00, (0x11AF20 - 0x11AF00) @ length: 0020

	.global gUnk_0811AF20
gUnk_0811AF20: @ 0811AF20
	.incbin "fe6-base.gba", 0x11AF20, (0x11AF52 - 0x11AF20) @ length: 0032

	.global gUnk_0811AF52
gUnk_0811AF52: @ 0811AF52
	.incbin "fe6-base.gba", 0x11AF52, (0x11AF5C - 0x11AF52) @ length: 000A

	.global gUnk_0811AF5C
gUnk_0811AF5C: @ 0811AF5C
	.incbin "fe6-base.gba", 0x11AF5C, (0x11AF9E - 0x11AF5C) @ length: 0042

	.global gUnk_0811AF9E
gUnk_0811AF9E: @ 0811AF9E
	.incbin "fe6-base.gba", 0x11AF9E, (0x11AFA4 - 0x11AF9E) @ length: 0006

	.global gUnk_0811AFA4
gUnk_0811AFA4: @ 0811AFA4
	.incbin "fe6-base.gba", 0x11AFA4, (0x11AFE8 - 0x11AFA4) @ length: 0044

	.global gUnk_0811AFE8
gUnk_0811AFE8: @ 0811AFE8
	.incbin "fe6-base.gba", 0x11AFE8, (0x11B3E8 - 0x11AFE8) @ length: 0400

	.global gUnk_0811B3E8
gUnk_0811B3E8: @ 0811B3E8
	.incbin "fe6-base.gba", 0x11B3E8, (0x11B408 - 0x11B3E8) @ length: 0020

	.global gUnk_0811B408
gUnk_0811B408: @ 0811B408
	.incbin "fe6-base.gba", 0x11B408, (0x11B444 - 0x11B408) @ length: 003C

	.global gUnk_0811B444
gUnk_0811B444: @ 0811B444
	.incbin "fe6-base.gba", 0x11B444, (0x11B674 - 0x11B444) @ length: 0230

	.global gUnk_0811B674
gUnk_0811B674: @ 0811B674
	.incbin "fe6-base.gba", 0x11B674, (0x11B694 - 0x11B674) @ length: 0020

	.global gUnk_0811B694
gUnk_0811B694: @ 0811B694
	.incbin "fe6-base.gba", 0x11B694, (0x11B8B0 - 0x11B694) @ length: 021C

	.global gUnk_0811B8B0
gUnk_0811B8B0: @ 0811B8B0
	.incbin "fe6-base.gba", 0x11B8B0, (0x11B8D0 - 0x11B8B0) @ length: 0020

	.global gUnk_0811B8D0
gUnk_0811B8D0: @ 0811B8D0
	.incbin "fe6-base.gba", 0x11B8D0, (0x11BAE8 - 0x11B8D0) @ length: 0218

	.global gUnk_0811BAE8
gUnk_0811BAE8: @ 0811BAE8
	.incbin "fe6-base.gba", 0x11BAE8, (0x11BB08 - 0x11BAE8) @ length: 0020

	.global gUnk_0811BB08
gUnk_0811BB08: @ 0811BB08
	.incbin "fe6-base.gba", 0x11BB08, (0x11BD24 - 0x11BB08) @ length: 021C

	.global gUnk_0811BD24
gUnk_0811BD24: @ 0811BD24
	.incbin "fe6-base.gba", 0x11BD24, (0x11BD44 - 0x11BD24) @ length: 0020

	.global gUnk_0811BD44
gUnk_0811BD44: @ 0811BD44
	.incbin "fe6-base.gba", 0x11BD44, (0x11BF70 - 0x11BD44) @ length: 022C

	.global gUnk_0811BF70
gUnk_0811BF70: @ 0811BF70
	.incbin "fe6-base.gba", 0x11BF70, (0x11BF90 - 0x11BF70) @ length: 0020

	.global gUnk_0811BF90
gUnk_0811BF90: @ 0811BF90
	.incbin "fe6-base.gba", 0x11BF90, (0x11C1D8 - 0x11BF90) @ length: 0248

	.global gUnk_0811C1D8
gUnk_0811C1D8: @ 0811C1D8
	.incbin "fe6-base.gba", 0x11C1D8, (0x11C1F8 - 0x11C1D8) @ length: 0020

	.global gUnk_0811C1F8
gUnk_0811C1F8: @ 0811C1F8
	.incbin "fe6-base.gba", 0x11C1F8, (0x11C430 - 0x11C1F8) @ length: 0238

	.global gUnk_0811C430
gUnk_0811C430: @ 0811C430
	.incbin "fe6-base.gba", 0x11C430, (0x11C450 - 0x11C430) @ length: 0020

	.global gUnk_0811C450
gUnk_0811C450: @ 0811C450
	.incbin "fe6-base.gba", 0x11C450, (0x11C6B4 - 0x11C450) @ length: 0264

	.global gUnk_0811C6B4
gUnk_0811C6B4: @ 0811C6B4
	.incbin "fe6-base.gba", 0x11C6B4, (0x11C6D4 - 0x11C6B4) @ length: 0020

	.global gUnk_0811C6D4
gUnk_0811C6D4: @ 0811C6D4
	.incbin "fe6-base.gba", 0x11C6D4, (0x11C944 - 0x11C6D4) @ length: 0270

	.global gUnk_0811C944
gUnk_0811C944: @ 0811C944
	.incbin "fe6-base.gba", 0x11C944, (0x11C964 - 0x11C944) @ length: 0020

	.global gUnk_0811C964
gUnk_0811C964: @ 0811C964
	.incbin "fe6-base.gba", 0x11C964, (0x11CAD8 - 0x11C964) @ length: 0174

	.global gUnk_0811CAD8
gUnk_0811CAD8: @ 0811CAD8
	.incbin "fe6-base.gba", 0x11CAD8, (0x11CAF8 - 0x11CAD8) @ length: 0020

	.global gUnk_0811CAF8
gUnk_0811CAF8: @ 0811CAF8
	.incbin "fe6-base.gba", 0x11CAF8, (0x11CD14 - 0x11CAF8) @ length: 021C

	.global gUnk_0811CD14
gUnk_0811CD14: @ 0811CD14
	.incbin "fe6-base.gba", 0x11CD14, (0x11D0D4 - 0x11CD14) @ length: 03C0

	.global gUnk_0811D0D4
gUnk_0811D0D4: @ 0811D0D4
	.incbin "fe6-base.gba", 0x11D0D4, (0x11E36C - 0x11D0D4) @ length: 1298

	.global gUnk_0811E36C
gUnk_0811E36C: @ 0811E36C
	.incbin "fe6-base.gba", 0x11E36C, (0x11F22C - 0x11E36C) @ length: 0EC0

	.global gUnk_0811F22C
gUnk_0811F22C: @ 0811F22C
	.incbin "fe6-base.gba", 0x11F22C, (0x11F32C - 0x11F22C) @ length: 0100

	.global gUnk_0811F32C
gUnk_0811F32C: @ 0811F32C
	.incbin "fe6-base.gba", 0x11F32C, (0x11F6F4 - 0x11F32C) @ length: 03C8

	.global gUnk_0811F6F4
gUnk_0811F6F4: @ 0811F6F4
	.incbin "fe6-base.gba", 0x11F6F4, (0x1203F4 - 0x11F6F4) @ length: 0D00

	.global gUnk_081203F4
gUnk_081203F4: @ 081203F4
	.incbin "fe6-base.gba", 0x1203F4, (0x120414 - 0x1203F4) @ length: 0020

	.global gUnk_08120414
gUnk_08120414: @ 08120414
	.incbin "fe6-base.gba", 0x120414, (0x120CB4 - 0x120414) @ length: 08A0

	.global gUnk_08120CB4
gUnk_08120CB4: @ 08120CB4
	.incbin "fe6-base.gba", 0x120CB4, (0x121498 - 0x120CB4) @ length: 07E4

	.global gUnk_08121498
gUnk_08121498: @ 08121498
	.incbin "fe6-base.gba", 0x121498, (0x1214B8 - 0x121498) @ length: 0020

	.global gUnk_081214B8
gUnk_081214B8: @ 081214B8
	.incbin "fe6-base.gba", 0x1214B8, (0x1214D8 - 0x1214B8) @ length: 0020

	.global gUnk_081214D8
gUnk_081214D8: @ 081214D8
	.incbin "fe6-base.gba", 0x1214D8, (0x1214F8 - 0x1214D8) @ length: 0020

	.global gUnk_081214F8
gUnk_081214F8: @ 081214F8
	.incbin "fe6-base.gba", 0x1214F8, (0x122A3C - 0x1214F8) @ length: 1544

	.global gUnk_08122A3C
gUnk_08122A3C: @ 08122A3C
	.incbin "fe6-base.gba", 0x122A3C, (0x123B1C - 0x122A3C) @ length: 10E0

	.global gUnk_08123B1C
gUnk_08123B1C: @ 08123B1C
	.incbin "fe6-base.gba", 0x123B1C, (0x123D1C - 0x123B1C) @ length: 0200

	.global gUnk_08123D1C
gUnk_08123D1C: @ 08123D1C
	.incbin "fe6-base.gba", 0x123D1C, (0x1241BC - 0x123D1C) @ length: 04A0

	.global gUnk_081241BC
gUnk_081241BC: @ 081241BC
	.incbin "fe6-base.gba", 0x1241BC, (0x124618 - 0x1241BC) @ length: 045C

	.global gUnk_08124618
gUnk_08124618: @ 08124618
	.incbin "fe6-base.gba", 0x124618, (0x1246D8 - 0x124618) @ length: 00C0

	.global gUnk_081246D8
gUnk_081246D8: @ 081246D8
	.incbin "fe6-base.gba", 0x1246D8, (0x1246F8 - 0x1246D8) @ length: 0020

	.global gUnk_081246F8
gUnk_081246F8: @ 081246F8
	.incbin "fe6-base.gba", 0x1246F8, (0x12479C - 0x1246F8) @ length: 00A4

	.global gUnk_0812479C
gUnk_0812479C: @ 0812479C
	.incbin "fe6-base.gba", 0x12479C, (0x124B64 - 0x12479C) @ length: 03C8

	.global gUnk_08124B64
gUnk_08124B64: @ 08124B64
	.incbin "fe6-base.gba", 0x124B64, (0x127778 - 0x124B64) @ length: 2C14

	.global gUnk_08127778
gUnk_08127778: @ 08127778
	.incbin "fe6-base.gba", 0x127778, (0x129504 - 0x127778) @ length: 1D8C

	.global gUnk_08129504
gUnk_08129504: @ 08129504
	.incbin "fe6-base.gba", 0x129504, (0x12A258 - 0x129504) @ length: 0D54

	.global gUnk_0812A258
gUnk_0812A258: @ 0812A258
	.incbin "fe6-base.gba", 0x12A258, (0x12B19C - 0x12A258) @ length: 0F44

	.global gUnk_0812B19C
gUnk_0812B19C: @ 0812B19C
	.incbin "fe6-base.gba", 0x12B19C, (0x12BE10 - 0x12B19C) @ length: 0C74

	.global gUnk_0812BE10
gUnk_0812BE10: @ 0812BE10
	.incbin "fe6-base.gba", 0x12BE10, (0x12C1BC - 0x12BE10) @ length: 03AC

	.global gUnk_0812C1BC
gUnk_0812C1BC: @ 0812C1BC
	.incbin "fe6-base.gba", 0x12C1BC, (0x12C62C - 0x12C1BC) @ length: 0470

	.global gUnk_0812C62C
gUnk_0812C62C: @ 0812C62C
	.incbin "fe6-base.gba", 0x12C62C, (0x12C64C - 0x12C62C) @ length: 0020

	.global gUnk_0812C64C
gUnk_0812C64C: @ 0812C64C
	.incbin "fe6-base.gba", 0x12C64C, (0x12C66C - 0x12C64C) @ length: 0020

	.global gUnk_0812C66C
gUnk_0812C66C: @ 0812C66C
	.incbin "fe6-base.gba", 0x12C66C, (0x12C68C - 0x12C66C) @ length: 0020

	.global gUnk_0812C68C
gUnk_0812C68C: @ 0812C68C
	.incbin "fe6-base.gba", 0x12C68C, (0x12CF48 - 0x12C68C) @ length: 08BC

	.global gUnk_0812CF48
gUnk_0812CF48: @ 0812CF48
	.incbin "fe6-base.gba", 0x12CF48, (0x12D374 - 0x12CF48) @ length: 042C

	.global gUnk_0812D374
gUnk_0812D374: @ 0812D374
	.incbin "fe6-base.gba", 0x12D374, (0x12D80C - 0x12D374) @ length: 0498

	.global gUnk_0812D80C
gUnk_0812D80C: @ 0812D80C
	.incbin "fe6-base.gba", 0x12D80C, (0x12D8AC - 0x12D80C) @ length: 00A0

	.global gUnk_0812D8AC
gUnk_0812D8AC: @ 0812D8AC
	.incbin "fe6-base.gba", 0x12D8AC, (0x12E4A4 - 0x12D8AC) @ length: 0BF8

	.global gUnk_0812E4A4
gUnk_0812E4A4: @ 0812E4A4
	.incbin "fe6-base.gba", 0x12E4A4, (0x12F9DC - 0x12E4A4) @ length: 1538

	.global gUnk_0812F9DC
gUnk_0812F9DC: @ 0812F9DC
	.incbin "fe6-base.gba", 0x12F9DC, (0x12FFD8 - 0x12F9DC) @ length: 05FC

	.global gUnk_0812FFD8
gUnk_0812FFD8: @ 0812FFD8
	.incbin "fe6-base.gba", 0x12FFD8, (0x138BF0 - 0x12FFD8) @ length: 8C18

	.global gUnk_08138BF0
gUnk_08138BF0: @ 08138BF0
	.incbin "fe6-base.gba", 0x138BF0, (0x13A6F8 - 0x138BF0) @ length: 1B08

	.global gUnk_0813A6F8
gUnk_0813A6F8: @ 0813A6F8
	.incbin "fe6-base.gba", 0x13A6F8, (0x13B6B4 - 0x13A6F8) @ length: 0FBC

	.global gUnk_0813B6B4
gUnk_0813B6B4: @ 0813B6B4
	.incbin "fe6-base.gba", 0x13B6B4, (0x13B8B4 - 0x13B6B4) @ length: 0200

	.global gUnk_0813B8B4
gUnk_0813B8B4: @ 0813B8B4
	.incbin "fe6-base.gba", 0x13B8B4, (0x13BA64 - 0x13B8B4) @ length: 01B0

	.global gUnk_0813BA64
gUnk_0813BA64: @ 0813BA64
	.incbin "fe6-base.gba", 0x13BA64, (0x13BAFC - 0x13BA64) @ length: 0098

	.global gUnk_0813BAFC
gUnk_0813BAFC: @ 0813BAFC
	.incbin "fe6-base.gba", 0x13BAFC, (0x13BD74 - 0x13BAFC) @ length: 0278

	.global gUnk_0813BD74
gUnk_0813BD74: @ 0813BD74
	.incbin "fe6-base.gba", 0x13BD74, (0x13E75C - 0x13BD74) @ length: 29E8

	.global gUnk_0813E75C
gUnk_0813E75C: @ 0813E75C
	.incbin "fe6-base.gba", 0x13E75C, (0x1408CC - 0x13E75C) @ length: 2170

	.global gUnk_081408CC
gUnk_081408CC: @ 081408CC
	.incbin "fe6-base.gba", 0x1408CC, (0x141320 - 0x1408CC) @ length: 0A54

	.global gUnk_08141320
gUnk_08141320: @ 08141320
	.incbin "fe6-base.gba", 0x141320, (0x142EAC - 0x141320) @ length: 1B8C

	.global gUnk_08142EAC
gUnk_08142EAC: @ 08142EAC
	.incbin "fe6-base.gba", 0x142EAC, (0x143A38 - 0x142EAC) @ length: 0B8C

	.global gUnk_08143A38
gUnk_08143A38: @ 08143A38
	.incbin "fe6-base.gba", 0x143A38, (0x143A58 - 0x143A38) @ length: 0020

	.global gUnk_08143A58
gUnk_08143A58: @ 08143A58
	.incbin "fe6-base.gba", 0x143A58, (0x143A78 - 0x143A58) @ length: 0020

	.global gUnk_08143A78
gUnk_08143A78: @ 08143A78
	.incbin "fe6-base.gba", 0x143A78, (0x143A98 - 0x143A78) @ length: 0020

	.global gUnk_08143A98
gUnk_08143A98: @ 08143A98
	.incbin "fe6-base.gba", 0x143A98, (0x143AB8 - 0x143A98) @ length: 0020

	.global gUnk_08143AB8
gUnk_08143AB8: @ 08143AB8
	.incbin "fe6-base.gba", 0x143AB8, (0x143DA8 - 0x143AB8) @ length: 02F0

	.global gUnk_08143DA8
gUnk_08143DA8: @ 08143DA8
	.incbin "fe6-base.gba", 0x143DA8, (0x143EE4 - 0x143DA8) @ length: 013C

	.global gUnk_08143EE4
gUnk_08143EE4: @ 08143EE4
	.incbin "fe6-base.gba", 0x143EE4, (0x144A00 - 0x143EE4) @ length: 0B1C

	.global gUnk_08144A00
gUnk_08144A00: @ 08144A00
	.incbin "fe6-base.gba", 0x144A00, (0x14A498 - 0x144A00) @ length: 5A98

	.global gUnk_0814A498
gUnk_0814A498: @ 0814A498
	.incbin "fe6-base.gba", 0x14A498, (0x1521C0 - 0x14A498) @ length: 7D28

	.global gUnk_081521C0
gUnk_081521C0: @ 081521C0
	.incbin "fe6-base.gba", 0x1521C0, (0x152E78 - 0x1521C0) @ length: 0CB8

	.global gUnk_08152E78
gUnk_08152E78: @ 08152E78
	.incbin "fe6-base.gba", 0x152E78, (0x159D98 - 0x152E78) @ length: 6F20

	.global gUnk_08159D98
gUnk_08159D98: @ 08159D98
	.incbin "fe6-base.gba", 0x159D98, (0x15B364 - 0x159D98) @ length: 15CC

	.global gUnk_0815B364
gUnk_0815B364: @ 0815B364
	.incbin "fe6-base.gba", 0x15B364, (0x15B910 - 0x15B364) @ length: 05AC

	.global gUnk_0815B910
gUnk_0815B910: @ 0815B910
	.incbin "fe6-base.gba", 0x15B910, (0x15BED4 - 0x15B910) @ length: 05C4

	.global gUnk_0815BED4
gUnk_0815BED4: @ 0815BED4
	.incbin "fe6-base.gba", 0x15BED4, (0x15F880 - 0x15BED4) @ length: 39AC

	.global gUnk_0815F880
gUnk_0815F880: @ 0815F880
	.incbin "fe6-base.gba", 0x15F880, (0x15F8A0 - 0x15F880) @ length: 0020

	.global gUnk_0815F8A0
gUnk_0815F8A0: @ 0815F8A0
	.incbin "fe6-base.gba", 0x15F8A0, (0x161DDC - 0x15F8A0) @ length: 253C

	.global gUnk_08161DDC
gUnk_08161DDC: @ 08161DDC
	.incbin "fe6-base.gba", 0x161DDC, (0x1621DC - 0x161DDC) @ length: 0400

	.global gUnk_081621DC
gUnk_081621DC: @ 081621DC
	.incbin "fe6-base.gba", 0x1621DC, (0x16261C - 0x1621DC) @ length: 0440

	.global gUnk_0816261C
gUnk_0816261C: @ 0816261C
	.incbin "fe6-base.gba", 0x16261C, (0x1629D4 - 0x16261C) @ length: 03B8

	.global gUnk_081629D4
gUnk_081629D4: @ 081629D4
	.incbin "fe6-base.gba", 0x1629D4, (0x16B328 - 0x1629D4) @ length: 8954

	.global gUnk_0816B328
gUnk_0816B328: @ 0816B328
	.incbin "fe6-base.gba", 0x16B328, (0x176A4C - 0x16B328) @ length: B724

	.global gUnk_08176A4C
gUnk_08176A4C: @ 08176A4C
	.incbin "fe6-base.gba", 0x176A4C, (0x176A6C - 0x176A4C) @ length: 0020

	.global gUnk_08176A6C
gUnk_08176A6C: @ 08176A6C
	.incbin "fe6-base.gba", 0x176A6C, (0x17AAC0 - 0x176A6C) @ length: 4054

	.global gUnk_0817AAC0
gUnk_0817AAC0: @ 0817AAC0
	.incbin "fe6-base.gba", 0x17AAC0, (0x17AC2C - 0x17AAC0) @ length: 016C

	.global gUnk_0817AC2C
gUnk_0817AC2C: @ 0817AC2C
	.incbin "fe6-base.gba", 0x17AC2C, (0x17AC4C - 0x17AC2C) @ length: 0020

	.global gUnk_0817AC4C
gUnk_0817AC4C: @ 0817AC4C
	.incbin "fe6-base.gba", 0x17AC4C, (0x17B418 - 0x17AC4C) @ length: 07CC

	.global gUnk_0817B418
gUnk_0817B418: @ 0817B418
	.incbin "fe6-base.gba", 0x17B418, (0x17B438 - 0x17B418) @ length: 0020

	.global gUnk_0817B438
gUnk_0817B438: @ 0817B438
	.incbin "fe6-base.gba", 0x17B438, (0x17B8D0 - 0x17B438) @ length: 0498

	.global gUnk_0817B8D0
gUnk_0817B8D0: @ 0817B8D0
	.incbin "fe6-base.gba", 0x17B8D0, (0x17BBB4 - 0x17B8D0) @ length: 02E4

	.global gUnk_0817BBB4
gUnk_0817BBB4: @ 0817BBB4
	.incbin "fe6-base.gba", 0x17BBB4, (0x17BBB6 - 0x17BBB4) @ length: 0002

	.global gUnk_0817BBB6
gUnk_0817BBB6: @ 0817BBB6
	.incbin "fe6-base.gba", 0x17BBB6, (0x181E60 - 0x17BBB6) @ length: 62AA

	.global gUnk_08181E60
gUnk_08181E60: @ 08181E60
	.incbin "fe6-base.gba", 0x181E60, (0x1830F4 - 0x181E60) @ length: 1294

	.global gUnk_081830F4
gUnk_081830F4: @ 081830F4
	.incbin "fe6-base.gba", 0x1830F4, (0x18360C - 0x1830F4) @ length: 0518

	.global gUnk_0818360C
gUnk_0818360C: @ 0818360C
	.incbin "fe6-base.gba", 0x18360C, (0x18BBCC - 0x18360C) @ length: 85C0

	.global gUnk_0818BBCC
gUnk_0818BBCC: @ 0818BBCC
	.incbin "fe6-base.gba", 0x18BBCC, (0x18BBEC - 0x18BBCC) @ length: 0020

	.global gUnk_0818BBEC
gUnk_0818BBEC: @ 0818BBEC
	.incbin "fe6-base.gba", 0x18BBEC, (0x18DD18 - 0x18BBEC) @ length: 212C

	.global gUnk_0818DD18
gUnk_0818DD18: @ 0818DD18
	.incbin "fe6-base.gba", 0x18DD18, (0x18E1E4 - 0x18DD18) @ length: 04CC

	.global gUnk_0818E1E4
gUnk_0818E1E4: @ 0818E1E4
	.incbin "fe6-base.gba", 0x18E1E4, (0x18E67C - 0x18E1E4) @ length: 0498

	.global gUnk_0818E67C
gUnk_0818E67C: @ 0818E67C
	.incbin "fe6-base.gba", 0x18E67C, (0x18EA78 - 0x18E67C) @ length: 03FC

	.global gUnk_0818EA78
gUnk_0818EA78: @ 0818EA78
	.incbin "fe6-base.gba", 0x18EA78, (0x18EA98 - 0x18EA78) @ length: 0020

	.global gUnk_0818EA98
gUnk_0818EA98: @ 0818EA98
	.incbin "fe6-base.gba", 0x18EA98, (0x18F1F8 - 0x18EA98) @ length: 0760

	.global gUnk_0818F1F8
gUnk_0818F1F8: @ 0818F1F8
	.incbin "fe6-base.gba", 0x18F1F8, (0x18F3D8 - 0x18F1F8) @ length: 01E0

	.global gUnk_0818F3D8
gUnk_0818F3D8: @ 0818F3D8
	.incbin "fe6-base.gba", 0x18F3D8, (0x193598 - 0x18F3D8) @ length: 41C0

	.global gUnk_08193598
gUnk_08193598: @ 08193598
	.incbin "fe6-base.gba", 0x193598, (0x1935B8 - 0x193598) @ length: 0020

	.global gUnk_081935B8
gUnk_081935B8: @ 081935B8
	.incbin "fe6-base.gba", 0x1935B8, (0x197BE0 - 0x1935B8) @ length: 4628

	.global gUnk_08197BE0
gUnk_08197BE0: @ 08197BE0
	.incbin "fe6-base.gba", 0x197BE0, (0x19875C - 0x197BE0) @ length: 0B7C

	.global gUnk_0819875C
gUnk_0819875C: @ 0819875C
	.incbin "fe6-base.gba", 0x19875C, (0x19877C - 0x19875C) @ length: 0020

	.global gUnk_0819877C
gUnk_0819877C: @ 0819877C
	.incbin "fe6-base.gba", 0x19877C, (0x1AAECC - 0x19877C) @ length: 12750

	.global gUnk_081AAECC
gUnk_081AAECC: @ 081AAECC
	.incbin "fe6-base.gba", 0x1AAECC, (0x1AB190 - 0x1AAECC) @ length: 02C4

	.global gUnk_081AB190
gUnk_081AB190: @ 081AB190
	.incbin "fe6-base.gba", 0x1AB190, (0x1AB1B0 - 0x1AB190) @ length: 0020

	.global gUnk_081AB1B0
gUnk_081AB1B0: @ 081AB1B0
	.incbin "fe6-base.gba", 0x1AB1B0, (0x1AB340 - 0x1AB1B0) @ length: 0190

	.global gUnk_081AB340
gUnk_081AB340: @ 081AB340
	.incbin "fe6-base.gba", 0x1AB340, (0x1ABCA0 - 0x1AB340) @ length: 0960

	.global gUnk_081ABCA0
gUnk_081ABCA0: @ 081ABCA0
	.incbin "fe6-base.gba", 0x1ABCA0, (0x1ABEA0 - 0x1ABCA0) @ length: 0200

	.global gUnk_081ABEA0
gUnk_081ABEA0: @ 081ABEA0
	.incbin "fe6-base.gba", 0x1ABEA0, (0x1AC0F4 - 0x1ABEA0) @ length: 0254

	.global gUnk_081AC0F4
gUnk_081AC0F4: @ 081AC0F4
	.incbin "fe6-base.gba", 0x1AC0F4, (0x1AC114 - 0x1AC0F4) @ length: 0020

	.global gUnk_081AC114
gUnk_081AC114: @ 081AC114
	.incbin "fe6-base.gba", 0x1AC114, (0x1AC90C - 0x1AC114) @ length: 07F8

	.global gUnk_081AC90C
gUnk_081AC90C: @ 081AC90C
	.incbin "fe6-base.gba", 0x1AC90C, (0x1AD26C - 0x1AC90C) @ length: 0960

	.global gUnk_081AD26C
gUnk_081AD26C: @ 081AD26C
	.incbin "fe6-base.gba", 0x1AD26C, (0x1ADBCC - 0x1AD26C) @ length: 0960

	.global gUnk_081ADBCC
gUnk_081ADBCC: @ 081ADBCC
	.incbin "fe6-base.gba", 0x1ADBCC, (0x1ADDEC - 0x1ADBCC) @ length: 0220

	.global gUnk_081ADDEC
gUnk_081ADDEC: @ 081ADDEC
	.incbin "fe6-base.gba", 0x1ADDEC, (0x1AE88C - 0x1ADDEC) @ length: 0AA0

	.global gUnk_081AE88C
gUnk_081AE88C: @ 081AE88C
	.incbin "fe6-base.gba", 0x1AE88C, (0x1AEA8C - 0x1AE88C) @ length: 0200

	.global gUnk_081AEA8C
gUnk_081AEA8C: @ 081AEA8C
	.incbin "fe6-base.gba", 0x1AEA8C, (0x1AEC8C - 0x1AEA8C) @ length: 0200

	.global gUnk_081AEC8C
gUnk_081AEC8C: @ 081AEC8C
	.incbin "fe6-base.gba", 0x1AEC8C, (0x1B1710 - 0x1AEC8C) @ length: 2A84

	.global Pal_Unk_081B1710
Pal_Unk_081B1710: @ 081B1710
	.incbin "fe6-base.gba", 0x1B1710, (0x1B2348 - 0x1B1710) @ length: 0C38

	.global gUnk_081B2348
gUnk_081B2348: @ 081B2348
	.incbin "fe6-base.gba", 0x1B2348, (0x1B3D34 - 0x1B2348) @ length: 19EC

	.global gUnk_081B3D34
gUnk_081B3D34: @ 081B3D34
	.incbin "fe6-base.gba", 0x1B3D34, (0x1B4254 - 0x1B3D34) @ length: 0520

	.global gUnk_081B4254
gUnk_081B4254: @ 081B4254
	.incbin "fe6-base.gba", 0x1B4254, (0x1B4274 - 0x1B4254) @ length: 0020

	.global gUnk_081B4274
gUnk_081B4274: @ 081B4274
	.incbin "fe6-base.gba", 0x1B4274, (0x1B4E9C - 0x1B4274) @ length: 0C28

	.global gUnk_081B4E9C
gUnk_081B4E9C: @ 081B4E9C
	.incbin "fe6-base.gba", 0x1B4E9C, (0x1B4F9C - 0x1B4E9C) @ length: 0100

	.global gUnk_081B4F9C
gUnk_081B4F9C: @ 081B4F9C
	.incbin "fe6-base.gba", 0x1B4F9C, (0x1B57BC - 0x1B4F9C) @ length: 0820

	.global gUnk_081B57BC
gUnk_081B57BC: @ 081B57BC
	.incbin "fe6-base.gba", 0x1B57BC, (0x1B6688 - 0x1B57BC) @ length: 0ECC

	.global gUnk_081B6688
gUnk_081B6688: @ 081B6688
	.incbin "fe6-base.gba", 0x1B6688, (0x1B7468 - 0x1B6688) @ length: 0DE0

	.global gUnk_081B7468
gUnk_081B7468: @ 081B7468
	.incbin "fe6-base.gba", 0x1B7468, (0x1B7650 - 0x1B7468) @ length: 01E8

	.global gUnk_081B7650
gUnk_081B7650: @ 081B7650
	.incbin "fe6-base.gba", 0x1B7650, (0x1B7670 - 0x1B7650) @ length: 0020

	.global gUnk_081B7670
gUnk_081B7670: @ 081B7670
	.incbin "fe6-base.gba", 0x1B7670, (0x1B7690 - 0x1B7670) @ length: 0020

	.global gUnk_081B7690
gUnk_081B7690: @ 081B7690
	.incbin "fe6-base.gba", 0x1B7690, (0x1B76B0 - 0x1B7690) @ length: 0020

	.global gUnk_081B76B0
gUnk_081B76B0: @ 081B76B0
	.incbin "fe6-base.gba", 0x1B76B0, (0x1B7B48 - 0x1B76B0) @ length: 0498

	.global gUnk_081B7B48
gUnk_081B7B48: @ 081B7B48
	.incbin "fe6-base.gba", 0x1B7B48, (0x1B7F68 - 0x1B7B48) @ length: 0420

	.global gUnk_081B7F68
gUnk_081B7F68: @ 081B7F68
	.incbin "fe6-base.gba", 0x1B7F68, (0x1B80A8 - 0x1B7F68) @ length: 0140

	.global gUnk_081B80A8
gUnk_081B80A8: @ 081B80A8
	.incbin "fe6-base.gba", 0x1B80A8, (0x1B8934 - 0x1B80A8) @ length: 088C

	.global gUnk_081B8934
gUnk_081B8934: @ 081B8934
	.incbin "fe6-base.gba", 0x1B8934, (0x1B8E44 - 0x1B8934) @ length: 0510

	.global gUnk_081B8E44
gUnk_081B8E44: @ 081B8E44
	.incbin "fe6-base.gba", 0x1B8E44, (0x1B8E64 - 0x1B8E44) @ length: 0020

	.global gUnk_081B8E64
gUnk_081B8E64: @ 081B8E64
	.incbin "fe6-base.gba", 0x1B8E64, (0x1BB35C - 0x1B8E64) @ length: 24F8

	.global gUnk_081BB35C
gUnk_081BB35C: @ 081BB35C
	.incbin "fe6-base.gba", 0x1BB35C, (0x1BB37C - 0x1BB35C) @ length: 0020

	.global gUnk_081BB37C
gUnk_081BB37C: @ 081BB37C
	.incbin "fe6-base.gba", 0x1BB37C, (0x1BB5E4 - 0x1BB37C) @ length: 0268

	.global gUnk_081BB5E4
gUnk_081BB5E4: @ 081BB5E4
	.incbin "fe6-base.gba", 0x1BB5E4, (0x1BBBB4 - 0x1BB5E4) @ length: 05D0

	.global gUnk_081BBBB4
gUnk_081BBBB4: @ 081BBBB4
	.incbin "fe6-base.gba", 0x1BBBB4, (0x1BC0A8 - 0x1BBBB4) @ length: 04F4

	.global gUnk_081BC0A8
gUnk_081BC0A8: @ 081BC0A8
	.incbin "fe6-base.gba", 0x1BC0A8, (0x1BC0C8 - 0x1BC0A8) @ length: 0020

	.global FrameLut_EkrManaketefxNormalAttack
FrameLut_EkrManaketefxNormalAttack: @ 081BC0C8
	.short 0, 3
	.short 1, 3
	.short 2, 3
	.short 3, 3
	.short 4, 3
	.short 5, 3
	.short 6, 3
	.short 7, 3
	.short 8, 3
	.short -2

	.global FrameLut_EkrManaketefxCriticalAttack
FrameLut_EkrManaketefxCriticalAttack: @ 081BC0EE
	.short 9, 2
	.short 10, 2
	.short 11, 10
	.short -1

	.global FrameLut_EkrFaefx
FrameLut_EkrFaefx: @ 081BC0FC
	.incbin "fe6-base.gba", 0x1BC0FC, (0x1BC132 - 0x1BC0FC) @ length: 0036

	.global gUnk_081BC132
gUnk_081BC132: @ 081BC132
	.incbin "fe6-base.gba", 0x1BC132, (0x1BC140 - 0x1BC132) @ length: 000E

	.global gUnk_081BC140
gUnk_081BC140: @ 081BC140
	.incbin "fe6-base.gba", 0x1BC140, (0x1BC15E - 0x1BC140) @ length: 001E

	.global gUnk_081BC15E
gUnk_081BC15E: @ 081BC15E
	.incbin "fe6-base.gba", 0x1BC15E, (0x1BC17C - 0x1BC15E) @ length: 001E

	.global gUnk_081BC17C
gUnk_081BC17C: @ 081BC17C
	.incbin "fe6-base.gba", 0x1BC17C, (0x1BC19A - 0x1BC17C) @ length: 001E

	.global gUnk_081BC19A
gUnk_081BC19A: @ 081BC19A
	.incbin "fe6-base.gba", 0x1BC19A, (0x1BC268 - 0x1BC19A) @ length: 00CE

	.global Img_ManaketeBodyIntro2
Img_ManaketeBodyIntro2: @ 081BC268
	.incbin "fe6-base.gba", 0x1BC268, (0x1BCBDC - 0x1BC268) @ length: 0974

	.global Img_ManaketeBodyIntro1
Img_ManaketeBodyIntro1: @ 081BCBDC
	.incbin "fe6-base.gba", 0x1BCBDC, (0x1BD5E8 - 0x1BCBDC) @ length: 0A0C

	.global Img_ManaketeBodyStd
Img_ManaketeBodyStd: @ 081BD5E8
	.incbin "fe6-base.gba", 0x1BD5E8, (0x1BE490 - 0x1BD5E8) @ length: 0EA8

	.global Img_081BE490
Img_081BE490: @ 081BE490
	.incbin "fe6-base.gba", 0x1BE490, (0x1BF434 - 0x1BE490) @ length: 0FA4

	.global Pal_EkrManaketefx
Pal_EkrManaketefx: @ 081BF434
	.incbin "fe6-base.gba", 0x1BF434, (0x1BF5B4 - 0x1BF434) @ length: 0180

	.global Tsa_ManaketeBodyIntro2
Tsa_ManaketeBodyIntro2: @ 081BF5B4
	.incbin "fe6-base.gba", 0x1BF5B4, (0x1BF6F4 - 0x1BF5B4) @ length: 0140

	.global Tsa_ManaketeBodyIntro1
Tsa_ManaketeBodyIntro1: @ 081BF6F4
	.incbin "fe6-base.gba", 0x1BF6F4, (0x1BF848 - 0x1BF6F4) @ length: 0154

	.global Tsa_ManaketeBodyStd
Tsa_ManaketeBodyStd: @ 081BF848
	.incbin "fe6-base.gba", 0x1BF848, (0x1BFA34 - 0x1BF848) @ length: 01EC

	.global Tsa_081BFA34
Tsa_081BFA34: @ 081BFA34
	.incbin "fe6-base.gba", 0x1BFA34, (0x1BFC74 - 0x1BFA34) @ length: 0240

	.global Img_ManaketeObjfx1
Img_ManaketeObjfx1: @ 081BFC74
	.incbin "fe6-base.gba", 0x1BFC74, (0x1C079C - 0x1BFC74) @ length: 0B28

	.global Img_ManaketeObjfx2
Img_ManaketeObjfx2: @ 081C079C
	.incbin "fe6-base.gba", 0x1C079C, (0x1C14D0 - 0x1C079C) @ length: 0D34

	.global Img_ManaketeObjfx3
Img_ManaketeObjfx3: @ 081C14D0
	.incbin "fe6-base.gba", 0x1C14D0, (0x1C1C74 - 0x1C14D0) @ length: 07A4

	.global Pal_ManaketeBodyStd
Pal_ManaketeBodyStd: @ 081C1C74
	.incbin "fe6-base.gba", 0x1C1C74, (0x1C1C94 - 0x1C1C74) @ length: 0020

	.global Img_EkrIdunn_081C1C94
Img_EkrIdunn_081C1C94: @ 081C1C94
	.incbin "fe6-base.gba", 0x1C1C94, (0x1C4DE8 - 0x1C1C94) @ length: 3154

	.global Pal_081C4DE8
Pal_081C4DE8: @ 081C4DE8
	.incbin "fe6-base.gba", 0x1C4DE8, (0x1C4E28 - 0x1C4DE8) @ length: 0040

	.global Tsa_EkrIdunn_081C4E28
Tsa_EkrIdunn_081C4E28: @ 081C4E28
	.incbin "fe6-base.gba", 0x1C4E28, (0x1C5264 - 0x1C4E28) @ length: 043C

	.global gUnk_081C5264
gUnk_081C5264: @ 081C5264
	.incbin "fe6-base.gba", 0x1C5264, (0x1C5688 - 0x1C5264) @ length: 0424

	.global gUnk_081C5688
gUnk_081C5688: @ 081C5688
	.incbin "fe6-base.gba", 0x1C5688, (0x1C5AAC - 0x1C5688) @ length: 0424

	.global Tsa_EkrIdunn_081C5AAC
Tsa_EkrIdunn_081C5AAC: @ 081C5AAC
	.incbin "fe6-base.gba", 0x1C5AAC, (0x1C864C - 0x1C5AAC) @ length: 2BA0

	.global Img_EkrFaefx
Img_EkrFaefx: @ 081C864C
	.incbin "fe6-base.gba", 0x1C864C, (0x1C8F38 - 0x1C864C) @ length: 08EC

	.global Pal_EkrFaefx
Pal_EkrFaefx: @ 081C8F38
	.incbin "fe6-base.gba", 0x1C8F38, (0x1C8F58 - 0x1C8F38) @ length: 0F90

	.global Tsa_EkrFaefx1
Tsa_EkrFaefx1:
	.incbin "fe6-base.gba", 0x1C8F58, (0x1C9084 - 0x1C8F58)

	.global Tsa_EkrFaefx2
Tsa_EkrFaefx2:
	.incbin "fe6-base.gba", 0x1C9084, (0x1C91CC - 0x1C9084)

	.global Tsa_EkrFaefx3
Tsa_EkrFaefx3:
	.incbin "fe6-base.gba", 0x1C91CC, (0x1C92F8 - 0x1C91CC)

	.global Tsa_EkrFaefx4
Tsa_EkrFaefx4:
	.incbin "fe6-base.gba", 0x1C92F8, (0x1C946C - 0x1C92F8)

	.global Tsa_EkrFaefx5
Tsa_EkrFaefx5:
	.incbin "fe6-base.gba", 0x1C946C, (0x1C9618 - 0x1C946C)

	.global Tsa_EkrFaefx6
Tsa_EkrFaefx6:
	.incbin "fe6-base.gba", 0x1C9618, (0x1C9794 - 0x1C9618)

	.global Tsa_EkrFaefx7
Tsa_EkrFaefx7:
	.incbin "fe6-base.gba", 0x1C9794, (0x1C9940 - 0x1C9794)

	.global Tsa_EkrFaefx8
Tsa_EkrFaefx8:
	.incbin "fe6-base.gba", 0x1C9940, (0x1C9A9C - 0x1C9940)

	.global Tsa_EkrFaefx9
Tsa_EkrFaefx9:
	.incbin "fe6-base.gba", 0x1C9A9C, (0x1C9BB8 - 0x1C9A9C)

	.global Tsa_EkrFaefx10
Tsa_EkrFaefx10:
	.incbin "fe6-base.gba", 0x1C9BB8, (0x1C9CE4 - 0x1C9BB8)

	.global Tsa_EkrFaefx11
Tsa_EkrFaefx11:
	.incbin "fe6-base.gba", 0x1C9CE4, (0x1C9DEC - 0x1C9CE4)

	.global Tsa_EkrFaefx12
Tsa_EkrFaefx12:
	.incbin "fe6-base.gba", 0x1C9DEC, (0x1C9EC8 - 0x1C9DEC)

	.global gUnk_081C9EC8
gUnk_081C9EC8: @ 081C9EC8
	.incbin "fe6-base.gba", 0x1C9EC8, (0x1C9ED6 - 0x1C9EC8) @ length: 000E

	.global gUnk_081C9ED6
gUnk_081C9ED6: @ 081C9ED6
	.incbin "fe6-base.gba", 0x1C9ED6, (0x1C9EE8 - 0x1C9ED6) @ length: 0012

	.global gUnk_081C9EE8
gUnk_081C9EE8: @ 081C9EE8
	.incbin "fe6-base.gba", 0x1C9EE8, (0x1C9EF4 - 0x1C9EE8) @ length: 000C

	.global gUnk_081C9EF4
gUnk_081C9EF4: @ 081C9EF4
	.incbin "fe6-base.gba", 0x1C9EF4, (0x1C9F14 - 0x1C9EF4) @ length: 0020

	.global gUnk_081C9F14
gUnk_081C9F14: @ 081C9F14
	.incbin "fe6-base.gba", 0x1C9F14, (0x1C9F34 - 0x1C9F14) @ length: 0020

	.global gUnk_081C9F34
gUnk_081C9F34: @ 081C9F34
	.incbin "fe6-base.gba", 0x1C9F34, (0x1C9FA6 - 0x1C9F34) @ length: 0072

	.global gUnk_081C9FA6
gUnk_081C9FA6: @ 081C9FA6
	.incbin "fe6-base.gba", 0x1C9FA6, (0x1C9FEC - 0x1C9FA6) @ length: 0046

	.global gUnk_081C9FEC
gUnk_081C9FEC: @ 081C9FEC
	.incbin "fe6-base.gba", 0x1C9FEC, (0x1CA014 - 0x1C9FEC) @ length: 0028

	.global gUnk_081CA014
gUnk_081CA014: @ 081CA014
	.incbin "fe6-base.gba", 0x1CA014, (0x1CA03C - 0x1CA014) @ length: 0028

	.global gUnk_081CA03C
gUnk_081CA03C: @ 081CA03C
	.incbin "fe6-base.gba", 0x1CA03C, (0x1CA04C - 0x1CA03C) @ length: 0010

	.global gUnk_081CA04C
gUnk_081CA04C: @ 081CA04C
	.incbin "fe6-base.gba", 0x1CA04C, (0x1CA054 - 0x1CA04C) @ length: 0008

	.global gUnk_081CA054
gUnk_081CA054: @ 081CA054
	.incbin "fe6-base.gba", 0x1CA054, (0x1CA062 - 0x1CA054) @ length: 000E

	.global gUnk_081CA062
gUnk_081CA062: @ 081CA062
	.incbin "fe6-base.gba", 0x1CA062, (0x1CA070 - 0x1CA062) @ length: 000E

	.global gUnk_081CA070
gUnk_081CA070: @ 081CA070
	.incbin "fe6-base.gba", 0x1CA070, (0x1CAA14 - 0x1CA070) @ length: 09A4

	.global gUnk_081CAA14
gUnk_081CAA14: @ 081CAA14
	.incbin "fe6-base.gba", 0x1CAA14, (0x1CB404 - 0x1CAA14) @ length: 09F0

	.global gUnk_081CB404
gUnk_081CB404: @ 081CB404
	.incbin "fe6-base.gba", 0x1CB404, (0x1CC428 - 0x1CB404) @ length: 1024

	.global gUnk_081CC428
gUnk_081CC428: @ 081CC428
	.incbin "fe6-base.gba", 0x1CC428, (0x1CCDE0 - 0x1CC428) @ length: 09B8

	.global gUnk_081CCDE0
gUnk_081CCDE0: @ 081CCDE0
	.incbin "fe6-base.gba", 0x1CCDE0, (0x1CD7AC - 0x1CCDE0) @ length: 09CC

	.global gUnk_081CD7AC
gUnk_081CD7AC: @ 081CD7AC
	.incbin "fe6-base.gba", 0x1CD7AC, (0x1CE154 - 0x1CD7AC) @ length: 09A8

	.global gUnk_081CE154
gUnk_081CE154: @ 081CE154
	.incbin "fe6-base.gba", 0x1CE154, (0x1CE474 - 0x1CE154) @ length: 0320

	.global gUnk_081CE474
gUnk_081CE474: @ 081CE474
	.incbin "fe6-base.gba", 0x1CE474, (0x1CE848 - 0x1CE474) @ length: 03D4

	.global gUnk_081CE848
gUnk_081CE848: @ 081CE848
	.incbin "fe6-base.gba", 0x1CE848, (0x1CEC7C - 0x1CE848) @ length: 0434

	.global gUnk_081CEC7C
gUnk_081CEC7C: @ 081CEC7C
	.incbin "fe6-base.gba", 0x1CEC7C, (0x1CF03C - 0x1CEC7C) @ length: 03C0

	.global gUnk_081CF03C
gUnk_081CF03C: @ 081CF03C
	.incbin "fe6-base.gba", 0x1CF03C, (0x1CF574 - 0x1CF03C) @ length: 0538

	.global gUnk_081CF574
gUnk_081CF574: @ 081CF574
	.incbin "fe6-base.gba", 0x1CF574, (0x1CFCB0 - 0x1CF574) @ length: 073C

	.global gUnk_081CFCB0
gUnk_081CFCB0: @ 081CFCB0
	.incbin "fe6-base.gba", 0x1CFCB0, (0x1D043C - 0x1CFCB0) @ length: 078C

	.global gUnk_081D043C
gUnk_081D043C: @ 081D043C
	.incbin "fe6-base.gba", 0x1D043C, (0x2563F4 - 0x1D043C) @ length: 85FB8

	.global Img_TilesetAnim_085C788C_0
Img_TilesetAnim_085C788C_0: @ 082563F4
	.incbin "fe6-base.gba", 0x2563F4, (0x2573F4 - 0x2563F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_1
Img_TilesetAnim_085C788C_1: @ 082573F4
	.incbin "fe6-base.gba", 0x2573F4, (0x2583F4 - 0x2573F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_2
Img_TilesetAnim_085C788C_2: @ 082583F4
	.incbin "fe6-base.gba", 0x2583F4, (0x2593F4 - 0x2583F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_3
Img_TilesetAnim_085C788C_3: @ 082593F4
	.incbin "fe6-base.gba", 0x2593F4, (0x25A3F4 - 0x2593F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_4
Img_TilesetAnim_085C788C_4: @ 0825A3F4
	.incbin "fe6-base.gba", 0x25A3F4, (0x25B3F4 - 0x25A3F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_5
Img_TilesetAnim_085C788C_5: @ 0825B3F4
	.incbin "fe6-base.gba", 0x25B3F4, (0x25C3F4 - 0x25B3F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_6
Img_TilesetAnim_085C788C_6: @ 0825C3F4
	.incbin "fe6-base.gba", 0x25C3F4, (0x25D3F4 - 0x25C3F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_7
Img_TilesetAnim_085C788C_7: @ 0825D3F4
	.incbin "fe6-base.gba", 0x25D3F4, (0x25E3F4 - 0x25D3F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_8
Img_TilesetAnim_085C788C_8: @ 0825E3F4
	.incbin "fe6-base.gba", 0x25E3F4, (0x25F3F4 - 0x25E3F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_9
Img_TilesetAnim_085C788C_9: @ 0825F3F4
	.incbin "fe6-base.gba", 0x25F3F4, (0x2603F4 - 0x25F3F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_10
Img_TilesetAnim_085C788C_10: @ 082603F4
	.incbin "fe6-base.gba", 0x2603F4, (0x2613F4 - 0x2603F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_11
Img_TilesetAnim_085C788C_11: @ 082613F4
	.incbin "fe6-base.gba", 0x2613F4, (0x2623F4 - 0x2613F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_12
Img_TilesetAnim_085C788C_12: @ 082623F4
	.incbin "fe6-base.gba", 0x2623F4, (0x2633F4 - 0x2623F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_13
Img_TilesetAnim_085C788C_13: @ 082633F4
	.incbin "fe6-base.gba", 0x2633F4, (0x2643F4 - 0x2633F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_14
Img_TilesetAnim_085C788C_14: @ 082643F4
	.incbin "fe6-base.gba", 0x2643F4, (0x2653F4 - 0x2643F4) @ length: 1000

	.global Img_TilesetAnim_085C788C_15
Img_TilesetAnim_085C788C_15: @ 082653F4
	.incbin "fe6-base.gba", 0x2653F4, (0x2663F4 - 0x2653F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_0
Img_TilesetAnim_085C7914_0: @ 082663F4
	.incbin "fe6-base.gba", 0x2663F4, (0x2673F4 - 0x2663F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_1
Img_TilesetAnim_085C7914_1: @ 082673F4
	.incbin "fe6-base.gba", 0x2673F4, (0x2683F4 - 0x2673F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_2
Img_TilesetAnim_085C7914_2: @ 082683F4
	.incbin "fe6-base.gba", 0x2683F4, (0x2693F4 - 0x2683F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_3
Img_TilesetAnim_085C7914_3: @ 082693F4
	.incbin "fe6-base.gba", 0x2693F4, (0x26A3F4 - 0x2693F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_4
Img_TilesetAnim_085C7914_4: @ 0826A3F4
	.incbin "fe6-base.gba", 0x26A3F4, (0x26B3F4 - 0x26A3F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_5
Img_TilesetAnim_085C7914_5: @ 0826B3F4
	.incbin "fe6-base.gba", 0x26B3F4, (0x26C3F4 - 0x26B3F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_6
Img_TilesetAnim_085C7914_6: @ 0826C3F4
	.incbin "fe6-base.gba", 0x26C3F4, (0x26D3F4 - 0x26C3F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_7
Img_TilesetAnim_085C7914_7: @ 0826D3F4
	.incbin "fe6-base.gba", 0x26D3F4, (0x26E3F4 - 0x26D3F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_8
Img_TilesetAnim_085C7914_8: @ 0826E3F4
	.incbin "fe6-base.gba", 0x26E3F4, (0x26F3F4 - 0x26E3F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_9
Img_TilesetAnim_085C7914_9: @ 0826F3F4
	.incbin "fe6-base.gba", 0x26F3F4, (0x2703F4 - 0x26F3F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_10
Img_TilesetAnim_085C7914_10: @ 082703F4
	.incbin "fe6-base.gba", 0x2703F4, (0x2713F4 - 0x2703F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_11
Img_TilesetAnim_085C7914_11: @ 082713F4
	.incbin "fe6-base.gba", 0x2713F4, (0x2723F4 - 0x2713F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_12
Img_TilesetAnim_085C7914_12: @ 082723F4
	.incbin "fe6-base.gba", 0x2723F4, (0x2733F4 - 0x2723F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_13
Img_TilesetAnim_085C7914_13: @ 082733F4
	.incbin "fe6-base.gba", 0x2733F4, (0x2743F4 - 0x2733F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_14
Img_TilesetAnim_085C7914_14: @ 082743F4
	.incbin "fe6-base.gba", 0x2743F4, (0x2753F4 - 0x2743F4) @ length: 1000

	.global Img_TilesetAnim_085C7914_15
Img_TilesetAnim_085C7914_15: @ 082753F4
	.incbin "fe6-base.gba", 0x2753F4, (0x2763F4 - 0x2753F4) @ length: 1000

	.global Img_TilesetAnim_085C799C_0
Img_TilesetAnim_085C799C_0: @ 082763F4
	.incbin "fe6-base.gba", 0x2763F4, (0x2767F4 - 0x2763F4) @ length: 0400

	.global Img_TilesetAnim_085C799C_1
Img_TilesetAnim_085C799C_1: @ 082767F4
	.incbin "fe6-base.gba", 0x2767F4, (0x276BF4 - 0x2767F4) @ length: 0400

	.global Img_TilesetAnim_085C799C_2
Img_TilesetAnim_085C799C_2: @ 08276BF4
	.incbin "fe6-base.gba", 0x276BF4, (0x276FF4 - 0x276BF4) @ length: 0400

	.global Img_TilesetAnim_085C799C_3
Img_TilesetAnim_085C799C_3: @ 08276FF4
	.incbin "fe6-base.gba", 0x276FF4, (0x2773F4 - 0x276FF4) @ length: 0400

	.global Img_TilesetAnim_085C799C_4
Img_TilesetAnim_085C799C_4: @ 082773F4
	.incbin "fe6-base.gba", 0x2773F4, (0x2777F4 - 0x2773F4) @ length: 0400

	.global Img_TilesetAnim_085C799C_5
Img_TilesetAnim_085C799C_5: @ 082777F4
	.incbin "fe6-base.gba", 0x2777F4, (0x277BF4 - 0x2777F4) @ length: 0400

	.global Img_TilesetAnim_085C79D4_0
Img_TilesetAnim_085C79D4_0: @ 08277BF4
	.incbin "fe6-base.gba", 0x277BF4, (0x277FF4 - 0x277BF4) @ length: 0400

	.global Img_TilesetAnim_085C79D4_1
Img_TilesetAnim_085C79D4_1: @ 08277FF4
	.incbin "fe6-base.gba", 0x277FF4, (0x2783F4 - 0x277FF4) @ length: 0400

	.global Img_TilesetAnim_085C79D4_2
Img_TilesetAnim_085C79D4_2: @ 082783F4
	.incbin "fe6-base.gba", 0x2783F4, (0x2787F4 - 0x2783F4) @ length: 0400

	.global Img_TilesetAnim_085C79D4_3
Img_TilesetAnim_085C79D4_3: @ 082787F4
	.incbin "fe6-base.gba", 0x2787F4, (0x278BF4 - 0x2787F4) @ length: 0400

	.global Img_TilesetAnim_085C79D4_4
Img_TilesetAnim_085C79D4_4: @ 08278BF4
	.incbin "fe6-base.gba", 0x278BF4, (0x278FF4 - 0x278BF4) @ length: 0400

	.global Img_TilesetAnim_085C79D4_5
Img_TilesetAnim_085C79D4_5: @ 08278FF4
	.incbin "fe6-base.gba", 0x278FF4, (0x2793F4 - 0x278FF4) @ length: 0400

	.global Img_TilesetAnim_085C79D4_6
Img_TilesetAnim_085C79D4_6: @ 082793F4
	.incbin "fe6-base.gba", 0x2793F4, (0x2797F4 - 0x2793F4) @ length: 0400

	.global Img_TilesetAnim_085C79D4_7
Img_TilesetAnim_085C79D4_7: @ 082797F4
	.incbin "fe6-base.gba", 0x2797F4, (0x279BF4 - 0x2797F4) @ length: 0400

	.global Pal_TilesetAnim_085C7A1C_0
Pal_TilesetAnim_085C7A1C_0: @ 08279BF4
	.incbin "fe6-base.gba", 0x279BF4, (0x279BFC - 0x279BF4) @ length: 0008

	.global Pal_TilesetAnim_085C7A1C_2
Pal_TilesetAnim_085C7A1C_2: @ 08279BFC
	.incbin "fe6-base.gba", 0x279BFC, (0x279C04 - 0x279BFC) @ length: 0008

	.global Pal_TilesetAnim_085C7A1C_3
Pal_TilesetAnim_085C7A1C_3: @ 08279C04
	.incbin "fe6-base.gba", 0x279C04, (0x279C0C - 0x279C04) @ length: 0008

	.global Pal_TilesetAnim_085C7A1C_4
Pal_TilesetAnim_085C7A1C_4: @ 08279C0C
	.incbin "fe6-base.gba", 0x279C0C, (0x279C14 - 0x279C0C) @ length: 0008

	.global Pal_TilesetAnim_085C7A1C_5
Pal_TilesetAnim_085C7A1C_5: @ 08279C14
	.incbin "fe6-base.gba", 0x279C14, (0x279C1C - 0x279C14) @ length: 0008

	.global Pal_TilesetAnim_085C7A1C_6
Pal_TilesetAnim_085C7A1C_6: @ 08279C1C
	.incbin "fe6-base.gba", 0x279C1C, (0x279C24 - 0x279C1C) @ length: 0008

	.global Pal_TilesetAnim_085C7A1C_7
Pal_TilesetAnim_085C7A1C_7: @ 08279C24
	.incbin "fe6-base.gba", 0x279C24, (0x279C2E - 0x279C24) @ length: 000A

	.global Pal_TilesetAnim_085C7A64_0
Pal_TilesetAnim_085C7A64_0: @ 08279C2E
	.incbin "fe6-base.gba", 0x279C2E, (0x279C34 - 0x279C2E) @ length: 0006

	.global Pal_TilesetAnim_085C7A64_1
Pal_TilesetAnim_085C7A64_1: @ 08279C34
	.incbin "fe6-base.gba", 0x279C34, (0x279C3A - 0x279C34) @ length: 0006

	.global Pal_TilesetAnim_085C7A64_2
Pal_TilesetAnim_085C7A64_2: @ 08279C3A
	.incbin "fe6-base.gba", 0x279C3A, (0x279C40 - 0x279C3A) @ length: 0006

	.global Pal_TilesetAnim_085C7A64_3
Pal_TilesetAnim_085C7A64_3: @ 08279C40
	.incbin "fe6-base.gba", 0x279C40, (0x279C46 - 0x279C40) @ length: 0006

	.global Pal_TilesetAnim_085C7A64_4
Pal_TilesetAnim_085C7A64_4: @ 08279C46
	.incbin "fe6-base.gba", 0x279C46, (0x279C4E - 0x279C46) @ length: 0008

	.global Pal_TilesetAnim_085C7A64_5
Pal_TilesetAnim_085C7A64_5: @ 08279C4E
	.incbin "fe6-base.gba", 0x279C4E, (0x279C54 - 0x279C4E) @ length: 0006

	.global Pal_TilesetAnim_085C7A64_6
Pal_TilesetAnim_085C7A64_6: @ 08279C54
	.incbin "fe6-base.gba", 0x279C54, (0x279C5A - 0x279C54) @ length: 0006

	.global Pal_TilesetAnim_085C7A64_7
Pal_TilesetAnim_085C7A64_7: @ 08279C5A
	.incbin "fe6-base.gba", 0x279C5A, (0x279C60 - 0x279C5A) @ length: 0006

	.global Pal_TilesetAnim_085C7A64_8
Pal_TilesetAnim_085C7A64_8: @ 08279C60
	.incbin "fe6-base.gba", 0x279C60, (0x279C66 - 0x279C60) @ length: 0006

	.global Pal_TilesetAnim_085C7A64_9
Pal_TilesetAnim_085C7A64_9: @ 08279C66
	.incbin "fe6-base.gba", 0x279C66, (0x279C6E - 0x279C66) @ length: 0008

	.global Pal_TilesetAnim_085C7A64_10
Pal_TilesetAnim_085C7A64_10: @ 08279C6E
	.incbin "fe6-base.gba", 0x279C6E, (0x279C74 - 0x279C6E) @ length: 0006

	.global Pal_TilesetAnim_085C7A64_11
Pal_TilesetAnim_085C7A64_11: @ 08279C74
	.incbin "fe6-base.gba", 0x279C74, (0x279C7C - 0x279C74) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_0
Pal_TilesetAnim_085C7ADC_0: @ 08279C7C
	.incbin "fe6-base.gba", 0x279C7C, (0x279C84 - 0x279C7C) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_1
Pal_TilesetAnim_085C7ADC_1: @ 08279C84
	.incbin "fe6-base.gba", 0x279C84, (0x279C8C - 0x279C84) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_2
Pal_TilesetAnim_085C7ADC_2: @ 08279C8C
	.incbin "fe6-base.gba", 0x279C8C, (0x279C94 - 0x279C8C) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_3
Pal_TilesetAnim_085C7ADC_3: @ 08279C94
	.incbin "fe6-base.gba", 0x279C94, (0x279C9C - 0x279C94) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_4
Pal_TilesetAnim_085C7ADC_4: @ 08279C9C
	.incbin "fe6-base.gba", 0x279C9C, (0x279CA4 - 0x279C9C) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_5
Pal_TilesetAnim_085C7ADC_5: @ 08279CA4
	.incbin "fe6-base.gba", 0x279CA4, (0x279CAC - 0x279CA4) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_6
Pal_TilesetAnim_085C7ADC_6: @ 08279CAC
	.incbin "fe6-base.gba", 0x279CAC, (0x279CB4 - 0x279CAC) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_7
Pal_TilesetAnim_085C7ADC_7: @ 08279CB4
	.incbin "fe6-base.gba", 0x279CB4, (0x279CBC - 0x279CB4) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_8
Pal_TilesetAnim_085C7ADC_8: @ 08279CBC
	.incbin "fe6-base.gba", 0x279CBC, (0x279CC4 - 0x279CBC) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_9
Pal_TilesetAnim_085C7ADC_9: @ 08279CC4
	.incbin "fe6-base.gba", 0x279CC4, (0x279CCC - 0x279CC4) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_10
Pal_TilesetAnim_085C7ADC_10: @ 08279CCC
	.incbin "fe6-base.gba", 0x279CCC, (0x279CD4 - 0x279CCC) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_11
Pal_TilesetAnim_085C7ADC_11: @ 08279CD4
	.incbin "fe6-base.gba", 0x279CD4, (0x279CDC - 0x279CD4) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_12
Pal_TilesetAnim_085C7ADC_12: @ 08279CDC
	.incbin "fe6-base.gba", 0x279CDC, (0x279CE4 - 0x279CDC) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_13
Pal_TilesetAnim_085C7ADC_13: @ 08279CE4
	.incbin "fe6-base.gba", 0x279CE4, (0x279CEC - 0x279CE4) @ length: 0008

	.global Pal_TilesetAnim_085C7ADC_14
Pal_TilesetAnim_085C7ADC_14: @ 08279CEC
	.incbin "fe6-base.gba", 0x279CEC, (0x279CF4 - 0x279CEC) @ length: 0008

	.global Pal_TilesetAnim_085C7B5C_0
Pal_TilesetAnim_085C7B5C_0: @ 08279CF4
	.incbin "fe6-base.gba", 0x279CF4, (0x279CFC - 0x279CF4) @ length: 0008

	.global Pal_TilesetAnim_085C7B5C_1
Pal_TilesetAnim_085C7B5C_1: @ 08279CFC
	.incbin "fe6-base.gba", 0x279CFC, (0x279D04 - 0x279CFC) @ length: 0008

	.global Pal_TilesetAnim_085C7B5C_2
Pal_TilesetAnim_085C7B5C_2: @ 08279D04
	.incbin "fe6-base.gba", 0x279D04, (0x279D0C - 0x279D04) @ length: 0008

	.global Pal_TilesetAnim_085C7B5C_3
Pal_TilesetAnim_085C7B5C_3: @ 08279D0C
	.incbin "fe6-base.gba", 0x279D0C, (0x279D14 - 0x279D0C) @ length: 0008

	.global Pal_TilesetAnim_085C7B5C_4
Pal_TilesetAnim_085C7B5C_4: @ 08279D14
	.incbin "fe6-base.gba", 0x279D14, (0x279D1C - 0x279D14) @ length: 0008

	.global Pal_TilesetAnim_085C7B5C_5
Pal_TilesetAnim_085C7B5C_5: @ 08279D1C
	.incbin "fe6-base.gba", 0x279D1C, (0x279D24 - 0x279D1C) @ length: 0008
