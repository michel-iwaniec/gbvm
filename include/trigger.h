#ifndef TRIGGER_H
#define TRIGGER_H

#include <gbdk/platform.h>

#include "gbs_types.h"
#include "math.h"
#include "actor.h"

#define MAX_TRIGGERS 31
#define MAX_ACTIVE_TRIGGERS 11
#define NO_TRIGGER_COLLISON 0xFF

extern trigger_t triggers[MAX_TRIGGERS];
extern UBYTE triggers_len;

/**
 * Resets trigger collision flags on scene start
 */
void trigger_reset(void) BANKED;

/**
 * Find trigger at tile {tx,ty}
 *
 * @param tx Left tile
 * @param ty Top tile
 * @return tile index or NO_TRIGGER_COLLISON if not found
 */
UBYTE trigger_at_tile(UBYTE tx_a, UBYTE ty_a) BANKED;

/**
 * Run script for trigger specified trigger
 *
 * @param i Trigger index
 */
void trigger_interact(UBYTE i) BANKED;

/**
 * Run script for trigger at tile {tx,ty} if this tile was the
 * most recently activated trigger tile don't reactivate
 * (i.e. player must move to another tile first)
 *
 * @param tx Left tile
 * @param ty Top tile
 * @param force Force trigger to activate without changing tile
 */
UBYTE trigger_activate_at(UBYTE tx, UBYTE ty, UBYTE force) BANKED;

// gbdk-nes: Specialization that hard-codes PLAYER for bb and offset (as this is the only current use-case)
UBYTE trigger_activate_at_intersection_PLAYER(UBYTE force) BANKED;

// gbdk-nes: Changed to inline function, as it is only called from two banked functions
inline UBYTE trigger_at_intersection(bounding_box_16_t *bb_x16, point16_t *offset) {
    UBYTE tile_left   = (offset->x + bb_x16->left)   >> 7;
    UBYTE tile_right  = (offset->x + bb_x16->right)  >> 7;
    UBYTE tile_top    = (offset->y + bb_x16->top)    >> 7;
    UBYTE tile_bottom = (offset->y + bb_x16->bottom) >> 7;
    UBYTE i;

    for (i = 0; i != triggers_len; i++) {
        UBYTE trigger_left   = triggers[i].x;
        UBYTE trigger_top    = triggers[i].y;
        UBYTE trigger_right  = triggers[i].x + triggers[i].width - 1;
        UBYTE trigger_bottom = triggers[i].y + triggers[i].height - 1;

        if ((tile_left <= trigger_right)
            && (tile_right >= trigger_left)
            && (tile_top <= trigger_bottom)
            && (tile_bottom >= trigger_top)) {
                return i;
        }
    }

    return NO_TRIGGER_COLLISON;
}


// gbdk-nes: Special version for PLAYER only (and the only one actually called by the modules)
inline UBYTE trigger_at_intersection_PLAYER() {
    UBYTE tile_left   = (PLAYER.pos.x + PLAYER.bounds_x16.left) >> 7;
    UBYTE tile_right  = (PLAYER.pos.x + PLAYER.bounds_x16.right) >> 7;
    UBYTE tile_top    = (PLAYER.pos.y + PLAYER.bounds_x16.top) >> 7;
    UBYTE tile_bottom = (PLAYER.pos.y + PLAYER.bounds_x16.bottom) >> 7;
    UBYTE i;

    for (i = 0; i != triggers_len; i++) {
        UBYTE trigger_left   = triggers[i].x;
        UBYTE trigger_top    = triggers[i].y;
        UBYTE trigger_right  = triggers[i].x + triggers[i].width - 1;
        UBYTE trigger_bottom = triggers[i].y + triggers[i].height - 1;

        if ((tile_left <= trigger_right)
            && (tile_right >= trigger_left)
            && (tile_top <= trigger_bottom)
            && (tile_bottom >= trigger_top)) {
                return i;
        }
    }

    return NO_TRIGGER_COLLISON;
}

#endif
