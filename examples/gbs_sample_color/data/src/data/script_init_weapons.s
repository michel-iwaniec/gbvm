.module script_init_weapons

.include "vm.i"
.include "data/game_globals.i"
.include "global.s"

.area _CODE_255


___bank_script_init_weapons = 255
.globl ___bank_script_init_weapons

_script_init_weapons::
        ; Input Script Attach
        VM_CONTEXT_PREPARE      4, ___bank_script_input_1, _script_input_1
        VM_INPUT_ATTACH         ^/.A/, ^/(4 | .OVERRIDE_DEFAULT)/

        VM_RET_FAR
