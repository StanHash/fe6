#!/bin/bash

if [ "$#" -ne "2" ];
then
    echo "usage: $0 <old name> <new name>"
    exit 1
fi

echo "Rename $1 to $2?"
read

grep -rl "$1" asm/*.s asm/*/*.s src/*.c src/*/*.c include/*.h include/*/*.h data/*.s data/*/*.h ldscr.txt | xargs sed -i "s/\b$1\b/$2/g"
