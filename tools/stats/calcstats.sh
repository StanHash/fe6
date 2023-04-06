#!/bin/bash

# Usage: ./calcstats.sh ELF MAP

temp=$(mktemp)

arm-none-eabi-nm $1 > $temp
python $(dirname "$(readlink -f "$0")")/calcstats.py $2 $temp

rm -f $temp
