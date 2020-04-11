
#pragma once

#include "gba/gba.h"
#include "types.h"

#include "proc.h"
#include "text.h"

void Decompress(void const* src, void* dst);
int sub_8013B24(int, int, int, int, int);
void sub_8013C18(char const* src, char* dst);
void sub_8013E58(u16* tm, int tileref, int width, int height);
void sub_80141E0(int palid, int arg_2, ProcPtr proc);
void sub_8014218(u16 const* pal, int palid, int arg_2, ProcPtr proc);
void sub_8014374(int pal);
void sub_8014BAC(ProcPtr proc, int arg_1);
int sub_8014BE4(int number, char* buf);
void sub_80151A8(Func func, int time);
int sub_80184F0(struct Unit* unit);
int sub_8028E98(void);
char* MsgDecode(int msg);
void LoadObjUiGfx(void);
void sub_80415CC(int x, int y);
s8 sub_80425C4(void);
void sub_8069C34(void);
void sub_806A218(u16 yStart, u16 yEnd, int arg_2, int arg_3);
void sub_8094030(int arg_0, int arg_1, int arg_2, ProcPtr proc);
void sub_8095FC4(void);
void sub_8095FF8(void);
void LockGame(void);
void UnlockGame(void);
struct ChapterInfo const* GetChapterInfo(int id);
void LoadUiFrameGraphics(void);
char const* sub_8017130(int item);
int sub_80172D8(int item);
void sub_8041358(int x, int y, int width, int height, int winKind);
struct Unit* GetUnitByCharId(int pid);
struct Unit* GetUnit(int uid);
struct Unit* LoadUnit(struct UnitInfo const* info);
void sub_80178F4(struct Unit* unit, int levels);
void RefreshEntityMaps(void);
void RefreshSMS(void);
void sub_80146F8(ProcPtr proc);
void StartBlockingFadeOutBlack(int arg_0, ProcPtr parent);
void StartBlockingFadeOutBlackMedium(ProcPtr parent);
void sub_80292DC(void);
void UnlockBattleMapDisplay(void);
void sub_806095C(void);
void FillBmMap(u8** map, int value);
void EndMapMain(void);
void sub_8014AF8(void);
void sub_8061704(void);
s8 sub_802CB60(void);
s8 BattleMapFadeExists(void);
s8 sub_8093444(void);
void LockBattleMapDisplay(void);
void BlockAllProcsMarked4(void);
short sub_8015E44(int x);
short sub_8015E88(int y);
void sub_801600C(int x, int y);
Bool EnsureCameraOntoPosition(ProcPtr proc, int x, int y);
void RedrawBattleMap(void);
void ApplyMoveScriptToCoordinates(int* x, int* y, u8 const* movescr);
void TryMoveUnit(struct Unit* unit, int x, int y, s8 moveClosest);
Bool GetUnitClosestValidPosition(struct Unit* unit, short x, short y, struct Vec2* out);
void UnitUpdateRescueePosition(struct Unit* unit);
void sub_80193F4(int x, int y, s8 const* movTable);
void sub_8019600(int x, int y, u8* output);
void HideUnitSMS(struct Unit* unit);
void sub_8022A5C(struct Unit* unit);
void sub_8021FE8(void);
Bool CheckFlag(int flagId);
void PrepareBattleMapFade(void);
void ApplyMapChange(int id);
void AddMapChangeTrap(int id);
void RefreshTerrainMap(void);
void UpdateRoofedUnits(void);
void StartBattleMapFade(Bool locksGame);
int GetMapChangeIdByPosition(int x, int y);
void UnitChangeFaction(struct Unit* unit, int faction);
void sub_8015F1C(int x, int y, int arg_2);
void ClearUnit(struct Unit* unit);
void SetEid(int flag);
void ClearEid(int flag);
void SetNextChapterId(int chapter);
void SetNextGameAction(int action);
void sub_8014708(ProcPtr parent);
void sub_8029084(void);
void sub_8029370(void);
u16 sub_8015ECC(int x);
u16 sub_8015EF4(int y);
void InitUiGraphics(void);
void UnpackChapterMapPalette(void);
void ApplyMapSpritePalettes(void);
void sub_8014748(ProcPtr parent);
void StartBlockingFadeInBlack(int duration, ProcPtr parent);
void StartBlockingFadeOutBlack(int duration, ProcPtr parent);
void sub_8014680(int duration, ProcPtr parent);
void sub_8014698(int duration, ProcPtr parent);
int GetMoney(void);
void SetMoney(int amount);
u8 GetGameLogicLock(void);
void SetActiveUnit(struct Unit* unit);
int GetItemType(int item);
void BattleInitItemEffect(struct Unit* instigator, int itemSlot);
void BattleInitItemEffectTarget(struct Unit* unit);
void BattleGenerateReal(struct Unit* instigator, struct Unit* target);
void BattleGenerateBallistaReal(struct Unit* instigator, struct Unit* target);
void ClearBattleHits(void);
void sub_80260CC(void);
void sub_80260DC(void);
void sub_8025C7C(void);
void sub_802EDC4(void);
void sub_8028E80(int weather);
void sub_80922B0(void);
void sub_80933F8(void);
void StartWMIntroRotation(ProcPtr parent);
void PlayWMIntroBGM(void);
void sub_80928DC(int x, int y, ProcPtr parent);
void sub_809347C(int x, int y);
void sub_8092CD8(ProcPtr parent);
void sub_80934A0(void);
void sub_8092E94(void);
Bool sub_8092E68(void);
void sub_8093518(void);
void sub_80934BC(int x, int y);
void StartWMHighlight(int arg_0, int id);
void sub_80939A8(int id);
s8 WMHighlightExists(int id);
s8 sub_80939D0(void);
void sub_80939F0(int palid, int x, int y, int id);
void EndWMDot(int id);
void StartWMFlag(int palid, int x, int y, int id);
void EndWMFlag(int id);
void StartWMMapText(int xA, int yA, int unk, int xB, int yB, int id);
void sub_8093BB4(int id);
void sub_80149B0(ProcPtr proc);
void sub_8014758(ProcPtr proc);
void sub_8014768(ProcPtr proc);
int sub_801650C(int iid);
void sub_801C5B0(struct Unit* unit, int item, ProcPtr parent);
struct UnitInfo const* sub_806B638(void);

extern struct BmSt gBmSt;
extern struct PlaySt gPlaySt;
extern struct Unit* gActiveUnit;
extern u8** gMapUnit;
extern u8** gMapTerrain;
extern u8** gMapOther;
extern u8 gMoveScrBuf[0x40];
extern struct BattleUnit gBattleUnitA;
extern struct BattleUnit gBattleUnitB;
extern struct BattleHit* gBattleHitIt;
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
extern struct ProcScr CONST_DATA ProcScr_Unk_085C8080[];
extern struct ProcScr CONST_DATA ProcScr_CamMove[];
extern struct FaceInfo CONST_DATA FaceInfoTable[];

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

#define UNIT_FACTION(unit) ((unit)->id & 0xC0)

#define FOR_UNITS(begin, end, varName, body) \
{ \
    int _uid; \
    struct Unit* varName; \
    for (_uid = (begin); _uid < (end); ++_uid) \
    { \
        varName = GetUnit(_uid); \
        if (!varName) \
            continue; \
        if (!varName->person) \
            continue; \
        body \
    } \
}

#define FOR_UNITS_FACTION(faction, varName, body) \
    FOR_UNITS((faction) + 1, (faction) + 0x40, varName, body)

#define FOR_UNITS_ALL(varName, body) \
    FOR_UNITS(1, 0xC0, varName, body)
