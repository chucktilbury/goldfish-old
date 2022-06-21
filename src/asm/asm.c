
#include <unistd.h> // this is io.h for winders
#include "vMachine.h"
#include "fileIo.h"
#include "scanner.h"
#include "listing.h"
#include "symtab.h"
#include "errors.h"
#include "registers.h"

extern void dumpSymtab();

VM* vm;

int main(int argc, char** argv)
{
    _init_memory();
    cmd_line cl = create_cmd_line("This is the assembler");
    add_str_param(cl, "ifile", "-i", "input file name", "", CF_NONE);
    add_str_param(cl, "ofile", "-o", "output file name", "output.bin", CF_NONE);
    add_num_param(cl, "verbose", "-v", "verbosity number from 0 to 10", 0, CF_NONE);
    add_str_param(cl, "lfile", "-l", "listing file name (with verbosity > 1)", "output.lst", CF_NONE);
    add_bool_param(cl, "nopp", "-p", "turn off using the preprocessor", true, CF_NONE);
    add_str_param(cl, "srch", "-I", "add a preprocessor include search path", ".", CF_NONE);
    add_str_param(cl, "def", "-D", "add a preprocessor define", "", CF_NONE);
    add_str_param(cl, "test", "-t", "test an existing output file", "", CF_NONE);
    parse_cmd_line(cl, argc, argv);
    // TODO: add a cmdline list maker/iterator.
    // TODO: add the preprocessor to this using tmp files.

    vm = _alloc_ds(VM);
    initVM(vm);

    if(isatty(fileno(stdin))) {
        const char* name = get_str_param(cl, "ifile");
        if(strlen(name) > 0)
            open_file(name);
        else
            cmd_use(cl);
    }
    // else flex will open the pipe

    yyparse();

    if(!getErrors()) {
        if(get_num_param(cl, "verbose") >= 1)
            showListing(vm, stdout);

        if(get_num_param(cl, "verbose") >= 5) {
            //dumpRegs(vm, stdout);
            dumpSymtab(stdout);
            dumpVars(&vm->vstore, stdout);
            dumpStrs(&vm->sstore, stdout);
        }

        saveVM(vm, get_str_param(cl, "ofile"));
    }
    _uninit_memory();

    return 0;
}