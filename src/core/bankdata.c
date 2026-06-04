#include <gbdk/platform.h>
#include <string.h>

#include "compat.h"
#include "bankdata.h"

static FASTUBYTE _save;    // functions below are not reentrant

void MemcpyBanked(void* to, const void* from, size_t n, UBYTE bank) NONBANKED {
    _save = CURRENT_BANK;
    SWITCH_ROM(bank);
    memcpy(to, from, n);
    SWITCH_ROM(_save);
}

void MemcpyVRAMBanked(void* to, const void* from, size_t n, UBYTE bank) NONBANKED {
    _save = CURRENT_BANK;
    SWITCH_ROM(bank);
    set_data(to, from, n);
    SWITCH_ROM(_save);
}

UBYTE IndexOfFarPtr(const far_ptr_t * list, UBYTE bank, UBYTE count, const far_ptr_t * item) NONBANKED {
    far_ptr_t v;
    for (UBYTE i = 0; i != count; i++, list++) {
        ReadBankedFarPtr(&v, (void *)list, bank);
        if ((v.bank == item->bank) && (v.ptr == item->ptr)) return i;
    }
    return count;
}
