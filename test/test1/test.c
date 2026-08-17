#include <gb/gb.h>
#include <string.h>

#include "framework/test_main.h"

void core_reset_hook(void) {}

void test(void) {
    strcpy(result, "PASSED"); 
    delay(100);
}
