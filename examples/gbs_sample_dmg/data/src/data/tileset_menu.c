#pragma bank 255

// Tileset: tileset_menu

#include "gbs_types.h"

BANKREF(tileset_menu)

const struct tileset_t tileset_menu = {
    .n_tiles = 33,
    .tiles = {
        0x3F, 0x00, 0x7F, 0x3F, 0xC0, 0x40, 0xDF, 0x5F, 0xF0, 0x50, 0xD0, 0x50, 0xF0, 0x50, 0xF0, 0x50,
        0xFF, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xFC, 0x00, 0xFE, 0xFC, 0x03, 0x02, 0xFB, 0xFA, 0x0F, 0x0A, 0x0B, 0x0A, 0x0F, 0x0A, 0x0F, 0x0A,
        0xF0, 0x50, 0xF0, 0x50, 0xF0, 0x50, 0xF0, 0x50, 0xF0, 0x50, 0xF0, 0x50, 0xF0, 0x50, 0xF0, 0x50,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3C, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x4A, 0x4A, 0x44, 0x44, 0x3A, 0x3A, 0x00, 0x00,
        0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x3C, 0x00, 0x00,
        0x00, 0x00, 0x7E, 0x7E, 0x40, 0x40, 0x7C, 0x7C, 0x40, 0x40, 0x40, 0x40, 0x7E, 0x7E, 0x00, 0x00,
        0x00, 0x00, 0x3E, 0x3E, 0x40, 0x40, 0x3C, 0x3C, 0x02, 0x02, 0x42, 0x42, 0x3C, 0x3C, 0x00, 0x00,
        0x00, 0x00, 0x7C, 0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00,
        0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7E, 0x7E, 0x00, 0x00,
        0x00, 0x00, 0x7C, 0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x7C, 0x7C, 0x00, 0x00,
        0x0F, 0x0A, 0x0F, 0x0A, 0x0F, 0x0A, 0x0F, 0x0A, 0x0F, 0x0A, 0x0F, 0x0A, 0x0F, 0x0A, 0x0F, 0x0A,
        0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x42, 0x42, 0x66, 0x66, 0x5A, 0x5A, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
        0x00, 0x00, 0x42, 0x42, 0x62, 0x62, 0x52, 0x52, 0x4A, 0x4A, 0x46, 0x46, 0x42, 0x42, 0x00, 0x00,
        0x00, 0x00, 0x3C, 0x3C, 0x42, 0x42, 0x40, 0x40, 0x4E, 0x4E, 0x42, 0x42, 0x3E, 0x3E, 0x00, 0x00,
        0x00, 0x00, 0x3C, 0x3C, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x42, 0x3C, 0x3C, 0x00, 0x00,
        0x00, 0x00, 0x3C, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x7E, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
        0x00, 0x00, 0x7C, 0x7C, 0x42, 0x42, 0x7C, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x7C, 0x00, 0x00,
        0x00, 0x00, 0x3C, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x3C, 0x00, 0x00,
        0x00, 0x00, 0x44, 0x44, 0x48, 0x48, 0x50, 0x50, 0x70, 0x70, 0x48, 0x48, 0x44, 0x44, 0x00, 0x00,
        0x00, 0x00, 0x7C, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x7C, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00,
        0x00, 0x00, 0x7C, 0x7C, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x7C, 0x7C, 0x00, 0x00,
        0x00, 0x00, 0x7E, 0x7E, 0x40, 0x40, 0x40, 0x40, 0x7C, 0x7C, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00,
        0x00, 0x00, 0x7C, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
        0x00, 0x00, 0x7C, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x7C, 0x00, 0x00,
        0x00, 0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x28, 0x28, 0x28, 0x28, 0x10, 0x10, 0x00, 0x00,
        0x00, 0x00, 0x42, 0x42, 0x24, 0x24, 0x18, 0x18, 0x18, 0x18, 0x24, 0x24, 0x42, 0x42, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xD0, 0x70, 0xF0, 0x50, 0xD0, 0x70, 0xF0, 0x50, 0xDF, 0x7F, 0xC0, 0x7F, 0x7F, 0x3F, 0x3F, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
        0x0B, 0x0E, 0x0F, 0x0A, 0x0B, 0x0E, 0x0F, 0x0A, 0xFB, 0xFE, 0x03, 0xFE, 0xFE, 0xFC, 0xFC, 0x00
    }
};