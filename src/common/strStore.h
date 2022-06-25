#ifndef STRSTORE_H
#define STRSTORE_H

#include "system.h"
#include "store.h"

void initStrStore();

void loadStrStore(FILE* fp);
void saveStrStore(FILE* fp);

Index addStr(const char* str);
const char* getStr(Index idx);
void delStr(Index idx);
void dumpStrs(FILE* outf);

#endif