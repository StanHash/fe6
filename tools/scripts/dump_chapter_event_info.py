import sys

import symbols
from fe6db import IID_DICT, JID_DICT, PID_DICT, CHAPTER_DICT

CMD_REF_ADDR = 0x08666114

ALL_CMDS = [x for x in range(14)]

CMD_NAMES = {
    0x00: 'End',
    0x01: 'Flag',
    0x02: 'Turn',
    0x03: 'TurnHard',
    0x04: 'Talk',
    0x05: 'Tile',
    0x06: 'TileMapChange',
    0x07: 'Chest',
    0x08: 'Door',
    0x09: 'Drawbridge',
    0x0A: 'Shop',
    0x0B: 'Area',
    0x0C: 'AreaHard',
    0x0D: 'Func'}

FACTION_NAMES = {
    0x00: 'FACTION_BLUE',
    0x40: 'FACTION_GREEN',
    0x80: 'FACTION_RED',
    0xC0: 'FACTION_PURPLE'}

TILE_COMMAND_NAMES = {
    0x00: 'TILE_COMMAND_NONE',
    0x0E: 'TILE_COMMAND_VISIT',
    0x0F: 'TILE_COMMAND_SEIZE',
    0x10: 'TILE_COMMAND_DOOR',
    0x11: 'TILE_COMMAND_BRIDGE',
    0x12: 'TILE_COMMAND_CHEST',
    0x13: 'TILE_COMMAND_ARMORY',
    0x14: 'TILE_COMMAND_VENDOR',
    0x15: 'TILE_COMMAND_SECRET',
    0x16: 'TILE_COMMAND_SHOP_UNK',
    0x1D: 'TILE_COMMAND_PILLAGE'}

def read_cmd_size(rom_data: bytes, cmd: int) -> int:
    int_bytes = rom_data[CMD_REF_ADDR - 0x08000000 + 4 + cmd * 8:CMD_REF_ADDR - 0x08000000 + 8 + cmd * 8]
    return int.from_bytes(int_bytes, 'little')

def main(args):
    try:
        rom_path = args[1]
        base_addrs = [(int(arg, base = 0) & 0x01FFFFFF) + 0x08000000 for arg in args[2:]]

    except IndexError:
        sys.exit(f"Usage: {args[0]} ROM ADDR...")

    with open(rom_path, 'rb') as f:
        rom_data = f.read()

    elf_path = rom_path.replace(".gba", ".elf")

    with open(elf_path, 'rb') as f:
        names = { addr: name for addr, name in symbols.from_elf(f) }

    cmd_sizes = { cmd: read_cmd_size(rom_data, cmd) for cmd in ALL_CMDS }

    for base_addr in base_addrs:
        # part 1: read ChapterEventInfo

        off = base_addr - 0x08000000
        info_data = rom_data[off:off + 0x1C]

        event_list_turn = int.from_bytes(info_data[0x00:0x04], 'little')
        event_list_talk = int.from_bytes(info_data[0x04:0x08], 'little')
        event_list_tile = int.from_bytes(info_data[0x08:0x0C], 'little')
        event_list_move = int.from_bytes(info_data[0x0C:0x10], 'little')
        units_red = int.from_bytes(info_data[0x10:0x14], 'little')
        units_blue = int.from_bytes(info_data[0x14:0x18], 'little')
        event_script_victory = int.from_bytes(info_data[0x18:0x1C], 'little')

        addr = min(x for x in (event_list_turn, event_list_talk, event_list_tile, event_list_move) if x != 0)

        while addr < base_addr:
            name = f'EventListScr_Unk_{addr:08X}' if addr not in names else names[addr]
            names[addr] = name

            print()
            print(f"// EventListScr @ {addr:08X}")
            print(f'EventListScr CONST_DATA {name}[] =')
            print('{')

            off = addr - 0x08000000

            while True:
                cmd = int.from_bytes(rom_data[off:off + 2], 'little')

                if cmd not in ALL_CMDS:
                    print(f"// error @ {off + 0x08000000:08X}")
                    break

                cmd_data = rom_data[off:off + 4 * cmd_sizes[cmd]]
                off = off + 4 * cmd_sizes[cmd]

                cmd_name = CMD_NAMES[cmd]

                line = f'    EvtList{cmd_name}'

                ent_flag_name = 0
                ent_script_name = '0'

                if cmd_name != 'End':
                    ent_flag = int.from_bytes(cmd_data[2:4], 'little')
                    ent_flag_name = f'FLAG_{ent_flag}' if ent_flag != 0 else '0'

                if cmd_name not in ('End', 'Chest'):
                    ent_script = int.from_bytes(cmd_data[4:8], 'little')
                    ent_script_name = f'{names[ent_script] if ent_script != 1 else "EVENT_NOSCRIPT"}'

                if cmd_name == 'Flag':
                    flag = int.from_bytes(cmd_data[8:12], 'little')
                    flag_name = f'FLAG_{flag}' if flag != 0 else '0'
                    line = f'{line}({ent_flag_name}, {ent_script_name}, {flag_name})'

                if cmd_name in ('Turn', 'TurnHard'):
                    turn = int.from_bytes(cmd_data[8:9], 'little')
                    turn_max = int.from_bytes(cmd_data[9:10], 'little')
                    faction = int.from_bytes(cmd_data[10:11], 'little')
                    line = f'{line}({ent_flag_name}, {ent_script_name}, {turn}, {turn_max}, {FACTION_NAMES[faction]})'

                if cmd_name == 'Talk':
                    pid_a = int.from_bytes(cmd_data[8:9], 'little')
                    pid_b = int.from_bytes(cmd_data[9:10], 'little')
                    line = f'{line}({ent_flag_name}, {ent_script_name}, {PID_DICT[pid_a]}, {PID_DICT[pid_b]})'

                if cmd_name in ('Tile', 'TileMapChange', 'Door', 'Drawbridge', 'Shop'):
                    x = int.from_bytes(cmd_data[8:9], 'little')
                    y = int.from_bytes(cmd_data[9:10], 'little')
                    tile_command = int.from_bytes(cmd_data[10:11], 'little')
                    line = f'{line}({ent_flag_name}, {ent_script_name}, {x}, {y}, {TILE_COMMAND_NAMES[tile_command]})'

                if cmd_name == 'Chest':
                    iid = int.from_bytes(cmd_data[4:6], 'little')
                    money = int.from_bytes(cmd_data[6:8], 'little')
                    x = int.from_bytes(cmd_data[8:9], 'little')
                    y = int.from_bytes(cmd_data[9:10], 'little')
                    tile_command = int.from_bytes(cmd_data[10:11], 'little')
                    line = f'{line}({ent_flag_name}, {IID_DICT[iid]}, {money}, {x}, {y}, {TILE_COMMAND_NAMES[tile_command]})'

                if cmd_name in ('Area', 'AreaHard'):
                    x1 = int.from_bytes(cmd_data[8:9], 'little')
                    y1 = int.from_bytes(cmd_data[9:10], 'little')
                    x2 = int.from_bytes(cmd_data[10:11], 'little')
                    y2 = int.from_bytes(cmd_data[11:12], 'little')
                    line = f'{line}({ent_flag_name}, {ent_script_name}, {x1}, {y1}, {x2}, {y2})'

                if cmd_name == 'Func':
                    func = int.from_bytes(cmd_data[8:12], 'little')
                    line = f'{line}({ent_flag_name}, {ent_script_name}, {names[func]})'

                print(line)

                if cmd_name == 'End':
                    break

            print('};')

            addr = off + 0x08000000

        print()
        print(f'// ChapterEventInfo @ {base_addr:08X}')
        print(f'struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_{base_addr:08X} =')
        print('{')

        if event_list_turn != 0:
            print(f'    .event_list_turn = {names[event_list_turn]},')

        if event_list_talk != 0:
            print(f'    .event_list_talk = {names[event_list_talk]},')

        if event_list_tile != 0:
            print(f'    .event_list_tile = {names[event_list_tile]},')

        if event_list_move != 0:
            print(f'    .event_list_move = {names[event_list_move]},')

        if units_red != 0:
            print(f'    .units_red = {names[units_red]},')

        if units_blue != 0:
            print(f'    .units_blue = {names[units_blue]},')

        if event_script_victory != 0:
            print(f'    .event_script_victory = {names[event_script_victory]},')

        print('};')

if __name__ == '__main__':
    main(sys.argv)
