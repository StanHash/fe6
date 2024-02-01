#pragma once

#include "prelude.h"

// Event command ids

enum
{
    EVT_CMD_END,
    EVT_CMD_KILL,
    EVT_CMD_SLEEP,
    EVT_CMD_BACKGROUND,
    EVT_CMD_BACKGROUNDMORE,
    EVT_CMD_CLEARTALK,
    EVT_CMD_CLEARSKIP,
    EVT_CMD_TALK,
    EVT_CMD_TALKMORE,
    EVT_CMD_TALKAUTO,
    EVT_CMD_TALKCONT,
    EVT_CMD_CAMERA_POS,
    EVT_CMD_CAMERA_PID,
    EVT_CMD_MOVE_POS,
    EVT_CMD_MOVE_POS_MANUAL,
    EVT_CMD_MOVE_PID,
    EVT_CMD_MOVE_PID_MANUAL,
    EVT_CMD_MOVE_PID_NEXTTO,
    EVT_CMD_LOADUNITS,
    EVT_CMD_LOADUNITS_PARTY,
    EVT_CMD_MOVEWAIT,
    EVT_CMD_UNITCAM_ON,
    EVT_CMD_UNITCAM_OFF,
    EVT_CMD_FUNC,
    EVT_CMD_FUNC_UNTIL,
    EVT_CMD_FUNC_WHILE,
    EVT_CMD_STOP,
    EVT_CMD_LABEL,
    EVT_CMD_GOTO,
    EVT_CMD_GOTO_IFN_ALIVE,
    EVT_CMD_GOTO_IFN_INTEAM,
    EVT_CMD_GOTO_IFY_FUNC,
    EVT_CMD_GOTO_IFN_FUNC,
    EVT_CMD_GOTO_IFY_SKIPPED,
    EVT_CMD_GOTO_IFY_FLAG,
    EVT_CMD_GOTO_IFN_FLAG,
    EVT_CMD_GOTO_IFY_ACTIVE,
    EVT_CMD_JUMP,
    EVT_CMD_ITEM,
    EVT_CMD_ITEM_PID,
    EVT_CMD_MONEY,
    EVT_CMD_MAPCHANGE,
    EVT_CMD_MAPCHANGE_POS,
    EVT_CMD_FACTION,
    EVT_CMD_FLASHCURSOR_POS,
    EVT_CMD_FLASHCURSOR_PID,
    EVT_CMD_CURSOR,
    EVT_CMD_CLEARCURSOR,
    EVT_CMD_REMOVEUNIT,
    EVT_CMD_REMOVEUNIT_DISPLAYED,
    EVT_CMD_SETAI_PID,
    EVT_CMD_SETAI_POS,
    EVT_CMD_SETFLAG,
    EVT_CMD_CLEARFLAG,
    EVT_CMD_BGM,
    EVT_CMD_BGM_OVERRIDE,
    EVT_CMD_BGM_RESTORE,
    EVT_CMD_BGM_FADEOUT,
    EVT_CMD_BGM_LOWER_ON,
    EVT_CMD_BGM_LOWER_OFF,
    EVT_CMD_SE,
    EVT_CMD_CHAPTER,
    EVT_CMD_GAMEEND,
    EVT_CMD_SETMAP,
    EVT_CMD_NOSKIP,
    EVT_CMD_NOSKIP_NOTEXTSKIP,
    EVT_CMD_YESSKIP,
    EVT_CMD_FADE_TOBLACK,
    EVT_CMD_FADE_FROMBLACK,
    EVT_CMD_FADE_TOWHITE,
    EVT_CMD_FADE_FROMWHITE,
    EVT_CMD_EXIT_MAP,
    EVT_CMD_ENTER_MAP,
    EVT_CMD_FIGHTSCR,
    EVT_CMD_NOCLEARTALK,
    EVT_CMD_FUNC_ONSKIP,
    EVT_CMD_WEATHER,
    EVT_CMD_WM_START,
    EVT_CMD_WM_END,
    EVT_CMD_WM_ZOOMTO,
    EVT_CMD_WM_ZOOMBACK,
    EVT_CMD_WM_PUTFACE,
    EVT_CMD_WM_REMOVEFACE,
    EVT_CMD_WM_MOVEFACE,
    EVT_CMD_WM_NOP54,
    EVT_CMD_WM_NOP55,
    EVT_CMD_WM_TALK,
    EVT_CMD_WM_TALKBOX_BOTTOM,
    EVT_CMD_WM_TALKBOX_TOP,
    EVT_CMD_WM_TALKBOX_REMOVE,
    EVT_CMD_WM_ARROW,
    EVT_CMD_WM_HIGHLIGHT,
    EVT_CMD_WM_HIGHLIGHT_REMOVE,
    EVT_CMD_WM_HIGHLIGHT_REMOVEBOTH,
    EVT_CMD_WM_DOT,
    EVT_CMD_WM_DOT_REMOVE,
    EVT_CMD_WM_FLAG,
    EVT_CMD_WM_FLAG_REMOVE,
    EVT_CMD_WM_MAPTEXT,
    EVT_CMD_WM_MAPTEXT_REMOVE,
};

// Event command macros
// EventScr const EventScr_<Name>[] = { /* to be used here */ };

#define _EvtParams2(x, y) ((((y) & 0xFFFF) << 16) + ((x) & 0xFFFF))
#define _EvtParams4(a, b, c, d) ((((d) & 0xFF) << 24) + (((c) & 0xFF) << 16) + (((b) & 0xFF) << 8) + ((a) & 0xFF))

#define EvtEnd \
    EVT_CMD_END,

#define EvtKill \
    EVT_CMD_KILL,

#define EvtSleep(duration) \
    EVT_CMD_SLEEP, (duration),

#define EvtBackground(background) \
    EVT_CMD_BACKGROUND, (background),

#define EvtBackgroundMore(background) \
    EVT_CMD_BACKGROUNDMORE, (background),

#define EvtClearTalk \
    EVT_CMD_CLEARTALK,

#define EvtClearSkip \
    EVT_CMD_CLEARSKIP,

#define EvtTalk(msgid) \
    EVT_CMD_TALK, (msgid),

#define EvtTalkMore(msgid) \
    EVT_CMD_TALKMORE, (msgid),

#define EvtTalkAuto \
    EVT_CMD_TALKAUTO,

#define EvtTalkContinue \
    EVT_CMD_TALKCONT,

#define EvtCamera(x, y) \
    EVT_CMD_CAMERA_POS, _EvtParams2(x, y),

#define EvtCameraUnit(pid) \
    EVT_CMD_CAMERA_PID, (pid),

#define EvtMove(x, y, x_to, y_to) \
    EVT_CMD_MOVE_POS, _EvtParams2(x, y), _EvtParams2(x_to, y_to),

#define EvtMoveScript(x, y, movescript) \
    EVT_CMD_MOVE_POS_MANUAL, _EvtParams2(x, y), (EventScr) (movescript),

#define EvtMoveUnit(pid, x_to, y_to) \
    EVT_CMD_MOVE_PID, (pid), _EvtParams2(x_to, y_to),

#define EvtMoveUnitScript(pid, movescript) \
    EVT_CMD_MOVE_PID_MANUAL, (pid), (EventScr) (movescript),

#define EvtMoveUnitNextTo(pid, pid_to) \
    EVT_CMD_MOVE_PID_NEXTTO, (pid), (pid_to),

#define EvtLoadUnits(info) \
    EVT_CMD_LOADUNITS, (EventScr) (info),

#define EvtLoadUnitsParty(info) \
    EVT_CMD_LOADUNITS_PARTY, (EventScr) (info),

#define EvtMoveWait \
    EVT_CMD_MOVEWAIT,

#define EvtUnitCameraOn \
    EVT_CMD_UNITCAM_ON,

#define EvtUnitCameraOff \
    EVT_CMD_UNITCAM_OFF,

#define EvtFunc(func) \
    EVT_CMD_FUNC, (EventScr) (func),

#define EvtFuncUntil(func) \
    EVT_CMD_FUNC_UNTIL, (EventScr) (func),

#define EvtFuncWhile(func) \
    EVT_CMD_FUNC_WHILE, (EventScr) (func),

#define EvtStop \
    EVT_CMD_STOP,

#define EvtLabel(id) \
    EVT_CMD_LABEL, (id),

#define EvtGoto(id) \
    EVT_CMD_GOTO, (id),

#define EvtGotoIfNotAlive(id, pid) \
    EVT_CMD_GOTO_IFN_ALIVE, (id), (pid),

#define EvtGotoIfNotInTeam(id, pid) \
    EVT_CMD_GOTO_IFN_INTEAM, (id), (pid),

#define EvtGotoIfFunc(id, func) \
    EVT_CMD_GOTO_IFY_FUNC, (id), (EventScr) (func),

#define EvtGotoIfNotFunc(id, func) \
    EVT_CMD_GOTO_IFN_FUNC, (id), (EventScr) (func),

#define EvtGotoIfSkipped(id) \
    EVT_CMD_GOTO_IFY_SKIPPED, (id),

#define EvtGotoIfFlag(id, flag) \
    EVT_CMD_GOTO_IFY_FLAG, (id), (flag),

#define EvtGotoIfNotFlag(id, flag) \
    EVT_CMD_GOTO_IFN_FLAG, (id), (flag),

#define EvtGotoIfActive(id, pid) \
    EVT_CMD_GOTO_IFY_ACTIVE, (id), (pid),

#define EvtJump(script) \
    EVT_CMD_JUMP, (EventScr) (script),

#define EvtGiveItem(iid) \
    EVT_CMD_ITEM, (iid),

#define EvtGiveItemTo(iid, pid) \
    EVT_CMD_ITEM_PID, (pid), (iid),

#define EvtGiveMoney(amount) \
    EVT_CMD_MONEY, (amount),

#define EvtMapChange(id) \
    EVT_CMD_MAPCHANGE, (id),

#define EvtMapChangePosition(x, y) \
    EVT_CMD_MAPCHANGE_POS, _EvtParams4(x, y, 0, 0),

#define EvtChangeFaction(pid, faction) \
    EVT_CMD_FACTION, (pid), (faction),

#define EvtFlashCursor(x, y) \
    EVT_CMD_FLASHCURSOR_POS, _EvtParams2(x, y),

#define EvtFlashCursorUnit(pid) \
    EVT_CMD_FLASHCURSOR_PID, (pid),

#define EvtPutCursor(x, y) \
    EVT_CMD_CURSOR, _EvtParams2(x, y),

#define EvtRemoveCursor \
    EVT_CMD_CLEARCURSOR,

#define EvtRemoveUnit(pid) \
    EVT_CMD_REMOVEUNIT, (pid),

#define EvtRemoveUnitDisplayed(pid) \
    EVT_CMD_REMOVEUNIT_DISPLAYED, (pid),

#define EvtSetAi(pid, ai_a, ai_b, ai_c) \
    EVT_CMD_SETAI_PID, (pid), _EvtParams4(ai_a, ai_b, ai_c, 0),

#define EvtSetAiPosition(x, y, ai_a, ai_b, ai_c) \
    EVT_CMD_SETAI_POS, _EvtParams2(x, y), _EvtParams4(ai_a, ai_b, ai_c, 0),

#define EvtSetFlag(flag) \
    EVT_CMD_SETFLAG, (flag),

#define EvtClearFlag(flag) \
    EVT_CMD_CLEARFLAG, (flag),

#define EvtSetBgm(song) \
    EVT_CMD_BGM, (song),

#define EvtOverrideBgm(song) \
    EVT_CMD_BGM_OVERRIDE, (song),

#define EvtRestoreBgm \
    EVT_CMD_BGM_RESTORE,

#define EvtFadeBgmOut(fade_speed) \
    EVT_CMD_BGM_FADEOUT, (fade_speed),

#define EvtLowerBgmVolume \
    EVT_CMD_BGM_LOWER_ON,

#define EvtRaiseBgmVolume \
    EVT_CMD_BGM_LOWER_OFF,

#define EvtPlaySe(song) \
    EVT_CMD_SE, (song),

#define EvtNextChapter(chapter) \
    EVT_CMD_CHAPTER, (chapter),

#define EvtGameEnd \
    EVT_CMD_GAMEEND,

#define EvtSetMap(chapter, camx, camy) \
    EVT_CMD_SETMAP, (chapter), (camx), (camy),

#define EvtNoSkip \
    EVT_CMD_NOSKIP,

#define EvtNoSkipNoTextSkip \
    EVT_CMD_NOSKIP_NOTEXTSKIP,

#define EvtYesSkip \
    EVT_CMD_YESSKIP,

#define EvtFadeToBlack(speed) \
    EVT_CMD_FADE_TOBLACK, (speed),

#define EvtFadeFromBlack(speed) \
    EVT_CMD_FADE_FROMBLACK, (speed),

#define EvtFadeToWhite(speed) \
    EVT_CMD_FADE_TOWHITE, (speed),

#define EvtFadeFromWhite(speed) \
    EVT_CMD_FADE_FROMWHITE, (speed),

#define EvtExitMap \
    EVT_CMD_EXIT_MAP,

#define EvtEnterMap \
    EVT_CMD_ENTER_MAP,

#define EvtFightScript(attacker_pid, defender_pid, battle_hits, is_ballista) \
    EVT_CMD_FIGHTSCR, (attacker_pid), (defender_pid), (EventScr) (battle_hits), (is_ballista),

#define EvtDisableAutoClear \
    EVT_CMD_NOCLEARTALK,

#define EvtFuncOnSkip(func) \
    EVT_CMD_FUNC_ONSKIP, (EventScr) (func),

#define EvtWeather(weather) \
    EVT_CMD_WEATHER, (weather),

// aliases
#define EvtPlaySE(song) EvtPlaySe(song)

// Helper event macros
// EventScr const EventScr_<Name>[] = { /* to be used here */ };

enum
{
    EVT_LIST_CMD_END,
    EVT_LIST_CMD_FLAG,
    EVT_LIST_CMD_TURN,
    EVT_LIST_CMD_TURN_HARD,
    EVT_LIST_CMD_TALK,
    EVT_LIST_CMD_TILE,
    EVT_LIST_CMD_TILE_MAPCHANGE,
    EVT_LIST_CMD_CHEST,
    EVT_LIST_CMD_DOOR,
    EVT_LIST_CMD_DRAWBRIDGE,
    EVT_LIST_CMD_SHOP,
    EVT_LIST_CMD_AREA,
    EVT_LIST_CMD_AREA_HARD,
    EVT_LIST_CMD_FUNC,
};

#define EvtListEnd \
    _EvtParams2(EVT_LIST_CMD_END, 0),

#define EvtListFlag(ent_flag, ent_script, flag) \
    _EvtParams2(EVT_LIST_CMD_FLAG, (ent_flag)), (EventListScr) (ent_script), (flag),

#define EvtListTurn(ent_flag, ent_script, turn, turn_max, faction) \
    _EvtParams2(EVT_LIST_CMD_TURN, (ent_flag)), (EventListScr) (ent_script), _EvtParams4((turn), (turn_max), (faction), 0),

#define EvtListTurnHard(ent_flag, ent_script, turn, turn_max, faction) \
    _EvtParams2(EVT_LIST_CMD_TURN_HARD, (ent_flag)), (EventListScr) (ent_script), _EvtParams4((turn), (turn_max), (faction), 0),

#define EvtListTalk(ent_flag, ent_script, pid_a, pid_b) \
    _EvtParams2(EVT_LIST_CMD_TALK, (ent_flag)), (EventListScr) (ent_script), _EvtParams4((pid_a), (pid_b), 0, 0),

#define EvtListTile(ent_flag, ent_script, x, y, tile_command) \
    _EvtParams2(EVT_LIST_CMD_TILE, (ent_flag)), (EventListScr) (ent_script), _EvtParams4((x), (y), (tile_command), 0),

#define EvtListTileMapChange(ent_flag, ent_script, x, y, tile_command) \
    _EvtParams2(EVT_LIST_CMD_TILE_MAPCHANGE, (ent_flag)), (EventListScr) (ent_script), _EvtParams4((x), (y), (tile_command), 0),

#define EvtListChest(ent_flag, iid, money, x, y, tile_command) \
    _EvtParams2(EVT_LIST_CMD_CHEST, (ent_flag)), _EvtParams2((iid), (money)), _EvtParams4((x), (y), (tile_command), 0),

#define EvtListDoor(ent_flag, ent_script, x, y, tile_command) \
    _EvtParams2(EVT_LIST_CMD_DOOR, (ent_flag)), (EventListScr) (ent_script), _EvtParams4((x), (y), (tile_command), 0),

#define EvtListDrawbridge(ent_flag, ent_script, x, y, tile_command) \
    _EvtParams2(EVT_LIST_CMD_DRAWBRIDGE, (ent_flag)), (EventListScr) (ent_script), _EvtParams4((x), (y), (tile_command), 0),

#define EvtListShop(ent_flag, item_list, x, y, tile_command) \
    _EvtParams2(EVT_LIST_CMD_SHOP, (ent_flag)), (EventListScr) (item_list), _EvtParams4((x), (y), (tile_command), 0),

#define EvtListArea(ent_flag, ent_script, x1, y1, x2, y2) \
    _EvtParams2(EVT_LIST_CMD_AREA, (ent_flag)), (EventListScr) (ent_script), _EvtParams4((x1), (y1), (x2), (y2)),

#define EvtListAreaHard(ent_flag, ent_script, x1, y1, x2, y2) \
    _EvtParams2(EVT_LIST_CMD_AREA_HARD, (ent_flag)), (EventListScr) (ent_script), _EvtParams4((x1), (y1), (x2), (y2)),

#define EvtListFunc(ent_flag, ent_script, func) \
    _EvtParams2(EVT_LIST_CMD_FUNC, (ent_flag)), (EventListScr) (ent_script), (EventListScr) (func),
