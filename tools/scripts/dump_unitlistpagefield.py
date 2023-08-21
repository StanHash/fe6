import sys

OFFSET = 0x678840
LENGTH = 0x5A0

def decode_sjis_string(rom, offset):
    offset = offset & 0x01FFFFFF
    end_offs = offset

    while True:
        if rom[end_offs] == 0:
            break

        end_offs = end_offs + 1

    array = rom[offset:end_offs + 1]
    return array.decode("sjis")

def main(args):
    try:
        rom_path = args[1]

    except:
        return f"Usage: {args[0]} ROM"

    with open(rom_path, 'rb') as f:
        rom = f.read()

    print("{")

    for i in range(10):
        page_offset = OFFSET + 9 * 0x10 * i
        page_name = f"UNITLIST_PAGE_{i}"

        print(f"    [{page_name}] =")
        print("    {")

        for j in range(9):
            offset = page_offset + 0x10 * j
            ent = rom[offset:offset+0x10]

            print("        {")

            sort_key = ent[0]
            label_string_addr = int.from_bytes(ent[4:8], byteorder='little')
            x_column = ent[8]
            msg_help = int.from_bytes(ent[12:16], byteorder='little')

            print(f"            .sort_key = UNITLIST_SORTKEY_{sort_key},")

            if label_string_addr != 0:
                label_string = decode_sjis_string(rom, label_string_addr)
                print(f"            .label_string = \"{label_string}\",")

            print(f"            .x_column = 0x{x_column:02X},")
            print(f"            .msg_help = MSG_{msg_help:03X},")
            print("        },")

        print("    },")

    print("};")

if __name__ == '__main__':
    sys.exit(main(sys.argv))
