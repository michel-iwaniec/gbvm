    .module     vm_a
    .include    "global.s"
    .ez80

    .area   _CODE

; terminate the unit test
; void vm_test_terminate(SCRIPT_CTX * THIS, UBYTE flags) OLDCALL BANKED
_vm_test_terminate::
        ld iy,#0
        add iy,sp
        ld a, 7(iy)
        and #1
        call nz, _vsync
        ld b, b
        ret

; call native function by far pointer;
; void vm_call_native(DUMMY0_t dummy0, DUMMY1_t dummy1, SCRIPT_CTX * THIS, UINT8 bank, const void * ptr) OLDCALL NONBANKED NAKED
_vm_call_native::
        ld iy,#0
        add iy,sp
        ld l, 5(iy)
        ld h, 6(iy)
        push hl
        ld e, 7(iy)
        ld l, 8(iy)
        ld h, 9(iy)
        call ___sdcc_bcall_ehl
        pop hl
        ret

; call the inlined native code by THIS->PC
; void vm_asm(DUMMY0_t dummy0, DUMMY1_t dummy1, SCRIPT_CTX * THIS) OLDCALL NONBANKED NAKED
_vm_asm::
        ld iy,#0
        add iy,sp
        ld e, 5(iy)
        ld d, 6(iy)
        push de
        ld iyh, d
        ld iyl, e

        ld a, 2(iy)             ; a contains THIS->bank
        ld (_MAP_FRAME1), a     ; switch bank with script
        ld e, 0(iy)
        ld d, 1(iy)

        ex de, hl
        rst  0x30

        pop de                  ; de contains the new PC

        pop iy                  ; iy contains THIS

        ld 0(iy), e
        ld 1(iy), d             ; save new PC to THIS->PC
        ret

; executes one step in the passed context
; return zero if script end
; VM_STEP must not be called from outside, but not declared static, because the symbol address is required for the GBStudio debugger
; UBYTE VM_STEP(SCRIPT_CTX * CTX) NAKED NONBANKED STEP_FUNC_ATTR
_VM_STEP::
        ex de, hl
        ld iyh, d
        ld iyl, e

        ld l, 0 (iy)
        ld h, 1 (iy)

        ld a, (_MAP_FRAME1)
        push af

        ld a, 2 (iy)
        ld (_MAP_FRAME1), a

        ld a, (hl)              ; load current command and return if terminator
        inc hl
        ld e, a
        or a
        jr z, 3$

        ld d, #0
        dec e

        ld b, h
        ld c, l                 ; save hl to bc

        ld h, d
        ld l, e

        add hl, hl
        add hl, hl              ; hl = de * sizeof(SCRIPT_CMD)

        ld de, #_script_cmds
        add hl, de              ; hl = &script_cmds[command]

        ld e, (hl)
        inc hl
        ld d, (hl)              ; de = fn
        inc hl
        ld a, (hl)
        ld (_current_fn_bank), a
        inc hl
        ld a, (hl)

        ld h, b
        ld l, c                 ; restore hl from bc
        ld c, a

        ld b, c                 ; b = c = args_len
        srl b
        jr nc, 4$               ; d is even?
        ld a, (hl)              ; copy one arg onto stack
        inc hl
        push af
        inc sp
4$:
        jr z, 1$                ; only one parameter?
2$:
        ld a, (hl)
        inc hl
        push af
        inc sp
        ld a, (hl)
        inc hl
        push af
        inc sp
        dec b
        jr nz, 2$               ; loop through remaining parameters, copy 2 bytes at a time
1$:

        ld 0 (iy), l
        ld 1 (iy), h            ; PC = PC + sizeof(instruction) + args_len

        push iy                 ; pushing THIS

        push bc                 ; bc: args_len
        dec sp                  ; not used

        ld a, (_current_fn_bank)    ; a = script_bank (all script functions in one bank: take any complimantary symbol)
        ld (_MAP_FRAME1), a     ; switch bank with functions

        ex de, hl
        rst  0x30

        inc sp

        pop hl                  ; hl: args_len
        pop de                  ; deallocate THIS
        add hl, sp
        ld sp, hl

        ld e, #1                ; command executed
3$:
        pop af
        ld (_MAP_FRAME1), a     ; restore bank

        ld l, e                 ; __z88dk_fastcall function must return result in l

        ret
