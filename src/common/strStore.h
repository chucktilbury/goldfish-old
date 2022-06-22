#ifndef STRSTORE_H
#define STRSTORE_H

#include "system.h"
#include "store.h"

typedef struct {
    const char* str;
    size_t len;
    Status status;
} String;

typedef struct {
    String* list;
    uint32_t cap;
    uint32_t len;
    uint32_t free_slots;
} StrStore;

void initStrStore(StrStore* store);

Index addStr(StrStore* store, const char* str);
const char* getStr(StrStore* store, Index idx);
void delStr(StrStore* store, Index idx);
void dumpStrs(StrStore* store, FILE* outf);

#endif