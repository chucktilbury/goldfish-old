/**
 * @file instrStore.c
 * @brief This is the instruction store of the virtual machine. It is
 * basically a buffer of unsigned characters that can be written and read
 * as different sized objects.
 */
#include "common.h"
#include "errors.h"

typedef struct {
    unsigned char* buffer;
    unsigned long cap;
    unsigned long len;
    unsigned long index;
} InstrStore;

static InstrStore store;

void initInstrStore()
{
    store.len = 0;
    store.index = 0;
    store.cap = 0x01 << 3;

    store.buffer = _alloc(store.cap);
}

void loadInstrStore(FILE* fp)
{
    fread(&store.len, sizeof(store.len), 1, fp);

    store.cap = 1;
    while(store.cap <= store.len)
        store.cap <<= 1;

    store.buffer = _alloc_ds_array(uint8_t, store.len);
    fread(store.buffer, sizeof(char), store.len, fp);
}

void saveInstrStore(FILE* fp)
{
    fwrite(&store.len, sizeof(store.len), 1, fp);
    fwrite(store.buffer, sizeof(char), store.len, fp);
}

unsigned long getInstrIndex()
{
    return store.index;
}

unsigned long getInstrLen()
{
    return store.len;
}

unsigned long getLabelAddr()
{
    return store.len; //(store.len == 0)? 0: store.len - 1;
}

void setInstrIndex(unsigned long idx)
{
    store.index = idx;
}

void incInstrIndex(int idx)
{
    store.index += idx;
}

bool isInstrEnded()
{
    return (store.index >= store.len);
}

void write_instr_obj(void* ptr, size_t size)
{
    if(store.len+size > store.cap) {
        while(store.len+size > store.cap) {
            store.cap <<= 1;
        }
        store.buffer = _realloc(store.buffer, store.cap);
    }

    memcpy(&store.buffer[store.len], ptr, size);
    store.len += size;
}

void write_instr_8(uint8_t val)
{
    size_t size = sizeof(uint8_t);
    if(store.len+size > store.cap) {
        while(store.len+size > store.cap) {
            store.cap <<= 1;
        }
        store.buffer = _realloc(store.buffer, store.cap);
    }

    memcpy(&store.buffer[store.len], &val, size);
    store.len += size;
}

void write_instr_16(uint16_t val)
{
    size_t size = sizeof(uint16_t);
    if(store.len+size > store.cap) {
        while(store.len+size > store.cap) {
            store.cap <<= 1;
        }
        store.buffer = _realloc(store.buffer, store.cap);
    }

    memcpy(&store.buffer[store.len], &val, size);
    store.len += size;
}

void read_instr_obj(void* ptr, size_t size)
{
    if(store.index + size <= store.len) {
        memcpy(ptr, &store.buffer[store.index], size);
        store.index += size;
    }
    else
        fatal("instruction store over run at %d", store.index);
}

void read_instr_8(uint8_t* ptr)
{
    size_t size = sizeof(uint8_t);
    if(store.index + size <= store.len) {
        memcpy(ptr, &store.buffer[store.index], size);
        store.index += size;
    }
    else
        fatal("instruction store over run at %d", store.index);
}

void read_instr_16(uint16_t* ptr)
{
    size_t size = sizeof(uint16_t);
    if(store.index + size <= store.len) {
        memcpy(ptr, &store.buffer[store.index], size);
        store.index += size;
    }
    else
        fatal("instruction store over run at %d", store.index);
}