#pragma bank 2

#include <string.h>
#include <stdlib.h>

#include "vm.h"
#include "UI.h"

void ui_draw_frame(UBYTE x, UBYTE y, UBYTE width, UBYTE height) __banked;

// renders UI text into buffer
void vm_load_text(UWORD dummy0, UWORD dummy1, SCRIPT_CTX * THIS, UBYTE nargs) __nonbanked {
    dummy0; dummy1; // suppress warnings

    UBYTE _save = _current_bank;
    SWITCH_ROM_MBC1(THIS->bank);
    
    const UBYTE * args = THIS->PC;
    unsigned char * d = ui_text_data; 
    const unsigned char * s = args + (nargs << 1);
    INT16 idx;

    while (*s) {
        if (*s == '%') {
            s++;
            switch (*s) {
                // variable by index
                case 'd':
                    idx = *((INT16 *)args);
                    if (idx < 0) idx = *(THIS->stack_ptr + idx); else idx = script_memory[idx];
                    d += strlen(itoa(idx, d));
                    s++;
                    args += 2u;
                    continue;
                // char in variable
                case 'c':
                    idx = *((INT16 *)args);
                    if (idx < 0) idx = *(THIS->stack_ptr + idx); else idx = script_memory[idx];
                    *d++ = (unsigned char)idx;
                    s++;
                    args += 2u;
                    continue;
                // text tempo
                case 't':
                    *d++ = *((UINT8 *)args) + 0x10u;
                    s++;
                    args += 2u;
                    continue;
                case '%':
                    break;
                default:
                    s--;
            }
        }
        *d++ = *s++;
    }
    *d = 0, s++;

    SWITCH_ROM_MBC1(_save);
    THIS->PC = s;
}

// start displaying text
void vm_display_text(SCRIPT_CTX * THIS, UBYTE avatar_index) __banked {
    THIS;
    text_drawn = FALSE;
    text_wait = 0;
    text_num_lines = 3;
    avatar_enabled = (avatar_index != 0);
    ui_draw_frame(0, 0, 19, 4);
}

// set position of overlayed window
void vm_overlay_setpos(SCRIPT_CTX * THIS, UBYTE pos_x, UBYTE pos_y) __banked {
    THIS;
    ui_set_pos(pos_x << 3, pos_y << 3);
}

// hides overlayed window
void vm_overlay_hide() __banked {
    ui_set_pos(0, MENU_CLOSED_Y);
}

// wait until overlay window reaches destination
void vm_overlay_wait(SCRIPT_CTX * THIS) __banked {
    if ((win_pos_x != win_dest_pos_x) || (win_pos_y != win_dest_pos_y)) {
        THIS->waitable = 1;
        THIS->PC -= 1;
    }
}

// set position of overlayed window
void vm_overlay_move_to(SCRIPT_CTX * THIS, UBYTE pos_x, UBYTE pos_y, UBYTE speed) __banked {
    THIS;
    ui_move_to(pos_x << 3, pos_y << 3, speed);
}
