import sys
import symbols

def read_int(f, count, signed = False):
    return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

def get_ptr_expr(syms, addr):
    return syms[addr] if addr in syms else f'(void const *) 0x{addr:08X}'

ENUM_WINDOW_KIND = {
    0x00: "UI_WINDOW_REGULAR",
    0x01: "UI_WINDOW_FILL",
    0x02: "UI_WINDOW_SABLE"}

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

            f.seek(offset)

            rect_x      = read_int(f, 1) # +00
            rect_y      = read_int(f, 1) # +01
            rect_w      = read_int(f, 1) # +02
            rect_h      = read_int(f, 1) # +03
            window_kind = read_int(f, 1) # +04
            read_int(f, 3) # padding     # +05
            entries     = read_int(f, 4) # +08
            on_init     = read_int(f, 4) # +0C
            on_end      = read_int(f, 4) # +10
            unk_14      = read_int(f, 4) # +14
            on_b_press  = read_int(f, 4) # +18
            on_r_press  = read_int(f, 4) # +1C
            on_help_box = read_int(f, 4) # +20

            print(f"struct MenuInfo CONST_DATA {get_ptr_expr(syms, 0x08000000 + offset)} =")
            print("{")

            offset = offset + 0x24

            if (rect_x, rect_y, rect_w, rect_h) != (0, 0, 0, 0):
                print(f"    .rect = {{ {rect_x}, {rect_y}, {rect_w}, {rect_h} }},")

            if window_kind != 0:
                print(f"    .window_kind = {ENUM_WINDOW_KIND[window_kind] if window_kind in ENUM_WINDOW_KIND else f'{window_kind}'},")

            print(f"    .entries = {get_ptr_expr(syms, entries)},")

            if on_init != 0:
                print(f"    .on_init = {get_ptr_expr(syms, on_init)},")

            if on_end != 0:
                print(f"    .on_end = {get_ptr_expr(syms, on_end)},")

            if unk_14 != 0:
                print(f"    .unk_14 = {get_ptr_expr(syms, unk_14)},")

            if on_b_press != 0:
                print(f"    .on_b_press = {get_ptr_expr(syms, on_b_press)},")

            if on_r_press != 0:
                print(f"    .on_r_press = {get_ptr_expr(syms, on_r_press)},")

            if on_help_box != 0:
                print(f"    .on_help_box = {get_ptr_expr(syms, on_help_box)},")

            print("};")
            print("")

    for offset in sorted(offsets):
        print(f"// {0x08000000 + offset:08X}")

if __name__ == '__main__':
    main(sys.argv)
