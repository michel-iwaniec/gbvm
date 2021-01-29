#pragma bank 255

// SpriteSheet: savepoint

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_5;

const metasprite_t spritesheet_5_metasprite_0[]  = {
    {0, 0, 0, 0}, {0, 8, 2, 0}, {metasprite_end}
};

const metasprite_t spritesheet_5_metasprite_1[]  = {
    {0, 0, 4, 0}, {0, 8, 6, 0}, {metasprite_end}
};

const metasprite_t * const spritesheet_5_metasprites[] = {
    spritesheet_5_metasprite_0,
    spritesheet_5_metasprite_1,
};

const struct spritesheet_t spritesheet_5 = {
  .n_tiles = 8,
  .n_metasprites = 2,
  .metasprites = spritesheet_5_metasprites,
  .animations  = {
    { .start = 0, .end = 1 }, // bottom
    { .start = 0, .end = 1 }, // right
    { .start = 0, .end = 1 }, // top
    { .start = 0, .end = 1 }, // left
  },    
  .tiles = {
    1,1,3,2,5,6,9,14,25,22,23,24,9,14,9,14,5,6,5,6,3,2,3,2,1,1,1,3,0,15,0,3,128,128,192,64,160,96,144,112,152,104,232,24,144,112,144,112,160,96,160,96,192,64,192,64,128,128,128,192,0,240,0,192,0,0,1,1,3,2,5,6,9,14,25,22,23,24,9,14,9,14,5,6,5,6,3,2,3,2,1,3,1,15,0,3,0,0,128,128,192,64,160,96,144,112,152,104,232,24,144,112,144,112,160,96,160,96,192,64,192,64,128,192,128,240,0,192
  }
};
