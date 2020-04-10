
import sys, os

def read_int(f, count, signed = False):
	return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

def main(args):
	try:
		rom = args[0]
		offset = int(args[1], base=0) & 0x1FFFFFF
		count = int(args[2], base=0)

	except IndexError:
		sys.exit("Usage: {} <rom> <array offset> <array entry count>".format(sys.argv[0]))

	# background entries
	entries = []

	with open(rom, 'rb') as f:
		for i in range(count):
			f.seek(offset + i*12)

			imgAddr = read_int(f, 4)
			tsaAddr = read_int(f, 4)
			palAddr = read_int(f, 4)

			entries.append((imgAddr, tsaAddr, palAddr))

	# address to name dict
	names = {}

	for imgAddr, tsaAddr, palAddr in entries:
		names[imgAddr] = 'Img_Background_{:08X}'.format(imgAddr)
		names[tsaAddr] = 'Tsa_Background_{:08X}'.format(tsaAddr)
		names[palAddr] = 'Pal_Background_{:08X}'.format(palAddr)

	# sorted address list
	addresses = sorted(names.keys())

	print('@?ASM')
	print('')

	for i in range(len(addresses)):
		address = addresses[i]
		addressNext = addresses[i+1] if i+1 < len(addresses) else 0xFFFFFFFF
		name = names[address]

		print('\t.global {}'.format(name))
		print('{}: @ {:08X}'.format(name, address))
		print('\t.incbin "fe6-base.gba", 0x{0:X}, (0x{1:X} - 0x{0:X})'.format(
			address & 0x1FFFFFF, addressNext & 0x1FFFFFF))
		print('')

	print('// C')
	print('')

	for address in addresses:
		typename = 'u16' if names[address].startswith('Pal') else 'u8'

		print('extern {} const {}[];'.format(typename, names[address]))

	print('')

	print('struct BackgroundEnt CONST_DATA gBackgroundTable[] =')
	print('{')

	for i, (imgAddr, tsaAddr, palAddr) in enumerate(entries):
		print('    [BACKGROUND_{}] = {{ {}, {}, {} }},'.format(i, names[imgAddr], names[tsaAddr], names[palAddr]))

	print('};')
	print('')

if __name__ == '__main__':
	main(sys.argv[1:])
