import sys
import symbols

def read_int(f, len: int, signed: bool = False) -> int:
    return int.from_bytes(f.read(len), byteorder = 'little', signed = signed)

def main(args):
    try:
        elf_filename = args[1]
        rom_filename = args[2]
        beg_offset = int(args[3], base = 0) & 0x1FFFFFF
        end_offset = int(args[4], base = 0) & 0x1FFFFFF

    except IndexError:
        sys.exit(f"usage: {args[0]} ELF ROM BEGIN END")

    with open(elf_filename, 'rb') as f:
        syms = { addr: name for addr, name in symbols.from_elf(f) }

    offsets = [off for off in range(beg_offset, end_offset, 0x1C)]
    addresses = [0x08000000 + off for off in offsets]

    with open(rom_filename, 'rb') as f:
        print(f"// declarations")

        for addr in addresses:
            if addr not in syms:
                syms[addr] = f"HelpInfo_{addr:08X}"
            print(f"extern struct HelpBoxInfo CONST_DATA {syms[addr]};")

        print()

        print(f"// definitions")

        for offset, addr in zip(offsets, addresses):
            f.seek(offset)

            adjacent_up = read_int(f, 4)
            adjacent_down = read_int(f, 4)
            adjacent_left = read_int(f, 4)
            adjacent_right = read_int(f, 4)
            x = read_int(f, 1)
            y = read_int(f, 1)
            msg = read_int(f, 2)
            redirect = read_int(f, 4)
            populate = read_int(f, 4)

            print(f"struct HelpBoxInfo CONST_DATA {syms[addr]} =")
            print("{")

            if adjacent_up != 0:
                print(f"    .adjacent_up = &{syms[adjacent_up]},")
            if adjacent_down != 0:
                print(f"    .adjacent_down = &{syms[adjacent_down]},")
            if adjacent_left != 0:
                print(f"    .adjacent_left = &{syms[adjacent_left]},")
            if adjacent_right != 0:
                print(f"    .adjacent_right = &{syms[adjacent_right]},")

            print(f"    .x = {x},")
            print(f"    .y = {y},")
            print(f"    .msg = MSG_{msg:03X},")

            if redirect != 0:
                print(f"    .redirect = {syms[redirect]},")
            if populate != 0:
                print(f"    .populate = {syms[populate]},")

            print("};")
            print()

if __name__ == '__main__':
    main(sys.argv)
