#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

void addSym(const char* key, Index idx);
Index symToIdx(const char* key);
Value* symToVal(const char*key);
void dumpSymtab(FILE* outf);
const char* findLabel(unsigned long addr);

void pushContext(const  char* name);
void popContext();

#endif