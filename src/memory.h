#ifndef _MEMORY_H_
#define _MEMORY_H_

#define _init_memory() GC_init()
#define _uninit_memory() GC_deinit()
#define _alloc(s) GC_malloc(size)
#define _alloc_ds(t) (t*)GC_malloc(sizeof(t))
#define _alloc_ds_array(t, n) (t*)GC_malloc(sizeof(t)*(n))
#define _realloc(p, s) GC_realloc((p), (s))
#define _realloc_ds_array(p, t, n) (t*)GC_realloc((p), sizeof(t)*(n))
#define _copy_str(s) GC_strdup(s)

#if 0
#define _copy_mem(p, s) mem_copy(p, s)
#define _copy_ds(p, t) (t*)mem_copy(p, sizeof(t))
#define _copy_ds_array(p, t, n) (t*)mem_copy(p, sizeof(t)*(n))

const char* mem_strcpy(const char* str);
void* mem_copy(void* ptr, size_t size);
#endif

#endif