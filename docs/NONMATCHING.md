# Nonmatching functions and function bits

This is a matching decompilation, which means that we are rewriting functions such that the resulting compiled code is the same as the one we started from.

Sometimes, we fail at getting that, in which case we have a nonmatch (a function which doesn't produce identical code to what we started with). To keep the rest of the disassembly matching, we substitue nonmatching bits of code with the original asm. Defining `NONMATCHING` to 1 will build the nonmatching bits instead.

Some functions are only matching thanks to "hacks" such as register variables. Those are "fake-matching" functions.

## List of non-matching functions in fe6

| File         | Function           | Opt. Level | Notes
| ------------ | ------------------ | ---------- | -----
| `main.c`     | `AgbMain`          | `O2`       | Need -mtpcs-frame which agbcc doesn't support
| `main.c`     | `PutBuildInfo`     | `O2`       | ^
| `chapter.c`  | `CleanupUnitsBeforeChapter` | `O2` | annoying register swaps in the else block regarding constant loads for unit->flags changes
| `unitlistscreen.c` | `func_fe6_08075E94` | `O2` | https://decomp.me/scratch/sjiAE - reg swap + wrong loop constant load order

## List of fake-matching functions in fe6

| File           | Function          | Opt. Level | Notes
| -------------- | ----------------- | ---------- | -----
| `util.c`       | `Interpolate` | `O2` | stole it from fe8
| `ai-utility.c` | `func_fe6_08030968` | `O2` | need to load constant before useless function call
| `eventinfo.c` | `EvtListCmd_Door` | `O2` | `asm("":::"memory");` needed (in multiple functions after this also)
| `eventinfo.c` | `StartAvailableTileEvent` | `O2` | somehow theres a couple `nop`s in here.
| `statusscreen.c` | `StatusScreenSprites_Loop`| `O2` | register asm("r4")
| `minimap.c` | `Minimap_ApplyViewportFlashColor` | `O2` | register asm("r3")
