#ifndef _VM_GBPRINTER_H_INCLUDE
#define _VM_GBPRINTER_H_INCLUDE

#include <gbdk/platform.h>

#include "vm.h"

BANKREF_EXTERN(VM_GBPRINTER)

void vm_print_detect(SCRIPT_CTX * THIS, INT16 idx, UBYTE delay) VM_CALL;
void vm_print_overlay(SCRIPT_CTX * THIS, INT16 idx, UBYTE start, UBYTE height, UBYTE margins) VM_CALL;

#endif