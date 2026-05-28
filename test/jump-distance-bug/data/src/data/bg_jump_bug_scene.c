#pragma bank 255

// Background: Jump_Bug_Scene

#include "gbs_types.h"
#include "data/bg_jump_bug_scene_tileset.h"
#include "data/bg_jump_bug_scene_tilemap.h"

BANKREF(bg_jump_bug_scene)

const struct background_t bg_jump_bug_scene = {
    .width = 20,
    .height = 18,
    .tileset = TO_FAR_PTR_T(bg_jump_bug_scene_tileset),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(bg_jump_bug_scene_tilemap),
    .cgb_tilemap_attr = { NULL, NULL }
};
