
#include "vMachine.h"
#include "fileIo.h"
#include "scanner.h"
#include "listing.h"
#include "symtab.h"

extern void dumpSymtab();

VM* vm;

int main(int argc, char** argv)
{
    _init_memory();
    cmd_line cl = create_cmd_line("This is the assembler");
    add_str_param(cl, "ofile", "-o", "output file name", "outfile.bin", CF_NONE);
    parse_cmd_line(cl, argc, argv);

    vm = _alloc_ds(VM);
    initVM(vm);

    reset_cmd_excess(cl);
    open_file(iterate_cmd_excess(cl));

    yyparse();

    showListing(vm);
    dumpSymtab();

    saveVM(vm, get_str_param(cl, "ofile"));
    _uninit_memory();

    return 0;
}