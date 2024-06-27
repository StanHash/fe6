#!/bin/bash

OBJDUMP="$DEVKITARM/bin/arm-none-eabi-objdump -D -bbinary -marmv4t -Mforce-thumb"
OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
$OBJDUMP $OPTIONS fe6-base.gba > fe6-base.dump
$OBJDUMP $OPTIONS fe6.gba > fe6.dump
diff -y fe6-base.dump fe6.dump
rm fe6-base.dump fe6.dump
