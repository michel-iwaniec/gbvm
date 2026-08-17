#ifndef _VM_MUSIC_H_INCLUDE
#define _VM_MUSIC_H_INCLUDE

#include <gbdk/platform.h>

#include "vm.h"
#include "music_manager.h"

BANKREF_EXTERN(VM_MUSIC)

void vm_music_play(SCRIPT_CTX * THIS, UBYTE track_bank, const TRACK_T *track) VM_CALL;
void vm_music_stop(void) VM_CALL;
void vm_music_mute(SCRIPT_CTX * THIS, UBYTE channels) VM_CALL;
void vm_music_routine(SCRIPT_CTX * THIS, UBYTE routine, UBYTE bank, UBYTE * pc) VM_CALL;
void vm_music_setpos(SCRIPT_CTX * THIS, UBYTE pattern, UBYTE row) VM_CALL;

void vm_sound_mastervol(SCRIPT_CTX * THIS, UBYTE volume) VM_CALL;

void vm_sfx_play(SCRIPT_CTX * THIS, UBYTE bank, UBYTE * offset, UBYTE channel_mask, UBYTE priority) VM_CALL;

#endif