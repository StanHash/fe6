
import sys

def main(args):
    try:
        offset = int(args[0], base = 0)

    except IndexError:
        sys.exit(f"Usage: {sys.argv[0]} <offset>")

    index = offset // 2

    y = index // 0x20
    x = index % 0x20

    print(f"TM_OFFSET({x}, {y})")

if __name__ == "__main__":
    main(sys.argv[1:])
