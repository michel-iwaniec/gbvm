.module scene_dmg_init

.include "vm.i"
.include "data/game_globals.i"

.globl _fade_frames_per_step

.area _CODE_255


___bank_scene_dmg_init = 255
.globl ___bank_scene_dmg_init

_scene_dmg_init::
        VM_LOCK

        ; Input Script Attach
        VM_CONTEXT_PREPARE      1, ___bank_script_input, _script_input
        VM_INPUT_ATTACH         128, ^/(1 | .OVERRIDE_DEFAULT)/

        ; Wait 1 Frames
        VM_IDLE

        ; Fade In
        VM_SET_CONST_INT8       _fade_frames_per_step, 1
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
