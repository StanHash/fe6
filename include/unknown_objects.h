#ifndef UNKNOWN_OBJECTS_H
#define UNKNOWN_OBJECTS_H

#include "gba/gba.h"
#include "types.h"

#include "proc.h"
#include "text.h"
#include "menu.h"
#include "mapselect.h"

// some or those are not so much "unknown" as much as they just don't have a home yet

extern struct Font gFont_Unk_02002770;
extern u16 gUiTmScratchA[0x280];
extern u16 gUiTmScratchB[0x280];
extern u16 gUiTmScratchC[0x240];

extern struct Glyph const * CONST_DATA TextGlyphs_Special[];
extern struct Glyph const * CONST_DATA TextGlyphs_System[];
extern struct Glyph const * CONST_DATA TextGlyphs_Talk[];
extern u16 const Pal_Text[]; // 2 palettes (system and talk)
extern u16 const Pal_GreenTextColors[];
extern u8 const Img_FactionMiniCard[];
extern u16 const Pal_FactionMiniCard[];
extern u8 const Img_TalkBubble[];
extern u16 const Pal_TalkBubble[];
extern u8 const Img_TalkBubbleOpeningA[];
extern u8 const Img_TalkBubbleOpeningB[];
extern u8 const Img_TalkBubbleOpeningC[];
extern u8 const Img_TalkBubbleOpeningD[];
extern u8 const Img_TalkBubbleOpeningE[];
extern u8 const Tsa_Unk_08101974[];
extern u8 const Tsa_Unk_08101A2C[];
extern u8 const Img_SystemObjects[];
extern u16 const Pal_SystemObjects[];
extern u8 const Img_LimitViewSquares[];
extern u16 const Pal_LimitViewBlue[];
extern u16 const Pal_LimitViewRed[];
extern u16 const Pal_LimitViewGreen[];
extern u8 const Img_PhaseChangeSquares[];
extern u8 const Img_PhaseChangePlayer[];
extern u16 const Pal_PhaseChangePlayer[];
extern u8 const Img_PhaseChangeEnemy[];
extern u16 const Pal_PhaseChangeEnemy[];
extern u8 const Img_PhaseChangeOther[];
extern u16 const Pal_PhaseChangeOther[];
extern u16 const SpriteAnim_08102450[];
extern u16 const SpriteAnim_GasTrapVertical[];
extern u16 const SpriteAnim_GasTrapHorizontal[];
extern u8 const Img_GasTrapVertical[];
extern u8 const Img_GasTrapHorizontal[];
extern u16 const Pal_GasTrap[];
extern u8 const Img_ArrowTrap[];
extern u16 const Pal_ArrowTrap[];
extern u16 const SpriteAnim_ArrowTrap[];
extern u8 const Img_FireTrap[];
extern u16 const Pal_FireTrap[];
extern u16 const SpriteAnim_FireTrap[];
extern u8 const Img_PikeTrap[];
extern u16 const SpriteAnim_PikeTrap[];
extern u16 const Pal_PikeTrap[];
extern u8 const Img_ChapterIntroFog[];
extern u16 const Pal_ChapterIntroFog[];
extern u8 const Img_ChapterIntroMotif[];
extern u16 const Pal_ChapterIntroMotif[];
extern u8 const Tm_ChapterIntroMotif[];
extern u8 const Img_GameOverText[];
extern u16 const Pal_GameOverText[];
extern u16 const Pal_Unk_0830D95C[];
extern u8 const Tsa_Unk_0830D97C[];
extern u8 const Tsa_Unk_081022FC[];
extern u16 const Pal_UnitSprites[];
extern u16 const Pal_UnitSpritesPurple[];
extern u8 const Img_SandstormParticles[];
extern u8 const Img_SnowstormParticles[];
extern u8 const Img_FlamesParticles[];
extern u16 const Pal_FlamesParticles[];
extern u8 const Img_CloudWeather[];
extern u16 const Pal_CloudWeather[];
extern u8 const Img_MovePath[];
extern u16 const Pal_MovePath[];
extern u8 const Tsa_UnitPanelHeader[];
extern u8 const Img_StatusHealEffect[];
extern u16 const Pal_StatusHealEffect[];
extern u8 const Tsa_StatusHealEffect[];
extern u8 const Tsa_BattlePreviewFrame_Short[];
extern u8 const Tsa_BattlePreviewFrame_Long[];
extern u16 const Pal_BattlePreviewFrame_Blue[];
extern u16 const Pal_BattlePreviewFrame_Red[];
extern u16 const Pal_BattlePreviewFrame_Green[];
extern u16 const Pal_BattlePreviewFrame_Purple[];
extern u8 const Img_BattlePreviewFrame[];
extern u8 const Img_BattlePreviewMultipliers[];
extern u16 const Pal_BattlePreviewMultipliers[];
extern u8 const Img_MuFogBump[];
extern u16 const SpriteAnim_MuFogBump[];
extern u8 const Img_ManimInfoWindowDigits[];
extern u16 const Pal_ManimWindowHpBar[];
extern u8 const Img_ManimInfoFrame[];
extern u8 const Img_ManimHpBar[];
extern u16 const Pal_UiWindowFrame_ThemeBlue[];
extern u16 const Pal_UiWindowFrame_ThemeRed[];
extern u16 const Pal_UiWindowFrame_ThemeGray[];
extern u16 const Pal_UiWindowFrame_ThemeGreen[];
extern u8 const Img_UiWindowFrame_ThemeBlue[];
extern u8 const Img_UiWindowFrame_ThemeRed[];
extern u8 const Img_UiWindowFrame_ThemeGray[];
extern u8 const Img_UiWindowFrame_ThemeGreen[];
extern u16 const Pal_UiStatBar_ThemeBlue[];
extern u16 const Pal_UiStatBar_ThemeRed[];
extern u16 const Pal_UiStatBar_ThemeGray[];
extern u16 const Pal_UiStatBar_ThemeGreen[];
extern u8 const Img_UiUnitNameFrame[];
extern u16 const Pal_UiUnitNameFrame[];

extern u16 const Pal_Unk_081B1710[]; // manim

extern u8 const Tsa_StatusScreen_FactionInfoFrame[]; // tsa
extern u8 const Tsa_StatusScreen_PlaytimeFrame[]; // tsa
extern u8 const gUnk_08309408[]; // compressed tsa
extern u8 const gUnk_0833C6F4[]; // tsa
extern u8 const gUnk_0833C8D8[]; // tsa

extern struct ProcScr CONST_DATA ProcScr_OpeningSequence[];
extern struct ProcScr CONST_DATA ProcScr_TitleScreenHandler[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0868C304[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0868B010[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0868AE04[];
extern u16 CONST_DATA Pal_ManimFireDragonMu[];
extern u16 CONST_DATA Pal_ManimDivineDragonMu[];

extern struct ChapterInfo CONST_DATA ChapterInfoTable[];

extern void const * CONST_DATA ChapterAssets[];

extern u16 const Pal_LinkArenaMuralBackground[];
extern u16 const Pal_MuralBackground[];
extern u8 const Img_MuralBackground[];
extern u16 const Pal_Unk_083087C8[][0x20];

extern u8 const gUnk_083080D0[]; // compressed img (statscreen misc sprite sheet)
extern u8 const gUnk_08307CEC[]; // compressed tsa (statscreen main window frame)
extern u16 const gUnk_08308050[]; // pal (statscreen equip stats frame)
extern u8 const gUnk_08307ED4[]; // compressed img (statscreen equip stats frame)
extern u8 const gUnk_08308920[]; // compressed img (equipment label)

extern u8 const gUnk_08307D58[]; // tsa (compressed): statscreen page A frame
extern u8 const gUnk_08307DD4[]; // tsa (compressed): statscreen page B frame
extern u8 const gUnk_08307E50[]; // tsa (compressed): statscreen page C frame
extern u8 const gUnk_08308070[]; // tsa (compressed): statscreen page B battle stat box
extern u8 const gUnk_083080AC[]; // tsa: statscreen page B equipped weapon background

extern i16 const gEfxNoDmgBgShakeOff[];
extern i16 const gEfxQuakePureVec1[];
extern i16 const gEfxQuakePureVec2[];
extern i16 const gEfxQuakePureVec3[];
extern i16 const gEfxQuakePureVec4[];
extern i16 const gEfxQuakePureVec5[];
extern i16 const gEfxQuakePureVec6[];
extern i16 const gEfxQuakeVec_08111E14[];
extern i16 const gEfxQuakePureVec7[];
extern i16 const gEfxQuakePureVec8[];
extern i16 const gEfxQuakePureVec9[];
extern i16 const gEfxQuakePureVec10[];
extern i16 const gEfxQuakePureVec11[];
extern i16 const gEfxQuakeVec_08111F30[];
extern i16 const gEfxQuakeVec_08111FC6[];
// extern ??? gUnk_081120F8
// extern ??? gUnk_08112122
// extern ??? gUnk_08112144
// extern ??? gUnk_08112234
// extern ??? gUnk_0811223E
// extern ??? gUnk_08112248
// extern ??? gUnk_08112252
// extern ??? gUnk_0811225C
// extern ??? gUnk_08112266
// extern ??? gUnk_08112270
// extern ??? gUnk_0811227A
// extern ??? gUnk_08112284
// extern ??? gUnk_0811228E
// extern ??? gUnk_08112298
// extern ??? gUnk_081122C0
// extern ??? gUnk_081122C5
// extern ??? gUnk_081122CA
// extern ??? gUnk_081122D0
// extern ??? gUnk_081122DA
// extern ??? gUnk_08112370
// extern ??? gUnk_081125E0
// extern ??? gUnk_081127F0
// extern ??? gUnk_08112840
// extern ??? gUnk_081128AC
// extern ??? gUnk_081128FC
// extern ??? gUnk_08112968
// extern ??? gUnk_08112A1C
// extern ??? gUnk_08112AD0
// extern ??? gUnk_08112BA4
// extern ??? gUnk_08112C84
// extern ??? gUnk_08112CD4
// extern ??? gUnk_08112D54
// extern ??? gUnk_08112DF4
// extern ??? gUnk_08113024
// extern ??? gUnk_081131A4
extern u16 Pal_08113224[];
// extern ??? gUnk_08113424
// extern ??? gUnk_081134A4
// extern ??? gUnk_081134C4
extern u16 const Pal_BanimUnitFlashing[];
extern u8 const Img_EkrExpBar[];
extern u8 const Img_EkrExpBarChange[];
extern u8 const Img_BarNumfx[];
extern u8 const Tsa_EkrExpBar[];
extern u16 const Pal_EkrExpBar[];
// extern ??? gUnk_08113D70
// extern ??? gUnk_08113F98
// extern ??? gUnk_08113FB8
// extern ??? gUnk_08113FD8
// extern ??? gUnk_08113FF8
// extern ??? gUnk_0811446C
// extern ??? gUnk_0811490C
extern u8 const Img_LevelUpFrame[]; // img (stat gains)
extern u8 const Tm_LevelUpFrame[]; // tiles (stat gains)
extern u16 const Pal_LevelUpFrame[]; // pal (stat gains)
// extern ??? gUnk_081150E8
// extern ??? gUnk_081152FC
// extern ??? gUnk_0811531C
// extern ??? gUnk_08115378
// extern ??? gUnk_08115478
// extern ??? gUnk_08115498
// extern ??? gUnk_08115524
// extern ??? gUnk_08117B90
// extern ??? gUnk_08118330
// extern ??? gUnk_08119CD8
// extern ??? gUnk_08119CDC
// extern ??? gUnk_08119D56
// extern ??? gUnk_08119D78
// extern ??? gUnk_08119DEA
// extern ??? gUnk_08119E30
// extern ??? gUnk_08119ED2
// extern ??? gUnk_08119EDC
// extern ??? gUnk_08119F1E
// extern ??? gUnk_08119F50
// extern ??? gUnk_08119FA6
// extern ??? gUnk_08119FFC
// extern ??? gUnk_0811A06A
// extern ??? gUnk_0811A098
// extern ??? gUnk_0811A0DE
// extern ??? gUnk_0811A0E8
// extern ??? gUnk_0811A102
// extern ??? gUnk_0811A134
// extern ??? gUnk_0811A1AA
// extern ??? gUnk_0811A218
// extern ??? gUnk_0811A276
// extern ??? gUnk_0811A27C
// extern ??? gUnk_0811A302
// extern ??? gUnk_0811A478
// extern ??? gUnk_0811A50E
// extern ??? gUnk_0811A520
// extern ??? gUnk_0811A530
// extern ??? gUnk_0811A59E
// extern ??? gUnk_0811A5AC
// extern ??? gUnk_0811A602
// extern ??? gUnk_0811A618
// extern ??? gUnk_0811A62A
// extern ??? gUnk_0811A668
// extern ??? gUnk_0811A67A
// extern ??? gUnk_0811A680
// extern ??? gUnk_0811A722
// extern ??? gUnk_0811A758
// extern ??? gUnk_0811A796
// extern ??? gUnk_0811A898
// extern ??? gUnk_0811A89E
// extern ??? gUnk_0811A8A4
// extern ??? gUnk_0811A8AA
// extern ??? gUnk_0811A8B0
// extern ??? gUnk_0811A8F2
// extern ??? gUnk_0811A934
// extern ??? gUnk_0811A966
// extern ??? gUnk_0811A9A8
// extern ??? gUnk_0811A9BA
// extern ??? gUnk_0811A9C2
// extern ??? gUnk_0811A9CA
// extern ??? gUnk_0811AACC
// extern ??? gUnk_0811AAD2
// extern ??? gUnk_0811ABB0
// extern ??? gUnk_0811ABE6
// extern ??? gUnk_0811AC30
// extern ??? gUnk_0811AD32
// extern ??? gUnk_0811AD68
// extern ??? gUnk_0811AE34
// extern ??? gUnk_0811AE76
// extern ??? gUnk_0811AEA0
// extern ??? gUnk_0811AEB6
// extern ??? gUnk_0811AEBC
// extern ??? gUnk_0811AEDE
// extern ??? gUnk_0811AF00
// extern ??? gUnk_0811AF20
// extern ??? gUnk_0811AF52
// extern ??? gUnk_0811AF5C
// extern ??? gUnk_0811AF9E
// extern ??? gUnk_0811AFA4
// extern ??? gUnk_0811AFE8
// extern ??? gUnk_0811B3E8
// extern ??? gUnk_0811B408
// extern ??? gUnk_0811B444
// extern ??? gUnk_0811B674
// extern ??? gUnk_0811B694
// extern ??? gUnk_0811B8B0
// extern ??? gUnk_0811B8D0
// extern ??? gUnk_0811BAE8
// extern ??? gUnk_0811BB08
// extern ??? gUnk_0811BD24
// extern ??? gUnk_0811BD44
// extern ??? gUnk_0811BF70
// extern ??? gUnk_0811BF90
// extern ??? gUnk_0811C1D8
// extern ??? gUnk_0811C1F8
// extern ??? gUnk_0811C430
// extern ??? gUnk_0811C450
// extern ??? gUnk_0811C6B4
// extern ??? gUnk_0811C6D4
// extern ??? gUnk_0811C944
// extern ??? gUnk_0811C964
// extern ??? gUnk_0811CAD8
// extern ??? gUnk_0811CAF8
// extern ??? gUnk_0811CD14
// extern ??? gUnk_0811D0D4
// extern ??? gUnk_0811E36C
// extern ??? gUnk_0811F22C
// extern ??? gUnk_0811F32C
// extern ??? gUnk_0811F6F4
// extern ??? gUnk_081203F4
// extern ??? gUnk_08120414
// extern ??? gUnk_08120CB4
// extern ??? gUnk_08121498
// extern ??? gUnk_081214B8
// extern ??? gUnk_081214D8
// extern ??? gUnk_081214F8
// extern ??? gUnk_08122A3C
// extern ??? gUnk_08123B1C
// extern ??? gUnk_08123D1C
// extern ??? gUnk_081241BC
// extern ??? gUnk_08124618
// extern ??? gUnk_081246D8
// extern ??? gUnk_081246F8
// extern ??? gUnk_0812479C
// extern ??? gUnk_08124B64
// extern ??? gUnk_08127778
// extern ??? gUnk_08129504
// extern ??? gUnk_0812A258
// extern ??? gUnk_0812B19C
// extern ??? gUnk_0812BE10
// extern ??? gUnk_0812C1BC
// extern ??? gUnk_0812C62C
// extern ??? gUnk_0812C64C
// extern ??? gUnk_0812C66C
// extern ??? gUnk_0812C68C
// extern ??? gUnk_0812CF48
// extern ??? gUnk_0812D374
// extern ??? gUnk_0812D80C
// extern ??? gUnk_0812D8AC
// extern ??? gUnk_0812E4A4
// extern ??? gUnk_0812F9DC
// extern ??? gUnk_0812FFD8
// extern ??? gUnk_08138BF0
// extern ??? gUnk_0813A6F8
// extern ??? gUnk_0813B6B4
// extern ??? gUnk_0813B8B4
// extern ??? gUnk_0813BA64
// extern ??? gUnk_0813BAFC
// extern ??? gUnk_0813BD74
// extern ??? gUnk_0813E75C
// extern ??? gUnk_081408CC
// extern ??? gUnk_08141320
// extern ??? gUnk_08142EAC
// extern ??? gUnk_08143A38
// extern ??? gUnk_08143A58
// extern ??? gUnk_08143A78
// extern ??? gUnk_08143A98
// extern ??? gUnk_08143AB8
// extern ??? gUnk_08143DA8
// extern ??? gUnk_08143EE4
// extern ??? gUnk_08144A00
// extern ??? gUnk_0814A498
// extern ??? gUnk_081521C0
// extern ??? gUnk_08152E78
// extern ??? gUnk_08159D98
// extern ??? gUnk_0815B364
// extern ??? gUnk_0815B910
// extern ??? gUnk_0815BED4
// extern ??? gUnk_0815F880
// extern ??? gUnk_0815F8A0
// extern ??? gUnk_08161DDC
// extern ??? gUnk_081621DC
// extern ??? gUnk_0816261C
// extern ??? gUnk_081629D4
// extern ??? gUnk_0816B328
// extern ??? gUnk_08176A4C
// extern ??? gUnk_08176A6C
// extern ??? gUnk_0817AAC0
// extern ??? gUnk_0817AC2C
// extern ??? gUnk_0817AC4C
// extern ??? gUnk_0817B418
// extern ??? gUnk_0817B438
// extern ??? gUnk_0817B8D0
// extern ??? gUnk_0817BBB4
// extern ??? gUnk_0817BBB6
// extern ??? gUnk_08181E60
// extern ??? gUnk_081830F4
// extern ??? gUnk_0818360C
// extern ??? gUnk_0818BBCC
// extern ??? gUnk_0818BBEC
// extern ??? gUnk_0818DD18
// extern ??? gUnk_0818E1E4
// extern ??? gUnk_0818E67C
// extern ??? gUnk_0818EA78
// extern ??? gUnk_0818EA98
// extern ??? gUnk_0818F1F8
// extern ??? gUnk_0818F3D8
// extern ??? gUnk_08193598
// extern ??? gUnk_081935B8
// extern ??? gUnk_08197BE0
// extern ??? gUnk_0819875C
// extern ??? gUnk_0819877C
// extern ??? gUnk_081AAECC
// extern ??? gUnk_081AB190
// extern ??? gUnk_081AB1B0
// extern ??? gUnk_081AB340
// extern ??? gUnk_081ABCA0
// extern ??? gUnk_081ABEA0
// extern ??? gUnk_081AC0F4
// extern ??? gUnk_081AC114
// extern ??? gUnk_081AC90C
// extern ??? gUnk_081AD26C
// extern ??? gUnk_081ADBCC
// extern ??? gUnk_081ADDEC
// extern ??? gUnk_081AE88C
// extern ??? gUnk_081AEA8C
// extern ??? gUnk_081AEC8C
extern u16 const Pal_Unk_081B1710[];
// extern ??? gUnk_081B2348
// extern ??? gUnk_081B3D34
// extern ??? gUnk_081B4254
// extern ??? gUnk_081B4274
// extern ??? gUnk_081B4E9C
// extern ??? gUnk_081B4F9C
// extern ??? gUnk_081B57BC
// extern ??? gUnk_081B6688
// extern ??? gUnk_081B7468
// extern ??? gUnk_081B7650
// extern ??? gUnk_081B7670
// extern ??? gUnk_081B7690
// extern ??? gUnk_081B76B0
// extern ??? gUnk_081B7B48
// extern ??? gUnk_081B7F68
// extern ??? gUnk_081B80A8
// extern ??? gUnk_081B8934
// extern ??? gUnk_081B8E44
// extern ??? gUnk_081B8E64
// extern ??? gUnk_081BB35C
// extern ??? gUnk_081BB37C
// extern ??? gUnk_081BB5E4
// extern ??? gUnk_081BBBB4
// extern ??? gUnk_081BC0A8
extern i16 const FrameLut_EkrManaketefxNormalAttack[];
extern i16 const FrameLut_EkrManaketefxCriticalAttack[];
extern i16 const FrameLut_EkrFaefx[];
// extern ??? gUnk_081BC132
// extern ??? gUnk_081BC140
// extern ??? gUnk_081BC15E
// extern ??? gUnk_081BC17C
// extern ??? gUnk_081BC19A
extern u8 const Img_ManaketeBodyIntro2[];
extern u8 const Img_ManaketeBodyIntro1[];
extern u8 const Img_ManaketeBodyStd[];
extern u8 const Img_081BE490[];
extern const u16 Pal_EkrManaketefx[0xC0];
extern u8 const Tsa_ManaketeBodyIntro2[];
extern u8 const Tsa_ManaketeBodyIntro1[];
extern u8 const Tsa_ManaketeBodyStd[];
extern u8 const Tsa_081BFA34[];
extern u8 const Img_ManaketeObjfx1[];
extern u8 const Img_ManaketeObjfx2[];
extern u8 const Img_ManaketeObjfx3[];
extern u16 const Pal_ManaketeBodyStd[];
extern u8 const Img_EkrIdunn_081C1C94[];
extern u16 const Pal_081C4DE8[];
extern u8 const Tsa_EkrIdunn_081C4E28[];
// extern ??? gUnk_081C5264
// extern ??? gUnk_081C5688
extern u8 const Tsa_EkrIdunn_081C5AAC[];
extern u8 const Img_EkrFaefx[];
extern u16 const Pal_EkrFaefx[];
extern u16 const Tsa_EkrFaefx1[];
extern u16 const Tsa_EkrFaefx2[];
extern u16 const Tsa_EkrFaefx3[];
extern u16 const Tsa_EkrFaefx4[];
extern u16 const Tsa_EkrFaefx5[];
extern u16 const Tsa_EkrFaefx6[];
extern u16 const Tsa_EkrFaefx7[];
extern u16 const Tsa_EkrFaefx8[];
extern u16 const Tsa_EkrFaefx9[];
extern u16 const Tsa_EkrFaefx10[];
extern u16 const Tsa_EkrFaefx11[];
extern u16 const Tsa_EkrFaefx12[];
// extern ??? gUnk_081C9EC8
// extern ??? gUnk_081C9ED6
// extern ??? gUnk_081C9EE8
// extern ??? gUnk_081C9EF4
// extern ??? gUnk_081C9F14
// extern ??? gUnk_081C9F34
// extern ??? gUnk_081C9FA6
// extern ??? gUnk_081C9FEC
// extern ??? gUnk_081CA014
// extern ??? gUnk_081CA03C
// extern ??? gUnk_081CA04C
// extern ??? gUnk_081CA054
// extern ??? gUnk_081CA062
// extern ??? gUnk_081CA070
// extern ??? gUnk_081CAA14
// extern ??? gUnk_081CB404
// extern ??? gUnk_081CC428
// extern ??? gUnk_081CCDE0
// extern ??? gUnk_081CD7AC
// extern ??? gUnk_081CE154
// extern ??? gUnk_081CE474
// extern ??? gUnk_081CE848
// extern ??? gUnk_081CEC7C
// extern ??? gUnk_081CF03C
// extern ??? gUnk_081CF574
// extern ??? gUnk_081CFCB0
// extern ??? gUnk_081D043C

extern u8 const Img_Background_082D80B0[];
extern u8 const Tsa_Background_082DAC8C[];
extern u16 const Pal_Background_082DB140[];
extern u8 const Img_Background_082E28F8[];
extern u8 const Tsa_Background_082E35DC[];
extern u16 const Pal_Background_082E3A90[];
extern u8 const Img_Background_082E3B10[];
extern u8 const Tsa_Background_082E3EC0[];
extern u16 const Pal_Background_082E4374[];
extern u8 const Img_Background_082E4650[];
extern u8 const Tsa_Background_082E6EB4[];
extern u16 const Pal_Background_082E7368[];
extern u8 const Img_Background_082E73E8[];
extern u8 const Tsa_Background_082EADF0[];
extern u16 const Pal_Background_082EB2A4[];
extern u8 const Img_Background_082EB324[];
extern u8 const Tsa_Background_082EDB7C[];
extern u16 const Pal_Background_082EE030[];
extern u8 const Img_Background_082EE0B0[];
extern u8 const Tsa_Background_082EF97C[];
extern u16 const Pal_Background_082EFE30[];
extern u16 const Pal_Background_082EFEB0[];
extern u8 const Img_Background_082EFF30[];
extern u8 const Tsa_Background_082F1490[];
extern u16 const Pal_Background_082F1944[];
extern u8 const Img_Background_082F19C4[];
extern u8 const Tsa_Background_082F3494[];
extern u16 const Pal_Background_082F3948[];
extern u8 const Img_Background_082F39C8[];
extern u8 const Tsa_Background_082F62E0[];
extern u16 const Pal_Background_082F6794[];
extern u16 const Pal_Background_082F6814[];
extern u8 const Img_Background_082F6894[];
extern u8 const Tsa_Background_082F85E8[];
extern u16 const Pal_Background_082F8A9C[];
extern u8 const Img_Background_082F8B1C[];
extern u8 const Tsa_Background_082FBE6C[];
extern u16 const Pal_Background_082FC320[];
extern u8 const Img_Background_082FC3A0[];
extern u8 const Tsa_Background_082FECE0[];
extern u16 const Pal_Background_082FF194[];
extern u8 const Img_Background_082FF214[];
extern u8 const Tsa_Background_08301244[];
extern u16 const Pal_Background_083016F8[];
extern u16 const Pal_Background_08301778[];
extern u16 const Pal_Background_083017F8[];
extern u8 const Img_Background_08301878[];
extern u8 const Tsa_Background_0830491C[];
extern u16 const Pal_Background_08304DD0[];
extern u8 const Img_Background_08304E50[];
extern u8 const Tsa_Background_08306F24[];
extern u16 const Pal_Background_083073D8[];

extern u16 const Pal_Unk_08309474[];
extern u16 const Pal_Unk_083094F4[];
extern u16 const Pal_Unk_0830D5E4[];

extern u8 const Img_MapUiElements[];

extern u16 const Pal_UnitMapUiFrame_Blue[];
extern u16 const Pal_UnitMapUiFrame_Red[];
extern u16 const Pal_UnitMapUiFrame_Green[];

extern u8 const Tsa_UnitMapUi_Frame[];
extern u8 const Tsa_TerrainMapUi_Labels[];
extern u8 const Tsa_TerrainMapUi_BallistaLabels[];
extern u8 const Tsa_TerrainMapUi_ObstacleLabels[];
extern u8 const Tsa_TerrainMapUi_ObstacleFullHp[];
extern u8 const Tsa_TerrainMapUi_Frame[];
extern u8 const Tsa_UnitBurstMapUi_Frame0[];
extern u8 const Tsa_UnitBurstMapUi_Frame1[];
extern u8 const Tsa_UnitBurstMapUi_Frame2[];
extern u8 const Tsa_UnitBurstMapUi_Frame3[];
extern u8 const Tsa_UnitBurstMapUi_Frame4[];
extern u8 const Tsa_UnitBurstMapUi_Frame5[];

extern u16 const Pal_Unk_0833C944[];
extern u8 const Img_Unk_083092CC[];
extern u8 const Img_Unk_0833C378[];

struct HelpBoxInfo;
extern struct HelpBoxInfo CONST_DATA HelpInfo_0868B1B0;
extern struct HelpBoxInfo CONST_DATA HelpInfo_0868B2C8;
extern struct HelpBoxInfo CONST_DATA HelpInfo_0868B3C4;

#endif // UNKNOWN_OBJECTS_H
