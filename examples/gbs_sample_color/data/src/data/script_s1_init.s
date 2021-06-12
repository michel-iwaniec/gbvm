.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

___bank_script_s1_init = 255
.globl ___bank_script_s1_init

_script_s1_init::
        VM_LOCK

        ; Call Script: Init Menu
        VM_CALL_FAR             ___bank_script_init_menu, _script_init_menu

        ; Music Play
        VM_MUSIC_PLAY           ___bank_music_track_5__Data, _music_track_5__Data, .MUSIC_LOOP

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
