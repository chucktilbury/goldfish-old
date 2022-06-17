#include "system.h"
#include "errors.h"
#include <stdarg.h>

static int num_errors = 0;
static int num_warnings = 0;

void syntaxError(const char* fmt, ...)
{
    va_list args;
    fprintf(stderr, "syntax ");

    va_start(args, fmt);
    error(fmt, args);
    va_end(args);
}

void syntaxWarning(const char* fmt, ...)
{
    va_list args;
    fprintf(stderr, "warning ");

    va_start(args, fmt);
    warning(fmt, args);
    va_end(args);
}

void fatalError(const char* fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    fatal(fmt, args);
    va_end(args);
}

int getErrors()
{
    return get_errors();
}

int getWarnings()
{
    return get_warnings();
}