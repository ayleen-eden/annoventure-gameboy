# Annoventure

> **Status**: paused

<img width="456" height="430" src="https://github.com/user-attachments/assets/d2b7d730-3dfe-44af-96c3-0f0a7b0663c4" />
<img width="571.2" height="428.4" src="https://github.com/user-attachments/assets/ec9bff7b-53c0-4eba-a88e-304d3b03eb42" />

A purr-fectly tiny cat-themed platformer built for the original Game Boy hardware. No game engines.

## What it does

Move and jump a cat sprite around a scrolling background using real Game Boy hardware registers. It features direct memory-mapped I/O, tile/sprite management, and completely manual physics (gravity, jump velocity, and ground collision).

## Controls

* **D-pad left/right** — Move
* **A** — Jump

## Tech Stack

* C
* GBDK-2020 (Game Boy Development Kit)
* Game Boy Hardware Architecture (Sprites, background/window tiles, sound registers)

## Try it / Building

You can run the compiled `Annoventure.gb` file in any Game Boy emulator (like [BGB](https://bgb.bircd.org/)) or on original hardware via a flash cart.

To build it yourself, you will need [GBDK-2020](https://github.com/gbdk-2020/gbdk-2020) installed locally:
```bash
make GBDK_HOME=/path/to/gbdk/
```

> **Note**: Replace `/path/to/gbdk/` with your local GBDK installation directory, making sure to *include the trailing slash*!