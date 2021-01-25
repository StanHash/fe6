
	.data

	.global PersonInfoTable
PersonInfoTable: @ 086076D0
	.incbin "fe6-base.gba", 0x6076D0, (0x60A130 - 0x6076D0) @ length: 2A60

	.global JobInfoTable
JobInfoTable: @ 0860A130
	.incbin "fe6-base.gba", 0x60A130, (0x60B648 - 0x60A130) @ length: 1518

	.global ItemInfoTable
ItemInfoTable: @ 0860B648
	.incbin "fe6-base.gba", 0x60B648, (0x60C714 - 0x60B648) @ length: 10CC

	.global gUnk_0860C714
gUnk_0860C714: @ 0860C714
	.incbin "fe6-base.gba", 0x60C714, (0x60C912 - 0x60C714) @ length: 01FE

	.global MoveTable_Unk_0860C912
MoveTable_Unk_0860C912: @ 0860C912
	.incbin "fe6-base.gba", 0x60C912, (0x60C978 - 0x60C912) @ length: 0066

	.global gUnk_0860C978
gUnk_0860C978: @ 0860C978
	.incbin "fe6-base.gba", 0x60C978, (0x60C9AB - 0x60C978) @ length: 0033

	.global gUnk_0860C9AB
gUnk_0860C9AB: @ 0860C9AB
	.incbin "fe6-base.gba", 0x60C9AB, (0x60CBA9 - 0x60C9AB) @ length: 01FE

	.global TerrainHealAmountTable
TerrainHealAmountTable: @ 0860CBA9
	.incbin "fe6-base.gba", 0x60CBA9, (0x60CBDC - 0x60CBA9) @ length: 0033

	.global TerrainHealsStatusTable
TerrainHealsStatusTable: @ 0860CBDC
	.incbin "fe6-base.gba", 0x60CBDC, (0x60CC0F - 0x60CBDC) @ length: 0033

	.global gUnk_0860CC0F
gUnk_0860CC0F: @ 0860CC0F
	.incbin "fe6-base.gba", 0x60CC0F, (0x60CC42 - 0x60CC0F) @ length: 0033

	.global gUnk_0860CC42
gUnk_0860CC42: @ 0860CC42
	.incbin "fe6-base.gba", 0x60CC42, (0x60CC75 - 0x60CC42) @ length: 0033

	.global gUnk_0860CC75
gUnk_0860CC75: @ 0860CC75
	.incbin "fe6-base.gba", 0x60CC75, (0x60CCA8 - 0x60CC75) @ length: 0033

	.global gUnk_0860CCA8
gUnk_0860CCA8: @ 0860CCA8
	.incbin "fe6-base.gba", 0x60CCA8, (0x60CCDB - 0x60CCA8) @ length: 0033

	.global gUnk_0860CCDB
gUnk_0860CCDB: @ 0860CCDB
	.incbin "fe6-base.gba", 0x60CCDB, (0x60CD0E - 0x60CCDB) @ length: 0033

	.global gUnk_0860CD0E
gUnk_0860CD0E: @ 0860CD0E
	.incbin "fe6-base.gba", 0x60CD0E, (0x60CD41 - 0x60CD0E) @ length: 0033

	.global gUnk_0860CD41
gUnk_0860CD41: @ 0860CD41
	.incbin "fe6-base.gba", 0x60CD41, (0x60CD74 - 0x60CD41) @ length: 0033

	.global gUnk_0860CD74
gUnk_0860CD74: @ 0860CD74
	.incbin "fe6-base.gba", 0x60CD74, (0x60CDA7 - 0x60CD74) @ length: 0033

	.global gUnk_0860CDA7
gUnk_0860CDA7: @ 0860CDA7
	.incbin "fe6-base.gba", 0x60CDA7, (0x60CDDA - 0x60CDA7) @ length: 0033

	.global gUnk_0860CDDA
gUnk_0860CDDA: @ 0860CDDA
	.incbin "fe6-base.gba", 0x60CDDA, (0x60CE0D - 0x60CDDA) @ length: 0033

	.global gUnk_0860CE0D
gUnk_0860CE0D: @ 0860CE0D
	.incbin "fe6-base.gba", 0x60CE0D, (0x60CE40 - 0x60CE0D) @ length: 0033

	.global gUnk_0860CE40
gUnk_0860CE40: @ 0860CE40
	.incbin "fe6-base.gba", 0x60CE40, (0x60CE73 - 0x60CE40) @ length: 0033

	.global gUnk_0860CE73
gUnk_0860CE73: @ 0860CE73
	.incbin "fe6-base.gba", 0x60CE73, (0x60CEA6 - 0x60CE73) @ length: 0033

	.global gUnk_0860CEA6
gUnk_0860CEA6: @ 0860CEA6
	.incbin "fe6-base.gba", 0x60CEA6, (0x60CED9 - 0x60CEA6) @ length: 0033

	.global gUnk_0860CED9
gUnk_0860CED9: @ 0860CED9
	.incbin "fe6-base.gba", 0x60CED9, (0x60CF0C - 0x60CED9) @ length: 0033

	.global gUnk_0860CF0C
gUnk_0860CF0C: @ 0860CF0C
	.incbin "fe6-base.gba", 0x60CF0C, (0x60CF3F - 0x60CF0C) @ length: 0033

	.global gUnk_0860CF3F
gUnk_0860CF3F: @ 0860CF3F
	.incbin "fe6-base.gba", 0x60CF3F, (0x60CF72 - 0x60CF3F) @ length: 0033

	.global gUnk_0860CF72
gUnk_0860CF72: @ 0860CF72
	.incbin "fe6-base.gba", 0x60CF72, (0x60CFA5 - 0x60CF72) @ length: 0033

	.global gUnk_0860CFA5
gUnk_0860CFA5: @ 0860CFA5
	.incbin "fe6-base.gba", 0x60CFA5, (0x60CFD8 - 0x60CFA5) @ length: 0033

	.global gUnk_0860CFD8
gUnk_0860CFD8: @ 0860CFD8
	.incbin "fe6-base.gba", 0x60CFD8, (0x60D00C - 0x60CFD8) @ length: 0034

	.global TerrainNameStringTable
TerrainNameStringTable: @ 0860D00C
	.incbin "fe6-base.gba", 0x60D00C, (0x66074C - 0x60D00C) @ length: 53740

	.global FaceInfoTable
FaceInfoTable: @ 0866074C
	.incbin "fe6-base.gba", 0x66074C, (0x6615DB - 0x66074C) @ length: 0E8F

	.global JList_BowEffectiveness
JList_BowEffectiveness: @ 086615DB
	.incbin "fe6-base.gba", 0x6615DB, (0x6615E2 - 0x6615DB) @ length: 0007

	.global JList_HeroCrestPromotes
JList_HeroCrestPromotes: @ 086615E2
	.incbin "fe6-base.gba", 0x6615E2, (0x6615EA - 0x6615E2) @ length: 0008

	.global JList_KnightCrestPromotes
JList_KnightCrestPromotes: @ 086615EA
	.incbin "fe6-base.gba", 0x6615EA, (0x6615EF - 0x6615EA) @ length: 0005

	.global JList_OrionBoltPromotes
JList_OrionBoltPromotes: @ 086615EF
	.incbin "fe6-base.gba", 0x6615EF, (0x6615F4 - 0x6615EF) @ length: 0005

	.global JList_ElysianWhipPromotes
JList_ElysianWhipPromotes: @ 086615F4
	.incbin "fe6-base.gba", 0x6615F4, (0x6615F8 - 0x6615F4) @ length: 0004

	.global JList_GuidingRingPromotes
JList_GuidingRingPromotes: @ 086615F8
	.incbin "fe6-base.gba", 0x6615F8, (0x662C14 - 0x6615F8) @ length: 161C

	.global UnitSpriteTable
UnitSpriteTable: @ 08662C14
	.incbin "fe6-base.gba", 0x662C14, (0x662E4C - 0x662C14) @ length: 0238

	.global gUnk_08662E4C
gUnk_08662E4C: @ 08662E4C
	.incbin "fe6-base.gba", 0x662E4C, (0x66350C - 0x662E4C) @ length: 06C0

	.global AffinityBonuses
AffinityBonuses: @ 0866350C
	.incbin "fe6-base.gba", 0x66350C, (0x66354C - 0x66350C) @ length: 0040

	.global gUnk_0866354C
gUnk_0866354C: @ 0866354C
	.incbin "fe6-base.gba", 0x66354C, (0x6637A4 - 0x66354C) @ length: 0258

	.global ChapterInfoTable
ChapterInfoTable: @ 086637A4
	.incbin "fe6-base.gba", 0x6637A4, (0x664398 - 0x6637A4) @ length: 0BF4

	.global ChapterAssets
ChapterAssets: @ 08664398
	.incbin "fe6-base.gba", 0x664398, (0x66472C - 0x664398) @ length: 0394
