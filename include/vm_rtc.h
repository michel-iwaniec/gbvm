#ifndef _VM_RTC_H_INCLUDE
#define _VM_RTC_H_INCLUDE

#include <gbdk/platform.h>

#include "vm.h"

BANKREF_EXTERN(VM_RTC)

void vm_rtc_latch(void) VM_CALL;
void vm_rtc_get(SCRIPT_CTX * THIS, INT16 idx, UBYTE what) VM_CALL;
void vm_rtc_set(SCRIPT_CTX * THIS, INT16 idx, UBYTE what) VM_CALL;
void vm_rtc_start(SCRIPT_CTX * THIS, UBYTE start) VM_CALL;

#endif