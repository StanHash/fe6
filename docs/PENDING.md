# Pending functions

Those functions have been decompiled (using decomp.me, most likely), but the files haven't been split and such.

```c
struct SuspendPackedUnit
{
    /* 00 */ u8 pid;
    /* 01 */ u8 jid;
    /* 02 */ u8 ai_a;
    /* 03 */ u8 rescue;
    /* 04 */ u16 flags;
    /* 06 */ u16 item_a;
    /* 08 */ u16 item_b;
    /* 0A */ u16 item_c;
    /* 0C */ u8 max_hp;
    /* 0D */ u8 hp;
    /* 0E */ u8 exp;
    /* 0F */ u8 ai_flags;
    /* 10 */ u8 wexp[UNIT_WEAPON_EXP_COUNT];
    /* 18 */ u8 supports[UNIT_SUPPORT_COUNT];
    /* 22 */ u8 ai_a_pc;
    /* 23 */ u8 ai_b;
    /* 24 */ u16 ai_config;
    /* 26 */ u8 ai_b_pc;
    /* 27 */ u8 unit_unk_46;
    /* 28 */ u32 level           : 5;
    /*    */ u32 x               : 6;
    /*    */ u32 y               : 6;
    /*    */ u32 pow             : 5;
    /*    */ u32 skl             : 5;
    /*    */ u32 spd             : 5;
    /* 2C */ u32 def             : 5;
    /*    */ u32 res             : 5;
    /*    */ u32 lck             : 5;
    /*    */ u32 bonus_con       : 5;
    /*    */ u32 status          : 3;
    /*    */ u32 status_duration : 3;
    /*    */ u32 torch           : 3;
    /*    */ u32 barrier         : 3;
    /* 30 */ u32 bonus_mov       : 4;
    /*    */ u32 item_d          : 14;
    /*    */ u32 item_e          : 14;
};

void func_fe6_08085A48(struct Unit * unit, void * buf)
{
    int i;

    struct SuspendPackedUnit * dst = buf;

    if (unit->pinfo == NULL)
    {
        dst->pid = 0;
        return;
    }

    dst->pid = unit->pinfo->id;
    dst->jid = unit->jinfo->id;
    dst->level = unit->level;
    dst->exp = unit->exp;
    dst->flags = unit->flags;
    dst->x = unit->x;
    dst->y = unit->y;
    dst->max_hp = unit->max_hp;
    dst->hp = unit->hp;
    dst->pow = unit->pow;
    dst->skl = unit->skl;
    dst->spd = unit->spd;
    dst->def = unit->def;
    dst->res = unit->res;
    dst->lck = unit->lck;
    dst->bonus_con = unit->bonus_con;
    dst->status = unit->status;
    dst->status_duration = unit->status_duration;
    dst->torch = unit->torch;
    dst->barrier = unit->barrier;
    dst->rescue = unit->rescue;
    dst->bonus_mov = unit->bonus_mov;
    dst->item_a = unit->items[0];
    dst->item_b = unit->items[1];
    dst->item_c = unit->items[2];
    dst->item_d = unit->items[3];
    dst->item_e = unit->items[4];

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; i++)
        dst->wexp[i] = unit->wexp[i];

    for (i = 0; i < UNIT_SUPPORT_COUNT; i++)
        dst->supports[i] = unit->supports[i];

    dst->ai_a = unit->ai_a;
    dst->ai_a_pc = unit->ai_a_pc;
    dst->ai_b = unit->ai_b;
    dst->ai_b_pc = unit->ai_b_pc;
    dst->ai_config = unit->ai_config;
    dst->unit_unk_46 = unit->unk_46;
    dst->ai_flags = unit->ai_flags;
}
```
