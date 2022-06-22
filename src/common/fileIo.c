
#include "system.h"
#include "fileIo.h"

static void initRegisters(VM* vm)
{
    memset(vm->registers, 0, sizeof(vm->registers));
}

static void load_var_store(VarStore* vs, FILE* fp)
{
    fread(&vs->len, sizeof(vs->len), 1, fp);

    vs->cap = 1;
    while(vs->cap <= vs->len)
        vs->cap <<= 1;

    vs->list = _alloc_ds_array(Variable, vs->len);
    fread(vs->list, sizeof(Variable), vs->len, fp);
}

static void load_instr_store(InstrStore* is, FILE* fp)
{
    fread(&is->len, sizeof(is->len), 1, fp);

    is->cap = 1;
    while(is->cap <= is->len)
        is->cap <<= 1;

    is->buffer = _alloc_ds_array(uint8_t, is->len);
    fread(is->buffer, sizeof(char), is->len, fp);
}

static void load_str_store(StrStore* ss, FILE* fp)
{
    fread(&ss->len, sizeof(ss->len), 1, fp);
    fread(&ss->free_slots, sizeof(ss->free_slots), 1, fp);

    ss->cap = 1;
    while(ss->cap <= ss->len)
        ss->cap <<= 1;

    ss->list = _alloc_ds_array(String, ss->len);
    for(uint32_t i = 0; i < ss->len; i++) {
        fread(&ss->list[i].len, sizeof(size_t), 1, fp);
        ss->list[i].str = _alloc(ss->list[i].len);
        fread(&ss->list[i].status, sizeof(Status), 1, fp);
        fread((void*)ss->list[i].str, sizeof(char), ss->list[i].len, fp);
    }
}

static void save_var_store(VarStore* vs, FILE* fp)
{
    fwrite(&vs->len, sizeof(vs->len), 1, fp);
    fwrite(vs->list, sizeof(Variable), vs->len, fp);
}

static void save_instr_store(InstrStore* is, FILE* fp)
{
    fwrite(&is->len, sizeof(is->len), 1, fp);
    fwrite(is->buffer, sizeof(char), is->len, fp);
}

static void save_str_store(StrStore* ss, FILE* fp)
{
    fwrite(&ss->len, sizeof(ss->len), 1, fp);
    fwrite(&ss->free_slots, sizeof(ss->free_slots), 1, fp);
    for(uint32_t i = 0; i < ss->len; i++) {
        fwrite(&ss->list[i].len, sizeof(size_t), 1, fp);
        fwrite(&ss->list[i].status, sizeof(Status), 1, fp);
        fwrite(ss->list[i].str, sizeof(char), ss->list[i].len, fp);
    }
}

void initVM(VM* vm)
{
    initInstrStore(&vm->istore);
    initCallStack(&vm->cstack);
    initValStack(&vm->vstack);
    initVarStore(&vm->vstore);
    initStrStore(&vm->sstore);
    initRegisters(vm);
}

void loadVM(VM* vm, const char* fname)
{
    FILE* fp = fopen(fname, "r");
    if(fp == NULL) {
        fprintf(stderr, "fatal error: cannot open input file: %s\n", strerror(errno));
        exit(1);
    }

    initVM(vm);

    size_t nl;
    fread(&nl, sizeof(nl), 1, fp);
    vm->fname = _alloc(nl);
    fread((void*)vm->fname, sizeof(char), nl, fp);

    load_var_store(&vm->vstore, fp);
    load_instr_store(&vm->istore, fp);
    load_str_store(&vm->sstore, fp);
    fclose(fp);
}

void saveVM(VM* vm, const char* fname)
{
    FILE* fp = fopen(fname, "w");
    if(fp == NULL) {
        fprintf(stderr, "fatal error: cannot open output file: %s\n", strerror(errno));
        exit(1);
    }

    size_t nl = strlen(vm->fname)+1;
    fwrite(&nl, sizeof(nl), 1, fp);
    fwrite(vm->fname, sizeof(char), nl, fp);

    save_var_store(&vm->vstore, fp);
    save_instr_store(&vm->istore, fp);
    save_str_store(&vm->sstore, fp);
    fclose(fp);
}


