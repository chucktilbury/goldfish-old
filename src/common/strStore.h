#ifndef STRSTORE_H
#define STRSTORE_H

#include "system.h"

typedef uint32_t StrIdx;

typedef struct {
    const char* str;
    size_t len;
} String;

typedef struct {
    String* list;
    uint32_t cap;
    uint32_t len;
} StrStore;

void initStrStore(StrStore* store);

StrIdx addStr(StrStore* store, const char* str);
const char* getStr(StrStore* store, StrIdx idx);
void dumpStrs(StrStore* store, FILE* outf);
void printStr(StrStore* store, StrIdx idx, FILE* outf);

#endif