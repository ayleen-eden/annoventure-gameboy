# Annoventure

<img width="456" height="430" src="https://github.com/user-attachments/assets/d2b7d730-3dfe-44af-96c3-0f0a7b0663c4" />
<img width="571.2" height="428.4" src="https://github.com/user-attachments/assets/ec9bff7b-53c0-4eba-a88e-304d3b03eb42" />

A tiny cat-themed platformer built for the original Game Boy, written in C using [GBDK-2020](https://github.com/gbdk-2020/gbdk-2020).

## What it does

Move and jump a sprite around a scrolling background using real Game Boy hardware registers — no game engine, just direct memory-mapped I/O, tile/sprite management, and manual physics (gravity, jump velocity, ground collision).

### Controls
- **D-pad left/right** — move
- **A** — jump

## Tech
- C
- GBDK-2020 (Game Boy Development Kit)
- Game Boy hardware: sprites, background/window tiles, sound registers

## Status
Paused — core movement, physics, and background/sprite rendering are working; enemies, collectibles, and level design are still on the to-do list.

## Try it
Build with `make` (see Building below), then run the resulting `Annoventure.gb` in any Game Boy emulator (e.g. [BGB](https://bgb.bircd.org/)) or on original hardware.

### Building
Requires [GBDK-2020](https://github.com/gbdk-2020/gbdk-2020) installed locally.

```bash
make GBDK_HOME=/path/to/gbdk/
```

Replace `/path/to/gbdk/` with your local GBDK installation directory (must end with a trailing slash).
