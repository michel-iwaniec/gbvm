#ifndef PROJECTILES_H
#define PROJECTILES_H

#include <gbdk/platform.h>

#include "math.h"
#include "collision.h"
#include "gbs_types.h"

#define MAX_PROJECTILES 5
#define MAX_PROJECTILE_DEFS 5

extern projectile_def_t projectile_defs[MAX_PROJECTILES];

void projectiles_init(void) BANKED;
void projectiles_update(void) NONBANKED;
void projectiles_render(void) NONBANKED;

void projectile_launch(UBYTE index, point16_t *pos, UBYTE angle) BANKED;

inline void projectile_update_bounds_sp(projectile_t* projectile)
{
    projectile->bounds_sp.left = projectile->pos.x + PX_TO_SUBPX(projectile->def.bounds.left);
    projectile->bounds_sp.right = projectile->pos.x + PX_TO_SUBPX(projectile->def.bounds.right);
    projectile->bounds_sp.top = projectile->pos.y + PX_TO_SUBPX(projectile->def.bounds.top);
    projectile->bounds_sp.bottom = projectile->pos.y + PX_TO_SUBPX(projectile->def.bounds.bottom);
}

#endif
