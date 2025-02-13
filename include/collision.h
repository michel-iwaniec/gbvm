#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <gbdk/platform.h>

#include "math.h"
#include "bankdata.h"

#define COLLISION_TOP 0x1
#define COLLISION_BOTTOM 0x2
#define COLLISION_LEFT 0x4
#define COLLISION_RIGHT 0x8
#define COLLISION_ALL 0xF
#define TILE_PROP_LADDER 0x10

extern UBYTE collision_bank;
extern unsigned char *collision_ptr;
extern UBYTE image_tile_width;
extern UBYTE image_tile_height;

/**
 * Check if point is within bounding box.
 *
 * @param bb Pointer to bounding box
 * @param point Pointer to position to look for within bounding box
 * @return Point is within bounding box
 */
inline UBYTE bb_contains(bounding_box_16_t *bb_sp, point16_t *point) {
    if ((point->x < bb_sp->left) || 
        (point->x > bb_sp->right)) return FALSE;
    if ((point->y < bb_sp->top) || 
        (point->y > bb_sp->bottom)) return FALSE;
    return TRUE;
}

/**
 * Check if two bounding boxes intersect.
 *
 * @param bb_a Pointer to bounding box A
 * @param bb_b Pointer to bounding box B
 * @return Positioned bounding boxes intersect
 */
inline UBYTE bb_intersects(bounding_box_16_t *bb_sp_a, bounding_box_16_t *bb_sp_b) {
    if ((bb_sp_b->left   > bb_sp_a->right) ||
        (bb_sp_b->right  < bb_sp_a->left)) return FALSE;
    if ((bb_sp_b->top    > bb_sp_a->bottom) ||
        (bb_sp_b->bottom < bb_sp_a->top)) return FALSE;
    return TRUE;
}

/**
 * Return collision tile value at given tile x,y coordinate.
 *
 * @param tx Left tile
 * @param ty Top tile
 * @return Tile value, 0 if no collisions, COLLISION_ALL if out of bounds
 */
inline UBYTE tile_at(UBYTE tx, UBYTE ty) {
    if ((tx < image_tile_width) && (ty < image_tile_height)) 
        return ReadBankedUBYTE(collision_ptr + (ty * (UINT16)image_tile_width) + tx, collision_bank);
    return COLLISION_ALL;
}

#endif
