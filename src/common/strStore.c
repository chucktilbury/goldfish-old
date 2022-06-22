
#include "store.h"
#include "memory.h"

static Index find_slot(StrStore* store)
{
    if(store->free_slots > 0) {
        for(Index idx = 0; idx < store->len; idx++) {
            if(store->list[idx].status == DELETED) {
                store->free_slots--;
                store->list[idx].status = ACTIVE;
                return idx;
            }
        }
        return 0; // error
    }

    if(store->len+1 > store->cap) {
        store->cap <<= 1;
        store->list = _realloc_ds_array(store->list, String, store->cap);
    }

    Index idx = store->len;
    store->len++;

    return idx;
}

static Index validate(StrStore* store, Index idx)
{
    if(idx < store->len) {
        if(store->list[idx].status != DELETED) {
            //fprintf(stderr, "string valid = true\n");
            return true;
        }
    }

    //fprintf(stderr, "string valid = false\n");
    return false;
}

void initStrStore(StrStore* store)
{
    store->cap = 0x01 << 3;
    store->list = _alloc_ds_array(String, store->cap);

    String str;
    str.str = _copy_str("NONE");
    str.len = 0;
    str.status = ACTIVE;
    store->list[0] = str;
    store->len = 1;

}

Index addStr(StrStore* store, const char* str)
{
    Index idx = find_slot(store);

    String s;
    s.str = _copy_str(str);
    s.len = strlen(str)+1;
    s.status = ACTIVE;

    store->list[idx] = s;
    return idx;
}

void delStr(StrStore* store, Index idx)
{
    if(validate(store, idx)) {
        store->list[idx].status = DELETED;
        store->free_slots ++;
    }
}

const char* getStr(StrStore* store, Index idx)
{
    if(validate(store, idx))
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
