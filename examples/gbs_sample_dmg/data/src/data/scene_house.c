#pragma bank 255

// Scene: House

#include "gbs_types.h"
#include "data/bg_house.h"
#include "data/scene_house_collisions.h"
#include "data/palette_0.h"
#include "data/palette_1.h"
#include "data/sprite_player.h"
#include "data/scene_house_actors.h"
#include "data/scene_house_triggers.h"
#include "data/scene_house_sprites.h"
#include "data/scene_house_init.h"

BANKREF(scene_house)

const struct scene_t scene_house = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(bg_house),
    .collisions = TO_FAR_PTR_T(scene_house_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0, 0, 0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_1),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(sprite_player),
    .n_actors = 5,
    .n_triggers = 1,
    .n_sprites = 3,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_house_actors),
    .triggers = TO_FAR_PTR_T(scene_house_triggers),
    .sprites = TO_FAR_PTR_T(scene_house_sprites),
    .script_init = TO_FAR_PTR_T(scene_house_init)
};
