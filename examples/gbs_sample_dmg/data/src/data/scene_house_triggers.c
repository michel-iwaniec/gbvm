#pragma bank 255

// Scene: House
// Triggers

#include "gbs_types.h"
#include "data/trigger_4_interact.h"

BANKREF(scene_house_triggers)

const struct trigger_t scene_house_triggers[] = {
    {
        // Trigger 1,
        .left = 9,
        .top = 16,
        .right = 10,
        .bottom = 16,
        .script = TO_FAR_PTR_T(trigger_4_interact),
        .script_flags = TRIGGER_HAS_ENTER_SCRIPT
    }
};
