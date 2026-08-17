#include "core.h"
#include "test_main.h"

UBYTE reset_count = 2;
void core_reset_hook(void) {
    if (reset_count) reset_count--; else TERMINATE_TEST;
    core_reset();
}

void test(void) {
    core_run();
}
