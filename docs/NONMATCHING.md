
# Nonmatching functions and function bits

This is a matching decompilation, which means that we are rewriting functions such that the resulting compiled code is the same as the one we started from.

Sometimes, we fail at getting that, in which case we have a nonmatch (a function which doesn't produce identical code to what we started with). To keep the rest of the disassembly matching, we substitue nonmatching bits of code with the original asm. Defining `NONMATCHING` to 1 will build the nonmatching bits instead.

Some functions are only matching thanks to "hacks" such as register variables. Those are "fake-matching" functions.

## List of non-matching functions in fe6

| File         | Function           | Opt. Level | Notes
| ------------ | ------------------ | ---------- | -----
| `main.c`     | `AgbMain`          | `O2`       | Prologue features strange bits I don't know how to generate
| `main.c`     | `PutBuildInfo`     | `O2`       | ^
| `util.c`     | `Interpolate` | `O2` | [this](https://agbcc.karathan.at/#z:OYLghAFBqd5QCxAYwPYBMCmBRdBLAF1QCcAaPECAM1QDsCBlZAQwBtMQBGAOgAYB2ACwBOAKyCATAGZhsucIAcpAFZdSrZrVAB9XclIBnVAFdiyDgHIApLwCCeegGoAIngBuEBwVKOvASispACEbW1CvRwNjACNtBV5OYIlBTycDBGYAB0wfCNZUXKcEPEKCRwAPUsdMWnQAuyt%2BEIbeYQjaYwBbQOaw1ojicp7Qkf6qRwga9EdA51nHXnq%2B4RthYkwCU1pHYuGW5YMAd0JkBAn0rMwl1cbe0eEWA0wFkHvVjs6ZqWcJ4scAWkc%2BT8jgAVBU9stVutNsRtvkZhIgi53BAPj4pgFgqNlo9npxXi0Vq0Pl8fuUwRVKRA/oDgZCbq0YVsgahEcjXB50dVapTMQyiXjHBJCVCSV0yVTwRTpdTaaysXcidCNiyEVYkSiuV0MbzwVM%2BbVFTjVkKpKLGcJSfMZVK7baaXgAQqBWK1qq4az2Vq0TqedN9Xr/Ya6q7Tcwno5BBbWtCKfMDYChtjleLPvNBpTM%2BDHc76Sm%2Bm7mZ71Zrc3TUCDAZzfZ1dQH/cb9uHI6IY8S1vHvsGkwKO9bu9nHEOh%2BWXQW3kyPfC2RrkWPgc6a9yDYGG/yJ8r%2BHNm1PYdteAzt6ELH51CALKILKRaBfeNfUBeAMKRExmZ4aqSca8EO%2Bns8ANYgKIvDnhYgjXreFj3qQj4WNeBggKBv7QaepBwLASBoJ0mR4OwZAUBA2G4fhIDMMA0TIPoVB4QQmDEIhEDRH%2BpDRA4zDEAAnhe36kNhnQ1AQADytCsNxqGkFgnSaMA7Asfg6zIAQ7iYIhEmYOUmDIMYdE8deXiYKwenqHg0TEBxnFPhgli8QQxB4J0elnhoWggLo2j6KwpmIZAZ6oJkyl0Gp/ydAQCBdNE/wGcQhwkABAJCRIAJUAgGn/BGnQIW%2B5hcM5F5XjeLFweRlHII4Ey4IQJCIl%2BPhWTheH0TVnAgk%2BP5/n4gHAaBRngZBRUXghSGkCh96dWBEj9RJcHtah41uPRBh4HQICCEAA%3D%3D) function generates asm that is closer to matching than the current nonmatching substitute.
| `util.c`     | `func_fe6_080149E0` | `O2` | Reg swap + Weird function pointer invocations.
| `util.c`     | `func_fe6_08014E98` | `O2` | Loop optimization weirdness
| `util.c`     | `func_fe6_08014F70` | `O2` | ^ + lazy
| `util.c`     | `func_fe6_0801501C` | `O2` | ^
| `util.c`     | `func_fe6_080150DC` | `O2` | ^
| `chapter.c`  | `CleanupUnitsBeforeChapter` | `O2` | annoying register swaps in the else block reguarding constant loads for unit->state changes
| `ai-080326C4.c` | `func_fe6_08032CE8` | `O2` | perc needs to be loaded into r4, I have no way of doing that.

## List of fake-matching functions in fe6

| File           | Function          | Opt. Level | Notes
| -------------- | ----------------- | ---------- | -----
| `ai-perform.c` | `AiPillageAction` | `O2` | Either operation order is wrong or regalloc is wrong. register variable "fixes" it.
| `ai-utility.c` | `AiFindClosestUnlockPosition` | `O2` | `mov r0, #0 ; cmp r0, #0 ; bne label`?
| `ai-utility.c` | `func_fe6_08030968` | `O2` | need to load constant before useless function call
| `ai-080326C4.c` | `func_fe6_08032C2C` | `O2` | need to load 0 and do math with it.
