
# So Long — And thanks for all the fish!

A small 2D top-down game in C using MiniLibX.

## Description

**So Long** is a 42 project that introduces window management, event handling, textures, and basic game logic. The player navigates a tile-based map, collects all collectibles, and reaches the exit.

The map is loaded from a `.ber` file and validated before the game starts — checking for rectangular shape, wall enclosure, required elements, and a valid path to all collectibles and the exit using flood fill.

## Features

- Tile-based 2D top-down rendering via MiniLibX
- XPM texture loading with size validation
- Map validation: rectangle check, wall enclosure, element counts, flood fill path check
- Player movement: `W A S D` and arrow keys
- Move counter displayed on screen (bonus)
- Directional player sprites (up, down, left, right)
- Clean exit on `ESC` or window close

## Map Format

Maps use `.ber` files with 5 characters:

| Character | Meaning |
|---|---|
| `0` | Empty space |
| `1` | Wall |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player start |

Example:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Build
```bash
make
```
```bash
make clean    # remove object files
make fclean   # remove object files and binary
make re       # fclean + compile
```

## Usage
```bash
./so_long maps/test.ber
```

## Controls

| Key | Action |
|---|---|
| `W` / `↑` | Move up |
| `S` / `↓` | Move down |
| `A` / `←` | Move left |
| `D` / `→` | Move right |
| `ESC` | Quit |

## Project Structure
```
so_long/
├── src/
│   ├── main.c              # entry point
│   ├── game/
│   │   ├── move.c          # player movement and collision
│   │   └── end_game.c      # win condition
│   ├── init/
│   │   └── init_bonus.c    # animation init (WIP)
│   ├── map/
│   │   ├── map_loader.c    # file reading, map allocation
│   │   ├── map_check.c     # validation (walls, count, path)
│   │   ├── map_utils.c     # player/collectible init, free_map
│   │   └── path_check.c    # flood fill reachability check
│   ├── mlxwrap/
│   │   ├── mlx_init.c      # window initialization
│   │   └── hooks.c         # keyboard and close events
│   ├── render/
│   │   ├── render.c        # tile and map drawing
│   │   ├── textures.c      # XPM loading and validation
│   │   └── hud.c           # on-screen move counter
│   └── utils/
│       ├── ft_utils.c      # ft_itoa, ft_bzero
│       ├── errors.c        # error handling
│       └── debugger.c      # map debug print
├── include/
│   ├── so_long.h
│   └── so_long_bonus.h
├── assets/                 # XPM textures
├── gnl/                    # get_next_line
├── maps/                   # .ber map files
├── mlx/                    # MiniLibX library
└── Makefile
```

## Resources

- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [XPM format reference](https://en.wikipedia.org/wiki/X_PixMap)
- [Flood fill algorithm](https://en.wikipedia.org/wiki/Flood_fill)

## Author
```
loasaad
```
