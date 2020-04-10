
#pragma once

#include "gba/gba.h"
#include "types.h"

#include "proc.h"

enum
{
    BACKGROUND_0,
    BACKGROUND_1,
    BACKGROUND_2,
    BACKGROUND_3,
    BACKGROUND_4,
    BACKGROUND_5,
    BACKGROUND_6,
    BACKGROUND_7,
    BACKGROUND_8,
    BACKGROUND_9,
    BACKGROUND_10,
    BACKGROUND_11,
    BACKGROUND_12,
    BACKGROUND_13,
    BACKGROUND_14,
    BACKGROUND_15,
    BACKGROUND_16,
    BACKGROUND_17,
    BACKGROUND_18,
    BACKGROUND_19,
    BACKGROUND_20,
};

void DisableEventSkip(void);
ProcPtr StartEvent(u32 const* script);
ProcPtr StartEventLocking(u32 const* script, ProcPtr parent);
void DisplayBackground(int background);
void DisplayBackgroundNoClear(int background);
void TryMoveUnit(struct Unit* unit, int x, int y, s8 moveClosest);
Bool TryMoveUnitDisplayed(ProcPtr proc, struct Unit* unit, int x, int y);
int GetNextAvailableBlueUnitId(int start);
Bool UnitInfoRequiresNoMovement(struct UnitInfo const* info);
int EventGotoLabel(ProcPtr proc, int label);
int EventEndBattleMap(ProcPtr proc);
void ClearTalk(void);
void sub_8011F4C(void);
void sub_8011F64(void);
Bool IsEventRunning(void);
Bool IsEventProcRunning(void);
void KillTalkAndEvent(void);
void SetFightEventFaceConfig(void);
ProcPtr StartTalkEvent(int msgid);
ProcPtr StartTalkSupportEvent(int msgid);
void StartPopup_08012040(u16 item, ProcPtr parent);
void StartPopup_08012070(u16 item, ProcPtr parent);
void StartPopup_080120A0(u16 item, ProcPtr parent);
void StartPopup_080120D0(int amount, ProcPtr parent);
void StartPopup_08012120(u16 item, ProcPtr parent);
void StartPopup_08012178(u16 item, ProcPtr parent);
void StartSupportLevelGaindPopup(ProcPtr parent);
void StartGiveItem(struct Unit* unit, u16 iid, ProcPtr parent);
void StartGiveItemEvent(u16 iid);
void StartGiveItemToEvent(u16 pid, u16 iid);
void StartGiveMoneyEvent(int amount);
void StartMapChangeEvent(u8 id);
void StartChestItemEvent(u16 iid, u8 id);
void StartChestMoneyEvent(int amount, u8 id);
void SetEventTalkSkipped(void);
int GetPlayerDeployCount(void);
void InitPlayerDeployUnits(void);
void InitPlayerDeployUnitPositions(void);
