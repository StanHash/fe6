
import sys
import symbols

def read_int(f, count, signed = False):
    return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

class AiScr:

    def __init__(self, input):
        self.code  = read_int(input, 1)
        self.sarg0 = read_int(input, 1)
        self.sarg1 = read_int(input, 1)
        self.sarg2 = read_int(input, 1)

        self.larg0 = read_int(input, 4)
        self.larg1 = read_int(input, 4)
        self.larg2 = read_int(input, 4)

    def __str__(self):
        return f"{{ 0x{self.code:X}, 0x{self.sarg0:X}, 0x{self.sarg1:X}, 0x{self.sarg2:X}, 0x{self.larg0:X}, 0x{self.larg1:X}, 0x{self.larg2:X} }}"

def main(args):
    try:
        elf_name = args[0]
        rom_name = args[1]
        offset = 0x1FFFFFF & int(args[2], base = 0)
        count = int(args[3], base = 0)

    except IndexError:
        sys.exit(f"Usage: {sys.argv[0]} ELF ROM OFFSET COUNT")

    #with open(elf_name, 'rb') as f:
    #    syms = { addr: name for addr, name in symbols.from_elf(f) }

    print(f"struct AiScr CONST_DATA AiScr_Unk_{offset + 0x08000000:08X}[] =")
    print("{")

    with open(rom_name, 'rb') as f:
        f.seek(offset)

        for _ in range(count):
            ai_scr = AiScr(f)

            print(f"    {ai_scr},")

    print("};")

if __name__ == '__main__':
    main(sys.argv[1:])
