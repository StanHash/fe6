
import sys

def read_int(f, count, signed = False):
	return int.from_bytes(f.read(count), byteorder = 'little', signed = signed)

def main(args):
	try:
		romName = args[0]
		offset = int(args[1], base = 0) & 0x1FFFFFF

	except IndexError:
		sys.exit("usage: {} <rom> <offset>".format(sys.argv[0]))

	with open(romName, 'rb') as f:
		array = bytearray(b'')

		f.seek(offset)

		while True:
			byte = f.read(1)[0]

			if byte == 0:
				break

			array.append(byte)

		print(array.decode("sjis"))

if __name__ == '__main__':
	main(sys.argv[1:])
