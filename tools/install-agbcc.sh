#!/bin/bash

here=$(dirname "$(readlink -f "$0")")/..
temp=$(mktemp -d)

git clone https://github.com/StanHash/agbcc.git $temp

cd $temp
git checkout origin/fix-dwarf-debug-line
./build.sh
./install.sh $here

rm -fr $temp
