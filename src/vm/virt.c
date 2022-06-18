
#include "vMachine.h"
#include "memory.h"
#include "opcodes.h"
#include "runLoop.h"
#include "traps.h"
#include "fileIo.h"


int main() {

    _init_memory();

    VM* vm = _alloc_ds(VM);
    initVM(vm);

    vm->registers[0].type = UINT;
    vm->registers[0].data.unum = 0xdeadbeef;

    Value val;
    val.type = UINT;
    val.data.unum = 0;
    pushValStack(&vm->vstack, val);

    WRITE_VM_OBJ(uint8_t, OP_TRAP);
    WRITE_VM_OBJ(TrapNumType, PRINTR); // trap number
    WRITE_VM_OBJ(uint8_t, OP_EXIT);

    runLoop(vm);

    _uninit_memory();

    return 0;
}