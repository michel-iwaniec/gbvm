#pragma bank 255

// Scene: Level 1
// Actors

#include "gbs_types.h"
#include "data/sprite_box.h"
#include "data/actor_box_interact.h"
#include "data/sprite_box.h"
#include "data/actor_box_0_interact.h"
#include "data/sprite_box.h"
#include "data/actor_box_1_interact.h"
#include "data/sprite_box.h"
#include "data/actor_box_2_interact.h"
#include "data/sprite_box.h"
#include "data/actor_box_3_interact.h"
#include "data/sprite_box.h"
#include "data/actor_box_4_interact.h"
#include "data/sprite_box.h"
#include "data/actor_box_5_interact.h"

BANKREF(scene_level_1_actors)

const struct actor_t scene_level_1_actors[] = {
    {
        // Box,
        .pos = {
            .x = 64 * 16,
            .y = 40 * 16
        },
        .bounds = {
            .left = PX_TO_SUBPX(0),
            .bottom = PX_TO_SUBPX(7),
            .right = PX_TO_SUBPX(15),
            .top = PX_TO_SUBPX(-8)
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_box),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .persistent = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(actor_box_interact),
        .reserve_tiles = 0
    },
    {
        // Box,
        .pos = {
            .x = 32 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = PX_TO_SUBPX(0),
            .bottom = PX_TO_SUBPX(7),
            .right = PX_TO_SUBPX(15),
            .top = PX_TO_SUBPX(-8)
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_box),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .persistent = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(actor_box_0_interact),
        .reserve_tiles = 0
    },
    {
        // Box,
        .pos = {
            .x = 80 * 16,
            .y = 56 * 16
        },
        .bounds = {
            .left = PX_TO_SUBPX(0),
            .bottom = PX_TO_SUBPX(7),
            .right = PX_TO_SUBPX(15),
            .top = PX_TO_SUBPX(-8)
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_box),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .persistent = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(actor_box_1_interact),
        .reserve_tiles = 0
    },
    {
        // Box,
        .pos = {
            .x = 80 * 16,
            .y = 72 * 16
        },
        .bounds = {
            .left = PX_TO_SUBPX(0),
            .bottom = PX_TO_SUBPX(7),
            .right = PX_TO_SUBPX(15),
            .top = PX_TO_SUBPX(-8)
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_box),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .persistent = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(actor_box_2_interact),
        .reserve_tiles = 0
    },
    {
        // Box,
        .pos = {
            .x = 64 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = PX_TO_SUBPX(0),
            .bottom = PX_TO_SUBPX(7),
            .right = PX_TO_SUBPX(15),
            .top = PX_TO_SUBPX(-8)
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_box),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .persistent = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(actor_box_3_interact),
        .reserve_tiles = 0
    },
    {
        // Box,
        .pos = {
            .x = 80 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = PX_TO_SUBPX(0),
            .bottom = PX_TO_SUBPX(7),
            .right = PX_TO_SUBPX(15),
            .top = PX_TO_SUBPX(-8)
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_box),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .persistent = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(actor_box_4_interact),
        .reserve_tiles = 0
    },
    {
        // Box,
        .pos = {
            .x = 96 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = PX_TO_SUBPX(0),
            .bottom = PX_TO_SUBPX(7),
            .right = PX_TO_SUBPX(15),
            .top = PX_TO_SUBPX(-8)
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_box),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .persistent = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(actor_box_5_interact),
        .reserve_tiles = 0
    }
};
