import sys, re

def main(args):
    try:
        splitfile_path = args[1]
        start_off = int(args[2], base = 0) & 0x01FFFFFF
        end_off = int(args[3], base = 0) & 0x01FFFFFF

    except IndexError:
        sys.exit(f"Usage: {args[0]} SPLITFILE START END")

    offmap = {}

    with open(splitfile_path, 'r') as f:
        for line in f.readlines():
            line = line.strip()

            if len(line) == 0 or line[0] == '#':
                continue

            m = re.match(r'(?P<addr>[0-9A-Fa-f]{8})\s+(?P<name>[A-Za-z_][A-Za-z0-9_]*)', line)

            if m == None:
                sys.exit(f"parse error at `{line}`")

            addr = m.group('addr')
            name = m.group('name')

            off = int(addr, base = 16) & 0x01FFFFFF

            offmap[off] = name

    off_order = [k for k in offmap.keys()]
    off_order.sort()

    last_off = start_off

    print(f"    .data")

    for off in off_order:
        if last_off != off:
            if off == off_order[0]:
                print()

            print(f'    .incbin "fe6-base.gba", 0x{last_off:06X}, (0x{off:06X} - 0x{last_off:06X}) @ length: {off - last_off:04X}')
            last_off = off

        name = offmap[off]

        print()
        print(f"    .global {name}")
        print(f"{name}: @ {off + 0x08000000:08X}")

    if last_off != end_off:
        print(f'    .incbin "fe6-base.gba", 0x{last_off:06X}, (0x{end_off:06X} - 0x{last_off:06X}) @ length: {end_off - last_off:04X}')

if __name__ == '__main__':
    main(sys.argv)
