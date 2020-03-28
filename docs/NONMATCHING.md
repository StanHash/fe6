
# Nonmatching functions and function bits

This is a matching decompilation, which means that we are rewriting functions such that the resulting compiled code is the same as the one we started from.

Sometimes, we fail at getting that, in which case we have a nonmatch (a function which doesn't produce identical code to what we started with). To keep the rest of the disassembly matching, we substitue nonmatching bits of code with the original asm. Defining `NONMATCHING` to 1 will build the nonmatching bits instead.

## List of non-matching functions in fe6

| File         | Function           | Opt. Level | Notes
| ------------ | ------------------ | ---------- | -----
| `main.c`     | `AgbMain`          | `O2`       | Prologue features strange bits I don't know how to generate
| `main.c`     | `sub_8000AFC`      | `O2`       | ^
| `hardware.c` | `InitBgs`          | `O0`       | One load stubbornly wants to use `r0` where `r1` is needed to match
| `face.c`     | `UpdateFaceTalk`   | `O0`       | Despite `O0`, ternary gets optimized out.
| `face.c`     | `Face_OnIdle`      | `O0`       | ^
| `talk.c`     | `IsTalkFaceMoving` | `O0`       | Needs to not generate `mov r1, r0; mov r0, r1` before compare
