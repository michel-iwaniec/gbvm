#ifndef _VM_SCENE_H_INCLUDE
#define _VM_SCENE_H_INCLUDE

#include <gbdk/platform.h>

#include "vm.h"

BANKREF_EXTERN(VM_SCENE)

void vm_scene_push(void) VM_CALL;
void vm_scene_pop(void) VM_CALL;
void vm_scene_pop_all(void) VM_CALL;
void vm_scene_stack_reset(void) VM_CALL;

#endif