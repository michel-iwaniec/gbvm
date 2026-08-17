    .module     vm_a
    .include    "global.s"

    .area   _CODE

; terminate the unit test
; void vm_test_terminate(SCRIPT_CTX * THIS, UBYTE flags) OLDCALL BANKED
_vm_test_terminate::
        and #1
        call nz, _vsync
        ld b, b
        ret

; call native function by far pointer;
; void vm_call_native(DUMMY0_t dummy0, DUMMY1_t dummy1, SCRIPT_CTX * THIS, UINT8 bank, const void * ptr) OLDCALL NONBANKED NAKED
_vm_call_native::
        ldhl sp, #8
        ld a, (hl+)
        ldh (__current_bank), a
        ld (_rROMB0), a
        ld a, (hl+)
        ld h, (hl)
        ld l, a
        jp (hl)

; call the inlined native code by THIS->PC
; void vm_asm(DUMMY0_t dummy0, DUMMY1_t dummy1, SCRIPT_CTX * THIS) OLDCALL NONBANKED NAKED
_vm_asm::
        ldhl sp, #6
        ld a, (hl+)
        ld h, (hl)
        ld l, a                 ; hl contains THIS

        push hl

        inc hl
        inc hl
        ld a, (hl-)             ; a contains THIS->bank
        ldh (__current_bank), a
        ld (_rROMB0), a         ; switch bank with script
        ld a, (hl-)
        ld l, (hl)
        ld h, a                 ; hl contains THIS->PC

        rst 0x20                ; call hl, new PC returned on stack

        pop de                  ; de contains the new PC

        pop hl                  ; hl contains THIS

        ld (hl), e
        inc hl
        ld (hl), d              ; save new PC to THIS->PC
        ret

; executes one step in the passed context
; return zero if script end
; VM_STEP must not be called from outside, but not declared static, because the symbol address is required for the GBStudio debugger
; UBYTE VM_STEP(SCRIPT_CTX * CTX) NAKED NONBANKED STEP_FUNC_ATTR

    .area _HRAM
current_fn_bank:    .ds 1
current_fn_nargs:   .ds 1

    .area _DATA
current_sp:         .ds 2

    .area _CODE
_VM_STEP::
        ld b, d
        ld c, e                 ; bc = THIS

        ld a, (de)
        ld l, a
        inc de
        ld a, (de)
        ld h, a                 ; hl offset of the script
        inc de

        ld a, (de)              ; bank of the script
        ldh (__current_bank), a
        ld (_rROMB0), a         ; switch bank with vm code

        ld a, (hl+)             ; load current instruction and return if terminator
        or a
        ret z                   ; exit if VM_STOP encountered

        ld (current_sp), sp

        push bc                 ; store bc == THIS
        push hl

        ld h, #0
        ld l, a
        add hl, hl
        add hl, hl              ; hl = instruction * sizeof(SCRIPT_CMD)
        dec hl
        ld de, #_script_cmds
        add hl, de              ; hl = &script_cmds[instruction].args_len

        ld a, (hl-)
        ldh (current_fn_nargs), a
        ld a, (hl-)
        ldh (current_fn_bank), a
        ld a, (hl-)
        ld b, a
        ld c, (hl)              ; bc = fn

        pop hl                  ; hl points to the next VM instruction or a first byte of the args
        ldh a, (current_fn_nargs)
        srl a
        jr nc, 4$               ; d is even?
        ld d, (hl)              ; copy one arg onto stack
        inc hl
        push de
        inc sp
4$:
        jr z, 1$                ; only one arg?
2$:
        ld d, (hl)
        inc hl
        ld e, (hl)
        inc hl
        push de
        dec a
        jr nz, 2$               ; loop through remaining args, copy 2 bytes at a time
1$:
        ld d, h
        ld e, l                 ; de points to the next VM instruction

        ld hl, #current_sp
        ld a, (hl+)
        ld h, (hl)
        ld l, a
        dec hl

        ld a, (hl-)
        ld l, (hl)
        ld h, a                 ; hl = THIS

        push hl                 ; pushing THIS

        ld a, e
        ld (hl+), a
        ld (hl), d              ; PC = PC + sizeof(instruction) + args_len

        ld hl, #current_sp
        ld a, (hl+)
        ld h, (hl)
        ld l, a
        push hl                 ; not used
        push hl                 ; SP to restore

        ldh a, (current_fn_bank)   ; a = script_bank
        ldh (__current_bank), a
        ld (_rROMB0), a         ; switch bank with functions

        ld h, b                 ; restore function pointer
        ld l, c
        rst 0x20                ; call hl

        pop hl
        ld sp, hl

        ld a, #1                ; instruction executed
        ret
