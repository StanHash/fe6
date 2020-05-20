
#pragma once

#include "gba/gba.h"
#include "types.h"

#include "proc.h"
#include "text.h"

extern u8 gBuf[];

extern struct Vec2 gMapSize;
extern u8** gMapUnit;
extern u8** gMapTerrain;
extern u8** gMapMovement;
extern u8** gMapHidden;
extern u8** gMapOther;
extern u8 gMoveScrBuf[0x40];
extern struct BattleUnit gBattleUnitA;
extern struct BattleUnit gBattleUnitB;
extern struct BattleHit* gBattleHitIt;
extern struct Action gAction;
extern struct AiDecision gAiDecision;

extern struct ProcScr CONST_DATA ProcScr_EventWaitForMu[];
extern struct ProcScr CONST_DATA ProcScr_FlashCursor[];
extern struct ProcScr CONST_DATA ProcScr_EventCursor[];
extern struct ProcScr CONST_DATA ProcScr_WeatherChangeFade[];
extern struct ProcScr CONST_DATA ProcScr_WmEventShowFace[];
extern struct ProcScr CONST_DATA ProcScr_WmEventHideFace[];
extern struct ProcScr CONST_DATA ProcScr_WmEventMoveFace[];
extern struct Glyph const* CONST_DATA TextGlyphs_Special[];
extern struct Glyph const* CONST_DATA TextGlyphs_System[];
extern struct Glyph const* CONST_DATA TextGlyphs_Talk[];
extern u16 CONST_DATA Pal_SystemText[];
extern u16 CONST_DATA Pal_TalkText[];
extern u16 CONST_DATA Pal_GreenTextColors[];
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
extern struct ProcScr CONST_DATA ProcScr_Unk_085C8080[];
extern struct ProcScr CONST_DATA ProcScr_CamMove[];
extern struct FaceInfo CONST_DATA FaceInfoTable[];
extern struct ProcScr CONST_DATA ProcScr_OpeningSequence[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08691480[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0868C304[];
extern struct ProcScr CONST_DATA ProcScr_PlayerPhase[];
extern struct ProcScr CONST_DATA ProcScr_AiPhase[];
extern struct ProcScr CONST_DATA ProcScr_UpdateTraps[];
extern struct ProcScr CONST_DATA ProcScr_PrepScreen[];
extern struct ProcScr CONST_DATA ProcScr_ChapterIntro[];
extern struct ProcScr CONST_DATA ProcScr_InitPhaseCursor[];
extern struct ProcScr CONST_DATA ProcScr_PhaseIntro[];
extern struct ProcScr CONST_DATA ProcScr_StatusDecayDisplay[];
extern struct ProcScr CONST_DATA ProcScr_TerrainHealDisplay[];
extern struct ProcScr CONST_DATA ProcScr_PoisonDamageDisplay[];
extern struct ProcScr CONST_DATA ProcScr_BerserkPhase[];

extern u8 CONST_DATA Effectiveness_FlyingClasses[];
extern u8 CONST_DATA MoveTable_Unk_0860C912[];

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
