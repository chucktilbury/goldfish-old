#ifndef MEMORY_H
#define MEMORY_H

#include "gc.h"

#define _init_memory() GC_init()
#define _uninit_memory() GC_deinit()
#define _alloc(s) GC_malloc(s)
#define _alloc_ds(t) (t*)GC_malloc(sizeof(t))
#define _alloc_ds_array(t, n) (t*)GC_malloc(sizeof(t)*(n))
#define _realloc(p, s) GC_realloc((p), (s))
#define _realloc_ds_array(p, t, n) (t*)GC_realloc((p), sizeof(t)*(n))
#define _copy_str(s) GC_strdup(s)

#endif