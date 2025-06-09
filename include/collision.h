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
 * Check if point is within positioned bounding box.
 *
 * @param bb Pointer to bounding box
 * @param offset Pointer to position offset for bounding box (e.g Actor position)
 * @param point Pointer to position to look for within bounding box
 * @return Point is within bounding box
 */
inline UBYTE bb_contains(bounding_box_16_t *bb, point16_t *offset, point16_t *point) {
    if ((point->x < offset->x + bb->left) || 
        (point->x > offset->x + bb->right)) return FALSE;
    if ((point->y < offset->y + bb->top) || 
        (point->y > offset->y + bb->bottom)) return FALSE;
    return TRUE;
}

/**
 * Check if two positioned bounding boxes intersect.
 *
 * @param bb_a Pointer to bounding box A
 * @param offset_a Pointer to position offset for bounding box A
 * @param bb_b Pointer to bounding box B
 * @param offset_b Pointer to position offset for bounding box B
 * @return Positioned bounding boxes intersect
 */
inline UBYTE bb_intersects(bounding_box_16_t *bb_a, upoint16_t *offset_a, bounding_box_16_t *bb_b, upoint16_t *offset_b) {
    if ((offset_b->x + bb_b->left   > offset_a->x + bb_a->right) ||
        (offset_b->x + bb_b->right  < offset_a->x + bb_a->left)) return FALSE;
    if ((offset_b->y + bb_b->top    > offset_a->y + bb_a->bottom) ||
        (offset_b->y + bb_b->bottom < offset_a->y + bb_a->top)) return FALSE;
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
