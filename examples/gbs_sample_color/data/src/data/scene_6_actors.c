#pragma bank 255

// Scene: Menu Page 1
// Actors

#include "gbs_types.h"
#include "data/spritesheet_23.h"
#include "data/spritesheet_23.h"
#include "data/spritesheet_23.h"
#include "data/spritesheet_23.h"
#include "data/spritesheet_23.h"
#include "data/spritesheet_23.h"

BANKREF(scene_6_actors)

const struct actor_t scene_6_actors[] = {
    {
        // Quest1,
        .pos = {
            .x = 16 * 16,
            .y = 32 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_23),
        .move_speed = 16,
        .anim_tick = 255,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .reserve_tiles = 0
    },
    {
        // Quest2,
        .pos = {
            .x = 16 * 16,
            .y = 48 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_23),
        .move_speed = 16,
        .anim_tick = 255,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .reserve_tiles = 0
    },
    {
        // Quest3,
        .pos = {
            .x = 16 * 16,
            .y = 64 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_23),
        .move_speed = 16,
        .anim_tick = 255,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .reserve_tiles = 0
    },
    {
        // Quest4,
        .pos = {
            .x = 16 * 16,
            .y = 88 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_23),
        .move_speed = 16,
        .anim_tick = 255,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .reserve_tiles = 0
    },
    {
        // Quest5,
        .pos = {
            .x = 16 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_23),
        .move_speed = 16,
        .anim_tick = 255,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .reserve_tiles = 0
    },
    {
        // Quest6,
        .pos = {
            .x = 16 * 16,
            .y = 120 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_23),
        .move_speed = 16,
        .anim_tick = 255,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .reserve_tiles = 0
    }
};
