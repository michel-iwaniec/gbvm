.include "vm.i"
.include "data/game_globals.i"
.include "global.s"

.globl b_wait_frames, _wait_frames

.area _CODE_255

___bank_script_s1_init = 255
.globl ___bank_script_s1_init

_script_s1_init::
        VM_LOCK

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Input Script Attach
        VM_CONTEXT_PREPARE      1, ___bank_script_input_0, _script_input_0
        VM_INPUT_ATTACH         ^/.START/, 1

        ; Input Script Attach
        VM_CONTEXT_PREPARE      3, ___bank_script_input_1, _script_input_1
        VM_INPUT_ATTACH         ^/.B/, 3

        ; Input Script Attach
        VM_CONTEXT_PREPARE      4, ___bank_script_input_2, _script_input_2
        VM_INPUT_ATTACH         ^/.A/, 4

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Welcome!\nA: Make money\nB: Spend money\nStart: Menu"
        VM_OVERLAY_CLEAR        0, 0, 20, 6, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 12, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Stop Script
        VM_STOP
