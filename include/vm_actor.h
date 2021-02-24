#ifndef _VM_ACTOR_H_INCLUDE
#define _VM_ACTOR_H_INCLUDE

#include "vm.h"
#include "gbs_types.h"

void vm_actor_move_to(SCRIPT_CTX * THIS, INT16 idx) __banked;
void vm_actor_activate(SCRIPT_CTX * THIS, INT16 idx) __banked;
void vm_actor_set_dir(SCRIPT_CTX * THIS, INT16 idx, direction_e dir) __banked;
void vm_actor_deactivate(SCRIPT_CTX * THIS, INT16 idx) __banked;
void vm_actor_set_anim(SCRIPT_CTX * THIS, INT16 idx, INT16 idx_anim) __banked;
void vm_actor_set_pos(SCRIPT_CTX * THIS, INT16 idx) __banked;
void vm_actor_emote(SCRIPT_CTX * THIS, INT16 idx, UBYTE emote_sprite_bank, spritesheet_t *emote_sprite) __banked;
void vm_actor_set_bounds(SCRIPT_CTX * THIS, INT16 idx, BYTE left, BYTE right, BYTE top, BYTE bottom) __banked;
void vm_actor_set_spritesheet(SCRIPT_CTX * THIS, INT16 idx, UBYTE spritesheet_bank, const spritesheet_t *spritesheet) __banked;
void vm_actor_replace_tile(SCRIPT_CTX * THIS, INT16 idx, UBYTE target_tile, UBYTE tileset_bank, const tileset_t * tileset, UBYTE start_tile, UBYTE length) __banked;

#endif