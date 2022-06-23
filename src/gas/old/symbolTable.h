#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "varStore.h"

void addSym(const char* key, Index idx);
Index symToIdx(const char* key);
Value symToVal(const char*key);

void pushContext(const  char* name);
void popContext();

#endif