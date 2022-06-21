#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "varStore.h"

void addSym(const char* key, VarIdx idx);
VarIdx symToIdx(const char* key);
Value* symToVal(const char*key);
void dumpSymtab(FILE* outf);
const char* findLabel(unsigned long addr);

void pushContext(const  char* name);
void popContext();

#endif