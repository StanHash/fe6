import sys
import symbols
from fe6db import all_jinfo, JID_DICT
from dump_pinfo import ITEM_KIND_NAMES, WEXP_MAP, unit_attributes_expr

WALKSPEED_NAMES = {
    0x00: 'UNIT_WALKSPEED_FAST',
    0x01: 'UNIT_WALKSPEED_SLOW'}

def main(args):
    try:
        rom_path = args[1]

    except IndexError:
        return f"Usage: {args[0]} ROM"

    with open(rom_path, 'rb') as f:
        rom_data = f.read()

    elf_path = rom_path.replace(".gba", ".elf").replace("-base.elf", ".elf")

    with open(elf_path, 'rb') as f:
        names = { addr: name for addr, name in symbols.from_elf(f) }

    print("struct JInfo CONST_DATA JInfoTable[] =")
    print("{")

    is_first = True

    for jid, jinfo in all_jinfo(rom_data):
        if not is_first:
            print()

        print(f"    [{JID_DICT[jid]} - 1] =")
        print(f"    {{")

        print(f"        .id = {JID_DICT[jid]},")

        if jinfo.msg_name != 0:
            print(f"        .msg_name = MSG_{jinfo.msg_name:03X},")

        if jinfo.msg_desc != 0:
            print(f"        .msg_desc = MSG_{jinfo.msg_desc:03X},")

        if jinfo.jid_promote != 0:
            print(f"        .jid_promote = {JID_DICT[jinfo.jid_promote]},")

        print(f"        .map_sprite = UNITSPRITE_{jinfo.map_sprite:02X},")

        if jinfo.base_mov != 0:
            print(f"        .walk_speed = {WALKSPEED_NAMES[jinfo.walk_speed]},")

        if jinfo.fid != 0:
            print(f"        .fid = FID_{jinfo.fid:02X},")

        if jinfo.unk_0A != 0:
            print(f"        .unk_0A = {jinfo.unk_0A},")

        if jinfo.base_hp != 0:
            print(f"        .base_hp = {jinfo.base_hp},")
        if jinfo.base_pow != 0:
            print(f"        .base_pow = {jinfo.base_pow},")
        if jinfo.base_skl != 0:
            print(f"        .base_skl = {jinfo.base_skl},")
        if jinfo.base_spd != 0:
            print(f"        .base_spd = {jinfo.base_spd},")
        if jinfo.base_def != 0:
            print(f"        .base_def = {jinfo.base_def},")
        if jinfo.base_res != 0:
            print(f"        .base_res = {jinfo.base_res},")
        if jinfo.base_con != 0:
            print(f"        .base_con = {jinfo.base_con},")
        if jinfo.base_mov != 0:
            print(f"        .base_mov = {jinfo.base_mov},")

        if jinfo.max_hp != 0:
            print(f"        .max_hp = {jinfo.max_hp},")
        if jinfo.max_pow != 0:
            print(f"        .max_pow = {jinfo.max_pow},")
        if jinfo.max_skl != 0:
            print(f"        .max_skl = {jinfo.max_skl},")
        if jinfo.max_spd != 0:
            print(f"        .max_spd = {jinfo.max_spd},")
        if jinfo.max_def != 0:
            print(f"        .max_def = {jinfo.max_def},")
        if jinfo.max_res != 0:
            print(f"        .max_res = {jinfo.max_res},")
        if jinfo.max_con != 0:
            print(f"        .max_con = {jinfo.max_con},")

        if jinfo.power_level != 0:
            print(f"        .power_level = {jinfo.power_level},")

        if jinfo.growth_hp != 0:
            print(f"        .growth_hp = {jinfo.growth_hp},")
            print(f"        .growth_pow = {jinfo.growth_pow},")
            print(f"        .growth_skl = {jinfo.growth_skl},")
            print(f"        .growth_spd = {jinfo.growth_spd},")
            print(f"        .growth_def = {jinfo.growth_def},")
            print(f"        .growth_res = {jinfo.growth_res},")
            print(f"        .growth_lck = {jinfo.growth_lck},")

        print(f"        .attributes = {unit_attributes_expr(jinfo.attributes)},")

        wexp = [
            jinfo.wexp_sword,
            jinfo.wexp_lance,
            jinfo.wexp_axe,
            jinfo.wexp_bow,
            jinfo.wexp_staff,
            jinfo.wexp_anima,
            jinfo.wexp_light,
            jinfo.wexp_elder]

        if sum(wexp) != 0:
            print(f"        .wexp =")
            print(f"        {{")

            for i, exp in enumerate(wexp):
                if exp != 0:
                    print(f"            [{ITEM_KIND_NAMES[i]}] = {WEXP_MAP[exp]},")

            print(f"        }},")

        if jinfo.banim_info != 0:
            print(f"        .banim_info = {names[jinfo.banim_info]},")

        if jinfo.mov_table != 0:
            print(f"        .mov_table = {names[jinfo.mov_table]},")

        if jinfo.avo_terrain_table != 0:
            print(f"        .avo_terrain_table = {names[jinfo.avo_terrain_table]},")
        if jinfo.def_terrain_table != 0:
            print(f"        .def_terrain_table = {names[jinfo.def_terrain_table]},")
        if jinfo.res_terrain_table != 0:
            print(f"        .res_terrain_table = {names[jinfo.res_terrain_table]},")
        if jinfo.unk_44 != 0:
            print(f"        .unk_44 = {names[jinfo.unk_44]},")

        print(f"    }},")

        is_first = False

    print("};")

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
