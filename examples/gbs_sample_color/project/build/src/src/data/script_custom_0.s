.include "vm.i"
.include "data/game_globals.i"
.include "global.s"

.area _CODE_255



___bank_script_custom_0 = 255
.globl ___bank_script_custom_0

_script_custom_0::
        ; Input Script Attach
        VM_CONTEXT_PREPARE      1, ___bank_script_input_0, _script_input_0
        VM_INPUT_ATTACH         ^/.START/, 1

        VM_RET_FAR
