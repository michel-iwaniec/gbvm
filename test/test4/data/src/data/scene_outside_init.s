.module scene_outside_init

.include "vm.i"
.include "data/game_globals.i"

.globl _fade_frames_per_step

.area _CODE_255


___bank_scene_outside_init = 255
.globl ___bank_scene_outside_init

_scene_outside_init::
        VM_LOCK

GBVM$scene_outside_init$autofade$94c18861_b352_4f49_a64d_52f2e3415077$scene$94c18861_b352_4f49_a64d_52f2e3415077$script = .
.globl GBVM$scene_outside_init$autofade$94c18861_b352_4f49_a64d_52f2e3415077$scene$94c18861_b352_4f49_a64d_52f2e3415077$script
        ; Wait 1 Frames
        VM_IDLE

        ; Fade In
        VM_SET_CONST_INT8       _fade_frames_per_step, 1
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
