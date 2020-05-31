
import sys, os

def read_int(f, count, signed = False):
	return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

def main(args):
	try:
		rom = args[0]
		
		offsets = []

		for arg in args[1:]:
			offsets.append(int(arg, base=0) & 0x1FFFFFF)

	except IndexError:
		sys.exit("Usage: {} <rom> <offset>...".format(sys.argv[0]))

	with open(rom, 'rb') as f:
		data_names = {}

		for offset in offsets:
			f.seek(offset)

			first = read_int(f, 4)
			second = read_int(f, 4)
			is_pal = (first > 0x8000000) and (first <= 0x8800000) and not((second > 0x8000000) and (second <= 0x8800000))

			f.seek(offset)

			if is_pal:
				name = "TilesetPalAnim_{:08X}".format(0x8000000 + offset)

				print("struct TsPalAnim CONST_DATA {}[] =".format(name))
				print("{")

				num = 0

				while True:
					data_offset = read_int(f, 4) & 0x1FFFFFF
					time = read_int(f, 1)
					color_count = read_int(f, 1)
					color_start = read_int(f, 1)
					_ = read_int(f, 1) # discard padding

					if time == 0:
						print("    {},")
						break

					if data_offset in data_names:
						data_name = data_names[data_offset]

					else:
						data_name = "Pal_TilesetAnim_{:08X}_{}".format(0x8000000 + offset, num)
						data_names[data_offset] = data_name

					print("    {{ {}, {}, 0x{:02X}, 0x{:02X} }},".format(data_name, time, color_count, color_start))

					num = num + 1

				print("};")
				print("")

			else:
				name = "TilesetImgAnim_{:08X}".format(0x8000000 + offset)

				print("struct TsImgAnim CONST_DATA {}[] =".format(name))
				print("{")

				num = 0

				while True:
					time = read_int(f, 2)
					size = read_int(f, 2)
					data_offset = read_int(f, 4) & 0x1FFFFFF

					if time == 0:
						print("    {},")
						break

					if data_offset in data_names:
						data_name = data_names[data_offset]

					else:
						data_name = "Img_TilesetAnim_{:08X}_{}".format(0x8000000 + offset, num)
						data_names[data_offset] = data_name

					print("    {{ {:2}, 0x{:04X}, {} }},".format(time, size, data_name))

					num = num + 1

				print("};")
				print("")

		data_offsets = sorted(data_names.keys())

		for i in range(len(data_offsets)):
			offset = data_offsets[i]
			offset_next = data_offsets[i+1] if i+1 < len(data_offsets) else 0xFFFFFFFF

			name = data_names[offset]

			print('\t.global {}'.format(name))
			print('{}: @ {:08X}'.format(name, offset + 0x8000000))
			print('\t.incbin "fe6-base.gba", 0x{0:X}, (0x{1:X} - 0x{0:X})'.format(
				offset, offset_next))
			print('')

		for offset in data_offsets:
			typename = 'u16' if data_names[offset].startswith('Pal') else 'u8'

			print('extern {} const {}[];'.format(typename, data_names[offset]))

if __name__ == '__main__':
	main(sys.argv[1:])

