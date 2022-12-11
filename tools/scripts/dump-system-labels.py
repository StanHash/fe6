import sys

def read_int(f, count, signed = False):
    return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

def read_sjis_string(f) -> str:
    array = bytearray(b'')

    while True:
        byte = f.read(1)[0]

        if byte == 0:
            break

        array.append(byte)

    return array.decode("cp932")

def main(args):
    try:
        romName = args[0]
        beg_offset = int(args[1], base = 0) & 0x1FFFFFF
        end_offset = int(args[2], base = 0) & 0x1FFFFFF

    except IndexError:
        sys.exit("usage: {} <rom> <start offset> <end offset>".format(sys.argv[0]))

    names = []

    with open(romName, 'rb') as f:
        for offset in range(beg_offset, end_offset, 8):
            f.seek(offset)
            addr_jp = read_int(f, 4)
            addr_en = read_int(f, 4)

            f.seek(addr_jp & 0x1FFFFFF)
            str_jp = read_sjis_string(f)

            f.seek(addr_en & 0x1FFFFFF)
            str_en = read_sjis_string(f)

            name = f"SystemLabel_{0x08000000 + offset:08X}"
            names.append(name)

            print(f"char const * CONST_DATA {name}[] =")
            print("{")
            print(f"    [LANG_JAPANESE] = JTEXT(\"{str_jp}\"),")
            print(f"    [LANG_ENGLISH] = TEXT(\"{str_en}\", \"{str_en}\"),")
            print("};")
            print()

    for name in names:
        print(f"extern char const * CONST_DATA {name}[];")

if __name__ == '__main__':
    main(sys.argv[1:])
