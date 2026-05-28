.module scene_13_init

.include "vm.i"
.include "data/game_globals.i"

.globl _fade_frames_per_step

.area _CODE_255


___bank_scene_13_init = 255
.globl ___bank_scene_13_init

_scene_13_init::
        VM_LOCK

        ; Set Sprite Mode: 8x16
        VM_SET_SPRITE_MODE      .MODE_8X16

GBVM$scene_13_init$autofade$8fbb50ad_b1db_4351_8f12_2958aec3ae46$scene$8fbb50ad_b1db_4351_8f12_2958aec3ae46$script = .
.globl GBVM$scene_13_init$autofade$8fbb50ad_b1db_4351_8f12_2958aec3ae46$scene$8fbb50ad_b1db_4351_8f12_2958aec3ae46$script
        ; Idle
        VM_IDLE

        ; Fade In
        VM_SET_CONST_INT8       _fade_frames_per_step, 1
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
