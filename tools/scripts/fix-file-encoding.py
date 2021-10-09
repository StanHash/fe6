import sys

def val2hex(val):
    if val >= 10:
        return ord('A') + (val - 10)

    return ord('0') + val

def main(args):
    try:
        filenames = args[1:]

    except IndexError:
        sys.exit(f"USAGE: {args[0]} FILENAME...")

    for filename in filenames:
        data = bytearray()

        with open(filename, 'rb') as f:
            while True:
                byte = f.read(1)

                if byte == b'':
                    break

                byte = byte[0]

                if byte >= 0x80:
                    data.append(ord('\\'))
                    data.append(ord('x'))
                    data.append(val2hex((byte & 0xF0) >> 4))
                    data.append(val2hex((byte & 0x0F)))
                    byte = f.read(1)[0]
                    data.append(ord('\\'))
                    data.append(ord('x'))
                    data.append(val2hex((byte & 0xF0) >> 4))
                    data.append(val2hex((byte & 0x0F)))
                else:
                    data.append(byte)

        with open(filename, 'wb') as f:
            f.write(data)

if __name__ == '__main__':
    main(sys.argv)
