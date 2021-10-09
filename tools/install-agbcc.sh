#!/bin/bash

here=$(dirname "$(readlink -f "$0")")/..
tdir=$(mktemp -d)

git clone https://github.com/pret/agbcc.git $tdir

cd $tdir
./build.sh
./install.sh $here

rm -fr $tdir
