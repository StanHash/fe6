
import sys

def read_rom_words(rom_filename):
    words = []

    with open(rom_filename, 'rb') as rom:
        while True:
            word = rom.read(4)

            if word == b'':
                break

            words.append(word)

    return words

def pointer_iter(rom_filename, value):
    target = value.to_bytes(4, 'little')
    words  = read_rom_words(rom_filename)

    return (i * 4 for i, word in enumerate(words) if word == target)

def pointer_offsets(rom_filename, value):
    return tuple(pointer_iter(rom_filename, value))

def main(args):
    rom_addr_base = 0x08000000

    try:
        rom    = args[0] # rom file name
        target = rom_addr_base + (int(args[1], base = 0) & 0x01FFFFFF) # pointer (int)

    except IndexError:
        sys.exit(f"Usage: {sys.argv[0]} ROM ADDR")

    for offset in pointer_offsets(rom, target):
        print(f"{(rom_addr_base + offset):08X}")

if __name__ == '__main__':
    main(sys.argv[1:])
