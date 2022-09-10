import sys
import symbols

def read_int(f, count, signed = False):
    return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

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

            f.seek(offset)

            on_init       = read_int(f, 4) # +00
            on_end        = read_int(f, 4) # +04
            on_init_b     = read_int(f, 4) # +08
            on_switch_in  = read_int(f, 4) # +0C
            on_switch_out = read_int(f, 4) # +10
            on_a_press    = read_int(f, 4) # +14
            on_b_press    = read_int(f, 4) # +18
            on_r_press    = read_int(f, 4) # +1C

            print(f"struct MapSelectInfo CONST_DATA {get_ptr_expr(syms, 0x08000000 + offset)} =")
            print("{")

            offset = offset + 0x20

            if on_init != 0:
                print(f"    .on_init = {get_ptr_expr(syms, on_init)},")

            if on_end != 0:
                print(f"    .on_end = {get_ptr_expr(syms, on_end)},")

            if on_init_b != 0:
                print(f"    .unk_14 = {get_ptr_expr(syms, on_init_b)},")

            if on_switch_in != 0:
                print(f"    .on_switch_in = {get_ptr_expr(syms, on_switch_in)},")

            if on_switch_out != 0:
                print(f"    .on_switch_out = {get_ptr_expr(syms, on_switch_out)},")

            if on_a_press != 0:
                print(f"    .on_a_press = {get_ptr_expr(syms, on_a_press)},")

            if on_b_press != 0:
                print(f"    .on_b_press = {get_ptr_expr(syms, on_b_press)},")

            if on_r_press != 0:
                print(f"    .on_r_press = {get_ptr_expr(syms, on_r_press)},")

            print("};")
            print("")

    for offset in sorted(offsets):
        print(f"// {0x08000000 + offset:08X}")

if __name__ == '__main__':
    main(sys.argv)
