#pragma bank 255

#include "data/states_defines.h"
#include "states/pointnclick.h"

#include "actor.h"
#include "camera.h"
#include "data_manager.h"
#include "game_time.h"
#include "input.h"
#include "trigger.h"
#include "vm.h"
#include "math.h"

#ifndef POINT_N_CLICK_CAMERA_DEADZONE
#define POINT_N_CLICK_CAMERA_DEADZONE 24
#endif

UBYTE last_hit_trigger = MAX_TRIGGERS;

void pointnclick_init(void) BANKED {
    camera_offset_x_sp = PX_TO_SUBPX(0);
    camera_offset_y_sp = PX_TO_SUBPX(0);
    camera_deadzone_x_sp = PX_TO_SUBPX(POINT_N_CLICK_CAMERA_DEADZONE);
    camera_deadzone_y_sp = PX_TO_SUBPX(POINT_N_CLICK_CAMERA_DEADZONE);
    PLAYER.dir = DIR_RIGHT;
    actor_set_anim(&PLAYER, ANIM_CURSOR);
}

void pointnclick_update(void) BANKED {
    UBYTE angle, hit_trigger, is_hover_trigger, is_hover_actor;
    actor_t *hit_actor;

    player_moving = FALSE;

    // Handle input
    if (INPUT_LEFT) {
        player_moving = TRUE;
        if (INPUT_UP) {
            angle = ANGLE_315DEG;
        } else if (INPUT_DOWN) {
            angle = ANGLE_225DEG;
        } else {
            angle = ANGLE_270DEG;
        }
    } else if (INPUT_RIGHT) {
        player_moving = TRUE;
        if (INPUT_UP) {
            angle = ANGLE_45DEG;
        } else if (INPUT_DOWN) {
            angle = ANGLE_135DEG;
        } else {
            angle = ANGLE_90DEG;
        }
    } else if (INPUT_UP) {
        player_moving = TRUE;
        angle = ANGLE_0DEG;
    } else if (INPUT_DOWN) {
        player_moving = TRUE;
        angle = ANGLE_180DEG;
    } else {
        angle = ANGLE_0DEG;
    }

    // Move cursor
    if (player_moving) {
        point_translate_angle(&(PLAYER.pos), angle, PLAYER.move_speed);
        // Clamp X
        if (SUBPX_TO_PX(PLAYER.pos.x) - PLAYER.bounds.left > image_width) {
            PLAYER.pos.x = PX_TO_SUBPX(PLAYER.bounds.left);
        } else if (SUBPX_TO_PX(PLAYER.pos.x) + PLAYER.bounds.right > image_width) {
            PLAYER.pos.x = PX_TO_SUBPX(image_width - PLAYER.bounds.right);
        }
        // Clamp Y
        if (SUBPX_TO_PX(PLAYER.pos.y) + PLAYER.bounds.top > image_height) {
            PLAYER.pos.y = -PX_TO_SUBPX(PLAYER.bounds.top);
        } else if (SUBPX_TO_PX(PLAYER.pos.y) + PLAYER.bounds.bottom > image_height) {
            PLAYER.pos.y = PX_TO_SUBPX(image_height - PLAYER.bounds.bottom);
        }
        actor_update_bounds_sp(&PLAYER);
    }

    // Check for trigger collisions
    hit_trigger = trigger_at_intersection(&PLAYER.bounds_sp);

    // Check for actor collisions
    hit_actor = actor_overlapping_player(FALSE);

    is_hover_trigger = (hit_trigger != NO_TRIGGER_COLLISON)
        && (triggers[hit_trigger].script.bank);

    is_hover_actor = hit_actor && hit_actor->script.bank;

    // Set cursor animation
    if (is_hover_trigger || is_hover_actor) {
        actor_set_anim(&PLAYER, ANIM_CURSOR_HOVER);
    } else {
        actor_set_anim(&PLAYER, ANIM_CURSOR);
    }

    if (INPUT_A_PRESSED) {
        player_moving = FALSE;
        if (is_hover_actor) {
            // Run actor script
            script_execute(hit_actor->script.bank, hit_actor->script.ptr, 0, 1, 0);
        }
        else if (is_hover_trigger) {
            // Run trigger script
            trigger_interact(hit_trigger);
        }
    }
}
