
#include "strutils.h"
#include "memory.h"
#include "vMachine.h"
#include "values.h"

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
    if(s->len+len+1 > s->cap) {
        while(s->len+len+1 > s->cap)
            s->cap <<= 1;
        s->list = _realloc_ds_array(s->list, char, s->cap);
    }

    memcpy(&s->list[s->len], str, len+1);
    s->len += len;
}

void addStrChar(String* s, char ch)
{
    if(s->len+1 > s->cap) {
        s->cap <<= 1;
        s->list = _realloc_ds_array(s->list, char, s->cap);
    }

    s->list[s->len] = ch;

    s->len++;
}

String* copyStr(String* str)
{
    return createStr(str->list);
}

/**
 * @brief Format a string that is found in R0 where variable names are
 * enclosed in "{}". The value of the variable is substituted for the name
 * and the resulting string is placed in R0. If there are any variables that
 * cannot be substituted, then the variable is copied out without modification.
 *
 * @param vm
 *
 */
const char* format_str(VM* vm, const char* str)
{
    bool finished = false;
    String* s = createStr(NULL);
    String* tmp = createStr(NULL);
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
                            addStrChar(s, '{');
                            addStrStr(s, tmp->list);
                            addStrChar(s, '{');
                            state = 1; // go back to copying chars
                            break;
                        case '}': // tmp has a potential variable
                            state = 2;
                            break;
                        default:
                            addStrChar(tmp, str[idx]);
                            break;
                    }
                }
                break;

            case 2: {
                    // have a potential variable
                    // if it's not a var name, then we need the original
                    String* tmp1 = copyStr(tmp);

                }
                break;

            case 255: {
                    // ending normally
                    finished = true;
                }
        }
    }

    return s->list;
}
