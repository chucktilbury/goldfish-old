
#include "system.h"
#include "errors.h"
#include <stdarg.h>

void runtimeError(const char* fmt, ...)
{
    va_list args;
    fprintf(stderr, "runtime ");

    va_start(args, fmt);
    error(fmt, args);
    va_end(args);
}

void runtimeWarning(const char* fmt, ...)
{
    va_list args;
    fprintf(stderr, "runtime ");

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