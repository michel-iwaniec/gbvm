.include "vm.i"
.include "data/game_globals.i"
.include "global.s"

.area _CODE_255



___bank_script_custom_1 = 255
.globl ___bank_script_custom_1

_script_custom_1::
        ; Input Script Attach
        VM_CONTEXT_PREPARE      4, ___bank_script_input_1, _script_input_1
        VM_INPUT_ATTACH         ^/.A/, 4

        VM_RET_FAR
