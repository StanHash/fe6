#include "save.h"

#include "sram.h"
#include "gbaio.h"
#include "util.h"
#include "eventinfo.h"
#include "supply.h"
#include "bm.h"
#include "hardware.h"
#include "faction.h"
#include "battle.h"
#include "chapter.h"

void UpdateLastUsedGameSaveSlot(int slot_sa)
{
    struct GlobalSaveInfo info;

    LoadGlobalSaveInfo(&info);
    info.slot_sa = slot_sa;
    SaveGlobalSaveInfoNoChecksum(&info);
}

int GetLastUsedGameSaveSlot()
{
    int ret;
    struct GlobalSaveInfo info;

    if (!LoadGlobalSaveInfo(&info))
        return 0;
    
    ret = info.slot_sa;
    if (ret > 2)
        return 0;
    else if (ret < 0)
        return 0;
    else
        return ret;
}

void func_fe6_08084FB8(int slot)
{
    struct SaveBlockInfo chunk;
    struct PlaySt playSt;

    if (AdvanceSuspendSaveDataSlotId(SAVE_ID_SUSPEND0))
    {
        LoadPlayStByGlobalSusIndex(SAVE_ID_SUSPEND0, &playSt);

        if (playSt.save_slot == slot)
            ResetSaveBlockInfo(SAVE_ID_SUSPEND0);
    }

    chunk.kind = BLOCK_INFO_KIND_INVALID;
    WriteSaveBlockInfo(&chunk, slot);
}

void CopyGameSave(int index_src, int index_dst)
{
    struct SaveBlockInfo chunk;
    u8 * src = GetSaveSourceAddress(index_src);
    u8 * dst = GetSaveTargetAddress(index_dst);

    (*ReadSramFast)(src, gBuf, SAV_MEMMAP_MAX);
    WriteAndVerifySramFast(gBuf, dst, SAV_MEMMAP_MAX);

    chunk.magic_a = SAVE_MAGICA_COMM;
    chunk.kind = BLOCK_INFO_KIND_SAV;
    WriteSaveBlockInfo(&chunk, index_dst);
}

void SaveNewGame(int slot, int isHard)
{
    int i;
    struct SaveBlockInfo chunk;
    struct SavePackedUnit unitp;
    u8 * dst = GetSaveTargetAddress(slot);

    InitPlayConfig(isHard);
    InitUnits();
    ClearSupplyItems();
    ResetPermanentFlags();
    ResetSaveBlockInfo(SAVE_ID_SUSPEND0);

    gPlaySt.playthrough_id = GetNewPlaythroughId();
    gPlaySt.save_slot = slot;

    WriteAndVerifySramFast((u8 *)&gPlaySt, dst, sizeof(gPlaySt));

    CpuFill16(0, &unitp, sizeof(unitp));
    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
        WriteAndVerifySramFast((u8*)&unitp, dst + SAV_MEMMAP_UNIT + i * sizeof(struct SavePackedUnit), sizeof(struct SavePackedUnit));

    SaveSupplyItems(dst + SAV_MEMMAP_SUPPLY);
    ClearPidChStatsSaveData(dst);
    SavePermanentFlagBits(dst + SAV_MEMMAP_PERMFLAG);

    chunk.magic_a = SAVE_MAGICA_COMM;
    chunk.kind = BLOCK_INFO_KIND_SAV;
    WriteSaveBlockInfo(&chunk, slot);
    UpdateLastUsedGameSaveSlot(slot);
}

void SaveGame(int slot)
{
    int i;
    struct SaveBlockInfo chunk;
    u8 * dst = GetSaveTargetAddress(slot);

    ResetSaveBlockInfo(SAVE_ID_SUSPEND0);

    gPlaySt.save_slot = slot;
    gPlaySt.unk_00 = GetGameTime();
    WriteAndVerifySramFast((u8 *)&gPlaySt, dst + SAV_MEMMAP_PLAYST, sizeof(gPlaySt));

    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
        SaveUnit(&gUnitArrayBlue[i], dst + SAV_MEMMAP_UNIT + i * sizeof(struct SavePackedUnit));

    SaveSupplyItems(dst + SAV_MEMMAP_SUPPLY);
    SavePidStats(dst + SAV_MEMMAP_PIDSTATS);
    SaveChWinData(dst + SAV_MEMMAP_CHWIN);
    SavePermanentFlagBits(dst + SAV_MEMMAP_PERMFLAG);

    chunk.magic_a = SAVE_MAGICA_COMM;
    chunk.kind = BLOCK_INFO_KIND_SAV;
    WriteSaveBlockInfo(&chunk, slot);
    UpdateLastUsedGameSaveSlot(slot);
}

void LoadGame(int slot)
{
    int i;
    u8 * src = GetSaveSourceAddress(slot);

    if (!(BM_FLAG_LINKARENA & gBmSt.flags))
        ResetSaveBlockInfo(SAVE_ID_SUSPEND0);

    (*ReadSramFast)(src + SAV_MEMMAP_PLAYST, (u8 *)&gPlaySt, sizeof(gPlaySt));
    SetGameTime(gPlaySt.unk_00);
    gPlaySt.save_slot = slot;

    InitUnits();
    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
        LoadUnit(src + SAV_MEMMAP_UNIT + i * sizeof(struct SavePackedUnit), &gUnitArrayBlue[i]);

    LoadSupplyItems(src + SAV_MEMMAP_SUPPLY);
    LoadPermanentFlagBits(src + SAV_MEMMAP_PERMFLAG);
    LoadPidStats(src + SAV_MEMMAP_PIDSTATS);
    LoadChWinData(src + SAV_MEMMAP_CHWIN);

    UpdateLastUsedGameSaveSlot(slot);
}

bool VerifySaveBlockInfoByIndex(int slot)
{
    return LoadAndVerifySaveBlockInfo(NULL, slot);
}

void LoadPlaySt(int slot, struct PlaySt * playSt)
{
    u8 * src = GetSaveSourceAddress(slot);
    (*ReadSramFast)(src + SAV_MEMMAP_PLAYST, (u8 *)playSt, sizeof(struct PlaySt));
}

bool CheckSaveChunkChapterValid(int slot)
{
    struct PlaySt playSt;

    if (!VerifySaveBlockInfoByIndex(slot))
        return FALSE;

    LoadPlaySt(slot, &playSt);

    if (playSt.chapter <= 1)
        return FALSE;
    else
        return TRUE;
}

void SaveUnit(struct Unit * unit, void * sram_dst)
{
    int i;
    struct SavePackedUnit unitp;

    unitp.pid = unit->pinfo->id;
    unitp.jid = unit->jinfo->id;

    if (!unit->pinfo)
    {
        struct Unit _unit;
        unit = &_unit;

        ClearUnit(unit);
        unitp.pid = 0;
        unitp.jid = 0;
    }

    unitp.level = *(u8 *)&unit->level;
    unitp.exp = unit->exp;
    unitp.x = unit->x;
    unitp.y = unit->y;
    unitp.max_hp = *(i8 *)&unit->max_hp;
    unitp.pow = unit->pow;
    unitp.skl = unit->skl;
    unitp.spd = unit->spd;
    unitp.def = unit->def;
    unitp.res = unit->res;
    unitp.lck = unit->lck;
    unitp.con = unit->bonus_con;
    unitp.mov = unit->bonus_mov;

    unitp.item0 = unit->items[0];
    unitp.item1 = unit->items[1];
    unitp.item2 = unit->items[2];
    unitp.item3 = unit->items[3];
    unitp.item4 = unit->items[4];

    unitp.flags = 0;

    if (UNIT_FLAG_DEAD & unit->flags)
        unitp.flags |= PACKED_US_DEAD;

    if (UNIT_FLAG_NOT_DEPLOYED & unit->flags)
        unitp.flags |= PACKED_US_UNDEPLOYED;

    if (UNIT_FLAG_SOLOANIM_1 & unit->flags)
        unitp.flags |= PACKED_US_SOLO_ANIM1;

    if (UNIT_FLAG_SOLOANIM_2 & unit->flags)
        unitp.flags |= PACKED_US_SOLO_ANIM2;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; i++)
        unitp.wexp[i] = unit->wexp[i];

    for (i = 0; i < UNIT_SUPPORT_COUNT; i++)
        unitp.supports[i] = unit->supports[i];

    WriteAndVerifySramFast((u8*)&unitp, sram_dst, sizeof(struct SavePackedUnit));
}

void LoadUnit(u8 * sram_src, struct Unit * unit)
{
    int i;
    struct SavePackedUnit unitp;

    (*ReadSramFast)(sram_src, (u8 *)&unitp, sizeof(struct SavePackedUnit));

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

    unit->items[0] = unitp.item0;
    unit->items[1] = unitp.item1;
    unit->items[2] = unitp.item2;
    unit->items[3] = unitp.item3;
    unit->items[4] = unitp.item4;

    if (unit->exp > 99)
        unit->exp = -1;

    unit->flags = 0;

    if (unitp.flags & PACKED_US_DEAD)
        unit->flags |= UNIT_FLAG_DEAD | UNIT_FLAG_HIDDEN;

    if (unitp.flags & PACKED_US_UNDEPLOYED)
        unit->flags |= UNIT_FLAG_NOT_DEPLOYED | UNIT_FLAG_HIDDEN;

    if (unitp.flags & PACKED_US_SOLO_ANIM1)
        unit->flags |= UNIT_FLAG_SOLOANIM_1;

    if (unitp.flags & PACKED_US_SOLO_ANIM2)
        unit->flags |= UNIT_FLAG_SOLOANIM_2;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; i++)
        unit->wexp[i] = unitp.wexp[i];

    for (i = 0; i < UNIT_SUPPORT_COUNT; i++)
        unit->supports[i] = unitp.supports[i];

    SetUnitHp(unit, GetUnitMaxHp(unit));

    if (0x7F == unit->exp)
        unit->exp = -1;

    if (0x3F == unit->x)
        unit->x = -1;

    if (0x3F == unit->y)
        unit->y = -1;
}

void ResetSaveBlockInfo(int slot)
{
    struct SaveBlockInfo chunk;

    chunk.kind = BLOCK_INFO_KIND_INVALID;
    WriteSaveBlockInfo(&chunk, slot);

    if (SAVE_ID_SUSPEND0 == slot)
        WriteSaveBlockInfo(&chunk, SAVE_ID_SUSPEND1);
}

void SaveSuspendedGame(int slot)
{
    int i;
    u8 * dst;
    struct SuspendPackedUnit * buf;
    struct SaveBlockInfo chunk;

    if (PLAY_FLAG_3 & gPlaySt.flags)
        return;

    if (!IsSramWorking())
        return;

    slot += GetNextSuspendSaveId();
    dst = GetSaveTargetAddress(slot);

    gPlaySt.unk_00 = GetGameTime();
    WriteAndVerifySramFast((u8 *)&gPlaySt, dst + SUS_MEMMAP_PLAYST, sizeof(struct PlaySt));

    SaveActionRand();
    WriteAndVerifySramFast((u8 *)&gAction, dst + SUS_MEMMAP_ACTION, sizeof(struct Action));

    buf = (struct SuspendPackedUnit *)gBuf;
    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
        PackUnitForSuspend(&gUnitArrayBlue[i], (u8 *)buf++);
    for (i = 0; i < UNIT_SAVE_AMOUNT_RED; i++)
        PackUnitForSuspend(&gUnitArrayRed[i], (u8 *)buf++);
    for (i = 0; i < UNIT_SAVE_AMOUNT_GREEN; i++)
        PackUnitForSuspend(&gUnitArrayGreen[i], (u8 *)buf++);
    WriteSramFast(gBuf, dst + SUS_MEMMAP_UNIT_B, SUS_SIZE_UNIT_B + SUS_SIZE_UNIT_R + SUS_SIZE_UNIT_G);

    SavePermanentFlagBits(dst + SUS_MEMMAP_PERMFLAG);
    SaveChapterFlagBits(dst + SUS_MEMMAP_TEMPFLAG);
    SaveSupplyItems(dst + SUS_MEMMAP_SUPPLY);
    SavePidStats(dst + SUS_MEMMAP_PIDSTATS);
    SaveChWinData(dst + SUS_MEMMAP_CHWIN);
    SaveTraps(dst + SUS_MEMMAP_TRAP);

    chunk.magic_a = SAVE_MAGICA_COMM;
    chunk.kind = BLOCK_INFO_KIND_SUS;
    WriteSaveBlockInfo(&chunk, slot);

    gBmSt.unk_3C = 0;
    ChangeSuspendSaveId();
}

void LoadSuspendedGame(int slot)
{
    int i;
    u8 *src = GetSaveSourceAddress(slot + gSuspendSlotIndex);

    (*ReadSramFast)(src + SUS_MEMMAP_PLAYST, (u8 *)&gPlaySt, sizeof(struct PlaySt));
    SetGameTime(gPlaySt.unk_00);

    (*ReadSramFast)(src + SUS_MEMMAP_ACTION, (u8 *)&gAction, sizeof(struct Action));
    RestoreActionRand();

    InitUnits();
    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
        LoadUnitFormSuspend(src + SUS_MEMMAP_UNIT_B + i * sizeof(struct SuspendPackedUnit), &gUnitArrayBlue[i]);
    for (i = 0; i < UNIT_SAVE_AMOUNT_RED; i++)
        LoadUnitFormSuspend(src + SUS_MEMMAP_UNIT_R + i * sizeof(struct SuspendPackedUnit), &gUnitArrayRed[i]);
    for (i = 0; i < UNIT_SAVE_AMOUNT_GREEN; i++)
        LoadUnitFormSuspend(src + SUS_MEMMAP_UNIT_G + i * sizeof(struct SuspendPackedUnit), &gUnitArrayGreen[i]);

    LoadPidStats(src + SUS_MEMMAP_PIDSTATS);
    LoadChWinData(src + SUS_MEMMAP_CHWIN);
    LoadSupplyItems(src + SUS_MEMMAP_SUPPLY);
    LoadPermanentFlagBits(src + SUS_MEMMAP_PERMFLAG);
    LoadChapterFlagBits(src + SUS_MEMMAP_TEMPFLAG);
    LoadTraps(src + SUS_MEMMAP_TRAP);
}

bool AdvanceSuspendSaveDataSlotId(int slot)
{
    int ret;

    if (!IsSramWorking())
        return FALSE;
    
    if (SAVE_ID_SUSPEND0 != slot)
        return FALSE;
    
    gSuspendSlotIndex = GetLastSuspendSaveId();

    ret = LoadAndVerifySaveBlockInfo(NULL, gSuspendSlotIndex + SAVE_ID_SUSPEND0);
    if (ret)
        return TRUE;

    gSuspendSlotIndex = GetNextSuspendSaveId();

    ret = LoadAndVerifySaveBlockInfo(NULL, gSuspendSlotIndex + SAVE_ID_SUSPEND0);
    if (ret)
        return TRUE;

    gSuspendSlotIndex = 0x7F;
    return FALSE;
}

void LoadPlayStByGlobalSusIndex(int slot, struct PlaySt * buf)
{
    LoadPlaySt(slot + gSuspendSlotIndex, buf);
}

void PackUnitForSuspend(struct Unit * unit, u8 * buf)
{
    int i;
    struct SuspendPackedUnit * unitp = (struct SuspendPackedUnit *)buf;

    if (unit->pinfo == NULL)
    {
        unitp->pid = 0;
        return;
    }

    unitp->pid = unit->pinfo->id;
    unitp->jid = unit->jinfo->id;
    unitp->level = unit->level;
    unitp->exp = unit->exp;
    unitp->flags = unit->flags;
    unitp->x = unit->x;
    unitp->y = unit->y;
    unitp->max_hp = unit->max_hp;
    unitp->hp = unit->hp;
    unitp->pow = unit->pow;
    unitp->skl = unit->skl;
    unitp->spd = unit->spd;
    unitp->def = unit->def;
    unitp->res = unit->res;
    unitp->lck = unit->lck;
    unitp->bonus_con = unit->bonus_con;
    unitp->status = unit->status;
    unitp->status_duration = unit->status_duration;
    unitp->torch = unit->torch;
    unitp->barrier = unit->barrier;
    unitp->rescue = unit->rescue;
    unitp->bonus_mov = unit->bonus_mov;
    unitp->item_a = unit->items[0];
    unitp->item_b = unit->items[1];
    unitp->item_c = unit->items[2];
    unitp->item_d = unit->items[3];
    unitp->item_e = unit->items[4];

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; i++)
        unitp->wexp[i] = unit->wexp[i];

    for (i = 0; i < UNIT_SUPPORT_COUNT; i++)
        unitp->supports[i] = unit->supports[i];

    unitp->ai_a = unit->ai_a;
    unitp->ai_a_pc = unit->ai_a_pc;
    unitp->ai_b = unit->ai_b;
    unitp->ai_b_pc = unit->ai_b_pc;
    unitp->ai_config = unit->ai_config;
    unitp->unit_unk_46 = unit->unk_46;
    unitp->ai_flags = unit->ai_flags;
}

void LoadUnitFormSuspend(u8 * sram_src, struct Unit * unit)
{
    int i;
    struct SuspendPackedUnit unitp;

    (*ReadSramFast)(sram_src, (u8 *)&unitp, sizeof(struct SuspendPackedUnit));

    unit->pinfo = GetPInfo(unitp.pid);
    unit->jinfo = GetJInfo(unitp.jid);

    unit->level = unitp.level;
    unit->exp = unitp.exp;
    unit->flags =unitp.flags;
    unit->x = unitp.x;
    unit->y = unitp.y;
    unit->max_hp = unitp.max_hp;
    unit->hp = unitp.hp;
    unit->pow = unitp.pow;
    unit->skl = unitp.skl;
    unit->spd = unitp.spd;
    unit->def = unitp.def;
    unit->res = unitp.res;
    unit->lck = unitp.lck;
    unit->bonus_con = unitp.bonus_con;
    unit->status = unitp.status;
    unit->status_duration = unitp.status_duration;
    unit->torch = unitp.torch;
    unit->barrier = unitp.barrier;
    unit->rescue = unitp.rescue;
    unit->bonus_mov = unitp.bonus_mov;

    unit->items[0] = unitp.item_a;
    unit->items[1] = unitp.item_b;
    unit->items[2] = unitp.item_c;
    unit->items[3] = unitp.item_d;
    unit->items[4] = unitp.item_e;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; i++)
        unit->wexp[i] = unitp.wexp[i];

    for (i = 0; i < UNIT_SUPPORT_COUNT; i++)
        unit->supports[i] = unitp.supports[i];

    unit->ai_a = unitp.ai_a;
    unit->ai_a_pc = unitp.ai_a_pc;
    unit->ai_b = unitp.ai_b;
    unit->ai_b_pc = unitp.ai_b_pc;
    unit->ai_config = unitp.ai_config;
    unit->unk_46 = unitp.unit_unk_46;
    unit->ai_flags = unitp.ai_flags;

    if (0x7F == unit->exp)
        unit->exp = -1;

    if (0x3F == unit->x)
        unit->x = -1;

    if (0x3F == unit->y)
        unit->y = -1;
}

void SaveTraps(u8 * sram_dst)
{
    WriteAndVerifySramFast((u8 *)GetTrap(0), sram_dst, TRAP_MAX_COUNT * sizeof(struct Trap));
}

void LoadTraps(u8 * sram_src)
{
    (*ReadSramFast)(sram_src, (u8 *)GetTrap(0), TRAP_MAX_COUNT * sizeof(struct Trap));
}

int GetLastSuspendSaveId()
{
    struct GlobalSaveInfo info;
	LoadGlobalSaveInfo(&info);

    if (1 == info.slot_su)
        return 1;
    else
        return 0;
}

int GetNextSuspendSaveId()
{
    return 1 - GetLastSuspendSaveId();
}

void ChangeSuspendSaveId()
{
    struct GlobalSaveInfo info;
	LoadGlobalSaveInfo(&info);

    info.slot_su = 0 == info.slot_su;
    SaveGlobalSaveInfoNoChecksum(&info);
}

int GetCkSum32ViaGenericBuf(void * sram_src, int size)
{
    (*ReadSramFast)(sram_src, gBuf, size);
    return Checksum32_t((u16 *)gBuf, size);
}

bool CkSum32SaveBlockInfo(struct SaveBlockInfo * chunk)
{
    int size = chunk->size;
    u8 * sram_dst = SramOffsetToPointer(chunk->offset);
    int cksum32 = GetCkSum32ViaGenericBuf(sram_dst, size);

    if (chunk->checksum32 != cksum32)
        return FALSE;
    else
        return TRUE;
}

void GenerateSaveBlockInfoCkSum32(struct SaveBlockInfo * chunk)
{
    int size = chunk->size;
    u8 * dst = SramOffsetToPointer(chunk->offset);
    chunk->checksum32 = GetCkSum32ViaGenericBuf(dst, size);
}

u16 ComputeSaveDataCkSum32()
{
    int i;
    u16 ret = 0;

    for (i = 0; i < UNIT_SAVE_AMOUNT_BLUE; i++)
    {
        if (!gUnitArrayBlue[i].pinfo)
            continue;

        gUnitArrayBlue[i].map_sprite = NULL;
        ret += GetCkSum32ViaGenericBuf(&gUnitArrayBlue[i], sizeof(struct Unit) / 2);
    }

    for (i = 0; i < UNIT_SAVE_AMOUNT_RED; i++)
    {
        if (!gUnitArrayRed[i].pinfo)
            continue;

        gUnitArrayRed[i].map_sprite = NULL;
        ret += GetCkSum32ViaGenericBuf(&gUnitArrayRed[i], sizeof(struct Unit) / 2);
    }

    for (i = 0; i < UNIT_SAVE_AMOUNT_GREEN; i++)
    {
        if (!gUnitArrayGreen[i].pinfo)
            continue;

        gUnitArrayGreen[i].map_sprite = NULL;
        ret += GetCkSum32ViaGenericBuf(&gUnitArrayGreen[i], sizeof(struct Unit) / 2);
    }

    ret += GetCkSum32ViaGenericBuf(GetPermanentFlagBits(), GetPermanentFlagBitsSize() / 2);
    ret += GetCkSum32ViaGenericBuf(GetChapterFlagBits(), GetChapterFlagBitsSize() / 2);
    ret += GetCkSum32ViaGenericBuf((u8*)GetTrap(0), TRAP_MAX_COUNT * sizeof(struct Trap) / 2);

    return ret;
}

void func_fe6_08086088()
{
    u8 buf[8];
}

bool VerifySaveBlockInfoByIndex2(int slot)
{
    return LoadAndVerifySaveBlockInfo(NULL, slot);
}
