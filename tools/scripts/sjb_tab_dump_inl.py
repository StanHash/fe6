import sys

def read_int(f, count, signed = False):
    return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

def read_sjis_string(f):
    array = bytearray(b'')

    while True:
        byte = f.read(1)[0]

        if byte == 0:
            break

        array.append(byte)

    return array

def main(args):
    try:
        romName = args[0]
        offset = int(args[1], base = 0) & 0x1FFFFFF
        tabsize = int(args[2], base = 0)
        outputName = args[3]

    except IndexError:
        sys.exit("usage: {} <rom> <offset> <entry count> <output file>".format(sys.argv[0]))

    with open(outputName, 'wb') as out:
        with open(romName, 'rb') as f:
            names = []
            lo_off = 0xFFFFFFFF
            hi_off = 0

            out.write(b'\n')

            for i in range(tabsize):
                f.seek(offset + 4*i)
                stroff = read_int(f, 4) & 0x01FFFFFF
                lo_off = min(stroff, lo_off)
                hi_off = max(stroff, hi_off)

                f.seek(stroff & 0x1FFFFFF)

                names.append(read_sjis_string(f))

            out.write(f'// strings: {lo_off + 0x08000000:08X}-{hi_off + 0x08000000:08X}'.encode("sjis"))

            out.write(b'\n')
            out.write('char const * CONST_DATA gUnk_{:08X}[] =\n'.format(offset + 0x08000000).encode("sjis"))
            out.write(b'{\n')

            for name in names:
                out.write(b'    \"')
                out.write(name)
                out.write(b'\",\n')

            out.write(b'};\n')

if __name__ == '__main__':
    main(sys.argv[1:])
