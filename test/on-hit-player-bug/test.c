#include "core.h"
#include "test_main.h"
#include <string.h>

void core_reset_hook(void) { core_reset(); }

void test(void) {
  strcpy(result, "PASSED");
  core_run();
}
