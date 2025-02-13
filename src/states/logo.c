#pragma bank 255

#include "data/states_defines.h"
#include "states/logo.h"

#include "camera.h"
#include "game_time.h"
#include "math.h"

void logo_init(void) BANKED {
  camera_offset_x_sp = PX_TO_SUBPX(0);
  camera_offset_y_sp = PX_TO_SUBPX(0);

  game_time = 0;
}

void logo_update(void) BANKED {
    return;
}
