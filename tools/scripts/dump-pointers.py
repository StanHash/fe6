
import sys
import symbols

def read_int(f, count, signed = False):
    return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

def main(args):
    try:
        elf_name = args[0]
        rom_name = args[1]
        offset = 0x1FFFFFF & int(args[2], base = 0)
        ptr_count = int(args[3], base = 0)

    except IndexError:
        sys.exit(f"Usage: {sys.argv[0]} ELF ROM OFFSET COUNT")

    with open(elf_name, 'rb') as f:
        syms = { addr: name for addr, name in symbols.from_elf(f) }

    addr = offset + 0x08000000
    name = syms[addr] if addr in syms else f'gUnk_{offset + 0x08000000:08X}'

    print(f"void * CONST_DATA {name}[] =")
    print("{")

    with open(rom_name, 'rb') as f:
        f.seek(offset)

        for _ in range(ptr_count):
            ptr = read_int(f, 4)
            sym = syms[ptr] if ptr in syms else f"0x{ptr:08X}"

            print(f"    {sym},")

    print("};")

if __name__ == '__main__':
    main(sys.argv[1:])
