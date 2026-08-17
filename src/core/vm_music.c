#pragma bank 255

#include <stdarg.h>

#include "vm_music.h"
#include "music_manager.h"

BANKREF(VM_MUSIC)

void vm_music_play(SCRIPT_CTX * THIS, UBYTE track_bank, const TRACK_T * track) VM_CALL {
    THIS;
    music_effective_mute = driver_set_mute_mask((music_global_mute_mask = MUTE_MASK_NONE) | music_mute_mask);
    music_load(track_bank, track);
}

void vm_music_stop(void) VM_CALL {
    music_stop();
}

void vm_music_mute(SCRIPT_CTX * THIS, UBYTE channels) VM_CALL {
    THIS;
    music_effective_mute = driver_set_mute_mask(music_sound_cut_mask(music_global_mute_mask = channels) | music_mute_mask);
}

void vm_music_routine(SCRIPT_CTX * THIS, UBYTE routine, UBYTE bank, UBYTE * pc) VM_CALL {
    THIS;
    script_event_t * event = &music_events[routine & 0x03];
    event->script_bank = bank;
    event->script_addr = pc;
}

void vm_music_setpos(SCRIPT_CTX * THIS, UBYTE pattern, UBYTE row) VM_CALL {
    THIS;
    CRITICAL {
        music_setpos(pattern, row);
    }
}

void vm_sound_mastervol(SCRIPT_CTX * THIS, UBYTE volume) VM_CALL {
    THIS;
    NR50_REG = volume;
}

void vm_sfx_play(SCRIPT_CTX * THIS, UBYTE bank, UBYTE * offset, UBYTE channel_mask, UBYTE priority) VM_CALL {
    THIS;
    music_play_sfx(bank, offset, channel_mask, priority);
}
