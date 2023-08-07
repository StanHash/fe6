import sys
import symbols

TERRAIN_NAMES = {
    0x00: 'TERRAIN_TILE_00',
    0x01: 'TERRAIN_PLAINS',
    0x02: 'TERRAIN_ROAD',
    0x03: 'TERRAIN_VILLAGE',
    0x04: 'TERRAIN_VILLAGE_CLOSED',
    0x05: 'TERRAIN_HOUSE',
    0x06: 'TERRAIN_ARMORY',
    0x07: 'TERRAIN_VENDOR',
    0x08: 'TERRAIN_ARENA_08',
    0x09: 'TERRAIN_C_ROOM_09',
    0x0A: 'TERRAIN_FORT',
    0x0B: 'TERRAIN_GATE_0B',
    0x0C: 'TERRAIN_FOREST',
    0x0D: 'TERRAIN_THICKET',
    0x0E: 'TERRAIN_SAND',
    0x0F: 'TERRAIN_DESERT',
    0x10: 'TERRAIN_RIVER',
    0x11: 'TERRAIN_MOUNTAIN',
    0x12: 'TERRAIN_PEAK',
    0x13: 'TERRAIN_BRIDGE',
    0x14: 'TERRAIN_DRAWBRIDGE',
    0x15: 'TERRAIN_SEA',
    0x16: 'TERRAIN_LAKE',
    0x17: 'TERRAIN_FLOOR_17',
    0x18: 'TERRAIN_FLOOR_18',
    0x19: 'TERRAIN_FENCE_19',
    0x1A: 'TERRAIN_WALL',
    0x1B: 'TERRAIN_WALL_BREAKABLE',
    0x1C: 'TERRAIN_RUBBLE',
    0x1D: 'TERRAIN_PILLAR',
    0x1E: 'TERRAIN_DOOR',
    0x1F: 'TERRAIN_THRONE',
    0x20: 'TERRAIN_CHEST_OPENED',
    0x21: 'TERRAIN_CHEST',
    0x22: 'TERRAIN_ROOF',
    0x23: 'TERRAIN_GATE_23',
    0x24: 'TERRAIN_CHURCH',
    0x25: 'TERRAIN_RUINS',
    0x26: 'TERRAIN_CLIFF',
    0x27: 'TERRAIN_BALLISTA',
    0x28: 'TERRAIN_LONGBALLISTA',
    0x29: 'TERRAIN_KILLERBALLISTA',
    0x2A: 'TERRAIN_SHIP_FLAT',
    0x2B: 'TERRAIN_SHIP_WRECK',
    0x2C: 'TERRAIN_TILE_2C',
    0x2D: 'TERRAIN_STAIRS',
    0x2E: 'TERRAIN_TILE_2E',
    0x2F: 'TERRAIN_GLACIER',
    0x30: 'TERRAIN_ARENA_30',
    0x31: 'TERRAIN_VALLEY',
    0x32: 'TERRAIN_FENCE_32'}

TERRAIN_COUNT = 0x33
ALL_TERRAINS = [x for x in range(TERRAIN_COUNT)]

def main(args):
    try:
        rom_path = args[1]
        start_addr = (int(args[2], base = 0) & 0x01FFFFFF) + 0x08000000
        end_addr = (int(args[3], base = 0) & 0x01FFFFFF) + 0x08000000

    except IndexError:
        sys.exit(f"Usage: {args[0]} ROM ADDR END")

    elf_path = rom_path.replace(".gba", ".elf")

    with open(rom_path, 'rb') as f:
        rom_data = f.read()

    with open(elf_path, 'rb') as f:
        names = { addr: name for addr, name in symbols.from_elf(f) }

    offset = start_addr - 0x08000000

    while offset < end_addr - 0x08000000:
        addr = offset + 0x08000000
        data = rom_data[offset:offset + TERRAIN_COUNT]
        name = names[addr] if addr in names else f'Unk_TerrainTable_{addr:08X}'

        print()
        print(f"// MoveTable @ {addr:08X}")
        print(f"i8 CONST_DATA {name}[] =")
        print("{")

        for i in ALL_TERRAINS:
            key_name = TERRAIN_NAMES[i]
            value = int.from_bytes(data[i:i + 1], 'little', signed=True)

            print(f"    [{key_name}] = {value},")

        print("};")

        offset = offset + TERRAIN_COUNT

if __name__ == '__main__':
    main(sys.argv)
