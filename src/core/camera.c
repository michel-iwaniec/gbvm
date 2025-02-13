#pragma bank 255

#include "camera.h"

#include "actor.h"

#define CAMERA_FIXED_OFFSET_X 128
#define CAMERA_FIXED_OFFSET_Y 128

UINT16 camera_x;
UINT16 camera_y;
INT16 camera_offset_x_sp;
INT16 camera_offset_y_sp;
INT16 camera_deadzone_x_sp;
INT16 camera_deadzone_y_sp;
UBYTE camera_settings;

void camera_init(void) BANKED {
    camera_settings = CAMERA_LOCK_FLAG;
    camera_x = camera_y = 0;
    camera_offset_x_sp = camera_offset_y_sp = 0;
    camera_reset();
}

void camera_update(void) NONBANKED {
    if ((camera_settings & CAMERA_LOCK_X_FLAG)) {
        UWORD a_x = PLAYER.pos.x + CAMERA_FIXED_OFFSET_X;
        // Horizontal lock
        if (camera_x < a_x - camera_deadzone_x_sp - camera_offset_x_sp) { 
            camera_x = a_x - camera_deadzone_x_sp - camera_offset_x_sp;
        } else if (camera_x > a_x + camera_deadzone_x_sp - camera_offset_x_sp) { 
            camera_x = a_x + camera_deadzone_x_sp - camera_offset_x_sp;
        }
    }

    if ((camera_settings & CAMERA_LOCK_Y_FLAG)) {
        UWORD a_y = PLAYER.pos.y + CAMERA_FIXED_OFFSET_Y;
        // Vertical lock
        if (camera_y < a_y - camera_deadzone_y_sp - camera_offset_y_sp) { 
            camera_y = a_y - camera_deadzone_y_sp - camera_offset_y_sp;
        } else if (camera_y > a_y + camera_deadzone_y_sp - camera_offset_y_sp) { 
            camera_y = a_y + camera_deadzone_y_sp - camera_offset_y_sp;
        }
    }
}
