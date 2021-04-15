#pragma bank 255

// Scene: Start
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_1.h"
#include "data/spritesheet_4.h"
#include "data/spritesheet_5.h"

const void __at(255) __bank_scene_0_sprites;

const far_ptr_t scene_0_sprites[] = {
    TO_FAR_PTR_T(spritesheet_1),
    TO_FAR_PTR_T(spritesheet_4),
    TO_FAR_PTR_T(spritesheet_5)
};