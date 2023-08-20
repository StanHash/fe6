import sys

import symbols
from fe6db import IID_DICT, JID_DICT, PID_DICT, CHAPTER_DICT

START_ADDR = 0x0866AAF8
END_ADDR = 0x0867619C
CMD_REF_ADDR = 0x085C4164

FACTION_NAMES = {
    0x00: 'FACTION_BLUE',
    0x40: 'FACTION_GREEN',
    0x80: 'FACTION_RED',
    0xC0: 'FACTION_PURPLE'}

BOOL_NAMES = { 0: 'FALSE', 1: 'TRUE' }

WEATHER_NAMES = {
    0x00: 'WEATHER_NONE',
    0x01: 'WEATHER_SNOW',
    0x02: 'WEATHER_SNOWSTORM',
    0x03: 'WEATHER_NIGHT',
    0x04: 'WEATHER_RAIN',
    0x05: 'WEATHER_FLAMES',
    0x06: 'WEATHER_SANDSTORM',
    0x07: 'WEATHER_CLOUDS'}

ALL_CMDS = [x for x in range(0x64)]

CMD_NAMES = {
    0x00: 'End',
    0x01: 'Kill',
    0x02: 'Sleep',
    0x03: 'Background',
    0x04: 'BackgroundMore',
    0x05: 'ClearTalk',
    0x06: 'ClearSkip',
    0x07: 'Talk',
    0x08: 'TalkMore',
    0x09: 'TalkAuto',
    0x0A: 'TalkContinue',
    0x0B: 'Camera',
    0x0C: 'CameraUnit',
    0x0D: 'Move',
    0x0E: 'MoveScript',
    0x0F: 'MoveUnit',
    0x10: 'MoveUnitScript',
    0x11: 'MoveUnitNextTo',
    0x12: 'LoadUnits',
    0x13: 'LoadUnitsParty',
    0x14: 'MoveWait',
    0x15: 'UnitCameraOn',
    0x16: 'UnitCameraOff',
    0x17: 'Func',
    0x18: 'FuncUntil',
    0x19: 'FuncWhile',
    0x1A: 'Stop',
    0x1B: 'Label',
    0x1C: 'Goto',
    0x1D: 'GotoIfNotAlive',
    0x1E: 'GotoIfNotInTeam',
    0x1F: 'GotoIfFunc',
    0x20: 'GotoIfNotFunc',
    0x21: 'GotoIfSkipped',
    0x22: 'GotoIfFlag',
    0x23: 'GotoIfNotFlag',
    0x24: 'GotoIfActive',
    0x25: 'Jump',
    0x26: 'GiveItem',
    0x27: 'GiveItemTo',
    0x28: 'GiveMoney',
    0x29: 'MapChange',
    0x2A: 'MapChangePosition',
    0x2B: 'ChangeFaction',
    0x2C: 'FlashCursor',
    0x2D: 'FlashCursorUnit',
    0x2E: 'PutCursor',
    0x2F: 'RemoveCursor',
    0x30: 'RemoveUnit',
    0x31: 'RemoveUnitDisplayed',
    0x32: 'SetAi',
    0x33: 'SetAiPosition',
    0x34: 'SetFlag',
    0x35: 'ClearFlag',
    0x36: 'SetBgm',
    0x37: 'OverrideBgm',
    0x38: 'RestoreBgm',
    0x39: 'FadeBgmOut',
    0x3A: 'LowerBgmVolume',
    0x3B: 'RaiseBgmVolume',
    0x3C: 'PlaySe',
    0x3D: 'NextChapter',
    0x3E: 'GameEnd',
    0x3F: 'SetMap',
    0x40: 'NoSkip',
    0x41: 'NoSkipNoTextSkip',
    0x42: 'YesSkip',
    0x43: 'FadeToBlack',
    0x44: 'FadeFromBlack',
    0x45: 'FadeToWhite',
    0x46: 'FadeFromWhite',
    0x47: 'ExitMap',
    0x48: 'EnterMap',
    0x49: 'FightScript',
    0x4A: 'DisableAutoClear',
    0x4B: 'FuncOnSkip',
    0x4C: 'Weather',
    0x4D: 'WmStart',
    0x4E: 'WmEnd',
    0x4F: 'WmZoomTo',
    0x50: 'WmZoomBack',
    0x51: 'WmPutFace',
    0x52: 'WmRemoveFace',
    0x53: 'WmMoveFace',
    0x54: 'WmNop54',
    0x55: 'WmNop55',
    0x56: 'WmTalk',
    0x57: 'WmTalkBoxBottom',
    0x58: 'WmTalkBoxTop',
    0x59: 'WmTalkBoxRemove',
    0x5A: 'WmArrow',
    0x5B: 'WmPutHighlight',
    0x5C: 'WmRemoveHighlight',
    0x5D: 'WmRemoveBothHighlights',
    0x5E: 'WmPutDot',
    0x5F: 'WmRemoveDot',
    0x60: 'WmPutFlag',
    0x61: 'WmRemoveFlag',
    0x62: 'WmPutMapText',
    0x63: 'WmPutRemoveMapText'}

def main(args):
    try:
        rom_path = args[1]
        start_addr = (int(args[2], base = 0) & 0x01FFFFFF) + 0x08000000
        end_addr = (int(args[3], base = 0) & 0x01FFFFFF) + 0x08000000

    except IndexError:
        sys.exit(f"Usage: {args[0]} ROM ADDR END")

    elf_path = rom_path.replace(".gba", ".elf")

    with open(rom_path, 'rb') as f:
        rom_data = f.read()

    with open(elf_path, 'rb') as f:
        names = { addr: name for addr, name in symbols.from_elf(f) }

    cmd_sizes = { cmd: int.from_bytes(rom_data[CMD_REF_ADDR - 0x08000000 + 4 + cmd * 8:CMD_REF_ADDR - 0x08000000 + 8 + cmd * 8], 'little') for cmd in ALL_CMDS }

    off = start_addr - 0x08000000

    while off < end_addr - 0x08000000:
        head_u32 = int.from_bytes(rom_data[off:off + 4], 'little')

        if head_u32 not in ALL_CMDS:
            print(f"// end @ {off + 0x08000000:08X}")
            break

        if off + 0x08000000 not in names:
            name = f'EventScr_Unk_{off + 0x08000000:08X}'
            names[off + 0x08000000] = name

        else:
            name = names[off + 0x08000000]

        print()
        print(f"// EventScr @ {off + 0x08000000:08X}")
        print(f"EventScr CONST_DATA {name}[] =")
        print("{")

        was_goto = False

        while True:
            cmd = int.from_bytes(rom_data[off:off + 4], 'little')

            if cmd not in ALL_CMDS:
                print(f"// error @ {off + 0x08000000:08X}")
                break

            if cmd not in CMD_NAMES:
                print(f"// nameless cmd: {cmd:02X} @ {off + 0x08000000:08X}")
                break

            cmd_name = CMD_NAMES[cmd]

            param_data = rom_data[off + 4:off + 4 * cmd_sizes[cmd]]
            off = off + 4 * cmd_sizes[cmd]

            # do not indent label cmds
            line = "" if cmd_name == 'Label' else "    "
            line = f"{line}Evt{cmd_name}"

            if was_goto or cmd_name == 'Label':
                print()

            # handle each cmd

            # End
            if cmd_name == 'End':
                print(line)
                print("};")
                break

            # one number
            if cmd_name in ('Sleep', 'GiveMoney', 'FadeBgmOut', 'FadeToBlack', 'FadeFromBlack', 'FadeToWhite', 'FadeFromWhite', 'WmRemoveHighlight', 'WmRemoveDot', 'WmRemoveFlag', 'WmRemoveMapText'):
                line = f"{line}({int.from_bytes(param_data, 'little')})"

            # background
            if cmd_name in ('Background', 'BackgroundMore'):
                line = f"{line}(BACKGROUND_{int.from_bytes(param_data, 'little')})"

            # talk
            if cmd_name in ('Talk', 'TalkMore', 'WmTalk'):
                line = f"{line}(MSG_{int.from_bytes(param_data, 'little'):03X})"

            # any one i16 coord pair cmd
            if cmd_name in ('Camera', 'FlashCursor', 'PutCursor', 'WmZoomTo', 'WmArrow'):
                x = int.from_bytes(param_data[0:2], 'little', signed = True)
                y = int.from_bytes(param_data[2:4], 'little', signed = True)
                line = f"{line}({x}, {y})"

            # Move
            if cmd_name == 'Move':
                x = int.from_bytes(param_data[0:2], 'little', signed = True)
                y = int.from_bytes(param_data[2:4], 'little', signed = True)
                x_to = int.from_bytes(param_data[4:6], 'little', signed = True)
                y_to = int.from_bytes(param_data[6:8], 'little', signed = True)
                line = f"{line}({x}, {y}, {x_to}, {y_to})"

            # MoveScript
            if cmd_name == 'MoveScript':
                x = int.from_bytes(param_data[0:2], 'little', signed = True)
                y = int.from_bytes(param_data[2:4], 'little', signed = True)
                movescr_addr = int.from_bytes(param_data[4:8], 'little')
                line = f"{line}({x}, {y}, {names[movescr_addr]})"

            # MoveUnit
            if cmd_name == 'MoveUnit':
                pid = int.from_bytes(param_data[0:4], 'little')
                x_to = int.from_bytes(param_data[4:6], 'little')
                y_to = int.from_bytes(param_data[6:8], 'little')
                line = f"{line}({PID_DICT[pid]}, {x_to}, {y_to})"

            # MoveUnitScript
            if cmd_name == 'MoveUnitScript':
                pid = int.from_bytes(param_data[0:4], 'little')
                movescr_addr = int.from_bytes(param_data[4:8], 'little')
                line = f"{line}({PID_DICT[pid]}, {names[movescr_addr]})"

            # MoveUnitNextTo
            if cmd_name == 'MoveUnitNextTo':
                pid = int.from_bytes(param_data[0:4], 'little')
                pid_to = int.from_bytes(param_data[4:8], 'little')
                line = f"{line}({PID_DICT[pid]}, {PID_DICT[pid_to]})"

            # one named addr
            if cmd_name in ('LoadUnits', 'LoadUnitsParty', 'Func', 'FuncUntil', 'FuncWhile', 'FuncOnSkip', 'Jump'):
                addr = int.from_bytes(param_data[0:4], 'little')
                line = f"{line}({names[addr]})"

            # one label
            if cmd_name in ('Label', 'Goto', 'GotoIfSkipped'):
                line = f"{line}({int.from_bytes(param_data, 'little')})"

            # label + pid
            if cmd_name in ('GotoIfNotAlive', 'GotoIfNotInTeam', 'GotoIfActive'):
                label = int.from_bytes(param_data[0:4], 'little')
                pid = int.from_bytes(param_data[4:8], 'little')
                line = f"{line}({label}, {PID_DICT[pid]})"

            # label + flag
            if cmd_name in ('GotoIfFlag', 'GotoIfNotFlag'):
                label = int.from_bytes(param_data[0:4], 'little')
                flag = int.from_bytes(param_data[4:8], 'little')
                line = f"{line}({label}, FLAG_{flag})"

            # label + addr
            if cmd_name in ('GotoIfFunc', 'GotoIfNotFunc'):
                label = int.from_bytes(param_data[0:4], 'little')
                addr = int.from_bytes(param_data[4:8], 'little')
                line = f"{line}({label}, {names[addr]})"

            # GiveItem
            if cmd_name == 'GiveItem':
                iid = int.from_bytes(param_data[0:4], 'little')
                line = f"{line}({IID_DICT[iid]})"

            # GiveItemTo
            if cmd_name == 'GiveItemTo':
                pid = int.from_bytes(param_data[0:4], 'little')
                iid = int.from_bytes(param_data[4:8], 'little')
                line = f"{line}({IID_DICT[iid]}, {PID_DICT[pid]})"

            # MapChange
            if cmd_name == 'MapChange':
                id = int.from_bytes(param_data[0:4], 'little')
                line = f"{line}({id})"

            # MapChangePosition
            if cmd_name == 'MapChangePosition':
                x = int.from_bytes(param_data[0:1], 'little')
                y = int.from_bytes(param_data[1:2], 'little')
                line = f"{line}({x}, {y})"

            # ChangeFaction
            if cmd_name == 'ChangeFaction':
                pid = int.from_bytes(param_data[0:4], 'little')
                fac = int.from_bytes(param_data[4:8], 'little')
                line = f"{line}({PID_DICT[pid]}, {FACTION_NAMES[fac]})"

            # one pid
            if cmd_name in ('CameraUnit', 'FlashCursorUnit', 'RemoveUnit', 'RemoveUnitDisplayed'):
                pid = int.from_bytes(param_data[0:4], 'little')
                line = f"{line}({PID_DICT[pid]})"

            # SetAi
            if cmd_name == 'SetAi':
                pid = int.from_bytes(param_data[0:4], 'little')
                ai_a = int.from_bytes(param_data[4:5], 'little')
                ai_b = int.from_bytes(param_data[5:6], 'little')
                ai_c = int.from_bytes(param_data[6:7], 'little')
                line = f"{line}({PID_DICT[pid]}, AI_A_{ai_a:02X}, AI_B_{ai_b:02X}, {f'0x{ai_c:02X}' if ai_c != 0 else '0'})"

            # SetAiPosition
            if cmd_name == 'SetAiPosition':
                x = int.from_bytes(param_data[0:2], 'little', signed = True)
                y = int.from_bytes(param_data[2:4], 'little', signed = True)
                ai_a = int.from_bytes(param_data[4:5], 'little')
                ai_b = int.from_bytes(param_data[5:6], 'little')
                ai_c = int.from_bytes(param_data[6:7], 'little')
                line = f"{line}({x}, {y}, AI_A_{ai_a:02X}, AI_B_{ai_b:02X}, {f'0x{ai_c:02X}' if ai_c != 0 else '0'})"

            # one flag
            if cmd_name in ('SetFlag', 'ClearFlag'):
                flag = int.from_bytes(param_data[0:4], 'little')
                line = f"{line}(FLAG_{flag})"

            # one song
            if cmd_name in ('SetBgm', 'OverrideBgm', 'PlaySe'):
                song = int.from_bytes(param_data[0:4], 'little')
                line = f"{line}(SONG_{song:02X})"

            # NextChapter
            if cmd_name == 'NextChapter':
                chapter = int.from_bytes(param_data[0:4], 'little')
                line = f"{line}({CHAPTER_DICT[chapter]})"

            # SetMap
            if cmd_name == 'SetMap':
                chapter = int.from_bytes(param_data[0:4], 'little')
                x = int.from_bytes(param_data[4:8], 'little')
                y = int.from_bytes(param_data[8:12], 'little')
                line = f"{line}({CHAPTER_DICT[chapter]}, {x}, {y})"

            # FightScript
            if cmd_name == 'FightScript':
                pid_a = int.from_bytes(param_data[0:4], 'little')
                pid_b = int.from_bytes(param_data[4:8], 'little')
                addr = int.from_bytes(param_data[8:12], 'little')
                is_ballista = int.from_bytes(param_data[12:16], 'little')
                line = f"{line}({PID_DICT[pid_a]}, {PID_DICT[pid_b]}, {names[addr]}, {BOOL_NAMES[is_ballista]})"

            # Weather
            if cmd_name == 'Weather':
                weather = int.from_bytes(param_data[0:4], 'little')
                line = f"{line}({WEATHER_NAMES[weather]})"

            # WmPutFace
            if cmd_name == 'WmPutFace':
                face_slot = int.from_bytes(param_data[0:4], 'little')
                x = int.from_bytes(param_data[4:6], 'little', signed = True)
                y = int.from_bytes(param_data[6:8], 'little', signed = True)
                fid = int.from_bytes(param_data[8:12], 'little')
                line = f"{line}({face_slot}, FID_{fid:02X}, {x}, {y})"

            # WmPutHighlight
            if cmd_name == 'WmPutHighlight':
                id = int.from_bytes(param_data[0:2], 'little', signed = True)
                unk = int.from_bytes(param_data[2:4], 'little', signed = True)
                line = f"{line}({id}, {unk})"

            # WmPutHighlight, WmPutFlag
            if cmd_name in ('WmPutDot', 'WmPutFlag'):
                id = int.from_bytes(param_data[0:4], 'little')
                x = int.from_bytes(param_data[4:6], 'little', signed = True)
                y = int.from_bytes(param_data[6:8], 'little', signed = True)
                palid = int.from_bytes(param_data[8:12], 'little')
                line = f"{line}({id}, {palid}, {x}, {y})"

            if cmd_name == 'WmPutMapText':
                id = int.from_bytes(param_data[0:4], 'little')
                x_a = int.from_bytes(param_data[4:6], 'little', signed = True)
                y_a = int.from_bytes(param_data[6:8], 'little', signed = True)
                unk = int.from_bytes(param_data[8:12], 'little')
                x_b = int.from_bytes(param_data[12:14], 'little', signed = True)
                y_b = int.from_bytes(param_data[14:16], 'little', signed = True)
                line = f"{line}({id}, {unk}, {x_a}, {y_a}, {x_b}, {y_b})"

            print(line)

            was_goto = cmd_name.startswith('Goto') or cmd_name == 'Jump'

if __name__ == '__main__':
    main(sys.argv)
