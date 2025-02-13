#pragma bank 255

#include "data/states_defines.h"
#include "states/shmup.h"

#include "actor.h"
#include "camera.h"
#include "collision.h"
#include "data_manager.h"
#include "game_time.h"
#include "input.h"
#include "trigger.h"
#include "vm.h"
#include "math.h"

#ifndef SHOOTER_HURT_IFRAMES
#define SHOOTER_HURT_IFRAMES 10
#endif

UINT8 shooter_scroll_speed = 16;
UBYTE shooter_reached_end;
UWORD shooter_dest;
direction_e shooter_direction;

void shmup_init(void) BANKED {

    camera_offset_x_sp = PX_TO_SUBPX(0);
    camera_offset_y_sp = PX_TO_SUBPX(0);
    camera_deadzone_x_sp = PX_TO_SUBPX(0);
    camera_deadzone_y_sp = PX_TO_SUBPX(0);

    shooter_direction = PLAYER.dir;

    if (shooter_direction == DIR_LEFT) {
        // Right to left scrolling
        camera_offset_x_sp = PX_TO_SUBPX(48);
        shooter_dest = PX_TO_SUBPX(SCREEN_WIDTH_HALF + 48);
    } else if (shooter_direction == DIR_RIGHT) {
        // Left to right scrolling
        camera_offset_x_sp = PX_TO_SUBPX(-64);
        shooter_dest = PX_TO_SUBPX(image_width - SCREEN_WIDTH_HALF - 64);
    } else if (shooter_direction == DIR_UP) {
        // Bottom to top scrolling
        camera_offset_y_sp = PX_TO_SUBPX(48);
        shooter_dest = PX_TO_SUBPX(SCREEN_WIDTH_HALF + 40);
    } else {
        // Top to bottom scrolling
        camera_offset_y_sp = PX_TO_SUBPX(-48);
        shooter_dest = PX_TO_SUBPX(image_height - SCREEN_WIDTH_HALF - 40);
    }

    shooter_reached_end = FALSE;
}

void shmup_update(void) BANKED {
    actor_t *hit_actor;
    UBYTE tile_start, tile_end;
    direction_e new_dir = DIR_NONE;
    player_moving = FALSE;

    if (IS_DIR_HORIZONTAL(shooter_direction)) {
        if (INPUT_UP) {
            player_moving = TRUE;
            new_dir = DIR_UP;
        } else if (INPUT_DOWN) {
            player_moving = TRUE;
            new_dir = DIR_DOWN;
        } else {
            new_dir = shooter_direction;
        }
    } else {
        if (INPUT_LEFT) {
            player_moving = TRUE;
            new_dir = DIR_LEFT;
        } else if (INPUT_RIGHT) {
            player_moving = TRUE;
            new_dir = DIR_RIGHT;
        } else {
            new_dir = shooter_direction;
        }
    }

    // Set animation if direction has changed
    if (new_dir != PLAYER.dir) {
        actor_set_dir(&PLAYER, new_dir, player_moving);
    }

    // Move player from input
    if (player_moving) {
        upoint16_t new_pos;
        new_pos.x = PLAYER.pos.x;
        new_pos.y = PLAYER.pos.y;
        point_translate_dir(&new_pos, PLAYER.dir, PLAYER.move_speed);

        // Check for tile collisions
        if (IS_DIR_HORIZONTAL(shooter_direction)) {
            // Step Y
            tile_start = SUBPX_TO_TILE(PLAYER.bounds_sp.left);
            tile_end   = SUBPX_TO_TILE(PLAYER.bounds_sp.right) + 1;
            if (PLAYER.dir == DIR_DOWN) {
                uint16_t bottom_sp_rel = PLAYER.bounds_sp.bottom - PLAYER.pos.y;
                UBYTE tile_y = SUBPX_TO_TILE(new_pos.y + bottom_sp_rel);
                while (tile_start != tile_end) {
                    if (tile_at(tile_start, tile_y) & COLLISION_TOP) {
                        new_pos.y = (TILE_TO_SUBPX(tile_y) - bottom_sp_rel) - 1;
                        break;
                    }
                    tile_start++;
                }
                PLAYER.pos.y = new_pos.y;
            } else {
                uint16_t top_sp_rel = PLAYER.bounds_sp.top - PLAYER.pos.y;
                UBYTE tile_y = SUBPX_TO_TILE(new_pos.y + top_sp_rel);
                while (tile_start != tile_end) {
                    if (tile_at(tile_start, tile_y) & COLLISION_BOTTOM) {
                        new_pos.y = ((UBYTE)TILE_TO_SUBPX(tile_y + 1) - top_sp_rel) + 1;
                        break;
                    }
                    tile_start++;
                }
                PLAYER.pos.y = new_pos.y;
            }
        } else {
            // Step X
            tile_start = SUBPX_TO_TILE(PLAYER.bounds_sp.top);
            tile_end   = SUBPX_TO_TILE(PLAYER.bounds_sp.bottom) + 1;
            if (PLAYER.dir == DIR_RIGHT) {
                uint16_t right_sp_rel = PLAYER.bounds_sp.right - PLAYER.pos.x;
                UBYTE tile_x = SUBPX_TO_TILE(new_pos.x + right_sp_rel);
                while (tile_start != tile_end) {
                    if (tile_at(tile_x, tile_start) & COLLISION_LEFT) {
                        new_pos.x = (TILE_TO_SUBPX(tile_x) - right_sp_rel) - 1;
                        break;
                    }
                    tile_start++;
                }
                PLAYER.pos.x = MIN((image_width_sp - right_sp_rel - PX_TO_SUBPX(1)), new_pos.x);
            } else {
                uint16_t left_sp_rel = PLAYER.bounds_sp.left - PLAYER.pos.x;
                UBYTE tile_x = SUBPX_TO_TILE(new_pos.x + left_sp_rel);
                while (tile_start != tile_end) {
                    if (tile_at(tile_x, tile_start) & COLLISION_RIGHT) {
                        new_pos.x = (TILE_TO_SUBPX(tile_x + 1) - left_sp_rel) + 1;
                        break;
                    }
                    tile_start++;
                }
                PLAYER.pos.x = MAX(0, (WORD)new_pos.x);
            }
        }
    }

    // Auto scroll background
    if (!shooter_reached_end) {
        point_translate_dir(&PLAYER.pos, shooter_direction, shooter_scroll_speed);

        // Check if reached end of screen
        if ((shooter_direction == DIR_RIGHT) && (PLAYER.pos.x > shooter_dest)) {
            shooter_reached_end = TRUE;
            PLAYER.pos.x = shooter_dest;
        } else if ((shooter_direction == DIR_LEFT) && (PLAYER.pos.x < shooter_dest)) {
            shooter_reached_end = TRUE;
            PLAYER.pos.x = shooter_dest;
        } else if ((shooter_direction == DIR_DOWN) && (PLAYER.pos.y > shooter_dest)) {
            shooter_reached_end = TRUE;
            PLAYER.pos.y = shooter_dest;
        } else if ((shooter_direction == DIR_UP) && (PLAYER.pos.y < shooter_dest)) {
            shooter_reached_end = TRUE;
            PLAYER.pos.y = shooter_dest;
        }
    }
    actor_update_bounds_sp(&PLAYER);

    if (IS_FRAME_ODD) {
        // Check for trigger collisions
        if (trigger_activate_at_intersection(&PLAYER.bounds_sp, FALSE)) {
            // Landed on a trigger
            return;
        }

        // Check for actor collisions
        hit_actor = actor_overlapping_player(FALSE);
        if (hit_actor != NULL && hit_actor->collision_group) {
            player_register_collision_with(hit_actor);
        } else if (INPUT_A_PRESSED) {
            if (!hit_actor) {
                hit_actor = actor_in_front_of_player(8, TRUE);
            }
            if (hit_actor && !hit_actor->collision_group && hit_actor->script.bank) {
                script_execute(hit_actor->script.bank, hit_actor->script.ptr, 0, 1, 0);
            }
        }
    }
}
