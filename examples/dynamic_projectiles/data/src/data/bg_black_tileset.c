#pragma bank 255

// Tileset: bg_black_tileset

#include "gbs_types.h"

BANKREF(bg_black_tileset)

const struct tileset_t bg_black_tileset = {
    .n_tiles = 1,
    .tiles = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
    }
};
