#pragma bank 255

// Scene: Underground
// Triggers

#include "gbs_types.h"
#include "data/trigger_1_interact.h"
#include "data/trigger_2_interact.h"

BANKREF(scene_underground_triggers)

const struct trigger_t scene_underground_triggers[] = {
    {
        // Trigger 1,
        .left = 21,
        .top = 31,
        .right = 22,
        .bottom = 31,
        .script = TO_FAR_PTR_T(trigger_1_interact),
        .script_flags = TRIGGER_HAS_ENTER_SCRIPT
    },
    {
        // Trigger 2,
        .left = 11,
        .top = 11,
        .right = 12,
        .bottom = 12,
        .script = TO_FAR_PTR_T(trigger_2_interact),
        .script_flags = TRIGGER_HAS_ENTER_SCRIPT
    }
};
