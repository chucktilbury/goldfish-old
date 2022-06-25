
#include "valStack.h"
#include "memory.h"

typedef struct {
    Value* list;
    uint32_t cap;
    uint32_t len;
} ValStack;

static ValStack store;

void initValStack()
{
    store.cap = 0x01 << 1;
    store.len = 0;

    store.list = _alloc_ds_array(Value, store.cap);
}

void pushValStack(Value* value)
{
    if(store.cap < store.len+1) {
        store.cap <<= 1;
        store.list = _realloc_ds_array(store.list, Value, store.cap);
    }

    store.list[store.len] = *value;
    store.len++;
}

Value* peekValStack(int index)
{
    if(index == 0) {
        // peek the top of the stack
        if(store.len-1 > store.cap) {
            fprintf(stderr, "fatal error: call stack under run\n");
            exit(1);
        }

        return &store.list[store.len-1];
    }
    else if(index < 0) {
        // peek a index relative to the TOS. This is an unsigned compare.
        if(index+store.len > store.cap) {
            fprintf(stderr, "fatal error: invalid value stack index\n");
            exit(1);
        }

        return &store.list[store.len+index];
    }

    return &store.list[0]; // return an error
}

Value* popValStack()
{
    if(store.len-1 > store.cap) {
        fprintf(stderr, "fatal error: call stack under run\n");
        exit(1);
    }

    store.len--;
    return &store.list[store.len];
}

uint32_t valStackIndex()
{
    return store.len;
}