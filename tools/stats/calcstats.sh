#!/bin/bash

# Usage: ./calcstats.sh ELF MAP

if [[ ! $# -eq 2 ]]
then
    echo "Usage: $0 ELF MAP"
    exit 1
fi

temp=$(mktemp)

arm-none-eabi-nm $1 > $temp
python $(dirname "$(readlink -f "$0")")/calcstats.py $2 $temp

rm -f $temp
