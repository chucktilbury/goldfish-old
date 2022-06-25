
// #include "store.h"
// #include "memory.h"
#include "common.h"

typedef struct {
    const char* str;
    size_t len;
    Status status;
} sString;

typedef struct {
    sString* list;
    uint32_t cap;
    uint32_t len;
    uint32_t free_slots;
} StrStore;

static StrStore store;

static Index find_slot()
{
    if(store.free_slots > 0) {
        for(Index idx = 0; idx < store.len; idx++) {
            if(store.list[idx].status == DELETED) {
                store.free_slots--;
                store.list[idx].status = ACTIVE;
                return idx;
            }
        }
        return 0; // error
    }

    if(store.len+1 > store.cap) {
        store.cap <<= 1;
        store.list = _realloc_ds_array(store.list, sString, store.cap);
    }

    Index idx = store.len;
    store.len++;

    return idx;
}

static Index validate(Index idx)
{
    if(idx < store.len) {
        if(store.list[idx].status != DELETED) {
            //fprintf(stderr, "string valid = true\n");
            return true;
        }
    }

    //fprintf(stderr, "string valid = false\n");
    return false;
}

void initStrStore()
{
    store.cap = 0x01 << 3;
    store.list = _alloc_ds_array(sString, store.cap);

    sString str;
    str.str = _copy_str("NONE");
    str.len = 0;
    str.status = ACTIVE;
    store.list[0] = str;
    store.len = 1;

}

void loadStrStore(FILE* fp)
{
    fread(&store.len, sizeof(store.len), 1, fp);
    fread(&store.free_slots, sizeof(store.free_slots), 1, fp);

    store.cap = 1;
    while(store.cap <= store.len)
        store.cap <<= 1;

    store.list = _alloc_ds_array(sString, store.len);
    for(uint32_t i = 0; i < store.len; i++) {
        fread(&store.list[i].len, sizeof(size_t), 1, fp);
        store.list[i].str = _alloc(store.list[i].len);
        fread(&store.list[i].status, sizeof(Status), 1, fp);
        fread((void*)store.list[i].str, sizeof(char), store.list[i].len, fp);
    }
}

void saveStrStore(FILE* fp)
{
    fwrite(&store.len, sizeof(store.len), 1, fp);
    fwrite(&store.free_slots, sizeof(store.free_slots), 1, fp);
    for(uint32_t i = 0; i < store.len; i++) {
        fwrite(&store.list[i].len, sizeof(size_t), 1, fp);
        fwrite(&store.list[i].status, sizeof(Status), 1, fp);
        fwrite(store.list[i].str, sizeof(char), store.list[i].len, fp);
    }
}

Index addStr(const char* str)
{
    Index idx = find_slot();

    sString s;
    s.str = _copy_str(str);
    s.len = strlen(str)+1;
    s.status = ACTIVE;

    store.list[idx] = s;
    return idx;
}

void delStr(Index idx)
{
    if(validate(idx)) {
        store.list[idx].status = DELETED;
        store.free_slots ++;
    }
}

const char* getStr(Index idx)
{
    if(validate(idx))
        return store.list[idx].str;
    else
        return NULL;
}

void dumpStrs(FILE* outf)
{
    fprintf(outf, "-------- Dump String Table ----------\n");

    for(uint32_t i = 0; i < store.len; i++) {
        fprintf(outf, "<%d>\t\"%s\"\n", i, store.list[i].str);
    }
    fprintf(outf, "-------- end dump ----------\n\n");
}
