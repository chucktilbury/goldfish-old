/**
 * @file instrStore.c
 * @brief This is the instruction store of the virtual machine. It is
 * basically a buffer of unsigned characters that can be written and read
 * as different sized objects.
 */
#include "memory.h"
#include "instrStore.h"

void initInstrStore(InstrStore* store)
{

    store->len = 0;
    store->index = 0;
    store->cap = 0x01 << 3;

    store->buffer = _alloc(store->cap);
}

unsigned long getInstrIndex(InstrStore* store)
{
    return store->index;
}

unsigned long getInstrLen(InstrStore* store)
{
    return store->len;
}

void setInstrIndex(InstrStore* store, unsigned long idx)
{
    store->index = idx;
}

void incInstrIndex(InstrStore* store, int idx)
{
    store->index += idx;
}

bool isInstrEnded(InstrStore* store)
{
    return (store->index >= store->len);
}
