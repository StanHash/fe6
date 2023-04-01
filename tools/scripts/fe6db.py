from collections import namedtuple
import re
import struct
from typing import List, NamedTuple, Tuple

def name_to_words(name: str) -> List[str]:
    return [w for w in re.sub(r'[^A-Za-z0-9 ]+', '', name).split()]

def name_to_big_sticky(name: str) -> str:
    return ''.join(name_to_words(name)).upper()

def name_to_pascal_sticky(name: str) -> str:
    return ''.join(f"{w[0].upper()}{w[1:].lower()}" for w in name_to_words(name))

def name_to_constant(name: str) -> str:
    part_a = re.sub(r'\(.+\)', '', name)
    part_b = re.match(r'.+\((.+)\)', name)
    part_b = part_b.group(1) if part_b is not None else None

    return name_to_big_sticky(part_a) if part_b is None else f"{name_to_big_sticky(part_a)}_{name_to_big_sticky(part_b)}"

def name_to_identifier(name: str) -> str:
    part_a = re.sub(r'\(.+\)', '', name)
    part_b = re.match(r'.+\((.+)\)', name)
    part_b = part_b.group(1) if part_b is not None else None

    return name_to_pascal_sticky(part_a) if part_b is None else f"{name_to_pascal_sticky(part_a)}_{name_to_pascal_sticky(part_b)}"

def name_to_display(name: str) -> str:
    return re.sub(r'\(.+\)', '', name).strip()

ALL_IIDS = [1 + x for x in range(0x7F)]
ALL_PIDS = [1 + x for x in range(0xE2)]
ALL_JIDS = [1 + x for x in range(0x4B)]
ALL_CHAPTERS = [x for x in range(0x2D)]

ITEM_NAME_DICT = {
    0x01: "Iron Sword",
    0x02: "Iron Blade",
    0x03: "Steel Sword",
    0x04: "Silver Sword",
    0x05: "Slim Sword",
    0x06: "Poison Sword",
    0x07: "Brave Sword",
    0x08: "Light Brand",
    0x09: "Durandal",
    0x0A: "Armorslayer",
    0x0B: "Rapier",
    0x0C: "Killing Edge",
    0x0D: "Lancereaver",
    0x0E: "Wo Dao",
    0x0F: "Binding Blade",
    0x10: "Iron Lance",
    0x11: "Steel Lance",
    0x12: "Silver Lance",
    0x13: "Slim Lance",
    0x14: "Poison Lance",
    0x15: "Brave Lance",
    0x16: "Javelin",
    0x17: "Maltet",
    0x18: "Horseslayer",
    0x19: "Killer Lance",
    0x1A: "Axereaver",
    0x1B: "Iron Axe",
    0x1C: "Steel Axe",
    0x1D: "Silver Axe",
    0x1E: "Poison Axe",
    0x1F: "Brave Axe",
    0x20: "Hand Axe",
    0x21: "Armads",
    0x22: "Hammer",
    0x23: "Killer Axe",
    0x24: "Swordreaver",
    0x25: "Devil Axe",
    0x26: "Halberd",
    0x27: "Iron Bow",
    0x28: "Steel Bow",
    0x29: "Silver Bow",
    0x2A: "Poison Bow",
    0x2B: "Killer Bow",
    0x2C: "Brave Bow",
    0x2D: "Short Bow",
    0x2E: "Long Bow",
    0x2F: "Mulagir",
    0x30: "Ballista",
    0x31: "Long Ballista",
    0x32: "Killer Ballista",
    0x33: "Fire",
    0x34: "Thunder",
    0x35: "Fimbulvetr",
    0x36: "Elfire",
    0x37: "Aircalibur",
    0x38: "Fenrir",
    0x39: "Bolting",
    0x3A: "Forblaze",
    0x3B: "Lightning",
    0x3C: "Divine",
    0x3D: "Purge",
    0x3E: "Aureola",
    0x3F: "Flux",
    0x40: "Nosferatu",
    0x41: "Eclipse",
    0x42: "Apocalypse",
    0x43: "Heal",
    0x44: "Mend",
    0x45: "Recover",
    0x46: "Physic",
    0x47: "Fortify",
    0x48: "Warp",
    0x49: "Rescue",
    0x4A: "Restore",
    0x4B: "Silence",
    0x4C: "Sleep",
    0x4D: "Torch",
    0x4E: "Hammerne",
    0x4F: "Watch",
    0x50: "Berserk",
    0x51: "Unlock",
    0x52: "Barrier",
    0x53: "Firestone",
    0x54: "Divinestone",
    0x55: "Demonstone",
    0x56: "Secret Book",
    0x57: "Goddess Icon",
    0x58: "Seraph Robe",
    0x59: "Dracoshield",
    0x5A: "Energy Ring",
    0x5B: "Speedwing",
    0x5C: "Talisman",
    0x5D: "Boots",
    0x5E: "Body Ring",
    0x5F: "Hero Crest",
    0x60: "Knight Crest",
    0x61: "Orion's Bolt",
    0x62: "Elysian Whip",
    0x63: "Guiding Ring",
    0x64: "Chest Key",
    0x65: "Door Key",
    0x66: "Bridge Key",
    0x67: "Lockpick",
    0x68: "Vulnerary",
    0x69: "Elixir",
    0x6A: "Pure Water",
    0x6B: "Torch",
    0x6C: "Antitoxin",
    0x6D: "Member Card",
    0x6E: "Silver Card",
    0x6F: "Gold",
    0x70: "Dark Breath",
    0x71: "Eckesachs",
    0x72: "Steel Blade",
    0x73: "Silver Blade",
    0x74: "Al's Sword",
    0x75: "Gant's Lance",
    0x76: "Tina's Staff",
    0x77: "Saint's Staff",
    0x78: "Wyrmslayer",
    0x79: "White Gem",
    0x7A: "Blue Gem",
    0x7B: "Red Gem",
    0x7C: "Delphi Shield",
    0x7D: "Runesword",
    0x7E: "Spear",
    0x7F: "Tomahawk"}

CLASS_NAME_DICT = {
    0x01: "Roy",
    0x02: "Mercenary",
    0x03: "Mercenary (F)",
    0x04: "Hero",
    0x05: "Hero (F)",
    0x06: "Myrmidon",
    0x07: "Myrmidon (F)",
    0x08: "Swordmaster",
    0x09: "Swordmaster (F)",
    0x0A: "Fighter",
    0x0B: "Warrior",
    0x0C: "Armor",
    0x0D: "Armor (F)",
    0x0E: "General",
    0x0F: "General (F)",
    0x10: "Archer",
    0x11: "Archer (F)",
    0x12: "Sniper",
    0x13: "Sniper (F)",
    0x14: "Priest",
    0x15: "Cleric",
    0x16: "Bishop",
    0x17: "Bishop (F)",
    0x18: "Mage",
    0x19: "Mage (F)",
    0x1A: "Sage",
    0x1B: "Sage (F)",
    0x1C: "Shaman",
    0x1D: "Shaman (F)",
    0x1E: "Druid",
    0x1F: "Druid (F)",
    0x20: "Cavalier",
    0x21: "Cavalier (F)",
    0x22: "Paladin",
    0x23: "Paladin (F)",
    0x24: "Troubadour",
    0x25: "Valkyrie",
    0x26: "Nomad",
    0x27: "Nomad (F)",
    0x28: "Nomad Trooper",
    0x29: "Nomad Trooper (F)",
    0x2A: "Pegasus Knight",
    0x2B: "Falcon Knight",
    0x2C: "Wyvern Rider",
    0x2D: "Wyvern Rider (F)",
    0x2E: "Wyvern Lord",
    0x2F: "Wyvern Lord (F)",
    0x30: "Soldier",
    0x31: "Brigand",
    0x32: "Pirate",
    0x33: "Berserker",
    0x34: "Thief",
    0x35: "Thief (F)",
    0x36: "Bard",
    0x37: "Dancer",
    0x38: "Manakete",
    0x39: "Manakete (F)",
    0x3A: "Fire Dragon",
    0x3B: "Divine Dragon",
    0x3C: "Demon Dragon",
    0x3D: "King",
    0x3E: "Civilian",
    0x3F: "Civilian (F)",
    0x40: "Child",
    0x41: "Child (F)",
    0x42: "Supply",
    0x43: "Roy (Promoted)",
    0x44: "Ballista (Mounted)",
    0x45: "Long Ballista (Mounted)",
    0x46: "Killer Ballista (Mounted)",
    0x47: "Ballista",
    0x48: "Long Ballista",
    0x49: "Killer Ballista",
    0x4A: "Dismounted",
    0x4B: "Dismounted (F)"}

CHARACTER_NAME_DICT = {
    0x01: "Roy",
    0x02: "Clarine",
    0x03: "Fae",
    0x04: "Sin",
    0x05: "Sue",
    0x06: "Dayan",
    0x07: "Dayan (Alt)",
    0x08: "Barthe",
    0x09: "Bors",
    0x0A: "Gwendolyn",
    0x0B: "Douglas",
    0x0C: "Douglas (Alt)",
    0x0D: "Wolt",
    0x0E: "Dorothy",
    0x0F: "Klein",
    0x10: "Saul",
    0x11: "Elen",
    0x12: "Yoder",
    0x13: "Yoder (Alt)",
    0x14: "Chad",
    0x15: "Karel",
    0x16: "Fir",
    0x17: "Rutger",
    0x18: "Dieck",
    0x19: "Ogier",
    0x1A: "Garret",
    0x1B: "Alen",
    0x1C: "Lance",
    0x1D: "Perceval",
    0x1E: "Igrene",
    0x1F: "Marcus",
    0x20: "Astolfo",
    0x21: "Ward",
    0x22: "Lot",
    0x23: "Bartre",
    0x24: "Bartre (Alt)",
    0x25: "Lugh",
    0x26: "Lilina",
    0x27: "Hugh",
    0x28: "Niime",
    0x29: "Niime (Alt)",
    0x2A: "Raigh",
    0x2B: "Larum",
    0x2C: "Juno",
    0x2D: "Juno (Alt)",
    0x2E: "Thea",
    0x2F: "Thea (NPC)",
    0x30: "Thea (NPC, Alt)",
    0x31: "Shanna",
    0x32: "Zeiss",
    0x33: "Galle",
    0x34: "Elffin",
    0x35: "Cath",
    0x36: "Sophia",
    0x37: "Melady",
    0x38: "Gonzalez",
    0x39: "Gonzalez (Alt)",
    0x3A: "Noah",
    0x3B: "Trec",
    0x3C: "Zelot",
    0x3D: "Echidna",
    0x3E: "Echidna (Alt)",
    0x3F: "Cecilia",
    0x40: "Geese",
    0x41: "Geese (Alt)",
    0x42: "Merlinus",
    0x43: "Eliwood",
    0x44: "Guinivere",

    0x59: "Narcian",

    0x62: "Murdock",
    0x63: "Brunnya",
    0x64: "Zephiel",
    0x65: "Idunn",
    0x66: "Idunn (Dragon)",
    0x67: "Jahn",

    0xA4: "Citizen (A4)",

    0xCD: "Citizen (CD)",

    0xCF: "Hector",
    0xD0: "Bors (Tutorial)",

    0xE1: "Arena Opponent",
    0xE2: "Wall"}

ITEM_IID_OVERRIDE_DICT = {
    0x43: "IID_HEALSTAFF",
    0x44: "IID_MENDSTAFF",
    0x45: "IID_RECOVERSTAFF",
    0x46: "IID_PHYSICSTAFF",
    0x47: "IID_FORTIFYSTAFF",
    0x48: "IID_WARPSTAFF",
    0x49: "IID_RESCUESTAFF",
    0x4A: "IID_RESTORESTAFF",
    0x4B: "IID_SILENCESTAFF",
    0x4C: "IID_SLEEPSTAFF",
    0x4D: "IID_TORCHSTAFF",
    0x4E: "IID_HAMMERNESTAFF",
    0x4F: "IID_WATCHSTAFF",
    0x50: "IID_BERSERKSTAFF",
    0x51: "IID_UNLOCKSTAFF",
    0x52: "IID_BARRIERSTAFF"}

CLASS_JID_OVERRIDE_DICT = {}

CHARACTER_PID_OVERRIDE_DICT = {
    0x30: "PID_THEA_NPC_ALT",
    0xB0: "PID_COMMON_MANAKETE",
    0xD1: "PID_TUTORIAL_SOLDIER",
    0xD2: "PID_TUTORIAL_ARCHER",
    0xD8: "PID_KLEIN_SQUAD",
    0xD9: "PID_THEA_SQUAD",
    0xE1: "PID_ARENA_OPPONENT"}

CHAPTER_OVERRIDE_DICT = {
    0x00: 'CHAPTER_TUTORIAL',
    0x01: 'CHAPTER_1',
    0x02: 'CHAPTER_2',
    0x03: 'CHAPTER_3',
    0x04: 'CHAPTER_4',
    0x05: 'CHAPTER_5',
    0x06: 'CHAPTER_6',
    0x07: 'CHAPTER_7',
    0x08: 'CHAPTER_8',
    0x09: 'CHAPTER_9',
    0x0A: 'CHAPTER_10_A',
    0x0B: 'CHAPTER_11_A',
    0x0C: 'CHAPTER_12',
    0x0D: 'CHAPTER_13',
    0x0E: 'CHAPTER_14',
    0x0F: 'CHAPTER_15',
    0x10: 'CHAPTER_16',
    0x11: 'CHAPTER_17_I',
    0x12: 'CHAPTER_18_I',
    0x13: 'CHAPTER_19_I',
    0x14: 'CHAPTER_20_I',
    0x15: 'CHAPTER_21',
    0x16: 'CHAPTER_22',
    0x17: 'CHAPTER_23',
    0x18: 'CHAPTER_24',
    0x19: 'CHAPTER_FINAL',
    0x1A: 'CHAPTER_10_B',
    0x1B: 'CHAPTER_11_B',
    0x1C: 'CHAPTER_17_S',
    0x1D: 'CHAPTER_18_S',
    0x1E: 'CHAPTER_19_S',
    0x1F: 'CHAPTER_20_S',
    0x20: 'CHAPTER_8X',
    0x21: 'CHAPTER_12X',
    0x22: 'CHAPTER_14X',
    0x23: 'CHAPTER_16X',
    0x24: 'CHAPTER_20X_I',
    0x25: 'CHAPTER_20X_S',
    0x26: 'CHAPTER_21X',
    0x27: 'CHAPTER_MULTIARENA',
    0x28: 'CHAPTER_TRIAL_A',
    0x29: 'CHAPTER_TRIAL_B',
    0x2A: 'CHAPTER_TRIAL_C',
    0x2B: 'CHAPTER_TRIAL_D',
    0x2C: 'CHAPTER_TRIAL_E'}

def iid_name(iid: int) -> str:
    if iid in ITEM_IID_OVERRIDE_DICT:
        return ITEM_IID_OVERRIDE_DICT[iid]

    if iid in ITEM_NAME_DICT:
        return f"IID_{name_to_constant(ITEM_NAME_DICT[iid])}"

    return f"IID_UNKNOWN_{iid:02X}"

def jid_name(jid: int) -> str:
    if jid in CLASS_JID_OVERRIDE_DICT:
        return CLASS_JID_OVERRIDE_DICT[jid]

    if jid in CLASS_NAME_DICT:
        return f"JID_{name_to_constant(CLASS_NAME_DICT[jid])}"

    return f"JID_UNKNOWN_{jid:02X}"

def jid_ident(jid: int) -> str:
    if jid in CLASS_NAME_DICT:
        return f"{name_to_identifier(CLASS_NAME_DICT[jid])}"

    return f"Unk_Jid{jid:02X}"

def pid_name(pid: int) -> str:
    if pid in CHARACTER_PID_OVERRIDE_DICT:
        return CHARACTER_PID_OVERRIDE_DICT[pid]

    if pid in CHARACTER_NAME_DICT:
        return f"PID_{name_to_constant(CHARACTER_NAME_DICT[pid])}"

    return f"PID_UNKNOWN_{pid:02X}"

def chapter_name(chapter: int) -> str:
    if chapter in CHAPTER_OVERRIDE_DICT:
        return CHAPTER_OVERRIDE_DICT[chapter]

    return f"CHAPTER_UNK_{chapter:02X}"

IID_DICT = { iid: iid_name(iid) for iid in ALL_IIDS }
JID_DICT = { jid: jid_name(jid) for jid in ALL_JIDS }
PID_DICT = { pid: pid_name(pid) for pid in ALL_PIDS }
CHAPTER_DICT = { chapter: chapter_name(chapter) for chapter in ALL_CHAPTERS }

IINFO_LAYOUT = [
    ('msg_name', 'H'),
    ('msg_desc', 'H'),
    ('msg_desc_use', 'H'),
    ('id', 'B'),
    ('kind', 'B'),
    ('attributes', 'H'),
    ('', 'xx'), # pad
    ('bonuses', 'I'), # ptr
    ('effectiveness', 'I'), # ptr
    ('uses', 'B'),
    ('might', 'B'),
    ('hit', 'B'),
    ('weight', 'B'),
    ('crit', 'B'),
    ('encoded_range', 'B'),
    ('cost_per_use', 'H'),
    ('required_wexp', 'B'),
    ('icon', 'B'),
    ('item_effect', 'B'),
    ('weapon_effect', 'B')]

PINFO_LAYOUT = [
    ('msg_name', 'H'),
    ('msg_desc', 'H'),
    ('id', 'B'),
    ('jid_default', 'B'),
    ('fid', 'H'),
    ('chibi_id', 'B'),
    ('affinity', 'B'),
    ('unk_0A', 'B'),
    ('base_level', 'B'),
    ('base_hp', 'B'),
    ('base_pow', 'B'),
    ('base_skl', 'B'),
    ('base_spd', 'B'),
    ('base_def', 'B'),
    ('base_res', 'B'),
    ('base_lck', 'B'),
    ('bonus_con', 'B'),
    ('wexp_sword', 'B'),
    ('wexp_lance', 'B'),
    ('wexp_axe', 'B'),
    ('wexp_bow', 'B'),
    ('wexp_staff', 'B'),
    ('wexp_anima', 'B'),
    ('wexp_light', 'B'),
    ('wexp_elder', 'B'),
    ('growth_hp', 'B'),
    ('growth_pow', 'B'),
    ('growth_skl', 'B'),
    ('growth_spd', 'B'),
    ('growth_def', 'B'),
    ('growth_res', 'B'),
    ('growth_lck', 'B'),
    ('banim_pal_a', 'B'),
    ('banim_pal_b', 'B'),
    ('', 'xxx'), # pad
    ('attributes', 'I'),
    ('support_info', 'I')] # ptr

JINFO_LAYOUT = [
    ('msg_name', 'H'),
    ('msg_desc', 'H'),
    ('id', 'B'),
    ('jid_promote', 'B'),
    ('map_sprite', 'B'),
    ('walk_speed', 'B'),
    ('fid', 'H'),
    ('unk_0A', 'B'),
    ('base_hp', 'B'),
    ('base_pow', 'B'),
    ('base_skl', 'B'),
    ('base_spd', 'B'),
    ('base_def', 'B'),
    ('base_res', 'B'),
    ('base_con', 'B'),
    ('base_mov', 'B'),
    ('max_hp', 'B'),
    ('max_pow', 'B'),
    ('max_skl', 'B'),
    ('max_spd', 'B'),
    ('max_def', 'B'),
    ('max_res', 'B'),
    ('max_con', 'B'),
    ('power_level', 'B'),
    ('growth_hp', 'B'),
    ('growth_pow', 'B'),
    ('growth_skl', 'B'),
    ('growth_spd', 'B'),
    ('growth_def', 'B'),
    ('growth_res', 'B'),
    ('growth_lck', 'B'),
    ('', 'xx'), # pad
    ('attributes', 'I'),
    ('wexp_sword', 'B'),
    ('wexp_lance', 'B'),
    ('wexp_axe', 'B'),
    ('wexp_bow', 'B'),
    ('wexp_staff', 'B'),
    ('wexp_anima', 'B'),
    ('wexp_light', 'B'),
    ('wexp_elder', 'B'),
    ('banim_info', 'I'), # ptr
    ('mov_table', 'I'), # ptr
    ('avo_terrain_table', 'I'), # ptr
    ('def_terrain_table', 'I'), # ptr
    ('res_terrain_table', 'I'), # ptr
    ('unk_44', 'I')] # ptr?

def unpack_from_layout(bytes: bytes, name: str, layout: List[Tuple[str, str]]):
    result_type = namedtuple(name, (field[0] for field in layout if len(field[0]) != 0))
    return result_type._make(struct.unpack(f"<{''.join((field[1] for field in layout))}", bytes))

def all_iinfo(rom_data):
    for iid in ALL_IIDS:
        off = iid * 0x20
        ent_data = rom_data[0x60B648 + off:0x60B648 + off + 0x20]
        yield iid, unpack_from_layout(ent_data, 'IInfo', IINFO_LAYOUT)

def all_pinfo(rom_data):
    for pid in ALL_PIDS:
        off = (pid - 1) * 0x30
        ent_data = rom_data[0x6076D0 + off:0x6076D0 + off + 0x30]
        yield pid, unpack_from_layout(ent_data, 'PInfo', PINFO_LAYOUT)

def all_jinfo(rom_data):
    for jid in ALL_JIDS:
        off = (jid - 1) * 0x48
        ent_data = rom_data[0x60A130 + off:0x60A130 + off + 0x48]
        yield jid, unpack_from_layout(ent_data, 'JInfo', JINFO_LAYOUT)

# following this is stuff I used for listing game data objects for dumping

def print_all_support_info(rom_data):
    for pid, pinfo in all_pinfo(rom_data):
        if pinfo.support_info != 0:
            print(f"{pinfo.support_info:08X} SupportInfo_{name_to_identifier(CHARACTER_NAME_DICT[pid])}")

def print_all_banim_info(rom_data):
    for jid, jinfo in all_jinfo(rom_data):
        if jinfo.banim_info != 0:
            print(f"{jinfo.banim_info:08X} BanimInfo_{jid_ident(jid)}")

def print_all_mov_tables(rom_data):
    for jid, jinfo in all_jinfo(rom_data):
        if jinfo.mov_table != 0:
            print(f"{jinfo.mov_table:08X} MoveTable_{jid_ident(jid)}")

def print_all_terrain_tables(rom_data):
    for jid, jinfo in all_jinfo(rom_data):
        if jinfo.avo_terrain_table != 0:
            print(f"{jinfo.avo_terrain_table:08X} TerrainAvoTable_{jid_ident(jid)}")
        if jinfo.def_terrain_table != 0:
            print(f"{jinfo.def_terrain_table:08X} TerrainDefTable_{jid_ident(jid)}")
        if jinfo.res_terrain_table != 0:
            print(f"{jinfo.res_terrain_table:08X} TerrainResTable_{jid_ident(jid)}")

def print_all_unk_44(rom_data):
    for jid, jinfo in all_jinfo(rom_data):
        if jinfo.unk_44 != 0:
            print(f"{jinfo.unk_44:08X} gUnk_Jinfo44_{jid_ident(jid)}")

def print_all_iinfo_bonuses(rom_data):
    for iid, iinfo in all_iinfo(rom_data):
        if iinfo.bonuses != 0:
            print(f"{iinfo.bonuses:08X} ItemBonuses_{name_to_identifier(ITEM_NAME_DICT[iid])}")

def print_all_iinfo_effectiveness(rom_data):
    for iid, iinfo in all_iinfo(rom_data):
        if iinfo.effectiveness != 0:
            print(f"{iinfo.effectiveness:08X} JList_Effectiveness_{name_to_identifier(ITEM_NAME_DICT[iid])}")
