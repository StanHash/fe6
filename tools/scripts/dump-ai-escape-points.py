
import sys

def read_int(f, count, signed = False):
    return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

FACING_CONSTANTS = [
    "FACING_LEFT",
    "FACING_RIGHT",
    "FACING_DOWN",
    "FACING_UP"]

def main(args):
    try:
        rom_name = args[0]
        offset = 0x1FFFFFF & int(args[1], base = 0)
        count = int(args[2], base = 0)

    except IndexError:
        sys.exit(f"Usage: {sys.argv[0]} ROM OFFSET COUNT")

    with open(rom_name, 'rb') as f:
        f.seek(offset)

        addr_list = []

        for _ in range(count):
            addr_list.append(read_int(f, 4))

        end_offset = f.tell()

        unique_addr_list = sorted(set(addr_list))
        addr_to_chapter = { addr: i for i, addr in enumerate(addr_list) }

        for addr in unique_addr_list:
            print(f"struct AiEscapePt const AiEscapePts_{addr_to_chapter[addr]}[] =")
            print(f"{{")

            f.seek(addr & 0x01FFFFFF)

            while True:
                x = read_int(f, 1, True)
                y = read_int(f, 1, True)
                facing = read_int(f, 1)

                read_int(f, 1) # discard padding

                print(f"    {{ {x}, {y}, {facing} }},")

                if x == -1:
                    break

            print(f"}};")
            print(f"")

        print(f"// ends at {0x08000000 + f.tell():08X}")
        print(f"")

        print(f"struct AiEscapePt CONST_DATA gAiEscapePts_{offset + 0x08000000:08X}[] =")
        print(f"{{")

        for addr in addr_list:
            print(f"    AiEscapePts_{addr_to_chapter[addr]},")

        print(f"}};")

        print(f"// ends at {0x08000000 + end_offset:08X}")

if __name__ == '__main__':
    main(sys.argv[1:])
