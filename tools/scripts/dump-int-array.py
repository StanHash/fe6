
import sys, os

def read_int(f, count, signed = False):
    return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

def main(args):
    try:
        rom = args[0]
        offset = int(args[1], base = 0) & 0x1FFFFFF
        intSize = int(args[2], base = 0)
        count = int(args[3], base = 0)

    except IndexError:
        sys.exit("Usage: {} <rom> <offset> <int size> <count>".format(sys.argv[0]))

    with open(rom, 'rb') as f:
        print("u{} CONST_DATA gUnk_{:08X}[] =".format(intSize*8, offset + 0x8000000))
        print("{")

        f.seek(offset)

        if count == 0:
            while True:
                value = read_int(f, intSize)

                print("\t0x{:X},".format(value))

                if value == 0:
                    break

        else:
            for _ in range(count):
                print("\t0x{:X},".format(read_int(f, intSize)))

        print("};")

if __name__ == '__main__':
    main(sys.argv[1:])
