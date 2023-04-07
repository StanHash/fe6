import sys
from typing import List
import symbols
from fe6db import all_iinfo, IID_DICT
from dump_pinfo import ITEM_KIND_NAMES, WEXP_MAP

WALKSPEED_NAMES = {
    0x00: 'UNIT_WALKSPEED_FAST',
    0x01: 'UNIT_WALKSPEED_SLOW'}

ITEM_ATTRIBUTE_NAMES = [
    "ITEM_ATTR_WEAPON",
    "ITEM_ATTR_MAGIC",
    "ITEM_ATTR_STAFF",
    "ITEM_ATTR_UNBREAKABLE",
    "ITEM_ATTR_IMPORTANT",
    "ITEM_ATTR_BRAVE",
    "ITEM_ATTR_LIGHTBRAND",
    "ITEM_ATTR_UNCOUNTERABLE",
    "ITEM_ATTR_REVERTS_TRIANGLE",
    "ITEM_ATTR_UNREPAIRABLE",
    "ITEM_ATTR_LOCK_DRAGON",
    "ITEM_ATTR_LOCK_ROY",
    "ITEM_ATTR_LOCK_MYRM",
    "ITEM_ATTR_LOCK_ZEPHIEL",
    "ITEM_ATTR_DELPHI_SHIELD"]

WEAPON_EFFECT_NAMES = {
    1: 'WEAPON_EFFECT_POISON',
    2: 'WEAPON_EFFECT_NOSFERATU',
    3: 'WEAPON_EFFECT_ECLIPSE',
    4: 'WEAPON_EFFECT_DEVIL'}

def item_attributes_expr(item_attributes: int) -> str:
    terms: List[str] = []

    for i, attr_name in enumerate(ITEM_ATTRIBUTE_NAMES):
        if (item_attributes & (1 << i)) != 0:
            terms.append(attr_name)

    return ' | '.join(terms) if len(terms) != 0 else '0'

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

    print("struct IInfo CONST_DATA IInfoTable[] =")
    print("{")

    is_first = True

    for iid, iinfo in all_iinfo(rom_data):
        if not is_first:
            print()

        print(f"    [{IID_DICT[iid]}] =")
        print(f"    {{")

        print(f"        .id = {IID_DICT[iid]},")

        if iinfo.msg_name != 0:
            print(f"        .msg_name = MSG_{iinfo.msg_name:03X},")

        if iinfo.msg_desc != 0:
            print(f"        .msg_desc = MSG_{iinfo.msg_desc:03X},")

        if iinfo.msg_desc_use != 0:
            print(f"        .msg_desc_use = MSG_{iinfo.msg_desc_use:03X},")

        print(f"        .kind = {ITEM_KIND_NAMES[iinfo.kind]},")
        print(f"        .attributes = {item_attributes_expr(iinfo.attributes)},")

        if iinfo.bonuses != 0:
            print(f"        .bonuses = &{names[iinfo.bonuses]},")

        if iinfo.effectiveness != 0:
            print(f"        .effectiveness = {names[iinfo.effectiveness]},")

        if iinfo.uses != 0:
            print(f"        .uses = {iinfo.uses},")
        if iinfo.might != 0:
            print(f"        .might = {iinfo.might},")
        if iinfo.hit != 0:
            print(f"        .hit = {iinfo.hit},")
        if iinfo.weight != 0:
            print(f"        .weight = {iinfo.weight},")
        if iinfo.crit != 0:
            print(f"        .crit = {iinfo.crit},")

        if iinfo.encoded_range != 0:
            print(f"        .encoded_range = 0x{iinfo.encoded_range:02X},")

        if iinfo.cost_per_use != 0:
            print(f"        .cost_per_use = {iinfo.cost_per_use},")

        if iinfo.required_wexp != 0:
            print(f"        .required_wexp = {WEXP_MAP[iinfo.required_wexp]},")

        print(f"        .icon = ICON_ITEM_{iinfo.icon:02X},")

        if iinfo.item_effect != 0:
            print(f"        .item_effect = ITEM_EFFECT_{iinfo.item_effect:02X},")

        if iinfo.weapon_effect != 0:
            print(f"        .weapon_effect = {WEAPON_EFFECT_NAMES[iinfo.weapon_effect]},")

        print(f"    }},")

        is_first = False

    print("};")

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
