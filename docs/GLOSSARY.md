## TM/tilemap

Stands for "tile map".

In text background modes, each of the GBA's hardware backgrounds is assigned a tile map.
This is the kind of tile map this is referring to.

In GBAFE, there exists buffers for tilemaps of each of the 4 hardware backgrounds (whose
names in fe6 are `gBgTm0` through `gBgTm3`). Each of these can hold 32x32 16bit tiles.

## TSA

This is a term that was used to denote tile map data ever since way before my time.
I do not know what it stands for (or if it even stands for anything).

When the term is used here, it is _only_ referring to specifically the headered tilemaps with rows in reverse
order that the `TmApplyTsa` function takes as input, and nothing else. I would say "Tile Map" or "TM" otherwise.

## BM

Stands for "Battle Map".

The screen where the map is displayed.

## Banim/Manim

Banim stands for "Battle Animations", Manim stands for "Map (Battle) Animations".

## PID/PInfo

A PID is a character ID, a PInfo is a struct containing the static info of a character.

The term "PID" is what the original developers used for exacly what I use it for. It probably stands for "Person ID".

The term "PInfo" is my invention.
Along with "JInfo" and "IInfo", I think it makes for nice symmetric mapping between "IDs" and "Infos".

## JID/JInfo

Same as PID/PInfo, but for classes. The "J" probably stands for "Job".

This one is probably the biggest stretch, as no one in the western community really refers to Fire Emblem classes as "jobs". I didn't want to go for a "C" prefix because it could be confused for character as well (and CLASS starts to get long for a prefix for identifiers that are commonly used in chapter events).

## IID/IInfo

Same as PID/PInfo and JID/JInfo, but for items. "I" is for "Item" (this one isn't hard to figure out).

## Unit

A unit is not a character (PID/PInfo)!

Units are part of the mutable game state. They have many attributes that can change over the course of a playthrough, among which is a PID and JID.

Sometimes in the decompiled code, I may use the term "UID" to refer to a unit id, but those aren't really the same kind of IDs as PID/JID/IIDs.

Each faction has a range of unit ids assigned to it:

- blue: 0x01 through 0x3F
- green: 0x41 through 0x7F
- red: 0x81 through 0xBF
- purple: 0xC1 through 0xFF

This means that a unit's id also encodes its faction.
