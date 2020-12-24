#pragma bank 255

// Scene: Scene 3

#include "data/data_types.h"
#include "data/background_1.h"
#include "data/scene_2_collisions.h"
#include "data/scene_2_colors.h"
#include "data/palette_2.h"
#include "data/palette_0.h"
#include "data/scene_2_actors.h"
#include "data/scene_2_triggers.h"
#include "data/scene_2_sprites.h"

const void __at(255) __bank_scene_2;

const struct scene_t scene_2 = {
  .width = 32,
  .height = 32,
  .type = 0,
  .background = TO_FAR_PTR_T(background_1),
  .collisions = TO_FAR_PTR_T(scene_2_collisions),
  .colors = TO_FAR_PTR_T(scene_2_colors),
  .palette = TO_FAR_PTR_T(palette_2),
  .sprite_palette = TO_FAR_PTR_T(palette_0),
  .n_actors = 1,
  .n_triggers = 2,
  .n_sprites = 1,
  .actors = TO_FAR_PTR_T(scene_2_actors),
  .triggers = TO_FAR_PTR_T(scene_2_triggers),
  .sprites = TO_FAR_PTR_T(scene_2_sprites)
};