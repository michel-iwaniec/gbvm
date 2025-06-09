#pragma bank 255

#include "camera.h"

#include "actor.h"

#define CAMERA_FIXED_OFFSET_X 128
#define CAMERA_FIXED_OFFSET_Y 128

UINT16 camera_x;
UINT16 camera_y;
UINT16 camera_clamp_x;
UINT16 camera_clamp_y;
INT16 camera_offset_x_subpx;
INT16 camera_offset_y_subpx;
INT16 camera_deadzone_x_subpx;
INT16 camera_deadzone_y_subpx;
UBYTE camera_settings;

void camera_init(void) BANKED {
    camera_settings = CAMERA_LOCK_FLAG;
    camera_x = camera_y = 0;
    camera_offset_x_subpx = camera_offset_y_subpx = 0;
    camera_clamp_x = camera_clamp_y = 0;
    camera_reset();
}

void camera_update(void) BANKED {
    if (camera_settings & CAMERA_LOCK_X_FLAG)
    {
        UWORD target_pos = PLAYER.pos.x + CAMERA_FIXED_OFFSET_X;
        WORD tolerance = camera_deadzone_x_subpx + camera_offset_x_subpx;
        UWORD new_cam_pos = camera_x;

        if (new_cam_pos < target_pos - tolerance)
        {
            new_cam_pos = target_pos - tolerance;
            if ((camera_settings & CAMERA_LOCK_X_MAX_FLAG) && new_cam_pos > camera_clamp_x)
            {
                new_cam_pos = camera_clamp_x;
            }
        }
        else if (new_cam_pos > target_pos + tolerance)
        {
            new_cam_pos = target_pos + tolerance;
            if ((camera_settings & CAMERA_LOCK_X_MIN_FLAG) && new_cam_pos < camera_clamp_x)
            {
                new_cam_pos = camera_clamp_x;
            }
        }
        camera_x = camera_clamp_x = new_cam_pos;
    }

    if (camera_settings & CAMERA_LOCK_Y_FLAG)
    {
        UWORD target_pos = PLAYER.pos.y + CAMERA_FIXED_OFFSET_Y;
        WORD tolerance = camera_deadzone_y_subpx + camera_offset_y_subpx;
        UWORD new_cam_pos = camera_y;

        if (new_cam_pos < target_pos - tolerance)
        {
            new_cam_pos = target_pos - tolerance;
            if ((camera_settings & CAMERA_LOCK_Y_MAX_FLAG) && new_cam_pos > camera_clamp_y)
            {
                new_cam_pos = camera_clamp_y;
            }
        }
        else if (new_cam_pos > target_pos + tolerance)
        {
            new_cam_pos = target_pos + tolerance;
            if ((camera_settings & CAMERA_LOCK_Y_MIN_FLAG) && new_cam_pos < camera_clamp_y)
            {
                new_cam_pos = camera_clamp_y;
            }
        }
        camera_y = camera_clamp_y = new_cam_pos;
    }
}