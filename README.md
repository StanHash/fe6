
# Fire Emblem: The Binding Blade

This is a decompilation of Fire Emblem: The Binding Blade.

It builds the following ROM:

* [**fe6.gba**](https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=0367) `sha1: a57095da867de4d585c33d4394712986245fe6ca`

## Setting up

More better instructions will come eventually.

* You must have a copy of a Fire Emblem: The Binding Blade ROM named `fe6-base.gba` in the repository directory.

* Have one of Unix/Linux/WSL/MSYS/Cygwin/whatever

* Have a arm-none-eabi toolchain of some kind (such as devkitARM)

* Build and install the [**agbcc**](https://github.com/pret/agbcc) compiler. (should be under tools/agbcc)

* Build fe6 using `LOCAL_PREFIX=/path/to/arm-none-eabi/toolchain/ make`
  * For devkitARM, do `LOCAL_PREFIX=$DEVKITARM/bin/ make`

## Contributing

I am not in active need of contributions. If you want to contribute to a GBA Fire Emblem decompilation project you may want to consider contributing to fireemblem8u (see below) first (for example: by porting code from fe6 to fe8u).

If you are still willing to contribute to fe6 specifically, I won't deny you. Be warning that I will be quite picky about code quality/style and such.

## See also

* [**ZaneAvernathy/FireEmblem5**](https://github.com/ZaneAvernathy/FireEmblem5), a disassembly of Fire Emblem: Thracia 776
* [**FireEmblemUniverse/fireemblem8u**](https://github.com/FireEmblemUniverse/fireemblem8u), a decompilation of Fire Emblem: The Sacred Stones (US)

## Contact

You can find me over at the [Fire Emblem Universe Discord](https://feuniverse.us/t/feu-discord-server/1480?u=stanh) under the handle `stan#4387`. I also lurk some other places, including the pret discord, so you can find me there too.
