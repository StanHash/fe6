# Nonmatching functions and function bits

This is a matching decompilation, which means that we are rewriting functions such that the resulting compiled code is the same as the one we started from.

Sometimes, we fail at getting that, in which case we have a nonmatch (a function which doesn't produce identical code to what we started with). To keep the rest of the disassembly matching, we substitue nonmatching bits of code with the original asm. Defining `NONMATCHING` to 1 will build the nonmatching bits instead.

Some functions are only matching thanks to "hacks" such as register variables. Those are "fake-matching" functions.

## List of non-matching functions in fe6

| File         | Function           | Opt. Level | Notes
| ------------ | ------------------ | ---------- | -----
| `main.c`     | `AgbMain`          | `O2`       | Need -mtpcs-frame which agbcc doesn't support
| `main.c`     | `PutBuildInfo`     | `O2`       | ^
| `util.c`     | `func_fe6_080149E0` | `O2` | Reg swap + Weird function pointer invocations.
| `chapter.c`  | `CleanupUnitsBeforeChapter` | `O2` | annoying register swaps in the else block regarding constant loads for unit->flags changes
| `ai-080326C4.c` | `func_fe6_08032CE8` | `O2` | perc needs to be loaded into r4, I have no way of doing that.

## List of fake-matching functions in fe6

| File           | Function          | Opt. Level | Notes
| -------------- | ----------------- | ---------- | -----
| `util.c`       | `Interpolate` | `O2` | stole it from fe8
| `ai-utility.c` | `AiFindClosestUnlockPosition` | `O2` | `mov r0, #0 ; cmp r0, #0 ; bne label`?
| `ai-utility.c` | `func_fe6_08030968` | `O2` | need to load constant before useless function call
| `ai-080326C4.c` | `func_fe6_08032C2C` | `O2` | need to load 0 and do math with it.
| `eventinfo.c` | `EvtListCmd_Door` | `O2` | `asm("":::"memory");` needed
| `eventinfo.c` | `StartAvailableTileEvent` | `O2` | somehow theres a couple `nop`s in here.
