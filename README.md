# fillit
Tetris like game, filling a map with tetris blocks.

## Goal
Make the smallest possible "square" (which can contain holes) with a given list of
tetriminos (tetris blocks).

## Compiling
Run `make`, giving you a executable called `fillit` (running on linux and macosx)

## Usage
`./fillit [file]`

Example:
```
~ ./fillit samples/test_8

.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```

```
cat map/test_8

....
....
..##
.##.

....
.##.
..#.
..#.

....
....
..##
.##.

....
....
..##
.##.

....
....
..##
.##.

....
....
..##
.##.

....
....
..##
.##.

....
....
..##
.##.
```
