#!/bin/bash

function dump_chapter
{
    echo $1
    mkdir -p data/chapters/$1
    mv data/chapterevents/$1.h data/chapters/$1/eventscript.h
    echo "#pragma once" > data/chapters/$1/eventinfo.h
    python tools/scripts/dump_chapter_event_info.py fe6.gba $2 >> data/chapters/$1/eventinfo.h
}

dump_chapter tutorial 0x086676F0
dump_chapter chapter1 0x086677A0
dump_chapter chapter2 0x08667868
dump_chapter chapter3 0x08667960
dump_chapter chapter4 0x08667ADC
dump_chapter chapter5 0x08667BBC
dump_chapter chapter6 0x08667D5C
dump_chapter chapter7 0x08667FA4
dump_chapter chapter8 0x0866812C
dump_chapter chapter9 0x08668248
dump_chapter chapter10_a 0x08668364
dump_chapter chapter11_a 0x08668588
dump_chapter chapter12 0x08668728
dump_chapter chapter13 0x086688B0
dump_chapter chapter14 0x086689FC
dump_chapter chapter15 0x08668AF4
dump_chapter chapter16 0x08668C94
dump_chapter chapter17_i 0x08668D8C
dump_chapter chapter18_i 0x08668F2C
dump_chapter chapter19_i 0x0866900C
dump_chapter chapter20_i 0x086691DC
dump_chapter chapter21 0x086692F8
dump_chapter chapter22 0x086694BC
dump_chapter chapter23 0x0866959C
dump_chapter chapter24 0x0866967C
dump_chapter final 0x086696CC
dump_chapter chapter10_b 0x086698D8
dump_chapter chapter11_b 0x08669A54
dump_chapter chapter17_s 0x08669B58
dump_chapter chapter18_s 0x08669C80
dump_chapter chapter19_s 0x08669E14
dump_chapter chapter20_s 0x08669F78
dump_chapter chapter8x 0x08669FC8
dump_chapter chapter12x 0x0866A0A8
dump_chapter chapter14x 0x0866A0F8
dump_chapter chapter16x 0x0866A184
dump_chapter chapter20x_i 0x0866A1D4
dump_chapter chapter20x_s 0x0866A260
dump_chapter chapter21x 0x0866A2F8
dump_chapter trial_a 0x0866A384
dump_chapter trial_b 0x0866A5B4
dump_chapter trial_c 0x0866A664
dump_chapter trial_d 0x0866A75C
dump_chapter trial_e 0x0866A800
