#include "common.h"
#include <stdarg.h>

String* createStrFmt(const char* fmt, ...)
{
    String* str = createStr(NULL);
    char buf[255];

    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    addStrStr(str, buf);
    return str;
}

String* createStr(const char* str)
{
    String* s = _alloc_ds(String);
    s->cap = 1 << 3;
    s->len = 0;
    s->list = _alloc_ds_array(char, s->cap);

    if(str != NULL)
        addStrStr(s, str);

    return s;
}

const char* getStrStr(String* s)
{
    return s->list;
}

void addStrStr(String* s, const char* str)
{
    size_t len = strlen(str);
    if(s->len + len + 1 > s->cap) {
        while(s->len + len + 1 > s->cap)
            s->cap <<= 1;
        s->list = _realloc_ds_array(s->list, char, s->cap);
    }

    memcpy(&s->list[s->len], str, len + 1);
    s->len += len;
    s->list[s->len] = '\0';
}

void addStrFmt(String* s, const char* fmt, ...)
{
    char buf[255];
    va_list args;

    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    addStrStr(s, buf);
}

void addStrChar(String* s, char ch)
{
    if(s->len + 2 > s->cap) {
        s->cap <<= 1;
        s->list = _realloc_ds_array(s->list, char, s->cap);
    }

    s->list[s->len] = ch;

    s->len++;
    s->list[s->len] = '\0';
}


String* copyStr(String* str)
{
    return createStr(str->list);
}

/**
 * @brief When this is called, the string that is format expected is the index
 * of a variable in the varStore. The value that is in the var is substituted
 * into the string and a new String is created and stored in the String table.
 *
 * @param vm
 * @param str
 * @return const char*
 */
const char* formatStr(const char* str)
{
    bool finished = false;
    String* s = createStr(NULL);
    String* tmp;
    int state = 0;
    int idx = 0;

    while(!finished) {
        switch(state) {
            case 0: {
                    // entry state. copying the string
                    switch(str[idx]) {
                        case '\0':
                            state = 255;
                            break;
                        case '{':
                            tmp = createStr(NULL);
                            state = 1;
                            break;
                        default:
                            addStrChar(s, str[idx]);
                            break;
                    }
                }
                break;

            case 1: {
                    // seen a '{' may or may not have a var name
                    switch(str[idx]) {
                        case '\0': // string ending
                            addStrChar(s, '{');
                            addStrStr(s, tmp->list);
                            state = 255;
                            break;
                        case '{': // cannot be a variable
                            state = 2;
                            addStrChar(tmp, str[idx]);
                            break;
                        case '}': // tmp has a potential variable
                            state = 3;
                            break;
                        default:
                            if(!isdigit(str[idx]) && isspace(str[idx]))
                                state = 2;
                            addStrChar(tmp, str[idx]);
                            break;
                    }
                }
                break;

            case 2: {
                    // aborting the variable read
                    addStrChar(s, '{');
                    addStrStr(s, tmp->list);
                    state = 0; // go back to copying chars
                }
                break;

            case 3: {
                    // have a potential variable
                    // if it's not a var name, then we need the original
                    Index sidx = strtol(tmp->list, NULL, 10);
                    //printf("index: %d\n", sidx);
                    Value* val = getVar(sidx);
                    if(val->type != ERROR) {
                        String* str = valToStr(val);
                        addStrStr(s, str->list);
                    } else {
                        addStrFmt(s, "{%s}", tmp->list);
                    }
                    idx--;
                    state = 0;
                }
                break;

            case 255: {
                    // ending normally
                    finished = true;
                }
        }
        idx++;
    }

    return s->list;
}

void stripStr(String* str)
{
    int idx = 0;
    for(idx = 0; isspace(str->list[idx]); idx++) {}
    if(idx > 0)
        memmove(str->list, &str->list[idx], strlen(&str->list[idx]));
    for(idx = strlen(str->list)-1; idx > 0 && isspace(str->list[idx]); idx--) {}
    idx++;
    str->list[idx] = '\0';
    str->len = strlen(str->list);
}
