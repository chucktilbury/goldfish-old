#ifndef VARIABLES_H
#define VARIABLES_H

#include "system.h"
#include "store.h"

typedef struct {
    Value val;
    Status status;
    Index name;
    //bool isAssigned;
} Variable;

typedef struct {
    Variable* list;
    uint32_t cap;
    uint32_t len;
    uint32_t free_slots;
} VarStore;

void initVarStore(VarStore* store);

Index createVar(VarStore* store, ValType type);
Index assignVar(VarStore* store, Index idx, Value val);
Index assignVarName(VarStore* store, Index vidx, Index sidx);
Index addVar(VarStore* store, Value val);
Value* getVar(VarStore* store, Index idx);
void delVar(VarStore* store, Index idx);
void dumpVars(VarStore* store, FILE* outf);

#endif