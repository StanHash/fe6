
import sys

def read_int(f, count, signed = False):
    return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

def main(args):
    try:
        rom_name = args[0]
        offset = 0x1FFFFFF & int(args[1], base = 0)
        count = int(args[2], base = 0)

    except IndexError:
        sys.exit(f"Usage: {sys.argv[0]} ROM OFFSET COUNT")

    #with open(elf_name, 'rb') as f:
    #    syms = { addr: name for addr, name in symbols.from_elf(f) }

    print(f"struct AiCombatScoreCoefficients const gUnk_{offset + 0x08000000:08X}[] =")
    print("{")

    with open(rom_name, 'rb') as f:
        f.seek(offset)

        for i in range(count):
            val0 = read_int(f, 1)
            val1 = read_int(f, 1)
            val2 = read_int(f, 1)
            val3 = read_int(f, 1)
            val4 = read_int(f, 1)
            val5 = read_int(f, 1)
            val6 = read_int(f, 1)
            val7 = read_int(f, 1)

            arry = []

            for _ in range(12):
                arry.append(read_int(f, 1))

            print(f"    [{i}] =")
            print(f"    {{")
            print(f"        .unk_00 = {val0},")
            print(f"        .unk_01 = {val1},")
            print(f"        .unk_02 = {val2},")
            print(f"        .unk_03 = {val3},")
            print(f"        .unk_04 = {val4},")
            print(f"        .unk_05 = {val5},")
            print(f"        .unk_06 = {val6},")
            print(f"        .unk_07 = {val7},")
            print(f"        .unk_08 =")
            print(f"        {{")

            for i, val in enumerate(arry):
                if val != 0:
                    print(f"            [{i}] = {val},")

            print(f"        }}")

            print(f"    }},")
            print(f"")

        print("};")

        print(f"// ends at {f.tell() + 0x08000000:08X}")

if __name__ == '__main__':
    main(sys.argv[1:])
