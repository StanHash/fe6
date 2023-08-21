
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

	return array.decode("sjis")

def main(args):
	try:
		romName = args[0]
		offset = int(args[1], base = 0) & 0x1FFFFFF

	except IndexError:
		sys.exit("usage: {} <rom> <offset>".format(sys.argv[0]))

	with open(romName, 'rb') as f:
		f.seek(offset)
		print(f"\"{read_sjis_string(f)}\"")

if __name__ == '__main__':
	main(sys.argv[1:])
