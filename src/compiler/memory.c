
#include "goldfish.h"

const char* mem_strcpy(const char* str) {
    size_t len = strlen(str)+1;
    const char* ptr = GC_malloc(len);
    memcpy((void*)ptr, str, len);
    return ptr;
}

void* mem_copy(void* ptr, size_t size) {
    void* p = GC_malloc(size);
    memcpy(p, ptr, size);
    return p;
}