
#include "vMachine.h"
#include "memory.h"
#include "opcodes.h"
#include "runLoop.h"
#include "traps.h"
#include "fileIo.h"
#include "cmdline.h"


int main(int argc, char** argv) {

    _init_memory();

    cmd_line cl = create_cmd_line("This is the dis-assembler");
    add_str_param(cl, "ifile", "-i", "input file name", "output.bin", CF_NONE);
    add_num_param(cl, "verbose", "-v", "verbosity number from 0 to 10", 0, CF_NONE);
    parse_cmd_line(cl, argc, argv);

    VM* vm = _alloc_ds(VM);
    initVM(vm);
    loadVM(vm, get_str_param(cl, "ifile"));

    runLoop(vm);

    _uninit_memory();

    return 0;
}