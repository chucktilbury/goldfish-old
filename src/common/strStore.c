
#include "strStore.h"
#include "memory.h"

void initStrStore(StrStore* store)
{
    store->cap = 0x01 << 3;
    store->list = _alloc_ds_array(String, store->cap);

    String str;
    str.str = _copy_str("NONE");
    str.len = 0;
    store->list[0] = str;
    store->len = 1;

}

StrIdx addStr(StrStore* store, const char* str)
{
    if(store->len+1 > store->cap) {
        store->cap <<= 1;
        store->list = _realloc_ds_array(store->list, String, store->cap);
    }

    String s;
    s.str = _copy_str(str);
    s.len = strlen(str)+1;

    store->list[store->len] = s;
    StrIdx idx = store->len++;
    return idx;
}

const char* getStr(StrStore* store, StrIdx idx)
{
    if(idx < store->len)
        return store->list[idx].str;
    else
        return NULL;
}

void dumpStrs(StrStore* store, FILE* outf)
{
    fprintf(outf, "-------- Dump String Table ----------\n");

    for(uint32_t i = 0; i < store->len; i++) {
        fprintf(outf, "<%d>\t\"%s\"\n", i, store->list[i].str);
    }
    fprintf(outf, "-------- end dump ----------\n\n");
}
