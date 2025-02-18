#pragma bank 255

// Tileset: bg_titlescreen_tileset

#include "gbs_types.h"

BANKREF(bg_titlescreen_tileset)

const struct tileset_t bg_titlescreen_tileset = {
    .n_tiles = 104,
    .tiles = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF8, 0xF8, 0xF8, 0xE0, 0xE0, 0x00, 0xE0,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x01, 0x01, 0x01, 0x01,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE,
        0xFF, 0xFF, 0xF0, 0xF0, 0xE0, 0xF0, 0xC0, 0xC0, 0x80, 0xC0, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00,
        0xFF, 0xFF, 0x0F, 0x1F, 0x0F, 0x1F, 0x01, 0x07, 0x01, 0x07, 0x01, 0x07, 0x00, 0x07, 0x00, 0x03,
        0xFF, 0xFF, 0xF8, 0xFF, 0xE0, 0xFC, 0xE0, 0xFC, 0xE0, 0xFC, 0xE0, 0xFC, 0x60, 0xFC, 0x70, 0xFC,
        0x07, 0x07, 0x07, 0x07, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x81, 0xC3, 0x81, 0xC3, 0x00, 0x81, 0x00, 0x81, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
        0xFF, 0xFF, 0xFF, 0xFF, 0x7C, 0xFE, 0x7C, 0xFE, 0x7C, 0xFE, 0x1C, 0xFE, 0x1C, 0x7E, 0x1C, 0x7E,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x07, 0x0F,
        0x7F, 0x7F, 0x1F, 0x7F, 0x0F, 0x0F, 0x01, 0x0F, 0x01, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x80,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7E, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0xC7, 0xC0, 0xC7, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x01, 0x03,
        0xFF, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0xF8, 0xFF, 0xF8, 0xFF, 0xF8, 0xFF, 0xFC, 0xFF, 0xFC, 0xFF,
        0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0xF8,
        0x01, 0x01, 0x01, 0x01, 0x03, 0xC7, 0x07, 0x3F, 0x07, 0x3F, 0x07, 0x07, 0x07, 0x07, 0x01, 0x01,
        0xFC, 0xFE, 0xFC, 0xFE, 0xF8, 0xF8, 0xF8, 0xF8, 0xF0, 0xF8, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xF0,
        0x00, 0x03, 0x00, 0x03, 0x01, 0x0F, 0x01, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x83, 0x00, 0x83, 0x80, 0x83, 0x80, 0x83, 0x00, 0x83, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03,
        0x70, 0xFC, 0x40, 0xF8, 0x40, 0xF8, 0x40, 0xF8, 0x40, 0xF8, 0x40, 0xF8, 0x40, 0xF8, 0x00, 0xF8,
        0x00, 0x00, 0x00, 0x18, 0x10, 0x18, 0x1C, 0x1E, 0x1C, 0x1F, 0x1F, 0x1F, 0x07, 0x07, 0x07, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x30, 0x10, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
        0x1C, 0x7E, 0x1C, 0x7E, 0x1C, 0x7E, 0x1C, 0x7E, 0x0C, 0x1E, 0x0C, 0x1E, 0x0C, 0x1F, 0x0F, 0x1F,
        0x07, 0x0F, 0x01, 0x07, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x0F, 0x00, 0x0F,
        0x1C, 0xFC, 0x1C, 0xFC, 0x1C, 0xFC, 0x1C, 0xFC, 0x10, 0xFC, 0x10, 0xF8, 0xF0, 0xF8, 0xF0, 0xF8,
        0x00, 0x01, 0x00, 0x07, 0x00, 0x07, 0x01, 0x07, 0x01, 0x07, 0x01, 0x1F, 0x07, 0x1F, 0x07, 0x1F,
        0x3F, 0xFF, 0x3F, 0xFF, 0x7E, 0xFF, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF0, 0xFC, 0xF0, 0xFC,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x0F, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x3F, 0x0C, 0x3F,
        0x7F, 0xFF, 0x7F, 0xFF, 0x1F, 0xFF, 0x1F, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0xFC, 0xFF, 0xFC, 0xFF,
        0x00, 0x87, 0x00, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x0F,
        0x20, 0x70, 0x20, 0x70, 0x20, 0x78, 0x20, 0x78, 0x30, 0x7F, 0x34, 0xFF, 0x7C, 0xFF, 0x7F, 0xFF,
        0x00, 0x00, 0x00, 0x3C, 0x02, 0x7F, 0x0E, 0x7F, 0x0F, 0xFF, 0x1F, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF,
        0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x80, 0x87, 0x80, 0x87, 0xE0, 0xFF, 0xFF, 0xFF,
        0x00, 0xF8, 0x00, 0xF8, 0x00, 0xF8, 0x00, 0xFC, 0x30, 0xFC, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x1F, 0x1F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0,
        0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x3F,
        0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x7F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xC1, 0xC1,
        0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0xC7, 0x83, 0xC7, 0x83, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0,
        0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xF0, 0xF8, 0xE0, 0xF8, 0xE0, 0xF8, 0xE0, 0xF8, 0xE0, 0xF8, 0xF8, 0xFC, 0xF8, 0xFC, 0xFF, 0xFF,
        0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0xFF,
        0xF0, 0xF8, 0xF0, 0xF8, 0x70, 0x78, 0x20, 0x78, 0x20, 0x78, 0x20, 0xF8, 0x20, 0xF8, 0xE0, 0xF8,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x0C, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x3F, 0x07, 0x7F, 0x07, 0x7F, 0x07, 0xFF, 0x3F, 0xFF, 0x0F, 0x0F, 0x07, 0x0F, 0x03, 0x0F,
        0xFC, 0xFF, 0xFC, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x00, 0x80, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x03, 0x0F, 0x07, 0xFF, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFE, 0xFC, 0xFE, 0xF0, 0xFE,
        0xFF, 0xFF, 0xF0, 0xF0, 0xF0, 0xF0, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x07,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0xF8, 0xFF, 0xFC, 0xFC, 0xF0, 0xFC, 0xF0, 0xFC,
        0x80, 0xE0, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x07,
        0x3F, 0x3F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
        0xC0, 0xC1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xF0, 0xF0, 0x60, 0x60, 0x20, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xFF, 0xFF, 0x7F, 0x7F, 0x3F, 0x7F, 0x1F, 0x7F, 0x1F, 0x7F, 0x1F, 0x1F, 0x07, 0x1F, 0x07, 0x1F,
        0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF8, 0xF8, 0xF8, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0xE0,
        0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xF0, 0xFC, 0xF8, 0xFC, 0xFF, 0xFF, 0x7F, 0xFF, 0x3F, 0x7F, 0x1F, 0x7F, 0x0F, 0x7F, 0x1F, 0x7F,
        0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x07, 0x3F, 0x07, 0x3F, 0x07, 0xFF, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xF0, 0xFC, 0xF0, 0xFC, 0xF0, 0xFC, 0xE0, 0xFC, 0xE0, 0xFC, 0xE0, 0xFC, 0xE0, 0xFC, 0xF0, 0xFC,
        0x00, 0x03, 0x00, 0x03, 0x07, 0x0F, 0x04, 0x0F, 0x0C, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x03,
        0x0F, 0xFF, 0x0F, 0xFF, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
        0xF0, 0xF0, 0xC0, 0xF0, 0xC0, 0xF0, 0xC0, 0xE0, 0xC0, 0xE0, 0x80, 0xE0, 0x80, 0xE0, 0x80, 0xE0,
        0x0E, 0x1F, 0x0E, 0x1F, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78,
        0x06, 0x06, 0x04, 0x06, 0x04, 0x06, 0x04, 0x06, 0x04, 0x06, 0x04, 0x06, 0x04, 0x06, 0x04, 0x06,
        0x00, 0x06, 0x00, 0x06, 0x02, 0x07, 0x03, 0x07, 0x03, 0x07, 0x01, 0x01, 0x00, 0x01, 0x00, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x8C, 0x80, 0xFC, 0x84, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC,
        0x07, 0x1F, 0x07, 0x1F, 0x0F, 0x1F, 0x07, 0x07, 0x06, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x00, 0xFF, 0x00, 0xFF, 0x07, 0x07, 0x01, 0x07, 0x01, 0x07, 0x01, 0x0F, 0x03, 0x0F,
        0x1F, 0xFF, 0x1F, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xF0, 0xFC, 0xF0, 0xFE, 0xF0, 0xFE, 0xF0, 0xFE, 0xFC, 0xFF, 0xFC, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF,
        0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0xFF, 0xC0, 0xFF,
        0x00, 0xC0, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1F, 0x0F, 0x1F, 0x0F, 0xFF, 0xFF, 0xFF,
        0x00, 0xF0, 0x80, 0xF0, 0x80, 0xFF, 0xE0, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x00, 0xFE, 0x70, 0xFE, 0x78, 0xFF, 0xF8, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x04, 0x06, 0x04, 0x06, 0x04, 0x0F, 0x04, 0x0F, 0x0F, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x00, 0x01, 0x00, 0x01, 0x00, 0x07, 0x00, 0x07, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xFF, 0xF8, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x02, 0x07, 0x02, 0x07, 0x02, 0x1F, 0x06, 0x1F, 0x04, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0xFC, 0xFF,
        0x0F, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x07, 0x01, 0x07, 0x07, 0xFF,
        0xFF, 0xFF, 0xFF, 0xF8, 0xFF, 0xFB, 0xFF, 0xFB, 0xFF, 0xF8, 0xFF, 0xFB, 0xFF, 0xFB, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x38, 0xFF, 0xDB, 0xFF, 0xDB, 0xFF, 0x38, 0xFF, 0xFB, 0xFF, 0xFB, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x38, 0xFF, 0xDB, 0xFF, 0xD8, 0xFF, 0x3B, 0xFF, 0xDB, 0xFF, 0xD8, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x1C, 0xFF, 0xFB, 0xFF, 0x3C, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0x1C, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x1C, 0xFF, 0xFB, 0xFF, 0x3C, 0xFF, 0xDF, 0xFF, 0xDB, 0xFF, 0x3C, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x1F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xDF, 0xFF, 0xDF, 0xFF, 0x3F, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFB, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFC, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x18, 0xFF, 0xFE, 0xFF, 0x3E, 0xFF, 0xDE, 0xFF, 0xDE, 0xFF, 0x3E, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x3C, 0xFF, 0xFB, 0xFF, 0xFB, 0xFF, 0xF8, 0xFF, 0xFB, 0xFF, 0xFB, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x38, 0xFF, 0xDB, 0xFF, 0xDB, 0xFF, 0x18, 0xFF, 0xDB, 0xFF, 0xDB, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x38, 0xFF, 0xDE, 0xFF, 0xDE, 0xFF, 0x3E, 0xFF, 0xDE, 0xFF, 0xDE, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
    }
};
