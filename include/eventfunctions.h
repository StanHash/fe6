#pragma once

// NOTE: this may end up getting merged with chapterevents

#include "common.h"

#include "proc.h"
#include "event.h"
#include "eventinfo.h"

enum
{
    ENDING_0,
    ENDING_1,
    ENDING_2,
};

struct TutorialEventProcA
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
    /* 66 */ i16 unk_66;
};

struct TutorialEventProcB
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

bool IsHard(void);
// GetHardModeBonusLevelsByPid
void ApplyAllHardModeBonusLevels(void);
bool func_fe6_0806BB34(struct EventInfo * info);
bool func_fe6_0806BB68(struct EventInfo * info);
bool func_fe6_0806BB9C(struct EventInfo * info);
bool func_fe6_0806BBD0(struct EventInfo * info);
// func_fe6_0806BBF8
bool func_fe6_0806BC20(struct EventInfo * info);
bool func_fe6_0806BC5C(struct EventInfo * info);
bool func_fe6_0806BCA4(struct EventInfo * info);
bool func_fe6_0806BCEC(struct EventInfo * info);
bool func_fe6_0806BD34(struct EventInfo * info);
bool func_fe6_0806BD7C(struct EventInfo * info);
bool func_fe6_0806BDC4(struct EventInfo * info);
bool Chapter10B_CheckTalkShannaThea(struct EventInfo * info);
bool Chapter10B_CheckTalkShannaTheaAfterKlein(struct EventInfo * info);
bool Chapter10B_CheckShannaRecruitsThea(struct EventInfo * info);
// func_fe6_0806BE90
// func_fe6_0806BEB8
bool func_fe6_0806BEEC(struct EventInfo * info);
bool func_fe6_0806BF14(struct EventInfo * info);
bool IsGuinivereAround(void);
// func_fe6_0806BF70
// func_fe6_0806BF7C
// func_fe6_0806BF98
// func_fe6_0806BFA4
void RemoveFog(void);
void AddFiveThousandGold(void);
// RemoveGold
// WeakenUnitStats
// WeakenUnitStatsByPid
// IsPidBlueDeployed
bool IsLilinaBlueDeployed(void);
bool IsMarcusBlueDeployed(void);
bool IsMerlinusBlueDeployed(void);
bool IsJunoBlueDeployed(void);
bool IsZelotBlueDeployed(void);
bool IsSinBlueDeployed(void);
bool IsDayanBlueDeployed(void);
bool IsSueBlueDeployed(void);
bool IsMeladyBlueDeployed(void);
bool IsZeissBlueDeployed(void);
bool IsPercivalBlueDeployed(void);
// IsPidBlue
bool IsBorsBlue(void);
bool IsLilinaBlue(void);
bool IsElenBlue(void);
// IsRaighBlue
bool IsSueBlue(void);
// IsCathBlue
bool IsMeladyBlue(void);
bool IsZeissBlue(void);
bool IsSophiaBlue(void);
bool IsJunoBlue(void);
bool IsZelotBlue(void);
bool IsElffinBlue(void);
// IsFaeBlue
bool IsSinBlue(void);
bool IsDayanBlue(void);
bool IsKleinBlue(void);
bool IsTheaBlue(void);
bool IsDouglasBlue(void);
// func_fe6_0806C2C4
bool func_fe6_0806C2F8(void);
bool IsPidNonBlue(fu8 pid);
// IsTheaNonBlue
bool func_fe6_0806C35C(void);
bool IsKleinNonBlue(void);
bool IsCathNonBlue(void);
bool IsHughNonBlue(void);
bool IsGalleNonBlue(void);
bool func_fe6_0806C3AC(void);
bool func_fe6_0806C3BC(void);
bool IsDouglasNonBlue(void);
bool IsPercevalNonBlue(void);
bool func_fe6_0806C3EC(void);
bool func_fe6_0806C3FC(void);
bool func_fe6_0806C40C(void);
// func_fe6_0806C41C
// func_fe6_0806C460
bool IsPastTurn20(void);
bool IsPastTurn25(void);
bool IsPastTurn30(void);
bool IsBluePhase(void);
bool IsRedPhase(void);
bool IsActiveUnitMale(void);
bool func_fe6_0806C524(void);
bool func_fe6_0806C540(void);
bool func_fe6_0806C55C(void);
bool func_fe6_0806C578(void);
bool func_fe6_0806C594(void);
bool AreWeGoingToSacae(void);
void func_fe6_0806C608(void);
bool func_fe6_0806C62C(void);
void func_fe6_0806C64C(void);
void func_fe6_0806C670(void);
bool func_fe6_0806C68C(void);
void func_fe6_0806C69C(void);
void func_fe6_0806C6B0(void);
void func_fe6_0806C718(void);
void func_fe6_0806C734(void);
void func_fe6_0806C750(void);
// func_fe6_0806C76C
void func_fe6_0806C7BC(struct TutorialEventProcA * proc);
void func_fe6_0806C7E0(struct TutorialEventProcA * proc);
void func_fe6_0806C948(struct TutorialEventProcB * proc);
void func_fe6_0806C950(struct TutorialEventProcB * proc);
// func_fe6_0806C998
bool func_fe6_0806C9F8(void);
void func_fe6_0806CA1C(void);
void func_fe6_0806CA30(void);
void func_fe6_0806CA44(void);
void func_fe6_0806CA58(void);
void func_fe6_0806CA6C(void);
void func_fe6_0806CA84(void);
void func_fe6_0806CA98(void);
void func_fe6_0806CAAC(void);
void func_fe6_0806CAC4(void);
void func_fe6_0806CAD8(void);
void func_fe6_0806CAEC(void);
void func_fe6_0806CB00(void);
void func_fe6_0806CB18(void);
// func_fe6_0806CB2C
void func_fe6_0806CB40(void);
void func_fe6_0806CB54(void);
void func_fe6_0806CB6C(void);
void func_fe6_0806CB80(void);
void func_fe6_0806CB94(void);
void func_fe6_0806CBA8(void);
void func_fe6_0806CBBC(void);
bool IsActiveUnitRoy(void);
bool IsActiveUnitWolt(void);
bool IsActiveUnitLilina(void);
// IsActiveUnitAlen
bool func_fe6_0806CC68(void);
bool IsCombatAction(void);
bool func_fe6_0806CC94(void);
// func_fe6_0806CCC0
void func_fe6_0806CCC4(void);
bool IsAnyTutorialUnitDamaged(void);
bool IsAnyTutorialUnitPastColumn16(void);
bool IsBossDefeated(void);
// IsPastTurn1
bool func_fe6_0806CDC0(void);
bool func_fe6_0806CE18(void);
bool func_fe6_0806CE34(void);
bool func_fe6_0806CE50(void);
bool func_fe6_0806CE80(void);
bool func_fe6_0806CEAC(void);
void RefreshClarine(void);
bool func_fe6_0806CEF0(void);
bool func_fe6_0806CF3C(void);
void Chapter8_WeakenNorthWestWall(void);
// func_fe6_0806CFA0
void func_fe6_0806CFB8(void);
void func_fe6_0806CFD0(void);
// func_fe6_0806CFE8
void func_fe6_0806D000(void);
void func_fe6_0806D01C(void);
bool func_fe6_0806D028(void);
void func_fe6_0806D064(void);
void func_fe6_0806D0E4(void);
// func_fe6_0806D0FC
bool func_fe6_0806D150(void);
void func_fe6_0806D17C(void);
void func_fe6_0806D194(void);
void func_fe6_0806D1AC(void);
void func_fe6_0806D1D4(void);
bool func_fe6_0806D1FC(struct EventProc * proc);
bool func_fe6_0806D35C(void);
bool func_fe6_0806D398(void);
bool func_fe6_0806D3B4(void);
void func_fe6_0806D3E0(void);
void func_fe6_0806D41C(void);
void func_fe6_0806D55C(void);
void func_fe6_0806D568(void);
void func_fe6_0806D620(void);
void func_fe6_0806D648(void);
void func_fe6_0806D6B4(void);
void func_fe6_0806D6D8(void);
void func_fe6_0806D77C(void);
// func_fe6_0806D7C8
// func_fe6_0806D7E4
// func_fe6_0806D7F4
// func_fe6_0806D808
// func_fe6_0806D81C
// func_fe6_0806D82C
// func_fe6_0806D850
// func_fe6_0806D868
// func_fe6_0806D894
// func_fe6_0806D8B0
// func_fe6_0806D9B4
// func_fe6_0806D9F4
// func_fe6_0806DA54
// func_fe6_0806DA90
// func_fe6_0806DAA0
// func_fe6_0806DAB0
// func_fe6_0806DAC0
// func_fe6_0806DAD0
// func_fe6_0806DAF0
void func_fe6_0806DB00(int arg_0, ProcPtr proc);
// func_fe6_0806DB2C
// func_fe6_0806DB38
// func_fe6_0806DB58
// func_fe6_0806DB88
// func_fe6_0806DBA0
// func_fe6_0806DBA8
// func_fe6_0806DC24
// func_fe6_0806DC38
// func_fe6_0806DC48
// func_fe6_0806DC50
// func_fe6_0806DC90
// func_fe6_0806DCA4
// func_fe6_0806DD08
// func_fe6_0806DD84
// func_fe6_0806DD98
// func_fe6_0806DDC4
// func_fe6_0806DDCC
void func_fe6_0806DDD4(void);
// func_fe6_0806DDE0
void func_fe6_0806DE00(void);
void func_fe6_0806DE20(void);
// func_fe6_0806DE40
// func_fe6_0806DE5C
// func_fe6_0806DE78
// func_fe6_0806DEA0
// func_fe6_0806DEB4
// func_fe6_0806DEC4
// func_fe6_0806DEF8
// func_fe6_0806DF18
// func_fe6_0806DF3C
// func_fe6_0806DF94
// func_fe6_0806DFAC
// func_fe6_0806DFC4
// func_fe6_0806DFD0
// func_fe6_0806DFD8
// func_fe6_0806E004
// func_fe6_0806E040
// func_fe6_0806E04C
// func_fe6_0806E060
// func_fe6_0806E074
// func_fe6_0806E0B8
// func_fe6_0806E178
// func_fe6_0806E240
void func_fe6_0806E278(void);
void UpdateEndingId(void);
fu8 GetEndingId(void);
void StartGameEndingScene(ProcPtr parent);
// func_fe6_0806E32C
// func_fe6_0806E36C
// func_fe6_0806E430
// func_fe6_0806E50C
// func_fe6_0806E520
void func_fe6_0806E684(int arg_0, int arg_1);
// func_fe6_0806E714
// func_fe6_0806E730
// func_fe6_0806E73C
// func_fe6_0806E7A0
// func_fe6_0806E7BC
// func_fe6_0806E7D8
// func_fe6_0806E7F4
// func_fe6_0806E810
