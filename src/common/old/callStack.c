
#include "callStack.h"
#include "memory.h"

void initCallStack(CallStack* store)
{
    store->cap = 0x01 << 1;
    store->len = 0;

    store->list = _alloc_ds_array(CallStackElem, store->cap);
}

void pushCallStack(CallStack* store, CallStackElem cse)
{
    if(store->cap < store->len+1) {
        store->cap <<= 1;
        store->list = _realloc_ds_array(store->list, CallStackElem, store->cap);
    }

    store->list[store->len] = cse;
    store->len++;
}

CallStackElem peekCallStack(CallStack* store)
{
    if(store->len-1 > store->cap) {
        fprintf(stderr, "fatal error: call stack under run\n");
        exit(1);
    }

    return store->list[store->len-1];
}

CallStackElem popCallStack(CallStack* store)
{
    if(store->len-1 > store->cap) {
        fprintf(stderr, "fatal error: call stack under run\n");
        exit(1);
    }

    store->len--;
    return store->list[store->len];
}
