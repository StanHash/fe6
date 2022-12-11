# Fire Emblem: The Binding Blade

This is a decompilation of Fire Emblem: The Binding Blade.

It builds the following ROM:

* **[fe6.gba]** `sha1: a57095da867de4d585c33d4394712986245fe6ca`

[fe6.gba]: https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=0367

## Quick setup

- get a `arm-none-eabi` binutils toolchain (devkitARM works).
- get a copy of the original rom (still required for every build for now), put it in this folder and name it `fe6-base.gba`.
- run [tools/install-agbcc.sh](tools/install-agbcc.sh) or get an agbcc another way.
- `make compare`

In the future, a native GCC or GCC-like C compiler (such as clang) will be required to build tools, there is just no tool to build yet.

## Contributing

Please do. I'm going to be pretty strict on what I accept though, so mind your formatting and naming conventions.

You can also consider porting stuff between fe6 and fe8.

## See also

* [**StanHash/fe1**](https://github.com/StanHash/fe1), a disassembly of Fire Emblem: Shadow Dragon and the Blade of Light
* [**ZaneAvernathy/FireEmblem5**](https://github.com/ZaneAvernathy/FireEmblem5), a disassembly of Fire Emblem: Thracia 776
* [**FireEmblemUniverse/fireemblem8u**](https://github.com/FireEmblemUniverse/fireemblem8u), a decompilation of Fire Emblem: The Sacred Stones (US)
* [**StanHash/fomt**](https://github.com/StanHash/fomt), a decompilation of Havest Moon: Friends of Mineral Town (US)

## Contact

You can find me over at the [Fire Emblem Universe Discord](https://feuniverse.us/t/feu-discord-server/1480?u=stanh) under the handle `nat5#4387`.
