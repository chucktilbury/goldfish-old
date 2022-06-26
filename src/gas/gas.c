
#include "common.h"
#include "scanner.h"
#include "asErrors.h"

extern void dumpSymtab();

int main(int argc, char** argv)
{
    _init_memory();
    cmd_line cl = create_cmd_line("This is the assembler");
    add_str_param(cl, "ifile", "-i", "input file name", "", CF_NONE);
    add_str_param(cl, "ofile", "-o", "output file name", "output.bin", CF_NONE);
    add_num_param(cl, "verbose", "-v", "verbosity number from 0 to 10", 0, CF_NONE);
    parse_cmd_line(cl, argc, argv);

    initVM();

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
            showListing(stdout);

        if(get_num_param(cl, "verbose") >= 5) {
            //dumpRegs(vm, stdout);
            dumpSymtab(stdout);
            dumpVars(stdout);
            dumpStrs(stdout);
        }

        saveVM(get_str_param(cl, "ofile"));
    }
    _uninit_memory();

    return 0;
}
