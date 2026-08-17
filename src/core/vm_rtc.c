#pragma bank 255

#include "vm_rtc.h"

#include "vm.h"

#include "rtc.h"

BANKREF(VM_RTC)

void vm_rtc_latch(void) VM_CALL {
    RTC_LATCH();
}

void vm_rtc_get(SCRIPT_CTX * THIS, INT16 idx, UBYTE what) VM_CALL {
    INT16 * res = VM_REF_TO_PTR(idx);
    *res = RTC_GET((rtc_dateparts_e)((what & 0x03) + RTC_VALUE_SEC));
}

void vm_rtc_set(SCRIPT_CTX * THIS, INT16 idx, UBYTE what) VM_CALL {
    INT16 * res = VM_REF_TO_PTR(idx);
    RTC_SET((rtc_dateparts_e)((what & 0x03) + RTC_VALUE_SEC), (UWORD)*res);
}

void vm_rtc_start(SCRIPT_CTX * THIS, UBYTE start) VM_CALL {
    THIS;
    RTC_START(start);
}
