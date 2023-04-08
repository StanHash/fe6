# this is like calcrom.pl except in a language I know
# (I made some changes)

import re, bisect
from typing import List, Tuple

RE_SYM = re.compile(r'^(?P<addr>0[238][0-9a-f]+).+\s+(?P<name>[^_][^ .]+)$')
RE_UNK = re.compile(r'[Uu]nk(nown)?_|^func_fe6_')
RE_PAR = re.compile(r'_(?P<addr>[0-9a-fA-F]{7,8})$')

RE_MAP_INPUT_SECTION = re.compile(r'^ +(?P<name>[._\w]+)\s+0x0*(?P<addr>[0-9a-f]+)\s+0x0*(?P<size>[0-9a-f]+)\s+(?P<file>[^ ]+\.o)?$')
RE_MAP_INPUT_SECTION_LONG_LINE1 = re.compile(r'^ +(?P<name>[._\w]+)$')
RE_MAP_INPUT_SECTION_LONG_LINE2 = re.compile(r'^\s+0x0*(?P<addr>[0-9a-f]+)\s+0x0*(?P<size>[0-9a-f]+)\s+(?P<file>[^ ]+\.o)?$')

def main(args: List[str]) -> str | int:
    try:
        mapfile_path = args[1]
        symfile_path = args[2]

    except:
        return f'Usage: {args[0]} MAP SYMS'

    names = {}

    with open(symfile_path, 'r') as f:
        for line in f.readlines():
            line = line[0:-1] # remove newline

            if len(line) == 0:
                continue

            m = RE_SYM.match(line)

            if m == None:
                continue

            addr = int(m.group('addr'), base = 16)
            name = m.group('name')

            names[addr] = name

    addrs = [k for k in names.keys()]
    addrs.sort()

    def count_syms_in(addr: int, size: int) -> Tuple[int, int, int]:
        min_idx = bisect.bisect_left(addrs, addr)
        max_idx = bisect.bisect_left(addrs, addr + size)

        count = 0
        count_par = 0
        count_unk = 0

        for name_addr in addrs[min_idx:max_idx]:
            name = names[name_addr]

            count = count + 1

            if RE_UNK.search(name) != None:
                count_unk = count_unk + 1
                continue

            m = RE_PAR.search(name)

            if m != None and int(m.group('addr'), base = 16) == name_addr:
                count_par = count_par + 1

        return count, count_par, count_unk

    text_src = 0
    text_asm = 0

    data_src = 0
    data_raw = 0

    syms_src = 0
    syms_asm = 0

    syms_doc = 0
    syms_unk = 0
    syms_par = 0

    longsec = None
    name = ""
    addr = 0
    size = 0
    file = ""

    with open(mapfile_path, 'r') as f:
        for line in f.readlines():
            line = line[0:-1] # remove newline

            if len(line) == 0:
                continue

            # sometimes section names are on a different line from the rest of the info
            # for long section names (eg. ".ARM.attributes", "ewram_overlay_banim")
            # so we need to account for that in our parsing (it sucks)

            if longsec != None:
                name = longsec
                longsec = None

                m = RE_MAP_INPUT_SECTION_LONG_LINE2.match(line)

                if m == None:
                    continue

                addr = int(m.group('addr'), base = 16)
                size = int(m.group('size'), base = 16)
                file = m.group('file')

            else:
                m = RE_MAP_INPUT_SECTION.match(line)

                if m == None:
                    m = RE_MAP_INPUT_SECTION_LONG_LINE1.match(line)

                    if m != None:
                        longsec = m.group('name')

                    # we need the second line to handle this
                    continue

                name = m.group('name')
                addr = int(m.group('addr'), base = 16)
                size = int(m.group('size'), base = 16)
                file = m.group('file')

            dirname = file.split('/')[0]

            syms, pars, unks = count_syms_in(addr, size)

            syms_doc += syms - unks - pars
            syms_par += pars
            syms_unk += unks

            if name.startswith('.text'):
                if dirname == 'src':
                    text_src += size
                    syms_src += syms

                if dirname == 'asm':
                    text_asm += size
                    syms_asm += syms

            if name.startswith('.data') or name.startswith('.rodata'):
                if dirname == 'src':
                    data_src += size

                if dirname in ('asm', 'data'):
                    data_raw += size

    print(f'code src: {text_src}')
    print(f'code max: {text_src + text_asm}')
    print(f'data src: {data_src}')
    print(f'data max: {data_src + data_raw}')
    print(f'code sym src: {syms_src}')
    print(f'code sym max: {syms_src + syms_asm}')
    print(f'syms doc: {syms_doc}')
    print(f'syms par: {syms_par}')
    print(f'syms max: {syms_doc + syms_par + syms_unk}')
    print(f'code %: {100 * text_src / (text_src + text_asm)}% ({text_src:08X}/{text_src + text_asm:08X})')
    print(f'data %: {100 * data_src / (data_src + data_raw)}% ({data_src:08X}/{data_src + data_raw:08X})')
    print(f'code sym %: {100 * syms_src / (syms_src + syms_asm)}%')

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
