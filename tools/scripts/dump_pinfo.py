import sys
import symbols
from fe6db import all_pinfo, PID_DICT, JID_DICT

ITEM_KIND_NAMES = {
    0x00: "ITEM_KIND_SWORD",
    0x01: "ITEM_KIND_LANCE",
    0x02: "ITEM_KIND_AXE",
    0x03: "ITEM_KIND_BOW",
    0x04: "ITEM_KIND_STAFF",
    0x05: "ITEM_KIND_ANIMA",
    0x06: "ITEM_KIND_LIGHT",
    0x07: "ITEM_KIND_ELDER",
    0x08: "ITEM_KIND_UNK8",
    0x09: "ITEM_KIND_ITEM",
    0x0A: "ITEM_KIND_DRAGON",
    0x0B: "ITEM_KIND_DRAGONSTONE"}

WEXP_MAP = {
    1: "WEXP_E",
    51: "WEXP_D",
    101: "WEXP_C",
    151: "WEXP_B",
    201: "WEXP_A",
    251: "WEXP_S"}

UNIT_ATTRIBUTE_NAMES = [
    "UNIT_ATTR_MOUNTED",
    "UNIT_ATTR_RE_MOVE",
    "UNIT_ATTR_STEAL",
    "UNIT_ATTR_THIEF",
    "UNIT_ATTR_DANCE",
    "UNIT_ATTR_PLAY",
    "UNIT_ATTR_CRITBONUS",
    "UNIT_ATTR_BALLISTA",
    "UNIT_ATTR_PROMOTED",
    "UNIT_ATTR_SUPPLY",
    "UNIT_ATTR_MOUNT_ICON",
    "UNIT_ATTR_WYVERN_ICON",
    "UNIT_ATTR_PEGASUS_ICON",
    "UNIT_ATTR_LORD",
    "UNIT_ATTR_FEMALE",
    "UNIT_ATTR_BOSS",
    "UNIT_ATTR_LOCK_ROY",
    "UNIT_ATTR_LOCK_MYRM",
    "UNIT_ATTR_LOCK_DRAGON",
    "UNIT_ATTR_LOCK_ZEPHIEL",
    "UNIT_ATTR_20",
    "UNIT_ATTR_TRIANGLE_ATTACK_PEGASI",
    "UNIT_ATTR_TRIANGLE_ATTACK_ARMORS",
    "UNIT_ATTR_ALT_PINFO",
    "UNIT_ATTR_MAJOR_BOSS"]

def unit_attributes_expr(unit_attributes):
    terms = []

    for i, attr_name in enumerate(UNIT_ATTRIBUTE_NAMES):
        if (unit_attributes & (1 << i)) != 0:
            terms.append(attr_name)

    return ' | '.join(terms) if len(terms) != 0 else '0'

def main(args):
    try:
        rom_path = args[1]

    except IndexError:
        sys.exit(f"Usage: {args[0]} ROM")

    with open(rom_path, 'rb') as f:
        rom_data = f.read()

    elf_path = rom_path.replace("-base.gba", ".elf")

    with open(elf_path, 'rb') as f:
        names = { addr: name for addr, name in symbols.from_elf(f) }

    print("struct PInfo CONST_DATA PInfoTable[] =")
    print("{")

    is_first = True

    for pid, pinfo in all_pinfo(rom_data):
        if not is_first:
            print()

        print(f"    [{PID_DICT[pid]} - 1] =")
        print(f"    {{")

        print(f"        .id = {PID_DICT[pid]},")
        print(f"        .msg_name = MSG_{pinfo.msg_name:03X},")

        if pinfo.msg_desc != 0:
            print(f"        .msg_desc = MSG_{pinfo.msg_desc:03X},")

        if pinfo.jid_default != 0:
            print(f"        .jid_default = {JID_DICT[pinfo.jid_default]},")

        if pinfo.fid != 0:
            print(f"        .fid = FID_{pinfo.fid:02X},")

        if pinfo.chibi_id != 0:
            print(f"        .chibi_id = FID_FACTION_CHIBI_{pinfo.chibi_id} - FID_FACTION_CHIBI,")

        if pinfo.affinity != 0:
            print(f"        .affinity = AFFINITY_{pinfo.affinity},")

        if pinfo.unk_0A != 0:
            print(f"        .unk_0A = {pinfo.unk_0A},")

        if pinfo.base_level != 0:
            print(f"        .base_level = {pinfo.base_level},")
        if pinfo.base_hp != 0:
            print(f"        .base_hp = {pinfo.base_hp},")
        if pinfo.base_pow != 0:
            print(f"        .base_pow = {pinfo.base_pow},")
        if pinfo.base_skl != 0:
            print(f"        .base_skl = {pinfo.base_skl},")
        if pinfo.base_spd != 0:
            print(f"        .base_spd = {pinfo.base_spd},")
        if pinfo.base_def != 0:
            print(f"        .base_def = {pinfo.base_def},")
        if pinfo.base_res != 0:
            print(f"        .base_res = {pinfo.base_res},")
        if pinfo.base_lck != 0:
            print(f"        .base_lck = {pinfo.base_lck},")
        if pinfo.bonus_con != 0:
            print(f"        .bonus_con = {pinfo.bonus_con},")

        wexp = [
            pinfo.wexp_sword,
            pinfo.wexp_lance,
            pinfo.wexp_axe,
            pinfo.wexp_bow,
            pinfo.wexp_staff,
            pinfo.wexp_anima,
            pinfo.wexp_light,
            pinfo.wexp_elder]

        if sum(wexp) != 0:
            print(f"        .wexp =")
            print(f"        {{")

            for i, exp in enumerate(wexp):
                if exp != 0:
                    print(f"            [{ITEM_KIND_NAMES[i]}] = {WEXP_MAP[exp]},")

            print(f"        }},")

        if pinfo.growth_hp != 0:
            print(f"        .growth_hp = {pinfo.growth_hp},")
            print(f"        .growth_pow = {pinfo.growth_pow},")
            print(f"        .growth_skl = {pinfo.growth_skl},")
            print(f"        .growth_spd = {pinfo.growth_spd},")
            print(f"        .growth_def = {pinfo.growth_def},")
            print(f"        .growth_res = {pinfo.growth_res},")
            print(f"        .growth_lck = {pinfo.growth_lck},")

        if pinfo.banim_pal_a != 0:
            print(f"        .banim_pal_a = BANIM_PAL_{pinfo.banim_pal_a:02X},")
        if pinfo.banim_pal_b != 0:
            print(f"        .banim_pal_b = BANIM_PAL_{pinfo.banim_pal_b:02X},")

        print(f"        .attributes = {unit_attributes_expr(pinfo.attributes)},")

        if pinfo.support_info != 0:
            print(f"        .support_info = &{names[pinfo.support_info]},")

        print(f"    }},")

        is_first = False

    print("};")

if __name__ == '__main__':
    main(sys.argv)    
