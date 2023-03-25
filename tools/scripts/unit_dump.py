import sys

from fe6db import IID_DICT, JID_DICT, PID_DICT

START_ADDR = 0x08679974
END_ADDR = 0x0868784C

FACTION_NAMES = {
    0x00: "FACTION_ID_BLUE",
    0x01: "FACTION_ID_GREEN",
    0x02: "FACTION_ID_RED",
    0x03: "FACTION_ID_PURPLE"}

BOOL_NAMES = { 0: "FALSE", 1: "TRUE" }

EVENTSCR_LOAD_1_DATA = b'\x12\x00\x00\x00\x00\x00\x00\x00\x14\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00'
EVENTSCR_LOAD_1_MASK = b'\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF'

assert len(EVENTSCR_LOAD_1_DATA) == len(EVENTSCR_LOAD_1_MASK)

EVENTSCR_LOAD_2_DATA = b'\x16\x00\x00\x00\x40\x00\x00\x00' + EVENTSCR_LOAD_1_DATA
EVENTSCR_LOAD_2_MASK = b'\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF' + EVENTSCR_LOAD_1_MASK

assert len(EVENTSCR_LOAD_2_DATA) == len(EVENTSCR_LOAD_2_MASK)

def eventscr1_unit_addr(eventscr: bytes) -> int | None:
    if len(eventscr) != len(EVENTSCR_LOAD_1_DATA):
        return None

    for a, b, m in zip(eventscr, EVENTSCR_LOAD_1_DATA, EVENTSCR_LOAD_1_MASK):
        if a & m != b:
            return None

    return int.from_bytes(eventscr[4:8], 'little')

def eventscr2_unit_addr(eventscr: bytes) -> int | None:
    if len(eventscr) != len(EVENTSCR_LOAD_2_DATA):
        return None

    for a, b, m in zip(eventscr, EVENTSCR_LOAD_2_DATA, EVENTSCR_LOAD_2_MASK):
        if a & m != b:
            return None

    return int.from_bytes(eventscr[12:16], 'little')

def main(args):
    try:
        rom_path = args[1]

    except IndexError:
        sys.exit(f"Usage: {args[0]} ROM")

    with open(rom_path, 'rb') as f:
        rom_data = f.read()

    off = START_ADDR - 0x08000000
    group_count = 0

    while off < END_ADDR - 0x08000000:
        group_units = {}
        group_event_kinds = {}

        prev_off = off

        # units
        while True:
            head_u32 = int.from_bytes(rom_data[off:off + 4], 'little')

            if head_u32 != 0 and head_u32 < 100:
                break

            print()
            print(f"// UnitInfo @ {off + 0x08000000:08X}")

            list_name = f"UnitInfo_Unk_{off + 0x08000000:08X}"

            print(f"struct UnitInfo CONST_DATA {list_name}[] =")
            print("{")

            group_units[off + 0x08000000] = list_name

            while True:
                unitinfo = rom_data[off:off + 0x10]
                off = off + 0x10

                pid = unitinfo[0]
                jid = unitinfo[1]
                pid_lead = unitinfo[2]
                autolevel = unitinfo[3] & 1
                faction_id = (unitinfo[3] >> 1) & 3
                level = (unitinfo[3] >> 3) & 0x1F
                x_load = unitinfo[4]
                y_load = unitinfo[5]
                x_move = unitinfo[6]
                y_move = unitinfo[7]
                items = [unitinfo[8 + i] for i in range(4)]
                ai = [unitinfo[12 + i] for i in range(4)]

                if pid == 0:
                    print("    { 0 }, // end")
                    print("};")
                    break

                jid_str = f"{JID_DICT[jid]}" if jid != 0 else "0"
                pid_lead_str = f"{PID_DICT[pid_lead]}" if pid_lead != 0 else "0"

                item_names = []

                for item in items:
                    if item == 0:
                        break

                    item_names.append(IID_DICT[item])

                if len(item_names) == 0:
                    item_names.append("0")

                ai_names = []

                if ai[0] == 0 and ai[1] == 0 and ai[2] == 0 and ai[3] == 0:
                    ai_names.append("0")

                else:
                    ai_names.append(f"AI_A_{ai[0]:02X}")
                    ai_names.append(f"AI_B_{ai[1]:02X}")

                    if ai[2] != 0 or ai[3] != 0:
                        ai_names.append(f"0x{ai[2]:02X}")
                        ai_names.append(f"0x{ai[3]:02X}")

                print(f"    {{ {PID_DICT[pid]}, {jid_str}, {pid_lead_str},"
                    + f" {BOOL_NAMES[autolevel]}, {FACTION_NAMES[faction_id]}, {level},"
                    + f" {x_load}, {y_load}, {x_move}, {y_move},"
                    + f" {{ {', '.join(item_names)} }}, {{ {', '.join(ai_names)} }} }},")

        # events
        if len(group_units) != 0:
            while True:
                addr1 = eventscr1_unit_addr(rom_data[off:off + 0x14])
                addr2 = eventscr2_unit_addr(rom_data[off:off + 0x1C])

                if addr1 not in group_units and addr2 not in group_units:
                    print()
                    print(f"// Group {group_count} summary:")

                    for addr in sorted(group_units.keys()):
                        print(f"// Units {group_units[addr]} {group_event_kinds[addr]}")

                    group_count = group_count + 1
                    break

                units_addr = addr1 if addr1 in group_units else addr2

                print()
                print(f"// EventScr @ {off + 0x08000000:08X}")
                print(f"EventScr CONST_DATA EventScr_LoadUnits_{units_addr:08X}[] =")
                print("{")

                group_event_kinds[units_addr] = 1

                if addr2 != None:
                    off = off + 8
                    print(f"    EvtUnitCameraOff")
                    print(f"    EvtNoSkip")
                    group_event_kinds[units_addr] = 2

                off = off + 0x14
                print(f"    EvtLoadUnits({group_units[units_addr]})")
                print(f"    EvtMoveWait")
                print(f"    EvtClearSkip")
                print(f"    EvtEnd")
                print("};")

        if off == prev_off:
            break

if __name__ == '__main__':
    main(sys.argv)
