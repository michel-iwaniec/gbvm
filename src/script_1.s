.include "vm.inc"
        
.globl b_wait_frames, _wait_frames
; .globl b_vm_actor_activate, _vm_actor_activate
; .globl b_vm_actor_set_dir, _vm_actor_set_dir

.area _CODE_3

___bank_SCRIPT_1 = 3
.globl ___bank_SCRIPT_1

_SCRIPT_1::
        ; init some variables on stack
        VM_RPN
            .R_INT8 'f'
            .R_INT8 'o'
            .R_INT8 'x'
            .R_INT8 'd'
            .R_INT8 'o'
            .R_INT8 'g'
            .R_INT8 10
            .R_STOP

        ; render text with all features
        VM_LOAD_TEXT            11
            .dw 4, 2, .ARG6, .ARG5, .ARG4, 5, .ARG3, .ARG2, .ARG1, 2, .ARG0
            .asciz "The %tquick%t red\n%c%c%c jumps over\nthe lazy brown\n%t%c%c%c%t %dx!"

        ; dispose variables on stack
        VM_POP                  7

        ; move window to 12 tiles by Y
        VM_OVERLAY_MOVE_TO      0, 12, 1

        ; start displaying text
        VM_DISPLAY_TEXT         1

        ; wait for window to slide
        VM_OVERLAY_WAIT

        VM_STOP
