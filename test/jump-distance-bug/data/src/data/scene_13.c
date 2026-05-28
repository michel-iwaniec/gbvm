#pragma bank 255

// Scene: Jump Test

#include "gbs_types.h"
#include "data/bg_jump_bug_scene.h"
#include "data/scene_13_collisions.h"
#include "data/palette_0.h"
#include "data/palette_1.h"
#include "data/sprite_actor.h"
#include "data/scene_13_init.h"

BANKREF(scene_13)

const struct scene_t scene_13 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_PLATFORM,
    .background = TO_FAR_PTR_T(bg_jump_bug_scene),
    .collisions = TO_FAR_PTR_T(scene_13_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0, 0, 0)
    },
    .scroll_bounds = {
        .left = 0,
        .top = 0,
        .right = 0,
        .bottom = 0
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_1),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(sprite_actor),
    .n_actors = 0,
    .n_triggers = 0,
    .n_sprites = 0,
    .n_projectiles = 0,
    .script_init = TO_FAR_PTR_T(scene_13_init)
};
