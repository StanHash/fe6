#include "save.h"

#include "gbasram.h"
#include "gbaio.h"
#include "util.h"
#include "eventinfo.h"
#include "supply.h"
#include "bm.h"
#include "hardware.h"
#include "faction.h"
#include "battle.h"
#include "chapter.h"
#include "savelayout.h"

#include "constants/chapters.h"

void WriteLastGameSaveId(int save_id)
{
    struct GlobalSaveInfo info;

    ReadGlobalSaveInfo(&info);
    info.last_game_save_id = save_id;
    WriteGlobalSaveInfoNoChecksum(&info);
}

int ReadLastGameSaveId(void)
{
    struct GlobalSaveInfo info;
    int result;

    if (!ReadGlobalSaveInfo(&info))
        return SAVE_ID_GAME0;

    result = info.last_game_save_id;

    if (result > SAVE_ID_GAME2)
        return SAVE_ID_GAME0;

    if (result < 0)
        return SAVE_ID_GAME0;

    return result;
}

void InvalidateGameSave(int save_id)
{
    struct SaveBlockInfo chunk;
    struct PlaySt play_st;

    if (IsValidSuspendSave(SAVE_ID_SUSPEND))
    {
        ReadSuspendSavePlaySt(SAVE_ID_SUSPEND, &play_st);

        if (play_st.save_id == save_id)
            InvalidateSuspendSave(SAVE_ID_SUSPEND);
    }

    chunk.kind = SAVEBLOCK_KIND_INVALID;
    WriteSaveBlockInfo(&chunk, save_id);
}

void CopyGameSave(int index_src, int index_dst)
{
    struct SaveBlockInfo block_info;

    void const * src = GetSaveReadAddr(index_src);
    void * dst = GetSaveWriteAddr(index_dst);

    STATIC_ASSERT(SRAM_SIZE_GAMESAVE <= sizeof(gBuf));

    ReadSramFast(src, gBuf, SRAM_SIZE_GAMESAVE);
    WriteAndVerifySramFast(gBuf, dst, SRAM_SIZE_GAMESAVE);

    block_info.magic32 = SAVEMAGIC32;
    block_info.kind = SAVEBLOCK_KIND_GAME;
    WriteSaveBlockInfo(&block_info, index_dst);
}

void WriteNewGameSave(int save_id, int is_hard)
{
    struct SaveBlockInfo block_info;
    struct GameSavePackedUnit unitp;
    int i;

    void * dst = GetSaveWriteAddr(save_id);

    InitPlayConfig(is_hard);
    InitUnits();
    ClearSupplyItems();
    ResetPermanentFlags();
    InvalidateSuspendSave(SAVE_ID_SUSPEND);

    gPlaySt.playthrough_id = GetNewPlaythroughId();
    gPlaySt.save_id = save_id;

    WriteAndVerifySramFast(&gPlaySt, dst + GAMESAVE_OFFSET_PLAYST, sizeof(gPlaySt));

    CpuFill16(0, &unitp, sizeof(unitp));

    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
        WriteAndVerifySramFast(&unitp, dst + GAMESAVE_OFFSET_UNITS + i * sizeof(struct GameSavePackedUnit), sizeof(struct GameSavePackedUnit));

    WriteSupplyItems(dst + GAMESAVE_OFFSET_SUPPLY);
    ClearPidChStatsSaveData(dst);
    WritePermanentFlags(dst + GAMESAVE_OFFSET_PERMANENTFLAGS);

    block_info.magic32 = SAVEMAGIC32;
    block_info.kind = SAVEBLOCK_KIND_GAME;
    WriteSaveBlockInfo(&block_info, save_id);

    WriteLastGameSaveId(save_id);
}

void WriteGameSave(int save_id)
{
    struct SaveBlockInfo block_info;
    int i;

    void * dst = GetSaveWriteAddr(save_id);

    InvalidateSuspendSave(SAVE_ID_SUSPEND);

    gPlaySt.save_id = save_id;
    gPlaySt.time_saved = GetGameTime();
    WriteAndVerifySramFast(&gPlaySt, dst + GAMESAVE_OFFSET_PLAYST, sizeof(gPlaySt));

    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
        WriteGameSavePackedUnit(&gUnitArrayBlue[i], dst + GAMESAVE_OFFSET_UNITS + i * sizeof(struct GameSavePackedUnit));

    WriteSupplyItems(dst + GAMESAVE_OFFSET_SUPPLY);
    WritePidStats(dst + GAMESAVE_OFFSET_PIDSTATS);
    WriteChapterStats(dst + GAMESAVE_OFFSET_CHAPTERSTATS);
    WritePermanentFlags(dst + GAMESAVE_OFFSET_PERMANENTFLAGS);

    block_info.magic32 = SAVEMAGIC32;
    block_info.kind = SAVEBLOCK_KIND_GAME;
    WriteSaveBlockInfo(&block_info, save_id);

    WriteLastGameSaveId(save_id);
}

void ReadGameSave(int save_id)
{
    int i;

    void * src = GetSaveReadAddr(save_id);

    if (!(gBmSt.flags & BM_FLAG_LINKARENA))
        InvalidateSuspendSave(SAVE_ID_SUSPEND);

    ReadSramFast(src + GAMESAVE_OFFSET_PLAYST, &gPlaySt, sizeof(gPlaySt));
    SetGameTime(gPlaySt.time_saved);
    gPlaySt.save_id = save_id;

    InitUnits();

    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
        ReadGameSavePackedUnit(src + GAMESAVE_OFFSET_UNITS + i * sizeof(struct GameSavePackedUnit), &gUnitArrayBlue[i]);

    ReadSupplyItems(src + GAMESAVE_OFFSET_SUPPLY);
    ReadPermanentFlags(src + GAMESAVE_OFFSET_PERMANENTFLAGS);
    ReadPidStats(src + GAMESAVE_OFFSET_PIDSTATS);
    ReadChapterStats(src + GAMESAVE_OFFSET_CHAPTERSTATS);

    WriteLastGameSaveId(save_id);
}

bool IsSaveValid(int save_id)
{
    return ReadSaveBlockInfo(NULL, save_id);
}

void ReadGameSavePlaySt(int save_id, struct PlaySt * play_st)
{
    void const * src = GetSaveReadAddr(save_id);
    ReadSramFast(src + GAMESAVE_OFFSET_PLAYST, play_st, sizeof(struct PlaySt));
}

bool IsGameSavePastFirstChapter(int save_id)
{
    struct PlaySt play_st;

    if (!IsSaveValid(save_id))
        return FALSE;

    ReadGameSavePlaySt(save_id, &play_st);

    if (play_st.chapter <= CHAPTER_CH01)
        return FALSE;

    return TRUE;
}

void WriteGameSavePackedUnit(struct Unit * unit, void * sram_dst)
{
    struct GameSavePackedUnit unitp;
    struct Unit unit_tmp;
    int i;

#if !BUGFIX
    // BUG: because we read from unit->pinfo here, the compiler is allowed to assume it is not NULL
    // and could thus optimize out the test later on, which would be disastrous
    unitp.pid = unit->pinfo->id;
    unitp.jid = unit->jinfo->id;
#endif

    if (unit->pinfo == NULL)
    {
        unit = &unit_tmp;
        ClearUnit(unit);
        unitp.pid = 0;
        unitp.jid = 0;
    }
#if BUGFIX
    else
    {
        unitp.pid = unit->pinfo->id;
        unitp.jid = unit->jinfo->id;
    }
#endif

    unitp.level = unit->level;
    unitp.exp = unit->exp;
    unitp.x = unit->x;
    unitp.y = unit->y;
    unitp.max_hp = unit->max_hp;
    unitp.pow = unit->pow;
    unitp.skl = unit->skl;
    unitp.spd = unit->spd;
    unitp.def = unit->def;
    unitp.res = unit->res;
    unitp.lck = unit->lck;
    unitp.con = unit->bonus_con;
    unitp.mov = unit->bonus_mov;

    unitp.item_a = unit->items[0];
    unitp.item_b = unit->items[1];
    unitp.item_c = unit->items[2];
    unitp.item_d = unit->items[3];
    unitp.item_e = unit->items[4];

    unitp.flags = 0;

    if (UNIT_FLAG_DEAD & unit->flags)
        unitp.flags |= SAVEUNIT_FLAG_DEAD;

    if (UNIT_FLAG_NOT_DEPLOYED & unit->flags)
        unitp.flags |= SAVEUNIT_FLAG_UNDEPLOYED;

    if (UNIT_FLAG_SOLOANIM_1 & unit->flags)
        unitp.flags |= SAVEUNIT_FLAG_SOLOANIM1;

    if (UNIT_FLAG_SOLOANIM_2 & unit->flags)
        unitp.flags |= SAVEUNIT_FLAG_SOLOANIM2;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; i++)
        unitp.wexp[i] = unit->wexp[i];

    for (i = 0; i < UNIT_SUPPORT_COUNT; i++)
        unitp.supports[i] = unit->supports[i];

    WriteAndVerifySramFast(&unitp, sram_dst, sizeof(struct GameSavePackedUnit));
}

void ReadGameSavePackedUnit(void const * sram_src, struct Unit * unit)
{
    int i;
    struct GameSavePackedUnit unitp;

    ReadSramFast(sram_src, &unitp, sizeof(struct GameSavePackedUnit));

    unit->pinfo = GetPInfo(unitp.pid);
    unit->jinfo = GetJInfo(unitp.jid);

    unit->level = unitp.level;
    unit->exp = unitp.exp;
    unit->x = unitp.x;
    unit->y = unitp.y;
    unit->max_hp = unitp.max_hp;
    unit->pow = unitp.pow;
    unit->skl = unitp.skl;
    unit->spd = unitp.spd;
    unit->def = unitp.def;
    unit->res = unitp.res;
    unit->lck = unitp.lck;
    unit->bonus_con = unitp.con;
    unit->bonus_mov = unitp.mov;

    unit->items[0] = unitp.item_a;
    unit->items[1] = unitp.item_b;
    unit->items[2] = unitp.item_c;
    unit->items[3] = unitp.item_d;
    unit->items[4] = unitp.item_e;

    if (unit->exp > 99)
        unit->exp = -1;

    unit->flags = 0;

    if (unitp.flags & SAVEUNIT_FLAG_DEAD)
        unit->flags |= UNIT_FLAG_DEAD | UNIT_FLAG_HIDDEN;

    if (unitp.flags & SAVEUNIT_FLAG_UNDEPLOYED)
        unit->flags |= UNIT_FLAG_NOT_DEPLOYED | UNIT_FLAG_HIDDEN;

    if (unitp.flags & SAVEUNIT_FLAG_SOLOANIM1)
        unit->flags |= UNIT_FLAG_SOLOANIM_1;

    if (unitp.flags & SAVEUNIT_FLAG_SOLOANIM2)
        unit->flags |= UNIT_FLAG_SOLOANIM_2;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; i++)
        unit->wexp[i] = unitp.wexp[i];

    for (i = 0; i < UNIT_SUPPORT_COUNT; i++)
        unit->supports[i] = unitp.supports[i];

    SetUnitHp(unit, GetUnitMaxHp(unit));

    if (unit->exp == 0x7F)
        unit->exp = -1;

    if (unit->x == 0x3F)
        unit->x = -1;

    if (unit->y == 0x3F)
        unit->y = -1;
}

void InvalidateSuspendSave(int save_id)
{
    struct SaveBlockInfo chunk;

    chunk.kind = SAVEBLOCK_KIND_INVALID;
    WriteSaveBlockInfo(&chunk, save_id);

    if (save_id == SAVE_ID_SUSPEND)
        WriteSaveBlockInfo(&chunk, SAVE_ID_SUSPEND_ALT);
}

void WriteSuspendSave(int save_id)
{
    struct SaveBlockInfo block_info;
    struct SuspendSavePackedUnit * buf;
    void * dst;
    int i;

    if (gPlaySt.flags & PLAY_FLAG_TUTORIAL)
        return;

    if (!IsSramWorking())
        return;

    save_id += GetNextSuspendSaveId();
    dst = GetSaveWriteAddr(save_id);

    gPlaySt.time_saved = GetGameTime();
    WriteAndVerifySramFast(&gPlaySt, dst + SUSPENDSAVE_OFFSET_PLAYST, sizeof(struct PlaySt));

    SaveActionRand();
    WriteAndVerifySramFast(&gAction, dst + SUSPENDSAVE_OFFSET_ACTION, sizeof(struct Action));

    buf = (struct SuspendSavePackedUnit *)gBuf;

    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
        EncodeSuspendSavePackedUnit(&gUnitArrayBlue[i], buf++);

    for (i = 0; i < UNIT_SAVE_AMOUNT_RED; i++)
        EncodeSuspendSavePackedUnit(&gUnitArrayRed[i], buf++);

    for (i = 0; i < UNIT_SAVE_AMOUNT_GREEN; i++)
        EncodeSuspendSavePackedUnit(&gUnitArrayGreen[i], buf++);

    WriteSramFast(gBuf, dst + SUSPENDSAVE_OFFSET_UNITS_BLUE, SUSPENDSAVE_SIZE_UNITS_BLUE + SUSPENDSAVE_SIZE_UNITS_RED + SUSPENDSAVE_SIZE_UNITS_GREEN);

    WritePermanentFlags(dst + SUSPENDSAVE_OFFSET_PERMANENTFLAGS);
    WriteChapterFlags(dst + SUSPENDSAVE_OFFSET_CHAPTERFLAGS);
    WriteSupplyItems(dst + SUSPENDSAVE_OFFSET_SUPPLY);
    WritePidStats(dst + SUSPENDSAVE_OFFSET_PIDSTATS);
    WriteChapterStats(dst + SUSPENDSAVE_OFFSET_CHAPTERSTATS);
    WriteTraps(dst + SUSPENDSAVE_OFFSET_TRAPS);

    block_info.magic32 = SAVEMAGIC32;
    block_info.kind = SAVEBLOCK_KIND_SUSPEND;
    WriteSaveBlockInfo(&block_info, save_id);

    gBmSt.just_resumed = FALSE;
    WriteSwappedSuspendSaveId();
}

void ReadSuspendSave(int save_id)
{
    int i;

    void * src = GetSaveReadAddr(save_id + gSuspendSaveIdOffset);

    ReadSramFast(src + SUSPENDSAVE_OFFSET_PLAYST, &gPlaySt, sizeof(struct PlaySt));
    SetGameTime(gPlaySt.time_saved);

    ReadSramFast(src + SUSPENDSAVE_OFFSET_ACTION, &gAction, sizeof(struct Action));
    RestoreActionRand();

    InitUnits();

    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
        ReadSuspendSavePackedUnit(src + SUSPENDSAVE_OFFSET_UNITS_BLUE + i * sizeof(struct SuspendSavePackedUnit), gUnitArrayBlue + i);

    for (i = 0; i < UNIT_SAVE_AMOUNT_RED; i++)
        ReadSuspendSavePackedUnit(src + SUSPENDSAVE_OFFSET_UNITS_RED + i * sizeof(struct SuspendSavePackedUnit), gUnitArrayRed + i);

    for (i = 0; i < UNIT_SAVE_AMOUNT_GREEN; i++)
        ReadSuspendSavePackedUnit(src + SUSPENDSAVE_OFFSET_UNITS_GREEN + i * sizeof(struct SuspendSavePackedUnit), gUnitArrayGreen + i);

    ReadPidStats(src + SUSPENDSAVE_OFFSET_PIDSTATS);
    ReadChapterStats(src + SUSPENDSAVE_OFFSET_CHAPTERSTATS);
    ReadSupplyItems(src + SUSPENDSAVE_OFFSET_SUPPLY);
    ReadPermanentFlags(src + SUSPENDSAVE_OFFSET_PERMANENTFLAGS);
    ReadChapterFlags(src + SUSPENDSAVE_OFFSET_CHAPTERFLAGS);
    ReadTraps(src + SUSPENDSAVE_OFFSET_TRAPS);
}

bool IsValidSuspendSave(int save_id)
{
    int result;

    if (!IsSramWorking())
        return FALSE;

    if (save_id != SAVE_ID_SUSPEND)
        return FALSE;

    gSuspendSaveIdOffset = GetLastSuspendSaveId();

    if (ReadSaveBlockInfo(NULL, SAVE_ID_SUSPEND + gSuspendSaveIdOffset))
        return TRUE;

    gSuspendSaveIdOffset = GetNextSuspendSaveId();

    if (ReadSaveBlockInfo(NULL, SAVE_ID_SUSPEND + gSuspendSaveIdOffset))
        return TRUE;

    gSuspendSaveIdOffset = 0x7F;
    return FALSE;
}

void ReadSuspendSavePlaySt(int save_id, struct PlaySt * buf)
{
    // because of this function, ReadGameSavePlaySt is used for both game saves and suspend saves, despite them potentially having different layouts
    STATIC_ASSERT(GAMESAVE_OFFSET_PLAYST == SUSPENDSAVE_OFFSET_PLAYST);

    ReadGameSavePlaySt(save_id + gSuspendSaveIdOffset, buf);
}

void EncodeSuspendSavePackedUnit(struct Unit * unit, void * buf)
{
    int i;
    struct SuspendSavePackedUnit * suspend_unit = (struct SuspendSavePackedUnit *)buf;

    if (unit->pinfo == NULL)
    {
        suspend_unit->pid = 0;
        return;
    }

    suspend_unit->pid = unit->pinfo->id;
    suspend_unit->jid = unit->jinfo->id;
    suspend_unit->level = unit->level;
    suspend_unit->exp = unit->exp;
    suspend_unit->flags = unit->flags;
    suspend_unit->x = unit->x;
    suspend_unit->y = unit->y;
    suspend_unit->max_hp = unit->max_hp;
    suspend_unit->hp = unit->hp;
    suspend_unit->pow = unit->pow;
    suspend_unit->skl = unit->skl;
    suspend_unit->spd = unit->spd;
    suspend_unit->def = unit->def;
    suspend_unit->res = unit->res;
    suspend_unit->lck = unit->lck;
    suspend_unit->bonus_con = unit->bonus_con;
    suspend_unit->status = unit->status;
    suspend_unit->status_duration = unit->status_duration;
    suspend_unit->torch = unit->torch;
    suspend_unit->barrier = unit->barrier;
    suspend_unit->rescue = unit->rescue;
    suspend_unit->bonus_mov = unit->bonus_mov;
    suspend_unit->item_a = unit->items[0];
    suspend_unit->item_b = unit->items[1];
    suspend_unit->item_c = unit->items[2];
    suspend_unit->item_d = unit->items[3];
    suspend_unit->item_e = unit->items[4];

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; i++)
        suspend_unit->wexp[i] = unit->wexp[i];

    for (i = 0; i < UNIT_SUPPORT_COUNT; i++)
        suspend_unit->supports[i] = unit->supports[i];

    suspend_unit->ai_a = unit->ai_a;
    suspend_unit->ai_a_pc = unit->ai_a_pc;
    suspend_unit->ai_b = unit->ai_b;
    suspend_unit->ai_b_pc = unit->ai_b_pc;
    suspend_unit->ai_config = unit->ai_config;
    suspend_unit->unit_unk_46 = unit->unk_46;
    suspend_unit->ai_flags = unit->ai_flags;
}

void ReadSuspendSavePackedUnit(void const * sram_src, struct Unit * unit)
{
    struct SuspendSavePackedUnit suspend_unit;
    int i;

    ReadSramFast(sram_src, &suspend_unit, sizeof(struct SuspendSavePackedUnit));

    unit->pinfo = GetPInfo(suspend_unit.pid);
    unit->jinfo = GetJInfo(suspend_unit.jid);

    unit->level = suspend_unit.level;
    unit->exp = suspend_unit.exp;
    unit->flags =suspend_unit.flags;
    unit->x = suspend_unit.x;
    unit->y = suspend_unit.y;
    unit->max_hp = suspend_unit.max_hp;
    unit->hp = suspend_unit.hp;
    unit->pow = suspend_unit.pow;
    unit->skl = suspend_unit.skl;
    unit->spd = suspend_unit.spd;
    unit->def = suspend_unit.def;
    unit->res = suspend_unit.res;
    unit->lck = suspend_unit.lck;
    unit->bonus_con = suspend_unit.bonus_con;
    unit->status = suspend_unit.status;
    unit->status_duration = suspend_unit.status_duration;
    unit->torch = suspend_unit.torch;
    unit->barrier = suspend_unit.barrier;
    unit->rescue = suspend_unit.rescue;
    unit->bonus_mov = suspend_unit.bonus_mov;
    unit->items[0] = suspend_unit.item_a;
    unit->items[1] = suspend_unit.item_b;
    unit->items[2] = suspend_unit.item_c;
    unit->items[3] = suspend_unit.item_d;
    unit->items[4] = suspend_unit.item_e;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; i++)
        unit->wexp[i] = suspend_unit.wexp[i];

    for (i = 0; i < UNIT_SUPPORT_COUNT; i++)
        unit->supports[i] = suspend_unit.supports[i];

    unit->ai_a = suspend_unit.ai_a;
    unit->ai_a_pc = suspend_unit.ai_a_pc;
    unit->ai_b = suspend_unit.ai_b;
    unit->ai_b_pc = suspend_unit.ai_b_pc;
    unit->ai_config = suspend_unit.ai_config;
    unit->unk_46 = suspend_unit.unit_unk_46;
    unit->ai_flags = suspend_unit.ai_flags;

    if (unit->exp == 0x7F)
        unit->exp = -1;

    if (unit->x == 0x3F)
        unit->x = -1;

    if (unit->y == 0x3F)
        unit->y = -1;
}

void WriteTraps(void * sram_dst)
{
    WriteAndVerifySramFast((u8 *)GetTrap(0), sram_dst, TRAP_MAX_COUNT * sizeof(struct Trap));
}

void ReadTraps(void const * sram_src)
{
    ReadSramFast(sram_src, (u8 *)GetTrap(0), TRAP_MAX_COUNT * sizeof(struct Trap));
}

int GetLastSuspendSaveId()
{
    struct GlobalSaveInfo info;
    ReadGlobalSaveInfo(&info);

    if (info.last_suspend_slot == 1)
        return 1;
    else
        return 0;
}

int GetNextSuspendSaveId(void)
{
    return 1 - GetLastSuspendSaveId();
}

void WriteSwappedSuspendSaveId(void)
{
    struct GlobalSaveInfo info;
    ReadGlobalSaveInfo(&info);
    info.last_suspend_slot = !info.last_suspend_slot;
    WriteGlobalSaveInfoNoChecksum(&info);
}

int SramChecksum32(void const * sram_src, int size)
{
    ReadSramFast(sram_src, gBuf, size);
    return Checksum32_t(gBuf, size);
}

bool VerifySaveBlockChecksum(struct SaveBlockInfo * chunk)
{
    int size = chunk->size;
    void * sram_dst = SramOffsetToAddr(chunk->offset);
    int checksum32 = SramChecksum32(sram_dst, size);

    if (chunk->checksum32 != checksum32)
        return FALSE;
    else
        return TRUE;
}

void PopulateSaveBlockChecksum(struct SaveBlockInfo * chunk)
{
    int size = chunk->size;
    u8 * dst = SramOffsetToAddr(chunk->offset);
    chunk->checksum32 = SramChecksum32(dst, size);
}

u16 GetGameStateChecksum_Unused(void)
{
    int i;
    u16 result = 0;

    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
    {
        if (!gUnitArrayBlue[i].pinfo)
            continue;

        gUnitArrayBlue[i].map_sprite = NULL;
        result += SramChecksum32(&gUnitArrayBlue[i], sizeof(struct Unit) / 2);
    }

    for (i = 0; i < UNIT_SAVE_AMOUNT_RED; i++)
    {
        if (!gUnitArrayRed[i].pinfo)
            continue;

        gUnitArrayRed[i].map_sprite = NULL;
        result += SramChecksum32(&gUnitArrayRed[i], sizeof(struct Unit) / 2);
    }

    for (i = 0; i < UNIT_SAVE_AMOUNT_GREEN; i++)
    {
        if (!gUnitArrayGreen[i].pinfo)
            continue;

        gUnitArrayGreen[i].map_sprite = NULL;
        result += SramChecksum32(&gUnitArrayGreen[i], sizeof(struct Unit) / 2);
    }

    result += SramChecksum32(GetPermanentFlagBits(), GetPermanentFlagBitsSize() / 2);
    result += SramChecksum32(GetChapterFlagBits(), GetChapterFlagBitsSize() / 2);
    result += SramChecksum32(GetTrap(0), TRAP_MAX_COUNT * sizeof(struct Trap) / 2);

    return result;
}

void func_fe6_08086088(void)
{
    u8 buf[8];
}

bool IsSaveBlockValid2(int save_id)
{
    return ReadSaveBlockInfo(NULL, save_id);
}
