#!/bin/bash

here=$(dirname "$(readlink -f "$0")")/..
temp=$(mktemp -d)

agbcc_repo="https://github.com/pret/agbcc.git"

git clone $agbcc_repo $temp

cd $temp
./build.sh
./install.sh $here

rm -fr $temp
