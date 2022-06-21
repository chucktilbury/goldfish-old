

#include "system.h"
#include <stdarg.h>
#include "memory.h"

const char* padStr(int len, const char* fmt, ...) {

    va_list args;
    int requested = (len > 0)? len: -len;
    char* buffer;

    va_start(args, fmt);
    int actual = vsnprintf(NULL, 0, fmt, args);
    if(actual <= requested) {
        buffer = _alloc(requested+1);
        char* str = _alloc(actual+1);
        vsprintf(str, fmt, args);
        if(len > 0)
            sprintf(buffer, "%s%*s", str, len - actual, "");
        else
            sprintf(buffer, "%*s%s", (-len) - actual, "", str);
    }
    else {
        buffer = _alloc(actual+1);
        vsprintf(buffer, fmt, args);
    }
    va_end(args);

    return buffer;
}