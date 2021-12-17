
# Fire Emblem: The Binding Blade

This is a decompilation of Fire Emblem: The Binding Blade.

It builds the following ROM:

* [**fe6.gba**](https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=0367) `sha1: a57095da867de4d585c33d4394712986245fe6ca`

## Setting up

More better instructions will come eventually.

* You must have a copy of a Fire Emblem: The Binding Blade ROM named `fe6-base.gba` in the repository directory.

* Have one of Unix/Linux/[WSL](https://docs.microsoft.com/en-us/windows/wsl/install-win10)/MSYS2/Cygwin/whatever

* Have [devkitARM](https://devkitpro.org/wiki/Getting_Started) or another arm-none-eabi toolchain

* Build and install the [**agbcc**](https://github.com/pret/agbcc) compiler by running the [`tools/install-agbcc.sh`](tools/install-agbcc.sh) script.

* Build fe6 using `make`
  * For non-devkitARM toolchains, do `make TOOLCHAIN=/path/to/toolchain/`

## Contributing

Please do. I'm going to be pretty strict on what I accept though, so mind your formatting and naming conventions.

You can also consider porting stuff from fe6 over to fe8.

## See also

* [**StanHash/fe1**](https://github.com/StanHash/fe1), a disassembly of Fire Emblem : Shadow Dragon and the Blade of Light
* [**ZaneAvernathy/FireEmblem5**](https://github.com/ZaneAvernathy/FireEmblem5), a disassembly of Fire Emblem: Thracia 776
* [**StanHash/fe8**](https://github.com/StanHash/fe8), a decompilation of Fire Emblem: The Sacred Stones (US)

## Contact

You can find me over at the [Fire Emblem Universe Discord](https://feuniverse.us/t/feu-discord-server/1480?u=stanh) under the handle `nat5#4387`.
