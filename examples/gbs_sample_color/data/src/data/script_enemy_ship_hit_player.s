.module script_enemy_ship_hit_player

.include "vm.i"
.include "data/game_globals.i"

.globl b_camera_shake_frames, _camera_shake_frames

.area _CODE_255

.LOCAL_TMP0_CAMERA_SHAKE_ARGS = -2

___bank_script_enemy_ship_hit_player = 255
.globl ___bank_script_enemy_ship_hit_player

_script_enemy_ship_hit_player::
        VM_RESERVE              2

        ; Camera Shake
        VM_SET_CONST            .LOCAL_TMP0_CAMERA_SHAKE_ARGS, 30
        VM_SET_CONST            ^/(.LOCAL_TMP0_CAMERA_SHAKE_ARGS + 1)/, .CAMERA_SHAKE_X
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 0, .LOCAL_TMP0_CAMERA_SHAKE_ARGS

        ; Sound Play Crash
        ;VM_SOUND_PLAY           30, 4, 0x01, 0xF2, 0x13, 0x80, 0x00
        VM_RESERVE              -2
        VM_RET_FAR
