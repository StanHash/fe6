
import sys

def main(args):
	data = bytes(int(s, base = 0) for s in args)
	print(data.decode("sjis"))

if __name__ == '__main__':
	main(sys.argv[1:])
