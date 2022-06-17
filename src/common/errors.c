
#include "system.h"
#include <stdarg.h>

static int errors = 0;
static int warnings = 0;

void error(const char* fmt, ...)
{
    va_list args;

    fprintf(stderr, "error: ");
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
    errors++;
}

void warning(const char* fmt, ...)
{
    va_list args;

    fprintf(stderr, "warning: ");
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
    warnings++;
}

void fatal(const char* fmt, ...)
{
    va_list args;

    fprintf(stderr, "fatal: ");
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
    errors++;
    exit(1);
}

int get_errors() { return errors; }
int get_warnings() { return warnings; }
