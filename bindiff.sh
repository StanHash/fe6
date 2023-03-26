#!/bin/bash

# from https://superuser.com/questions/125376/how-do-i-compare-binary-files-in-linux because I'm newb
cmp -l fe6-base.gba fe6.gba | gawk '{printf "%08X %02X %02X\n", $1, strtonum(0$2), strtonum(0$3)}' | more
