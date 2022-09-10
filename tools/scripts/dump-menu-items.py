import sys
import symbols

def read_int(f, count, signed = False):
    return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

def read_cp932_str(f):
    array = bytearray(b'')

    while True:
        byte = f.read(1)[0]

        if byte == 0:
            break

        array.append(byte)

    return array.decode(encoding = 'cp932')

TEXT_COLOR_ENUM = {
    0x00: "TEXT_COLOR_SYSTEM_WHITE",
    0x01: "TEXT_COLOR_SYSTEM_GRAY",
    0x02: "TEXT_COLOR_SYSTEM_BLUE",
    0x03: "TEXT_COLOR_SYSTEM_GOLD",
    0x04: "TEXT_COLOR_SYSTEM_GREEN"}

def get_ptr_expr(syms, addr):
    return syms[addr] if addr in syms else f'(void const *) 0x{addr:08X}'

def main(args):
    try:
        elf_name = args[1]
        rom_name = args[2]
        offset_beg = 0x1FFFFFF & int(args[3], base = 0)
        offset_end = 0x1FFFFFF & int(args[4], base = 0)

    except IndexError:
        sys.exit(f"Usage: {args[0]} ELF ROM START END")

    with open(elf_name, 'rb') as f:
        syms = { addr: name for addr, name in symbols.from_elf(f) }

    offsets = set()

    with open(rom_name, 'rb') as f:
        offset = offset_beg

        while offset < offset_end:
            offsets.add(offset)

            print(f"struct MenuEntInfo CONST_DATA MenuEntInfo_{0x08000000 + offset:08X}[] =")
            print("{")

            while True:
                f.seek(offset)

                label_addr    = read_int(f, 4) # +00
                msg_label     = read_int(f, 2) # +04
                msg_help      = read_int(f, 2) # +06
                text_color    = read_int(f, 1) # +08
                read_int(f, 3) # padding       # +09
                available     = read_int(f, 4) # +0C
                on_draw       = read_int(f, 4) # +10
                on_select     = read_int(f, 4) # +14
                on_idle       = read_int(f, 4) # +18
                on_switch_in  = read_int(f, 4) # +1C
                on_switch_out = read_int(f, 4) # +20

                offset = offset + 0x24

                if available == 0:
                    print("    { 0 }, // end")
                    break

                print("    {")

                if label_addr != 0:
                    label_offset = 0x1FFFFFF & label_addr
                    offsets.add(label_offset)

                    f.seek(label_offset)
                    print(f'        .label = JTEXT("{read_cp932_str(f)}"),')

                if msg_label != 0:
                    print(f'        .msg_label = MSG_{msg_label:03X},')

                if msg_help != 0:
                    print(f'        .msg_help = MSG_{msg_help:03X},')

                if text_color != 0:
                    print(f'        .msg_help = {TEXT_COLOR_ENUM[text_color] if text_color in TEXT_COLOR_ENUM else f"{text_color}"},')

                if available != 0:
                    print(f'        .available = {get_ptr_expr(syms, available)},')

                if on_draw != 0:
                    print(f'        .on_draw = {get_ptr_expr(syms, on_draw)},')

                if on_select != 0:
                    print(f'        .on_select = {get_ptr_expr(syms, on_select)},')

                if on_idle != 0:
                    print(f'        .on_idle = {get_ptr_expr(syms, on_idle)},')

                if on_switch_in != 0:
                    print(f'        .on_switch_in = {get_ptr_expr(syms, on_switch_in)},')

                if on_switch_out != 0:
                    print(f'        .on_switch_out = {get_ptr_expr(syms, on_switch_out)},')

                print("    },")
                print("")

            print("};")
            print("")

    for offset in sorted(offsets):
        print(f"// {0x08000000 + offset:08X}")

if __name__ == '__main__':
    main(sys.argv)
