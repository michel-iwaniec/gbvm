#pragma bank 255

// Tileset: 2

#include "gbs_types.h"

const void __at(255) __bank_tileset_2;

const struct tileset_t tileset_2 = {
    .n_tiles = 4,
    .tiles = {
        0xFF, 0xFF, 0xFF, 0x01, 0x01, 0xFF, 0xF9, 0xFF, 0xE9, 0xDF, 0xC9, 0xBF, 0x99, 0x7F, 0x39, 0xFF,
        0x79, 0xFF, 0xF9, 0xDF, 0x99, 0xEF, 0xC9, 0xFF, 0xF9, 0xFF, 0xF9, 0x07, 0x01, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x80, 0x80, 0xFF, 0x9F, 0xFF, 0x97, 0xFB, 0x93, 0xFD, 0x9B, 0xFF, 0x9F, 0xFE,
        0x9E, 0xFD, 0x9C, 0xFB, 0x99, 0xF7, 0x93, 0xFF, 0x9F, 0xFF, 0x9F, 0xE0, 0x80, 0xFF, 0xFF, 0xFF
    }
};