import sys
from fe6db import IID_DICT

START_ADDR = 0x0866A81C
END_ADDR = 0x0866AAF8

def main(args):
    try:
        rom_path = args[1]

    except IndexError:
        sys.exit(f"Usage: {args[0]} ROM")

    with open(rom_path, 'rb') as f:
        rom_data = f.read()

    off = START_ADDR - 0x08000000

    while off < END_ADDR - 0x08000000:
        print()
        print(f"// ShopItems @ {off + 0x08000000:08X}")
        print(f"u16 CONST_DATA ShopItems_Unk_{off + 0x08000000:08X}[] =")
        print("{")

        while True:
            iid = int.from_bytes(rom_data[off:off + 2], 'little')
            off = off + 2

            if iid == 0:
                print('    0, // end')
                break

            iid_name = IID_DICT[iid]
            print(f"    {iid_name},")

        print("};")

if __name__ == '__main__':
    main(sys.argv)
