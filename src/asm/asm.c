/**
 * @file asm.c
 * @brief This is a small driver that combines the cpp and gas programs so
 * that they can be run seamlessly. This is mostly about the command line
 * interface.
 */
#include <linux/limits.h> // for PATH_MAX = 4096 and NAME_MAX = 255
#include <stdarg.h>
#include "system.h"
#include "cmdline.h"
#include "memory.h"

static char path_buf[PATH_MAX];

// defined cmdline.c
void dump_cmd_line(cmd_line cptr);

static void add_pp_def(const char* str)
{
    printf("definition: %s\n", str);
}

static void add_pp_inc(const char* str)
{
    printf("include: %s\n", str);
}

// Append the formatted string to str and return a pointer to it. Use free().
static const char* append_str(const char* str, const char* fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    size_t nlen = vsnprintf(NULL, 0, fmt, args);
    va_end(args);

    char* ptr;
    if(str != NULL) {
        size_t olen = strlen(str);
        ptr = _alloc(nlen+olen+1);

        strcpy(ptr, str);
        va_start(args, fmt);
        vsprintf(&ptr[olen], fmt, args);
        va_end(args);
    }
    else {
        ptr = _alloc(nlen+1);

        va_start(args, fmt);
        vsprintf(ptr, fmt, args);
        va_end(args);
    }

    return ptr;
}

// Assume the last thing after a '/' is a name and everything in front of
// it is path. If there are no '/' in the string then return an empty string.
static const char* extract_path(const char* str)
{
    char* ptr = _copy_str(str);
    char* tmp = strrchr(ptr, '/');
    if(tmp != NULL)
        *tmp = '\0';
    else
        ptr[0] = '\0';

    return ptr;
}

int main(int argc, char** argv)
{
    _init_memory();
    cmd_line cl = create_cmd_line("This is the assembler");
    add_str_param(cl, "ifile", "-i", "input file name", "", CF_NONE);
    add_str_param(cl, "ofile", "-o", "output file name", "output.bin", CF_NONE);
    add_num_param(cl, "verbose", "-v", "verbosity number from 0 to 10", 0, CF_NONE);
    add_callback_param(cl, "def", "-D", "preprocessor definition", add_pp_def, CF_NONE);
    add_callback_param(cl, "inc", "-I", "preprocessor include path", add_pp_inc, CF_NONE);
    parse_cmd_line(cl, argc, argv);
    dump_cmd_line(cl);

    printf("command: %s\n", get_cmd(cl));

    _uninit_memory();
    return 0;
}
