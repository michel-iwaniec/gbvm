#include "core.h"
#include "test_main.h"

void core_reset_hook(void) {
    core_reset();
}

void test(void) {
    core_run();
}
