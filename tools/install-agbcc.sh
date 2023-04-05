#!/bin/bash

here=$(dirname "$(readlink -f "$0")")/..
temp=$(mktemp -d)

agbcc_repo="https://github.com/pret/agbcc.git"
agbcc_branch="master"

git clone $agbcc_repo $temp

cd $temp
git checkout origin/$agbcc_branch
./build.sh
./install.sh $here

rm -fr $temp
