#!/bin/bash

here=$(dirname "$(readlink -f "$0")")/..
temp=$(mktemp -d)

if [[ "$OSTYPE" == "darwin"* ]]
then
    agbcc_repo="https://github.com/holmesmr/agbcc.git"
    agbcc_branch="master"
else
    agbcc_repo="https://github.com/StanHash/agbcc.git"
    agbcc_branch="fix-dwarf-debug-line"
fi

git clone $agbcc_repo $temp

cd $temp
git checkout origin/$agbcc_branch
./build.sh
./install.sh $here

rm -fr $temp
