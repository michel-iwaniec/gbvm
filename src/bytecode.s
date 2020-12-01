.include "vm.inc"
        
.globl b_wait_frames, _wait_frames

.area _CODE_3

___bank_BYTECODE = 3
.globl ___bank_BYTECODE

_BYTECODE::
        VM_RESERVE      2               ; reserve 2 words for globals
        VM_SET_CONST    0, 2            ; set global[0] to 2
        
        VM_RPN
        .db .TYP_B, 5, .TYP_B, 3, "-", .TYP_REF, 0, "+", .TYP_B, -2, "+", .RPN_STOP   ; push(5 - 3 + global[0] + -2) == 2

        VM_SET          1, -1           ; set global[1] to *(SP-1)

        VM_DEBUG        3               ; printf("0:%d 1:%d -1:%d\n", global[0], global[1], *(SP-1));
        .db 0, 1, -1
        .asciz "0:%d 1:%d -1:%d"        ; debug string may be embedded into the code

        VM_IF .EQ       0, 1, 1$, 0     ; compare global[0] with global[1]; jump to 1$ if EQUAL; don't cleanup stack
        VM_DEBUG        0
         .asciz "!ERROR!"
        VM_STOP
1$:    
        VM_CALL_REL     2$
        VM_LOOP_REL     1$              ; test loop 

        VM_BEGINTHREAD  ___bank_THREAD1, _THREAD1

        VM_PUSH         3               ; value A to compare
        VM_PUSH         3               ; value B to compare

        VM_PUSHVALUE    -2              ; test pushvalue, value == 3 must be pushed
5$:    
        VM_LOOP_REL     5$

        VM_IF .EQ       -1, -2, 3$, 2   ; compare *(SP-1) with *(SP-2); jump to 3$ if EQUAL; cleanup 2 arguments from stack
        VM_DEBUG        0
        .asciz "Not equal"
        VM_JUMP_REL     4$
3$:     
        VM_DEBUG        0
        .asciz "Equal"
4$:
        VM_CALL_FAR     ___bank_libfuncs, _LIBFUNC01
        VM_DEBUG        0
        .asciz "Main terminated"
        VM_STOP
2$:
        VM_DEBUG        0
        .asciz "Hello, world!"
        VM_PUSH         60              ; 90 frames == 1,5s
        VM_INVOKE       b_wait_frames, _wait_frames, 1
        VM_RET

___bank_THREAD1 = 3
_THREAD1::
        VM_DEBUG        0
        .asciz "Thread started"
        VM_PUSH         90              ; 60 frames == 1s
        VM_INVOKE       b_wait_frames, _wait_frames, 1
        VM_CALL_FAR     ___bank_libfuncs, _LIBFUNC01
        VM_DEBUG        0
        .asciz "Thread terminated"
        VM_STOP

.area _CODE_1

___bank_libfuncs = 1
.globl ___bank_libfuncs

_LIBFUNC01::
        VM_DEBUG        0
        .asciz "LIBFUNC01()"
        VM_RET_FAR
